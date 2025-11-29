#include <opencv2/core/hal/intrin_wasm.hpp>
#include "intrin_wasm-rb.hpp"

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

void Init_IntrinWasm()
{
  Class(rb_cObject).define_constant("CV_SIMD128", CV_SIMD128);
  
  Class(rb_cObject).define_constant("CV_SIMD128_64F", CV_SIMD128_64F);
  
  Class(rb_cObject).define_constant("CV_SIMD128_FP16", CV_SIMD128_FP16);
  
  Module rb_mCv = define_module("Cv");
  
  rb_cCvVUint8x16 = define_class_under<cv::v_uint8x16>(rb_mCv, "VUint8x16").
    define_constructor(Constructor<cv::v_uint8x16>()).
    define_constructor(Constructor<cv::v_uint8x16, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint8x16, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).
    define_method("get0", &cv::v_uint8x16::get0).
    define_attr("val", &cv::v_uint8x16::val);
  
  rb_cCvVUint8x16.define_constant("Nlanes", (int)cv::v_uint8x16::nlanes);
  
  rb_cCvVInt8x16 = define_class_under<cv::v_int8x16>(rb_mCv, "VInt8x16").
    define_constructor(Constructor<cv::v_int8x16>()).
    define_constructor(Constructor<cv::v_int8x16, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int8x16, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).
    define_method("get0", &cv::v_int8x16::get0).
    define_attr("val", &cv::v_int8x16::val);
  
  rb_cCvVInt8x16.define_constant("Nlanes", (int)cv::v_int8x16::nlanes);
  
  rb_cCvVUint16x8 = define_class_under<cv::v_uint16x8>(rb_mCv, "VUint16x8").
    define_constructor(Constructor<cv::v_uint16x8>()).
    define_constructor(Constructor<cv::v_uint16x8, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint16x8, ushort, ushort, ushort, ushort, ushort, ushort, ushort, ushort>(),
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
    define_constructor(Constructor<cv::v_float32x4, float, float, float, float>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_method("get0", &cv::v_float32x4::get0).
    define_attr("val", &cv::v_float32x4::val);
  
  rb_cCvVFloat32x4.define_constant("Nlanes", (int)cv::v_float32x4::nlanes);
  
  rb_cCvVUint64x2 = define_class_under<cv::v_uint64x2>(rb_mCv, "VUint64x2").
    define_constructor(Constructor<cv::v_uint64x2>()).
    define_constructor(Constructor<cv::v_uint64x2, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint64x2, uint64, uint64>(),
      Arg("v0"), Arg("v1")).
    define_method("get0", &cv::v_uint64x2::get0).
    define_attr("val", &cv::v_uint64x2::val);
  
  rb_cCvVUint64x2.define_constant("Nlanes", (int)cv::v_uint64x2::nlanes);
  
  rb_cCvVInt64x2 = define_class_under<cv::v_int64x2>(rb_mCv, "VInt64x2").
    define_constructor(Constructor<cv::v_int64x2>()).
    define_constructor(Constructor<cv::v_int64x2, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int64x2, int64, int64>(),
      Arg("v0"), Arg("v1")).
    define_method("get0", &cv::v_int64x2::get0).
    define_attr("val", &cv::v_int64x2::val);
  
  rb_cCvVInt64x2.define_constant("Nlanes", (int)cv::v_int64x2::nlanes);
  
  rb_cCvVFloat64x2 = define_class_under<cv::v_float64x2>(rb_mCv, "VFloat64x2").
    define_constructor(Constructor<cv::v_float64x2>()).
    define_constructor(Constructor<cv::v_float64x2, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_float64x2, double, double>(),
      Arg("v0"), Arg("v1")).
    define_method("get0", &cv::v_float64x2::get0).
    define_attr("val", &cv::v_float64x2::val);
  
  rb_cCvVFloat64x2.define_constant("Nlanes", (int)cv::v_float64x2::nlanes);
  
  Module rb_mCvAnonymous = define_module_under(rb_mCv, "Anonymous");
  
  rb_mCvAnonymous.define_singleton_attr("PopCountTable", &cv::::popCountTable);
  
  rb_mCv.define_module_function("wasm_unpacklo_i8x16", &cv::wasm_unpacklo_i8x16,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("wasm_unpacklo_i16x8", &cv::wasm_unpacklo_i16x8,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("wasm_unpacklo_i32x4", &cv::wasm_unpacklo_i32x4,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("wasm_unpacklo_i64x2", &cv::wasm_unpacklo_i64x2,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("wasm_unpackhi_i8x16", &cv::wasm_unpackhi_i8x16,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("wasm_unpackhi_i16x8", &cv::wasm_unpackhi_i16x8,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("wasm_unpackhi_i32x4", &cv::wasm_unpackhi_i32x4,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("wasm_unpackhi_i64x2", &cv::wasm_unpackhi_i64x2,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("v128_cvtu8x16_i16x8", &cv::v128_cvtu8x16_i16x8,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvti8x16_i16x8", &cv::v128_cvti8x16_i16x8,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvtu8x16_i32x4", &cv::v128_cvtu8x16_i32x4,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvti8x16_i32x4", &cv::v128_cvti8x16_i32x4,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvtu16x8_i32x4", &cv::v128_cvtu16x8_i32x4,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvti16x8_i32x4", &cv::v128_cvti16x8_i32x4,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvtu32x4_i64x2", &cv::v128_cvtu32x4_i64x2,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvti32x4_i64x2", &cv::v128_cvti32x4_i64x2,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvtu8x16_i16x8_high", &cv::v128_cvtu8x16_i16x8_high,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvti8x16_i16x8_high", &cv::v128_cvti8x16_i16x8_high,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvtu16x8_i32x4_high", &cv::v128_cvtu16x8_i32x4_high,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvti16x8_i32x4_high", &cv::v128_cvti16x8_i32x4_high,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvtu32x4_i64x2_high", &cv::v128_cvtu32x4_i64x2_high,
    Arg("a"));
  
  rb_mCv.define_module_function("v128_cvti32x4_i64x2_high", &cv::v128_cvti32x4_i64x2_high,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint32x4&, const cv::v_uint32x4&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint64x2&, const cv::v_uint64x2&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int64x2&, const cv::v_int64x2&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_pack_u", &cv::v_pack_u,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_pack_u", &cv::v_pack_u,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(uchar*, const cv::v_uint16x8&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(schar*, const cv::v_int16x8&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(ushort*, const cv::v_uint32x4&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(short*, const cv::v_int32x4&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint64x2&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int64x2&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(uchar*, const cv::v_int16x8&)>("v_pack_u_store", &cv::v_pack_u_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(ushort*, const cv::v_int32x4&)>("v_pack_u_store", &cv::v_pack_u_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint32x4&, const cv::v_uint32x4&, const cv::v_uint32x4&, const cv::v_uint32x4&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("e"), Arg("f"), Arg("g"), Arg("h"));
  
  rb_mCv.define_module_function("v_matmul", &cv::v_matmul,
    Arg("v"), Arg("m0"), Arg("m1"), Arg("m2"), Arg("m3"));
  
  rb_mCv.define_module_function("v_matmuladd", &cv::v_matmuladd,
    Arg("v"), Arg("m0"), Arg("m1"), Arg("m2"), Arg("a"));
  
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
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_sqrt", &cv::v_sqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_invsqrt", &cv::v_invsqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&)>("v_sqrt", &cv::v_sqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&)>("v_invsqrt", &cv::v_invsqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_abs", &cv::v_abs,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&)>("v_abs", &cv::v_abs,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_not_nan", &cv::v_not_nan,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&)>("v_not_nan", &cv::v_not_nan,
    Arg("a"));
  
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
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_absdiffs", &cv::v_absdiffs,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_absdiffs", &cv::v_absdiffs,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int32x4&, const cv::v_int32x4&, const cv::v_int32x4&)>("v_fma", &cv::v_fma,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int32x4&, const cv::v_int32x4&, const cv::v_int32x4&)>("v_muladd", &cv::v_muladd,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&, const cv::v_float32x4&, const cv::v_float32x4&)>("v_fma", &cv::v_fma,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&, const cv::v_float64x2&, const cv::v_float64x2&)>("v_fma", &cv::v_fma,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&, const cv::v_float32x4&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&, const cv::v_float64x2&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  Module rb_mCvHalWasmInternal = define_module_under(rb_mCv, "HalWasmInternal");
  
  
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
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint64x2&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int64x2&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x2(*)(const cv::v_float64x2&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function("v_reduce_sum4", &cv::v_reduce_sum4,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint8x16&, const cv::v_uint8x16&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_reduce_sad", &cv::v_reduce_sad,
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
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint32x4&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint64x2&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_int8x16&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_int16x8&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_int32x4&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_int64x2&)>("v_popcount", &cv::v_popcount,
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
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float32x4&)>("v_round", &cv::v_round,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float32x4&)>("v_floor", &cv::v_floor,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float32x4&)>("v_ceil", &cv::v_ceil,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float32x4&)>("v_trunc", &cv::v_trunc,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_float64x2&, const cv::v_float64x2&)>("v_round", &cv::v_round,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const uchar*, cv::v_uint8x16&, cv::v_uint8x16&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const uchar*, cv::v_uint8x16&, cv::v_uint8x16&, cv::v_uint8x16&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const uchar*, cv::v_uint8x16&, cv::v_uint8x16&, cv::v_uint8x16&, cv::v_uint8x16&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const ushort*, cv::v_uint16x8&, cv::v_uint16x8&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const ushort*, cv::v_uint16x8&, cv::v_uint16x8&, cv::v_uint16x8&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const ushort*, cv::v_uint16x8&, cv::v_uint16x8&, cv::v_uint16x8&, cv::v_uint16x8&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const unsigned int*, cv::v_uint32x4&, cv::v_uint32x4&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const unsigned int*, cv::v_uint32x4&, cv::v_uint32x4&, cv::v_uint32x4&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const unsigned int*, cv::v_uint32x4&, cv::v_uint32x4&, cv::v_uint32x4&, cv::v_uint32x4&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const float*, cv::v_float32x4&, cv::v_float32x4&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const float*, cv::v_float32x4&, cv::v_float32x4&, cv::v_float32x4&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const float*, cv::v_float32x4&, cv::v_float32x4&, cv::v_float32x4&, cv::v_float32x4&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const uint64*, cv::v_uint64x2&, cv::v_uint64x2&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const uint64*, cv::v_uint64x2&, cv::v_uint64x2&, cv::v_uint64x2&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const uint64*, cv::v_uint64x2&, cv::v_uint64x2&, cv::v_uint64x2&, cv::v_uint64x2&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(uchar*, const cv::v_uint8x16&, const cv::v_uint8x16&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(uchar*, const cv::v_uint8x16&, const cv::v_uint8x16&, const cv::v_uint8x16&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(uchar*, const cv::v_uint8x16&, const cv::v_uint8x16&, const cv::v_uint8x16&, const cv::v_uint8x16&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(ushort*, const cv::v_uint16x8&, const cv::v_uint16x8&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(ushort*, const cv::v_uint16x8&, const cv::v_uint16x8&, const cv::v_uint16x8&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(ushort*, const cv::v_uint16x8&, const cv::v_uint16x8&, const cv::v_uint16x8&, const cv::v_uint16x8&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint32x4&, const cv::v_uint32x4&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint32x4&, const cv::v_uint32x4&, const cv::v_uint32x4&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint32x4&, const cv::v_uint32x4&, const cv::v_uint32x4&, const cv::v_uint32x4&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(float*, const cv::v_float32x4&, const cv::v_float32x4&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(float*, const cv::v_float32x4&, const cv::v_float32x4&, const cv::v_float32x4&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(float*, const cv::v_float32x4&, const cv::v_float32x4&, const cv::v_float32x4&, const cv::v_float32x4&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(uint64*, const cv::v_uint64x2&, const cv::v_uint64x2&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(uint64*, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(uint64*, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("") = static_cast<int>());
  
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
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const schar*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const schar*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const schar*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const uchar*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const uchar*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const uchar*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const short*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const short*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const short*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const ushort*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const ushort*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const ushort*, const int*)>("v_lut_quads", &cv::v_lut_quads,
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
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const int64_t*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const int64_t*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const uint64_t*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const uint64_t*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
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
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::hfloat*)>("v_load_expand", &cv::v_load_expand,
    Arg("ptr"));
  
  rb_mCv.define_module_function<void(*)(cv::hfloat*, const cv::v_float32x4&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("v"));
  
  rb_mCv.define_module_function("v_cleanup", &cv::v_cleanup);

}