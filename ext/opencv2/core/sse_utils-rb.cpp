#include <opencv2/core/sse_utils.hpp>
#include "sse_utils-rb.hpp"

using namespace Rice;


void Init_SseUtils()
{
  define_global_function<void(*)(__m128i&, __m128i&, __m128i&, __m128i&)>("_mm_deinterleave_epi8", &_mm_deinterleave_epi8,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"));
  
  define_global_function<void(*)(__m128i&, __m128i&, __m128i&, __m128i&, __m128i&, __m128i&)>("_mm_deinterleave_epi8", &_mm_deinterleave_epi8,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"), Arg("v_b0"), Arg("v_b1"));
  
  define_global_function<void(*)(__m128i&, __m128i&, __m128i&, __m128i&, __m128i&, __m128i&, __m128i&, __m128i&)>("_mm_deinterleave_epi8", &_mm_deinterleave_epi8,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"), Arg("v_b0"), Arg("v_b1"), Arg("v_a0"), Arg("v_a1"));
  
  define_global_function<void(*)(__m128i&, __m128i&, __m128i&, __m128i&)>("_mm_interleave_epi8", &_mm_interleave_epi8,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"));
  
  define_global_function<void(*)(__m128i&, __m128i&, __m128i&, __m128i&, __m128i&, __m128i&)>("_mm_interleave_epi8", &_mm_interleave_epi8,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"), Arg("v_b0"), Arg("v_b1"));
  
  define_global_function<void(*)(__m128i&, __m128i&, __m128i&, __m128i&, __m128i&, __m128i&, __m128i&, __m128i&)>("_mm_interleave_epi8", &_mm_interleave_epi8,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"), Arg("v_b0"), Arg("v_b1"), Arg("v_a0"), Arg("v_a1"));
  
  define_global_function<void(*)(__m128i&, __m128i&, __m128i&, __m128i&)>("_mm_deinterleave_epi16", &_mm_deinterleave_epi16,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"));
  
  define_global_function<void(*)(__m128i&, __m128i&, __m128i&, __m128i&, __m128i&, __m128i&)>("_mm_deinterleave_epi16", &_mm_deinterleave_epi16,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"), Arg("v_b0"), Arg("v_b1"));
  
  define_global_function<void(*)(__m128i&, __m128i&, __m128i&, __m128i&, __m128i&, __m128i&, __m128i&, __m128i&)>("_mm_deinterleave_epi16", &_mm_deinterleave_epi16,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"), Arg("v_b0"), Arg("v_b1"), Arg("v_a0"), Arg("v_a1"));
  
  define_global_function<void(*)(__m128&, __m128&, __m128&, __m128&)>("_mm_deinterleave_ps", &_mm_deinterleave_ps,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"));
  
  define_global_function<void(*)(__m128&, __m128&, __m128&, __m128&, __m128&, __m128&)>("_mm_deinterleave_ps", &_mm_deinterleave_ps,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"), Arg("v_b0"), Arg("v_b1"));
  
  define_global_function<void(*)(__m128&, __m128&, __m128&, __m128&, __m128&, __m128&, __m128&, __m128&)>("_mm_deinterleave_ps", &_mm_deinterleave_ps,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"), Arg("v_b0"), Arg("v_b1"), Arg("v_a0"), Arg("v_a1"));
  
  define_global_function<void(*)(__m128&, __m128&, __m128&, __m128&)>("_mm_interleave_ps", &_mm_interleave_ps,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"));
  
  define_global_function<void(*)(__m128&, __m128&, __m128&, __m128&, __m128&, __m128&)>("_mm_interleave_ps", &_mm_interleave_ps,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"), Arg("v_b0"), Arg("v_b1"));
  
  define_global_function<void(*)(__m128&, __m128&, __m128&, __m128&, __m128&, __m128&, __m128&, __m128&)>("_mm_interleave_ps", &_mm_interleave_ps,
    Arg("v_r0"), Arg("v_r1"), Arg("v_g0"), Arg("v_g1"), Arg("v_b0"), Arg("v_b1"), Arg("v_a0"), Arg("v_a1"));

}