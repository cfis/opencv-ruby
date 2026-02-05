#include <opencv2/video/tracking.hpp>
#include "tracking-rb.hpp"

using namespace Rice;

void Init_Video_Tracking()
{
  Module rb_mCv = define_module("Cv");

  rb_mCv.define_constant("OPTFLOW_USE_INITIAL_FLOW", (int)cv::OPTFLOW_USE_INITIAL_FLOW);
  rb_mCv.define_constant("OPTFLOW_LK_GET_MIN_EIGENVALS", (int)cv::OPTFLOW_LK_GET_MIN_EIGENVALS);
  rb_mCv.define_constant("OPTFLOW_FARNEBACK_GAUSSIAN", (int)cv::OPTFLOW_FARNEBACK_GAUSSIAN);

  rb_mCv.define_module_function<cv::RotatedRect(*)(cv::InputArray, cv::Rect&, cv::TermCriteria)>("cam_shift", &cv::CamShift,
    Arg("prob_image"), Arg("window"), Arg("criteria"));

  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::Rect&, cv::TermCriteria)>("mean_shift", &cv::meanShift,
    Arg("prob_image"), Arg("window"), Arg("criteria"));

  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::OutputArrayOfArrays, cv::Size, int, bool, int, int, bool)>("build_optical_flow_pyramid", &cv::buildOpticalFlowPyramid,
    Arg("img"), Arg("pyramid"), Arg("win_size"), Arg("max_level"), Arg("with_derivatives") = static_cast<bool>(true), Arg("pyr_border") = static_cast<int>(cv::BORDER_REFLECT_101), Arg("deriv_border") = static_cast<int>(cv::BORDER_CONSTANT), Arg("try_reuse_input_image") = static_cast<bool>(true));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray, cv::Size, int, cv::TermCriteria, int, double)>("calc_optical_flow_pyr_lk", &cv::calcOpticalFlowPyrLK,
    Arg("prev_img"), Arg("next_img"), Arg("prev_pts"), Arg("next_pts"), Arg("status"), Arg("err"), Arg("win_size") = static_cast<cv::Size>(cv::Size(21,21)), Arg("max_level") = static_cast<int>(3), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::Type::COUNT+cv::TermCriteria::Type::EPS, 30, 0.01)), Arg("flags") = static_cast<int>(0), Arg("min_eig_threshold") = static_cast<double>(1e-4));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::InputOutputArray, double, int, int, int, int, double, int)>("calc_optical_flow_farneback", &cv::calcOpticalFlowFarneback,
    Arg("prev"), Arg("next"), Arg("flow"), Arg("pyr_scale"), Arg("levels"), Arg("winsize"), Arg("iterations"), Arg("poly_n"), Arg("poly_sigma"), Arg("flags"));

  rb_mCv.define_constant("MOTION_TRANSLATION", (int)cv::MOTION_TRANSLATION);
  rb_mCv.define_constant("MOTION_EUCLIDEAN", (int)cv::MOTION_EUCLIDEAN);
  rb_mCv.define_constant("MOTION_AFFINE", (int)cv::MOTION_AFFINE);
  rb_mCv.define_constant("MOTION_HOMOGRAPHY", (int)cv::MOTION_HOMOGRAPHY);

  rb_mCv.define_module_function<double(*)(cv::InputArray, cv::InputArray, cv::InputArray)>("compute_ecc", &cv::computeECC,
    Arg("template_image"), Arg("input_image"), Arg("input_mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function<double(*)(cv::InputArray, cv::InputArray, cv::InputOutputArray, int, cv::TermCriteria, cv::InputArray, int)>("find_transform_ecc", &cv::findTransformECC,
    Arg("template_image"), Arg("input_image"), Arg("warp_matrix"), Arg("motion_type"), Arg("criteria"), Arg("input_mask"), Arg("gauss_filt_size"));

  rb_mCv.define_module_function<double(*)(cv::InputArray, cv::InputArray, cv::InputOutputArray, int, cv::TermCriteria, cv::InputArray)>("find_transform_ecc", &cv::findTransformECC,
    Arg("template_image"), Arg("input_image"), Arg("warp_matrix"), Arg("motion_type") = static_cast<int>(cv::MOTION_AFFINE), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::Type::COUNT+cv::TermCriteria::Type::EPS, 50, 0.001)), Arg("input_mask") = static_cast<cv::InputArray>(cv::noArray()));

  Rice::Data_Type<cv::KalmanFilter> rb_cCvKalmanFilter = define_class_under<cv::KalmanFilter>(rb_mCv, "KalmanFilter").
    define_constructor(Constructor<cv::KalmanFilter>()).
    define_constructor(Constructor<cv::KalmanFilter, int, int, int, int>(),
      Arg("dynam_params"), Arg("measure_params"), Arg("control_params") = static_cast<int>(0), Arg("type") = static_cast<int>(CV_32F)).
    define_method<void(cv::KalmanFilter::*)(int, int, int, int)>("init", &cv::KalmanFilter::init,
      Arg("dynam_params"), Arg("measure_params"), Arg("control_params") = static_cast<int>(0), Arg("type") = static_cast<int>(CV_32F)).
    define_method<const cv::Mat&(cv::KalmanFilter::*)(const cv::Mat&)>("predict", &cv::KalmanFilter::predict,
      Arg("control") = static_cast<const cv::Mat&>(cv::Mat())).
    define_method<const cv::Mat&(cv::KalmanFilter::*)(const cv::Mat&)>("correct", &cv::KalmanFilter::correct,
      Arg("measurement")).
    define_attr("state_pre", &cv::KalmanFilter::statePre).
    define_attr("state_post", &cv::KalmanFilter::statePost).
    define_attr("transition_matrix", &cv::KalmanFilter::transitionMatrix).
    define_attr("control_matrix", &cv::KalmanFilter::controlMatrix).
    define_attr("measurement_matrix", &cv::KalmanFilter::measurementMatrix).
    define_attr("process_noise_cov", &cv::KalmanFilter::processNoiseCov).
    define_attr("measurement_noise_cov", &cv::KalmanFilter::measurementNoiseCov).
    define_attr("error_cov_pre", &cv::KalmanFilter::errorCovPre).
    define_attr("gain", &cv::KalmanFilter::gain).
    define_attr("error_cov_post", &cv::KalmanFilter::errorCovPost).
    define_attr("temp1", &cv::KalmanFilter::temp1).
    define_attr("temp2", &cv::KalmanFilter::temp2).
    define_attr("temp3", &cv::KalmanFilter::temp3).
    define_attr("temp4", &cv::KalmanFilter::temp4).
    define_attr("temp5", &cv::KalmanFilter::temp5);

  rb_mCv.define_module_function<cv::Mat(*)(const cv::String&)>("read_optical_flow", &cv::readOpticalFlow,
    Arg("path"));

  rb_mCv.define_module_function<bool(*)(const cv::String&, cv::InputArray)>("write_optical_flow", &cv::writeOpticalFlow,
    Arg("path"), Arg("flow"));

  Rice::Data_Type<cv::DenseOpticalFlow> rb_cCvDenseOpticalFlow = define_class_under<cv::DenseOpticalFlow, cv::Algorithm>(rb_mCv, "DenseOpticalFlow").
    define_method<void(cv::DenseOpticalFlow::*)(cv::InputArray, cv::InputArray, cv::InputOutputArray)>("calc", &cv::DenseOpticalFlow::calc,
      Arg("i0"), Arg("i1"), Arg("flow")).
    define_method<void(cv::DenseOpticalFlow::*)()>("collect_garbage", &cv::DenseOpticalFlow::collectGarbage);

  Rice::Data_Type<cv::SparseOpticalFlow> rb_cCvSparseOpticalFlow = define_class_under<cv::SparseOpticalFlow, cv::Algorithm>(rb_mCv, "SparseOpticalFlow").
    define_method<void(cv::SparseOpticalFlow::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray)>("calc", &cv::SparseOpticalFlow::calc,
      Arg("prev_img"), Arg("next_img"), Arg("prev_pts"), Arg("next_pts"), Arg("status"), Arg("err") = static_cast<cv::OutputArray>(cv::noArray()));

  Rice::Data_Type<cv::FarnebackOpticalFlow> rb_cCvFarnebackOpticalFlow = define_class_under<cv::FarnebackOpticalFlow, cv::DenseOpticalFlow>(rb_mCv, "FarnebackOpticalFlow").
    define_method<int(cv::FarnebackOpticalFlow::*)() const>("get_num_levels", &cv::FarnebackOpticalFlow::getNumLevels).
    define_method<void(cv::FarnebackOpticalFlow::*)(int)>("set_num_levels", &cv::FarnebackOpticalFlow::setNumLevels,
      Arg("num_levels")).
    define_method<double(cv::FarnebackOpticalFlow::*)() const>("get_pyr_scale", &cv::FarnebackOpticalFlow::getPyrScale).
    define_method<void(cv::FarnebackOpticalFlow::*)(double)>("set_pyr_scale", &cv::FarnebackOpticalFlow::setPyrScale,
      Arg("pyr_scale")).
    define_method<bool(cv::FarnebackOpticalFlow::*)() const>("get_fast_pyramids?", &cv::FarnebackOpticalFlow::getFastPyramids).
    define_method<void(cv::FarnebackOpticalFlow::*)(bool)>("set_fast_pyramids", &cv::FarnebackOpticalFlow::setFastPyramids,
      Arg("fast_pyramids")).
    define_method<int(cv::FarnebackOpticalFlow::*)() const>("get_win_size", &cv::FarnebackOpticalFlow::getWinSize).
    define_method<void(cv::FarnebackOpticalFlow::*)(int)>("set_win_size", &cv::FarnebackOpticalFlow::setWinSize,
      Arg("win_size")).
    define_method<int(cv::FarnebackOpticalFlow::*)() const>("get_num_iters", &cv::FarnebackOpticalFlow::getNumIters).
    define_method<void(cv::FarnebackOpticalFlow::*)(int)>("set_num_iters", &cv::FarnebackOpticalFlow::setNumIters,
      Arg("num_iters")).
    define_method<int(cv::FarnebackOpticalFlow::*)() const>("get_poly_n", &cv::FarnebackOpticalFlow::getPolyN).
    define_method<void(cv::FarnebackOpticalFlow::*)(int)>("set_poly_n", &cv::FarnebackOpticalFlow::setPolyN,
      Arg("poly_n")).
    define_method<double(cv::FarnebackOpticalFlow::*)() const>("get_poly_sigma", &cv::FarnebackOpticalFlow::getPolySigma).
    define_method<void(cv::FarnebackOpticalFlow::*)(double)>("set_poly_sigma", &cv::FarnebackOpticalFlow::setPolySigma,
      Arg("poly_sigma")).
    define_method<int(cv::FarnebackOpticalFlow::*)() const>("get_flags", &cv::FarnebackOpticalFlow::getFlags).
    define_method<void(cv::FarnebackOpticalFlow::*)(int)>("set_flags", &cv::FarnebackOpticalFlow::setFlags,
      Arg("flags")).
    define_singleton_function<cv::Ptr<cv::FarnebackOpticalFlow>(*)(int, double, bool, int, int, int, double, int)>("create", &cv::FarnebackOpticalFlow::create,
      Arg("num_levels") = static_cast<int>(5), Arg("pyr_scale") = static_cast<double>(0.5), Arg("fast_pyramids") = static_cast<bool>(false), Arg("win_size") = static_cast<int>(13), Arg("num_iters") = static_cast<int>(10), Arg("poly_n") = static_cast<int>(5), Arg("poly_sigma") = static_cast<double>(1.1), Arg("flags") = static_cast<int>(0));

  Rice::Data_Type<cv::VariationalRefinement> rb_cCvVariationalRefinement = define_class_under<cv::VariationalRefinement, cv::DenseOpticalFlow>(rb_mCv, "VariationalRefinement").
    define_method<void(cv::VariationalRefinement::*)(cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::InputOutputArray)>("calc_uv", &cv::VariationalRefinement::calcUV,
      Arg("i0"), Arg("i1"), Arg("flow_u"), Arg("flow_v")).
    define_method<int(cv::VariationalRefinement::*)() const>("get_fixed_point_iterations", &cv::VariationalRefinement::getFixedPointIterations).
    define_method<void(cv::VariationalRefinement::*)(int)>("set_fixed_point_iterations", &cv::VariationalRefinement::setFixedPointIterations,
      Arg("val")).
    define_method<int(cv::VariationalRefinement::*)() const>("get_sor_iterations", &cv::VariationalRefinement::getSorIterations).
    define_method<void(cv::VariationalRefinement::*)(int)>("set_sor_iterations", &cv::VariationalRefinement::setSorIterations,
      Arg("val")).
    define_method<float(cv::VariationalRefinement::*)() const>("get_omega", &cv::VariationalRefinement::getOmega).
    define_method<void(cv::VariationalRefinement::*)(float)>("set_omega", &cv::VariationalRefinement::setOmega,
      Arg("val")).
    define_method<float(cv::VariationalRefinement::*)() const>("get_alpha", &cv::VariationalRefinement::getAlpha).
    define_method<void(cv::VariationalRefinement::*)(float)>("set_alpha", &cv::VariationalRefinement::setAlpha,
      Arg("val")).
    define_method<float(cv::VariationalRefinement::*)() const>("get_delta", &cv::VariationalRefinement::getDelta).
    define_method<void(cv::VariationalRefinement::*)(float)>("set_delta", &cv::VariationalRefinement::setDelta,
      Arg("val")).
    define_method<float(cv::VariationalRefinement::*)() const>("get_gamma", &cv::VariationalRefinement::getGamma).
    define_method<void(cv::VariationalRefinement::*)(float)>("set_gamma", &cv::VariationalRefinement::setGamma,
      Arg("val")).
