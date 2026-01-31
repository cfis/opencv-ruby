#include <opencv2/face/facemark_train.hpp>
#include "facemark_train-rb.hpp"

using namespace Rice;

void Init_Face_FacemarkTrain()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFace = define_module_under(rb_mCv, "Face");

  Rice::Data_Type<cv::face::CParams> rb_cCvFaceCParams = define_class_under<cv::face::CParams>(rb_mCvFace, "CParams").
    define_attr("cascade", &cv::face::CParams::cascade).
    define_attr("scale_factor", &cv::face::CParams::scaleFactor).
    define_attr("min_neighbors", &cv::face::CParams::minNeighbors).
    define_attr("min_size", &cv::face::CParams::minSize).
    define_attr("max_size", &cv::face::CParams::maxSize).
    define_constructor(Constructor<cv::face::CParams, cv::String, double, int, cv::Size, cv::Size>(),
      Arg("cascade_model"), Arg("sf") = static_cast<double>(1.1), Arg("min_n") = static_cast<int>(3), Arg("min_sz") = static_cast<cv::Size>(cv::Size(30, 30)), Arg("max_sz") = static_cast<cv::Size>(cv::Size())).
    define_attr("face_cascade", &cv::face::CParams::face_cascade);

  rb_mCvFace.define_module_function<bool(*)(cv::InputArray, cv::OutputArray, cv::face::CParams*)>("get_faces", &cv::face::getFaces,
    Arg("image"), Arg("faces"), Arg("params"));

  rb_mCvFace.define_module_function<bool(*)(cv::InputArray, cv::OutputArray, const cv::String&)>("get_faces_haar", &cv::face::getFacesHAAR,
    Arg("image"), Arg("faces"), Arg("face_cascade_name"));

  rb_mCvFace.define_module_function<bool(*)(cv::String, cv::String, std::vector<std::basic_string<char>>&, std::vector<std::basic_string<char>>&)>("load_dataset_list", &cv::face::loadDatasetList,
    Arg("image_list"), Arg("annotation_list"), Arg("images"), Arg("annotations"));

  rb_mCvFace.define_module_function<bool(*)(cv::String, std::vector<std::basic_string<char>>&, cv::OutputArray, char, float)>("load_training_data", &cv::face::loadTrainingData,
    Arg("filename"), Arg("images"), Arg("face_points"), Arg("delim") = static_cast<char>(' '), Arg("offset") = static_cast<float>(0.0f));

  rb_mCvFace.define_module_function<bool(*)(cv::String, cv::String, std::vector<std::basic_string<char>>&, cv::OutputArray, float)>("load_training_data", &cv::face::loadTrainingData,
    Arg("image_list"), Arg("ground_truth"), Arg("images"), Arg("face_points"), Arg("offset") = static_cast<float>(0.0f));

  rb_mCvFace.define_module_function<bool(*)(std::vector<std::basic_string<char>>, std::vector<std::vector<cv::Point_<float>>>&, std::vector<std::basic_string<char>>&)>("load_training_data", &cv::face::loadTrainingData,
    Arg("filename"), Arg("trainlandmarks"), Arg("trainimages"));

  rb_mCvFace.define_module_function<bool(*)(cv::String, cv::OutputArray, float)>("load_face_points", &cv::face::loadFacePoints,
    Arg("filename"), Arg("points"), Arg("offset") = static_cast<float>(0.0f));

  rb_mCvFace.define_module_function<void(*)(cv::InputOutputArray, cv::InputArray, cv::Scalar)>("draw_facemarks", &cv::face::drawFacemarks,
    Arg("image"), Arg("points"), Arg("color") = static_cast<cv::Scalar>(cv::Scalar(255,0,0)));

  Rice::Data_Type<cv::face::FacemarkTrain> rb_cCvFaceFacemarkTrain = define_class_under<cv::face::FacemarkTrain, cv::face::Facemark>(rb_mCvFace, "FacemarkTrain").
    define_method<bool(cv::face::FacemarkTrain::*)(cv::InputArray, cv::InputArray)>("add_training_sample", &cv::face::FacemarkTrain::addTrainingSample,
      Arg("image"), Arg("landmarks")).
    define_method<void(cv::face::FacemarkTrain::*)(void*)>("training", &cv::face::FacemarkTrain::training,
      ArgBuffer("parameters") = static_cast<void*>(0)).
    define_method<bool(cv::face::FacemarkTrain::*)(cv::face::FN_FaceDetector, void*)>("set_face_detector", &cv::face::FacemarkTrain::setFaceDetector,
      Arg("detector"), ArgBuffer("user_data") = static_cast<void*>(0)).
    define_method<bool(cv::face::FacemarkTrain::*)(cv::InputArray, cv::OutputArray)>("get_faces", &cv::face::FacemarkTrain::getFaces,
      Arg("image"), Arg("faces")).
    define_method<bool(cv::face::FacemarkTrain::*)(void*)>("get_data", &cv::face::FacemarkTrain::getData,
      ArgBuffer("items") = static_cast<void*>(0));
}