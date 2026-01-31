#include <opencv2/cudev/functional/detail/color_cvt.hpp>
#include "color_cvt-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void ColorChannel_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<T(*)()>("max", &cv::cudev::color_cvt_detail::ColorChannel<T>::max).
    template define_singleton_function<T(*)()>("half", &cv::cudev::color_cvt_detail::ColorChannel<T>::half);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::RGB2RGB<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::RGB2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T, int dcn>
inline void Gray2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::Gray2RGB<T, dcn>::*)(T) const>("call", &cv::cudev::color_cvt_detail::Gray2RGB<T, dcn>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T, int scn, int bidx>
inline void RGB2Gray_builder(Data_Type_T& klass)
{
  klass.template define_method<T(cv::cudev::color_cvt_detail::RGB2Gray<T, scn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::RGB2Gray<T, scn, bidx>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2YUV_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::RGB2YUV<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::RGB2YUV<T, scn, dcn, bidx>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void YUV2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::YUV2RGB<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::YUV2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2YCrCb_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::RGB2YCrCb<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::RGB2YCrCb<T, scn, dcn, bidx>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void YCrCb2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::YCrCb2RGB<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::YCrCb2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2XYZ_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::RGB2XYZ<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::RGB2XYZ<T, scn, dcn, bidx>::operator(),
      Arg("src"));
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void XYZ2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<typename MakeVec<T, dcn>::type(cv::cudev::color_cvt_detail::XYZ2RGB<T, scn, dcn, bidx>::*)(const typename MakeVec<T, scn>::type&) const>("call", &cv::cudev::color_cvt_detail::XYZ2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src"));
};

