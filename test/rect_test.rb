#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class RectTest < OpenCVTestCase
  def test_initialize
    rect = Cv::Rect.new
    assert_equal(0, rect.x)
    assert_equal(0, rect.y)
    assert_equal(0, rect.width)
    assert_equal(0, rect.height)

    rect = Cv::Rect.new(10, 20, 30, 40)
    assert_equal(10, rect.x)
    assert_equal(20, rect.y)
    assert_equal(30, rect.width)
    assert_equal(40, rect.height)

    original = Cv::Rect.new(10, 20, 30, 40)
    clone = original.clone
    assert_equal(10, clone.x)
    assert_equal(20, clone.y)
    assert_equal(30, clone.width)
    assert_equal(40, clone.height)
  end

  def test_x
    rect = Cv::Rect.new
    rect.x = 100
    assert_equal(100, rect.x)
    rect.x = 200
    assert_equal(200, rect.x)
  end

  def test_y
    rect = Cv::Rect.new
    rect.y = 100
    assert_equal(100, rect.y)
    rect.y = 200
    assert_equal(200, rect.y)
  end

  def test_corners
    rect = Cv::Rect.new(5, 4, 10, 10)
    assert_equal(Cv::Point.new(5, 4), rect.tl)
    assert_equal(Cv::Point.new(15, 14), rect.br)
  end

  def test_width
    rect = Cv::Rect.new
    rect.width = 100
    assert_equal(100, rect.width)
    rect.width = 200
    assert_equal(200, rect.width)
  end

  def test_height
    rect = Cv::Rect.new
    rect.height = 100
    assert_equal(100, rect.height)
    rect.height = 200
    assert_equal(200, rect.height)
  end

  def test_size
    rect = Cv::Rect.new(10, 20, 30, 40)
    assert_equal(Cv::Size.new(30, 40), rect.size)
  end

  def test_area
    rect = Cv::Rect.new(10, 20, 30, 40)
    assert_equal(1200, rect.area)
  end

  def test_empty
    rect = Cv::Rect.new
    assert(rect.empty?)

    rect = Cv::Rect.new(10, 20, 30, 40)
    refute(rect.empty?)
  end

  def test_contains
    point = Cv::Point.new(3, 4)
    rect = Cv::Rect.new(2, 2, 10, 10)
    inside = rect.contains?(point)
    assert(inside)
  end
end
