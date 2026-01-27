#include <opencv2/superres/optical_flow.hpp>
#include "optical_flow-rb.hpp"

using namespace Rice;

void Init_Superres_OpticalFlow()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvSuperres = define_module_under(rb_mCv, "Superres");

  Rice::Data_Type<cv::superres::DenseOpticalFlowExt> rb_cCvSuperresDenseOpticalFlowExt = define_class_under<cv::superres::DenseOpticalFlowExt, cv::Algorithm>(rb_mCvSuperres, "DenseOpticalFlowExt").
    define_method("calc", &cv::superres::DenseOpticalFlowExt::calc,
      Arg("frame0"), Arg("frame1"), Arg("flow1"), Arg("flow2") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method("collect_garbage", &cv::superres::DenseOpticalFlowExt::collectGarbage);

  Rice::Data_Type<cv::superres::FarnebackOpticalFlow> rb_cCvSuperresFarnebackOpticalFlow = define_class_under<cv::superres::FarnebackOpticalFlow, cv::superres::DenseOpticalFlowExt>(rb_mCvSuperres, "FarnebackOpticalFlow").
    define_method("get_pyr_scale", &cv::superres::FarnebackOpticalFlow::getPyrScale).
    define_method("set_pyr_scale", &cv::superres::FarnebackOpticalFlow::setPyrScale,
      Arg("val")).
    define_method("get_levels_number", &cv::superres::FarnebackOpticalFlow::getLevelsNumber).
    define_method("set_levels_number", &cv::superres::FarnebackOpticalFlow::setLevelsNumber,
      Arg("val")).
    define_method("get_window_size", &cv::superres::FarnebackOpticalFlow::getWindowSize).
    define_method("set_window_size", &cv::superres::FarnebackOpticalFlow::setWindowSize,
      Arg("val")).
    define_method("get_iterations", &cv::superres::FarnebackOpticalFlow::getIterations).
    define_method("set_iterations", &cv::superres::FarnebackOpticalFlow::setIterations,
      Arg("val")).
    define_method("get_poly_n", &cv::superres::FarnebackOpticalFlow::getPolyN).
    define_method("set_poly_n", &cv::superres::FarnebackOpticalFlow::setPolyN,
      Arg("val")).
    define_method("get_poly_sigma", &cv::superres::FarnebackOpticalFlow::getPolySigma).
    define_method("set_poly_sigma", &cv::superres::FarnebackOpticalFlow::setPolySigma,
      Arg("val")).
    define_method("get_flags", &cv::superres::FarnebackOpticalFlow::getFlags).
    define_method("set_flags", &cv::superres::FarnebackOpticalFlow::setFlags,
      Arg("val"));

  rb_mCvSuperres.define_module_function("create_opt_flow_farneback", &cv::superres::createOptFlow_Farneback);

  rb_mCvSuperres.define_module_function("create_opt_flow_farneback_cuda", &cv::superres::createOptFlow_Farneback_CUDA);

  Rice::Data_Type<cv::superres::DualTVL1OpticalFlow> rb_cCvSuperresDualTVL1OpticalFlow = define_class_under<cv::superres::DualTVL1OpticalFlow, cv::superres::DenseOpticalFlowExt>(rb_mCvSuperres, "DualTVL1OpticalFlow").
    define_method("get_tau", &cv::superres::DualTVL1OpticalFlow::getTau).
    define_method("set_tau", &cv::superres::DualTVL1OpticalFlow::setTau,
      Arg("val")).
    define_method("get_lambda", &cv::superres::DualTVL1OpticalFlow::getLambda).
    define_method("set_lambda", &cv::superres::DualTVL1OpticalFlow::setLambda,
      Arg("val")).
    define_method("get_theta", &cv::superres::DualTVL1OpticalFlow::getTheta).
    define_method("set_theta", &cv::superres::DualTVL1OpticalFlow::setTheta,
      Arg("val")).
    define_method("get_scales_number", &cv::superres::DualTVL1OpticalFlow::getScalesNumber).
    define_method("set_scales_number", &cv::superres::DualTVL1OpticalFlow::setScalesNumber,
      Arg("val")).
    define_method("get_warpings_number", &cv::superres::DualTVL1OpticalFlow::getWarpingsNumber).
    define_method("set_warpings_number", &cv::superres::DualTVL1OpticalFlow::setWarpingsNumber,
      Arg("val")).
    define_method("get_epsilon", &cv::superres::DualTVL1OpticalFlow::getEpsilon).
    define_method("set_epsilon", &cv::superres::DualTVL1OpticalFlow::setEpsilon,
      Arg("val")).
    define_method("get_iterations", &cv::superres::DualTVL1OpticalFlow::getIterations).
    define_method("set_iterations", &cv::superres::DualTVL1OpticalFlow::setIterations,
      Arg("val")).
    define_method("get_use_initial_flow?", &cv::superres::DualTVL1OpticalFlow::getUseInitialFlow).
    define_method("set_use_initial_flow", &cv::superres::DualTVL1OpticalFlow::setUseInitialFlow,
      Arg("val"));

  rb_mCvSuperres.define_module_function("create_opt_flow_dual_tvl1", &cv::superres::createOptFlow_DualTVL1);

  rb_mCvSuperres.define_module_function("create_opt_flow_dual_tvl1_cuda", &cv::superres::createOptFlow_DualTVL1_CUDA);

  Rice::Data_Type<cv::superres::BroxOpticalFlow> rb_cCvSuperresBroxOpticalFlow = define_class_under<cv::superres::BroxOpticalFlow, cv::superres::DenseOpticalFlowExt>(rb_mCvSuperres, "BroxOpticalFlow").
    define_method("get_alpha", &cv::superres::BroxOpticalFlow::getAlpha).
    define_method("set_alpha", &cv::superres::BroxOpticalFlow::setAlpha,
      Arg("val")).
    define_method("get_gamma", &cv::superres::BroxOpticalFlow::getGamma).
    define_method("set_gamma", &cv::superres::BroxOpticalFlow::setGamma,
      Arg("val")).
    define_method("get_scale_factor", &cv::superres::BroxOpticalFlow::getScaleFactor).
    define_method("set_scale_factor", &cv::superres::BroxOpticalFlow::setScaleFactor,
      Arg("val")).
    define_method("get_inner_iterations", &cv::superres::BroxOpticalFlow::getInnerIterations).
    define_method("set_inner_iterations", &cv::superres::BroxOpticalFlow::setInnerIterations,
      Arg("val")).
    define_method("get_outer_iterations", &cv::superres::BroxOpticalFlow::getOuterIterations).
    define_method("set_outer_iterations", &cv::superres::BroxOpticalFlow::setOuterIterations,
      Arg("val")).
    define_method("get_solver_iterations", &cv::superres::BroxOpticalFlow::getSolverIterations).
    define_method("set_solver_iterations", &cv::superres::BroxOpticalFlow::setSolverIterations,
      Arg("val"));

  rb_mCvSuperres.define_module_function("create_opt_flow_brox_cuda", &cv::superres::createOptFlow_Brox_CUDA);

  Rice::Data_Type<cv::superres::PyrLKOpticalFlow> rb_cCvSuperresPyrLKOpticalFlow = define_class_under<cv::superres::PyrLKOpticalFlow, cv::superres::DenseOpticalFlowExt>(rb_mCvSuperres, "PyrLKOpticalFlow").
    define_method("get_window_size", &cv::superres::PyrLKOpticalFlow::getWindowSize).
    define_method("set_window_size", &cv::superres::PyrLKOpticalFlow::setWindowSize,
      Arg("val")).
    define_method("get_max_level", &cv::superres::PyrLKOpticalFlow::getMaxLevel).
    define_method("set_max_level", &cv::superres::PyrLKOpticalFlow::setMaxLevel,
      Arg("val")).
    define_method("get_iterations", &cv::superres::PyrLKOpticalFlow::getIterations).
    define_method("set_iterations", &cv::superres::PyrLKOpticalFlow::setIterations,
      Arg("val"));

  rb_mCvSuperres.define_module_function("create_opt_flow_pyr_lk_cuda", &cv::superres::createOptFlow_PyrLK_CUDA);
}