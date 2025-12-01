#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class LDATest < OpenCVTestCase
  def test_subspace_project
    w = create_mat(3, 2, CV_32FC1) do |row, col, count|
      (row * 2 + col + 1).to_f  # Creates: [[1,2], [3,4], [5,6]]
    end
    mean = create_mat(w.rows, 1, CV_32FC1) do |row, col, count|
      (row + 1).to_f
    end
    src = create_mat(1, w.rows, CV_32FC1) do |row, col, count|
      (col + 1) * 2.0
    end

    # Project: result should be (src - mean)^T * W
    # (src - mean) = [1, 2, 3]
    # [1,2,3] * [[1,2], [3,4], [5,6]] = [1*1+2*3+3*5, 1*2+2*4+3*6] = [22, 28]
    projected = Cv::LDA::subspace_project(w.input_array, mean.input_array, src.input_array)
    expected = [22.0, 28.0]
    assert_in_delta_array(expected, projected.to_a)
  end

  def test_subspace_reconstruct
    w = Cv::Mat.new(10, 20, CV_32FC1)
    mean = Cv::Mat.new(w.rows, 1, CV_32FC1)
    result = Cv::Mat.new(w.rows, w.cols, CV_32FC1)
    Cv::LDA::subspace_reconstruct(w.input_array, mean.input_array, result.input_array)
    assert_equal(Cv::Mat, result.class)
    assert_equal(w.rows, result.rows)
    assert_equal(w.cols, result.cols)
  end
end
