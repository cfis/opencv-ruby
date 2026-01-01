#include <opencv2/calib3d.hpp>
#include "../opencv_ruby_version.hpp"
#include "core/cvstd_wrapper-rb.hpp"
#include "calib3d-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCirclesGridFinderParameters;
Rice::Class rb_cCvLMSolver;
Rice::Class rb_cCvLMSolverCallback;
Rice::Class rb_cCvStereoBM;
Rice::Class rb_cCvStereoMatcher;
Rice::Class rb_cCvStereoSGBM;
Data_Type<cv::UsacParams> rb_cCvUsacParams;

void Init_Calib3d()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_constant("LMEDS", (int)cv::LMEDS);
  rb_mCv.define_constant("RANSAC", (int)cv::RANSAC);
  rb_mCv.define_constant("RHO", (int)cv::RHO);
  rb_mCv.define_constant("USAC_DEFAULT", (int)cv::USAC_DEFAULT);
  rb_mCv.define_constant("USAC_PARALLEL", (int)cv::USAC_PARALLEL);
  rb_mCv.define_constant("USAC_FM_8PTS", (int)cv::USAC_FM_8PTS);
  rb_mCv.define_constant("USAC_FAST", (int)cv::USAC_FAST);
  rb_mCv.define_constant("USAC_ACCURATE", (int)cv::USAC_ACCURATE);
  rb_mCv.define_constant("USAC_PROSAC", (int)cv::USAC_PROSAC);
  rb_mCv.define_constant("USAC_MAGSAC", (int)cv::USAC_MAGSAC);
  
  Enum<cv::SolvePnPMethod> rb_cCvSolvePnPMethod = define_enum_under<cv::SolvePnPMethod>("SolvePnPMethod", rb_mCv).
    define_value("SOLVEPNP_ITERATIVE", cv::SolvePnPMethod::SOLVEPNP_ITERATIVE).
    define_value("SOLVEPNP_EPNP", cv::SolvePnPMethod::SOLVEPNP_EPNP).
    define_value("SOLVEPNP_P3P", cv::SolvePnPMethod::SOLVEPNP_P3P).
    define_value("SOLVEPNP_DLS", cv::SolvePnPMethod::SOLVEPNP_DLS).
    define_value("SOLVEPNP_UPNP", cv::SolvePnPMethod::SOLVEPNP_UPNP).
    define_value("SOLVEPNP_AP3P", cv::SolvePnPMethod::SOLVEPNP_AP3P).
    define_value("SOLVEPNP_IPPE", cv::SolvePnPMethod::SOLVEPNP_IPPE).
    define_value("SOLVEPNP_IPPE_SQUARE", cv::SolvePnPMethod::SOLVEPNP_IPPE_SQUARE).
    define_value("SOLVEPNP_SQPNP", cv::SolvePnPMethod::SOLVEPNP_SQPNP).
    define_value("SOLVEPNP_MAX_COUNT", cv::SolvePnPMethod::SOLVEPNP_MAX_COUNT);
  
  rb_mCv.define_constant("CALIB_CB_ADAPTIVE_THRESH", (int)cv::CALIB_CB_ADAPTIVE_THRESH);
  rb_mCv.define_constant("CALIB_CB_NORMALIZE_IMAGE", (int)cv::CALIB_CB_NORMALIZE_IMAGE);
  rb_mCv.define_constant("CALIB_CB_FILTER_QUADS", (int)cv::CALIB_CB_FILTER_QUADS);
  rb_mCv.define_constant("CALIB_CB_FAST_CHECK", (int)cv::CALIB_CB_FAST_CHECK);
  rb_mCv.define_constant("CALIB_CB_EXHAUSTIVE", (int)cv::CALIB_CB_EXHAUSTIVE);
  rb_mCv.define_constant("CALIB_CB_ACCURACY", (int)cv::CALIB_CB_ACCURACY);
  rb_mCv.define_constant("CALIB_CB_LARGER", (int)cv::CALIB_CB_LARGER);
  rb_mCv.define_constant("CALIB_CB_MARKER", (int)cv::CALIB_CB_MARKER);

#if RUBY_CV_VERSION >= 409
    rb_mCv.define_constant("CALIB_CB_PLAIN", (int)cv::CALIB_CB_PLAIN);
