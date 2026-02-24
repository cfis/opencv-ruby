#include <opencv2/core/types.hpp>
#include "types-rb.hpp"

using namespace Rice;

#include "matx-rb.ipp"
#include "types-rb.ipp"

void Init_Core_Types()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::Complex<float>> rb_cComplexf = Complex_instantiate<float>(rb_mCv, "Complexf");

  Rice::Data_Type<cv::Complex<double>> rb_cComplexd = Complex_instantiate<double>(rb_mCv, "Complexd");

  Module rb_mCvTraits = define_module_under(rb_mCv, "Traits");

  Rice::Data_Type<cv::Point_<int>> rb_cPoint2i = Point__instantiate<int>(rb_mCv, "Point2i");

  Rice::Data_Type<cv::Point_<int64>> rb_cPoint2l = Point__instantiate<int64>(rb_mCv, "Point2l"); // Manual fix: use int64 instead of long

  Rice::Data_Type<cv::Point_<float>> rb_cPoint2f = Point__instantiate<float>(rb_mCv, "Point2f");

  Rice::Data_Type<cv::Point_<double>> rb_cPoint2d = Point__instantiate<double>(rb_mCv, "Point2d");

  Rice::Data_Type<cv::Point_<int>> rb_cPoint = Point__instantiate<int>(rb_mCv, "Point");

  Rice::Data_Type<cv::Point3_<int>> rb_cPoint3i = Point3__instantiate<int>(rb_mCv, "Point3i");

  Rice::Data_Type<cv::Point3_<float>> rb_cPoint3f = Point3__instantiate<float>(rb_mCv, "Point3f");

  Rice::Data_Type<cv::Point3_<double>> rb_cPoint3d = Point3__instantiate<double>(rb_mCv, "Point3d");

  Rice::Data_Type<cv::Size_<int>> rb_cSize2i = Size__instantiate<int>(rb_mCv, "Size2i");

  Rice::Data_Type<cv::Size_<int64>> rb_cSize2l = Size__instantiate<int64>(rb_mCv, "Size2l"); // Manual fix: use int64 instead of long

  Rice::Data_Type<cv::Size_<float>> rb_cSize2f = Size__instantiate<float>(rb_mCv, "Size2f");

  Rice::Data_Type<cv::Size_<double>> rb_cSize2d = Size__instantiate<double>(rb_mCv, "Size2d");

  Rice::Data_Type<cv::Size_<int>> rb_cSize = Size__instantiate<int>(rb_mCv, "Size");

  Rice::Data_Type<cv::Rect_<int>> rb_cRect2i = Rect__instantiate<int>(rb_mCv, "Rect2i");

  Rice::Data_Type<cv::Rect_<float>> rb_cRect2f = Rect__instantiate<float>(rb_mCv, "Rect2f");

  Rice::Data_Type<cv::Rect_<double>> rb_cRect2d = Rect__instantiate<double>(rb_mCv, "Rect2d");

  Rice::Data_Type<cv::Rect_<int>> rb_cRect = Rect__instantiate<int>(rb_mCv, "Rect");

  Rice::Data_Type<cv::RotatedRect> rb_cCvRotatedRect = define_class_under<cv::RotatedRect>(rb_mCv, "RotatedRect").
    define_constructor(Constructor<cv::RotatedRect>()).
    define_constructor(Constructor<cv::RotatedRect, const cv::Point2f&, const cv::Size2f&, float>(),
      Arg("center"), Arg("size"), Arg("angle")).
    define_constructor(Constructor<cv::RotatedRect, const cv::Point2f&, const cv::Point2f&, const cv::Point2f&>(),
      Arg("point1"), Arg("point2"), Arg("point3")).
    define_method<void(cv::RotatedRect::*)(cv::Point2f[]) const>("points", &cv::RotatedRect::points,
      Arg("pts")).
#if RUBY_CV_VERSION >= 408
    define_method<void(cv::RotatedRect::*)(std::vector<cv::Point_<float>>&) const>("points", &cv::RotatedRect::points,
      Arg("pts")).
