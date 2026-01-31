#include <opencv2/core/cuda/simd_functions.hpp>
#include "simd_functions-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_SimdFunctions()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vadd2", &cv::cuda::device::vadd2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsub2", &cv::cuda::device::vsub2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vabsdiff2", &cv::cuda::device::vabsdiff2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vavg2", &cv::cuda::device::vavg2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vavrg2", &cv::cuda::device::vavrg2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vseteq2", &cv::cuda::device::vseteq2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpeq2", &cv::cuda::device::vcmpeq2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetge2", &cv::cuda::device::vsetge2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpge2", &cv::cuda::device::vcmpge2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetgt2", &cv::cuda::device::vsetgt2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpgt2", &cv::cuda::device::vcmpgt2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetle2", &cv::cuda::device::vsetle2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmple2", &cv::cuda::device::vcmple2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetlt2", &cv::cuda::device::vsetlt2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmplt2", &cv::cuda::device::vcmplt2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetne2", &cv::cuda::device::vsetne2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpne2", &cv::cuda::device::vcmpne2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vmax2", &cv::cuda::device::vmax2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vmin2", &cv::cuda::device::vmin2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vadd4", &cv::cuda::device::vadd4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsub4", &cv::cuda::device::vsub4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vavg4", &cv::cuda::device::vavg4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vavrg4", &cv::cuda::device::vavrg4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vseteq4", &cv::cuda::device::vseteq4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpeq4", &cv::cuda::device::vcmpeq4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetle4", &cv::cuda::device::vsetle4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmple4", &cv::cuda::device::vcmple4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetlt4", &cv::cuda::device::vsetlt4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmplt4", &cv::cuda::device::vcmplt4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetge4", &cv::cuda::device::vsetge4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpge4", &cv::cuda::device::vcmpge4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetgt4", &cv::cuda::device::vsetgt4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpgt4", &cv::cuda::device::vcmpgt4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetne4", &cv::cuda::device::vsetne4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpne4", &cv::cuda::device::vcmpne4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vabsdiff4", &cv::cuda::device::vabsdiff4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vmax4", &cv::cuda::device::vmax4,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vmin4", &cv::cuda::device::vmin4,
    Arg("a"), Arg("b"));
}