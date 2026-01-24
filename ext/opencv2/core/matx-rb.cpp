#include <opencv2/core.hpp> // Manual
#include <opencv2/core/matx.hpp>
#include "traits-rb.hpp" // Manual
#include "matx-rb.hpp"

using namespace Rice;

// Shared via extern
Rice::Class rb_cMatx44d;

// Manual
namespace cv
{
  typedef Vec<uchar, 1> Vec1b;
  typedef Vec<short, 1> Vec1s;
  typedef Vec<ushort, 1> Vec1w;
  typedef Vec<int, 1> Vec1i;
  typedef Vec<float, 1> Vec1f;
  typedef Vec<double, 1> Vec1d;
  typedef Vec<int64, 2> Vec2l;
}

template<typename Data_Type_T, typename _Tp, int m, int n>
inline void Matx_builder(Data_Type_T& klass)
{
  klass.
    // TODO - These block methods defined below
    // define_constant("Rows", (int)cv::Matx<_Tp, m, n>::rows).
    //define_constant("Cols", (int)cv::Matx<_Tp, m, n>::cols).
    //define_constant("Channels", (int)cv::Matx<_Tp, m, n>::channels).
    //define_constant("Shortdim", (int)cv::Matx<_Tp, m, n>::shortdim).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>>());

  if constexpr (m * n == 1)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp>(),
      Arg("v0"));
  }

  if constexpr (m * n == 2)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"));
  }

  if constexpr (m * n == 3)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"));
  }

  if constexpr (m * n == 4)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"));
  }

  if constexpr (m * n == 5)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"));
  }

  if constexpr (m * n == 6)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"));
  }

  if constexpr (m * n == 7)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"));
  }

  if constexpr (m * n == 8)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"));
  }

  if constexpr (m * n == 9)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"));
  }

  if constexpr (m * n == 10)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"));
  }

  if constexpr (m * n == 12)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"));
  }

  if constexpr (m * n == 14)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"));
  }

  if constexpr (m * n == 16)
  {
    klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15"));
  }

  klass.
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const _Tp*>(),
      Arg("vals")).
    define_method("dot", &cv::Matx<_Tp, m, n>::dot,
      Arg("v")).
    define_method("ddot", &cv::Matx<_Tp, m, n>::ddot,
      Arg("v")).
    define_method("row", &cv::Matx<_Tp, m, n>::row,
      Arg("i")).
    define_method("col", &cv::Matx<_Tp, m, n>::col,
      Arg("i")).
    template define_method<typename cv::Matx<_Tp, m, n>::diag_type(cv::Matx<_Tp, m, n>::*)() const>("diag", &cv::Matx<_Tp, m, n>::diag).
    define_method("t", &cv::Matx<_Tp, m, n>::t);

  // inv and solve only work with floating point types
  if constexpr (std::is_floating_point_v<_Tp>)
  {
    klass.
      define_method("inv", &cv::Matx<_Tp, m, n>::inv,
        Arg("method") = static_cast<int>(cv::DECOMP_LU), ArgBuffer("p_is_ok") = static_cast<bool*>(NULL)).
      template define_method<cv::Vec<_Tp, n>(cv::Matx<_Tp, m, n>::*)(const cv::Vec<_Tp, m>&, int) const>("solve", &cv::Matx<_Tp, m, n>::solve,
        Arg("rhs"), Arg("method"));
  }

  klass.
    define_method("mul", &cv::Matx<_Tp, m, n>::mul,
      Arg("a")).
    define_method("div", &cv::Matx<_Tp, m, n>::div,
      Arg("a")).
    template define_method<const _Tp&(cv::Matx<_Tp, m, n>::*)(int, int) const>("call", &cv::Matx<_Tp, m, n>::operator(),
      Arg("row"), Arg("col"));

  if constexpr (m == 1 || n == 1)
  {
    klass.
      template define_method<const _Tp& (cv::Matx<_Tp, m, n>::*)(int) const>("call", &cv::Matx<_Tp, m, n>::operator(),
        Arg("i")).
      template define_method<_Tp& (cv::Matx<_Tp, m, n>::*)(int)>("call", &cv::Matx<_Tp, m, n>::operator(),
        Arg("i")).
      template define_method<const _Tp& (cv::Matx<_Tp, m, n>::*)(int) const>("call", &cv::Matx<_Tp, m, n>::operator(),
        Arg("i")).
      template define_method<_Tp& (cv::Matx<_Tp, m, n>::*)(int)>("call", &cv::Matx<_Tp, m, n>::operator(),
        Arg("i"));
  }

  klass.
    template define_method<_Tp&(cv::Matx<_Tp, m, n>::*)(int, int)>("call", &cv::Matx<_Tp, m, n>::operator(),
      Arg("row"), Arg("col")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_AddOp>(),
      Arg("a"), Arg("b"), Arg("arg_2")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_SubOp>(),
      Arg("a"), Arg("b"), Arg("arg_2")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_MulOp>(),
      Arg("a"), Arg("b"), Arg("arg_2")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_DivOp>(),
      Arg("a"), Arg("b"), Arg("arg_2")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, n, m>&, cv::Matx_TOp>(),
      Arg("a"), Arg("arg_1")).
    define_singleton_function("all", &cv::Matx<_Tp, m, n>::all,
      Arg("alpha")).
    define_singleton_function("zeros", &cv::Matx<_Tp, m, n>::zeros).
    define_singleton_function("ones", &cv::Matx<_Tp, m, n>::ones).
    define_singleton_function("eye", &cv::Matx<_Tp, m, n>::eye).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)(const typename cv::Matx<_Tp, m, n>::diag_type&)>("diag", &cv::Matx<_Tp, m, n>::diag,
      Arg("d")).
    define_singleton_function("randu", &cv::Matx<_Tp, m, n>::randu,
      Arg("a"), Arg("b")).
    define_singleton_function("randn", &cv::Matx<_Tp, m, n>::randn,
      Arg("a"), Arg("b"));

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
};

