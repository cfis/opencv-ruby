#include <opencv2/core/utility.hpp>
#include "../../opencv_ruby_version.hpp"
#include "utility-rb.hpp"

using namespace Rice;

Rice::Class rb_cAutoLock;
Data_Type<cv::CommandLineParser> rb_cCvCommandLineParser;
Rice::Class rb_cCvParallelLoopBody;
Rice::Class rb_cCvParallelLoopBodyLambdaWrapper;
Rice::Class rb_cCvTickMeter;

template<typename Data_Type_T, typename _Tp, size_t fixed_size>
inline void AutoBuffer_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::AutoBuffer<_Tp, fixed_size>>()).
    define_constructor(Constructor<cv::AutoBuffer<_Tp, fixed_size>, ::size_t>(),
      Arg("_size")).
    define_constructor(Constructor<cv::AutoBuffer<_Tp, fixed_size>, const cv::AutoBuffer<_Tp, fixed_size>&>(),
      Arg("buf")).
    template define_method<>("assign", &cv::AutoBuffer<_Tp, fixed_size>::operator=,
      Arg("buf")).
    template define_method<>("allocate", &cv::AutoBuffer<_Tp, fixed_size>::allocate,
      Arg("_size")).
    template define_method<>("deallocate", &cv::AutoBuffer<_Tp, fixed_size>::deallocate).
    template define_method<>("resize", &cv::AutoBuffer<_Tp, fixed_size>::resize,
      Arg("_size")).
    template define_method<>("size", &cv::AutoBuffer<_Tp, fixed_size>::size).
    template define_method<_Tp*(cv::AutoBuffer<_Tp, fixed_size>::*)()>("data", &cv::AutoBuffer<_Tp, fixed_size>::data).
    template define_method<const _Tp*(cv::AutoBuffer<_Tp, fixed_size>::*)() const>("data", &cv::AutoBuffer<_Tp, fixed_size>::data).
    define_method("to_type_parameter_0_0 *", [](const cv::AutoBuffer<_Tp, fixed_size>& self) -> _Tp*
    {
      return self;
    }).
    define_method("to_const type_parameter_0_0 *", [](const cv::AutoBuffer<_Tp, fixed_size>& self) -> const _Tp*
    {
      return self;
    });
};

template<typename Data_Type_T, typename OBJECT>
inline void Node_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Node<OBJECT>>()).
    define_constructor(Constructor<cv::Node<OBJECT>, OBJECT&>(),
      Arg("payload")).
    template define_method<cv::Node<OBJECT>*(cv::Node<OBJECT>::*)(OBJECT&) const>("find_child", &cv::Node<OBJECT>::findChild,
      Arg("payload")).
    template define_method<int(cv::Node<OBJECT>::*)(cv::Node<OBJECT>*) const>("find_child", &cv::Node<OBJECT>::findChild,
      Arg("p_node")).
    template define_method<>("add_child", &cv::Node<OBJECT>::addChild,
      Arg("p_node")).
    template define_method<>("remove_childs", &cv::Node<OBJECT>::removeChilds).
    template define_method<>("get_depth", &cv::Node<OBJECT>::getDepth).
    define_attr("m_payload", &cv::Node<OBJECT>::m_payload).
    define_attr("m_p_parent", &cv::Node<OBJECT>::m_pParent).
    define_attr("m_childs", &cv::Node<OBJECT>::m_childs);
};

