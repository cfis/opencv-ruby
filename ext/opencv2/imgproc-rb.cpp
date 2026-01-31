#include <opencv2/imgproc.hpp>
#include "imgproc-rb.hpp"

using namespace Rice;

void Init_Imgproc()
{
  Module rb_mCv = define_module("Cv");

  Enum<cv::SpecialFilter> rb_cCvSpecialFilter = define_enum_under<cv::SpecialFilter>("SpecialFilter", rb_mCv).
    define_value("FILTER_SCHARR", cv::SpecialFilter::FILTER_SCHARR);

  Enum<cv::MorphTypes> rb_cCvMorphTypes = define_enum_under<cv::MorphTypes>("MorphTypes", rb_mCv).
    define_value("MORPH_ERODE", cv::MorphTypes::MORPH_ERODE).
    define_value("MORPH_DILATE", cv::MorphTypes::MORPH_DILATE).
    define_value("MORPH_OPEN", cv::MorphTypes::MORPH_OPEN).
    define_value("MORPH_CLOSE", cv::MorphTypes::MORPH_CLOSE).
    define_value("MORPH_GRADIENT", cv::MorphTypes::MORPH_GRADIENT).
    define_value("MORPH_TOPHAT", cv::MorphTypes::MORPH_TOPHAT).
    define_value("MORPH_BLACKHAT", cv::MorphTypes::MORPH_BLACKHAT).
    define_value("MORPH_HITMISS", cv::MorphTypes::MORPH_HITMISS);

  Enum<cv::MorphShapes> rb_cCvMorphShapes = define_enum_under<cv::MorphShapes>("MorphShapes", rb_mCv).
    define_value("MORPH_RECT", cv::MorphShapes::MORPH_RECT).
    define_value("MORPH_CROSS", cv::MorphShapes::MORPH_CROSS).
    define_value("MORPH_ELLIPSE", cv::MorphShapes::MORPH_ELLIPSE);

  Enum<cv::InterpolationFlags> rb_cCvInterpolationFlags = define_enum_under<cv::InterpolationFlags>("InterpolationFlags", rb_mCv).
    define_value("INTER_NEAREST", cv::InterpolationFlags::INTER_NEAREST).
    define_value("INTER_LINEAR", cv::InterpolationFlags::INTER_LINEAR).
    define_value("INTER_CUBIC", cv::InterpolationFlags::INTER_CUBIC).
    define_value("INTER_AREA", cv::InterpolationFlags::INTER_AREA).
    define_value("INTER_LANCZOS4", cv::InterpolationFlags::INTER_LANCZOS4).
    define_value("INTER_LINEAR_EXACT", cv::InterpolationFlags::INTER_LINEAR_EXACT).
    define_value("INTER_NEAREST_EXACT", cv::InterpolationFlags::INTER_NEAREST_EXACT).
    define_value("INTER_MAX", cv::InterpolationFlags::INTER_MAX).
    define_value("WARP_FILL_OUTLIERS", cv::InterpolationFlags::WARP_FILL_OUTLIERS).
    define_value("WARP_INVERSE_MAP", cv::InterpolationFlags::WARP_INVERSE_MAP).
    define_value("WARP_RELATIVE_MAP", cv::InterpolationFlags::WARP_RELATIVE_MAP);

  Enum<cv::WarpPolarMode> rb_cCvWarpPolarMode = define_enum_under<cv::WarpPolarMode>("WarpPolarMode", rb_mCv).
    define_value("WARP_POLAR_LINEAR", cv::WarpPolarMode::WARP_POLAR_LINEAR).
    define_value("WARP_POLAR_LOG", cv::WarpPolarMode::WARP_POLAR_LOG);

  Enum<cv::InterpolationMasks> rb_cCvInterpolationMasks = define_enum_under<cv::InterpolationMasks>("InterpolationMasks", rb_mCv).
    define_value("INTER_BITS", cv::InterpolationMasks::INTER_BITS).
    define_value("INTER_BITS2", cv::InterpolationMasks::INTER_BITS2).
    define_value("INTER_TAB_SIZE", cv::InterpolationMasks::INTER_TAB_SIZE).
    define_value("INTER_TAB_SIZE2", cv::InterpolationMasks::INTER_TAB_SIZE2);

  Enum<cv::DistanceTypes> rb_cCvDistanceTypes = define_enum_under<cv::DistanceTypes>("DistanceTypes", rb_mCv).
    define_value("DIST_USER", cv::DistanceTypes::DIST_USER).
    define_value("DIST_L1", cv::DistanceTypes::DIST_L1).
    define_value("DIST_L2", cv::DistanceTypes::DIST_L2).
    define_value("DIST_C", cv::DistanceTypes::DIST_C).
    define_value("DIST_L12", cv::DistanceTypes::DIST_L12).
    define_value("DIST_FAIR", cv::DistanceTypes::DIST_FAIR).
    define_value("DIST_WELSCH", cv::DistanceTypes::DIST_WELSCH).
    define_value("DIST_HUBER", cv::DistanceTypes::DIST_HUBER);

  Enum<cv::DistanceTransformMasks> rb_cCvDistanceTransformMasks = define_enum_under<cv::DistanceTransformMasks>("DistanceTransformMasks", rb_mCv).
    define_value("DIST_MASK_3", cv::DistanceTransformMasks::DIST_MASK_3).
    define_value("DIST_MASK_5", cv::DistanceTransformMasks::DIST_MASK_5).
    define_value("DIST_MASK_PRECISE", cv::DistanceTransformMasks::DIST_MASK_PRECISE);

  Enum<cv::ThresholdTypes> rb_cCvThresholdTypes = define_enum_under<cv::ThresholdTypes>("ThresholdTypes", rb_mCv).
    define_value("THRESH_BINARY", cv::ThresholdTypes::THRESH_BINARY).
    define_value("THRESH_BINARY_INV", cv::ThresholdTypes::THRESH_BINARY_INV).
    define_value("THRESH_TRUNC", cv::ThresholdTypes::THRESH_TRUNC).
    define_value("THRESH_TOZERO", cv::ThresholdTypes::THRESH_TOZERO).
    define_value("THRESH_TOZERO_INV", cv::ThresholdTypes::THRESH_TOZERO_INV).
    define_value("THRESH_MASK", cv::ThresholdTypes::THRESH_MASK).
    define_value("THRESH_OTSU", cv::ThresholdTypes::THRESH_OTSU).
    define_value("THRESH_TRIANGLE", cv::ThresholdTypes::THRESH_TRIANGLE);

  Enum<cv::AdaptiveThresholdTypes> rb_cCvAdaptiveThresholdTypes = define_enum_under<cv::AdaptiveThresholdTypes>("AdaptiveThresholdTypes", rb_mCv).
    define_value("ADAPTIVE_THRESH_MEAN_C", cv::AdaptiveThresholdTypes::ADAPTIVE_THRESH_MEAN_C).
    define_value("ADAPTIVE_THRESH_GAUSSIAN_C", cv::AdaptiveThresholdTypes::ADAPTIVE_THRESH_GAUSSIAN_C);

  Enum<cv::GrabCutClasses> rb_cCvGrabCutClasses = define_enum_under<cv::GrabCutClasses>("GrabCutClasses", rb_mCv).
    define_value("GC_BGD", cv::GrabCutClasses::GC_BGD).
    define_value("GC_FGD", cv::GrabCutClasses::GC_FGD).
    define_value("GC_PR_BGD", cv::GrabCutClasses::GC_PR_BGD).
    define_value("GC_PR_FGD", cv::GrabCutClasses::GC_PR_FGD);

  Enum<cv::GrabCutModes> rb_cCvGrabCutModes = define_enum_under<cv::GrabCutModes>("GrabCutModes", rb_mCv).
    define_value("GC_INIT_WITH_RECT", cv::GrabCutModes::GC_INIT_WITH_RECT).
    define_value("GC_INIT_WITH_MASK", cv::GrabCutModes::GC_INIT_WITH_MASK).
    define_value("GC_EVAL", cv::GrabCutModes::GC_EVAL).
    define_value("GC_EVAL_FREEZE_MODEL", cv::GrabCutModes::GC_EVAL_FREEZE_MODEL);

  Enum<cv::DistanceTransformLabelTypes> rb_cCvDistanceTransformLabelTypes = define_enum_under<cv::DistanceTransformLabelTypes>("DistanceTransformLabelTypes", rb_mCv).
    define_value("DIST_LABEL_CCOMP", cv::DistanceTransformLabelTypes::DIST_LABEL_CCOMP).
    define_value("DIST_LABEL_PIXEL", cv::DistanceTransformLabelTypes::DIST_LABEL_PIXEL);

  Enum<cv::FloodFillFlags> rb_cCvFloodFillFlags = define_enum_under<cv::FloodFillFlags>("FloodFillFlags", rb_mCv).
    define_value("FLOODFILL_FIXED_RANGE", cv::FloodFillFlags::FLOODFILL_FIXED_RANGE).
    define_value("FLOODFILL_MASK_ONLY", cv::FloodFillFlags::FLOODFILL_MASK_ONLY);

  Enum<cv::ConnectedComponentsTypes> rb_cCvConnectedComponentsTypes = define_enum_under<cv::ConnectedComponentsTypes>("ConnectedComponentsTypes", rb_mCv).
    define_value("CC_STAT_LEFT", cv::ConnectedComponentsTypes::CC_STAT_LEFT).
    define_value("CC_STAT_TOP", cv::ConnectedComponentsTypes::CC_STAT_TOP).
    define_value("CC_STAT_WIDTH", cv::ConnectedComponentsTypes::CC_STAT_WIDTH).
    define_value("CC_STAT_HEIGHT", cv::ConnectedComponentsTypes::CC_STAT_HEIGHT).
    define_value("CC_STAT_AREA", cv::ConnectedComponentsTypes::CC_STAT_AREA).
    define_value("CC_STAT_MAX", cv::ConnectedComponentsTypes::CC_STAT_MAX);

  Enum<cv::ConnectedComponentsAlgorithmsTypes> rb_cCvConnectedComponentsAlgorithmsTypes = define_enum_under<cv::ConnectedComponentsAlgorithmsTypes>("ConnectedComponentsAlgorithmsTypes", rb_mCv).
    define_value("CCL_DEFAULT", cv::ConnectedComponentsAlgorithmsTypes::CCL_DEFAULT).
    define_value("CCL_WU", cv::ConnectedComponentsAlgorithmsTypes::CCL_WU).
    define_value("CCL_GRANA", cv::ConnectedComponentsAlgorithmsTypes::CCL_GRANA).
    define_value("CCL_BOLELLI", cv::ConnectedComponentsAlgorithmsTypes::CCL_BOLELLI).
    define_value("CCL_SAUF", cv::ConnectedComponentsAlgorithmsTypes::CCL_SAUF).
    define_value("CCL_BBDT", cv::ConnectedComponentsAlgorithmsTypes::CCL_BBDT).
    define_value("CCL_SPAGHETTI", cv::ConnectedComponentsAlgorithmsTypes::CCL_SPAGHETTI);

  Enum<cv::RetrievalModes> rb_cCvRetrievalModes = define_enum_under<cv::RetrievalModes>("RetrievalModes", rb_mCv).
    define_value("RETR_EXTERNAL", cv::RetrievalModes::RETR_EXTERNAL).
    define_value("RETR_LIST", cv::RetrievalModes::RETR_LIST).
    define_value("RETR_CCOMP", cv::RetrievalModes::RETR_CCOMP).
    define_value("RETR_TREE", cv::RetrievalModes::RETR_TREE).
    define_value("RETR_FLOODFILL", cv::RetrievalModes::RETR_FLOODFILL);

  Enum<cv::ContourApproximationModes> rb_cCvContourApproximationModes = define_enum_under<cv::ContourApproximationModes>("ContourApproximationModes", rb_mCv).
    define_value("CHAIN_APPROX_NONE", cv::ContourApproximationModes::CHAIN_APPROX_NONE).
    define_value("CHAIN_APPROX_SIMPLE", cv::ContourApproximationModes::CHAIN_APPROX_SIMPLE).
    define_value("CHAIN_APPROX_TC89_L1", cv::ContourApproximationModes::CHAIN_APPROX_TC89_L1).
    define_value("CHAIN_APPROX_TC89_KCOS", cv::ContourApproximationModes::CHAIN_APPROX_TC89_KCOS);

  Enum<cv::ShapeMatchModes> rb_cCvShapeMatchModes = define_enum_under<cv::ShapeMatchModes>("ShapeMatchModes", rb_mCv).
    define_value("CONTOURS_MATCH_I1", cv::ShapeMatchModes::CONTOURS_MATCH_I1).
    define_value("CONTOURS_MATCH_I2", cv::ShapeMatchModes::CONTOURS_MATCH_I2).
    define_value("CONTOURS_MATCH_I3", cv::ShapeMatchModes::CONTOURS_MATCH_I3);

  Enum<cv::HoughModes> rb_cCvHoughModes = define_enum_under<cv::HoughModes>("HoughModes", rb_mCv).
    define_value("HOUGH_STANDARD", cv::HoughModes::HOUGH_STANDARD).
    define_value("HOUGH_PROBABILISTIC", cv::HoughModes::HOUGH_PROBABILISTIC).
    define_value("HOUGH_MULTI_SCALE", cv::HoughModes::HOUGH_MULTI_SCALE).
    define_value("HOUGH_GRADIENT", cv::HoughModes::HOUGH_GRADIENT).
    define_value("HOUGH_GRADIENT_ALT", cv::HoughModes::HOUGH_GRADIENT_ALT);

  Enum<cv::LineSegmentDetectorModes> rb_cCvLineSegmentDetectorModes = define_enum_under<cv::LineSegmentDetectorModes>("LineSegmentDetectorModes", rb_mCv).
    define_value("LSD_REFINE_NONE", cv::LineSegmentDetectorModes::LSD_REFINE_NONE).
    define_value("LSD_REFINE_STD", cv::LineSegmentDetectorModes::LSD_REFINE_STD).
    define_value("LSD_REFINE_ADV", cv::LineSegmentDetectorModes::LSD_REFINE_ADV);

  Enum<cv::HistCompMethods> rb_cCvHistCompMethods = define_enum_under<cv::HistCompMethods>("HistCompMethods", rb_mCv).
    define_value("HISTCMP_CORREL", cv::HistCompMethods::HISTCMP_CORREL).
    define_value("HISTCMP_CHISQR", cv::HistCompMethods::HISTCMP_CHISQR).
    define_value("HISTCMP_INTERSECT", cv::HistCompMethods::HISTCMP_INTERSECT).
    define_value("HISTCMP_BHATTACHARYYA", cv::HistCompMethods::HISTCMP_BHATTACHARYYA).
    define_value("HISTCMP_HELLINGER", cv::HistCompMethods::HISTCMP_HELLINGER).
    define_value("HISTCMP_CHISQR_ALT", cv::HistCompMethods::HISTCMP_CHISQR_ALT).
    define_value("HISTCMP_KL_DIV", cv::HistCompMethods::HISTCMP_KL_DIV);

  Enum<cv::ColorConversionCodes> rb_cCvColorConversionCodes = define_enum_under<cv::ColorConversionCodes>("ColorConversionCodes", rb_mCv).
    define_value("COLOR_BGR2BGRA", cv::ColorConversionCodes::COLOR_BGR2BGRA).
    define_value("COLOR_RGB2RGBA", cv::ColorConversionCodes::COLOR_RGB2RGBA).
    define_value("COLOR_BGRA2BGR", cv::ColorConversionCodes::COLOR_BGRA2BGR).
    define_value("COLOR_RGBA2RGB", cv::ColorConversionCodes::COLOR_RGBA2RGB).
    define_value("COLOR_BGR2RGBA", cv::ColorConversionCodes::COLOR_BGR2RGBA).
    define_value("COLOR_RGB2BGRA", cv::ColorConversionCodes::COLOR_RGB2BGRA).
    define_value("COLOR_RGBA2BGR", cv::ColorConversionCodes::COLOR_RGBA2BGR).
    define_value("COLOR_BGRA2RGB", cv::ColorConversionCodes::COLOR_BGRA2RGB).
    define_value("COLOR_BGR2RGB", cv::ColorConversionCodes::COLOR_BGR2RGB).
    define_value("COLOR_RGB2BGR", cv::ColorConversionCodes::COLOR_RGB2BGR).
    define_value("COLOR_BGRA2RGBA", cv::ColorConversionCodes::COLOR_BGRA2RGBA).
    define_value("COLOR_RGBA2BGRA", cv::ColorConversionCodes::COLOR_RGBA2BGRA).
    define_value("COLOR_BGR2GRAY", cv::ColorConversionCodes::COLOR_BGR2GRAY).
    define_value("COLOR_RGB2GRAY", cv::ColorConversionCodes::COLOR_RGB2GRAY).
    define_value("COLOR_GRAY2BGR", cv::ColorConversionCodes::COLOR_GRAY2BGR).
    define_value("COLOR_GRAY2RGB", cv::ColorConversionCodes::COLOR_GRAY2RGB).
    define_value("COLOR_GRAY2BGRA", cv::ColorConversionCodes::COLOR_GRAY2BGRA).
    define_value("COLOR_GRAY2RGBA", cv::ColorConversionCodes::COLOR_GRAY2RGBA).
    define_value("COLOR_BGRA2GRAY", cv::ColorConversionCodes::COLOR_BGRA2GRAY).
    define_value("COLOR_RGBA2GRAY", cv::ColorConversionCodes::COLOR_RGBA2GRAY).
    define_value("COLOR_BGR2BGR565", cv::ColorConversionCodes::COLOR_BGR2BGR565).
    define_value("COLOR_RGB2BGR565", cv::ColorConversionCodes::COLOR_RGB2BGR565).
    define_value("COLOR_BGR5652BGR", cv::ColorConversionCodes::COLOR_BGR5652BGR).
    define_value("COLOR_BGR5652RGB", cv::ColorConversionCodes::COLOR_BGR5652RGB).
    define_value("COLOR_BGRA2BGR565", cv::ColorConversionCodes::COLOR_BGRA2BGR565).
    define_value("COLOR_RGBA2BGR565", cv::ColorConversionCodes::COLOR_RGBA2BGR565).
    define_value("COLOR_BGR5652BGRA", cv::ColorConversionCodes::COLOR_BGR5652BGRA).
    define_value("COLOR_BGR5652RGBA", cv::ColorConversionCodes::COLOR_BGR5652RGBA).
    define_value("COLOR_GRAY2BGR565", cv::ColorConversionCodes::COLOR_GRAY2BGR565).
    define_value("COLOR_BGR5652GRAY", cv::ColorConversionCodes::COLOR_BGR5652GRAY).
    define_value("COLOR_BGR2BGR555", cv::ColorConversionCodes::COLOR_BGR2BGR555).
    define_value("COLOR_RGB2BGR555", cv::ColorConversionCodes::COLOR_RGB2BGR555).
    define_value("COLOR_BGR5552BGR", cv::ColorConversionCodes::COLOR_BGR5552BGR).
    define_value("COLOR_BGR5552RGB", cv::ColorConversionCodes::COLOR_BGR5552RGB).
    define_value("COLOR_BGRA2BGR555", cv::ColorConversionCodes::COLOR_BGRA2BGR555).
    define_value("COLOR_RGBA2BGR555", cv::ColorConversionCodes::COLOR_RGBA2BGR555).
    define_value("COLOR_BGR5552BGRA", cv::ColorConversionCodes::COLOR_BGR5552BGRA).
    define_value("COLOR_BGR5552RGBA", cv::ColorConversionCodes::COLOR_BGR5552RGBA).
    define_value("COLOR_GRAY2BGR555", cv::ColorConversionCodes::COLOR_GRAY2BGR555).
    define_value("COLOR_BGR5552GRAY", cv::ColorConversionCodes::COLOR_BGR5552GRAY).
    define_value("COLOR_BGR2XYZ", cv::ColorConversionCodes::COLOR_BGR2XYZ).
    define_value("COLOR_RGB2XYZ", cv::ColorConversionCodes::COLOR_RGB2XYZ).
    define_value("COLOR_XYZ2BGR", cv::ColorConversionCodes::COLOR_XYZ2BGR).
    define_value("COLOR_XYZ2RGB", cv::ColorConversionCodes::COLOR_XYZ2RGB).
    define_value("COLOR_BGR2YCrCb", cv::ColorConversionCodes::COLOR_BGR2YCrCb).
    define_value("COLOR_RGB2YCrCb", cv::ColorConversionCodes::COLOR_RGB2YCrCb).
    define_value("COLOR_YCrCb2BGR", cv::ColorConversionCodes::COLOR_YCrCb2BGR).
    define_value("COLOR_YCrCb2RGB", cv::ColorConversionCodes::COLOR_YCrCb2RGB).
    define_value("COLOR_BGR2HSV", cv::ColorConversionCodes::COLOR_BGR2HSV).
    define_value("COLOR_RGB2HSV", cv::ColorConversionCodes::COLOR_RGB2HSV).
    define_value("COLOR_BGR2Lab", cv::ColorConversionCodes::COLOR_BGR2Lab).
    define_value("COLOR_RGB2Lab", cv::ColorConversionCodes::COLOR_RGB2Lab).
    define_value("COLOR_BGR2Luv", cv::ColorConversionCodes::COLOR_BGR2Luv).
    define_value("COLOR_RGB2Luv", cv::ColorConversionCodes::COLOR_RGB2Luv).
    define_value("COLOR_BGR2HLS", cv::ColorConversionCodes::COLOR_BGR2HLS).
    define_value("COLOR_RGB2HLS", cv::ColorConversionCodes::COLOR_RGB2HLS).
    define_value("COLOR_HSV2BGR", cv::ColorConversionCodes::COLOR_HSV2BGR).
    define_value("COLOR_HSV2RGB", cv::ColorConversionCodes::COLOR_HSV2RGB).
    define_value("COLOR_Lab2BGR", cv::ColorConversionCodes::COLOR_Lab2BGR).
    define_value("COLOR_Lab2RGB", cv::ColorConversionCodes::COLOR_Lab2RGB).
    define_value("COLOR_Luv2BGR", cv::ColorConversionCodes::COLOR_Luv2BGR).
    define_value("COLOR_Luv2RGB", cv::ColorConversionCodes::COLOR_Luv2RGB).
    define_value("COLOR_HLS2BGR", cv::ColorConversionCodes::COLOR_HLS2BGR).
    define_value("COLOR_HLS2RGB", cv::ColorConversionCodes::COLOR_HLS2RGB).
    define_value("COLOR_BGR2HSV_FULL", cv::ColorConversionCodes::COLOR_BGR2HSV_FULL).
    define_value("COLOR_RGB2HSV_FULL", cv::ColorConversionCodes::COLOR_RGB2HSV_FULL).
    define_value("COLOR_BGR2HLS_FULL", cv::ColorConversionCodes::COLOR_BGR2HLS_FULL).
    define_value("COLOR_RGB2HLS_FULL", cv::ColorConversionCodes::COLOR_RGB2HLS_FULL).
    define_value("COLOR_HSV2BGR_FULL", cv::ColorConversionCodes::COLOR_HSV2BGR_FULL).
    define_value("COLOR_HSV2RGB_FULL", cv::ColorConversionCodes::COLOR_HSV2RGB_FULL).
    define_value("COLOR_HLS2BGR_FULL", cv::ColorConversionCodes::COLOR_HLS2BGR_FULL).
    define_value("COLOR_HLS2RGB_FULL", cv::ColorConversionCodes::COLOR_HLS2RGB_FULL).
    define_value("COLOR_LBGR2Lab", cv::ColorConversionCodes::COLOR_LBGR2Lab).
    define_value("COLOR_LRGB2Lab", cv::ColorConversionCodes::COLOR_LRGB2Lab).
    define_value("COLOR_LBGR2Luv", cv::ColorConversionCodes::COLOR_LBGR2Luv).
    define_value("COLOR_LRGB2Luv", cv::ColorConversionCodes::COLOR_LRGB2Luv).
    define_value("COLOR_Lab2LBGR", cv::ColorConversionCodes::COLOR_Lab2LBGR).
    define_value("COLOR_Lab2LRGB", cv::ColorConversionCodes::COLOR_Lab2LRGB).
    define_value("COLOR_Luv2LBGR", cv::ColorConversionCodes::COLOR_Luv2LBGR).
    define_value("COLOR_Luv2LRGB", cv::ColorConversionCodes::COLOR_Luv2LRGB).
    define_value("COLOR_BGR2YUV", cv::ColorConversionCodes::COLOR_BGR2YUV).
    define_value("COLOR_RGB2YUV", cv::ColorConversionCodes::COLOR_RGB2YUV).
    define_value("COLOR_YUV2BGR", cv::ColorConversionCodes::COLOR_YUV2BGR).
    define_value("COLOR_YUV2RGB", cv::ColorConversionCodes::COLOR_YUV2RGB).
    define_value("COLOR_YUV2RGB_NV12", cv::ColorConversionCodes::COLOR_YUV2RGB_NV12).
    define_value("COLOR_YUV2BGR_NV12", cv::ColorConversionCodes::COLOR_YUV2BGR_NV12).
    define_value("COLOR_YUV2RGB_NV21", cv::ColorConversionCodes::COLOR_YUV2RGB_NV21).
    define_value("COLOR_YUV2BGR_NV21", cv::ColorConversionCodes::COLOR_YUV2BGR_NV21).
    define_value("COLOR_YUV420sp2RGB", cv::ColorConversionCodes::COLOR_YUV420sp2RGB).
    define_value("COLOR_YUV420sp2BGR", cv::ColorConversionCodes::COLOR_YUV420sp2BGR).
    define_value("COLOR_YUV2RGBA_NV12", cv::ColorConversionCodes::COLOR_YUV2RGBA_NV12).
    define_value("COLOR_YUV2BGRA_NV12", cv::ColorConversionCodes::COLOR_YUV2BGRA_NV12).
    define_value("COLOR_YUV2RGBA_NV21", cv::ColorConversionCodes::COLOR_YUV2RGBA_NV21).
    define_value("COLOR_YUV2BGRA_NV21", cv::ColorConversionCodes::COLOR_YUV2BGRA_NV21).
    define_value("COLOR_YUV420sp2RGBA", cv::ColorConversionCodes::COLOR_YUV420sp2RGBA).
    define_value("COLOR_YUV420sp2BGRA", cv::ColorConversionCodes::COLOR_YUV420sp2BGRA).
    define_value("COLOR_YUV2RGB_YV12", cv::ColorConversionCodes::COLOR_YUV2RGB_YV12).
    define_value("COLOR_YUV2BGR_YV12", cv::ColorConversionCodes::COLOR_YUV2BGR_YV12).
    define_value("COLOR_YUV2RGB_IYUV", cv::ColorConversionCodes::COLOR_YUV2RGB_IYUV).
    define_value("COLOR_YUV2BGR_IYUV", cv::ColorConversionCodes::COLOR_YUV2BGR_IYUV).
    define_value("COLOR_YUV2RGB_I420", cv::ColorConversionCodes::COLOR_YUV2RGB_I420).
    define_value("COLOR_YUV2BGR_I420", cv::ColorConversionCodes::COLOR_YUV2BGR_I420).
    define_value("COLOR_YUV420p2RGB", cv::ColorConversionCodes::COLOR_YUV420p2RGB).
    define_value("COLOR_YUV420p2BGR", cv::ColorConversionCodes::COLOR_YUV420p2BGR).
    define_value("COLOR_YUV2RGBA_YV12", cv::ColorConversionCodes::COLOR_YUV2RGBA_YV12).
    define_value("COLOR_YUV2BGRA_YV12", cv::ColorConversionCodes::COLOR_YUV2BGRA_YV12).
    define_value("COLOR_YUV2RGBA_IYUV", cv::ColorConversionCodes::COLOR_YUV2RGBA_IYUV).
    define_value("COLOR_YUV2BGRA_IYUV", cv::ColorConversionCodes::COLOR_YUV2BGRA_IYUV).
    define_value("COLOR_YUV2RGBA_I420", cv::ColorConversionCodes::COLOR_YUV2RGBA_I420).
    define_value("COLOR_YUV2BGRA_I420", cv::ColorConversionCodes::COLOR_YUV2BGRA_I420).
    define_value("COLOR_YUV420p2RGBA", cv::ColorConversionCodes::COLOR_YUV420p2RGBA).
    define_value("COLOR_YUV420p2BGRA", cv::ColorConversionCodes::COLOR_YUV420p2BGRA).
    define_value("COLOR_YUV2GRAY_420", cv::ColorConversionCodes::COLOR_YUV2GRAY_420).
    define_value("COLOR_YUV2GRAY_NV21", cv::ColorConversionCodes::COLOR_YUV2GRAY_NV21).
    define_value("COLOR_YUV2GRAY_NV12", cv::ColorConversionCodes::COLOR_YUV2GRAY_NV12).
    define_value("COLOR_YUV2GRAY_YV12", cv::ColorConversionCodes::COLOR_YUV2GRAY_YV12).
    define_value("COLOR_YUV2GRAY_IYUV", cv::ColorConversionCodes::COLOR_YUV2GRAY_IYUV).
    define_value("COLOR_YUV2GRAY_I420", cv::ColorConversionCodes::COLOR_YUV2GRAY_I420).
    define_value("COLOR_YUV420sp2GRAY", cv::ColorConversionCodes::COLOR_YUV420sp2GRAY).
    define_value("COLOR_YUV420p2GRAY", cv::ColorConversionCodes::COLOR_YUV420p2GRAY).
    define_value("COLOR_YUV2RGB_UYVY", cv::ColorConversionCodes::COLOR_YUV2RGB_UYVY).
    define_value("COLOR_YUV2BGR_UYVY", cv::ColorConversionCodes::COLOR_YUV2BGR_UYVY).
    define_value("COLOR_YUV2RGB_Y422", cv::ColorConversionCodes::COLOR_YUV2RGB_Y422).
    define_value("COLOR_YUV2BGR_Y422", cv::ColorConversionCodes::COLOR_YUV2BGR_Y422).
    define_value("COLOR_YUV2RGB_UYNV", cv::ColorConversionCodes::COLOR_YUV2RGB_UYNV).
    define_value("COLOR_YUV2BGR_UYNV", cv::ColorConversionCodes::COLOR_YUV2BGR_UYNV).
    define_value("COLOR_YUV2RGBA_UYVY", cv::ColorConversionCodes::COLOR_YUV2RGBA_UYVY).
    define_value("COLOR_YUV2BGRA_UYVY", cv::ColorConversionCodes::COLOR_YUV2BGRA_UYVY).
    define_value("COLOR_YUV2RGBA_Y422", cv::ColorConversionCodes::COLOR_YUV2RGBA_Y422).
    define_value("COLOR_YUV2BGRA_Y422", cv::ColorConversionCodes::COLOR_YUV2BGRA_Y422).
    define_value("COLOR_YUV2RGBA_UYNV", cv::ColorConversionCodes::COLOR_YUV2RGBA_UYNV).
    define_value("COLOR_YUV2BGRA_UYNV", cv::ColorConversionCodes::COLOR_YUV2BGRA_UYNV).
    define_value("COLOR_YUV2RGB_YUY2", cv::ColorConversionCodes::COLOR_YUV2RGB_YUY2).
    define_value("COLOR_YUV2BGR_YUY2", cv::ColorConversionCodes::COLOR_YUV2BGR_YUY2).
    define_value("COLOR_YUV2RGB_YVYU", cv::ColorConversionCodes::COLOR_YUV2RGB_YVYU).
    define_value("COLOR_YUV2BGR_YVYU", cv::ColorConversionCodes::COLOR_YUV2BGR_YVYU).
    define_value("COLOR_YUV2RGB_YUYV", cv::ColorConversionCodes::COLOR_YUV2RGB_YUYV).
    define_value("COLOR_YUV2BGR_YUYV", cv::ColorConversionCodes::COLOR_YUV2BGR_YUYV).
    define_value("COLOR_YUV2RGB_YUNV", cv::ColorConversionCodes::COLOR_YUV2RGB_YUNV).
    define_value("COLOR_YUV2BGR_YUNV", cv::ColorConversionCodes::COLOR_YUV2BGR_YUNV).
    define_value("COLOR_YUV2RGBA_YUY2", cv::ColorConversionCodes::COLOR_YUV2RGBA_YUY2).
    define_value("COLOR_YUV2BGRA_YUY2", cv::ColorConversionCodes::COLOR_YUV2BGRA_YUY2).
    define_value("COLOR_YUV2RGBA_YVYU", cv::ColorConversionCodes::COLOR_YUV2RGBA_YVYU).
    define_value("COLOR_YUV2BGRA_YVYU", cv::ColorConversionCodes::COLOR_YUV2BGRA_YVYU).
    define_value("COLOR_YUV2RGBA_YUYV", cv::ColorConversionCodes::COLOR_YUV2RGBA_YUYV).
    define_value("COLOR_YUV2BGRA_YUYV", cv::ColorConversionCodes::COLOR_YUV2BGRA_YUYV).
    define_value("COLOR_YUV2RGBA_YUNV", cv::ColorConversionCodes::COLOR_YUV2RGBA_YUNV).
    define_value("COLOR_YUV2BGRA_YUNV", cv::ColorConversionCodes::COLOR_YUV2BGRA_YUNV).
    define_value("COLOR_YUV2GRAY_UYVY", cv::ColorConversionCodes::COLOR_YUV2GRAY_UYVY).
    define_value("COLOR_YUV2GRAY_YUY2", cv::ColorConversionCodes::COLOR_YUV2GRAY_YUY2).
    define_value("COLOR_YUV2GRAY_Y422", cv::ColorConversionCodes::COLOR_YUV2GRAY_Y422).
    define_value("COLOR_YUV2GRAY_UYNV", cv::ColorConversionCodes::COLOR_YUV2GRAY_UYNV).
    define_value("COLOR_YUV2GRAY_YVYU", cv::ColorConversionCodes::COLOR_YUV2GRAY_YVYU).
    define_value("COLOR_YUV2GRAY_YUYV", cv::ColorConversionCodes::COLOR_YUV2GRAY_YUYV).
    define_value("COLOR_YUV2GRAY_YUNV", cv::ColorConversionCodes::COLOR_YUV2GRAY_YUNV).
    define_value("COLOR_RGBA2mRGBA", cv::ColorConversionCodes::COLOR_RGBA2mRGBA).
    define_value("COLOR_mRGBA2RGBA", cv::ColorConversionCodes::COLOR_mRGBA2RGBA).
    define_value("COLOR_RGB2YUV_I420", cv::ColorConversionCodes::COLOR_RGB2YUV_I420).
    define_value("COLOR_BGR2YUV_I420", cv::ColorConversionCodes::COLOR_BGR2YUV_I420).
    define_value("COLOR_RGB2YUV_IYUV", cv::ColorConversionCodes::COLOR_RGB2YUV_IYUV).
    define_value("COLOR_BGR2YUV_IYUV", cv::ColorConversionCodes::COLOR_BGR2YUV_IYUV).
    define_value("COLOR_RGBA2YUV_I420", cv::ColorConversionCodes::COLOR_RGBA2YUV_I420).
    define_value("COLOR_BGRA2YUV_I420", cv::ColorConversionCodes::COLOR_BGRA2YUV_I420).
    define_value("COLOR_RGBA2YUV_IYUV", cv::ColorConversionCodes::COLOR_RGBA2YUV_IYUV).
    define_value("COLOR_BGRA2YUV_IYUV", cv::ColorConversionCodes::COLOR_BGRA2YUV_IYUV).
    define_value("COLOR_RGB2YUV_YV12", cv::ColorConversionCodes::COLOR_RGB2YUV_YV12).
    define_value("COLOR_BGR2YUV_YV12", cv::ColorConversionCodes::COLOR_BGR2YUV_YV12).
    define_value("COLOR_RGBA2YUV_YV12", cv::ColorConversionCodes::COLOR_RGBA2YUV_YV12).
    define_value("COLOR_BGRA2YUV_YV12", cv::ColorConversionCodes::COLOR_BGRA2YUV_YV12).
    define_value("COLOR_BayerBG2BGR", cv::ColorConversionCodes::COLOR_BayerBG2BGR).
    define_value("COLOR_BayerGB2BGR", cv::ColorConversionCodes::COLOR_BayerGB2BGR).
    define_value("COLOR_BayerRG2BGR", cv::ColorConversionCodes::COLOR_BayerRG2BGR).
    define_value("COLOR_BayerGR2BGR", cv::ColorConversionCodes::COLOR_BayerGR2BGR).
    define_value("COLOR_BayerRGGB2BGR", cv::ColorConversionCodes::COLOR_BayerRGGB2BGR).
    define_value("COLOR_BayerGRBG2BGR", cv::ColorConversionCodes::COLOR_BayerGRBG2BGR).
    define_value("COLOR_BayerBGGR2BGR", cv::ColorConversionCodes::COLOR_BayerBGGR2BGR).
    define_value("COLOR_BayerGBRG2BGR", cv::ColorConversionCodes::COLOR_BayerGBRG2BGR).
    define_value("COLOR_BayerRGGB2RGB", cv::ColorConversionCodes::COLOR_BayerRGGB2RGB).
    define_value("COLOR_BayerGRBG2RGB", cv::ColorConversionCodes::COLOR_BayerGRBG2RGB).
    define_value("COLOR_BayerBGGR2RGB", cv::ColorConversionCodes::COLOR_BayerBGGR2RGB).
    define_value("COLOR_BayerGBRG2RGB", cv::ColorConversionCodes::COLOR_BayerGBRG2RGB).
    define_value("COLOR_BayerBG2RGB", cv::ColorConversionCodes::COLOR_BayerBG2RGB).
    define_value("COLOR_BayerGB2RGB", cv::ColorConversionCodes::COLOR_BayerGB2RGB).
    define_value("COLOR_BayerRG2RGB", cv::ColorConversionCodes::COLOR_BayerRG2RGB).
    define_value("COLOR_BayerGR2RGB", cv::ColorConversionCodes::COLOR_BayerGR2RGB).
    define_value("COLOR_BayerBG2GRAY", cv::ColorConversionCodes::COLOR_BayerBG2GRAY).
    define_value("COLOR_BayerGB2GRAY", cv::ColorConversionCodes::COLOR_BayerGB2GRAY).
    define_value("COLOR_BayerRG2GRAY", cv::ColorConversionCodes::COLOR_BayerRG2GRAY).
    define_value("COLOR_BayerGR2GRAY", cv::ColorConversionCodes::COLOR_BayerGR2GRAY).
    define_value("COLOR_BayerRGGB2GRAY", cv::ColorConversionCodes::COLOR_BayerRGGB2GRAY).
    define_value("COLOR_BayerGRBG2GRAY", cv::ColorConversionCodes::COLOR_BayerGRBG2GRAY).
    define_value("COLOR_BayerBGGR2GRAY", cv::ColorConversionCodes::COLOR_BayerBGGR2GRAY).
    define_value("COLOR_BayerGBRG2GRAY", cv::ColorConversionCodes::COLOR_BayerGBRG2GRAY).
    define_value("COLOR_BayerBG2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerBG2BGR_VNG).
    define_value("COLOR_BayerGB2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerGB2BGR_VNG).
    define_value("COLOR_BayerRG2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerRG2BGR_VNG).
    define_value("COLOR_BayerGR2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerGR2BGR_VNG).
    define_value("COLOR_BayerRGGB2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerRGGB2BGR_VNG).
    define_value("COLOR_BayerGRBG2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerGRBG2BGR_VNG).
    define_value("COLOR_BayerBGGR2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerBGGR2BGR_VNG).
    define_value("COLOR_BayerGBRG2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerGBRG2BGR_VNG).
    define_value("COLOR_BayerRGGB2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerRGGB2RGB_VNG).
    define_value("COLOR_BayerGRBG2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerGRBG2RGB_VNG).
    define_value("COLOR_BayerBGGR2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerBGGR2RGB_VNG).
    define_value("COLOR_BayerGBRG2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerGBRG2RGB_VNG).
    define_value("COLOR_BayerBG2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerBG2RGB_VNG).
    define_value("COLOR_BayerGB2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerGB2RGB_VNG).
    define_value("COLOR_BayerRG2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerRG2RGB_VNG).
    define_value("COLOR_BayerGR2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerGR2RGB_VNG).
    define_value("COLOR_BayerBG2BGR_EA", cv::ColorConversionCodes::COLOR_BayerBG2BGR_EA).
    define_value("COLOR_BayerGB2BGR_EA", cv::ColorConversionCodes::COLOR_BayerGB2BGR_EA).
    define_value("COLOR_BayerRG2BGR_EA", cv::ColorConversionCodes::COLOR_BayerRG2BGR_EA).
    define_value("COLOR_BayerGR2BGR_EA", cv::ColorConversionCodes::COLOR_BayerGR2BGR_EA).
    define_value("COLOR_BayerRGGB2BGR_EA", cv::ColorConversionCodes::COLOR_BayerRGGB2BGR_EA).
    define_value("COLOR_BayerGRBG2BGR_EA", cv::ColorConversionCodes::COLOR_BayerGRBG2BGR_EA).
    define_value("COLOR_BayerBGGR2BGR_EA", cv::ColorConversionCodes::COLOR_BayerBGGR2BGR_EA).
    define_value("COLOR_BayerGBRG2BGR_EA", cv::ColorConversionCodes::COLOR_BayerGBRG2BGR_EA).
    define_value("COLOR_BayerRGGB2RGB_EA", cv::ColorConversionCodes::COLOR_BayerRGGB2RGB_EA).
    define_value("COLOR_BayerGRBG2RGB_EA", cv::ColorConversionCodes::COLOR_BayerGRBG2RGB_EA).
    define_value("COLOR_BayerBGGR2RGB_EA", cv::ColorConversionCodes::COLOR_BayerBGGR2RGB_EA).
    define_value("COLOR_BayerGBRG2RGB_EA", cv::ColorConversionCodes::COLOR_BayerGBRG2RGB_EA).
    define_value("COLOR_BayerBG2RGB_EA", cv::ColorConversionCodes::COLOR_BayerBG2RGB_EA).
    define_value("COLOR_BayerGB2RGB_EA", cv::ColorConversionCodes::COLOR_BayerGB2RGB_EA).
    define_value("COLOR_BayerRG2RGB_EA", cv::ColorConversionCodes::COLOR_BayerRG2RGB_EA).
    define_value("COLOR_BayerGR2RGB_EA", cv::ColorConversionCodes::COLOR_BayerGR2RGB_EA).
    define_value("COLOR_BayerBG2BGRA", cv::ColorConversionCodes::COLOR_BayerBG2BGRA).
    define_value("COLOR_BayerGB2BGRA", cv::ColorConversionCodes::COLOR_BayerGB2BGRA).
    define_value("COLOR_BayerRG2BGRA", cv::ColorConversionCodes::COLOR_BayerRG2BGRA).
    define_value("COLOR_BayerGR2BGRA", cv::ColorConversionCodes::COLOR_BayerGR2BGRA).
    define_value("COLOR_BayerRGGB2BGRA", cv::ColorConversionCodes::COLOR_BayerRGGB2BGRA).
    define_value("COLOR_BayerGRBG2BGRA", cv::ColorConversionCodes::COLOR_BayerGRBG2BGRA).
    define_value("COLOR_BayerBGGR2BGRA", cv::ColorConversionCodes::COLOR_BayerBGGR2BGRA).
    define_value("COLOR_BayerGBRG2BGRA", cv::ColorConversionCodes::COLOR_BayerGBRG2BGRA).
    define_value("COLOR_BayerRGGB2RGBA", cv::ColorConversionCodes::COLOR_BayerRGGB2RGBA).
    define_value("COLOR_BayerGRBG2RGBA", cv::ColorConversionCodes::COLOR_BayerGRBG2RGBA).
    define_value("COLOR_BayerBGGR2RGBA", cv::ColorConversionCodes::COLOR_BayerBGGR2RGBA).
    define_value("COLOR_BayerGBRG2RGBA", cv::ColorConversionCodes::COLOR_BayerGBRG2RGBA).
    define_value("COLOR_BayerBG2RGBA", cv::ColorConversionCodes::COLOR_BayerBG2RGBA).
    define_value("COLOR_BayerGB2RGBA", cv::ColorConversionCodes::COLOR_BayerGB2RGBA).
    define_value("COLOR_BayerRG2RGBA", cv::ColorConversionCodes::COLOR_BayerRG2RGBA).
    define_value("COLOR_BayerGR2RGBA", cv::ColorConversionCodes::COLOR_BayerGR2RGBA).
    define_value("COLOR_RGB2YUV_UYVY", cv::ColorConversionCodes::COLOR_RGB2YUV_UYVY).
    define_value("COLOR_BGR2YUV_UYVY", cv::ColorConversionCodes::COLOR_BGR2YUV_UYVY).
    define_value("COLOR_RGB2YUV_Y422", cv::ColorConversionCodes::COLOR_RGB2YUV_Y422).
    define_value("COLOR_BGR2YUV_Y422", cv::ColorConversionCodes::COLOR_BGR2YUV_Y422).
    define_value("COLOR_RGB2YUV_UYNV", cv::ColorConversionCodes::COLOR_RGB2YUV_UYNV).
    define_value("COLOR_BGR2YUV_UYNV", cv::ColorConversionCodes::COLOR_BGR2YUV_UYNV).
    define_value("COLOR_RGBA2YUV_UYVY", cv::ColorConversionCodes::COLOR_RGBA2YUV_UYVY).
    define_value("COLOR_BGRA2YUV_UYVY", cv::ColorConversionCodes::COLOR_BGRA2YUV_UYVY).
    define_value("COLOR_RGBA2YUV_Y422", cv::ColorConversionCodes::COLOR_RGBA2YUV_Y422).
    define_value("COLOR_BGRA2YUV_Y422", cv::ColorConversionCodes::COLOR_BGRA2YUV_Y422).
    define_value("COLOR_RGBA2YUV_UYNV", cv::ColorConversionCodes::COLOR_RGBA2YUV_UYNV).
    define_value("COLOR_BGRA2YUV_UYNV", cv::ColorConversionCodes::COLOR_BGRA2YUV_UYNV).
    define_value("COLOR_RGB2YUV_YUY2", cv::ColorConversionCodes::COLOR_RGB2YUV_YUY2).
    define_value("COLOR_BGR2YUV_YUY2", cv::ColorConversionCodes::COLOR_BGR2YUV_YUY2).
    define_value("COLOR_RGB2YUV_YVYU", cv::ColorConversionCodes::COLOR_RGB2YUV_YVYU).
    define_value("COLOR_BGR2YUV_YVYU", cv::ColorConversionCodes::COLOR_BGR2YUV_YVYU).
    define_value("COLOR_RGB2YUV_YUYV", cv::ColorConversionCodes::COLOR_RGB2YUV_YUYV).
    define_value("COLOR_BGR2YUV_YUYV", cv::ColorConversionCodes::COLOR_BGR2YUV_YUYV).
    define_value("COLOR_RGB2YUV_YUNV", cv::ColorConversionCodes::COLOR_RGB2YUV_YUNV).
    define_value("COLOR_BGR2YUV_YUNV", cv::ColorConversionCodes::COLOR_BGR2YUV_YUNV).
    define_value("COLOR_RGBA2YUV_YUY2", cv::ColorConversionCodes::COLOR_RGBA2YUV_YUY2).
    define_value("COLOR_BGRA2YUV_YUY2", cv::ColorConversionCodes::COLOR_BGRA2YUV_YUY2).
    define_value("COLOR_RGBA2YUV_YVYU", cv::ColorConversionCodes::COLOR_RGBA2YUV_YVYU).
    define_value("COLOR_BGRA2YUV_YVYU", cv::ColorConversionCodes::COLOR_BGRA2YUV_YVYU).
    define_value("COLOR_RGBA2YUV_YUYV", cv::ColorConversionCodes::COLOR_RGBA2YUV_YUYV).
    define_value("COLOR_BGRA2YUV_YUYV", cv::ColorConversionCodes::COLOR_BGRA2YUV_YUYV).
    define_value("COLOR_RGBA2YUV_YUNV", cv::ColorConversionCodes::COLOR_RGBA2YUV_YUNV).
    define_value("COLOR_BGRA2YUV_YUNV", cv::ColorConversionCodes::COLOR_BGRA2YUV_YUNV).
    define_value("COLOR_COLORCVT_MAX", cv::ColorConversionCodes::COLOR_COLORCVT_MAX);

  Enum<cv::RectanglesIntersectTypes> rb_cCvRectanglesIntersectTypes = define_enum_under<cv::RectanglesIntersectTypes>("RectanglesIntersectTypes", rb_mCv).
    define_value("INTERSECT_NONE", cv::RectanglesIntersectTypes::INTERSECT_NONE).
    define_value("INTERSECT_PARTIAL", cv::RectanglesIntersectTypes::INTERSECT_PARTIAL).
    define_value("INTERSECT_FULL", cv::RectanglesIntersectTypes::INTERSECT_FULL);

  Enum<cv::LineTypes> rb_cCvLineTypes = define_enum_under<cv::LineTypes>("LineTypes", rb_mCv).
    define_value("FILLED", cv::LineTypes::FILLED).
    define_value("LINE_4", cv::LineTypes::LINE_4).
    define_value("LINE_8", cv::LineTypes::LINE_8).
    define_value("LINE_AA", cv::LineTypes::LINE_AA);

  Enum<cv::HersheyFonts> rb_cCvHersheyFonts = define_enum_under<cv::HersheyFonts>("HersheyFonts", rb_mCv).
    define_value("FONT_HERSHEY_SIMPLEX", cv::HersheyFonts::FONT_HERSHEY_SIMPLEX).
    define_value("FONT_HERSHEY_PLAIN", cv::HersheyFonts::FONT_HERSHEY_PLAIN).
    define_value("FONT_HERSHEY_DUPLEX", cv::HersheyFonts::FONT_HERSHEY_DUPLEX).
    define_value("FONT_HERSHEY_COMPLEX", cv::HersheyFonts::FONT_HERSHEY_COMPLEX).
    define_value("FONT_HERSHEY_TRIPLEX", cv::HersheyFonts::FONT_HERSHEY_TRIPLEX).
    define_value("FONT_HERSHEY_COMPLEX_SMALL", cv::HersheyFonts::FONT_HERSHEY_COMPLEX_SMALL).
    define_value("FONT_HERSHEY_SCRIPT_SIMPLEX", cv::HersheyFonts::FONT_HERSHEY_SCRIPT_SIMPLEX).
    define_value("FONT_HERSHEY_SCRIPT_COMPLEX", cv::HersheyFonts::FONT_HERSHEY_SCRIPT_COMPLEX).
    define_value("FONT_ITALIC", cv::HersheyFonts::FONT_ITALIC);

  Enum<cv::MarkerTypes> rb_cCvMarkerTypes = define_enum_under<cv::MarkerTypes>("MarkerTypes", rb_mCv).
    define_value("MARKER_CROSS", cv::MarkerTypes::MARKER_CROSS).
    define_value("MARKER_TILTED_CROSS", cv::MarkerTypes::MARKER_TILTED_CROSS).
    define_value("MARKER_STAR", cv::MarkerTypes::MARKER_STAR).
    define_value("MARKER_DIAMOND", cv::MarkerTypes::MARKER_DIAMOND).
    define_value("MARKER_SQUARE", cv::MarkerTypes::MARKER_SQUARE).
    define_value("MARKER_TRIANGLE_UP", cv::MarkerTypes::MARKER_TRIANGLE_UP).
    define_value("MARKER_TRIANGLE_DOWN", cv::MarkerTypes::MARKER_TRIANGLE_DOWN);

  Rice::Data_Type<cv::GeneralizedHough> rb_cCvGeneralizedHough = define_class_under<cv::GeneralizedHough, cv::Algorithm>(rb_mCv, "GeneralizedHough").
    define_method<void(cv::GeneralizedHough::*)(cv::InputArray, cv::Point)>("set_template", &cv::GeneralizedHough::setTemplate,
      Arg("templ"), Arg("templ_center") = static_cast<cv::Point>(cv::Point(-1, -1))).
    define_method<void(cv::GeneralizedHough::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::Point)>("set_template", &cv::GeneralizedHough::setTemplate,
      Arg("edges"), Arg("dx"), Arg("dy"), Arg("templ_center") = static_cast<cv::Point>(cv::Point(-1, -1))).
    define_method<void(cv::GeneralizedHough::*)(cv::InputArray, cv::OutputArray, cv::OutputArray)>("detect", &cv::GeneralizedHough::detect,
      Arg("image"), Arg("positions"), Arg("votes") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method<void(cv::GeneralizedHough::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("detect", &cv::GeneralizedHough::detect,
      Arg("edges"), Arg("dx"), Arg("dy"), Arg("positions"), Arg("votes") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method<void(cv::GeneralizedHough::*)(int)>("set_canny_low_thresh", &cv::GeneralizedHough::setCannyLowThresh,
      Arg("canny_low_thresh")).
    define_method<int(cv::GeneralizedHough::*)() const>("get_canny_low_thresh", &cv::GeneralizedHough::getCannyLowThresh).
    define_method<void(cv::GeneralizedHough::*)(int)>("set_canny_high_thresh", &cv::GeneralizedHough::setCannyHighThresh,
      Arg("canny_high_thresh")).
    define_method<int(cv::GeneralizedHough::*)() const>("get_canny_high_thresh", &cv::GeneralizedHough::getCannyHighThresh).
    define_method<void(cv::GeneralizedHough::*)(double)>("set_min_dist", &cv::GeneralizedHough::setMinDist,
      Arg("min_dist")).
    define_method<double(cv::GeneralizedHough::*)() const>("get_min_dist", &cv::GeneralizedHough::getMinDist).
    define_method<void(cv::GeneralizedHough::*)(double)>("set_dp", &cv::GeneralizedHough::setDp,
      Arg("dp")).
    define_method<double(cv::GeneralizedHough::*)() const>("get_dp", &cv::GeneralizedHough::getDp).
    define_method<void(cv::GeneralizedHough::*)(int)>("set_max_buffer_size", &cv::GeneralizedHough::setMaxBufferSize,
      Arg("max_buffer_size")).
    define_method<int(cv::GeneralizedHough::*)() const>("get_max_buffer_size", &cv::GeneralizedHough::getMaxBufferSize);

  Rice::Data_Type<cv::GeneralizedHoughBallard> rb_cCvGeneralizedHoughBallard = define_class_under<cv::GeneralizedHoughBallard, cv::GeneralizedHough>(rb_mCv, "GeneralizedHoughBallard").
    define_method<void(cv::GeneralizedHoughBallard::*)(int)>("set_levels", &cv::GeneralizedHoughBallard::setLevels,
      Arg("levels")).
    define_method<int(cv::GeneralizedHoughBallard::*)() const>("get_levels", &cv::GeneralizedHoughBallard::getLevels).
    define_method<void(cv::GeneralizedHoughBallard::*)(int)>("set_votes_threshold", &cv::GeneralizedHoughBallard::setVotesThreshold,
      Arg("votes_threshold")).
    define_method<int(cv::GeneralizedHoughBallard::*)() const>("get_votes_threshold", &cv::GeneralizedHoughBallard::getVotesThreshold);

  Rice::Data_Type<cv::GeneralizedHoughGuil> rb_cCvGeneralizedHoughGuil = define_class_under<cv::GeneralizedHoughGuil, cv::GeneralizedHough>(rb_mCv, "GeneralizedHoughGuil").
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_xi", &cv::GeneralizedHoughGuil::setXi,
      Arg("xi")).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_xi", &cv::GeneralizedHoughGuil::getXi).
    define_method<void(cv::GeneralizedHoughGuil::*)(int)>("set_levels", &cv::GeneralizedHoughGuil::setLevels,
      Arg("levels")).
    define_method<int(cv::GeneralizedHoughGuil::*)() const>("get_levels", &cv::GeneralizedHoughGuil::getLevels).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_angle_epsilon", &cv::GeneralizedHoughGuil::setAngleEpsilon,
      Arg("angle_epsilon")).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_angle_epsilon", &cv::GeneralizedHoughGuil::getAngleEpsilon).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_min_angle", &cv::GeneralizedHoughGuil::setMinAngle,
      Arg("min_angle")).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_min_angle", &cv::GeneralizedHoughGuil::getMinAngle).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_max_angle", &cv::GeneralizedHoughGuil::setMaxAngle,
      Arg("max_angle")).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_max_angle", &cv::GeneralizedHoughGuil::getMaxAngle).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_angle_step", &cv::GeneralizedHoughGuil::setAngleStep,
      Arg("angle_step")).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_angle_step", &cv::GeneralizedHoughGuil::getAngleStep).
    define_method<void(cv::GeneralizedHoughGuil::*)(int)>("set_angle_thresh", &cv::GeneralizedHoughGuil::setAngleThresh,
      Arg("angle_thresh")).
    define_method<int(cv::GeneralizedHoughGuil::*)() const>("get_angle_thresh", &cv::GeneralizedHoughGuil::getAngleThresh).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_min_scale", &cv::GeneralizedHoughGuil::setMinScale,
      Arg("min_scale")).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_min_scale", &cv::GeneralizedHoughGuil::getMinScale).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_max_scale", &cv::GeneralizedHoughGuil::setMaxScale,
      Arg("max_scale")).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_max_scale", &cv::GeneralizedHoughGuil::getMaxScale).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_scale_step", &cv::GeneralizedHoughGuil::setScaleStep,
      Arg("scale_step")).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_scale_step", &cv::GeneralizedHoughGuil::getScaleStep).
    define_method<void(cv::GeneralizedHoughGuil::*)(int)>("set_scale_thresh", &cv::GeneralizedHoughGuil::setScaleThresh,
      Arg("scale_thresh")).
    define_method<int(cv::GeneralizedHoughGuil::*)() const>("get_scale_thresh", &cv::GeneralizedHoughGuil::getScaleThresh).
    define_method<void(cv::GeneralizedHoughGuil::*)(int)>("set_pos_thresh", &cv::GeneralizedHoughGuil::setPosThresh,
      Arg("pos_thresh")).
    define_method<int(cv::GeneralizedHoughGuil::*)() const>("get_pos_thresh", &cv::GeneralizedHoughGuil::getPosThresh);

  Rice::Data_Type<cv::CLAHE> rb_cCvCLAHE = define_class_under<cv::CLAHE, cv::Algorithm>(rb_mCv, "CLAHE").
    define_method<void(cv::CLAHE::*)(cv::InputArray, cv::OutputArray)>("apply", &cv::CLAHE::apply,
      Arg("src"), Arg("dst")).
    define_method<void(cv::CLAHE::*)(double)>("set_clip_limit", &cv::CLAHE::setClipLimit,
      Arg("clip_limit")).
    define_method<double(cv::CLAHE::*)() const>("get_clip_limit", &cv::CLAHE::getClipLimit).
    define_method<void(cv::CLAHE::*)(cv::Size)>("set_tiles_grid_size", &cv::CLAHE::setTilesGridSize,
      Arg("tile_grid_size")).
    define_method<cv::Size(cv::CLAHE::*)() const>("get_tiles_grid_size", &cv::CLAHE::getTilesGridSize).
    define_method<void(cv::CLAHE::*)()>("collect_garbage", &cv::CLAHE::collectGarbage);

  Rice::Data_Type<cv::Subdiv2D> rb_cCvSubdiv2D = define_class_under<cv::Subdiv2D>(rb_mCv, "Subdiv2D").
    define_constructor(Constructor<cv::Subdiv2D>()).
    define_constructor(Constructor<cv::Subdiv2D, cv::Rect>(),
      Arg("rect")).
    define_method<void(cv::Subdiv2D::*)(cv::Rect)>("init_delaunay", &cv::Subdiv2D::initDelaunay,
      Arg("rect")).
    define_method<int(cv::Subdiv2D::*)(cv::Point2f)>("insert", &cv::Subdiv2D::insert,
      Arg("pt")).
    define_method<void(cv::Subdiv2D::*)(const std::vector<cv::Point_<float>>&)>("insert", &cv::Subdiv2D::insert,
      Arg("ptvec")).
    define_method<int(cv::Subdiv2D::*)(cv::Point2f, int&, int&)>("locate", &cv::Subdiv2D::locate,
      Arg("pt"), Arg("edge"), Arg("vertex")).
    define_method<int(cv::Subdiv2D::*)(cv::Point2f, cv::Point2f*)>("find_nearest", &cv::Subdiv2D::findNearest,
      Arg("pt"), Arg("nearest_pt") = static_cast<cv::Point2f*>(0)).
    define_method<void(cv::Subdiv2D::*)(std::vector<cv::Vec<float, 4>>&) const>("get_edge_list", &cv::Subdiv2D::getEdgeList,
      Arg("edge_list")).
    define_method<void(cv::Subdiv2D::*)(std::vector<int>&) const>("get_leading_edge_list", &cv::Subdiv2D::getLeadingEdgeList,
      Arg("leading_edge_list")).
    define_method<void(cv::Subdiv2D::*)(std::vector<cv::Vec<float, 6>>&) const>("get_triangle_list", &cv::Subdiv2D::getTriangleList,
      Arg("triangle_list")).
    define_method<void(cv::Subdiv2D::*)(const std::vector<int>&, std::vector<std::vector<cv::Point_<float>>>&, std::vector<cv::Point_<float>>&)>("get_voronoi_facet_list", &cv::Subdiv2D::getVoronoiFacetList,
      Arg("idx"), Arg("facet_list"), Arg("facet_centers")).
    define_method<cv::Point2f(cv::Subdiv2D::*)(int, int*) const>("get_vertex", &cv::Subdiv2D::getVertex,
      Arg("vertex"), ArgBuffer("first_edge") = static_cast<int*>(0)).
    define_method<int(cv::Subdiv2D::*)(int, int) const>("get_edge", &cv::Subdiv2D::getEdge,
      Arg("edge"), Arg("next_edge_type")).
    define_method<int(cv::Subdiv2D::*)(int) const>("next_edge", &cv::Subdiv2D::nextEdge,
      Arg("edge")).
    define_method<int(cv::Subdiv2D::*)(int, int) const>("rotate_edge", &cv::Subdiv2D::rotateEdge,
      Arg("edge"), Arg("rotate")).
    define_method<int(cv::Subdiv2D::*)(int) const>("sym_edge", &cv::Subdiv2D::symEdge,
      Arg("edge")).
    define_method<int(cv::Subdiv2D::*)(int, cv::Point2f*) const>("edge_org", &cv::Subdiv2D::edgeOrg,
      Arg("edge"), Arg("orgpt") = static_cast<cv::Point2f*>(0)).
    define_method<int(cv::Subdiv2D::*)(int, cv::Point2f*) const>("edge_dst", &cv::Subdiv2D::edgeDst,
      Arg("edge"), Arg("dstpt") = static_cast<cv::Point2f*>(0));

  rb_cCvSubdiv2D.define_constant("PTLOC_ERROR", (int)cv::Subdiv2D::PTLOC_ERROR);
  rb_cCvSubdiv2D.define_constant("PTLOC_OUTSIDE_RECT", (int)cv::Subdiv2D::PTLOC_OUTSIDE_RECT);
  rb_cCvSubdiv2D.define_constant("PTLOC_INSIDE", (int)cv::Subdiv2D::PTLOC_INSIDE);
  rb_cCvSubdiv2D.define_constant("PTLOC_VERTEX", (int)cv::Subdiv2D::PTLOC_VERTEX);
  rb_cCvSubdiv2D.define_constant("PTLOC_ON_EDGE", (int)cv::Subdiv2D::PTLOC_ON_EDGE);

  rb_cCvSubdiv2D.define_constant("NEXT_AROUND_ORG", (int)cv::Subdiv2D::NEXT_AROUND_ORG);
  rb_cCvSubdiv2D.define_constant("NEXT_AROUND_DST", (int)cv::Subdiv2D::NEXT_AROUND_DST);
  rb_cCvSubdiv2D.define_constant("PREV_AROUND_ORG", (int)cv::Subdiv2D::PREV_AROUND_ORG);
  rb_cCvSubdiv2D.define_constant("PREV_AROUND_DST", (int)cv::Subdiv2D::PREV_AROUND_DST);
  rb_cCvSubdiv2D.define_constant("NEXT_AROUND_LEFT", (int)cv::Subdiv2D::NEXT_AROUND_LEFT);
  rb_cCvSubdiv2D.define_constant("NEXT_AROUND_RIGHT", (int)cv::Subdiv2D::NEXT_AROUND_RIGHT);
  rb_cCvSubdiv2D.define_constant("PREV_AROUND_LEFT", (int)cv::Subdiv2D::PREV_AROUND_LEFT);
  rb_cCvSubdiv2D.define_constant("PREV_AROUND_RIGHT", (int)cv::Subdiv2D::PREV_AROUND_RIGHT);

  Rice::Data_Type<cv::LineSegmentDetector> rb_cCvLineSegmentDetector = define_class_under<cv::LineSegmentDetector, cv::Algorithm>(rb_mCv, "LineSegmentDetector").
    define_method<void(cv::LineSegmentDetector::*)(cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray)>("detect", &cv::LineSegmentDetector::detect,
      Arg("image"), Arg("lines"), Arg("width") = static_cast<cv::OutputArray>(cv::noArray()), Arg("prec") = static_cast<cv::OutputArray>(cv::noArray()), Arg("nfa") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method<void(cv::LineSegmentDetector::*)(cv::InputOutputArray, cv::InputArray)>("draw_segments", &cv::LineSegmentDetector::drawSegments,
      Arg("image"), Arg("lines")).
    define_method<int(cv::LineSegmentDetector::*)(const cv::Size&, cv::InputArray, cv::InputArray, cv::InputOutputArray)>("compare_segments", &cv::LineSegmentDetector::compareSegments,
      Arg("size"), Arg("lines1"), Arg("lines2"), Arg("image") = static_cast<cv::InputOutputArray>(cv::noArray()));

  rb_mCv.define_module_function<cv::Ptr<cv::LineSegmentDetector>(*)(int, double, double, double, double, double, double, int)>("create_line_segment_detector", &cv::createLineSegmentDetector,
    Arg("refine") = static_cast<int>(cv::LSD_REFINE_STD), Arg("scale") = static_cast<double>(0.8), Arg("sigma_scale") = static_cast<double>(0.6), Arg("quant") = static_cast<double>(2.0), Arg("ang_th") = static_cast<double>(22.5), Arg("log_eps") = static_cast<double>(0), Arg("density_th") = static_cast<double>(0.7), Arg("n_bins") = static_cast<int>(1024));

  rb_mCv.define_module_function<cv::Mat(*)(int, double, int)>("get_gaussian_kernel", &cv::getGaussianKernel,
    Arg("ksize"), Arg("sigma"), Arg("ktype") = static_cast<int>(CV_64F));

  rb_mCv.define_module_function<void(*)(cv::OutputArray, cv::OutputArray, int, int, int, bool, int)>("get_deriv_kernels", &cv::getDerivKernels,
    Arg("kx"), Arg("ky"), Arg("dx"), Arg("dy"), Arg("ksize"), Arg("normalize") = static_cast<bool>(false), Arg("ktype") = static_cast<int>(CV_32F));

  rb_mCv.define_module_function<cv::Mat(*)(cv::Size, double, double, double, double, double, int)>("get_gabor_kernel", &cv::getGaborKernel,
    Arg("ksize"), Arg("sigma"), Arg("theta"), Arg("lambd"), Arg("gamma"), Arg("psi"), Arg("ktype") = static_cast<int>(CV_64F));

  rb_mCv.define_module_function<cv::Scalar(*)()>("morphology_default_border_value", &cv::morphologyDefaultBorderValue);

  rb_mCv.define_module_function<cv::Mat(*)(int, cv::Size, cv::Point)>("get_structuring_element", &cv::getStructuringElement,
    Arg("shape"), Arg("ksize"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int)>("median_blur", &cv::medianBlur,
    Arg("src"), Arg("dst"), Arg("ksize"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::Size, double, double, int, cv::AlgorithmHint)>("gaussian_blur", &cv::GaussianBlur,
    Arg("src"), Arg("dst"), Arg("ksize"), Arg("sigma_x"), Arg("sigma_y") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT), Arg("hint") = static_cast<cv::AlgorithmHint>(cv::ALGO_HINT_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, double, double, int)>("bilateral_filter", &cv::bilateralFilter,
    Arg("src"), Arg("dst"), Arg("d"), Arg("sigma_color"), Arg("sigma_space"), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, cv::Size, cv::Point, bool, int)>("box_filter", &cv::boxFilter,
    Arg("src"), Arg("dst"), Arg("ddepth"), Arg("ksize"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("normalize") = static_cast<bool>(true), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, cv::Size, cv::Point, bool, int)>("sqr_box_filter", &cv::sqrBoxFilter,
    Arg("src"), Arg("dst"), Arg("ddepth"), Arg("ksize"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1, -1)), Arg("normalize") = static_cast<bool>(true), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::Size, cv::Point, int)>("blur", &cv::blur,
    Arg("src"), Arg("dst"), Arg("ksize"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::Size)>("stack_blur", &cv::stackBlur,
    Arg("src"), Arg("dst"), Arg("ksize"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, cv::InputArray, cv::Point, double, int)>("filter_2d", &cv::filter2D,
    Arg("src"), Arg("dst"), Arg("ddepth"), Arg("kernel"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("delta") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, cv::InputArray, cv::InputArray, cv::Point, double, int)>("sep_filter_2d", &cv::sepFilter2D,
    Arg("src"), Arg("dst"), Arg("ddepth"), Arg("kernel_x"), Arg("kernel_y"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("delta") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, int, int, double, double, int)>("sobel", &cv::Sobel,
    Arg("src"), Arg("dst"), Arg("ddepth"), Arg("dx"), Arg("dy"), Arg("ksize") = static_cast<int>(3), Arg("scale") = static_cast<double>(1), Arg("delta") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, int, int)>("spatial_gradient", &cv::spatialGradient,
    Arg("src"), Arg("dx"), Arg("dy"), Arg("ksize") = static_cast<int>(3), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, int, double, double, int)>("scharr", &cv::Scharr,
    Arg("src"), Arg("dst"), Arg("ddepth"), Arg("dx"), Arg("dy"), Arg("scale") = static_cast<double>(1), Arg("delta") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, double, double, int)>("laplacian", &cv::Laplacian,
    Arg("src"), Arg("dst"), Arg("ddepth"), Arg("ksize") = static_cast<int>(1), Arg("scale") = static_cast<double>(1), Arg("delta") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, double, int, bool)>("canny", &cv::Canny,
    Arg("image"), Arg("edges"), Arg("threshold1"), Arg("threshold2"), Arg("aperture_size") = static_cast<int>(3), Arg("l2gradient") = static_cast<bool>(false));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, double, double, bool)>("canny", &cv::Canny,
    Arg("dx"), Arg("dy"), Arg("edges"), Arg("threshold1"), Arg("threshold2"), Arg("l2gradient") = static_cast<bool>(false));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, int)>("corner_min_eigen_val", &cv::cornerMinEigenVal,
    Arg("src"), Arg("dst"), Arg("block_size"), Arg("ksize") = static_cast<int>(3), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, double, int)>("corner_harris", &cv::cornerHarris,
    Arg("src"), Arg("dst"), Arg("block_size"), Arg("ksize"), Arg("k"), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, int)>("corner_eigen_vals_and_vecs", &cv::cornerEigenValsAndVecs,
    Arg("src"), Arg("dst"), Arg("block_size"), Arg("ksize"), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int)>("pre_corner_detect", &cv::preCornerDetect,
    Arg("src"), Arg("dst"), Arg("ksize"), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::Size, cv::Size, cv::TermCriteria)>("corner_sub_pix", &cv::cornerSubPix,
    Arg("image"), Arg("corners"), Arg("win_size"), Arg("zero_zone"), Arg("criteria"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, double, double, cv::InputArray, int, bool, double)>("good_features_to_track", &cv::goodFeaturesToTrack,
    Arg("image"), Arg("corners"), Arg("max_corners"), Arg("quality_level"), Arg("min_distance"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("block_size") = static_cast<int>(3), Arg("use_harris_detector") = static_cast<bool>(false), Arg("k") = static_cast<double>(0.04));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, double, double, cv::InputArray, int, int, bool, double)>("good_features_to_track", &cv::goodFeaturesToTrack,
    Arg("image"), Arg("corners"), Arg("max_corners"), Arg("quality_level"), Arg("min_distance"), Arg("mask"), Arg("block_size"), Arg("gradient_size"), Arg("use_harris_detector") = static_cast<bool>(false), Arg("k") = static_cast<double>(0.04));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, double, double, cv::InputArray, cv::OutputArray, int, int, bool, double)>("good_features_to_track", &cv::goodFeaturesToTrack,
    Arg("image"), Arg("corners"), Arg("max_corners"), Arg("quality_level"), Arg("min_distance"), Arg("mask"), Arg("corners_quality"), Arg("block_size") = static_cast<int>(3), Arg("gradient_size") = static_cast<int>(3), Arg("use_harris_detector") = static_cast<bool>(false), Arg("k") = static_cast<double>(0.04));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, double, int, double, double, double, double, bool)>("hough_lines", &cv::HoughLines,
    Arg("image"), Arg("lines"), Arg("rho"), Arg("theta"), Arg("threshold"), Arg("srn") = static_cast<double>(0), Arg("stn") = static_cast<double>(0), Arg("min_theta") = static_cast<double>(0), Arg("max_theta") = static_cast<double>(CV_PI), Arg("use_edgeval") = static_cast<bool>(false));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, double, int, double, double)>("hough_lines_p", &cv::HoughLinesP,
    Arg("image"), Arg("lines"), Arg("rho"), Arg("theta"), Arg("threshold"), Arg("min_line_length") = static_cast<double>(0), Arg("max_line_gap") = static_cast<double>(0));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, double, double, double, double, double, double)>("hough_lines_point_set", &cv::HoughLinesPointSet,
    Arg("point"), Arg("lines"), Arg("lines_max"), Arg("threshold"), Arg("min_rho"), Arg("max_rho"), Arg("rho_step"), Arg("min_theta"), Arg("max_theta"), Arg("theta_step"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, double, double, double, double, int, int)>("hough_circles", &cv::HoughCircles,
    Arg("image"), Arg("circles"), Arg("method"), Arg("dp"), Arg("min_dist"), Arg("param1") = static_cast<double>(100), Arg("param2") = static_cast<double>(100), Arg("min_radius") = static_cast<int>(0), Arg("max_radius") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::Point, int, int, const cv::Scalar&)>("erode", &cv::erode,
    Arg("src"), Arg("dst"), Arg("kernel"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("iterations") = static_cast<int>(1), Arg("border_type") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar&>(cv::morphologyDefaultBorderValue()));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::Point, int, int, const cv::Scalar&)>("dilate", &cv::dilate,
    Arg("src"), Arg("dst"), Arg("kernel"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("iterations") = static_cast<int>(1), Arg("border_type") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar&>(cv::morphologyDefaultBorderValue()));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, cv::InputArray, cv::Point, int, int, const cv::Scalar&)>("morphology_ex", &cv::morphologyEx,
    Arg("src"), Arg("dst"), Arg("op"), Arg("kernel"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("iterations") = static_cast<int>(1), Arg("border_type") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar&>(cv::morphologyDefaultBorderValue()));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::Size, double, double, int)>("resize", &cv::resize,
    Arg("src"), Arg("dst"), Arg("dsize"), Arg("fx") = static_cast<double>(0), Arg("fy") = static_cast<double>(0), Arg("interpolation") = static_cast<int>(cv::INTER_LINEAR));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::Size, int, int, const cv::Scalar&)>("warp_affine", &cv::warpAffine,
    Arg("src"), Arg("dst"), Arg("m"), Arg("dsize"), Arg("flags") = static_cast<int>(cv::INTER_LINEAR), Arg("border_mode") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar&>(cv::Scalar()));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::Size, int, int, const cv::Scalar&)>("warp_perspective", &cv::warpPerspective,
    Arg("src"), Arg("dst"), Arg("m"), Arg("dsize"), Arg("flags") = static_cast<int>(cv::INTER_LINEAR), Arg("border_mode") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar&>(cv::Scalar()));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::InputArray, int, int, const cv::Scalar&)>("remap", &cv::remap,
    Arg("src"), Arg("dst"), Arg("map1"), Arg("map2"), Arg("interpolation"), Arg("border_mode") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar&>(cv::Scalar()));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, int, bool)>("convert_maps", &cv::convertMaps,
    Arg("map1"), Arg("map2"), Arg("dstmap1"), Arg("dstmap2"), Arg("dstmap1type"), Arg("nninterpolation") = static_cast<bool>(false));

  rb_mCv.define_module_function<cv::Mat(*)(cv::Point2f, double, double)>("get_rotation_matrix_2d", &cv::getRotationMatrix2D,
    Arg("center"), Arg("angle"), Arg("scale"));

  rb_mCv.define_module_function<cv::Mat(*)(cv::Point2f, double, double)>("get_rotation_matrix_2d", &cv::getRotationMatrix2D,
    Arg("center"), Arg("angle"), Arg("scale"));

  rb_mCv.define_module_function<cv::Mat(*)(const cv::Point2f[], const cv::Point2f[])>("get_affine_transform", &cv::getAffineTransform,
    Arg("src"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray)>("invert_affine_transform", &cv::invertAffineTransform,
    Arg("m"), Arg("i_m"));

  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, int)>("get_perspective_transform", &cv::getPerspectiveTransform,
    Arg("src"), Arg("dst"), Arg("solve_method") = static_cast<int>(cv::DECOMP_LU));

  rb_mCv.define_module_function<cv::Mat(*)(const cv::Point2f[], const cv::Point2f[], int)>("get_perspective_transform", &cv::getPerspectiveTransform,
    Arg("src"), Arg("dst"), Arg("solve_method") = static_cast<int>(cv::DECOMP_LU));

  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray)>("get_affine_transform", &cv::getAffineTransform,
    Arg("src"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::Size, cv::Point2f, cv::OutputArray, int)>("get_rect_sub_pix", &cv::getRectSubPix,
    Arg("image"), Arg("patch_size"), Arg("center"), Arg("patch"), Arg("patch_type") = static_cast<int>(-1));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::Point2f, double, int)>("log_polar", &cv::logPolar,
    Arg("src"), Arg("dst"), Arg("center"), Arg("m"), Arg("flags"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::Point2f, double, int)>("linear_polar", &cv::linearPolar,
    Arg("src"), Arg("dst"), Arg("center"), Arg("max_radius"), Arg("flags"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::Size, cv::Point2f, double, int)>("warp_polar", &cv::warpPolar,
    Arg("src"), Arg("dst"), Arg("dsize"), Arg("center"), Arg("max_radius"), Arg("flags"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, int, int)>("integral", &cv::integral,
    Arg("src"), Arg("sum"), Arg("sqsum"), Arg("tilted"), Arg("sdepth") = static_cast<int>(-1), Arg("sqdepth") = static_cast<int>(-1));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int)>("integral", &cv::integral,
    Arg("src"), Arg("sum"), Arg("sdepth") = static_cast<int>(-1));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, int, int)>("integral", &cv::integral,
    Arg("src"), Arg("sum"), Arg("sqsum"), Arg("sdepth") = static_cast<int>(-1), Arg("sqdepth") = static_cast<int>(-1));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::InputArray)>("accumulate", &cv::accumulate,
    Arg("src"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::InputArray)>("accumulate_square", &cv::accumulateSquare,
    Arg("src"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::InputArray)>("accumulate_product", &cv::accumulateProduct,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, double, cv::InputArray)>("accumulate_weighted", &cv::accumulateWeighted,
    Arg("src"), Arg("dst"), Arg("alpha"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function<cv::Point2d(*)(cv::InputArray, cv::InputArray, cv::InputArray, double*)>("phase_correlate", &cv::phaseCorrelate,
    Arg("src1"), Arg("src2"), Arg("window") = static_cast<cv::InputArray>(cv::noArray()), ArgBuffer("response") = static_cast<double*>(0));

  rb_mCv.define_module_function<void(*)(cv::OutputArray, cv::Size, int)>("create_hanning_window", &cv::createHanningWindow,
    Arg("dst"), Arg("win_size"), Arg("type"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, bool)>("div_spectrums", &cv::divSpectrums,
    Arg("a"), Arg("b"), Arg("c"), Arg("flags"), Arg("conj_b") = static_cast<bool>(false));

  rb_mCv.define_module_function<double(*)(cv::InputArray, cv::OutputArray, double, double, int)>("threshold", &cv::threshold,
    Arg("src"), Arg("dst"), Arg("thresh"), Arg("maxval"), Arg("type"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, int, int, int, double)>("adaptive_threshold", &cv::adaptiveThreshold,
    Arg("src"), Arg("dst"), Arg("max_value"), Arg("adaptive_method"), Arg("threshold_type"), Arg("block_size"), Arg("c"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, const cv::Size&, int)>("pyr_down", &cv::pyrDown,
    Arg("src"), Arg("dst"), Arg("dstsize") = static_cast<const cv::Size&>(cv::Size()), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, const cv::Size&, int)>("pyr_up", &cv::pyrUp,
    Arg("src"), Arg("dst"), Arg("dstsize") = static_cast<const cv::Size&>(cv::Size()), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArrayOfArrays, int, int)>("build_pyramid", &cv::buildPyramid,
    Arg("src"), Arg("dst"), Arg("maxlevel"), Arg("border_type") = static_cast<int>(cv::BORDER_DEFAULT));

  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, const int*, cv::InputArray, cv::OutputArray, int, const int*, const float**, bool, bool)>("calc_hist", &cv::calcHist,
    Arg("images"), Arg("nimages"), ArgBuffer("channels"), Arg("mask"), Arg("hist"), Arg("dims"), ArgBuffer("hist_size"), ArgBuffer("ranges"), Arg("uniform") = static_cast<bool>(true), Arg("accumulate") = static_cast<bool>(false));

  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, const int*, cv::InputArray, cv::SparseMat&, int, const int*, const float**, bool, bool)>("calc_hist", &cv::calcHist,
    Arg("images"), Arg("nimages"), ArgBuffer("channels"), Arg("mask"), Arg("hist"), Arg("dims"), ArgBuffer("hist_size"), ArgBuffer("ranges"), Arg("uniform") = static_cast<bool>(true), Arg("accumulate") = static_cast<bool>(false));

  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, const std::vector<int>&, cv::InputArray, cv::OutputArray, const std::vector<int>&, const std::vector<float>&, bool)>("calc_hist", &cv::calcHist,
    Arg("images"), Arg("channels"), Arg("mask"), Arg("hist"), Arg("hist_size"), Arg("ranges"), Arg("accumulate") = static_cast<bool>(false));

  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, const int*, cv::InputArray, cv::OutputArray, const float**, double, bool)>("calc_back_project", &cv::calcBackProject,
    Arg("images"), Arg("nimages"), ArgBuffer("channels"), Arg("hist"), Arg("back_project"), ArgBuffer("ranges"), Arg("scale") = static_cast<double>(1), Arg("uniform") = static_cast<bool>(true));

  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, const int*, const cv::SparseMat&, cv::OutputArray, const float**, double, bool)>("calc_back_project", &cv::calcBackProject,
    Arg("images"), Arg("nimages"), ArgBuffer("channels"), Arg("hist"), Arg("back_project"), ArgBuffer("ranges"), Arg("scale") = static_cast<double>(1), Arg("uniform") = static_cast<bool>(true));

  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, const std::vector<int>&, cv::InputArray, cv::OutputArray, const std::vector<float>&, double)>("calc_back_project", &cv::calcBackProject,
    Arg("images"), Arg("channels"), Arg("hist"), Arg("dst"), Arg("ranges"), Arg("scale"));

  rb_mCv.define_module_function<double(*)(cv::InputArray, cv::InputArray, int)>("compare_hist", &cv::compareHist,
    Arg("h1"), Arg("h2"), Arg("method"));

  rb_mCv.define_module_function<double(*)(const cv::SparseMat&, const cv::SparseMat&, int)>("compare_hist", &cv::compareHist,
    Arg("h1"), Arg("h2"), Arg("method"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray)>("equalize_hist", &cv::equalizeHist,
    Arg("src"), Arg("dst"));

  rb_mCv.define_module_function<cv::Ptr<cv::CLAHE>(*)(double, cv::Size)>("create_clahe", &cv::createCLAHE,
    Arg("clip_limit") = static_cast<double>(40.0), Arg("tile_grid_size") = static_cast<cv::Size>(cv::Size(8, 8)));

  rb_mCv.define_module_function<float(*)(cv::InputArray, cv::InputArray, int, cv::InputArray, float*, cv::OutputArray)>("emd", &cv::EMD,
    Arg("signature1"), Arg("signature2"), Arg("dist_type"), Arg("cost") = static_cast<cv::InputArray>(cv::noArray()), ArgBuffer("lower_bound") = static_cast<float*>(0), Arg("flow") = static_cast<cv::OutputArray>(cv::noArray()));

  rb_mCv.define_module_function<float(*)(cv::InputArray, cv::InputArray, int, cv::InputArray, cv::Ptr<float>, cv::OutputArray)>("wrapper_emd", &cv::wrapperEMD,
    Arg("signature1"), Arg("signature2"), Arg("dist_type"), Arg("cost") = static_cast<cv::InputArray>(cv::noArray()), Arg("lower_bound") = static_cast<cv::Ptr<float>>(cv::Ptr<float>()), Arg("flow") = static_cast<cv::OutputArray>(cv::noArray()));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray)>("watershed", &cv::watershed,
    Arg("image"), Arg("markers"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, double, int, cv::TermCriteria)>("pyr_mean_shift_filtering", &cv::pyrMeanShiftFiltering,
    Arg("src"), Arg("dst"), Arg("sp"), Arg("sr"), Arg("max_level") = static_cast<int>(1), Arg("termcrit") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::Type::MAX_ITER+cv::TermCriteria::Type::EPS,5,1)));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::Rect, cv::InputOutputArray, cv::InputOutputArray, int, int)>("grab_cut", &cv::grabCut,
    Arg("img"), Arg("mask"), Arg("rect"), Arg("bgd_model"), Arg("fgd_model"), Arg("iter_count"), Arg("mode") = static_cast<int>(cv::GC_EVAL));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, int, int, int)>("distance_transform", &cv::distanceTransform,
    Arg("src"), Arg("dst"), Arg("labels"), Arg("distance_type"), Arg("mask_size"), Arg("label_type") = static_cast<int>(cv::DIST_LABEL_CCOMP));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, int)>("distance_transform", &cv::distanceTransform,
    Arg("src"), Arg("dst"), Arg("distance_type"), Arg("mask_size"), Arg("dst_type") = static_cast<int>(CV_32F));

  rb_mCv.define_module_function<int(*)(cv::InputOutputArray, cv::InputOutputArray, cv::Point, cv::Scalar, cv::Rect*, cv::Scalar, cv::Scalar, int)>("flood_fill", &cv::floodFill,
    Arg("image"), Arg("mask"), Arg("seed_point"), Arg("new_val"), Arg("rect") = static_cast<cv::Rect*>(0), Arg("lo_diff") = static_cast<cv::Scalar>(cv::Scalar()), Arg("up_diff") = static_cast<cv::Scalar>(cv::Scalar()), Arg("flags") = static_cast<int>(4));

  rb_mCv.define_module_function<int(*)(cv::InputOutputArray, cv::Point, cv::Scalar, cv::Rect*, cv::Scalar, cv::Scalar, int)>("flood_fill", &cv::floodFill,
    Arg("image"), Arg("seed_point"), Arg("new_val"), Arg("rect") = static_cast<cv::Rect*>(0), Arg("lo_diff") = static_cast<cv::Scalar>(cv::Scalar()), Arg("up_diff") = static_cast<cv::Scalar>(cv::Scalar()), Arg("flags") = static_cast<int>(4));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray)>("blend_linear", &cv::blendLinear,
    Arg("src1"), Arg("src2"), Arg("weights1"), Arg("weights2"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, cv::AlgorithmHint)>("cvt_color", &cv::cvtColor,
    Arg("src"), Arg("dst"), Arg("code"), Arg("dst_cn") = static_cast<int>(0), Arg("hint") = static_cast<cv::AlgorithmHint>(cv::ALGO_HINT_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, cv::AlgorithmHint)>("cvt_color_two_plane", &cv::cvtColorTwoPlane,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("code"), Arg("hint") = static_cast<cv::AlgorithmHint>(cv::ALGO_HINT_DEFAULT));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int)>("demosaicing", &cv::demosaicing,
    Arg("src"), Arg("dst"), Arg("code"), Arg("dst_cn") = static_cast<int>(0));

  rb_mCv.define_module_function<cv::Moments(*)(cv::InputArray, bool)>("moments", &cv::moments,
    Arg("array"), Arg("binary_image") = static_cast<bool>(false));

  rb_mCv.define_module_function<void(*)(const cv::Moments&, double[7])>("hu_moments", &cv::HuMoments,
    Arg("moments"), Arg("hu"));

  rb_mCv.define_module_function<void(*)(const cv::Moments&, cv::OutputArray)>("hu_moments", &cv::HuMoments,
    Arg("m"), Arg("hu"));

  Enum<cv::TemplateMatchModes> rb_cCvTemplateMatchModes = define_enum_under<cv::TemplateMatchModes>("TemplateMatchModes", rb_mCv).
    define_value("TM_SQDIFF", cv::TemplateMatchModes::TM_SQDIFF).
    define_value("TM_SQDIFF_NORMED", cv::TemplateMatchModes::TM_SQDIFF_NORMED).
    define_value("TM_CCORR", cv::TemplateMatchModes::TM_CCORR).
    define_value("TM_CCORR_NORMED", cv::TemplateMatchModes::TM_CCORR_NORMED).
    define_value("TM_CCOEFF", cv::TemplateMatchModes::TM_CCOEFF).
    define_value("TM_CCOEFF_NORMED", cv::TemplateMatchModes::TM_CCOEFF_NORMED);

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, cv::InputArray)>("match_template", &cv::matchTemplate,
    Arg("image"), Arg("templ"), Arg("result"), Arg("method"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::OutputArray, int, int, int)>("connected_components", &cv::connectedComponents,
    Arg("image"), Arg("labels"), Arg("connectivity"), Arg("ltype"), Arg("ccltype"));

  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::OutputArray, int, int)>("connected_components", &cv::connectedComponents,
    Arg("image"), Arg("labels"), Arg("connectivity") = static_cast<int>(8), Arg("ltype") = static_cast<int>(CV_32S));

  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, int, int, int)>("connected_components_with_stats", &cv::connectedComponentsWithStats,
    Arg("image"), Arg("labels"), Arg("stats"), Arg("centroids"), Arg("connectivity"), Arg("ltype"), Arg("ccltype"));

  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, int, int)>("connected_components_with_stats", &cv::connectedComponentsWithStats,
    Arg("image"), Arg("labels"), Arg("stats"), Arg("centroids"), Arg("connectivity") = static_cast<int>(8), Arg("ltype") = static_cast<int>(CV_32S));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArrayOfArrays, cv::OutputArray, int, int, cv::Point)>("find_contours", &cv::findContours,
    Arg("image"), Arg("contours"), Arg("hierarchy"), Arg("mode"), Arg("method"), Arg("offset") = static_cast<cv::Point>(cv::Point()));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArrayOfArrays, int, int, cv::Point)>("find_contours", &cv::findContours,
    Arg("image"), Arg("contours"), Arg("mode"), Arg("method"), Arg("offset") = static_cast<cv::Point>(cv::Point()));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArrayOfArrays, cv::OutputArray)>("find_contours_link_runs", &cv::findContoursLinkRuns,
    Arg("image"), Arg("contours"), Arg("hierarchy"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArrayOfArrays)>("find_contours_link_runs", &cv::findContoursLinkRuns,
    Arg("image"), Arg("contours"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, bool)>("approx_poly_dp", &cv::approxPolyDP,
    Arg("curve"), Arg("approx_curve"), Arg("epsilon"), Arg("closed"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, float, bool)>("approx_poly_n", &cv::approxPolyN,
    Arg("curve"), Arg("approx_curve"), Arg("nsides"), Arg("epsilon_percentage") = static_cast<float>(-1.0), Arg("ensure_convex") = static_cast<bool>(true));

  rb_mCv.define_module_function<double(*)(cv::InputArray, bool)>("arc_length", &cv::arcLength,
    Arg("curve"), Arg("closed"));

  rb_mCv.define_module_function<cv::Rect(*)(cv::InputArray)>("bounding_rect", &cv::boundingRect,
    Arg("array"));

  rb_mCv.define_module_function<double(*)(cv::InputArray, bool)>("contour_area", &cv::contourArea,
    Arg("contour"), Arg("oriented") = static_cast<bool>(false));

  rb_mCv.define_module_function<cv::RotatedRect(*)(cv::InputArray)>("min_area_rect", &cv::minAreaRect,
    Arg("points"));

  rb_mCv.define_module_function<void(*)(cv::RotatedRect, cv::OutputArray)>("box_points", &cv::boxPoints,
    Arg("box"), Arg("points"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::Point2f&, float&)>("min_enclosing_circle", &cv::minEnclosingCircle,
    Arg("points"), Arg("center"), Arg("radius"));

  rb_mCv.define_module_function<double(*)(cv::InputArray, cv::OutputArray)>("min_enclosing_triangle", &cv::minEnclosingTriangle,
    Arg("points"), Arg("triangle"));

  rb_mCv.define_module_function<double(*)(cv::InputArray, cv::InputArray, int, double)>("match_shapes", &cv::matchShapes,
    Arg("contour1"), Arg("contour2"), Arg("method"), Arg("parameter"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, bool, bool)>("convex_hull", &cv::convexHull,
    Arg("points"), Arg("hull"), Arg("clockwise") = static_cast<bool>(false), Arg("return_points") = static_cast<bool>(true));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("convexity_defects", &cv::convexityDefects,
    Arg("contour"), Arg("convexhull"), Arg("convexity_defects"));

  rb_mCv.define_module_function<bool(*)(cv::InputArray)>("contour_convex?", &cv::isContourConvex,
    Arg("contour"));

  rb_mCv.define_module_function<float(*)(cv::InputArray, cv::InputArray, cv::OutputArray, bool)>("intersect_convex_convex", &cv::intersectConvexConvex,
    Arg("p1"), Arg("p2"), Arg("p12"), Arg("handle_nested") = static_cast<bool>(true));

  rb_mCv.define_module_function<cv::RotatedRect(*)(cv::InputArray)>("fit_ellipse", &cv::fitEllipse,
    Arg("points"));

  rb_mCv.define_module_function<cv::RotatedRect(*)(cv::InputArray)>("fit_ellipse_ams", &cv::fitEllipseAMS,
    Arg("points"));

  rb_mCv.define_module_function<cv::RotatedRect(*)(cv::InputArray)>("fit_ellipse_direct", &cv::fitEllipseDirect,
    Arg("points"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, double, double, double)>("fit_line", &cv::fitLine,
    Arg("points"), Arg("line"), Arg("dist_type"), Arg("param"), Arg("reps"), Arg("aeps"));

  rb_mCv.define_module_function<double(*)(cv::InputArray, cv::Point2f, bool)>("point_polygon_test", &cv::pointPolygonTest,
    Arg("contour"), Arg("pt"), Arg("measure_dist"));

  rb_mCv.define_module_function<int(*)(const cv::RotatedRect&, const cv::RotatedRect&, cv::OutputArray)>("rotated_rectangle_intersection", &cv::rotatedRectangleIntersection,
    Arg("rect1"), Arg("rect2"), Arg("intersecting_region"));

  rb_mCv.define_module_function<cv::Ptr<cv::GeneralizedHoughBallard>(*)()>("create_generalized_hough_ballard", &cv::createGeneralizedHoughBallard);

  rb_mCv.define_module_function<cv::Ptr<cv::GeneralizedHoughGuil>(*)()>("create_generalized_hough_guil", &cv::createGeneralizedHoughGuil);

  Enum<cv::ColormapTypes> rb_cCvColormapTypes = define_enum_under<cv::ColormapTypes>("ColormapTypes", rb_mCv).
    define_value("COLORMAP_AUTUMN", cv::ColormapTypes::COLORMAP_AUTUMN).
    define_value("COLORMAP_BONE", cv::ColormapTypes::COLORMAP_BONE).
    define_value("COLORMAP_JET", cv::ColormapTypes::COLORMAP_JET).
    define_value("COLORMAP_WINTER", cv::ColormapTypes::COLORMAP_WINTER).
    define_value("COLORMAP_RAINBOW", cv::ColormapTypes::COLORMAP_RAINBOW).
    define_value("COLORMAP_OCEAN", cv::ColormapTypes::COLORMAP_OCEAN).
    define_value("COLORMAP_SUMMER", cv::ColormapTypes::COLORMAP_SUMMER).
    define_value("COLORMAP_SPRING", cv::ColormapTypes::COLORMAP_SPRING).
    define_value("COLORMAP_COOL", cv::ColormapTypes::COLORMAP_COOL).
    define_value("COLORMAP_HSV", cv::ColormapTypes::COLORMAP_HSV).
    define_value("COLORMAP_PINK", cv::ColormapTypes::COLORMAP_PINK).
    define_value("COLORMAP_HOT", cv::ColormapTypes::COLORMAP_HOT).
    define_value("COLORMAP_PARULA", cv::ColormapTypes::COLORMAP_PARULA).
    define_value("COLORMAP_MAGMA", cv::ColormapTypes::COLORMAP_MAGMA).
    define_value("COLORMAP_INFERNO", cv::ColormapTypes::COLORMAP_INFERNO).
    define_value("COLORMAP_PLASMA", cv::ColormapTypes::COLORMAP_PLASMA).
    define_value("COLORMAP_VIRIDIS", cv::ColormapTypes::COLORMAP_VIRIDIS).
    define_value("COLORMAP_CIVIDIS", cv::ColormapTypes::COLORMAP_CIVIDIS).
    define_value("COLORMAP_TWILIGHT", cv::ColormapTypes::COLORMAP_TWILIGHT).
    define_value("COLORMAP_TWILIGHT_SHIFTED", cv::ColormapTypes::COLORMAP_TWILIGHT_SHIFTED).
    define_value("COLORMAP_TURBO", cv::ColormapTypes::COLORMAP_TURBO).
    define_value("COLORMAP_DEEPGREEN", cv::ColormapTypes::COLORMAP_DEEPGREEN);

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int)>("apply_color_map", &cv::applyColorMap,
    Arg("src"), Arg("dst"), Arg("colormap"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray)>("apply_color_map", &cv::applyColorMap,
    Arg("src"), Arg("dst"), Arg("user_color"));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, cv::Point, cv::Point, const cv::Scalar&, int, int, int)>("line", &cv::line,
    Arg("img"), Arg("pt1"), Arg("pt2"), Arg("color"), Arg("thickness") = static_cast<int>(1), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("shift") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, cv::Point, cv::Point, const cv::Scalar&, int, int, int, double)>("arrowed_line", &cv::arrowedLine,
    Arg("img"), Arg("pt1"), Arg("pt2"), Arg("color"), Arg("thickness") = static_cast<int>(1), Arg("line_type") = static_cast<int>(8), Arg("shift") = static_cast<int>(0), Arg("tip_length") = static_cast<double>(0.1));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, cv::Point, cv::Point, const cv::Scalar&, int, int, int)>("rectangle", &cv::rectangle,
    Arg("img"), Arg("pt1"), Arg("pt2"), Arg("color"), Arg("thickness") = static_cast<int>(1), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("shift") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, cv::Rect, const cv::Scalar&, int, int, int)>("rectangle", &cv::rectangle,
    Arg("img"), Arg("rec"), Arg("color"), Arg("thickness") = static_cast<int>(1), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("shift") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, cv::Point, int, const cv::Scalar&, int, int, int)>("circle", &cv::circle,
    Arg("img"), Arg("center"), Arg("radius"), Arg("color"), Arg("thickness") = static_cast<int>(1), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("shift") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, cv::Point, cv::Size, double, double, double, const cv::Scalar&, int, int, int)>("ellipse", &cv::ellipse,
    Arg("img"), Arg("center"), Arg("axes"), Arg("angle"), Arg("start_angle"), Arg("end_angle"), Arg("color"), Arg("thickness") = static_cast<int>(1), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("shift") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, const cv::RotatedRect&, const cv::Scalar&, int, int)>("ellipse", &cv::ellipse,
    Arg("img"), Arg("box"), Arg("color"), Arg("thickness") = static_cast<int>(1), Arg("line_type") = static_cast<int>(cv::LINE_8));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, cv::Point, const cv::Scalar&, int, int, int, int)>("draw_marker", &cv::drawMarker,
    Arg("img"), Arg("position"), Arg("color"), Arg("marker_type") = static_cast<int>(cv::MARKER_CROSS), Arg("marker_size") = static_cast<int>(20), Arg("thickness") = static_cast<int>(1), Arg("line_type") = static_cast<int>(8));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, cv::InputArray, const cv::Scalar&, int, int)>("fill_convex_poly", &cv::fillConvexPoly,
    Arg("img"), Arg("points"), Arg("color"), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("shift") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, const cv::Point*, int, const cv::Scalar&, int, int)>("fill_convex_poly", &cv::fillConvexPoly,
    Arg("img"), Arg("pts"), Arg("npts"), Arg("color"), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("shift") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, cv::InputArrayOfArrays, const cv::Scalar&, int, int, cv::Point)>("fill_poly", &cv::fillPoly,
    Arg("img"), Arg("pts"), Arg("color"), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("shift") = static_cast<int>(0), Arg("offset") = static_cast<cv::Point>(cv::Point()));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, const cv::Point**, const int*, int, const cv::Scalar&, int, int, cv::Point)>("fill_poly", &cv::fillPoly,
    Arg("img"), ArgBuffer("pts"), ArgBuffer("npts"), Arg("ncontours"), Arg("color"), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("shift") = static_cast<int>(0), Arg("offset") = static_cast<cv::Point>(cv::Point()));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, cv::InputArrayOfArrays, bool, const cv::Scalar&, int, int, int)>("polylines", &cv::polylines,
    Arg("img"), Arg("pts"), Arg("is_closed"), Arg("color"), Arg("thickness") = static_cast<int>(1), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("shift") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, const cv::Point* const*, const int*, int, bool, const cv::Scalar&, int, int, int)>("polylines", &cv::polylines,
    Arg("img"), ArgBuffer("pts"), ArgBuffer("npts"), Arg("ncontours"), Arg("is_closed"), Arg("color"), Arg("thickness") = static_cast<int>(1), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("shift") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, cv::InputArrayOfArrays, int, const cv::Scalar&, int, int, cv::InputArray, int, cv::Point)>("draw_contours", &cv::drawContours,
    Arg("image"), Arg("contours"), Arg("contour_idx"), Arg("color"), Arg("thickness") = static_cast<int>(1), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("hierarchy") = static_cast<cv::InputArray>(cv::noArray()), Arg("max_level") = static_cast<int>(INT_MAX), Arg("offset") = static_cast<cv::Point>(cv::Point()));

  rb_mCv.define_module_function<bool(*)(cv::Size, cv::Point&, cv::Point&)>("clip_line", &cv::clipLine,
    Arg("img_size"), Arg("pt1"), Arg("pt2"));

  rb_mCv.define_module_function<bool(*)(cv::Size2l, cv::Point2l&, cv::Point2l&)>("clip_line", &cv::clipLine,
    Arg("img_size"), Arg("pt1"), Arg("pt2"));

  rb_mCv.define_module_function<bool(*)(cv::Rect, cv::Point&, cv::Point&)>("clip_line", &cv::clipLine,
    Arg("img_rect"), Arg("pt1"), Arg("pt2"));

  rb_mCv.define_module_function<void(*)(cv::Point, cv::Size, int, int, int, int, std::vector<cv::Point_<int>>&)>("ellipse2_poly", &cv::ellipse2Poly,
    Arg("center"), Arg("axes"), Arg("angle"), Arg("arc_start"), Arg("arc_end"), Arg("delta"), Arg("pts"));

  rb_mCv.define_module_function<void(*)(cv::Point2d, cv::Size2d, int, int, int, int, std::vector<cv::Point_<double>>&)>("ellipse2_poly", &cv::ellipse2Poly,
    Arg("center"), Arg("axes"), Arg("angle"), Arg("arc_start"), Arg("arc_end"), Arg("delta"), Arg("pts"));

  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, const cv::String&, cv::Point, int, double, cv::Scalar, int, int, bool)>("put_text", &cv::putText,
    Arg("img"), Arg("text"), Arg("org"), Arg("font_face"), Arg("font_scale"), Arg("color"), Arg("thickness") = static_cast<int>(1), Arg("line_type") = static_cast<int>(cv::LINE_8), Arg("bottom_left_origin") = static_cast<bool>(false));

  rb_mCv.define_module_function<cv::Size(*)(const cv::String&, int, double, int, int*)>("get_text_size", &cv::getTextSize,
    Arg("text"), Arg("font_face"), Arg("font_scale"), Arg("thickness"), ArgBuffer("base_line"));

  rb_mCv.define_module_function<double(*)(const int, const int, const int)>("get_font_scale_from_height", &cv::getFontScaleFromHeight,
    Arg("font_face"), Arg("pixel_height"), Arg("thickness") = static_cast<const int>(1));

  Rice::Data_Type<cv::LineIterator> rb_cCvLineIterator = define_class_under<cv::LineIterator>(rb_mCv, "LineIterator").
    define_constructor(Constructor<cv::LineIterator, const cv::Mat&, cv::Point, cv::Point, int, bool>(),
      Arg("img"), Arg("pt1"), Arg("pt2"), Arg("connectivity") = static_cast<int>(8), Arg("left_to_right") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::LineIterator, cv::Point, cv::Point, int, bool>(),
      Arg("pt1"), Arg("pt2"), Arg("connectivity") = static_cast<int>(8), Arg("left_to_right") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::LineIterator, cv::Size, cv::Point, cv::Point, int, bool>(),
      Arg("bounding_area_size"), Arg("pt1"), Arg("pt2"), Arg("connectivity") = static_cast<int>(8), Arg("left_to_right") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::LineIterator, cv::Rect, cv::Point, cv::Point, int, bool>(),
      Arg("bounding_area_rect"), Arg("pt1"), Arg("pt2"), Arg("connectivity") = static_cast<int>(8), Arg("left_to_right") = static_cast<bool>(false)).
    define_method<void(cv::LineIterator::*)(const cv::Mat*, cv::Rect, cv::Point, cv::Point, int, bool)>("init", &cv::LineIterator::init,
      Arg("img"), Arg("bounding_area_rect"), Arg("pt1"), Arg("pt2"), Arg("connectivity"), Arg("left_to_right")).
    define_method<uchar*(cv::LineIterator::*)()>("dereference", &cv::LineIterator::operator*,
      ReturnBuffer()).
    define_method<cv::LineIterator&(cv::LineIterator::*)()>("increment", &cv::LineIterator::operator++).
    define_method<cv::LineIterator(cv::LineIterator::*)(int)>("increment_post", &cv::LineIterator::operator++,
      Arg("arg_0")).
    define_method<cv::Point(cv::LineIterator::*)() const>("pos", &cv::LineIterator::pos).
    define_attr("ptr", &cv::LineIterator::ptr).
    define_attr("ptr0", &cv::LineIterator::ptr0).
    define_attr("step", &cv::LineIterator::step).
    define_attr("elem_size", &cv::LineIterator::elemSize).
    define_attr("err", &cv::LineIterator::err).
    define_attr("count", &cv::LineIterator::count).
    define_attr("minus_delta", &cv::LineIterator::minusDelta).
    define_attr("plus_delta", &cv::LineIterator::plusDelta).
    define_attr("minus_step", &cv::LineIterator::minusStep).
    define_attr("plus_step", &cv::LineIterator::plusStep).
    define_attr("minus_shift", &cv::LineIterator::minusShift).
    define_attr("plus_shift", &cv::LineIterator::plusShift).
    define_attr("p", &cv::LineIterator::p).
    define_attr("ptmode", &cv::LineIterator::ptmode);
}