#include <opencv2/cudalegacy.hpp>
#include "cudalegacy-rb.hpp"

using namespace Rice;

void Init_Cudalegacy()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::ImagePyramid> rb_cCvCudaImagePyramid = define_class_under<cv::cuda::ImagePyramid, cv::Algorithm>(rb_mCvCuda, "ImagePyramid").
    define_method<void(cv::cuda::ImagePyramid::*)(cv::OutputArray, cv::Size, cv::cuda::Stream&) const>("get_layer", &cv::cuda::ImagePyramid::getLayer,
      Arg("out_img"), Arg("out_roi"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::ImagePyramid>(*)(cv::InputArray, int, cv::cuda::Stream&)>("create_image_pyramid", &cv::cuda::createImagePyramid,
    Arg("img"), Arg("n_layers") = static_cast<int>(-1), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Rice::Data_Type<cv::cuda::BackgroundSubtractorGMG> rb_cCvCudaBackgroundSubtractorGMG = define_class_under<cv::cuda::BackgroundSubtractorGMG, cv::BackgroundSubtractor>(rb_mCvCuda, "BackgroundSubtractorGMG").
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(cv::InputArray, cv::OutputArray, double, cv::cuda::Stream&)>("apply", &cv::cuda::BackgroundSubtractorGMG::apply,
      Arg("image"), Arg("fgmask"), Arg("learning_rate"), Arg("stream")).
    define_method<int(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_max_features", &cv::cuda::BackgroundSubtractorGMG::getMaxFeatures).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(int)>("set_max_features", &cv::cuda::BackgroundSubtractorGMG::setMaxFeatures,
      Arg("max_features")).
    define_method<double(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_default_learning_rate", &cv::cuda::BackgroundSubtractorGMG::getDefaultLearningRate).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(double)>("set_default_learning_rate", &cv::cuda::BackgroundSubtractorGMG::setDefaultLearningRate,
      Arg("lr")).
    define_method<int(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_num_frames", &cv::cuda::BackgroundSubtractorGMG::getNumFrames).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(int)>("set_num_frames", &cv::cuda::BackgroundSubtractorGMG::setNumFrames,
      Arg("nframes")).
    define_method<int(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_quantization_levels", &cv::cuda::BackgroundSubtractorGMG::getQuantizationLevels).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(int)>("set_quantization_levels", &cv::cuda::BackgroundSubtractorGMG::setQuantizationLevels,
      Arg("nlevels")).
    define_method<double(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_background_prior", &cv::cuda::BackgroundSubtractorGMG::getBackgroundPrior).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(double)>("set_background_prior", &cv::cuda::BackgroundSubtractorGMG::setBackgroundPrior,
      Arg("bgprior")).
    define_method<int(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_smoothing_radius", &cv::cuda::BackgroundSubtractorGMG::getSmoothingRadius).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(int)>("set_smoothing_radius", &cv::cuda::BackgroundSubtractorGMG::setSmoothingRadius,
      Arg("radius")).
    define_method<double(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_decision_threshold", &cv::cuda::BackgroundSubtractorGMG::getDecisionThreshold).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(double)>("set_decision_threshold", &cv::cuda::BackgroundSubtractorGMG::setDecisionThreshold,
      Arg("thresh")).
    define_method<bool(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_update_background_model?", &cv::cuda::BackgroundSubtractorGMG::getUpdateBackgroundModel).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(bool)>("set_update_background_model", &cv::cuda::BackgroundSubtractorGMG::setUpdateBackgroundModel,
      Arg("update")).
    define_method<double(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_min_val", &cv::cuda::BackgroundSubtractorGMG::getMinVal).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(double)>("set_min_val", &cv::cuda::BackgroundSubtractorGMG::setMinVal,
      Arg("val")).
    define_method<double(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_max_val", &cv::cuda::BackgroundSubtractorGMG::getMaxVal).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(double)>("set_max_val", &cv::cuda::BackgroundSubtractorGMG::setMaxVal,
      Arg("val"));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::BackgroundSubtractorGMG>(*)(int, double)>("create_background_subtractor_gmg", &cv::cuda::createBackgroundSubtractorGMG,
    Arg("initialization_frames") = static_cast<int>(120), Arg("decision_threshold") = static_cast<double>(0.8));

  Rice::Data_Type<cv::cuda::BackgroundSubtractorFGD> rb_cCvCudaBackgroundSubtractorFGD = define_class_under<cv::cuda::BackgroundSubtractorFGD, cv::BackgroundSubtractor>(rb_mCvCuda, "BackgroundSubtractorFGD").
    define_method<void(cv::cuda::BackgroundSubtractorFGD::*)(cv::OutputArrayOfArrays)>("get_foreground_regions", &cv::cuda::BackgroundSubtractorFGD::getForegroundRegions,
      Arg("foreground_regions"));

  Rice::Data_Type<cv::cuda::FGDParams> rb_cCvCudaFGDParams = define_class_under<cv::cuda::FGDParams>(rb_mCvCuda, "FGDParams").
    define_attr("lc", &cv::cuda::FGDParams::Lc).
    define_attr("n1c", &cv::cuda::FGDParams::N1c).
    define_attr("n2c", &cv::cuda::FGDParams::N2c).
    define_attr("lcc", &cv::cuda::FGDParams::Lcc).
    define_attr("n1cc", &cv::cuda::FGDParams::N1cc).
    define_attr("n2cc", &cv::cuda::FGDParams::N2cc).
    define_attr("is_obj_without_holes", &cv::cuda::FGDParams::is_obj_without_holes).
    define_attr("perform_morphing", &cv::cuda::FGDParams::perform_morphing).
    define_attr("alpha1", &cv::cuda::FGDParams::alpha1).
    define_attr("alpha2", &cv::cuda::FGDParams::alpha2).
    define_attr("alpha3", &cv::cuda::FGDParams::alpha3).
    define_attr("delta", &cv::cuda::FGDParams::delta).
    define_attr("t", &cv::cuda::FGDParams::T).
    define_attr("min_area", &cv::cuda::FGDParams::minArea).
    define_constructor(Constructor<cv::cuda::FGDParams>());

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::BackgroundSubtractorFGD>(*)(const cv::cuda::FGDParams&)>("create_background_subtractor_fgd", &cv::cuda::createBackgroundSubtractorFGD,
    Arg("params") = static_cast<const cv::cuda::FGDParams&>(cv::cuda::FGDParams()));

  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::Size, cv::Size, cv::Size, bool, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("calc_optical_flow_bm", &cv::cuda::calcOpticalFlowBM,
    Arg("prev"), Arg("curr"), Arg("block_size"), Arg("shift_size"), Arg("max_range"), Arg("use_previous"), Arg("velx"), Arg("vely"), Arg("buf"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Rice::Data_Type<cv::cuda::FastOpticalFlowBM> rb_cCvCudaFastOpticalFlowBM = define_class_under<cv::cuda::FastOpticalFlowBM>(rb_mCvCuda, "FastOpticalFlowBM").
    define_constructor(Constructor<cv::cuda::FastOpticalFlowBM>()).
    define_method<void(cv::cuda::FastOpticalFlowBM::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, int, int, cv::cuda::Stream&)>("call", &cv::cuda::FastOpticalFlowBM::operator(),
      Arg("i0"), Arg("i1"), Arg("flowx"), Arg("flowy"), Arg("search_window") = static_cast<int>(21), Arg("block_window") = static_cast<int>(7), Arg("s") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, float, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("interpolate_frames", &cv::cuda::interpolateFrames,
    Arg("frame0"), Arg("frame1"), Arg("fu"), Arg("fv"), Arg("bu"), Arg("bv"), Arg("pos"), Arg("new_frame"), Arg("buf"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("create_optical_flow_needle_map", &cv::cuda::createOpticalFlowNeedleMap,
    Arg("u"), Arg("v"), Arg("vertex"), Arg("colors"));

  rb_mCvCuda.define_module_function<void(*)(cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("graphcut", &cv::cuda::graphcut,
    Arg("terminals"), Arg("left_transp"), Arg("right_transp"), Arg("top"), Arg("bottom"), Arg("labels"), Arg("buf"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("graphcut", &cv::cuda::graphcut,
    Arg("terminals"), Arg("left_transp"), Arg("right_transp"), Arg("top"), Arg("top_left"), Arg("top_right"), Arg("bottom"), Arg("bottom_left"), Arg("bottom_right"), Arg("labels"), Arg("buf"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, cv::cuda::GpuMat&, const cv::Scalar&, const cv::Scalar&, cv::cuda::Stream&)>("connectivity_mask", &cv::cuda::connectivityMask,
    Arg("image"), Arg("mask"), Arg("lo"), Arg("hi"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, cv::cuda::GpuMat&, int, cv::cuda::Stream&)>("label_components", &cv::cuda::labelComponents,
    Arg("mask"), Arg("components"), Arg("flags") = static_cast<int>(0), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, const cv::Mat&, const cv::Mat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("transform_points", &cv::cuda::transformPoints,
    Arg("src"), Arg("rvec"), Arg("tvec"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("project_points", &cv::cuda::projectPoints,
    Arg("src"), Arg("rvec"), Arg("tvec"), Arg("camera_mat"), Arg("dist_coef"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&, cv::Mat&, cv::Mat&, bool, int, float, int, std::vector<int>*)>("solve_pn_p_ransac", &cv::cuda::solvePnPRansac,
    Arg("object"), Arg("image"), Arg("camera_mat"), Arg("dist_coef"), Arg("rvec"), Arg("tvec"), Arg("use_extrinsic_guess") = static_cast<bool>(false), Arg("num_iters") = static_cast<int>(100), Arg("max_dist") = static_cast<float>(8.0), Arg("min_inlier_count") = static_cast<int>(100), Arg("inliers") = static_cast<std::vector<int>*>(NULL));
}
