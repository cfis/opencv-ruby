#include <opencv2/stitching/warpers.hpp>
#include "warpers-rb.hpp"

using namespace Rice;

void Init_Stitching_Warpers()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::PyRotationWarper> rb_cCvPyRotationWarper = define_class_under<cv::PyRotationWarper>(rb_mCv, "PyRotationWarper").
    define_constructor(Constructor<cv::PyRotationWarper, cv::String, float>(),
      Arg("type"), Arg("scale")).
    define_constructor(Constructor<cv::PyRotationWarper>()).
    define_method<cv::Point2f(cv::PyRotationWarper::*)(const cv::Point2f&, cv::InputArray, cv::InputArray)>("warp_point", &cv::PyRotationWarper::warpPoint,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method<cv::Point2f(cv::PyRotationWarper::*)(const cv::Point2f&, cv::InputArray, cv::InputArray)>("warp_point_backward", &cv::PyRotationWarper::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method<cv::Rect(cv::PyRotationWarper::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::PyRotationWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::PyRotationWarper::*)(cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::PyRotationWarper::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<void(cv::PyRotationWarper::*)(cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::Size, cv::OutputArray)>("warp_backward", &cv::PyRotationWarper::warpBackward,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst_size"), Arg("dst")).
    define_method<cv::Rect(cv::PyRotationWarper::*)(cv::Size, cv::InputArray, cv::InputArray)>("warp_roi", &cv::PyRotationWarper::warpRoi,
      Arg("src_size"), Arg("k"), Arg("r")).
    define_method<float(cv::PyRotationWarper::*)() const>("get_scale", &cv::PyRotationWarper::getScale).
    define_method<void(cv::PyRotationWarper::*)(float)>("set_scale", &cv::PyRotationWarper::setScale,
      Arg("arg_0"));

  Rice::Data_Type<cv::WarperCreator> rb_cCvWarperCreator = define_class_under<cv::WarperCreator>(rb_mCv, "WarperCreator").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::WarperCreator::*)(float) const>("create", &cv::WarperCreator::create,
      Arg("scale"));

  Rice::Data_Type<cv::PlaneWarper> rb_cCvPlaneWarper = define_class_under<cv::PlaneWarper, cv::WarperCreator>(rb_mCv, "PlaneWarper").
    define_constructor(Constructor<cv::PlaneWarper>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::PlaneWarper::*)(float) const>("create", &cv::PlaneWarper::create,
      Arg("scale"));

  Rice::Data_Type<cv::AffineWarper> rb_cCvAffineWarper = define_class_under<cv::AffineWarper, cv::WarperCreator>(rb_mCv, "AffineWarper").
    define_constructor(Constructor<cv::AffineWarper>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::AffineWarper::*)(float) const>("create", &cv::AffineWarper::create,
      Arg("scale"));

  Rice::Data_Type<cv::CylindricalWarper> rb_cCvCylindricalWarper = define_class_under<cv::CylindricalWarper, cv::WarperCreator>(rb_mCv, "CylindricalWarper").
    define_constructor(Constructor<cv::CylindricalWarper>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::CylindricalWarper::*)(float) const>("create", &cv::CylindricalWarper::create,
      Arg("scale"));

  Rice::Data_Type<cv::SphericalWarper> rb_cCvSphericalWarper = define_class_under<cv::SphericalWarper, cv::WarperCreator>(rb_mCv, "SphericalWarper").
    define_constructor(Constructor<cv::SphericalWarper>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::SphericalWarper::*)(float) const>("create", &cv::SphericalWarper::create,
      Arg("scale"));

  Rice::Data_Type<cv::FisheyeWarper> rb_cCvFisheyeWarper = define_class_under<cv::FisheyeWarper, cv::WarperCreator>(rb_mCv, "FisheyeWarper").
    define_constructor(Constructor<cv::FisheyeWarper>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::FisheyeWarper::*)(float) const>("create", &cv::FisheyeWarper::create,
      Arg("scale"));

  Rice::Data_Type<cv::StereographicWarper> rb_cCvStereographicWarper = define_class_under<cv::StereographicWarper, cv::WarperCreator>(rb_mCv, "StereographicWarper").
    define_constructor(Constructor<cv::StereographicWarper>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::StereographicWarper::*)(float) const>("create", &cv::StereographicWarper::create,
      Arg("scale"));

  Rice::Data_Type<cv::CompressedRectilinearWarper> rb_cCvCompressedRectilinearWarper = define_class_under<cv::CompressedRectilinearWarper, cv::WarperCreator>(rb_mCv, "CompressedRectilinearWarper").
    define_constructor(Constructor<cv::CompressedRectilinearWarper, float, float>(),
      Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1)).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::CompressedRectilinearWarper::*)(float) const>("create", &cv::CompressedRectilinearWarper::create,
      Arg("scale"));

  Rice::Data_Type<cv::CompressedRectilinearPortraitWarper> rb_cCvCompressedRectilinearPortraitWarper = define_class_under<cv::CompressedRectilinearPortraitWarper, cv::WarperCreator>(rb_mCv, "CompressedRectilinearPortraitWarper").
    define_constructor(Constructor<cv::CompressedRectilinearPortraitWarper, float, float>(),
      Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1)).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::CompressedRectilinearPortraitWarper::*)(float) const>("create", &cv::CompressedRectilinearPortraitWarper::create,
      Arg("scale"));

  Rice::Data_Type<cv::PaniniWarper> rb_cCvPaniniWarper = define_class_under<cv::PaniniWarper, cv::WarperCreator>(rb_mCv, "PaniniWarper").
    define_constructor(Constructor<cv::PaniniWarper, float, float>(),
      Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1)).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::PaniniWarper::*)(float) const>("create", &cv::PaniniWarper::create,
      Arg("scale"));

  Rice::Data_Type<cv::PaniniPortraitWarper> rb_cCvPaniniPortraitWarper = define_class_under<cv::PaniniPortraitWarper, cv::WarperCreator>(rb_mCv, "PaniniPortraitWarper").
    define_constructor(Constructor<cv::PaniniPortraitWarper, float, float>(),
      Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1)).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::PaniniPortraitWarper::*)(float) const>("create", &cv::PaniniPortraitWarper::create,
      Arg("scale"));

  Rice::Data_Type<cv::MercatorWarper> rb_cCvMercatorWarper = define_class_under<cv::MercatorWarper, cv::WarperCreator>(rb_mCv, "MercatorWarper").
    define_constructor(Constructor<cv::MercatorWarper>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::MercatorWarper::*)(float) const>("create", &cv::MercatorWarper::create,
      Arg("scale"));

  Rice::Data_Type<cv::TransverseMercatorWarper> rb_cCvTransverseMercatorWarper = define_class_under<cv::TransverseMercatorWarper, cv::WarperCreator>(rb_mCv, "TransverseMercatorWarper").
    define_constructor(Constructor<cv::TransverseMercatorWarper>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::TransverseMercatorWarper::*)(float) const>("create", &cv::TransverseMercatorWarper::create,
      Arg("scale"));

  Rice::Data_Type<cv::PlaneWarperGpu> rb_cCvPlaneWarperGpu = define_class_under<cv::PlaneWarperGpu, cv::WarperCreator>(rb_mCv, "PlaneWarperGpu").
    define_constructor(Constructor<cv::PlaneWarperGpu>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::PlaneWarperGpu::*)(float) const>("create", &cv::PlaneWarperGpu::create,
      Arg("scale"));

  Rice::Data_Type<cv::CylindricalWarperGpu> rb_cCvCylindricalWarperGpu = define_class_under<cv::CylindricalWarperGpu, cv::WarperCreator>(rb_mCv, "CylindricalWarperGpu").
    define_constructor(Constructor<cv::CylindricalWarperGpu>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::CylindricalWarperGpu::*)(float) const>("create", &cv::CylindricalWarperGpu::create,
      Arg("scale"));

  Rice::Data_Type<cv::SphericalWarperGpu> rb_cCvSphericalWarperGpu = define_class_under<cv::SphericalWarperGpu, cv::WarperCreator>(rb_mCv, "SphericalWarperGpu").
    define_constructor(Constructor<cv::SphericalWarperGpu>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::SphericalWarperGpu::*)(float) const>("create", &cv::SphericalWarperGpu::create,
      Arg("scale"));
}
