#include <opencv2/cudev/grid/detail/transform.hpp>
#include "transform-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_Detail_Transform()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevGridTransformDetail = define_module_under(rb_mCvCudev, "GridTransformDetail");

  Rice::Data_Type<cv::cudev::grid_transform_detail::OpUnroller<1>> rb_cCvCudevGridTransformDetailOpUnroller1 = define_class_under<cv::cudev::grid_transform_detail::OpUnroller<1>>(rb_mCvCudevGridTransformDetail, "OpUnroller1").
    define_constructor(Constructor<cv::cudev::grid_transform_detail::OpUnroller<1>>());

  Rice::Data_Type<cv::cudev::grid_transform_detail::OpUnroller<2>> rb_cCvCudevGridTransformDetailOpUnroller2 = define_class_under<cv::cudev::grid_transform_detail::OpUnroller<2>>(rb_mCvCudevGridTransformDetail, "OpUnroller2").
    define_constructor(Constructor<cv::cudev::grid_transform_detail::OpUnroller<2>>());

  Rice::Data_Type<cv::cudev::grid_transform_detail::OpUnroller<3>> rb_cCvCudevGridTransformDetailOpUnroller3 = define_class_under<cv::cudev::grid_transform_detail::OpUnroller<3>>(rb_mCvCudevGridTransformDetail, "OpUnroller3").
    define_constructor(Constructor<cv::cudev::grid_transform_detail::OpUnroller<3>>());

  Rice::Data_Type<cv::cudev::grid_transform_detail::OpUnroller<4>> rb_cCvCudevGridTransformDetailOpUnroller4 = define_class_under<cv::cudev::grid_transform_detail::OpUnroller<4>>(rb_mCvCudevGridTransformDetail, "OpUnroller4").
    define_constructor(Constructor<cv::cudev::grid_transform_detail::OpUnroller<4>>());

  Rice::Data_Type<cv::cudev::grid_transform_detail::Unroll<0>> rb_cCvCudevGridTransformDetailUnroll0 = define_class_under<cv::cudev::grid_transform_detail::Unroll<0>>(rb_mCvCudevGridTransformDetail, "Unroll0").
    define_constructor(Constructor<cv::cudev::grid_transform_detail::Unroll<0>>());
}