template<typename T>
inline Rice::Data_Type<cv::Affine3<T>> Affine3_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::Affine3<T>>(parent, name).
    define_constructor(Constructor<cv::Affine3<T>>()).
    define_constructor(Constructor<cv::Affine3<T>, const typename cv::Affine3<T>::Mat4&>(),
      Arg("affine")).
    define_constructor(Constructor<cv::Affine3<T>, const typename cv::Affine3<T>::Mat3&, const typename cv::Affine3<T>::Vec3&>(),
      Arg("r"), Arg("t") = static_cast<const typename cv::Affine3<T>::Vec3&>(cv::Affine3<T>::Vec3::all(0))).
    define_constructor(Constructor<cv::Affine3<T>, const typename cv::Affine3<T>::Vec3&, const typename cv::Affine3<T>::Vec3&>(),
      Arg("rvec"), Arg("t") = static_cast<const typename cv::Affine3<T>::Vec3&>(cv::Affine3<T>::Vec3::all(0))).
    define_constructor(Constructor<cv::Affine3<T>, const cv::Mat&, const typename cv::Affine3<T>::Vec3&>(),
      Arg("data"), Arg("t") = static_cast<const typename cv::Affine3<T>::Vec3&>(cv::Affine3<T>::Vec3::all(0))).
    define_constructor(Constructor<cv::Affine3<T>, const typename cv::Affine3<T>::float_type*>(),
      Arg("vals")).
    template define_singleton_function<cv::Affine3<T>(*)()>("identity", &cv::Affine3<T>::Identity).
    template define_method<void(cv::Affine3<T>::*)(const typename cv::Affine3<T>::Mat3&)>("rotation", &cv::Affine3<T>::rotation,
      Arg("r")).
    template define_method<void(cv::Affine3<T>::*)(const typename cv::Affine3<T>::Vec3&)>("rotation", &cv::Affine3<T>::rotation,
      Arg("rvec")).
    template define_method<void(cv::Affine3<T>::*)(const cv::Mat&)>("rotation", &cv::Affine3<T>::rotation,
      Arg("data")).
    template define_method<void(cv::Affine3<T>::*)(const typename cv::Affine3<T>::Mat3&)>("linear", &cv::Affine3<T>::linear,
      Arg("l")).
    template define_method<void(cv::Affine3<T>::*)(const typename cv::Affine3<T>::Vec3&)>("translation", &cv::Affine3<T>::translation,
      Arg("t")).
    template define_method<typename cv::Affine3<T>::Mat3(cv::Affine3<T>::*)() const>("rotation", &cv::Affine3<T>::rotation).
    template define_method<typename cv::Affine3<T>::Mat3(cv::Affine3<T>::*)() const>("linear", &cv::Affine3<T>::linear).
    template define_method<typename cv::Affine3<T>::Vec3(cv::Affine3<T>::*)() const>("translation", &cv::Affine3<T>::translation).
    template define_method<typename cv::Affine3<T>::Vec3(cv::Affine3<T>::*)() const>("rvec", &cv::Affine3<T>::rvec).
    template define_method<cv::Affine3<T>(cv::Affine3<T>::*)(int) const>("inv", &cv::Affine3<T>::inv,
      Arg("method") = static_cast<int>(cv::DECOMP_SVD)).
    template define_method<cv::Affine3<T>(cv::Affine3<T>::*)(const typename cv::Affine3<T>::Mat3&) const>("rotate", &cv::Affine3<T>::rotate,
      Arg("r")).
    template define_method<cv::Affine3<T>(cv::Affine3<T>::*)(const typename cv::Affine3<T>::Vec3&) const>("rotate", &cv::Affine3<T>::rotate,
      Arg("rvec")).
    template define_method<cv::Affine3<T>(cv::Affine3<T>::*)(const typename cv::Affine3<T>::Vec3&) const>("translate", &cv::Affine3<T>::translate,
      Arg("t")).
    template define_method<cv::Affine3<T>(cv::Affine3<T>::*)(const cv::Affine3<T>&) const>("concatenate", &cv::Affine3<T>::concatenate,
      Arg("affine")).
    define_attr("matrix", &cv::Affine3<T>::matrix);
}

