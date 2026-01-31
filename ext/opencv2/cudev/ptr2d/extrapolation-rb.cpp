#include <opencv2/cudev/ptr2d/extrapolation.hpp>
#include "extrapolation-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename SrcPtr>
inline void BrdConstant_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::BrdConstant<SrcPtr>::src).
    define_attr("rows", &cv::cudev::BrdConstant<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::BrdConstant<SrcPtr>::cols).
    define_attr("val", &cv::cudev::BrdConstant<SrcPtr>::val).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::BrdConstant<SrcPtr>::*)(int, int) const>("call", &cv::cudev::BrdConstant<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename BrdImpl, typename SrcPtr>
inline void BrdBase_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::BrdBase<BrdImpl, SrcPtr>::src).
    define_attr("rows", &cv::cudev::BrdBase<BrdImpl, SrcPtr>::rows).
    define_attr("cols", &cv::cudev::BrdBase<BrdImpl, SrcPtr>::cols).
    template define_method<int(cv::cudev::BrdBase<BrdImpl, SrcPtr>::*)(int) const>("idx_row", &cv::cudev::BrdBase<BrdImpl, SrcPtr>::idx_row,
      Arg("y")).
    template define_method<int(cv::cudev::BrdBase<BrdImpl, SrcPtr>::*)(int) const>("idx_col", &cv::cudev::BrdBase<BrdImpl, SrcPtr>::idx_col,
      Arg("x")).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::BrdBase<BrdImpl, SrcPtr>::*)(int, int) const>("call", &cv::cudev::BrdBase<BrdImpl, SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

void Init_Cudev_Ptr2d_Extrapolation()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::BrdReplicate> rb_cCvCudevBrdReplicate = define_class_under<cv::cudev::BrdReplicate>(rb_mCvCudev, "BrdReplicate").
    define_constructor(Constructor<cv::cudev::BrdReplicate>()).
    define_singleton_function<int(*)(int, int)>("idx_low", &cv::cudev::BrdReplicate::idx_low,
      Arg("i"), Arg("len")).
    define_singleton_function<int(*)(int, int)>("idx_high", &cv::cudev::BrdReplicate::idx_high,
      Arg("i"), Arg("len"));

  Rice::Data_Type<cv::cudev::BrdReflect101> rb_cCvCudevBrdReflect101 = define_class_under<cv::cudev::BrdReflect101>(rb_mCvCudev, "BrdReflect101").
    define_constructor(Constructor<cv::cudev::BrdReflect101>()).
    define_singleton_function<int(*)(int, int)>("idx_low", &cv::cudev::BrdReflect101::idx_low,
      Arg("i"), Arg("len")).
    define_singleton_function<int(*)(int, int)>("idx_high", &cv::cudev::BrdReflect101::idx_high,
      Arg("i"), Arg("len"));

  Rice::Data_Type<cv::cudev::BrdReflect> rb_cCvCudevBrdReflect = define_class_under<cv::cudev::BrdReflect>(rb_mCvCudev, "BrdReflect").
    define_constructor(Constructor<cv::cudev::BrdReflect>()).
    define_singleton_function<int(*)(int, int)>("idx_low", &cv::cudev::BrdReflect::idx_low,
      Arg("i"), Arg("len")).
    define_singleton_function<int(*)(int, int)>("idx_high", &cv::cudev::BrdReflect::idx_high,
      Arg("i"), Arg("len"));

  Rice::Data_Type<cv::cudev::BrdWrap> rb_cCvCudevBrdWrap = define_class_under<cv::cudev::BrdWrap>(rb_mCvCudev, "BrdWrap").
    define_constructor(Constructor<cv::cudev::BrdWrap>()).
    define_singleton_function<int(*)(int, int)>("idx_low", &cv::cudev::BrdWrap::idx_low,
      Arg("i"), Arg("len")).
    define_singleton_function<int(*)(int, int)>("idx_high", &cv::cudev::BrdWrap::idx_high,
      Arg("i"), Arg("len"));
}