#if RUBY_CV_VERSION >= 410
    define_method<float(cv::VariationalRefinement::*)() const>("get_epsilon", &cv::VariationalRefinement::getEpsilon).
    define_method<void(cv::VariationalRefinement::*)(float)>("set_epsilon", &cv::VariationalRefinement::setEpsilon,
      Arg("val")).
#endif
    define_singleton_function<cv::Ptr<cv::VariationalRefinement>(*)()>("create", &cv::VariationalRefinement::create);

  Rice::Data_Type<cv::DISOpticalFlow> rb_cCvDISOpticalFlow = define_class_under<cv::DISOpticalFlow, cv::DenseOpticalFlow>(rb_mCv, "DISOpticalFlow").
    define_method<int(cv::DISOpticalFlow::*)() const>("get_finest_scale", &cv::DISOpticalFlow::getFinestScale).
    define_method<void(cv::DISOpticalFlow::*)(int)>("set_finest_scale", &cv::DISOpticalFlow::setFinestScale,
      Arg("val")).
    define_method<int(cv::DISOpticalFlow::*)() const>("get_patch_size", &cv::DISOpticalFlow::getPatchSize).
    define_method<void(cv::DISOpticalFlow::*)(int)>("set_patch_size", &cv::DISOpticalFlow::setPatchSize,
      Arg("val")).
    define_method<int(cv::DISOpticalFlow::*)() const>("get_patch_stride", &cv::DISOpticalFlow::getPatchStride).
    define_method<void(cv::DISOpticalFlow::*)(int)>("set_patch_stride", &cv::DISOpticalFlow::setPatchStride,
      Arg("val")).
    define_method<int(cv::DISOpticalFlow::*)() const>("get_gradient_descent_iterations", &cv::DISOpticalFlow::getGradientDescentIterations).
    define_method<void(cv::DISOpticalFlow::*)(int)>("set_gradient_descent_iterations", &cv::DISOpticalFlow::setGradientDescentIterations,
      Arg("val")).
    define_method<int(cv::DISOpticalFlow::*)() const>("get_variational_refinement_iterations", &cv::DISOpticalFlow::getVariationalRefinementIterations).
    define_method<void(cv::DISOpticalFlow::*)(int)>("set_variational_refinement_iterations", &cv::DISOpticalFlow::setVariationalRefinementIterations,
      Arg("val")).
    define_method<float(cv::DISOpticalFlow::*)() const>("get_variational_refinement_alpha", &cv::DISOpticalFlow::getVariationalRefinementAlpha).
    define_method<void(cv::DISOpticalFlow::*)(float)>("set_variational_refinement_alpha", &cv::DISOpticalFlow::setVariationalRefinementAlpha,
      Arg("val")).
    define_method<float(cv::DISOpticalFlow::*)() const>("get_variational_refinement_delta", &cv::DISOpticalFlow::getVariationalRefinementDelta).
    define_method<void(cv::DISOpticalFlow::*)(float)>("set_variational_refinement_delta", &cv::DISOpticalFlow::setVariationalRefinementDelta,
      Arg("val")).
    define_method<float(cv::DISOpticalFlow::*)() const>("get_variational_refinement_gamma", &cv::DISOpticalFlow::getVariationalRefinementGamma).
    define_method<void(cv::DISOpticalFlow::*)(float)>("set_variational_refinement_gamma", &cv::DISOpticalFlow::setVariationalRefinementGamma,
      Arg("val")).
