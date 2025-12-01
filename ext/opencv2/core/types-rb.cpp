#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include "../../opencv_ruby_version.hpp"
#include "matx-rb.hpp"
#include "types-rb.hpp"

using namespace Rice;

Rice::Class rb_cComplexd;
Rice::Class rb_cComplexf;
Rice::Class rb_cCvDMatch;
Rice::Class rb_cCvDataTypeMoments;
Rice::Class rb_cCvDataTypeRange;
Rice::Class rb_cCvDataTypeRotatedRect;
Rice::Class rb_cCvKeyPoint;
Rice::Class rb_cCvMoments;
Rice::Class rb_cCvRange;
Rice::Class rb_cCvRotatedRect;
Rice::Class rb_cCvTermCriteria;
Rice::Class rb_cCvTraitsDepthMoments;
Rice::Class rb_cCvTraitsDepthRange;
Rice::Class rb_cCvTraitsDepthRotatedRect;
Rice::Class rb_cCvTraitsTypeMoments;
Rice::Class rb_cCvTraitsTypeRange;
Rice::Class rb_cCvTraitsTypeRotatedRect;
Rice::Class rb_cPoint;
Rice::Class rb_cPoint2b;
Rice::Class rb_cPoint2s;
Rice::Class rb_cPoint2w;
Rice::Class rb_cPoint2d;
Rice::Class rb_cPoint2f;
Rice::Class rb_cPoint2i;
Rice::Class rb_cPoint2l;
Rice::Class rb_cPoint3b;
Rice::Class rb_cPoint3s;
Rice::Class rb_cPoint3w;
Rice::Class rb_cPoint3d;
Rice::Class rb_cPoint3f;
Rice::Class rb_cPoint3i;
Rice::Class rb_cRect;
Rice::Class rb_cRect2b;
Rice::Class rb_cRect2s;
Rice::Class rb_cRect2w;
Rice::Class rb_cRect2d;
Rice::Class rb_cRect2f;
Rice::Class rb_cRect2i;
Rice::Class rb_cRect2l;
Rice::Class rb_cScalar;
Rice::Class rb_cSize;
Rice::Class rb_cSize2b;
Rice::Class rb_cSize2s;
Rice::Class rb_cSize2w;
Rice::Class rb_cSize2d;
Rice::Class rb_cSize2f;
Rice::Class rb_cSize2i;
Rice::Class rb_cSize2l;

template<typename Data_Type_T, typename _Tp>
inline void Complex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Complex<_Tp>>()).
    define_constructor(Constructor<cv::Complex<_Tp>, _Tp, _Tp>(),
      Arg("_re"), Arg("_im") = static_cast<_Tp>(0)).
    define_method("conj", &cv::Complex<_Tp>::conj).
    define_attr("re", &cv::Complex<_Tp>::re).
    define_attr("im", &cv::Complex<_Tp>::im);
};

