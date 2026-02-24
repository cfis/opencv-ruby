#include <opencv2/core/core.hpp>
#include <opencv2/core/traits.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/cvstd.inl.hpp>
#include "cvstd.inl-rb.hpp"

using namespace Rice;

void Init_Core_CvstdInl()
{
  Module rb_mCv = define_module("Cv");

  Data_Type<cv::Ptr<cv::Formatted>>().
    define_method("inspect", [](cv::Ptr<cv::Formatted> self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
  
  Data_Type<cv::MatND>().
    define_method("inspect", [](const cv::Mat& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
  
  Data_Type<cv::UMat>().
    define_method("inspect", [](const cv::UMat& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
  
  Data_Type<cv::MatSize>().
    define_method("inspect", [](const cv::MatSize& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
  
  Data_Type<cv::Range>().
    define_method("inspect", [](cv::Range& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
}
