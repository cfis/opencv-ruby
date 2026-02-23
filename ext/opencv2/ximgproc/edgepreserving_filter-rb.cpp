#include <opencv2/ximgproc/edgepreserving_filter.hpp>
#include "edgepreserving_filter-rb.hpp"

using namespace Rice;

void Init_Ximgproc_EdgepreservingFilter()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  rb_mCvXimgproc.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, double)>("edge_preserving_filter", &cv::ximgproc::edgePreservingFilter,
    Arg("src"), Arg("dst"), Arg("d"), Arg("threshold"));
}
