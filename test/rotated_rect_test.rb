#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class RotatedRectTest < OpenCVTestCase
  def test_initialize
    rotated_rect = Cv::RotatedRect.new
    assert_equal(0, rotated_rect.center.x)
    assert_equal(0, rotated_rect.center.y)
    assert_equal(0, rotated_rect.size.width)
    assert_equal(0, rotated_rect.size.height)
    assert_equal(0, rotated_rect.angle)

    center = Cv::Point2f.new(7, 8)
    size = Cv::Size2f.new(12, 15)
    angle = 3.0
    rotated_rect = Cv::RotatedRect.new(center, size, angle)
    assert_equal(7.0, rotated_rect.center.x)
    assert_equal(8.0, rotated_rect.center.y)
    assert_equal(12.0, rotated_rect.size.width)
    assert_equal(15.0, rotated_rect.size.height)
    assert_equal(3.0, rotated_rect.angle)
  end

  def test_points
    center = Cv::Point2f.new(9.9, 14.8)
    size = Cv::Size2f.new(16.12, 44.15)
    angle = 45.0
    rotated_rect = Cv::RotatedRect.new(center, size, angle)

    points = Std::Vector≺cv꞉꞉Point_≺float≻≻.new
    rotated_rect.points(points)

    assert_equal(4, points.size)

    point = points[0]
    assert_kind_of(Cv::Point2f, point)
    assert_in_delta(-11.408, point.x)
    assert_in_delta(24.71, point.y)

    point = points[1]
    assert_kind_of(Cv::Point2f, point)
    assert_in_delta(19.810, point.x)
    assert_in_delta(-6.508, point.y)

    point = points[2]
    assert_kind_of(Cv::Point2f, point)
    assert_in_delta(31.208, point.x)
    assert_in_delta(4.889, point.y)

    point = points[3]
    assert_kind_of(Cv::Point2f, point)
    assert_in_delta(-0.010, point.x)
    assert_in_delta(36.108, point.y)
  end

  def test_bounding_rect
    center = Cv::Point2f.new(44.2, 16.3)
    size = Cv::Size2f.new(8.8, 15.15)
    angle = 19.0
    rotated_rect = Cv::RotatedRect.new(center, size, angle)

    expected = Cv::Rect.new(37, 7, 15, 19)
    rect = rotated_rect.bounding_rect
    assert_equal(expected, rect)
  end

  def test_bounding_rect2f
    center = Cv::Point2f.new(44.2, 16.3)
    size = Cv::Size2f.new(8.8, 15.15)
    angle = 19.0
    rotated_rect = Cv::RotatedRect.new(center, size, angle)

    rect = rotated_rect.bounding_rect2f
    assert_in_delta(37.5735, rect.x)
    assert_in_delta(7.7052, rect.y)
    assert_in_delta(13.2529, rect.width)
    assert_in_delta(17.1896, rect.height)
  end
end
