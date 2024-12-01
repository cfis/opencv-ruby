#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class MatTest < OpenCVTestCase
  def test_create
    mat = Cv::Mat.new(10, 20, CV_32F)
    assert_equal(10, mat.rows)
    assert_equal(20, mat.cols)
    assert_equal(CV_32F, mat.depth)
    assert_equal(CV_32F, mat.type)
    assert_equal(1, mat.channels)
  end

  def test_initialize_size
    mat = Cv::Mat.new(Cv::Size.new(3, 2), CV_32F)
    assert_equal(2, mat.rows)
    assert_equal(3, mat.cols)
    assert_equal(CV_32F, mat.depth)
    assert_equal(CV_32F, mat.type)
    assert_equal(1, mat.channels)
  end

  def test_initialize_scalar
    mat = Cv::Mat.new(2, 3, CV_8SC1, Cv::Scalar.new(10))
    assert_equal(2, mat.rows)
    assert_equal(3, mat.cols)
    assert_equal(CV_8S, mat.depth)
    assert_equal(CV_8SC1, mat.type)
    assert_equal(1, mat.channels)
    assert_equal([10, 10, 10, 10, 10, 10], mat.data.to_ary(6))

    mat = Cv::Mat.new(2, 3, CV_8SC4, Cv::Scalar.new(10, 11, 12, 13))
    assert_equal(2, mat.rows)
    assert_equal(3, mat.cols)
    assert_equal(CV_8S, mat.depth)
    assert_equal(CV_8SC4, mat.type)
    assert_equal(4, mat.channels)
    assert_equal([10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13, 10, 11, 12, 13],
                 mat.data.to_ary(24))
  end

  def test_initialize_from_buffer_array
    buffer = (1..4).to_a.pack("i*")
    mat = Cv::Mat.new(2, 2, CV_32SC1, buffer)
    assert_equal(2, mat.rows)
    assert_equal(2, mat.cols)
    assert_equal(CV_32S, mat.depth)
    assert_equal(CV_32SC1, mat.type)
    assert_equal(1, mat.channels)
    assert_equal("[1, 2;\n 3, 4]",
                 mat.inspect)
  end

  def test_initialize_sizes
    vector = Std::Vector≺int≻.new
    vector << 2 << 3
    mat = Cv::Mat.new(vector, CV_32SC1, Cv::Scalar.new(3))

    expected = <<~EOS.chomp
      [3, 3, 3;
       3, 3, 3]
    EOS
    assert_equal(expected, mat.inspect)
  end

  def test_initialize_multi_dimensional_matrix
    dimensions = [2, 2, 2]
    buffer = Rice::Buffer≺int≻.new(dimensions)
    mat = Cv::Mat.new(3, buffer, CV_8UC1, Cv::Scalar.new(3))
    assert_equal(3, mat.dims)
    assert_equal([3, 3, 3, 3, 3, 3, 3, 3], mat.data.to_ary(8))
  end

  def test_clone
    mat1 = create_mat(10, 20)
    mat2 = mat1.clone
    assert_equal(mat1.rows, mat2.rows)
    assert_equal(mat1.cols, mat2.cols)
    assert_equal(mat1.type, mat2.type)
    assert_equal(mat1.channels, mat2.channels)
    assert_equal(mat1.inspect, mat2.inspect)
    assert(mat1.eql?(mat2))
    refute_same(mat1, mat2)
  end

  def test_zeros
    expr = Cv::Mat.zeros(5, 5, CV_32F)
    mat = expr.to_mat
    assert_equal(5, mat.rows)
    assert_equal(5, mat.cols)
    assert_equal(CV_32F, mat.depth)
    assert_equal(1, mat.channels)
    assert_equal("[0, 0, 0, 0, 0;\n 0, 0, 0, 0, 0;\n 0, 0, 0, 0, 0;\n 0, 0, 0, 0, 0;\n 0, 0, 0, 0, 0]",
                 mat.inspect)
  end

  def test_ptr_uchar
    expr = Cv::Mat.eye(3, 3, CV_8UC1)
    mat = expr.to_mat

    row = mat.ptr(0).to_ary
    assert_equal([1, 0, 0], row)

    row = mat.ptr(1).to_ary(3)
    assert_equal([0, 1, 0], row)

    row = mat.ptr(2).to_ary
    assert_equal([0, 0, 1], row)
  end

  def test_ptr_float
    mat = Cv::Mat.new(2, 3, CV_32FC4, Cv::Scalar.new(1.1, 2.2, 3.3, 4.4))

    cell = Cv::Matx41f.new(1.1, 2.2, 3.3, 4.4)
    row = mat.ptr(0).to_ary
    assert_equal([cell, cell, cell], row)

    row = mat.ptr(1).to_ary
    assert_equal([cell, cell, cell], row)
  end

  def test_data
    mat = create_mat(2, 2, CV_8UC2)
    size = mat.step[0] * mat.rows

    assert_kind_of(Rice::Buffer≺unsigned char≻, mat.data)
    data = mat.data.bytes(size)
    assert_equal("\x01\x01\x02\x02\x03\x03\x04\x04", data)

    assert_kind_of(Array, mat.data.to_ary)
    array = mat.data.to_ary(size)
    assert_equal([1, 1, 2, 2, 3, 3, 4, 4], array)
  end

  def test_each
    mat1 = create_mat(2, 2, CV_32SC1)
    mat1.each.with_index do |value, i|
      assert_kind_of(Integer, value)
      assert_equal(i + 1, value)
    end

    expected = [1, 2, 3, 4]
    actual = mat1.each.to_a
    assert_equal(expected, actual)

    mat2 = create_mat(2, 2, CV_32SC2) do |row, column, count|
      Cv::Vec2i.new(count, count)
    end

    mat2.each.with_index do |value, i|
      assert_kind_of(Cv::Vec2i, value)
      assert_equal([i, i], value.to_a)
    end

    expected = [Cv::Vec2i.new(0, 0), Cv::Vec2i.new(1, 1), Cv::Vec2i.new(2, 2), Cv::Vec2i.new(3, 3)]
    actual = mat2.each.to_a
    assert_equal(expected, actual)
  end

  def test_each_writable
    mat1 = create_mat(2, 2, CV_32SC2) do |row, column, count|
      Cv::Vec2i.new(count, count)
    end
    expected = "[0, 0, 1, 1;\n 2, 2, 3, 3]"
    actual = mat1.inspect
    assert_equal(expected, actual)

    mat1.each.with_index do |value, i|
      value[0] = value[0] + 1
      value[1] = value[1] + 1
    end
    expected = "[1, 1, 2, 2;\n 3, 3, 4, 4]"
    actual = mat1.inspect
    assert_equal(expected, actual)
  end

  def test_ones
    expr = Cv::Mat.ones(5, 5, CV_32F)
    mat = expr.to_mat
    assert_equal(5, mat.rows)
    assert_equal(5, mat.cols)
    assert_equal(CV_32F, mat.depth)
    assert_equal(1, mat.channels)
    assert_equal("[1, 1, 1, 1, 1;\n 1, 1, 1, 1, 1;\n 1, 1, 1, 1, 1;\n 1, 1, 1, 1, 1;\n 1, 1, 1, 1, 1]",
                 mat.inspect)
  end

  def test_eye
    expr = Cv::Mat.eye(5, 5, CV_32F)
    mat = expr.to_mat
    assert_equal(5, mat.rows)
    assert_equal(5, mat.cols)
    assert_equal(CV_32F, mat.depth)
    assert_equal(1, mat.channels)
    assert_equal('<Cv::Mat:5x5,type=CV_32FC1,channel=1>', mat.to_s)
    assert_equal("[1, 0, 0, 0, 0;\n 0, 1, 0, 0, 0;\n 0, 0, 1, 0, 0;\n 0, 0, 0, 1, 0;\n 0, 0, 0, 0, 1]",
                 mat.inspect)
  end

  def test_get_row_range
    buffer = (1..50).to_a.pack("i*")
    mat1 = Cv::Mat.new(10, 5, CV_32SC1, buffer)
    mat2 = mat1.row_range(4, 6)
    assert_equal(2, mat2.rows)
    assert_equal(mat1.cols, mat2.cols)
    assert_equal("[21, 22, 23, 24, 25;\n 26, 27, 28, 29, 30]", mat2.inspect)
  end

  def test_get_col
    buffer = (1..50).to_a.pack("i*")
    mat1 = Cv::Mat.new(10, 5, CV_32SC1, buffer)
    mat2 = mat1.col(2)
    assert_equal(10, mat2.rows)
    assert_equal(mat1.rows, mat2.rows)
    assert_equal("[3;\n 8;\n 13;\n 18;\n 23;\n 28;\n 33;\n 38;\n 43;\n 48]", mat2.inspect)
  end

  def test_get_pixel
    buffer = (1..4).to_a.pack("i*")
    mat = Cv::Mat.new(2, 2, CV_32SC1, buffer)
    assert_kind_of(Integer, mat[0, 0])
    assert_equal(1, mat[0, 0])
    assert_equal(2, mat[0, 1])
    assert_equal(3, mat[1, 0])
    assert_equal(4, mat[1, 1])

    buffer = (1..16).to_a.pack("i*")
    mat = Cv::Mat.new(2, 2, CV_32SC4, buffer)
    assert_kind_of(Cv::Vec4i, mat[0, 0])
    assert_equal(Cv::Vec4i.new(1, 2, 3, 4), mat[0, 0])
    assert_equal(Cv::Vec4i.new(5, 6, 7, 8), mat[0, 1])
    assert_equal(Cv::Vec4i.new(9, 10, 11, 12), mat[1, 0])
    assert_equal(Cv::Vec4i.new(13, 14, 15, 16), mat[1, 1])
  end

  def test_set_uchar
    mat = Cv::Mat.new(1, 1, CV_8UC1)
    mat[0, 0] = 1
    assert_equal(1, mat[0, 0])
  end

  def test_set_short
    mat = Cv::Mat.new(1, 1, CV_16SC1)
    mat[0, 0] = 1
    assert_equal(1, mat[0, 0])
  end

  def test_set_unsigned_short
    mat = Cv::Mat.new(1, 1, CV_16UC1)
    mat[0, 0] = 1
    assert_equal(1, mat[0, 0])
  end

  def test_set_int
    mat = Cv::Mat.new(1, 1, CV_32SC1)
    mat[0, 0] = 1
    assert_equal(1, mat[0, 0])
  end

  def test_set_float
    mat = Cv::Mat.new(1, 1, CV_32FC1)
    mat[0, 0] = 1.0
    assert_equal(1.0, mat[0, 0])
  end

  def test_set_double
    mat = Cv::Mat.new(1, 1, CV_64FC1)
    mat[0, 0] = 1.0
    assert_equal(1.0, mat[0, 0])
  end

  def test_set_pixel
    mat = Cv::Mat.new(2, 2, CV_8UC2)

    vec1 = Cv::Vec2b.new(1, 2)
    vec2 = Cv::Vec2b.new(3, 4)
    vec3 = Cv::Vec2b.new(5, 6)
    vec4 = Cv::Vec2b.new(7, 8)

    mat[0, 0] = vec1
    mat[0, 1] = vec2
    mat[1, 0] = vec3
    mat[1, 1] = vec4

    assert_equal(vec1, mat[0, 0])
    assert_equal(vec2, mat[0, 1])
    assert_equal(vec3, mat[1, 0])
    assert_equal(vec4, mat[1, 1])
  end

  def test_assign
    mat = Cv::Mat.new(2, 3, CV_8SC1, Cv::Scalar.new(10))

    expected = <<~EOS.chomp
      [ 10,  10,  10;
        10,  10,  10]
    EOS
    assert_equal(expected, mat.inspect)

    mat.assign(Cv::Scalar.new(5))

    expected = <<~EOS.chomp
      [  5,   5,   5;
         5,   5,   5]
    EOS
    assert_equal(expected, mat.inspect)

    mat2 = Cv::Mat.new(2, 3, CV_8SC1, Cv::Scalar.new(4))
    mat.assign(mat2)

    expected = <<~EOS.chomp
      [  4,   4,   4;
         4,   4,   4]
    EOS
    assert_equal(expected, mat.inspect)

  end

  def test_set_to
    mat = Cv::Mat.new(2, 3, CV_8SC1, Cv::Scalar.new(10))
    input_array = Cv::InputArray.new(4)
    mat.set_to(input_array)

    expected = <<~EOS.chomp
      [  4,   4,   4;
         4,   4,   4]
    EOS
    assert_equal(expected, mat.inspect)
  end

  def test_slice_range
    buffer = (1..9).to_a.pack("i*")
    mat = Cv::Mat.new(3, 3, CV_32SC1, buffer)

    row_range = Cv::Range.new(0, 3)
    col_range = Cv::Range.new(0, 3)
    mat_slice = mat[row_range, col_range]
    assert_equal("[1, 2, 3;\n 4, 5, 6;\n 7, 8, 9]", mat_slice.inspect)

    row_range = Cv::Range.new(1, 2)
    col_range = Cv::Range.new(2, 3)
    mat_slice = mat[row_range, col_range]
    assert_equal("[6]", mat_slice.inspect)
  end

  def test_slice_range_pointer
    buffer = (1..9).to_a.pack("i*")
    mat = Cv::Mat.new(3, 3, CV_32SC1, buffer)

    row_range = Cv::Range.new(0, 3)
    col_range = Cv::Range.new(0, 3)
    mat_slice = mat[row_range, col_range]
    assert_equal("[1, 2, 3;\n 4, 5, 6;\n 7, 8, 9]", mat_slice.inspect)

    row_range = Cv::Range.new(1, 2)
    col_range = Cv::Range.new(2, 3)
    mat_slice = mat[row_range, col_range]
    assert_equal("[6]", mat_slice.inspect)
  end

  def test_slice_rect
    buffer = (1..9).to_a.pack("i*")
    mat = Cv::Mat.new(3, 3, CV_32SC1, buffer)

    rect = Cv::Rect.new(0, 0, 3, 3)
    mat_slice = mat[rect]
    assert_equal("[1, 2, 3;\n 4, 5, 6;\n 7, 8, 9]", mat_slice.inspect)

    rect = Cv::Rect.new(2, 1, 1, 1)
    mat_slice = mat[rect]
    assert_equal("[6]", mat_slice.inspect)
  end

  def test_get_row
    buffer = (1..50).to_a.pack("i*")
    mat1 = Cv::Mat.new(10, 5, CV_32SC1, buffer)
    mat2 = mat1.row(2)
    assert_equal(1, mat2.rows)
    assert_equal(mat1.cols, mat2.cols)
    assert_equal("[11, 12, 13, 14, 15]", mat2.inspect)
  end

  def test_diag
    buffer = (1..25).to_a.pack("i*")
    mat1 = Cv::Mat.new(5, 5, CV_32SC1, buffer)

    mat2 = mat1.diag
    assert_equal("[1;\n 7;\n 13;\n 19;\n 25]",
                 mat2.inspect)

    mat3 = mat1.diag(1)
    assert_equal("[2;\n 8;\n 14;\n 20]",
                 mat3.inspect)

    mat4 = mat1.diag(-1)
    assert_equal("[6;\n 12;\n 18;\n 24]",
                 mat4.inspect)

    [mat1.rows, mat1.cols, -mat1.rows, -mat1.cols].each do |index|
      assert_raises(Cv::StsAssert) do
        mat1.diag(index)
      end
    end
  end

  def test_get_u_mat
    mat = Cv::Mat.new(2, 3, CV_32FC2, Cv::Scalar.new(12, 13))
    umat = mat.get_u_mat(Cv::AccessFlag::ACCESS_RW)
    assert_kind_of(Cv::UMat, umat)
    expected = <<~EOS.chomp
      [12, 13, 12, 13, 12, 13;
       12, 13, 12, 13, 12, 13]
    EOS
    assert_equal(expected, umat.inspect)
  end

  def test_identity
    mat = Cv::Mat.new(2, 2, CV_32SC2)
    io_array = Cv::InputOutputArray.new(mat)
    scalar = Cv::Scalar.new(1, 2)
    Cv::set_identity(io_array, scalar)
    assert_equal("[1, 2, 0, 0;\n 0, 0, 1, 2]", mat.inspect)
  end

  def test_reshape
    mat = Cv::Mat.new(2, 3, CV_8UC3, Cv::Scalar.new(1, 2, 3))
    vec = mat.reshape(0, 1)
    assert_equal(1, vec.rows)
    assert_equal(6, vec.cols)
    assert_equal("[  1,   2,   3,   1,   2,   3,   1,   2,   3,   1,   2,   3,   1,   2,   3,   1,   2,   3]",
                 vec.inspect)

    ch1 = mat.reshape(1)
    assert_equal(2, ch1.rows)
    assert_equal(9, ch1.cols)

    assert_equal("[  1,   2,   3,   1,   2,   3,   1,   2,   3;\n   1,   2,   3,   1,   2,   3,   1,   2,   3]",
                 ch1.inspect)
  end

  def test_repeat
    mat1 = Cv::Mat.new(1, 1, CV_8UC3, Cv::Scalar.new(1, 2, 3))
    mat2 = Cv::repeat(mat1, 3, 2)

    expected = <<~EOS.chomp
      [  1,   2,   3,   1,   2,   3;
         1,   2,   3,   1,   2,   3;
         1,   2,   3,   1,   2,   3]
    EOS
    assert_equal(expected, mat2.inspect)
  end

  def test_addition
    mat_expr1 = Cv::Mat.eye(2, 3, CV_32F);
    mat_expr2 = Cv::Mat.ones(2, 3, CV_32F);
    mat_expr3 = mat_expr1 + mat_expr2
    mat = mat_expr3.to_mat
    assert_equal(2, mat.rows)
    assert_equal(3, mat.cols)
    assert_equal(CV_32F, mat.depth)
    assert_equal(1, mat.channels)

    expected = <<~EOS.chomp
      [2, 1, 1;
       1, 2, 1]
    EOS
    assert_equal(expected, mat.inspect)
  end

  def test_add_scalar
    mat1 = create_mat(3, 2, CV_32FC4) do |row, col, count|
      Cv::Vec4f.new(count * 0.1, count * 0.2, count * 0.3, count * 0.4)
    end

    scalar = Cv::Scalar.new(1, 2, 3, 4)
    expr = mat1 + scalar
    mat2 = expr.to_mat

    assert_equal(mat1.rows, mat2.rows)
    assert_equal(mat1.cols, mat2.cols)

    assert_each_element(mat2, 0.01) do |row, col, count|
      n = count + 1
      Cv::Vec4f.new(count * 0.1 + 1, count * 0.2 + 2, count * 0.3 + 3, count * 0.4 + 4)
    end
  end

  def test_multiplication
    mat_expr1 = Cv::Mat.eye(4, 3, CV_32F)
    mat_expr2 = mat_expr1 * 5
    mat = mat_expr2.to_mat

    expected = <<~EOS.chomp
      [5, 0, 0;
       0, 5, 0;
       0, 0, 5;
       0, 0, 0]
    EOS
    assert_equal(expected, mat.inspect)
  end

  def test_sub
    mat1 = create_mat(3, 2, CV_32FC4) do |row, col, count|
      Cv::Vec4f.new(count * 0.1, count * 0.2, count * 0.3, count * 0.4)
    end

    mat2 = create_mat(3, 2, CV_32FC4) do |row, col, count|
      Cv::Vec4f.new(count * 1, count * 2, count * 3, count * 4)
    end

    expr = mat1 - mat2
    mat3 = expr.to_mat

    assert_equal(mat1.rows, mat3.rows)
    assert_equal(mat1.cols, mat3.cols)

    assert_each_element(mat3, 0.001) do |row, col, count|
      Cv::Vec4f.new(count * 0.1 - count * 1, count * 0.2 - count * 2,
                    count * 0.3 - count * 3, count * 0.4 - count * 4)
    end
  end

  def test_sub_scalar
    mat1 = create_mat(3, 2, CV_32FC4) do |row, col, count|
      Cv::Vec4f.new(count * 0.1, count * 0.2, count * 0.3, count * 0.4)
    end

    scalar= Cv::Scalar.new(1, 2, 3, 4)
    expr = mat1 - scalar
    mat2 = expr.to_mat

    assert_equal(mat1.rows, mat2.rows)
    assert_equal(mat1.cols, mat2.cols)

    assert_each_element(mat2, 0.001) do |row, col, count|
      Cv::Vec4f.new(count * 0.1 - 1, count * 0.2 - 2,
                    count * 0.3 - 3, count * 0.4 - 4)
    end
  end

  def test_multiply
    mat1 = Cv::Mat.new(3, 3, CV_32FC1, Cv::Scalar.new(2))
    mat2 = Cv::Mat.new(3, 3, CV_32FC1, Cv::Scalar.new(3))
    expr = mat1 * mat2

    expected = <<~EOS.chomp
      [18, 18, 18;
       18, 18, 18;
       18, 18, 18]
    EOS
    assert_equal(expected, expr.to_mat.inspect)
  end

  def test_multiply_value
    mat1 = Cv::Mat.new(3, 3, CV_32FC1, Cv::Scalar.new(2))
    expr = mat1 * 3
    mat2 = expr.to_mat

    expected = <<~EOS.chomp
      [6, 6, 6;
       6, 6, 6;
       6, 6, 6]
    EOS
    assert_equal(expected, expr.to_mat.inspect)
  end

  def test_divide
    mat1 = Cv::Mat.new(3, 3, CV_32FC1, Cv::Scalar.new(8))
    mat2 = Cv::Mat.new(3, 3, CV_32FC1, Cv::Scalar.new(2))
    expr = mat1 / mat2

    expected = <<~EOS.chomp
      [4, 4, 4;
       4, 4, 4;
       4, 4, 4]
    EOS
    assert_equal(expected, expr.to_mat.inspect)
  end

  def test_divide_value
    mat1 = Cv::Mat.new(3, 3, CV_32FC1, Cv::Scalar.new(18))
    expr = mat1 / 3
    mat2 = expr.to_mat

    expected = <<~EOS.chomp
      [6, 6, 6;
       6, 6, 6;
       6, 6, 6]
    EOS
    assert_equal(expected, expr.to_mat.inspect)
  end

  def test_and
    mat1 = create_mat(6, 4, CV_8UC4)
    mat2 = create_mat(6, 4, CV_8UC4) do
      Cv::Vec4b.new(1, 2, 3, 4)
    end

    # Cv::Mat & Cv::Mat
    expr = mat1 & mat2
    mat3 = expr.to_mat
    assert_equal(mat1.rows, mat3.rows)
    assert_equal(mat1.cols, mat3.cols)

    assert_each_element(mat3) do |row, col, count|
      n = count + 1
      Cv::Vec4b.new(n & 1, n & 2, n & 3, n & 4)
    end

    # Cv::Mat & Cv::Scalar
    expr = mat1 & Cv::Scalar.new(1, 2, 3, 4)
    mat4 = expr.to_mat
    assert_equal(mat1.rows, mat4.rows)
    assert_equal(mat1.cols, mat4.cols)
    assert_each_element(mat4) do |row, col, count|
      n = count + 1
      Cv::Vec4b.new(n & 1, n & 2, n & 3, n & 4)
    end
  end

  def test_bitwise_and
    mat1 = create_mat(6, 4, CV_8UC4)
    mat2 = create_mat(6, 4, CV_8UC4) do
      Cv::Vec4b.new(1, 2, 3, 4)
    end
    mask = create_mat(6, 4, CV_8UC1) do |row, col, count|
      (row < 3 and col < 2) ? 1 : 0
    end

    # Cv::Mat & Cv::Mat with mask
    mat3 = mat1.bitwise_and(mat2, mask: mask)
    assert_equal(mat1.rows, mat3.rows)
    assert_equal(mat1.cols, mat3.cols)

    assert_each_element(mat3) do |row, col, count|
      n = count + 1
      if row < 3 and col < 2
        Cv::Vec4b.new(n & 1, n & 2, n & 3, n & 4)
      else
        Cv::Vec4b.new(n, n, n, n)
      end
    end

    # Cv::Mat & Cv::Scalar with mask
    mat3 = mat1.bitwise_and(Cv::Scalar.new(1, 2, 3, 4), mask: mask)
    assert_equal(mat1.rows, mat3.rows)
    assert_equal(mat1.cols, mat3.cols)
    assert_each_element(mat3) do |row, col, count|
      n = count + 1
      if row < 3 and col < 2
        Cv::Vec4b.new(n & 1, n & 2, n & 3, n & 4)
      else
        Cv::Vec4b.new(n, n, n, n)
      end
    end
  end

  def test_or
    mat1 = create_mat(6, 4, CV_8UC4)

    mat2 = create_mat(6, 4) do
      Cv::Vec4b.new(1, 2, 3, 4)
    end

    # Cv::Mat & Cv::Mat
    expr = mat1 | mat2
    mat3 = expr.to_mat
    assert_equal(mat1.rows, mat3.rows)
    assert_equal(mat1.cols, mat3.cols)

    assert_each_element(mat3) do |row, col, count|
      n = count + 1
      Cv::Vec4b.new(n | 1, n | 2, n | 3, n | 4)
    end

    # Cv::Mat | Cv::Scalar
    expr = mat1 | Cv::Scalar.new(1, 2, 3, 4)
    mat4 = expr.to_mat
    assert_equal(mat1.rows, mat4.rows)
    assert_equal(mat1.cols, mat4.cols)
    assert_each_element(mat4) do |row, col, count|
      n = count + 1
      Cv::Vec4b.new(n | 1, n | 2, n | 3, n | 4)
    end
  end

  def test_bitwise_or
    mat1 = create_mat(6, 4, CV_8UC4)

    mat2 = create_mat(6, 4) do
      Cv::Vec4b.new(1, 2, 3, 4)
    end

    mask = create_mat(6, 4, CV_8UC1) do |row, col, count|
      (row < 3 and col < 2) ? 1 : 0
    end

    # Cv::Mat | Cv::Mat with mask
    mat3 = mat1.bitwise_or(mat2, mask: mask)
    assert_equal(mat1.rows, mat3.rows)
    assert_equal(mat1.cols, mat3.cols)
    assert_each_element(mat3) do |row, col, count|
      n = count + 1
      if row < 3 and col < 2
        Cv::Vec4b.new(n | 1, n | 2, n | 3, n | 4)
      else
        Cv::Vec4b.new(n, n, n, n)
      end
    end

    # Cv::Mat | Cv::Scalar with mask
    mat4 = mat1.bitwise_or(Cv::Scalar.new(1, 2, 3, 4), mask: mask)
    assert_equal(mat1.rows, mat4.rows)
    assert_equal(mat1.cols, mat4.cols)
    assert_each_element(mat4) do |row, col, count|
      n = count + 1
      if row < 3 and col < 2
        Cv::Vec4b.new(n | 1, n | 2, n | 3, n | 4)
      else
        Cv::Vec4b.new(n, n, n, n)
      end
    end
  end

  def test_xor
    mat1 = create_mat(6, 4, CV_8UC4)

    mat2 = create_mat(6, 4) do
      Cv::Vec4b.new(1, 2, 3, 4)
    end

    # Cv::Mat ^ Cv::Mat
    expr = mat1 ^ mat2
    mat3 = expr.to_mat
    assert_equal(mat1.rows, mat3.rows)
    assert_equal(mat1.cols, mat3.cols)
    assert_each_element(mat3) do |row, col, count|
      n = count + 1
      Cv::Vec4b.new(n ^ 1, n ^ 2, n ^ 3, n ^ 4)
    end

    # Cv::Mat ^ Cv::Scalar
    expr = mat1 ^ Cv::Scalar.new(1, 2, 3, 4)
    mat4 = expr.to_mat
    assert_equal(mat1.rows, mat4.rows)
    assert_equal(mat1.cols, mat4.cols)
    assert_each_element(mat4) do |row, col, count|
      n = count + 1
      Cv::Vec4b.new(n ^ 1, n ^ 2, n ^ 3, n ^ 4)
    end
  end

  def test_bitwise_xor
    mat1 = create_mat(6, 4, CV_8UC4)

    mat2 = create_mat(6, 4) do
      Cv::Vec4b.new(1, 2, 3, 4)
    end

    mask = create_mat(6, 4, CV_8UC1) do |row, col, count|
      (row < 3 and col < 2) ? 1 : 0
    end

    # Cv::Mat ^ Cv::Mat with mask
    mat3 = mat1.bitwise_xor(mat2, mask: mask)
    assert_equal(mat1.rows, mat3.rows)
    assert_equal(mat1.cols, mat3.cols)
    assert_each_element(mat3) do |row, col, count|
      n = count + 1
      if row < 3 and col < 2
        Cv::Vec4b.new(n ^ 1, n ^ 2, n ^ 3, n ^ 4)
      else
        Cv::Vec4b.new(n, n, n, n)
      end
    end

    # Cv::Mat ^ Cv::Scalar with mask
    mat3 = mat1.bitwise_xor(Cv::Scalar.new(1, 2, 3, 4), mask: mask)
    assert_equal(mat1.rows, mat3.rows)
    assert_equal(mat1.cols, mat3.cols)
    assert_each_element(mat3) do |row, col, count|
      n = count + 1
      if row < 3 and col < 2
        Cv::Vec4b.new(n ^ 1, n ^ 2, n ^ 3, n ^ 4)
      else
        Cv::Vec4b.new(n, n, n, n)
      end
    end
  end

  def test_not
    mat1 = create_mat(6, 4, CV_8UC4)
    expr = ~mat1
    mat2 = expr.to_mat
    assert_each_element(mat2) do |row, col, count|
      n = count + 1
      Cv::Vec4b.new(~n, ~n, ~n, ~n)
    end
  end

  def test_bitwise_not
    mat1 = create_mat(6, 4, CV_8UC4)
    mask = create_mat(6, 4, CV_8UC1) do |row, col, count|
      (row < 3 and col < 2) ? 1 : 0
    end

    mat2 = mat1.bitwise_not(mask: mask)
    assert_each_element(mat2) do |row, col, count|
      n = count + 1
      if row < 3 and col < 2
        Cv::Vec4b.new(~n, ~n, ~n, ~n)
      else
        Cv::Vec4b.new(n, n, n, n)
      end
    end
  end

  def test_eq
    mat1 = create_mat(6, 4) do |row, col, count|
      n = (count.even?) ? 10 : count
      Cv::Vec4b.new(n, 0, 0, 0)
    end

    mat2 = create_mat(6, 4) do |row, col, count|
      Cv::Vec4b.new(10, 0, 0, 0)
    end

    mat3 = mat1.eq(mat2)
    assert_equal(mat3.rows, mat1.rows)
    assert_equal(mat3.cols, mat1.cols)
    assert_each_element(mat3) do |row, col, count|
      n = (count.even?) ? 255 : 0
      Cv::Vec4b.new(n, 255, 255, 255)
    end
  end

  def test_gt
    mat1 = create_mat(6, 4, CV_8UC1) do |row, col, count|
      count % 4 == 0 ? count : 0
    end
    mat2 = create_mat(6, 4, CV_8UC1) do |row, col, count|
      count % 4 == 0 ? 10 : 0
    end
    mat3 = mat1.gt(mat2)
    assert_each_element(mat3) do |row, col, count|
      [12, 16, 20].include?(count) ? 255 : 0
    end

    scalar1 = Cv::Scalar.new(10, 0, 0, 0)
    mat4 = mat1.gt(scalar1)
    assert_each_element(mat3) do |row, col, count|
      [12, 16, 20].include?(count) ? 255 : 0
    end
  end

  def test_ge
    mat1 = create_mat(6, 4, CV_8UC1) do |row, col, count|
      count % 4 == 0 ? count : 0
    end
    mat2 = create_mat(6, 4, CV_8UC1) do |row, col, count|
      count % 4 == 0 ? 10 : 0
    end
    mat3 = mat1.ge(mat2)
    assert_each_element(mat3) do |row, col, count|
      [0, 4, 8].include?(count) ? 0 : 255
    end

    scalar1 = Cv::Scalar.new(10, 0, 0, 0)
    mat4 = mat1.ge(scalar1)
    assert_each_element(mat3) do |row, col, count|
      [0, 4, 8].include?(count) ? 0 : 255
    end
  end

  def test_lt
    mat1 = create_mat(6, 4, CV_8UC1) do |row, col, count|
      count % 4 == 0 ? count : 0
    end
    mat2 = create_mat(6, 4, CV_8UC1) do |row, col, count|
      count % 4 == 0 ? 10 : 0
    end
    mat3 = mat1.lt(mat2)
    assert_each_element(mat3) do |row, col, count|
      [0, 4, 8].include?(count) ? 255 : 0
    end

    scalar1 = Cv::Scalar.new(10, 0, 0, 0)
    mat4 = mat1.lt(scalar1)
    assert_each_element(mat3) do |row, col, count|
      [0, 4, 8].include?(count) ? 255 : 0
    end
  end

  def test_le
    mat1 = create_mat(6, 4, CV_8UC1) do |row, col, count|
      count % 4 == 0 ? count : 0
    end
    mat2 = create_mat(6, 4, CV_8UC1) do |row, col, count|
      count % 4 == 0 ? 10 : 0
    end
    mat3 = mat1.le(mat2)
    assert_each_element(mat3) do |row, col, count|
      [12, 16, 20].include?(count) ? 0 : 255
    end

    scalar1 = Cv::Scalar.new(10, 0, 0, 0)
    mat4 = mat1.le(scalar1)
    assert_each_element(mat3) do |row, col, count|
      [12, 16, 20].include?(count) ? 0 : 255
    end
  end

  def test_in_range
    lower, upper = 10, 20

    mat1 = create_mat(6, 4, CV_8UC1) do |row, col, count|
      count % 4 == 0 ? count + 5 : 0
    end
    lowerb = create_mat(6, 4, CV_8UC1) do |row, col, count|
      count % 4 == 0 ? lower : 0
    end
    upperb = create_mat(6, 4, CV_8UC1) do |row, col, count|
      count % 4 == 0 ? upper : 0
    end

    mat2 = mat1.in_range(lowerb, upperb)
    assert_each_element(mat2) do |row, col, count|
      [0, 4, 16, 20].include?(count) ? 0 : 255
    end

    lowerb_s = Cv::Scalar.new(lower, 0, 0, 0)
    upperb_s = Cv::Scalar.new(upper, 0, 0, 0)

    mat3 = mat1.in_range(lowerb_s, upperb_s)
    assert_each_element(mat2) do |row, col, count|
      [0, 4, 16, 20].include?(count) ? 0 : 255
    end
  end

  def test_abs_diff
    mat1 = create_mat(6, 4, CV_32FC4) do |row, col, count|
      Cv::Vec4f.new(count + 10.5, count - 10.5, count + 10.5, count - 10.5)
    end
    mat2 = create_mat(6, 4, CV_32FC4) do |row, col, count|
      Cv::Vec4f.new(count, count, count, count)
    end

    mat3 = mat1.absdiff(mat2)
    assert_each_element(mat3, 0.001) do
      Cv::Vec4f.new(10.5, 10.5, 10.5, 10.5)
    end

    mat4 = create_mat(6, 4, CV_32FC4) do |row, col, count|
      Cv::Vec4f.new(-10 + 10.5, 20 + 10.5, -30 + 10.5, 40 - 10.5)
    end
    scalar1 = Cv::Scalar.new(-10, 20, -30, 40)

    mat5 = mat4.absdiff(scalar1)
    assert_each_element(mat5, 0.001) do
      Cv::Vec4f.new(10.5, 10.5, 10.5, 10.5)
    end
  end

  def test_normalize
    mat1 = create_mat(2, 2, CV_32FC1) do |row, col, count|
      count.to_f
    end
    mat2 = mat1.normalize
    expected = [0.0, 0.267, 0.534, 0.801]
    assert_in_delta_array(expected, mat2.each.to_a, 0.001)

    mat3 = mat1.normalize(alpha: 1, beta: 0, norm_type: Cv::NormTypes::NORM_INF)
    expected = [0.0, 0.333, 0.666, 1.0]
    assert_in_delta_array(expected, mat3.each.to_a, 0.001)

    mat4 = mat1.normalize(alpha: 1, beta: 0, norm_type: Cv::NormTypes::NORM_L1)
    expected = [0.0, 0.166, 0.333, 0.5]
    assert_in_delta_array(expected, mat4.each.to_a, 0.001)

    mat5 = mat1.normalize(alpha: 1, beta: 0, norm_type: Cv::NormTypes::NORM_L2)
    expected = [0.0, 0.267, 0.534, 0.801]
    assert_in_delta_array(expected, mat5.each.to_a, 0.001)

    mat6 = mat1.normalize(alpha: 10, beta: 5, norm_type: Cv::NormTypes::NORM_MINMAX)
    expected = [5.0, 6.666, 8.333, 10.0]
    assert_in_delta_array(expected, mat6.each.to_a, 0.001)

    mat7 = mat1.normalize(alpha: 1, beta: 0, norm_type: Cv::NormTypes::NORM_INF, dtype: CV_32FC3)
    expected = [0.0, 0.333, 0.666, 1.0]
    assert_in_delta_array(expected, mat7.each.to_a, 0.001)

    #mask = mat1.to_8u.zero
    mask = Cv::Mat.new(2, 2, CV_8UC1, Cv::Scalar.new(0))
    #mask[0, 0] = Cv::Vec3b.new(255, 0, 0)
    #mask[1, 0] = Cv::Vec3b.new(255, 0, 0)
    # mat8 = mat1.normalize(1, 0, Cv::NormTypes::NORM_INF, -1, mask.input_array)
    # expected = [0.0, 0.0, 1.0, 0.0]
    # assert_in_delta_array(expected, mat8.each.to_a, 0.001)
  end

  def test_count_non_zero
    mat = create_mat(6, 4, CV_32SC1) do |row, col, count|
      col == 0 ? 1 : 0
    end
    assert_equal(6, mat.count_non_zero)
  end

  def test_sum
    mat1 = create_mat(6, 4, CV_32SC1) do |row, col, count|
      count
    end
    expected = Cv::Scalar.new(276.0, 0.0, 0.0, 0.0)
    actual = mat1.sum
    assert_equal(expected, actual)

    mat2 = create_mat(6, 4, CV_32SC1) do |row, col, count|
      -count
    end
    expected = Cv::Scalar.new(-276.0, 0.0, 0.0, 0.0)
    actual = mat2.sum
    assert_equal(expected, actual)
  end

  def test_min_max_loc
    mat = create_mat(6, 4, CV_32FC1) do |row, col, count|
      count * 0.5
    end
    mat[2, 3] = 100.5 # Max
    mat[5, 1] = -100.5 # Min

    min_val, max_val, min_loc, max_loc = mat.min_max_loc
    assert_equal(-100.5, min_val)
    assert_equal(5, min_loc.y)
    assert_equal(1, min_loc.x)
    assert_equal(100.5, max_val)
    assert_equal(2, max_loc.y)
    assert_equal(3, max_loc.x)

    mat2 = create_mat(6, 4, CV_32SC3) do |row, col, count|
      Cv::Vec3i.new(count, count + 1, count + 2)
    end

    min_val, max_val, min_loc, max_loc = mat2.min_max_loc
    assert_equal(0, min_val)
    assert_equal(0, min_loc.y)
    assert_equal(0, min_loc.x)
    assert_equal(25, max_val)
    assert_equal(0, max_loc.y)
    assert_equal(0, max_loc.x)
  end

  def test_norm
    buffer = [1, 2, 3, 4, 5, 6, 7, 8, 9].to_a.pack("f*")
    mat1 = Cv::Mat.new(3, 3, CV_32FC1, buffer)

    buffer =[2, 3, 4, 5, 6, 7, 8, 9, 1].to_a.pack("f*")
    mat2 = Cv::Mat.new(3, 3, CV_32FC1, buffer)

    buffer = [1, 1, 0, 1, 1, 0, 0, 0, 0].to_a.pack("f*")
    mask = Cv::Mat.new(3, 3, CV_8UC1, buffer)

    norm = Cv::norm(mat1.input_array)
    assert_in_delta(16.88, norm,0.01)

    norm = Cv::norm(mat1.input_array, Cv::NormTypes::NORM_L1)
    assert_in_delta(45.0, norm, 0.01)

    norm = Cv::norm(mat1.input_array, Cv::NormTypes::NORM_L2)
    assert_in_delta(16.88, norm, 0.01)

    norm = Cv::norm(mat1.input_array, Cv::NormTypes::NORM_INF)
    assert_in_delta(9.0, norm, 0.01)

    norm = Cv::norm(mat1.input_array, mat2.input_array, Cv::NormTypes::NORM_L1)
    assert_in_delta(16.0, norm, 0.01)

    norm = Cv::norm(mat1.input_array, mat2.input_array, Cv::NormTypes::NORM_L2)
    assert_in_delta(8.49, norm, 0.01)

    norm = Cv::norm(mat1.input_array, mat2.input_array, Cv::NormTypes::NORM_INF)
    assert_in_delta(8.0, norm, 0.01)

    norm = Cv::norm(mat1.input_array, mat2.input_array, Cv::NormTypes::NORM_L1, mask.input_array)
    assert_in_delta(4.0, norm, 0.01)

    norm = Cv::norm(mat1.input_array, mat2.input_array, Cv::NormTypes::NORM_L2, mask.input_array)
    assert_in_delta(2.0, norm, 0.01)

    norm = Cv::norm(mat1.input_array, mat2.input_array, Cv::NormTypes::NORM_INF, mask.input_array)
    assert_in_delta(1.0, norm, 0.01)
  end

  def test_dot_product
    mat1 = create_mat(2, 2, CV_32FC1) do |row, col, count|
      count * 0.5
    end
    mat2 = create_mat(2, 2, CV_32FC1) do |row, col, count|
      count * 1.5
    end
    assert_in_delta(10.5, mat1.dot(mat2.input_array), 0.001)

    mat3 = create_mat(2, 2, CV_32FC4) do |row, col, count|
      Cv::Vec4f.new(count * 0.5, count * 0.6, count * 0.7, count * 0.8)
    end
    mat4 = create_mat(2, 2, CV_32FC4) do |row, col, count|
      Cv::Vec4f.new(count * 1.5, count * 2.0, count * 2.5, count * 3.0)
    end
    assert_in_delta(85.39999, mat3.dot(mat4.input_array), 0.001)
  end

  def test_cross_product
    mat1 = create_mat(1, 3, CV_32FC1) do |row, col, count|
      count * 0.5
    end
    mat2 = create_mat(1, 3, CV_32FC1) do |row, col, count|
      count + 1.0
    end

    mat3 = mat1.cross(mat2.input_array)

    assert_in_delta(-0.5, mat3[0, 0], 0.001)
    assert_in_delta(1, mat3[0, 1], 0.001)
    assert_in_delta(-0.5, mat3[0, 2], 0.001)
  end

  def test_transform
    mat1 = create_mat(5, 5, CV_32FC3) do |row, col, count|
      Cv::Vec3f.new(count * 0.5, count * 1.0, count * 1.5)
    end

    transmat = Cv::Mat.new(3, 3, CV_32FC1, Cv::Scalar.new(0.0))
    transmat[0, 2] = 1.0
    transmat[2, 1] = 1.0

    mat2 = mat1.transform(transmat)
    assert_each_element(mat2, 0.01) do |row, col, count|
      Cv::Vec3f.new(count * 1.5, 0, count)
    end
  end

  def test_perspective_transform
    mat1 = Cv::Mat.new(1, 1, CV_32FC2)
    mat1[0, 0] = Cv::Vec2f.new(2, 3)

    transmat = Cv::Mat.new(3, 3, CV_32FC1, Cv::Scalar.new(0))
    mat1.channels.times do |count|
      transmat[count, count] = 1.0
    end
    transmat[2, 2] = 0.5

    mat2 = mat1.perspective_transform(transmat)
    assert_equal(1, mat2.rows)
    assert_equal(1, mat2.cols)
    assert_equal(CV_32FC1, mat2.depth)
    assert_equal(2, mat2.channels)
    assert_in_delta_array(Cv::Vec2f.new(4, 6), mat2[0, 0], 0.001);

    mat3 = Cv::Mat.new(1, 1, CV_32FC3)
    mat3[0, 0] = Cv::Vec3f.new(2, 3, 4)
    transmat = Cv::Mat.new(4, 4, CV_32FC1, Cv::Scalar.new(0))
    mat3.channels.times do |count|
      transmat[count, count] = 1.0
    end
    transmat[3, 3] = 0.5

    mat4 = mat3.perspective_transform(transmat)
    assert_equal(1, mat4.rows)
    assert_equal(1, mat4.cols)
    assert_equal(CV_32FC1, mat4.depth)
    assert_equal(3, mat4.channels)
    assert_in_delta_array(Cv::Vec3f.new(4, 6, 8), mat4[0, 0], 0.001)
  end

  def test_mul_transposed
    mat1 = create_mat(2, 2, CV_32FC1) do |row, col, count|
      (count + 1) * 2.0
    end
    delta = create_mat(2, 2, CV_32FC1) do |row, col, count|
      count + 1.0
    end

    mat2 = mat1.mul_transposed
    assert_equal(2, mat2.rows)
    assert_equal(2, mat2.cols)
    assert_equal(CV_32FC1, mat2.depth)

    #expected = [40.0, 56.0, 56.0, 80.0]
    #actual = mat2.each.to_a
    #assert_equal(expected, actual)
  end

  def test_trace
    mat1 = create_mat(5, 5, CV_32FC4) do |row, col, count|
      Cv::Vec4f.new(count * 0.5, count * 1.0, count * 1.5, count * 2.0)
    end
    expected = Cv::Scalar.new(30, 60, 90, 120)
    actual = mat1.trace
    assert_equal(expected, actual)
  end

  def test_transpose
    mat1 = create_mat(2, 3, CV_32FC4) do |row, col, count|
      Cv::Vec4f.new(count * 0.5, count * 1.0, count * 1.5, count * 2.0)
    end
    mat2 = mat1.transpose

    assert_each_element(mat2, 0.001) do |row, col, count|
      mat1[col, row]
    end
  end

  def test_det
    elems = [2.5, 4.5, 2.0,
             3.0, 2.5, -0.5,
             1.0, 0.5, 1.5]

    buffer = elems.pack("f*")
    mat = Cv::Mat.new(3, 3, CV_32FC1, buffer)
    det = mat.determinant
    assert_in_delta(-14.5, det, 0.001)
  end

  def test_invert
    elems = [1, 2, 3,
             2, 6, 9,
             1, 4, 7]

    buffer = elems.pack("f*")
    mat1 = Cv::Mat.new(3, 3, CV_32FC1, buffer)

    mat2 = mat1.invert
    mat3 = mat1.invert(flags: Cv::DecompTypes::DECOMP_LU)
    mat4 = mat1.invert(flags: Cv::DecompTypes::DECOMP_SVD)
    mat5 = mat1.invert(flags: Cv::DecompTypes::DECOMP_CHOLESKY)

    expected = [3, -1, 0, -2.5, 2, -1.5, 1, -1, 1]
    [mat2, mat3, mat4, mat5].each do |mat|
      assert_each_element(mat, 0.001) do |row, col, count|
        expected[count]
      end
    end

    mat6 = mat1.invert(flags: Cv::DecompTypes::DECOMP_EIG)

    expected = [3, -1, 0, -1.0, 0.15, 0.23, 0, 0.23, -0.15]
    [mat6].each do |mat|
      assert_each_element(mat, 0.005) do |row, col, count|
        expected[count]
      end
    end
  end

  def test_format
    buffer = (1..6).to_a.pack("i*")
    mat = Cv::Mat.new(2, 3, CV_32SC1, buffer)

    formatted = Cv.format(mat.input_array, Cv::Formatter::FormatType::FMT_DEFAULT)
    expected = <<~EOS.chomp
      [1, 2, 3;
       4, 5, 6]
    EOS
    assert_equal(expected, formatted.to_s)

    formatted = Cv.format(mat.input_array, Cv::Formatter::FormatType::FMT_MATLAB)
    expected = <<~EOS.chomp
      (:, :, 1) = 
      1, 2, 3;
      4, 5, 6
    EOS
    assert_equal(expected, formatted.to_s)

    formatted = Cv.format(mat.input_array, Cv::Formatter::FormatType::FMT_CSV)
    expected = <<~EOS.chomp
      1, 2, 3
      4, 5, 6

    EOS
    assert_equal(expected, formatted.to_s)

    formatted = Cv.format(mat.input_array, Cv::Formatter::FormatType::FMT_PYTHON)
    expected = <<~EOS.chomp
      [[1, 2, 3],
       [4, 5, 6]]
    EOS
    assert_equal(expected, formatted.to_s)

    formatted = Cv.format(mat.input_array, Cv::Formatter::FormatType::FMT_NUMPY)
    expected = <<~EOS.chomp
      array([[1, 2, 3],
             [4, 5, 6]], dtype='int32')
    EOS
    assert_equal(expected, formatted.to_s)

    formatted = Cv.format(mat.input_array, Cv::Formatter::FormatType::FMT_C)
    expected = <<~EOS.chomp
      {1, 2, 3,
       4, 5, 6}
    EOS
    assert_equal(expected, formatted.to_s)
  end

  def test_to_s
    mat = Cv::Mat.new
    assert_equal('<Cv::Mat:0x0,type=CV_8UC1,channel=1>', mat.to_s)
    mat = Cv::Mat.new(10, 20, CV_16S)
    assert_equal('<Cv::Mat:10x20,type=CV_16SC1,channel=1>', mat.to_s)
    mat = Cv::Mat.new(20, 10, CV_32F)
    assert_equal('<Cv::Mat:20x10,type=CV_32FC1,channel=1>', mat.to_s)
  end
end
