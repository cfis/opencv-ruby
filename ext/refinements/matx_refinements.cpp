#include <opencv2/core/matx.hpp>
#include "matx_refinements.hpp"

using namespace Rice;

// Manual
namespace cv
{
  typedef Vec<uchar, 1> Vec1b;
  typedef Vec<short, 1> Vec1s;
  typedef Vec<unsigned short, 1> Vec1w;
  typedef Vec<int, 1> Vec1i;
  typedef Vec<float, 1> Vec1f;
  typedef Vec<double, 1> Vec1d;
  typedef Vec<int64, 2> Vec2l;
}


template<typename Data_Type_T, typename _Tp, int m, int n>
inline void Matx_Refinements_builder(Data_Type_T& klass)
{
  // Convert to inputarray
  klass.
    define_method("input_array", [](const cv::Matx<_Tp, m, n>& self) -> cv::_InputArray
    {
      return cv::_InputArray(self);
    }).
    define_method("inspect", [](const cv::Matx<_Tp, m, n>& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });

  // Iteration
  klass.
    include_module(rb_mEnumerable).
    define_method("each", [](VALUE self, VALUE) -> VALUE
    {
      if (!detail::protect(rb_block_given_p))
      {
        static Identifier identifier("each");
        VALUE enumerator = detail::protect(rb_enumeratorize_with_size, self, identifier.to_sym(), 0, nullptr, nullptr);
        return enumerator;
      }
      else
      {
        cv::Matx<_Tp, m, n>* matx = detail::From_Ruby<cv::Matx<_Tp, m, n>*>().convert(self);

        // The iterator returns references - we do NOT want to create a copy
        detail::To_Ruby<_Tp&> toRuby;

        auto it = std::begin(matx->val);
        auto end = std::end(matx->val);

        for (; it != end; ++it)
        {
          detail::protect(rb_yield, toRuby.convert(*it));
        }

        return self;
      }
    }, Arg("proc").setValue() = Qnil, Return().setValue());

    // Match cv::Mat API
    klass.define_method("rows", [](const cv::Matx<_Tp, m, n>&) -> int
    {
        return (int)cv::Matx<_Tp, m, n>::rows;
    }).
    define_method("cols", [](const cv::Matx<_Tp, m, n>&) -> int
    {
      return (int)cv::Matx<_Tp, m, n>::cols;
    }).
    define_method("channels", [](const cv::Matx<_Tp, m, n>&) -> int
    {
      return (int)cv::Matx<_Tp, m, n>::channels;
    }).
    define_method("shortdim", [](const cv::Matx<_Tp, m, n>&) -> int
    {
      return (int)cv::Matx<_Tp, m, n>::shortdim;
    });

    // Add in a bunch of non-member functions
    klass.define_method("determinant", [](const cv::Matx<_Tp, m, n>& self) -> double
    {
      return determinant(self);
    }).
    define_method("trace", [](const cv::Matx<_Tp, m, n>& self) -> double
    {
      return trace(self);
    }).
    define_method("norm", [](const cv::Matx<_Tp, m, n>& self) -> double
    {
      return norm(self);
    }).
    define_method("norm", [](const cv::Matx<_Tp, m, n>& self, int normType) -> double
    {
      return norm(self, normType);
    });

    // Add in a bunch of non-member operators
    klass.define_method("assign_plus", [](cv::Matx<_Tp, m, n>& self, const cv::Matx<_Tp, m, n>& other) -> cv::Matx<_Tp, m, n>&
    {
      return self += other;
    }).
    define_method("assign_minus", [](cv::Matx<_Tp, m, n>& self, const cv::Matx<_Tp, m, n>& other) -> cv::Matx<_Tp, m, n>&
    {
      return self -= other;
    }).
    define_method("+", [](const cv::Matx<_Tp, m, n>& self, const cv::Matx<_Tp, m, n>& other) -> cv::Matx<_Tp, m, n>
    {
      return self + other;
    }).
    define_method("-", [](const cv::Matx<_Tp, m, n>& self, const cv::Matx<_Tp, m, n>& other) -> cv::Matx<_Tp, m, n>
    {
      return self - other;
    }).
    define_method("assign_multiply", [](cv::Matx<_Tp, m, n>& self, int alpha) -> cv::Matx<_Tp, m, n>&
    {
      return self *= alpha;
    }).
    define_method("assign_multiply", [](cv::Matx<_Tp, m, n>& self, float alpha) -> cv::Matx<_Tp, m, n>&
    {
      return self *= alpha;
    }).
    define_method("assign_multiply", [](cv::Matx<_Tp, m, n>& self, double alpha) -> cv::Matx<_Tp, m, n>&
    {
      return self *= alpha;
    }).
    define_method("*", [](const cv::Matx<_Tp, m, n>& self, int alpha) -> cv::Matx<_Tp, m, n>
    {
      return self * alpha;
    }).
    define_method("*", [](const cv::Matx<_Tp, m, n>& self, float alpha) -> cv::Matx<_Tp, m, n>
    {
      return self * alpha;
    }).
    define_method("*", [](const cv::Matx<_Tp, m, n>& self, double alpha) -> cv::Matx<_Tp, m, n>
    {
      return self * alpha;
    }).
    define_method("assign_divide", [](cv::Matx<_Tp, m, n>& self, float alpha) -> cv::Matx<_Tp, m, n>&
    {
      return self /= alpha;
    }).
    define_method("assign_divide", [](cv::Matx<_Tp, m, n>& self, double alpha) -> cv::Matx<_Tp, m, n>&
    {
      return self /= alpha;
    }).
    define_method("/", [](const cv::Matx<_Tp, m, n>& self, float alpha) -> cv::Matx<_Tp, m, n>
    {
      return self / alpha;
    }).
    define_method("/", [](const cv::Matx<_Tp, m, n>& self, double alpha) -> cv::Matx<_Tp, m, n>
    {
      return self / alpha;
    }).
    define_method("*", [](const cv::Matx<_Tp, m, n>& self, const cv::Vec<_Tp, n>& vec) -> cv::Vec<_Tp, m>
    {
      return self * vec;
    }).
    define_method("eql?", [](const cv::Matx<_Tp, m, n>& self, const cv::Matx<_Tp, m, n>& other) -> bool
    {
      return self == other;
    }).
    define_method("==", [](const cv::Matx<_Tp, m, n>& self, const cv::Matx<_Tp, m, n>& other) -> bool
    {
      return self == other;
    }).
    define_method("!=", [](const cv::Matx<_Tp, m, n>& self, const cv::Matx<_Tp, m, n>& other) -> bool
    {
      return self != other;
    });

    // Make minitest exception handling happy
    klass.define_method("_dump_data", [](const cv::Scalar&) -> Rice::Hash
    {
      Rice::Hash result;
      return result;
    });
}

