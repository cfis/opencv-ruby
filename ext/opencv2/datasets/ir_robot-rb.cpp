#include <opencv2/datasets/ir_robot.hpp>
#include "ir_robot-rb.hpp"

using namespace Rice;

void Init_Datasets_IrRobot()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::cameraPos> rb_cCvDatasetsCameraPos = define_class_under<cv::datasets::cameraPos>(rb_mCvDatasets, "CameraPos").
    define_constructor(Constructor<cv::datasets::cameraPos>()).
    define_attr("images", &cv::datasets::cameraPos::images);

  Rice::Data_Type<cv::datasets::IR_robotObj> rb_cCvDatasetsIRRobotObj = define_class_under<cv::datasets::IR_robotObj, cv::datasets::Object>(rb_mCvDatasets, "IRRobotObj").
    define_constructor(Constructor<cv::datasets::IR_robotObj>()).
    define_attr("name", &cv::datasets::IR_robotObj::name).
    define_attr("pos", &cv::datasets::IR_robotObj::pos);

  Rice::Data_Type<cv::datasets::IR_robot> rb_cCvDatasetsIRRobot = define_class_under<cv::datasets::IR_robot, cv::datasets::Dataset>(rb_mCvDatasets, "IRRobot").
    define_method<void(cv::datasets::IR_robot::*)(const std::string&)>("load", &cv::datasets::IR_robot::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::IR_robot>(*)()>("create", &cv::datasets::IR_robot::create);
}
