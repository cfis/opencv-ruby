#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class SizeTest < OpenCVTestCase
  def test_initialize
    size = Cv::Size.new
    assert_equal(0, size.width)
    assert_equal(0, size.height)

    size = Cv::Size.new(10, 20)
    assert_equal(10, size.width)
    assert_equal(20, size.height)

    assert_raises(ArgumentError) do
      Cv::Size.new(1, 2, 3)
    end
  end

  def test_clone
    original = Cv::Size.new(30, 31)
    clone = original.clone
    assert_equal(original.width, clone.width)
    assert_equal(original.height, clone.height)
  end

  def test_dup
    original = Cv::Size.new(30, 31)
    clone = original.dup
    assert_equal(original.width, clone.width)
    assert_equal(original.height, clone.height)
  end

  def test_width
    size = Cv::Size.new
    size.width = 100
    assert_equal(100, size.width)
    size.width = 200
    assert_equal(200, size.width)
  end

  def test_height
    size = Cv::Size.new
    size.height = 100
    assert_equal(100, size.height)
    size.height = 200
    assert_equal(200, size.height)
  end

  def test_height
    size = Cv::Size.new(5, 6)
    assert_equal(30, size.area)
  end

  def test_height
    size = Cv::Size.new(12, 6)
    assert_equal(2.0, size.aspect_ratio)
  end

  def test_empty
    size = Cv::Size.new
    assert(size.empty?)

    size = Cv::Size.new(1, 3)
    refute(size.empty?)
  end

  def test_equal
    size1 = Cv::Size.new(5, 6)
    size2 = Cv::Size.new(5, 6)
    assert_equal(size1, size2)
  end

  def test_add
    size1 = Cv::Size.new(2, 3)
    size2 = Cv::Size.new(4, 5)
    size3 = size1 + size2

    assert_equal(6, size3.width)
    assert_equal(8, size3.height)
  end

  def test_subtract
    size1 = Cv::Size.new(2, 3)
    size2 = Cv::Size.new(4, 5)
    size3 = size1 - size2

    assert_equal(-2, size3.width)
    assert_equal(-2, size3.height)
  end

  def test_multiply
    size1 = Cv::Size.new(2, 3)
    size1 *= 2

    assert_equal(4, size1.width)
    assert_equal(6, size1.height)

    size2 = size1 * 3
    assert_equal(4, size1.width)
    assert_equal(6, size1.height)
    assert_equal(12, size2.width)
    assert_equal(18, size2.height)
  end

  def test_divide
    size1 = Cv::Size.new(30, 24)
    size1 /= 2

    assert_equal(15, size1.width)
    assert_equal(12, size1.height)

    size2 = size1 / 3
    assert_equal(5, size2.width)
    assert_equal(4, size2.height)

    assert_equal(15, size1.width)
    assert_equal(12, size1.height)
  end

  def test_inspect
    size = Cv::Size.new(10, 20)
    assert_equal('[10 x 20]', size.inspect)
  end

  def test_to_s
    size = Cv::Size.new(10, 20)
    assert_equal('<Cv::Size:10x20>', size.to_s)

    size = Cv::Size2i.new(10, 20)
    assert_equal('<Cv::Size:10x20>', size.to_s)

    size = Cv::Size2l.new(10, 20)
    assert_equal('<Cv::Size2l:10x20>', size.to_s)

    size = Cv::Size2f.new(10.1, 20.2)
    assert_equal('<Cv::Size2f:10.1x20.2>', size.to_s)

    size = Cv::Size2d.new(10, 33.3)
    assert_equal('<Cv::Size2d:10x33.3>', size.to_s)
  end
end
