#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class Point3dTest < OpenCVTestCase
  def test_initialize
    point = Cv::Point3d.new
    assert_in_delta(0, point.x, 0.001)
    assert_in_delta(0, point.y, 0.001)
    assert_in_delta(0, point.z, 0.001)

    point = Cv::Point3d.new(1.1, 2.2, 3.3)
    assert_in_delta(1.1, point.x, 0.001)
    assert_in_delta(2.2, point.y, 0.001)
    assert_in_delta(3.3, point.z, 0.001)

    original = Cv::Point3d.new(1.1, 2.2, 3.3)
    point = original.clone
    assert_in_delta(1.1, point.x, 0.001)
    assert_in_delta(2.2, point.y, 0.001)
    assert_in_delta(3.3, point.z, 0.001)
  end

  def test_x
    point = Cv::Point3d.new
    point.x = 1.1
    assert_in_delta(1.1, point.x, 0.001)
    point.x = 2.2
    assert_in_delta(2.2, point.x, 0.001)
  end

  def test_y
    point = Cv::Point3d.new
    point.y = 1.1
    assert_in_delta(1.1, point.y, 0.001)
    point.y = 2.2
    assert_in_delta(2.2, point.y, 0.001)
  end

  def test_z
    point = Cv::Point3d.new
    point.z = 1.1
    assert_in_delta(1.1, point.z, 0.001)
    point.z = 2.2
    assert_in_delta(2.2, point.z, 0.001)
  end

  def test_inspect
    point = Cv::Point3d.new(1.1, 2.2, 3.3)
    assert_equal('[1.1, 2.2, 3.3]', point.inspect)
  end
end

