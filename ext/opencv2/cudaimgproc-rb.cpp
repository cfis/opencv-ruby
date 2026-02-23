#include <opencv2/cudaimgproc.hpp>
#include "cudaimgproc-rb.hpp"

using namespace Rice;

void Init_Cudaimgproc()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, cv::cuda::Stream&)>("cvt_color", &cv::cuda::cvtColor,
    Arg("src"), Arg("dst"), Arg("code"), Arg("dcn") = static_cast<int>(0), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Enum<cv::cuda::DemosaicTypes> rb_cCvCudaDemosaicTypes = define_enum_under<cv::cuda::DemosaicTypes>("DemosaicTypes", rb_mCvCuda).
    define_value("COLOR_BayerBG2BGR_MHT", cv::cuda::DemosaicTypes::COLOR_BayerBG2BGR_MHT).
    define_value("COLOR_BayerGB2BGR_MHT", cv::cuda::DemosaicTypes::COLOR_BayerGB2BGR_MHT).
    define_value("COLOR_BayerRG2BGR_MHT", cv::cuda::DemosaicTypes::COLOR_BayerRG2BGR_MHT).
    define_value("COLOR_BayerGR2BGR_MHT", cv::cuda::DemosaicTypes::COLOR_BayerGR2BGR_MHT).
    define_value("COLOR_BayerBG2RGB_MHT", cv::cuda::DemosaicTypes::COLOR_BayerBG2RGB_MHT).
    define_value("COLOR_BayerGB2RGB_MHT", cv::cuda::DemosaicTypes::COLOR_BayerGB2RGB_MHT).
    define_value("COLOR_BayerRG2RGB_MHT", cv::cuda::DemosaicTypes::COLOR_BayerRG2RGB_MHT).
    define_value("COLOR_BayerGR2RGB_MHT", cv::cuda::DemosaicTypes::COLOR_BayerGR2RGB_MHT).
    define_value("COLOR_BayerBG2GRAY_MHT", cv::cuda::DemosaicTypes::COLOR_BayerBG2GRAY_MHT).
    define_value("COLOR_BayerGB2GRAY_MHT", cv::cuda::DemosaicTypes::COLOR_BayerGB2GRAY_MHT).
    define_value("COLOR_BayerRG2GRAY_MHT", cv::cuda::DemosaicTypes::COLOR_BayerRG2GRAY_MHT).
    define_value("COLOR_BayerGR2GRAY_MHT", cv::cuda::DemosaicTypes::COLOR_BayerGR2GRAY_MHT);

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, cv::cuda::Stream&)>("demosaicing", &cv::cuda::demosaicing,
    Arg("src"), Arg("dst"), Arg("code"), Arg("dcn") = static_cast<int>(-1), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputOutputArray, const int[4], cv::cuda::Stream&)>("swap_channels", &cv::cuda::swapChannels,
    Arg("image"), Arg("dst_order"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, bool, cv::cuda::Stream&)>("gamma_correction", &cv::cuda::gammaCorrection,
    Arg("src"), Arg("dst"), Arg("forward") = static_cast<bool>(true), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Enum<cv::cuda::AlphaCompTypes> rb_cCvCudaAlphaCompTypes = define_enum_under<cv::cuda::AlphaCompTypes>("AlphaCompTypes", rb_mCvCuda).
    define_value("ALPHA_OVER", cv::cuda::AlphaCompTypes::ALPHA_OVER).
    define_value("ALPHA_IN", cv::cuda::AlphaCompTypes::ALPHA_IN).
    define_value("ALPHA_OUT", cv::cuda::AlphaCompTypes::ALPHA_OUT).
    define_value("ALPHA_ATOP", cv::cuda::AlphaCompTypes::ALPHA_ATOP).
    define_value("ALPHA_XOR", cv::cuda::AlphaCompTypes::ALPHA_XOR).
    define_value("ALPHA_PLUS", cv::cuda::AlphaCompTypes::ALPHA_PLUS).
    define_value("ALPHA_OVER_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_OVER_PREMUL).
    define_value("ALPHA_IN_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_IN_PREMUL).
    define_value("ALPHA_OUT_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_OUT_PREMUL).
    define_value("ALPHA_ATOP_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_ATOP_PREMUL).
    define_value("ALPHA_XOR_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_XOR_PREMUL).
    define_value("ALPHA_PLUS_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_PLUS_PREMUL).
    define_value("ALPHA_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_PREMUL);

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, cv::cuda::Stream&)>("alpha_comp", &cv::cuda::alphaComp,
    Arg("img1"), Arg("img2"), Arg("dst"), Arg("alpha_op"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("calc_hist", &cv::cuda::calcHist,
    Arg("src"), Arg("hist"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("calc_hist", &cv::cuda::calcHist,
    Arg("src"), Arg("mask"), Arg("hist"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("equalize_hist", &cv::cuda::equalizeHist,
    Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Rice::Data_Type<cv::cuda::CLAHE> rb_cCvCudaCLAHE = define_class_under<cv::cuda::CLAHE, cv::CLAHE>(rb_mCvCuda, "CLAHE").
    define_method<void(cv::cuda::CLAHE::*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("apply", &cv::cuda::CLAHE::apply,
      Arg("src"), Arg("dst"), Arg("stream"));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::CLAHE>(*)(double, cv::Size)>("create_clahe", &cv::cuda::createCLAHE,
    Arg("clip_limit") = static_cast<double>(40.0), Arg("tile_grid_size") = static_cast<cv::Size>(cv::Size(8, 8)));

  rb_mCvCuda.define_module_function<void(*)(cv::OutputArray, int, int, int, cv::cuda::Stream&)>("even_levels", &cv::cuda::evenLevels,
    Arg("levels"), Arg("n_levels"), Arg("lower_level"), Arg("upper_level"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, int, cv::cuda::Stream&)>("hist_even", &cv::cuda::histEven,
    Arg("src"), Arg("hist"), Arg("hist_size"), Arg("lower_level"), Arg("upper_level"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, GpuMat[4], int[4], int[4], int[4], cv::cuda::Stream&)>("hist_even", &cv::cuda::histEven,
    Arg("src"), Arg("hist"), Arg("hist_size"), Arg("lower_level"), Arg("upper_level"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::cuda::Stream&)>("hist_range", &cv::cuda::histRange,
    Arg("src"), Arg("hist"), Arg("levels"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, GpuMat[4], const GpuMat[4], cv::cuda::Stream&)>("hist_range", &cv::cuda::histRange,
    Arg("src"), Arg("hist"), Arg("levels"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Rice::Data_Type<cv::cuda::CannyEdgeDetector> rb_cCvCudaCannyEdgeDetector = define_class_under<cv::cuda::CannyEdgeDetector, cv::Algorithm>(rb_mCvCuda, "CannyEdgeDetector").
    define_method<void(cv::cuda::CannyEdgeDetector::*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("detect", &cv::cuda::CannyEdgeDetector::detect,
      Arg("image"), Arg("edges"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::CannyEdgeDetector::*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("detect", &cv::cuda::CannyEdgeDetector::detect,
      Arg("dx"), Arg("dy"), Arg("edges"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::CannyEdgeDetector::*)(double)>("set_low_threshold", &cv::cuda::CannyEdgeDetector::setLowThreshold,
      Arg("low_thresh")).
    define_method<double(cv::cuda::CannyEdgeDetector::*)() const>("get_low_threshold", &cv::cuda::CannyEdgeDetector::getLowThreshold).
    define_method<void(cv::cuda::CannyEdgeDetector::*)(double)>("set_high_threshold", &cv::cuda::CannyEdgeDetector::setHighThreshold,
      Arg("high_thresh")).
    define_method<double(cv::cuda::CannyEdgeDetector::*)() const>("get_high_threshold", &cv::cuda::CannyEdgeDetector::getHighThreshold).
    define_method<void(cv::cuda::CannyEdgeDetector::*)(int)>("set_apperture_size", &cv::cuda::CannyEdgeDetector::setAppertureSize,
      Arg("apperture_size")).
    define_method<int(cv::cuda::CannyEdgeDetector::*)() const>("get_apperture_size", &cv::cuda::CannyEdgeDetector::getAppertureSize).
    define_method<void(cv::cuda::CannyEdgeDetector::*)(bool)>("set_l2_gradient", &cv::cuda::CannyEdgeDetector::setL2Gradient,
      Arg("l2gradient")).
    define_method<bool(cv::cuda::CannyEdgeDetector::*)() const>("get_l2_gradient?", &cv::cuda::CannyEdgeDetector::getL2Gradient);

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::CannyEdgeDetector>(*)(double, double, int, bool)>("create_canny_edge_detector", &cv::cuda::createCannyEdgeDetector,
    Arg("low_thresh"), Arg("high_thresh"), Arg("apperture_size") = static_cast<int>(3), Arg("l2gradient") = static_cast<bool>(false));

  Rice::Data_Type<cv::cuda::HoughLinesDetector> rb_cCvCudaHoughLinesDetector = define_class_under<cv::cuda::HoughLinesDetector, cv::Algorithm>(rb_mCvCuda, "HoughLinesDetector").
    define_method<void(cv::cuda::HoughLinesDetector::*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("detect", &cv::cuda::HoughLinesDetector::detect,
      Arg("src"), Arg("lines"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::HoughLinesDetector::*)(cv::InputArray, cv::OutputArray, cv::OutputArray, cv::cuda::Stream&)>("download_results", &cv::cuda::HoughLinesDetector::downloadResults,
      Arg("d_lines"), Arg("h_lines"), Arg("h_votes") = static_cast<cv::OutputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::HoughLinesDetector::*)(float)>("set_rho", &cv::cuda::HoughLinesDetector::setRho,
      Arg("rho")).
    define_method<float(cv::cuda::HoughLinesDetector::*)() const>("get_rho", &cv::cuda::HoughLinesDetector::getRho).
    define_method<void(cv::cuda::HoughLinesDetector::*)(float)>("set_theta", &cv::cuda::HoughLinesDetector::setTheta,
      Arg("theta")).
    define_method<float(cv::cuda::HoughLinesDetector::*)() const>("get_theta", &cv::cuda::HoughLinesDetector::getTheta).
    define_method<void(cv::cuda::HoughLinesDetector::*)(int)>("set_threshold", &cv::cuda::HoughLinesDetector::setThreshold,
      Arg("threshold")).
    define_method<int(cv::cuda::HoughLinesDetector::*)() const>("get_threshold", &cv::cuda::HoughLinesDetector::getThreshold).
    define_method<void(cv::cuda::HoughLinesDetector::*)(bool)>("set_do_sort", &cv::cuda::HoughLinesDetector::setDoSort,
      Arg("do_sort")).
    define_method<bool(cv::cuda::HoughLinesDetector::*)() const>("get_do_sort?", &cv::cuda::HoughLinesDetector::getDoSort).
    define_method<void(cv::cuda::HoughLinesDetector::*)(int)>("set_max_lines", &cv::cuda::HoughLinesDetector::setMaxLines,
      Arg("max_lines")).
    define_method<int(cv::cuda::HoughLinesDetector::*)() const>("get_max_lines", &cv::cuda::HoughLinesDetector::getMaxLines);

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::HoughLinesDetector>(*)(float, float, int, bool, int)>("create_hough_lines_detector", &cv::cuda::createHoughLinesDetector,
    Arg("rho"), Arg("theta"), Arg("threshold"), Arg("do_sort") = static_cast<bool>(false), Arg("max_lines") = static_cast<int>(4096));

  Rice::Data_Type<cv::cuda::HoughSegmentDetector> rb_cCvCudaHoughSegmentDetector = define_class_under<cv::cuda::HoughSegmentDetector, cv::Algorithm>(rb_mCvCuda, "HoughSegmentDetector").
    define_method<void(cv::cuda::HoughSegmentDetector::*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("detect", &cv::cuda::HoughSegmentDetector::detect,
      Arg("src"), Arg("lines"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::HoughSegmentDetector::*)(float)>("set_rho", &cv::cuda::HoughSegmentDetector::setRho,
      Arg("rho")).
    define_method<float(cv::cuda::HoughSegmentDetector::*)() const>("get_rho", &cv::cuda::HoughSegmentDetector::getRho).
    define_method<void(cv::cuda::HoughSegmentDetector::*)(float)>("set_theta", &cv::cuda::HoughSegmentDetector::setTheta,
      Arg("theta")).
    define_method<float(cv::cuda::HoughSegmentDetector::*)() const>("get_theta", &cv::cuda::HoughSegmentDetector::getTheta).
    define_method<void(cv::cuda::HoughSegmentDetector::*)(int)>("set_min_line_length", &cv::cuda::HoughSegmentDetector::setMinLineLength,
      Arg("min_line_length")).
    define_method<int(cv::cuda::HoughSegmentDetector::*)() const>("get_min_line_length", &cv::cuda::HoughSegmentDetector::getMinLineLength).
    define_method<void(cv::cuda::HoughSegmentDetector::*)(int)>("set_max_line_gap", &cv::cuda::HoughSegmentDetector::setMaxLineGap,
      Arg("max_line_gap")).
    define_method<int(cv::cuda::HoughSegmentDetector::*)() const>("get_max_line_gap", &cv::cuda::HoughSegmentDetector::getMaxLineGap).
    define_method<void(cv::cuda::HoughSegmentDetector::*)(int)>("set_max_lines", &cv::cuda::HoughSegmentDetector::setMaxLines,
      Arg("max_lines")).
    define_method<int(cv::cuda::HoughSegmentDetector::*)() const>("get_max_lines", &cv::cuda::HoughSegmentDetector::getMaxLines).
    define_method<void(cv::cuda::HoughSegmentDetector::*)(int)>("set_threshold", &cv::cuda::HoughSegmentDetector::setThreshold,
      Arg("threshold")).
    define_method<int(cv::cuda::HoughSegmentDetector::*)() const>("get_threshold", &cv::cuda::HoughSegmentDetector::getThreshold);

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::HoughSegmentDetector>(*)(float, float, int, int, int, int)>("create_hough_segment_detector", &cv::cuda::createHoughSegmentDetector,
    Arg("rho"), Arg("theta"), Arg("min_line_length"), Arg("max_line_gap"), Arg("max_lines") = static_cast<int>(4096), Arg("threshold") = static_cast<int>(-1));

  Rice::Data_Type<cv::cuda::HoughCirclesDetector> rb_cCvCudaHoughCirclesDetector = define_class_under<cv::cuda::HoughCirclesDetector, cv::Algorithm>(rb_mCvCuda, "HoughCirclesDetector").
    define_method<void(cv::cuda::HoughCirclesDetector::*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("detect", &cv::cuda::HoughCirclesDetector::detect,
      Arg("src"), Arg("circles"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(float)>("set_dp", &cv::cuda::HoughCirclesDetector::setDp,
      Arg("dp")).
    define_method<float(cv::cuda::HoughCirclesDetector::*)() const>("get_dp", &cv::cuda::HoughCirclesDetector::getDp).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(float)>("set_min_dist", &cv::cuda::HoughCirclesDetector::setMinDist,
      Arg("min_dist")).
    define_method<float(cv::cuda::HoughCirclesDetector::*)() const>("get_min_dist", &cv::cuda::HoughCirclesDetector::getMinDist).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(int)>("set_canny_threshold", &cv::cuda::HoughCirclesDetector::setCannyThreshold,
      Arg("canny_threshold")).
    define_method<int(cv::cuda::HoughCirclesDetector::*)() const>("get_canny_threshold", &cv::cuda::HoughCirclesDetector::getCannyThreshold).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(int)>("set_votes_threshold", &cv::cuda::HoughCirclesDetector::setVotesThreshold,
      Arg("votes_threshold")).
    define_method<int(cv::cuda::HoughCirclesDetector::*)() const>("get_votes_threshold", &cv::cuda::HoughCirclesDetector::getVotesThreshold).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(int)>("set_min_radius", &cv::cuda::HoughCirclesDetector::setMinRadius,
      Arg("min_radius")).
    define_method<int(cv::cuda::HoughCirclesDetector::*)() const>("get_min_radius", &cv::cuda::HoughCirclesDetector::getMinRadius).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(int)>("set_max_radius", &cv::cuda::HoughCirclesDetector::setMaxRadius,
      Arg("max_radius")).
    define_method<int(cv::cuda::HoughCirclesDetector::*)() const>("get_max_radius", &cv::cuda::HoughCirclesDetector::getMaxRadius).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(int)>("set_max_circles", &cv::cuda::HoughCirclesDetector::setMaxCircles,
      Arg("max_circles")).
    define_method<int(cv::cuda::HoughCirclesDetector::*)() const>("get_max_circles", &cv::cuda::HoughCirclesDetector::getMaxCircles);

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::HoughCirclesDetector>(*)(float, float, int, int, int, int, int)>("create_hough_circles_detector", &cv::cuda::createHoughCirclesDetector,
    Arg("dp"), Arg("min_dist"), Arg("canny_threshold"), Arg("votes_threshold"), Arg("min_radius"), Arg("max_radius"), Arg("max_circles") = static_cast<int>(4096));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::GeneralizedHoughBallard>(*)()>("create_generalized_hough_ballard", &cv::cuda::createGeneralizedHoughBallard);

  rb_mCvCuda.define_module_function<cv::Ptr<cv::GeneralizedHoughGuil>(*)()>("create_generalized_hough_guil", &cv::cuda::createGeneralizedHoughGuil);

  Rice::Data_Type<cv::cuda::CornernessCriteria> rb_cCvCudaCornernessCriteria = define_class_under<cv::cuda::CornernessCriteria, cv::Algorithm>(rb_mCvCuda, "CornernessCriteria").
    define_method<void(cv::cuda::CornernessCriteria::*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("compute", &cv::cuda::CornernessCriteria::compute,
      Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::CornernessCriteria>(*)(int, int, int, double, int)>("create_harris_corner", &cv::cuda::createHarrisCorner,
    Arg("src_type"), Arg("block_size"), Arg("ksize"), Arg("k"), Arg("border_type") = static_cast<int>(cv::BORDER_REFLECT101));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::CornernessCriteria>(*)(int, int, int, int)>("create_min_eigen_val_corner", &cv::cuda::createMinEigenValCorner,
    Arg("src_type"), Arg("block_size"), Arg("ksize"), Arg("border_type") = static_cast<int>(cv::BORDER_REFLECT101));

  Rice::Data_Type<cv::cuda::CornersDetector> rb_cCvCudaCornersDetector = define_class_under<cv::cuda::CornersDetector, cv::Algorithm>(rb_mCvCuda, "CornersDetector").
    define_method<void(cv::cuda::CornersDetector::*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::cuda::Stream&)>("detect", &cv::cuda::CornersDetector::detect,
      Arg("image"), Arg("corners"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<void(cv::cuda::CornersDetector::*)(int)>("set_max_corners", &cv::cuda::CornersDetector::setMaxCorners,
      Arg("max_corners")).
    define_method<void(cv::cuda::CornersDetector::*)(double)>("set_min_distance", &cv::cuda::CornersDetector::setMinDistance,
      Arg("min_distance"));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::CornersDetector>(*)(int, int, double, double, int, bool, double)>("create_good_features_to_track_detector", &cv::cuda::createGoodFeaturesToTrackDetector,
    Arg("src_type"), Arg("max_corners") = static_cast<int>(1000), Arg("quality_level") = static_cast<double>(0.01), Arg("min_distance") = static_cast<double>(0.0), Arg("block_size") = static_cast<int>(3), Arg("use_harris_detector") = static_cast<bool>(false), Arg("harris_k") = static_cast<double>(0.04));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, cv::TermCriteria, cv::cuda::Stream&)>("mean_shift_filtering", &cv::cuda::meanShiftFiltering,
    Arg("src"), Arg("dst"), Arg("sp"), Arg("sr"), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::Type::MAX_ITER + cv::TermCriteria::Type::EPS, 5, 1)), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, int, int, cv::TermCriteria, cv::cuda::Stream&)>("mean_shift_proc", &cv::cuda::meanShiftProc,
    Arg("src"), Arg("dstr"), Arg("dstsp"), Arg("sp"), Arg("sr"), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::Type::MAX_ITER + cv::TermCriteria::Type::EPS, 5, 1)), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, int, cv::TermCriteria, cv::cuda::Stream&)>("mean_shift_segmentation", &cv::cuda::meanShiftSegmentation,
    Arg("src"), Arg("dst"), Arg("sp"), Arg("sr"), Arg("minsize"), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::Type::MAX_ITER + cv::TermCriteria::Type::EPS, 5, 1)), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Rice::Data_Type<cv::cuda::TemplateMatching> rb_cCvCudaTemplateMatching = define_class_under<cv::cuda::TemplateMatching, cv::Algorithm>(rb_mCvCuda, "TemplateMatching").
    define_method<void(cv::cuda::TemplateMatching::*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("match", &cv::cuda::TemplateMatching::match,
      Arg("image"), Arg("templ"), Arg("result"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::TemplateMatching>(*)(int, int, cv::Size)>("create_template_matching", &cv::cuda::createTemplateMatching,
    Arg("src_type"), Arg("method"), Arg("user_block_size") = static_cast<cv::Size>(cv::Size()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, float, float, int, cv::cuda::Stream&)>("bilateral_filter", &cv::cuda::bilateralFilter,
    Arg("src"), Arg("dst"), Arg("kernel_size"), Arg("sigma_color"), Arg("sigma_spatial"), Arg("border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("blend_linear", &cv::cuda::blendLinear,
    Arg("img1"), Arg("img2"), Arg("weights1"), Arg("weights2"), Arg("result"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Enum<cv::cuda::ConnectedComponentsAlgorithmsTypes> rb_cCvCudaConnectedComponentsAlgorithmsTypes = define_enum_under<cv::cuda::ConnectedComponentsAlgorithmsTypes>("ConnectedComponentsAlgorithmsTypes", rb_mCvCuda).
    define_value("CCL_DEFAULT", cv::cuda::ConnectedComponentsAlgorithmsTypes::CCL_DEFAULT).
    define_value("CCL_BKE", cv::cuda::ConnectedComponentsAlgorithmsTypes::CCL_BKE);

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, cv::cuda::ConnectedComponentsAlgorithmsTypes)>("connected_components", &cv::cuda::connectedComponents,
    Arg("image"), Arg("labels"), Arg("connectivity"), Arg("ltype"), Arg("ccltype"));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int)>("connected_components", &cv::cuda::connectedComponents,
    Arg("image"), Arg("labels"), Arg("connectivity") = static_cast<int>(8), Arg("ltype") = static_cast<int>(CV_32S));

  Enum<cv::cuda::MomentsOrder> rb_cCvCudaMomentsOrder = define_enum_under<cv::cuda::MomentsOrder>("MomentsOrder", rb_mCvCuda).
    define_value("FIRST_ORDER_MOMENTS", cv::cuda::MomentsOrder::FIRST_ORDER_MOMENTS).
    define_value("SECOND_ORDER_MOMENTS", cv::cuda::MomentsOrder::SECOND_ORDER_MOMENTS).
    define_value("THIRD_ORDER_MOMENTS", cv::cuda::MomentsOrder::THIRD_ORDER_MOMENTS);

  rb_mCvCuda.define_module_function<int(*)(const cv::cuda::MomentsOrder)>("num_moments", &cv::cuda::numMoments,
    Arg("order"));

  rb_mCvCuda.define_module_function<cv::Moments(*)(cv::Mat, const cv::cuda::MomentsOrder, const int)>("convert_spatial_moments", &cv::cuda::convertSpatialMoments,
    Arg("spatial_moments"), Arg("order"), Arg("moments_type"));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, const bool, const cv::cuda::MomentsOrder, const int, cv::cuda::Stream&)>("spatial_moments", &cv::cuda::spatialMoments,
    Arg("src"), Arg("moments"), Arg("binary_image") = static_cast<const bool>(false), Arg("order") = static_cast<const cv::cuda::MomentsOrder>(cv::cuda::THIRD_ORDER_MOMENTS), Arg("moments_type") = static_cast<const int>(CV_64F), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<cv::Moments(*)(cv::InputArray, const bool, const cv::cuda::MomentsOrder, const int)>("moments", &cv::cuda::moments,
    Arg("src"), Arg("binary_image") = static_cast<const bool>(false), Arg("order") = static_cast<const cv::cuda::MomentsOrder>(cv::cuda::THIRD_ORDER_MOMENTS), Arg("moments_type") = static_cast<const int>(CV_64F));
}