template<typename Data_Type_T, typename _Tp, int cn>
inline void Vec_Refinements_builder(Data_Type_T& klass)
{
  klass.
    define_method("to_a", [](const cv::Vec<_Tp, cn>& self) -> VALUE
    {
      Rice::Array result((long)cn);
      for (int i = 0; i < cn; i++)
      {
        result.push(self[i], true);
      }
      return result.value();
    }, Return().setValue()).
    define_method("inspect", [](const cv::Vec<_Tp, cn>& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    }).
    define_method("to_s", [](VALUE self) -> std::string
    {
      const cv::Vec<_Tp, cn>& vec = detail::From_Ruby<cv::Vec<_Tp, cn>&>().convert(self);
      
      std::ostringstream stream;
      stream << "<" << detail::protect(rb_obj_classname, self) << ":" << vec << ">";
      return stream.str();
    });
}

void Init_Core_Matx_Refinements()
{
  Module rb_mCv = define_module("Cv");

  // Manual
  Rice::Data_Type<cv::Matx<unsigned char, 1, 1>> rb_cMatx11b = define_class_under<cv::Matx<unsigned char, 1, 1>>(rb_mCv, "Matx11b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 1, 1>>, unsigned char, 1, 1>);

  Rice::Data_Type<cv::Matx<unsigned char, 1, 2>> rb_cMatx12b = define_class_under<cv::Matx<unsigned char, 1, 2 >>(rb_mCv, "Matx12b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 1, 2>>, unsigned char, 1, 2>);

  Rice::Data_Type<cv::Matx<unsigned char, 1, 3>> rb_cMatx13b = define_class_under<cv::Matx<unsigned char, 1, 3 >>(rb_mCv, "Matx13b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 1, 3>>, unsigned char, 1, 3>);

  Rice::Data_Type<cv::Matx<unsigned char, 1, 4>> rb_cMatx14b = define_class_under<cv::Matx<unsigned char, 1, 4 >>(rb_mCv, "Matx14b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 1, 4>>, unsigned char, 1, 4>);
  Rice::Data_Type<cv::Matx<short, 1, 1>> rb_cMatx11s = define_class_under<cv::Matx<short, 1, 1 >>(rb_mCv, "Matx11s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 1, 1>>, short, 1, 1>);

  Rice::Data_Type<cv::Matx<short, 1, 2>> rb_cMatx12s = define_class_under<cv::Matx<short, 1, 2 >>(rb_mCv, "Matx12s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 1, 2>>, short, 1, 2>);

  Rice::Data_Type<cv::Matx<short, 1, 3>> rb_cMatx13s = define_class_under<cv::Matx<short, 1, 3 >>(rb_mCv, "Matx13s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 1, 3>>, short, 1, 3>);

  Rice::Data_Type<cv::Matx<short, 1, 4>> rb_cMatx14s = define_class_under<cv::Matx<short, 1, 4 >>(rb_mCv, "Matx14s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 1, 4>>, short, 1, 4>);

  Rice::Data_Type<cv::Matx<unsigned short, 1, 1>> rb_cMatx11w = define_class_under<cv::Matx<unsigned short, 1, 1 >>(rb_mCv, "Matx11w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 1, 1>>, unsigned short, 1, 1>);

  Rice::Data_Type<cv::Matx<unsigned short, 1, 2>> rb_cMatx12w = define_class_under<cv::Matx<unsigned short, 1, 2 >>(rb_mCv, "Matx12w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 1, 2>>, unsigned short, 1, 2>);

  Rice::Data_Type<cv::Matx<unsigned short, 1, 3>> rb_cMatx13w = define_class_under<cv::Matx<unsigned short, 1, 3 >>(rb_mCv, "Matx13w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 1, 3>>, unsigned short, 1, 3>);

  Rice::Data_Type<cv::Matx<unsigned short, 1, 4>> rb_cMatx14w = define_class_under<cv::Matx<unsigned short, 1, 4 >>(rb_mCv, "Matx14w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 1, 4>>, unsigned short, 1, 4>);

  Rice::Data_Type<cv::Matx<int, 1, 1>> rb_cMatx11i = define_class_under<cv::Matx<int, 1, 1 >>(rb_mCv, "Matx11i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 1, 1>>, int, 1, 1>);

  Rice::Data_Type<cv::Matx<int, 1, 2>> rb_cMatx12i = define_class_under<cv::Matx<int, 1, 2 >>(rb_mCv, "Matx12i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 1, 2>>, int, 1, 2>);

  Rice::Data_Type<cv::Matx<int, 1, 3>> rb_cMatx13i = define_class_under<cv::Matx<int, 1, 3 >>(rb_mCv, "Matx13i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 1, 3>>, int, 1, 3>);

  Rice::Data_Type<cv::Matx<int, 1, 4>> rb_cMatx14i = define_class_under<cv::Matx<int, 1, 4 >>(rb_mCv, "Matx14i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 1, 4>>, int, 1, 4>);

  Rice::Data_Type<cv::Matx<int, 1, 6>> rb_cMatx16i = define_class_under<cv::Matx<int, 1, 6 >>(rb_mCv, "Matx16i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 1, 6>>, int, 1, 6>);

  Rice::Data_Type<cv::Matx<int, 1, 8>> rb_cMatx18i = define_class_under<cv::Matx<int, 1, 8 >>(rb_mCv, "Matx18i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 1, 8>>, int, 1, 8>);

  Rice::Data_Type<cv::Matx<float, 3, 1>> rb_cMatx31f = define_class_under<cv::Matx<float, 3, 1>>(rb_mCv, "Matx31f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 1>>, float, 3, 1>);

  Rice::Data_Type<cv::Matx<float, 4, 1>> rb_cMatx41f = define_class_under<cv::Matx<float, 4, 1>>(rb_mCv, "Matx41f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 4, 1>>, float, 4, 1>);

  Rice::Data_Type<cv::Matx<float, 6, 1>> rb_cMatx61f = define_class_under<cv::Matx<float, 6, 1>>(rb_mCv, "Matx61f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 6, 1>>, float, 6, 1>);

  // Needed by DualQuat
  Rice::Data_Type<cv::Matx<float, 8, 1>> rb_cMatx81f = define_class_under<cv::Matx<float, 8, 1>>(rb_mCv, "Matx81f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 8, 1>>, float, 8, 1>);

  Rice::Data_Type<cv::Vec<float, 8>> rb_cVec8f = define_class_under<cv::Vec<float, 8>, cv::Matx<float, 8, 1>>(rb_mCv, "Vec8f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 8>>, float, 8>);

  Rice::Data_Type<cv::Matx<double, 2, 1>> rb_cMatx21d = define_class_under<cv::Matx<double, 2, 1>>(rb_mCv, "Matx21d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 2, 1>>, double, 2, 1>);

  Rice::Data_Type<cv::Matx<double, 8, 1>> rb_cMatx81d = define_class_under<cv::Matx<double, 8, 1>>(rb_mCv, "Matx81d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 8, 1>>, double, 8, 1>);

  Rice::Data_Type<cv::Vec<double, 8>> rb_cVec8d = define_class_under<cv::Vec<double, 8>, cv::Matx<double, 8, 1>>(rb_mCv, "Vec8d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 8>>, double, 8>);

  Rice::Data_Type<cv::Matx<float, 1, 1>> rb_cMatx11f = define_class_under<cv::Matx<float, 1, 1>>(rb_mCv, "Matx11f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 1>>, float, 1, 1>);

  Rice::Data_Type<cv::Matx<double, 1, 1>> rb_cMatx11d = define_class_under<cv::Matx<double, 1, 1>>(rb_mCv, "Matx11d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 1>>, double, 1, 1>);

  Rice::Data_Type<cv::Vec<unsigned char, 1>> rb_cVec1b = define_class_under<cv::Vec<unsigned char, 1>, cv::Matx<unsigned char, 1, 1>>(rb_mCv, "Vec1b").
    define(&Vec_builder<Data_Type<cv::Vec<unsigned char, 1>>, unsigned char, 1>);

  Rice::Data_Type<cv::Vec<short, 1>> rb_cVec1s = define_class_under<cv::Vec<short, 1>, cv::Matx<short, 1, 1>>(rb_mCv, "Vec1s").
    define(&Vec_builder<Data_Type<cv::Vec<short, 1>>, short, 1>);

  Rice::Data_Type<cv::Vec<unsigned short, 1>> rb_cVec1w = define_class_under<cv::Vec<unsigned short, 1>, cv::Matx<unsigned short, 1, 1>>(rb_mCv, "Vec1w").
    define(&Vec_builder<Data_Type<cv::Vec<unsigned short, 1>>, unsigned short, 1>);

  Rice::Data_Type<cv::Vec<int, 1>> rb_cVec1i = define_class_under<cv::Vec<int, 1>, cv::Matx<int, 1, 1>>(rb_mCv, "Vec1i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 1>>, int, 1>);

  Rice::Data_Type<cv::Vec<float, 1>> rb_cVec1f = define_class_under<cv::Vec<float, 1>, cv::Matx<float, 1, 1>>(rb_mCv, "Vec1f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 1>>, float, 1>);

  Rice::Data_Type<cv::Vec<double, 1>> rb_cVec1d = define_class_under<cv::Vec<double, 1>, cv::Matx<double, 1, 1>>(rb_mCv, "Vec1d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 1>>, double, 1>);

  // Requires adding long long (int64) support from OpenCV5
  Rice::Data_Type<cv::Matx<int64, 2, 1>> rb_cMatx21l = define_class_under<cv::Matx<int64, 2, 1 >>(rb_mCv, "Matx21l").
    define(&Matx_builder<Data_Type<cv::Matx<int64, 2, 1>>, int, 2, 1>);

  Rice::Data_Type<cv::Vec<int64, 2>> rb_cVec2l = define_class_under<cv::Vec<int64, 2>, cv::Matx<int64, 2, 1>>(rb_mCv, "Vec2l").
    define(&Vec_builder<Data_Type<cv::Vec<int64, 2>>, int64, 2>);

  // Define std::vector<cv::vec> classes so Ruby can create them and send them to a Mat_<_Tp> constructor
  define_vector<cv::Vec1b>(u8"Vector≺Cv꞉꞉Vec1b≻");
  define_vector<cv::Vec2b>(u8"Vector≺Cv꞉꞉Vec2b≻");
  define_vector<cv::Vec3b>(u8"Vector≺Cv꞉꞉Vec3b≻");
  define_vector<cv::Vec4b>(u8"Vector≺Cv꞉꞉Vec4b≻");
  define_vector<cv::Vec1s>(u8"Vector≺Cv꞉꞉Vec1s≻");
  define_vector<cv::Vec2s>(u8"Vector≺Cv꞉꞉Vec2s≻");
  define_vector<cv::Vec3s>(u8"Vector≺Cv꞉꞉Vec3s≻");
  define_vector<cv::Vec4s>(u8"Vector≺Cv꞉꞉Vec4s≻");
  define_vector<cv::Vec1w>(u8"Vector≺Cv꞉꞉Vec1w≻");
  define_vector<cv::Vec2w>(u8"Vector≺Cv꞉꞉Vec2w≻");
  define_vector<cv::Vec3w>(u8"Vector≺Cv꞉꞉Vec3w≻");
  define_vector<cv::Vec4w>(u8"Vector≺Cv꞉꞉Vec4w≻");
  define_vector<cv::Vec1i>(u8"Vector≺Cv꞉꞉Vec1i≻");
  define_vector<cv::Vec2i>(u8"Vector≺Cv꞉꞉Vec2i≻");
  define_vector<cv::Vec3i>(u8"Vector≺Cv꞉꞉Vec3i≻");
  define_vector<cv::Vec4i>(u8"Vector≺Cv꞉꞉Vec4i≻");
  define_vector<cv::Vec6i>(u8"Vector≺Cv꞉꞉Vec6i≻");
  define_vector<cv::Vec8i>(u8"Vector≺Cv꞉꞉Vec8i≻");
  define_vector<cv::Vec1f>(u8"Vector≺Cv꞉꞉Vec1f≻");
  define_vector<cv::Vec2f>(u8"Vector≺Cv꞉꞉Vec2f≻");
  define_vector<cv::Vec3f>(u8"Vector≺Cv꞉꞉Vec3f≻");
  define_vector<cv::Vec4f>(u8"Vector≺Cv꞉꞉Vec4f≻");
  define_vector<cv::Vec6f>(u8"Vector≺Cv꞉꞉Vec6f≻");
  define_vector<cv::Vec1d>(u8"Vector≺Cv꞉꞉Vec1d≻");
  define_vector<cv::Vec2d>(u8"Vector≺Cv꞉꞉Vec2d≻");
  define_vector<cv::Vec3d>(u8"Vector≺Cv꞉꞉Vec3d≻");
  define_vector<cv::Vec4d>(u8"Vector≺Cv꞉꞉Vec4d≻");
  define_vector<cv::Vec6f>(u8"Vector≺Cv꞉꞉Vec6f≻");
  define_vector<cv::Vec2l>(u8"Vector≺Cv꞉꞉Vec2l≻");

  // And just in case use th actual underlying names
  define_vector<cv::Vec1b>();
  define_vector<cv::Vec2b>();
  define_vector<cv::Vec3b>();
  define_vector<cv::Vec4b>();
  define_vector<cv::Vec1s>();
  define_vector<cv::Vec2s>();
  define_vector<cv::Vec3s>();
  define_vector<cv::Vec4s>();
  define_vector<cv::Vec1w>();
  define_vector<cv::Vec2w>();
  define_vector<cv::Vec3w>();
  define_vector<cv::Vec4w>();
  define_vector<cv::Vec1i>();
  define_vector<cv::Vec2i>();
  define_vector<cv::Vec3i>();
  define_vector<cv::Vec4i>();
  define_vector<cv::Vec6i>();
  define_vector<cv::Vec8i>();
  define_vector<cv::Vec1f>();
  define_vector<cv::Vec2f>();
  define_vector<cv::Vec3f>();
  define_vector<cv::Vec4f>();
  define_vector<cv::Vec6f>();
  define_vector<cv::Vec1d>();
  define_vector<cv::Vec2d>();
  define_vector<cv::Vec3d>();
  define_vector<cv::Vec4d>();
  define_vector<cv::Vec6f>();
  define_vector<cv::Vec2l>();
}
