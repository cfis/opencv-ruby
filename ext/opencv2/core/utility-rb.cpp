#include <opencv2/core/utility.hpp>
#include "utility-rb.hpp"

using namespace Rice;

#include "utility-rb.ipp"

void Init_Core_Utility()
{
  Module rb_mCv = define_module("Cv");

  rb_mCv.define_module_function<bool(*)(bool)>("set_break_on_error", &cv::setBreakOnError,
    Arg("flag"));

  rb_mCv.define_module_function<cv::ErrorCallback(*)(cv::ErrorCallback, void*, void**)>("redirect_error", &cv::redirectError,
    Arg("err_callback"), ArgBuffer("userdata") = static_cast<void*>(0), ArgBuffer("prev_userdata") = static_cast<void**>(0));

  rb_mCv.define_module_function<cv::String(*)(const char*)>("tempfile", &cv::tempfile,
    Arg("suffix") = static_cast<const char*>(0));

  rb_mCv.define_module_function<void(*)(cv::String, std::vector<std::basic_string<char>>&, bool)>("glob", &cv::glob,
    Arg("pattern"), Arg("result"), Arg("recursive") = static_cast<bool>(false));

  rb_mCv.define_module_function<void(*)(int)>("set_num_threads", &cv::setNumThreads,
    Arg("nthreads"));

  rb_mCv.define_module_function<int(*)()>("get_num_threads", &cv::getNumThreads);

  rb_mCv.define_module_function<int(*)()>("get_thread_num", &cv::getThreadNum);

  rb_mCv.define_module_function<const cv::String&(*)()>("get_build_information", &cv::getBuildInformation);

  rb_mCv.define_module_function<cv::String(*)()>("get_version_string", &cv::getVersionString);

  rb_mCv.define_module_function<int(*)()>("get_version_major", &cv::getVersionMajor);

  rb_mCv.define_module_function<int(*)()>("get_version_minor", &cv::getVersionMinor);

  rb_mCv.define_module_function<int(*)()>("get_version_revision", &cv::getVersionRevision);

  rb_mCv.define_module_function<int64(*)()>("get_tick_count", &cv::getTickCount);

  rb_mCv.define_module_function<double(*)()>("get_tick_frequency", &cv::getTickFrequency);

  Rice::Data_Type<cv::TickMeter> rb_cCvTickMeter = define_class_under<cv::TickMeter>(rb_mCv, "TickMeter").
    define_constructor(Constructor<cv::TickMeter>()).
    define_method<void(cv::TickMeter::*)()>("start", &cv::TickMeter::start).
    define_method<void(cv::TickMeter::*)()>("stop", &cv::TickMeter::stop).
    define_method<int64(cv::TickMeter::*)() const>("get_time_ticks", &cv::TickMeter::getTimeTicks).
    define_method<double(cv::TickMeter::*)() const>("get_time_micro", &cv::TickMeter::getTimeMicro).
    define_method<double(cv::TickMeter::*)() const>("get_time_milli", &cv::TickMeter::getTimeMilli).
    define_method<double(cv::TickMeter::*)() const>("get_time_sec", &cv::TickMeter::getTimeSec).
    define_method<int64(cv::TickMeter::*)() const>("get_last_time_ticks", &cv::TickMeter::getLastTimeTicks).
    define_method<double(cv::TickMeter::*)() const>("get_last_time_micro", &cv::TickMeter::getLastTimeMicro).
    define_method<double(cv::TickMeter::*)() const>("get_last_time_milli", &cv::TickMeter::getLastTimeMilli).
    define_method<double(cv::TickMeter::*)() const>("get_last_time_sec", &cv::TickMeter::getLastTimeSec).
    define_method<int64(cv::TickMeter::*)() const>("get_counter", &cv::TickMeter::getCounter).
    define_method<double(cv::TickMeter::*)() const>("get_fps", &cv::TickMeter::getFPS).
    define_method<double(cv::TickMeter::*)() const>("get_avg_time_sec", &cv::TickMeter::getAvgTimeSec).
    define_method<double(cv::TickMeter::*)() const>("get_avg_time_milli", &cv::TickMeter::getAvgTimeMilli).
    define_method<void(cv::TickMeter::*)()>("reset", &cv::TickMeter::reset);

  rb_mCv.define_module_function<int64(*)()>("get_cpu_tick_count", &cv::getCPUTickCount);

  rb_mCv.define_module_function<bool(*)(int)>("check_hardware_support", &cv::checkHardwareSupport,
    Arg("feature"));

  rb_mCv.define_module_function<cv::String(*)(int)>("get_hardware_feature_name", &cv::getHardwareFeatureName,
    Arg("feature"));

  rb_mCv.define_module_function<std::string(*)()>("get_cpu_features_line", &cv::getCPUFeaturesLine);

  rb_mCv.define_module_function<int(*)()>("get_number_of_cp_us", &cv::getNumberOfCPUs);

  rb_mCv.define_module_function<size_t(*)(size_t, int)>("align_size", &cv::alignSize,
    Arg("sz"), Arg("n"));

  rb_mCv.define_module_function<int(*)(int, unsigned int)>("div_up", &cv::divUp,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function<size_t(*)(size_t, unsigned int)>("div_up", &cv::divUp,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function<int(*)(int, unsigned int)>("round_up", &cv::roundUp,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function<size_t(*)(size_t, unsigned int)>("round_up", &cv::roundUp,
    Arg("a"), Arg("b"));

#if RUBY_CV_VERSION >= 411
  Enum<cv::AlgorithmHint> rb_cCvAlgorithmHint = define_enum_under<cv::AlgorithmHint>("AlgorithmHint", rb_mCv).
    define_value("ALGO_HINT_DEFAULT", cv::AlgorithmHint::ALGO_HINT_DEFAULT).
    define_value("ALGO_HINT_ACCURATE", cv::AlgorithmHint::ALGO_HINT_ACCURATE).
    define_value("ALGO_HINT_APPROX", cv::AlgorithmHint::ALGO_HINT_APPROX);

  rb_mCv.define_module_function<cv::AlgorithmHint(*)()>("get_default_algorithm_hint", &cv::getDefaultAlgorithmHint);
#endif

  rb_mCv.define_module_function<void(*)(bool)>("set_use_optimized", &cv::setUseOptimized,
    Arg("onoff"));

  rb_mCv.define_module_function<bool(*)()>("use_optimized?", &cv::useOptimized);

  rb_mCv.define_module_function<size_t(*)(int)>("get_elem_size", &cv::getElemSize,
    Arg("type"));

  Rice::Data_Type<cv::ParallelLoopBody> rb_cCvParallelLoopBody = define_class_under<cv::ParallelLoopBody>(rb_mCv, "ParallelLoopBody").
    define_method<void(cv::ParallelLoopBody::*)(const cv::Range&) const>("call", &cv::ParallelLoopBody::operator(),
      Arg("range"));

  Rice::Data_Type<cv::ParallelLoopBodyLambdaWrapper> rb_cCvParallelLoopBodyLambdaWrapper = define_class_under<cv::ParallelLoopBodyLambdaWrapper, cv::ParallelLoopBody>(rb_mCv, "ParallelLoopBodyLambdaWrapper").
    define_constructor(Constructor<cv::ParallelLoopBodyLambdaWrapper, std::function<void (const cv::Range &)>>(),
      Arg("functor")).
    define_method<void(cv::ParallelLoopBodyLambdaWrapper::*)(const cv::Range&) const>("call", &cv::ParallelLoopBodyLambdaWrapper::operator(),
      Arg("range"));

  Rice::Data_Type<cv::CommandLineParser> rb_cCvCommandLineParser = define_class_under<cv::CommandLineParser>(rb_mCv, "CommandLineParser").
    define_constructor(Constructor<cv::CommandLineParser, int, const char* const[], const cv::String&>(),
      Arg("argc"), Arg("argv"), Arg("keys")).
    define_constructor(Constructor<cv::CommandLineParser, const cv::CommandLineParser&>(),
      Arg("parser")).
    define_method<cv::CommandLineParser&(cv::CommandLineParser::*)(const cv::CommandLineParser&)>("assign", &cv::CommandLineParser::operator=,
      Arg("parser")).
    define_method<cv::String(cv::CommandLineParser::*)() const>("get_path_to_application", &cv::CommandLineParser::getPathToApplication).
    define_method<bool(cv::CommandLineParser::*)(const cv::String&) const>("has", &cv::CommandLineParser::has,
      Arg("name")).
    define_method<bool(cv::CommandLineParser::*)() const>("check?", &cv::CommandLineParser::check).
    define_method<void(cv::CommandLineParser::*)(const cv::String&)>("about", &cv::CommandLineParser::about,
      Arg("message")).
    define_method<void(cv::CommandLineParser::*)() const>("print_message", &cv::CommandLineParser::printMessage).
    define_method<void(cv::CommandLineParser::*)() const>("print_errors", &cv::CommandLineParser::printErrors);

  Module rb_mCvSamples = define_module_under(rb_mCv, "Samples");

  rb_mCvSamples.define_module_function<cv::String(*)(const cv::String&, bool, bool)>("find_file", &cv::samples::findFile,
    Arg("relative_path"), Arg("required") = static_cast<bool>(true), Arg("silent_mode") = static_cast<bool>(false));

  rb_mCvSamples.define_module_function<cv::String(*)(const cv::String&, bool)>("find_file_or_keep", &cv::samples::findFileOrKeep,
    Arg("relative_path"), Arg("silent_mode") = static_cast<bool>(false));

  rb_mCvSamples.define_module_function<cv::String(*)(const cv::String&, bool)>("find_file_or_keep", &cv::samples::findFileOrKeep,
    Arg("relative_path"), Arg("silent_mode"));

  rb_mCvSamples.define_module_function<void(*)(const cv::String&)>("add_samples_data_search_path", &cv::samples::addSamplesDataSearchPath,
    Arg("path"));

  rb_mCvSamples.define_module_function<void(*)(const cv::String&)>("add_samples_data_search_sub_directory", &cv::samples::addSamplesDataSearchSubDirectory,
    Arg("subdir"));

  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");

  rb_mCvUtils.define_module_function<int(*)()>("get_thread_id", &cv::utils::getThreadID);

  rb_cCvTickMeter.
    define_method("inspect", [](const cv::TickMeter& self) -> std::string
  {
    std::ostringstream stream;
    stream << self;
    return stream.str();
  });
}