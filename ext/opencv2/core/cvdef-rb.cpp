#include <opencv2/core/cvdef.h>
#include "../../opencv_ruby_version.hpp"
#include "cvdef-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvHfloat;

void Init_Cvdef()
{
  Class(rb_cObject).define_constant("CV_ENABLE_UNROLLED", CV_ENABLE_UNROLLED);

  Class(rb_cObject).define_constant("CV_CPU_NONE", CV_CPU_NONE);

  Class(rb_cObject).define_constant("CV_CPU_MMX", CV_CPU_MMX);

  Class(rb_cObject).define_constant("CV_CPU_SSE", CV_CPU_SSE);

  Class(rb_cObject).define_constant("CV_CPU_SSE2", CV_CPU_SSE2);

  Class(rb_cObject).define_constant("CV_CPU_SSE3", CV_CPU_SSE3);

  Class(rb_cObject).define_constant("CV_CPU_SSSE3", CV_CPU_SSSE3);

  Class(rb_cObject).define_constant("CV_CPU_SSE4_1", CV_CPU_SSE4_1);

  Class(rb_cObject).define_constant("CV_CPU_SSE4_2", CV_CPU_SSE4_2);

  Class(rb_cObject).define_constant("CV_CPU_POPCNT", CV_CPU_POPCNT);

  Class(rb_cObject).define_constant("CV_CPU_FP16", CV_CPU_FP16);

  Class(rb_cObject).define_constant("CV_CPU_AVX", CV_CPU_AVX);

  Class(rb_cObject).define_constant("CV_CPU_AVX2", CV_CPU_AVX2);

  Class(rb_cObject).define_constant("CV_CPU_FMA3", CV_CPU_FMA3);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512F", CV_CPU_AVX_512F);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512BW", CV_CPU_AVX_512BW);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512CD", CV_CPU_AVX_512CD);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512DQ", CV_CPU_AVX_512DQ);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512ER", CV_CPU_AVX_512ER);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512IFMA512", CV_CPU_AVX_512IFMA512);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512IFMA", CV_CPU_AVX_512IFMA);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512PF", CV_CPU_AVX_512PF);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512VBMI", CV_CPU_AVX_512VBMI);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512VL", CV_CPU_AVX_512VL);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512VBMI2", CV_CPU_AVX_512VBMI2);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512VNNI", CV_CPU_AVX_512VNNI);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512BITALG", CV_CPU_AVX_512BITALG);

  Class(rb_cObject).define_constant("CV_CPU_AVX_512VPOPCNTDQ", CV_CPU_AVX_512VPOPCNTDQ);

  Class(rb_cObject).define_constant("CV_CPU_AVX_5124VNNIW", CV_CPU_AVX_5124VNNIW);

  Class(rb_cObject).define_constant("CV_CPU_AVX_5124FMAPS", CV_CPU_AVX_5124FMAPS);

  Class(rb_cObject).define_constant("CV_CPU_NEON", CV_CPU_NEON);

#if RUBY_CV_VERSION >= 407
  Class(rb_cObject).define_constant("CV_CPU_NEON_DOTPROD", CV_CPU_NEON_DOTPROD);
#endif

#if RUBY_CV_VERSION >= 409
  Class(rb_cObject).define_constant("CV_CPU_NEON_FP16", CV_CPU_NEON_FP16);

  Class(rb_cObject).define_constant("CV_CPU_NEON_BF16", CV_CPU_NEON_BF16);
#endif

  Class(rb_cObject).define_constant("CV_CPU_MSA", CV_CPU_MSA);

  Class(rb_cObject).define_constant("CV_CPU_RISCVV", CV_CPU_RISCVV);

  Class(rb_cObject).define_constant("CV_CPU_VSX", CV_CPU_VSX);

  Class(rb_cObject).define_constant("CV_CPU_VSX3", CV_CPU_VSX3);

  Class(rb_cObject).define_constant("CV_CPU_RVV", CV_CPU_RVV);

#if RUBY_CV_VERSION >= 409
  Class(rb_cObject).define_constant("CV_CPU_LSX", CV_CPU_LSX);

  Class(rb_cObject).define_constant("CV_CPU_LASX", CV_CPU_LASX);
