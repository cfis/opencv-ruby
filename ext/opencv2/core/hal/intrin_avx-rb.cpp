#include <opencv2/core/hal/intrin_avx.hpp>
#include "intrin_avx-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvVFloat32x8;
Rice::Class rb_cCvVFloat64x4;
Rice::Class rb_cCvVInt16x16;
Rice::Class rb_cCvVInt32x8;
Rice::Class rb_cCvVInt64x4;
Rice::Class rb_cCvVInt8x32;
Rice::Class rb_cCvVUint16x16;
Rice::Class rb_cCvVUint32x8;
Rice::Class rb_cCvVUint64x4;
Rice::Class rb_cCvVUint8x32;

void Init_IntrinAvx()
{
  Class(rb_cObject).define_constant("CV_SIMD256", CV_SIMD256);
  
  Class(rb_cObject).define_constant("CV_SIMD256_64F", CV_SIMD256_64F);
  
  Class(rb_cObject).define_constant("CV_SIMD256_FP16", CV_SIMD256_FP16);
  
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_singleton_attr("M256i", &cv::__m256i);
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("_v256_combine", &cv::_v256_combine,
    Arg("lo"), Arg("hi"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("_v256_combine", &cv::_v256_combine,
    Arg("lo"), Arg("hi"));
  
  rb_mCv.define_module_function("_v_cvtsi256_si32", &cv::_v_cvtsi256_si32,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("_v256_shuffle_odd_64", &cv::_v256_shuffle_odd_64,
    Arg("v"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("_v256_shuffle_odd_64", &cv::_v256_shuffle_odd_64,
    Arg("v"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("_v256_extract_high", &cv::_v256_extract_high,
    Arg("v"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("_v256_extract_high", &cv::_v256_extract_high,
    Arg("v"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("_v256_extract_high", &cv::_v256_extract_high,
    Arg("v"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("_v256_extract_low", &cv::_v256_extract_low,
    Arg("v"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("_v256_extract_low", &cv::_v256_extract_low,
    Arg("v"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("_v256_extract_low", &cv::_v256_extract_low,
    Arg("v"));
  
  rb_mCv.define_module_function("_v256_packs_epu32", &cv::_v256_packs_epu32,
    Arg("a"), Arg("b"));
  
  rb_cCvVUint8x32 = define_class_under<cv::v_uint8x32>(rb_mCv, "VUint8x32").
    define_attr("val", &cv::v_uint8x32::val).
    define_constructor(Constructor<cv::v_uint8x32, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint8x32, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15"), Arg("v16"), Arg("v17"), Arg("v18"), Arg("v19"), Arg("v20"), Arg("v21"), Arg("v22"), Arg("v23"), Arg("v24"), Arg("v25"), Arg("v26"), Arg("v27"), Arg("v28"), Arg("v29"), Arg("v30"), Arg("v31")).
    define_constructor(Constructor<cv::v_uint8x32>()).
    define_method("get0", &cv::v_uint8x32::get0);
  
  rb_cCvVUint8x32.define_constant("Nlanes", (int)cv::v_uint8x32::nlanes);
  
  rb_cCvVInt8x32 = define_class_under<cv::v_int8x32>(rb_mCv, "VInt8x32").
    define_attr("val", &cv::v_int8x32::val).
    define_constructor(Constructor<cv::v_int8x32, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int8x32, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15"), Arg("v16"), Arg("v17"), Arg("v18"), Arg("v19"), Arg("v20"), Arg("v21"), Arg("v22"), Arg("v23"), Arg("v24"), Arg("v25"), Arg("v26"), Arg("v27"), Arg("v28"), Arg("v29"), Arg("v30"), Arg("v31")).
    define_constructor(Constructor<cv::v_int8x32>()).
    define_method("get0", &cv::v_int8x32::get0);
  
  rb_cCvVInt8x32.define_constant("Nlanes", (int)cv::v_int8x32::nlanes);
  
  rb_cCvVUint16x16 = define_class_under<cv::v_uint16x16>(rb_mCv, "VUint16x16").
    define_attr("val", &cv::v_uint16x16::val).
    define_constructor(Constructor<cv::v_uint16x16, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint16x16, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).
    define_constructor(Constructor<cv::v_uint16x16>()).
    define_method("get0", &cv::v_uint16x16::get0);
  
  rb_cCvVUint16x16.define_constant("Nlanes", (int)cv::v_uint16x16::nlanes);
  
  rb_cCvVInt16x16 = define_class_under<cv::v_int16x16>(rb_mCv, "VInt16x16").
    define_attr("val", &cv::v_int16x16::val).
    define_constructor(Constructor<cv::v_int16x16, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int16x16, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).
    define_constructor(Constructor<cv::v_int16x16>()).
    define_method("get0", &cv::v_int16x16::get0);
  
  rb_cCvVInt16x16.define_constant("Nlanes", (int)cv::v_int16x16::nlanes);
  
  rb_cCvVUint32x8 = define_class_under<cv::v_uint32x8>(rb_mCv, "VUint32x8").
    define_attr("val", &cv::v_uint32x8::val).
    define_constructor(Constructor<cv::v_uint32x8, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint32x8, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_constructor(Constructor<cv::v_uint32x8>()).
    define_method("get0", &cv::v_uint32x8::get0);
  
  rb_cCvVUint32x8.define_constant("Nlanes", (int)cv::v_uint32x8::nlanes);
  
  rb_cCvVInt32x8 = define_class_under<cv::v_int32x8>(rb_mCv, "VInt32x8").
    define_attr("val", &cv::v_int32x8::val).
    define_constructor(Constructor<cv::v_int32x8, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int32x8, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_constructor(Constructor<cv::v_int32x8>()).
    define_method("get0", &cv::v_int32x8::get0);
  
  rb_cCvVInt32x8.define_constant("Nlanes", (int)cv::v_int32x8::nlanes);
  
  rb_cCvVFloat32x8 = define_class_under<cv::v_float32x8>(rb_mCv, "VFloat32x8").
    define_attr("val", &cv::v_float32x8::val).
    define_constructor(Constructor<cv::v_float32x8, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_float32x8, float, float, float, float, float, float, float, float>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_constructor(Constructor<cv::v_float32x8>()).
    define_method("get0", &cv::v_float32x8::get0);
  
  rb_cCvVFloat32x8.define_constant("Nlanes", (int)cv::v_float32x8::nlanes);
  
  rb_cCvVUint64x4 = define_class_under<cv::v_uint64x4>(rb_mCv, "VUint64x4").
    define_attr("val", &cv::v_uint64x4::val).
    define_constructor(Constructor<cv::v_uint64x4, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint64x4, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_constructor(Constructor<cv::v_uint64x4>()).
    define_method("get0", &cv::v_uint64x4::get0);
  
  rb_cCvVUint64x4.define_constant("Nlanes", (int)cv::v_uint64x4::nlanes);
  
  rb_cCvVInt64x4 = define_class_under<cv::v_int64x4>(rb_mCv, "VInt64x4").
    define_attr("val", &cv::v_int64x4::val).
    define_constructor(Constructor<cv::v_int64x4, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int64x4, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_constructor(Constructor<cv::v_int64x4>()).
    define_method("get0", &cv::v_int64x4::get0);
  
  rb_cCvVInt64x4.define_constant("Nlanes", (int)cv::v_int64x4::nlanes);
  
  rb_cCvVFloat64x4 = define_class_under<cv::v_float64x4>(rb_mCv, "VFloat64x4").
    define_attr("val", &cv::v_float64x4::val).
    define_constructor(Constructor<cv::v_float64x4, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_float64x4, double, double, double, double>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_constructor(Constructor<cv::v_float64x4>()).
    define_method("get0", &cv::v_float64x4::get0);
  
  rb_cCvVFloat64x4.define_constant("Nlanes", (int)cv::v_float64x4::nlanes);
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_float32x8&)>("v_reinterpret_as_f32", &cv::v_reinterpret_as_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_float64x4&)>("v_reinterpret_as_f32", &cv::v_reinterpret_as_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_float64x4&)>("v_reinterpret_as_f64", &cv::v_reinterpret_as_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_float32x8&)>("v_reinterpret_as_f64", &cv::v_reinterpret_as_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_float32x8&, const cv::v_float32x8&)>("v256_combine_diagonal", &cv::v256_combine_diagonal,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_float64x4&, const cv::v_float64x4&)>("v256_combine_diagonal", &cv::v256_combine_diagonal,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("v256_alignr_64", &cv::v256_alignr_64,
    Arg("a"), Arg("b"));
  
  rb_cCvVUint8x32.define_method("*", [](const cv::v_uint8x32& self, const cv::v_uint8x32& other) -> cv::v_uint8x32
  {
    return self * other;
  });
  
  rb_cCvVInt8x32.define_method("*", [](const cv::v_int8x32& self, const cv::v_int8x32& other) -> cv::v_int8x32
  {
    return self * other;
  });
  
  rb_cCvVUint16x16.define_method("*", [](const cv::v_uint16x16& self, const cv::v_uint16x16& other) -> cv::v_uint16x16
  {
    return self * other;
  });
  
  rb_cCvVInt16x16.define_method("*", [](const cv::v_int16x16& self, const cv::v_int16x16& other) -> cv::v_int16x16
  {
    return self * other;
  });
  
  rb_cCvVUint8x32.define_method("assign_multiply", [](cv::v_uint8x32& self, const cv::v_uint8x32& other) -> cv::v_uint8x32&
  {
    return self *= other;
  });
  
  rb_cCvVInt8x32.define_method("assign_multiply", [](cv::v_int8x32& self, const cv::v_int8x32& other) -> cv::v_int8x32&
  {
    return self *= other;
  });
  
  rb_cCvVUint16x16.define_method("assign_multiply", [](cv::v_uint16x16& self, const cv::v_uint16x16& other) -> cv::v_uint16x16&
  {
    return self *= other;
  });
  
  rb_cCvVInt16x16.define_method("assign_multiply", [](cv::v_int16x16& self, const cv::v_int16x16& other) -> cv::v_int16x16&
  {
    return self *= other;
  });
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_uint8x32&, const cv::v_uint8x32&)>("v_mul_wrap", &cv::v_mul_wrap,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int8x32(*)(const cv::v_int8x32&, const cv::v_int8x32&)>("v_mul_wrap", &cv::v_mul_wrap,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint8x32&, const cv::v_uint8x32&, cv::v_uint16x16&, cv::v_uint16x16&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int8x32&, const cv::v_int8x32&, cv::v_int16x16&, cv::v_int16x16&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int16x16&, const cv::v_int16x16&, cv::v_int32x8&, cv::v_int32x8&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint16x16&, const cv::v_uint16x16&, cv::v_uint32x8&, cv::v_uint32x8&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint32x8&, const cv::v_uint32x8&, cv::v_uint64x4&, cv::v_uint64x4&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<cv::v_int16x16(*)(const cv::v_int16x16&, const cv::v_int16x16&)>("v_mul_hi", &cv::v_mul_hi,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const cv::v_uint16x16&, const cv::v_uint16x16&)>("v_mul_hi", &cv::v_mul_hi,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("_mm256_srai_epi64xx", &cv::_mm256_srai_epi64xx,
    Arg("a"), Arg("imm"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_float32x8&)>("v_not_nan", &cv::v_not_nan,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_float64x4&)>("v_not_nan", &cv::v_not_nan,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_uint8x32&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int8x32(*)(const cv::v_int8x32&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const cv::v_uint16x16&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int16x16(*)(const cv::v_int16x16&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const cv::v_uint32x8&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int32x8&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_float32x8&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x4(*)(const cv::v_uint64x4&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int64x4(*)(const cv::v_int64x4&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_float64x4&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint8x32&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int8x32&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int32x8&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint32x8&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int16x16&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint16x16&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<float(*)(const cv::v_float32x8&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint64x4&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int64x4&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<double(*)(const cv::v_float64x4&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function("v_reduce_sum4", &cv::v_reduce_sum4,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint8x32&, const cv::v_uint8x32&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int8x32&, const cv::v_int8x32&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint16x16&, const cv::v_uint16x16&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int16x16&, const cv::v_int16x16&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint32x8&, const cv::v_uint32x8&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int32x8&, const cv::v_int32x8&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<float(*)(const cv::v_float32x8&, const cv::v_float32x8&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_uint8x32&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const cv::v_uint16x16&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const cv::v_uint32x8&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x4(*)(const cv::v_uint64x4&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_int8x32&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const cv::v_int16x16&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const cv::v_int32x8&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x4(*)(const cv::v_int64x4&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int8x32&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint8x32&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int16x16&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint16x16&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float32x8&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float64x4&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int32x8&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint32x8&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int64x4&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint64x4&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int8x32&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint8x32&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int16x16&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint16x16&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int32x8&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint32x8&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float32x8&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int64x4&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint64x4&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float64x4&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int32x8&, const cv::v_int32x8&, const cv::v_int32x8&)>("v_fma", &cv::v_fma,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int32x8&, const cv::v_int32x8&, const cv::v_int32x8&)>("v_muladd", &cv::v_muladd,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_float32x8&)>("v_invsqrt", &cv::v_invsqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_float64x4&)>("v_invsqrt", &cv::v_invsqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_float32x8&)>("v_abs", &cv::v_abs,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_float64x4&)>("v_abs", &cv::v_abs,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_uint8x32&, const cv::v_uint8x32&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const cv::v_uint16x16&, const cv::v_uint16x16&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const cv::v_uint32x8&, const cv::v_uint32x8&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_int8x32&, const cv::v_int8x32&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const cv::v_int16x16&, const cv::v_int16x16&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const cv::v_int32x8&, const cv::v_int32x8&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_float32x8&, const cv::v_float32x8&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_float64x4&, const cv::v_float64x4&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int8x32(*)(const cv::v_int8x32&, const cv::v_int8x32&)>("v_absdiffs", &cv::v_absdiffs,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int16x16(*)(const cv::v_int16x16&, const cv::v_int16x16&)>("v_absdiffs", &cv::v_absdiffs,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_float32x8&)>("v_round", &cv::v_round,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_float64x4&)>("v_round", &cv::v_round,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_float64x4&, const cv::v_float64x4&)>("v_round", &cv::v_round,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_float32x8&)>("v_trunc", &cv::v_trunc,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_float64x4&)>("v_trunc", &cv::v_trunc,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_float32x8&)>("v_floor", &cv::v_floor,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_float64x4&)>("v_floor", &cv::v_floor,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_float32x8&)>("v_ceil", &cv::v_ceil,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_float64x4&)>("v_ceil", &cv::v_ceil,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_int32x8&)>("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_float64x4&)>("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_float64x4&, const cv::v_float64x4&)>("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_int32x8&)>("v_cvt_f64", &cv::v_cvt_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_int32x8&)>("v_cvt_f64_high", &cv::v_cvt_f64_high,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_float32x8&)>("v_cvt_f64", &cv::v_cvt_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_float32x8&)>("v_cvt_f64_high", &cv::v_cvt_f64_high,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_int64x4&)>("v_cvt_f64", &cv::v_cvt_f64,
    Arg("v"));
  
  rb_mCv.define_module_function<cv::v_int8x32(*)(const int*, const int*)>("v256_lut", &cv::v256_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int8x32(*)(const int*, const int*)>("v256_lut_pairs", &cv::v256_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int8x32(*)(const int*, const int*)>("v256_lut_quads", &cv::v256_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const int*, const int*)>("v256_lut", &cv::v256_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const int*, const int*)>("v256_lut_pairs", &cv::v256_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const int*, const int*)>("v256_lut_quads", &cv::v256_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x16(*)(const short*, const int*)>("v256_lut", &cv::v256_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x16(*)(const short*, const int*)>("v256_lut_pairs", &cv::v256_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x16(*)(const short*, const int*)>("v256_lut_quads", &cv::v256_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const int*, const int*)>("v256_lut", &cv::v256_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const int*, const int*)>("v256_lut_pairs", &cv::v256_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const int*, const int*)>("v256_lut_quads", &cv::v256_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const int*, const int*)>("v256_lut", &cv::v256_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const int*, const int*)>("v256_lut_pairs", &cv::v256_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const int*, const int*)>("v256_lut_quads", &cv::v256_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const unsigned int*, const int*)>("v256_lut", &cv::v256_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const unsigned int*, const int*)>("v256_lut_pairs", &cv::v256_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const unsigned int*, const int*)>("v256_lut_quads", &cv::v256_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int64x4(*)(const int*, const int*)>("v256_lut", &cv::v256_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int64x4(*)(const int*, const int*)>("v256_lut_pairs", &cv::v256_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint64x4(*)(const int*, const int*)>("v256_lut", &cv::v256_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint64x4(*)(const int*, const int*)>("v256_lut_pairs", &cv::v256_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const float*, const int*)>("v256_lut", &cv::v256_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const float*, const int*)>("v256_lut_pairs", &cv::v256_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const float*, const int*)>("v256_lut_quads", &cv::v256_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const double*, const int*)>("v256_lut", &cv::v256_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const double*, const int*)>("v256_lut_pairs", &cv::v256_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const int*, const cv::v_int32x8&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const unsigned int*, const cv::v_int32x8&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const float*, const cv::v_int32x8&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const double*, const cv::v_int32x8&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<void(*)(const float*, const cv::v_int32x8&, cv::v_float32x8&, cv::v_float32x8&)>("v_lut_deinterleave", &cv::v_lut_deinterleave,
    Arg("tab"), Arg("idxvec"), Arg("x"), Arg("y"));
  
  rb_mCv.define_module_function<void(*)(const double*, const cv::v_int32x8&, cv::v_float64x4&, cv::v_float64x4&)>("v_lut_deinterleave", &cv::v_lut_deinterleave,
    Arg("tab"), Arg("idxvec"), Arg("x"), Arg("y"));
  
  rb_mCv.define_module_function<cv::v_int8x32(*)(const cv::v_int8x32&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_uint8x32&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int8x32(*)(const cv::v_int8x32&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_uint8x32&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int16x16(*)(const cv::v_int16x16&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const cv::v_uint16x16&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int16x16(*)(const cv::v_int16x16&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const cv::v_uint16x16&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int32x8&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const cv::v_uint32x8&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_float32x8&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int8x32(*)(const cv::v_int8x32&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_uint8x32&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int16x16(*)(const cv::v_int16x16&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const cv::v_uint16x16&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int32x8&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const cv::v_uint32x8&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const cv::v_float32x8&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int16x16&, const cv::v_int16x16&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int16x16&, const cv::v_int16x16&, const cv::v_int32x8&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x4(*)(const cv::v_int32x8&, const cv::v_int32x8&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x4(*)(const cv::v_int32x8&, const cv::v_int32x8&, const cv::v_int64x4&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const cv::v_uint8x32&, const cv::v_uint8x32&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const cv::v_uint8x32&, const cv::v_uint8x32&, const cv::v_uint32x8&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int8x32&, const cv::v_int8x32&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int8x32&, const cv::v_int8x32&, const cv::v_int32x8&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint64x4(*)(const cv::v_uint16x16&, const cv::v_uint16x16&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint64x4(*)(const cv::v_uint16x16&, const cv::v_uint16x16&, const cv::v_uint64x4&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x4(*)(const cv::v_int16x16&, const cv::v_int16x16&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x4(*)(const cv::v_int16x16&, const cv::v_int16x16&, const cv::v_int64x4&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_int32x8&, const cv::v_int32x8&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_int32x8&, const cv::v_int32x8&, const cv::v_float64x4&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int16x16&, const cv::v_int16x16&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int16x16&, const cv::v_int16x16&, const cv::v_int32x8&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x4(*)(const cv::v_int32x8&, const cv::v_int32x8&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x4(*)(const cv::v_int32x8&, const cv::v_int32x8&, const cv::v_int64x4&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const cv::v_uint8x32&, const cv::v_uint8x32&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const cv::v_uint8x32&, const cv::v_uint8x32&, const cv::v_uint32x8&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int8x32&, const cv::v_int8x32&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int8x32&, const cv::v_int8x32&, const cv::v_int32x8&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint64x4(*)(const cv::v_uint16x16&, const cv::v_uint16x16&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint64x4(*)(const cv::v_uint16x16&, const cv::v_uint16x16&, const cv::v_uint64x4&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x4(*)(const cv::v_int16x16&, const cv::v_int16x16&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x4(*)(const cv::v_int16x16&, const cv::v_int16x16&, const cv::v_int64x4&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_int32x8&, const cv::v_int32x8&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x4(*)(const cv::v_int32x8&, const cv::v_int32x8&, const cv::v_float64x4&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function("v_matmul", &cv::v_matmul,
    Arg("v"), Arg("m0"), Arg("m1"), Arg("m2"), Arg("m3"));
  
  rb_mCv.define_module_function("v_matmuladd", &cv::v_matmuladd,
    Arg("v"), Arg("m0"), Arg("m1"), Arg("m2"), Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int8x32(*)(const cv::v_int16x16&, const cv::v_int16x16&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_uint16x16&, const cv::v_uint16x16&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_int16x16&, const cv::v_int16x16&)>("v_pack_u", &cv::v_pack_u,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int16x16&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint16x16&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int16x16&)>("v_pack_u_store", &cv::v_pack_u_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int16x16(*)(const cv::v_int32x8&, const cv::v_int32x8&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const cv::v_uint32x8&, const cv::v_uint32x8&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x16(*)(const cv::v_int32x8&, const cv::v_int32x8&)>("v_pack_u", &cv::v_pack_u,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(short*, const cv::v_int32x8&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint32x8&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int32x8&)>("v_pack_u_store", &cv::v_pack_u_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x8(*)(const cv::v_uint64x4&, const cv::v_uint64x4&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x8(*)(const cv::v_int64x4&, const cv::v_int64x4&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint64x4&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int64x4&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_uint16x16&, const cv::v_uint16x16&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_uint32x8&, const cv::v_uint32x8&, const cv::v_uint32x8&, const cv::v_uint32x8&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<cv::v_uint8x32(*)(const cv::v_uint64x4&, const cv::v_uint64x4&, const cv::v_uint64x4&, const cv::v_uint64x4&, const cv::v_uint64x4&, const cv::v_uint64x4&, const cv::v_uint64x4&, const cv::v_uint64x4&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("e"), Arg("f"), Arg("g"), Arg("h"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint8x32&, cv::v_uint8x32&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint16x16&, cv::v_uint16x16&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const unsigned int*, cv::v_uint32x8&, cv::v_uint32x8&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint64x4&, cv::v_uint64x4&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint8x32&, cv::v_uint8x32&, cv::v_uint8x32&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint16x16&, cv::v_uint16x16&, cv::v_uint16x16&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const unsigned int*, cv::v_uint32x8&, cv::v_uint32x8&, cv::v_uint32x8&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint64x4&, cv::v_uint64x4&, cv::v_uint64x4&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint8x32&, cv::v_uint8x32&, cv::v_uint8x32&, cv::v_uint8x32&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint16x16&, cv::v_uint16x16&, cv::v_uint16x16&, cv::v_uint16x16&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const unsigned int*, cv::v_uint32x8&, cv::v_uint32x8&, cv::v_uint32x8&, cv::v_uint32x8&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint64x4&, cv::v_uint64x4&, cv::v_uint64x4&, cv::v_uint64x4&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint8x32&, const cv::v_uint8x32&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("x"), Arg("y"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint16x16&, const cv::v_uint16x16&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("x"), Arg("y"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint32x8&, const cv::v_uint32x8&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("x"), Arg("y"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint64x4&, const cv::v_uint64x4&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("x"), Arg("y"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint8x32&, const cv::v_uint8x32&, const cv::v_uint8x32&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint16x16&, const cv::v_uint16x16&, const cv::v_uint16x16&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint32x8&, const cv::v_uint32x8&, const cv::v_uint32x8&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint64x4&, const cv::v_uint64x4&, const cv::v_uint64x4&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint8x32&, const cv::v_uint8x32&, const cv::v_uint8x32&, const cv::v_uint8x32&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint16x16&, const cv::v_uint16x16&, const cv::v_uint16x16&, const cv::v_uint16x16&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint32x8&, const cv::v_uint32x8&, const cv::v_uint32x8&, const cv::v_uint32x8&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint64x4&, const cv::v_uint64x4&, const cv::v_uint64x4&, const cv::v_uint64x4&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<cv::v_float32x8(*)(const int*)>("v256_load_expand", &cv::v256_load_expand,
    Arg("ptr"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_float32x8&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function("v256_cleanup", &cv::v256_cleanup);

}