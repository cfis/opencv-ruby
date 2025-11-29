#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class Point2dTest < OpenCVTestCase
  def test_initialize
    point = Cv::Point2d.new
    assert_in_delta(0, point.x, 0.001)
    assert_in_delta(0, point.y, 0.001)

    point = Cv::Point2d.new(1.1, 2.2)
    assert_in_delta(1.1, point.x, 0.001)
    assert_in_delta(2.2, point.y, 0.001)

    original = Cv::Point2d.new(1.1, 2.2)
    point = original.clone
    assert_in_delta(1.1, point.x, 0.001)
    assert_in_delta(2.2, point.y, 0.001)
  end

  def test_x
    point = Cv::Point2d.new
    point.x = 1.1
    assert_in_delta(1.1, point.x, 0.001)
    point.x = 2.2
    assert_in_delta(2.2, point.x, 0.001)
  end

  def test_y
    point = Cv::Point2d.new
    point.y = 1.1
    assert_in_delta(1.1, point.y, 0.001)
    point.y = 2.2
    assert_in_delta(2.2, point.y, 0.001)
  end

  def test_inspect
    point = Cv::Point2d.new(1.1, 2.2)
    assert_equal('[1.1, 2.2]', point.inspect)
  end
end

