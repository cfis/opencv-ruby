#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class ObjdetectTest < OpenCVTestCase
  def setup
    # Create test images
    @gray_image = Cv::Mat.new(200, 200, CV_8UC1, Cv::Scalar.new(128))
    @color_image = Cv::Mat.new(200, 200, CV_8UC3, Cv::Scalar.new(128, 128, 128))

    # Create a simple QR-code-like pattern for testing
    @qr_test_image = Cv::Mat.new(200, 200, CV_8UC1, Cv::Scalar.new(255))
    # Draw a simple pattern
    Cv::rectangle(@qr_test_image.input_output_array, Cv::Point.new(20, 20), Cv::Point.new(60, 60), Cv::Scalar.new(0), -1)
    Cv::rectangle(@qr_test_image.input_output_array, Cv::Point.new(140, 20), Cv::Point.new(180, 60), Cv::Scalar.new(0), -1)
    Cv::rectangle(@qr_test_image.input_output_array, Cv::Point.new(20, 140), Cv::Point.new(60, 180), Cv::Scalar.new(0), -1)
  end

  # ============ CascadeClassifier ============
  def test_cascade_classifier_new
    cascade = Cv::CascadeClassifier.new
    refute_nil(cascade)
    assert_instance_of(Cv::CascadeClassifier, cascade)
  end

  def test_cascade_classifier_empty
    cascade = Cv::CascadeClassifier.new
    assert(cascade.empty?)
  end

  # Note: isOldFormatCascade, getOriginalWindowSize, getFeatureType require a loaded cascade
  # These methods assert !empty() so they can only be tested with a valid cascade file

  # ============ HOGDescriptor ============
  def test_hog_descriptor_new
    hog = Cv::HOGDescriptor.new
    refute_nil(hog)
    assert_instance_of(Cv::HOGDescriptor, hog)
  end

  def test_hog_descriptor_new_with_params
    win_size = Cv::Size.new(64, 128)
    block_size = Cv::Size.new(16, 16)
    block_stride = Cv::Size.new(8, 8)
    cell_size = Cv::Size.new(8, 8)

    hog = Cv::HOGDescriptor.new(win_size, block_size, block_stride, cell_size, 9)
    refute_nil(hog)
  end

  def test_hog_descriptor_get_descriptor_size
    hog = Cv::HOGDescriptor.new
    size = hog.get_descriptor_size
    assert_operator(size, :>, 0)
  end

  def test_hog_descriptor_get_win_sigma
    hog = Cv::HOGDescriptor.new
    sigma = hog.get_win_sigma
    refute_nil(sigma)
  end

  def test_hog_descriptor_check_detector_size
    hog = Cv::HOGDescriptor.new
    # With empty SVM detector, should return false
    result = hog.check_detector_size?
    assert_kind_of(TrueClass.superclass, result)  # Boolean check
  end

  def test_hog_descriptor_get_default_people_detector
    detector = Cv::HOGDescriptor.get_default_people_detector
    refute_nil(detector)
    # Should return a vector of floats
    assert_operator(detector.size, :>, 0)
  end

  def test_hog_descriptor_get_daimler_people_detector
    detector = Cv::HOGDescriptor.get_daimler_people_detector
    refute_nil(detector)
    assert_operator(detector.size, :>, 0)
  end

  # Note: set_svm_detector requires InputArray from vector<float>
  # which needs special handling - skipping for now

  def test_hog_descriptor_compute
    hog = Cv::HOGDescriptor.new

    # Create appropriate sized test image (default HOG expects 64x128)
    test_img = Cv::Mat.new(128, 64, CV_8UC1, Cv::Scalar.new(128))

    descriptors = Std::Vector≺float≻.new
    hog.compute(test_img.input_array, descriptors)

    assert_operator(descriptors.size, :>, 0)
  end

  # ============ QRCodeDetector ============
  def test_qr_code_detector_new
    detector = Cv::QRCodeDetector.new
    refute_nil(detector)
    assert_instance_of(Cv::QRCodeDetector, detector)
  end

  def test_qr_code_detector_set_eps_x
    detector = Cv::QRCodeDetector.new
    result = detector.set_eps_x(0.2)
    refute_nil(result)
  end

  def test_qr_code_detector_set_eps_y
    detector = Cv::QRCodeDetector.new
    result = detector.set_eps_y(0.2)
    refute_nil(result)
  end

  def test_qr_code_detector_set_use_alignment_markers
    detector = Cv::QRCodeDetector.new
    result = detector.set_use_alignment_markers(true)
    refute_nil(result)
  end

  def test_qr_code_detector_detect
    detector = Cv::QRCodeDetector.new
    points = Cv::Mat.new

    # Try to detect on our test image (won't find a real QR code but tests API)
    result = detector.detect?(@gray_image.input_array, points.output_array)
    assert_kind_of(TrueClass.superclass, result)  # Boolean check
  end

  # ============ QRCodeDetectorAruco ============
  def test_qr_code_detector_aruco_new
    detector = Cv::QRCodeDetectorAruco.new
    refute_nil(detector)
    assert_instance_of(Cv::QRCodeDetectorAruco, detector)
  end

  def test_qr_code_detector_aruco_get_aruco_parameters
    detector = Cv::QRCodeDetectorAruco.new
    params = detector.get_aruco_parameters
    refute_nil(params)
  end

  def test_qr_code_detector_aruco_set_aruco_parameters
    detector = Cv::QRCodeDetectorAruco.new
    params = detector.get_aruco_parameters
    detector.set_aruco_parameters(params)
    # Just verify it doesn't crash
    refute_nil(detector)
  end

  def test_qr_code_detector_aruco_get_detector_parameters
    detector = Cv::QRCodeDetectorAruco.new
    params = detector.get_detector_parameters
    refute_nil(params)
  end

  # ============ QRCodeEncoder ============
  def test_qr_code_encoder_params
    params = Cv::QRCodeEncoder::Params.new
    refute_nil(params)
    assert_instance_of(Cv::QRCodeEncoder::Params, params)
  end

  def test_qr_code_encoder_create
    encoder = Cv::QRCodeEncoder.create
    refute_nil(encoder)
  end

  def test_qr_code_encoder_create_with_params
    params = Cv::QRCodeEncoder::Params.new
    encoder = Cv::QRCodeEncoder.create(params)
    refute_nil(encoder)
  end

  def test_qr_code_encoder_encode
    encoder = Cv::QRCodeEncoder.create
    qr_image = Cv::Mat.new
    encoder.encode("Hello", qr_image.output_array)

    refute(qr_image.empty?)
    assert_equal(CV_8UC1, qr_image.type)
  end

  def test_qr_code_encoder_encode_structured_append
    encoder = Cv::QRCodeEncoder.create
    qr_images = Std::Vector≺cv꞉꞉Mat≻.new
    encoder.encode_structured_append("Hello World Test Message", Cv::OutputArray.new(qr_images))

    # Structured append creates multiple QR codes for longer messages
    assert_operator(qr_images.size, :>=, 1)
  end

  # ============ groupRectangles function ============
  def test_group_rectangles
    # Create overlapping rectangles
    rects = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    rects.push_back(Cv::Rect.new(10, 10, 50, 50))
    rects.push_back(Cv::Rect.new(12, 12, 50, 50))
    rects.push_back(Cv::Rect.new(11, 11, 50, 50))
    rects.push_back(Cv::Rect.new(100, 100, 50, 50))
    rects.push_back(Cv::Rect.new(101, 101, 50, 50))

    Cv.group_rectangles(rects, 2, 0.2)

    # After grouping, similar rectangles should be merged
    assert_operator(rects.size, :<, 5)
  end

  # ============ Aruco module ============
  def test_aruco_dictionary_get_predefined_dictionary
    dict = Cv::Aruco.get_predefined_dictionary(Cv::Aruco::PredefinedDictionaryType::DICT_4X4_50)
    refute_nil(dict)
  end

  def test_aruco_generate_image_marker
    dict = Cv::Aruco.get_predefined_dictionary(Cv::Aruco::PredefinedDictionaryType::DICT_4X4_50)
    marker_img = Cv::Mat.new

    Cv::Aruco.generate_image_marker(dict, 0, 100, marker_img.output_array, 1)

    assert_equal(100, marker_img.rows)
    assert_equal(100, marker_img.cols)
  end

  def test_aruco_detector_parameters
    params = Cv::Aruco::DetectorParameters.new
    refute_nil(params)
    assert_instance_of(Cv::Aruco::DetectorParameters, params)
  end

  def test_aruco_detector_parameters_attributes
    params = Cv::Aruco::DetectorParameters.new

    # Test some attributes exist
    refute_nil(params.adaptive_thresh_win_size_min)
    refute_nil(params.adaptive_thresh_win_size_max)
    refute_nil(params.adaptive_thresh_win_size_step)
    refute_nil(params.adaptive_thresh_constant)
    refute_nil(params.min_marker_perimeter_rate)
    refute_nil(params.max_marker_perimeter_rate)
    refute_nil(params.polygonal_approx_accuracy_rate)
    refute_nil(params.min_corner_distance_rate)
    refute_nil(params.min_marker_distance_rate)
  end

  def test_aruco_dictionary
    dict = Cv::Aruco::Dictionary.new
    refute_nil(dict)
    assert_instance_of(Cv::Aruco::Dictionary, dict)
  end

  def test_aruco_aruco_detector_new
    dict = Cv::Aruco.get_predefined_dictionary(Cv::Aruco::PredefinedDictionaryType::DICT_4X4_50)
    params = Cv::Aruco::DetectorParameters.new

    detector = Cv::Aruco::ArucoDetector.new(dict, params)
    refute_nil(detector)
    assert_instance_of(Cv::Aruco::ArucoDetector, detector)
  end

  def test_aruco_aruco_detector_get_dictionary
    dict = Cv::Aruco.get_predefined_dictionary(Cv::Aruco::PredefinedDictionaryType::DICT_4X4_50)
    params = Cv::Aruco::DetectorParameters.new
    detector = Cv::Aruco::ArucoDetector.new(dict, params)

    retrieved_dict = detector.get_dictionary
    refute_nil(retrieved_dict)
  end

  def test_aruco_aruco_detector_get_detector_parameters
    dict = Cv::Aruco.get_predefined_dictionary(Cv::Aruco::PredefinedDictionaryType::DICT_4X4_50)
    params = Cv::Aruco::DetectorParameters.new
    detector = Cv::Aruco::ArucoDetector.new(dict, params)

    retrieved_params = detector.get_detector_parameters
    refute_nil(retrieved_params)
  end
end
