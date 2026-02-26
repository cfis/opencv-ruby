#include <opencv2/stereo/descriptor.hpp>
#include "descriptor-rb.hpp"

using namespace Rice;

void Init_Stereo_Descriptor()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvStereo = define_module_under(rb_mCv, "Stereo");

  rb_mCvStereo.define_constant("CV_DENSE_CENSUS", (int)cv::stereo::CV_DENSE_CENSUS);
  rb_mCvStereo.define_constant("CV_SPARSE_CENSUS", (int)cv::stereo::CV_SPARSE_CENSUS);
  rb_mCvStereo.define_constant("CV_CS_CENSUS", (int)cv::stereo::CV_CS_CENSUS);
  rb_mCvStereo.define_constant("CV_MODIFIED_CS_CENSUS", (int)cv::stereo::CV_MODIFIED_CS_CENSUS);
  rb_mCvStereo.define_constant("CV_MODIFIED_CENSUS_TRANSFORM", (int)cv::stereo::CV_MODIFIED_CENSUS_TRANSFORM);
  rb_mCvStereo.define_constant("CV_MEAN_VARIATION", (int)cv::stereo::CV_MEAN_VARIATION);
  rb_mCvStereo.define_constant("CV_STAR_KERNEL", (int)cv::stereo::CV_STAR_KERNEL);

  rb_mCvStereo.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, int, cv::Mat&, cv::Mat&, const int)>("census_transform", &cv::stereo::censusTransform,
    Arg("image1"), Arg("image2"), Arg("kernel_size"), Arg("dist1"), Arg("dist2"), Arg("type"));

  rb_mCvStereo.define_module_function<void(*)(const cv::Mat&, int, cv::Mat&, const int)>("census_transform", &cv::stereo::censusTransform,
    Arg("image1"), Arg("kernel_size"), Arg("dist1"), Arg("type"));

  rb_mCvStereo.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, int, cv::Mat&, cv::Mat&, const int, int, const cv::Mat&, const cv::Mat&)>("modified_census_transform", &cv::stereo::modifiedCensusTransform,
    Arg("img1"), Arg("img2"), Arg("kernel_size"), Arg("dist1"), Arg("dist2"), Arg("type"), Arg("t") = static_cast<int>(0), Arg("integral_image1") = static_cast<const cv::Mat&>(cv::Mat()), Arg("integral_image2") = static_cast<const cv::Mat&>(cv::Mat()));

  rb_mCvStereo.define_module_function<void(*)(const cv::Mat&, int, cv::Mat&, const int, int, const cv::Mat&)>("modified_census_transform", &cv::stereo::modifiedCensusTransform,
    Arg("img1"), Arg("kernel_size"), Arg("dist"), Arg("type"), Arg("t") = static_cast<int>(0), Arg("integral_image") = static_cast<const cv::Mat&>(cv::Mat()));

  rb_mCvStereo.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, int, cv::Mat&, cv::Mat&, const int)>("symetric_census_transform", &cv::stereo::symetricCensusTransform,
    Arg("img1"), Arg("img2"), Arg("kernel_size"), Arg("dist1"), Arg("dist2"), Arg("type"));

  rb_mCvStereo.define_module_function<void(*)(const cv::Mat&, int, cv::Mat&, const int)>("symetric_census_transform", &cv::stereo::symetricCensusTransform,
    Arg("img1"), Arg("kernel_size"), Arg("dist1"), Arg("type"));

  rb_mCvStereo.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, int, cv::Mat&, cv::Mat&)>("star_census_transform", &cv::stereo::starCensusTransform,
    Arg("img1"), Arg("img2"), Arg("kernel_size"), Arg("dist1"), Arg("dist2"));

  rb_mCvStereo.define_module_function<void(*)(const cv::Mat&, int, cv::Mat&)>("star_census_transform", &cv::stereo::starCensusTransform,
    Arg("img1"), Arg("kernel_size"), Arg("dist"));
}
