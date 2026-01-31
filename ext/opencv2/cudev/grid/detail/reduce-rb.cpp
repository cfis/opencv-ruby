#include "reduce-rb.ipp"

void Init_Cudev_Grid_Detail_Reduce()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevGridReduceDetail = define_module_under(rb_mCvCudev, "GridReduceDetail");

  Rice::Data_Type<cv::cudev::grid_reduce_detail::Unroll<1>> rb_cCvCudevGridReduceDetailUnroll1 = define_class_under<cv::cudev::grid_reduce_detail::Unroll<1>>(rb_mCvCudevGridReduceDetail, "Unroll1").
    define_constructor(Constructor<cv::cudev::grid_reduce_detail::Unroll<1>>());

  Rice::Data_Type<cv::cudev::grid_reduce_detail::Unroll<2>> rb_cCvCudevGridReduceDetailUnroll2 = define_class_under<cv::cudev::grid_reduce_detail::Unroll<2>>(rb_mCvCudevGridReduceDetail, "Unroll2").
    define_constructor(Constructor<cv::cudev::grid_reduce_detail::Unroll<2>>());

  Rice::Data_Type<cv::cudev::grid_reduce_detail::Unroll<3>> rb_cCvCudevGridReduceDetailUnroll3 = define_class_under<cv::cudev::grid_reduce_detail::Unroll<3>>(rb_mCvCudevGridReduceDetail, "Unroll3").
    define_constructor(Constructor<cv::cudev::grid_reduce_detail::Unroll<3>>());

  Rice::Data_Type<cv::cudev::grid_reduce_detail::Unroll<4>> rb_cCvCudevGridReduceDetailUnroll4 = define_class_under<cv::cudev::grid_reduce_detail::Unroll<4>>(rb_mCvCudevGridReduceDetail, "Unroll4").
    define_constructor(Constructor<cv::cudev::grid_reduce_detail::Unroll<4>>());

  Rice::Data_Type<cv::cudev::grid_reduce_detail::both> rb_cCvCudevGridReduceDetailBoth = define_class_under<cv::cudev::grid_reduce_detail::both>(rb_mCvCudevGridReduceDetail, "Both").
    define_constructor(Constructor<cv::cudev::grid_reduce_detail::both>());
}