#endif

  rb_mCv.define_constant("CALIB_CB_SYMMETRIC_GRID", (int)cv::CALIB_CB_SYMMETRIC_GRID);
  rb_mCv.define_constant("CALIB_CB_ASYMMETRIC_GRID", (int)cv::CALIB_CB_ASYMMETRIC_GRID);
  rb_mCv.define_constant("CALIB_CB_CLUSTERING", (int)cv::CALIB_CB_CLUSTERING);
  
  rb_mCv.define_constant("CALIB_NINTRINSIC", (int)cv::CALIB_NINTRINSIC);
  rb_mCv.define_constant("CALIB_USE_INTRINSIC_GUESS", (int)cv::CALIB_USE_INTRINSIC_GUESS);
  rb_mCv.define_constant("CALIB_FIX_ASPECT_RATIO", (int)cv::CALIB_FIX_ASPECT_RATIO);
  rb_mCv.define_constant("CALIB_FIX_PRINCIPAL_POINT", (int)cv::CALIB_FIX_PRINCIPAL_POINT);
  rb_mCv.define_constant("CALIB_ZERO_TANGENT_DIST", (int)cv::CALIB_ZERO_TANGENT_DIST);
  rb_mCv.define_constant("CALIB_FIX_FOCAL_LENGTH", (int)cv::CALIB_FIX_FOCAL_LENGTH);
  rb_mCv.define_constant("CALIB_FIX_K1", (int)cv::CALIB_FIX_K1);
  rb_mCv.define_constant("CALIB_FIX_K2", (int)cv::CALIB_FIX_K2);
  rb_mCv.define_constant("CALIB_FIX_K3", (int)cv::CALIB_FIX_K3);
  rb_mCv.define_constant("CALIB_FIX_K4", (int)cv::CALIB_FIX_K4);
  rb_mCv.define_constant("CALIB_FIX_K5", (int)cv::CALIB_FIX_K5);
  rb_mCv.define_constant("CALIB_FIX_K6", (int)cv::CALIB_FIX_K6);
  rb_mCv.define_constant("CALIB_RATIONAL_MODEL", (int)cv::CALIB_RATIONAL_MODEL);
  rb_mCv.define_constant("CALIB_THIN_PRISM_MODEL", (int)cv::CALIB_THIN_PRISM_MODEL);
  rb_mCv.define_constant("CALIB_FIX_S1_S2_S3_S4", (int)cv::CALIB_FIX_S1_S2_S3_S4);
  rb_mCv.define_constant("CALIB_TILTED_MODEL", (int)cv::CALIB_TILTED_MODEL);
  rb_mCv.define_constant("CALIB_FIX_TAUX_TAUY", (int)cv::CALIB_FIX_TAUX_TAUY);
  rb_mCv.define_constant("CALIB_USE_QR", (int)cv::CALIB_USE_QR);
  rb_mCv.define_constant("CALIB_FIX_TANGENT_DIST", (int)cv::CALIB_FIX_TANGENT_DIST);
  rb_mCv.define_constant("CALIB_FIX_INTRINSIC", (int)cv::CALIB_FIX_INTRINSIC);
  rb_mCv.define_constant("CALIB_SAME_FOCAL_LENGTH", (int)cv::CALIB_SAME_FOCAL_LENGTH);
  rb_mCv.define_constant("CALIB_ZERO_DISPARITY", (int)cv::CALIB_ZERO_DISPARITY);
  rb_mCv.define_constant("CALIB_USE_LU", (int)cv::CALIB_USE_LU);
  rb_mCv.define_constant("CALIB_USE_EXTRINSIC_GUESS", (int)cv::CALIB_USE_EXTRINSIC_GUESS);
  
  rb_mCv.define_constant("FM_7POINT", (int)cv::FM_7POINT);
  rb_mCv.define_constant("FM_8POINT", (int)cv::FM_8POINT);
  rb_mCv.define_constant("FM_LMEDS", (int)cv::FM_LMEDS);
  rb_mCv.define_constant("FM_RANSAC", (int)cv::FM_RANSAC);
  
  Enum<cv::HandEyeCalibrationMethod> rb_cCvHandEyeCalibrationMethod = define_enum_under<cv::HandEyeCalibrationMethod>("HandEyeCalibrationMethod", rb_mCv).
    define_value("CALIB_HAND_EYE_TSAI", cv::HandEyeCalibrationMethod::CALIB_HAND_EYE_TSAI).
    define_value("CALIB_HAND_EYE_PARK", cv::HandEyeCalibrationMethod::CALIB_HAND_EYE_PARK).
    define_value("CALIB_HAND_EYE_HORAUD", cv::HandEyeCalibrationMethod::CALIB_HAND_EYE_HORAUD).
    define_value("CALIB_HAND_EYE_ANDREFF", cv::HandEyeCalibrationMethod::CALIB_HAND_EYE_ANDREFF).
    define_value("CALIB_HAND_EYE_DANIILIDIS", cv::HandEyeCalibrationMethod::CALIB_HAND_EYE_DANIILIDIS);
  
  Enum<cv::RobotWorldHandEyeCalibrationMethod> rb_cCvRobotWorldHandEyeCalibrationMethod = define_enum_under<cv::RobotWorldHandEyeCalibrationMethod>("RobotWorldHandEyeCalibrationMethod", rb_mCv).
    define_value("CALIB_ROBOT_WORLD_HAND_EYE_SHAH", cv::RobotWorldHandEyeCalibrationMethod::CALIB_ROBOT_WORLD_HAND_EYE_SHAH).
    define_value("CALIB_ROBOT_WORLD_HAND_EYE_LI", cv::RobotWorldHandEyeCalibrationMethod::CALIB_ROBOT_WORLD_HAND_EYE_LI);
  
  Enum<cv::SamplingMethod> rb_cCvSamplingMethod = define_enum_under<cv::SamplingMethod>("SamplingMethod", rb_mCv).
    define_value("SAMPLING_UNIFORM", cv::SamplingMethod::SAMPLING_UNIFORM).
    define_value("SAMPLING_PROGRESSIVE_NAPSAC", cv::SamplingMethod::SAMPLING_PROGRESSIVE_NAPSAC).
    define_value("SAMPLING_NAPSAC", cv::SamplingMethod::SAMPLING_NAPSAC).
    define_value("SAMPLING_PROSAC", cv::SamplingMethod::SAMPLING_PROSAC);
  
  Enum<cv::LocalOptimMethod> rb_cCvLocalOptimMethod = define_enum_under<cv::LocalOptimMethod>("LocalOptimMethod", rb_mCv).
    define_value("LOCAL_OPTIM_NULL", cv::LocalOptimMethod::LOCAL_OPTIM_NULL).
    define_value("LOCAL_OPTIM_INNER_LO", cv::LocalOptimMethod::LOCAL_OPTIM_INNER_LO).
    define_value("LOCAL_OPTIM_INNER_AND_ITER_LO", cv::LocalOptimMethod::LOCAL_OPTIM_INNER_AND_ITER_LO).
    define_value("LOCAL_OPTIM_GC", cv::LocalOptimMethod::LOCAL_OPTIM_GC).
    define_value("LOCAL_OPTIM_SIGMA", cv::LocalOptimMethod::LOCAL_OPTIM_SIGMA);
  
  Enum<cv::ScoreMethod> rb_cCvScoreMethod = define_enum_under<cv::ScoreMethod>("ScoreMethod", rb_mCv).
    define_value("SCORE_METHOD_RANSAC", cv::ScoreMethod::SCORE_METHOD_RANSAC).
    define_value("SCORE_METHOD_MSAC", cv::ScoreMethod::SCORE_METHOD_MSAC).
    define_value("SCORE_METHOD_MAGSAC", cv::ScoreMethod::SCORE_METHOD_MAGSAC).
    define_value("SCORE_METHOD_LMEDS", cv::ScoreMethod::SCORE_METHOD_LMEDS);
  
  Enum<cv::NeighborSearchMethod> rb_cCvNeighborSearchMethod = define_enum_under<cv::NeighborSearchMethod>("NeighborSearchMethod", rb_mCv).
    define_value("NEIGH_FLANN_KNN", cv::NeighborSearchMethod::NEIGH_FLANN_KNN).
    define_value("NEIGH_GRID", cv::NeighborSearchMethod::NEIGH_GRID).
    define_value("NEIGH_FLANN_RADIUS", cv::NeighborSearchMethod::NEIGH_FLANN_RADIUS);
  
#if RUBY_CV_VERSION >= 408
  Enum<cv::PolishingMethod> rb_cCvPolishingMethod = define_enum_under<cv::PolishingMethod>("PolishingMethod", rb_mCv).
    define_value("NONE_POLISHER", cv::PolishingMethod::NONE_POLISHER).
    define_value("LSQ_POLISHER", cv::PolishingMethod::LSQ_POLISHER).
    define_value("MAGSAC", cv::PolishingMethod::MAGSAC).
    define_value("COV_POLISHER", cv::PolishingMethod::COV_POLISHER);
#endif

  rb_cCvUsacParams = define_class_under<cv::UsacParams>(rb_mCv, "UsacParams").
    define_constructor(Constructor<cv::UsacParams>()).
    define_attr("confidence", &cv::UsacParams::confidence).
    define_attr("is_parallel", &cv::UsacParams::isParallel).
    define_attr("lo_iterations", &cv::UsacParams::loIterations).
    define_attr("lo_method", &cv::UsacParams::loMethod).
    define_attr("lo_sample_size", &cv::UsacParams::loSampleSize).
    define_attr("max_iterations", &cv::UsacParams::maxIterations).
    define_attr("neighbors_search", &cv::UsacParams::neighborsSearch).
    define_attr("random_generator_state", &cv::UsacParams::randomGeneratorState).
    define_attr("sampler", &cv::UsacParams::sampler).
    define_attr("score", &cv::UsacParams::score).
    define_attr("threshold", &cv::UsacParams::threshold);

#if RUBY_CV_VERSION >= 408
  rb_cCvUsacParams.
    define_attr("final_polisher", &cv::UsacParams::final_polisher).
    define_attr("final_polisher_iterations", &cv::UsacParams::final_polisher_iterations);
