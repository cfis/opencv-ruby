template<typename _Tp>
inline Rice::Data_Type<cv::DualQuat<_Tp>> DualQuat_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::DualQuat<_Tp>>(parent, name).
    define_constant("CV_DUAL_QUAT_EPS", cv::DualQuat<_Tp>::CV_DUAL_QUAT_EPS).
    define_constructor(Constructor<cv::DualQuat<_Tp>>()).
    define_constructor(Constructor<cv::DualQuat<_Tp>, const _Tp, const _Tp, const _Tp, const _Tp, const _Tp, const _Tp, const _Tp, const _Tp>(),
      Arg("w"), Arg("x"), Arg("y"), Arg("z"), Arg("w_"), Arg("x_"), Arg("y_"), Arg("z_")).
    define_constructor(Constructor<cv::DualQuat<_Tp>, const cv::Vec<_Tp, 8>&>(),
      Arg("q")).
    define_attr("w", &cv::DualQuat<_Tp>::w).
    define_attr("x", &cv::DualQuat<_Tp>::x).
    define_attr("y", &cv::DualQuat<_Tp>::y).
    define_attr("z", &cv::DualQuat<_Tp>::z).
    define_attr("w_", &cv::DualQuat<_Tp>::w_).
    define_attr("x_", &cv::DualQuat<_Tp>::x_).
    define_attr("y_", &cv::DualQuat<_Tp>::y_).
    define_attr("z_", &cv::DualQuat<_Tp>::z_).
    // Commented out - causes linker errors (no explicit template instantiation in OpenCV)
    // template define_singleton_function<cv::DualQuat<_Tp>(*)(const cv::Quat<_Tp>&, const cv::Quat<_Tp>&)>("create_from_quat", &cv::DualQuat<_Tp>::createFromQuat,
    //   Arg("real_part"), Arg("dual_part")).
    // template define_singleton_function<cv::DualQuat<_Tp>(*)(const _Tp, const cv::Vec<_Tp, 3>&, const cv::Vec<_Tp, 3>&)>("create_from_angle_axis_trans", &cv::DualQuat<_Tp>::createFromAngleAxisTrans,
    //   Arg("angle"), Arg("axis"), Arg("translation")).
    template define_singleton_function<cv::DualQuat<_Tp>(*)(cv::InputArray)>("create_from_mat", &cv::DualQuat<_Tp>::createFromMat,
      Arg("_r")).
    template define_singleton_function<cv::DualQuat<_Tp>(*)(const cv::Affine3<_Tp>&)>("create_from_affine3", &cv::DualQuat<_Tp>::createFromAffine3,
      Arg("r")).
    template define_singleton_function<cv::DualQuat<_Tp>(*)(const _Tp, const _Tp, const cv::Vec<_Tp, 3>&, const cv::Vec<_Tp, 3>&)>("create_from_pitch", &cv::DualQuat<_Tp>::createFromPitch,
      Arg("angle"), Arg("d"), Arg("axis"), Arg("moment")).
    template define_method<cv::Quat<_Tp>(cv::DualQuat<_Tp>::*)() const>("get_real_part", &cv::DualQuat<_Tp>::getRealPart).
    template define_method<cv::Quat<_Tp>(cv::DualQuat<_Tp>::*)() const>("get_dual_part", &cv::DualQuat<_Tp>::getDualPart).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)() const>("conjugate", &cv::DualQuat<_Tp>::conjugate).
    template define_method<cv::Quat<_Tp>(cv::DualQuat<_Tp>::*)(cv::QuatAssumeType) const>("get_rotation", &cv::DualQuat<_Tp>::getRotation,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Vec<_Tp, 3>(cv::DualQuat<_Tp>::*)(cv::QuatAssumeType) const>("get_translation", &cv::DualQuat<_Tp>::getTranslation,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)() const>("norm", &cv::DualQuat<_Tp>::norm).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)() const>("normalize", &cv::DualQuat<_Tp>::normalize).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(cv::QuatAssumeType) const>("inv", &cv::DualQuat<_Tp>::inv,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<_Tp(cv::DualQuat<_Tp>::*)(cv::DualQuat<_Tp>) const>("dot", &cv::DualQuat<_Tp>::dot,
      Arg("p")).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const _Tp, cv::QuatAssumeType) const>("power", &cv::DualQuat<_Tp>::power,
      Arg("t"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&, cv::QuatAssumeType) const>("power", &cv::DualQuat<_Tp>::power,
      Arg("q"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)() const>("exp", &cv::DualQuat<_Tp>::exp).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(cv::QuatAssumeType) const>("log", &cv::DualQuat<_Tp>::log,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Vec<_Tp, 8>(cv::DualQuat<_Tp>::*)() const>("to_vec", &cv::DualQuat<_Tp>::toVec).
    template define_method<cv::Matx<_Tp, 4, 4>(cv::DualQuat<_Tp>::*)(cv::QuatAssumeType) const>("to_mat", &cv::DualQuat<_Tp>::toMat,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Affine3<_Tp>(cv::DualQuat<_Tp>::*)(cv::QuatAssumeType) const>("to_affine3", &cv::DualQuat<_Tp>::toAffine3,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_singleton_function<cv::DualQuat<_Tp>(*)(const cv::DualQuat<_Tp>&, const cv::DualQuat<_Tp>&, const _Tp, bool, cv::QuatAssumeType)>("sclerp", &cv::DualQuat<_Tp>::sclerp,
      Arg("q1"), Arg("q2"), Arg("t"), Arg("direct_change") = static_cast<bool>(true), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_singleton_function<cv::DualQuat<_Tp>(*)(const cv::DualQuat<_Tp>&, const cv::DualQuat<_Tp>&, const _Tp, cv::QuatAssumeType)>("dqblend", &cv::DualQuat<_Tp>::dqblend,
      Arg("q1"), Arg("q2"), Arg("t"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_singleton_function<cv::DualQuat<_Tp>(*)(cv::InputArray, cv::InputArray, cv::QuatAssumeType)>("gdqblend", &cv::DualQuat<_Tp>::gdqblend,
      Arg("dualquat"), Arg("weights"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)() const>("-@", &cv::DualQuat<_Tp>::operator-).
    template define_method<bool(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&) const>("==", &cv::DualQuat<_Tp>::operator==,
      Arg("arg_0")).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&) const>("-", &cv::DualQuat<_Tp>::operator-,
      Arg("arg_0")).
    template define_method<cv::DualQuat<_Tp>&(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&)>("assign_minus", &cv::DualQuat<_Tp>::operator-=,
      Arg("arg_0")).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&) const>("+", &cv::DualQuat<_Tp>::operator+,
      Arg("arg_0")).
    template define_method<cv::DualQuat<_Tp>&(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&)>("assign_plus", &cv::DualQuat<_Tp>::operator+=,
      Arg("arg_0")).
    // Commented out - causes linker errors (no explicit template instantiation in OpenCV)
    // template define_method<cv::DualQuat<_Tp>&(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&)>("assign_multiply", &cv::DualQuat<_Tp>::operator*=,
    //   Arg("arg_0")).
    // template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const _Tp)>("assign_multiply", &cv::DualQuat<_Tp>::operator*=,
    //   Arg("s")).
    // template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&) const>("*", &cv::DualQuat<_Tp>::operator*,
    //   Arg("arg_0")).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const _Tp) const>("/", &cv::DualQuat<_Tp>::operator/,
      Arg("s")).
    template define_method<cv::DualQuat<_Tp>(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&) const>("/", &cv::DualQuat<_Tp>::operator/,
      Arg("arg_0"));  // Changed . to ; because next methods are commented out
    // Commented out - causes linker errors (no explicit template instantiation in OpenCV)
    // template define_method<cv::DualQuat<_Tp>&(cv::DualQuat<_Tp>::*)(const cv::DualQuat<_Tp>&)>("assign_divide", &cv::DualQuat<_Tp>::operator/=,
    //   Arg("arg_0")).
    // template define_method<cv::Quat<_Tp>&(cv::DualQuat<_Tp>::*)(const _Tp)>("assign_divide", &cv::DualQuat<_Tp>::operator/=,
    //   Arg("s"));
}

