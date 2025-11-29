#include <opencv2/core/hal/intrin_rvv_compat_overloaded.hpp>
#include "intrin_rvv_compat_overloaded-rb.hpp"

using namespace Rice;


void Init_IntrinRvvCompatOverloaded()
{
  define_global_function("vmul", &vmul,
    Arg("op1"), Arg("op2"), Arg("vl"));
  
  define_global_function("vreinterpret_u32mf2", &vreinterpret_u32mf2,
    Arg("val"));
  
  define_global_function("vreinterpret_u32mf2", &vreinterpret_u32mf2,
    Arg("val"));

}