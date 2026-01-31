#include <opencv2/flann/timer.h>
#include "timer-rb.hpp"

using namespace Rice;

void Init_Flann_Timer()
{
  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::StartStopTimer> rb_cCvflannStartStopTimer = define_class_under<cvflann::StartStopTimer>(rb_mCvflann, "StartStopTimer").
    define_attr("value", &cvflann::StartStopTimer::value).
    define_constructor(Constructor<cvflann::StartStopTimer>()).
    define_method<void(cvflann::StartStopTimer::*)()>("start", &cvflann::StartStopTimer::start).
    define_method<void(cvflann::StartStopTimer::*)()>("stop", &cvflann::StartStopTimer::stop).
    define_method<void(cvflann::StartStopTimer::*)()>("reset", &cvflann::StartStopTimer::reset);
}