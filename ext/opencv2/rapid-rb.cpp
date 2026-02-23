#include <opencv2/rapid.hpp>
#include "rapid-rb.hpp"

using namespace Rice;

void Init_Rapid()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvRapid = define_module_under(rb_mCv, "Rapid");

  rb_mCvRapid.define_module_function<void(*)(cv::InputOutputArray, cv::InputArray, cv::InputArray)>("draw_correspondencies", &cv::rapid::drawCorrespondencies,
    Arg("bundle"), Arg("cols"), Arg("colors") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvRapid.define_module_function<void(*)(cv::InputOutputArray, cv::InputArray, const cv::Scalar&)>("draw_search_lines", &cv::rapid::drawSearchLines,
    Arg("img"), Arg("locations"), Arg("color"));

  rb_mCvRapid.define_module_function<void(*)(cv::InputOutputArray, cv::InputArray, cv::InputArray, const cv::Scalar&, int, bool)>("draw_wireframe", &cv::rapid::drawWireframe,
    Arg("img"), Arg("pts2d"), Arg("tris"), Arg("color"), Arg("type") = static_cast<int>(cv::LINE_8), Arg("cull_backface") = static_cast<bool>(false));

  rb_mCvRapid.define_module_function<void(*)(int, int, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, const cv::Size&, cv::InputArray, cv::OutputArray, cv::OutputArray)>("extract_control_points", &cv::rapid::extractControlPoints,
    Arg("num"), Arg("len"), Arg("pts3d"), Arg("rvec"), Arg("tvec"), Arg("k"), Arg("imsize"), Arg("tris"), Arg("ctl2d"), Arg("ctl3d"));

  rb_mCvRapid.define_module_function<void(*)(int, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("extract_line_bundle", &cv::rapid::extractLineBundle,
    Arg("len"), Arg("ctl2d"), Arg("img"), Arg("bundle"), Arg("src_locations"));

  rb_mCvRapid.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray)>("find_correspondencies", &cv::rapid::findCorrespondencies,
    Arg("bundle"), Arg("cols"), Arg("response") = static_cast<cv::OutputArray>(cv::noArray()));

  rb_mCvRapid.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::InputOutputArray, cv::InputArray)>("convert_correspondencies", &cv::rapid::convertCorrespondencies,
    Arg("cols"), Arg("src_locations"), Arg("pts2d"), Arg("pts3d") = static_cast<cv::InputOutputArray>(cv::noArray()), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvRapid.define_module_function<float(*)(cv::InputArray, int, int, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::InputOutputArray, double*)>("rapid", &cv::rapid::rapid,
    Arg("img"), Arg("num"), Arg("len"), Arg("pts3d"), Arg("tris"), Arg("k"), Arg("rvec"), Arg("tvec"), ArgBuffer("rmsd") = static_cast<double*>(0));

  Rice::Data_Type<cv::rapid::Tracker> rb_cCvRapidTracker = define_class_under<cv::rapid::Tracker, cv::Algorithm>(rb_mCvRapid, "Tracker").
    define_method<float(cv::rapid::Tracker::*)(cv::InputArray, int, int, cv::InputArray, cv::InputOutputArray, cv::InputOutputArray, const cv::TermCriteria&)>("compute", &cv::rapid::Tracker::compute,
      Arg("img"), Arg("num"), Arg("len"), Arg("k"), Arg("rvec"), Arg("tvec"), Arg("termcrit") = static_cast<const cv::TermCriteria&>(cv::TermCriteria(cv::TermCriteria::Type::MAX_ITER | cv::TermCriteria::Type::EPS, 5, 1.5))).
    define_method<void(cv::rapid::Tracker::*)()>("clear_state", &cv::rapid::Tracker::clearState);

  Rice::Data_Type<cv::rapid::Rapid> rb_cCvRapidRapid = define_class_under<cv::rapid::Rapid, cv::rapid::Tracker>(rb_mCvRapid, "Rapid").
    define_singleton_function<cv::Ptr<cv::rapid::Rapid>(*)(cv::InputArray, cv::InputArray)>("create", &cv::rapid::Rapid::create,
      Arg("pts3d"), Arg("tris"));

  Rice::Data_Type<cv::rapid::OLSTracker> rb_cCvRapidOLSTracker = define_class_under<cv::rapid::OLSTracker, cv::rapid::Tracker>(rb_mCvRapid, "OLSTracker").
    define_singleton_function<cv::Ptr<cv::rapid::OLSTracker>(*)(cv::InputArray, cv::InputArray, int, uchar)>("create", &cv::rapid::OLSTracker::create,
      Arg("pts3d"), Arg("tris"), Arg("hist_bins") = static_cast<int>(8), Arg("sobel_thesh") = static_cast<uchar>(10));

  Rice::Data_Type<cv::rapid::GOSTracker> rb_cCvRapidGOSTracker = define_class_under<cv::rapid::GOSTracker, cv::rapid::Tracker>(rb_mCvRapid, "GOSTracker").
    define_singleton_function<cv::Ptr<cv::rapid::OLSTracker>(*)(cv::InputArray, cv::InputArray, int, uchar)>("create", &cv::rapid::GOSTracker::create,
      Arg("pts3d"), Arg("tris"), Arg("hist_bins") = static_cast<int>(4), Arg("sobel_thesh") = static_cast<uchar>(10));
}
