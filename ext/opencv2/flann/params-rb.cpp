#include <opencv2/core/base.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/params.h>
#include "params-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannSearchParams;
Rice::Class rb_cIndexParams;

void Init_Params()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cIndexParams = define_map<cv::String, cvflann::any>("IndexParams");
  
  rb_cCvflannSearchParams = define_class_under<cvflann::SearchParams, cvflann::IndexParams>(rb_mCvflann, "SearchParams").
    define_constructor(Constructor<cvflann::SearchParams, int, float, bool>(),
      Arg("checks") = static_cast<int>(32), Arg("eps") = static_cast<float>(0), Arg("sorted") = static_cast<bool>(true)).
    define_constructor(Constructor<cvflann::SearchParams, int, float, bool, bool>(),
      Arg("checks"), Arg("eps"), Arg("sorted"), Arg("explore_all_trees")).
    define_method("init", &cvflann::SearchParams::init,
      Arg("checks") = static_cast<int>(32), Arg("eps") = static_cast<float>(0), Arg("sorted") = static_cast<bool>(true), Arg("explore_all_trees") = static_cast<bool>(false));
  
  //rb_mCvflann.define_module_function<void(*)(const cvflann::IndexParams&, std::ostream&)>("print_params", &cvflann::print_params,
  //  Arg("params"), Arg("stream"));
  
  rb_mCvflann.define_module_function<void(*)(const cvflann::IndexParams&)>("print_params", &cvflann::print_params,
    Arg("params"));

}