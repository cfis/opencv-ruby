#include <opencv2/dnn/dnn.inl.hpp>
#include "dnn.inl-rb.hpp"

using namespace Rice;

void Init_Dnn_DnnInl()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");

  Module rb_mCvDnnDnn4V20241223 = define_module_under(rb_mCvDnn, "Dnn4V20241223");

  Data_Type<cv::dnn::dnn4_v20241223::DictValue>().
    define_method("inspect", [](const cv::dnn::dnn4_v20241223::DictValue& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
  
  Data_Type<cv::dnn::dnn4_v20241223::Dict>().
    define_method("inspect", [](const cv::dnn::dnn4_v20241223::Dict& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
}
