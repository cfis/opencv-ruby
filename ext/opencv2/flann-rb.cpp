#include <opencv2/flann.hpp>
#include "flann-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Distance>
inline void GenericIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::flann::GenericIndex<Distance>, const cv::Mat&, const cvflann::IndexParams&, Distance>(),
      Arg("features"), Arg("params"), Arg("distance") = static_cast<Distance>(cv::flann::GenericIndex::Distance())).
    template define_method<void(cv::flann::GenericIndex<Distance>::*)(const vector<type-parameter-0-0::ElementType, allocator<type-parameter-0-0::ElementType>>&, std::vector<int>&, vector<type-parameter-0-0::ResultType, allocator<type-parameter-0-0::ResultType>>&, int, const cvflann::SearchParams&)>("knn_search", &cv::flann::GenericIndex<Distance>::knnSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method<void(cv::flann::GenericIndex<Distance>::*)(const cv::Mat&, cv::Mat&, cv::Mat&, int, const cvflann::SearchParams&)>("knn_search", &cv::flann::GenericIndex<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method<int(cv::flann::GenericIndex<Distance>::*)(const vector<type-parameter-0-0::ElementType, allocator<type-parameter-0-0::ElementType>>&, std::vector<int>&, vector<type-parameter-0-0::ResultType, allocator<type-parameter-0-0::ResultType>>&, typename cv::flann::GenericIndex<Distance>::DistanceType, const cvflann::SearchParams&)>("radius_search", &cv::flann::GenericIndex<Distance>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("params")).
    template define_method<int(cv::flann::GenericIndex<Distance>::*)(const cv::Mat&, cv::Mat&, cv::Mat&, typename cv::flann::GenericIndex<Distance>::DistanceType, const cvflann::SearchParams&)>("radius_search", &cv::flann::GenericIndex<Distance>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("params")).
    define_method("save", &cv::flann::GenericIndex<Distance>::save,
      Arg("filename")).
    define_method("veclen", &cv::flann::GenericIndex<Distance>::veclen).
    define_method("size", &cv::flann::GenericIndex<Distance>::size).
    define_method("get_parameters", &cv::flann::GenericIndex<Distance>::getParameters);
};

void Init_Flann()
{
  Module rb_mCvflann = define_module("Cvflann");

  rb_mCvflann.define_module_function("flann_distance_type", &cvflann::flann_distance_type);

  Module rb_mCv = define_module("Cv");

  Module rb_mCvFlann = define_module_under(rb_mCv, "Flann");

  Rice::Data_Type<cv::flann::CvType<unsigned char>> rb_cCvFlannCvTypeUnsignedChar = define_class_under<cv::flann::CvType<unsigned char>>(rb_mCvFlann, "CvTypeUnsignedChar").
    define_constructor(Constructor<cv::flann::CvType<unsigned char>>()).
    define_singleton_function("type", &cv::flann::CvType<unsigned char>::type);

  Rice::Data_Type<cv::flann::CvType<char>> rb_cCvFlannCvTypeChar = define_class_under<cv::flann::CvType<char>>(rb_mCvFlann, "CvTypeChar").
    define_constructor(Constructor<cv::flann::CvType<char>>()).
    define_singleton_function("type", &cv::flann::CvType<char>::type);

  Rice::Data_Type<cv::flann::CvType<unsigned short>> rb_cCvFlannCvTypeUnsignedShort = define_class_under<cv::flann::CvType<unsigned short>>(rb_mCvFlann, "CvTypeUnsignedShort").
    define_constructor(Constructor<cv::flann::CvType<unsigned short>>()).
    define_singleton_function("type", &cv::flann::CvType<unsigned short>::type);

  Rice::Data_Type<cv::flann::CvType<short>> rb_cCvFlannCvTypeShort = define_class_under<cv::flann::CvType<short>>(rb_mCvFlann, "CvTypeShort").
    define_constructor(Constructor<cv::flann::CvType<short>>()).
    define_singleton_function("type", &cv::flann::CvType<short>::type);

  Rice::Data_Type<cv::flann::CvType<int>> rb_cCvFlannCvTypeInt = define_class_under<cv::flann::CvType<int>>(rb_mCvFlann, "CvTypeInt").
    define_constructor(Constructor<cv::flann::CvType<int>>()).
    define_singleton_function("type", &cv::flann::CvType<int>::type);

  Rice::Data_Type<cv::flann::CvType<float>> rb_cCvFlannCvTypeFloat = define_class_under<cv::flann::CvType<float>>(rb_mCvFlann, "CvTypeFloat").
    define_constructor(Constructor<cv::flann::CvType<float>>()).
    define_singleton_function("type", &cv::flann::CvType<float>::type);

  Rice::Data_Type<cv::flann::CvType<double>> rb_cCvFlannCvTypeDouble = define_class_under<cv::flann::CvType<double>>(rb_mCvFlann, "CvTypeDouble").
    define_constructor(Constructor<cv::flann::CvType<double>>()).
    define_singleton_function("type", &cv::flann::CvType<double>::type);
}