void Init_Utility()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_module_function("set_break_on_error?", &cv::setBreakOnError,
    Arg("flag"));
  
 // rb_mCv.define_module_function("redirect_error", &cv::redirectError,
 //   Arg("err_callback"), Arg("userdata") = static_cast<void *>(0), Arg("prev_userdata") = static_cast<void **>(0));
  
  rb_mCv.define_module_function("tempfile", &cv::tempfile,
    Arg("suffix") = static_cast<const char *>(0));
  
  rb_mCv.define_module_function("glob", &cv::glob,
    Arg("pattern"), Arg("result"), Arg("recursive") = static_cast<bool>(false));
  
  rb_mCv.define_module_function("set_num_threads", &cv::setNumThreads,
    Arg("nthreads"));
  
  rb_mCv.define_module_function("get_num_threads", &cv::getNumThreads);
  
  rb_mCv.define_module_function("get_thread_num", &cv::getThreadNum);
  
  rb_mCv.define_module_function("get_build_information", &cv::getBuildInformation);
  
  rb_mCv.define_module_function("get_version_string", &cv::getVersionString);
  
  rb_mCv.define_module_function("get_version_major", &cv::getVersionMajor);
  
  rb_mCv.define_module_function("get_version_minor", &cv::getVersionMinor);
  
  rb_mCv.define_module_function("get_version_revision", &cv::getVersionRevision);
  
  rb_mCv.define_module_function("get_tick_count", &cv::getTickCount);
  
  rb_mCv.define_module_function("get_tick_frequency", &cv::getTickFrequency);
  
  rb_cCvTickMeter = define_class_under<cv::TickMeter>(rb_mCv, "TickMeter").
    define_constructor(Constructor<cv::TickMeter>()).
    define_method("start", &cv::TickMeter::start).
    define_method("stop", &cv::TickMeter::stop).
    define_method("get_time_ticks", &cv::TickMeter::getTimeTicks).
    define_method("get_time_micro", &cv::TickMeter::getTimeMicro).
    define_method("get_time_milli", &cv::TickMeter::getTimeMilli).
    define_method("get_time_sec", &cv::TickMeter::getTimeSec).
    define_method("get_counter", &cv::TickMeter::getCounter).
    define_method("get_fps", &cv::TickMeter::getFPS).
    define_method("get_avg_time_sec", &cv::TickMeter::getAvgTimeSec).
    define_method("get_avg_time_milli", &cv::TickMeter::getAvgTimeMilli).
    define_method("reset", &cv::TickMeter::reset);
  
  
  rb_cCvTickMeter.define_method("inspect", [](const cv::TickMeter& self) -> std::string
  {
    std::ostringstream stream;
    stream << self;
    return stream.str();
  });
  
  rb_mCv.define_module_function("get_cpu_tick_count", &cv::getCPUTickCount);
  
  rb_mCv.define_module_function("check_hardware_support?", &cv::checkHardwareSupport,
    Arg("feature"));
  
  rb_mCv.define_module_function("get_hardware_feature_name", &cv::getHardwareFeatureName,
    Arg("feature"));
  
  rb_mCv.define_module_function("get_cpu_features_line", &cv::getCPUFeaturesLine);
  
  rb_mCv.define_module_function("get_number_of_cp_us", &cv::getNumberOfCPUs);
  
  rb_mCv.define_module_function("align_size", &cv::alignSize,
    Arg("sz"), Arg("n"));
  
  rb_mCv.define_module_function<int(*)(int, unsigned int)>("div_up", &cv::divUp,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<::size_t(*)(::size_t, unsigned int)>("div_up", &cv::divUp,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<int(*)(int, unsigned int)>("round_up", &cv::roundUp,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<::size_t(*)(::size_t, unsigned int)>("round_up", &cv::roundUp,
    Arg("a"), Arg("b"));

#if RUBY_CV_VERSION >= 411
  Enum<cv::AlgorithmHint> rb_cCvAlgorithmHint = define_enum_under<cv::AlgorithmHint>("AlgorithmHint", rb_mCv).
    define_value("ALGO_HINT_DEFAULT", cv::AlgorithmHint::ALGO_HINT_DEFAULT).
    define_value("ALGO_HINT_ACCURATE", cv::AlgorithmHint::ALGO_HINT_ACCURATE).
    define_value("ALGO_HINT_APPROX", cv::AlgorithmHint::ALGO_HINT_APPROX);
#endif

  rb_mCv.define_module_function("set_use_optimized", &cv::setUseOptimized,
    Arg("onoff"));
  
  rb_mCv.define_module_function("use_optimized?", &cv::useOptimized);
  
  rb_mCv.define_module_function("get_elem_size", &cv::getElemSize,
    Arg("type"));
  
  rb_cCvParallelLoopBody = define_class_under<cv::ParallelLoopBody>(rb_mCv, "ParallelLoopBody").
    define_method("call", &cv::ParallelLoopBody::operator(),
      Arg("range"));
  
  rb_mCv.define_module_function<void(*)(const cv::Range&, const cv::ParallelLoopBody&, double)>("parallel_for_", &cv::parallel_for_,
    Arg("range"), Arg("body"), Arg("nstripes") = static_cast<double>(-1.));
  
 /* rb_cCvParallelLoopBodyLambdaWrapper = define_class_under<cv::ParallelLoopBodyLambdaWrapper, cv::ParallelLoopBody>(rb_mCv, "ParallelLoopBodyLambdaWrapper").
    define_constructor(Constructor<cv::ParallelLoopBodyLambdaWrapper, std::function<void (const cv::Range &)>>(),
      Arg("functor")).
    define_method("call", &cv::ParallelLoopBodyLambdaWrapper::operator(),
      Arg("range"));
  */
  /*rb_mCv.define_module_function<void(*)(const cv::Range&, std::function<void(const cv::Range&)>, double)>("parallel_for_", &cv::parallel_for_,
    Arg("range"), Arg("functor"), Arg("nstripes") = static_cast<double>(-1.));
  */
  //rb_cAutoLock = define_class_under<std::lock_guard<std::recursive_mutex>>(rb_mCv, "AutoLock").
  //define(&lock_guard_builder<Data_Type<std::lock_guard<std::recursive_mutex>>, std::recursive_mutex>);

  rb_cCvCommandLineParser = define_class_under<cv::CommandLineParser>(rb_mCv, "CommandLineParser").
    define_constructor(Constructor<cv::CommandLineParser, const cv::CommandLineParser&>(),
      Arg("parser")).
    define_method("assign", &cv::CommandLineParser::operator=,
      Arg("parser")).
    define_method("get_path_to_application", &cv::CommandLineParser::getPathToApplication).
    define_method("has?", &cv::CommandLineParser::has,
      Arg("name")).
    define_method("check?", &cv::CommandLineParser::check).
    define_method("about", &cv::CommandLineParser::about,
      Arg("message")).
    define_method("print_message", &cv::CommandLineParser::printMessage).
    define_method("print_errors", &cv::CommandLineParser::printErrors);
  
#if RUBY_CV_VERSION >= 411
  rb_cCvCommandLineParser.
    define_constructor(Constructor<cv::CommandLineParser, int, const char* const [], const cv::String&>(),
      Arg("argc"), Arg("argv"), Arg("keys"));
#endif

  Module rb_mCvSamples = define_module_under(rb_mCv, "Samples");
  
  rb_mCvSamples.define_module_function("find_file", &cv::samples::findFile,
    Arg("relative_path"), Arg("required") = static_cast<bool>(true), Arg("silent_mode") = static_cast<bool>(false));
  
  rb_mCvSamples.define_module_function<cv::String(*)(const cv::String&, bool)>("find_file_or_keep", &cv::samples::findFileOrKeep,
    Arg("relative_path"), Arg("silent_mode") = static_cast<bool>(false));
  
  rb_mCvSamples.define_module_function<cv::String(*)(const cv::String&, bool)>("find_file_or_keep", &cv::samples::findFileOrKeep,
    Arg("relative_path"), Arg("silent_mode"));
  
  rb_mCvSamples.define_module_function("add_samples_data_search_path", &cv::samples::addSamplesDataSearchPath,
    Arg("path"));
  
  rb_mCvSamples.define_module_function("add_samples_data_search_sub_directory", &cv::samples::addSamplesDataSearchSubDirectory,
    Arg("subdir"));
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  rb_mCvUtils.define_module_function("get_thread_id", &cv::utils::getThreadID);
}