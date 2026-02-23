#include <opencv2/imgcodecs/macosx.h>
#include "macosx-rb.hpp"

using namespace Rice;

void Init_Imgcodecs_Macosx()
{
  define_global_function<void(*)(const int, cv::Mat&, bool)>("cg_image_to_mat", &CGImageToMat,
    Arg("image"), Arg("m"), Arg("alpha_exist") = static_cast<bool>(false));

  define_global_function<int*(*)(const cv::Mat&)>("mat_to_ns_image", &MatToNSImage,
    Arg("image"), ReturnBuffer());

  define_global_function<void(*)(const int*, cv::Mat&, bool)>("ns_image_to_mat", &NSImageToMat,
    ArgBuffer("image"), Arg("m"), Arg("alpha_exist") = static_cast<bool>(false));
}
