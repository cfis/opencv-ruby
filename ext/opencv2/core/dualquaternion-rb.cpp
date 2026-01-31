#include "dualquaternion-rb.ipp"

void Init_Core_Dualquaternion()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::DualQuat<double>> dual_quatd = define_class_under<cv::DualQuat<double>>(rb_mCv, "DualQuatd").
    define(&DualQuat_builder<Data_Type<cv::DualQuat<double>>, double>);

  Rice::Data_Type<cv::DualQuat<float>> dual_quatf = define_class_under<cv::DualQuat<float>>(rb_mCv, "DualQuatf").
    define(&DualQuat_builder<Data_Type<cv::DualQuat<float>>, float>);
}