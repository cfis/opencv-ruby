#include <opencv2/mcc/checker_model.hpp>
#include "checker_model-rb.hpp"

using namespace Rice;

void Init_Mcc_CheckerModel()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvMcc = define_module_under(rb_mCv, "Mcc");

  Enum<cv::mcc::TYPECHART> rb_cCvMccTYPECHART = define_enum_under<cv::mcc::TYPECHART>("TYPECHART", rb_mCvMcc).
    define_value("MCC24", cv::mcc::TYPECHART::MCC24).
    define_value("SG140", cv::mcc::TYPECHART::SG140).
    define_value("VINYL18", cv::mcc::TYPECHART::VINYL18);

  Rice::Data_Type<cv::mcc::CChecker> rb_cCvMccCChecker = define_class_under<cv::mcc::CChecker>(rb_mCvMcc, "CChecker").
    define_singleton_function<cv::Ptr<cv::mcc::CChecker>(*)()>("create", &cv::mcc::CChecker::create).
    define_method<void(cv::mcc::CChecker::*)(cv::mcc::TYPECHART)>("set_target", &cv::mcc::CChecker::setTarget,
      Arg("_target")).
    define_method<void(cv::mcc::CChecker::*)(std::vector<cv::Point_<float>>)>("set_box", &cv::mcc::CChecker::setBox,
      Arg("_box")).
    define_method<void(cv::mcc::CChecker::*)(cv::Mat)>("set_charts_rgb", &cv::mcc::CChecker::setChartsRGB,
      Arg("_charts_rgb")).
    define_method<void(cv::mcc::CChecker::*)(cv::Mat)>("set_charts_y_cb_cr", &cv::mcc::CChecker::setChartsYCbCr,
      Arg("_charts_y_cb_cr")).
    define_method<void(cv::mcc::CChecker::*)(float)>("set_cost", &cv::mcc::CChecker::setCost,
      Arg("_cost")).
    define_method<void(cv::mcc::CChecker::*)(cv::Point2f)>("set_center", &cv::mcc::CChecker::setCenter,
      Arg("_center")).
    define_method<cv::mcc::TYPECHART(cv::mcc::CChecker::*)()>("get_target", &cv::mcc::CChecker::getTarget).
    define_method<std::vector<cv::Point_<float>>(cv::mcc::CChecker::*)()>("get_box", &cv::mcc::CChecker::getBox).
    define_method<std::vector<cv::Point_<float>>(cv::mcc::CChecker::*)()>("get_color_charts", &cv::mcc::CChecker::getColorCharts).
    define_method<cv::Mat(cv::mcc::CChecker::*)()>("get_charts_rgb", &cv::mcc::CChecker::getChartsRGB).
    define_method<cv::Mat(cv::mcc::CChecker::*)()>("get_charts_y_cb_cr", &cv::mcc::CChecker::getChartsYCbCr).
    define_method<float(cv::mcc::CChecker::*)()>("get_cost", &cv::mcc::CChecker::getCost).
    define_method<cv::Point2f(cv::mcc::CChecker::*)()>("get_center", &cv::mcc::CChecker::getCenter);

  Rice::Data_Type<cv::mcc::CCheckerDraw> rb_cCvMccCCheckerDraw = define_class_under<cv::mcc::CCheckerDraw>(rb_mCvMcc, "CCheckerDraw").
    define_method<void(cv::mcc::CCheckerDraw::*)(cv::InputOutputArray)>("draw", &cv::mcc::CCheckerDraw::draw,
      Arg("img")).
    define_singleton_function<cv::Ptr<cv::mcc::CCheckerDraw>(*)(cv::Ptr<cv::mcc::CChecker>, cv::Scalar, int)>("create", &cv::mcc::CCheckerDraw::create,
      Arg("p_checker"), Arg("color") = static_cast<cv::Scalar>(CV_RGB(0, 250, 0)), Arg("thickness") = static_cast<int>(2));
}