#if RUBY_CV_VERSION >= 410
    define_method<float(cv::DISOpticalFlow::*)() const>("get_variational_refinement_epsilon", &cv::DISOpticalFlow::getVariationalRefinementEpsilon).
    define_method<void(cv::DISOpticalFlow::*)(float)>("set_variational_refinement_epsilon", &cv::DISOpticalFlow::setVariationalRefinementEpsilon,
      Arg("val")).
#endif
    define_method<bool(cv::DISOpticalFlow::*)() const>("get_use_mean_normalization?", &cv::DISOpticalFlow::getUseMeanNormalization).
    define_method<void(cv::DISOpticalFlow::*)(bool)>("set_use_mean_normalization", &cv::DISOpticalFlow::setUseMeanNormalization,
      Arg("val")).
    define_method<bool(cv::DISOpticalFlow::*)() const>("get_use_spatial_propagation?", &cv::DISOpticalFlow::getUseSpatialPropagation).
    define_method<void(cv::DISOpticalFlow::*)(bool)>("set_use_spatial_propagation", &cv::DISOpticalFlow::setUseSpatialPropagation,
      Arg("val")).
    define_singleton_function<cv::Ptr<cv::DISOpticalFlow>(*)(int)>("create", &cv::DISOpticalFlow::create,
      Arg("preset") = static_cast<int>(cv::DISOpticalFlow::PRESET_FAST));

