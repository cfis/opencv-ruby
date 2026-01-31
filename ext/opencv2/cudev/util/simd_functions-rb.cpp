#include <opencv2/cudev/util/simd_functions.hpp>
#include "simd_functions-rb.hpp"

using namespace Rice;

void Init_Cudev_Util_SimdFunctions()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vadd2", &cv::cudev::vadd2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vsub2", &cv::cudev::vsub2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vabsdiff2", &cv::cudev::vabsdiff2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vavg2", &cv::cudev::vavg2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vavrg2", &cv::cudev::vavrg2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vseteq2", &cv::cudev::vseteq2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vcmpeq2", &cv::cudev::vcmpeq2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vsetge2", &cv::cudev::vsetge2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vcmpge2", &cv::cudev::vcmpge2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vsetgt2", &cv::cudev::vsetgt2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vcmpgt2", &cv::cudev::vcmpgt2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vsetle2", &cv::cudev::vsetle2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vcmple2", &cv::cudev::vcmple2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vsetlt2", &cv::cudev::vsetlt2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vcmplt2", &cv::cudev::vcmplt2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vsetne2", &cv::cudev::vsetne2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vcmpne2", &cv::cudev::vcmpne2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vmax2", &cv::cudev::vmax2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vmin2", &cv::cudev::vmin2,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vadd4", &cv::cudev::vadd4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vsub4", &cv::cudev::vsub4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vavg4", &cv::cudev::vavg4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vavrg4", &cv::cudev::vavrg4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vseteq4", &cv::cudev::vseteq4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vcmpeq4", &cv::cudev::vcmpeq4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vsetle4", &cv::cudev::vsetle4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vcmple4", &cv::cudev::vcmple4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vsetlt4", &cv::cudev::vsetlt4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vcmplt4", &cv::cudev::vcmplt4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vsetge4", &cv::cudev::vsetge4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vcmpge4", &cv::cudev::vcmpge4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vsetgt4", &cv::cudev::vsetgt4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vcmpgt4", &cv::cudev::vcmpgt4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vsetne4", &cv::cudev::vsetne4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vcmpne4", &cv::cudev::vcmpne4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vabsdiff4", &cv::cudev::vabsdiff4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vmax4", &cv::cudev::vmax4,
    Arg("a"), Arg("b"));

  rb_mCvCudev.define_module_function<uint(*)(uint, uint)>("vmin4", &cv::cudev::vmin4,
    Arg("a"), Arg("b"));
}