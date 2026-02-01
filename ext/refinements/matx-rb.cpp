#include <opencv2/core.hpp>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/mat.hpp>
#include "matx-rb.hpp"
#include "../opencv2/core/matx-rb.ipp"

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

template<typename _Tp, int m, int n>
inline void Matx_Refinements()
{
  Data_Type<cv::Matx<_Tp, m, n>> dataType;

  dataType.
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
  dataType.
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
  dataType.
    define_method("rows", [](const cv::Matx<_Tp, m, n>&) -> int
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
  dataType.
   /* define_method("determinant", [](const cv::Matx<_Tp, m, n>& self) -> double
    {
      return determinant<double(*)(const Matx<_Tp, m, m>&)>(self);
    }).*/
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
  dataType
    .define_method("assign_plus", [](cv::Matx<_Tp, m, n>& self, const cv::Matx<_Tp, m, n>& other) -> cv::Matx<_Tp, m, n>&
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
  dataType.
    define_method("_dump_data", [](const cv::Scalar&) -> Rice::Hash
    {
      Rice::Hash result;
      return result;
    });
}

template<typename _Tp, int cn>
inline void Vec_Refinements()
{
  Data_Type<cv::Vec<_Tp, cn>> dataType;

  dataType.
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

  // First add refinements to Matx defined in matx-rb.cpp
  Matx_Refinements<float, 1, 2>();
  Matx_Refinements<double, 1, 2>();
  Matx_Refinements<float, 1, 3>();
  Matx_Refinements<double, 1, 3>();
  Matx_Refinements<float, 1, 4>();
  Matx_Refinements<double, 1, 4>();
  Matx_Refinements<float, 1, 6>();
  Matx_Refinements<double, 1, 6>();
  Matx_Refinements<float, 2, 1>();
  Matx_Refinements<double, 2, 1>();
  Matx_Refinements<float, 3, 1>();
  Matx_Refinements<double, 3, 1>();
  Matx_Refinements<float, 4, 1>();
  Matx_Refinements<double, 4, 1>();
  Matx_Refinements<float, 6, 1>();
  Matx_Refinements<double, 6, 1>();
  Matx_Refinements<float, 2, 2>();
  Matx_Refinements<double, 2, 2>();
  Matx_Refinements<float, 2, 3>();
  Matx_Refinements<double, 2, 3>();
  Matx_Refinements<float, 3, 2>();
  Matx_Refinements<double, 3, 2>();
  Matx_Refinements<float, 3, 3>();
  Matx_Refinements<double, 3, 3>();
  Matx_Refinements<float, 3, 4>();
  Matx_Refinements<double, 3, 4>();
  Matx_Refinements<float, 4, 3>();
  Matx_Refinements<double, 4, 3>();
  Matx_Refinements<float, 4, 4>();
  Matx_Refinements<double, 4, 4>();
  Matx_Refinements<float, 6, 6>();
  Matx_Refinements<double, 6, 6>();
  Matx_Refinements<unsigned char, 2, 1>();
  Matx_Refinements<unsigned char, 3, 1>();
  Matx_Refinements<unsigned char, 4, 1>();
  Matx_Refinements<short, 2, 1>();
  Matx_Refinements<short, 3, 1>();
  Matx_Refinements<short, 4, 1>();
  Matx_Refinements<unsigned short, 2, 1>();
  Matx_Refinements<unsigned short, 3, 1>();
  Matx_Refinements<unsigned short, 4, 1>();
  Matx_Refinements<int, 2, 1>();
  Matx_Refinements<int, 3, 1>();
  Matx_Refinements<int, 4, 1>();
  Matx_Refinements<int, 6, 1>();
  Matx_Refinements<int, 8, 1>();

  // Now add extra ones
  Matx_instantiate<unsigned char, 1, 1>(rb_mCv, "Matx11b");
  Matx_Refinements<unsigned char, 1, 1>();

  Matx_instantiate<unsigned char, 1, 2>(rb_mCv, "Matx12b");
  Matx_Refinements<unsigned char, 1, 2>();

  Matx_instantiate<unsigned char, 1, 3>(rb_mCv, "Matx13b");
  Matx_Refinements<unsigned char, 1, 3>();

  Matx_instantiate<unsigned char, 1, 4>(rb_mCv, "Matx14b");
  Matx_Refinements<unsigned char, 1, 4>();

  Matx_instantiate<short, 1, 1>(rb_mCv, "Matx11s");
  Matx_Refinements<short, 1, 1>();

  Matx_instantiate<short, 1, 2>(rb_mCv, "Matx12s");
  Matx_Refinements<short, 1, 2>();

  Matx_instantiate<short, 1, 3>(rb_mCv, "Matx13s");
  Matx_Refinements<short, 1, 3>();

  Matx_instantiate<short, 1, 4>(rb_mCv, "Matx14s");
  Matx_Refinements<short, 1, 4>();

  Matx_instantiate<unsigned short, 1, 1>(rb_mCv, "Matx11w");
  Matx_Refinements<unsigned short, 1, 1>();

  Matx_instantiate<unsigned short, 1, 2>(rb_mCv, "Matx12w");
  Matx_Refinements<unsigned short, 1, 2>();

  Matx_instantiate<unsigned short, 1, 3>(rb_mCv, "Matx13w");
  Matx_Refinements<unsigned short, 1, 3>();

  Matx_instantiate<unsigned short, 1, 4>(rb_mCv, "Matx14w");
  Matx_Refinements<unsigned short, 1, 4>();

  Matx_instantiate<int, 1, 1>(rb_mCv, "Matx11i");
  Matx_Refinements<int, 1, 1>();

  Matx_instantiate<int, 1, 2>(rb_mCv, "Matx12i");
  Matx_Refinements<int, 1, 2>();

  Matx_instantiate<int, 1, 3>(rb_mCv, "Matx13i");
  Matx_Refinements<int, 1, 3>();

  Matx_instantiate<int, 1, 4>(rb_mCv, "Matx14i");
  Matx_Refinements<int, 1, 4>();

  Matx_instantiate<int, 1, 6>(rb_mCv, "Matx16i");
  Matx_Refinements<int, 1, 6>();

  Matx_instantiate<int, 1, 8>(rb_mCv, "Matx18i");
  Matx_Refinements<int, 1, 8>();

  Matx_instantiate<float, 1, 1>(rb_mCv, "Matx11f");
  Matx_Refinements<float, 1, 1>();

  Matx_instantiate<float, 1, 8>(rb_mCv, "Matx18f");
  Matx_Refinements<float, 1, 8>();

  Matx_instantiate<float, 8, 1>(rb_mCv, "Matx81f");
  Matx_Refinements<float, 8, 1>();

  Matx_instantiate<double, 1, 1>(rb_mCv, "Matx11d");
  Matx_Refinements<double, 1, 1>();

  Matx_instantiate<double, 1, 8>(rb_mCv, "Matx18d");
  Matx_Refinements<double, 1, 8>();

  Matx_instantiate<double, 8, 1>(rb_mCv, "Matx81d");
  Matx_Refinements<double, 8, 1>();

  Matx_instantiate<int64, 1, 1>(rb_mCv, "Matx11l");
  Matx_Refinements<int64, 1, 1>();

  Matx_instantiate<int64, 1, 2>(rb_mCv, "Matx12l");
  Matx_Refinements<int64, 1, 2>();

  Matx_instantiate<int64, 2, 1>(rb_mCv, "Matx21l");
  Matx_Refinements<int64, 2, 1>();

  // Vecs defined in matx-rb.cpp
  Vec_Refinements<unsigned char, 2>();
  Vec_Refinements<unsigned char, 3>();
  Vec_Refinements<unsigned char, 4>();
  Vec_Refinements<short, 2>();
  Vec_Refinements<short, 3>();
  Vec_Refinements<short, 4>();
  Vec_Refinements<unsigned short, 2>();
  Vec_Refinements<unsigned short, 3>();
  Vec_Refinements<unsigned short, 4>();
  Vec_Refinements<int, 2>();
  Vec_Refinements<int, 3>();
  Vec_Refinements<int, 4>();
  Vec_Refinements<int, 6>();
  Vec_Refinements<int, 8>();
  Vec_Refinements<float, 2>();
  Vec_Refinements<float, 3>();
  Vec_Refinements<float, 4>();
  Vec_Refinements<float, 6>();
  Vec_Refinements<double, 2>();
  Vec_Refinements<double, 3>();
  Vec_Refinements<double, 4>();
  Vec_Refinements<double, 6>();

  // These Vecs are generated while compiling and thus must be defined 
  Vec_instantiate<unsigned char, 1>(rb_mCv, "Vec1b");
  Vec_Refinements<unsigned char, 1>();

  Vec_instantiate<short, 1>(rb_mCv, "Vec1s");
  Vec_Refinements<short, 1>();

  Vec_instantiate<unsigned short, 1>(rb_mCv, "Vec1w");
  Vec_Refinements<unsigned short, 1>();

  Vec_instantiate<int, 1>(rb_mCv, "Vec1i");
  Vec_Refinements<int, 1>();

  Vec_instantiate<int64, 1>(rb_mCv, "Vec1l");
  Vec_Refinements<int64, 1>();

  Vec_instantiate<int64, 2>(rb_mCv, "Vec2l");
  Vec_Refinements<int64, 1>();

  Vec_instantiate<float, 1>(rb_mCv, "Vec1f");
  Vec_Refinements<float, 1>();

  Vec_instantiate<float, 8>(rb_mCv, "Vec8f");
  Vec_Refinements<float, 1>();

  Vec_instantiate<double, 1>(rb_mCv, "Vec1d");
  Vec_Refinements<double, 1>();

  Vec_instantiate<double, 8>(rb_mCv, "Vec8d");
  Vec_Refinements<double, 1>();

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
  //define_vector<cv::Vec2l>(u8"Vector≺Cv꞉꞉Vec2l≻");

  // And just in case use the actual underlying names
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
