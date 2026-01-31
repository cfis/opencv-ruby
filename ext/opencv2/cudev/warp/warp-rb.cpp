#include <opencv2/cudev/warp/warp.hpp>
#include "warp-rb.hpp"

using namespace Rice;

void Init_Cudev_Warp_Warp()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  rb_mCvCudev.define_constant("LOG_WARP_SIZE", (int)cv::cudev::LOG_WARP_SIZE);
  rb_mCvCudev.define_constant("WARP_SIZE", (int)cv::cudev::WARP_SIZE);

  Rice::Data_Type<cv::cudev::Warp> rb_cCvCudevWarp = define_class_under<cv::cudev::Warp>(rb_mCvCudev, "Warp").
    define_constructor(Constructor<cv::cudev::Warp>()).
    define_singleton_function<uint(*)()>("lane_id", &cv::cudev::Warp::laneId).
    define_singleton_function<uint(*)()>("warp_id", &cv::cudev::Warp::warpId);
}