#endif

  Class(rb_cObject).define_constant("CV_CPU_AVX512_SKX", CV_CPU_AVX512_SKX);

  Class(rb_cObject).define_constant("CV_CPU_AVX512_COMMON", CV_CPU_AVX512_COMMON);

  Class(rb_cObject).define_constant("CV_CPU_AVX512_KNL", CV_CPU_AVX512_KNL);

  Class(rb_cObject).define_constant("CV_CPU_AVX512_KNM", CV_CPU_AVX512_KNM);

  Class(rb_cObject).define_constant("CV_CPU_AVX512_CNL", CV_CPU_AVX512_CNL);

  Class(rb_cObject).define_constant("CV_CPU_AVX512_CLX", CV_CPU_AVX512_CLX);

  Class(rb_cObject).define_constant("CV_CPU_AVX512_ICL", CV_CPU_AVX512_ICL);

  Class(rb_cObject).define_constant("CV_HARDWARE_MAX_FEATURE", CV_HARDWARE_MAX_FEATURE);

  Class(rb_cObject).define_constant("CV_STRONG_ALIGNMENT", CV_STRONG_ALIGNMENT);

  Class(rb_cObject).define_constant("CV_PI", CV_PI);

  Class(rb_cObject).define_constant("CV_2PI", CV_2PI);

  Class(rb_cObject).define_constant("CV_LOG2", CV_LOG2);

  Class(rb_cObject).define_constant("CV_FP16_TYPE", CV_FP16_TYPE);

  Class(rb_cObject).define_constant("OPENCV_ABI_COMPATIBILITY", OPENCV_ABI_COMPATIBILITY);

#if RUBY_CV_VERSION >= 410
  Class(rb_cObject).define_constant("CV_MAX_DIM", CV_MAX_DIM);
