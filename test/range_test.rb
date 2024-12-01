#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class RangeTest < OpenCVTestCase
  def test_initialize
    range = Cv::Range.new
    assert_equal(0, range.start)
    assert_equal(0, range.end)
    assert_equal(0, range.size)
    assert(range.empty?)

    range = Cv::Range.new(5, 9)
    assert_equal(5, range.start)
    assert_equal(9, range.end)
    assert_equal(4, range.size)
    refute(range.empty?)
  end

  def test_all
    range = Cv::Range.all
    assert_equal(-2147483648, range.start)
    assert_equal(2147483647, range.end)
    assert_equal(-1, range.size)
    refute(range.empty?)
  end
end