template<typename Data_Type_T, typename _Tp>
inline void Point__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Point_<_Tp>>()).
    define_constructor(Constructor<cv::Point_<_Tp>, _Tp, _Tp>(),
      Arg("_x"), Arg("_y")).
    define_constructor(Constructor<cv::Point_<_Tp>, const cv::Point_<_Tp>&>(),
      Arg("pt")).
    define_constructor(Constructor<cv::Point_<_Tp>, const cv::Size_<_Tp>&>(),
      Arg("sz")).
    define_constructor(Constructor<cv::Point_<_Tp>, const cv::Vec<_Tp, 2>&>(),
      Arg("v")).
    define_method("to_vec", [](const cv::Point_<_Tp>& self) -> cv::Vec<_Tp, 2>
    {
      return self;
    }).
    define_method("dot", &cv::Point_<_Tp>::dot,
      Arg("pt")).
    define_method("ddot", &cv::Point_<_Tp>::ddot,
      Arg("pt")).
    define_method("cross", &cv::Point_<_Tp>::cross,
      Arg("pt")).
    define_method("inside?", &cv::Point_<_Tp>::inside,
      Arg("r")).
    define_attr("x", &cv::Point_<_Tp>::x).
    define_attr("y", &cv::Point_<_Tp>::y).
    define_method("norm", [](cv::Point_<_Tp>& self) -> double
    {
      return cv::norm(self);
    }).
    define_method("assign_multiply", [](cv::Point_<_Tp>& self, float value) -> cv::Point_<_Tp>&
    {
      return self *= value;
    }).
    define_method("assign_multiply", [](cv::Point_<_Tp>& self, double value) -> cv::Point_<_Tp>&
    {
      return self *= value;
    }).
    define_method("*", [](const cv::Point_<_Tp>& self, int value) -> cv::Point_<_Tp>
    {
      return self * value;
    }).
    define_method("assign_divide", [](cv::Point_<_Tp>& self, int value) -> cv::Point_<_Tp>&
    {
      return self /= value;
    }).
    define_method("assign_divide", [](cv::Point_<_Tp>& self, float value) -> cv::Point_<_Tp>&
    {
      return self /= value;
    }).
    define_method("/", [](const cv::Point_<_Tp>& self, int value) -> cv::Point_<_Tp>
    {
      return self / value;
    }).
    define_method("/", [](const cv::Point_<_Tp>& self, float value) -> cv::Point_<_Tp>
    {
      return self / value;
    }).
    define_method("assign_plus", [](cv::Point_<_Tp>& self, const cv::Point_<_Tp>& other) -> cv::Point_<_Tp>&
    {
      return self += other;
    }).
    define_method("+", [](const cv::Point_<_Tp>& self, const cv::Point_<_Tp>& other) -> cv::Point_<_Tp>
    {
      return self + other;
    }).
    define_method("assign_minus", [](cv::Point_<_Tp>& self, const cv::Point_<_Tp>& other) -> cv::Point_<_Tp>&
    {
      return self -= other;
    }).
    define_method("-", [](const cv::Point_<_Tp>& self, const cv::Point_<_Tp>& other) -> cv::Point_<_Tp>
    {
      return self - other;
    }).
    define_method("==", [](const cv::Point_<_Tp>& self, const cv::Point_<_Tp>& other) -> bool
    {
      return self == other;
    }).
    define_method("!=", [](const cv::Point_<_Tp>& self, const cv::Point_<_Tp>& other) -> bool
    {
      return self != other;
    }).
    define_method("*", [](const cv::Point_<_Tp>& self, int value) -> cv::Point_<_Tp>
    {
      return self * value;
    }).
    define_method("*", [](const cv::Point_<_Tp>& self, float value) -> cv::Point_<_Tp>
    {
      return self * value;
    }).
    define_method("assign_divide", [](cv::Point_<_Tp>& self, int value) -> cv::Point_<_Tp>&
    {
      return self /= value;
    }).
    define_method("assign_divide", [](cv::Point_<_Tp>& self, float value) -> cv::Point_<_Tp>&
    {
      return self /= value;
    }).
    define_method("/", [](const cv::Point_<_Tp>& self, int value) -> cv::Point_<_Tp>
    {
      return self / value;
    }).
    define_method("/", [](const cv::Point_<_Tp>& self, float value) -> cv::Point_<_Tp>
    {
      return self / value;
    }).
    define_method("assign_plus", [](cv::Point_<_Tp>& self, const cv::Point_<_Tp>& other) -> cv::Point_<_Tp>&
    {
      return self += other;
    }).
    define_method("+", [](const cv::Point_<_Tp>& self, const cv::Point_<_Tp>& other) -> cv::Point_<_Tp>
    {
      return self + other;
    }).
    define_method("assign_minus", [](cv::Point_<_Tp>& self, const cv::Point_<_Tp>& other) -> cv::Point_<_Tp>&
    {
      return self -= other;
    }).
    define_method("-", [](const cv::Point_<_Tp>& self, const cv::Point_<_Tp>& other) -> cv::Point_<_Tp>
    {
      return self - other;
    }).
    define_method("==", [](const cv::Point_<_Tp>& self, const cv::Point_<_Tp>& other) -> bool
    {
      return self == other;
    }).
    define_method("!=", [](const cv::Point_<_Tp>& self, const cv::Point_<_Tp>& other) -> bool
    {
      return self != other;
    }).
    define_method("inspect", [](const cv::Point_<_Tp>& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    }).
    define_method("to_s", [klass](const cv::Point_<_Tp>& self) -> std::string
    {
      std::ostringstream stream;
      stream << "<" << klass.name() << ": " << self << ">";
      return stream.str();
    });
};

