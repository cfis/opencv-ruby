#include <opencv2/stitching/detail/warpers.hpp>
#include "../../core/cvstd_wrapper-rb.hpp"
#include "warpers-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDetailAffineWarper;
Rice::Class rb_cCvDetailCompressedRectilinearPortraitProjector;
Rice::Class rb_cCvDetailCompressedRectilinearPortraitWarper;
Rice::Class rb_cCvDetailCompressedRectilinearProjector;
Rice::Class rb_cCvDetailCompressedRectilinearWarper;
Rice::Class rb_cCvDetailCylindricalPortraitProjector;
Rice::Class rb_cCvDetailCylindricalPortraitWarper;
Rice::Class rb_cCvDetailCylindricalProjector;
Rice::Class rb_cCvDetailCylindricalWarper;
Rice::Class rb_cCvDetailCylindricalWarperGpu;
Rice::Class rb_cCvDetailFisheyeProjector;
Rice::Class rb_cCvDetailFisheyeWarper;
Rice::Class rb_cCvDetailMercatorProjector;
Rice::Class rb_cCvDetailMercatorWarper;
Rice::Class rb_cCvDetailPaniniPortraitProjector;
Rice::Class rb_cCvDetailPaniniPortraitWarper;
Rice::Class rb_cCvDetailPaniniProjector;
Rice::Class rb_cCvDetailPaniniWarper;
Rice::Class rb_cCvDetailPlanePortraitProjector;
Rice::Class rb_cCvDetailPlanePortraitWarper;
Rice::Class rb_cCvDetailPlaneProjector;
Rice::Class rb_cCvDetailPlaneWarper;
Rice::Class rb_cCvDetailPlaneWarperGpu;
Rice::Class rb_cCvDetailProjectorBase;
Rice::Class rb_cCvDetailRotationWarper;
Rice::Class rb_cCvDetailRotationWarperBaseCompressedRectilinearProjector;
Rice::Class rb_cCvDetailRotationWarperBaseCompressedRectilinearPortraitProjector;
Rice::Class rb_cCvDetailRotationWarperBaseCylindricalPortraitProjector;
Rice::Class rb_cCvDetailRotationWarperBaseCylindricalProjector;
Rice::Class rb_cCvDetailRotationWarperBaseFisheyeProjector;
Rice::Class rb_cCvDetailRotationWarperBaseMercatorProjector;
Rice::Class rb_cCvDetailRotationWarperBasePaniniProjector;
Rice::Class rb_cCvDetailRotationWarperBasePaniniPortraitProjector;
Rice::Class rb_cCvDetailRotationWarperBasePlanePortraitProjector;
Rice::Class rb_cCvDetailRotationWarperBasePlaneProjector;
Rice::Class rb_cCvDetailRotationWarperBaseSphericalPortraitProjector;
Rice::Class rb_cCvDetailRotationWarperBaseSphericalProjector;
Rice::Class rb_cCvDetailRotationWarperBaseStereographicProjector;
Rice::Class rb_cCvDetailRotationWarperBaseTransverseMercatorProjector;
Rice::Class rb_cCvDetailSphericalPortraitProjector;
Rice::Class rb_cCvDetailSphericalPortraitWarper;
Rice::Class rb_cCvDetailSphericalProjector;
Rice::Class rb_cCvDetailSphericalWarper;
Rice::Class rb_cCvDetailSphericalWarperGpu;
Rice::Class rb_cCvDetailStereographicProjector;
Rice::Class rb_cCvDetailStereographicWarper;
Rice::Class rb_cCvDetailTransverseMercatorProjector;
Rice::Class rb_cCvDetailTransverseMercatorWarper;

