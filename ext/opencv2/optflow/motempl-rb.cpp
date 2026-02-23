#include <opencv2/optflow/motempl.hpp>
#include "motempl-rb.hpp"

using namespace Rice;

void Init_Optflow_Motempl()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvMotempl = define_module_under(rb_mCv, "Motempl");

  rb_mCvMotempl.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, double, double)>("update_motion_history", &cv::motempl::updateMotionHistory,
    Arg("silhouette"), Arg("mhi"), Arg("timestamp"), Arg("duration"));

  rb_mCvMotempl.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, double, double, int)>("calc_motion_gradient", &cv::motempl::calcMotionGradient,
    Arg("mhi"), Arg("mask"), Arg("orientation"), Arg("delta1"), Arg("delta2"), Arg("aperture_size") = static_cast<int>(3));

  rb_mCvMotempl.define_module_function<double(*)(cv::InputArray, cv::InputArray, cv::InputArray, double, double)>("calc_global_orientation", &cv::motempl::calcGlobalOrientation,
    Arg("orientation"), Arg("mask"), Arg("mhi"), Arg("timestamp"), Arg("duration"));

  rb_mCvMotempl.define_module_function<void(*)(cv::InputArray, cv::OutputArray, std::vector<cv::Rect_<int>>&, double, double)>("segment_motion", &cv::motempl::segmentMotion,
    Arg("mhi"), Arg("segmask"), Arg("bounding_rects"), Arg("timestamp"), Arg("seg_thresh"));
}