#endif

  Class(rb_cObject).define_constant("CV_MAT_CONT_FLAG_SHIFT", CV_MAT_CONT_FLAG_SHIFT);

  Class(rb_cObject).define_constant("CV_SUBMAT_FLAG_SHIFT", CV_SUBMAT_FLAG_SHIFT);

  Class(rb_cObject).define_constant("CV_CXX11", CV_CXX11);

  Enum<CpuFeatures> rb_cCpuFeatures = define_enum<CpuFeatures>("CpuFeatures").
    define_value("CPU_MMX", CpuFeatures::CPU_MMX).
    define_value("CPU_SSE", CpuFeatures::CPU_SSE).
    define_value("CPU_SSE2", CpuFeatures::CPU_SSE2).
    define_value("CPU_SSE3", CpuFeatures::CPU_SSE3).
    define_value("CPU_SSSE3", CpuFeatures::CPU_SSSE3).
    define_value("CPU_SSE4_1", CpuFeatures::CPU_SSE4_1).
    define_value("CPU_SSE4_2", CpuFeatures::CPU_SSE4_2).
    define_value("CPU_POPCNT", CpuFeatures::CPU_POPCNT).
    define_value("CPU_FP16", CpuFeatures::CPU_FP16).
    define_value("CPU_AVX", CpuFeatures::CPU_AVX).
    define_value("CPU_AVX2", CpuFeatures::CPU_AVX2).
    define_value("CPU_FMA3", CpuFeatures::CPU_FMA3).
    define_value("CPU_AVX_512F", CpuFeatures::CPU_AVX_512F).
    define_value("CPU_AVX_512BW", CpuFeatures::CPU_AVX_512BW).
    define_value("CPU_AVX_512CD", CpuFeatures::CPU_AVX_512CD).
    define_value("CPU_AVX_512DQ", CpuFeatures::CPU_AVX_512DQ).
    define_value("CPU_AVX_512ER", CpuFeatures::CPU_AVX_512ER).
    define_value("CPU_AVX_512IFMA512", CpuFeatures::CPU_AVX_512IFMA512).
    define_value("CPU_AVX_512IFMA", CpuFeatures::CPU_AVX_512IFMA).
    define_value("CPU_AVX_512PF", CpuFeatures::CPU_AVX_512PF).
    define_value("CPU_AVX_512VBMI", CpuFeatures::CPU_AVX_512VBMI).
    define_value("CPU_AVX_512VL", CpuFeatures::CPU_AVX_512VL).
    define_value("CPU_AVX_512VBMI2", CpuFeatures::CPU_AVX_512VBMI2).
    define_value("CPU_AVX_512VNNI", CpuFeatures::CPU_AVX_512VNNI).
    define_value("CPU_AVX_512BITALG", CpuFeatures::CPU_AVX_512BITALG).
    define_value("CPU_AVX_512VPOPCNTDQ", CpuFeatures::CPU_AVX_512VPOPCNTDQ).
    define_value("CPU_AVX_5124VNNIW", CpuFeatures::CPU_AVX_5124VNNIW).
    define_value("CPU_AVX_5124FMAPS", CpuFeatures::CPU_AVX_5124FMAPS).
    define_value("CPU_NEON", CpuFeatures::CPU_NEON).
    define_value("CPU_MSA", CpuFeatures::CPU_MSA).
    define_value("CPU_RISCVV", CpuFeatures::CPU_RISCVV).
    define_value("CPU_VSX", CpuFeatures::CPU_VSX).
    define_value("CPU_VSX3", CpuFeatures::CPU_VSX3).
    define_value("CPU_RVV", CpuFeatures::CPU_RVV).
    define_value("CPU_AVX512_SKX", CpuFeatures::CPU_AVX512_SKX).
    define_value("CPU_AVX512_COMMON", CpuFeatures::CPU_AVX512_COMMON).
    define_value("CPU_AVX512_KNL", CpuFeatures::CPU_AVX512_KNL).
    define_value("CPU_AVX512_KNM", CpuFeatures::CPU_AVX512_KNM).
    define_value("CPU_AVX512_CNL", CpuFeatures::CPU_AVX512_CNL).
    define_value("CPU_AVX512_CLX", CpuFeatures::CPU_AVX512_CLX).
    define_value("CPU_AVX512_ICL", CpuFeatures::CPU_AVX512_ICL).
    define_value("CPU_MAX_FEATURE", CpuFeatures::CPU_MAX_FEATURE);

#if RUBY_CV_VERSION >= 407
  rb_cCpuFeatures.
    define_value("CPU_NEON_DOTPROD", CpuFeatures::CPU_NEON_DOTPROD);
#endif

#if RUBY_CV_VERSION >= 409
  rb_cCpuFeatures.
    define_value("CPU_NEON_FP16", CpuFeatures::CPU_NEON_FP16).
    define_value("CPU_NEON_BF16", CpuFeatures::CPU_NEON_BF16).
    define_value("CPU_LSX", CpuFeatures::CPU_LSX).
    define_value("CPU_LASX", CpuFeatures::CPU_LASX);
#endif

  Class cv16suf = define_class<Cv16suf>("Cv16suf").
    define_attr("i", &Cv16suf::i).
    define_attr("u", &Cv16suf::u);

  Class cv32suf = define_class<Cv32suf>("Cv32suf").
    define_attr("i", &Cv32suf::i).
    define_attr("u", &Cv32suf::u).
    define_attr("f", &Cv32suf::f);

  Class cv64suf = define_class<Cv64suf>("Cv64suf").
    define_attr("i", &Cv64suf::i).
    define_attr("u", &Cv64suf::u).
    define_attr("f", &Cv64suf::f);

  Module rb_mCv = define_module("Cv");

#if RUBY_CV_VERSION >= 410
  rb_cCvHfloat = define_class_under<cv::hfloat>(rb_mCv, "Hfloat").
    define_constructor(Constructor<cv::hfloat>()).
    define_constructor(Constructor<cv::hfloat, float>(),
      Arg("x")).
    define_method("to_float", [](const cv::hfloat& self) -> float
      {
        return self;
      });

  rb_mCv.define_module_function("hfloat_from_bits", &cv::hfloatFromBits,
    Arg("w"));
#endif
}