template<typename Data_Type_T, typename _Tp, int cn>
inline void Vec_builder(Data_Type_T& klass)
{
  klass.define_constant("Channels", (int)cv::Vec<_Tp, cn>::channels).
    // TODO - not a valid Ruby identifer
    //define_constant("_dummy_enum_finalizer", (int)cv::Vec<_Tp, cn>::_dummy_enum_finalizer).
    define_constructor(Constructor<cv::Vec<_Tp, cn>>());

  if constexpr (cn == 1)
  {
    klass.define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp>(),
      Arg("v0"));
  }

  if constexpr (cn == 2)
  {
    klass.define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"));
  }

  if constexpr (cn == 3)
  {
    klass.define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"));
  }

  if constexpr (cn == 4)
  {
    klass.define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"));
  }

  if constexpr (cn == 5)
  {
    klass.define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"));
  }

  if constexpr (cn == 6)
  {
    klass.define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"));
  }

  if constexpr (cn == 7)
  {
    klass.define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"));
  }

  if constexpr (cn == 8)
  {
    klass.define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"));
  }

  if constexpr (cn == 9)
  {
    klass.define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"));
  }

  if constexpr (cn == 10)
  {
    klass.define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"));
  }

  if constexpr (cn == 14)
  {
    klass.define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"));
  }

  klass.
    define_constructor(Constructor<cv::Vec<_Tp, cn>, const _Tp*>(),
      Arg("values")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, const cv::Vec<_Tp, cn>&>(),
      Arg("v")).
    define_method("mul", &cv::Vec<_Tp, cn>::mul,
      Arg("v"));

    if constexpr ((cn == 2 || cn == 4) && (std::is_same_v<_Tp, float> || std::is_same_v<_Tp, double>))
    {
      klass.
        define_method("conj", &cv::Vec<_Tp, cn>::conj);
    }

    if constexpr (cn == 3)
    {
      klass.
        define_method("cross", &cv::Vec<_Tp, cn>::cross,
          Arg("v"));
    }

  klass.
    template define_method<const _Tp&(cv::Vec<_Tp, cn>::*)(int) const>("[]", &cv::Vec<_Tp, cn>::operator[],
      Arg("i")).
    template define_method<_Tp&(cv::Vec<_Tp, cn>::*)(int)>("[]", &cv::Vec<_Tp, cn>::operator[],
      Arg("i")).
    define_method("[]=", [](cv::Vec<_Tp, cn>&self, int index, _Tp & value)
    {
        self[index] = value;
    }).
    template define_method<const _Tp&(cv::Vec<_Tp, cn>::*)(int) const>("call", &cv::Vec<_Tp, cn>::operator(),
      Arg("i")).
    template define_method<_Tp&(cv::Vec<_Tp, cn>::*)(int)>("call", &cv::Vec<_Tp, cn>::operator(),
      Arg("i")).
    define_method("assign", &cv::Vec<_Tp, cn>::operator=,
      Arg("rhs")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, const cv::Matx<_Tp, cn, 1>&, const cv::Matx<_Tp, cn, 1>&, cv::Matx_AddOp>(),
      Arg("a"), Arg("b"), Arg("arg_2")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, const cv::Matx<_Tp, cn, 1>&, const cv::Matx<_Tp, cn, 1>&, cv::Matx_SubOp>(),
      Arg("a"), Arg("b"), Arg("arg_2")).
    define_singleton_function("all", &cv::Vec<_Tp, cn>::all,
      Arg("alpha")).
    define_singleton_function("ones", &cv::Vec<_Tp, cn>::ones).
    define_singleton_function("randn", &cv::Vec<_Tp, cn>::randn,
      Arg("a"), Arg("b")).
    define_singleton_function("randu", &cv::Vec<_Tp, cn>::randu,
      Arg("a"), Arg("b")).
    define_singleton_function("zeros", &cv::Vec<_Tp, cn>::zeros);

  // Manual
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
};

