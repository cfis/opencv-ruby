#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class MatStepTest < OpenCVTestCase
	# def test_initialize
	# 	step = Cv::MatStep.new
	#
	# 	step_0 = step[0]
	# 	assert_equal(0, step_0)
	#
	# 	step_1 = step[1]
	# 	assert_equal(0, step_1)
	# end
	#
	# def test_initialize_with_size
	# 	step = Cv::MatStep.new(4)
	#
	# 	step_0 = step[0]
	# 	assert_equal(4, step_0)
	#
	# 	step_1 = step[1]
	# 	assert_equal(0, step_1)
	# end
	#
	# def test_set
	# 	step = Cv::MatStep.new
	#
	# 	step_0 = step[0]
	# 	assert_equal(0, step_0)
	#
	# 	step[0] = 5
	#
	# 	step_0 = step[0]
	# 	assert_equal(5, step_0)
	# end
	#
	# def test_to_size_t
	# 	step = Cv::MatStep.new(444)
	# 	actual = step.to_size_t
	# 	assert_equal(444, actual)
	# end

	def test_p
		step = Cv::MatStep.new(4)
		buffer = step.p.bytes(2)
		assert_equal("\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", buffer)

		step = Cv::MatStep.new(4)
		data = step.p.to_ary(2)
		assert_equal([4, 0], data)
	end

	# def test_buffer
	# 	step = Cv::MatStep.new(4)
	# 	buffer = step.buf.to_str
	# 	assert_equal("\x04\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", buffer)
	#
	# 	step = Cv::MatStep.new(4)
	# 	data = step.buf.to_ary
	# 	assert_equal([4, 0], data)
	# end
end
