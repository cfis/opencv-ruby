#include <opencv2/ccalib/omnidir.hpp>
#include "omnidir-rb.hpp"

using namespace Rice;

void Init_Ccalib_Omnidir()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvOmnidir = define_module_under(rb_mCv, "Omnidir");

  rb_mCvOmnidir.define_constant("CALIB_USE_GUESS", (int)cv::omnidir::CALIB_USE_GUESS);
  rb_mCvOmnidir.define_constant("CALIB_FIX_SKEW", (int)cv::omnidir::CALIB_FIX_SKEW);
  rb_mCvOmnidir.define_constant("CALIB_FIX_K1", (int)cv::omnidir::CALIB_FIX_K1);
  rb_mCvOmnidir.define_constant("CALIB_FIX_K2", (int)cv::omnidir::CALIB_FIX_K2);
  rb_mCvOmnidir.define_constant("CALIB_FIX_P1", (int)cv::omnidir::CALIB_FIX_P1);
  rb_mCvOmnidir.define_constant("CALIB_FIX_P2", (int)cv::omnidir::CALIB_FIX_P2);
  rb_mCvOmnidir.define_constant("CALIB_FIX_XI", (int)cv::omnidir::CALIB_FIX_XI);
  rb_mCvOmnidir.define_constant("CALIB_FIX_GAMMA", (int)cv::omnidir::CALIB_FIX_GAMMA);
  rb_mCvOmnidir.define_constant("CALIB_FIX_CENTER", (int)cv::omnidir::CALIB_FIX_CENTER);

  rb_mCvOmnidir.define_constant("RECTIFY_PERSPECTIVE", (int)cv::omnidir::RECTIFY_PERSPECTIVE);
  rb_mCvOmnidir.define_constant("RECTIFY_CYLINDRICAL", (int)cv::omnidir::RECTIFY_CYLINDRICAL);
  rb_mCvOmnidir.define_constant("RECTIFY_LONGLATI", (int)cv::omnidir::RECTIFY_LONGLATI);
  rb_mCvOmnidir.define_constant("RECTIFY_STEREOGRAPHIC", (int)cv::omnidir::RECTIFY_STEREOGRAPHIC);

  rb_mCvOmnidir.define_constant("XYZRGB", (int)cv::omnidir::XYZRGB);
  rb_mCvOmnidir.define_constant("XYZ", (int)cv::omnidir::XYZ);

  rb_mCvOmnidir.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::InputArray, cv::InputArray, double, cv::InputArray, cv::OutputArray)>("project_points", &cv::omnidir::projectPoints,
    Arg("object_points"), Arg("image_points"), Arg("rvec"), Arg("tvec"), Arg("k"), Arg("xi"), Arg("d"), Arg("jacobian") = static_cast<cv::OutputArray>(cv::noArray()));

  rb_mCvOmnidir.define_module_function<void(*)(cv::InputArray, cv::OutputArray, const cv::Affine3d&, cv::InputArray, double, cv::InputArray, cv::OutputArray)>("project_points", &cv::omnidir::projectPoints,
    Arg("object_points"), Arg("image_points"), Arg("affine"), Arg("k"), Arg("xi"), Arg("d"), Arg("jacobian") = static_cast<cv::OutputArray>(cv::noArray()));

  rb_mCvOmnidir.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray)>("undistort_points", &cv::omnidir::undistortPoints,
    Arg("distorted"), Arg("undistorted"), Arg("k"), Arg("d"), Arg("xi"), Arg("r"));

  rb_mCvOmnidir.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, const cv::Size&, int, cv::OutputArray, cv::OutputArray, int)>("init_undistort_rectify_map", &cv::omnidir::initUndistortRectifyMap,
    Arg("k"), Arg("d"), Arg("xi"), Arg("r"), Arg("p"), Arg("size"), Arg("m1type"), Arg("map1"), Arg("map2"), Arg("flags"));

  rb_mCvOmnidir.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::InputArray, cv::InputArray, int, cv::InputArray, const cv::Size&, cv::InputArray)>("undistort_image", &cv::omnidir::undistortImage,
    Arg("distorted"), Arg("undistorted"), Arg("k"), Arg("d"), Arg("xi"), Arg("flags"), Arg("knew") = static_cast<cv::InputArray>(cv::noArray()), Arg("new_size") = static_cast<const cv::Size&>(cv::Size()), Arg("r") = static_cast<cv::InputArray>(cv::Mat::eye(3, 3, CV_64F)));

  rb_mCvOmnidir.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::Size, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, int, cv::TermCriteria, cv::OutputArray)>("calibrate", &cv::omnidir::calibrate,
    Arg("object_points"), Arg("image_points"), Arg("size"), Arg("k"), Arg("xi"), Arg("d"), Arg("rvecs"), Arg("tvecs"), Arg("flags"), Arg("criteria"), Arg("idx") = static_cast<cv::OutputArray>(cv::noArray()));

  rb_mCvOmnidir.define_module_function<double(*)(cv::InputOutputArrayOfArrays, cv::InputOutputArrayOfArrays, cv::InputOutputArrayOfArrays, const cv::Size&, const cv::Size&, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, int, cv::TermCriteria, cv::OutputArray)>("stereo_calibrate", &cv::omnidir::stereoCalibrate,
    Arg("object_points"), Arg("image_points1"), Arg("image_points2"), Arg("image_size1"), Arg("image_size2"), Arg("k1"), Arg("xi1"), Arg("d1"), Arg("k2"), Arg("xi2"), Arg("d2"), Arg("rvec"), Arg("tvec"), Arg("rvecs_l"), Arg("tvecs_l"), Arg("flags"), Arg("criteria"), Arg("idx") = static_cast<cv::OutputArray>(cv::noArray()));

  rb_mCvOmnidir.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("stereo_rectify", &cv::omnidir::stereoRectify,
    Arg("r"), Arg("t"), Arg("r1"), Arg("r2"));

  rb_mCvOmnidir.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, int, int, int, cv::OutputArray, cv::OutputArray, cv::OutputArray, const cv::Size&, cv::InputArray, cv::OutputArray, int)>("stereo_reconstruct", &cv::omnidir::stereoReconstruct,
    Arg("image1"), Arg("image2"), Arg("k1"), Arg("d1"), Arg("xi1"), Arg("k2"), Arg("d2"), Arg("xi2"), Arg("r"), Arg("t"), Arg("flag"), Arg("num_disparities"), Arg("sad_window_size"), Arg("disparity"), Arg("image1_rec"), Arg("image2_rec"), Arg("new_size") = static_cast<const cv::Size&>(cv::Size()), Arg("knew") = static_cast<cv::InputArray>(cv::noArray()), Arg("point_cloud") = static_cast<cv::OutputArray>(cv::noArray()), Arg("point_type") = static_cast<int>(cv::omnidir::XYZRGB));

  Module rb_mCvOmnidirInternal = define_module_under(rb_mCvOmnidir, "Internal");

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::Size, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArray, double&, cv::OutputArray)>("initialize_calibration", &cv::omnidir::internal::initializeCalibration,
    Arg("object_points"), Arg("image_points"), Arg("size"), Arg("om_all"), Arg("t_all"), Arg("k"), Arg("xi"), Arg("idx") = static_cast<cv::OutputArray>(cv::noArray()));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArrayOfArrays, const cv::Size&, const cv::Size&, cv::OutputArray, cv::OutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, double&, double&, int, cv::OutputArray)>("initialize_stereo_calibration", &cv::omnidir::internal::initializeStereoCalibration,
    Arg("object_points"), Arg("image_points1"), Arg("image_points2"), Arg("size1"), Arg("size2"), Arg("om"), Arg("t"), Arg("om_l"), Arg("t_l"), Arg("k1"), Arg("d1"), Arg("k2"), Arg("d2"), Arg("xi1"), Arg("xi2"), Arg("flags"), Arg("idx"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArray, cv::Mat&, cv::Mat&, int, double)>("compute_jacobian", &cv::omnidir::internal::computeJacobian,
    Arg("object_points"), Arg("image_points"), Arg("parameters"), Arg("jtj_inv"), Arg("jte"), Arg("flags"), Arg("epsilon"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArray, cv::Mat&, cv::Mat&, int, double)>("compute_jacobian_stereo", &cv::omnidir::internal::computeJacobianStereo,
    Arg("object_points"), Arg("image_points1"), Arg("image_points2"), Arg("parameters"), Arg("jtj_inv"), Arg("jte"), Arg("flags"), Arg("epsilon"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::InputArray, cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArray, double, cv::OutputArray)>("encode_parameters", &cv::omnidir::internal::encodeParameters,
    Arg("k"), Arg("om_all"), Arg("t_all"), Arg("distoaration"), Arg("xi"), Arg("parameters"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArray, cv::InputArray, double, double, cv::OutputArray)>("encode_parameters_stereo", &cv::omnidir::internal::encodeParametersStereo,
    Arg("k1"), Arg("k2"), Arg("om"), Arg("t"), Arg("om_l"), Arg("t_l"), Arg("d1"), Arg("d2"), Arg("xi1"), Arg("xi2"), Arg("parameters"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArray, double&)>("decode_parameters", &cv::omnidir::internal::decodeParameters,
    Arg("paramsters"), Arg("k"), Arg("om_all"), Arg("t_all"), Arg("distoration"), Arg("xi"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArray, cv::OutputArray, double&, double&)>("decode_parameters_stereo", &cv::omnidir::internal::decodeParametersStereo,
    Arg("parameters"), Arg("k1"), Arg("k2"), Arg("om"), Arg("t"), Arg("om_l"), Arg("t_l"), Arg("d1"), Arg("d2"), Arg("xi1"), Arg("xi2"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArray, cv::Mat&, cv::Vec2d&, double&, int)>("estimate_uncertainties", &cv::omnidir::internal::estimateUncertainties,
    Arg("object_points"), Arg("image_points"), Arg("parameters"), Arg("errors"), Arg("std_error"), Arg("rms"), Arg("flags"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArray, cv::Mat&, cv::Vec2d&, double&, int)>("estimate_uncertainties_stereo", &cv::omnidir::internal::estimateUncertaintiesStereo,
    Arg("object_points"), Arg("image_points1"), Arg("image_points2"), Arg("parameters"), Arg("errors"), Arg("std_error"), Arg("rms"), Arg("flags"));

  rb_mCvOmnidirInternal.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays)>("compute_mean_repro_err", &cv::omnidir::internal::computeMeanReproErr,
    Arg("image_points"), Arg("pro_image_points"));

  rb_mCvOmnidirInternal.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArray, cv::InputArray, double, cv::InputArrayOfArrays, cv::InputArrayOfArrays)>("compute_mean_repro_err", &cv::omnidir::internal::computeMeanReproErr,
    Arg("object_points"), Arg("image_points"), Arg("k"), Arg("d"), Arg("xi"), Arg("om_all"), Arg("t_all"));

  rb_mCvOmnidirInternal.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, double, double, cv::InputArray, cv::InputArray, cv::InputArrayOfArrays, cv::InputArrayOfArrays)>("compute_mean_repro_err_stereo", &cv::omnidir::internal::computeMeanReproErrStereo,
    Arg("object_points"), Arg("image_points1"), Arg("image_points2"), Arg("k1"), Arg("k2"), Arg("d1"), Arg("d2"), Arg("xi1"), Arg("xi2"), Arg("om"), Arg("t"), Arg("om_l"), Arg("tl"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::Mat&, cv::Mat&, const std::vector<int>&, const std::vector<int>&)>("sub_matrix", &cv::omnidir::internal::subMatrix,
    Arg("src"), Arg("dst"), Arg("cols"), Arg("rows"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(int, std::vector<int>&, int)>("flags2idx", &cv::omnidir::internal::flags2idx,
    Arg("flags"), Arg("idx"), Arg("n"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(int, std::vector<int>&, int)>("flags2idx_stereo", &cv::omnidir::internal::flags2idxStereo,
    Arg("flags"), Arg("idx"), Arg("n"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::Mat&, int, int)>("fill_fixed", &cv::omnidir::internal::fillFixed,
    Arg("g"), Arg("flags"), Arg("n"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::Mat&, int, int)>("fill_fixed_stereo", &cv::omnidir::internal::fillFixedStereo,
    Arg("g"), Arg("flags"), Arg("n"));

  rb_mCvOmnidirInternal.define_module_function<double(*)(const cv::Mat&)>("find_median", &cv::omnidir::internal::findMedian,
    Arg("row"));

  rb_mCvOmnidirInternal.define_module_function<cv::Vec3d(*)(cv::InputArray)>("find_median3", &cv::omnidir::internal::findMedian3,
    Arg("mat"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray)>("get_interset", &cv::omnidir::internal::getInterset,
    Arg("idx1"), Arg("idx2"), Arg("inter1"), Arg("inter2"), Arg("inter_ori"));

  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&)>("compose_motion", &cv::omnidir::internal::compose_motion,
    Arg("_om1"), Arg("_t1"), Arg("_om2"), Arg("_t2"), Arg("om3"), Arg("t3"), Arg("dom3dom1"), Arg("dom3d_t1"), Arg("dom3dom2"), Arg("dom3d_t2"), Arg("d_t3dom1"), Arg("d_t3d_t1"), Arg("d_t3dom2"), Arg("d_t3d_t2"));
}