#include <opencv2/core/base.hpp>
#include <opencv2/core/persistence.hpp>
#include "persistence-rb.hpp"

using namespace Rice;

void Init_Core_Persistence_Refinements()
{
  Module rb_mCv = define_module("Cv");

  // Alias each_const to each for FileNode (read-only iteration)
  rb_define_alias(Data_Type<cv::FileNode>::klass(), "each", "each_const");

  Data_Type<cv::FileStorage>().
    define_method("<<", [](cv::FileStorage& self, const cv::String& str) ->cv::FileStorage&
    {
      self << str;
      return self;
    }).
    define_method("<<", [](cv::FileStorage& self, const char* str) ->cv::FileStorage&
    {
      self << str;
      return self;
    }).
    define_method("<<", [](cv::FileStorage& self, char* str) ->cv::FileStorage&
    {
      self << str;
      return self;
    }).
    define_method("<<", [](cv::FileStorage& self, bool& value) ->cv::FileStorage&
    {
      self << value;
      return self;
    }).
    define_method("<<", [](cv::FileStorage& self, double& value) ->cv::FileStorage&
    {
      self << value;
      return self;
    }).
    define_method("<<", [](cv::FileStorage& self, float& value) ->cv::FileStorage&
    {
      self << value;
      return self;
    }).
    define_method("<<", [](cv::FileStorage& self, short& value) ->cv::FileStorage&
    {
      self << value;
      return self;
    }).
    define_method("<<", [](cv::FileStorage& self, int& value) ->cv::FileStorage&
    {
      self << value;
      return self;
    }).
    define_method("<<", [](cv::FileStorage& self, const cv::Mat& value) ->cv::FileStorage&
    {
      self << value;
      return self;
    }).
    define_method("<<", [](cv::FileStorage& self, const std::vector<cv::String>& value) ->cv::FileStorage&
    {
      self << value;
      return self;
    });
}
