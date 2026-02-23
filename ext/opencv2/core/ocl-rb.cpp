#include <opencv2/core/ocl.hpp>
#include "ocl-rb.hpp"

using namespace Rice;

void Init_Core_Ocl()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvOcl = define_module_under(rb_mCv, "Ocl");

  rb_mCvOcl.define_module_function<bool(*)()>("have_open_cl?", &cv::ocl::haveOpenCL);

  rb_mCvOcl.define_module_function<bool(*)()>("use_open_cl?", &cv::ocl::useOpenCL);

  rb_mCvOcl.define_module_function<bool(*)()>("have_amd_blas?", &cv::ocl::haveAmdBlas);

  rb_mCvOcl.define_module_function<bool(*)()>("have_amd_fft?", &cv::ocl::haveAmdFft);

  rb_mCvOcl.define_module_function<void(*)(bool)>("set_use_open_cl", &cv::ocl::setUseOpenCL,
    Arg("flag"));

  rb_mCvOcl.define_module_function<void(*)()>("finish", &cv::ocl::finish);

  rb_mCvOcl.define_module_function<bool(*)()>("have_svm?", &cv::ocl::haveSVM);

  Rice::Data_Type<cv::ocl::Device> rb_cCvOclDevice = define_class_under<cv::ocl::Device>(rb_mCvOcl, "Device");

  Rice::Data_Type<cv::ocl::Device::Impl> rb_cCvOclDeviceImpl = define_class_under<cv::ocl::Device::Impl>(rb_cCvOclDevice, "Impl");

  rb_cCvOclDevice.
    define_constructor(Constructor<cv::ocl::Device>()).
    define_constructor(Constructor<cv::ocl::Device, void*>(),
      ArgBuffer("d")).
    define_constructor(Constructor<cv::ocl::Device, const cv::ocl::Device&>(),
      Arg("d")).
    define_method<cv::ocl::Device&(cv::ocl::Device::*)(const cv::ocl::Device&)>("assign", &cv::ocl::Device::operator=,
      Arg("d")).
    define_method<cv::ocl::Device&(cv::ocl::Device::*)(cv::ocl::Device&&) noexcept>("assign", &cv::ocl::Device::operator=,
      Arg("d")).
    define_method<void(cv::ocl::Device::*)(void*)>("set", &cv::ocl::Device::set,
      ArgBuffer("d")).
    define_method<cv::String(cv::ocl::Device::*)() const>("name", &cv::ocl::Device::name).
    define_method<cv::String(cv::ocl::Device::*)() const>("extensions", &cv::ocl::Device::extensions).
    define_method<bool(cv::ocl::Device::*)(const cv::String&) const>("extension_supported?", &cv::ocl::Device::isExtensionSupported,
      Arg("extension_name")).
    define_method<cv::String(cv::ocl::Device::*)() const>("version", &cv::ocl::Device::version).
    define_method<cv::String(cv::ocl::Device::*)() const>("vendor_name", &cv::ocl::Device::vendorName).
    define_method<cv::String(cv::ocl::Device::*)() const>("open_cl_c_version", &cv::ocl::Device::OpenCL_C_Version).
    define_method<cv::String(cv::ocl::Device::*)() const>("open_cl_version", &cv::ocl::Device::OpenCLVersion).
    define_method<int(cv::ocl::Device::*)() const>("device_version_major", &cv::ocl::Device::deviceVersionMajor).
    define_method<int(cv::ocl::Device::*)() const>("device_version_minor", &cv::ocl::Device::deviceVersionMinor).
    define_method<cv::String(cv::ocl::Device::*)() const>("driver_version", &cv::ocl::Device::driverVersion).
    define_method<void*(cv::ocl::Device::*)() const>("ptr", &cv::ocl::Device::ptr,
      ReturnBuffer()).
    define_method<int(cv::ocl::Device::*)() const>("type", &cv::ocl::Device::type).
    define_method<int(cv::ocl::Device::*)() const>("address_bits", &cv::ocl::Device::addressBits).
    define_method<bool(cv::ocl::Device::*)() const>("available?", &cv::ocl::Device::available).
    define_method<bool(cv::ocl::Device::*)() const>("compiler_available?", &cv::ocl::Device::compilerAvailable).
    define_method<bool(cv::ocl::Device::*)() const>("linker_available?", &cv::ocl::Device::linkerAvailable).
    define_method<int(cv::ocl::Device::*)() const>("double_fp_config", &cv::ocl::Device::doubleFPConfig).
    define_method<int(cv::ocl::Device::*)() const>("single_fp_config", &cv::ocl::Device::singleFPConfig).
    define_method<int(cv::ocl::Device::*)() const>("half_fp_config", &cv::ocl::Device::halfFPConfig).
    define_method<bool(cv::ocl::Device::*)() const>("has_fp64?", &cv::ocl::Device::hasFP64).
    define_method<bool(cv::ocl::Device::*)() const>("has_fp16?", &cv::ocl::Device::hasFP16).
    define_method<bool(cv::ocl::Device::*)() const>("endian_little?", &cv::ocl::Device::endianLittle).
    define_method<bool(cv::ocl::Device::*)() const>("error_correction_support?", &cv::ocl::Device::errorCorrectionSupport).
    define_method<int(cv::ocl::Device::*)() const>("execution_capabilities", &cv::ocl::Device::executionCapabilities).
    define_method<size_t(cv::ocl::Device::*)() const>("global_mem_cache_size", &cv::ocl::Device::globalMemCacheSize).
    define_method<int(cv::ocl::Device::*)() const>("global_mem_cache_type", &cv::ocl::Device::globalMemCacheType).
    define_method<int(cv::ocl::Device::*)() const>("global_mem_cache_line_size", &cv::ocl::Device::globalMemCacheLineSize).
    define_method<size_t(cv::ocl::Device::*)() const>("global_mem_size", &cv::ocl::Device::globalMemSize).
    define_method<size_t(cv::ocl::Device::*)() const>("local_mem_size", &cv::ocl::Device::localMemSize).
    define_method<int(cv::ocl::Device::*)() const>("local_mem_type", &cv::ocl::Device::localMemType).
    define_method<bool(cv::ocl::Device::*)() const>("host_unified_memory?", &cv::ocl::Device::hostUnifiedMemory).
    define_method<bool(cv::ocl::Device::*)() const>("image_support?", &cv::ocl::Device::imageSupport).
    define_method<bool(cv::ocl::Device::*)() const>("image_from_buffer_support?", &cv::ocl::Device::imageFromBufferSupport).
    define_method<uint(cv::ocl::Device::*)() const>("image_pitch_alignment", &cv::ocl::Device::imagePitchAlignment).
    define_method<uint(cv::ocl::Device::*)() const>("image_base_address_alignment", &cv::ocl::Device::imageBaseAddressAlignment).
    define_method<bool(cv::ocl::Device::*)() const>("intel_subgroups_support?", &cv::ocl::Device::intelSubgroupsSupport).
    define_method<size_t(cv::ocl::Device::*)() const>("image_2d_max_width", &cv::ocl::Device::image2DMaxWidth).
    define_method<size_t(cv::ocl::Device::*)() const>("image_2d_max_height", &cv::ocl::Device::image2DMaxHeight).
    define_method<size_t(cv::ocl::Device::*)() const>("image_3d_max_width", &cv::ocl::Device::image3DMaxWidth).
    define_method<size_t(cv::ocl::Device::*)() const>("image_3d_max_height", &cv::ocl::Device::image3DMaxHeight).
    define_method<size_t(cv::ocl::Device::*)() const>("image_3d_max_depth", &cv::ocl::Device::image3DMaxDepth).
    define_method<size_t(cv::ocl::Device::*)() const>("image_max_buffer_size", &cv::ocl::Device::imageMaxBufferSize).
    define_method<size_t(cv::ocl::Device::*)() const>("image_max_array_size", &cv::ocl::Device::imageMaxArraySize).
    define_method<int(cv::ocl::Device::*)() const>("vendor_id", &cv::ocl::Device::vendorID).
    define_method<bool(cv::ocl::Device::*)() const>("amd?", &cv::ocl::Device::isAMD).
    define_method<bool(cv::ocl::Device::*)() const>("intel?", &cv::ocl::Device::isIntel).
    define_method<bool(cv::ocl::Device::*)() const>("n_vidia?", &cv::ocl::Device::isNVidia).
    define_method<int(cv::ocl::Device::*)() const>("max_clock_frequency", &cv::ocl::Device::maxClockFrequency).
    define_method<int(cv::ocl::Device::*)() const>("max_compute_units", &cv::ocl::Device::maxComputeUnits).
    define_method<int(cv::ocl::Device::*)() const>("max_constant_args", &cv::ocl::Device::maxConstantArgs).
    define_method<size_t(cv::ocl::Device::*)() const>("max_constant_buffer_size", &cv::ocl::Device::maxConstantBufferSize).
    define_method<size_t(cv::ocl::Device::*)() const>("max_mem_alloc_size", &cv::ocl::Device::maxMemAllocSize).
    define_method<size_t(cv::ocl::Device::*)() const>("max_parameter_size", &cv::ocl::Device::maxParameterSize).
    define_method<int(cv::ocl::Device::*)() const>("max_read_image_args", &cv::ocl::Device::maxReadImageArgs).
    define_method<int(cv::ocl::Device::*)() const>("max_write_image_args", &cv::ocl::Device::maxWriteImageArgs).
    define_method<int(cv::ocl::Device::*)() const>("max_samplers", &cv::ocl::Device::maxSamplers).
    define_method<size_t(cv::ocl::Device::*)() const>("max_work_group_size", &cv::ocl::Device::maxWorkGroupSize).
    define_method<int(cv::ocl::Device::*)() const>("max_work_item_dims", &cv::ocl::Device::maxWorkItemDims).
    define_method<void(cv::ocl::Device::*)(size_t*) const>("max_work_item_sizes", &cv::ocl::Device::maxWorkItemSizes,
      ArgBuffer("arg_0")).
    define_method<int(cv::ocl::Device::*)() const>("mem_base_addr_align", &cv::ocl::Device::memBaseAddrAlign).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_char", &cv::ocl::Device::nativeVectorWidthChar).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_short", &cv::ocl::Device::nativeVectorWidthShort).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_int", &cv::ocl::Device::nativeVectorWidthInt).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_long", &cv::ocl::Device::nativeVectorWidthLong).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_float", &cv::ocl::Device::nativeVectorWidthFloat).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_double", &cv::ocl::Device::nativeVectorWidthDouble).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_half", &cv::ocl::Device::nativeVectorWidthHalf).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_char", &cv::ocl::Device::preferredVectorWidthChar).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_short", &cv::ocl::Device::preferredVectorWidthShort).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_int", &cv::ocl::Device::preferredVectorWidthInt).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_long", &cv::ocl::Device::preferredVectorWidthLong).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_float", &cv::ocl::Device::preferredVectorWidthFloat).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_double", &cv::ocl::Device::preferredVectorWidthDouble).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_half", &cv::ocl::Device::preferredVectorWidthHalf).
    define_method<size_t(cv::ocl::Device::*)() const>("printf_buffer_size", &cv::ocl::Device::printfBufferSize).
    define_method<size_t(cv::ocl::Device::*)() const>("profiling_timer_resolution", &cv::ocl::Device::profilingTimerResolution).
    define_singleton_function<const cv::ocl::Device&(*)()>("get_default", &cv::ocl::Device::getDefault).
    define_singleton_function<cv::ocl::Device(*)(void*)>("from_handle", &cv::ocl::Device::fromHandle,
      ArgBuffer("d")).
    define_method<cv::ocl::Device::Impl*(cv::ocl::Device::*)() const>("get_impl", &cv::ocl::Device::getImpl).
    define_method<bool(cv::ocl::Device::*)() const>("empty?", &cv::ocl::Device::empty);

  rb_cCvOclDevice.define_constant("TYPE_DEFAULT", (int)cv::ocl::Device::TYPE_DEFAULT);
  rb_cCvOclDevice.define_constant("TYPE_CPU", (int)cv::ocl::Device::TYPE_CPU);
  rb_cCvOclDevice.define_constant("TYPE_GPU", (int)cv::ocl::Device::TYPE_GPU);
  rb_cCvOclDevice.define_constant("TYPE_ACCELERATOR", (int)cv::ocl::Device::TYPE_ACCELERATOR);
  rb_cCvOclDevice.define_constant("TYPE_DGPU", (int)cv::ocl::Device::TYPE_DGPU);
  rb_cCvOclDevice.define_constant("TYPE_IGPU", (int)cv::ocl::Device::TYPE_IGPU);
  rb_cCvOclDevice.define_constant("TYPE_ALL", (int)cv::ocl::Device::TYPE_ALL);

  rb_cCvOclDevice.define_constant("FP_DENORM", (int)cv::ocl::Device::FP_DENORM);
  rb_cCvOclDevice.define_constant("FP_INF_NAN", (int)cv::ocl::Device::FP_INF_NAN);
  rb_cCvOclDevice.define_constant("FP_ROUND_TO_NEAREST", (int)cv::ocl::Device::FP_ROUND_TO_NEAREST);
  rb_cCvOclDevice.define_constant("FP_ROUND_TO_ZERO", (int)cv::ocl::Device::FP_ROUND_TO_ZERO);
  rb_cCvOclDevice.define_constant("FP_ROUND_TO_INF", (int)cv::ocl::Device::FP_ROUND_TO_INF);
  rb_cCvOclDevice.define_constant("FP_FMA", (int)cv::ocl::Device::FP_FMA);
  rb_cCvOclDevice.define_constant("FP_SOFT_FLOAT", (int)cv::ocl::Device::FP_SOFT_FLOAT);
  rb_cCvOclDevice.define_constant("FP_CORRECTLY_ROUNDED_DIVIDE_SQRT", (int)cv::ocl::Device::FP_CORRECTLY_ROUNDED_DIVIDE_SQRT);

  rb_cCvOclDevice.define_constant("EXEC_KERNEL", (int)cv::ocl::Device::EXEC_KERNEL);
  rb_cCvOclDevice.define_constant("EXEC_NATIVE_KERNEL", (int)cv::ocl::Device::EXEC_NATIVE_KERNEL);

  rb_cCvOclDevice.define_constant("NO_CACHE", (int)cv::ocl::Device::NO_CACHE);
  rb_cCvOclDevice.define_constant("READ_ONLY_CACHE", (int)cv::ocl::Device::READ_ONLY_CACHE);
  rb_cCvOclDevice.define_constant("READ_WRITE_CACHE", (int)cv::ocl::Device::READ_WRITE_CACHE);

  rb_cCvOclDevice.define_constant("NO_LOCAL_MEM", (int)cv::ocl::Device::NO_LOCAL_MEM);
  rb_cCvOclDevice.define_constant("LOCAL_IS_LOCAL", (int)cv::ocl::Device::LOCAL_IS_LOCAL);
  rb_cCvOclDevice.define_constant("LOCAL_IS_GLOBAL", (int)cv::ocl::Device::LOCAL_IS_GLOBAL);

  rb_cCvOclDevice.define_constant("UNKNOWN_VENDOR", (int)cv::ocl::Device::UNKNOWN_VENDOR);
  rb_cCvOclDevice.define_constant("VENDOR_AMD", (int)cv::ocl::Device::VENDOR_AMD);
  rb_cCvOclDevice.define_constant("VENDOR_INTEL", (int)cv::ocl::Device::VENDOR_INTEL);
  rb_cCvOclDevice.define_constant("VENDOR_NVIDIA", (int)cv::ocl::Device::VENDOR_NVIDIA);

  Rice::Data_Type<cv::ocl::Context> rb_cCvOclContext = define_class_under<cv::ocl::Context>(rb_mCvOcl, "Context");

  Rice::Data_Type<cv::ocl::Context::Impl> rb_cCvOclContextImpl = define_class_under<cv::ocl::Context::Impl>(rb_cCvOclContext, "Impl");

  rb_cCvOclContext.
    define_constructor(Constructor<cv::ocl::Context>()).
    define_constructor(Constructor<cv::ocl::Context, int>(),
      Arg("dtype")).
    define_constructor(Constructor<cv::ocl::Context, const cv::ocl::Context&>(),
      Arg("c")).
    define_method<cv::ocl::Context&(cv::ocl::Context::*)(const cv::ocl::Context&)>("assign", &cv::ocl::Context::operator=,
      Arg("c")).
    define_method<cv::ocl::Context&(cv::ocl::Context::*)(cv::ocl::Context&&) noexcept>("assign", &cv::ocl::Context::operator=,
      Arg("c")).
    define_method<bool(cv::ocl::Context::*)()>("create?", &cv::ocl::Context::create).
    define_method<bool(cv::ocl::Context::*)(int)>("create", &cv::ocl::Context::create,
      Arg("dtype")).
    define_method<size_t(cv::ocl::Context::*)() const>("ndevices", &cv::ocl::Context::ndevices).
    define_method<cv::ocl::Device&(cv::ocl::Context::*)(size_t) const>("device", &cv::ocl::Context::device,
      Arg("idx")).
    define_method<cv::ocl::Program(cv::ocl::Context::*)(const cv::ocl::ProgramSource&, const cv::String&, cv::String&)>("get_prog", &cv::ocl::Context::getProg,
      Arg("prog"), Arg("buildopt"), Arg("errmsg")).
    define_method<void(cv::ocl::Context::*)(cv::ocl::Program&)>("unload_prog", &cv::ocl::Context::unloadProg,
      Arg("prog")).
    define_singleton_function<cv::ocl::Context&(*)(bool)>("get_default", &cv::ocl::Context::getDefault,
      Arg("initialize") = static_cast<bool>(true)).
    define_method<void*(cv::ocl::Context::*)() const>("ptr", &cv::ocl::Context::ptr,
      ReturnBuffer()).
    define_method<void*(cv::ocl::Context::*)(int) const>("get_open_cl_context_property", &cv::ocl::Context::getOpenCLContextProperty,
      Arg("property_id"), ReturnBuffer()).
    define_method<bool(cv::ocl::Context::*)() const>("use_svm?", &cv::ocl::Context::useSVM).
    define_method<void(cv::ocl::Context::*)(bool)>("set_use_svm", &cv::ocl::Context::setUseSVM,
      Arg("enabled")).
    define_singleton_function<cv::ocl::Context(*)(void*)>("from_handle", &cv::ocl::Context::fromHandle,
      ArgBuffer("context")).
    define_singleton_function<cv::ocl::Context(*)(const cv::ocl::Device&)>("from_device", &cv::ocl::Context::fromDevice,
      Arg("device")).
    define_singleton_function<cv::ocl::Context(*)(const std::string&)>("create", &cv::ocl::Context::create,
      Arg("configuration")).
    define_method<void(cv::ocl::Context::*)()>("release", &cv::ocl::Context::release).
    define_method<void(cv::ocl::Context::*)(std::type_index, const std::shared_ptr<cv::ocl::Context::UserContext>&)>("set_user_context", &cv::ocl::Context::setUserContext,
      Arg("type_id"), Arg("user_context")).
    define_method<std::shared_ptr<cv::ocl::Context::UserContext>(cv::ocl::Context::*)(std::type_index)>("get_user_context", &cv::ocl::Context::getUserContext,
      Arg("type_id")).
    define_method<cv::ocl::Context::Impl*(cv::ocl::Context::*)() const>("get_impl", &cv::ocl::Context::getImpl).
    define_method<bool(cv::ocl::Context::*)() const>("empty?", &cv::ocl::Context::empty).
    define_attr("p", &cv::ocl::Context::p);

  Rice::Data_Type<cv::ocl::Context::UserContext> rb_cCvOclContextUserContext = define_class_under<cv::ocl::Context::UserContext>(rb_cCvOclContext, "UserContext").
    define_constructor(Constructor<cv::ocl::Context::UserContext>());

  Rice::Data_Type<cv::ocl::Platform> rb_cCvOclPlatform = define_class_under<cv::ocl::Platform>(rb_mCvOcl, "Platform");

  Rice::Data_Type<cv::ocl::Platform::Impl> rb_cCvOclPlatformImpl = define_class_under<cv::ocl::Platform::Impl>(rb_cCvOclPlatform, "Impl");

  rb_cCvOclPlatform.
    define_constructor(Constructor<cv::ocl::Platform>()).
    define_constructor(Constructor<cv::ocl::Platform, const cv::ocl::Platform&>(),
      Arg("p")).
    define_method<cv::ocl::Platform&(cv::ocl::Platform::*)(const cv::ocl::Platform&)>("assign", &cv::ocl::Platform::operator=,
      Arg("p")).
    define_method<cv::ocl::Platform&(cv::ocl::Platform::*)(cv::ocl::Platform&&) noexcept>("assign", &cv::ocl::Platform::operator=,
      Arg("p")).
    define_method<void*(cv::ocl::Platform::*)() const>("ptr", &cv::ocl::Platform::ptr,
      ReturnBuffer()).
    define_singleton_function<cv::ocl::Platform&(*)()>("get_default", &cv::ocl::Platform::getDefault).
    define_method<cv::ocl::Platform::Impl*(cv::ocl::Platform::*)() const>("get_impl", &cv::ocl::Platform::getImpl).
    define_method<bool(cv::ocl::Platform::*)() const>("empty?", &cv::ocl::Platform::empty);

  rb_mCvOcl.define_module_function<void(*)(const cv::String&, void*, void*, void*)>("attach_context", &cv::ocl::attachContext,
    Arg("platform_name"), ArgBuffer("platform_id"), ArgBuffer("context"), ArgBuffer("device_id"));

  rb_mCvOcl.define_module_function<void(*)(void*, size_t, int, int, int, cv::UMat&)>("convert_from_buffer", &cv::ocl::convertFromBuffer,
    ArgBuffer("cl_mem_buffer"), Arg("step"), Arg("rows"), Arg("cols"), Arg("type"), Arg("dst"));

  rb_mCvOcl.define_module_function<void(*)(void*, cv::UMat&)>("convert_from_image", &cv::ocl::convertFromImage,
    ArgBuffer("cl_mem_image"), Arg("dst"));

  Rice::Data_Type<cv::ocl::Queue> rb_cCvOclQueue = define_class_under<cv::ocl::Queue>(rb_mCvOcl, "Queue");

  Rice::Data_Type<cv::ocl::Queue::Impl> rb_cCvOclQueueImpl = define_class_under<cv::ocl::Queue::Impl>(rb_cCvOclQueue, "Impl");

  rb_cCvOclQueue.
    define_constructor(Constructor<cv::ocl::Queue>()).
    define_constructor(Constructor<cv::ocl::Queue, const cv::ocl::Context&, const cv::ocl::Device&>(),
      Arg("c"), Arg("d") = static_cast<const cv::ocl::Device&>(cv::ocl::Device())).
    define_constructor(Constructor<cv::ocl::Queue, const cv::ocl::Queue&>(),
      Arg("q")).
    define_method<cv::ocl::Queue&(cv::ocl::Queue::*)(const cv::ocl::Queue&)>("assign", &cv::ocl::Queue::operator=,
      Arg("q")).
    define_method<cv::ocl::Queue&(cv::ocl::Queue::*)(cv::ocl::Queue&&) noexcept>("assign", &cv::ocl::Queue::operator=,
      Arg("q")).
    define_method<bool(cv::ocl::Queue::*)(const cv::ocl::Context&, const cv::ocl::Device&)>("create", &cv::ocl::Queue::create,
      Arg("c") = static_cast<const cv::ocl::Context&>(cv::ocl::Context()), Arg("d") = static_cast<const cv::ocl::Device&>(cv::ocl::Device())).
    define_method<void(cv::ocl::Queue::*)()>("finish", &cv::ocl::Queue::finish).
    define_method<void*(cv::ocl::Queue::*)() const>("ptr", &cv::ocl::Queue::ptr,
      ReturnBuffer()).
    define_singleton_function<cv::ocl::Queue&(*)()>("get_default", &cv::ocl::Queue::getDefault).
    define_method<const cv::ocl::Queue&(cv::ocl::Queue::*)() const>("get_profiling_queue", &cv::ocl::Queue::getProfilingQueue).
    define_method<cv::ocl::Queue::Impl*(cv::ocl::Queue::*)() const>("get_impl", &cv::ocl::Queue::getImpl).
    define_method<bool(cv::ocl::Queue::*)() const>("empty?", &cv::ocl::Queue::empty);

  Rice::Data_Type<cv::ocl::KernelArg> rb_cCvOclKernelArg = define_class_under<cv::ocl::KernelArg>(rb_mCvOcl, "KernelArg").
    define_constructor(Constructor<cv::ocl::KernelArg, int, cv::UMat*, int, int, const void*, size_t>(),
      Arg("_flags"), Arg("_m"), Arg("wscale") = static_cast<int>(1), Arg("iwscale") = static_cast<int>(1), ArgBuffer("_obj") = static_cast<const void*>(0), Arg("_sz") = static_cast<size_t>(0)).
    define_constructor(Constructor<cv::ocl::KernelArg>()).
    define_singleton_function<cv::ocl::KernelArg(*)(size_t)>("local", &cv::ocl::KernelArg::Local,
      Arg("local_mem_size")).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&)>("ptr_write_only", &cv::ocl::KernelArg::PtrWriteOnly,
      Arg("m")).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&)>("ptr_read_only", &cv::ocl::KernelArg::PtrReadOnly,
      Arg("m")).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&)>("ptr_read_write", &cv::ocl::KernelArg::PtrReadWrite,
      Arg("m")).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&, int, int)>("read_write", &cv::ocl::KernelArg::ReadWrite,
      Arg("m"), Arg("wscale") = static_cast<int>(1), Arg("iwscale") = static_cast<int>(1)).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&, int, int)>("read_write_no_size", &cv::ocl::KernelArg::ReadWriteNoSize,
      Arg("m"), Arg("wscale") = static_cast<int>(1), Arg("iwscale") = static_cast<int>(1)).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&, int, int)>("read_only", &cv::ocl::KernelArg::ReadOnly,
      Arg("m"), Arg("wscale") = static_cast<int>(1), Arg("iwscale") = static_cast<int>(1)).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&, int, int)>("write_only", &cv::ocl::KernelArg::WriteOnly,
      Arg("m"), Arg("wscale") = static_cast<int>(1), Arg("iwscale") = static_cast<int>(1)).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&, int, int)>("read_only_no_size", &cv::ocl::KernelArg::ReadOnlyNoSize,
      Arg("m"), Arg("wscale") = static_cast<int>(1), Arg("iwscale") = static_cast<int>(1)).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&, int, int)>("write_only_no_size", &cv::ocl::KernelArg::WriteOnlyNoSize,
      Arg("m"), Arg("wscale") = static_cast<int>(1), Arg("iwscale") = static_cast<int>(1)).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::Mat&)>("constant", &cv::ocl::KernelArg::Constant,
      Arg("m")).
    define_attr("flags", &cv::ocl::KernelArg::flags).
    define_attr("m", &cv::ocl::KernelArg::m).
    define_attr("obj", &cv::ocl::KernelArg::obj).
    define_attr("sz", &cv::ocl::KernelArg::sz).
    define_attr("wscale", &cv::ocl::KernelArg::wscale).
    define_attr("iwscale", &cv::ocl::KernelArg::iwscale);

  rb_cCvOclKernelArg.define_constant("LOCAL", (int)cv::ocl::KernelArg::LOCAL);
  rb_cCvOclKernelArg.define_constant("READ_ONLY", (int)cv::ocl::KernelArg::READ_ONLY);
  rb_cCvOclKernelArg.define_constant("WRITE_ONLY", (int)cv::ocl::KernelArg::WRITE_ONLY);
  rb_cCvOclKernelArg.define_constant("READ_WRITE", (int)cv::ocl::KernelArg::READ_WRITE);
  rb_cCvOclKernelArg.define_constant("CONSTANT", (int)cv::ocl::KernelArg::CONSTANT);
  rb_cCvOclKernelArg.define_constant("PTR_ONLY", (int)cv::ocl::KernelArg::PTR_ONLY);
  rb_cCvOclKernelArg.define_constant("NO_SIZE", (int)cv::ocl::KernelArg::NO_SIZE);

  Rice::Data_Type<cv::ocl::Kernel> rb_cCvOclKernel = define_class_under<cv::ocl::Kernel>(rb_mCvOcl, "Kernel");

  Rice::Data_Type<cv::ocl::Kernel::Impl> rb_cCvOclKernelImpl = define_class_under<cv::ocl::Kernel::Impl>(rb_cCvOclKernel, "Impl");

  rb_cCvOclKernel.
    define_constructor(Constructor<cv::ocl::Kernel>()).
    define_constructor(Constructor<cv::ocl::Kernel, const char*, const cv::ocl::Program&>(),
      Arg("kname"), Arg("prog")).
    define_constructor(Constructor<cv::ocl::Kernel, const char*, const cv::ocl::ProgramSource&, const cv::String&, cv::String*>(),
      Arg("kname"), Arg("prog"), Arg("buildopts") = static_cast<const cv::String&>(cv::String()), Arg("errmsg") = static_cast<cv::String*>(0)).
    define_constructor(Constructor<cv::ocl::Kernel, const cv::ocl::Kernel&>(),
      Arg("k")).
    define_method<cv::ocl::Kernel&(cv::ocl::Kernel::*)(const cv::ocl::Kernel&)>("assign", &cv::ocl::Kernel::operator=,
      Arg("k")).
    define_method<cv::ocl::Kernel&(cv::ocl::Kernel::*)(cv::ocl::Kernel&&) noexcept>("assign", &cv::ocl::Kernel::operator=,
      Arg("k")).
    define_method<bool(cv::ocl::Kernel::*)() const>("empty?", &cv::ocl::Kernel::empty).
    define_method<bool(cv::ocl::Kernel::*)(const char*, const cv::ocl::Program&)>("create", &cv::ocl::Kernel::create,
      Arg("kname"), Arg("prog")).
    define_method<bool(cv::ocl::Kernel::*)(const char*, const cv::ocl::ProgramSource&, const cv::String&, cv::String*)>("create", &cv::ocl::Kernel::create,
      Arg("kname"), Arg("prog"), Arg("buildopts"), Arg("errmsg") = static_cast<cv::String*>(0)).
    define_method<int(cv::ocl::Kernel::*)(int, const void*, size_t)>("set", &cv::ocl::Kernel::set,
      Arg("i"), ArgBuffer("value"), Arg("sz")).
    define_method<int(cv::ocl::Kernel::*)(int, const cv::ocl::Image2D&)>("set", &cv::ocl::Kernel::set,
      Arg("i"), Arg("image_2d")).
    define_method<int(cv::ocl::Kernel::*)(int, const cv::UMat&)>("set", &cv::ocl::Kernel::set,
      Arg("i"), Arg("m")).
    define_method<int(cv::ocl::Kernel::*)(int, const cv::ocl::KernelArg&)>("set", &cv::ocl::Kernel::set,
      Arg("i"), Arg("arg")).
    define_method<bool(cv::ocl::Kernel::*)(int, size_t[], size_t[], bool, const cv::ocl::Queue&)>("run", &cv::ocl::Kernel::run,
      Arg("dims"), Arg("globalsize"), Arg("localsize"), Arg("sync"), Arg("q") = static_cast<const cv::ocl::Queue&>(cv::ocl::Queue())).
    define_method<bool(cv::ocl::Kernel::*)(bool, const cv::ocl::Queue&)>("run_task", &cv::ocl::Kernel::runTask,
      Arg("sync"), Arg("q") = static_cast<const cv::ocl::Queue&>(cv::ocl::Queue())).
    define_method<int64(cv::ocl::Kernel::*)(int, size_t[], size_t[], const cv::ocl::Queue&)>("run_profiling", &cv::ocl::Kernel::runProfiling,
      Arg("dims"), Arg("globalsize"), Arg("localsize"), Arg("q") = static_cast<const cv::ocl::Queue&>(cv::ocl::Queue())).
    define_method<size_t(cv::ocl::Kernel::*)() const>("work_group_size", &cv::ocl::Kernel::workGroupSize).
    define_method<size_t(cv::ocl::Kernel::*)() const>("prefered_work_group_size_multiple", &cv::ocl::Kernel::preferedWorkGroupSizeMultiple).
    define_method<bool(cv::ocl::Kernel::*)(size_t[]) const>("compile_work_group_size", &cv::ocl::Kernel::compileWorkGroupSize,
      Arg("wsz")).
    define_method<size_t(cv::ocl::Kernel::*)() const>("local_mem_size", &cv::ocl::Kernel::localMemSize).
    define_method<void*(cv::ocl::Kernel::*)() const>("ptr", &cv::ocl::Kernel::ptr,
      ReturnBuffer());

  Rice::Data_Type<cv::ocl::Program> rb_cCvOclProgram = define_class_under<cv::ocl::Program>(rb_mCvOcl, "Program");

  Rice::Data_Type<cv::ocl::Program::Impl> rb_cCvOclProgramImpl = define_class_under<cv::ocl::Program::Impl>(rb_cCvOclProgram, "Impl");

  rb_cCvOclProgram.
    define_constructor(Constructor<cv::ocl::Program>()).
    define_constructor(Constructor<cv::ocl::Program, const cv::ocl::ProgramSource&, const cv::String&, cv::String&>(),
      Arg("src"), Arg("buildflags"), Arg("errmsg")).
    define_constructor(Constructor<cv::ocl::Program, const cv::ocl::Program&>(),
      Arg("prog")).
    define_method<cv::ocl::Program&(cv::ocl::Program::*)(const cv::ocl::Program&)>("assign", &cv::ocl::Program::operator=,
      Arg("prog")).
    define_method<cv::ocl::Program&(cv::ocl::Program::*)(cv::ocl::Program&&) noexcept>("assign", &cv::ocl::Program::operator=,
      Arg("prog")).
    define_method<bool(cv::ocl::Program::*)(const cv::ocl::ProgramSource&, const cv::String&, cv::String&)>("create", &cv::ocl::Program::create,
      Arg("src"), Arg("buildflags"), Arg("errmsg")).
    define_method<void*(cv::ocl::Program::*)() const>("ptr", &cv::ocl::Program::ptr,
      ReturnBuffer()).
    define_method<void(cv::ocl::Program::*)(std::vector<char>&) const>("get_binary", &cv::ocl::Program::getBinary,
      Arg("binary")).
    define_method<cv::ocl::Program::Impl*(cv::ocl::Program::*)() const>("get_impl", &cv::ocl::Program::getImpl).
    define_method<bool(cv::ocl::Program::*)() const>("empty?", &cv::ocl::Program::empty);

  Rice::Data_Type<cv::ocl::ProgramSource> rb_cCvOclProgramSource = define_class_under<cv::ocl::ProgramSource>(rb_mCvOcl, "ProgramSource");

  Rice::Data_Type<cv::ocl::ProgramSource::Impl> rb_cCvOclProgramSourceImpl = define_class_under<cv::ocl::ProgramSource::Impl>(rb_cCvOclProgramSource, "Impl");

  rb_cCvOclProgramSource.
    define_constructor(Constructor<cv::ocl::ProgramSource>()).
    define_constructor(Constructor<cv::ocl::ProgramSource, const cv::String&, const cv::String&, const cv::String&, const cv::String&>(),
      Arg("module"), Arg("name"), Arg("code_str"), Arg("code_hash")).
    define_constructor(Constructor<cv::ocl::ProgramSource, const cv::String&>(),
      Arg("prog")).
    define_constructor(Constructor<cv::ocl::ProgramSource, const char*>(),
      Arg("prog")).
    define_constructor(Constructor<cv::ocl::ProgramSource, const cv::ocl::ProgramSource&>(),
      Arg("prog")).
    define_method<cv::ocl::ProgramSource&(cv::ocl::ProgramSource::*)(const cv::ocl::ProgramSource&)>("assign", &cv::ocl::ProgramSource::operator=,
      Arg("prog")).
    define_method<cv::ocl::ProgramSource&(cv::ocl::ProgramSource::*)(cv::ocl::ProgramSource&&) noexcept>("assign", &cv::ocl::ProgramSource::operator=,
      Arg("prog")).
    define_method<const cv::String&(cv::ocl::ProgramSource::*)() const>("source", &cv::ocl::ProgramSource::source).
    define_method<cv::ocl::ProgramSource::hash_t(cv::ocl::ProgramSource::*)() const>("hash", &cv::ocl::ProgramSource::hash).
    define_singleton_function<cv::ocl::ProgramSource(*)(const cv::String&, const cv::String&, const unsigned char*, const size_t, const cv::String&)>("from_binary", &cv::ocl::ProgramSource::fromBinary,
      Arg("module"), Arg("name"), ArgBuffer("binary"), Arg("size"), Arg("build_options") = static_cast<const cv::String&>(cv::String())).
    define_singleton_function<cv::ocl::ProgramSource(*)(const cv::String&, const cv::String&, const unsigned char*, const size_t, const cv::String&)>("from_spir", &cv::ocl::ProgramSource::fromSPIR,
      Arg("module"), Arg("name"), ArgBuffer("binary"), Arg("size"), Arg("build_options") = static_cast<const cv::String&>(cv::String())).
    define_method<cv::ocl::ProgramSource::Impl*(cv::ocl::ProgramSource::*)() const>("get_impl", &cv::ocl::ProgramSource::getImpl).
    define_method<bool(cv::ocl::ProgramSource::*)() const>("empty?", &cv::ocl::ProgramSource::empty);

  Rice::Data_Type<cv::ocl::PlatformInfo> rb_cCvOclPlatformInfo = define_class_under<cv::ocl::PlatformInfo>(rb_mCvOcl, "PlatformInfo");

  Rice::Data_Type<cv::ocl::PlatformInfo::Impl> rb_cCvOclPlatformInfoImpl = define_class_under<cv::ocl::PlatformInfo::Impl>(rb_cCvOclPlatformInfo, "Impl");

  rb_cCvOclPlatformInfo.
    define_constructor(Constructor<cv::ocl::PlatformInfo>()).
    define_constructor(Constructor<cv::ocl::PlatformInfo, void*>(),
      ArgBuffer("id")).
    define_constructor(Constructor<cv::ocl::PlatformInfo, const cv::ocl::PlatformInfo&>(),
      Arg("i")).
    define_method<cv::ocl::PlatformInfo&(cv::ocl::PlatformInfo::*)(const cv::ocl::PlatformInfo&)>("assign", &cv::ocl::PlatformInfo::operator=,
      Arg("i")).
    define_method<cv::ocl::PlatformInfo&(cv::ocl::PlatformInfo::*)(cv::ocl::PlatformInfo&&) noexcept>("assign", &cv::ocl::PlatformInfo::operator=,
      Arg("i")).
    define_method<cv::String(cv::ocl::PlatformInfo::*)() const>("name", &cv::ocl::PlatformInfo::name).
    define_method<cv::String(cv::ocl::PlatformInfo::*)() const>("vendor", &cv::ocl::PlatformInfo::vendor).
    define_method<cv::String(cv::ocl::PlatformInfo::*)() const>("version", &cv::ocl::PlatformInfo::version).
    define_method<int(cv::ocl::PlatformInfo::*)() const>("device_number", &cv::ocl::PlatformInfo::deviceNumber).
    define_method<void(cv::ocl::PlatformInfo::*)(cv::ocl::Device&, int) const>("get_device", &cv::ocl::PlatformInfo::getDevice,
      Arg("device"), Arg("d")).
    define_method<bool(cv::ocl::PlatformInfo::*)() const>("empty?", &cv::ocl::PlatformInfo::empty);

  rb_mCvOcl.define_module_function<const char*(*)(int)>("type_to_str", &cv::ocl::typeToStr,
    Arg("t"));

  rb_mCvOcl.define_module_function<const char*(*)(int)>("memop_type_to_str", &cv::ocl::memopTypeToStr,
    Arg("t"));

  rb_mCvOcl.define_module_function<const char*(*)(int)>("vecop_type_to_str", &cv::ocl::vecopTypeToStr,
    Arg("t"));

  rb_mCvOcl.define_module_function<const char*(*)(int)>("get_open_cl_error_string", &cv::ocl::getOpenCLErrorString,
    Arg("error_code"));

  rb_mCvOcl.define_module_function<cv::String(*)(cv::InputArray, int, const char*)>("kernel_to_str", &cv::ocl::kernelToStr,
    Arg("_kernel"), Arg("ddepth") = static_cast<int>(-1), Arg("name") = static_cast<const char*>(NULL));

  rb_mCvOcl.define_module_function<void(*)(std::vector<cv::ocl::PlatformInfo>&)>("get_platfoms_info", &cv::ocl::getPlatfomsInfo,
    Arg("platform_info"));

  Enum<cv::ocl::OclVectorStrategy> rb_cCvOclOclVectorStrategy = define_enum_under<cv::ocl::OclVectorStrategy>("OclVectorStrategy", rb_mCvOcl).
    define_value("OCL_VECTOR_OWN", cv::ocl::OclVectorStrategy::OCL_VECTOR_OWN).
    define_value("OCL_VECTOR_MAX", cv::ocl::OclVectorStrategy::OCL_VECTOR_MAX).
    define_value("OCL_VECTOR_DEFAULT", cv::ocl::OclVectorStrategy::OCL_VECTOR_DEFAULT);

  rb_mCvOcl.define_module_function<int(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::ocl::OclVectorStrategy)>("predict_optimal_vector_width", &cv::ocl::predictOptimalVectorWidth,
    Arg("src1"), Arg("src2") = static_cast<cv::InputArray>(cv::noArray()), Arg("src3") = static_cast<cv::InputArray>(cv::noArray()), Arg("src4") = static_cast<cv::InputArray>(cv::noArray()), Arg("src5") = static_cast<cv::InputArray>(cv::noArray()), Arg("src6") = static_cast<cv::InputArray>(cv::noArray()), Arg("src7") = static_cast<cv::InputArray>(cv::noArray()), Arg("src8") = static_cast<cv::InputArray>(cv::noArray()), Arg("src9") = static_cast<cv::InputArray>(cv::noArray()), Arg("strat") = static_cast<cv::ocl::OclVectorStrategy>(cv::ocl::OCL_VECTOR_DEFAULT));

  rb_mCvOcl.define_module_function<int(*)(const int*, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::ocl::OclVectorStrategy)>("check_optimal_vector_width", &cv::ocl::checkOptimalVectorWidth,
    ArgBuffer("vector_widths"), Arg("src1"), Arg("src2") = static_cast<cv::InputArray>(cv::noArray()), Arg("src3") = static_cast<cv::InputArray>(cv::noArray()), Arg("src4") = static_cast<cv::InputArray>(cv::noArray()), Arg("src5") = static_cast<cv::InputArray>(cv::noArray()), Arg("src6") = static_cast<cv::InputArray>(cv::noArray()), Arg("src7") = static_cast<cv::InputArray>(cv::noArray()), Arg("src8") = static_cast<cv::InputArray>(cv::noArray()), Arg("src9") = static_cast<cv::InputArray>(cv::noArray()), Arg("strat") = static_cast<cv::ocl::OclVectorStrategy>(cv::ocl::OCL_VECTOR_DEFAULT));

  rb_mCvOcl.define_module_function<int(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray)>("predict_optimal_vector_width_max", &cv::ocl::predictOptimalVectorWidthMax,
    Arg("src1"), Arg("src2") = static_cast<cv::InputArray>(cv::noArray()), Arg("src3") = static_cast<cv::InputArray>(cv::noArray()), Arg("src4") = static_cast<cv::InputArray>(cv::noArray()), Arg("src5") = static_cast<cv::InputArray>(cv::noArray()), Arg("src6") = static_cast<cv::InputArray>(cv::noArray()), Arg("src7") = static_cast<cv::InputArray>(cv::noArray()), Arg("src8") = static_cast<cv::InputArray>(cv::noArray()), Arg("src9") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvOcl.define_module_function<void(*)(cv::String&, const cv::String&, cv::InputArray)>("build_options_add_matrix_description", &cv::ocl::buildOptionsAddMatrixDescription,
    Arg("build_options"), Arg("name"), Arg("_m"));

  Rice::Data_Type<cv::ocl::Image2D> rb_cCvOclImage2D = define_class_under<cv::ocl::Image2D>(rb_mCvOcl, "Image2D").
    define_constructor(Constructor<cv::ocl::Image2D>()).
    define_constructor(Constructor<cv::ocl::Image2D, const cv::UMat&, bool, bool>(),
      Arg("src"), Arg("norm") = static_cast<bool>(false), Arg("alias") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::ocl::Image2D, const cv::ocl::Image2D&>(),
      Arg("i")).
    define_method<cv::ocl::Image2D&(cv::ocl::Image2D::*)(const cv::ocl::Image2D&)>("assign", &cv::ocl::Image2D::operator=,
      Arg("i")).
    define_method<cv::ocl::Image2D&(cv::ocl::Image2D::*)(cv::ocl::Image2D&&) noexcept>("assign", &cv::ocl::Image2D::operator=,
      Arg("arg_0")).
    define_singleton_function<bool(*)(const cv::UMat&)>("can_create_alias", &cv::ocl::Image2D::canCreateAlias,
      Arg("u")).
    define_singleton_function<bool(*)(int, int, bool)>("format_supported?", &cv::ocl::Image2D::isFormatSupported,
      Arg("depth"), Arg("cn"), Arg("norm")).
    define_method<void*(cv::ocl::Image2D::*)() const>("ptr", &cv::ocl::Image2D::ptr,
      ReturnBuffer());

  Rice::Data_Type<cv::ocl::Timer> rb_cCvOclTimer = define_class_under<cv::ocl::Timer>(rb_mCvOcl, "Timer").
    define_constructor(Constructor<cv::ocl::Timer, const cv::ocl::Queue&>(),
      Arg("q")).
    define_method<void(cv::ocl::Timer::*)()>("start", &cv::ocl::Timer::start).
    define_method<void(cv::ocl::Timer::*)()>("stop", &cv::ocl::Timer::stop).
    define_method<uint64(cv::ocl::Timer::*)() const>("duration_ns", &cv::ocl::Timer::durationNS);

  rb_mCvOcl.define_module_function<cv::MatAllocator*(*)()>("get_open_cl_allocator", &cv::ocl::getOpenCLAllocator);

  Rice::Data_Type<cv::ocl::OpenCLExecutionContext> rb_cCvOclOpenCLExecutionContext = define_class_under<cv::ocl::OpenCLExecutionContext>(rb_mCvOcl, "OpenCLExecutionContext");

  Rice::Data_Type<cv::ocl::OpenCLExecutionContext::Impl> rb_cCvOclOpenCLExecutionContextImpl = define_class_under<cv::ocl::OpenCLExecutionContext::Impl>(rb_cCvOclOpenCLExecutionContext, "Impl");

  rb_cCvOclOpenCLExecutionContext.
    define_constructor(Constructor<cv::ocl::OpenCLExecutionContext>()).
    define_constructor(Constructor<cv::ocl::OpenCLExecutionContext, const cv::ocl::OpenCLExecutionContext&>(),
      Arg("arg_0")).
    define_method<cv::ocl::OpenCLExecutionContext&(cv::ocl::OpenCLExecutionContext::*)(const cv::ocl::OpenCLExecutionContext&)>("assign", &cv::ocl::OpenCLExecutionContext::operator=,
      Arg("arg_0")).
    define_method<cv::ocl::OpenCLExecutionContext&(cv::ocl::OpenCLExecutionContext::*)(cv::ocl::OpenCLExecutionContext&&)>("assign", &cv::ocl::OpenCLExecutionContext::operator=,
      Arg("arg_0")).
    define_method<cv::ocl::Context&(cv::ocl::OpenCLExecutionContext::*)() const>("get_context", &cv::ocl::OpenCLExecutionContext::getContext).
    define_method<cv::ocl::Device&(cv::ocl::OpenCLExecutionContext::*)() const>("get_device", &cv::ocl::OpenCLExecutionContext::getDevice).
    define_method<cv::ocl::Queue&(cv::ocl::OpenCLExecutionContext::*)() const>("get_queue", &cv::ocl::OpenCLExecutionContext::getQueue).
    define_method<bool(cv::ocl::OpenCLExecutionContext::*)() const>("use_open_cl?", &cv::ocl::OpenCLExecutionContext::useOpenCL).
    define_method<void(cv::ocl::OpenCLExecutionContext::*)(bool)>("set_use_open_cl", &cv::ocl::OpenCLExecutionContext::setUseOpenCL,
      Arg("flag")).
    define_singleton_function<cv::ocl::OpenCLExecutionContext&(*)()>("get_current", &cv::ocl::OpenCLExecutionContext::getCurrent).
    define_singleton_function<cv::ocl::OpenCLExecutionContext&(*)()>("get_current_ref", &cv::ocl::OpenCLExecutionContext::getCurrentRef).
    define_method<void(cv::ocl::OpenCLExecutionContext::*)() const>("bind", &cv::ocl::OpenCLExecutionContext::bind).
    define_method<cv::ocl::OpenCLExecutionContext(cv::ocl::OpenCLExecutionContext::*)(const cv::ocl::Queue&) const>("clone_with_new_queue", &cv::ocl::OpenCLExecutionContext::cloneWithNewQueue,
      Arg("q")).
    define_method<cv::ocl::OpenCLExecutionContext(cv::ocl::OpenCLExecutionContext::*)() const>("clone_with_new_queue", &cv::ocl::OpenCLExecutionContext::cloneWithNewQueue).
    define_singleton_function<cv::ocl::OpenCLExecutionContext(*)(const std::string&, void*, void*, void*)>("create", &cv::ocl::OpenCLExecutionContext::create,
      Arg("platform_name"), ArgBuffer("platform_id"), ArgBuffer("context"), ArgBuffer("device_id")).
    define_singleton_function<cv::ocl::OpenCLExecutionContext(*)(const cv::ocl::Context&, const cv::ocl::Device&, const cv::ocl::Queue&)>("create", &cv::ocl::OpenCLExecutionContext::create,
      Arg("context"), Arg("device"), Arg("queue")).
    define_singleton_function<cv::ocl::OpenCLExecutionContext(*)(const cv::ocl::Context&, const cv::ocl::Device&)>("create", &cv::ocl::OpenCLExecutionContext::create,
      Arg("context"), Arg("device")).
    define_method<bool(cv::ocl::OpenCLExecutionContext::*)() const>("empty?", &cv::ocl::OpenCLExecutionContext::empty).
    define_method<void(cv::ocl::OpenCLExecutionContext::*)()>("release", &cv::ocl::OpenCLExecutionContext::release);

  Rice::Data_Type<cv::ocl::OpenCLExecutionContextScope> rb_cCvOclOpenCLExecutionContextScope = define_class_under<cv::ocl::OpenCLExecutionContextScope>(rb_mCvOcl, "OpenCLExecutionContextScope").
    define_constructor(Constructor<cv::ocl::OpenCLExecutionContextScope, const cv::ocl::OpenCLExecutionContext&>(),
      Arg("ctx"));
}