void Init_Core_Matx()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::Matx_AddOp> rb_cCvMatxAddOp = define_class_under<cv::Matx_AddOp>(rb_mCv, "MatxAddOp").
    define_constructor(Constructor<cv::Matx_AddOp>()).
    define_constructor(Constructor<cv::Matx_AddOp, const cv::Matx_AddOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx_SubOp> rb_cCvMatxSubOp = define_class_under<cv::Matx_SubOp>(rb_mCv, "MatxSubOp").
    define_constructor(Constructor<cv::Matx_SubOp>()).
    define_constructor(Constructor<cv::Matx_SubOp, const cv::Matx_SubOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx_ScaleOp> rb_cCvMatxScaleOp = define_class_under<cv::Matx_ScaleOp>(rb_mCv, "MatxScaleOp").
    define_constructor(Constructor<cv::Matx_ScaleOp>()).
    define_constructor(Constructor<cv::Matx_ScaleOp, const cv::Matx_ScaleOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx_MulOp> rb_cCvMatxMulOp = define_class_under<cv::Matx_MulOp>(rb_mCv, "MatxMulOp").
    define_constructor(Constructor<cv::Matx_MulOp>()).
    define_constructor(Constructor<cv::Matx_MulOp, const cv::Matx_MulOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx_DivOp> rb_cCvMatxDivOp = define_class_under<cv::Matx_DivOp>(rb_mCv, "MatxDivOp").
    define_constructor(Constructor<cv::Matx_DivOp>()).
    define_constructor(Constructor<cv::Matx_DivOp, const cv::Matx_DivOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx_MatMulOp> rb_cCvMatxMatMulOp = define_class_under<cv::Matx_MatMulOp>(rb_mCv, "MatxMatMulOp").
    define_constructor(Constructor<cv::Matx_MatMulOp>()).
    define_constructor(Constructor<cv::Matx_MatMulOp, const cv::Matx_MatMulOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx_TOp> rb_cCvMatxTOp = define_class_under<cv::Matx_TOp>(rb_mCv, "MatxTOp").
    define_constructor(Constructor<cv::Matx_TOp>()).
    define_constructor(Constructor<cv::Matx_TOp, const cv::Matx_TOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx<float, 1, 2>> rb_cMatx12f = define_class_under<cv::Matx<float, 1, 2>>(rb_mCv, "Matx12f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 2>>, float, 1, 2>);

  Rice::Data_Type<cv::Matx<double, 1, 2>> rb_cMatx12d = define_class_under<cv::Matx<double, 1, 2>>(rb_mCv, "Matx12d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 2>>, double, 1, 2>);

  Rice::Data_Type<cv::Matx<float, 1, 3>> rb_cMatx13f = define_class_under<cv::Matx<float, 1, 3>>(rb_mCv, "Matx13f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 3>>, float, 1, 3>);

  Rice::Data_Type<cv::Matx<double, 1, 3>> rb_cMatx13d = define_class_under<cv::Matx<double, 1, 3>>(rb_mCv, "Matx13d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 3>>, double, 1, 3>);

  Rice::Data_Type<cv::Matx<float, 1, 4>> rb_cMatx14f = define_class_under<cv::Matx<float, 1, 4>>(rb_mCv, "Matx14f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 4>>, float, 1, 4>);

  Rice::Data_Type<cv::Matx<double, 1, 4>> rb_cMatx14d = define_class_under<cv::Matx<double, 1, 4>>(rb_mCv, "Matx14d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 4>>, double, 1, 4>);

  Rice::Data_Type<cv::Matx<float, 1, 6>> rb_cMatx16f = define_class_under<cv::Matx<float, 1, 6>>(rb_mCv, "Matx16f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 6>>, float, 1, 6>);

  Rice::Data_Type<cv::Matx<double, 1, 6>> rb_cMatx16d = define_class_under<cv::Matx<double, 1, 6>>(rb_mCv, "Matx16d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 6>>, double, 1, 6>);

  Rice::Data_Type<cv::Matx<float, 2, 2>> rb_cMatx22f = define_class_under<cv::Matx<float, 2, 2>>(rb_mCv, "Matx22f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 2, 2>>, float, 2, 2>);

  Rice::Data_Type<cv::Matx<double, 2, 2>> rb_cMatx22d = define_class_under<cv::Matx<double, 2, 2>>(rb_mCv, "Matx22d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 2, 2>>, double, 2, 2>);

  Rice::Data_Type<cv::Matx<float, 2, 3>> rb_cMatx23f = define_class_under<cv::Matx<float, 2, 3>>(rb_mCv, "Matx23f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 2, 3>>, float, 2, 3>);

  Rice::Data_Type<cv::Matx<double, 2, 3>> rb_cMatx23d = define_class_under<cv::Matx<double, 2, 3>>(rb_mCv, "Matx23d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 2, 3>>, double, 2, 3>);

  Rice::Data_Type<cv::Matx<float, 3, 2>> rb_cMatx32f = define_class_under<cv::Matx<float, 3, 2>>(rb_mCv, "Matx32f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 2>>, float, 3, 2>);

  Rice::Data_Type<cv::Matx<double, 3, 2>> rb_cMatx32d = define_class_under<cv::Matx<double, 3, 2>>(rb_mCv, "Matx32d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 3, 2>>, double, 3, 2>);

  Rice::Data_Type<cv::Matx<float, 3, 3>> rb_cMatx33f = define_class_under<cv::Matx<float, 3, 3>>(rb_mCv, "Matx33f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 3>>, float, 3, 3>);

  Rice::Data_Type<cv::Matx<double, 3, 3>> rb_cMatx33d = define_class_under<cv::Matx<double, 3, 3>>(rb_mCv, "Matx33d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 3, 3>>, double, 3, 3>);

  Rice::Data_Type<cv::Matx<float, 3, 4>> rb_cMatx34f = define_class_under<cv::Matx<float, 3, 4>>(rb_mCv, "Matx34f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 4>>, float, 3, 4>);

  Rice::Data_Type<cv::Matx<double, 3, 4>> rb_cMatx34d = define_class_under<cv::Matx<double, 3, 4>>(rb_mCv, "Matx34d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 3, 4>>, double, 3, 4>);

  Rice::Data_Type<cv::Matx<float, 4, 3>> rb_cMatx43f = define_class_under<cv::Matx<float, 4, 3>>(rb_mCv, "Matx43f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 4, 3>>, float, 4, 3>);

  Rice::Data_Type<cv::Matx<double, 4, 3>> rb_cMatx43d = define_class_under<cv::Matx<double, 4, 3>>(rb_mCv, "Matx43d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 4, 3>>, double, 4, 3>);

  Rice::Data_Type<cv::Matx<float, 4, 4>> rb_cMatx44f = define_class_under<cv::Matx<float, 4, 4>>(rb_mCv, "Matx44f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 4, 4>>, float, 4, 4>);

  rb_cMatx44d = define_class_under<cv::Matx<double, 4, 4>>(rb_mCv, "Matx44d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 4, 4>>, double, 4, 4>);

  Rice::Data_Type<cv::Matx<float, 6, 6>> rb_cMatx66f = define_class_under<cv::Matx<float, 6, 6>>(rb_mCv, "Matx66f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 6, 6>>, float, 6, 6>);

  Rice::Data_Type<cv::Matx<double, 6, 6>> rb_cMatx66d = define_class_under<cv::Matx<double, 6, 6>>(rb_mCv, "Matx66d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 6, 6>>, double, 6, 6>);

  // Manual
  Rice::Data_Type<cv::Matx<unsigned char, 1, 1>> rb_cMatx11b = define_class_under<cv::Matx<unsigned char, 1, 1>>(rb_mCv, "Matx11b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 1, 1>>, unsigned char, 1, 1>);

  Rice::Data_Type<cv::Matx<unsigned char, 1, 2>> rb_cMatx12b = define_class_under<cv::Matx<unsigned char, 1, 2 >>(rb_mCv, "Matx12b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 1, 2>>, unsigned char, 1, 2>);

  Rice::Data_Type<cv::Matx<unsigned char, 1, 3>> rb_cMatx13b = define_class_under<cv::Matx<unsigned char, 1, 3 >>(rb_mCv, "Matx13b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 1, 3>>, unsigned char, 1, 3>);

  Rice::Data_Type<cv::Matx<unsigned char, 1, 4>> rb_cMatx14b = define_class_under<cv::Matx<unsigned char, 1, 4 >>(rb_mCv, "Matx14b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 1, 4>>, unsigned char, 1, 4>);

  Rice::Data_Type<cv::Matx<unsigned char, 2, 1>> rb_cMatx21b = define_class_under<cv::Matx<unsigned char, 2, 1>>(rb_mCv, "Matx21b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 2, 1>>, unsigned char, 2, 1>);
  
  Rice::Data_Type<cv::Vec<uchar, 2>> rb_cVec2b = define_class_under<cv::Vec<uchar, 2>, cv::Matx<unsigned char, 2, 1>>(rb_mCv, "Vec2b").
    define(&Vec_builder<Data_Type<cv::Vec<uchar, 2>>, unsigned char, 2>);

  Rice::Data_Type<cv::Matx<unsigned char, 3, 1>> rb_cMatx31b = define_class_under<cv::Matx<unsigned char, 3, 1>>(rb_mCv, "Matx31b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 3, 1>>, unsigned char, 3, 1>);

  Rice::Data_Type<cv::Vec<uchar, 3>> rb_cVec3b = define_class_under<cv::Vec<uchar, 3>, cv::Matx<unsigned char, 3, 1>>(rb_mCv, "Vec3b").
    define(&Vec_builder<Data_Type<cv::Vec<uchar, 3>>, unsigned char, 3>);

  Rice::Data_Type<cv::Matx<unsigned char, 4, 1>> rb_cMatx41b = define_class_under<cv::Matx<unsigned char, 4, 1>>(rb_mCv, "Matx41b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 4, 1>>, unsigned char, 4, 1>);

  Rice::Data_Type<cv::Vec<uchar, 4>> rb_cVec4b = define_class_under<cv::Vec<uchar, 4>, cv::Matx<unsigned char, 4, 1>>(rb_mCv, "Vec4b").
    define(&Vec_builder<Data_Type<cv::Vec<uchar, 4>>, unsigned char, 4>);

  Rice::Data_Type<cv::Matx<short, 1, 1>> rb_cMatx11s = define_class_under<cv::Matx<short, 1, 1 >>(rb_mCv, "Matx11s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 1, 1>>, short, 1, 1>);

  Rice::Data_Type<cv::Matx<short, 1, 2>> rb_cMatx12s = define_class_under<cv::Matx<short, 1, 2 >>(rb_mCv, "Matx12s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 1, 2>>, short, 1, 2>);

  Rice::Data_Type<cv::Matx<short, 1, 3>> rb_cMatx13s = define_class_under<cv::Matx<short, 1, 3 >>(rb_mCv, "Matx13s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 1, 3>>, short, 1, 3>);

  Rice::Data_Type<cv::Matx<short, 1, 4>> rb_cMatx14s = define_class_under<cv::Matx<short, 1, 4 >>(rb_mCv, "Matx14s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 1, 4>>, short, 1, 4>);

  Rice::Data_Type<cv::Matx<short, 2, 1>> rb_cMatx21s = define_class_under<cv::Matx<short, 2, 1>>(rb_mCv, "Matx21s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 2, 1>>, short, 2, 1>);

  Rice::Data_Type<cv::Vec<short, 2>> rb_cVec2s = define_class_under<cv::Vec<short, 2>, cv::Matx<short, 2, 1>>(rb_mCv, "Vec2s").
    define(&Vec_builder<Data_Type<cv::Vec<short, 2>>, short, 2>);

  Rice::Data_Type<cv::Matx<short, 3, 1>> rb_cMatx31s = define_class_under<cv::Matx<short, 3, 1>>(rb_mCv, "Matx31s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 3, 1>>, short, 3, 1>);
  Rice::Data_Type<cv::Vec<short, 3>> rb_cVec3s = define_class_under<cv::Vec<short, 3>, cv::Matx<short, 3, 1>>(rb_mCv, "Vec3s").
    define(&Vec_builder<Data_Type<cv::Vec<short, 3>>, short, 3>);

  Rice::Data_Type<cv::Matx<short, 4, 1>> rb_cMatx41s = define_class_under<cv::Matx<short, 4, 1>>(rb_mCv, "Matx41s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 4, 1>>, short, 4, 1>);

  Rice::Data_Type<cv::Vec<short, 4>> rb_cVec4s = define_class_under<cv::Vec<short, 4>, cv::Matx<short, 4, 1>>(rb_mCv, "Vec4s").
    define(&Vec_builder<Data_Type<cv::Vec<short, 4>>, short, 4>);

  Rice::Data_Type<cv::Vec<unsigned short, 1>> rb_cMatx11w = define_class_under<cv::Matx<unsigned short, 1, 1 >>(rb_mCv, "Matx11w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 1, 1>>, unsigned short, 1, 1>);

  Rice::Data_Type<cv::Vec<unsigned short, 2>> rb_cMatx12w = define_class_under<cv::Matx<unsigned short, 1, 2 >>(rb_mCv, "Matx12w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 1, 2>>, unsigned short, 1, 2>);

  Rice::Data_Type<cv::Vec<unsigned short, 3>> rb_cMatx13w = define_class_under<cv::Matx<unsigned short, 1, 3 >>(rb_mCv, "Matx13w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 1, 3>>, unsigned short, 1, 3>);

  Rice::Data_Type<cv::Vec<unsigned short, 4>> rb_cMatx14w = define_class_under<cv::Matx<unsigned short, 1, 4 >>(rb_mCv, "Matx14w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 1, 4>>, unsigned short, 1, 4>);

  Rice::Data_Type<cv::Matx<unsigned short, 2, 1>> rb_cMatx21w = define_class_under<cv::Matx<unsigned short, 2, 1>>(rb_mCv, "Matx21w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 2, 1>>, unsigned short, 2, 1>);
    
  Rice::Data_Type<cv::Vec<ushort, 2>> rb_cVec2w = define_class_under<cv::Vec<ushort, 2>, cv::Matx<unsigned short, 2, 1>>(rb_mCv, "Vec2w").
    define(&Vec_builder<Data_Type<cv::Vec<ushort, 2>>, unsigned short, 2>);

  Rice::Data_Type<cv::Matx<unsigned short, 3, 1>> rb_cMatx31w = define_class_under<cv::Matx<unsigned short, 3, 1>>(rb_mCv, "Matx31w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 3, 1>>, unsigned short, 3, 1>);

  Rice::Data_Type<cv::Vec<ushort, 3>> rb_cVec3w = define_class_under<cv::Vec<ushort, 3>, cv::Matx<unsigned short, 3, 1>>(rb_mCv, "Vec3w").
    define(&Vec_builder<Data_Type<cv::Vec<ushort, 3>>, unsigned short, 3>);

  Rice::Data_Type<cv::Matx<unsigned short, 4, 1>> rb_cMatx41w = define_class_under<cv::Matx<unsigned short, 4, 1>>(rb_mCv, "Matx41w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 4, 1>>, unsigned short, 4, 1>);

  Rice::Data_Type<cv::Vec<ushort, 4>> rb_cVec4w = define_class_under<cv::Vec<ushort, 4>, cv::Matx<unsigned short, 4, 1>>(rb_mCv, "Vec4w").
    define(&Vec_builder<Data_Type<cv::Vec<ushort, 4>>, unsigned short, 4>);

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

  Rice::Data_Type<cv::Matx<int, 2, 1>> rb_cMatx21i = define_class_under<cv::Matx<int, 2, 1>>(rb_mCv, "Matx21i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 2, 1>>, int, 2, 1>);

  Rice::Data_Type<cv::Vec<int, 2>> rb_cVec2i = define_class_under<cv::Vec<int, 2>, cv::Matx<int, 2, 1>>(rb_mCv, "Vec2i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 2>>, int, 2>);

  Rice::Data_Type<cv::Matx<int, 3, 1>> rb_cMatx31i = define_class_under<cv::Matx<int, 3, 1>>(rb_mCv, "Matx31i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 3, 1>>, int, 3, 1>);

  Rice::Data_Type<cv::Vec<int, 3>> rb_cVec3i = define_class_under<cv::Vec<int, 3>, cv::Matx<int, 3, 1>>(rb_mCv, "Vec3i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 3>>, int, 3>);

  Rice::Data_Type<cv::Matx<int, 4, 1>> rb_cMatx41i = define_class_under<cv::Matx<int, 4, 1>>(rb_mCv, "Matx41i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 4, 1>>, int, 4, 1>);

  Rice::Data_Type<cv::Vec<int, 4>> rb_cVec4i = define_class_under<cv::Vec<int, 4>, cv::Matx<int, 4, 1>>(rb_mCv, "Vec4i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 4>>, int, 4>);

  Rice::Data_Type<cv::Matx<int, 6, 1>> rb_cMatx61i = define_class_under<cv::Matx<int, 6, 1>>(rb_mCv, "Matx61i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 6, 1>>, int, 6, 1>);

  Rice::Data_Type<cv::Vec<int, 6>> rb_cVec6i = define_class_under<cv::Vec<int, 6>, cv::Matx<int, 6, 1>>(rb_mCv, "Vec6i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 6>>, int, 6>);

  Rice::Data_Type<cv::Matx<int, 8, 1>> rb_cMatx81i = define_class_under<cv::Matx<int, 8, 1>>(rb_mCv, "Matx81i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 8, 1>>, int, 8, 1>);

  Rice::Data_Type<cv::Vec<int, 8>> rb_cVec8i = define_class_under<cv::Vec<int, 8>, cv::Matx<int, 8, 1>>(rb_mCv, "Vec8i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 8>>, int, 8>);

  Rice::Data_Type<cv::Matx<float, 2, 1>> rb_cMatx21f = define_class_under<cv::Matx<float, 2, 1>>(rb_mCv, "Matx21f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 2, 1>>, float, 2, 1>);

  Rice::Data_Type<cv::Vec<float, 2>> rb_cVec2f = define_class_under<cv::Vec<float, 2>, cv::Matx<float, 2, 1>>(rb_mCv, "Vec2f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 2>>, float, 2>);

  Rice::Data_Type<cv::Matx<float, 3, 1>> rb_cMatx31f = define_class_under<cv::Matx<float, 3, 1>>(rb_mCv, "Matx31f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 1>>, float, 3, 1>);

  Rice::Data_Type<cv::Vec<float, 3>> rb_cVec3f = define_class_under<cv::Vec<float, 3>, cv::Matx<float, 3, 1>>(rb_mCv, "Vec3f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 3>>, float, 3>);

  Rice::Data_Type<cv::Matx<float, 4, 1>> rb_cMatx41f = define_class_under<cv::Matx<float, 4, 1>>(rb_mCv, "Matx41f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 4, 1>>, float, 4, 1>);

  Rice::Data_Type<cv::Vec<float, 4>> rb_cVec4f = define_class_under<cv::Vec<float, 4>, cv::Matx<float, 4, 1>>(rb_mCv, "Vec4f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 4>>, float, 4>);

  Rice::Data_Type<cv::Matx<float, 6, 1>> rb_cMatx61f = define_class_under<cv::Matx<float, 6, 1>>(rb_mCv, "Matx61f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 6, 1>>, float, 6, 1>);

  Rice::Data_Type<cv::Vec<float, 6>> rb_cVec6f = define_class_under<cv::Vec<float, 6>, cv::Matx<float, 6, 1>>(rb_mCv, "Vec6f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 6>>, float, 6>);

  // Needed by DualQuat
  Rice::Data_Type<cv::Matx<float, 8, 1>> rb_cMatx81f = define_class_under<cv::Matx<float, 8, 1>>(rb_mCv, "Matx81f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 8, 1>>, float, 8, 1>);

  Rice::Data_Type<cv::Vec<float, 8>> rb_cVec8f = define_class_under<cv::Vec<float, 8>, cv::Matx<float, 8, 1>>(rb_mCv, "Vec8f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 8>>, float, 8>);

  Rice::Data_Type<cv::Matx<double, 2, 1>> rb_cMatx21d = define_class_under<cv::Matx<double, 2, 1>>(rb_mCv, "Matx21d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 2, 1>>, double, 2, 1>);

  Rice::Data_Type<cv::Vec<double, 2>> rb_cVec2d = define_class_under<cv::Vec<double, 2>, cv::Matx<double, 2, 1>>(rb_mCv, "Vec2d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 2>>, double, 2>);

  Rice::Data_Type<cv::Matx<double, 3, 1>> rb_cMatx31d = define_class_under<cv::Matx<double, 3, 1>>(rb_mCv, "Matx31d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 3, 1>>, double, 3, 1>);
  Rice::Data_Type<cv::Vec<double, 3>> rb_cVec3d = define_class_under<cv::Vec<double, 3>, cv::Matx<double, 3, 1>>(rb_mCv, "Vec3d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 3>>, double, 3>);

  Rice::Data_Type<cv::Matx<double, 4, 1>> rb_cMatx41d = define_class_under<cv::Matx<double, 4, 1>>(rb_mCv, "Matx41d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 4, 1>>, double, 4, 1>);

  Rice::Data_Type<cv::Vec<double, 4>> rb_cVec4d = define_class_under<cv::Vec<double, 4>, cv::Matx<double, 4, 1>>(rb_mCv, "Vec4d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 4>>, double, 4>);

  Rice::Data_Type<cv::Matx<double, 6, 1>> rb_cMatx61d = define_class_under<cv::Matx<double, 6, 1>>(rb_mCv, "Matx61d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 6, 1>>, double, 6, 1>);

  Rice::Data_Type<cv::Vec<double, 6>> rb_cVec6d = define_class_under<cv::Vec<double, 6>, cv::Matx<double, 6, 1>>(rb_mCv, "Vec6d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 6>>, double, 6>);

  // Manually added
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