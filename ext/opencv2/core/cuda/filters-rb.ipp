#include <opencv2/core/cuda/filters.hpp>
#include "filters-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Ptr2D>
inline void PointFilter_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::PointFilter<Ptr2D>, const Ptr2D&, float, float>(),
      Arg("src_"), Arg("fx") = static_cast<float>(0.f), Arg("fy") = static_cast<float>(0.f)).
    template define_method<typename cv::cuda::device::PointFilter<Ptr2D>::elem_type(cv::cuda::device::PointFilter<Ptr2D>::*)(float, float) const>("call", &cv::cuda::device::PointFilter<Ptr2D>::operator(),
      Arg("y"), Arg("x")).
    define_attr("src", &cv::cuda::device::PointFilter<Ptr2D>::src);
};

template<typename Data_Type_T, typename Ptr2D>
inline void LinearFilter_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::LinearFilter<Ptr2D>, const Ptr2D&, float, float>(),
      Arg("src_"), Arg("fx") = static_cast<float>(0.f), Arg("fy") = static_cast<float>(0.f)).
    template define_method<typename cv::cuda::device::LinearFilter<Ptr2D>::elem_type(cv::cuda::device::LinearFilter<Ptr2D>::*)(float, float) const>("call", &cv::cuda::device::LinearFilter<Ptr2D>::operator(),
      Arg("y"), Arg("x")).
    define_attr("src", &cv::cuda::device::LinearFilter<Ptr2D>::src);
};

template<typename Data_Type_T, typename Ptr2D>
inline void CubicFilter_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::CubicFilter<Ptr2D>, const Ptr2D&, float, float>(),
      Arg("src_"), Arg("fx") = static_cast<float>(0.f), Arg("fy") = static_cast<float>(0.f)).
    template define_method<typename cv::cuda::device::CubicFilter<Ptr2D>::elem_type(cv::cuda::device::CubicFilter<Ptr2D>::*)(float, float) const>("call", &cv::cuda::device::CubicFilter<Ptr2D>::operator(),
      Arg("y"), Arg("x")).
    define_attr("src", &cv::cuda::device::CubicFilter<Ptr2D>::src).
    template define_singleton_function<float(*)(float)>("bicubic_coeff", &cv::cuda::device::CubicFilter<Ptr2D>::bicubicCoeff,
      Arg("x_"));
};

template<typename Data_Type_T, typename Ptr2D>
inline void IntegerAreaFilter_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::IntegerAreaFilter<Ptr2D>, const Ptr2D&, float, float>(),
      Arg("src_"), Arg("scale_x_"), Arg("scale_y_")).
    template define_method<typename cv::cuda::device::IntegerAreaFilter<Ptr2D>::elem_type(cv::cuda::device::IntegerAreaFilter<Ptr2D>::*)(float, float) const>("call", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::operator(),
      Arg("y"), Arg("x")).
    define_attr("src", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::src).
    define_attr("scale_x", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::scale_x).
    define_attr("scale_y", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::scale_y).
    define_attr("scale", &cv::cuda::device::IntegerAreaFilter<Ptr2D>::scale);
};

template<typename Data_Type_T, typename Ptr2D>
inline void AreaFilter_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cuda::device::AreaFilter<Ptr2D>, const Ptr2D&, float, float>(),
      Arg("src_"), Arg("scale_x_"), Arg("scale_y_")).
    template define_method<typename cv::cuda::device::AreaFilter<Ptr2D>::elem_type(cv::cuda::device::AreaFilter<Ptr2D>::*)(float, float) const>("call", &cv::cuda::device::AreaFilter<Ptr2D>::operator(),
      Arg("y"), Arg("x")).
    define_attr("src", &cv::cuda::device::AreaFilter<Ptr2D>::src).
    define_attr("scale_x", &cv::cuda::device::AreaFilter<Ptr2D>::scale_x).
    define_attr("scale_y", &cv::cuda::device::AreaFilter<Ptr2D>::scale_y).
    define_attr("width", &cv::cuda::device::AreaFilter<Ptr2D>::width).
    define_attr("haight", &cv::cuda::device::AreaFilter<Ptr2D>::haight);
};