#endif
    define_method<cv::Rect(cv::RotatedRect::*)() const>("bounding_rect", &cv::RotatedRect::boundingRect).
    define_method<cv::Rect2f(cv::RotatedRect::*)() const>("bounding_rect2f", &cv::RotatedRect::boundingRect2f).
    define_attr("center", &cv::RotatedRect::center).
    define_attr("size", &cv::RotatedRect::size).
    define_attr("angle", &cv::RotatedRect::angle);

  Rice::Data_Type<cv::DataType<cv::RotatedRect>> rb_cCvDataTypeRotatedRect = define_class_under<cv::DataType<cv::RotatedRect>>(rb_mCv, "DataTypeRotatedRect").
    define_constructor(Constructor<cv::DataType<cv::RotatedRect>>());

  rb_cCvDataTypeRotatedRect.define_constant("Generic_type", (int)cv::DataType<cv::RotatedRect>::generic_type);
  rb_cCvDataTypeRotatedRect.define_constant("Channels", (int)cv::DataType<cv::RotatedRect>::channels);
  rb_cCvDataTypeRotatedRect.define_constant("Fmt", (int)cv::DataType<cv::RotatedRect>::fmt);

  Rice::Data_Type<cv::traits::Depth<cv::RotatedRect>> rb_cCvTraitsDepthRotatedRect = define_class_under<cv::traits::Depth<cv::RotatedRect>>(rb_mCvTraits, "DepthRotatedRect").
    define_constructor(Constructor<cv::traits::Depth<cv::RotatedRect>>());

  rb_cCvTraitsDepthRotatedRect.define_constant("Value", (int)cv::traits::Depth<cv::RotatedRect>::value);

  Rice::Data_Type<cv::traits::Type<cv::RotatedRect>> rb_cCvTraitsTypeRotatedRect = define_class_under<cv::traits::Type<cv::RotatedRect>>(rb_mCvTraits, "TypeRotatedRect").
    define_constructor(Constructor<cv::traits::Type<cv::RotatedRect>>());

  rb_cCvTraitsTypeRotatedRect.define_constant("Value", (int)cv::traits::Type<cv::RotatedRect>::value);

  Rice::Data_Type<cv::Range> rb_cCvRange = define_class_under<cv::Range>(rb_mCv, "Range").
    define_constructor(Constructor<cv::Range>()).
    define_constructor(Constructor<cv::Range, int, int>(),
      Arg("_start"), Arg("_end")).
    define_method<int(cv::Range::*)() const>("size", &cv::Range::size).
    define_method<bool(cv::Range::*)() const>("empty?", &cv::Range::empty).
    define_singleton_function<cv::Range(*)()>("all", &cv::Range::all).
    define_attr("start", &cv::Range::start).
    define_attr("end", &cv::Range::end);

  Rice::Data_Type<cv::DataType<cv::Range>> rb_cCvDataTypeRange = define_class_under<cv::DataType<cv::Range>>(rb_mCv, "DataTypeRange").
    define_constructor(Constructor<cv::DataType<cv::Range>>());

  rb_cCvDataTypeRange.define_constant("Generic_type", (int)cv::DataType<cv::Range>::generic_type);
  rb_cCvDataTypeRange.define_constant("Channels", (int)cv::DataType<cv::Range>::channels);
  rb_cCvDataTypeRange.define_constant("Fmt", (int)cv::DataType<cv::Range>::fmt);

  Rice::Data_Type<cv::traits::Depth<cv::Range>> rb_cCvTraitsDepthRange = define_class_under<cv::traits::Depth<cv::Range>>(rb_mCvTraits, "DepthRange").
    define_constructor(Constructor<cv::traits::Depth<cv::Range>>());

  rb_cCvTraitsDepthRange.define_constant("Value", (int)cv::traits::Depth<cv::Range>::value);

  Rice::Data_Type<cv::traits::Type<cv::Range>> rb_cCvTraitsTypeRange = define_class_under<cv::traits::Type<cv::Range>>(rb_mCvTraits, "TypeRange").
    define_constructor(Constructor<cv::traits::Type<cv::Range>>());

  rb_cCvTraitsTypeRange.define_constant("Value", (int)cv::traits::Type<cv::Range>::value);

  Rice::Data_Type<cv::Matx<double, 4, 1>> rb_cMatx41d = Matx_instantiate<double, 4, 1>(rb_mCv, "Matx41d");
  Rice::Data_Type<cv::Vec<double, 4>> rb_cVec4d = Vec_instantiate<double, 4>(rb_mCv, "Vec4d");
  Rice::Data_Type<cv::Scalar_<double>> rb_cScalar = Scalar__instantiate<double>(rb_mCv, "Scalar");

  Rice::Data_Type<cv::KeyPoint> rb_cCvKeyPoint = define_class_under<cv::KeyPoint>(rb_mCv, "KeyPoint").
    define_constructor(Constructor<cv::KeyPoint>()).
    define_constructor(Constructor<cv::KeyPoint, cv::Point2f, float, float, float, int, int>(),
      Arg("pt"), Arg("size"), Arg("angle") = static_cast<float>(-1), Arg("response") = static_cast<float>(0), Arg("octave") = static_cast<int>(0), Arg("class_id") = static_cast<int>(-1)).
    define_constructor(Constructor<cv::KeyPoint, float, float, float, float, float, int, int>(),
      Arg("x"), Arg("y"), Arg("size"), Arg("angle") = static_cast<float>(-1), Arg("response") = static_cast<float>(0), Arg("octave") = static_cast<int>(0), Arg("class_id") = static_cast<int>(-1)).
    define_method<size_t(cv::KeyPoint::*)() const>("hash", &cv::KeyPoint::hash).
    define_singleton_function<void(*)(const std::vector<cv::KeyPoint>&, std::vector<cv::Point_<float>>&, const std::vector<int>&)>("convert", &cv::KeyPoint::convert,
      Arg("keypoints"), Arg("points2f"), Arg("keypoint_indexes") = static_cast<const std::vector<int>&>(std::vector<int>())).
    define_singleton_function<void(*)(const std::vector<cv::Point_<float>>&, std::vector<cv::KeyPoint>&, float, float, int, int)>("convert", &cv::KeyPoint::convert,
      Arg("points2f"), Arg("keypoints"), Arg("size") = static_cast<float>(1), Arg("response") = static_cast<float>(1), Arg("octave") = static_cast<int>(0), Arg("class_id") = static_cast<int>(-1)).
    define_singleton_function<float(*)(const cv::KeyPoint&, const cv::KeyPoint&)>("overlap", &cv::KeyPoint::overlap,
      Arg("kp1"), Arg("kp2")).
    define_attr("pt", &cv::KeyPoint::pt).
    define_attr("size", &cv::KeyPoint::size).
    define_attr("angle", &cv::KeyPoint::angle).
    define_attr("response", &cv::KeyPoint::response).
    define_attr("octave", &cv::KeyPoint::octave).
    define_attr("class_id", &cv::KeyPoint::class_id);

  Rice::Data_Type<cv::DMatch> rb_cCvDMatch = define_class_under<cv::DMatch>(rb_mCv, "DMatch").
    define_constructor(Constructor<cv::DMatch>()).
    define_constructor(Constructor<cv::DMatch, int, int, float>(),
      Arg("_query_idx"), Arg("_train_idx"), Arg("_distance")).
    define_constructor(Constructor<cv::DMatch, int, int, int, float>(),
      Arg("_query_idx"), Arg("_train_idx"), Arg("_img_idx"), Arg("_distance")).
    define_attr("query_idx", &cv::DMatch::queryIdx).
    define_attr("train_idx", &cv::DMatch::trainIdx).
    define_attr("img_idx", &cv::DMatch::imgIdx).
    define_attr("distance", &cv::DMatch::distance).
    define_method<bool(cv::DMatch::*)(const cv::DMatch&) const>("<", &cv::DMatch::operator<,
      Arg("m"));

  Rice::Data_Type<cv::TermCriteria> rb_cCvTermCriteria = define_class_under<cv::TermCriteria>(rb_mCv, "TermCriteria").
    define_constructor(Constructor<cv::TermCriteria>()).
    define_constructor(Constructor<cv::TermCriteria, int, int, double>(),
      Arg("type"), Arg("max_count"), Arg("epsilon")).
    define_method<bool(cv::TermCriteria::*)() const>("valid?", &cv::TermCriteria::isValid).
    define_attr("type", &cv::TermCriteria::type).
    define_attr("max_count", &cv::TermCriteria::maxCount).
    define_attr("epsilon", &cv::TermCriteria::epsilon);

  Enum<cv::TermCriteria::Type> rb_cCvTermCriteriaType = define_enum_under<cv::TermCriteria::Type>("Type", rb_cCvTermCriteria).
    define_value("COUNT", cv::TermCriteria::Type::COUNT).
    define_value("MAX_ITER", cv::TermCriteria::Type::MAX_ITER).
    define_value("EPS", cv::TermCriteria::Type::EPS);

  Rice::Data_Type<cv::Moments> rb_cCvMoments = define_class_under<cv::Moments>(rb_mCv, "Moments").
    define_constructor(Constructor<cv::Moments>()).
    define_constructor(Constructor<cv::Moments, double, double, double, double, double, double, double, double, double, double>(),
      Arg("m00"), Arg("m10"), Arg("m01"), Arg("m20"), Arg("m11"), Arg("m02"), Arg("m30"), Arg("m21"), Arg("m12"), Arg("m03")).
    define_attr("m00", &cv::Moments::m00).
    define_attr("m10", &cv::Moments::m10).
    define_attr("m01", &cv::Moments::m01).
    define_attr("m20", &cv::Moments::m20).
    define_attr("m11", &cv::Moments::m11).
    define_attr("m02", &cv::Moments::m02).
    define_attr("m30", &cv::Moments::m30).
    define_attr("m21", &cv::Moments::m21).
    define_attr("m12", &cv::Moments::m12).
    define_attr("m03", &cv::Moments::m03).
    define_attr("mu20", &cv::Moments::mu20).
    define_attr("mu11", &cv::Moments::mu11).
    define_attr("mu02", &cv::Moments::mu02).
    define_attr("mu30", &cv::Moments::mu30).
    define_attr("mu21", &cv::Moments::mu21).
    define_attr("mu12", &cv::Moments::mu12).
    define_attr("mu03", &cv::Moments::mu03).
    define_attr("nu20", &cv::Moments::nu20).
    define_attr("nu11", &cv::Moments::nu11).
    define_attr("nu02", &cv::Moments::nu02).
    define_attr("nu30", &cv::Moments::nu30).
    define_attr("nu21", &cv::Moments::nu21).
    define_attr("nu12", &cv::Moments::nu12).
    define_attr("nu03", &cv::Moments::nu03);

  Rice::Data_Type<cv::DataType<cv::Moments>> rb_cCvDataTypeMoments = define_class_under<cv::DataType<cv::Moments>>(rb_mCv, "DataTypeMoments").
    define_constructor(Constructor<cv::DataType<cv::Moments>>());

  rb_cCvDataTypeMoments.define_constant("Generic_type", (int)cv::DataType<cv::Moments>::generic_type);
  rb_cCvDataTypeMoments.define_constant("Channels", (int)cv::DataType<cv::Moments>::channels);
  rb_cCvDataTypeMoments.define_constant("Fmt", (int)cv::DataType<cv::Moments>::fmt);

  Rice::Data_Type<cv::traits::Depth<cv::Moments>> rb_cCvTraitsDepthMoments = define_class_under<cv::traits::Depth<cv::Moments>>(rb_mCvTraits, "DepthMoments").
    define_constructor(Constructor<cv::traits::Depth<cv::Moments>>());

  rb_cCvTraitsDepthMoments.define_constant("Value", (int)cv::traits::Depth<cv::Moments>::value);

  Rice::Data_Type<cv::traits::Type<cv::Moments>> rb_cCvTraitsTypeMoments = define_class_under<cv::traits::Type<cv::Moments>>(rb_mCvTraits, "TypeMoments").
    define_constructor(Constructor<cv::traits::Type<cv::Moments>>());

  rb_cCvTraitsTypeMoments.define_constant("Value", (int)cv::traits::Type<cv::Moments>::value);

  rb_mCv.define_module_function<int(*)(const cv::Point_<int>&)>("norm_l2_sqr", &cv::normL2Sqr,
    Arg("pt"));

  rb_mCv.define_module_function<int64(*)(const cv::Point_<int64>&)>("norm_l2_sqr", &cv::normL2Sqr,
    Arg("pt"));

  rb_mCv.define_module_function<float(*)(const cv::Point_<float>&)>("norm_l2_sqr", &cv::normL2Sqr,
    Arg("pt"));

  rb_mCv.define_module_function<double(*)(const cv::Point_<int>&)>("norm_l2_sqr", &cv::normL2Sqr,
    Arg("pt"));

  rb_mCv.define_module_function<double(*)(const cv::Point_<float>&)>("norm_l2_sqr", &cv::normL2Sqr,
    Arg("pt"));

  rb_mCv.define_module_function<double(*)(const cv::Point_<double>&)>("norm_l2_sqr", &cv::normL2Sqr,
    Arg("pt"));

