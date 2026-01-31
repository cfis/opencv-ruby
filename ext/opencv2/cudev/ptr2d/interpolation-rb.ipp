#include <opencv2/cudev/ptr2d/interpolation.hpp>
#include "interpolation-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename SrcPtr>
inline void NearestInterPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::NearestInterPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::NearestInterPtr<SrcPtr>::*)(float, float) const>("call", &cv::cudev::NearestInterPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr>
inline void NearestInterPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::NearestInterPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::NearestInterPtrSz<SrcPtr>::cols);
};

template<typename Data_Type_T, typename SrcPtr>
inline void LinearInterPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::LinearInterPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::LinearInterPtr<SrcPtr>::*)(float, float) const>("call", &cv::cudev::LinearInterPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr>
inline void LinearInterPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::LinearInterPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::LinearInterPtrSz<SrcPtr>::cols);
};

template<typename Data_Type_T, typename SrcPtr>
inline void CubicInterPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::CubicInterPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::CubicInterPtr<SrcPtr>::*)(float, float) const>("call", &cv::cudev::CubicInterPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x")).
    template define_singleton_function<float(*)(float)>("bicubic_coeff", &cv::cudev::CubicInterPtr<SrcPtr>::bicubicCoeff,
      Arg("x_"));
};

template<typename Data_Type_T, typename SrcPtr>
inline void CubicInterPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::CubicInterPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::CubicInterPtrSz<SrcPtr>::cols);
};

template<typename Data_Type_T, typename SrcPtr>
inline void IntegerAreaInterPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::IntegerAreaInterPtr<SrcPtr>::src).
    define_attr("area_width", &cv::cudev::IntegerAreaInterPtr<SrcPtr>::area_width).
    define_attr("area_height", &cv::cudev::IntegerAreaInterPtr<SrcPtr>::area_height).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::IntegerAreaInterPtr<SrcPtr>::*)(float, float) const>("call", &cv::cudev::IntegerAreaInterPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr>
inline void IntegerAreaInterPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::IntegerAreaInterPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::IntegerAreaInterPtrSz<SrcPtr>::cols);
};

template<typename Data_Type_T, typename SrcPtr>
inline void CommonAreaInterPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::CommonAreaInterPtr<SrcPtr>::src).
    define_attr("area_width", &cv::cudev::CommonAreaInterPtr<SrcPtr>::area_width).
    define_attr("area_height", &cv::cudev::CommonAreaInterPtr<SrcPtr>::area_height).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::CommonAreaInterPtr<SrcPtr>::*)(float, float) const>("call", &cv::cudev::CommonAreaInterPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr>
inline void CommonAreaInterPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::CommonAreaInterPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::CommonAreaInterPtrSz<SrcPtr>::cols);
};

