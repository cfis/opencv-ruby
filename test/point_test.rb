#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class PointTest < OpenCVTestCase
  def test_initialize
    point = Cv::Point.new
    assert_equal(0, point.x)
    assert_equal(0, point.y)

    point = Cv::Point.new(10, 20)
    assert_equal(10, point.x)
    assert_equal(20, point.y)

    point = Cv::Point.new(Cv::Size.new(11, 21))
    assert_equal(11, point.x)
    assert_equal(21, point.y)

    point = Cv::Point.new(Cv::Vec2i.new(12, 22))
    assert_equal(12, point.x)
    assert_equal(22, point.y)

    original = Cv::Point.new(13, 33)
    clone = original.clone
    refute_same(original, clone)
    assert_equal(13, clone.x)
    assert_equal(33, clone.y)
  end

  def test_x
    point = Cv::Point.new
    point.x = 100
    assert_equal(100, point.x)
    point.x = 200
    assert_equal(200, point.x)
  end

  def test_y
    point = Cv::Point.new
    point.y = 100
    assert_equal(100, point.y)
    point.y = 200
    assert_equal(200, point.y)
  end

  def test_equal
    point1 = Cv::Point.new(9, 10)
    point2 = Cv::Point.new(9, 10)
    point3 = Cv::Point.new(99, 100)
    assert_equal(point1, point2)
    refute_equal(point1, point3)
  end

  def test_add
    point1 = Cv::Point.new(4, 3)
    point2 = Cv::Point.new(9, 11)
    point3 = point1 + point2
    assert_equal(13, point3.x)
    assert_equal(14, point3.y)
  end

  def test_divide
    point1 = Cv::Point.new(4, 3)
    point2 = Cv::Point.new(9, 11)
    point3 = point1 / point2
    assert_equal(13, point3.x)
    refute_equal(14, point3.y)
  end

  def test_multiply
    point1 = Cv::Point.new(4, 3)
    point2 = point1 * 4
    assert_equal(16, point2.x)
    assert_equal(12, point2.y)
  end

  def test_divide
    point1 = Cv::Point.new(16, 12)
    point2 = point1 / 4
    assert_equal(4, point2.x)
    assert_equal(3, point2.y)
  end

  def test_to_vec
    point = Cv::Point.new(14, 44)
    vec = point.to_vec
    assert_kind_of(Cv::Vec2i, vec)
    assert_equal([14, 44], vec.to_a)
  end

  def test_dot
    point1 = Cv::Point.new(3, 4)
    point2 = Cv::Point.new(5, 6)
    dot = point1.dot(point2)
    assert_kind_of(Integer, dot)
    assert_equal(39, dot)
  end

  def test_dddot
    point1 = Cv::Point.new(3, 4)
    point2 = Cv::Point.new(5, 6)
    dot = point1.ddot(point2)
    assert_kind_of(Float, dot)
    assert_equal(39.0, dot)
  end

  def test_cross
    point1 = Cv::Point.new(3, 4)
    point2 = Cv::Point.new(5, 6)
    cross = point1.cross(point2)
    assert_kind_of(Float, cross)
    assert_equal(-2.0, cross)
  end

  def test_norm
    point = Cv::Point.new(3, 4)
    norm = point.norm
    assert_equal(5, norm)
  end

  def test_inside
    point = Cv::Point.new(3, 4)
    rect = Cv::Rect.new(2, 2, 10, 10)
    inside = point.inside?(rect)
    assert(inside)
  end

  def test_inspect
    point = Cv::Point.new(10, 20)
    assert_equal('[10, 20]', point.inspect)
  end
end