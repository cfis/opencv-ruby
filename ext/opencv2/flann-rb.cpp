#include <opencv2/flann.hpp>
#include "flann-rb.hpp"

using namespace Rice;

#include "flann-rb.ipp"

void Init_Flann()
{
  Module rb_mCvflann = define_module("Cvflann");

  rb_mCvflann.define_module_function<cvflann::flann_distance_t(*)()>("flann_distance_type", &cvflann::flann_distance_type);

  Module rb_mCv = define_module("Cv");

  Module rb_mCvFlann = define_module_under(rb_mCv, "Flann");

  Rice::Data_Type<cv::flann::CvType<unsigned char>> rb_cCvFlannCvTypeUnsignedChar = define_class_under<cv::flann::CvType<unsigned char>>(rb_mCvFlann, "CvTypeUnsignedChar").
    define_constructor(Constructor<cv::flann::CvType<unsigned char>>()).
    define_singleton_function<int(*)()>("type", &cv::flann::CvType<unsigned char>::type);

  Rice::Data_Type<cv::flann::CvType<char>> rb_cCvFlannCvTypeChar = define_class_under<cv::flann::CvType<char>>(rb_mCvFlann, "CvTypeChar").
    define_constructor(Constructor<cv::flann::CvType<char>>()).
    define_singleton_function<int(*)()>("type", &cv::flann::CvType<char>::type);

  Rice::Data_Type<cv::flann::CvType<unsigned short>> rb_cCvFlannCvTypeUnsignedShort = define_class_under<cv::flann::CvType<unsigned short>>(rb_mCvFlann, "CvTypeUnsignedShort").
    define_constructor(Constructor<cv::flann::CvType<unsigned short>>()).
    define_singleton_function<int(*)()>("type", &cv::flann::CvType<unsigned short>::type);

  Rice::Data_Type<cv::flann::CvType<short>> rb_cCvFlannCvTypeShort = define_class_under<cv::flann::CvType<short>>(rb_mCvFlann, "CvTypeShort").
    define_constructor(Constructor<cv::flann::CvType<short>>()).
    define_singleton_function<int(*)()>("type", &cv::flann::CvType<short>::type);

  Rice::Data_Type<cv::flann::CvType<int>> rb_cCvFlannCvTypeInt = define_class_under<cv::flann::CvType<int>>(rb_mCvFlann, "CvTypeInt").
    define_constructor(Constructor<cv::flann::CvType<int>>()).
    define_singleton_function<int(*)()>("type", &cv::flann::CvType<int>::type);

  Rice::Data_Type<cv::flann::CvType<float>> rb_cCvFlannCvTypeFloat = define_class_under<cv::flann::CvType<float>>(rb_mCvFlann, "CvTypeFloat").
    define_constructor(Constructor<cv::flann::CvType<float>>()).
    define_singleton_function<int(*)()>("type", &cv::flann::CvType<float>::type);

  Rice::Data_Type<cv::flann::CvType<double>> rb_cCvFlannCvTypeDouble = define_class_under<cv::flann::CvType<double>>(rb_mCvFlann, "CvTypeDouble").
    define_constructor(Constructor<cv::flann::CvType<double>>()).
    define_singleton_function<int(*)()>("type", &cv::flann::CvType<double>::type);
}