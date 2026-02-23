#include <opencv2/core/cv_cpu_dispatch.h>
#include "cv_cpu_dispatch-rb.hpp"

using namespace Rice;

void Init_Core_CvCpuDispatch()
{
  Class(rb_cObject).define_constant("CV_MMX", CV_MMX);

  Class(rb_cObject).define_constant("CV_SSE", CV_SSE);

  Class(rb_cObject).define_constant("CV_SSE2", CV_SSE2);

  Class(rb_cObject).define_constant("CV_SSE3", CV_SSE3);

  Class(rb_cObject).define_constant("CV_SSSE3", CV_SSSE3);

  Class(rb_cObject).define_constant("CV_SSE4_1", CV_SSE4_1);

  Class(rb_cObject).define_constant("CV_SSE4_2", CV_SSE4_2);

  Class(rb_cObject).define_constant("CV_POPCNT", CV_POPCNT);

  Class(rb_cObject).define_constant("CV_AVX", CV_AVX);

  Class(rb_cObject).define_constant("CV_FP16", CV_FP16);

  Class(rb_cObject).define_constant("CV_AVX2", CV_AVX2);

  Class(rb_cObject).define_constant("CV_FMA3", CV_FMA3);

  Class(rb_cObject).define_constant("CV_AVX_512F", CV_AVX_512F);

  Class(rb_cObject).define_constant("CV_AVX_512BW", CV_AVX_512BW);

  Class(rb_cObject).define_constant("CV_AVX_512CD", CV_AVX_512CD);

  Class(rb_cObject).define_constant("CV_AVX_512DQ", CV_AVX_512DQ);

  Class(rb_cObject).define_constant("CV_AVX_512ER", CV_AVX_512ER);

  Class(rb_cObject).define_constant("CV_AVX_512IFMA", CV_AVX_512IFMA);

  Class(rb_cObject).define_constant("CV_AVX_512PF", CV_AVX_512PF);

  Class(rb_cObject).define_constant("CV_AVX_512VBMI", CV_AVX_512VBMI);

  Class(rb_cObject).define_constant("CV_AVX_512VL", CV_AVX_512VL);

  Class(rb_cObject).define_constant("CV_AVX_5124FMAPS", CV_AVX_5124FMAPS);

  Class(rb_cObject).define_constant("CV_AVX_5124VNNIW", CV_AVX_5124VNNIW);

  Class(rb_cObject).define_constant("CV_AVX_512VPOPCNTDQ", CV_AVX_512VPOPCNTDQ);

  Class(rb_cObject).define_constant("CV_AVX_512VNNI", CV_AVX_512VNNI);

  Class(rb_cObject).define_constant("CV_AVX_512VBMI2", CV_AVX_512VBMI2);

  Class(rb_cObject).define_constant("CV_AVX_512BITALG", CV_AVX_512BITALG);

  Class(rb_cObject).define_constant("CV_AVX512_COMMON", CV_AVX512_COMMON);

  Class(rb_cObject).define_constant("CV_AVX512_KNL", CV_AVX512_KNL);

  Class(rb_cObject).define_constant("CV_AVX512_KNM", CV_AVX512_KNM);

  Class(rb_cObject).define_constant("CV_AVX512_SKX", CV_AVX512_SKX);

  Class(rb_cObject).define_constant("CV_AVX512_CNL", CV_AVX512_CNL);

  Class(rb_cObject).define_constant("CV_AVX512_CLX", CV_AVX512_CLX);

  Class(rb_cObject).define_constant("CV_AVX512_ICL", CV_AVX512_ICL);

  Class(rb_cObject).define_constant("CV_NEON", CV_NEON);

  Class(rb_cObject).define_constant("CV_RVV071", CV_RVV071);

  Class(rb_cObject).define_constant("CV_VSX", CV_VSX);

  Class(rb_cObject).define_constant("CV_VSX3", CV_VSX3);

  Class(rb_cObject).define_constant("CV_MSA", CV_MSA);

  Class(rb_cObject).define_constant("CV_WASM_SIMD", CV_WASM_SIMD);

  Class(rb_cObject).define_constant("CV_RVV", CV_RVV);

  Class(rb_cObject).define_constant("CV_LSX", CV_LSX);

  Class(rb_cObject).define_constant("CV_LASX", CV_LASX);

  Class(rb_cObject).define_constant("CV_MMX", CV_MMX);

  Class(rb_cObject).define_constant("CV_SSE", CV_SSE);

  Class(rb_cObject).define_constant("CV_SSE2", CV_SSE2);
}
