#include <opencv2/core/base.hpp> // Manual
#include <opencv2/flann/defines.h> // Manual
#include <opencv2/flann/flann_base.hpp>
#include "flann_base-rb.hpp"

using namespace Rice;

#include "flann_base-rb.ipp"

void Init_Flann_FlannBase()
{
  Module rb_mCvflann = define_module("Cvflann");

#if RUBY_CV_VERSION >= 408
  Rice::Data_Type<cvflann::FILEScopeGuard> rb_cCvflannFILEScopeGuard = define_class_under<cvflann::FILEScopeGuard>(rb_mCvflann, "FILEScopeGuard").
    define_constructor(Constructor<cvflann::FILEScopeGuard, FILE*>(),
      Arg("file"));
#endif

  rb_mCvflann.define_module_function<void(*)(int)>("log_verbosity", &cvflann::log_verbosity,
    Arg("level"));

  Rice::Data_Type<cvflann::SavedIndexParams> rb_cCvflannSavedIndexParams = define_class_under<cvflann::SavedIndexParams, std::map<std::basic_string<char>, cvflann::any>>(rb_mCvflann, "SavedIndexParams").
    define_constructor(Constructor<cvflann::SavedIndexParams, cv::String>(),
      Arg("filename"));
}
