#include <opencv2/core/dualquaternion.hpp>
#include "dualquaternion-rb.hpp"

using namespace Rice;

#include "dualquaternion-rb.ipp"

void Init_Core_Dualquaternion()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::DualQuat<double>> dual_quatd = DualQuat_instantiate<double>(rb_mCv, "DualQuatd");

  Rice::Data_Type<cv::DualQuat<float>> dual_quatf = DualQuat_instantiate<float>(rb_mCv, "DualQuatf");
}
