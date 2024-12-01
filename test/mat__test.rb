#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class Mat_Test < OpenCVTestCase
  def test_create_1_channel
    mat = Cv::Mat1i.new(2, 3)
    assert_equal(2, mat.rows)
    assert_equal(3, mat.cols)
    assert_equal(CV_32S, mat.depth)
    assert_equal(1, mat.channels)
  end

  def test_create_3_channel
    mat = Cv::Mat3i.new(2, 3)
    assert_equal(2, mat.rows)
    assert_equal(3, mat.cols)
    assert_equal(CV_32S, mat.depth)
    assert_equal(3, mat.channels)
  end

  def test_initialize_size
    mat = Cv::Mat3f.new(Cv::Size.new(3, 2))
    assert_equal(2, mat.rows)
    assert_equal(3, mat.cols)
    assert_equal(CV_32F, mat.depth)
    assert_equal(3, mat.channels)
  end

  def test_initialize_value
    mat = Cv::Mat1i.new(2, 3, 10)
    assert_equal(2, mat.rows)
    assert_equal(3, mat.cols)
    assert_equal(CV_32S, mat.depth)
    assert_equal(1, mat.channels)
    assert_equal("[10, 10, 10;\n 10, 10, 10]", mat.inspect)
  end

  def test_initialize_buffer
    range = 1..4
    buffer = Rice::Buffer≺int≻.new(range.to_a)
    mat1 = Cv::Mat1i.new(2, 2, buffer)
    assert_equal(2, mat1.rows)
    assert_equal(2, mat1.cols)
    assert_equal(CV_32S, mat1.depth)
    assert_equal(CV_32SC1, mat1.type)
    assert_equal(1, mat1.channels)
    assert_equal("[1, 2;\n 3, 4]",
                 mat1.inspect)

    mat2 = Cv::Mat1i.new(2, 2, buffer)
    assert_equal("[1, 2;\n 3, 4]",
                 mat1.inspect)
  end

  def test_initialize_array
    data1 = [Cv::Vec2f.new(0, 0),
             Cv::Vec2f.new(1, 1)]

    mat1 = Cv::Mat2f.new(data1, true) # Tell OpenCV to copy data!
    assert_equal("[0, 0;\n 1, 1]", mat1.inspect)

    data2 = [Cv::Vec2f.new(2, 2),
             Cv::Vec2f.new(3, 3)]

    mat2 = Cv::Mat2f.new(data2, true)  # Tell OpenCV to copy data!
    assert_equal("[2, 2;\n 3, 3]", mat2.inspect)

    # Validate mat1 is still valid
    assert_equal("[0, 0;\n 1, 1]", mat1.inspect)
  end

  def test_initialize_vector
    data1 = Std::Vector≺Cv꞉꞉Vec2f≻.new
    data1 << Cv::Vec2f.new(0, 0) << Cv::Vec2f.new(1, 1)
    mat1 = Cv::Mat2f.new(data1, false) # Do not copy data
    assert_equal("[0, 0;\n 1, 1]", mat1.inspect)

    data2 = Std::Vector≺Cv꞉꞉Vec2f≻.new
    data2 << Cv::Vec2f.new(2, 2) << Cv::Vec2f.new(3, 3)
    mat2 = Cv::Mat2f.new(data2, false)  # Do not copy data
    assert_equal("[2, 2;\n 3, 3]", mat2.inspect)

    # mat1 should still be valid
    assert_equal("[0, 0;\n 1, 1]", mat1.inspect)
  end

  def test_initialize_vec
    buffer = Rice::Buffer≺int≻.new([3, 4])
    vec = Cv::Vec2i.new(buffer)
    mat = Cv::Mat2i.new(3, 2, vec)
    expected = <<~EOS.chomp
      [3, 4, 3, 4;
       3, 4, 3, 4;
       3, 4, 3, 4]
    EOS
    assert_equal(expected, mat.inspect)

    assert_equal(vec, mat[0])
  end

  def test_initialize_mat
    mat1 = Cv::Mat.new(2, 3, CV_8SC1, Cv::Scalar.new(10))
    mat2 = Cv::Mat1i.new(mat1)

    expected = <<~EOS.chomp
      [10, 10, 10;
       10, 10, 10]
    EOS
    assert_equal(expected, mat2.inspect)
  end

  def test_each
    mat = Cv::Mat1i.new(5, 5, 4)
    expected = [4, 4, 4, 4, 4,
                4, 4, 4, 4, 4,
                4, 4, 4, 4, 4,
                4, 4, 4, 4, 4,
                4, 4, 4, 4, 4]
    assert_equal(expected, mat.each.to_a)
  end

  def test_each_const
    mat = Cv::Mat1i.new(2, 3, 3)
    expected = [3, 3, 3,
                3, 3, 3]
    assert_equal(expected, mat.each_const.to_a)
  end

  def test_each_reverse
    vec = Cv::Vec2i.new(3, 4)
    mat = Cv::Mat2i.new(2, 3, vec)
    expected = [vec, vec, vec, vec, vec, vec]
    assert_equal(expected, mat.each_reverse.to_a)
  end

  def test_aref
    # [  1,   1,   1,   1,   2,   2,   2,   2,   3,   3,   3,   3;
    #    4,   4,   4,   4,   5,   5,   5,   5,   6,   6,   6,   6]

    mat = create_mat(2, 3)
    assert_equal([1, 1, 1, 1], mat[0, 0].to_a)
    assert_cvscalar_equal(Cv::Vec4b.new(1, 1, 1, 1), mat[0, 0])
    assert_equal([5, 5, 5, 5], mat[1, 1].to_a)
    assert_cvscalar_equal(Cv::Vec4b.new(5, 5, 5, 5), mat[1, 1])
    assert_equal([2, 2, 2, 2], mat[0, 1].to_a)
    assert_cvscalar_equal(Cv::Vec4b.new(2, 2, 2, 2), mat[0, 1])
    assert_equal([4, 4, 4, 4], mat[1, 0].to_a)
    assert_cvscalar_equal(Cv::Vec4b.new(4, 4, 4, 4), mat[1, 0])
    assert_cvscalar_equal(Cv::Vec4b.new(2, 2, 2, 2), mat[0, 1])
    assert_cvscalar_equal(Cv::Vec4b.new(4, 4, 4, 4), mat[1, 0])

    assert_raises(Cv::StsAssert) do
      mat[-1, -1]
    end

    assert_raises(Cv::StsAssert) do
      mat[6, 6]
    end
  end

  def test_aset
    mat = Cv::Mat4b.new(2, 3)
    buffer1 = Rice::Buffer≺unsigned char≻.new([10, 10, 10, 10])
    mat[0] = Cv::Vec4b.new(buffer1)
    assert_equal([10, 10, 10, 10], mat[0].to_a)

    buffer2 = Rice::Buffer≺unsigned char≻.new([20, 20, 20, 20])
    mat[1, 0] = Cv::Vec4b.new(buffer2)
    assert_equal([20, 20, 20, 20], mat[1, 0].to_a)
  end

  def test_element_access
    image_path = self.sample_path("starry_night.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
    mat = image.mat_klass.new(image)
    buffer = Rice::Buffer≺unsigned char≻.new([99, 39, 10])
    assert_equal(Cv::Vec3b.new(buffer), mat[44, 44])
  end

  def test_range_access
    image_path = self.sample_path("starry_night.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
    mat = image.mat_klass.new(image)
    row_range = Cv::Range.new(44, 45)
    col_range = Cv::Range.new(44, 45)

    mat2 = mat[row_range, col_range]
    assert_kind_of(image.mat_klass, mat2)
    assert_equal(1, mat2.rows)
    assert_equal(1, mat2.cols)

    buffer = Rice::Buffer≺unsigned char≻.new([99, 39, 10])
    assert_equal(Cv::Vec3b.new(buffer), mat2[0, 0])
  end
end