#if RUBY_CV_VERSION >= 407
  rb_cCvDISOpticalFlow.define_constant("PRESET_ULTRAFAST", (int)cv::DISOpticalFlow::PRESET_ULTRAFAST);
  rb_cCvDISOpticalFlow.define_constant("PRESET_FAST", (int)cv::DISOpticalFlow::PRESET_FAST);
  rb_cCvDISOpticalFlow.define_constant("PRESET_MEDIUM", (int)cv::DISOpticalFlow::PRESET_MEDIUM);
#endif

  Rice::Data_Type<cv::SparsePyrLKOpticalFlow> rb_cCvSparsePyrLKOpticalFlow = define_class_under<cv::SparsePyrLKOpticalFlow, cv::SparseOpticalFlow>(rb_mCv, "SparsePyrLKOpticalFlow").
    define_method<cv::Size(cv::SparsePyrLKOpticalFlow::*)() const>("get_win_size", &cv::SparsePyrLKOpticalFlow::getWinSize).
    define_method<void(cv::SparsePyrLKOpticalFlow::*)(cv::Size)>("set_win_size", &cv::SparsePyrLKOpticalFlow::setWinSize,
      Arg("win_size")).
    define_method<int(cv::SparsePyrLKOpticalFlow::*)() const>("get_max_level", &cv::SparsePyrLKOpticalFlow::getMaxLevel).
    define_method<void(cv::SparsePyrLKOpticalFlow::*)(int)>("set_max_level", &cv::SparsePyrLKOpticalFlow::setMaxLevel,
      Arg("max_level")).
    define_method<cv::TermCriteria(cv::SparsePyrLKOpticalFlow::*)() const>("get_term_criteria", &cv::SparsePyrLKOpticalFlow::getTermCriteria).
    define_method<void(cv::SparsePyrLKOpticalFlow::*)(cv::TermCriteria&)>("set_term_criteria", &cv::SparsePyrLKOpticalFlow::setTermCriteria,
      Arg("crit")).
    define_method<int(cv::SparsePyrLKOpticalFlow::*)() const>("get_flags", &cv::SparsePyrLKOpticalFlow::getFlags).
    define_method<void(cv::SparsePyrLKOpticalFlow::*)(int)>("set_flags", &cv::SparsePyrLKOpticalFlow::setFlags,
      Arg("flags")).
    define_method<double(cv::SparsePyrLKOpticalFlow::*)() const>("get_min_eig_threshold", &cv::SparsePyrLKOpticalFlow::getMinEigThreshold).
    define_method<void(cv::SparsePyrLKOpticalFlow::*)(double)>("set_min_eig_threshold", &cv::SparsePyrLKOpticalFlow::setMinEigThreshold,
      Arg("min_eig_threshold")).
    define_singleton_function<cv::Ptr<cv::SparsePyrLKOpticalFlow>(*)(cv::Size, int, cv::TermCriteria, int, double)>("create", &cv::SparsePyrLKOpticalFlow::create,
      Arg("win_size") = static_cast<cv::Size>(cv::Size(21, 21)), Arg("max_level") = static_cast<int>(3), Arg("crit") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::Type::COUNT+cv::TermCriteria::Type::EPS, 30, 0.01)), Arg("flags") = static_cast<int>(0), Arg("min_eig_threshold") = static_cast<double>(1e-4));

  Rice::Data_Type<cv::Tracker> rb_cCvTracker = define_class_under<cv::Tracker>(rb_mCv, "Tracker").
    define_method<void(cv::Tracker::*)(cv::InputArray, const cv::Rect&)>("init", &cv::Tracker::init,
      Arg("image"), Arg("bounding_box")).
    define_method<bool(cv::Tracker::*)(cv::InputArray, cv::Rect&)>("update", &cv::Tracker::update,
      Arg("image"), Arg("bounding_box"));

  Rice::Data_Type<cv::TrackerMIL> rb_cCvTrackerMIL = define_class_under<cv::TrackerMIL, cv::Tracker>(rb_mCv, "TrackerMIL").
    define_singleton_function<cv::Ptr<cv::TrackerMIL>(*)(const cv::TrackerMIL::Params&)>("create", &cv::TrackerMIL::create,
      Arg("parameters") = static_cast<const cv::TrackerMIL::Params&>(cv::TrackerMIL::Params()));

  Rice::Data_Type<cv::TrackerMIL::Params> rb_cCvTrackerMILParams = define_class_under<cv::TrackerMIL::Params>(rb_cCvTrackerMIL, "Params").
    define_constructor(Constructor<cv::TrackerMIL::Params>()).
    define_attr("sampler_init_in_radius", &cv::TrackerMIL::Params::samplerInitInRadius).
    define_attr("sampler_init_max_neg_num", &cv::TrackerMIL::Params::samplerInitMaxNegNum).
    define_attr("sampler_search_win_size", &cv::TrackerMIL::Params::samplerSearchWinSize).
    define_attr("sampler_track_in_radius", &cv::TrackerMIL::Params::samplerTrackInRadius).
    define_attr("sampler_track_max_pos_num", &cv::TrackerMIL::Params::samplerTrackMaxPosNum).
    define_attr("sampler_track_max_neg_num", &cv::TrackerMIL::Params::samplerTrackMaxNegNum).
    define_attr("feature_set_num_features", &cv::TrackerMIL::Params::featureSetNumFeatures);

  Rice::Data_Type<cv::TrackerGOTURN> rb_cCvTrackerGOTURN = define_class_under<cv::TrackerGOTURN, cv::Tracker>(rb_mCv, "TrackerGOTURN").
    define_singleton_function<cv::Ptr<cv::TrackerGOTURN>(*)(const cv::TrackerGOTURN::Params&)>("create", &cv::TrackerGOTURN::create,
      Arg("parameters") = static_cast<const cv::TrackerGOTURN::Params&>(cv::TrackerGOTURN::Params()));

  Rice::Data_Type<cv::TrackerGOTURN::Params> rb_cCvTrackerGOTURNParams = define_class_under<cv::TrackerGOTURN::Params>(rb_cCvTrackerGOTURN, "Params").
    define_constructor(Constructor<cv::TrackerGOTURN::Params>()).
    define_attr("model_txt", &cv::TrackerGOTURN::Params::modelTxt).
    define_attr("model_bin", &cv::TrackerGOTURN::Params::modelBin);

  Rice::Data_Type<cv::TrackerDaSiamRPN> rb_cCvTrackerDaSiamRPN = define_class_under<cv::TrackerDaSiamRPN, cv::Tracker>(rb_mCv, "TrackerDaSiamRPN").
    define_singleton_function<cv::Ptr<cv::TrackerDaSiamRPN>(*)(const cv::TrackerDaSiamRPN::Params&)>("create", &cv::TrackerDaSiamRPN::create,
      Arg("parameters") = static_cast<const cv::TrackerDaSiamRPN::Params&>(cv::TrackerDaSiamRPN::Params())).
    define_method<float(cv::TrackerDaSiamRPN::*)()>("get_tracking_score", &cv::TrackerDaSiamRPN::getTrackingScore);

  Rice::Data_Type<cv::TrackerDaSiamRPN::Params> rb_cCvTrackerDaSiamRPNParams = define_class_under<cv::TrackerDaSiamRPN::Params>(rb_cCvTrackerDaSiamRPN, "Params").
    define_constructor(Constructor<cv::TrackerDaSiamRPN::Params>()).
    define_attr("model", &cv::TrackerDaSiamRPN::Params::model).
    define_attr("kernel_cls1", &cv::TrackerDaSiamRPN::Params::kernel_cls1).
    define_attr("kernel_r1", &cv::TrackerDaSiamRPN::Params::kernel_r1).
    define_attr("backend", &cv::TrackerDaSiamRPN::Params::backend).
    define_attr("target", &cv::TrackerDaSiamRPN::Params::target);

