#include <opencv2/signal/signal_resample.hpp>
#include "signal_resample-rb.hpp"

using namespace Rice;

void Init_Signal_SignalResample()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvSignal = define_module_under(rb_mCv, "Signal");

  rb_mCvSignal.define_module_function<void(*)(cv::InputArray, cv::OutputArray, const int, const int)>("resample_signal", &cv::signal::resampleSignal,
    Arg("input_signal"), Arg("out_signal"), Arg("in_freq"), Arg("out_freq"));
}
