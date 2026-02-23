#include <opencv2/videoio/registry.hpp>
#include "registry-rb.hpp"

using namespace Rice;

void Init_Videoio_Registry()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvVideoioRegistry = define_module_under(rb_mCv, "VideoioRegistry");

  rb_mCvVideoioRegistry.define_module_function<cv::String(*)(cv::VideoCaptureAPIs)>("get_backend_name", &cv::videoio_registry::getBackendName,
    Arg("api"));

  rb_mCvVideoioRegistry.define_module_function<std::vector<cv::VideoCaptureAPIs>(*)()>("get_backends", &cv::videoio_registry::getBackends);

  rb_mCvVideoioRegistry.define_module_function<std::vector<cv::VideoCaptureAPIs>(*)()>("get_camera_backends", &cv::videoio_registry::getCameraBackends);

  rb_mCvVideoioRegistry.define_module_function<std::vector<cv::VideoCaptureAPIs>(*)()>("get_stream_backends", &cv::videoio_registry::getStreamBackends);

  rb_mCvVideoioRegistry.define_module_function<std::vector<cv::VideoCaptureAPIs>(*)()>("get_stream_buffered_backends", &cv::videoio_registry::getStreamBufferedBackends);

  rb_mCvVideoioRegistry.define_module_function<std::vector<cv::VideoCaptureAPIs>(*)()>("get_writer_backends", &cv::videoio_registry::getWriterBackends);

  rb_mCvVideoioRegistry.define_module_function<bool(*)(cv::VideoCaptureAPIs)>("has_backend", &cv::videoio_registry::hasBackend,
    Arg("api"));

  rb_mCvVideoioRegistry.define_module_function<bool(*)(cv::VideoCaptureAPIs)>("backend_built_in?", &cv::videoio_registry::isBackendBuiltIn,
    Arg("api"));

  rb_mCvVideoioRegistry.define_module_function<std::string(*)(cv::VideoCaptureAPIs, int&, int&)>("get_camera_backend_plugin_version", &cv::videoio_registry::getCameraBackendPluginVersion,
    Arg("api"), Arg("version_abi"), Arg("version_api"));

  rb_mCvVideoioRegistry.define_module_function<std::string(*)(cv::VideoCaptureAPIs, int&, int&)>("get_stream_backend_plugin_version", &cv::videoio_registry::getStreamBackendPluginVersion,
    Arg("api"), Arg("version_abi"), Arg("version_api"));

  rb_mCvVideoioRegistry.define_module_function<std::string(*)(cv::VideoCaptureAPIs, int&, int&)>("get_stream_buffered_backend_plugin_version", &cv::videoio_registry::getStreamBufferedBackendPluginVersion,
    Arg("api"), Arg("version_abi"), Arg("version_api"));

  rb_mCvVideoioRegistry.define_module_function<std::string(*)(cv::VideoCaptureAPIs, int&, int&)>("get_writer_backend_plugin_version", &cv::videoio_registry::getWriterBackendPluginVersion,
    Arg("api"), Arg("version_abi"), Arg("version_api"));
}