template<typename Data_Type_T, typename _Tp>
inline void Point3__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Point3_<_Tp>>()).
    define_constructor(Constructor<cv::Point3_<_Tp>, _Tp, _Tp, _Tp>(),
      Arg("_x"), Arg("_y"), Arg("_z")).
    define_constructor(Constructor<cv::Point3_<_Tp>, const cv::Point3_<_Tp>&>(),
      Arg("pt")).
    define_constructor(Constructor<cv::Point3_<_Tp>, const cv::Point_<_Tp>&>(),
      Arg("pt")).
    define_constructor(Constructor<cv::Point3_<_Tp>, const cv::Vec<_Tp, 3>&>(),
      Arg("v")).
    define_method("to_vec", [](const cv::Point3_<_Tp>& self) -> cv::Vec<_Tp, 3>
    {
      return self;
    }).
    define_method("dot", &cv::Point3_<_Tp>::dot,
      Arg("pt")).
    define_method("ddot", &cv::Point3_<_Tp>::ddot,
      Arg("pt")).
    define_method("cross", &cv::Point3_<_Tp>::cross,
      Arg("pt")).
    define_attr("x", &cv::Point3_<_Tp>::x).
    define_attr("y", &cv::Point3_<_Tp>::y).
    define_attr("z", &cv::Point3_<_Tp>::z).
    define_method("assign_multiply", [](cv::Point3_<_Tp>& self, float value) -> cv::Point3_<_Tp>&
    {
      return self *= value;
    }).
    define_method("assign_multiply", [](cv::Point3_<_Tp>& self, double value) -> cv::Point3_<_Tp>&
    {
      return self *= value;
    }).
    define_method("*", [](const cv::Point3_<_Tp>& self, int value) -> cv::Point3_<_Tp>
    {
      return self * value;
    }).
    define_method("assign_divide", [](cv::Point3_<_Tp>& self, int value) -> cv::Point3_<_Tp>&
    {
      return self /= value;
    }).
    define_method("assign_divide", [](cv::Point3_<_Tp>& self, float value) -> cv::Point3_<_Tp>&
    {
      return self /= value;
    }).
    define_method("/", [](const cv::Point3_<_Tp>& self, int value) -> cv::Point3_<_Tp>
    {
      return self / value;
    }).
    define_method("/", [](const cv::Point3_<_Tp>& self, float value) -> cv::Point3_<_Tp>
    {
      return self / value;
    }).
    define_method("assign_plus", [](cv::Point3_<_Tp>& self, const cv::Point3_<_Tp>& other) -> cv::Point3_<_Tp>&
    {
      return self += other;
    }).
    define_method("+", [](const cv::Point3_<_Tp>& self, const cv::Point3_<_Tp>& other) -> cv::Point3_<_Tp>
    {
      return self + other;
    }).
    define_method("assign_minus", [](cv::Point3_<_Tp>& self, const cv::Point3_<_Tp>& other) -> cv::Point3_<_Tp>&
    {
      return self -= other;
    }).
    define_method("-", [](const cv::Point3_<_Tp>& self, const cv::Point3_<_Tp>& other) -> cv::Point3_<_Tp>
    {
      return self - other;
    }).
    define_method("==", [](const cv::Point3_<_Tp>& self, const cv::Point3_<_Tp>& other) -> bool
    {
      return self == other;
    }).
    define_method("!=", [](const cv::Point3_<_Tp>& self, const cv::Point3_<_Tp>& other) -> bool
    {
      return self != other;
    }).
    define_method("*", [](const cv::Point3_<_Tp>& self, int value) -> cv::Point3_<_Tp>
    {
      return self * value;
    }).
    define_method("*", [](const cv::Point3_<_Tp>& self, float value) -> cv::Point3_<_Tp>
    {
      return self * value;
    }).
    define_method("assign_divide", [](cv::Point3_<_Tp>& self, int value) -> cv::Point3_<_Tp>&
    {
      return self /= value;
    }).
    define_method("assign_divide", [](cv::Point3_<_Tp>& self, float value) -> cv::Point3_<_Tp>&
    {
      return self /= value;
    }).
    define_method("/", [](const cv::Point3_<_Tp>& self, int value) -> cv::Point3_<_Tp>
    {
      return self / value;
    }).
    define_method("/", [](const cv::Point3_<_Tp>& self, float value) -> cv::Point3_<_Tp>
    {
      return self / value;
    }).
    define_method("assign_plus", [](cv::Point3_<_Tp>& self, const cv::Point3_<_Tp>& other) -> cv::Point3_<_Tp>&
    {
      return self += other;
    }).
    define_method("+", [](const cv::Point3_<_Tp>& self, const cv::Point3_<_Tp>& other) -> cv::Point3_<_Tp>
    {
      return self + other;
    }).
    define_method("assign_minus", [](cv::Point3_<_Tp>& self, const cv::Point3_<_Tp>& other) -> cv::Point3_<_Tp>&
    {
      return self -= other;
    }).
    define_method("-", [](const cv::Point3_<_Tp>& self, const cv::Point3_<_Tp>& other) -> cv::Point3_<_Tp>
    {
      return self - other;
    }).
    define_method("==", [](const cv::Point3_<_Tp>& self, const cv::Point3_<_Tp>& other) -> bool
    {
      return self == other;
    }).
    define_method("!=", [](const cv::Point3_<_Tp>& self, const cv::Point3_<_Tp>& other) -> bool
    {
      return self != other;
    }).
    define_method("inspect", [](const cv::Point3_<_Tp>& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
};

template<typename Data_Type_T, typename _Tp>
inline void Size__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Size_<_Tp>>()).
    define_constructor(Constructor<cv::Size_<_Tp>, _Tp, _Tp>(),
      Arg("_width"), Arg("_height")).
    define_constructor(Constructor<cv::Size_<_Tp>, const cv::Size_<_Tp>&>(),
      Arg("sz")).
    define_constructor(Constructor<cv::Size_<_Tp>, const cv::Point_<_Tp>&>(),
      Arg("pt")).
    define_method("area", &cv::Size_<_Tp>::area).
    define_method("aspect_ratio", &cv::Size_<_Tp>::aspectRatio).
    define_method("empty?", &cv::Size_<_Tp>::empty).
    define_attr("width", &cv::Size_<_Tp>::width).
    define_attr("height", &cv::Size_<_Tp>::height).
    define_method("assign_multiply", [](cv::Size_<_Tp>& self, _Tp value) -> cv::Size_<_Tp>&
    {
      return self *= value;
    }).
    define_method("*", [](const cv::Size_<_Tp>& self, _Tp value) -> cv::Size_<_Tp>
    {
      return self * value;
    }).
    define_method("assign_divide", [](cv::Size_<_Tp>& self, _Tp value) -> cv::Size_<_Tp>&
    {
      return self /= value;
    }).
    define_method("/", [](const cv::Size_<_Tp>& self, _Tp value) -> cv::Size_<_Tp>
    {
      return self / value;
    }).
    define_method("assign_plus", [](cv::Size_<_Tp>& self, const cv::Size_<_Tp>& other) -> cv::Size_<_Tp>&
    {
      return self += other;
    }).
    define_method("+", [](const cv::Size_<_Tp>& self, const cv::Size_<_Tp>& other) -> cv::Size_<_Tp>
    {
      return self + other;
    }).
    define_method("assign_minus", [](cv::Size_<_Tp>& self, const cv::Size_<_Tp>& other) -> cv::Size_<_Tp>&
    {
      return self -= other;
    }).
    define_method("-", [](const cv::Size_<_Tp>& self, const cv::Size_<_Tp>& other) -> cv::Size_<_Tp>
    {
      return self - other;
    }).
    define_method("==", [](const cv::Size_<_Tp>& self, const cv::Size_<_Tp>& other) -> bool
    {
      return self == other;
    }).
    define_method("!=", [](const cv::Size_<_Tp>& self, const cv::Size_<_Tp>& other) -> bool
    {
      return self != other;
    }).
    define_method("inspect", [](const cv::Size_<_Tp>& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    }).
    define_method("to_s", [klass](const cv::Size_<_Tp>& self) -> std::string
    {
      std::ostringstream stream;
      stream << "<" << klass.name() << ":" << self.width << "x" << self.height << ">";
      return stream.str();
    });
};

