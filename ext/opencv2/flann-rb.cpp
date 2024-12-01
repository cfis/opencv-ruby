#include <opencv2/flann.hpp>
#include "flann-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvFlannCvTypeChar;
Rice::Class rb_cCvFlannCvTypeDouble;
Rice::Class rb_cCvFlannCvTypeFloat;
Rice::Class rb_cCvFlannCvTypeInt;
Rice::Class rb_cCvFlannCvTypeShort;
Rice::Class rb_cCvFlannCvTypeUnsignedChar;
Rice::Class rb_cCvFlannCvTypeUnsignedShort;

template<typename Data_Type_T, typename T>
inline void CvType_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename Distance>
inline void GenericIndex_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::flann::GenericIndex<Distance>, const cv::Mat&, const cvflann::IndexParams&, Distance>(),
      Arg("features"), Arg("params"), Arg("distance") = static_cast<Distance>(Distance())).
    template define_method<void(cv::flann::GenericIndex<Distance>::*)(const std::vector<typename cv::flann::GenericIndex<Distance>::ElementType>&, std::vector<int>&, std::vector<typename cv::flann::GenericIndex<Distance>::DistanceType>&, int, const cvflann::SearchParams&)>("knn_search", &cv::flann::GenericIndex<Distance>::knnSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method<void(cv::flann::GenericIndex<Distance>::*)(const cv::Mat&, cv::Mat&, cv::Mat&, int, const cvflann::SearchParams&)>("knn_search", &cv::flann::GenericIndex<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method<int(cv::flann::GenericIndex<Distance>::*)(const std::vector<typename cv::flann::GenericIndex<Distance>::ElementType>&, std::vector<int>&, std::vector<typename cv::flann::GenericIndex<Distance>::DistanceType>&, typename cv::flann::GenericIndex<Distance>::DistanceType, const cvflann::SearchParams&)>("radius_search", &cv::flann::GenericIndex<Distance>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("params")).
    template define_method<int(cv::flann::GenericIndex<Distance>::*)(const cv::Mat&, cv::Mat&, cv::Mat&, typename cv::flann::GenericIndex<Distance>::DistanceType, const cvflann::SearchParams&)>("radius_search", &cv::flann::GenericIndex<Distance>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("params")).
    template define_method("save", &cv::flann::GenericIndex<Distance>::save,
      Arg("filename")).
    template define_method("veclen", &cv::flann::GenericIndex<Distance>::veclen).
    template define_method("size", &cv::flann::GenericIndex<Distance>::size).
    template define_method("get_parameters", &cv::flann::GenericIndex<Distance>::getParameters).
    template define_method("get_index_parameters", &cv::flann::GenericIndex<Distance>::getIndexParameters);
};

template<typename Data_Type_T, typename T>
inline void Index__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::flann::Index_<T>, const cv::Mat&, const cvflann::IndexParams&>(),
      Arg("dataset"), Arg("params")).
    template define_method<void(cv::flann::Index_<T>::*)(const std::vector<typename cv::flann::Index_<T>::ElementType>&, std::vector<int>&, std::vector<typename cv::flann::Index_<T>::DistanceType>&, int, const cvflann::SearchParams&)>("knn_search", &cv::flann::Index_<T>::knnSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("search_params")).
    template define_method<void(cv::flann::Index_<T>::*)(const cv::Mat&, cv::Mat&, cv::Mat&, int, const cvflann::SearchParams&)>("knn_search", &cv::flann::Index_<T>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("search_params")).
    template define_method<int(cv::flann::Index_<T>::*)(const std::vector<typename cv::flann::Index_<T>::ElementType>&, std::vector<int>&, std::vector<typename cv::flann::Index_<T>::DistanceType>&, typename cv::flann::Index_<T>::DistanceType, const cvflann::SearchParams&)>("radius_search", &cv::flann::Index_<T>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("search_params")).
    template define_method<int(cv::flann::Index_<T>::*)(const cv::Mat&, cv::Mat&, cv::Mat&, typename cv::flann::Index_<T>::DistanceType, const cvflann::SearchParams&)>("radius_search", &cv::flann::Index_<T>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("search_params")).
    template define_method("save", &cv::flann::Index_<T>::save,
      Arg("filename")).
    template define_method("veclen", &cv::flann::Index_<T>::veclen).
    template define_method("size", &cv::flann::Index_<T>::size).
    template define_method("get_parameters", &cv::flann::Index_<T>::getParameters).
    template define_method("get_index_parameters", &cv::flann::Index_<T>::getIndexParameters);
};

void Init_Flann()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_mCvflann.define_module_function("flann_distance_type", &cvflann::flann_distance_type);
  
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFlann = define_module_under(rb_mCv, "Flann");
  
  rb_cCvFlannCvTypeUnsignedChar = define_class_under<cv::flann::CvType<unsigned char>>(rb_mCvFlann, "CvTypeUnsignedChar").
    define_constructor(Constructor<cv::flann::CvType<unsigned char>>()).
    define_singleton_function("type", &cv::flann::CvType<unsigned char>::type);
  
  rb_cCvFlannCvTypeChar = define_class_under<cv::flann::CvType<char>>(rb_mCvFlann, "CvTypeChar").
    define_constructor(Constructor<cv::flann::CvType<char>>()).
    define_singleton_function("type", &cv::flann::CvType<char>::type);
  
  rb_cCvFlannCvTypeUnsignedShort = define_class_under<cv::flann::CvType<unsigned short>>(rb_mCvFlann, "CvTypeUnsignedShort").
    define_constructor(Constructor<cv::flann::CvType<unsigned short>>()).
    define_singleton_function("type", &cv::flann::CvType<unsigned short>::type);
  
  rb_cCvFlannCvTypeShort = define_class_under<cv::flann::CvType<short>>(rb_mCvFlann, "CvTypeShort").
    define_constructor(Constructor<cv::flann::CvType<short>>()).
    define_singleton_function("type", &cv::flann::CvType<short>::type);
  
  rb_cCvFlannCvTypeInt = define_class_under<cv::flann::CvType<int>>(rb_mCvFlann, "CvTypeInt").
    define_constructor(Constructor<cv::flann::CvType<int>>()).
    define_singleton_function("type", &cv::flann::CvType<int>::type);
  
  rb_cCvFlannCvTypeFloat = define_class_under<cv::flann::CvType<float>>(rb_mCvFlann, "CvTypeFloat").
    define_constructor(Constructor<cv::flann::CvType<float>>()).
    define_singleton_function("type", &cv::flann::CvType<float>::type);
  
  rb_cCvFlannCvTypeDouble = define_class_under<cv::flann::CvType<double>>(rb_mCvFlann, "CvTypeDouble").
    define_constructor(Constructor<cv::flann::CvType<double>>()).
    define_singleton_function("type", &cv::flann::CvType<double>::type);

}