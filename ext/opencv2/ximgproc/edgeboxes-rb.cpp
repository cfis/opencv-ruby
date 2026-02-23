#include <opencv2/ximgproc/edgeboxes.hpp>
#include "edgeboxes-rb.hpp"

using namespace Rice;

void Init_Ximgproc_Edgeboxes()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Rice::Data_Type<cv::ximgproc::Box> rb_cCvXimgprocBox = define_class_under<cv::ximgproc::Box>(rb_mCvXimgproc, "Box").
    define_constructor(Constructor<cv::ximgproc::Box>()).
    define_attr("x", &cv::ximgproc::Box::x).
    define_attr("y", &cv::ximgproc::Box::y).
    define_attr("w", &cv::ximgproc::Box::w).
    define_attr("h", &cv::ximgproc::Box::h).
    define_attr("score", &cv::ximgproc::Box::score);

  Rice::Data_Type<cv::ximgproc::EdgeBoxes> rb_cCvXimgprocEdgeBoxes = define_class_under<cv::ximgproc::EdgeBoxes, cv::Algorithm>(rb_mCvXimgproc, "EdgeBoxes").
    define_method<void(cv::ximgproc::EdgeBoxes::*)(cv::InputArray, cv::InputArray, std::vector<cv::Rect_<int>>&, cv::OutputArray)>("get_bounding_boxes", &cv::ximgproc::EdgeBoxes::getBoundingBoxes,
      Arg("edge_map"), Arg("orientation_map"), Arg("boxes"), Arg("scores") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_alpha", &cv::ximgproc::EdgeBoxes::getAlpha).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_alpha", &cv::ximgproc::EdgeBoxes::setAlpha,
      Arg("value")).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_beta", &cv::ximgproc::EdgeBoxes::getBeta).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_beta", &cv::ximgproc::EdgeBoxes::setBeta,
      Arg("value")).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_eta", &cv::ximgproc::EdgeBoxes::getEta).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_eta", &cv::ximgproc::EdgeBoxes::setEta,
      Arg("value")).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_min_score", &cv::ximgproc::EdgeBoxes::getMinScore).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_min_score", &cv::ximgproc::EdgeBoxes::setMinScore,
      Arg("value")).
    define_method<int(cv::ximgproc::EdgeBoxes::*)() const>("get_max_boxes", &cv::ximgproc::EdgeBoxes::getMaxBoxes).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(int)>("set_max_boxes", &cv::ximgproc::EdgeBoxes::setMaxBoxes,
      Arg("value")).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_edge_min_mag", &cv::ximgproc::EdgeBoxes::getEdgeMinMag).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_edge_min_mag", &cv::ximgproc::EdgeBoxes::setEdgeMinMag,
      Arg("value")).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_edge_merge_thr", &cv::ximgproc::EdgeBoxes::getEdgeMergeThr).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_edge_merge_thr", &cv::ximgproc::EdgeBoxes::setEdgeMergeThr,
      Arg("value")).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_cluster_min_mag", &cv::ximgproc::EdgeBoxes::getClusterMinMag).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_cluster_min_mag", &cv::ximgproc::EdgeBoxes::setClusterMinMag,
      Arg("value")).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_max_aspect_ratio", &cv::ximgproc::EdgeBoxes::getMaxAspectRatio).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_max_aspect_ratio", &cv::ximgproc::EdgeBoxes::setMaxAspectRatio,
      Arg("value")).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_min_box_area", &cv::ximgproc::EdgeBoxes::getMinBoxArea).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_min_box_area", &cv::ximgproc::EdgeBoxes::setMinBoxArea,
      Arg("value")).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_gamma", &cv::ximgproc::EdgeBoxes::getGamma).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_gamma", &cv::ximgproc::EdgeBoxes::setGamma,
      Arg("value")).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_kappa", &cv::ximgproc::EdgeBoxes::getKappa).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_kappa", &cv::ximgproc::EdgeBoxes::setKappa,
      Arg("value"));

  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::EdgeBoxes>(*)(float, float, float, float, int, float, float, float, float, float, float, float)>("create_edge_boxes", &cv::ximgproc::createEdgeBoxes,
    Arg("alpha") = static_cast<float>(0.65f), Arg("beta") = static_cast<float>(0.75f), Arg("eta") = static_cast<float>(1), Arg("min_score") = static_cast<float>(0.01f), Arg("max_boxes") = static_cast<int>(10000), Arg("edge_min_mag") = static_cast<float>(0.1f), Arg("edge_merge_thr") = static_cast<float>(0.5f), Arg("cluster_min_mag") = static_cast<float>(0.5f), Arg("max_aspect_ratio") = static_cast<float>(3), Arg("min_box_area") = static_cast<float>(1000), Arg("gamma") = static_cast<float>(2), Arg("kappa") = static_cast<float>(1.5f));
}
