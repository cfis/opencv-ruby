#include <opencv2/objdetect.hpp>
#include "core/cvstd_wrapper-rb.hpp"
#include "../opencv_ruby_version.hpp"
#include "objdetect-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvBaseCascadeClassifier;
Rice::Class rb_cCvBaseCascadeClassifierMaskGenerator;
Rice::Class rb_cCvCascadeClassifier;
Rice::Class rb_cCvDefaultDeleterCvHaarClassifierCascade;
Rice::Class rb_cCvDetectionROI;
Rice::Class rb_cCvHOGDescriptor;
Rice::Class rb_cCvQRCodeDetector;
Rice::Class rb_cCvQRCodeDetectorAruco;
Rice::Class rb_cCvQRCodeDetectorArucoParams;
Rice::Class rb_cCvQRCodeEncoder;
Rice::Class rb_cCvQRCodeEncoderParams;
Rice::Class rb_cCvSimilarRects;

void Init_Objdetect()
{
  Module rb_mCv = define_module("Cv");

  rb_cCvSimilarRects = define_class_under<cv::SimilarRects>(rb_mCv, "SimilarRects").
    define_constructor(Constructor<cv::SimilarRects, double>(),
      Arg("_eps")).
    define_method("call", &cv::SimilarRects::operator(),
      Arg("r1"), Arg("r2")).
    define_attr("eps", &cv::SimilarRects::eps);

  rb_mCv.define_module_function<void(*)(std::vector<cv::Rect_<int>>&, int, double)>("group_rectangles", &cv::groupRectangles,
    Arg("rect_list"), Arg("group_threshold"), Arg("eps") = static_cast<double>(0.2));

  rb_mCv.define_module_function<void(*)(std::vector<cv::Rect_<int>>&, std::vector<int>&, int, double)>("group_rectangles", &cv::groupRectangles,
    Arg("rect_list"), Arg("weights"), Arg("group_threshold"), Arg("eps") = static_cast<double>(0.2));

  rb_mCv.define_module_function<void(*)(std::vector<cv::Rect_<int>>&, int, double, std::vector<int>*, std::vector<double>*)>("group_rectangles", &cv::groupRectangles,
    Arg("rect_list"), Arg("group_threshold"), Arg("eps"), Arg("weights"), Arg("level_weights"));

  rb_mCv.define_module_function<void(*)(std::vector<cv::Rect_<int>>&, std::vector<int>&, std::vector<double>&, int, double)>("group_rectangles", &cv::groupRectangles,
    Arg("rect_list"), Arg("reject_levels"), Arg("level_weights"), Arg("group_threshold"), Arg("eps") = static_cast<double>(0.2));

  rb_mCv.define_module_function("group_rectangles_meanshift", &cv::groupRectangles_meanshift,
    Arg("rect_list"), Arg("found_weights"), Arg("found_scales"), Arg("detect_threshold") = static_cast<double>(0.0), Arg("win_det_size") = static_cast<cv::Size>(cv::Size(64, 128)));

  rb_cCvDefaultDeleterCvHaarClassifierCascade = define_class_under<cv::DefaultDeleter<CvHaarClassifierCascade>>(rb_mCv, "DefaultDeleterCvHaarClassifierCascade").
    define_constructor(Constructor<cv::DefaultDeleter<CvHaarClassifierCascade>>());
    // Causes link errors
    //define_method("call", &cv::DefaultDeleter<CvHaarClassifierCascade>::operator(),
    //  Arg("obj"));

  rb_mCv.define_constant("CASCADE_DO_CANNY_PRUNING", (int)cv::CASCADE_DO_CANNY_PRUNING);
  rb_mCv.define_constant("CASCADE_SCALE_IMAGE", (int)cv::CASCADE_SCALE_IMAGE);
  rb_mCv.define_constant("CASCADE_FIND_BIGGEST_OBJECT", (int)cv::CASCADE_FIND_BIGGEST_OBJECT);
  rb_mCv.define_constant("CASCADE_DO_ROUGH_SEARCH", (int)cv::CASCADE_DO_ROUGH_SEARCH);

  rb_cCvBaseCascadeClassifier = define_class_under<cv::BaseCascadeClassifier, cv::Algorithm>(rb_mCv, "BaseCascadeClassifier").
    define_method("empty?", &cv::BaseCascadeClassifier::empty).
    define_method("load", &cv::BaseCascadeClassifier::load,
      Arg("filename")).
    define_method<void(cv::BaseCascadeClassifier::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, double, int, int, cv::Size, cv::Size)>("detect_multi_scale", &cv::BaseCascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("scale_factor"), Arg("min_neighbors"), Arg("flags"), Arg("min_size"), Arg("max_size")).
    define_method<void(cv::BaseCascadeClassifier::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<int>&, double, int, int, cv::Size, cv::Size)>("detect_multi_scale", &cv::BaseCascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("num_detections"), Arg("scale_factor"), Arg("min_neighbors"), Arg("flags"), Arg("min_size"), Arg("max_size")).
    define_method<void(cv::BaseCascadeClassifier::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<int>&, std::vector<double>&, double, int, int, cv::Size, cv::Size, bool)>("detect_multi_scale", &cv::BaseCascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("reject_levels"), Arg("level_weights"), Arg("scale_factor"), Arg("min_neighbors"), Arg("flags"), Arg("min_size"), Arg("max_size"), Arg("output_reject_levels")).
    define_method("old_format_cascade?", &cv::BaseCascadeClassifier::isOldFormatCascade).
    define_method("get_original_window_size", &cv::BaseCascadeClassifier::getOriginalWindowSize).
    define_method("get_feature_type", &cv::BaseCascadeClassifier::getFeatureType).
    define_method("get_old_cascade", &cv::BaseCascadeClassifier::getOldCascade).
    define_method("set_mask_generator", &cv::BaseCascadeClassifier::setMaskGenerator,
      Arg("mask_generator")).
    define_method("get_mask_generator", &cv::BaseCascadeClassifier::getMaskGenerator);

  rb_cCvBaseCascadeClassifierMaskGenerator = define_class_under<cv::BaseCascadeClassifier::MaskGenerator>(rb_cCvBaseCascadeClassifier, "MaskGenerator").
    define_method("generate_mask", &cv::BaseCascadeClassifier::MaskGenerator::generateMask,
      Arg("src")).
    define_method("initialize_mask", &cv::BaseCascadeClassifier::MaskGenerator::initializeMask,
      Arg("arg_0"));

  rb_cCvCascadeClassifier = define_class_under<cv::CascadeClassifier>(rb_mCv, "CascadeClassifier").
    define_constructor(Constructor<cv::CascadeClassifier>()).
    define_constructor(Constructor<cv::CascadeClassifier, const cv::String&>(),
      Arg("filename")).
    define_method("empty?", &cv::CascadeClassifier::empty).
    define_method("load", &cv::CascadeClassifier::load,
      Arg("filename")).
    define_method("read", &cv::CascadeClassifier::read,
      Arg("node")).
    define_method<void(cv::CascadeClassifier::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, double, int, int, cv::Size, cv::Size)>("detect_multi_scale", &cv::CascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("scale_factor") = static_cast<double>(1.1), Arg("min_neighbors") = static_cast<int>(3), Arg("flags") = static_cast<int>(0), Arg("min_size") = static_cast<cv::Size>(cv::Size()), Arg("max_size") = static_cast<cv::Size>(cv::Size())).
    define_method<void(cv::CascadeClassifier::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<int>&, double, int, int, cv::Size, cv::Size)>("detect_multi_scale", &cv::CascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("num_detections"), Arg("scale_factor") = static_cast<double>(1.1), Arg("min_neighbors") = static_cast<int>(3), Arg("flags") = static_cast<int>(0), Arg("min_size") = static_cast<cv::Size>(cv::Size()), Arg("max_size") = static_cast<cv::Size>(cv::Size())).
    define_method<void(cv::CascadeClassifier::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<int>&, std::vector<double>&, double, int, int, cv::Size, cv::Size, bool)>("detect_multi_scale", &cv::CascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("reject_levels"), Arg("level_weights"), Arg("scale_factor") = static_cast<double>(1.1), Arg("min_neighbors") = static_cast<int>(3), Arg("flags") = static_cast<int>(0), Arg("min_size") = static_cast<cv::Size>(cv::Size()), Arg("max_size") = static_cast<cv::Size>(cv::Size()), Arg("output_reject_levels") = static_cast<bool>(false)).
    define_method("old_format_cascade?", &cv::CascadeClassifier::isOldFormatCascade).
    define_method("get_original_window_size", &cv::CascadeClassifier::getOriginalWindowSize).
    define_method("get_feature_type", &cv::CascadeClassifier::getFeatureType).
    define_method("get_old_cascade", &cv::CascadeClassifier::getOldCascade).
    define_method("set_mask_generator", &cv::CascadeClassifier::setMaskGenerator,
      Arg("mask_generator")).
    define_method("get_mask_generator", &cv::CascadeClassifier::getMaskGenerator).
    define_attr("cc", &cv::CascadeClassifier::cc).
    define_singleton_function("convert", &cv::CascadeClassifier::convert,
      Arg("oldcascade"), Arg("newcascade"));

  rb_mCv.define_module_function("create_face_detection_mask_generator", &cv::createFaceDetectionMaskGenerator);

  rb_cCvDetectionROI = define_class_under<cv::DetectionROI>(rb_mCv, "DetectionROI").
    define_constructor(Constructor<cv::DetectionROI>()).
    define_attr("scale", &cv::DetectionROI::scale).
    define_attr("locations", &cv::DetectionROI::locations).
    define_attr("confidences", &cv::DetectionROI::confidences);

  rb_cCvHOGDescriptor = define_class_under<cv::HOGDescriptor>(rb_mCv, "HOGDescriptor").
    define_constructor(Constructor<cv::HOGDescriptor>()).
    define_constructor(Constructor<cv::HOGDescriptor, cv::Size, cv::Size, cv::Size, cv::Size, int, int, double, cv::HOGDescriptor::HistogramNormType, double, bool, int, bool>(),
      Arg("_win_size"), Arg("_block_size"), Arg("_block_stride"), Arg("_cell_size"), Arg("_nbins"), Arg("_deriv_aperture") = static_cast<int>(1), Arg("_win_sigma") = static_cast<double>(-1), Arg("_histogram_norm_type") = static_cast<cv::HOGDescriptor::HistogramNormType>(cv::HOGDescriptor::L2Hys), Arg("_l2_hys_threshold") = static_cast<double>(0.2), Arg("_gamma_correction") = static_cast<bool>(false), Arg("_nlevels") = static_cast<int>(cv::HOGDescriptor::DEFAULT_NLEVELS), Arg("_signed_gradient") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::HOGDescriptor, const cv::String&>(),
      Arg("filename")).
    define_constructor(Constructor<cv::HOGDescriptor, const cv::HOGDescriptor&>(),
      Arg("d")).
    define_method("get_descriptor_size", &cv::HOGDescriptor::getDescriptorSize).
    define_method("check_detector_size?", &cv::HOGDescriptor::checkDetectorSize).
    define_method("get_win_sigma", &cv::HOGDescriptor::getWinSigma).
    define_method("set_svm_detector", &cv::HOGDescriptor::setSVMDetector,
      Arg("svmdetector")).
    define_method("read", &cv::HOGDescriptor::read,
      Arg("fn")).
    define_method("write", &cv::HOGDescriptor::write,
      Arg("fs"), Arg("objname")).
    define_method("load", &cv::HOGDescriptor::load,
      Arg("filename"), Arg("objname") = static_cast<const cv::String&>(cv::String())).
    define_method("save", &cv::HOGDescriptor::save,
      Arg("filename"), Arg("objname") = static_cast<const cv::String&>(cv::String())).
    define_method("copy_to", &cv::HOGDescriptor::copyTo,
      Arg("c")).
    define_method("compute", &cv::HOGDescriptor::compute,
      Arg("img"), Arg("descriptors"), Arg("win_stride") = static_cast<cv::Size>(cv::Size()), Arg("padding") = static_cast<cv::Size>(cv::Size()), Arg("locations") = static_cast<const std::vector<cv::Point_<int>>&>(std::vector<cv::Point>())).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray, std::vector<cv::Point_<int>>&, std::vector<double>&, double, cv::Size, cv::Size, const std::vector<cv::Point_<int>>&) const>("detect", &cv::HOGDescriptor::detect,
      Arg("img"), Arg("found_locations"), Arg("weights"), Arg("hit_threshold") = static_cast<double>(0), Arg("win_stride") = static_cast<cv::Size>(cv::Size()), Arg("padding") = static_cast<cv::Size>(cv::Size()), Arg("search_locations") = static_cast<const std::vector<cv::Point_<int>>&>(std::vector<cv::Point>())).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray, std::vector<cv::Point_<int>>&, double, cv::Size, cv::Size, const std::vector<cv::Point_<int>>&) const>("detect", &cv::HOGDescriptor::detect,
      Arg("img"), Arg("found_locations"), Arg("hit_threshold") = static_cast<double>(0), Arg("win_stride") = static_cast<cv::Size>(cv::Size()), Arg("padding") = static_cast<cv::Size>(cv::Size()), Arg("search_locations") = static_cast<const std::vector<cv::Point_<int>>&>(std::vector<cv::Point>())).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<double>&, double, cv::Size, cv::Size, double, double, bool) const>("detect_multi_scale", &cv::HOGDescriptor::detectMultiScale,
      Arg("img"), Arg("found_locations"), Arg("found_weights"), Arg("hit_threshold") = static_cast<double>(0), Arg("win_stride") = static_cast<cv::Size>(cv::Size()), Arg("padding") = static_cast<cv::Size>(cv::Size()), Arg("scale") = static_cast<double>(1.05), Arg("group_threshold") = static_cast<double>(2.0), Arg("use_meanshift_grouping") = static_cast<bool>(false)).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, double, cv::Size, cv::Size, double, double, bool) const>("detect_multi_scale", &cv::HOGDescriptor::detectMultiScale,
      Arg("img"), Arg("found_locations"), Arg("hit_threshold") = static_cast<double>(0), Arg("win_stride") = static_cast<cv::Size>(cv::Size()), Arg("padding") = static_cast<cv::Size>(cv::Size()), Arg("scale") = static_cast<double>(1.05), Arg("group_threshold") = static_cast<double>(2.0), Arg("use_meanshift_grouping") = static_cast<bool>(false)).
    define_method("compute_gradient", &cv::HOGDescriptor::computeGradient,
      Arg("img"), Arg("grad"), Arg("angle_ofs"), Arg("padding_tl") = static_cast<cv::Size>(cv::Size()), Arg("padding_br") = static_cast<cv::Size>(cv::Size())).
    define_attr("win_size", &cv::HOGDescriptor::winSize).
    define_attr("block_size", &cv::HOGDescriptor::blockSize).
    define_attr("block_stride", &cv::HOGDescriptor::blockStride).
    define_attr("cell_size", &cv::HOGDescriptor::cellSize).
    define_attr("nbins", &cv::HOGDescriptor::nbins).
    define_attr("deriv_aperture", &cv::HOGDescriptor::derivAperture).
    define_attr("win_sigma", &cv::HOGDescriptor::winSigma).
    define_attr("histogram_norm_type", &cv::HOGDescriptor::histogramNormType).
    define_attr("l2_hys_threshold", &cv::HOGDescriptor::L2HysThreshold).
    define_attr("gamma_correction", &cv::HOGDescriptor::gammaCorrection).
    define_attr("svm_detector", &cv::HOGDescriptor::svmDetector).
    define_attr("ocl_svm_detector", &cv::HOGDescriptor::oclSvmDetector).
    define_attr("free_coef", &cv::HOGDescriptor::free_coef).
    define_attr("nlevels", &cv::HOGDescriptor::nlevels).
    define_attr("signed_gradient", &cv::HOGDescriptor::signedGradient).
    define_method("detect_roi", &cv::HOGDescriptor::detectROI,
      Arg("img"), Arg("locations"), Arg("found_locations"), Arg("confidences"), Arg("hit_threshold") = static_cast<double>(0), Arg("win_stride") = static_cast<cv::Size>(cv::Size()), Arg("padding") = static_cast<cv::Size>(cv::Size())).
    define_method("detect_multi_scale_roi", &cv::HOGDescriptor::detectMultiScaleROI,
      Arg("img"), Arg("found_locations"), Arg("locations"), Arg("hit_threshold") = static_cast<double>(0), Arg("group_threshold") = static_cast<int>(0)).
    define_method("group_rectangles", &cv::HOGDescriptor::groupRectangles,
      Arg("rect_list"), Arg("weights"), Arg("group_threshold"), Arg("eps")).
    define_singleton_function("get_default_people_detector", &cv::HOGDescriptor::getDefaultPeopleDetector).
    define_singleton_function("get_daimler_people_detector", &cv::HOGDescriptor::getDaimlerPeopleDetector);

  Enum<cv::HOGDescriptor::HistogramNormType> rb_cCvHOGDescriptorHistogramNormType = define_enum_under<cv::HOGDescriptor::HistogramNormType>("HistogramNormType", rb_cCvHOGDescriptor).
    define_value("L2Hys", cv::HOGDescriptor::HistogramNormType::L2Hys);

  rb_cCvHOGDescriptor.define_constant("DEFAULT_NLEVELS", (int)cv::HOGDescriptor::DEFAULT_NLEVELS);

  Enum<cv::HOGDescriptor::DescriptorStorageFormat> rb_cCvHOGDescriptorDescriptorStorageFormat = define_enum_under<cv::HOGDescriptor::DescriptorStorageFormat>("DescriptorStorageFormat", rb_cCvHOGDescriptor).
    define_value("DESCR_FORMAT_COL_BY_COL", cv::HOGDescriptor::DescriptorStorageFormat::DESCR_FORMAT_COL_BY_COL).
    define_value("DESCR_FORMAT_ROW_BY_ROW", cv::HOGDescriptor::DescriptorStorageFormat::DESCR_FORMAT_ROW_BY_ROW);

  rb_cCvQRCodeEncoder = define_class_under<cv::QRCodeEncoder>(rb_mCv, "QRCodeEncoder").
    define_method("encode", &cv::QRCodeEncoder::encode,
      Arg("encoded_info"), Arg("qrcode")).
    define_method("encode_structured_append", &cv::QRCodeEncoder::encodeStructuredAppend,
      Arg("encoded_info"), Arg("qrcodes")).
    define_singleton_function("create", &cv::QRCodeEncoder::create,
      Arg("parameters") = static_cast<const cv::QRCodeEncoder::Params&>(cv::QRCodeEncoder::Params()));

  rb_cCvQRCodeEncoderParams = define_class_under<cv::QRCodeEncoder::Params>(rb_cCvQRCodeEncoder, "Params").
    define_constructor(Constructor<cv::QRCodeEncoder::Params>()).
    define_attr("version", &cv::QRCodeEncoder::Params::version).
    define_attr("correction_level", &cv::QRCodeEncoder::Params::correction_level).
    define_attr("mode", &cv::QRCodeEncoder::Params::mode).
    define_attr("structure_number", &cv::QRCodeEncoder::Params::structure_number);

  Enum<cv::QRCodeEncoder::EncodeMode> rb_cCvQRCodeEncoderEncodeMode = define_enum_under<cv::QRCodeEncoder::EncodeMode>("EncodeMode", rb_cCvQRCodeEncoder).
    define_value("MODE_AUTO", cv::QRCodeEncoder::EncodeMode::MODE_AUTO).
    define_value("MODE_NUMERIC", cv::QRCodeEncoder::EncodeMode::MODE_NUMERIC).
    define_value("MODE_ALPHANUMERIC", cv::QRCodeEncoder::EncodeMode::MODE_ALPHANUMERIC).
    define_value("MODE_BYTE", cv::QRCodeEncoder::EncodeMode::MODE_BYTE).
    define_value("MODE_ECI", cv::QRCodeEncoder::EncodeMode::MODE_ECI).
    define_value("MODE_KANJI", cv::QRCodeEncoder::EncodeMode::MODE_KANJI).
    define_value("MODE_STRUCTURED_APPEND", cv::QRCodeEncoder::EncodeMode::MODE_STRUCTURED_APPEND);

  Enum<cv::QRCodeEncoder::CorrectionLevel> rb_cCvQRCodeEncoderCorrectionLevel = define_enum_under<cv::QRCodeEncoder::CorrectionLevel>("CorrectionLevel", rb_cCvQRCodeEncoder).
    define_value("CORRECT_LEVEL_L", cv::QRCodeEncoder::CorrectionLevel::CORRECT_LEVEL_L).
    define_value("CORRECT_LEVEL_M", cv::QRCodeEncoder::CorrectionLevel::CORRECT_LEVEL_M).
    define_value("CORRECT_LEVEL_Q", cv::QRCodeEncoder::CorrectionLevel::CORRECT_LEVEL_Q).
    define_value("CORRECT_LEVEL_H", cv::QRCodeEncoder::CorrectionLevel::CORRECT_LEVEL_H);

  Enum<cv::QRCodeEncoder::ECIEncodings> rb_cCvQRCodeEncoderECIEncodings = define_enum_under<cv::QRCodeEncoder::ECIEncodings>("ECIEncodings", rb_cCvQRCodeEncoder).
    define_value("ECI_UTF8", cv::QRCodeEncoder::ECIEncodings::ECI_UTF8);

