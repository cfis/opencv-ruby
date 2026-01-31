#include <opencv2/cudev/ptr2d/warping.hpp>
#include "warping-rb.hpp"

using namespace Rice;

void Init_Cudev_Ptr2d_Warping()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::AffineMapPtr> rb_cCvCudevAffineMapPtr = define_class_under<cv::cudev::AffineMapPtr>(rb_mCvCudev, "AffineMapPtr").
    define_constructor(Constructor<cv::cudev::AffineMapPtr>()).
    define_attr("warp_mat", &cv::cudev::AffineMapPtr::warpMat).
    define_method<float2(cv::cudev::AffineMapPtr::*)(float, float) const>("call", &cv::cudev::AffineMapPtr::operator(),
      Arg("y"), Arg("x"));

  Rice::Data_Type<cv::cudev::AffineMapPtrSz> rb_cCvCudevAffineMapPtrSz = define_class_under<cv::cudev::AffineMapPtrSz, cv::cudev::AffineMapPtr>(rb_mCvCudev, "AffineMapPtrSz").
    define_constructor(Constructor<cv::cudev::AffineMapPtrSz>()).
    define_attr("rows", &cv::cudev::AffineMapPtrSz::rows).
    define_attr("cols", &cv::cudev::AffineMapPtrSz::cols);

  Rice::Data_Type<cv::cudev::PtrTraitsBase<cv::cudev::AffineMapPtrSz, cv::cudev::AffineMapPtr>> rb_cPtrTraitsBaseAffineMapPtrSzAffineMapPtr = define_class_under<cv::cudev::PtrTraitsBase<cv::cudev::AffineMapPtrSz, cv::cudev::AffineMapPtr>>(rb_mCvCudev, "PtrTraitsBaseAffineMapPtrSzAffineMapPtr").
    define(&PtrTraitsBase_builder<Data_Type<cv::cudev::PtrTraitsBase<cv::cudev::AffineMapPtrSz, cv::cudev::AffineMapPtr>>, cv::cudev::AffineMapPtrSz, cv::cudev::AffineMapPtr>);
  Rice::Data_Type<cv::cudev::PtrTraits<cv::cudev::AffineMapPtrSz>> rb_cCvCudevPtrTraitsAffineMapPtrSz = define_class_under<cv::cudev::PtrTraits<cv::cudev::AffineMapPtrSz>, cv::cudev::PtrTraitsBase<cv::cudev::AffineMapPtrSz, cv::cudev::AffineMapPtr>>(rb_mCvCudev, "PtrTraitsAffineMapPtrSz").
    define_constructor(Constructor<cv::cudev::PtrTraits<cv::cudev::AffineMapPtrSz>>());

  rb_mCvCudev.define_module_function<cv::cudev::AffineMapPtrSz(*)(cv::Size, const cv::cudev::GpuMat_<float>&)>("affine_map", &cv::cudev::affineMap,
    Arg("dst_size"), Arg("warp_mat"));

  Rice::Data_Type<cv::cudev::PerspectiveMapPtr> rb_cCvCudevPerspectiveMapPtr = define_class_under<cv::cudev::PerspectiveMapPtr>(rb_mCvCudev, "PerspectiveMapPtr").
    define_constructor(Constructor<cv::cudev::PerspectiveMapPtr>()).
    define_attr("warp_mat", &cv::cudev::PerspectiveMapPtr::warpMat).
    define_method<float2(cv::cudev::PerspectiveMapPtr::*)(float, float) const>("call", &cv::cudev::PerspectiveMapPtr::operator(),
      Arg("y"), Arg("x"));

  Rice::Data_Type<cv::cudev::PerspectiveMapPtrSz> rb_cCvCudevPerspectiveMapPtrSz = define_class_under<cv::cudev::PerspectiveMapPtrSz, cv::cudev::PerspectiveMapPtr>(rb_mCvCudev, "PerspectiveMapPtrSz").
    define_constructor(Constructor<cv::cudev::PerspectiveMapPtrSz>()).
    define_attr("rows", &cv::cudev::PerspectiveMapPtrSz::rows).
    define_attr("cols", &cv::cudev::PerspectiveMapPtrSz::cols);

  Rice::Data_Type<cv::cudev::PtrTraitsBase<cv::cudev::PerspectiveMapPtrSz, cv::cudev::PerspectiveMapPtr>> rb_cPtrTraitsBasePerspectiveMapPtrSzPerspectiveMapPtr = define_class_under<cv::cudev::PtrTraitsBase<cv::cudev::PerspectiveMapPtrSz, cv::cudev::PerspectiveMapPtr>>(rb_mCvCudev, "PtrTraitsBasePerspectiveMapPtrSzPerspectiveMapPtr").
    define(&PtrTraitsBase_builder<Data_Type<cv::cudev::PtrTraitsBase<cv::cudev::PerspectiveMapPtrSz, cv::cudev::PerspectiveMapPtr>>, cv::cudev::PerspectiveMapPtrSz, cv::cudev::PerspectiveMapPtr>);
  Rice::Data_Type<cv::cudev::PtrTraits<cv::cudev::PerspectiveMapPtrSz>> rb_cCvCudevPtrTraitsPerspectiveMapPtrSz = define_class_under<cv::cudev::PtrTraits<cv::cudev::PerspectiveMapPtrSz>, cv::cudev::PtrTraitsBase<cv::cudev::PerspectiveMapPtrSz, cv::cudev::PerspectiveMapPtr>>(rb_mCvCudev, "PtrTraitsPerspectiveMapPtrSz").
    define_constructor(Constructor<cv::cudev::PtrTraits<cv::cudev::PerspectiveMapPtrSz>>());

  rb_mCvCudev.define_module_function<cv::cudev::PerspectiveMapPtrSz(*)(cv::Size, const cv::cudev::GpuMat_<float>&)>("perspective_map", &cv::cudev::perspectiveMap,
    Arg("dst_size"), Arg("warp_mat"));
}