template<typename Data_Type_T, typename _Tp>
inline void Rect__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Rect_<_Tp>>()).
    define_constructor(Constructor<cv::Rect_<_Tp>, _Tp, _Tp, _Tp, _Tp>(),
      Arg("_x"), Arg("_y"), Arg("_width"), Arg("_height")).
    define_constructor(Constructor<cv::Rect_<_Tp>, const cv::Rect_<_Tp>&>(),
      Arg("r")).
    define_constructor(Constructor<cv::Rect_<_Tp>, const cv::Point_<_Tp>&, const cv::Size_<_Tp>&>(),
      Arg("org"), Arg("sz")).
    define_constructor(Constructor<cv::Rect_<_Tp>, const cv::Point_<_Tp>&, const cv::Point_<_Tp>&>(),
      Arg("pt1"), Arg("pt2")).
    define_method("tl", &cv::Rect_<_Tp>::tl).
    define_method("br", &cv::Rect_<_Tp>::br).
    define_method("size", &cv::Rect_<_Tp>::size).
    define_method("area", &cv::Rect_<_Tp>::area).
    define_method("empty?", &cv::Rect_<_Tp>::empty).
    template define_method<bool(cv::Rect_<_Tp>::*)(const cv::Point_<_Tp>&) const>("contains?", &cv::Rect_<_Tp>::contains,
      Arg("pt")).
    define_attr("x", &cv::Rect_<_Tp>::x).
    define_attr("y", &cv::Rect_<_Tp>::y).
    define_attr("width", &cv::Rect_<_Tp>::width).
    define_attr("height", &cv::Rect_<_Tp>::height).

    define_method("assign_plus", [](cv::Rect_<_Tp>& self, const cv::Point_<_Tp>& point) -> cv::Rect_<_Tp>
    {
      return self += point;
    }).
    define_method("assign_minus", [](cv::Rect_<_Tp>& self, const cv::Point_<_Tp>& point) -> cv::Rect_<_Tp>
    {
      return self -= point;
    }).
    define_method("assign_plus", [](cv::Rect_<_Tp>& self, const cv::Size_<_Tp>& size) -> cv::Rect_<_Tp>
    {
      return self += size;
    }).
    define_method("assign_minus", [](cv::Rect_<_Tp>& self, const cv::Size_<_Tp>& size) -> cv::Rect_<_Tp>
    {
      return self -= size;
    }).
   /* define_method("&=", [](cv::Rect_<_Tp>& self, const cv::Rect_<_Tp>& other) -> cv::Rect_<_Tp>
    {
      return self &= other;
    }).*/
    define_method("|=", [](cv::Rect_<_Tp>& self, const cv::Rect_<_Tp>& other) -> cv::Rect_<_Tp>
    {
      return self |= other;
    }).
    define_method("==", [](const cv::Rect_<_Tp>& self, const cv::Rect_<_Tp>& other) -> bool
    {
      return self == other;
    }).
    define_method("!=", [](const cv::Rect_<_Tp>& self, const cv::Rect_<_Tp>& other) -> bool
    {
      return self != other;
    }).
    define_method("+", [](const cv::Rect_<_Tp>& self, const cv::Point_<_Tp>& point) -> cv::Rect_<_Tp>
    {
      return self + point;
    }).
    define_method("-", [](cv::Rect_<_Tp>& self, const cv::Point_<_Tp>& point) -> cv::Rect_<_Tp>
    {
      return self - point;
    }).
    define_method("+", [](const cv::Rect_<_Tp>& self, const cv::Size_<_Tp>& size) -> cv::Rect_<_Tp>
    {
      return self + size;
    }).
    define_method("-", [](cv::Rect_<_Tp>& self, const cv::Size_<_Tp>& size) -> cv::Rect_<_Tp>
    {
      return self - size;
    }).
  /*  define_method("&", [](const cv::Rect_<_Tp>& self, const cv::Rect_<_Tp>& other) -> cv::Rect_<_Tp>
    {
      return self & other;
    }).*/
    define_method("|", [](const cv::Rect_<_Tp>& self, const cv::Rect_<_Tp>& other) -> cv::Rect_<_Tp>
    {
      return self | other;
    }).
    define_method("inspect", [](const cv::Rect_<_Tp>& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
};

template<typename Data_Type_T, typename _Tp>
inline void Scalar__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Scalar_<_Tp>>()).
    define_constructor(Constructor<cv::Scalar_<_Tp>, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2") = static_cast<_Tp>(0), Arg("v3") = static_cast<_Tp>(0)).
    define_constructor(Constructor<cv::Scalar_<_Tp>, _Tp>(),
      Arg("v0")).
    define_constructor(Constructor<cv::Scalar_<_Tp>, const cv::Scalar_<_Tp>&>(),
      Arg("s")).
    define_singleton_function("all", &cv::Scalar_<_Tp>::all,
      Arg("v0")).
     define_method("mul", &cv::Scalar_<_Tp>::mul,
      Arg("a"), Arg("scale") = static_cast<double>(1)).
    define_method("conj", &cv::Scalar_<_Tp>::conj).
    define_method("is_real?", &cv::Scalar_<_Tp>::isReal);
};