#endif
  
  rb_mCv.define_module_function("rodrigues", &cv::Rodrigues,
    Arg("src"), Arg("dst"), Arg("jacobian") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_cCvLMSolverCallback = define_class_under<cv::LMSolver::Callback>(rb_cCvLMSolver, "Callback").
    define_method("compute?", &cv::LMSolver::Callback::compute,
      Arg("param"), Arg("err"), Arg("j"));

  rb_cCvLMSolver = define_class_under<cv::LMSolver, cv::Algorithm>(rb_mCv, "LMSolver").
    define_method("run", &cv::LMSolver::run,
      Arg("param")).
    define_method("set_max_iters", &cv::LMSolver::setMaxIters,
      Arg("max_iters")).
    define_method("get_max_iters", &cv::LMSolver::getMaxIters).
    define_singleton_function<cv::Ptr<cv::LMSolver>(*)(const cv::Ptr<cv::LMSolver::Callback>&, int)>("create", &cv::LMSolver::create,
      Arg("cb"), Arg("max_iters")).
    define_singleton_function<cv::Ptr<cv::LMSolver>(*)(const cv::Ptr<cv::LMSolver::Callback>&, int, double)>("create", &cv::LMSolver::create,
      Arg("cb"), Arg("max_iters"), Arg("eps"));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, int, double, cv::OutputArray, const int, const double)>("find_homography", &cv::findHomography,
    Arg("src_points"), Arg("dst_points"), Arg("method") = static_cast<int>(0), Arg("ransac_reproj_threshold") = static_cast<double>(3), Arg("mask") = static_cast<cv::OutputArray>(cv::noArray()), Arg("max_iters") = static_cast<const int>(2000), Arg("confidence") = static_cast<const double>(0.995));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, double)>("find_homography", &cv::findHomography,
    Arg("src_points"), Arg("dst_points"), Arg("mask"), Arg("method") = static_cast<int>(0), Arg("ransac_reproj_threshold") = static_cast<double>(3));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, cv::OutputArray, const cv::UsacParams&)>("find_homography", &cv::findHomography,
    Arg("src_points"), Arg("dst_points"), Arg("mask"), Arg("params"));
  
  rb_mCv.define_module_function("rq_decomp3x3", &cv::RQDecomp3x3,
    Arg("src"), Arg("mtx_r"), Arg("mtx_q"), Arg("qx") = static_cast<cv::OutputArray>(cv::noArray()), Arg("qy") = static_cast<cv::OutputArray>(cv::noArray()), Arg("qz") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function("decompose_projection_matrix", &cv::decomposeProjectionMatrix,
    Arg("proj_matrix"), Arg("camera_matrix"), Arg("rot_matrix"), Arg("trans_vect"), Arg("rot_matrix_x") = static_cast<cv::OutputArray>(cv::noArray()), Arg("rot_matrix_y") = static_cast<cv::OutputArray>(cv::noArray()), Arg("rot_matrix_z") = static_cast<cv::OutputArray>(cv::noArray()), Arg("euler_angles") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function("mat_mul_deriv", &cv::matMulDeriv,
    Arg("a"), Arg("b"), Arg("d_a_bd_a"), Arg("d_a_bd_b"));
  
  rb_mCv.define_module_function("compose_rt", &cv::composeRT,
    Arg("rvec1"), Arg("tvec1"), Arg("rvec2"), Arg("tvec2"), Arg("rvec3"), Arg("tvec3"), Arg("dr3dr1") = static_cast<cv::OutputArray>(cv::noArray()), Arg("dr3dt1") = static_cast<cv::OutputArray>(cv::noArray()), Arg("dr3dr2") = static_cast<cv::OutputArray>(cv::noArray()), Arg("dr3dt2") = static_cast<cv::OutputArray>(cv::noArray()), Arg("dt3dr1") = static_cast<cv::OutputArray>(cv::noArray()), Arg("dt3dt1") = static_cast<cv::OutputArray>(cv::noArray()), Arg("dt3dr2") = static_cast<cv::OutputArray>(cv::noArray()), Arg("dt3dt2") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function("project_points", &cv::projectPoints,
    Arg("object_points"), Arg("rvec"), Arg("tvec"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("image_points"), Arg("jacobian") = static_cast<cv::OutputArray>(cv::noArray()), Arg("aspect_ratio") = static_cast<double>(0));
  
  rb_mCv.define_module_function("solve_pn_p?", &cv::solvePnP,
    Arg("object_points"), Arg("image_points"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("use_extrinsic_guess") = static_cast<bool>(false), Arg("flags") = static_cast<int>(cv::SolvePnPMethod::SOLVEPNP_ITERATIVE));
  
  rb_mCv.define_module_function<bool(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, bool, int, float, double, cv::OutputArray, int)>("solve_pn_p_ransac?", &cv::solvePnPRansac,
    Arg("object_points"), Arg("image_points"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("use_extrinsic_guess") = static_cast<bool>(false), Arg("iterations_count") = static_cast<int>(100), Arg("reprojection_error") = static_cast<float>(8.0), Arg("confidence") = static_cast<double>(0.99), Arg("inliers") = static_cast<cv::OutputArray>(cv::noArray()), Arg("flags") = static_cast<int>(cv::SolvePnPMethod::SOLVEPNP_ITERATIVE));
  
  rb_mCv.define_module_function<bool(*)(cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, const cv::UsacParams&)>("solve_pn_p_ransac?", &cv::solvePnPRansac,
    Arg("object_points"), Arg("image_points"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("inliers"), Arg("params") = static_cast<const cv::UsacParams &>(cv::UsacParams()));
  
  rb_mCv.define_module_function("solve_p3_p", &cv::solveP3P,
    Arg("object_points"), Arg("image_points"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvecs"), Arg("tvecs"), Arg("flags"));
  
  rb_mCv.define_module_function("solve_pn_p_refine_lm", &cv::solvePnPRefineLM,
    Arg("object_points"), Arg("image_points"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 20, FLT_EPSILON)));
  
  rb_mCv.define_module_function("solve_pn_p_refine_vvs", &cv::solvePnPRefineVVS,
    Arg("object_points"), Arg("image_points"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 20, FLT_EPSILON)), Arg("vv_slambda") = static_cast<double>(1));
  
  rb_mCv.define_module_function("solve_pn_p_generic", &cv::solvePnPGeneric,
    Arg("object_points"), Arg("image_points"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvecs"), Arg("tvecs"), Arg("use_extrinsic_guess") = static_cast<bool>(false), Arg("flags") = static_cast<cv::SolvePnPMethod>(cv::SolvePnPMethod::SOLVEPNP_ITERATIVE), Arg("rvec") = static_cast<cv::InputArray>(cv::noArray()), Arg("tvec") = static_cast<cv::InputArray>(cv::noArray()), Arg("reprojection_error") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function("init_camera_matrix_2d", &cv::initCameraMatrix2D,
    Arg("object_points"), Arg("image_points"), Arg("image_size"), Arg("aspect_ratio") = static_cast<double>(1.0));
  
  rb_mCv.define_module_function("find_chessboard_corners", &cv::findChessboardCorners,
    Arg("image"), Arg("pattern_size"), Arg("corners"), Arg("flags") = static_cast<int>(cv::CALIB_CB_ADAPTIVE_THRESH + cv::CALIB_CB_NORMALIZE_IMAGE));
  
  rb_mCv.define_module_function("check_chessboard?", &cv::checkChessboard,
    Arg("img"), Arg("size"));
  
  rb_mCv.define_module_function<bool(*)(cv::InputArray, cv::Size, cv::OutputArray, int, cv::OutputArray)>("find_chessboard_corners_sb?", &cv::findChessboardCornersSB,
    Arg("image"), Arg("pattern_size"), Arg("corners"), Arg("flags"), Arg("meta"));
  
  rb_mCv.define_module_function<bool(*)(cv::InputArray, cv::Size, cv::OutputArray, int)>("find_chessboard_corners_sb?", &cv::findChessboardCornersSB,
    Arg("image"), Arg("pattern_size"), Arg("corners"), Arg("flags") = static_cast<int>(0));
  
  rb_mCv.define_module_function("estimate_chessboard_sharpness", &cv::estimateChessboardSharpness,
    Arg("image"), Arg("pattern_size"), Arg("corners"), Arg("rise_distance") = static_cast<float>(0.8F), Arg("vertical") = static_cast<bool>(false), Arg("sharpness") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function("find4_quad_corner_subpix?", &cv::find4QuadCornerSubpix,
    Arg("img"), Arg("corners"), Arg("region_size"));
  
  rb_mCv.define_module_function("draw_chessboard_corners", &cv::drawChessboardCorners,
    Arg("image"), Arg("pattern_size"), Arg("corners"), Arg("pattern_was_found"));
  
  rb_mCv.define_module_function("draw_frame_axes", &cv::drawFrameAxes,
    Arg("image"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("length"), Arg("thickness") = static_cast<int>(3));
  
  rb_cCvCirclesGridFinderParameters = define_class_under<cv::CirclesGridFinderParameters>(rb_mCv, "CirclesGridFinderParameters").
    define_constructor(Constructor<cv::CirclesGridFinderParameters>()).
    define_attr("density_neighborhood_size", &cv::CirclesGridFinderParameters::densityNeighborhoodSize).
    define_attr("min_density", &cv::CirclesGridFinderParameters::minDensity).
    define_attr("kmeans_attempts", &cv::CirclesGridFinderParameters::kmeansAttempts).
    define_attr("min_distance_to_add_keypoint", &cv::CirclesGridFinderParameters::minDistanceToAddKeypoint).
    define_attr("keypoint_scale", &cv::CirclesGridFinderParameters::keypointScale).
    define_attr("min_graph_confidence", &cv::CirclesGridFinderParameters::minGraphConfidence).
    define_attr("vertex_gain", &cv::CirclesGridFinderParameters::vertexGain).
    define_attr("vertex_penalty", &cv::CirclesGridFinderParameters::vertexPenalty).
    define_attr("existing_vertex_gain", &cv::CirclesGridFinderParameters::existingVertexGain).
    define_attr("edge_gain", &cv::CirclesGridFinderParameters::edgeGain).
    define_attr("edge_penalty", &cv::CirclesGridFinderParameters::edgePenalty).
    define_attr("convex_hull_factor", &cv::CirclesGridFinderParameters::convexHullFactor).
    define_attr("min_rng_edge_switch_dist", &cv::CirclesGridFinderParameters::minRNGEdgeSwitchDist).
    define_attr("grid_type", &cv::CirclesGridFinderParameters::gridType).
    define_attr("square_size", &cv::CirclesGridFinderParameters::squareSize).
    define_attr("max_rectified_distance", &cv::CirclesGridFinderParameters::maxRectifiedDistance);
  
  Enum<cv::CirclesGridFinderParameters::GridType> rb_cCvCirclesGridFinderParametersGridType = define_enum_under<cv::CirclesGridFinderParameters::GridType>("GridType", rb_cCvCirclesGridFinderParameters).
    define_value("SYMMETRIC_GRID", cv::CirclesGridFinderParameters::GridType::SYMMETRIC_GRID).
    define_value("ASYMMETRIC_GRID", cv::CirclesGridFinderParameters::GridType::ASYMMETRIC_GRID);
  
  rb_mCv.define_module_function<bool(*)(cv::InputArray, cv::Size, cv::OutputArray, int, const cv::Ptr<cv::Feature2D>&, const cv::CirclesGridFinderParameters&)>("find_circles_grid?", &cv::findCirclesGrid,
    Arg("image"), Arg("pattern_size"), Arg("centers"), Arg("flags"), Arg("blob_detector"), Arg("parameters"));
  
  rb_mCv.define_module_function<bool(*)(cv::InputArray, cv::Size, cv::OutputArray, int, const cv::Ptr<cv::Feature2D>&)>("find_circles_grid?", &cv::findCirclesGrid,
    Arg("image"), Arg("pattern_size"), Arg("centers"), Arg("flags") = static_cast<int>(cv::CALIB_CB_SYMMETRIC_GRID), Arg("blob_detector") = static_cast<const cv::Ptr<cv::FeatureDetector> &>(cv::SimpleBlobDetector::create()));
  
  rb_mCv.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::Size, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArray, cv::OutputArray, cv::OutputArray, int, cv::TermCriteria)>("calibrate_camera", &cv::calibrateCamera,
    Arg("object_points"), Arg("image_points"), Arg("image_size"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvecs"), Arg("tvecs"), Arg("std_deviations_intrinsics"), Arg("std_deviations_extrinsics"), Arg("per_view_errors"), Arg("flags") = static_cast<int>(0), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria()));
  
  rb_mCv.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::Size, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, int, cv::TermCriteria)>("calibrate_camera", &cv::calibrateCamera,
    Arg("object_points"), Arg("image_points"), Arg("image_size"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvecs"), Arg("tvecs"), Arg("flags") = static_cast<int>(0), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria()));
  
  rb_mCv.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::Size, int, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, int, cv::TermCriteria)>("calibrate_camera_ro", &cv::calibrateCameraRO,
    Arg("object_points"), Arg("image_points"), Arg("image_size"), Arg("i_fixed_point"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvecs"), Arg("tvecs"), Arg("new_obj_points"), Arg("std_deviations_intrinsics"), Arg("std_deviations_extrinsics"), Arg("std_deviations_obj_points"), Arg("per_view_errors"), Arg("flags") = static_cast<int>(0), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria()));
  
  rb_mCv.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::Size, int, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArray, int, cv::TermCriteria)>("calibrate_camera_ro", &cv::calibrateCameraRO,
    Arg("object_points"), Arg("image_points"), Arg("image_size"), Arg("i_fixed_point"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvecs"), Arg("tvecs"), Arg("new_obj_points"), Arg("flags") = static_cast<int>(0), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria()));
  
  rb_mCv.define_module_function("calibration_matrix_values", &cv::calibrationMatrixValues,
    Arg("camera_matrix"), Arg("image_size"), Arg("aperture_width"), Arg("aperture_height"), Arg("fovx"), Arg("fovy"), Arg("focal_length"), Arg("principal_point"), Arg("aspect_ratio"));
  
#if RUBY_CV_VERSION >= 407
  rb_mCv.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::Size, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, cv::OutputArray, int, cv::TermCriteria)>("stereo_calibrate", &cv::stereoCalibrate,
    Arg("object_points"), Arg("image_points1"), Arg("image_points2"), Arg("camera_matrix1"), Arg("dist_coeffs1"), Arg("camera_matrix2"), Arg("dist_coeffs2"), Arg("image_size"), Arg("r"), Arg("t"), Arg("e"), Arg("f"), Arg("rvecs"), Arg("tvecs"), Arg("per_view_errors"), Arg("flags") = static_cast<int>(cv::CALIB_FIX_INTRINSIC), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::COUNT+cv::TermCriteria::EPS, 30, 1e-6)));
#endif

  rb_mCv.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::Size, cv::OutputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, int, cv::TermCriteria)>("stereo_calibrate", &cv::stereoCalibrate,
    Arg("object_points"), Arg("image_points1"), Arg("image_points2"), Arg("camera_matrix1"), Arg("dist_coeffs1"), Arg("camera_matrix2"), Arg("dist_coeffs2"), Arg("image_size"), Arg("r"), Arg("t"), Arg("e"), Arg("f"), Arg("flags") = static_cast<int>(cv::CALIB_FIX_INTRINSIC), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::COUNT+cv::TermCriteria::EPS, 30, 1e-6)));
  
  rb_mCv.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::Size, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, int, cv::TermCriteria)>("stereo_calibrate", &cv::stereoCalibrate,
    Arg("object_points"), Arg("image_points1"), Arg("image_points2"), Arg("camera_matrix1"), Arg("dist_coeffs1"), Arg("camera_matrix2"), Arg("dist_coeffs2"), Arg("image_size"), Arg("r"), Arg("t"), Arg("e"), Arg("f"), Arg("per_view_errors"), Arg("flags") = static_cast<int>(cv::CALIB_FIX_INTRINSIC), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::COUNT+cv::TermCriteria::EPS, 30, 1e-6)));
  
  rb_mCv.define_module_function("stereo_rectify", &cv::stereoRectify,
    Arg("camera_matrix1"), Arg("dist_coeffs1"), Arg("camera_matrix2"), Arg("dist_coeffs2"), Arg("image_size"), Arg("r"), Arg("t"), Arg("r1"), Arg("r2"), Arg("p1"), Arg("p2"), Arg("q"), Arg("flags") = static_cast<int>(cv::CALIB_ZERO_DISPARITY), Arg("alpha") = static_cast<double>(-1), Arg("new_image_size") = static_cast<cv::Size>(cv::Size()), Arg("valid_pix_roi1") = static_cast<cv::Rect *>(0), Arg("valid_pix_roi2") = static_cast<cv::Rect *>(0));
  
  rb_mCv.define_module_function("stereo_rectify_uncalibrated?", &cv::stereoRectifyUncalibrated,
    Arg("points1"), Arg("points2"), Arg("f"), Arg("img_size"), Arg("h1"), Arg("h2"), Arg("threshold") = static_cast<double>(5));
  
  rb_mCv.define_module_function("rectify3_collinear", &cv::rectify3Collinear,
    Arg("camera_matrix1"), Arg("dist_coeffs1"), Arg("camera_matrix2"), Arg("dist_coeffs2"), Arg("camera_matrix3"), Arg("dist_coeffs3"), Arg("imgpt1"), Arg("imgpt3"), Arg("image_size"), Arg("r12"), Arg("t12"), Arg("r13"), Arg("t13"), Arg("r1"), Arg("r2"), Arg("r3"), Arg("p1"), Arg("p2"), Arg("p3"), Arg("q"), Arg("alpha"), Arg("new_img_size"), Arg("roi1"), Arg("roi2"), Arg("flags"));
  
  rb_mCv.define_module_function("get_optimal_new_camera_matrix", &cv::getOptimalNewCameraMatrix,
    Arg("camera_matrix"), Arg("dist_coeffs"), Arg("image_size"), Arg("alpha"), Arg("new_img_size") = static_cast<cv::Size>(cv::Size()), Arg("valid_pix_roi") = static_cast<cv::Rect *>(0), Arg("center_principal_point") = static_cast<bool>(false));
  
  rb_mCv.define_module_function("calibrate_hand_eye", &cv::calibrateHandEye,
    Arg("r_gripper2base"), Arg("t_gripper2base"), Arg("r_target2cam"), Arg("t_target2cam"), Arg("r_cam2gripper"), Arg("t_cam2gripper"), Arg("method") = static_cast<cv::HandEyeCalibrationMethod>(cv::CALIB_HAND_EYE_TSAI));
  
  rb_mCv.define_module_function("calibrate_robot_world_hand_eye", &cv::calibrateRobotWorldHandEye,
    Arg("r_world2cam"), Arg("t_world2cam"), Arg("r_base2gripper"), Arg("t_base2gripper"), Arg("r_base2world"), Arg("t_base2world"), Arg("r_gripper2cam"), Arg("t_gripper2cam"), Arg("method") = static_cast<cv::RobotWorldHandEyeCalibrationMethod>(cv::CALIB_ROBOT_WORLD_HAND_EYE_SHAH));
  
  rb_mCv.define_module_function("convert_points_to_homogeneous", &cv::convertPointsToHomogeneous,
    Arg("src"), Arg("dst"));
  
  rb_mCv.define_module_function("convert_points_from_homogeneous", &cv::convertPointsFromHomogeneous,
    Arg("src"), Arg("dst"));
  
  rb_mCv.define_module_function("convert_points_homogeneous", &cv::convertPointsHomogeneous,
    Arg("src"), Arg("dst"));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, int, double, double, int, cv::OutputArray)>("find_fundamental_mat", &cv::findFundamentalMat,
    Arg("points1"), Arg("points2"), Arg("method"), Arg("ransac_reproj_threshold"), Arg("confidence"), Arg("max_iters"), Arg("mask") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, int, double, double, cv::OutputArray)>("find_fundamental_mat", &cv::findFundamentalMat,
    Arg("points1"), Arg("points2"), Arg("method") = static_cast<int>(cv::FM_RANSAC), Arg("ransac_reproj_threshold") = static_cast<double>(3.), Arg("confidence") = static_cast<double>(0.99), Arg("mask") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, double, double)>("find_fundamental_mat", &cv::findFundamentalMat,
    Arg("points1"), Arg("points2"), Arg("mask"), Arg("method") = static_cast<int>(cv::FM_RANSAC), Arg("ransac_reproj_threshold") = static_cast<double>(3.), Arg("confidence") = static_cast<double>(0.99));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, cv::OutputArray, const cv::UsacParams&)>("find_fundamental_mat", &cv::findFundamentalMat,
    Arg("points1"), Arg("points2"), Arg("mask"), Arg("params"));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, cv::InputArray, int, double, double, int, cv::OutputArray)>("find_essential_mat", &cv::findEssentialMat,
    Arg("points1"), Arg("points2"), Arg("camera_matrix"), Arg("method") = static_cast<int>(cv::RANSAC), Arg("prob") = static_cast<double>(0.999), Arg("threshold") = static_cast<double>(1.0), Arg("max_iters") = static_cast<int>(1000), Arg("mask") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, cv::InputArray, int, double, double, cv::OutputArray)>("find_essential_mat", &cv::findEssentialMat,
    Arg("points1"), Arg("points2"), Arg("camera_matrix"), Arg("method"), Arg("prob"), Arg("threshold"), Arg("mask"));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, double, cv::Point2d, int, double, double, int, cv::OutputArray)>("find_essential_mat", &cv::findEssentialMat,
    Arg("points1"), Arg("points2"), Arg("focal") = static_cast<double>(1.0), Arg("pp") = static_cast<cv::Point2d>(cv::Point2d(0, 0)), Arg("method") = static_cast<int>(cv::RANSAC), Arg("prob") = static_cast<double>(0.999), Arg("threshold") = static_cast<double>(1.0), Arg("max_iters") = static_cast<int>(1000), Arg("mask") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, double, cv::Point2d, int, double, double, cv::OutputArray)>("find_essential_mat", &cv::findEssentialMat,
    Arg("points1"), Arg("points2"), Arg("focal"), Arg("pp"), Arg("method"), Arg("prob"), Arg("threshold"), Arg("mask"));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, int, double, double, cv::OutputArray)>("find_essential_mat", &cv::findEssentialMat,
    Arg("points1"), Arg("points2"), Arg("camera_matrix1"), Arg("dist_coeffs1"), Arg("camera_matrix2"), Arg("dist_coeffs2"), Arg("method") = static_cast<int>(cv::RANSAC), Arg("prob") = static_cast<double>(0.999), Arg("threshold") = static_cast<double>(1.0), Arg("mask") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, const cv::UsacParams&)>("find_essential_mat", &cv::findEssentialMat,
    Arg("points1"), Arg("points2"), Arg("camera_matrix1"), Arg("camera_matrix2"), Arg("dist_coeff1"), Arg("dist_coeff2"), Arg("mask"), Arg("params"));
  
  rb_mCv.define_module_function("decompose_essential_mat", &cv::decomposeEssentialMat,
    Arg("e"), Arg("r1"), Arg("r2"), Arg("t"));
  
  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, int, double, double, cv::InputOutputArray)>("recover_pose", &cv::recoverPose,
    Arg("points1"), Arg("points2"), Arg("camera_matrix1"), Arg("dist_coeffs1"), Arg("camera_matrix2"), Arg("dist_coeffs2"), Arg("e"), Arg("r"), Arg("t"), Arg("method") = static_cast<int>(cv::RANSAC), Arg("prob") = static_cast<double>(0.999), Arg("threshold") = static_cast<double>(1.0), Arg("mask") = static_cast<cv::InputOutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, cv::InputOutputArray)>("recover_pose", &cv::recoverPose,
    Arg("e"), Arg("points1"), Arg("points2"), Arg("camera_matrix"), Arg("r"), Arg("t"), Arg("mask") = static_cast<cv::InputOutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, double, cv::Point2d, cv::InputOutputArray)>("recover_pose", &cv::recoverPose,
    Arg("e"), Arg("points1"), Arg("points2"), Arg("r"), Arg("t"), Arg("focal") = static_cast<double>(1.0), Arg("pp") = static_cast<cv::Point2d>(cv::Point2d(0, 0)), Arg("mask") = static_cast<cv::InputOutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, double, cv::InputOutputArray, cv::OutputArray)>("recover_pose", &cv::recoverPose,
    Arg("e"), Arg("points1"), Arg("points2"), Arg("camera_matrix"), Arg("r"), Arg("t"), Arg("distance_thresh"), Arg("mask") = static_cast<cv::InputOutputArray>(cv::noArray()), Arg("triangulated_points") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function("compute_correspond_epilines", &cv::computeCorrespondEpilines,
    Arg("points"), Arg("which_image"), Arg("f"), Arg("lines"));
  
  rb_mCv.define_module_function("triangulate_points", &cv::triangulatePoints,
    Arg("proj_matr1"), Arg("proj_matr2"), Arg("proj_points1"), Arg("proj_points2"), Arg("points4_d"));
  
  rb_mCv.define_module_function("correct_matches", &cv::correctMatches,
    Arg("f"), Arg("points1"), Arg("points2"), Arg("new_points1"), Arg("new_points2"));
  
  rb_mCv.define_module_function("filter_speckles", &cv::filterSpeckles,
    Arg("img"), Arg("new_val"), Arg("max_speckle_size"), Arg("max_diff"), Arg("buf") = static_cast<cv::InputOutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function("get_valid_disparity_roi", &cv::getValidDisparityROI,
    Arg("roi1"), Arg("roi2"), Arg("min_disparity"), Arg("number_of_disparities"), Arg("block_size"));
  
  rb_mCv.define_module_function("validate_disparity", &cv::validateDisparity,
    Arg("disparity"), Arg("cost"), Arg("min_disparity"), Arg("number_of_disparities"), Arg("disp12_max_disp") = static_cast<int>(1));
  
  rb_mCv.define_module_function("reproject_image_to3_d", &cv::reprojectImageTo3D,
    Arg("disparity"), Arg("_3d_image"), Arg("q"), Arg("handle_missing_values") = static_cast<bool>(false), Arg("ddepth") = static_cast<int>(-1));
  
  rb_mCv.define_module_function("sampson_distance", &cv::sampsonDistance,
    Arg("pt1"), Arg("pt2"), Arg("f"));
  
  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, double, double)>("estimate_affine3_d", &cv::estimateAffine3D,
    Arg("src"), Arg("dst"), Arg("out"), Arg("inliers"), Arg("ransac_threshold") = static_cast<double>(3), Arg("confidence") = static_cast<double>(0.99));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, double*, bool)>("estimate_affine3_d", &cv::estimateAffine3D,
    Arg("src"), Arg("dst"), Arg("scale") = static_cast<double *>(nullptr), Arg("force_rotation") = static_cast<bool>(true));
  
  rb_mCv.define_module_function("estimate_translation3_d", &cv::estimateTranslation3D,
    Arg("src"), Arg("dst"), Arg("out"), Arg("inliers"), Arg("ransac_threshold") = static_cast<double>(3), Arg("confidence") = static_cast<double>(0.99));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, double, ::size_t, double, ::size_t)>("estimate_affine_2d", &cv::estimateAffine2D,
    Arg("from"), Arg("to"), Arg("inliers") = static_cast<cv::OutputArray>(cv::noArray()), Arg("method") = static_cast<int>(cv::RANSAC), Arg("ransac_reproj_threshold") = static_cast<double>(3), Arg("max_iters") = static_cast<size_t>(2000), Arg("confidence") = static_cast<double>(0.99), Arg("refine_iters") = static_cast<size_t>(10));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, cv::OutputArray, const cv::UsacParams&)>("estimate_affine_2d", &cv::estimateAffine2D,
    Arg("pts1"), Arg("pts2"), Arg("inliers"), Arg("params"));
  
  rb_mCv.define_module_function("estimate_affine_partial_2d", &cv::estimateAffinePartial2D,
    Arg("from"), Arg("to"), Arg("inliers") = static_cast<cv::OutputArray>(cv::noArray()), Arg("method") = static_cast<int>(cv::RANSAC), Arg("ransac_reproj_threshold") = static_cast<double>(3), Arg("max_iters") = static_cast<size_t>(2000), Arg("confidence") = static_cast<double>(0.99), Arg("refine_iters") = static_cast<size_t>(10));
  
  rb_mCv.define_module_function("decompose_homography_mat", &cv::decomposeHomographyMat,
    Arg("h"), Arg("k"), Arg("rotations"), Arg("translations"), Arg("normals"));
  
  rb_mCv.define_module_function("filter_homography_decomp_by_visible_refpoints", &cv::filterHomographyDecompByVisibleRefpoints,
    Arg("rotations"), Arg("normals"), Arg("before_points"), Arg("after_points"), Arg("possible_solutions"), Arg("points_mask") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_cCvStereoMatcher = define_class_under<cv::StereoMatcher, cv::Algorithm>(rb_mCv, "StereoMatcher").
    define_method("compute", &cv::StereoMatcher::compute,
      Arg("left"), Arg("right"), Arg("disparity")).
    define_method("get_min_disparity", &cv::StereoMatcher::getMinDisparity).
    define_method("set_min_disparity", &cv::StereoMatcher::setMinDisparity,
      Arg("min_disparity")).
    define_method("get_num_disparities", &cv::StereoMatcher::getNumDisparities).
    define_method("set_num_disparities", &cv::StereoMatcher::setNumDisparities,
      Arg("num_disparities")).
    define_method("get_block_size", &cv::StereoMatcher::getBlockSize).
    define_method("set_block_size", &cv::StereoMatcher::setBlockSize,
      Arg("block_size")).
    define_method("get_speckle_window_size", &cv::StereoMatcher::getSpeckleWindowSize).
    define_method("set_speckle_window_size", &cv::StereoMatcher::setSpeckleWindowSize,
      Arg("speckle_window_size")).
    define_method("get_speckle_range", &cv::StereoMatcher::getSpeckleRange).
    define_method("set_speckle_range", &cv::StereoMatcher::setSpeckleRange,
      Arg("speckle_range")).
    define_method("get_disp12_max_diff", &cv::StereoMatcher::getDisp12MaxDiff).
    define_method("set_disp12_max_diff", &cv::StereoMatcher::setDisp12MaxDiff,
      Arg("disp12_max_diff"));
  
  rb_cCvStereoMatcher.define_constant("DISP_SHIFT", (int)cv::StereoMatcher::DISP_SHIFT);
  rb_cCvStereoMatcher.define_constant("DISP_SCALE", (int)cv::StereoMatcher::DISP_SCALE);
  
  rb_cCvStereoBM = define_class_under<cv::StereoBM, cv::StereoMatcher>(rb_mCv, "StereoBM").
    define_method("get_pre_filter_type", &cv::StereoBM::getPreFilterType).
    define_method("set_pre_filter_type", &cv::StereoBM::setPreFilterType,
      Arg("pre_filter_type")).
    define_method("get_pre_filter_size", &cv::StereoBM::getPreFilterSize).
    define_method("set_pre_filter_size", &cv::StereoBM::setPreFilterSize,
      Arg("pre_filter_size")).
    define_method("get_pre_filter_cap", &cv::StereoBM::getPreFilterCap).
    define_method("set_pre_filter_cap", &cv::StereoBM::setPreFilterCap,
      Arg("pre_filter_cap")).
    define_method("get_texture_threshold", &cv::StereoBM::getTextureThreshold).
    define_method("set_texture_threshold", &cv::StereoBM::setTextureThreshold,
      Arg("texture_threshold")).
    define_method("get_uniqueness_ratio", &cv::StereoBM::getUniquenessRatio).
    define_method("set_uniqueness_ratio", &cv::StereoBM::setUniquenessRatio,
      Arg("uniqueness_ratio")).
    define_method("get_smaller_block_size", &cv::StereoBM::getSmallerBlockSize).
    define_method("set_smaller_block_size", &cv::StereoBM::setSmallerBlockSize,
      Arg("block_size")).
    define_method("get_roi1", &cv::StereoBM::getROI1).
    define_method("set_roi1", &cv::StereoBM::setROI1,
      Arg("roi1")).
    define_method("get_roi2", &cv::StereoBM::getROI2).
    define_method("set_roi2", &cv::StereoBM::setROI2,
      Arg("roi2")).
    define_singleton_function("create", &cv::StereoBM::create,
      Arg("num_disparities") = static_cast<int>(0), Arg("block_size") = static_cast<int>(21));
  
  rb_cCvStereoBM.define_constant("PREFILTER_NORMALIZED_RESPONSE", (int)cv::StereoBM::PREFILTER_NORMALIZED_RESPONSE);
  rb_cCvStereoBM.define_constant("PREFILTER_XSOBEL", (int)cv::StereoBM::PREFILTER_XSOBEL);
  
  rb_cCvStereoSGBM = define_class_under<cv::StereoSGBM, cv::StereoMatcher>(rb_mCv, "StereoSGBM").
    define_method("get_pre_filter_cap", &cv::StereoSGBM::getPreFilterCap).
    define_method("set_pre_filter_cap", &cv::StereoSGBM::setPreFilterCap,
      Arg("pre_filter_cap")).
    define_method("get_uniqueness_ratio", &cv::StereoSGBM::getUniquenessRatio).
    define_method("set_uniqueness_ratio", &cv::StereoSGBM::setUniquenessRatio,
      Arg("uniqueness_ratio")).
    define_method("get_p1", &cv::StereoSGBM::getP1).
    define_method("set_p1", &cv::StereoSGBM::setP1,
      Arg("p1")).
    define_method("get_p2", &cv::StereoSGBM::getP2).
    define_method("set_p2", &cv::StereoSGBM::setP2,
      Arg("p2")).
    define_method("get_mode", &cv::StereoSGBM::getMode).
    define_method("set_mode", &cv::StereoSGBM::setMode,
      Arg("mode")).
    define_singleton_function("create", &cv::StereoSGBM::create,
      Arg("min_disparity") = static_cast<int>(0), Arg("num_disparities") = static_cast<int>(16), Arg("block_size") = static_cast<int>(3), Arg("p1") = static_cast<int>(0), Arg("p2") = static_cast<int>(0), Arg("disp12_max_diff") = static_cast<int>(0), Arg("pre_filter_cap") = static_cast<int>(0), Arg("uniqueness_ratio") = static_cast<int>(0), Arg("speckle_window_size") = static_cast<int>(0), Arg("speckle_range") = static_cast<int>(0), Arg("mode") = static_cast<int>(cv::StereoSGBM::MODE_SGBM));
  
  rb_cCvStereoSGBM.define_constant("MODE_SGBM", (int)cv::StereoSGBM::MODE_SGBM);
  rb_cCvStereoSGBM.define_constant("MODE_HH", (int)cv::StereoSGBM::MODE_HH);
  rb_cCvStereoSGBM.define_constant("MODE_SGBM_3WAY", (int)cv::StereoSGBM::MODE_SGBM_3WAY);
  rb_cCvStereoSGBM.define_constant("MODE_HH4", (int)cv::StereoSGBM::MODE_HH4);
  
  Enum<cv::UndistortTypes> rb_cCvUndistortTypes = define_enum_under<cv::UndistortTypes>("UndistortTypes", rb_mCv).
    define_value("PROJ_SPHERICAL_ORTHO", cv::UndistortTypes::PROJ_SPHERICAL_ORTHO).
    define_value("PROJ_SPHERICAL_EQRECT", cv::UndistortTypes::PROJ_SPHERICAL_EQRECT);
  
  rb_mCv.define_module_function("undistort", &cv::undistort,
    Arg("src"), Arg("dst"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("new_camera_matrix") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function("init_undistort_rectify_map", &cv::initUndistortRectifyMap,
    Arg("camera_matrix"), Arg("dist_coeffs"), Arg("r"), Arg("new_camera_matrix"), Arg("size"), Arg("m1type"), Arg("map1"), Arg("map2"));
  
  rb_mCv.define_module_function("init_inverse_rectification_map", &cv::initInverseRectificationMap,
    Arg("camera_matrix"), Arg("dist_coeffs"), Arg("r"), Arg("new_camera_matrix"), Arg("size"), Arg("m1type"), Arg("map1"), Arg("map2"));
  
  rb_mCv.define_module_function<float(*)(cv::InputArray, cv::InputArray, cv::Size, int, int, cv::OutputArray, cv::OutputArray, cv::UndistortTypes, double)>("init_wide_angle_proj_map", &cv::initWideAngleProjMap,
    Arg("camera_matrix"), Arg("dist_coeffs"), Arg("image_size"), Arg("dest_image_width"), Arg("m1type"), Arg("map1"), Arg("map2"), Arg("proj_type") = static_cast<enum cv::UndistortTypes>(cv::UndistortTypes::PROJ_SPHERICAL_EQRECT), Arg("alpha") = static_cast<double>(0));
  
  rb_mCv.define_module_function<float(*)(cv::InputArray, cv::InputArray, cv::Size, int, int, cv::OutputArray, cv::OutputArray, int, double)>("init_wide_angle_proj_map", &cv::initWideAngleProjMap,
    Arg("camera_matrix"), Arg("dist_coeffs"), Arg("image_size"), Arg("dest_image_width"), Arg("m1type"), Arg("map1"), Arg("map2"), Arg("proj_type"), Arg("alpha") = static_cast<double>(0));
  
  rb_mCv.define_module_function("get_default_new_camera_matrix", &cv::getDefaultNewCameraMatrix,
    Arg("camera_matrix"), Arg("imgsize") = static_cast<cv::Size>(cv::Size()), Arg("center_principal_point") = static_cast<bool>(false));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray)>("undistort_points", &cv::undistortPoints,
    Arg("src"), Arg("dst"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("r") = static_cast<cv::InputArray>(cv::noArray()), Arg("p") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::TermCriteria)>("undistort_points", &cv::undistortPoints,
    Arg("src"), Arg("dst"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("r"), Arg("p"), Arg("criteria"));
  
  rb_mCv.define_module_function("undistort_image_points", &cv::undistortImagePoints,
    Arg("src"), Arg("dst"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::MAX_ITER + cv::TermCriteria::EPS, 5, 0.01)));
  
  Module rb_mCvFisheye = define_module_under(rb_mCv, "Fisheye");
  
  rb_mCvFisheye.define_constant("CALIB_USE_INTRINSIC_GUESS", (int)cv::fisheye::CALIB_USE_INTRINSIC_GUESS);
  rb_mCvFisheye.define_constant("CALIB_RECOMPUTE_EXTRINSIC", (int)cv::fisheye::CALIB_RECOMPUTE_EXTRINSIC);
  rb_mCvFisheye.define_constant("CALIB_CHECK_COND", (int)cv::fisheye::CALIB_CHECK_COND);
  rb_mCvFisheye.define_constant("CALIB_FIX_SKEW", (int)cv::fisheye::CALIB_FIX_SKEW);
  rb_mCvFisheye.define_constant("CALIB_FIX_K1", (int)cv::fisheye::CALIB_FIX_K1);
  rb_mCvFisheye.define_constant("CALIB_FIX_K2", (int)cv::fisheye::CALIB_FIX_K2);
  rb_mCvFisheye.define_constant("CALIB_FIX_K3", (int)cv::fisheye::CALIB_FIX_K3);
  rb_mCvFisheye.define_constant("CALIB_FIX_K4", (int)cv::fisheye::CALIB_FIX_K4);
  rb_mCvFisheye.define_constant("CALIB_FIX_INTRINSIC", (int)cv::fisheye::CALIB_FIX_INTRINSIC);
  rb_mCvFisheye.define_constant("CALIB_FIX_PRINCIPAL_POINT", (int)cv::fisheye::CALIB_FIX_PRINCIPAL_POINT);
  rb_mCvFisheye.define_constant("CALIB_ZERO_DISPARITY", (int)cv::fisheye::CALIB_ZERO_DISPARITY);
  rb_mCvFisheye.define_constant("CALIB_FIX_FOCAL_LENGTH", (int)cv::fisheye::CALIB_FIX_FOCAL_LENGTH);
  
  rb_mCvFisheye.define_module_function<void(*)(cv::InputArray, cv::OutputArray, const cv::Affine3d&, cv::InputArray, cv::InputArray, double, cv::OutputArray)>("project_points", &cv::fisheye::projectPoints,
    Arg("object_points"), Arg("image_points"), Arg("affine"), Arg("k"), Arg("d"), Arg("alpha") = static_cast<double>(0), Arg("jacobian") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCvFisheye.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, double, cv::OutputArray)>("project_points", &cv::fisheye::projectPoints,
    Arg("object_points"), Arg("image_points"), Arg("rvec"), Arg("tvec"), Arg("k"), Arg("d"), Arg("alpha") = static_cast<double>(0), Arg("jacobian") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCvFisheye.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::InputArray, double)>("distort_points", &cv::fisheye::distortPoints,
    Arg("undistorted"), Arg("distorted"), Arg("k"), Arg("d"), Arg("alpha") = static_cast<double>(0));
  
  rb_mCvFisheye.define_module_function("undistort_points", &cv::fisheye::undistortPoints,
    Arg("distorted"), Arg("undistorted"), Arg("k"), Arg("d"), Arg("r") = static_cast<cv::InputArray>(cv::noArray()), Arg("p") = static_cast<cv::InputArray>(cv::noArray()), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::MAX_ITER + cv::TermCriteria::EPS, 10, 1e-8)));
  
  rb_mCvFisheye.define_module_function("init_undistort_rectify_map", &cv::fisheye::initUndistortRectifyMap,
    Arg("k"), Arg("d"), Arg("r"), Arg("p"), Arg("size"), Arg("m1type"), Arg("map1"), Arg("map2"));
  
  rb_mCvFisheye.define_module_function("undistort_image", &cv::fisheye::undistortImage,
    Arg("distorted"), Arg("undistorted"), Arg("k"), Arg("d"), Arg("knew") = static_cast<cv::InputArray>(cv::noArray()), Arg("new_size") = static_cast<const cv::Size &>(cv::Size()));
  
  rb_mCvFisheye.define_module_function("estimate_new_camera_matrix_for_undistort_rectify", &cv::fisheye::estimateNewCameraMatrixForUndistortRectify,
    Arg("k"), Arg("d"), Arg("image_size"), Arg("r"), Arg("p"), Arg("balance") = static_cast<double>(0.0), Arg("new_size") = static_cast<const cv::Size &>(cv::Size()), Arg("fov_scale") = static_cast<double>(1.0));
  
  rb_mCvFisheye.define_module_function("calibrate", &cv::fisheye::calibrate,
    Arg("object_points"), Arg("image_points"), Arg("image_size"), Arg("k"), Arg("d"), Arg("rvecs"), Arg("tvecs"), Arg("flags") = static_cast<int>(0), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 100, DBL_EPSILON)));
  
  rb_mCvFisheye.define_module_function("stereo_rectify", &cv::fisheye::stereoRectify,
    Arg("k1"), Arg("d1"), Arg("k2"), Arg("d2"), Arg("image_size"), Arg("r"), Arg("tvec"), Arg("r1"), Arg("r2"), Arg("p1"), Arg("p2"), Arg("q"), Arg("flags"), Arg("new_image_size") = static_cast<const cv::Size &>(cv::Size()), Arg("balance") = static_cast<double>(0.0), Arg("fov_scale") = static_cast<double>(1.0));
  
