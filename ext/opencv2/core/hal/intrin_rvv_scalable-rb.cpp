#include <opencv2/core/hal/intrin_rvv_scalable.hpp>
#include "intrin_rvv_scalable-rb.hpp"

using namespace Rice;


void Init_IntrinRvvScalable()
{
  Class(rb_cObject).define_constant("CV_RVV_MAX_VLEN", CV_RVV_MAX_VLEN);
  
  Class(rb_cObject).define_constant("CV_SIMD_SCALABLE", CV_SIMD_SCALABLE);
  
  Class(rb_cObject).define_constant("CV_SIMD_SCALABLE_64F", CV_SIMD_SCALABLE_64F);
  
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_constant("__cv_rvv_e8m1_nlanes", cv::__cv_rvv_e8m1_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e16m1_nlanes", cv::__cv_rvv_e16m1_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e32m1_nlanes", cv::__cv_rvv_e32m1_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e64m1_nlanes", cv::__cv_rvv_e64m1_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e8m2_nlanes", cv::__cv_rvv_e8m2_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e16m2_nlanes", cv::__cv_rvv_e16m2_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e32m2_nlanes", cv::__cv_rvv_e32m2_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e64m2_nlanes", cv::__cv_rvv_e64m2_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e8m4_nlanes", cv::__cv_rvv_e8m4_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e16m4_nlanes", cv::__cv_rvv_e16m4_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e32m4_nlanes", cv::__cv_rvv_e32m4_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e64m4_nlanes", cv::__cv_rvv_e64m4_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e8m8_nlanes", cv::__cv_rvv_e8m8_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e16m8_nlanes", cv::__cv_rvv_e16m8_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e32m8_nlanes", cv::__cv_rvv_e32m8_nlanes);
  
  rb_mCv.define_constant("__cv_rvv_e64m8_nlanes", cv::__cv_rvv_e64m8_nlanes);
  
  rb_mCv.define_module_function<float(*)(const int&)>("v_get0", &cv::v_get0,
    Arg("v"));
  
  rb_mCv.define_module_function<double(*)(const int&)>("v_get0", &cv::v_get0,
    Arg("v"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_reinterpret_as_f32", &cv::v_reinterpret_as_f32,
    Arg("v"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_reinterpret_as_f64", &cv::v_reinterpret_as_f64,
    Arg("v"));
  
  rb_mCv.define_module_function<int(*)(const double*, const int&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("vidx"));
  
  rb_mCv.define_module_function<int(*)(const cv::uchar*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<int(*)(const cv::uchar*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<int(*)(const cv::uchar*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<int(*)(const cv::ushort*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<int(*)(const cv::ushort*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<int(*)(const cv::ushort*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<int(*)(const unsigned int*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<int(*)(const unsigned int*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<int(*)(const unsigned int*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<int(*)(const cv::uint64*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<int(*)(const cv::uint64*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&, const int&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("e"), Arg("f"), Arg("g"), Arg("h"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_mul_hi", &cv::v_mul_hi,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_mul_hi", &cv::v_mul_hi,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_not", &cv::v_not,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_not", &cv::v_not,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_not_nan", &cv::v_not_nan,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_not_nan", &cv::v_not_nan,
    Arg("a"));
  
  rb_mCv.define_module_function("v_reduce_sum4", &cv::v_reduce_sum4,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_sqrt", &cv::v_sqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_invsqrt", &cv::v_invsqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_sqrt", &cv::v_sqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_invsqrt", &cv::v_invsqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_magnitude", &cv::v_magnitude,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_sqr_magnitude", &cv::v_sqr_magnitude,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_magnitude", &cv::v_magnitude,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_sqr_magnitude", &cv::v_sqr_magnitude,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_fma", &cv::v_fma,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_fma", &cv::v_fma,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_muladd", &cv::v_muladd,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_muladd", &cv::v_muladd,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_fma", &cv::v_fma,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_muladd", &cv::v_muladd,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<bool(*)(const int&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const int&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const int&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const int&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const int&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const int&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const int&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const int&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const int&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const int&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const int&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const int&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_select", &cv::v_select,
    Arg("mask"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_select", &cv::v_select,
    Arg("mask"), Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_cvt_f64", &cv::v_cvt_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_cvt_f64_high", &cv::v_cvt_f64_high,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_cvt_f64", &cv::v_cvt_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_cvt_f64_high", &cv::v_cvt_f64_high,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_cvt_f64", &cv::v_cvt_f64,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::uchar*)>("v_load_expand_q", &cv::v_load_expand_q,
    Arg("ptr"));
  
  rb_mCv.define_module_function<int(*)(const cv::schar*)>("v_load_expand_q", &cv::v_load_expand_q,
    Arg("ptr"));
  
  rb_mCv.define_module_function<void(*)(const int&, const int&, int&, int&)>("v_zip", &cv::v_zip,
    Arg("a0"), Arg("a1"), Arg("b0"), Arg("b1"));
  
  rb_mCv.define_singleton_attr("IdxInterleavePairs", &cv::idx_interleave_pairs);
  
  rb_mCv.define_singleton_attr("IdxInterleaveQuads", &cv::idx_interleave_quads);
  
  rb_mCv.define_singleton_attr("PopCountTable", &cv::popCountTable);
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::int64(*)(const int&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::int64(*)(const int&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::hfloat*)>("v_load_expand", &cv::v_load_expand,
    Arg("ptr"));
  
  rb_mCv.define_module_function<void(*)(cv::hfloat*, const int&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("v"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_round", &cv::v_round,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_floor", &cv::v_floor,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_ceil", &cv::v_ceil,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_trunc", &cv::v_trunc,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_round", &cv::v_round,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_round", &cv::v_round,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_floor", &cv::v_floor,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_ceil", &cv::v_ceil,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&)>("v_trunc", &cv::v_trunc,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(const int&, const int&, const int&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function("v_matmul", &cv::v_matmul,
    Arg("v"), Arg("m0"), Arg("m1"), Arg("m2"), Arg("m3"));
  
  rb_mCv.define_module_function("v_matmuladd", &cv::v_matmuladd,
    Arg("v"), Arg("m0"), Arg("m1"), Arg("m2"), Arg("a"));
  
  rb_mCv.define_module_function("v_cleanup", &cv::v_cleanup);

}