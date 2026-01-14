#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class PhotoTest < OpenCVTestCase
  def setup
    # Create a test image for denoising/filtering tests
    @color_image = Cv::Mat.new(100, 100, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    @gray_image = Cv::Mat.new(100, 100, CV_8UC1, Cv::Scalar.new(128))

    # Add some noise
    10.times do
      x = rand(100)
      y = rand(100)
      @gray_image[y, x] = rand(256)
    end
  end

  # ============ Inpainting ============
  def test_inpaint
    # Create an image with a "damaged" region
    src = Cv::Mat.new(100, 100, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    mask = Cv::Mat.new(100, 100, CV_8UC1, Cv::Scalar.new(0))

    # Mark a region to inpaint
    Cv::rectangle(mask.input_output_array, Cv::Point.new(40, 40), Cv::Point.new(60, 60), Cv::Scalar.new(255), -1)

    dst = Cv::Mat.new
    Cv.inpaint(src.input_array, mask.input_array, dst.output_array, 3.0, Cv::INPAINT_TELEA)

    assert_equal(src.rows, dst.rows)
    assert_equal(src.cols, dst.cols)
    assert_equal(src.type, dst.type)
  end

  def test_inpaint_ns_method
    src = Cv::Mat.new(100, 100, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    mask = Cv::Mat.new(100, 100, CV_8UC1, Cv::Scalar.new(0))
    Cv::rectangle(mask.input_output_array, Cv::Point.new(40, 40), Cv::Point.new(60, 60), Cv::Scalar.new(255), -1)

    dst = Cv::Mat.new
    Cv.inpaint(src.input_array, mask.input_array, dst.output_array, 3.0, Cv::INPAINT_NS)

    refute(dst.empty?)
  end

  # ============ Denoising ============
  def test_fast_nl_means_denoising
    dst = Cv::Mat.new
    Cv.fast_nl_means_denoising(@gray_image.input_array, dst.output_array, 3.0, 7, 21)

    assert_equal(@gray_image.rows, dst.rows)
    assert_equal(@gray_image.cols, dst.cols)
  end

  def test_fast_nl_means_denoising_default_params
    dst = Cv::Mat.new
    Cv.fast_nl_means_denoising(@gray_image.input_array, dst.output_array)

    refute(dst.empty?)
  end

  def test_fast_nl_means_denoising_colored
    dst = Cv::Mat.new
    Cv.fast_nl_means_denoising_colored(@color_image.input_array, dst.output_array, 3.0, 3.0, 7, 21)

    assert_equal(@color_image.rows, dst.rows)
    assert_equal(@color_image.cols, dst.cols)
    assert_equal(@color_image.channels, dst.channels)
  end

  def test_fast_nl_means_denoising_colored_default_params
    dst = Cv::Mat.new
    Cv.fast_nl_means_denoising_colored(@color_image.input_array, dst.output_array)

    refute(dst.empty?)
  end

  # ============ Tonemap ============
  def test_create_tonemap
    tonemap = Cv.create_tonemap
    refute_nil(tonemap)
    assert_instance_of(Cv::Ptr≺cv꞉꞉Tonemap≻, tonemap)
  end

  def test_create_tonemap_with_gamma
    tonemap = Cv.create_tonemap(2.2)
    assert_in_delta(2.2, tonemap.get_gamma, 0.01)
  end

  def test_tonemap_get_set_gamma
    tonemap = Cv.create_tonemap
    tonemap.set_gamma(1.5)
    assert_in_delta(1.5, tonemap.get_gamma, 0.01)
  end

  def test_tonemap_process
    # Create a simple HDR-like float image
    hdr = Cv::Mat.new(100, 100, CV_32FC3, Cv::Scalar.new(0.5, 0.5, 0.5))

    tonemap = Cv.create_tonemap(2.2)
    ldr = Cv::Mat.new
    tonemap.process(hdr.input_array, ldr.output_array)

    assert_equal(hdr.rows, ldr.rows)
    assert_equal(hdr.cols, ldr.cols)
  end

  # ============ TonemapDrago ============
  def test_create_tonemap_drago
    tonemap = Cv.create_tonemap_drago
    refute_nil(tonemap)
    assert_instance_of(Cv::Ptr≺cv꞉꞉TonemapDrago≻, tonemap)
  end

  def test_create_tonemap_drago_with_params
    tonemap = Cv.create_tonemap_drago(2.2, 0.8, 0.9)
    assert_in_delta(2.2, tonemap.get_gamma, 0.01)
    assert_in_delta(0.8, tonemap.get_saturation, 0.01)
    assert_in_delta(0.9, tonemap.get_bias, 0.01)
  end

  def test_tonemap_drago_get_set_saturation
    tonemap = Cv.create_tonemap_drago
    tonemap.set_saturation(0.5)
    assert_in_delta(0.5, tonemap.get_saturation, 0.01)
  end

  def test_tonemap_drago_get_set_bias
    tonemap = Cv.create_tonemap_drago
    tonemap.set_bias(0.7)
    assert_in_delta(0.7, tonemap.get_bias, 0.01)
  end

  # ============ TonemapReinhard ============
  def test_create_tonemap_reinhard
    tonemap = Cv.create_tonemap_reinhard
    refute_nil(tonemap)
    assert_instance_of(Cv::Ptr≺cv꞉꞉TonemapReinhard≻, tonemap)
  end

  def test_create_tonemap_reinhard_with_params
    tonemap = Cv.create_tonemap_reinhard(2.2, 0.5, 0.8, 0.3)
    assert_in_delta(2.2, tonemap.get_gamma, 0.01)
    assert_in_delta(0.5, tonemap.get_intensity, 0.01)
    assert_in_delta(0.8, tonemap.get_light_adaptation, 0.01)
    assert_in_delta(0.3, tonemap.get_color_adaptation, 0.01)
  end

  def test_tonemap_reinhard_get_set_intensity
    tonemap = Cv.create_tonemap_reinhard
    tonemap.set_intensity(0.5)
    assert_in_delta(0.5, tonemap.get_intensity, 0.01)
  end

  def test_tonemap_reinhard_get_set_light_adaptation
    tonemap = Cv.create_tonemap_reinhard
    tonemap.set_light_adaptation(0.7)
    assert_in_delta(0.7, tonemap.get_light_adaptation, 0.01)
  end

  def test_tonemap_reinhard_get_set_color_adaptation
    tonemap = Cv.create_tonemap_reinhard
    tonemap.set_color_adaptation(0.3)
    assert_in_delta(0.3, tonemap.get_color_adaptation, 0.01)
  end

  # ============ TonemapMantiuk ============
  def test_create_tonemap_mantiuk
    tonemap = Cv.create_tonemap_mantiuk
    refute_nil(tonemap)
    assert_instance_of(Cv::Ptr≺cv꞉꞉TonemapMantiuk≻, tonemap)
  end

  def test_create_tonemap_mantiuk_with_params
    tonemap = Cv.create_tonemap_mantiuk(2.2, 0.6, 0.9)
    assert_in_delta(2.2, tonemap.get_gamma, 0.01)
    assert_in_delta(0.6, tonemap.get_scale, 0.01)
    assert_in_delta(0.9, tonemap.get_saturation, 0.01)
  end

  def test_tonemap_mantiuk_get_set_scale
    tonemap = Cv.create_tonemap_mantiuk
    tonemap.set_scale(0.5)
    assert_in_delta(0.5, tonemap.get_scale, 0.01)
  end

  def test_tonemap_mantiuk_get_set_saturation
    tonemap = Cv.create_tonemap_mantiuk
    tonemap.set_saturation(0.8)
    assert_in_delta(0.8, tonemap.get_saturation, 0.01)
  end

  # ============ AlignMTB ============
  def test_create_align_mtb
    align = Cv.create_align_mtb
    refute_nil(align)
    assert_instance_of(Cv::Ptr≺cv꞉꞉AlignMTB≻, align)
  end

  def test_create_align_mtb_with_params
    align = Cv.create_align_mtb(8, 5, false)
    assert_equal(8, align.get_max_bits)
    assert_equal(5, align.get_exclude_range)
    assert_equal(false, align.get_cut?)
  end

  def test_align_mtb_get_set_max_bits
    align = Cv.create_align_mtb
    align.set_max_bits(10)
    assert_equal(10, align.get_max_bits)
  end

  def test_align_mtb_get_set_exclude_range
    align = Cv.create_align_mtb
    align.set_exclude_range(8)
    assert_equal(8, align.get_exclude_range)
  end

  def test_align_mtb_get_set_cut
    align = Cv.create_align_mtb
    align.set_cut(false)
    assert_equal(false, align.get_cut?)
  end

  def test_align_mtb_calculate_shift
    align = Cv.create_align_mtb

    img0 = Cv::Mat.new(100, 100, CV_8UC1, Cv::Scalar.new(128))
    img1 = Cv::Mat.new(100, 100, CV_8UC1, Cv::Scalar.new(128))

    shift = align.calculate_shift(img0.input_array, img1.input_array)
    assert_instance_of(Cv::Point, shift)
  end

  # ============ CalibrateDebevec ============
  def test_create_calibrate_debevec
    calibrate = Cv.create_calibrate_debevec
    refute_nil(calibrate)
    assert_instance_of(Cv::Ptr≺cv꞉꞉CalibrateDebevec≻, calibrate)
  end

  def test_create_calibrate_debevec_with_params
    calibrate = Cv.create_calibrate_debevec(100, 20.0, true)
    assert_equal(100, calibrate.get_samples)
    assert_in_delta(20.0, calibrate.get_lambda, 0.01)
    assert_equal(true, calibrate.get_random?)
  end

  def test_calibrate_debevec_get_set_samples
    calibrate = Cv.create_calibrate_debevec
    calibrate.set_samples(80)
    assert_equal(80, calibrate.get_samples)
  end

  def test_calibrate_debevec_get_set_lambda
    calibrate = Cv.create_calibrate_debevec
    calibrate.set_lambda(15.0)
    assert_in_delta(15.0, calibrate.get_lambda, 0.01)
  end

  def test_calibrate_debevec_get_set_random
    calibrate = Cv.create_calibrate_debevec
    calibrate.set_random(true)
    assert_equal(true, calibrate.get_random?)
  end

  # ============ CalibrateRobertson ============
  def test_create_calibrate_robertson
    calibrate = Cv.create_calibrate_robertson
    refute_nil(calibrate)
    assert_instance_of(Cv::Ptr≺cv꞉꞉CalibrateRobertson≻, calibrate)
  end

  def test_create_calibrate_robertson_with_params
    calibrate = Cv.create_calibrate_robertson(50, 0.02)
    assert_equal(50, calibrate.get_max_iter)
    assert_in_delta(0.02, calibrate.get_threshold, 0.001)
  end

  def test_calibrate_robertson_get_set_max_iter
    calibrate = Cv.create_calibrate_robertson
    calibrate.set_max_iter(40)
    assert_equal(40, calibrate.get_max_iter)
  end

  def test_calibrate_robertson_get_set_threshold
    calibrate = Cv.create_calibrate_robertson
    calibrate.set_threshold(0.02)
    assert_in_delta(0.02, calibrate.get_threshold, 0.001)
  end

  # ============ MergeDebevec ============
  def test_create_merge_debevec
    merge = Cv.create_merge_debevec
    refute_nil(merge)
    assert_instance_of(Cv::Ptr≺cv꞉꞉MergeDebevec≻, merge)
  end

  # ============ MergeMertens ============
  def test_create_merge_mertens
    merge = Cv.create_merge_mertens
    refute_nil(merge)
    assert_instance_of(Cv::Ptr≺cv꞉꞉MergeMertens≻, merge)
  end

  def test_create_merge_mertens_with_params
    merge = Cv.create_merge_mertens(0.8, 0.9, 0.1)
    assert_in_delta(0.8, merge.get_contrast_weight, 0.01)
    assert_in_delta(0.9, merge.get_saturation_weight, 0.01)
    assert_in_delta(0.1, merge.get_exposure_weight, 0.01)
  end

  def test_merge_mertens_get_set_contrast_weight
    merge = Cv.create_merge_mertens
    merge.set_contrast_weight(0.5)
    assert_in_delta(0.5, merge.get_contrast_weight, 0.01)
  end

  def test_merge_mertens_get_set_saturation_weight
    merge = Cv.create_merge_mertens
    merge.set_saturation_weight(0.7)
    assert_in_delta(0.7, merge.get_saturation_weight, 0.01)
  end

  def test_merge_mertens_get_set_exposure_weight
    merge = Cv.create_merge_mertens
    merge.set_exposure_weight(0.2)
    assert_in_delta(0.2, merge.get_exposure_weight, 0.01)
  end

  # ============ MergeRobertson ============
  def test_create_merge_robertson
    merge = Cv.create_merge_robertson
    refute_nil(merge)
    assert_instance_of(Cv::Ptr≺cv꞉꞉MergeRobertson≻, merge)
  end

  # ============ Edge-preserving filtering ============
  def test_edge_preserving_filter
    dst = Cv::Mat.new
    Cv.edge_preserving_filter(@color_image.input_array, dst.output_array, Cv::RECURS_FILTER, 60.0, 0.4)

    assert_equal(@color_image.rows, dst.rows)
    assert_equal(@color_image.cols, dst.cols)
  end

  def test_edge_preserving_filter_normconv
    dst = Cv::Mat.new
    Cv.edge_preserving_filter(@color_image.input_array, dst.output_array, Cv::NORMCONV_FILTER)

    refute(dst.empty?)
  end

  # ============ Detail Enhance ============
  def test_detail_enhance
    dst = Cv::Mat.new
    Cv.detail_enhance(@color_image.input_array, dst.output_array, 10.0, 0.15)

    assert_equal(@color_image.rows, dst.rows)
    assert_equal(@color_image.cols, dst.cols)
  end

  def test_detail_enhance_default_params
    dst = Cv::Mat.new
    Cv.detail_enhance(@color_image.input_array, dst.output_array)

    refute(dst.empty?)
  end

  # ============ Pencil Sketch ============
  def test_pencil_sketch
    dst1 = Cv::Mat.new
    dst2 = Cv::Mat.new
    Cv.pencil_sketch(@color_image.input_array, dst1.output_array, dst2.output_array, 60.0, 0.07, 0.02)

    # dst1 is grayscale pencil sketch
    assert_equal(@color_image.rows, dst1.rows)
    assert_equal(@color_image.cols, dst1.cols)

    # dst2 is color pencil sketch
    assert_equal(@color_image.rows, dst2.rows)
    assert_equal(@color_image.cols, dst2.cols)
  end

  # ============ Stylization ============
  def test_stylization
    dst = Cv::Mat.new
    Cv.stylization(@color_image.input_array, dst.output_array, 60.0, 0.45)

    assert_equal(@color_image.rows, dst.rows)
    assert_equal(@color_image.cols, dst.cols)
  end

  def test_stylization_default_params
    dst = Cv::Mat.new
    Cv.stylization(@color_image.input_array, dst.output_array)

    refute(dst.empty?)
  end

  # ============ Decolor ============
  def test_decolor
    grayscale = Cv::Mat.new
    color_boost = Cv::Mat.new
    Cv.decolor(@color_image.input_array, grayscale.output_array, color_boost.output_array)

    assert_equal(@color_image.rows, grayscale.rows)
    assert_equal(@color_image.cols, grayscale.cols)
    assert_equal(1, grayscale.channels)

    assert_equal(@color_image.rows, color_boost.rows)
    assert_equal(@color_image.cols, color_boost.cols)
  end

  # ============ Seamless Cloning ============
  def test_seamless_clone
    # Create source image (object to clone)
    src = Cv::Mat.new(50, 50, CV_8UC3, Cv::Scalar.new(255, 0, 0))

    # Create destination image
    dst_img = Cv::Mat.new(100, 100, CV_8UC3, Cv::Scalar.new(128, 128, 128))

    # Create mask (all white = use entire source)
    mask = Cv::Mat.new(50, 50, CV_8UC1, Cv::Scalar.new(255))

    # Center point in destination
    center = Cv::Point.new(50, 50)

    blend = Cv::Mat.new
    Cv.seamless_clone(src.input_array, dst_img.input_array, mask.input_array, center, blend.output_array, Cv::SeamlessCloneFlags::NORMAL_CLONE)

    assert_equal(dst_img.rows, blend.rows)
    assert_equal(dst_img.cols, blend.cols)
  end

  def test_seamless_clone_mixed
    src = Cv::Mat.new(50, 50, CV_8UC3, Cv::Scalar.new(255, 0, 0))
    dst_img = Cv::Mat.new(100, 100, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    mask = Cv::Mat.new(50, 50, CV_8UC1, Cv::Scalar.new(255))
    center = Cv::Point.new(50, 50)

    blend = Cv::Mat.new
    Cv.seamless_clone(src.input_array, dst_img.input_array, mask.input_array, center, blend.output_array, Cv::SeamlessCloneFlags::MIXED_CLONE)

    refute(blend.empty?)
  end

  # ============ Color Change ============
  def test_color_change
    mask = Cv::Mat.new(100, 100, CV_8UC1, Cv::Scalar.new(255))
    dst = Cv::Mat.new

    Cv.color_change(@color_image.input_array, mask.input_array, dst.output_array, 1.5, 0.5, 0.5)

    assert_equal(@color_image.rows, dst.rows)
    assert_equal(@color_image.cols, dst.cols)
  end

  # ============ Illumination Change ============
  def test_illumination_change
    mask = Cv::Mat.new(100, 100, CV_8UC1, Cv::Scalar.new(255))
    dst = Cv::Mat.new

    Cv.illumination_change(@color_image.input_array, mask.input_array, dst.output_array, 0.2, 0.4)

    assert_equal(@color_image.rows, dst.rows)
    assert_equal(@color_image.cols, dst.cols)
  end

  # ============ Texture Flattening ============
  def test_texture_flattening
    mask = Cv::Mat.new(100, 100, CV_8UC1, Cv::Scalar.new(255))
    dst = Cv::Mat.new

    Cv.texture_flattening(@color_image.input_array, mask.input_array, dst.output_array, 30.0, 45.0, 3)

    assert_equal(@color_image.rows, dst.rows)
    assert_equal(@color_image.cols, dst.cols)
  end
end
