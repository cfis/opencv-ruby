#include <opencv2/text/erfilter.hpp>
#include "erfilter-rb.hpp"

using namespace Rice;

void Init_Text_Erfilter()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvText = define_module_under(rb_mCv, "Text");

  Rice::Data_Type<cv::text::ERStat> rb_cCvTextERStat = define_class_under<cv::text::ERStat>(rb_mCvText, "ERStat").
    define_constructor(Constructor<cv::text::ERStat, int, int, int, int>(),
      Arg("level") = static_cast<int>(256), Arg("pixel") = static_cast<int>(0), Arg("x") = static_cast<int>(0), Arg("y") = static_cast<int>(0)).
    define_attr("pixel", &cv::text::ERStat::pixel).
    define_attr("level", &cv::text::ERStat::level).
    define_attr("area", &cv::text::ERStat::area).
    define_attr("perimeter", &cv::text::ERStat::perimeter).
    define_attr("euler", &cv::text::ERStat::euler).
    define_attr("rect", &cv::text::ERStat::rect).
    define_attr("raw_moments", &cv::text::ERStat::raw_moments, Rice::AttrAccess::Read).
    define_attr("central_moments", &cv::text::ERStat::central_moments, Rice::AttrAccess::Read).
    define_attr("crossings", &cv::text::ERStat::crossings).
    define_attr("med_crossings", &cv::text::ERStat::med_crossings).
    define_attr("hole_area_ratio", &cv::text::ERStat::hole_area_ratio).
    define_attr("convex_hull_ratio", &cv::text::ERStat::convex_hull_ratio).
    define_attr("num_inflexion_points", &cv::text::ERStat::num_inflexion_points).
    define_attr("pixels", &cv::text::ERStat::pixels).
    define_attr("probability", &cv::text::ERStat::probability).
    define_attr("parent", &cv::text::ERStat::parent).
    define_attr("child", &cv::text::ERStat::child).
    define_attr("next", &cv::text::ERStat::next).
    define_attr("prev", &cv::text::ERStat::prev).
    define_attr("local_maxima", &cv::text::ERStat::local_maxima).
    define_attr("max_probability_ancestor", &cv::text::ERStat::max_probability_ancestor).
    define_attr("min_probability_ancestor", &cv::text::ERStat::min_probability_ancestor);

  Rice::Data_Type<cv::text::ERFilter> rb_cCvTextERFilter = define_class_under<cv::text::ERFilter, cv::Algorithm>(rb_mCvText, "ERFilter").
    define_method<void(cv::text::ERFilter::*)(cv::InputArray, std::vector<cv::text::ERStat>&)>("run", &cv::text::ERFilter::run,
      Arg("image"), Arg("regions")).
    define_method<void(cv::text::ERFilter::*)(const cv::Ptr<cv::text::ERFilter::Callback>&)>("set_callback", &cv::text::ERFilter::setCallback,
      Arg("cb")).
    define_method<void(cv::text::ERFilter::*)(int)>("set_threshold_delta", &cv::text::ERFilter::setThresholdDelta,
      Arg("threshold_delta")).
    define_method<void(cv::text::ERFilter::*)(float)>("set_min_area", &cv::text::ERFilter::setMinArea,
      Arg("min_area")).
    define_method<void(cv::text::ERFilter::*)(float)>("set_max_area", &cv::text::ERFilter::setMaxArea,
      Arg("max_area")).
    define_method<void(cv::text::ERFilter::*)(float)>("set_min_probability", &cv::text::ERFilter::setMinProbability,
      Arg("min_probability")).
    define_method<void(cv::text::ERFilter::*)(float)>("set_min_probability_diff", &cv::text::ERFilter::setMinProbabilityDiff,
      Arg("min_probability_diff")).
    define_method<void(cv::text::ERFilter::*)(bool)>("set_non_max_suppression", &cv::text::ERFilter::setNonMaxSuppression,
      Arg("non_max_suppression")).
    define_method<int(cv::text::ERFilter::*)() const>("get_num_rejected", &cv::text::ERFilter::getNumRejected);

  Rice::Data_Type<cv::text::ERFilter::Callback> rb_cCvTextERFilterCallback = define_class_under<cv::text::ERFilter::Callback>(rb_cCvTextERFilter, "Callback").
    define_method<double(cv::text::ERFilter::Callback::*)(const cv::text::ERStat&)>("eval", &cv::text::ERFilter::Callback::eval,
      Arg("stat"));

  rb_mCvText.define_module_function<cv::Ptr<cv::text::ERFilter>(*)(const cv::Ptr<cv::text::ERFilter::Callback>&, int, float, float, float, bool, float)>("create_er_filter_nm1", &cv::text::createERFilterNM1,
    Arg("cb"), Arg("threshold_delta") = static_cast<int>(1), Arg("min_area"), Arg("max_area"), Arg("min_probability"), Arg("non_max_suppression") = static_cast<bool>(true), Arg("min_probability_diff"));

  rb_mCvText.define_module_function<cv::Ptr<cv::text::ERFilter>(*)(const cv::Ptr<cv::text::ERFilter::Callback>&, float)>("create_er_filter_nm2", &cv::text::createERFilterNM2,
    Arg("cb"), Arg("min_probability"));

  rb_mCvText.define_module_function<cv::Ptr<cv::text::ERFilter>(*)(const cv::String&, int, float, float, float, bool, float)>("create_er_filter_nm1", &cv::text::createERFilterNM1,
    Arg("filename"), Arg("threshold_delta") = static_cast<int>(1), Arg("min_area"), Arg("max_area"), Arg("min_probability"), Arg("non_max_suppression") = static_cast<bool>(true), Arg("min_probability_diff"));

  rb_mCvText.define_module_function<cv::Ptr<cv::text::ERFilter>(*)(const cv::String&, float)>("create_er_filter_nm2", &cv::text::createERFilterNM2,
    Arg("filename"), Arg("min_probability"));

  rb_mCvText.define_module_function<cv::Ptr<cv::text::ERFilter::Callback>(*)(const cv::String&)>("load_classifier_nm1", &cv::text::loadClassifierNM1,
    Arg("filename"));

  rb_mCvText.define_module_function<cv::Ptr<cv::text::ERFilter::Callback>(*)(const cv::String&)>("load_classifier_nm2", &cv::text::loadClassifierNM2,
    Arg("filename"));

  rb_mCvText.define_constant("ERFILTER_NM_RGBLGrad", (int)cv::text::ERFILTER_NM_RGBLGrad);
  rb_mCvText.define_constant("ERFILTER_NM_IHSGrad", (int)cv::text::ERFILTER_NM_IHSGrad);

  rb_mCvText.define_module_function<void(*)(cv::InputArray, cv::OutputArrayOfArrays, int)>("compute_nm_channels", &cv::text::computeNMChannels,
    Arg("_src"), Arg("_channels"), Arg("_mode") = static_cast<int>(cv::text::ERFILTER_NM_RGBLGrad));

  Enum<cv::text::erGrouping_Modes> rb_cCvTextErGroupingModes = define_enum_under<cv::text::erGrouping_Modes>("ErGroupingModes", rb_mCvText).
    define_value("ERGROUPING_ORIENTATION_HORIZ", cv::text::erGrouping_Modes::ERGROUPING_ORIENTATION_HORIZ).
    define_value("ERGROUPING_ORIENTATION_ANY", cv::text::erGrouping_Modes::ERGROUPING_ORIENTATION_ANY);

  rb_mCvText.define_module_function<void(*)(cv::InputArray, cv::InputArrayOfArrays, std::vector<std::vector<cv::text::ERStat>>&, std::vector<std::vector<cv::Vec<int, 2>>>&, std::vector<cv::Rect_<int>>&, int, const std::string&, float)>("er_grouping", &cv::text::erGrouping,
    Arg("img"), Arg("channels"), Arg("regions"), Arg("groups"), Arg("groups_rects"), Arg("method") = static_cast<int>(cv::text::ERGROUPING_ORIENTATION_HORIZ), Arg("filename") = static_cast<const std::string&>(std::string()), Arg("min_probablity") = static_cast<float>(0.5));

  rb_mCvText.define_module_function<void(*)(cv::InputArray, cv::InputArray, std::vector<std::vector<cv::Point_<int>>>, std::vector<cv::Rect_<int>>&, int, const cv::String&, float)>("er_grouping", &cv::text::erGrouping,
    Arg("image"), Arg("channel"), Arg("regions"), Arg("groups_rects"), Arg("method") = static_cast<int>(cv::text::ERGROUPING_ORIENTATION_HORIZ), Arg("filename") = static_cast<const cv::String&>(cv::String()), Arg("min_probablity"));

  rb_mCvText.define_module_function<void(*)(cv::InputArray, std::vector<std::vector<cv::Point_<int>>>&, std::vector<std::vector<cv::text::ERStat>>&)>("mse_rs_to_er_stats", &cv::text::MSERsToERStats,
    Arg("image"), Arg("contours"), Arg("regions"));

  rb_mCvText.define_module_function<void(*)(cv::InputArray, const cv::Ptr<cv::text::ERFilter>&, const cv::Ptr<cv::text::ERFilter>&, std::vector<std::vector<cv::Point_<int>>>&)>("detect_regions", &cv::text::detectRegions,
    Arg("image"), Arg("er_filter1"), Arg("er_filter2"), Arg("regions"));

  rb_mCvText.define_module_function<void(*)(cv::InputArray, const cv::Ptr<cv::text::ERFilter>&, const cv::Ptr<cv::text::ERFilter>&, std::vector<cv::Rect_<int>>&, int, const cv::String&, float)>("detect_regions", &cv::text::detectRegions,
    Arg("image"), Arg("er_filter1"), Arg("er_filter2"), Arg("groups_rects"), Arg("method") = static_cast<int>(cv::text::ERGROUPING_ORIENTATION_HORIZ), Arg("filename") = static_cast<const cv::String&>(cv::String()), Arg("min_probability"));
}