#if RUBY_CV_VERSION >= 407
  rb_mCvFisheye.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::Size, cv::OutputArray, cv::OutputArray, cv::OutputArrayOfArrays, cv::OutputArrayOfArrays, int, cv::TermCriteria)>("stereo_calibrate", &cv::fisheye::stereoCalibrate,
    Arg("object_points"), Arg("image_points1"), Arg("image_points2"), Arg("k1"), Arg("d1"), Arg("k2"), Arg("d2"), Arg("image_size"), Arg("r"), Arg("t"), Arg("rvecs"), Arg("tvecs"), Arg("flags") = static_cast<int>(cv::fisheye::CALIB_FIX_INTRINSIC), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 100, DBL_EPSILON)));
#endif

  rb_mCvFisheye.define_module_function<double(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::InputOutputArray, cv::Size, cv::OutputArray, cv::OutputArray, int, cv::TermCriteria)>("stereo_calibrate", &cv::fisheye::stereoCalibrate,
    Arg("object_points"), Arg("image_points1"), Arg("image_points2"), Arg("k1"), Arg("d1"), Arg("k2"), Arg("d2"), Arg("image_size"), Arg("r"), Arg("t"), Arg("flags") = static_cast<int>(cv::fisheye::CALIB_FIX_INTRINSIC), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 100, DBL_EPSILON)));
  
#if RUBY_CV_VERSION >= 410
  rb_mCvFisheye.define_module_function("solve_pn_p?", &cv::fisheye::solvePnP,
    Arg("object_points"), Arg("image_points"), Arg("camera_matrix"), Arg("dist_coeffs"), Arg("rvec"), Arg("tvec"), Arg("use_extrinsic_guess") = static_cast<bool>(false), Arg("flags") = static_cast<int>(cv::SOLVEPNP_ITERATIVE), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::MAX_ITER + cv::TermCriteria::Type::EPS, 10, 1e-8)));
#endif
}