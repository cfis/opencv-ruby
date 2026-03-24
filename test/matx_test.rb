#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class MatxTest < OpenCVTestCase
  def test_create
    buffer = Rice::Buffer≺float≻.new([10, 20])
    matx1 = Cv::Matx12f.new(buffer.data)
    matx2 = Cv::Matx12f.new(10, 20)

    [matx1, matx2].each do |matx|
      assert_equal(Cv::Matx12f::Rows, 1)
      assert_equal(Cv::Matx12f::Cols, 2)
      assert_equal(Cv::Matx12f::Channels, 2)
      assert_equal(Cv::Matx12f::Shortdim, 1)
      assert_equal(matx.rows, 1)
      assert_equal(matx.cols, 2)
      assert_equal(matx.channels, 2)
      assert_equal(matx.shortdim, 1)
      assert_equal("[10, 20]", matx.inspect)
      assert_equal("[10, 20]", matx.row(0).inspect)
      assert_equal("[10]", matx.col(0).inspect)
      assert_equal("[20]", matx.col(1).inspect)
    end
  end

  def test_create_multidimension
    buffer = Rice::Buffer≺double≻.new([10, 20, 30,
                                       40, 50, 60,
                                       70, 80, 90])
    matx = Cv::Matx33d.new(buffer.data)
    assert_equal("[10, 20, 30;\n 40, 50, 60;\n 70, 80, 90]", matx.inspect)
    assert_equal("[20;\n 50;\n 80]", matx.col(1).inspect)
    assert_equal("[40, 50, 60]", matx.row(1).inspect)
    assert_equal("[10;\n 50;\n 90]", matx.diag.inspect)
    assert_equal( "[10, 40, 70;\n 20, 50, 80;\n 30, 60, 90]", matx.t.inspect)
  end

  def test_singleton_methods
    assert_equal("[0, 0, 0;\n 0, 0, 0;\n 0, 0, 0]", Cv::Matx33d.zeros.inspect)
    assert_equal("[1, 1, 1;\n 1, 1, 1;\n 1, 1, 1]", Cv::Matx33d.ones.inspect)
    assert_equal("[1, 0, 0;\n 0, 1, 0;\n 0, 0, 1]", Cv::Matx33d.eye.inspect)
    assert_equal("[4, 4, 4;\n 4, 4, 4;\n 4, 4, 4]", Cv::Matx33d.all(4).inspect)
  end

  def test_out_of_bounds
    skip("CV_DbgAssert disabled in release builds") unless Cv::DBG_ASSERT_ENABLED

    buffer = Rice::Buffer≺float≻.new([10, 20])
    matx = Cv::Matx12f.new(buffer.data)

    assert_raises(Cv::StsAssert) do
      matx.row(1)
    end

    assert_raises(Cv::StsAssert) do
      matx.col(2).inspect
    end
  end

  def test_each
    expected = [10, 20, 30,
                40, 50, 60,
                70, 80, 90]

    buffer = Rice::Buffer≺double≻.new(expected)
    matx = Cv::Matx33d.new(buffer.data)
    actual = matx.each.to_a
    assert_equal(expected, actual)
  end

  def test_dot_product
    matx1 = Cv::Matx22f.new(0, 0.5, 1.0, 1.5)
    matx2 = Cv::Matx22f.new(0, 1.5, 3.0, 4.5)

    dot = matx1.dot(matx2)
    assert_in_delta(10.5, dot, 0.001)
  end

  def test_solve
    elems1 = [3, 4, 5,
              8, 9, 6,
              3, 5, 9]
    matx = Cv::Matx33f.new(*elems1)
    vec1 = Cv::Vec3f.new(3, 4, 5)

    expected = [2.0, -2.0, 1.0]

    vec2 = matx.solve(vec1, Cv::DecompTypes::DECOMP_LU)
    assert_equal(expected, vec2.to_a)

    vec3 = matx.solve(vec1, Cv::DecompTypes::DECOMP_SVD)
    assert_equal(expected, vec3.to_a)

    vec4 = matx.solve(vec1, Cv::DecompTypes::DECOMP_EIG)
    assert_equal(expected, vec4.to_a)

    vec5 = matx.solve(vec1, Cv::DecompTypes::DECOMP_CHOLESKY)
    assert_equal(expected, vec5.to_a)

    vec6 = matx.solve(vec1, Cv::DecompTypes::DECOMP_QR)
    assert_equal(expected, vec6.to_a)

    vec7 = matx.solve(vec1, Cv::DecompTypes::DECOMP_NORMAL)
    assert_equal(expected, vec7.to_a)
  end

  def test_ddot
    m1 = Cv::Matx33f.all(1.0)
    m2 = Cv::Matx33f.all(2.0)
    result = m1.ddot(m2)
    assert_in_delta(18.0, result, 0.001)
  end

  def test_mul
    m1 = Cv::Matx33f.all(2.0)
    m2 = Cv::Matx33f.all(3.0)
    result = m1.mul(m2)
    assert_in_delta(6.0, result[0, 0], 0.001)
  end

  def test_div
    m1 = Cv::Matx33f.all(6.0)
    m2 = Cv::Matx33f.all(2.0)
    result = m1.div(m2)
    assert_in_delta(3.0, result[0, 0], 0.001)
  end

  def test_inv
    m = Cv::Matx33f.new(1.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 4.0)
    inv = m.inv
    assert_in_delta(1.0, inv[0, 0], 0.001)
    assert_in_delta(0.5, inv[1, 1], 0.001)
    assert_in_delta(0.25, inv[2, 2], 0.001)
  end

  def test_arithmetic
    m1 = Cv::Matx33f.all(3.0)
    m2 = Cv::Matx33f.all(2.0)

    sum = m1 + m2
    assert_in_delta(5.0, sum[0, 0], 0.001)

    diff = m1 - m2
    assert_in_delta(1.0, diff[0, 0], 0.001)
  end

  def test_scalar_multiply
    m = Cv::Matx33f.all(3.0)
    result = m * 2.0
    assert_in_delta(6.0, result[0, 0], 0.001)
  end

  def test_equality
    m1 = Cv::Matx33f.eye
    m2 = Cv::Matx33f.eye
    m3 = Cv::Matx33f.ones
    assert_equal(m1, m2)
    refute_equal(m1, m3)
  end

  def test_val
    m = Cv::Matx22f.new(1.0, 2.0, 3.0, 4.0)
    val = m.val
    assert_equal(4, val.size)
  end

  def test_constructors_various_sizes
    m22 = Cv::Matx22f.new(1.0, 2.0, 3.0, 4.0)
    assert_in_delta(1.0, m22[0, 0], 0.001)
    assert_in_delta(4.0, m22[1, 1], 0.001)

    m44 = Cv::Matx44f.new(1.0, 0.0, 0.0, 0.0,
                           0.0, 2.0, 0.0, 0.0,
                           0.0, 0.0, 3.0, 0.0,
                           0.0, 0.0, 0.0, 4.0)
    assert_in_delta(4.0, m44[3, 3], 0.001)
  end

  def test_vector_single_index
    m = Cv::Matx31f.new(1.0, 2.0, 3.0)
    assert_in_delta(1.0, m[0], 0.001)
    assert_in_delta(2.0, m[1], 0.001)
    assert_in_delta(3.0, m[2], 0.001)
  end

  def test_input_array
    m = Cv::Matx33f.eye
    ia = m.input_array
    assert_instance_of(Cv::InputArray, ia)
  end
end
