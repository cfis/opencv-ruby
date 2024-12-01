#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class ScalarTest < OpenCVTestCase
  def test_initialize
    scalar = Cv::Scalar.new
    assert_equal([0, 0, 0, 0], scalar.to_a)

    scalar = Cv::Scalar.new(1.1)
    assert_equal([1.1, 0, 0, 0], scalar.to_a)

    scalar = Cv::Scalar.new(1.1, 2.2)
    assert_equal([1.1, 2.2, 0, 0], scalar.to_a)

    scalar = Cv::Scalar.new(1.1, 2.2, 3.3)
    assert_equal([1.1, 2.2, 3.3, 0], scalar.to_a)

    scalar = Cv::Scalar.new(1.1, 2.2, 3.3, 4.4)
    assert_equal([1.1, 2.2, 3.3, 4.4], scalar.to_a)

    scalar = Cv::Scalar.new(10, 20, 30, 40)
    assert_equal([10.0, 20.0, 30.0, 40.0], scalar.to_a)
  end

  def test_all
    scalar = Cv::Scalar.all(4.44)
    assert_equal([4.44, 4.44, 4.44, 4.44], scalar.to_a)
  end

  def test_clone
    scalar_original = Cv::Scalar.new(1.1, 2.2, 3.3, 4.4)
    scalar_clone = scalar_original.clone
    refute_same(scalar_original, scalar_clone)
    assert_equal(scalar_original.to_a, scalar_clone.to_a)
  end

  def test_aref
    scalar = Cv::Scalar.new(10, 20.2, 0.31, 40)
    assert_equal(10, scalar[0])
    assert_equal(20.2, scalar[1])
    assert_equal(0.31, scalar[2])
    assert_equal(40, scalar[3])
  end

  def test_aset
    scalar = Cv::Scalar.new
    [10, 20, 30.3, 0.4].each.with_index do |x, i|
      scalar[i] = x
    end
  end

  def test_to_s
    assert_equal("<Cv::Scalar:[10.0,20.0,30.0,40.0]>", Cv::Scalar.new(10, 20, 30, 40).to_s)
    assert_equal("<Cv::Scalar:[0.1,0.2,0.3,0.4]>", Cv::Scalar.new(0.1, 0.2, 0.3, 0.4).to_s)
  end
end
