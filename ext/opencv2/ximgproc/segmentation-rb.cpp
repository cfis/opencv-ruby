#include <opencv2/ximgproc/segmentation.hpp>
#include "segmentation-rb.hpp"

using namespace Rice;

void Init_Ximgproc_Segmentation()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");

  Module rb_mCvXimgprocSegmentation = define_module_under(rb_mCvXimgproc, "Segmentation");

  Rice::Data_Type<cv::ximgproc::segmentation::GraphSegmentation> rb_cCvXimgprocSegmentationGraphSegmentation = define_class_under<cv::ximgproc::segmentation::GraphSegmentation, cv::Algorithm>(rb_mCvXimgprocSegmentation, "GraphSegmentation").
    define_method<void(cv::ximgproc::segmentation::GraphSegmentation::*)(cv::InputArray, cv::OutputArray)>("process_image", &cv::ximgproc::segmentation::GraphSegmentation::processImage,
      Arg("src"), Arg("dst")).
    define_method<void(cv::ximgproc::segmentation::GraphSegmentation::*)(double)>("set_sigma", &cv::ximgproc::segmentation::GraphSegmentation::setSigma,
      Arg("sigma")).
    define_method<double(cv::ximgproc::segmentation::GraphSegmentation::*)()>("get_sigma", &cv::ximgproc::segmentation::GraphSegmentation::getSigma).
    define_method<void(cv::ximgproc::segmentation::GraphSegmentation::*)(float)>("set_k", &cv::ximgproc::segmentation::GraphSegmentation::setK,
      Arg("k")).
    define_method<float(cv::ximgproc::segmentation::GraphSegmentation::*)()>("get_k", &cv::ximgproc::segmentation::GraphSegmentation::getK).
    define_method<void(cv::ximgproc::segmentation::GraphSegmentation::*)(int)>("set_min_size", &cv::ximgproc::segmentation::GraphSegmentation::setMinSize,
      Arg("min_size")).
    define_method<int(cv::ximgproc::segmentation::GraphSegmentation::*)()>("get_min_size", &cv::ximgproc::segmentation::GraphSegmentation::getMinSize);

  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::GraphSegmentation>(*)(double, float, int)>("create_graph_segmentation", &cv::ximgproc::segmentation::createGraphSegmentation,
    Arg("sigma") = static_cast<double>(0.5), Arg("k") = static_cast<float>(300), Arg("min_size") = static_cast<int>(100));

  Rice::Data_Type<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy> rb_cCvXimgprocSegmentationSelectiveSearchSegmentationStrategy = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy, cv::Algorithm>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentationStrategy").
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy::*)(cv::InputArray, cv::InputArray, cv::InputArray, int)>("set_image", &cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy::setImage,
      Arg("img"), Arg("regions"), Arg("sizes"), Arg("image_id") = static_cast<int>(-1)).
    define_method<float(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy::*)(int, int)>("get", &cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy::get,
      Arg("r1"), Arg("r2")).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy::*)(int, int)>("merge", &cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy::merge,
      Arg("r1"), Arg("r2"));

  Rice::Data_Type<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyColor> rb_cCvXimgprocSegmentationSelectiveSearchSegmentationStrategyColor = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyColor, cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentationStrategyColor");

  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyColor>(*)()>("create_selective_search_segmentation_strategy_color", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyColor);

  Rice::Data_Type<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategySize> rb_cCvXimgprocSegmentationSelectiveSearchSegmentationStrategySize = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategySize, cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentationStrategySize");

  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategySize>(*)()>("create_selective_search_segmentation_strategy_size", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategySize);

  Rice::Data_Type<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyTexture> rb_cCvXimgprocSegmentationSelectiveSearchSegmentationStrategyTexture = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyTexture, cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentationStrategyTexture");

  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyTexture>(*)()>("create_selective_search_segmentation_strategy_texture", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyTexture);

  Rice::Data_Type<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyFill> rb_cCvXimgprocSegmentationSelectiveSearchSegmentationStrategyFill = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyFill, cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentationStrategyFill");

  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyFill>(*)()>("create_selective_search_segmentation_strategy_fill", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyFill);

  Rice::Data_Type<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple> rb_cCvXimgprocSegmentationSelectiveSearchSegmentationStrategyMultiple = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple, cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentationStrategyMultiple").
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple::*)(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, float)>("add_strategy", &cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple::addStrategy,
      Arg("g"), Arg("weight")).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple::*)()>("clear_strategies", &cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple::clearStrategies);

  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(*)()>("create_selective_search_segmentation_strategy_multiple", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple);

  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(*)(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>)>("create_selective_search_segmentation_strategy_multiple", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple,
    Arg("s1"));

  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(*)(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>)>("create_selective_search_segmentation_strategy_multiple", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple,
    Arg("s1"), Arg("s2"));

  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(*)(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>)>("create_selective_search_segmentation_strategy_multiple", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple,
    Arg("s1"), Arg("s2"), Arg("s3"));

  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(*)(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>)>("create_selective_search_segmentation_strategy_multiple", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple,
    Arg("s1"), Arg("s2"), Arg("s3"), Arg("s4"));

  Rice::Data_Type<cv::ximgproc::segmentation::SelectiveSearchSegmentation> rb_cCvXimgprocSegmentationSelectiveSearchSegmentation = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentation, cv::Algorithm>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentation").
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(cv::InputArray)>("set_base_image", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::setBaseImage,
      Arg("img")).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(int, float)>("switch_to_single_strategy", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::switchToSingleStrategy,
      Arg("k") = static_cast<int>(200), Arg("sigma") = static_cast<float>(0.8f)).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(int, int, float)>("switch_to_selective_search_fast", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::switchToSelectiveSearchFast,
      Arg("base_k") = static_cast<int>(150), Arg("inc_k") = static_cast<int>(150), Arg("sigma") = static_cast<float>(0.8f)).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(int, int, float)>("switch_to_selective_search_quality", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::switchToSelectiveSearchQuality,
      Arg("base_k") = static_cast<int>(150), Arg("inc_k") = static_cast<int>(150), Arg("sigma") = static_cast<float>(0.8f)).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(cv::InputArray)>("add_image", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::addImage,
      Arg("img")).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)()>("clear_images", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::clearImages).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(cv::Ptr<cv::ximgproc::segmentation::GraphSegmentation>)>("add_graph_segmentation", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::addGraphSegmentation,
      Arg("g")).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)()>("clear_graph_segmentations", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::clearGraphSegmentations).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>)>("add_strategy", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::addStrategy,
      Arg("s")).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)()>("clear_strategies", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::clearStrategies).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(std::vector<cv::Rect_<int>>&)>("process", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::process,
      Arg("rects"));

  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentation>(*)()>("create_selective_search_segmentation", &cv::ximgproc::segmentation::createSelectiveSearchSegmentation);
}
