#include <opencv2/cudaoptflow.hpp>
#include "cudaoptflow-rb.hpp"

using namespace Rice;

void Init_Cudaoptflow()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::DenseOpticalFlow> rb_cCvCudaDenseOpticalFlow = define_class_under<cv::cuda::DenseOpticalFlow, cv::Algorithm>(rb_mCvCuda, "DenseOpticalFlow").
    define_method<void(cv::cuda::DenseOpticalFlow::*)(cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::cuda::Stream&)>("calc", &cv::cuda::DenseOpticalFlow::calc,
      Arg("i0"), Arg("i1"), Arg("flow"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Rice::Data_Type<cv::cuda::SparseOpticalFlow> rb_cCvCudaSparseOpticalFlow = define_class_under<cv::cuda::SparseOpticalFlow, cv::Algorithm>(rb_mCvCuda, "SparseOpticalFlow").
    define_method<void(cv::cuda::SparseOpticalFlow::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray, cv::cuda::Stream&)>("calc", &cv::cuda::SparseOpticalFlow::calc,
      Arg("prev_img"), Arg("next_img"), Arg("prev_pts"), Arg("next_pts"), Arg("status"), Arg("err") = static_cast<cv::OutputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Rice::Data_Type<cv::cuda::NvidiaHWOpticalFlow> rb_cCvCudaNvidiaHWOpticalFlow = define_class_under<cv::cuda::NvidiaHWOpticalFlow, cv::Algorithm>(rb_mCvCuda, "NvidiaHWOpticalFlow").
    define_method<void(cv::cuda::NvidiaHWOpticalFlow::*)(cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::cuda::Stream&, cv::InputArray, cv::OutputArray)>("calc", &cv::cuda::NvidiaHWOpticalFlow::calc,
      Arg("input_image"), Arg("reference_image"), Arg("flow"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()), Arg("hint") = static_cast<cv::InputArray>(cv::noArray()), Arg("cost") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method<void(cv::cuda::NvidiaHWOpticalFlow::*)()>("collect_garbage", &cv::cuda::NvidiaHWOpticalFlow::collectGarbage).
    define_method<int(cv::cuda::NvidiaHWOpticalFlow::*)() const>("get_grid_size", &cv::cuda::NvidiaHWOpticalFlow::getGridSize);

  Rice::Data_Type<cv::cuda::BroxOpticalFlow> rb_cCvCudaBroxOpticalFlow = define_class_under<cv::cuda::BroxOpticalFlow, cv::cuda::DenseOpticalFlow>(rb_mCvCuda, "BroxOpticalFlow").
    define_method<double(cv::cuda::BroxOpticalFlow::*)() const>("get_flow_smoothness", &cv::cuda::BroxOpticalFlow::getFlowSmoothness).
    define_method<void(cv::cuda::BroxOpticalFlow::*)(double)>("set_flow_smoothness", &cv::cuda::BroxOpticalFlow::setFlowSmoothness,
      Arg("alpha")).
    define_method<double(cv::cuda::BroxOpticalFlow::*)() const>("get_gradient_constancy_importance", &cv::cuda::BroxOpticalFlow::getGradientConstancyImportance).
    define_method<void(cv::cuda::BroxOpticalFlow::*)(double)>("set_gradient_constancy_importance", &cv::cuda::BroxOpticalFlow::setGradientConstancyImportance,
      Arg("gamma")).
    define_method<double(cv::cuda::BroxOpticalFlow::*)() const>("get_pyramid_scale_factor", &cv::cuda::BroxOpticalFlow::getPyramidScaleFactor).
    define_method<void(cv::cuda::BroxOpticalFlow::*)(double)>("set_pyramid_scale_factor", &cv::cuda::BroxOpticalFlow::setPyramidScaleFactor,
      Arg("scale_factor")).
    define_method<int(cv::cuda::BroxOpticalFlow::*)() const>("get_inner_iterations", &cv::cuda::BroxOpticalFlow::getInnerIterations).
    define_method<void(cv::cuda::BroxOpticalFlow::*)(int)>("set_inner_iterations", &cv::cuda::BroxOpticalFlow::setInnerIterations,
      Arg("inner_iterations")).
    define_method<int(cv::cuda::BroxOpticalFlow::*)() const>("get_outer_iterations", &cv::cuda::BroxOpticalFlow::getOuterIterations).
    define_method<void(cv::cuda::BroxOpticalFlow::*)(int)>("set_outer_iterations", &cv::cuda::BroxOpticalFlow::setOuterIterations,
      Arg("outer_iterations")).
    define_method<int(cv::cuda::BroxOpticalFlow::*)() const>("get_solver_iterations", &cv::cuda::BroxOpticalFlow::getSolverIterations).
    define_method<void(cv::cuda::BroxOpticalFlow::*)(int)>("set_solver_iterations", &cv::cuda::BroxOpticalFlow::setSolverIterations,
      Arg("solver_iterations")).
    define_singleton_function<cv::Ptr<cv::cuda::BroxOpticalFlow>(*)(double, double, double, int, int, int)>("create", &cv::cuda::BroxOpticalFlow::create,
      Arg("alpha") = static_cast<double>(0.197), Arg("gamma") = static_cast<double>(50.0), Arg("scale_factor") = static_cast<double>(0.8), Arg("inner_iterations") = static_cast<int>(5), Arg("outer_iterations") = static_cast<int>(150), Arg("solver_iterations") = static_cast<int>(10));

  Rice::Data_Type<cv::cuda::SparsePyrLKOpticalFlow> rb_cCvCudaSparsePyrLKOpticalFlow = define_class_under<cv::cuda::SparsePyrLKOpticalFlow, cv::cuda::SparseOpticalFlow>(rb_mCvCuda, "SparsePyrLKOpticalFlow").
    define_method<cv::Size(cv::cuda::SparsePyrLKOpticalFlow::*)() const>("get_win_size", &cv::cuda::SparsePyrLKOpticalFlow::getWinSize).
    define_method<void(cv::cuda::SparsePyrLKOpticalFlow::*)(cv::Size)>("set_win_size", &cv::cuda::SparsePyrLKOpticalFlow::setWinSize,
      Arg("win_size")).
    define_method<int(cv::cuda::SparsePyrLKOpticalFlow::*)() const>("get_max_level", &cv::cuda::SparsePyrLKOpticalFlow::getMaxLevel).
    define_method<void(cv::cuda::SparsePyrLKOpticalFlow::*)(int)>("set_max_level", &cv::cuda::SparsePyrLKOpticalFlow::setMaxLevel,
      Arg("max_level")).
    define_method<int(cv::cuda::SparsePyrLKOpticalFlow::*)() const>("get_num_iters", &cv::cuda::SparsePyrLKOpticalFlow::getNumIters).
    define_method<void(cv::cuda::SparsePyrLKOpticalFlow::*)(int)>("set_num_iters", &cv::cuda::SparsePyrLKOpticalFlow::setNumIters,
      Arg("iters")).
    define_method<bool(cv::cuda::SparsePyrLKOpticalFlow::*)() const>("get_use_initial_flow?", &cv::cuda::SparsePyrLKOpticalFlow::getUseInitialFlow).
    define_method<void(cv::cuda::SparsePyrLKOpticalFlow::*)(bool)>("set_use_initial_flow", &cv::cuda::SparsePyrLKOpticalFlow::setUseInitialFlow,
      Arg("use_initial_flow")).
    define_singleton_function<cv::Ptr<cv::cuda::SparsePyrLKOpticalFlow>(*)(cv::Size, int, int, bool)>("create", &cv::cuda::SparsePyrLKOpticalFlow::create,
      Arg("win_size") = static_cast<cv::Size>(cv::Size(21, 21)), Arg("max_level") = static_cast<int>(3), Arg("iters") = static_cast<int>(30), Arg("use_initial_flow") = static_cast<bool>(false));

  Rice::Data_Type<cv::cuda::DensePyrLKOpticalFlow> rb_cCvCudaDensePyrLKOpticalFlow = define_class_under<cv::cuda::DensePyrLKOpticalFlow, cv::cuda::DenseOpticalFlow>(rb_mCvCuda, "DensePyrLKOpticalFlow").
    define_method<cv::Size(cv::cuda::DensePyrLKOpticalFlow::*)() const>("get_win_size", &cv::cuda::DensePyrLKOpticalFlow::getWinSize).
    define_method<void(cv::cuda::DensePyrLKOpticalFlow::*)(cv::Size)>("set_win_size", &cv::cuda::DensePyrLKOpticalFlow::setWinSize,
      Arg("win_size")).
    define_method<int(cv::cuda::DensePyrLKOpticalFlow::*)() const>("get_max_level", &cv::cuda::DensePyrLKOpticalFlow::getMaxLevel).
    define_method<void(cv::cuda::DensePyrLKOpticalFlow::*)(int)>("set_max_level", &cv::cuda::DensePyrLKOpticalFlow::setMaxLevel,
      Arg("max_level")).
    define_method<int(cv::cuda::DensePyrLKOpticalFlow::*)() const>("get_num_iters", &cv::cuda::DensePyrLKOpticalFlow::getNumIters).
    define_method<void(cv::cuda::DensePyrLKOpticalFlow::*)(int)>("set_num_iters", &cv::cuda::DensePyrLKOpticalFlow::setNumIters,
      Arg("iters")).
    define_method<bool(cv::cuda::DensePyrLKOpticalFlow::*)() const>("get_use_initial_flow?", &cv::cuda::DensePyrLKOpticalFlow::getUseInitialFlow).
    define_method<void(cv::cuda::DensePyrLKOpticalFlow::*)(bool)>("set_use_initial_flow", &cv::cuda::DensePyrLKOpticalFlow::setUseInitialFlow,
      Arg("use_initial_flow")).
    define_singleton_function<cv::Ptr<cv::cuda::DensePyrLKOpticalFlow>(*)(cv::Size, int, int, bool)>("create", &cv::cuda::DensePyrLKOpticalFlow::create,
      Arg("win_size") = static_cast<cv::Size>(cv::Size(13, 13)), Arg("max_level") = static_cast<int>(3), Arg("iters") = static_cast<int>(30), Arg("use_initial_flow") = static_cast<bool>(false));

  Rice::Data_Type<cv::cuda::FarnebackOpticalFlow> rb_cCvCudaFarnebackOpticalFlow = define_class_under<cv::cuda::FarnebackOpticalFlow, cv::cuda::DenseOpticalFlow>(rb_mCvCuda, "FarnebackOpticalFlow").
    define_method<int(cv::cuda::FarnebackOpticalFlow::*)() const>("get_num_levels", &cv::cuda::FarnebackOpticalFlow::getNumLevels).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(int)>("set_num_levels", &cv::cuda::FarnebackOpticalFlow::setNumLevels,
      Arg("num_levels")).
    define_method<double(cv::cuda::FarnebackOpticalFlow::*)() const>("get_pyr_scale", &cv::cuda::FarnebackOpticalFlow::getPyrScale).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(double)>("set_pyr_scale", &cv::cuda::FarnebackOpticalFlow::setPyrScale,
      Arg("pyr_scale")).
    define_method<bool(cv::cuda::FarnebackOpticalFlow::*)() const>("get_fast_pyramids?", &cv::cuda::FarnebackOpticalFlow::getFastPyramids).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(bool)>("set_fast_pyramids", &cv::cuda::FarnebackOpticalFlow::setFastPyramids,
      Arg("fast_pyramids")).
    define_method<int(cv::cuda::FarnebackOpticalFlow::*)() const>("get_win_size", &cv::cuda::FarnebackOpticalFlow::getWinSize).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(int)>("set_win_size", &cv::cuda::FarnebackOpticalFlow::setWinSize,
      Arg("win_size")).
    define_method<int(cv::cuda::FarnebackOpticalFlow::*)() const>("get_num_iters", &cv::cuda::FarnebackOpticalFlow::getNumIters).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(int)>("set_num_iters", &cv::cuda::FarnebackOpticalFlow::setNumIters,
      Arg("num_iters")).
    define_method<int(cv::cuda::FarnebackOpticalFlow::*)() const>("get_poly_n", &cv::cuda::FarnebackOpticalFlow::getPolyN).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(int)>("set_poly_n", &cv::cuda::FarnebackOpticalFlow::setPolyN,
      Arg("poly_n")).
    define_method<double(cv::cuda::FarnebackOpticalFlow::*)() const>("get_poly_sigma", &cv::cuda::FarnebackOpticalFlow::getPolySigma).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(double)>("set_poly_sigma", &cv::cuda::FarnebackOpticalFlow::setPolySigma,
      Arg("poly_sigma")).
    define_method<int(cv::cuda::FarnebackOpticalFlow::*)() const>("get_flags", &cv::cuda::FarnebackOpticalFlow::getFlags).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(int)>("set_flags", &cv::cuda::FarnebackOpticalFlow::setFlags,
      Arg("flags")).
    define_singleton_function<cv::Ptr<cv::cuda::FarnebackOpticalFlow>(*)(int, double, bool, int, int, int, double, int)>("create", &cv::cuda::FarnebackOpticalFlow::create,
      Arg("num_levels") = static_cast<int>(5), Arg("pyr_scale") = static_cast<double>(0.5), Arg("fast_pyramids") = static_cast<bool>(false), Arg("win_size") = static_cast<int>(13), Arg("num_iters") = static_cast<int>(10), Arg("poly_n") = static_cast<int>(5), Arg("poly_sigma") = static_cast<double>(1.1), Arg("flags") = static_cast<int>(0));

  Rice::Data_Type<cv::cuda::OpticalFlowDual_TVL1> rb_cCvCudaOpticalFlowDualTVL1 = define_class_under<cv::cuda::OpticalFlowDual_TVL1, cv::cuda::DenseOpticalFlow>(rb_mCvCuda, "OpticalFlowDualTVL1").
    define_method<double(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_tau", &cv::cuda::OpticalFlowDual_TVL1::getTau).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(double)>("set_tau", &cv::cuda::OpticalFlowDual_TVL1::setTau,
      Arg("tau")).
    define_method<double(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_lambda", &cv::cuda::OpticalFlowDual_TVL1::getLambda).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(double)>("set_lambda", &cv::cuda::OpticalFlowDual_TVL1::setLambda,
      Arg("lambda")).
    define_method<double(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_gamma", &cv::cuda::OpticalFlowDual_TVL1::getGamma).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(double)>("set_gamma", &cv::cuda::OpticalFlowDual_TVL1::setGamma,
      Arg("gamma")).
    define_method<double(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_theta", &cv::cuda::OpticalFlowDual_TVL1::getTheta).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(double)>("set_theta", &cv::cuda::OpticalFlowDual_TVL1::setTheta,
      Arg("theta")).
    define_method<int(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_num_scales", &cv::cuda::OpticalFlowDual_TVL1::getNumScales).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(int)>("set_num_scales", &cv::cuda::OpticalFlowDual_TVL1::setNumScales,
      Arg("nscales")).
    define_method<int(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_num_warps", &cv::cuda::OpticalFlowDual_TVL1::getNumWarps).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(int)>("set_num_warps", &cv::cuda::OpticalFlowDual_TVL1::setNumWarps,
      Arg("warps")).
    define_method<double(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_epsilon", &cv::cuda::OpticalFlowDual_TVL1::getEpsilon).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(double)>("set_epsilon", &cv::cuda::OpticalFlowDual_TVL1::setEpsilon,
      Arg("epsilon")).
    define_method<int(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_num_iterations", &cv::cuda::OpticalFlowDual_TVL1::getNumIterations).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(int)>("set_num_iterations", &cv::cuda::OpticalFlowDual_TVL1::setNumIterations,
      Arg("iterations")).
    define_method<double(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_scale_step", &cv::cuda::OpticalFlowDual_TVL1::getScaleStep).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(double)>("set_scale_step", &cv::cuda::OpticalFlowDual_TVL1::setScaleStep,
      Arg("scale_step")).
    define_method<bool(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_use_initial_flow?", &cv::cuda::OpticalFlowDual_TVL1::getUseInitialFlow).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(bool)>("set_use_initial_flow", &cv::cuda::OpticalFlowDual_TVL1::setUseInitialFlow,
      Arg("use_initial_flow")).
    define_singleton_function<cv::Ptr<cv::cuda::OpticalFlowDual_TVL1>(*)(double, double, double, int, int, double, int, double, double, bool)>("create", &cv::cuda::OpticalFlowDual_TVL1::create,
      Arg("tau") = static_cast<double>(0.25), Arg("lambda") = static_cast<double>(0.15), Arg("theta") = static_cast<double>(0.3), Arg("nscales") = static_cast<int>(5), Arg("warps") = static_cast<int>(5), Arg("epsilon") = static_cast<double>(0.01), Arg("iterations") = static_cast<int>(300), Arg("scale_step") = static_cast<double>(0.8), Arg("gamma") = static_cast<double>(0.0), Arg("use_initial_flow") = static_cast<bool>(false));

  Rice::Data_Type<cv::cuda::NvidiaOpticalFlow_1_0> rb_cCvCudaNvidiaOpticalFlow10 = define_class_under<cv::cuda::NvidiaOpticalFlow_1_0, cv::cuda::NvidiaHWOpticalFlow>(rb_mCvCuda, "NvidiaOpticalFlow10").
    define_method<void(cv::cuda::NvidiaOpticalFlow_1_0::*)(cv::InputArray, cv::Size, int, cv::InputOutputArray)>("up_sampler", &cv::cuda::NvidiaOpticalFlow_1_0::upSampler,
      Arg("flow"), Arg("image_size"), Arg("grid_size"), Arg("upsampled_flow")).
    define_singleton_function<cv::Ptr<cv::cuda::NvidiaOpticalFlow_1_0>(*)(cv::Size, cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL, bool, bool, bool, int, cv::cuda::Stream&, cv::cuda::Stream&)>("create", &cv::cuda::NvidiaOpticalFlow_1_0::create,
      Arg("image_size"), Arg("perf_preset") = static_cast<cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL>(cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_SLOW), Arg("enable_temporal_hints") = static_cast<bool>(false), Arg("enable_external_hints") = static_cast<bool>(false), Arg("enable_cost_buffer") = static_cast<bool>(false), Arg("gpu_id") = static_cast<int>(0), Arg("input_stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()), Arg("output_stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Enum<cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL> rb_cCvCudaNvidiaOpticalFlow10NVIDIAOFPERFLEVEL = define_enum_under<cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL>("NVIDIA_OF_PERF_LEVEL", rb_cCvCudaNvidiaOpticalFlow10).
    define_value("NV_OF_PERF_LEVEL_UNDEFINED", cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_UNDEFINED).
    define_value("NV_OF_PERF_LEVEL_SLOW", cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_SLOW).
    define_value("NV_OF_PERF_LEVEL_MEDIUM", cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_MEDIUM).
    define_value("NV_OF_PERF_LEVEL_FAST", cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_FAST).
    define_value("NV_OF_PERF_LEVEL_MAX", cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_MAX);

  Rice::Data_Type<cv::cuda::NvidiaOpticalFlow_2_0> rb_cCvCudaNvidiaOpticalFlow20 = define_class_under<cv::cuda::NvidiaOpticalFlow_2_0, cv::cuda::NvidiaHWOpticalFlow>(rb_mCvCuda, "NvidiaOpticalFlow20").
    define_method<void(cv::cuda::NvidiaOpticalFlow_2_0::*)(cv::InputArray, cv::InputOutputArray)>("convert_to_float", &cv::cuda::NvidiaOpticalFlow_2_0::convertToFloat,
      Arg("flow"), Arg("float_flow")).
    define_singleton_function<cv::Ptr<cv::cuda::NvidiaOpticalFlow_2_0>(*)(cv::Size, cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL, cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE, cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE, bool, bool, bool, int, cv::cuda::Stream&, cv::cuda::Stream&)>("create", &cv::cuda::NvidiaOpticalFlow_2_0::create,
      Arg("image_size"), Arg("perf_preset") = static_cast<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL>(cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_SLOW), Arg("output_grid_size") = static_cast<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE>(cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE::NV_OF_OUTPUT_VECTOR_GRID_SIZE_1), Arg("hint_grid_size") = static_cast<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE>(cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_1), Arg("enable_temporal_hints") = static_cast<bool>(false), Arg("enable_external_hints") = static_cast<bool>(false), Arg("enable_cost_buffer") = static_cast<bool>(false), Arg("gpu_id") = static_cast<int>(0), Arg("input_stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()), Arg("output_stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_singleton_function<cv::Ptr<cv::cuda::NvidiaOpticalFlow_2_0>(*)(cv::Size, std::vector<cv::Rect>, cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL, cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE, cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE, bool, bool, bool, int, cv::cuda::Stream&, cv::cuda::Stream&)>("create", &cv::cuda::NvidiaOpticalFlow_2_0::create,
      Arg("image_size"), Arg("roi_data"), Arg("perf_preset") = static_cast<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL>(cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_SLOW), Arg("output_grid_size") = static_cast<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE>(cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE::NV_OF_OUTPUT_VECTOR_GRID_SIZE_1), Arg("hint_grid_size") = static_cast<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE>(cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_1), Arg("enable_temporal_hints") = static_cast<bool>(false), Arg("enable_external_hints") = static_cast<bool>(false), Arg("enable_cost_buffer") = static_cast<bool>(false), Arg("gpu_id") = static_cast<int>(0), Arg("input_stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()), Arg("output_stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Enum<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL> rb_cCvCudaNvidiaOpticalFlow20NVIDIAOFPERFLEVEL = define_enum_under<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL>("NVIDIA_OF_PERF_LEVEL", rb_cCvCudaNvidiaOpticalFlow20).
    define_value("NV_OF_PERF_LEVEL_UNDEFINED", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_UNDEFINED).
    define_value("NV_OF_PERF_LEVEL_SLOW", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_SLOW).
    define_value("NV_OF_PERF_LEVEL_MEDIUM", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_MEDIUM).
    define_value("NV_OF_PERF_LEVEL_FAST", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_FAST).
    define_value("NV_OF_PERF_LEVEL_MAX", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_MAX);

  Enum<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE> rb_cCvCudaNvidiaOpticalFlow20NVIDIAOFOUTPUTVECTORGRIDSIZE = define_enum_under<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE>("NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE", rb_cCvCudaNvidiaOpticalFlow20).
    define_value("NV_OF_OUTPUT_VECTOR_GRID_SIZE_UNDEFINED", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE::NV_OF_OUTPUT_VECTOR_GRID_SIZE_UNDEFINED).
    define_value("NV_OF_OUTPUT_VECTOR_GRID_SIZE_1", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE::NV_OF_OUTPUT_VECTOR_GRID_SIZE_1).
    define_value("NV_OF_OUTPUT_VECTOR_GRID_SIZE_2", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE::NV_OF_OUTPUT_VECTOR_GRID_SIZE_2).
    define_value("NV_OF_OUTPUT_VECTOR_GRID_SIZE_4", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE::NV_OF_OUTPUT_VECTOR_GRID_SIZE_4).
    define_value("NV_OF_OUTPUT_VECTOR_GRID_SIZE_MAX", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE::NV_OF_OUTPUT_VECTOR_GRID_SIZE_MAX);

  Enum<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE> rb_cCvCudaNvidiaOpticalFlow20NVIDIAOFHINTVECTORGRIDSIZE = define_enum_under<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE>("NVIDIA_OF_HINT_VECTOR_GRID_SIZE", rb_cCvCudaNvidiaOpticalFlow20).
    define_value("NV_OF_HINT_VECTOR_GRID_SIZE_UNDEFINED", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_UNDEFINED).
    define_value("NV_OF_HINT_VECTOR_GRID_SIZE_1", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_1).
    define_value("NV_OF_HINT_VECTOR_GRID_SIZE_2", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_2).
    define_value("NV_OF_HINT_VECTOR_GRID_SIZE_4", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_4).
    define_value("NV_OF_HINT_VECTOR_GRID_SIZE_8", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_8).
    define_value("NV_OF_HINT_VECTOR_GRID_SIZE_MAX", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_MAX);
}
