#include <opencv2/core/hal/intrin_lsx.hpp>
#include "intrin_lsx-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvVFloat32x4;
Rice::Class rb_cCvVFloat64x2;
Rice::Class rb_cCvVInt16x8;
Rice::Class rb_cCvVInt32x4;
Rice::Class rb_cCvVInt64x2;
Rice::Class rb_cCvVInt8x16;
Rice::Class rb_cCvVUint16x8;
Rice::Class rb_cCvVUint32x4;
Rice::Class rb_cCvVUint64x2;
Rice::Class rb_cCvVUint8x16;

void Init_IntrinLsx()
{
  Class(rb_cObject).define_constant("CV_SIMD128", CV_SIMD128);
  
  Class(rb_cObject).define_constant("CV_SIMD128_64F", CV_SIMD128_64F);
  
  Class(rb_cObject).define_constant("CV_SIMD128_FP16", CV_SIMD128_FP16);
  
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_singleton_attr("M128i", &cv::__m128i);
  
  rb_mCv.define_module_function("_v128_set_b", &cv::_v128_set_b,
    Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15"));
  
  rb_mCv.define_module_function("_v128_setr_h", &cv::_v128_setr_h,
    Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"));
  
  rb_mCv.define_module_function("_v128_setr_w", &cv::_v128_setr_w,
    Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"));
  
  rb_mCv.define_module_function("_v128_set_w", &cv::_v128_set_w,
    Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"));
  
  rb_mCv.define_module_function("_v128_setall_w", &cv::_v128_setall_w,
    Arg("v0"));
  
  rb_mCv.define_module_function("_v128_setr_d", &cv::_v128_setr_d,
    Arg("v0"), Arg("v1"));
  
  rb_mCv.define_module_function("_v128_set_d", &cv::_v128_set_d,
    Arg("v0"), Arg("v1"));
  
  rb_mCv.define_module_function("_v128_setr_ps", &cv::_v128_setr_ps,
    Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"));
  
  rb_mCv.define_module_function("_v128_setall_ps", &cv::_v128_setall_ps,
    Arg("v0"));
  
  rb_mCv.define_module_function("_v128_setr_pd", &cv::_v128_setr_pd,
    Arg("v0"), Arg("v1"));
  
  rb_mCv.define_module_function("_v128_setall_pd", &cv::_v128_setall_pd,
    Arg("v0"));
  
  rb_mCv.define_module_function("_lsx_packus_h", &cv::_lsx_packus_h,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("_lsx_packs_h", &cv::_lsx_packs_h,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("_lsx_packus_w", &cv::_lsx_packus_w,
    Arg("a"), Arg("b"));
  
  rb_cCvVUint8x16 = define_class_under<cv::v_uint8x16>(rb_mCv, "VUint8x16").
    define_constructor(Constructor<cv::v_uint8x16>()).
    define_constructor(Constructor<cv::v_uint8x16, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint8x16, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).
    define_method("get0", &cv::v_uint8x16::get0).
    define_attr("val", &cv::v_uint8x16::val);
  
  rb_cCvVUint8x16.define_constant("Nlanes", (int)cv::v_uint8x16::nlanes);
  
  rb_cCvVInt8x16 = define_class_under<cv::v_int8x16>(rb_mCv, "VInt8x16").
    define_constructor(Constructor<cv::v_int8x16>()).
    define_constructor(Constructor<cv::v_int8x16, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int8x16, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).
    define_method("get0", &cv::v_int8x16::get0).
    define_attr("val", &cv::v_int8x16::val);
  
  rb_cCvVInt8x16.define_constant("Nlanes", (int)cv::v_int8x16::nlanes);
  
  rb_cCvVUint16x8 = define_class_under<cv::v_uint16x8>(rb_mCv, "VUint16x8").
    define_constructor(Constructor<cv::v_uint16x8>()).
    define_constructor(Constructor<cv::v_uint16x8, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint16x8, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_method("get0", &cv::v_uint16x8::get0).
    define_attr("val", &cv::v_uint16x8::val);
  
  rb_cCvVUint16x8.define_constant("Nlanes", (int)cv::v_uint16x8::nlanes);
  
  rb_cCvVInt16x8 = define_class_under<cv::v_int16x8>(rb_mCv, "VInt16x8").
    define_constructor(Constructor<cv::v_int16x8>()).
    define_constructor(Constructor<cv::v_int16x8, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int16x8, short, short, short, short, short, short, short, short>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_method("get0", &cv::v_int16x8::get0).
    define_attr("val", &cv::v_int16x8::val);
  
  rb_cCvVInt16x8.define_constant("Nlanes", (int)cv::v_int16x8::nlanes);
  
  rb_cCvVUint32x4 = define_class_under<cv::v_uint32x4>(rb_mCv, "VUint32x4").
    define_constructor(Constructor<cv::v_uint32x4>()).
    define_constructor(Constructor<cv::v_uint32x4, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint32x4, unsigned int, unsigned int, unsigned int, unsigned int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_method("get0", &cv::v_uint32x4::get0).
    define_attr("val", &cv::v_uint32x4::val);
  
  rb_cCvVUint32x4.define_constant("Nlanes", (int)cv::v_uint32x4::nlanes);
  
  rb_cCvVInt32x4 = define_class_under<cv::v_int32x4>(rb_mCv, "VInt32x4").
    define_constructor(Constructor<cv::v_int32x4>()).
    define_constructor(Constructor<cv::v_int32x4, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int32x4, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_method("get0", &cv::v_int32x4::get0).
    define_attr("val", &cv::v_int32x4::val);
  
  rb_cCvVInt32x4.define_constant("Nlanes", (int)cv::v_int32x4::nlanes);
  
  rb_cCvVFloat32x4 = define_class_under<cv::v_float32x4>(rb_mCv, "VFloat32x4").
    define_constructor(Constructor<cv::v_float32x4>()).
    define_constructor(Constructor<cv::v_float32x4, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_float32x4, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_float32x4, float, float, float, float>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_method("get0", &cv::v_float32x4::get0).
    define_method("get0toint", &cv::v_float32x4::get0toint).
    define_attr("val", &cv::v_float32x4::val);
  
  rb_cCvVFloat32x4.define_constant("Nlanes", (int)cv::v_float32x4::nlanes);
  
  rb_cCvVUint64x2 = define_class_under<cv::v_uint64x2>(rb_mCv, "VUint64x2").
    define_constructor(Constructor<cv::v_uint64x2>()).
    define_constructor(Constructor<cv::v_uint64x2, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint64x2, int, int>(),
      Arg("v0"), Arg("v1")).
    define_method("get0", &cv::v_uint64x2::get0).
    define_attr("val", &cv::v_uint64x2::val);
  
  rb_cCvVUint64x2.define_constant("Nlanes", (int)cv::v_uint64x2::nlanes);
  
  rb_cCvVInt64x2 = define_class_under<cv::v_int64x2>(rb_mCv, "VInt64x2").
    define_constructor(Constructor<cv::v_int64x2>()).
    define_constructor(Constructor<cv::v_int64x2, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int64x2, int, int>(),
      Arg("v0"), Arg("v1")).
    define_method("get0", &cv::v_int64x2::get0).
    define_attr("val", &cv::v_int64x2::val);
  
  rb_cCvVInt64x2.define_constant("Nlanes", (int)cv::v_int64x2::nlanes);
  
  rb_cCvVFloat64x2 = define_class_under<cv::v_float64x2>(rb_mCv, "VFloat64x2").
    define_constructor(Constructor<cv::v_float64x2>()).
    define_constructor(Constructor<cv::v_float64x2, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_float64x2, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_float64x2, double, double>(),
      Arg("v0"), Arg("v1")).
    define_method("get0", &cv::v_float64x2::get0).
    define_method("get0toint64", &cv::v_float64x2::get0toint64).
    define_attr("val", &cv::v_float64x2::val);
  
  rb_cCvVFloat64x2.define_constant("Nlanes", (int)cv::v_float64x2::nlanes);
  
  rb_mCv.define_module_function("_lsx_128_castps_si128", &cv::_lsx_128_castps_si128,
    Arg("v"));
  
  rb_mCv.define_module_function("_lsx_128_castpd_si128", &cv::_lsx_128_castpd_si128,
    Arg("v"));
  
  rb_mCv.define_module_function("_lsx_128_castsi128_ps", &cv::_lsx_128_castsi128_ps,
    Arg("v"));
  
  rb_mCv.define_module_function("_lsx_128_castsi128_pd", &cv::_lsx_128_castsi128_pd,
    Arg("v"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_reinterpret_as_f32", &cv::v_reinterpret_as_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float64x2&)>("v_reinterpret_as_f32", &cv::v_reinterpret_as_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&)>("v_reinterpret_as_f64", &cv::v_reinterpret_as_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float32x4&)>("v_reinterpret_as_f64", &cv::v_reinterpret_as_f64,
    Arg("a"));
  
  rb_cCvVUint8x16.define_method("*", [](const cv::v_uint8x16& self, const cv::v_uint8x16& other) -> cv::v_uint8x16
  {
    return self * other;
  });
  
  rb_cCvVInt8x16.define_method("*", [](const cv::v_int8x16& self, const cv::v_int8x16& other) -> cv::v_int8x16
  {
    return self * other;
  });
  
  rb_cCvVUint16x8.define_method("*", [](const cv::v_uint16x8& self, const cv::v_uint16x8& other) -> cv::v_uint16x8
  {
    return self * other;
  });
  
  rb_cCvVInt16x8.define_method("*", [](const cv::v_int16x8& self, const cv::v_int16x8& other) -> cv::v_int16x8
  {
    return self * other;
  });
  
  rb_cCvVUint8x16.define_method("assign_multiply", [](cv::v_uint8x16& self, const cv::v_uint8x16& other) -> cv::v_uint8x16&
  {
    return self *= other;
  });
  
  rb_cCvVInt8x16.define_method("assign_multiply", [](cv::v_int8x16& self, const cv::v_int8x16& other) -> cv::v_int8x16&
  {
    return self *= other;
  });
  
  rb_cCvVUint16x8.define_method("assign_multiply", [](cv::v_uint16x8& self, const cv::v_uint16x8& other) -> cv::v_uint16x8&
  {
    return self *= other;
  });
  
  rb_cCvVInt16x8.define_method("assign_multiply", [](cv::v_int16x8& self, const cv::v_int16x8& other) -> cv::v_int16x8&
  {
    return self *= other;
  });
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&, const cv::v_uint8x16&)>("v_mul_wrap", &cv::v_mul_wrap,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_mul_wrap", &cv::v_mul_wrap,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint8x16&, const cv::v_uint8x16&, cv::v_uint16x8&, cv::v_uint16x8&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int8x16&, const cv::v_int8x16&, cv::v_int16x8&, cv::v_int16x8&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int16x8&, const cv::v_int16x8&, cv::v_int32x4&, cv::v_int32x4&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint16x8&, const cv::v_uint16x8&, cv::v_uint32x4&, cv::v_uint32x4&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint32x4&, const cv::v_uint32x4&, cv::v_uint64x2&, cv::v_uint64x2&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_mul_hi", &cv::v_mul_hi,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_mul_hi", &cv::v_mul_hi,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&, const cv::v_float32x4&, const cv::v_float32x4&)>("v_select", &cv::v_select,
    Arg("mask"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&, const cv::v_float64x2&, const cv::v_float64x2&)>("v_select", &cv::v_select,
    Arg("mask"), Arg("a"), Arg("b"));
  
  rb_cCvVFloat32x4.define_method(">", [](const cv::v_float32x4& self, const cv::v_float32x4& other) -> cv::v_float32x4
  {
    return self > other;
  });
  
  rb_cCvVFloat32x4.define_method(">=", [](const cv::v_float32x4& self, const cv::v_float32x4& other) -> cv::v_float32x4
  {
    return self >= other;
  });
  
  rb_cCvVFloat64x2.define_method(">", [](const cv::v_float64x2& self, const cv::v_float64x2& other) -> cv::v_float64x2
  {
    return self > other;
  });
  
  rb_cCvVFloat64x2.define_method(">=", [](const cv::v_float64x2& self, const cv::v_float64x2& other) -> cv::v_float64x2
  {
    return self >= other;
  });
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_not_nan", &cv::v_not_nan,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&)>("v_not_nan", &cv::v_not_nan,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint32x4&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int32x4&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint64x2&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int64x2&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint8x16&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int8x16&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int32x4&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint32x4&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int16x8&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint16x8&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<float(*)(const cv::v_float32x4&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint64x2&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int64x2&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<double(*)(const cv::v_float64x2&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function("v_reduce_sum4", &cv::v_reduce_sum4,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint8x16&, const cv::v_uint8x16&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint32x4&, const cv::v_uint32x4&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<float(*)(const cv::v_float32x4&, const cv::v_float32x4&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int8x16&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint8x16&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int16x8&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint16x8&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint32x4&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int32x4&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint64x2&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int64x2&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float32x4&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float64x2&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int8x16&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint8x16&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int16x8&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint16x8&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int32x4&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint32x4&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float32x4&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int64x2&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint64x2&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float64x2&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int32x4&, const cv::v_int32x4&, const cv::v_int32x4&)>("v_fma", &cv::v_fma,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int32x4&, const cv::v_int32x4&, const cv::v_int32x4&)>("v_muladd", &cv::v_muladd,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_invsqrt", &cv::v_invsqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&)>("v_invsqrt", &cv::v_invsqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_abs", &cv::v_abs,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&)>("v_abs", &cv::v_abs,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&, const cv::v_uint8x16&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint32x4&, const cv::v_uint32x4&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&, const cv::v_float32x4&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&, const cv::v_float64x2&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_absdiffs", &cv::v_absdiffs,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_absdiffs", &cv::v_absdiffs,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float32x4&)>("v_round", &cv::v_round,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float64x2&)>("v_round", &cv::v_round,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float64x2&, const cv::v_float64x2&)>("v_round", &cv::v_round,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float32x4&)>("v_trunc", &cv::v_trunc,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float64x2&)>("v_trunc", &cv::v_trunc,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float32x4&)>("v_floor", &cv::v_floor,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float64x2&)>("v_floor", &cv::v_floor,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float32x4&)>("v_ceil", &cv::v_ceil,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float64x2&)>("v_ceil", &cv::v_ceil,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_int32x4&)>("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float64x2&)>("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float64x2&, const cv::v_float64x2&)>("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_int32x4&)>("v_cvt_f64", &cv::v_cvt_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_int32x4&)>("v_cvt_f64_high", &cv::v_cvt_f64_high,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float32x4&)>("v_cvt_f64", &cv::v_cvt_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float32x4&)>("v_cvt_f64_high", &cv::v_cvt_f64_high,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_int64x2&)>("v_cvt_f64", &cv::v_cvt_f64,
    Arg("v"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const int*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const int*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const int*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const int*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const int*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const int*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const short*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const short*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const short*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const int*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const int*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const int*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const int*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const int*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const int*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const unsigned int*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const unsigned int*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const unsigned int*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const int*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const int*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const int*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const int*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const float*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const float*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const float*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const double*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const double*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const int*, const cv::v_int32x4&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const unsigned int*, const cv::v_int32x4&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const float*, const cv::v_int32x4&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const double*, const cv::v_int32x4&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<void(*)(const float*, const cv::v_int32x4&, cv::v_float32x4&, cv::v_float32x4&)>("v_lut_deinterleave", &cv::v_lut_deinterleave,
    Arg("tab"), Arg("idxvec"), Arg("x"), Arg("y"));
  
  rb_mCv.define_module_function<void(*)(const double*, const cv::v_int32x4&, cv::v_float64x2&, cv::v_float64x2&)>("v_lut_deinterleave", &cv::v_lut_deinterleave,
    Arg("tab"), Arg("idxvec"), Arg("x"), Arg("y"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int32x4&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint32x4&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int32x4&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint32x4&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int16x8&, const cv::v_int16x8&, const cv::v_int32x4&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int32x4&, const cv::v_int32x4&, const cv::v_int64x2&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint8x16&, const cv::v_uint8x16&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint8x16&, const cv::v_uint8x16&, const cv::v_uint32x4&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int8x16&, const cv::v_int8x16&, const cv::v_int32x4&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint16x8&, const cv::v_uint16x8&, const cv::v_uint64x2&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int16x8&, const cv::v_int16x8&, const cv::v_int64x2&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_int32x4&, const cv::v_int32x4&, const cv::v_float64x2&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int16x8&, const cv::v_int16x8&, const cv::v_int32x4&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int32x4&, const cv::v_int32x4&, const cv::v_int64x2&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint8x16&, const cv::v_uint8x16&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint8x16&, const cv::v_uint8x16&, const cv::v_uint32x4&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int8x16&, const cv::v_int8x16&, const cv::v_int32x4&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint16x8&, const cv::v_uint16x8&, const cv::v_uint64x2&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int16x8&, const cv::v_int16x8&, const cv::v_int64x2&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_int32x4&, const cv::v_int32x4&, const cv::v_float64x2&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function("v_matmul", &cv::v_matmul,
    Arg("v"), Arg("m0"), Arg("m1"), Arg("m2"), Arg("m3"));
  
  rb_mCv.define_module_function("v_matmuladd", &cv::v_matmuladd,
    Arg("v"), Arg("m0"), Arg("m1"), Arg("m2"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_float32x4&, const cv::v_float32x4&, const cv::v_float32x4&, const cv::v_float32x4&, cv::v_float32x4&, cv::v_float32x4&, cv::v_float32x4&, cv::v_float32x4&)>("v_transpose4x4", &cv::v_transpose4x4,
    Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("b0"), Arg("b1"), Arg("b2"), Arg("b3"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_pack_u", &cv::v_pack_u,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int16x8&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint16x8&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int16x8&)>("v_pack_u_store", &cv::v_pack_u_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint32x4&, const cv::v_uint32x4&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_pack_u", &cv::v_pack_u,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(short*, const cv::v_int32x4&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint32x4&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int32x4&)>("v_pack_u_store", &cv::v_pack_u_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint64x2&, const cv::v_uint64x2&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int64x2&, const cv::v_int64x2&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint64x2&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int64x2&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint32x4&, const cv::v_uint32x4&, const cv::v_uint32x4&, const cv::v_uint32x4&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("e"), Arg("f"), Arg("g"), Arg("h"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint8x16&, cv::v_uint8x16&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint16x8&, cv::v_uint16x8&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const unsigned int*, cv::v_uint32x4&, cv::v_uint32x4&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint64x2&, cv::v_uint64x2&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint8x16&, cv::v_uint8x16&, cv::v_uint8x16&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint16x8&, cv::v_uint16x8&, cv::v_uint16x8&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const unsigned int*, cv::v_uint32x4&, cv::v_uint32x4&, cv::v_uint32x4&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint64x2&, cv::v_uint64x2&, cv::v_uint64x2&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint8x16&, cv::v_uint8x16&, cv::v_uint8x16&, cv::v_uint8x16&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint16x8&, cv::v_uint16x8&, cv::v_uint16x8&, cv::v_uint16x8&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const unsigned int*, cv::v_uint32x4&, cv::v_uint32x4&, cv::v_uint32x4&, cv::v_uint32x4&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint64x2&, cv::v_uint64x2&, cv::v_uint64x2&, cv::v_uint64x2&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint8x16&, const cv::v_uint8x16&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint16x8&, const cv::v_uint16x8&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint32x4&, const cv::v_uint32x4&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint64x2&, const cv::v_uint64x2&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint8x16&, const cv::v_uint8x16&, const cv::v_uint8x16&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint16x8&, const cv::v_uint16x8&, const cv::v_uint16x8&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint32x4&, const cv::v_uint32x4&, const cv::v_uint32x4&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint8x16&, const cv::v_uint8x16&, const cv::v_uint8x16&, const cv::v_uint8x16&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint16x8&, const cv::v_uint16x8&, const cv::v_uint16x8&, const cv::v_uint16x8&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint32x4&, const cv::v_uint32x4&, const cv::v_uint32x4&, const cv::v_uint32x4&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const int*)>("v_load_expand", &cv::v_load_expand,
    Arg("ptr"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_float32x4&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function("v_cleanup", &cv::v_cleanup);

}