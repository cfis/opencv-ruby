#include <opencv2/core/cuda/simd_functions.hpp>
#include "simd_functions-rb.hpp"

using namespace Rice;


void Init_SimdFunctions()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_mCvCudaDevice.define_module_function("vadd2", &cv::cuda::device::vadd2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vsub2", &cv::cuda::device::vsub2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vabsdiff2", &cv::cuda::device::vabsdiff2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vavg2", &cv::cuda::device::vavg2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vavrg2", &cv::cuda::device::vavrg2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vseteq2", &cv::cuda::device::vseteq2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vcmpeq2", &cv::cuda::device::vcmpeq2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vsetge2", &cv::cuda::device::vsetge2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vcmpge2", &cv::cuda::device::vcmpge2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vsetgt2", &cv::cuda::device::vsetgt2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vcmpgt2", &cv::cuda::device::vcmpgt2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vsetle2", &cv::cuda::device::vsetle2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vcmple2", &cv::cuda::device::vcmple2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vsetlt2", &cv::cuda::device::vsetlt2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vcmplt2", &cv::cuda::device::vcmplt2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vsetne2", &cv::cuda::device::vsetne2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vcmpne2", &cv::cuda::device::vcmpne2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vmax2", &cv::cuda::device::vmax2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vmin2", &cv::cuda::device::vmin2,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vadd4", &cv::cuda::device::vadd4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vsub4", &cv::cuda::device::vsub4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vavg4", &cv::cuda::device::vavg4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vavrg4", &cv::cuda::device::vavrg4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vseteq4", &cv::cuda::device::vseteq4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vcmpeq4", &cv::cuda::device::vcmpeq4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vsetle4", &cv::cuda::device::vsetle4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vcmple4", &cv::cuda::device::vcmple4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vsetlt4", &cv::cuda::device::vsetlt4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vcmplt4", &cv::cuda::device::vcmplt4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vsetge4", &cv::cuda::device::vsetge4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vcmpge4", &cv::cuda::device::vcmpge4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vsetgt4", &cv::cuda::device::vsetgt4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vcmpgt4", &cv::cuda::device::vcmpgt4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vsetne4", &cv::cuda::device::vsetne4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vcmpne4", &cv::cuda::device::vcmpne4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vabsdiff4", &cv::cuda::device::vabsdiff4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vmax4", &cv::cuda::device::vmax4,
    Arg("a"), Arg("b"));
  
  rb_mCvCudaDevice.define_module_function("vmin4", &cv::cuda::device::vmin4,
    Arg("a"), Arg("b"));

}