#include <opencv2/flann/params.h>
#include "params-rb.hpp"

using namespace Rice;

void Init_Flann_Params()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::SearchParams> rb_cCvflannSearchParams = define_class_under<cvflann::SearchParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "SearchParams").
    define_constructor(Constructor<cvflann::SearchParams, int, float, bool>(),
      Arg("checks") = static_cast<int>(32), Arg("eps") = static_cast<float>(0), Arg("sorted") = static_cast<bool>(true)).
    define_constructor(Constructor<cvflann::SearchParams, int, float, bool, bool>(),
      Arg("checks"), Arg("eps"), Arg("sorted"), Arg("explore_all_trees")).
    define_method<void(cvflann::SearchParams::*)(int, float, bool, bool)>("init", &cvflann::SearchParams::init,
      Arg("checks") = static_cast<int>(32), Arg("eps") = static_cast<float>(0), Arg("sorted") = static_cast<bool>(true), Arg("explore_all_trees") = static_cast<bool>(false));

  rb_mCvflann.define_module_function<void(*)(const cvflann::IndexParams&, std::ostream&)>("print_params", &cvflann::print_params,
    Arg("params"), Arg("stream"));

  rb_mCvflann.define_module_function<void(*)(const cvflann::IndexParams&)>("print_params", &cvflann::print_params,
    Arg("params"));
}