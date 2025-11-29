#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class MomentsTest < OpenCVTestCase
  def get_moments
    mat = create_mat(128, 128, CV_8UC1) do |j, i|
      if j >= 32 and j < 96 and i >= 16 and i < 112
        0
      elsif j >= 16 and j < 112 and i >= 16 and i < 112
        128
      else
        255
      end
    end
    Cv::moments(mat.input_array)
  end

  def test_initialize
    moment = Cv::Moments.new
    assert_in_delta(0, moment.m00, 0.001)
    assert_in_delta(0, moment.m10, 0.001)
    assert_in_delta(0, moment.m01, 0.001)
    assert_in_delta(0, moment.m20, 0.001)
    assert_in_delta(0, moment.m11, 0.001)
    assert_in_delta(0, moment.m02, 0.001)
    assert_in_delta(0, moment.m30, 0.001)
    assert_in_delta(0, moment.m21, 0.001)
    assert_in_delta(0, moment.m12, 0.001)
    assert_in_delta(0, moment.m03, 0.001)
    assert_in_delta(0, moment.mu20, 0.001)
    assert_in_delta(0, moment.mu11, 0.001)
    assert_in_delta(0, moment.mu02, 0.001)
    assert_in_delta(0, moment.mu30, 0.001)
    assert_in_delta(0, moment.mu21, 0.001)
    assert_in_delta(0, moment.mu12, 0.001)
    assert_in_delta(0, moment.mu03, 0.001)
    assert_in_delta(0, moment.nu20, 0.001)
    assert_in_delta(0, moment.nu11, 0.001)
    assert_in_delta(0, moment.nu02, 0.001)
    assert_in_delta(0, moment.nu30, 0.001)
    assert_in_delta(0, moment.nu21, 0.001)
    assert_in_delta(0, moment.nu12, 0.001)
    assert_in_delta(0, moment.nu03, 0.001)
  end

  def test_moments
    moment = get_moments
    assert_in_delta(2221056, moment.m00, 0.001)
    assert_in_delta(141037056, moment.m10, 0.001)
    assert_in_delta(141037056, moment.m01, 0.001)
    assert_in_delta(13157049856.0, moment.m20, 0.001)
    assert_in_delta(8955853056.0, moment.m11, 0.001)
    assert_in_delta(13492594176, moment.m02, 0.001)
    assert_in_delta(1369024659456, moment.m30, 0.001)
    # assert_in_delta(856779730176, moment.m21, 0.001)
    # assert_in_delta(0, moment.m12, 0.001)
    # assert_in_delta(0, moment.m03, 0.001)
    # assert_in_delta(0, moment.mu20, 0.001)
    # assert_in_delta(0, moment.mu11, 0.001)
    # assert_in_delta(0, moment.mu02, 0.001)
    # assert_in_delta(0, moment.mu30, 0.001)
    # assert_in_delta(0, moment.mu21, 0.001)
    # assert_in_delta(0, moment.mu12, 0.001)
    # assert_in_delta(0, moment.mu03, 0.001)
    # assert_in_delta(0, moment.nu20, 0.001)
    # assert_in_delta(0, moment.nu11, 0.001)
    # assert_in_delta(0, moment.nu02, 0.001)
    # assert_in_delta(0, moment.nu30, 0.001)
    # assert_in_delta(0, moment.nu21, 0.001)
    # assert_in_delta(0, moment.nu12, 0.001)
    # assert_in_delta(0, moment.nu03, 0.001)
  end

  def test_hu
    moments = get_moments
    result = Cv::Mat.new
    Cv::hu_moments(moments, result.output_array)

    expected = [0.001771291088085849,
                4.62659781690056e-09,
                0,
                0,
                0,
                0,
                0]

    assert_in_delta_array(expected, result.to_a)
  end
end
