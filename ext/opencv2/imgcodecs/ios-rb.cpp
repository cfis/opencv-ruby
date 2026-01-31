#include <opencv2/imgcodecs/ios.h>
#include "ios-rb.hpp"

using namespace Rice;

void Init_Imgcodecs_Ios()
{
  define_global_function<void(*)(const int, cv::Mat&, bool)>("cg_image_to_mat", &CGImageToMat,
    Arg("image"), Arg("m"), Arg("alpha_exist") = static_cast<bool>(false));

  define_global_function<int*(*)(const cv::Mat&)>("mat_to_ui_image", &MatToUIImage,
    Arg("image"), ReturnBuffer());

  define_global_function<void(*)(const int*, cv::Mat&, bool)>("ui_image_to_mat", &UIImageToMat,
    ArgBuffer("image"), Arg("m"), Arg("alpha_exist") = static_cast<bool>(false));
}