#include <opencv2/core/quaternion.hpp>
#include "quaternion-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvQuatEnum;

template<typename Data_Type_T, typename _Tp>
inline void Quat_builder(Data_Type_T& klass)
{
  klass.define_constant("cv::Quat::CV_QUAT_EPS", cv::Quat<_Tp>::cv::Quat::CV_QUAT_EPS).
    define_constant("CV_QUAT_CONVERT_THRESHOLD", cv::Quat<_Tp>::CV_QUAT_CONVERT_THRESHOLD).
    define_constructor(Constructor<cv::Quat<_Tp>>()).
    define_constructor(Constructor<cv::Quat<_Tp>, const cv::Vec<_Tp, 4>&>(),
      Arg("coeff")).
    define_constructor(Constructor<cv::Quat<_Tp>, _Tp, _Tp, _Tp, _Tp>(),
      Arg("w"), Arg("x"), Arg("y"), Arg("z")).
    template define_singleton_function("create_from_angle_axis", &cv::Quat<_Tp>::createFromAngleAxis,
      Arg("angle"), Arg("axis")).
    template define_singleton_function("create_from_rot_mat", &cv::Quat<_Tp>::createFromRotMat,
      Arg("r")).
    template define_singleton_function("create_from_rvec", &cv::Quat<_Tp>::createFromRvec,
      Arg("rvec")).
    template define_singleton_function("create_from_euler_angles", &cv::Quat<_Tp>::createFromEulerAngles,
      Arg("angles"), Arg("euler_angles_type")).
    template define_singleton_function("create_from_y_rot", &cv::Quat<_Tp>::createFromYRot,
      Arg("theta")).
    template define_singleton_function("create_from_x_rot", &cv::Quat<_Tp>::createFromXRot,
      Arg("theta")).
    template define_singleton_function("create_from_z_rot", &cv::Quat<_Tp>::createFromZRot,
      Arg("theta")).
    template define_method("at", &cv::Quat<_Tp>::at,
      Arg("index")).
    template define_method("conjugate", &cv::Quat<_Tp>::conjugate).
    template define_method("exp", &cv::Quat<_Tp>::exp).
    template define_method("log", &cv::Quat<_Tp>::log,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const _Tp, cv::QuatAssumeType) const>("power", &cv::Quat<_Tp>::power,
      Arg("x"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method("sqrt", &cv::Quat<_Tp>::sqrt,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&, cv::QuatAssumeType) const>("power", &cv::Quat<_Tp>::power,
      Arg("q"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method("cross_product", &cv::Quat<_Tp>::crossProduct,
      Arg("q")).
    template define_method("norm", &cv::Quat<_Tp>::norm).
    template define_method("normalize", &cv::Quat<_Tp>::normalize).
    template define_method("inv", &cv::Quat<_Tp>::inv,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method("sinh", &cv::Quat<_Tp>::sinh).
    template define_method("cosh", &cv::Quat<_Tp>::cosh).
    template define_method("tanh", &cv::Quat<_Tp>::tanh).
    template define_method("sin", &cv::Quat<_Tp>::sin).
    template define_method("cos", &cv::Quat<_Tp>::cos).
    template define_method("tan", &cv::Quat<_Tp>::tan).
    template define_method("asin", &cv::Quat<_Tp>::asin).
    template define_method("acos", &cv::Quat<_Tp>::acos).
    template define_method("atan", &cv::Quat<_Tp>::atan).
    template define_method("asinh", &cv::Quat<_Tp>::asinh).
    template define_method("acosh", &cv::Quat<_Tp>::acosh).
    template define_method("atanh", &cv::Quat<_Tp>::atanh).
    template define_method("normal?", &cv::Quat<_Tp>::isNormal,
      Arg("eps") = static_cast<_Tp>(cv::Quat<_Tp>::CV_QUAT_EPS)).
    template define_method("assert_normal", &cv::Quat<_Tp>::assertNormal,
      Arg("eps") = static_cast<_Tp>(cv::Quat<_Tp>::CV_QUAT_EPS)).
    template define_method("to_rot_mat3x3", &cv::Quat<_Tp>::toRotMat3x3,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method("to_rot_mat4x4", &cv::Quat<_Tp>::toRotMat4x4,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method("to_vec", &cv::Quat<_Tp>::toVec).
    template define_method("to_rot_vec", &cv::Quat<_Tp>::toRotVec,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method("get_angle", &cv::Quat<_Tp>::getAngle,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method("get_axis", &cv::Quat<_Tp>::getAxis,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method("dot", &cv::Quat<_Tp>::dot,
      Arg("q")).
    template define_singleton_function("lerp", &cv::Quat<_Tp>::lerp,
      Arg("q0"), Arg("q1"), Arg("t")).
    template define_singleton_function("nlerp", &cv::Quat<_Tp>::nlerp,
      Arg("q0"), Arg("q1"), Arg("t"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_singleton_function("slerp", &cv::Quat<_Tp>::slerp,
      Arg("q0"), Arg("q1"), Arg("t"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT), Arg("direct_change") = static_cast<bool>(true)).
    template define_singleton_function("squad", &cv::Quat<_Tp>::squad,
      Arg("q0"), Arg("s0"), Arg("s1"), Arg("q1"), Arg("t"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT), Arg("direct_change") = static_cast<bool>(true)).
    template define_singleton_function("inter_point", &cv::Quat<_Tp>::interPoint,
      Arg("q0"), Arg("q1"), Arg("q2"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_singleton_function("spline", &cv::Quat<_Tp>::spline,
      Arg("q0"), Arg("q1"), Arg("q2"), Arg("q3"), Arg("t"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)() const>("-", &cv::Quat<_Tp>::operator-).
    template define_method("==", &cv::Quat<_Tp>::operator==,
      Arg("")).
    template define_method("+", &cv::Quat<_Tp>::operator+,
      Arg("")).
    template define_method("assign_plus", &cv::Quat<_Tp>::operator+=,
      Arg("")).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&) const>("-", &cv::Quat<_Tp>::operator-,
      Arg("")).
    template define_method("assign_minus", &cv::Quat<_Tp>::operator-=,
      Arg("")).
    template define_method<cv::Quat<_Tp>&(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&)>("assign_multiply", &cv::Quat<_Tp>::operator*=,
      Arg("")).
    template define_method<cv::Quat<_Tp>&(cv::Quat<_Tp>::*)(const _Tp)>("assign_multiply", &cv::Quat<_Tp>::operator*=,
      Arg("s")).
    template define_method("dereference", &cv::Quat<_Tp>::operator*,
      Arg("")).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const _Tp) const>("/", &cv::Quat<_Tp>::operator/,
      Arg("s")).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&) const>("/", &cv::Quat<_Tp>::operator/,
      Arg("")).
    template define_method<cv::Quat<_Tp>&(cv::Quat<_Tp>::*)(const _Tp)>("assign_divide", &cv::Quat<_Tp>::operator/=,
      Arg("s")).
    template define_method<cv::Quat<_Tp>&(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&)>("assign_divide", &cv::Quat<_Tp>::operator/=,
      Arg("")).
    template define_method<_Tp&(cv::Quat<_Tp>::*)(std::size_t)>("[]", &cv::Quat<_Tp>::operator[],
      Arg("n")).
    define_method("[]=", [](cv::Quat<_Tp>&self, int index, _Tp & value)
    {
        self[index] = value;
    }).
    template define_method<const _Tp&(cv::Quat<_Tp>::*)(std::size_t) const>("[]", &cv::Quat<_Tp>::operator[],
      Arg("n")).
    template define_method("to_euler_angles", &cv::Quat<_Tp>::toEulerAngles,
      Arg("euler_angles_type")).
    define_attr("w", &cv::Quat<_Tp>::w).
    define_attr("x", &cv::Quat<_Tp>::x).
    define_attr("y", &cv::Quat<_Tp>::y).
    define_attr("z", &cv::Quat<_Tp>::z);
};
void Init_Quaternion()
{
  Module rb_mCv = define_module("Cv");
  
  Enum<cv::QuatAssumeType> rb_cCvQuatAssumeType = define_enum_under<cv::QuatAssumeType>("QuatAssumeType", rb_mCv).
    define_value("cv::QUAT_ASSUME_NOT_UNIT", cv::QuatAssumeType::QUAT_ASSUME_NOT_UNIT).
    define_value("QUAT_ASSUME_UNIT", cv::QuatAssumeType::QUAT_ASSUME_UNIT);
  
  rb_cCvQuatEnum = define_class_under<cv::QuatEnum>(rb_mCv, "QuatEnum").
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

}