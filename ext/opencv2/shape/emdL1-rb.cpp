#include <opencv2/shape/emdL1.hpp>
#include "emdL1-rb.hpp"

using namespace Rice;

void Init_Shape_EmdL1()
{
  Module rb_mCv = define_module("Cv");

  rb_mCv.define_module_function<float(*)(cv::InputArray, cv::InputArray)>("emdl1", &cv::EMDL1,
    Arg("signature1"), Arg("signature2"));
}