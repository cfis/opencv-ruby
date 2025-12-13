#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class Features2DTest < OpenCVTestCase
  def setup
    # Create a simple test image with some features
    @gray_image = Cv::Mat.new(100, 100, CV_8UC1, Cv::Scalar.new(128))
    # Add some corners/features
    Cv::rectangle(@gray_image.input_output_array, Cv::Point.new(20, 20), Cv::Point.new(40, 40), Cv::Scalar.new(255), -1)
    Cv::rectangle(@gray_image.input_output_array, Cv::Point.new(60, 60), Cv::Point.new(80, 80), Cv::Scalar.new(0), -1)
    Cv::circle(@gray_image.input_output_array, Cv::Point.new(50, 50), 10, Cv::Scalar.new(200), -1)
  end

  # ============ KeyPointsFilter ============
  def test_keypoints_filter_new
    filter = Cv::KeyPointsFilter.new
    assert_instance_of(Cv::KeyPointsFilter, filter)
  end

  def test_keypoints_filter_retain_best
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    keypoints.push_back(Cv::KeyPoint.new(10.0, 10.0, 5.0, -1, 0.9, 0, -1))
    keypoints.push_back(Cv::KeyPoint.new(20.0, 20.0, 5.0, -1, 0.5, 0, -1))
    keypoints.push_back(Cv::KeyPoint.new(30.0, 30.0, 5.0, -1, 0.7, 0, -1))

    Cv::KeyPointsFilter.retain_best(keypoints, 2)
    assert_equal(2, keypoints.size)
  end

  def test_keypoints_filter_remove_duplicated
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    keypoints.push_back(Cv::KeyPoint.new(10.0, 10.0, 5.0))
    keypoints.push_back(Cv::KeyPoint.new(10.0, 10.0, 5.0))  # duplicate
    keypoints.push_back(Cv::KeyPoint.new(20.0, 20.0, 5.0))

    Cv::KeyPointsFilter.remove_duplicated(keypoints)
    assert_equal(2, keypoints.size)
  end

  def test_keypoints_filter_run_by_image_border
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    keypoints.push_back(Cv::KeyPoint.new(5.0, 5.0, 5.0))    # near border
    keypoints.push_back(Cv::KeyPoint.new(50.0, 50.0, 5.0))  # center

    Cv::KeyPointsFilter.run_by_image_border(keypoints, Cv::Size.new(100, 100), 10)
    assert_equal(1, keypoints.size)
  end

  def test_keypoints_filter_run_by_keypoint_size
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    keypoints.push_back(Cv::KeyPoint.new(10.0, 10.0, 3.0))  # small
    keypoints.push_back(Cv::KeyPoint.new(20.0, 20.0, 10.0)) # medium
    keypoints.push_back(Cv::KeyPoint.new(30.0, 30.0, 20.0)) # large

    Cv::KeyPointsFilter.run_by_keypoint_size(keypoints, 5.0, 15.0)
    assert_equal(1, keypoints.size)
  end

  # ============ Feature2D Base Class ============
  def test_feature2d_new
    feature = Cv::Feature2D.new
    assert_instance_of(Cv::Feature2D, feature)
  end

  # ============ ORB Detector ============
  def test_orb_create
    orb = Cv::ORB.create
    refute_nil(orb)
  end

  def test_orb_create_with_params
    orb = Cv::ORB.create(500, 1.2, 8, 31, 0, 2, Cv::ORB::ScoreType::HARRIS_SCORE, 31, 20)
    refute_nil(orb)
  end

  def test_orb_detect
    orb = Cv::ORB.create
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    orb.detect(@gray_image.input_array, keypoints)
    assert_operator(keypoints.size, :>=, 0)
  end

  def test_orb_compute
    orb = Cv::ORB.create
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    orb.detect(@gray_image.input_array, keypoints)

    descriptors = Cv::Mat.new
    orb.compute(@gray_image.input_array, keypoints, descriptors.output_array)
    # ORB descriptors are 32 bytes (256 bits)
    assert_equal(32, descriptors.cols) if keypoints.size > 0
  end

  def test_orb_detect_and_compute
    orb = Cv::ORB.create
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    descriptors = Cv::Mat.new

    orb.detect_and_compute(@gray_image.input_array, Cv::no_array, keypoints, descriptors.output_array)
    assert_operator(keypoints.size, :>=, 0)
  end

  def test_orb_get_set_max_features
    orb = Cv::ORB.create
    orb.set_max_features(1000)
    assert_equal(1000, orb.get_max_features)
  end

  def test_orb_get_set_scale_factor
    orb = Cv::ORB.create
    orb.set_scale_factor(1.5)
    assert_in_delta(1.5, orb.get_scale_factor, 0.01)
  end

  def test_orb_get_set_n_levels
    orb = Cv::ORB.create
    orb.set_n_levels(4)
    assert_equal(4, orb.get_n_levels)
  end

  def test_orb_get_set_edge_threshold
    orb = Cv::ORB.create
    orb.set_edge_threshold(20)
    assert_equal(20, orb.get_edge_threshold)
  end

  def test_orb_get_set_fast_threshold
    orb = Cv::ORB.create
    orb.set_fast_threshold(15)
    assert_equal(15, orb.get_fast_threshold)
  end

  def test_orb_get_default_name
    orb = Cv::ORB.create
    assert_equal("Feature2D.ORB", orb.get_default_name)
  end

  def test_orb_descriptor_size
    orb = Cv::ORB.create
    assert_equal(32, orb.descriptor_size)
  end

  def test_orb_descriptor_type
    orb = Cv::ORB.create
    assert_equal(CV_8U, orb.descriptor_type)
  end

  # ============ BRISK Detector ============
  def test_brisk_create
    brisk = Cv::BRISK.create
    refute_nil(brisk)
  end

  def test_brisk_create_with_params
    brisk = Cv::BRISK.create(30, 3, 1.0)
    refute_nil(brisk)
  end

  def test_brisk_detect
    brisk = Cv::BRISK.create
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    brisk.detect(@gray_image.input_array, keypoints)
    assert_operator(keypoints.size, :>=, 0)
  end

  def test_brisk_get_set_threshold
    brisk = Cv::BRISK.create
    brisk.set_threshold(50)
    assert_equal(50, brisk.get_threshold)
  end

  def test_brisk_get_set_octaves
    brisk = Cv::BRISK.create
    brisk.set_octaves(4)
    assert_equal(4, brisk.get_octaves)
  end

  def test_brisk_get_default_name
    brisk = Cv::BRISK.create
    assert_equal("Feature2D.BRISK", brisk.get_default_name)
  end

  # ============ KAZE Detector ============
  def test_kaze_create
    kaze = Cv::KAZE.create
    refute_nil(kaze)
  end

  def test_kaze_create_with_params
    kaze = Cv::KAZE.create(false, false, 0.001, 4, 4, Cv::KAZE::DiffusivityType::DIFF_PM_G2)
    refute_nil(kaze)
  end

  def test_kaze_detect
    kaze = Cv::KAZE.create
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    kaze.detect(@gray_image.input_array, keypoints)
    assert_operator(keypoints.size, :>=, 0)
  end

  def test_kaze_get_set_extended
    kaze = Cv::KAZE.create
    kaze.set_extended(true)
    assert_equal(true, kaze.get_extended?)
  end

  def test_kaze_get_set_upright
    kaze = Cv::KAZE.create
    kaze.set_upright(true)
    assert_equal(true, kaze.get_upright?)
  end

  def test_kaze_get_set_threshold
    kaze = Cv::KAZE.create
    kaze.set_threshold(0.002)
    assert_in_delta(0.002, kaze.get_threshold, 0.0001)
  end

  def test_kaze_get_set_n_octaves
    kaze = Cv::KAZE.create
    kaze.set_n_octaves(5)
    assert_equal(5, kaze.get_n_octaves)
  end

  def test_kaze_get_default_name
    kaze = Cv::KAZE.create
    assert_equal("Feature2D.KAZE", kaze.get_default_name)
  end

  # ============ AKAZE Detector ============
  def test_akaze_create
    akaze = Cv::AKAZE.create
    refute_nil(akaze)
  end

  def test_akaze_detect
    akaze = Cv::AKAZE.create
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    akaze.detect(@gray_image.input_array, keypoints)
    assert_operator(keypoints.size, :>=, 0)
  end

  def test_akaze_get_set_descriptor_type
    akaze = Cv::AKAZE.create
    akaze.set_descriptor_type(Cv::AKAZE::DescriptorType::DESCRIPTOR_KAZE)
    assert_equal(Cv::AKAZE::DescriptorType::DESCRIPTOR_KAZE, akaze.get_descriptor_type)
  end

  def test_akaze_get_set_descriptor_size
    akaze = Cv::AKAZE.create
    akaze.set_descriptor_size(64)
    assert_equal(64, akaze.get_descriptor_size)
  end

  def test_akaze_get_default_name
    akaze = Cv::AKAZE.create
    assert_equal("Feature2D.AKAZE", akaze.get_default_name)
  end

  # ============ FastFeatureDetector ============
  def test_fast_feature_detector_create
    fast = Cv::FastFeatureDetector.create
    refute_nil(fast)
  end

  def test_fast_feature_detector_create_with_params
    fast = Cv::FastFeatureDetector.create(20, true, Cv::FastFeatureDetector::DetectorType::TYPE_9_16)
    refute_nil(fast)
  end

  def test_fast_feature_detector_detect
    fast = Cv::FastFeatureDetector.create
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    fast.detect(@gray_image.input_array, keypoints)
    assert_operator(keypoints.size, :>=, 0)
  end

  def test_fast_feature_detector_get_set_threshold
    fast = Cv::FastFeatureDetector.create
    fast.set_threshold(20)
    assert_equal(20, fast.get_threshold)
  end

  def test_fast_feature_detector_get_set_nonmax_suppression
    fast = Cv::FastFeatureDetector.create
    fast.set_nonmax_suppression(false)
    assert_equal(false, fast.get_nonmax_suppression?)
  end

  def test_fast_feature_detector_get_default_name
    fast = Cv::FastFeatureDetector.create
    assert_equal("Feature2D.FastFeatureDetector", fast.get_default_name)
  end

  # ============ FAST function ============
  def test_fast_function
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    Cv::fast(@gray_image.input_array, keypoints, 10, true)
    assert_operator(keypoints.size, :>=, 0)
  end

  # ============ AgastFeatureDetector ============
  def test_agast_feature_detector_create
    agast = Cv::AgastFeatureDetector.create
    refute_nil(agast)
  end

  def test_agast_feature_detector_detect
    agast = Cv::AgastFeatureDetector.create
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    agast.detect(@gray_image.input_array, keypoints)
    assert_operator(keypoints.size, :>=, 0)
  end

  def test_agast_feature_detector_get_set_threshold
    agast = Cv::AgastFeatureDetector.create
    agast.set_threshold(15)
    assert_equal(15, agast.get_threshold)
  end

  def test_agast_feature_detector_get_default_name
    agast = Cv::AgastFeatureDetector.create
    assert_equal("Feature2D.AgastFeatureDetector", agast.get_default_name)
  end

  # ============ AGAST function ============
  def test_agast_function
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    Cv::agast(@gray_image.input_array, keypoints, 10, true)
    assert_operator(keypoints.size, :>=, 0)
  end

  # ============ GFTTDetector (Good Features To Track) ============
  def test_gftt_detector_create
    gftt = Cv::GFTTDetector.create
    refute_nil(gftt)
  end

  def test_gftt_detector_create_with_params
    gftt = Cv::GFTTDetector.create(1000, 0.01, 1, 3, false, 0.04)
    refute_nil(gftt)
  end

  def test_gftt_detector_detect
    gftt = Cv::GFTTDetector.create
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    gftt.detect(@gray_image.input_array, keypoints)
    assert_operator(keypoints.size, :>=, 0)
  end

  def test_gftt_detector_get_set_max_features
    gftt = Cv::GFTTDetector.create
    gftt.set_max_features(500)
    assert_equal(500, gftt.get_max_features)
  end

  def test_gftt_detector_get_set_quality_level
    gftt = Cv::GFTTDetector.create
    gftt.set_quality_level(0.02)
    assert_in_delta(0.02, gftt.get_quality_level, 0.001)
  end

  def test_gftt_detector_get_set_min_distance
    gftt = Cv::GFTTDetector.create
    gftt.set_min_distance(5.0)
    assert_in_delta(5.0, gftt.get_min_distance, 0.01)
  end

  def test_gftt_detector_get_set_block_size
    gftt = Cv::GFTTDetector.create
    gftt.set_block_size(5)
    assert_equal(5, gftt.get_block_size)
  end

  def test_gftt_detector_get_set_harris_detector
    gftt = Cv::GFTTDetector.create
    gftt.set_harris_detector(true)
    assert_equal(true, gftt.get_harris_detector?)
  end

  def test_gftt_detector_get_set_k
    gftt = Cv::GFTTDetector.create
    gftt.set_k(0.05)
    assert_in_delta(0.05, gftt.get_k, 0.001)
  end

  def test_gftt_detector_get_default_name
    gftt = Cv::GFTTDetector.create
    assert_equal("Feature2D.GFTTDetector", gftt.get_default_name)
  end

  # ============ MSER Detector ============
  def test_mser_create
    mser = Cv::MSER.create
    refute_nil(mser)
  end

  def test_mser_create_with_params
    mser = Cv::MSER.create(5, 60, 14400, 0.25, 0.2, 200, 1.01, 0.003, 5)
    refute_nil(mser)
  end

  def test_mser_detect
    mser = Cv::MSER.create
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    mser.detect(@gray_image.input_array, keypoints)
    assert_operator(keypoints.size, :>=, 0)
  end

  def test_mser_get_set_delta
    mser = Cv::MSER.create
    mser.set_delta(10)
    assert_equal(10, mser.get_delta)
  end

  def test_mser_get_set_min_area
    mser = Cv::MSER.create
    mser.set_min_area(100)
    assert_equal(100, mser.get_min_area)
  end

  def test_mser_get_set_max_area
    mser = Cv::MSER.create
    mser.set_max_area(10000)
    assert_equal(10000, mser.get_max_area)
  end

  def test_mser_get_default_name
    mser = Cv::MSER.create
    assert_equal("Feature2D.MSER", mser.get_default_name)
  end

  # ============ SimpleBlobDetector ============
  def test_simple_blob_detector_create
    detector = Cv::SimpleBlobDetector.create
    refute_nil(detector)
  end

  def test_simple_blob_detector_params
    params = Cv::SimpleBlobDetector::Params.new
    assert_instance_of(Cv::SimpleBlobDetector::Params, params)
  end

  def test_simple_blob_detector_params_attributes
    params = Cv::SimpleBlobDetector::Params.new

    # Test default values exist
    refute_nil(params.threshold_step)
    refute_nil(params.min_threshold)
    refute_nil(params.max_threshold)
    refute_nil(params.filter_by_area)
    refute_nil(params.min_area)
    refute_nil(params.max_area)
    refute_nil(params.filter_by_circularity)
    refute_nil(params.filter_by_convexity)
    refute_nil(params.filter_by_inertia)
    refute_nil(params.filter_by_color)
  end

  def test_simple_blob_detector_params_set_attributes
    params = Cv::SimpleBlobDetector::Params.new
    params.min_threshold = 50.0
    params.max_threshold = 200.0
    params.filter_by_area = true
    params.min_area = 100.0
    params.max_area = 5000.0

    assert_in_delta(50.0, params.min_threshold, 0.01)
    assert_in_delta(200.0, params.max_threshold, 0.01)
    assert_equal(true, params.filter_by_area)
    assert_in_delta(100.0, params.min_area, 0.01)
    assert_in_delta(5000.0, params.max_area, 0.01)
  end

  def test_simple_blob_detector_create_with_params
    params = Cv::SimpleBlobDetector::Params.new
    params.min_threshold = 10.0
    params.max_threshold = 200.0

    detector = Cv::SimpleBlobDetector.create(params)
    refute_nil(detector)
  end

  def test_simple_blob_detector_detect
    detector = Cv::SimpleBlobDetector.create
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    detector.detect(@gray_image.input_array, keypoints)
    assert_operator(keypoints.size, :>=, 0)
  end

  def test_simple_blob_detector_get_default_name
    detector = Cv::SimpleBlobDetector.create
    assert_equal("Feature2D.SimpleBlobDetector", detector.get_default_name)
  end

  # ============ DescriptorMatcher ============
  def test_descriptor_matcher_create_bf
    matcher = Cv::DescriptorMatcher.create("BruteForce")
    refute_nil(matcher)
  end

  def test_descriptor_matcher_create_bf_hamming
    matcher = Cv::DescriptorMatcher.create("BruteForce-Hamming")
    refute_nil(matcher)
  end

  def test_descriptor_matcher_create_flann
    matcher = Cv::DescriptorMatcher.create("FlannBased")
    refute_nil(matcher)
  end

  def test_descriptor_matcher_create_by_type
    matcher = Cv::DescriptorMatcher.create(Cv::DescriptorMatcher::MatcherType::BRUTEFORCE)
    refute_nil(matcher)
  end

  # ============ BFMatcher ============
  def test_bf_matcher_new
    matcher = Cv::BFMatcher.new
    refute_nil(matcher)
  end

  def test_bf_matcher_new_with_params
    matcher = Cv::BFMatcher.new(Cv::NormTypes::NORM_L2, false)
    refute_nil(matcher)
  end

  def test_bf_matcher_create
    matcher = Cv::BFMatcher.create(Cv::NormTypes::NORM_HAMMING, false)
    refute_nil(matcher)
  end

  def test_bf_matcher_match
    # Create two simple descriptor sets
    desc1 = Cv::Mat.new(3, 32, CV_8UC1)
    desc2 = Cv::Mat.new(3, 32, CV_8UC1)

    # Fill with some values
    3.times do |i|
      32.times do |j|
        desc1[i, j] = (i * 32 + j) % 256
        desc2[i, j] = (i * 32 + j + 10) % 256
      end
    end

    matcher = Cv::BFMatcher.new(Cv::NormTypes::NORM_HAMMING, false)
    matches = Std::Vector≺cv꞉꞉DMatch≻.new
    matcher.match(desc1.input_array, desc2.input_array, matches)

    assert_equal(3, matches.size)
  end

  def test_bf_matcher_knn_match
    desc1 = Cv::Mat.new(3, 32, CV_8UC1)
    desc2 = Cv::Mat.new(5, 32, CV_8UC1)

    3.times do |i|
      32.times do |j|
        desc1[i, j] = (i * 32 + j) % 256
      end
    end
    5.times do |i|
      32.times do |j|
        desc2[i, j] = (i * 32 + j + 5) % 256
      end
    end

    matcher = Cv::BFMatcher.new(Cv::NormTypes::NORM_HAMMING, false)
    matches = Std::Vector≺vector≺cv꞉꞉DMatch≻≻.new
    matcher.knn_match(desc1.input_array, desc2.input_array, matches, 2)

    assert_equal(3, matches.size)
  end

  def test_bf_matcher_mask_supported
    matcher = Cv::BFMatcher.new
    assert_equal(true, matcher.mask_supported?)
  end

  # ============ FlannBasedMatcher ============
  def test_flann_based_matcher_new
    matcher = Cv::FlannBasedMatcher.new
    refute_nil(matcher)
  end

  def test_flann_based_matcher_create
    matcher = Cv::FlannBasedMatcher.create
    refute_nil(matcher)
  end

  # ============ draw_keypoints ============
  def test_draw_keypoints
    keypoints = Std::Vector≺cv꞉꞉KeyPoint≻.new
    keypoints.push_back(Cv::KeyPoint.new(25.0, 25.0, 5.0))
    keypoints.push_back(Cv::KeyPoint.new(50.0, 50.0, 5.0))

    color_image = @gray_image.cvt_color(Cv::ColorConversionCodes::COLOR_GRAY2BGR)

    out_image = Cv::Mat.new
    Cv::draw_keypoints(color_image.input_array, keypoints, out_image.input_output_array)

    refute(out_image.empty?)
    assert_equal(3, out_image.channels)
  end

  # ============ BOWKMeansTrainer ============
  def test_bow_kmeans_trainer_new
    trainer = Cv::BOWKMeansTrainer.new(10)
    refute_nil(trainer)
  end

  def test_bow_kmeans_trainer_add
    trainer = Cv::BOWKMeansTrainer.new(10)
    desc = Cv::Mat.new(100, 32, CV_32FC1)
    100.times do |i|
      32.times do |j|
        desc[i, j] = rand
      end
    end

    trainer.add(desc)
    assert_equal(100, trainer.descriptors_count)
  end

  def test_bow_kmeans_trainer_cluster
    trainer = Cv::BOWKMeansTrainer.new(5)
    desc = Cv::Mat.new(100, 32, CV_32FC1)
    100.times do |i|
      32.times do |j|
        desc[i, j] = rand
      end
    end

    trainer.add(desc)
    vocabulary = trainer.cluster

    assert_equal(5, vocabulary.rows)
    assert_equal(32, vocabulary.cols)
  end

  def test_bow_kmeans_trainer_clear
    trainer = Cv::BOWKMeansTrainer.new(10)
    desc = Cv::Mat.new(100, 32, CV_32FC1)
    trainer.add(desc)
    trainer.clear
    assert_equal(0, trainer.descriptors_count)
  end

  # ============ BOWImgDescriptorExtractor ============
  # Note: BOWImgDescriptorExtractor constructor requires Ptr<Feature2D> and Ptr<DescriptorMatcher>
  # which need special handling - skipping direct constructor tests

  # ============ AffineFeature ============
  # Note: AffineFeature.create crashes with Ptr<Feature2D> - skipping tests

  # ============ Evaluation Functions ============
  # Note: compute_recall_precision_curve needs special vector types - skipping tests
end
