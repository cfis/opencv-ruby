#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include "types-rb.hpp"
#include "../opencv2/core/types-rb.ipp"

using namespace Rice;

template<typename _Tp>
inline void Point__Refinements()
{
  Data_Type<cv::Point_<_Tp>>().
    define_method("to_vec", [](const cv::Point_<_Tp>& self) -> cv::Vec<_Tp, 2>
    {
      return self;
    }).
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
    define_method("to_s", [](const cv::Point_<_Tp>& self) -> std::string
    {
      std::ostringstream stream;
      stream << "<" << Data_Type<cv::Point_<_Tp>>::klass().name() << ": " << self << ">";
      return stream.str();
    });
}

template<typename _Tp>
inline void Point3__Refinements()
{
  Data_Type<cv::Point3_<_Tp>>().
    define_method("to_vec", [](const cv::Point3_<_Tp>& self) -> cv::Vec<_Tp, 3>
    {
      return self;
    }).
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
}

template<typename _Tp>
inline void Size__Refinements()
{
  Data_Type<cv::Size_<_Tp>>().
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
    define_method("to_s", [](const cv::Size_<_Tp>& self) -> std::string
    {
      std::ostringstream stream;
      stream << "<" << Data_Type<cv::Size_<_Tp>>::klass().name() << ":" << self.width << "x" << self.height << ">";
      return stream.str();
    });
}

template<typename _Tp>
inline void Rect__Refinements()
{
  Data_Type<cv::Rect_<_Tp>>().
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
    //define_method("&", [](const cv::Rect_<_Tp>& self, const cv::Rect_<_Tp>& other) -> cv::Rect_<_Tp>
    //{
    //  return self & other;
    //}).
    define_method("|", [](const cv::Rect_<_Tp>& self, const cv::Rect_<_Tp>& other) -> cv::Rect_<_Tp>
    {
      return self | other;
    }).
    template define_method<bool(cv::Rect_<_Tp>::*)(const cv::Point_<_Tp>&) const>("contains?", &cv::Rect_<_Tp>::contains,
        Arg("pt")).
    define_method("inspect", [](const cv::Rect_<_Tp>& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
}

void Init_Core_Types_Refinements()
{
  Module rb_mCv = define_module("Cv");

  // Previously defined in core/types-rb.cpp
  Point__Refinements<int>();
  Point__Refinements<int64>();
  Point__Refinements<float>();
  Point__Refinements<double>();
  Point__Refinements<int>();
  Point3__Refinements<int>();
  Point3__Refinements<float>();
  Point3__Refinements<double>();
  Size__Refinements<int>();
  Size__Refinements<int64>();
  Size__Refinements<float>();
  Size__Refinements<double>();
  Size__Refinements<int>();
  Rect__Refinements<int>();
  Rect__Refinements<float>();
  Rect__Refinements<double>();
  Rect__Refinements<int>();
  Size__Refinements<int>();
  Size__Refinements<int64>();
  Size__Refinements<float>();
  Size__Refinements<double>();

  // These points are generated while compiling and thus must be defined
  Point__instantiate<unsigned char>(rb_mCv, "Point2b");
  Point__Refinements<unsigned char>();
  Point__instantiate<short>(rb_mCv, "Point2s");
  Point__Refinements<short>();
  Point__instantiate<unsigned short>(rb_mCv, "Point2w");
  Point__Refinements<unsigned short>();

  Point3__instantiate<unsigned char>(rb_mCv, "Point3b");
  Point__Refinements<unsigned char>();
  Point3__instantiate<short>(rb_mCv, "Point3s");
  Point__Refinements<short>();
  Point3__instantiate<unsigned short>(rb_mCv, "Point3w");
  Point__Refinements<unsigned short>();

  Rect__instantiate<unsigned char>(rb_mCv, "Rect2b");
  Rect__Refinements<unsigned char>();
  Rect__instantiate<short>(rb_mCv, "Rect2s");
  Rect__Refinements<short>();
  Rect__instantiate<unsigned short>(rb_mCv, "Rect2w");
  Rect__Refinements<unsigned short>();
  Rect__instantiate<int64>(rb_mCv, "Rect2l");
  Rect__Refinements<int64>();

  Size__instantiate<unsigned char>(rb_mCv, "Size2b");
  Size__Refinements<unsigned char>();
  Size__instantiate<short>(rb_mCv, "Size2s");
  Size__Refinements<short>();
  Size__instantiate<unsigned short>(rb_mCv, "Size2w");
  Size__Refinements<unsigned short>();

  // Define some aliases
  rb_define_const(rb_mCv, "Point2i", Data_Type<cv::Point_<int>>::klass());
  rb_define_const(rb_mCv, "Point3i", Data_Type<cv::Point3_<int>>::klass());
  rb_define_const(rb_mCv, "Size2i", Data_Type<cv::Size_<int>>::klass());
  rb_define_const(rb_mCv, "Rect2i", Data_Type<cv::Rect_<int>>::klass());

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
