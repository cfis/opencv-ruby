#include <opencv2/core/cuda.hpp>
#include "cuda-rb.hpp"

using namespace Rice;

void Init_Core_Cuda()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::GpuMat> rb_cCvCudaGpuMat = define_class_under<cv::cuda::GpuMat>(rb_mCvCuda, "GpuMat").
    define_constructor(Constructor<cv::cuda::GpuMat, cv::cuda::GpuMat::Allocator*>(),
      Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    define_constructor(Constructor<cv::cuda::GpuMat, int, int, int, cv::cuda::GpuMat::Allocator*>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    define_constructor(Constructor<cv::cuda::GpuMat, cv::Size, int, cv::cuda::GpuMat::Allocator*>(),
      Arg("size"), Arg("type"), Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    define_constructor(Constructor<cv::cuda::GpuMat, int, int, int, cv::Scalar, cv::cuda::GpuMat::Allocator*>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("s"), Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    define_constructor(Constructor<cv::cuda::GpuMat, cv::Size, int, cv::Scalar, cv::cuda::GpuMat::Allocator*>(),
      Arg("size"), Arg("type"), Arg("s"), Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    define_constructor(Constructor<cv::cuda::GpuMat, const cv::cuda::GpuMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::cuda::GpuMat, int, int, int, void*, size_t>(),
      Arg("rows"), Arg("cols"), Arg("type"), ArgBuffer("data"), Arg("step") = static_cast<size_t>(cv::Mat::AUTO_STEP)).
    define_constructor(Constructor<cv::cuda::GpuMat, cv::Size, int, void*, size_t>(),
      Arg("size"), Arg("type"), ArgBuffer("data"), Arg("step") = static_cast<size_t>(cv::Mat::AUTO_STEP)).
    define_constructor(Constructor<cv::cuda::GpuMat, const cv::cuda::GpuMat&, cv::Range, cv::Range>(),
      Arg("m"), Arg("row_range"), Arg("col_range")).
    define_constructor(Constructor<cv::cuda::GpuMat, const cv::cuda::GpuMat&, cv::Rect>(),
      Arg("m"), Arg("roi")).
    define_constructor(Constructor<cv::cuda::GpuMat, cv::InputArray, cv::cuda::GpuMat::Allocator*>(),
      Arg("arr"), Arg("allocator") = static_cast<cv::cuda::GpuMat::Allocator*>(cv::cuda::GpuMat::defaultAllocator())).
    define_method("assign", &cv::cuda::GpuMat::operator=,
      Arg("m")).
    define_method<void(cv::cuda::GpuMat::*)(int, int, int)>("create", &cv::cuda::GpuMat::create,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_method<void(cv::cuda::GpuMat::*)(cv::Size, int)>("create", &cv::cuda::GpuMat::create,
      Arg("size"), Arg("type")).
    define_method("release", &cv::cuda::GpuMat::release).
    define_method("swap", &cv::cuda::GpuMat::swap,
      Arg("mat")).
    define_method<void(cv::cuda::GpuMat::*)(cv::InputArray)>("upload", &cv::cuda::GpuMat::upload,
      Arg("arr")).
    define_method<void(cv::cuda::GpuMat::*)(cv::InputArray, cv::cuda::Stream&)>("upload", &cv::cuda::GpuMat::upload,
      Arg("arr"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray) const>("download", &cv::cuda::GpuMat::download,
      Arg("dst")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, cv::cuda::Stream&) const>("download", &cv::cuda::GpuMat::download,
      Arg("dst"), Arg("stream")).
    define_method("clone", &cv::cuda::GpuMat::clone).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"));
// Manual
#if RUBY_CV_VERSION >= 409
  rb_cCvCudaGpuMat.
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"));
#endif
  rb_cCvCudaGpuMat.
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, cv::cuda::Stream&) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"), Arg("stream"));

#if RUBY_CV_VERSION >= 409
  rb_cCvCudaGpuMat.
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, cv::cuda::Stream&) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"), Arg("stream"));
#endif
  rb_cCvCudaGpuMat.
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, cv::InputArray) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"), Arg("mask"));

// Manual
#if RUBY_CV_VERSION >= 409
  rb_cCvCudaGpuMat.
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, cv::cuda::GpuMat&) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"), Arg("mask")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, cv::InputArray, cv::cuda::Stream&) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"), Arg("mask"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"), Arg("mask"), Arg("stream")).
    define_method<cv::cuda::GpuMat&(cv::cuda::GpuMat::*)(cv::Scalar)>("set_to", &cv::cuda::GpuMat::setTo,
      Arg("s")).
    define_method<cv::cuda::GpuMat&(cv::cuda::GpuMat::*)(cv::Scalar, cv::cuda::Stream&)>("set_to", &cv::cuda::GpuMat::setTo,
      Arg("s"), Arg("stream")).
    define_method<cv::cuda::GpuMat&(cv::cuda::GpuMat::*)(cv::Scalar, cv::InputArray)>("set_to", &cv::cuda::GpuMat::setTo,
      Arg("s"), Arg("mask")).
    define_method<cv::cuda::GpuMat&(cv::cuda::GpuMat::*)(cv::Scalar, cv::InputArray, cv::cuda::Stream&)>("set_to", &cv::cuda::GpuMat::setTo,
      Arg("s"), Arg("mask"), Arg("stream"));
#endif
  rb_cCvCudaGpuMat.
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, int) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, int, cv::cuda::Stream&) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("stream"));

