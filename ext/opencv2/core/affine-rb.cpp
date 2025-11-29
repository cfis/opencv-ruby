#include <opencv2/core/affine.hpp>
#include "affine-rb.hpp"

using namespace Rice;

Rice::Class rb_cAffine3d;
Rice::Class rb_cAffine3f;

template<typename Data_Type_T, typename T>
inline void Affine3_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Affine3<T>>()).
    define_constructor(Constructor<cv::Affine3<T>, const typename cv::Affine3<T>::Mat4&>(),
      Arg("affine")).
    define_constructor(Constructor<cv::Affine3<T>, const typename cv::Affine3<T>::Mat3&, const typename cv::Affine3<T>::Vec3&>(),
      Arg("r"), Arg("t") = static_cast<const typename cv::Affine3<T>::Vec3 &>(cv::Affine3<T>::Vec3::all(0))).
    define_constructor(Constructor<cv::Affine3<T>, const typename cv::Affine3<T>::Vec3&, const typename cv::Affine3<T>::Vec3&>(),
      Arg("rvec"), Arg("t") = static_cast<const typename cv::Affine3<T>::Vec3 &>(cv::Affine3<T>::Vec3::all(0))).
    define_constructor(Constructor<cv::Affine3<T>, const cv::Mat&, const typename cv::Affine3<T>::Vec3&>(),
      Arg("data"), Arg("t") = static_cast<const typename cv::Affine3<T>::Vec3 &>(cv::Affine3<T>::Vec3::all(0))).
    define_constructor(Constructor<cv::Affine3<T>, const typename cv::Affine3<T>::float_type*>(),
      Arg("vals")).
    define_singleton_function("identity", &cv::Affine3<T>::Identity).
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
    define_method("rvec", &cv::Affine3<T>::rvec).
    define_method("inv", &cv::Affine3<T>::inv,
      Arg("method") = static_cast<int>(cv::DECOMP_SVD)).
    template define_method<cv::Affine3<T>(cv::Affine3<T>::*)(const typename cv::Affine3<T>::Mat3&) const>("rotate", &cv::Affine3<T>::rotate,
      Arg("r")).
    template define_method<cv::Affine3<T>(cv::Affine3<T>::*)(const typename cv::Affine3<T>::Vec3&) const>("rotate", &cv::Affine3<T>::rotate,
      Arg("rvec")).
    define_method("translate", &cv::Affine3<T>::translate,
      Arg("t")).
    define_method("concatenate", &cv::Affine3<T>::concatenate,
      Arg("affine")).
    define_attr("matrix", &cv::Affine3<T>::matrix);
};
void Init_Affine()
{
  Module rb_mCv = define_module("Cv");
  
  rb_cAffine3f = define_class_under<cv::Affine3<float>>(rb_mCv, "Affine3f").
    define(&Affine3_builder<Data_Type<cv::Affine3<float>>, float>);
  
  rb_cAffine3d = define_class_under<cv::Affine3<double>>(rb_mCv, "Affine3d").
    define(&Affine3_builder<Data_Type<cv::Affine3<double>>, double>);
  
  rb_cAffine3f.define_method("*", [](const cv::Affine3f& self, const cv::Vec3f& other) -> cv::Vec3f
  {
    return self * other;
  });
  
  rb_cAffine3d.define_method("*", [](const cv::Affine3d& self, const cv::Vec3d& other) -> cv::Vec3d
  {
    return self * other;
  });
  
  Module rb_mCvTraits = define_module_under(rb_mCv, "Traits");
  
  
  rb_cAffine3f.define_method("*", [](const cv::Affine3f& self, const cv::Vec3f& other) -> cv::Vec3f
  {
    return self * other;
  });
  
  rb_cAffine3d.define_method("*", [](const cv::Affine3d& self, const cv::Vec3d& other) -> cv::Vec3d
  {
    return self * other;
  });

}