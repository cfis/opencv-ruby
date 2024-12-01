#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class Size2fTest < OpenCVTestCase
  def test_initialize
    size = Cv::Size2f.new
    assert_in_delta(0, size.width, 0.001)
    assert_in_delta(0, size.height, 0.001)

    size = Cv::Size2f.new(1.1, 2.2)
    assert_in_delta(1.1, size.width, 0.001)
    assert_in_delta(2.2, size.height, 0.001)

    original = Cv::Size2f.new(1.1, 2.2)
    size = original.clone
    assert_in_delta(1.1, size.width, 0.001)
    assert_in_delta(2.2, size.height, 0.001)
  end

  def test_width
    size = Cv::Size2f.new
    size.width = 1.1
    assert_in_delta(1.1, size.width, 0.001)
    size.width = 2.2
    assert_in_delta(2.2, size.width, 0.001)
  end

  def test_height
    size = Cv::Size2f.new
    size.height = 1.1
    assert_in_delta(1.1, size.height, 0.001)
    size.height = 2.2
    assert_in_delta(2.2, size.height, 0.001)
  end

  def test_inspect
    size = Cv::Size2f.new(1.1, 2.2)
    assert_equal('[1.1 x 2.2]', size.inspect)
  end
end