// Manual
#if RUBY_CV_VERSION >= 409
  rb_cCvCudaGpuMat.
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, int, cv::cuda::Stream&) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, int, double, double) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("alpha"), Arg("beta") = static_cast<double>(0.0)).
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, int, double, double) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("alpha") = static_cast<double>(1.0), Arg("beta") = static_cast<double>(0.0)).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, int, double, cv::cuda::Stream&) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("alpha"), Arg("stream"));
#endif
  rb_cCvCudaGpuMat.
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, int, double, double, cv::cuda::Stream&) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("alpha"), Arg("beta"), Arg("stream"));

#if RUBY_CV_VERSION >= 409
  rb_cCvCudaGpuMat.
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, int, double, double, cv::cuda::Stream&) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("alpha"), Arg("beta"), Arg("stream")).
#endif
  rb_cCvCudaGpuMat.
    define_method("assign_to", &cv::cuda::GpuMat::assignTo,
      Arg("m"), Arg("type") = static_cast<int>(-1)).
    define_method<uchar*(cv::cuda::GpuMat::*)(int)>("ptr", &cv::cuda::GpuMat::ptr,
      Arg("y") = static_cast<int>(0)).
    define_method<const uchar*(cv::cuda::GpuMat::*)(int) const>("ptr", &cv::cuda::GpuMat::ptr,
      Arg("y") = static_cast<int>(0)).
    define_method("row", &cv::cuda::GpuMat::row,
      Arg("y")).
    define_method("col", &cv::cuda::GpuMat::col,
      Arg("x")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(int, int) const>("row_range", &cv::cuda::GpuMat::rowRange,
      Arg("startrow"), Arg("endrow")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(cv::Range) const>("row_range", &cv::cuda::GpuMat::rowRange,
      Arg("r")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(int, int) const>("col_range", &cv::cuda::GpuMat::colRange,
      Arg("startcol"), Arg("endcol")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(cv::Range) const>("col_range", &cv::cuda::GpuMat::colRange,
      Arg("r")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(cv::Range, cv::Range) const>("call", &cv::cuda::GpuMat::operator(),
      Arg("row_range"), Arg("col_range")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(cv::Rect) const>("call", &cv::cuda::GpuMat::operator(),
      Arg("roi")).
    define_method("reshape", &cv::cuda::GpuMat::reshape,
      Arg("cn"), Arg("rows") = static_cast<int>(0)).
    define_method("locate_roi", &cv::cuda::GpuMat::locateROI,
      Arg("whole_size"), Arg("ofs")).
    define_method("adjust_roi", &cv::cuda::GpuMat::adjustROI,
      Arg("dtop"), Arg("dbottom"), Arg("dleft"), Arg("dright")).
    define_method("continuous?", &cv::cuda::GpuMat::isContinuous).
    define_method("elem_size", &cv::cuda::GpuMat::elemSize).
    define_method("elem_size1", &cv::cuda::GpuMat::elemSize1).
    define_method("type", &cv::cuda::GpuMat::type).
    define_method("depth", &cv::cuda::GpuMat::depth).
    define_method("channels", &cv::cuda::GpuMat::channels).
    define_method("step1", &cv::cuda::GpuMat::step1).
    define_method("size", &cv::cuda::GpuMat::size).
    define_method("empty?", &cv::cuda::GpuMat::empty).
    define_method("cuda_ptr", &cv::cuda::GpuMat::cudaPtr,
      ReturnBuffer()).
    define_method("update_continuity_flag", &cv::cuda::GpuMat::updateContinuityFlag).
    define_attr("flags", &cv::cuda::GpuMat::flags).
    define_attr("rows", &cv::cuda::GpuMat::rows).
    define_attr("cols", &cv::cuda::GpuMat::cols).
    define_attr("step", &cv::cuda::GpuMat::step).
    define_attr("data", &cv::cuda::GpuMat::data).
    define_attr("refcount", &cv::cuda::GpuMat::refcount).
    define_attr("datastart", &cv::cuda::GpuMat::datastart).
    define_attr("dataend", &cv::cuda::GpuMat::dataend).
    define_attr("allocator", &cv::cuda::GpuMat::allocator).
    define_singleton_function("default_allocator", &cv::cuda::GpuMat::defaultAllocator).
    define_singleton_function("set_default_allocator", &cv::cuda::GpuMat::setDefaultAllocator,
      Arg("allocator")).
    define_singleton_function("get_std_allocator", &cv::cuda::GpuMat::getStdAllocator);

  Rice::Data_Type<cv::cuda::GpuMat::Allocator> rb_cCvCudaGpuMatAllocator = define_class_under<cv::cuda::GpuMat::Allocator>(rb_cCvCudaGpuMat, "Allocator").
    define_method("allocate", &cv::cuda::GpuMat::Allocator::allocate,
      Arg("mat"), Arg("rows"), Arg("cols"), Arg("elem_size")).
    define_method("free", &cv::cuda::GpuMat::Allocator::free,
      Arg("mat"));

  Rice::Data_Type<cv::cuda::GpuData> rb_cCvCudaGpuData = define_class_under<cv::cuda::GpuData>(rb_mCvCuda, "GpuData").
    define_constructor(Constructor<cv::cuda::GpuData, size_t>(),
      Arg("_size")).
    define_attr("data", &cv::cuda::GpuData::data).
    define_attr("size", &cv::cuda::GpuData::size);

  Rice::Data_Type<cv::cuda::GpuMatND> rb_cCvCudaGpuMatND = define_class_under<cv::cuda::GpuMatND>(rb_mCvCuda, "GpuMatND").
    define_constructor(Constructor<cv::cuda::GpuMatND>()).
    define_constructor(Constructor<cv::cuda::GpuMatND, cv::cuda::GpuMatND::SizeArray, int>(),
      Arg("size"), Arg("type")).
    define_constructor(Constructor<cv::cuda::GpuMatND, cv::cuda::GpuMatND::SizeArray, int, void*, cv::cuda::GpuMatND::StepArray>(),
      Arg("size"), Arg("type"), ArgBuffer("data"), Arg("step") = static_cast<cv::cuda::GpuMatND::StepArray>(cv::cuda::GpuMatND::StepArray())).
    define_method("create", &cv::cuda::GpuMatND::create,
      Arg("size"), Arg("type")).
    define_method("release", &cv::cuda::GpuMatND::release).
    define_method("swap", &cv::cuda::GpuMatND::swap,
      Arg("m")).
    define_method<cv::cuda::GpuMatND(cv::cuda::GpuMatND::*)() const>("clone", &cv::cuda::GpuMatND::clone).
    define_method<cv::cuda::GpuMatND(cv::cuda::GpuMatND::*)(cv::cuda::Stream&) const>("clone", &cv::cuda::GpuMatND::clone,
      Arg("stream")).
    define_method<cv::cuda::GpuMatND(cv::cuda::GpuMatND::*)(const std::vector<cv::Range>&) const>("call", &cv::cuda::GpuMatND::operator(),
      Arg("ranges")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMatND::*)(cv::cuda::GpuMatND::IndexArray, cv::Range, cv::Range) const>("create_gpu_mat_header", &cv::cuda::GpuMatND::createGpuMatHeader,
      Arg("idx"), Arg("row_range"), Arg("col_range")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMatND::*)() const>("create_gpu_mat_header", &cv::cuda::GpuMatND::createGpuMatHeader).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMatND::*)(cv::cuda::GpuMatND::IndexArray, cv::Range, cv::Range) const>("call", &cv::cuda::GpuMatND::operator(),
      Arg("idx"), Arg("row_range"), Arg("col_range")).
    define_method("to_gpu_mat", [](const cv::cuda::GpuMatND& self) -> cv::cuda::GpuMat
    {
      return self;
    }).
    define_constructor(Constructor<cv::cuda::GpuMatND, const cv::cuda::GpuMatND&>(),
      Arg("arg_0")).
    define_method<cv::cuda::GpuMatND&(cv::cuda::GpuMatND::*)(const cv::cuda::GpuMatND&)>("assign", &cv::cuda::GpuMatND::operator=,
      Arg("arg_0")).
    define_method<cv::cuda::GpuMatND&(cv::cuda::GpuMatND::*)(cv::cuda::GpuMatND&&)>("assign", &cv::cuda::GpuMatND::operator=,
      Arg("arg_0")).
    define_method<void(cv::cuda::GpuMatND::*)(cv::InputArray)>("upload", &cv::cuda::GpuMatND::upload,
      Arg("src")).
    define_method<void(cv::cuda::GpuMatND::*)(cv::InputArray, cv::cuda::Stream&)>("upload", &cv::cuda::GpuMatND::upload,
      Arg("src"), Arg("stream")).
    define_method<void(cv::cuda::GpuMatND::*)(cv::OutputArray) const>("download", &cv::cuda::GpuMatND::download,
      Arg("dst")).
    define_method<void(cv::cuda::GpuMatND::*)(cv::OutputArray, cv::cuda::Stream&) const>("download", &cv::cuda::GpuMatND::download,
      Arg("dst"), Arg("stream")).
    define_method("continuous?", &cv::cuda::GpuMatND::isContinuous).
    define_method("submatrix?", &cv::cuda::GpuMatND::isSubmatrix).
    define_method("elem_size", &cv::cuda::GpuMatND::elemSize).
    define_method("elem_size1", &cv::cuda::GpuMatND::elemSize1).
    define_method("empty?", &cv::cuda::GpuMatND::empty).
    define_method("external?", &cv::cuda::GpuMatND::external).
    define_method("get_device_ptr", &cv::cuda::GpuMatND::getDevicePtr).
    define_method("total", &cv::cuda::GpuMatND::total).
    define_method("total_mem_size", &cv::cuda::GpuMatND::totalMemSize).
    define_method("type", &cv::cuda::GpuMatND::type).
    define_attr("flags", &cv::cuda::GpuMatND::flags).
    define_attr("dims", &cv::cuda::GpuMatND::dims).
    define_attr("size", &cv::cuda::GpuMatND::size).
    define_attr("step", &cv::cuda::GpuMatND::step);

  /* TODO
  rb_mCvCuda.define_module_function("create_continuous", &cv::cuda::createContinuous,
    Arg("rows"), Arg("cols"), Arg("type"), Arg("arr"));

  rb_mCvCuda.define_module_function("ensure_size_is_enough", &cv::cuda::ensureSizeIsEnough,
    Arg("rows"), Arg("cols"), Arg("type"), Arg("arr"));"));*/

#if RUBY_CV_VERSION >= 409
  rb_mCvCuda.define_module_function<cv::cuda::GpuMat(*)(int, int, int, size_t, size_t)>("create_gpu_mat_from_cuda_memory", &cv::cuda::createGpuMatFromCudaMemory,
    Arg("rows"), Arg("cols"), Arg("type"), Arg("cuda_memory_address"), Arg("step") = static_cast<size_t>(cv::Mat::AUTO_STEP));
#endif

  rb_mCvCuda.define_module_function<cv::cuda::GpuMat(*)(cv::Size, int, size_t, size_t)>("create_gpu_mat_from_cuda_memory", &cv::cuda::createGpuMatFromCudaMemory,
    Arg("size"), Arg("type"), Arg("cuda_memory_address"), Arg("step") = static_cast<size_t>(cv::Mat::AUTO_STEP));

  Rice::Data_Type<cv::cuda::BufferPool> rb_cCvCudaBufferPool = define_class_under<cv::cuda::BufferPool>(rb_mCvCuda, "BufferPool").
    define_constructor(Constructor<cv::cuda::BufferPool, cv::cuda::Stream&>(),
      Arg("stream")).
    define_method<cv::cuda::GpuMat(cv::cuda::BufferPool::*)(int, int, int)>("get_buffer", &cv::cuda::BufferPool::getBuffer,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_method<cv::cuda::GpuMat(cv::cuda::BufferPool::*)(cv::Size, int)>("get_buffer", &cv::cuda::BufferPool::getBuffer,
      Arg("size"), Arg("type")).
    define_method("get_allocator", &cv::cuda::BufferPool::getAllocator);

  rb_mCvCuda.define_module_function("set_buffer_pool_usage", &cv::cuda::setBufferPoolUsage,
    Arg("on"));

  rb_mCvCuda.define_module_function("set_buffer_pool_config", &cv::cuda::setBufferPoolConfig,
    Arg("device_id"), Arg("stack_size"), Arg("stack_count"));

  Rice::Data_Type<cv::cuda::HostMem> rb_cCvCudaHostMem = define_class_under<cv::cuda::HostMem>(rb_mCvCuda, "HostMem").
    define_constructor(Constructor<cv::cuda::HostMem, cv::cuda::HostMem::AllocType>(),
      Arg("alloc_type") = static_cast<cv::cuda::HostMem::AllocType>(cv::cuda::HostMem::AllocType::PAGE_LOCKED)).
    define_constructor(Constructor<cv::cuda::HostMem, const cv::cuda::HostMem&>(),
      Arg("m")).
    define_constructor(Constructor<cv::cuda::HostMem, int, int, int, cv::cuda::HostMem::AllocType>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("alloc_type") = static_cast<cv::cuda::HostMem::AllocType>(cv::cuda::HostMem::AllocType::PAGE_LOCKED)).
    define_constructor(Constructor<cv::cuda::HostMem, cv::Size, int, cv::cuda::HostMem::AllocType>(),
      Arg("size"), Arg("type"), Arg("alloc_type") = static_cast<cv::cuda::HostMem::AllocType>(cv::cuda::HostMem::AllocType::PAGE_LOCKED)).
    define_constructor(Constructor<cv::cuda::HostMem, cv::InputArray, cv::cuda::HostMem::AllocType>(),
      Arg("arr"), Arg("alloc_type") = static_cast<cv::cuda::HostMem::AllocType>(cv::cuda::HostMem::AllocType::PAGE_LOCKED)).
    define_method("assign", &cv::cuda::HostMem::operator=,
      Arg("m")).
    define_method("swap", &cv::cuda::HostMem::swap,
      Arg("b")).
    define_method("clone", &cv::cuda::HostMem::clone).
    define_method<void(cv::cuda::HostMem::*)(int, int, int)>("create", &cv::cuda::HostMem::create,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_method<void(cv::cuda::HostMem::*)(cv::Size, int)>("create", &cv::cuda::HostMem::create,
      Arg("size"), Arg("type")).
    define_method("reshape", &cv::cuda::HostMem::reshape,
      Arg("cn"), Arg("rows") = static_cast<int>(0)).
    define_method("release", &cv::cuda::HostMem::release).
    define_method("create_mat_header", &cv::cuda::HostMem::createMatHeader).
    define_method("create_gpu_mat_header", &cv::cuda::HostMem::createGpuMatHeader).
    define_method("continuous?", &cv::cuda::HostMem::isContinuous).
    define_method("elem_size", &cv::cuda::HostMem::elemSize).
    define_method("elem_size1", &cv::cuda::HostMem::elemSize1).
    define_method("type", &cv::cuda::HostMem::type).
    define_method("depth", &cv::cuda::HostMem::depth).
    define_method("channels", &cv::cuda::HostMem::channels).
    define_method("step1", &cv::cuda::HostMem::step1).
    define_method("size", &cv::cuda::HostMem::size).
    define_method("empty?", &cv::cuda::HostMem::empty).
    define_attr("flags", &cv::cuda::HostMem::flags).
    define_attr("rows", &cv::cuda::HostMem::rows).
    define_attr("cols", &cv::cuda::HostMem::cols).
    define_attr("step", &cv::cuda::HostMem::step).
    define_attr("data", &cv::cuda::HostMem::data).
    define_attr("refcount", &cv::cuda::HostMem::refcount).
    define_attr("datastart", &cv::cuda::HostMem::datastart).
    define_attr("dataend", &cv::cuda::HostMem::dataend).
    define_attr("alloc_type", &cv::cuda::HostMem::alloc_type).
    define_singleton_function("get_allocator", &cv::cuda::HostMem::getAllocator,
      Arg("alloc_type") = static_cast<cv::cuda::HostMem::AllocType>(cv::cuda::HostMem::AllocType::PAGE_LOCKED));

  Enum<cv::cuda::HostMem::AllocType> rb_cCvCudaHostMemAllocType = define_enum_under<cv::cuda::HostMem::AllocType>("AllocType", rb_cCvCudaHostMem).
    define_value("PAGE_LOCKED", cv::cuda::HostMem::AllocType::PAGE_LOCKED).
    define_value("SHARED", cv::cuda::HostMem::AllocType::SHARED).
    define_value("WRITE_COMBINED", cv::cuda::HostMem::AllocType::WRITE_COMBINED);

  rb_mCvCuda.define_module_function("register_page_locked", &cv::cuda::registerPageLocked,
    Arg("m"));

  rb_mCvCuda.define_module_function("unregister_page_locked", &cv::cuda::unregisterPageLocked,
    Arg("m"));

  Rice::Data_Type<cv::cuda::Stream> rb_cCvCudaStream = define_class_under<cv::cuda::Stream>(rb_mCvCuda, "Stream");

  Rice::Data_Type<cv::cuda::Stream::Impl> rb_cCvCudaStreamImpl = define_class_under<cv::cuda::Stream::Impl>(rb_cCvCudaStream, "Impl");

  rb_cCvCudaStream.
    define_constructor(Constructor<cv::cuda::Stream>()).
    define_constructor(Constructor<cv::cuda::Stream, const cv::Ptr<cv::cuda::GpuMat::Allocator>&>(),
      Arg("allocator")).
    define_constructor(Constructor<cv::cuda::Stream, const size_t>(),
      Arg("cuda_flags")).
    define_method("query_if_complete?", &cv::cuda::Stream::queryIfComplete).
    define_method("wait_for_completion", &cv::cuda::Stream::waitForCompletion).
    define_method("wait_event", &cv::cuda::Stream::waitEvent,
      Arg("event")).
    define_method("enqueue_host_callback", &cv::cuda::Stream::enqueueHostCallback,
      Arg("callback"), ArgBuffer("user_data")).
    define_method("cuda_ptr", &cv::cuda::Stream::cudaPtr,
      ReturnBuffer()).
    define_singleton_function("null", &cv::cuda::Stream::Null);

  rb_mCvCuda.define_module_function("wrap_stream", &cv::cuda::wrapStream,
    Arg("cuda_stream_memory_address"));

  Rice::Data_Type<cv::cuda::Event> rb_cCvCudaEvent = define_class_under<cv::cuda::Event>(rb_mCvCuda, "Event");

  Rice::Data_Type<cv::cuda::Event::Impl> rb_cCvCudaEventImpl = define_class_under<cv::cuda::Event::Impl>(rb_cCvCudaEvent, "Impl");

  rb_cCvCudaEvent.
    define_constructor(Constructor<cv::cuda::Event, const cv::cuda::Event::CreateFlags>(),
      Arg("flags") = static_cast<const cv::cuda::Event::CreateFlags>(cv::cuda::Event::CreateFlags::DEFAULT)).
    define_method("record", &cv::cuda::Event::record,
      Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())).
    define_method("query_if_complete?", &cv::cuda::Event::queryIfComplete).
    define_method("wait_for_completion", &cv::cuda::Event::waitForCompletion).
    define_singleton_function("elapsed_time", &cv::cuda::Event::elapsedTime,
      Arg("start"), Arg("end"));

  Enum<cv::cuda::Event::CreateFlags> rb_cCvCudaEventCreateFlags = define_enum_under<cv::cuda::Event::CreateFlags>("CreateFlags", rb_cCvCudaEvent).
    define_value("DEFAULT", cv::cuda::Event::CreateFlags::DEFAULT).
    define_value("BLOCKING_SYNC", cv::cuda::Event::CreateFlags::BLOCKING_SYNC).
    define_value("DISABLE_TIMING", cv::cuda::Event::CreateFlags::DISABLE_TIMING).
    define_value("INTERPROCESS", cv::cuda::Event::CreateFlags::INTERPROCESS);

  rb_mCvCuda.define_module_function("get_cuda_enabled_device_count", &cv::cuda::getCudaEnabledDeviceCount);

  rb_mCvCuda.define_module_function("set_device", &cv::cuda::setDevice,
    Arg("device"));

  rb_mCvCuda.define_module_function("get_device", &cv::cuda::getDevice);

  rb_mCvCuda.define_module_function("reset_device", &cv::cuda::resetDevice);

  Enum<cv::cuda::FeatureSet> rb_cCvCudaFeatureSet = define_enum_under<cv::cuda::FeatureSet>("FeatureSet", rb_mCvCuda).
    define_value("FEATURE_SET_COMPUTE_10", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_10).
    define_value("FEATURE_SET_COMPUTE_11", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_11).
    define_value("FEATURE_SET_COMPUTE_12", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_12).
    define_value("FEATURE_SET_COMPUTE_13", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_13).
    define_value("FEATURE_SET_COMPUTE_20", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_20).
    define_value("FEATURE_SET_COMPUTE_21", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_21).
    define_value("FEATURE_SET_COMPUTE_30", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_30).
    define_value("FEATURE_SET_COMPUTE_32", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_32).
    define_value("FEATURE_SET_COMPUTE_35", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_35).
    define_value("FEATURE_SET_COMPUTE_50", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_50).
    define_value("GLOBAL_ATOMICS", cv::cuda::FeatureSet::GLOBAL_ATOMICS).
    define_value("SHARED_ATOMICS", cv::cuda::FeatureSet::SHARED_ATOMICS).
    define_value("NATIVE_DOUBLE", cv::cuda::FeatureSet::NATIVE_DOUBLE).
    define_value("WARP_SHUFFLE_FUNCTIONS", cv::cuda::FeatureSet::WARP_SHUFFLE_FUNCTIONS).
    define_value("DYNAMIC_PARALLELISM", cv::cuda::FeatureSet::DYNAMIC_PARALLELISM);

  rb_mCvCuda.define_module_function("device_supports", &cv::cuda::deviceSupports,
    Arg("feature_set"));

  Rice::Data_Type<cv::cuda::TargetArchs> rb_cCvCudaTargetArchs = define_class_under<cv::cuda::TargetArchs>(rb_mCvCuda, "TargetArchs").
    define_constructor(Constructor<cv::cuda::TargetArchs>()).
    define_singleton_function("built_with", &cv::cuda::TargetArchs::builtWith,
      Arg("feature_set")).
    define_singleton_function("has", &cv::cuda::TargetArchs::has,
      Arg("major"), Arg("minor")).
    define_singleton_function("has_ptx", &cv::cuda::TargetArchs::hasPtx,
      Arg("major"), Arg("minor")).
    define_singleton_function("has_bin", &cv::cuda::TargetArchs::hasBin,
      Arg("major"), Arg("minor")).
    define_singleton_function("has_equal_or_less_ptx", &cv::cuda::TargetArchs::hasEqualOrLessPtx,
      Arg("major"), Arg("minor")).
    define_singleton_function("has_equal_or_greater", &cv::cuda::TargetArchs::hasEqualOrGreater,
      Arg("major"), Arg("minor")).
    define_singleton_function("has_equal_or_greater_ptx", &cv::cuda::TargetArchs::hasEqualOrGreaterPtx,
      Arg("major"), Arg("minor")).
    define_singleton_function("has_equal_or_greater_bin", &cv::cuda::TargetArchs::hasEqualOrGreaterBin,
      Arg("major"), Arg("minor"));

  Rice::Data_Type<cv::cuda::DeviceInfo> rb_cCvCudaDeviceInfo = define_class_under<cv::cuda::DeviceInfo>(rb_mCvCuda, "DeviceInfo").
    define_constructor(Constructor<cv::cuda::DeviceInfo>()).
    define_constructor(Constructor<cv::cuda::DeviceInfo, int>(),
      Arg("device_id")).
    define_method("device_id", &cv::cuda::DeviceInfo::deviceID).
    define_method("name", &cv::cuda::DeviceInfo::name).
    define_method("total_global_mem", &cv::cuda::DeviceInfo::totalGlobalMem).
    define_method("shared_mem_per_block", &cv::cuda::DeviceInfo::sharedMemPerBlock).
    define_method("regs_per_block", &cv::cuda::DeviceInfo::regsPerBlock).
    define_method("warp_size", &cv::cuda::DeviceInfo::warpSize).
    define_method("mem_pitch", &cv::cuda::DeviceInfo::memPitch).
    define_method("max_threads_per_block", &cv::cuda::DeviceInfo::maxThreadsPerBlock).
    define_method("max_threads_dim", &cv::cuda::DeviceInfo::maxThreadsDim).
    define_method("max_grid_size", &cv::cuda::DeviceInfo::maxGridSize).
    define_method("clock_rate", &cv::cuda::DeviceInfo::clockRate).
    define_method("total_const_mem", &cv::cuda::DeviceInfo::totalConstMem).
    define_method("major_version", &cv::cuda::DeviceInfo::majorVersion).
    define_method("minor_version", &cv::cuda::DeviceInfo::minorVersion).
    define_method("texture_alignment", &cv::cuda::DeviceInfo::textureAlignment).
    define_method("texture_pitch_alignment", &cv::cuda::DeviceInfo::texturePitchAlignment).
    define_method("multi_processor_count", &cv::cuda::DeviceInfo::multiProcessorCount).
    define_method("kernel_exec_timeout_enabled?", &cv::cuda::DeviceInfo::kernelExecTimeoutEnabled).
    define_method("integrated?", &cv::cuda::DeviceInfo::integrated).
    define_method("can_map_host_memory?", &cv::cuda::DeviceInfo::canMapHostMemory).
    define_method("compute_mode", &cv::cuda::DeviceInfo::computeMode).
    define_method("max_texture_1d", &cv::cuda::DeviceInfo::maxTexture1D).
    define_method("max_texture_1d_mipmap", &cv::cuda::DeviceInfo::maxTexture1DMipmap).
    define_method("max_texture_1d_linear", &cv::cuda::DeviceInfo::maxTexture1DLinear).
    define_method("max_texture_2d", &cv::cuda::DeviceInfo::maxTexture2D).
    define_method("max_texture_2d_mipmap", &cv::cuda::DeviceInfo::maxTexture2DMipmap).
    define_method("max_texture_2d_linear", &cv::cuda::DeviceInfo::maxTexture2DLinear).
    define_method("max_texture_2d_gather", &cv::cuda::DeviceInfo::maxTexture2DGather).
    define_method("max_texture_3d", &cv::cuda::DeviceInfo::maxTexture3D).
    define_method("max_texture_cubemap", &cv::cuda::DeviceInfo::maxTextureCubemap).
    define_method("max_texture_1d_layered", &cv::cuda::DeviceInfo::maxTexture1DLayered).
    define_method("max_texture_2d_layered", &cv::cuda::DeviceInfo::maxTexture2DLayered).
    define_method("max_texture_cubemap_layered", &cv::cuda::DeviceInfo::maxTextureCubemapLayered).
    define_method("max_surface_1d", &cv::cuda::DeviceInfo::maxSurface1D).
    define_method("max_surface_2d", &cv::cuda::DeviceInfo::maxSurface2D).
    define_method("max_surface_3d", &cv::cuda::DeviceInfo::maxSurface3D).
    define_method("max_surface_1d_layered", &cv::cuda::DeviceInfo::maxSurface1DLayered).
    define_method("max_surface_2d_layered", &cv::cuda::DeviceInfo::maxSurface2DLayered).
    define_method("max_surface_cubemap", &cv::cuda::DeviceInfo::maxSurfaceCubemap).
    define_method("max_surface_cubemap_layered", &cv::cuda::DeviceInfo::maxSurfaceCubemapLayered).
    define_method("surface_alignment", &cv::cuda::DeviceInfo::surfaceAlignment).
    define_method("concurrent_kernels?", &cv::cuda::DeviceInfo::concurrentKernels).
    define_method("ecc_enabled?", &cv::cuda::DeviceInfo::ECCEnabled).
    define_method("pci_bus_id", &cv::cuda::DeviceInfo::pciBusID).
    define_method("pci_device_id", &cv::cuda::DeviceInfo::pciDeviceID).
    define_method("pci_domain_id", &cv::cuda::DeviceInfo::pciDomainID).
    define_method("tcc_driver?", &cv::cuda::DeviceInfo::tccDriver).
    define_method("async_engine_count", &cv::cuda::DeviceInfo::asyncEngineCount).
    define_method("unified_addressing?", &cv::cuda::DeviceInfo::unifiedAddressing).
    define_method("memory_clock_rate", &cv::cuda::DeviceInfo::memoryClockRate).
    define_method("memory_bus_width", &cv::cuda::DeviceInfo::memoryBusWidth).
    define_method("l2_cache_size", &cv::cuda::DeviceInfo::l2CacheSize).
    define_method("max_threads_per_multi_processor", &cv::cuda::DeviceInfo::maxThreadsPerMultiProcessor).
    define_method("query_memory", &cv::cuda::DeviceInfo::queryMemory,
      Arg("total_memory"), Arg("free_memory")).
    define_method("free_memory", &cv::cuda::DeviceInfo::freeMemory).
    define_method("total_memory", &cv::cuda::DeviceInfo::totalMemory).
    define_method("supports", &cv::cuda::DeviceInfo::supports,
      Arg("feature_set")).
    define_method("compatible?", &cv::cuda::DeviceInfo::isCompatible);

  Enum<cv::cuda::DeviceInfo::ComputeMode> rb_cCvCudaDeviceInfoComputeMode = define_enum_under<cv::cuda::DeviceInfo::ComputeMode>("ComputeMode", rb_cCvCudaDeviceInfo).
    define_value("ComputeModeDefault", cv::cuda::DeviceInfo::ComputeMode::ComputeModeDefault).
    define_value("ComputeModeExclusive", cv::cuda::DeviceInfo::ComputeMode::ComputeModeExclusive).
    define_value("ComputeModeProhibited", cv::cuda::DeviceInfo::ComputeMode::ComputeModeProhibited).
    define_value("ComputeModeExclusiveProcess", cv::cuda::DeviceInfo::ComputeMode::ComputeModeExclusiveProcess);

  rb_mCvCuda.define_module_function("print_cuda_device_info", &cv::cuda::printCudaDeviceInfo,
    Arg("device"));

  rb_mCvCuda.define_module_function("print_short_cuda_device_info", &cv::cuda::printShortCudaDeviceInfo,
    Arg("device"));

  // TODO - linker error
  //rb_mCvCuda.define_module_function("convert_fp16", &cv::cuda::convertFp16,
  //  Arg("_src"), Arg("_dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));
}