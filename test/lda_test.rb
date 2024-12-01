#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class LDATest < OpenCVTestCase
	def test_subspace_project
		w = Cv::Mat.new(10, 20, CV_32FC1)
		mean = Cv::Mat.new(w.rows, 1, CV_32FC1)
		result = Cv::Mat.new(w.cols, w.rows, CV_32FC1)
		Cv::LDA::subspace_project(w.input_array, mean.input_array, result.input_array)

		assert_equal(w.cols, result.rows)
		assert_equal(w.cols, result.cols)
	end

	def test_subspace_reconstruct
		w = Cv::Mat.new(10, 20, CV_32FC1)
		mean = Cv::Mat.new(w.rows, 1, CV_32FC1)
		result = Cv::Mat.new(w.cols, w.cols, CV_32FC1)
		Cv::LDA::subspace_reconstruct(w.input_array, mean.input_array, result.input_array)
		assert_equal(Cv::Mat, result.class)
		assert_equal(w.cols, result.rows)
		assert_equal(w.rows, result.cols)
	end
end