template<typename Data_Type_T, typename P>
inline void RotationWarperBase_builder(Data_Type_T& klass)
{
  klass.define_method("warp_point", &cv::detail::RotationWarperBase<P>::warpPoint,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method("warp_point_backward", &cv::detail::RotationWarperBase<P>::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method("build_maps", &cv::detail::RotationWarperBase<P>::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method("warp", &cv::detail::RotationWarperBase<P>::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method("warp_backward", &cv::detail::RotationWarperBase<P>::warpBackward,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst_size"), Arg("dst")).
    define_method("warp_roi", &cv::detail::RotationWarperBase<P>::warpRoi,
      Arg("src_size"), Arg("k"), Arg("r")).
    define_method("get_scale", &cv::detail::RotationWarperBase<P>::getScale).
    define_method("set_scale", &cv::detail::RotationWarperBase<P>::setScale,
      Arg("val"));
};

void Init_Detail_Warpers()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  rb_cCvDetailRotationWarper = define_class_under<cv::detail::RotationWarper>(rb_mCvDetail, "RotationWarper").
    define_method("warp_point", &cv::detail::RotationWarper::warpPoint,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method("warp_point_backward", &cv::detail::RotationWarper::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method("build_maps", &cv::detail::RotationWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method("warp", &cv::detail::RotationWarper::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method("warp_backward", &cv::detail::RotationWarper::warpBackward,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst_size"), Arg("dst")).
    define_method("warp_roi", &cv::detail::RotationWarper::warpRoi,
      Arg("src_size"), Arg("k"), Arg("r")).
    define_method("get_scale", &cv::detail::RotationWarper::getScale).
    define_method("set_scale", &cv::detail::RotationWarper::setScale,
      Arg(""));
  
  rb_cCvDetailProjectorBase = define_class_under<cv::detail::ProjectorBase>(rb_mCvDetail, "ProjectorBase").
    define_constructor(Constructor<cv::detail::ProjectorBase>()).
    define_method("set_camera_params", &cv::detail::ProjectorBase::setCameraParams,
      Arg("k") = static_cast<cv::InputArray>(cv::Mat::eye(3, 3, CV_32F)), Arg("r") = static_cast<cv::InputArray>(cv::Mat::eye(3, 3, CV_32F)), Arg("t") = static_cast<cv::InputArray>(cv::Mat::zeros(3, 1, CV_32F))).
    define_attr("scale", &cv::detail::ProjectorBase::scale);
  
  rb_cCvDetailPlaneProjector = define_class_under<cv::detail::PlaneProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "PlaneProjector").
    define_constructor(Constructor<cv::detail::PlaneProjector>()).
    define_method("map_forward", &cv::detail::PlaneProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::PlaneProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));

  rb_cCvDetailRotationWarperBasePlaneProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::PlaneProjector>>(rb_mCvDetail, "RotationWarperBasePlaneProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::PlaneProjector>>, cv::detail::PlaneProjector>);
  
  rb_cCvDetailPlaneWarper = define_class_under<cv::detail::PlaneWarper, cv::detail::RotationWarperBase<cv::detail::PlaneProjector>>(rb_mCvDetail, "PlaneWarper").
    define_constructor(Constructor<cv::detail::PlaneWarper, float>(),
      Arg("scale") = static_cast<float>(1.f)).
    define_method<cv::Point2f(cv::detail::PlaneWarper::*)(const cv::Point2f&, cv::InputArray, cv::InputArray)>("warp_point", &cv::detail::PlaneWarper::warpPoint,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method<cv::Point2f(cv::detail::PlaneWarper::*)(const cv::Point2f&, cv::InputArray, cv::InputArray, cv::InputArray)>("warp_point", &cv::detail::PlaneWarper::warpPoint,
      Arg("pt"), Arg("k"), Arg("r"), Arg("t")).
    define_method<cv::Point2f(cv::detail::PlaneWarper::*)(const cv::Point2f&, cv::InputArray, cv::InputArray)>("warp_point_backward", &cv::detail::PlaneWarper::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method<cv::Point2f(cv::detail::PlaneWarper::*)(const cv::Point2f&, cv::InputArray, cv::InputArray, cv::InputArray)>("warp_point_backward", &cv::detail::PlaneWarper::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("r"), Arg("t")).
    define_method<cv::Rect(cv::detail::PlaneWarper::*)(cv::Size, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::PlaneWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("t"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Rect(cv::detail::PlaneWarper::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::PlaneWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::PlaneWarper::*)(cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::PlaneWarper::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Point(cv::detail::PlaneWarper::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::PlaneWarper::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("t"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Rect(cv::detail::PlaneWarper::*)(cv::Size, cv::InputArray, cv::InputArray)>("warp_roi", &cv::detail::PlaneWarper::warpRoi,
      Arg("src_size"), Arg("k"), Arg("r")).
    define_method<cv::Rect(cv::detail::PlaneWarper::*)(cv::Size, cv::InputArray, cv::InputArray, cv::InputArray)>("warp_roi", &cv::detail::PlaneWarper::warpRoi,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("t"));
  
  rb_cCvDetailAffineWarper = define_class_under<cv::detail::AffineWarper, cv::detail::PlaneWarper>(rb_mCvDetail, "AffineWarper").
    define_constructor(Constructor<cv::detail::AffineWarper, float>(),
      Arg("scale") = static_cast<float>(1.f)).
    define_method("warp_point", &cv::detail::AffineWarper::warpPoint,
      Arg("pt"), Arg("k"), Arg("h")).
    define_method("warp_point_backward", &cv::detail::AffineWarper::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("h")).
    define_method("build_maps", &cv::detail::AffineWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("h"), Arg("xmap"), Arg("ymap")).
    define_method("warp", &cv::detail::AffineWarper::warp,
      Arg("src"), Arg("k"), Arg("h"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method("warp_roi", &cv::detail::AffineWarper::warpRoi,
      Arg("src_size"), Arg("k"), Arg("h"));
  
  rb_cCvDetailSphericalProjector = define_class_under<cv::detail::SphericalProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "SphericalProjector").
    define_constructor(Constructor<cv::detail::SphericalProjector>()).
    define_method("map_forward", &cv::detail::SphericalProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::SphericalProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBaseSphericalProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::SphericalProjector>>(rb_mCvDetail, "RotationWarperBaseSphericalProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::SphericalProjector>>, cv::detail::SphericalProjector>);

  rb_cCvDetailSphericalWarper = define_class_under<cv::detail::SphericalWarper, cv::detail::RotationWarperBase<cv::detail::SphericalProjector>>(rb_mCvDetail, "SphericalWarper").
    define_constructor(Constructor<cv::detail::SphericalWarper, float>(),
      Arg("scale")).
    define_method("build_maps", &cv::detail::SphericalWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method("warp", &cv::detail::SphericalWarper::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst"));
  
  rb_cCvDetailCylindricalProjector = define_class_under<cv::detail::CylindricalProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "CylindricalProjector").
    define_constructor(Constructor<cv::detail::CylindricalProjector>()).
    define_method("map_forward", &cv::detail::CylindricalProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::CylindricalProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBaseCylindricalProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::CylindricalProjector>>(rb_mCvDetail, "RotationWarperBaseCylindricalProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::CylindricalProjector>>, cv::detail::SphericalProjector>);

  rb_cCvDetailCylindricalWarper = define_class_under<cv::detail::CylindricalWarper, cv::detail::RotationWarperBase<cv::detail::CylindricalProjector>>(rb_mCvDetail, "CylindricalWarper").
    define_constructor(Constructor<cv::detail::CylindricalWarper, float>(),
      Arg("scale")).
    define_method("build_maps", &cv::detail::CylindricalWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method("warp", &cv::detail::CylindricalWarper::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst"));
  
  rb_cCvDetailFisheyeProjector = define_class_under<cv::detail::FisheyeProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "FisheyeProjector").
    define_constructor(Constructor<cv::detail::FisheyeProjector>()).
    define_method("map_forward", &cv::detail::FisheyeProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::FisheyeProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBaseFisheyeProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::FisheyeProjector>>(rb_mCvDetail, "RotationWarperBaseFisheyeProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::FisheyeProjector>>, cv::detail::FisheyeProjector>);

  rb_cCvDetailFisheyeWarper = define_class_under<cv::detail::FisheyeWarper, cv::detail::RotationWarperBase<cv::detail::FisheyeProjector>>(rb_mCvDetail, "FisheyeWarper").
    define_constructor(Constructor<cv::detail::FisheyeWarper, float>(),
      Arg("scale"));
  
  rb_cCvDetailStereographicProjector = define_class_under<cv::detail::StereographicProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "StereographicProjector").
    define_constructor(Constructor<cv::detail::StereographicProjector>()).
    define_method("map_forward", &cv::detail::StereographicProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::StereographicProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBaseStereographicProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::StereographicProjector>>(rb_mCvDetail, "RotationWarperBaseStereographicProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::StereographicProjector>>, cv::detail::StereographicProjector>);

  rb_cCvDetailStereographicWarper = define_class_under<cv::detail::StereographicWarper, cv::detail::RotationWarperBase<cv::detail::StereographicProjector>>(rb_mCvDetail, "StereographicWarper").
    define_constructor(Constructor<cv::detail::StereographicWarper, float>(),
      Arg("scale"));
  
  rb_cCvDetailCompressedRectilinearProjector = define_class_under<cv::detail::CompressedRectilinearProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "CompressedRectilinearProjector").
    define_constructor(Constructor<cv::detail::CompressedRectilinearProjector>()).
    define_attr("a", &cv::detail::CompressedRectilinearProjector::a).
    define_attr("b", &cv::detail::CompressedRectilinearProjector::b).
    define_method("map_forward", &cv::detail::CompressedRectilinearProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::CompressedRectilinearProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBaseCompressedRectilinearProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::CompressedRectilinearProjector>>(rb_mCvDetail, "RotationWarperBaseCompressedRectilinearProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::CompressedRectilinearProjector>>, cv::detail::CompressedRectilinearProjector>);

  rb_cCvDetailCompressedRectilinearWarper = define_class_under<cv::detail::CompressedRectilinearWarper, cv::detail::RotationWarperBase<cv::detail::CompressedRectilinearProjector>>(rb_mCvDetail, "CompressedRectilinearWarper").
    define_constructor(Constructor<cv::detail::CompressedRectilinearWarper, float, float, float>(),
      Arg("scale"), Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1));
  
  rb_cCvDetailCompressedRectilinearPortraitProjector = define_class_under<cv::detail::CompressedRectilinearPortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "CompressedRectilinearPortraitProjector").
    define_constructor(Constructor<cv::detail::CompressedRectilinearPortraitProjector>()).
    define_attr("a", &cv::detail::CompressedRectilinearPortraitProjector::a).
    define_attr("b", &cv::detail::CompressedRectilinearPortraitProjector::b).
    define_method("map_forward", &cv::detail::CompressedRectilinearPortraitProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::CompressedRectilinearPortraitProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBaseCompressedRectilinearPortraitProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::CompressedRectilinearPortraitProjector>>(rb_mCvDetail, "RotationWarperBaseCompressedRectilinearPortraitProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::CompressedRectilinearPortraitProjector>>, cv::detail::CompressedRectilinearPortraitProjector>);

  rb_cCvDetailCompressedRectilinearPortraitWarper = define_class_under<cv::detail::CompressedRectilinearPortraitWarper, cv::detail::RotationWarperBase<cv::detail::CompressedRectilinearPortraitProjector>>(rb_mCvDetail, "CompressedRectilinearPortraitWarper").
    define_constructor(Constructor<cv::detail::CompressedRectilinearPortraitWarper, float, float, float>(),
      Arg("scale"), Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1));
  
  rb_cCvDetailPaniniProjector = define_class_under<cv::detail::PaniniProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "PaniniProjector").
    define_constructor(Constructor<cv::detail::PaniniProjector>()).
    define_attr("a", &cv::detail::PaniniProjector::a).
    define_attr("b", &cv::detail::PaniniProjector::b).
    define_method("map_forward", &cv::detail::PaniniProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::PaniniProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBasePaniniProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::PaniniProjector>>(rb_mCvDetail, "RotationWarperBasePaniniProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::PaniniProjector>>, cv::detail::PaniniProjector>);

  rb_cCvDetailPaniniWarper = define_class_under<cv::detail::PaniniWarper, cv::detail::RotationWarperBase<cv::detail::PaniniProjector>>(rb_mCvDetail, "PaniniWarper").
    define_constructor(Constructor<cv::detail::PaniniWarper, float, float, float>(),
      Arg("scale"), Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1));
  
  rb_cCvDetailPaniniPortraitProjector = define_class_under<cv::detail::PaniniPortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "PaniniPortraitProjector").
    define_constructor(Constructor<cv::detail::PaniniPortraitProjector>()).
    define_attr("a", &cv::detail::PaniniPortraitProjector::a).
    define_attr("b", &cv::detail::PaniniPortraitProjector::b).
    define_method("map_forward", &cv::detail::PaniniPortraitProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::PaniniPortraitProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBasePaniniPortraitProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::PaniniPortraitProjector>>(rb_mCvDetail, "RotationWarperBasePaniniPortraitProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::PaniniPortraitProjector>>, cv::detail::PaniniPortraitProjector>);

  rb_cCvDetailPaniniPortraitWarper = define_class_under<cv::detail::PaniniPortraitWarper, cv::detail::RotationWarperBase<cv::detail::PaniniPortraitProjector>>(rb_mCvDetail, "PaniniPortraitWarper").
    define_constructor(Constructor<cv::detail::PaniniPortraitWarper, float, float, float>(),
      Arg("scale"), Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1));
  
  rb_cCvDetailMercatorProjector = define_class_under<cv::detail::MercatorProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "MercatorProjector").
    define_constructor(Constructor<cv::detail::MercatorProjector>()).
    define_method("map_forward", &cv::detail::MercatorProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::MercatorProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBaseMercatorProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::MercatorProjector>>(rb_mCvDetail, "RotationWarperBaseMercatorProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::MercatorProjector>>, cv::detail::MercatorProjector>);

  rb_cCvDetailMercatorWarper = define_class_under<cv::detail::MercatorWarper, cv::detail::RotationWarperBase<cv::detail::MercatorProjector>>(rb_mCvDetail, "MercatorWarper").
    define_constructor(Constructor<cv::detail::MercatorWarper, float>(),
      Arg("scale"));
  
  rb_cCvDetailTransverseMercatorProjector = define_class_under<cv::detail::TransverseMercatorProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "TransverseMercatorProjector").
    define_constructor(Constructor<cv::detail::TransverseMercatorProjector>()).
    define_method("map_forward", &cv::detail::TransverseMercatorProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::TransverseMercatorProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBaseTransverseMercatorProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::TransverseMercatorProjector>>(rb_mCvDetail, "RotationWarperBaseTransverseMercatorProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::TransverseMercatorProjector>>, cv::detail::TransverseMercatorProjector>);

  rb_cCvDetailTransverseMercatorWarper = define_class_under<cv::detail::TransverseMercatorWarper, cv::detail::RotationWarperBase<cv::detail::TransverseMercatorProjector>>(rb_mCvDetail, "TransverseMercatorWarper").
    define_constructor(Constructor<cv::detail::TransverseMercatorWarper, float>(),
      Arg("scale"));
  
  rb_cCvDetailPlaneWarperGpu = define_class_under<cv::detail::PlaneWarperGpu, cv::detail::PlaneWarper>(rb_mCvDetail, "PlaneWarperGpu").
    define_constructor(Constructor<cv::detail::PlaneWarperGpu, float>(),
      Arg("scale") = static_cast<float>(1.f)).
    define_method<cv::Rect(cv::detail::PlaneWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::PlaneWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Rect(cv::detail::PlaneWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::PlaneWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("t"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::PlaneWarperGpu::*)(cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::PlaneWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Point(cv::detail::PlaneWarperGpu::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::PlaneWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("t"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Rect(cv::detail::PlaneWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("build_maps", &cv::detail::PlaneWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Rect(cv::detail::PlaneWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::InputArray, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("build_maps", &cv::detail::PlaneWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("t"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::PlaneWarperGpu::*)(const cv::cuda::GpuMat&, cv::InputArray, cv::InputArray, int, int, cv::cuda::GpuMat&)>("warp", &cv::detail::PlaneWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Point(cv::detail::PlaneWarperGpu::*)(const cv::cuda::GpuMat&, cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::cuda::GpuMat&)>("warp", &cv::detail::PlaneWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("t"), Arg("interp_mode"), Arg("border_mode"), Arg("dst"));
  
  rb_cCvDetailSphericalWarperGpu = define_class_under<cv::detail::SphericalWarperGpu, cv::detail::SphericalWarper>(rb_mCvDetail, "SphericalWarperGpu").
    define_constructor(Constructor<cv::detail::SphericalWarperGpu, float>(),
      Arg("scale")).
    define_method<cv::Rect(cv::detail::SphericalWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::SphericalWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::SphericalWarperGpu::*)(cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::SphericalWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Rect(cv::detail::SphericalWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("build_maps", &cv::detail::SphericalWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::SphericalWarperGpu::*)(const cv::cuda::GpuMat&, cv::InputArray, cv::InputArray, int, int, cv::cuda::GpuMat&)>("warp", &cv::detail::SphericalWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst"));
  
  rb_cCvDetailCylindricalWarperGpu = define_class_under<cv::detail::CylindricalWarperGpu, cv::detail::CylindricalWarper>(rb_mCvDetail, "CylindricalWarperGpu").
    define_constructor(Constructor<cv::detail::CylindricalWarperGpu, float>(),
      Arg("scale")).
    define_method<cv::Rect(cv::detail::CylindricalWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::CylindricalWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::CylindricalWarperGpu::*)(cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::CylindricalWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Rect(cv::detail::CylindricalWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("build_maps", &cv::detail::CylindricalWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::CylindricalWarperGpu::*)(const cv::cuda::GpuMat&, cv::InputArray, cv::InputArray, int, int, cv::cuda::GpuMat&)>("warp", &cv::detail::CylindricalWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst"));
  
  rb_cCvDetailSphericalPortraitProjector = define_class_under<cv::detail::SphericalPortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "SphericalPortraitProjector").
    define_constructor(Constructor<cv::detail::SphericalPortraitProjector>()).
    define_method("map_forward", &cv::detail::SphericalPortraitProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::SphericalPortraitProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBaseSphericalPortraitProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::SphericalPortraitProjector>>(rb_mCvDetail, "RotationWarperBaseSphericalPortraitProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::SphericalPortraitProjector>>, cv::detail::SphericalPortraitProjector>);

  rb_cCvDetailSphericalPortraitWarper = define_class_under<cv::detail::SphericalPortraitWarper, cv::detail::RotationWarperBase<cv::detail::SphericalPortraitProjector>>(rb_mCvDetail, "SphericalPortraitWarper").
    define_constructor(Constructor<cv::detail::SphericalPortraitWarper, float>(),
      Arg("scale"));
  
  rb_cCvDetailCylindricalPortraitProjector = define_class_under<cv::detail::CylindricalPortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "CylindricalPortraitProjector").
    define_constructor(Constructor<cv::detail::CylindricalPortraitProjector>()).
    define_method("map_forward", &cv::detail::CylindricalPortraitProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::CylindricalPortraitProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBaseCylindricalPortraitProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::CylindricalPortraitProjector>>(rb_mCvDetail, "RotationWarperBaseCylindricalPortraitProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::CylindricalPortraitProjector>>, cv::detail::CylindricalPortraitProjector>);

  rb_cCvDetailCylindricalPortraitWarper = define_class_under<cv::detail::CylindricalPortraitWarper, cv::detail::RotationWarperBase<cv::detail::CylindricalPortraitProjector>>(rb_mCvDetail, "CylindricalPortraitWarper").
    define_constructor(Constructor<cv::detail::CylindricalPortraitWarper, float>(),
      Arg("scale"));
  
  rb_cCvDetailPlanePortraitProjector = define_class_under<cv::detail::PlanePortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "PlanePortraitProjector").
    define_constructor(Constructor<cv::detail::PlanePortraitProjector>()).
    define_method("map_forward", &cv::detail::PlanePortraitProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::PlanePortraitProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  rb_cCvDetailRotationWarperBasePlanePortraitProjector = define_class_under<cv::detail::RotationWarperBase<cv::detail::PlanePortraitProjector>>(rb_mCvDetail, "RotationWarperBasePlanePortraitProjector").
    define(&RotationWarperBase_builder<Data_Type<cv::detail::RotationWarperBase<cv::detail::PlanePortraitProjector>>, cv::detail::PlanePortraitProjector>);

  rb_cCvDetailPlanePortraitWarper = define_class_under<cv::detail::PlanePortraitWarper, cv::detail::RotationWarperBase<cv::detail::PlanePortraitProjector>>(rb_mCvDetail, "PlanePortraitWarper").
    define_constructor(Constructor<cv::detail::PlanePortraitWarper, float>(),
      Arg("scale"));
}