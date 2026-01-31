#include <opencv2/ximgproc/brightedges.hpp>
#include "brightedges-rb.hpp"

using namespace Rice;

void Init_Ximgproc_Brightedges()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  rb_mCvXimgproc.define_module_function<void(*)(cv::Mat&, cv::Mat&, int, int, int)>("bright_edges", &cv::ximgproc::BrightEdges,
    Arg("_original"), Arg("_edgeview"), Arg("contrast") = static_cast<int>(1), Arg("shortrange") = static_cast<int>(3), Arg("longrange") = static_cast<int>(9));
}