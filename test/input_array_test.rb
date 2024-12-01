#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class InputArrayTest < OpenCVTestCase
  def test_create
    mat = Cv::Mat.new(2, 3, CV_8SC1, Cv::Scalar.new(10))
    input_array = Cv::InputArray.new(4)
    mat.set_to(input_array)

    expected = <<~EOS.chomp
      [  4,   4,   4;
         4,   4,   4]
    EOS
    assert_equal(expected, mat.inspect)
  end

  def test_initialize_mat
    mat = Cv::Mat.new(3, 2, CV_32SC2)
    input_array = Cv::InputOutputArray.new(mat)
    assert_equal(mat.size.to_size, input_array.size)
    assert_equal(Cv::InputArray::KindFlag::MAT, input_array.kind)
    assert_equal(2, input_array.dims)
    assert_equal(3, input_array.rows)
    assert_equal(2, input_array.cols)
    assert_equal(6, input_array.total)
    assert_equal(12, input_array.type)
    assert_equal(4, input_array.depth)
    assert_equal(true, input_array.continuous?)
    assert_equal(false, input_array.submatrix?)
    assert_equal(false, input_array.empty?)
  end

  def test_identity
    mat = Cv::Mat.new(2, 2, CV_32SC2)
    io_array = Cv::InputOutputArray.new(mat)
    scalar = Cv::Scalar.new(1, 2)
    Cv::set_identity(io_array, scalar)
    assert_equal("[1, 2, 0, 0;\n 0, 0, 1, 2]", mat.inspect)
  end
end
