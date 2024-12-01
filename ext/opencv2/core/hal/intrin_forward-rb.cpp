#include <opencv2/core/hal/intrin_forward.hpp>
#include "intrin_forward-rb.hpp"

using namespace Rice;


void Init_IntrinForward()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint8x16&, cv::v_uint16x8&, cv::v_uint16x8&)>("v_expand", &cv::v_expand,
    Arg(""), Arg(""), Arg(""));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int8x16&, cv::v_int16x8&, cv::v_int16x8&)>("v_expand", &cv::v_expand,
    Arg(""), Arg(""), Arg(""));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint16x8&, cv::v_uint32x4&, cv::v_uint32x4&)>("v_expand", &cv::v_expand,
    Arg(""), Arg(""), Arg(""));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int16x8&, cv::v_int32x4&, cv::v_int32x4&)>("v_expand", &cv::v_expand,
    Arg(""), Arg(""), Arg(""));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint32x4&, cv::v_uint64x2&, cv::v_uint64x2&)>("v_expand", &cv::v_expand,
    Arg(""), Arg(""), Arg(""));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int32x4&, cv::v_int64x2&, cv::v_int64x2&)>("v_expand", &cv::v_expand,
    Arg(""), Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint8x16&)>("v_expand_low", &cv::v_expand_low,
    Arg(""));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int8x16&)>("v_expand_low", &cv::v_expand_low,
    Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint16x8&)>("v_expand_low", &cv::v_expand_low,
    Arg(""));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int16x8&)>("v_expand_low", &cv::v_expand_low,
    Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint32x4&)>("v_expand_low", &cv::v_expand_low,
    Arg(""));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int32x4&)>("v_expand_low", &cv::v_expand_low,
    Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint8x16&)>("v_expand_high", &cv::v_expand_high,
    Arg(""));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int8x16&)>("v_expand_high", &cv::v_expand_high,
    Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint16x8&)>("v_expand_high", &cv::v_expand_high,
    Arg(""));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int16x8&)>("v_expand_high", &cv::v_expand_high,
    Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint32x4&)>("v_expand_high", &cv::v_expand_high,
    Arg(""));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int32x4&)>("v_expand_high", &cv::v_expand_high,
    Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_pack", &cv::v_pack,
    Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_pack", &cv::v_pack,
    Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint32x4&, const cv::v_uint32x4&)>("v_pack", &cv::v_pack,
    Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_pack", &cv::v_pack,
    Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint64x2&, const cv::v_uint64x2&)>("v_pack", &cv::v_pack,
    Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int64x2&, const cv::v_int64x2&)>("v_pack", &cv::v_pack,
    Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_pack_u", &cv::v_pack_u,
    Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_pack_u", &cv::v_pack_u,
    Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&, const cv::v_uint8x16&)>("v_mul_wrap", &cv::v_mul_wrap,
    Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_mul_wrap", &cv::v_mul_wrap,
    Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_mul_wrap", &cv::v_mul_wrap,
    Arg(""), Arg(""));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_mul_wrap", &cv::v_mul_wrap,
    Arg(""), Arg(""));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint8x16&, const cv::v_uint8x16&, cv::v_uint16x8&, cv::v_uint16x8&)>("v_mul_expand", &cv::v_mul_expand,
    Arg(""), Arg(""), Arg(""), Arg(""));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int8x16&, const cv::v_int8x16&, cv::v_int16x8&, cv::v_int16x8&)>("v_mul_expand", &cv::v_mul_expand,
    Arg(""), Arg(""), Arg(""), Arg(""));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint16x8&, const cv::v_uint16x8&, cv::v_uint32x4&, cv::v_uint32x4&)>("v_mul_expand", &cv::v_mul_expand,
    Arg(""), Arg(""), Arg(""), Arg(""));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int16x8&, const cv::v_int16x8&, cv::v_int32x4&, cv::v_int32x4&)>("v_mul_expand", &cv::v_mul_expand,
    Arg(""), Arg(""), Arg(""), Arg(""));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint32x4&, const cv::v_uint32x4&, cv::v_uint64x2&, cv::v_uint64x2&)>("v_mul_expand", &cv::v_mul_expand,
    Arg(""), Arg(""), Arg(""), Arg(""));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int32x4&, const cv::v_int32x4&, cv::v_int64x2&, cv::v_int64x2&)>("v_mul_expand", &cv::v_mul_expand,
    Arg(""), Arg(""), Arg(""), Arg(""));
  
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

}