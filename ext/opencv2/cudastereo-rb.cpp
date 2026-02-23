#include <opencv2/cudastereo.hpp>
#include "cudastereo-rb.hpp"

using namespace Rice;

void Init_Cudastereo()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::StereoBM> rb_cCvCudaStereoBM = define_class_under<cv::cuda::StereoBM, cv::StereoBM>(rb_mCvCuda, "StereoBM").
    define_method<void(cv::cuda::StereoBM::*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("compute", &cv::cuda::StereoBM::compute,
      Arg("left"), Arg("right"), Arg("disparity"), Arg("stream"));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::StereoBM>(*)(int, int)>("create_stereo_bm", &cv::cuda::createStereoBM,
    Arg("num_disparities") = static_cast<int>(64), Arg("block_size") = static_cast<int>(19));

  Rice::Data_Type<cv::cuda::StereoBeliefPropagation> rb_cCvCudaStereoBeliefPropagation = define_class_under<cv::cuda::StereoBeliefPropagation, cv::StereoMatcher>(rb_mCvCuda, "StereoBeliefPropagation").
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("compute", &cv::cuda::StereoBeliefPropagation::compute,
      Arg("left"), Arg("right"), Arg("disparity"), Arg("stream")).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("compute", &cv::cuda::StereoBeliefPropagation::compute,
      Arg("data"), Arg("disparity"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<int(cv::cuda::StereoBeliefPropagation::*)() const>("get_num_iters", &cv::cuda::StereoBeliefPropagation::getNumIters).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(int)>("set_num_iters", &cv::cuda::StereoBeliefPropagation::setNumIters,
      Arg("iters")).
    define_method<int(cv::cuda::StereoBeliefPropagation::*)() const>("get_num_levels", &cv::cuda::StereoBeliefPropagation::getNumLevels).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(int)>("set_num_levels", &cv::cuda::StereoBeliefPropagation::setNumLevels,
      Arg("levels")).
    define_method<double(cv::cuda::StereoBeliefPropagation::*)() const>("get_max_data_term", &cv::cuda::StereoBeliefPropagation::getMaxDataTerm).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(double)>("set_max_data_term", &cv::cuda::StereoBeliefPropagation::setMaxDataTerm,
      Arg("max_data_term")).
    define_method<double(cv::cuda::StereoBeliefPropagation::*)() const>("get_data_weight", &cv::cuda::StereoBeliefPropagation::getDataWeight).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(double)>("set_data_weight", &cv::cuda::StereoBeliefPropagation::setDataWeight,
      Arg("data_weight")).
    define_method<double(cv::cuda::StereoBeliefPropagation::*)() const>("get_max_disc_term", &cv::cuda::StereoBeliefPropagation::getMaxDiscTerm).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(double)>("set_max_disc_term", &cv::cuda::StereoBeliefPropagation::setMaxDiscTerm,
      Arg("max_disc_term")).
    define_method<double(cv::cuda::StereoBeliefPropagation::*)() const>("get_disc_single_jump", &cv::cuda::StereoBeliefPropagation::getDiscSingleJump).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(double)>("set_disc_single_jump", &cv::cuda::StereoBeliefPropagation::setDiscSingleJump,
      Arg("disc_single_jump")).
    define_method<int(cv::cuda::StereoBeliefPropagation::*)() const>("get_msg_type", &cv::cuda::StereoBeliefPropagation::getMsgType).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(int)>("set_msg_type", &cv::cuda::StereoBeliefPropagation::setMsgType,
      Arg("msg_type")).
    define_singleton_function<void(*)(int, int, int&, int&, int&)>("estimate_recommended_params", &cv::cuda::StereoBeliefPropagation::estimateRecommendedParams,
      Arg("width"), Arg("height"), Arg("ndisp"), Arg("iters"), Arg("levels"));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::StereoBeliefPropagation>(*)(int, int, int, int)>("create_stereo_belief_propagation", &cv::cuda::createStereoBeliefPropagation,
    Arg("ndisp") = static_cast<int>(64), Arg("iters") = static_cast<int>(5), Arg("levels") = static_cast<int>(5), Arg("msg_type") = static_cast<int>(CV_32F));

  Rice::Data_Type<cv::cuda::StereoConstantSpaceBP> rb_cCvCudaStereoConstantSpaceBP = define_class_under<cv::cuda::StereoConstantSpaceBP, cv::cuda::StereoBeliefPropagation>(rb_mCvCuda, "StereoConstantSpaceBP").
    define_method<int(cv::cuda::StereoConstantSpaceBP::*)() const>("get_nr_plane", &cv::cuda::StereoConstantSpaceBP::getNrPlane).
    define_method<void(cv::cuda::StereoConstantSpaceBP::*)(int)>("set_nr_plane", &cv::cuda::StereoConstantSpaceBP::setNrPlane,
      Arg("nr_plane")).
    define_method<bool(cv::cuda::StereoConstantSpaceBP::*)() const>("get_use_local_init_data_cost?", &cv::cuda::StereoConstantSpaceBP::getUseLocalInitDataCost).
    define_method<void(cv::cuda::StereoConstantSpaceBP::*)(bool)>("set_use_local_init_data_cost", &cv::cuda::StereoConstantSpaceBP::setUseLocalInitDataCost,
      Arg("use_local_init_data_cost")).
    define_singleton_function<void(*)(int, int, int&, int&, int&, int&)>("estimate_recommended_params", &cv::cuda::StereoConstantSpaceBP::estimateRecommendedParams,
      Arg("width"), Arg("height"), Arg("ndisp"), Arg("iters"), Arg("levels"), Arg("nr_plane"));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::StereoConstantSpaceBP>(*)(int, int, int, int, int)>("create_stereo_constant_space_bp", &cv::cuda::createStereoConstantSpaceBP,
    Arg("ndisp") = static_cast<int>(128), Arg("iters") = static_cast<int>(8), Arg("levels") = static_cast<int>(4), Arg("nr_plane") = static_cast<int>(4), Arg("msg_type") = static_cast<int>(CV_32F));

  Rice::Data_Type<cv::cuda::StereoSGM> rb_cCvCudaStereoSGM = define_class_under<cv::cuda::StereoSGM, cv::StereoSGBM>(rb_mCvCuda, "StereoSGM").
    define_method<void(cv::cuda::StereoSGM::*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("compute", &cv::cuda::StereoSGM::compute,
      Arg("left"), Arg("right"), Arg("disparity")).
    define_method<void(cv::cuda::StereoSGM::*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("compute", &cv::cuda::StereoSGM::compute,
      Arg("left"), Arg("right"), Arg("disparity"), Arg("stream"));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::StereoSGM>(*)(int, int, int, int, int, int)>("create_stereo_sgm", &cv::cuda::createStereoSGM,
    Arg("min_disparity") = static_cast<int>(0), Arg("num_disparities") = static_cast<int>(128), Arg("p1") = static_cast<int>(10), Arg("p2") = static_cast<int>(120), Arg("uniqueness_ratio") = static_cast<int>(5), Arg("mode") = static_cast<int>(cv::StereoSGBM::MODE_HH4));

  Rice::Data_Type<cv::cuda::DisparityBilateralFilter> rb_cCvCudaDisparityBilateralFilter = define_class_under<cv::cuda::DisparityBilateralFilter, cv::Algorithm>(rb_mCvCuda, "DisparityBilateralFilter").
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("apply", &cv::cuda::DisparityBilateralFilter::apply,
      Arg("disparity"), Arg("image"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method<int(cv::cuda::DisparityBilateralFilter::*)() const>("get_num_disparities", &cv::cuda::DisparityBilateralFilter::getNumDisparities).
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(int)>("set_num_disparities", &cv::cuda::DisparityBilateralFilter::setNumDisparities,
      Arg("num_disparities")).
    define_method<int(cv::cuda::DisparityBilateralFilter::*)() const>("get_radius", &cv::cuda::DisparityBilateralFilter::getRadius).
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(int)>("set_radius", &cv::cuda::DisparityBilateralFilter::setRadius,
      Arg("radius")).
    define_method<int(cv::cuda::DisparityBilateralFilter::*)() const>("get_num_iters", &cv::cuda::DisparityBilateralFilter::getNumIters).
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(int)>("set_num_iters", &cv::cuda::DisparityBilateralFilter::setNumIters,
      Arg("iters")).
    define_method<double(cv::cuda::DisparityBilateralFilter::*)() const>("get_edge_threshold", &cv::cuda::DisparityBilateralFilter::getEdgeThreshold).
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(double)>("set_edge_threshold", &cv::cuda::DisparityBilateralFilter::setEdgeThreshold,
      Arg("edge_threshold")).
    define_method<double(cv::cuda::DisparityBilateralFilter::*)() const>("get_max_disc_threshold", &cv::cuda::DisparityBilateralFilter::getMaxDiscThreshold).
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(double)>("set_max_disc_threshold", &cv::cuda::DisparityBilateralFilter::setMaxDiscThreshold,
      Arg("max_disc_threshold")).
    define_method<double(cv::cuda::DisparityBilateralFilter::*)() const>("get_sigma_range", &cv::cuda::DisparityBilateralFilter::getSigmaRange).
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(double)>("set_sigma_range", &cv::cuda::DisparityBilateralFilter::setSigmaRange,
      Arg("sigma_range"));

  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::DisparityBilateralFilter>(*)(int, int, int)>("create_disparity_bilateral_filter", &cv::cuda::createDisparityBilateralFilter,
    Arg("ndisp") = static_cast<int>(64), Arg("radius") = static_cast<int>(3), Arg("iters") = static_cast<int>(1));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, int, cv::cuda::Stream&)>("reproject_image_to_3d", &cv::cuda::reprojectImageTo3D,
    Arg("disp"), Arg("xyzw"), Arg("q"), Arg("dst_cn") = static_cast<int>(4), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::cuda::GpuMat, cv::cuda::GpuMat&, cv::Mat, int, cv::cuda::Stream&)>("reproject_image_to_3d", &cv::cuda::reprojectImageTo3D,
    Arg("disp"), Arg("xyzw"), Arg("q"), Arg("dst_cn") = static_cast<int>(4), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, cv::cuda::Stream&)>("draw_color_disp", &cv::cuda::drawColorDisp,
    Arg("src_disp"), Arg("dst_disp"), Arg("ndisp"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));
}
