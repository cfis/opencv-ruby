#include <opencv2/core/quaternion.hpp>
#include "quaternion-rb.hpp"

using namespace Rice;

#include "quaternion-rb.ipp"

void Init_Core_Quaternion()
{
  Module rb_mCv = define_module("Cv");

  Enum<cv::QuatAssumeType> rb_cCvQuatAssumeType = define_enum_under<cv::QuatAssumeType>("QuatAssumeType", rb_mCv).
    define_value("QUAT_ASSUME_NOT_UNIT", cv::QuatAssumeType::QUAT_ASSUME_NOT_UNIT).
    define_value("QUAT_ASSUME_UNIT", cv::QuatAssumeType::QUAT_ASSUME_UNIT);

  Rice::Data_Type<cv::QuatEnum> rb_cCvQuatEnum = define_class_under<cv::QuatEnum>(rb_mCv, "QuatEnum").
    define_constructor(Constructor<cv::QuatEnum>());

  Enum<cv::QuatEnum::EulerAnglesType> rb_cCvQuatEnumEulerAnglesType = define_enum_under<cv::QuatEnum::EulerAnglesType>("EulerAnglesType", rb_cCvQuatEnum).
    define_value("INT_XYZ", cv::QuatEnum::EulerAnglesType::INT_XYZ).
    define_value("INT_XZY", cv::QuatEnum::EulerAnglesType::INT_XZY).
    define_value("INT_YXZ", cv::QuatEnum::EulerAnglesType::INT_YXZ).
    define_value("INT_YZX", cv::QuatEnum::EulerAnglesType::INT_YZX).
    define_value("INT_ZXY", cv::QuatEnum::EulerAnglesType::INT_ZXY).
    define_value("INT_ZYX", cv::QuatEnum::EulerAnglesType::INT_ZYX).
    define_value("INT_XYX", cv::QuatEnum::EulerAnglesType::INT_XYX).
    define_value("INT_XZX", cv::QuatEnum::EulerAnglesType::INT_XZX).
    define_value("INT_YXY", cv::QuatEnum::EulerAnglesType::INT_YXY).
    define_value("INT_YZY", cv::QuatEnum::EulerAnglesType::INT_YZY).
    define_value("INT_ZXZ", cv::QuatEnum::EulerAnglesType::INT_ZXZ).
    define_value("INT_ZYZ", cv::QuatEnum::EulerAnglesType::INT_ZYZ).
    define_value("EXT_XYZ", cv::QuatEnum::EulerAnglesType::EXT_XYZ).
    define_value("EXT_XZY", cv::QuatEnum::EulerAnglesType::EXT_XZY).
    define_value("EXT_YXZ", cv::QuatEnum::EulerAnglesType::EXT_YXZ).
    define_value("EXT_YZX", cv::QuatEnum::EulerAnglesType::EXT_YZX).
    define_value("EXT_ZXY", cv::QuatEnum::EulerAnglesType::EXT_ZXY).
    define_value("EXT_ZYX", cv::QuatEnum::EulerAnglesType::EXT_ZYX).
    define_value("EXT_XYX", cv::QuatEnum::EulerAnglesType::EXT_XYX).
    define_value("EXT_XZX", cv::QuatEnum::EulerAnglesType::EXT_XZX).
    define_value("EXT_YXY", cv::QuatEnum::EulerAnglesType::EXT_YXY).
    define_value("EXT_YZY", cv::QuatEnum::EulerAnglesType::EXT_YZY).
    define_value("EXT_ZXZ", cv::QuatEnum::EulerAnglesType::EXT_ZXZ).
    define_value("EXT_ZYZ", cv::QuatEnum::EulerAnglesType::EXT_ZYZ).
    define_value("EULER_ANGLES_MAX_VALUE", cv::QuatEnum::EulerAnglesType::EULER_ANGLES_MAX_VALUE);

  Rice::Data_Type<cv::Quat<double>> quatd = Quat_instantiate<double>(rb_mCv, "Quatd");

  Rice::Data_Type<cv::Quat<float>> quatf = Quat_instantiate<float>(rb_mCv, "Quatf");
}