#if RUBY_CV_VERSION >= 407
  rb_mCv.define_module_function<double(*)(const cv::Rect2d&, const cv::Rect2d&)>("rectangle_intersection_area", &cv::rectangleIntersectionArea,
    Arg("a"), Arg("b"));
#endif

  rb_cCvRange.
    define_method("==", [](const cv::Range& self, const cv::Range& other) -> bool
    {
      return self == other;
    }).
    define_method("!=", [](const cv::Range& self, const cv::Range& other) -> bool
    {
      return self != other;
    }).
    define_method("!", [](const cv::Range& self) -> bool
    {
      return !self;
    }).
    define_method("&", [](const cv::Range& self, const cv::Range& other) -> cv::Range
    {
      return self & other;
    }).
    define_method("assign_and", [](cv::Range& self, const cv::Range& other) -> cv::Range&
    {
      self &= other;
      return self;
    }).
    define_method("+", [](const cv::Range& self, int other) -> cv::Range
    {
      return self + other;
    }).
    define_method("-", [](const cv::Range& self, int other) -> cv::Range
    {
      return self - other;
    });
  
  Data_Type<cv::Matx<double, 4, 4>>().
    define_method("*", [](const cv::Matx<double, 4, 4>& self, const cv::Scalar& other) -> cv::Scalar
    {
      return self * other;
    });
}
