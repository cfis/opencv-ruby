#include <opencv2/core/cv_cpu_helper.h>
#include "cv_cpu_helper-rb.hpp"

using namespace Rice;

void Init_Core_CvCpuHelper()
{
  Class(rb_cObject).define_constant("CV_TRY_SSE", CV_TRY_SSE);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_SSE", CV_CPU_FORCE_SSE);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_SSE", CV_CPU_HAS_SUPPORT_SSE);

  Class(rb_cObject).define_constant("CV_TRY_SSE2", CV_TRY_SSE2);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_SSE2", CV_CPU_FORCE_SSE2);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_SSE2", CV_CPU_HAS_SUPPORT_SSE2);

  Class(rb_cObject).define_constant("CV_TRY_SSE3", CV_TRY_SSE3);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_SSE3", CV_CPU_FORCE_SSE3);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_SSE3", CV_CPU_HAS_SUPPORT_SSE3);

  Class(rb_cObject).define_constant("CV_TRY_SSSE3", CV_TRY_SSSE3);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_SSSE3", CV_CPU_FORCE_SSSE3);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_SSSE3", CV_CPU_HAS_SUPPORT_SSSE3);

  Class(rb_cObject).define_constant("CV_TRY_SSE4_1", CV_TRY_SSE4_1);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_SSE4_1", CV_CPU_FORCE_SSE4_1);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_SSE4_1", CV_CPU_HAS_SUPPORT_SSE4_1);

  Class(rb_cObject).define_constant("CV_TRY_SSE4_2", CV_TRY_SSE4_2);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_SSE4_2", CV_CPU_FORCE_SSE4_2);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_SSE4_2", CV_CPU_HAS_SUPPORT_SSE4_2);

  Class(rb_cObject).define_constant("CV_TRY_POPCNT", CV_TRY_POPCNT);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_POPCNT", CV_CPU_FORCE_POPCNT);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_POPCNT", CV_CPU_HAS_SUPPORT_POPCNT);

  Class(rb_cObject).define_constant("CV_TRY_AVX", CV_TRY_AVX);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_AVX", CV_CPU_FORCE_AVX);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_AVX", CV_CPU_HAS_SUPPORT_AVX);

  Class(rb_cObject).define_constant("CV_TRY_FP16", CV_TRY_FP16);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_FP16", CV_CPU_FORCE_FP16);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_FP16", CV_CPU_HAS_SUPPORT_FP16);

  Class(rb_cObject).define_constant("CV_TRY_AVX2", CV_TRY_AVX2);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_AVX2", CV_CPU_FORCE_AVX2);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_AVX2", CV_CPU_HAS_SUPPORT_AVX2);

  Class(rb_cObject).define_constant("CV_TRY_FMA3", CV_TRY_FMA3);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_FMA3", CV_CPU_FORCE_FMA3);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_FMA3", CV_CPU_HAS_SUPPORT_FMA3);

  Class(rb_cObject).define_constant("CV_TRY_AVX_512F", CV_TRY_AVX_512F);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_AVX_512F", CV_CPU_FORCE_AVX_512F);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_AVX_512F", CV_CPU_HAS_SUPPORT_AVX_512F);

  Class(rb_cObject).define_constant("CV_TRY_AVX512_COMMON", CV_TRY_AVX512_COMMON);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_AVX512_COMMON", CV_CPU_FORCE_AVX512_COMMON);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_AVX512_COMMON", CV_CPU_HAS_SUPPORT_AVX512_COMMON);

  Class(rb_cObject).define_constant("CV_TRY_AVX512_KNL", CV_TRY_AVX512_KNL);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_AVX512_KNL", CV_CPU_FORCE_AVX512_KNL);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_AVX512_KNL", CV_CPU_HAS_SUPPORT_AVX512_KNL);

  Class(rb_cObject).define_constant("CV_TRY_AVX512_KNM", CV_TRY_AVX512_KNM);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_AVX512_KNM", CV_CPU_FORCE_AVX512_KNM);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_AVX512_KNM", CV_CPU_HAS_SUPPORT_AVX512_KNM);

  Class(rb_cObject).define_constant("CV_TRY_AVX512_SKX", CV_TRY_AVX512_SKX);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_AVX512_SKX", CV_CPU_FORCE_AVX512_SKX);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_AVX512_SKX", CV_CPU_HAS_SUPPORT_AVX512_SKX);

  Class(rb_cObject).define_constant("CV_TRY_AVX512_CNL", CV_TRY_AVX512_CNL);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_AVX512_CNL", CV_CPU_FORCE_AVX512_CNL);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_AVX512_CNL", CV_CPU_HAS_SUPPORT_AVX512_CNL);

  Class(rb_cObject).define_constant("CV_TRY_AVX512_CLX", CV_TRY_AVX512_CLX);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_AVX512_CLX", CV_CPU_FORCE_AVX512_CLX);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_AVX512_CLX", CV_CPU_HAS_SUPPORT_AVX512_CLX);

  Class(rb_cObject).define_constant("CV_TRY_AVX512_ICL", CV_TRY_AVX512_ICL);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_AVX512_ICL", CV_CPU_FORCE_AVX512_ICL);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_AVX512_ICL", CV_CPU_HAS_SUPPORT_AVX512_ICL);

  Class(rb_cObject).define_constant("CV_TRY_NEON", CV_TRY_NEON);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_NEON", CV_CPU_FORCE_NEON);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_NEON", CV_CPU_HAS_SUPPORT_NEON);

  Class(rb_cObject).define_constant("CV_TRY_NEON_DOTPROD", CV_TRY_NEON_DOTPROD);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_NEON_DOTPROD", CV_CPU_FORCE_NEON_DOTPROD);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_NEON_DOTPROD", CV_CPU_HAS_SUPPORT_NEON_DOTPROD);

  Class(rb_cObject).define_constant("CV_TRY_NEON_FP16", CV_TRY_NEON_FP16);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_NEON_FP16", CV_CPU_FORCE_NEON_FP16);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_NEON_FP16", CV_CPU_HAS_SUPPORT_NEON_FP16);

  Class(rb_cObject).define_constant("CV_TRY_NEON_BF16", CV_TRY_NEON_BF16);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_NEON_BF16", CV_CPU_FORCE_NEON_BF16);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_NEON_BF16", CV_CPU_HAS_SUPPORT_NEON_BF16);

  Class(rb_cObject).define_constant("CV_TRY_MSA", CV_TRY_MSA);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_MSA", CV_CPU_FORCE_MSA);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_MSA", CV_CPU_HAS_SUPPORT_MSA);

  Class(rb_cObject).define_constant("CV_TRY_VSX", CV_TRY_VSX);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_VSX", CV_CPU_FORCE_VSX);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_VSX", CV_CPU_HAS_SUPPORT_VSX);

  Class(rb_cObject).define_constant("CV_TRY_VSX3", CV_TRY_VSX3);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_VSX3", CV_CPU_FORCE_VSX3);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_VSX3", CV_CPU_HAS_SUPPORT_VSX3);

  Class(rb_cObject).define_constant("CV_TRY_RVV", CV_TRY_RVV);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_RVV", CV_CPU_FORCE_RVV);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_RVV", CV_CPU_HAS_SUPPORT_RVV);

  Class(rb_cObject).define_constant("CV_TRY_LSX", CV_TRY_LSX);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_LSX", CV_CPU_FORCE_LSX);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_LSX", CV_CPU_HAS_SUPPORT_LSX);

  Class(rb_cObject).define_constant("CV_TRY_LASX", CV_TRY_LASX);

  Class(rb_cObject).define_constant("CV_CPU_FORCE_LASX", CV_CPU_FORCE_LASX);

  Class(rb_cObject).define_constant("CV_CPU_HAS_SUPPORT_LASX", CV_CPU_HAS_SUPPORT_LASX);
}
