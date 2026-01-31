#include <opencv2/stitching/detail/warpers.hpp>
#include "warpers-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename P>
inline void RotationWarperBase_builder(Data_Type_T& klass)
{
  klass.template define_method<cv::Point2f(cv::detail::RotationWarperBase<P>::*)(const cv::Point2f&, cv::InputArray, cv::InputArray)>("warp_point", &cv::detail::RotationWarperBase<P>::warpPoint,
      Arg("pt"), Arg("k"), Arg("r")).
    template define_method<cv::Point2f(cv::detail::RotationWarperBase<P>::*)(const cv::Point2f&, cv::InputArray, cv::InputArray)>("warp_point_backward", &cv::detail::RotationWarperBase<P>::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("r")).
    template define_method<cv::Rect(cv::detail::RotationWarperBase<P>::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::RotationWarperBase<P>::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    template define_method<cv::Point(cv::detail::RotationWarperBase<P>::*)(cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::RotationWarperBase<P>::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    template define_method<void(cv::detail::RotationWarperBase<P>::*)(cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::Size, cv::OutputArray)>("warp_backward", &cv::detail::RotationWarperBase<P>::warpBackward,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst_size"), Arg("dst")).
    template define_method<cv::Rect(cv::detail::RotationWarperBase<P>::*)(cv::Size, cv::InputArray, cv::InputArray)>("warp_roi", &cv::detail::RotationWarperBase<P>::warpRoi,
      Arg("src_size"), Arg("k"), Arg("r")).
    template define_method<float(cv::detail::RotationWarperBase<P>::*)() const>("get_scale", &cv::detail::RotationWarperBase<P>::getScale).
    template define_method<void(cv::detail::RotationWarperBase<P>::*)(float)>("set_scale", &cv::detail::RotationWarperBase<P>::setScale,
      Arg("val"));
};

