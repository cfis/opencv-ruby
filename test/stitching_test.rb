#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class StitchingTest < OpenCVTestCase
  def setup
    # Create test images
    @image1 = Cv::Mat.new(200, 200, CV_8UC3, Cv::Scalar.new(100, 100, 100))
    @image2 = Cv::Mat.new(200, 200, CV_8UC3, Cv::Scalar.new(150, 150, 150))

    # Add some content to the images
    Cv::rectangle(@image1.input_output_array, Cv::Point.new(50, 50), Cv::Point.new(150, 150), Cv::Scalar.new(255, 0, 0), -1)
    Cv::rectangle(@image2.input_output_array, Cv::Point.new(25, 50), Cv::Point.new(125, 150), Cv::Scalar.new(0, 255, 0), -1)
  end

  # ============ Stitcher Creation ============
  def test_stitcher_create_panorama
    stitcher = Cv::Stitcher.create(Cv::Stitcher::Mode::PANORAMA)
    refute_nil(stitcher)
    assert_instance_of(Cv::Stitcher, stitcher)
  end

  def test_stitcher_create_scans
    stitcher = Cv::Stitcher.create(Cv::Stitcher::Mode::SCANS)
    refute_nil(stitcher)
  end

  # ============ Resolution Settings ============
  def test_stitcher_get_set_registration_resol
    stitcher = Cv::Stitcher.create(Cv::Stitcher::Mode::PANORAMA)
    stitcher.set_registration_resol(0.5)
    assert_in_delta(0.5, stitcher.registration_resol, 0.01)
  end

  def test_stitcher_get_set_seam_estimation_resol
    stitcher = Cv::Stitcher.create(Cv::Stitcher::Mode::PANORAMA)
    stitcher.set_seam_estimation_resol(0.1)
    assert_in_delta(0.1, stitcher.seam_estimation_resol, 0.01)
  end

  def test_stitcher_get_set_compositing_resol
    stitcher = Cv::Stitcher.create(Cv::Stitcher::Mode::PANORAMA)
    stitcher.set_compositing_resol(1.0)
    assert_in_delta(1.0, stitcher.compositing_resol, 0.01)
  end

  # ============ Confidence Threshold ============
  def test_stitcher_get_set_pano_confidence_thresh
    stitcher = Cv::Stitcher.create(Cv::Stitcher::Mode::PANORAMA)
    stitcher.set_pano_confidence_thresh(0.5)
    assert_in_delta(0.5, stitcher.pano_confidence_thresh, 0.01)
  end

  # ============ Wave Correction ============
  def test_stitcher_get_set_wave_correction
    stitcher = Cv::Stitcher.create(Cv::Stitcher::Mode::PANORAMA)
    stitcher.set_wave_correction(true)
    assert(stitcher.wave_correction?)
  end

  def test_stitcher_get_set_wave_correct_kind
    stitcher = Cv::Stitcher.create(Cv::Stitcher::Mode::PANORAMA)
    stitcher.set_wave_correct_kind(Cv::Detail::WaveCorrectKind::WAVE_CORRECT_VERT)
    assert_equal(Cv::Detail::WaveCorrectKind::WAVE_CORRECT_VERT, stitcher.wave_correct_kind)
  end

  # ============ Interpolation Flags ============
  def test_stitcher_get_set_interpolation_flags
    stitcher = Cv::Stitcher.create(Cv::Stitcher::Mode::PANORAMA)
    stitcher.set_interpolation_flags(Cv::InterpolationFlags::INTER_CUBIC)
    assert_equal(Cv::InterpolationFlags::INTER_CUBIC, stitcher.interpolation_flags)
  end

  # ============ Component Methods (return indices/masks) ============
  def test_stitcher_component
    stitcher = Cv::Stitcher.create(Cv::Stitcher::Mode::PANORAMA)
    # Before stitching, component should return empty or all indices
    component = stitcher.component
    refute_nil(component)
  end

  def test_stitcher_result_mask
    stitcher = Cv::Stitcher.create(Cv::Stitcher::Mode::PANORAMA)
    # Before stitching, result_mask should exist but may be empty
    mask = stitcher.result_mask
    refute_nil(mask)
  end

  # ============ Work Scale ============
  def test_stitcher_work_scale
    stitcher = Cv::Stitcher.create(Cv::Stitcher::Mode::PANORAMA)
    # work_scale should return a scale factor
    scale = stitcher.work_scale
    refute_nil(scale)
  end

  # Note: Full stitching tests require multiple overlapping images
  # which are complex to create programmatically. These tests focus
  # on the API surface and configuration methods.
end