#if RUBY_CV_VERSION >= 408
  rb_cCvQRCodeDetector = define_class_under<cv::QRCodeDetector, cv::GraphicalCodeDetector>(rb_mCv, "QRCodeDetector").
    define_constructor(Constructor<cv::QRCodeDetector>()).
    define_method("set_eps_x", &cv::QRCodeDetector::setEpsX,
      Arg("eps_x")).
    define_method("set_eps_y", &cv::QRCodeDetector::setEpsY,
      Arg("eps_y")).
    define_method("set_use_alignment_markers", &cv::QRCodeDetector::setUseAlignmentMarkers,
      Arg("use_alignment_markers")).
    define_method("decode_curved", &cv::QRCodeDetector::decodeCurved,
      Arg("img"), Arg("points"), Arg("straight_qrcode") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method("detect_and_decode_curved", &cv::QRCodeDetector::detectAndDecodeCurved,
      Arg("img"), Arg("points") = static_cast<cv::OutputArray>(cv::noArray()), Arg("straight_qrcode") = static_cast<cv::OutputArray>(cv::noArray()));

  rb_cCvQRCodeDetectorAruco = define_class_under<cv::QRCodeDetectorAruco, cv::GraphicalCodeDetector>(rb_mCv, "QRCodeDetectorAruco").
    define_constructor(Constructor<cv::QRCodeDetectorAruco>()).
    define_constructor(Constructor<cv::QRCodeDetectorAruco, const cv::QRCodeDetectorAruco::Params&>(),
      Arg("params")).
    define_method("get_detector_parameters", &cv::QRCodeDetectorAruco::getDetectorParameters).
    define_method("set_detector_parameters", &cv::QRCodeDetectorAruco::setDetectorParameters,
      Arg("params")).
    define_method("get_aruco_parameters", &cv::QRCodeDetectorAruco::getArucoParameters).
    define_method("set_aruco_parameters", &cv::QRCodeDetectorAruco::setArucoParameters,
      Arg("params"));

  rb_cCvQRCodeDetectorArucoParams = define_class_under<cv::QRCodeDetectorAruco::Params>(rb_cCvQRCodeDetectorAruco, "Params").
    define_constructor(Constructor<cv::QRCodeDetectorAruco::Params>()).
    define_attr("min_module_size_in_pyramid", &cv::QRCodeDetectorAruco::Params::minModuleSizeInPyramid).
    define_attr("max_rotation", &cv::QRCodeDetectorAruco::Params::maxRotation).
    define_attr("max_module_size_mismatch", &cv::QRCodeDetectorAruco::Params::maxModuleSizeMismatch).
    define_attr("max_timing_pattern_mismatch", &cv::QRCodeDetectorAruco::Params::maxTimingPatternMismatch).
    define_attr("max_penalties", &cv::QRCodeDetectorAruco::Params::maxPenalties).
    define_attr("max_colors_mismatch", &cv::QRCodeDetectorAruco::Params::maxColorsMismatch).
    define_attr("scale_timing_pattern_score", &cv::QRCodeDetectorAruco::Params::scaleTimingPatternScore);
#endif
}