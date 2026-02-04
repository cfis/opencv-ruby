#include <opencv2/core/affine.hpp>
#include "affine-rb.hpp"

using namespace Rice;

#include "affine-rb.ipp"

void Init_Core_Affine()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::Affine3<float>> rb_cAffine3f = Affine3_instantiate<float>(rb_mCv, "Affine3f");

  Rice::Data_Type<cv::Affine3<double>> rb_cAffine3d = Affine3_instantiate<double>(rb_mCv, "Affine3d");

  Module rb_mCvTraits = define_module_under(rb_mCv, "Traits");

  rb_cAffine3f.
    define_method("*", [](const cv::Affine3f& self, const cv::Vec3f& other) -> cv::Vec3f
    {
      return self * other;
    }).
    define_method("*", [](const cv::Affine3f& self, const cv::Vec3f& other) -> cv::Vec3f
    {
      return self * other;
    });
  
  rb_cAffine3d.
    define_method("*", [](const cv::Affine3d& self, const cv::Vec3d& other) -> cv::Vec3d
    {
      return self * other;
    }).
    define_method("*", [](const cv::Affine3d& self, const cv::Vec3d& other) -> cv::Vec3d
    {
      return self * other;
    });
}