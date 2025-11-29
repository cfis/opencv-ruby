#include <opencv2/flann/general.h>
#include "general-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannFLANNException;

void Init_General()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannFLANNException = define_class_under<cvflann::FLANNException, cv::Exception>(rb_mCvflann, "FLANNException").
    define_constructor(Constructor<cvflann::FLANNException, const char*>(),
      Arg("message")).
    define_constructor(Constructor<cvflann::FLANNException, const cv::String&>(),
      Arg("message"));

}