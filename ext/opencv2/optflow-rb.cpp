#include <opencv2/optflow.hpp>
#include "optflow-rb.hpp"

using namespace Rice;

void Init_Optflow()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvOptflow = define_module_under(rb_mCv, "Optflow");

  rb_mCvOptflow.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, int, int)>("calc_optical_flow_sf", &cv::optflow::calcOpticalFlowSF,
    Arg("from"), Arg("to"), Arg("flow"), Arg("layers"), Arg("averaging_block_size"), Arg("max_flow"));

  rb_mCvOptflow.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, int, int, double, double, int, double, double, double, int, double, double, double)>("calc_optical_flow_sf", &cv::optflow::calcOpticalFlowSF,
    Arg("from"), Arg("to"), Arg("flow"), Arg("layers"), Arg("averaging_block_size"), Arg("max_flow"), Arg("sigma_dist"), Arg("sigma_color"), Arg("postprocess_window"), Arg("sigma_dist_fix"), Arg("sigma_color_fix"), Arg("occ_thr"), Arg("upscale_averaging_radius"), Arg("upscale_sigma_dist"), Arg("upscale_sigma_color"), Arg("speed_up_thr"));

  rb_mCvOptflow.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, int, float, bool, float, float)>("calc_optical_flow_sparse_to_dense", &cv::optflow::calcOpticalFlowSparseToDense,
    Arg("from"), Arg("to"), Arg("flow"), Arg("grid_step") = static_cast<int>(8), Arg("k") = static_cast<int>(128), Arg("sigma") = static_cast<float>(0.05f), Arg("use_post_proc") = static_cast<bool>(true), Arg("fgs_lambda") = static_cast<float>(500.0f), Arg("fgs_sigma") = static_cast<float>(1.5f));

  rb_mCvOptflow.define_module_function<cv::Ptr<cv::DenseOpticalFlow>(*)()>("create_opt_flow_deep_flow", &cv::optflow::createOptFlow_DeepFlow);

  rb_mCvOptflow.define_module_function<cv::Ptr<cv::DenseOpticalFlow>(*)()>("create_opt_flow_simple_flow", &cv::optflow::createOptFlow_SimpleFlow);

  rb_mCvOptflow.define_module_function<cv::Ptr<cv::DenseOpticalFlow>(*)()>("create_opt_flow_farneback", &cv::optflow::createOptFlow_Farneback);

  rb_mCvOptflow.define_module_function<cv::Ptr<cv::DenseOpticalFlow>(*)()>("create_opt_flow_sparse_to_dense", &cv::optflow::createOptFlow_SparseToDense);

  Rice::Data_Type<cv::optflow::DualTVL1OpticalFlow> rb_cCvOptflowDualTVL1OpticalFlow = define_class_under<cv::optflow::DualTVL1OpticalFlow, cv::DenseOpticalFlow>(rb_mCvOptflow, "DualTVL1OpticalFlow").
    define_method<double(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_tau", &cv::optflow::DualTVL1OpticalFlow::getTau).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(double)>("set_tau", &cv::optflow::DualTVL1OpticalFlow::setTau,
      Arg("val")).
    define_method<double(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_lambda", &cv::optflow::DualTVL1OpticalFlow::getLambda).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(double)>("set_lambda", &cv::optflow::DualTVL1OpticalFlow::setLambda,
      Arg("val")).
    define_method<double(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_theta", &cv::optflow::DualTVL1OpticalFlow::getTheta).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(double)>("set_theta", &cv::optflow::DualTVL1OpticalFlow::setTheta,
      Arg("val")).
    define_method<double(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_gamma", &cv::optflow::DualTVL1OpticalFlow::getGamma).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(double)>("set_gamma", &cv::optflow::DualTVL1OpticalFlow::setGamma,
      Arg("val")).
    define_method<int(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_scales_number", &cv::optflow::DualTVL1OpticalFlow::getScalesNumber).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(int)>("set_scales_number", &cv::optflow::DualTVL1OpticalFlow::setScalesNumber,
      Arg("val")).
    define_method<int(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_warpings_number", &cv::optflow::DualTVL1OpticalFlow::getWarpingsNumber).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(int)>("set_warpings_number", &cv::optflow::DualTVL1OpticalFlow::setWarpingsNumber,
      Arg("val")).
    define_method<double(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_epsilon", &cv::optflow::DualTVL1OpticalFlow::getEpsilon).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(double)>("set_epsilon", &cv::optflow::DualTVL1OpticalFlow::setEpsilon,
      Arg("val")).
    define_method<int(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_inner_iterations", &cv::optflow::DualTVL1OpticalFlow::getInnerIterations).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(int)>("set_inner_iterations", &cv::optflow::DualTVL1OpticalFlow::setInnerIterations,
      Arg("val")).
    define_method<int(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_outer_iterations", &cv::optflow::DualTVL1OpticalFlow::getOuterIterations).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(int)>("set_outer_iterations", &cv::optflow::DualTVL1OpticalFlow::setOuterIterations,
      Arg("val")).
    define_method<bool(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_use_initial_flow?", &cv::optflow::DualTVL1OpticalFlow::getUseInitialFlow).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(bool)>("set_use_initial_flow", &cv::optflow::DualTVL1OpticalFlow::setUseInitialFlow,
      Arg("val")).
    define_method<double(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_scale_step", &cv::optflow::DualTVL1OpticalFlow::getScaleStep).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(double)>("set_scale_step", &cv::optflow::DualTVL1OpticalFlow::setScaleStep,
      Arg("val")).
    define_method<int(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_median_filtering", &cv::optflow::DualTVL1OpticalFlow::getMedianFiltering).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(int)>("set_median_filtering", &cv::optflow::DualTVL1OpticalFlow::setMedianFiltering,
      Arg("val")).
    define_singleton_function<cv::Ptr<cv::optflow::DualTVL1OpticalFlow>(*)(double, double, double, int, int, double, int, int, double, double, int, bool)>("create", &cv::optflow::DualTVL1OpticalFlow::create,
      Arg("tau") = static_cast<double>(0.25), Arg("lambda") = static_cast<double>(0.15), Arg("theta") = static_cast<double>(0.3), Arg("nscales") = static_cast<int>(5), Arg("warps") = static_cast<int>(5), Arg("epsilon") = static_cast<double>(0.01), Arg("innner_iterations") = static_cast<int>(30), Arg("outer_iterations") = static_cast<int>(10), Arg("scale_step") = static_cast<double>(0.8), Arg("gamma") = static_cast<double>(0.0), Arg("median_filtering") = static_cast<int>(5), Arg("use_initial_flow") = static_cast<bool>(false));

  rb_mCvOptflow.define_module_function<cv::Ptr<cv::optflow::DualTVL1OpticalFlow>(*)()>("create_opt_flow_dual_tvl1", &cv::optflow::createOptFlow_DualTVL1);
}