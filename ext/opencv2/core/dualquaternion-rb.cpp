#include <opencv2/core/dualquaternion.hpp>
#include "dualquaternion-rb.hpp"

using namespace Rice;

Rice::Class dual_quatd;
Rice::Class dual_quatf;

template<typename Data_Type_T, typename _Tp>
inline void DualQuat_builder(Data_Type_T& klass)
{
  klass.define_constant("CV_DUAL_QUAT_EPS", cv::DualQuat<_Tp>::CV_DUAL_QUAT_EPS).
    define_constructor(Constructor<cv::DualQuat<_Tp>>()).
    define_constructor(Constructor<cv::DualQuat<_Tp>, const _Tp, const _Tp, const _Tp, const _Tp, const _Tp, const _Tp, const _Tp, const _Tp>(),
      Arg("w"), Arg("x"), Arg("y"), Arg("z"), Arg("w_"), Arg("x_"), Arg("y_"), Arg("z_")).
    define_constructor(Constructor<cv::DualQuat<_Tp>, const cv::Vec<_Tp, 8>&>(),
      Arg("q") = static_cast<const cv::Vec<_Tp, 8>&>(8)).
    define_attr("w", &cv::DualQuat<_Tp>::w).
    define_attr("x", &cv::DualQuat<_Tp>::x).
    define_attr("y", &cv::DualQuat<_Tp>::y).
    define_attr("z", &cv::DualQuat<_Tp>::z).
    define_attr("w_", &cv::DualQuat<_Tp>::w_).
    define_attr("x_", &cv::DualQuat<_Tp>::x_).
    define_attr("y_", &cv::DualQuat<_Tp>::y_).
    define_attr("z_", &cv::DualQuat<_Tp>::z_).
    define_method("get_real_part", &cv::DualQuat<_Tp>::getRealPart).
    define_method("get_dual_part", &cv::DualQuat<_Tp>::getDualPart).
    define_method("conjugate", &cv::DualQuat<_Tp>::conjugate).
    define_method("get_rotation", &cv::DualQuat<_Tp>::getRotation,
      Arg("assume_unit")).
    define_method("get_translation", &cv::DualQuat<_Tp>::getTranslation,
      Arg("assume_unit")).
    define_method("norm", &cv::DualQuat<_Tp>::norm).
    define_method("normalize", &cv::DualQuat<_Tp>::normalize).
    define_method("inv", &cv::DualQuat<_Tp>::inv,
      Arg("assume_unit")).
    define_method("dot", &cv::DualQuat<_Tp>::dot,
      Arg("p")).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const _Tp, cv::QuatAssumeType) const>("power", &cv::DualQuat<_Tp>::power,
      Arg("t"), Arg("assume_unit")).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&, cv::QuatAssumeType) const>("power", &cv::DualQuat<_Tp>::power,
      Arg("q"), Arg("assume_unit")).
    define_method("exp", &cv::DualQuat<_Tp>::exp).
    define_method("log", &cv::DualQuat<_Tp>::log,
      Arg("assume_unit")).
    define_method("to_vec", &cv::DualQuat<_Tp>::toVec).
    define_method("to_mat", &cv::DualQuat<_Tp>::toMat,
      Arg("assume_unit")).
    define_method("to_affine3", &cv::DualQuat<_Tp>::toAffine3,
      Arg("assume_unit")).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)() const>("-", &cv::DualQuat<_Tp>::operator-).
    define_method("==", &cv::DualQuat<_Tp>::operator==,
      Arg("arg_0")).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&) const>("-", &cv::DualQuat<_Tp>::operator-,
      Arg("arg_0")).
    define_method("assign_minus", &cv::DualQuat<_Tp>::operator-=,
      Arg("arg_0")).
    define_method("+", &cv::DualQuat<_Tp>::operator+,
      Arg("arg_0")).
    define_method("assign_plus", &cv::DualQuat<_Tp>::operator+=,
      Arg("arg_0")).
    // Manual
    // There is no general implementation, just specializations for DualQuat
    // template define_method<cv::DualQuat<_Tp>&(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&)>("assign_multiply", &cv::DualQuat<_Tp>::operator*=,
    //  Arg("arg_0")).
    //template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const _Tp)>("assign_multiply", &cv::DualQuat<_Tp>::operator*=,
    //  Arg("s")).
    define_method("*", &cv::DualQuat<_Tp>::operator*,
      Arg("arg_0")).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const _Tp) const>("/", &cv::DualQuat<_Tp>::operator/,
      Arg("s")).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&) const>("/", &cv::DualQuat<_Tp>::operator/,
      Arg("arg_0")).
    //template define_method<cv::DualQuat<_Tp>&(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&)>("assign_divide", &cv::DualQuat<_Tp>::operator/=,
    //  Arg("arg_0")).
    //template define_method<cv::Quat<_Tp>&(cv::DualQuat<_Tp>::*)(const _Tp)>("assign_divide", &cv::DualQuat<_Tp>::operator/=,
    //  Arg("s")).
    define_singleton_function("create_from_quat", &cv::DualQuat<_Tp>::createFromQuat,
      Arg("real_part"), Arg("dual_part")).
    define_singleton_function("create_from_angle_axis_trans", &cv::DualQuat<_Tp>::createFromAngleAxisTrans,
      Arg("angle"), Arg("axis") = static_cast<const cv::Vec<_Tp, 3>&>(3), Arg("translation") = static_cast<const cv::Vec<_Tp, 3>&>(3)).
    define_singleton_function("create_from_mat", &cv::DualQuat<_Tp>::createFromMat,
      Arg("_r")).
    define_singleton_function("create_from_affine3", &cv::DualQuat<_Tp>::createFromAffine3,
      Arg("r")).
    define_singleton_function("create_from_pitch", &cv::DualQuat<_Tp>::createFromPitch,
      Arg("angle"), Arg("d"), Arg("axis") = static_cast<const cv::Vec<_Tp, 3>&>(3), Arg("moment") = static_cast<const cv::Vec<_Tp, 3>&>(3)).
    define_singleton_function("sclerp", &cv::DualQuat<_Tp>::sclerp,
      Arg("q1"), Arg("q2"), Arg("t"), Arg("direct_change"), Arg("assume_unit")).
    define_singleton_function("dqblend", &cv::DualQuat<_Tp>::dqblend,
      Arg("q1"), Arg("q2"), Arg("t"), Arg("assume_unit")).
    define_singleton_function("gdqblend", &cv::DualQuat<_Tp>::gdqblend,
      Arg("dualquat"), Arg("weights"), Arg("assume_unit"));
};
void Init_Dualquaternion()
{
  Module rb_mCv = define_module("Cv");

  dual_quatd = define_class_under<cv::DualQuat<double>>(rb_mCv, "DualQuatd").
    define(&DualQuat_builder<Data_Type<cv::DualQuat<double>>, double>);

  dual_quatf = define_class_under<cv::DualQuat<float>>(rb_mCv, "DualQuatf").
    define(&DualQuat_builder<Data_Type<cv::DualQuat<float>>, float>);

}