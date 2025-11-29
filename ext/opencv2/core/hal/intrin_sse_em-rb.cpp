#include <opencv2/core/hal/intrin_sse_em.hpp>
#include "intrin_sse_em-rb.hpp"

using namespace Rice;


void Init_IntrinSseEm()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_singleton_attr("M128i", &cv::__m128i);
  
  rb_mCv.define_module_function("_v128_blendv_epi8", &cv::_v128_blendv_epi8,
    Arg("a"), Arg("b"), Arg("mask"));
  
  rb_mCv.define_module_function("_v128_cvtepu8_epi16", &cv::_v128_cvtepu8_epi16,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_cvtepi8_epi16", &cv::_v128_cvtepi8_epi16,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_cvtepu8_epi32", &cv::_v128_cvtepu8_epi32,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_cvtepi8_epi32", &cv::_v128_cvtepi8_epi32,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_cvtepu16_epi32", &cv::_v128_cvtepu16_epi32,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_cvtepi16_epi32", &cv::_v128_cvtepi16_epi32,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_cvtepu32_epi64", &cv::_v128_cvtepu32_epi64,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_cvtepi32_epi64", &cv::_v128_cvtepi32_epi64,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_mullo_epi32", &cv::_v128_mullo_epi32,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("_v128_min_epu32", &cv::_v128_min_epu32,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("_v128_cvtepu8_epi16_high", &cv::_v128_cvtepu8_epi16_high,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_cvtepi8_epi16_high", &cv::_v128_cvtepi8_epi16_high,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_cvtepu16_epi32_high", &cv::_v128_cvtepu16_epi32_high,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_cvtepi16_epi32_high", &cv::_v128_cvtepi16_epi32_high,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_cvtepu32_epi64_high", &cv::_v128_cvtepu32_epi64_high,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_cvtepi32_epi64_high", &cv::_v128_cvtepi32_epi64_high,
    Arg("a"));
  
  rb_mCv.define_module_function("_v128_packs_epu32", &cv::_v128_packs_epu32,
    Arg("a"), Arg("b"));

}