void Init_Types()
{
  Module rb_mCv = define_module("Cv");
  
  rb_cComplexf = define_class_under<cv::Complex<float>>(rb_mCv, "Complexf").
    define(&Complex_builder<Data_Type<cv::Complex<float>>, float>);
  
  rb_cComplexd = define_class_under<cv::Complex<double>>(rb_mCv, "Complexd").
    define(&Complex_builder<Data_Type<cv::Complex<double>>, double>);
  
  Module rb_mCvTraits = define_module_under(rb_mCv, "Traits");
  
  rb_cPoint = define_class_under<cv::Point_<int>>(rb_mCv, "Point").
    define(&Point__builder<Data_Type<cv::Point_<int>>, int>);

  rb_cPoint2b = define_class_under<cv::Point_<unsigned char>>(rb_mCv, "Point2b").
    define(&Point__builder<Data_Type<cv::Point_<unsigned char>>, unsigned char>);

  rb_cPoint2s = define_class_under<cv::Point_<short>>(rb_mCv, "Point2s").
    define(&Point__builder<Data_Type<cv::Point_<short>>, short>);

  rb_cPoint2w = define_class_under<cv::Point_<unsigned short>>(rb_mCv, "Point2w").
    define(&Point__builder<Data_Type<cv::Point_<unsigned short>>, unsigned short>);

  //rb_cPoint2i = define_class_under<cv::Point_<int>>(rb_mCv, "Point2i").
  //  define(&Point__builder<Data_Type<cv::Point_<int>>, int>);
  rb_mCv.const_set(rb_intern("Point2i"), rb_cPoint);
  
  rb_cPoint2l = define_class_under<cv::Point_<long long>>(rb_mCv, "Point2l").
    define(&Point__builder<Data_Type<cv::Point_<long long>>, int64>);
  
  rb_cPoint2f = define_class_under<cv::Point_<float>>(rb_mCv, "Point2f").
    define(&Point__builder<Data_Type<cv::Point_<float>>, float>);
  
  rb_cPoint2d = define_class_under<cv::Point_<double>>(rb_mCv, "Point2d").
    define(&Point__builder<Data_Type<cv::Point_<double>>, double>);
  
  rb_cPoint3b = define_class_under<cv::Point3_<unsigned char>>(rb_mCv, "Point3b").
    define(&Point3__builder<Data_Type<cv::Point3_<unsigned char>>, unsigned char>);

  rb_cPoint3s = define_class_under<cv::Point3_<short>>(rb_mCv, "Point3s").
    define(&Point3__builder<Data_Type<cv::Point3_<short>>, short>);

  rb_cPoint3w = define_class_under<cv::Point3_<unsigned short>>(rb_mCv, "Point3w").
    define(&Point3__builder<Data_Type<cv::Point3_<unsigned short>>, unsigned short>);

  rb_cPoint3i = define_class_under<cv::Point3_<int>>(rb_mCv, "Point3i").
    define(&Point3__builder<Data_Type<cv::Point3_<int>>, int>);
  
  rb_cPoint3f = define_class_under<cv::Point3_<float>>(rb_mCv, "Point3f").
    define(&Point3__builder<Data_Type<cv::Point3_<float>>, float>);
  
  rb_cPoint3d = define_class_under<cv::Point3_<double>>(rb_mCv, "Point3d").
    define(&Point3__builder<Data_Type<cv::Point3_<double>>, double>);
  
  rb_cSize = define_class_under<cv::Size_<int>>(rb_mCv, "Size").
    define(&Size__builder<Data_Type<cv::Size_<int>>, int>);

  rb_cSize2b = define_class_under<cv::Size_<unsigned char>>(rb_mCv, "Size2b").
    define(&Size__builder<Data_Type<cv::Size_<unsigned char>>, unsigned char>);

  rb_cSize2s = define_class_under<cv::Size_<short>>(rb_mCv, "Size2s").
    define(&Size__builder<Data_Type<cv::Size_<short>>, short>);

  rb_cSize2w = define_class_under<cv::Size_<unsigned short>>(rb_mCv, "Size2w").
    define(&Size__builder<Data_Type<cv::Size_<unsigned short>>, unsigned short>);

  //rb_cSize2i = define_class_under<cv::Size_<int>>(rb_mCv, "Size2i").
  //  define(&Size__builder<Data_Type<cv::Size_<int>>, int>);
  rb_mCv.const_set(rb_intern("Size2i"), rb_cPoint);

  rb_cSize2l = define_class_under<cv::Size_<long long>>(rb_mCv, "Size2l").
    define(&Size__builder<Data_Type<cv::Size_<long long>>, long long>);
  
  rb_cSize2f = define_class_under<cv::Size_<float>>(rb_mCv, "Size2f").
    define(&Size__builder<Data_Type<cv::Size_<float>>, float>);
  
  rb_cSize2d = define_class_under<cv::Size_<double>>(rb_mCv, "Size2d").
    define(&Size__builder<Data_Type<cv::Size_<double>>, double>);
  
  rb_cRect = define_class_under<cv::Rect_<int>>(rb_mCv, "Rect").
    define(&Rect__builder<Data_Type<cv::Rect_<int>>, int>);

  rb_cRect2b = define_class_under<cv::Rect_<unsigned char>>(rb_mCv, "Rect2b").
    define(&Rect__builder<Data_Type<cv::Rect_<unsigned char>>, unsigned char>);

  rb_cRect2s = define_class_under<cv::Rect_<short>>(rb_mCv, "Rect2s").
    define(&Rect__builder<Data_Type<cv::Rect_<short>>, short>);

  rb_cRect2w = define_class_under<cv::Rect_<unsigned short>>(rb_mCv, "Rect2w").
    define(&Rect__builder<Data_Type<cv::Rect_<unsigned short>>, unsigned short>);

  //rb_cRect2i = define_class_under<cv::Rect_<int>>(rb_mCv, "Rect2i").
  //  define(&Rect__builder<Data_Type<cv::Rect_<int>>, int>);
  rb_mCv.const_set(rb_intern("Rect2i"), rb_cRect);

  rb_cRect2f = define_class_under<cv::Rect_<float>>(rb_mCv, "Rect2f").
    define(&Rect__builder<Data_Type<cv::Rect_<float>>, float>);
  
  rb_cRect2d = define_class_under<cv::Rect_<double>>(rb_mCv, "Rect2d").
    define(&Rect__builder<Data_Type<cv::Rect_<double>>, double>);
  
  rb_cCvRotatedRect = define_class_under<cv::RotatedRect>(rb_mCv, "RotatedRect").
    define_constructor(Constructor<cv::RotatedRect>()).
    define_constructor(Constructor<cv::RotatedRect, const cv::Point2f&, const cv::Size2f&, float>(),
      Arg("center"), Arg("size"), Arg("angle")).
    define_constructor(Constructor<cv::RotatedRect, const cv::Point2f&, const cv::Point2f&, const cv::Point2f&>(),
      Arg("point1"), Arg("point2"), Arg("point3")).
    define_method<void(cv::RotatedRect::*)(cv::Point_<float>[]) const>("points", &cv::RotatedRect::points,
      Arg("pts")).
    define_method("bounding_rect", &cv::RotatedRect::boundingRect).
    define_method("bounding_rect2f", &cv::RotatedRect::boundingRect2f).
    define_attr("center", &cv::RotatedRect::center).
    define_attr("size", &cv::RotatedRect::size).
    define_attr("angle", &cv::RotatedRect::angle);

#if RUBY_CV_VERSION >= 408
  rb_cCvRotatedRect.
    define_method<void(cv::RotatedRect::*)(std::vector<cv::Point_<float>>&) const>("points", &cv::RotatedRect::points,
      Arg("pts"));
#endif
  
  rb_cCvDataTypeRotatedRect = define_class_under<cv::DataType<cv::RotatedRect>>(rb_mCv, "DataTypeRotatedRect").
    define_constructor(Constructor<cv::DataType<cv::RotatedRect>>());
  
  rb_cCvDataTypeRotatedRect.define_constant("Generic_type", (int)cv::DataType<cv::RotatedRect>::generic_type);
  rb_cCvDataTypeRotatedRect.define_constant("Channels", (int)cv::DataType<cv::RotatedRect>::channels);
  rb_cCvDataTypeRotatedRect.define_constant("Fmt", (int)cv::DataType<cv::RotatedRect>::fmt);
  
  rb_cCvTraitsDepthRotatedRect = define_class_under<cv::traits::Depth<cv::RotatedRect>>(rb_mCvTraits, "DepthRotatedRect").
    define_constructor(Constructor<cv::traits::Depth<cv::RotatedRect>>());
  
  rb_cCvTraitsDepthRotatedRect.define_constant("Value", (int)cv::traits::Depth<cv::RotatedRect>::value);
  
  rb_cCvTraitsTypeRotatedRect = define_class_under<cv::traits::Type<cv::RotatedRect>>(rb_mCvTraits, "TypeRotatedRect").
    define_constructor(Constructor<cv::traits::Type<cv::RotatedRect>>());
  
  rb_cCvTraitsTypeRotatedRect.define_constant("Value", (int)cv::traits::Type<cv::RotatedRect>::value);
  
  rb_cCvRange = define_class_under<cv::Range>(rb_mCv, "Range").
    define_constructor(Constructor<cv::Range>()).
    define_constructor(Constructor<cv::Range, int, int>(),
      Arg("_start"), Arg("_end")).
    define_method("size", &cv::Range::size).
    define_method("empty?", &cv::Range::empty).
    define_singleton_function("all", &cv::Range::all).
    define_attr("start", &cv::Range::start).
    define_attr("end", &cv::Range::end);
  
  rb_cCvDataTypeRange = define_class_under<cv::DataType<cv::Range>>(rb_mCv, "DataTypeRange").
    define_constructor(Constructor<cv::DataType<cv::Range>>());
  
  rb_cCvDataTypeRange.define_constant("Generic_type", (int)cv::DataType<cv::Range>::generic_type);
  rb_cCvDataTypeRange.define_constant("Channels", (int)cv::DataType<cv::Range>::channels);
  rb_cCvDataTypeRange.define_constant("Fmt", (int)cv::DataType<cv::Range>::fmt);
  
  rb_cCvTraitsDepthRange = define_class_under<cv::traits::Depth<cv::Range>>(rb_mCvTraits, "DepthRange").
    define_constructor(Constructor<cv::traits::Depth<cv::Range>>());
  
  rb_cCvTraitsDepthRange.define_constant("Value", (int)cv::traits::Depth<cv::Range>::value);
  
  rb_cCvTraitsTypeRange = define_class_under<cv::traits::Type<cv::Range>>(rb_mCvTraits, "TypeRange").
    define_constructor(Constructor<cv::traits::Type<cv::Range>>());
  
  rb_cCvTraitsTypeRange.define_constant("Value", (int)cv::traits::Type<cv::Range>::value);
  
  rb_cScalar = define_class_under<cv::Scalar_<double>, cv::Vec<double, 4>>(rb_mCv, "Scalar").
    define(&Scalar__builder<Data_Type<cv::Scalar_<double>>, double>);
  
  rb_cCvKeyPoint = define_class_under<cv::KeyPoint>(rb_mCv, "KeyPoint").
    define_constructor(Constructor<cv::KeyPoint>()).
    define_constructor(Constructor<cv::KeyPoint, cv::Point2f, float, float, float, int, int>(),
      Arg("pt"), Arg("size"), Arg("angle") = static_cast<float>(-1), Arg("response") = static_cast<float>(0), Arg("octave") = static_cast<int>(0), Arg("class_id") = static_cast<int>(-1)).
    define_constructor(Constructor<cv::KeyPoint, float, float, float, float, float, int, int>(),
      Arg("x"), Arg("y"), Arg("size"), Arg("angle") = static_cast<float>(-1), Arg("response") = static_cast<float>(0), Arg("octave") = static_cast<int>(0), Arg("class_id") = static_cast<int>(-1)).
    define_method("hash", &cv::KeyPoint::hash).
    define_singleton_function<void(*)(const std::vector<cv::KeyPoint>&, std::vector<cv::Point_<float>>&, const std::vector<int>&)>("convert", &cv::KeyPoint::convert,
      Arg("keypoints"), Arg("points2f"), Arg("keypoint_indexes") = static_cast<const std::vector<int> &>(std::vector<int>())).
    define_singleton_function<void(*)(const std::vector<cv::Point_<float>>&, std::vector<cv::KeyPoint>&, float, float, int, int)>("convert", &cv::KeyPoint::convert,
      Arg("points2f"), Arg("keypoints"), Arg("size") = static_cast<float>(1), Arg("response") = static_cast<float>(1), Arg("octave") = static_cast<int>(0), Arg("class_id") = static_cast<int>(-1)).
    define_singleton_function("overlap", &cv::KeyPoint::overlap,
      Arg("kp1"), Arg("kp2")).
    define_attr("pt", &cv::KeyPoint::pt).
    define_attr("size", &cv::KeyPoint::size).
    define_attr("angle", &cv::KeyPoint::angle).
    define_attr("response", &cv::KeyPoint::response).
    define_attr("octave", &cv::KeyPoint::octave).
    define_attr("class_id", &cv::KeyPoint::class_id);
  
  rb_cCvDMatch = define_class_under<cv::DMatch>(rb_mCv, "DMatch").
    define_constructor(Constructor<cv::DMatch>()).
    define_constructor(Constructor<cv::DMatch, int, int, float>(),
      Arg("_query_idx"), Arg("_train_idx"), Arg("_distance")).
    define_constructor(Constructor<cv::DMatch, int, int, int, float>(),
      Arg("_query_idx"), Arg("_train_idx"), Arg("_img_idx"), Arg("_distance")).
    define_attr("query_idx", &cv::DMatch::queryIdx).
    define_attr("train_idx", &cv::DMatch::trainIdx).
    define_attr("img_idx", &cv::DMatch::imgIdx).
    define_attr("distance", &cv::DMatch::distance).
    define_method("<", &cv::DMatch::operator<,
      Arg("m"));
  
  rb_cCvTermCriteria = define_class_under<cv::TermCriteria>(rb_mCv, "TermCriteria").
    define_constructor(Constructor<cv::TermCriteria>()).
    define_constructor(Constructor<cv::TermCriteria, int, int, double>(),
      Arg("type"), Arg("max_count"), Arg("epsilon")).
    define_method("valid?", &cv::TermCriteria::isValid).
    define_attr("type", &cv::TermCriteria::type).
    define_attr("max_count", &cv::TermCriteria::maxCount).
    define_attr("epsilon", &cv::TermCriteria::epsilon);
  
  Enum<cv::TermCriteria::Type> rb_cCvTermCriteriaType = define_enum_under<cv::TermCriteria::Type>("Type", rb_cCvTermCriteria).
    define_value("COUNT", cv::TermCriteria::Type::COUNT).
    define_value("MAX_ITER", cv::TermCriteria::Type::MAX_ITER).
    define_value("EPS", cv::TermCriteria::Type::EPS);
  
  rb_cCvMoments = define_class_under<cv::Moments>(rb_mCv, "Moments").
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
  
  rb_cCvDataTypeMoments = define_class_under<cv::DataType<cv::Moments>>(rb_mCv, "DataTypeMoments").
    define_constructor(Constructor<cv::DataType<cv::Moments>>());
  
  rb_cCvDataTypeMoments.define_constant("Generic_type", (int)cv::DataType<cv::Moments>::generic_type);
  rb_cCvDataTypeMoments.define_constant("Channels", (int)cv::DataType<cv::Moments>::channels);
  rb_cCvDataTypeMoments.define_constant("Fmt", (int)cv::DataType<cv::Moments>::fmt);
  
  rb_cCvTraitsDepthMoments = define_class_under<cv::traits::Depth<cv::Moments>>(rb_mCvTraits, "DepthMoments").
    define_constructor(Constructor<cv::traits::Depth<cv::Moments>>());
  
  rb_cCvTraitsDepthMoments.define_constant("Value", (int)cv::traits::Depth<cv::Moments>::value);
  
  rb_cCvTraitsTypeMoments = define_class_under<cv::traits::Type<cv::Moments>>(rb_mCvTraits, "TypeMoments").
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
  rb_mCv.define_module_function("rectangle_intersection_area", &cv::rectangleIntersectionArea,
    Arg("a"), Arg("b"));
#endif

  rb_cCvRange.define_method("==", [](const cv::Range& self, const cv::Range& other) -> bool
  {
    return self == other;
  });
  
  rb_cCvRange.define_method("!=", [](const cv::Range& self, const cv::Range& other) -> bool
  {
    return self != other;
  });
  
  rb_cCvRange.define_method("&", [](const cv::Range& self, const cv::Range& other) -> cv::Range
  {
    return self & other;
  });
  
  rb_cCvRange.define_method("&=", [](cv::Range& self, const cv::Range& other) -> cv::Range&
  {
    return self &= other;
  });
  
  rb_cCvRange.define_method("+", [](const cv::Range& self, int other) -> cv::Range
  {
    return self + other;
  });
  
  rb_cCvRange.define_method("-", [](const cv::Range& self, int other) -> cv::Range
  {
    return self - other;
  });
  
  rb_cMatx44d.define_method("*", [](const cv::Matx<double, 4, 4>& self, const cv::Scalar& other) -> cv::Scalar
  {
    return self * other;
  });

  // Manually added
  rb_cRect2l = define_class_under<cv::Rect_<long long>>(rb_mCv, "Rect2l").
    define(&Rect__builder<Data_Type<cv::Rect_<long long>>, long long>);

  // Define point vectors
  define_vector<cv::Point>(u8"Vector≺Cv꞉꞉Point≻");
  define_vector<cv::Point>(u8"Vector≺Cv꞉꞉Point2≻");
  define_vector<cv::Point2i>(u8"Vector≺Cv꞉꞉Point2i≻");
  define_vector<cv::Point2l>(u8"Vector≺Cv꞉꞉Point2l≻");
  define_vector<cv::Point2f>(u8"Vector≺Cv꞉꞉Point2f≻");
  define_vector<cv::Point2d>(u8"Vector≺Cv꞉꞉Point2d≻");

  define_vector<cv::Point3i>(u8"Vector≺Cv꞉꞉Point3i≻");
  define_vector<cv::Point3f>(u8"Vector≺Cv꞉꞉Point3f≻");
  define_vector<cv::Point3d>(u8"Vector≺Cv꞉꞉Point3d≻");
}