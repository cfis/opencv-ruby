#include <opencv2/core/hal/intrin_avx512.hpp>
#include "intrin_avx512-rb.hpp"

using namespace Rice;

Rice::Class rb_cCv(anonymousNamespace)VRotateRightFalse0False0;
Rice::Class rb_cCv(anonymousNamespace)VRotateRightFalse0True16;
Rice::Class rb_cCv(anonymousNamespace)VRotateRightFalse0True32;
Rice::Class rb_cCvVFloat32x16;
Rice::Class rb_cCvVFloat64x8;
Rice::Class rb_cCvVInt16x32;
Rice::Class rb_cCvVInt32x16;
Rice::Class rb_cCvVInt64x8;
Rice::Class rb_cCvVInt8x64;
Rice::Class rb_cCvVUint16x32;
Rice::Class rb_cCvVUint32x16;
Rice::Class rb_cCvVUint64x8;
Rice::Class rb_cCvVUint8x64;

template<typename Data_Type_T, bool prec, int imm4, bool part, int imm32>
inline void _v_rotate_right_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function("eval", &cv::::_v_rotate_right<prec, imm4, part, imm32>::eval,
      Arg(""), Arg(""));
};
void Init_IntrinAvx512()
{
  Class(rb_cObject).define_constant("CVT_ROUND_MODES_IMPLEMENTED", CVT_ROUND_MODES_IMPLEMENTED);
  
  Class(rb_cObject).define_constant("CV_SIMD512", CV_SIMD512);
  
  Class(rb_cObject).define_constant("CV_SIMD512_64F", CV_SIMD512_64F);
  
  Class(rb_cObject).define_constant("CV_SIMD512_FP16", CV_SIMD512_FP16);
  
  Module rb_mAnonymous = define_module("Anonymous");
  
  rb_mAnonymous.define_module_function<int(*)(const int&, const int&)>("_v512_combine", &::_v512_combine,
    Arg("lo"), Arg("hi"));
  
  rb_mAnonymous.define_module_function<int(*)(const int&, const int&)>("_v512_combine", &::_v512_combine,
    Arg("lo"), Arg("hi"));
  
  rb_mAnonymous.define_module_function<int(*)(const int&, const int&)>("_v512_combine", &::_v512_combine,
    Arg("lo"), Arg("hi"));
  
  rb_mAnonymous.define_module_function("_v_cvtsi512_si32", &::_v_cvtsi512_si32,
    Arg("a"));
  
  rb_mAnonymous.define_module_function<int(*)(const int&)>("_v512_extract_high", &::_v512_extract_high,
    Arg("v"));
  
  rb_mAnonymous.define_module_function<int(*)(const int&)>("_v512_extract_high", &::_v512_extract_high,
    Arg("v"));
  
  rb_mAnonymous.define_module_function<int(*)(const int&)>("_v512_extract_high", &::_v512_extract_high,
    Arg("v"));
  
  rb_mAnonymous.define_module_function<int(*)(const int&)>("_v512_extract_low", &::_v512_extract_low,
    Arg("v"));
  
  rb_mAnonymous.define_module_function<int(*)(const int&)>("_v512_extract_low", &::_v512_extract_low,
    Arg("v"));
  
  rb_mAnonymous.define_module_function<int(*)(const int&)>("_v512_extract_low", &::_v512_extract_low,
    Arg("v"));
  
  rb_mAnonymous.define_module_function<int(*)(const int&, const int&)>("_v512_insert", &::_v512_insert,
    Arg("a"), Arg("b"));
  
  rb_mAnonymous.define_module_function<int(*)(const int&, const int&)>("_v512_insert", &::_v512_insert,
    Arg("a"), Arg("b"));
  
  rb_mAnonymous.define_module_function<int(*)(const int&, const int&)>("_v512_insert", &::_v512_insert,
    Arg("a"), Arg("b"));
  
  Module rb_mCv = define_module("Cv");
  
  rb_cCvVUint8x64 = define_class_under<cv::v_uint8x64>(rb_mCv, "VUint8x64").
    define_attr("val", &cv::v_uint8x64::val).
    define_constructor(Constructor<cv::v_uint8x64, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint8x64, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15"), Arg("v16"), Arg("v17"), Arg("v18"), Arg("v19"), Arg("v20"), Arg("v21"), Arg("v22"), Arg("v23"), Arg("v24"), Arg("v25"), Arg("v26"), Arg("v27"), Arg("v28"), Arg("v29"), Arg("v30"), Arg("v31"), Arg("v32"), Arg("v33"), Arg("v34"), Arg("v35"), Arg("v36"), Arg("v37"), Arg("v38"), Arg("v39"), Arg("v40"), Arg("v41"), Arg("v42"), Arg("v43"), Arg("v44"), Arg("v45"), Arg("v46"), Arg("v47"), Arg("v48"), Arg("v49"), Arg("v50"), Arg("v51"), Arg("v52"), Arg("v53"), Arg("v54"), Arg("v55"), Arg("v56"), Arg("v57"), Arg("v58"), Arg("v59"), Arg("v60"), Arg("v61"), Arg("v62"), Arg("v63")).
    define_constructor(Constructor<cv::v_uint8x64>()).
    define_singleton_function("zero", &cv::v_uint8x64::zero).
    define_method("get0", &cv::v_uint8x64::get0);
  
  rb_cCvVUint8x64.define_constant("Nlanes", (int)cv::v_uint8x64::nlanes);
  
  rb_cCvVInt8x64 = define_class_under<cv::v_int8x64>(rb_mCv, "VInt8x64").
    define_attr("val", &cv::v_int8x64::val).
    define_constructor(Constructor<cv::v_int8x64, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int8x64, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15"), Arg("v16"), Arg("v17"), Arg("v18"), Arg("v19"), Arg("v20"), Arg("v21"), Arg("v22"), Arg("v23"), Arg("v24"), Arg("v25"), Arg("v26"), Arg("v27"), Arg("v28"), Arg("v29"), Arg("v30"), Arg("v31"), Arg("v32"), Arg("v33"), Arg("v34"), Arg("v35"), Arg("v36"), Arg("v37"), Arg("v38"), Arg("v39"), Arg("v40"), Arg("v41"), Arg("v42"), Arg("v43"), Arg("v44"), Arg("v45"), Arg("v46"), Arg("v47"), Arg("v48"), Arg("v49"), Arg("v50"), Arg("v51"), Arg("v52"), Arg("v53"), Arg("v54"), Arg("v55"), Arg("v56"), Arg("v57"), Arg("v58"), Arg("v59"), Arg("v60"), Arg("v61"), Arg("v62"), Arg("v63")).
    define_constructor(Constructor<cv::v_int8x64>()).
    define_singleton_function("zero", &cv::v_int8x64::zero).
    define_method("get0", &cv::v_int8x64::get0);
  
  rb_cCvVInt8x64.define_constant("Nlanes", (int)cv::v_int8x64::nlanes);
  
  rb_cCvVUint16x32 = define_class_under<cv::v_uint16x32>(rb_mCv, "VUint16x32").
    define_attr("val", &cv::v_uint16x32::val).
    define_constructor(Constructor<cv::v_uint16x32, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint16x32, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15"), Arg("v16"), Arg("v17"), Arg("v18"), Arg("v19"), Arg("v20"), Arg("v21"), Arg("v22"), Arg("v23"), Arg("v24"), Arg("v25"), Arg("v26"), Arg("v27"), Arg("v28"), Arg("v29"), Arg("v30"), Arg("v31")).
    define_constructor(Constructor<cv::v_uint16x32>()).
    define_singleton_function("zero", &cv::v_uint16x32::zero).
    define_method("get0", &cv::v_uint16x32::get0);
  
  rb_cCvVUint16x32.define_constant("Nlanes", (int)cv::v_uint16x32::nlanes);
  
  rb_cCvVInt16x32 = define_class_under<cv::v_int16x32>(rb_mCv, "VInt16x32").
    define_attr("val", &cv::v_int16x32::val).
    define_constructor(Constructor<cv::v_int16x32, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int16x32, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short, short>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15"), Arg("v16"), Arg("v17"), Arg("v18"), Arg("v19"), Arg("v20"), Arg("v21"), Arg("v22"), Arg("v23"), Arg("v24"), Arg("v25"), Arg("v26"), Arg("v27"), Arg("v28"), Arg("v29"), Arg("v30"), Arg("v31")).
    define_constructor(Constructor<cv::v_int16x32>()).
    define_singleton_function("zero", &cv::v_int16x32::zero).
    define_method("get0", &cv::v_int16x32::get0);
  
  rb_cCvVInt16x32.define_constant("Nlanes", (int)cv::v_int16x32::nlanes);
  
  rb_cCvVUint32x16 = define_class_under<cv::v_uint32x16>(rb_mCv, "VUint32x16").
    define_attr("val", &cv::v_uint32x16::val).
    define_constructor(Constructor<cv::v_uint32x16, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint32x16, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).
    define_constructor(Constructor<cv::v_uint32x16>()).
    define_singleton_function("zero", &cv::v_uint32x16::zero).
    define_method("get0", &cv::v_uint32x16::get0);
  
  rb_cCvVUint32x16.define_constant("Nlanes", (int)cv::v_uint32x16::nlanes);
  
  rb_cCvVInt32x16 = define_class_under<cv::v_int32x16>(rb_mCv, "VInt32x16").
    define_attr("val", &cv::v_int32x16::val).
    define_constructor(Constructor<cv::v_int32x16, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int32x16, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).
    define_constructor(Constructor<cv::v_int32x16>()).
    define_singleton_function("zero", &cv::v_int32x16::zero).
    define_method("get0", &cv::v_int32x16::get0);
  
  rb_cCvVInt32x16.define_constant("Nlanes", (int)cv::v_int32x16::nlanes);
  
  rb_cCvVFloat32x16 = define_class_under<cv::v_float32x16>(rb_mCv, "VFloat32x16").
    define_attr("val", &cv::v_float32x16::val).
    define_constructor(Constructor<cv::v_float32x16, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_float32x16, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).
    define_constructor(Constructor<cv::v_float32x16>()).
    define_singleton_function("zero", &cv::v_float32x16::zero).
    define_method("get0", &cv::v_float32x16::get0);
  
  rb_cCvVFloat32x16.define_constant("Nlanes", (int)cv::v_float32x16::nlanes);
  
  rb_cCvVUint64x8 = define_class_under<cv::v_uint64x8>(rb_mCv, "VUint64x8").
    define_attr("val", &cv::v_uint64x8::val).
    define_constructor(Constructor<cv::v_uint64x8, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint64x8, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_constructor(Constructor<cv::v_uint64x8>()).
    define_singleton_function("zero", &cv::v_uint64x8::zero).
    define_method("get0", &cv::v_uint64x8::get0);
  
  rb_cCvVUint64x8.define_constant("Nlanes", (int)cv::v_uint64x8::nlanes);
  
  rb_cCvVInt64x8 = define_class_under<cv::v_int64x8>(rb_mCv, "VInt64x8").
    define_attr("val", &cv::v_int64x8::val).
    define_constructor(Constructor<cv::v_int64x8, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int64x8, int, int, int, int, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_constructor(Constructor<cv::v_int64x8>()).
    define_singleton_function("zero", &cv::v_int64x8::zero).
    define_method("get0", &cv::v_int64x8::get0);
  
  rb_cCvVInt64x8.define_constant("Nlanes", (int)cv::v_int64x8::nlanes);
  
  rb_cCvVFloat64x8 = define_class_under<cv::v_float64x8>(rb_mCv, "VFloat64x8").
    define_attr("val", &cv::v_float64x8::val).
    define_constructor(Constructor<cv::v_float64x8, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_float64x8, double, double, double, double, double, double, double, double>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_constructor(Constructor<cv::v_float64x8>()).
    define_singleton_function("zero", &cv::v_float64x8::zero).
    define_method("get0", &cv::v_float64x8::get0);
  
  rb_cCvVFloat64x8.define_constant("Nlanes", (int)cv::v_float64x8::nlanes);
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const cv::v_float32x16&)>("v_reinterpret_as_f32", &cv::v_reinterpret_as_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const cv::v_float64x8&)>("v_reinterpret_as_f32", &cv::v_reinterpret_as_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_float64x8&)>("v_reinterpret_as_f64", &cv::v_reinterpret_as_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_float32x16&)>("v_reinterpret_as_f64", &cv::v_reinterpret_as_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const int*)>("v512_load_expand", &cv::v512_load_expand,
    Arg("ptr"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_float32x16&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int8x64&, const cv::v_int8x64&, cv::v_int8x64&, cv::v_int8x64&)>("v_zip", &cv::v_zip,
    Arg("a"), Arg("b"), Arg("ab0"), Arg("ab1"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int16x32&, const cv::v_int16x32&, cv::v_int16x32&, cv::v_int16x32&)>("v_zip", &cv::v_zip,
    Arg("a"), Arg("b"), Arg("ab0"), Arg("ab1"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int32x16&, const cv::v_int32x16&, cv::v_int32x16&, cv::v_int32x16&)>("v_zip", &cv::v_zip,
    Arg("a"), Arg("b"), Arg("ab0"), Arg("ab1"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int64x8&, const cv::v_int64x8&, cv::v_int64x8&, cv::v_int64x8&)>("v_zip", &cv::v_zip,
    Arg("a"), Arg("b"), Arg("ab0"), Arg("ab1"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint8x64&, const cv::v_uint8x64&, cv::v_uint8x64&, cv::v_uint8x64&)>("v_zip", &cv::v_zip,
    Arg("a"), Arg("b"), Arg("ab0"), Arg("ab1"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint16x32&, const cv::v_uint16x32&, cv::v_uint16x32&, cv::v_uint16x32&)>("v_zip", &cv::v_zip,
    Arg("a"), Arg("b"), Arg("ab0"), Arg("ab1"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint32x16&, const cv::v_uint32x16&, cv::v_uint32x16&, cv::v_uint32x16&)>("v_zip", &cv::v_zip,
    Arg("a"), Arg("b"), Arg("ab0"), Arg("ab1"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint64x8&, const cv::v_uint64x8&, cv::v_uint64x8&, cv::v_uint64x8&)>("v_zip", &cv::v_zip,
    Arg("a"), Arg("b"), Arg("ab0"), Arg("ab1"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_float32x16&, const cv::v_float32x16&, cv::v_float32x16&, cv::v_float32x16&)>("v_zip", &cv::v_zip,
    Arg("a"), Arg("b"), Arg("ab0"), Arg("ab1"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_float64x8&, const cv::v_float64x8&, cv::v_float64x8&, cv::v_float64x8&)>("v_zip", &cv::v_zip,
    Arg("a"), Arg("b"), Arg("ab0"), Arg("ab1"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_uint8x64&, const cv::v_uint8x64&)>("v_mul_wrap", &cv::v_mul_wrap,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int8x64(*)(const cv::v_int8x64&, const cv::v_int8x64&)>("v_mul_wrap", &cv::v_mul_wrap,
    Arg("a"), Arg("b"));
  
  rb_cCvVUint8x64.define_method("*", [](const cv::v_uint8x64& self, const cv::v_uint8x64& other) -> cv::v_uint8x64
  {
    return self * other;
  });
  
  rb_cCvVInt8x64.define_method("*", [](const cv::v_int8x64& self, const cv::v_int8x64& other) -> cv::v_int8x64
  {
    return self * other;
  });
  
  rb_cCvVUint16x32.define_method("*", [](const cv::v_uint16x32& self, const cv::v_uint16x32& other) -> cv::v_uint16x32
  {
    return self * other;
  });
  
  rb_cCvVInt16x32.define_method("*", [](const cv::v_int16x32& self, const cv::v_int16x32& other) -> cv::v_int16x32
  {
    return self * other;
  });
  
  rb_cCvVUint8x64.define_method("assign_multiply", [](cv::v_uint8x64& self, const cv::v_uint8x64& other) -> cv::v_uint8x64&
  {
    return self *= other;
  });
  
  rb_cCvVInt8x64.define_method("assign_multiply", [](cv::v_int8x64& self, const cv::v_int8x64& other) -> cv::v_int8x64&
  {
    return self *= other;
  });
  
  rb_cCvVUint16x32.define_method("assign_multiply", [](cv::v_uint16x32& self, const cv::v_uint16x32& other) -> cv::v_uint16x32&
  {
    return self *= other;
  });
  
  rb_cCvVInt16x32.define_method("assign_multiply", [](cv::v_int16x32& self, const cv::v_int16x32& other) -> cv::v_int16x32&
  {
    return self *= other;
  });
  
  rb_mCv.define_module_function<cv::v_int16x32(*)(const cv::v_int16x32&, const cv::v_int16x32&)>("v_mul_hi", &cv::v_mul_hi,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const cv::v_uint16x32&, const cv::v_uint16x32&)>("v_mul_hi", &cv::v_mul_hi,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint8x64&, const cv::v_uint8x64&, cv::v_uint16x32&, cv::v_uint16x32&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int8x64&, const cv::v_int8x64&, cv::v_int16x32&, cv::v_int16x32&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int16x32&, const cv::v_int16x32&, cv::v_int32x16&, cv::v_int32x16&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint16x32&, const cv::v_uint16x32&, cv::v_uint32x16&, cv::v_uint32x16&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint32x16&, const cv::v_uint32x16&, cv::v_uint64x8&, cv::v_uint64x8&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int32x16&, const cv::v_int32x16&, cv::v_int64x8&, cv::v_int64x8&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const cv::v_float32x16&)>("v_not_nan", &cv::v_not_nan,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_float64x8&)>("v_not_nan", &cv::v_not_nan,
    Arg("a"));
  
  Module rb_mCvAnonymous = define_module_under(rb_mCv, "Anonymous");
  
  rb_cCv(anonymousNamespace)VRotateRightFalse0False0 = define_class_under<cv::(anonymous namespace)::_v_rotate_right<false, 0, false, 0>>(rb_mCvAnonymous, "VRotateRightFalse0False0").
    define_constructor(Constructor<cv::(anonymous namespace)::_v_rotate_right<false, 0, false, 0>>()).
    define_singleton_function("eval", &cv::::_v_rotate_right<false, 0, false, 0>::eval,
      Arg("a"), Arg(""));
  
  rb_cCv(anonymousNamespace)VRotateRightFalse0True16 = define_class_under<cv::(anonymous namespace)::_v_rotate_right<false, 0, true, 16>>(rb_mCvAnonymous, "VRotateRightFalse0True16").
    define_constructor(Constructor<cv::(anonymous namespace)::_v_rotate_right<false, 0, true, 16>>()).
    define_singleton_function("eval", &cv::::_v_rotate_right<false, 0, true, 16>::eval,
      Arg(""), Arg("b"));
  
  rb_cCv(anonymousNamespace)VRotateRightFalse0True32 = define_class_under<cv::(anonymous namespace)::_v_rotate_right<false, 0, true, 32>>(rb_mCvAnonymous, "VRotateRightFalse0True32").
    define_constructor(Constructor<cv::(anonymous namespace)::_v_rotate_right<false, 0, true, 32>>()).
    define_singleton_function("eval", &cv::::_v_rotate_right<false, 0, true, 32>::eval,
      Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_uint8x64&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int8x64(*)(const cv::v_int8x64&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const cv::v_uint16x32&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int16x32(*)(const cv::v_int16x32&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const cv::v_uint32x16&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int32x16&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const cv::v_float32x16&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x8(*)(const cv::v_uint64x8&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int64x8(*)(const cv::v_int64x8&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_float64x8&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<float(*)(const cv::v_float32x16&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int32x16&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint32x16&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int16x32&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint16x32&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function("v_reduce_sum4", &cv::v_reduce_sum4,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint8x64&, const cv::v_uint8x64&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int8x64&, const cv::v_int8x64&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint16x32&, const cv::v_uint16x32&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int16x32&, const cv::v_int16x32&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint32x16&, const cv::v_uint32x16&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int32x16&, const cv::v_int32x16&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<float(*)(const cv::v_float32x16&, const cv::v_float32x16&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<double(*)(const cv::v_float64x8&, const cv::v_float64x8&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_int8x64&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const cv::v_int16x32&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const cv::v_int32x16&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x8(*)(const cv::v_int64x8&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_uint8x64&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const cv::v_uint16x32&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const cv::v_uint32x16&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x8(*)(const cv::v_uint64x8&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int32x16&, const cv::v_int32x16&, const cv::v_int32x16&)>("v_fma", &cv::v_fma,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int32x16&, const cv::v_int32x16&, const cv::v_int32x16&)>("v_muladd", &cv::v_muladd,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const cv::v_float32x16&)>("v_invsqrt", &cv::v_invsqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_float64x8&)>("v_invsqrt", &cv::v_invsqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const cv::v_float32x16&)>("v_abs", &cv::v_abs,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_float64x8&)>("v_abs", &cv::v_abs,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_uint8x64&, const cv::v_uint8x64&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const cv::v_uint16x32&, const cv::v_uint16x32&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const cv::v_uint32x16&, const cv::v_uint32x16&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_int8x64&, const cv::v_int8x64&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const cv::v_int16x32&, const cv::v_int16x32&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const cv::v_int32x16&, const cv::v_int32x16&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const cv::v_float32x16&, const cv::v_float32x16&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_float64x8&, const cv::v_float64x8&)>("v_absdiff", &cv::v_absdiff,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int8x64(*)(const cv::v_int8x64&, const cv::v_int8x64&)>("v_absdiffs", &cv::v_absdiffs,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int16x32(*)(const cv::v_int16x32&, const cv::v_int16x32&)>("v_absdiffs", &cv::v_absdiffs,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_float32x16&)>("v_round", &cv::v_round,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_float64x8&)>("v_round", &cv::v_round,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_float64x8&, const cv::v_float64x8&)>("v_round", &cv::v_round,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_float32x16&)>("v_trunc", &cv::v_trunc,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_float64x8&)>("v_trunc", &cv::v_trunc,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_float32x16&)>("v_floor", &cv::v_floor,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_float64x8&)>("v_floor", &cv::v_floor,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_float32x16&)>("v_ceil", &cv::v_ceil,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_float64x8&)>("v_ceil", &cv::v_ceil,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const cv::v_int32x16&)>("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const cv::v_float64x8&)>("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const cv::v_float64x8&, const cv::v_float64x8&)>("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_int32x16&)>("v_cvt_f64", &cv::v_cvt_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_int32x16&)>("v_cvt_f64_high", &cv::v_cvt_f64_high,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_float32x16&)>("v_cvt_f64", &cv::v_cvt_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_float32x16&)>("v_cvt_f64_high", &cv::v_cvt_f64_high,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_int64x8&)>("v_cvt_f64", &cv::v_cvt_f64,
    Arg("v"));
  
  rb_mCv.define_module_function<cv::v_int8x64(*)(const int*, const int*)>("v512_lut", &cv::v512_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int8x64(*)(const int*, const int*)>("v512_lut_pairs", &cv::v512_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int8x64(*)(const int*, const int*)>("v512_lut_quads", &cv::v512_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const int*, const int*)>("v512_lut", &cv::v512_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const int*, const int*)>("v512_lut_pairs", &cv::v512_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const int*, const int*)>("v512_lut_quads", &cv::v512_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x32(*)(const short*, const int*)>("v512_lut", &cv::v512_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x32(*)(const short*, const int*)>("v512_lut_pairs", &cv::v512_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x32(*)(const short*, const int*)>("v512_lut_quads", &cv::v512_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const int*, const int*)>("v512_lut", &cv::v512_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const int*, const int*)>("v512_lut_pairs", &cv::v512_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const int*, const int*)>("v512_lut_quads", &cv::v512_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const int*, const int*)>("v512_lut", &cv::v512_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const int*, const int*)>("v512_lut_pairs", &cv::v512_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const int*, const int*)>("v512_lut_quads", &cv::v512_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const unsigned int*, const int*)>("v512_lut", &cv::v512_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const unsigned int*, const int*)>("v512_lut_pairs", &cv::v512_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const unsigned int*, const int*)>("v512_lut_quads", &cv::v512_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int64x8(*)(const int*, const int*)>("v512_lut", &cv::v512_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int64x8(*)(const int*, const int*)>("v512_lut_pairs", &cv::v512_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint64x8(*)(const int*, const int*)>("v512_lut", &cv::v512_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint64x8(*)(const int*, const int*)>("v512_lut_pairs", &cv::v512_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const float*, const int*)>("v512_lut", &cv::v512_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const float*, const int*)>("v512_lut_pairs", &cv::v512_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const float*, const int*)>("v512_lut_quads", &cv::v512_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const double*, const int*)>("v512_lut", &cv::v512_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const double*, const int*)>("v512_lut_pairs", &cv::v512_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const int*, const cv::v_int32x16&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const unsigned int*, const cv::v_int32x16&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const float*, const cv::v_int32x16&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const double*, const cv::v_int32x16&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<void(*)(const float*, const cv::v_int32x16&, cv::v_float32x16&, cv::v_float32x16&)>("v_lut_deinterleave", &cv::v_lut_deinterleave,
    Arg("tab"), Arg("idxvec"), Arg("x"), Arg("y"));
  
  rb_mCv.define_module_function<void(*)(const double*, const cv::v_int32x16&, cv::v_float64x8&, cv::v_float64x8&)>("v_lut_deinterleave", &cv::v_lut_deinterleave,
    Arg("tab"), Arg("idxvec"), Arg("x"), Arg("y"));
  
  rb_mCv.define_module_function<cv::v_int8x64(*)(const cv::v_int8x64&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_uint8x64&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int8x64(*)(const cv::v_int8x64&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_uint8x64&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int16x32(*)(const cv::v_int16x32&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const cv::v_uint16x32&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int16x32(*)(const cv::v_int16x32&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const cv::v_uint16x32&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int32x16&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const cv::v_uint32x16&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const cv::v_float32x16&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int8x64(*)(const cv::v_int8x64&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_uint8x64&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int16x32(*)(const cv::v_int16x32&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const cv::v_uint16x32&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int32x16&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const cv::v_uint32x16&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_float32x16(*)(const cv::v_float32x16&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int16x32&, const cv::v_int16x32&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int16x32&, const cv::v_int16x32&, const cv::v_int32x16&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x8(*)(const cv::v_int32x16&, const cv::v_int32x16&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x8(*)(const cv::v_int32x16&, const cv::v_int32x16&, const cv::v_int64x8&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const cv::v_uint8x64&, const cv::v_uint8x64&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const cv::v_uint8x64&, const cv::v_uint8x64&, const cv::v_uint32x16&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int8x64&, const cv::v_int8x64&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int8x64&, const cv::v_int8x64&, const cv::v_int32x16&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint64x8(*)(const cv::v_uint16x32&, const cv::v_uint16x32&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint64x8(*)(const cv::v_uint16x32&, const cv::v_uint16x32&, const cv::v_uint64x8&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x8(*)(const cv::v_int16x32&, const cv::v_int16x32&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x8(*)(const cv::v_int16x32&, const cv::v_int16x32&, const cv::v_int64x8&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_int32x16&, const cv::v_int32x16&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_int32x16&, const cv::v_int32x16&, const cv::v_float64x8&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int16x32&, const cv::v_int16x32&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int16x32&, const cv::v_int16x32&, const cv::v_int32x16&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x8(*)(const cv::v_int32x16&, const cv::v_int32x16&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x8(*)(const cv::v_int32x16&, const cv::v_int32x16&, const cv::v_int64x8&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const cv::v_uint8x64&, const cv::v_uint8x64&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const cv::v_uint8x64&, const cv::v_uint8x64&, const cv::v_uint32x16&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int8x64&, const cv::v_int8x64&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int8x64&, const cv::v_int8x64&, const cv::v_int32x16&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint64x8(*)(const cv::v_uint16x32&, const cv::v_uint16x32&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint64x8(*)(const cv::v_uint16x32&, const cv::v_uint16x32&, const cv::v_uint64x8&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x8(*)(const cv::v_int16x32&, const cv::v_int16x32&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x8(*)(const cv::v_int16x32&, const cv::v_int16x32&, const cv::v_int64x8&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_int32x16&, const cv::v_int32x16&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float64x8(*)(const cv::v_int32x16&, const cv::v_int32x16&, const cv::v_float64x8&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function("v_matmul", &cv::v_matmul,
    Arg("v"), Arg("m0"), Arg("m1"), Arg("m2"), Arg("m3"));
  
  rb_mCv.define_module_function("v_matmuladd", &cv::v_matmuladd,
    Arg("v"), Arg("m0"), Arg("m1"), Arg("m2"), Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int8x64(*)(const cv::v_int16x32&, const cv::v_int16x32&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_uint16x32&, const cv::v_uint16x32&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_int16x32&, const cv::v_int16x32&)>("v_pack_u", &cv::v_pack_u,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int16x32&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint16x32&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int16x32&)>("v_pack_u_store", &cv::v_pack_u_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int16x32(*)(const cv::v_int32x16&, const cv::v_int32x16&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const cv::v_uint32x16&, const cv::v_uint32x16&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x32(*)(const cv::v_int32x16&, const cv::v_int32x16&)>("v_pack_u", &cv::v_pack_u,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(short*, const cv::v_int32x16&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint32x16&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int32x16&)>("v_pack_u_store", &cv::v_pack_u_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x16(*)(const cv::v_uint64x8&, const cv::v_uint64x8&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x16(*)(const cv::v_int64x8&, const cv::v_int64x8&)>("v_pack", &cv::v_pack,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint64x8&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("a"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_int64x8&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_uint16x32&, const cv::v_uint16x32&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_uint32x16&, const cv::v_uint32x16&, const cv::v_uint32x16&, const cv::v_uint32x16&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<cv::v_uint8x64(*)(const cv::v_uint64x8&, const cv::v_uint64x8&, const cv::v_uint64x8&, const cv::v_uint64x8&, const cv::v_uint64x8&, const cv::v_uint64x8&, const cv::v_uint64x8&, const cv::v_uint64x8&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("e"), Arg("f"), Arg("g"), Arg("h"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint8x64&, cv::v_uint8x64&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint16x32&, cv::v_uint16x32&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const unsigned int*, cv::v_uint32x16&, cv::v_uint32x16&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint64x8&, cv::v_uint64x8&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint8x64&, cv::v_uint8x64&, cv::v_uint8x64&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint16x32&, cv::v_uint16x32&, cv::v_uint16x32&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const unsigned int*, cv::v_uint32x16&, cv::v_uint32x16&, cv::v_uint32x16&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint64x8&, cv::v_uint64x8&, cv::v_uint64x8&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint8x64&, cv::v_uint8x64&, cv::v_uint8x64&, cv::v_uint8x64&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint16x32&, cv::v_uint16x32&, cv::v_uint16x32&, cv::v_uint16x32&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const unsigned int*, cv::v_uint32x16&, cv::v_uint32x16&, cv::v_uint32x16&, cv::v_uint32x16&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const int*, cv::v_uint64x8&, cv::v_uint64x8&, cv::v_uint64x8&, cv::v_uint64x8&)>("v_load_deinterleave", &cv::v_load_deinterleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint8x64&, const cv::v_uint8x64&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("x"), Arg("y"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint16x32&, const cv::v_uint16x32&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("x"), Arg("y"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint32x16&, const cv::v_uint32x16&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("x"), Arg("y"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint64x8&, const cv::v_uint64x8&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("x"), Arg("y"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint8x64&, const cv::v_uint8x64&, const cv::v_uint8x64&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint16x32&, const cv::v_uint16x32&, const cv::v_uint16x32&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint32x16&, const cv::v_uint32x16&, const cv::v_uint32x16&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint64x8&, const cv::v_uint64x8&, const cv::v_uint64x8&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint8x64&, const cv::v_uint8x64&, const cv::v_uint8x64&, const cv::v_uint8x64&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint16x32&, const cv::v_uint16x32&, const cv::v_uint16x32&, const cv::v_uint16x32&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(unsigned int*, const cv::v_uint32x16&, const cv::v_uint32x16&, const cv::v_uint32x16&, const cv::v_uint32x16&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<void(*)(int*, const cv::v_uint64x8&, const cv::v_uint64x8&, const cv::v_uint64x8&, const cv::v_uint64x8&, int)>("v_store_interleave", &cv::v_store_interleave,
    Arg("ptr"), Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("mode") = static_cast<int>());
  
  rb_mCv.define_module_function<int(*)(const cv::v_int8x64&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int16x32&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int32x16&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int64x8&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint8x64&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint16x32&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint32x16&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint64x8&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float32x16&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float64x8&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int8x64&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int8x64&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int16x32&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int16x32&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int32x16&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int32x16&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int64x8&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int64x8&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_float32x16&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_float32x16&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_float64x8&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_float64x8&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_uint8x64&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_uint16x32&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_uint32x16&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_uint64x8&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_uint8x64&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_uint16x32&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_uint32x16&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_uint64x8&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int8x64&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint8x64&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int16x32&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint16x32&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int32x16&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint32x16&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float32x16&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int64x8&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint64x8&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float64x8&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function("v512_cleanup", &cv::v512_cleanup);

}