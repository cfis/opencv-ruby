template<typename _Tp>
inline Rice::Data_Type<cv::Quat<_Tp>> Quat_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::Quat<_Tp>>(parent, name).
    define_constant("CV_QUAT_EPS", cv::Quat<_Tp>::CV_QUAT_EPS).
    define_constant("CV_QUAT_CONVERT_THRESHOLD", cv::Quat<_Tp>::CV_QUAT_CONVERT_THRESHOLD).
    define_constructor(Constructor<cv::Quat<_Tp>>()).
    define_constructor(Constructor<cv::Quat<_Tp>, const cv::Vec<_Tp, 4>&>(),
      Arg("coeff")).
    define_constructor(Constructor<cv::Quat<_Tp>, _Tp, _Tp, _Tp, _Tp>(),
      Arg("w"), Arg("x"), Arg("y"), Arg("z")).
    template define_singleton_function<cv::Quat<_Tp>(*)(const _Tp, const cv::Vec<_Tp, 3>&)>("create_from_angle_axis", &cv::Quat<_Tp>::createFromAngleAxis,
      Arg("angle"), Arg("axis")).
    template define_singleton_function<cv::Quat<_Tp>(*)(cv::InputArray)>("create_from_rot_mat", &cv::Quat<_Tp>::createFromRotMat,
      Arg("r")).
    template define_singleton_function<cv::Quat<_Tp>(*)(cv::InputArray)>("create_from_rvec", &cv::Quat<_Tp>::createFromRvec,
      Arg("rvec")).
    template define_singleton_function<cv::Quat<_Tp>(*)(const cv::Vec<_Tp, 3>&, cv::QuatEnum::EulerAnglesType)>("create_from_euler_angles", &cv::Quat<_Tp>::createFromEulerAngles,
      Arg("angles"), Arg("euler_angles_type")).
    template define_singleton_function<cv::Quat<_Tp>(*)(const _Tp)>("create_from_y_rot", &cv::Quat<_Tp>::createFromYRot,
      Arg("theta")).
    template define_singleton_function<cv::Quat<_Tp>(*)(const _Tp)>("create_from_x_rot", &cv::Quat<_Tp>::createFromXRot,
      Arg("theta")).
    template define_singleton_function<cv::Quat<_Tp>(*)(const _Tp)>("create_from_z_rot", &cv::Quat<_Tp>::createFromZRot,
      Arg("theta")).
    template define_method<_Tp(cv::Quat<_Tp>::*)(size_t) const>("at", &cv::Quat<_Tp>::at,
      Arg("index")).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)() const>("conjugate", &cv::Quat<_Tp>::conjugate).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)() const>("exp", &cv::Quat<_Tp>::exp).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(cv::QuatAssumeType) const>("log", &cv::Quat<_Tp>::log,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const _Tp, cv::QuatAssumeType) const>("power", &cv::Quat<_Tp>::power,
      Arg("x"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(cv::QuatAssumeType) const>("sqrt", &cv::Quat<_Tp>::sqrt,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&, cv::QuatAssumeType) const>("power", &cv::Quat<_Tp>::power,
      Arg("q"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&) const>("cross_product", &cv::Quat<_Tp>::crossProduct,
      Arg("q")).
    template define_method<_Tp(cv::Quat<_Tp>::*)() const>("norm", &cv::Quat<_Tp>::norm).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)() const>("normalize", &cv::Quat<_Tp>::normalize).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(cv::QuatAssumeType) const>("inv", &cv::Quat<_Tp>::inv,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)() const>("sinh", &cv::Quat<_Tp>::sinh).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)() const>("cosh", &cv::Quat<_Tp>::cosh).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)() const>("tanh", &cv::Quat<_Tp>::tanh).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)() const>("sin", &cv::Quat<_Tp>::sin).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)() const>("cos", &cv::Quat<_Tp>::cos).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)() const>("tan", &cv::Quat<_Tp>::tan).
    template define_method<bool(cv::Quat<_Tp>::*)(_Tp) const>("normal?", &cv::Quat<_Tp>::isNormal,
      Arg("eps") = static_cast<_Tp>(cv::Quat<_Tp>::CV_QUAT_EPS)).
    template define_method<void(cv::Quat<_Tp>::*)(_Tp) const>("assert_normal", &cv::Quat<_Tp>::assertNormal,
      Arg("eps") = static_cast<_Tp>(cv::Quat<_Tp>::CV_QUAT_EPS)).
    template define_method<cv::Matx<_Tp, 3, 3>(cv::Quat<_Tp>::*)(cv::QuatAssumeType) const>("to_rot_mat3x3", &cv::Quat<_Tp>::toRotMat3x3,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Matx<_Tp, 4, 4>(cv::Quat<_Tp>::*)(cv::QuatAssumeType) const>("to_rot_mat4x4", &cv::Quat<_Tp>::toRotMat4x4,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Vec<_Tp, 4>(cv::Quat<_Tp>::*)() const>("to_vec", &cv::Quat<_Tp>::toVec).
    template define_method<cv::Vec<_Tp, 3>(cv::Quat<_Tp>::*)(cv::QuatAssumeType) const>("to_rot_vec", &cv::Quat<_Tp>::toRotVec,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<_Tp(cv::Quat<_Tp>::*)(cv::QuatAssumeType) const>("get_angle", &cv::Quat<_Tp>::getAngle,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Vec<_Tp, 3>(cv::Quat<_Tp>::*)(cv::QuatAssumeType) const>("get_axis", &cv::Quat<_Tp>::getAxis,
      Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<_Tp(cv::Quat<_Tp>::*)(cv::Quat<_Tp>) const>("dot", &cv::Quat<_Tp>::dot,
      Arg("q")).
    template define_singleton_function<cv::Quat<_Tp>(*)(const cv::Quat<_Tp>&, const cv::Quat<_Tp>&, const _Tp)>("lerp", &cv::Quat<_Tp>::lerp,
      Arg("q0"), Arg("q1"), Arg("t")).
    template define_singleton_function<cv::Quat<_Tp>(*)(const cv::Quat<_Tp>&, const cv::Quat<_Tp>&, const _Tp, cv::QuatAssumeType)>("nlerp", &cv::Quat<_Tp>::nlerp,
      Arg("q0"), Arg("q1"), Arg("t"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_singleton_function<cv::Quat<_Tp>(*)(const cv::Quat<_Tp>&, const cv::Quat<_Tp>&, const _Tp, cv::QuatAssumeType, bool)>("slerp", &cv::Quat<_Tp>::slerp,
      Arg("q0"), Arg("q1"), Arg("t"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT), Arg("direct_change") = static_cast<bool>(true)).
    template define_singleton_function<cv::Quat<_Tp>(*)(const cv::Quat<_Tp>&, const cv::Quat<_Tp>&, const cv::Quat<_Tp>&, const cv::Quat<_Tp>&, const _Tp, cv::QuatAssumeType, bool)>("squad", &cv::Quat<_Tp>::squad,
      Arg("q0"), Arg("s0"), Arg("s1"), Arg("q1"), Arg("t"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT), Arg("direct_change") = static_cast<bool>(true)).
    template define_singleton_function<cv::Quat<_Tp>(*)(const cv::Quat<_Tp>&, const cv::Quat<_Tp>&, const cv::Quat<_Tp>&, cv::QuatAssumeType)>("inter_point", &cv::Quat<_Tp>::interPoint,
      Arg("q0"), Arg("q1"), Arg("q2"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_singleton_function<cv::Quat<_Tp>(*)(const cv::Quat<_Tp>&, const cv::Quat<_Tp>&, const cv::Quat<_Tp>&, const cv::Quat<_Tp>&, const _Tp, cv::QuatAssumeType)>("spline", &cv::Quat<_Tp>::spline,
      Arg("q0"), Arg("q1"), Arg("q2"), Arg("q3"), Arg("t"), Arg("assume_unit") = static_cast<cv::QuatAssumeType>(cv::QUAT_ASSUME_NOT_UNIT)).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)() const>("-@", &cv::Quat<_Tp>::operator-).
    template define_method<bool(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&) const>("==", &cv::Quat<_Tp>::operator==,
      Arg("arg_0")).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&) const>("+", &cv::Quat<_Tp>::operator+,
      Arg("arg_0")).
    template define_method<cv::Quat<_Tp>&(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&)>("assign_plus", &cv::Quat<_Tp>::operator+=,
      Arg("arg_0")).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&) const>("-", &cv::Quat<_Tp>::operator-,
      Arg("arg_0")).
    template define_method<cv::Quat<_Tp>&(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&)>("assign_minus", &cv::Quat<_Tp>::operator-=,
      Arg("arg_0")).
    template define_method<cv::Quat<_Tp>&(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&)>("assign_multiply", &cv::Quat<_Tp>::operator*=,
      Arg("arg_0")).
    template define_method<cv::Quat<_Tp>&(cv::Quat<_Tp>::*)(const _Tp)>("assign_multiply", &cv::Quat<_Tp>::operator*=,
      Arg("s")).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&) const>("*", &cv::Quat<_Tp>::operator*,
      Arg("arg_0")).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const _Tp) const>("/", &cv::Quat<_Tp>::operator/,
      Arg("s")).
    template define_method<cv::Quat<_Tp>(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&) const>("/", &cv::Quat<_Tp>::operator/,
      Arg("arg_0")).
    template define_method<cv::Quat<_Tp>&(cv::Quat<_Tp>::*)(const _Tp)>("assign_divide", &cv::Quat<_Tp>::operator/=,
      Arg("s")).
    template define_method<cv::Quat<_Tp>&(cv::Quat<_Tp>::*)(const cv::Quat<_Tp>&)>("assign_divide", &cv::Quat<_Tp>::operator/=,
      Arg("arg_0")).
    template define_method<_Tp&(cv::Quat<_Tp>::*)(std::size_t)>("[]", &cv::Quat<_Tp>::operator[],
      Arg("n")).
    define_method("[]=", [](cv::Quat<_Tp>&self, int index, _Tp & value)
    {
        self[index] = value;
    }).
    template define_method<const _Tp&(cv::Quat<_Tp>::*)(std::size_t) const>("[]", &cv::Quat<_Tp>::operator[],
      Arg("n")).
    template define_method<cv::Vec<_Tp, 3>(cv::Quat<_Tp>::*)(cv::QuatEnum::EulerAnglesType)>("to_euler_angles", &cv::Quat<_Tp>::toEulerAngles,
      Arg("euler_angles_type")).
    define_attr("w", &cv::Quat<_Tp>::w).
    define_attr("x", &cv::Quat<_Tp>::x).
    define_attr("y", &cv::Quat<_Tp>::y).
    define_attr("z", &cv::Quat<_Tp>::z);
}

