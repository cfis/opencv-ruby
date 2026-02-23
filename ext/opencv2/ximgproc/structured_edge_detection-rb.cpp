#include <opencv2/ximgproc/structured_edge_detection.hpp>
#include "structured_edge_detection-rb.hpp"

using namespace Rice;

void Init_Ximgproc_StructuredEdgeDetection()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Rice::Data_Type<cv::ximgproc::RFFeatureGetter> rb_cCvXimgprocRFFeatureGetter = define_class_under<cv::ximgproc::RFFeatureGetter, cv::Algorithm>(rb_mCvXimgproc, "RFFeatureGetter").
    define_method<void(cv::ximgproc::RFFeatureGetter::*)(const cv::Mat&, cv::Mat&, const int, const int, const int, const int, const int) const>("get_features", &cv::ximgproc::RFFeatureGetter::getFeatures,
      Arg("src"), Arg("features"), Arg("gnrm_rad"), Arg("gsmth_rad"), Arg("shrink"), Arg("out_num"), Arg("grad_num"));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::RFFeatureGetter>(*)()>("create_rf_feature_getter", &cv::ximgproc::createRFFeatureGetter);

  Rice::Data_Type<cv::ximgproc::StructuredEdgeDetection> rb_cCvXimgprocStructuredEdgeDetection = define_class_under<cv::ximgproc::StructuredEdgeDetection, cv::Algorithm>(rb_mCvXimgproc, "StructuredEdgeDetection").
    define_method<void(cv::ximgproc::StructuredEdgeDetection::*)(cv::InputArray, cv::OutputArray) const>("detect_edges", &cv::ximgproc::StructuredEdgeDetection::detectEdges,
      Arg("src"), Arg("dst")).
    define_method<void(cv::ximgproc::StructuredEdgeDetection::*)(cv::InputArray, cv::OutputArray) const>("compute_orientation", &cv::ximgproc::StructuredEdgeDetection::computeOrientation,
      Arg("src"), Arg("dst")).
    define_method<void(cv::ximgproc::StructuredEdgeDetection::*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, int, float, bool) const>("edges_nms", &cv::ximgproc::StructuredEdgeDetection::edgesNms,
      Arg("edge_image"), Arg("orientation_image"), Arg("dst"), Arg("r") = static_cast<int>(2), Arg("s") = static_cast<int>(0), Arg("m") = static_cast<float>(1), Arg("is_parallel") = static_cast<bool>(true));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::StructuredEdgeDetection>(*)(const cv::String&, cv::Ptr<const cv::ximgproc::RFFeatureGetter>)>("create_structured_edge_detection", &cv::ximgproc::createStructuredEdgeDetection,
    Arg("model"), Arg("how_to_get_features") = static_cast<cv::Ptr<const cv::ximgproc::RFFeatureGetter>>(cv::Ptr<cv::ximgproc::RFFeatureGetter>()));
}