#if RUBY_CV_VERSION >= 407
  Rice::Data_Type<cv::TrackerNano> rb_cCvTrackerNano = define_class_under<cv::TrackerNano, cv::Tracker>(rb_mCv, "TrackerNano").
    define_singleton_function<cv::Ptr<cv::TrackerNano>(*)(const cv::TrackerNano::Params&)>("create", &cv::TrackerNano::create,
      Arg("parameters") = static_cast<const cv::TrackerNano::Params&>(cv::TrackerNano::Params())).
    define_method<float(cv::TrackerNano::*)()>("get_tracking_score", &cv::TrackerNano::getTrackingScore);

  Rice::Data_Type<cv::TrackerNano::Params> rb_cCvTrackerNanoParams = define_class_under<cv::TrackerNano::Params>(rb_cCvTrackerNano, "Params").
    define_constructor(Constructor<cv::TrackerNano::Params>()).
    define_attr("backbone", &cv::TrackerNano::Params::backbone).
    define_attr("neckhead", &cv::TrackerNano::Params::neckhead).
    define_attr("backend", &cv::TrackerNano::Params::backend).
    define_attr("target", &cv::TrackerNano::Params::target);
#endif

#if RUBY_CV_VERSION >= 409
  Rice::Data_Type<cv::TrackerVit> rb_cCvTrackerVit = define_class_under<cv::TrackerVit, cv::Tracker>(rb_mCv, "TrackerVit").
    define_singleton_function<cv::Ptr<cv::TrackerVit>(*)(const cv::TrackerVit::Params&)>("create", &cv::TrackerVit::create,
      Arg("parameters") = static_cast<const cv::TrackerVit::Params&>(cv::TrackerVit::Params())).
    define_method<float(cv::TrackerVit::*)()>("get_tracking_score", &cv::TrackerVit::getTrackingScore);

  Rice::Data_Type<cv::TrackerVit::Params> rb_cCvTrackerVitParams = define_class_under<cv::TrackerVit::Params>(rb_cCvTrackerVit, "Params").
    define_constructor(Constructor<cv::TrackerVit::Params>()).
    define_attr("net", &cv::TrackerVit::Params::net).
    define_attr("backend", &cv::TrackerVit::Params::backend).
    define_attr("target", &cv::TrackerVit::Params::target).
    define_attr("meanvalue", &cv::TrackerVit::Params::meanvalue).
    define_attr("stdvalue", &cv::TrackerVit::Params::stdvalue).
    define_attr("tracking_score_threshold", &cv::TrackerVit::Params::tracking_score_threshold);
#endif
}