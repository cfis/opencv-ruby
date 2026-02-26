#include <opencv2/dnn/dnn.inl.hpp>
#include "dnn.inl-rb.hpp"

using namespace Rice;

void Init_Dnn_DnnInl()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");


  Data_Type<cv::dnn::DictValue>().
    define_method("inspect", [](const cv::dnn::DictValue& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
  
  Data_Type<cv::dnn::Dict>().
    define_method("inspect", [](const cv::dnn::Dict& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
}
