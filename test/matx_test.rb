#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class MatxTest < OpenCVTestCase
  def test_create
    buffer = Rice::Buffer≺float≻.new([10, 20])
    matx1 = Cv::Matx12f.new(buffer)
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
    matx = Cv::Matx33d.new(buffer)
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
    buffer = Rice::Buffer≺float≻.new([10, 20, 30, 40])
    matx = Cv::Matx12f.new(buffer)
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
    matx = Cv::Matx33d.new(buffer)
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
end
