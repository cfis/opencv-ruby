#include <opencv2/cudev/ptr2d/mask.hpp>
#include "mask-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename MaskPtr>
inline void SingleMaskChannels_builder(Data_Type_T& klass)
{
  klass.define_attr("mask", &cv::cudev::SingleMaskChannels<MaskPtr>::mask).
    define_attr("channels", &cv::cudev::SingleMaskChannels<MaskPtr>::channels).
    template define_method<typename cv::cudev::SingleMaskChannels<MaskPtr>::value_type(cv::cudev::SingleMaskChannels<MaskPtr>::*)(typename cv::cudev::SingleMaskChannels<MaskPtr>::index_type, typename cv::cudev::SingleMaskChannels<MaskPtr>::index_type) const>("call", &cv::cudev::SingleMaskChannels<MaskPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename MaskPtr>
inline void SingleMaskChannelsSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::SingleMaskChannelsSz<MaskPtr>::rows).
    define_attr("cols", &cv::cudev::SingleMaskChannelsSz<MaskPtr>::cols);
};

void Init_Cudev_Ptr2d_Mask()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::WithOutMask> rb_cCvCudevWithOutMask = define_class_under<cv::cudev::WithOutMask>(rb_mCvCudev, "WithOutMask").
    define_constructor(Constructor<cv::cudev::WithOutMask>()).
    define_method<bool(cv::cudev::WithOutMask::*)(int, int) const>("call", &cv::cudev::WithOutMask::operator(),
      Arg("arg_0"), Arg("arg_1"));
}