#include <opencv2/ximgproc/fourier_descriptors.hpp>
#include "fourier_descriptors-rb.hpp"

using namespace Rice;

void Init_Ximgproc_FourierDescriptors()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Rice::Data_Type<cv::ximgproc::ContourFitting> rb_cCvXimgprocContourFitting = define_class_under<cv::ximgproc::ContourFitting, cv::Algorithm>(rb_mCvXimgproc, "ContourFitting").
    define_constructor(Constructor<cv::ximgproc::ContourFitting, int, int>(),
      Arg("ctr") = static_cast<int>(1024), Arg("fd") = static_cast<int>(16)).
    define_method<void(cv::ximgproc::ContourFitting::*)(cv::InputArray, cv::InputArray, cv::OutputArray, double*, bool)>("estimate_transformation", &cv::ximgproc::ContourFitting::estimateTransformation,
      Arg("src"), Arg("dst"), Arg("alpha_phi_st"), ArgBuffer("dist") = static_cast<double*>(0), Arg("fd_contour") = static_cast<bool>(false)).
    define_method<void(cv::ximgproc::ContourFitting::*)(cv::InputArray, cv::InputArray, cv::OutputArray, double&, bool)>("estimate_transformation", &cv::ximgproc::ContourFitting::estimateTransformation,
      Arg("src"), Arg("dst"), Arg("alpha_phi_st"), Arg("dist"), Arg("fd_contour") = static_cast<bool>(false)).
    define_method<void(cv::ximgproc::ContourFitting::*)(int)>("set_ctr_size", &cv::ximgproc::ContourFitting::setCtrSize,
      Arg("n")).
    define_method<void(cv::ximgproc::ContourFitting::*)(int)>("set_fd_size", &cv::ximgproc::ContourFitting::setFDSize,
      Arg("n")).
    define_method<int(cv::ximgproc::ContourFitting::*)()>("get_ctr_size", &cv::ximgproc::ContourFitting::getCtrSize).
    define_method<int(cv::ximgproc::ContourFitting::*)()>("get_fd_size", &cv::ximgproc::ContourFitting::getFDSize);

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int)>("fourier_descriptor", &cv::ximgproc::fourierDescriptor,
    Arg("src"), Arg("dst"), Arg("nb_elt") = static_cast<int>(-1), Arg("nb_fd") = static_cast<int>(-1));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, bool)>("transform_fd", &cv::ximgproc::transformFD,
    Arg("src"), Arg("t"), Arg("dst"), Arg("fd_contour") = static_cast<bool>(true));

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int)>("contour_sampling", &cv::ximgproc::contourSampling,
    Arg("src"), Arg("out"), Arg("nb_elt"));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::ContourFitting>(*)(int, int)>("create_contour_fitting", &cv::ximgproc::createContourFitting,
    Arg("ctr") = static_cast<int>(1024), Arg("fd") = static_cast<int>(16));
}
