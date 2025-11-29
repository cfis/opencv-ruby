#include <opencv2/core/fast_math.hpp>
#include "fast_math-rb.hpp"

using namespace Rice;


void Init_FastMath()
{
#ifdef OPENCV_USE_FASTMATH_BUILTINS
  Class(rb_cObject).define_constant("OPENCV_USE_FASTMATH_BUILTINS", OPENCV_USE_FASTMATH_BUILTINS);
#endif
  
  define_global_function<int(*)(double)>("cv_round", &cvRound,
    Arg("value"));
  
  define_global_function<int(*)(double)>("cv_floor", &cvFloor,
    Arg("value"));
  
  define_global_function<int(*)(double)>("cv_ceil", &cvCeil,
    Arg("value"));
  
  define_global_function<int(*)(double)>("cv_is_na_n", &cvIsNaN,
    Arg("value"));
  
  define_global_function<int(*)(double)>("cv_is_inf", &cvIsInf,
    Arg("value"));
  
  define_global_function<int(*)(float)>("cv_round", &cvRound,
    Arg("value"));
  
  define_global_function<int(*)(int)>("cv_round", &cvRound,
    Arg("value"));
  
  define_global_function<int(*)(float)>("cv_floor", &cvFloor,
    Arg("value"));
  
  define_global_function<int(*)(int)>("cv_floor", &cvFloor,
    Arg("value"));
  
  define_global_function<int(*)(float)>("cv_ceil", &cvCeil,
    Arg("value"));
  
  define_global_function<int(*)(int)>("cv_ceil", &cvCeil,
    Arg("value"));
  
  define_global_function<int(*)(float)>("cv_is_na_n", &cvIsNaN,
    Arg("value"));
  
  define_global_function<int(*)(float)>("cv_is_inf", &cvIsInf,
    Arg("value"));

}