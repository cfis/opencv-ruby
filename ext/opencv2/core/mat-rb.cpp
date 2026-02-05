#include <opencv2/core/cuda.hpp> // Manual
#include <opencv2/core/opengl.hpp> // Manual
#include <opencv2/core/mat.hpp>
#include "types-rb.hpp" // Manual
#include "refinements/mat-iterators.hpp" // Manual
#include "mat-rb.hpp"

using namespace Rice;

#include "mat-rb.ipp"

void Init_Core_Mat()
{
  Module rb_mCv = define_module("Cv");

  Enum<cv::AccessFlag> rb_cCvAccessFlag = define_enum_under<cv::AccessFlag>("AccessFlag", rb_mCv).
    define_value("ACCESS_READ", cv::AccessFlag::ACCESS_READ).
    define_value("ACCESS_WRITE", cv::AccessFlag::ACCESS_WRITE).
    define_value("ACCESS_RW", cv::AccessFlag::ACCESS_RW).
    define_value("ACCESS_MASK", cv::AccessFlag::ACCESS_MASK).
    define_value("ACCESS_FAST", cv::AccessFlag::ACCESS_FAST);

  Rice::Data_Type<cv::_InputArray> rb_cCvInputArray = define_class_under<cv::_InputArray>(rb_mCv, "InputArray").
    define_constructor(Constructor<cv::_InputArray>()).
    define_constructor(Constructor<cv::_InputArray, int, void*>(),
      Arg("_flags"), ArgBuffer("_obj")).
    define_constructor(Constructor<cv::_InputArray, const cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_InputArray, const cv::MatExpr&>(),
      Arg("expr")).
    define_constructor(Constructor<cv::_InputArray, const std::vector<cv::Mat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_InputArray, const std::vector<bool>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_InputArray, const double&>(),
      Arg("val")).
    define_constructor(Constructor<cv::_InputArray, const cv::cuda::GpuMat&>(),
      Arg("d_mat")).
    define_constructor(Constructor<cv::_InputArray, const std::vector<cv::cuda::GpuMat>&>(),
      Arg("d_mat_array")).
    define_constructor(Constructor<cv::_InputArray, const cv::ogl::Buffer&>(),
      Arg("buf")).
    define_constructor(Constructor<cv::_InputArray, const cv::cuda::HostMem&>(),
      Arg("cuda_mem")).
    define_constructor(Constructor<cv::_InputArray, const cv::UMat&>(),
      Arg("um")).
    define_constructor(Constructor<cv::_InputArray, const std::vector<cv::UMat>&>(),
      Arg("umv")).
    define_method<cv::Mat(cv::_InputArray::*)(int) const>("get_mat", &cv::_InputArray::getMat,
      Arg("idx") = static_cast<int>(-1)).
    define_method<cv::UMat(cv::_InputArray::*)(int) const>("get_u_mat", &cv::_InputArray::getUMat,
      Arg("idx") = static_cast<int>(-1)).
    define_method<void(cv::_InputArray::*)(std::vector<cv::Mat>&) const>("get_mat_vector", &cv::_InputArray::getMatVector,
      Arg("mv")).
    define_method<void(cv::_InputArray::*)(std::vector<cv::UMat>&) const>("get_u_mat_vector", &cv::_InputArray::getUMatVector,
      Arg("umv")).
    define_method<void(cv::_InputArray::*)(std::vector<cv::cuda::GpuMat>&) const>("get_gpu_mat_vector", &cv::_InputArray::getGpuMatVector,
      Arg("gpumv")).
    define_method<cv::cuda::GpuMat(cv::_InputArray::*)() const>("get_gpu_mat", &cv::_InputArray::getGpuMat).
    define_method<cv::ogl::Buffer(cv::_InputArray::*)() const>("get_o_gl_buffer", &cv::_InputArray::getOGlBuffer).
    define_method<int(cv::_InputArray::*)() const>("get_flags", &cv::_InputArray::getFlags).
    define_method<void*(cv::_InputArray::*)() const>("get_obj", &cv::_InputArray::getObj,
      ReturnBuffer()).
    define_method<cv::Size(cv::_InputArray::*)() const>("get_sz", &cv::_InputArray::getSz).
    define_method<cv::_InputArray::KindFlag(cv::_InputArray::*)() const>("kind", &cv::_InputArray::kind).
    define_method<int(cv::_InputArray::*)(int) const>("dims", &cv::_InputArray::dims,
      Arg("i") = static_cast<int>(-1)).
    define_method<int(cv::_InputArray::*)(int) const>("cols", &cv::_InputArray::cols,
      Arg("i") = static_cast<int>(-1)).
    define_method<int(cv::_InputArray::*)(int) const>("rows", &cv::_InputArray::rows,
      Arg("i") = static_cast<int>(-1)).
    define_method<cv::Size(cv::_InputArray::*)(int) const>("size", &cv::_InputArray::size,
      Arg("i") = static_cast<int>(-1)).
    define_method<int(cv::_InputArray::*)(int*, int) const>("sizend", &cv::_InputArray::sizend,
      ArgBuffer("sz"), Arg("i") = static_cast<int>(-1)).
    define_method<bool(cv::_InputArray::*)(const cv::_InputArray&) const>("same_size", &cv::_InputArray::sameSize,
      Arg("arr")).
    define_method<size_t(cv::_InputArray::*)(int) const>("total", &cv::_InputArray::total,
      Arg("i") = static_cast<int>(-1)).
    define_method<int(cv::_InputArray::*)(int) const>("type", &cv::_InputArray::type,
      Arg("i") = static_cast<int>(-1)).
    define_method<int(cv::_InputArray::*)(int) const>("depth", &cv::_InputArray::depth,
      Arg("i") = static_cast<int>(-1)).
    define_method<int(cv::_InputArray::*)(int) const>("channels", &cv::_InputArray::channels,
      Arg("i") = static_cast<int>(-1)).
    define_method<bool(cv::_InputArray::*)(int) const>("continuous?", &cv::_InputArray::isContinuous,
      Arg("i") = static_cast<int>(-1)).
    define_method<bool(cv::_InputArray::*)(int) const>("submatrix?", &cv::_InputArray::isSubmatrix,
      Arg("i") = static_cast<int>(-1)).
    define_method<bool(cv::_InputArray::*)() const>("empty?", &cv::_InputArray::empty).
    define_method<void(cv::_InputArray::*)(const cv::_OutputArray&) const>("copy_to", &cv::_InputArray::copyTo,
      Arg("arr")).
    define_method<void(cv::_InputArray::*)(const cv::_OutputArray&, const cv::_InputArray&) const>("copy_to", &cv::_InputArray::copyTo,
      Arg("arr"), Arg("mask")).
    define_method<size_t(cv::_InputArray::*)(int) const>("offset", &cv::_InputArray::offset,
      Arg("i") = static_cast<int>(-1)).
    define_method<size_t(cv::_InputArray::*)(int) const>("step", &cv::_InputArray::step,
      Arg("i") = static_cast<int>(-1)).
    define_method<bool(cv::_InputArray::*)() const>("mat?", &cv::_InputArray::isMat).
    define_method<bool(cv::_InputArray::*)() const>("u_mat?", &cv::_InputArray::isUMat).
    define_method<bool(cv::_InputArray::*)() const>("mat_vector?", &cv::_InputArray::isMatVector).
    define_method<bool(cv::_InputArray::*)() const>("u_mat_vector?", &cv::_InputArray::isUMatVector).
    define_method<bool(cv::_InputArray::*)() const>("matx?", &cv::_InputArray::isMatx).
    define_method<bool(cv::_InputArray::*)() const>("vector?", &cv::_InputArray::isVector).
    define_method<bool(cv::_InputArray::*)() const>("gpu_mat?", &cv::_InputArray::isGpuMat).
    define_method<bool(cv::_InputArray::*)() const>("gpu_mat_vector?", &cv::_InputArray::isGpuMatVector);

  Enum<cv::_InputArray::KindFlag> rb_cCvInputArrayKindFlag = define_enum_under<cv::_InputArray::KindFlag>("KindFlag", rb_cCvInputArray).
    define_value("KIND_SHIFT", cv::_InputArray::KindFlag::KIND_SHIFT).
    define_value("FIXED_TYPE", cv::_InputArray::KindFlag::FIXED_TYPE).
    define_value("FIXED_SIZE", cv::_InputArray::KindFlag::FIXED_SIZE).
    define_value("KIND_MASK", cv::_InputArray::KindFlag::KIND_MASK).
    define_value("NONE", cv::_InputArray::KindFlag::NONE).
    define_value("MAT", cv::_InputArray::KindFlag::MAT).
    define_value("MATX", cv::_InputArray::KindFlag::MATX).
    define_value("STD_VECTOR", cv::_InputArray::KindFlag::STD_VECTOR).
    define_value("STD_VECTOR_VECTOR", cv::_InputArray::KindFlag::STD_VECTOR_VECTOR).
    define_value("STD_VECTOR_MAT", cv::_InputArray::KindFlag::STD_VECTOR_MAT).
    define_value("EXPR", cv::_InputArray::KindFlag::EXPR).
    define_value("OPENGL_BUFFER", cv::_InputArray::KindFlag::OPENGL_BUFFER).
    define_value("CUDA_HOST_MEM", cv::_InputArray::KindFlag::CUDA_HOST_MEM).
    define_value("CUDA_GPU_MAT", cv::_InputArray::KindFlag::CUDA_GPU_MAT).
    define_value("UMAT", cv::_InputArray::KindFlag::UMAT).
    define_value("STD_VECTOR_UMAT", cv::_InputArray::KindFlag::STD_VECTOR_UMAT).
    define_value("STD_BOOL_VECTOR", cv::_InputArray::KindFlag::STD_BOOL_VECTOR).
    define_value("STD_VECTOR_CUDA_GPU_MAT", cv::_InputArray::KindFlag::STD_VECTOR_CUDA_GPU_MAT).
    define_value("STD_ARRAY", cv::_InputArray::KindFlag::STD_ARRAY).
    define_value("STD_ARRAY_MAT", cv::_InputArray::KindFlag::STD_ARRAY_MAT);

  Rice::Data_Type<cv::_OutputArray> rb_cCvOutputArray = define_class_under<cv::_OutputArray, cv::_InputArray>(rb_mCv, "OutputArray").
    define_constructor(Constructor<cv::_OutputArray>()).
    define_constructor(Constructor<cv::_OutputArray, int, void*>(),
      Arg("_flags"), ArgBuffer("_obj")).
    define_constructor(Constructor<cv::_OutputArray, cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Mat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_OutputArray, cv::cuda::GpuMat&>(),
      Arg("d_mat")).
    // Commented out - causes linker errors
    // define_constructor(Constructor<cv::_OutputArray, std::vector<cv::cuda::GpuMat>&>(),
    //   Arg("d_mat")).
    define_constructor(Constructor<cv::_OutputArray, cv::ogl::Buffer&>(),
      Arg("buf")).
    define_constructor(Constructor<cv::_OutputArray, cv::cuda::HostMem&>(),
      Arg("cuda_mem")).
    define_constructor(Constructor<cv::_OutputArray, cv::UMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::UMat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_OutputArray, const cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_OutputArray, const std::vector<cv::Mat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_OutputArray, const cv::cuda::GpuMat&>(),
      Arg("d_mat")).
    // Commented out - causes linker errors
    // define_constructor(Constructor<cv::_OutputArray, const std::vector<cv::cuda::GpuMat>&>(),
    //   Arg("d_mat")).
    define_constructor(Constructor<cv::_OutputArray, const cv::ogl::Buffer&>(),
      Arg("buf")).
    define_constructor(Constructor<cv::_OutputArray, const cv::cuda::HostMem&>(),
      Arg("cuda_mem")).
    define_constructor(Constructor<cv::_OutputArray, const cv::UMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_OutputArray, const std::vector<cv::UMat>&>(),
      Arg("vec")).
    define_method<bool(cv::_OutputArray::*)() const>("fixed_size?", &cv::_OutputArray::fixedSize).
    define_method<bool(cv::_OutputArray::*)() const>("fixed_type?", &cv::_OutputArray::fixedType).
    define_method<bool(cv::_OutputArray::*)() const>("needed?", &cv::_OutputArray::needed).
    define_method<cv::Mat&(cv::_OutputArray::*)(int) const>("get_mat_ref", &cv::_OutputArray::getMatRef,
      Arg("i") = static_cast<int>(-1)).
    define_method<cv::UMat&(cv::_OutputArray::*)(int) const>("get_u_mat_ref", &cv::_OutputArray::getUMatRef,
      Arg("i") = static_cast<int>(-1)).
    define_method<cv::cuda::GpuMat&(cv::_OutputArray::*)() const>("get_gpu_mat_ref", &cv::_OutputArray::getGpuMatRef).
    define_method<std::vector<cv::cuda::GpuMat>&(cv::_OutputArray::*)() const>("get_gpu_mat_vec_ref", &cv::_OutputArray::getGpuMatVecRef).
    define_method<cv::ogl::Buffer&(cv::_OutputArray::*)() const>("get_o_gl_buffer_ref", &cv::_OutputArray::getOGlBufferRef).
    define_method<cv::cuda::HostMem&(cv::_OutputArray::*)() const>("get_host_mem_ref", &cv::_OutputArray::getHostMemRef).
    define_method<void(cv::_OutputArray::*)(cv::Size, int, int, bool, cv::_OutputArray::DepthMask) const>("create", &cv::_OutputArray::create,
      Arg("sz"), Arg("type"), Arg("i") = static_cast<int>(-1), Arg("allow_transposed") = static_cast<bool>(false), Arg("fixed_depth_mask")).
    define_method<void(cv::_OutputArray::*)(int, int, int, int, bool, cv::_OutputArray::DepthMask) const>("create", &cv::_OutputArray::create,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("i") = static_cast<int>(-1), Arg("allow_transposed") = static_cast<bool>(false), Arg("fixed_depth_mask")).
    define_method<void(cv::_OutputArray::*)(int, const int*, int, int, bool, cv::_OutputArray::DepthMask) const>("create", &cv::_OutputArray::create,
      Arg("dims"), ArgBuffer("size"), Arg("type"), Arg("i") = static_cast<int>(-1), Arg("allow_transposed") = static_cast<bool>(false), Arg("fixed_depth_mask")).
    define_method<void(cv::_OutputArray::*)(const cv::_InputArray&, int) const>("create_same_size", &cv::_OutputArray::createSameSize,
      Arg("arr"), Arg("mtype")).
    define_method<void(cv::_OutputArray::*)() const>("release", &cv::_OutputArray::release).
    define_method<void(cv::_OutputArray::*)() const>("clear", &cv::_OutputArray::clear).
    define_method<void(cv::_OutputArray::*)(const cv::_InputArray&, const cv::_InputArray&) const>("set_to", &cv::_OutputArray::setTo,
      Arg("value"), Arg("mask") = static_cast<const cv::_InputArray&>(cv::_InputArray())).
    define_method<void(cv::_OutputArray::*)(const cv::UMat&) const>("assign", &cv::_OutputArray::assign,
      Arg("u")).
    define_method<void(cv::_OutputArray::*)(const cv::Mat&) const>("assign", &cv::_OutputArray::assign,
      Arg("m")).
    define_method<void(cv::_OutputArray::*)(const std::vector<cv::UMat>&) const>("assign", &cv::_OutputArray::assign,
      Arg("v")).
    define_method<void(cv::_OutputArray::*)(const std::vector<cv::Mat>&) const>("assign", &cv::_OutputArray::assign,
      Arg("v")).
    define_method<void(cv::_OutputArray::*)(cv::UMat&) const>("move", &cv::_OutputArray::move,
      Arg("u")).
    define_method<void(cv::_OutputArray::*)(cv::Mat&) const>("move", &cv::_OutputArray::move,
      Arg("m"));

  Enum<cv::_OutputArray::DepthMask> rb_cCvOutputArrayDepthMask = define_enum_under<cv::_OutputArray::DepthMask>("DepthMask", rb_cCvOutputArray).
    define_value("DEPTH_MASK_8U", cv::_OutputArray::DepthMask::DEPTH_MASK_8U).
    define_value("DEPTH_MASK_8S", cv::_OutputArray::DepthMask::DEPTH_MASK_8S).
    define_value("DEPTH_MASK_16U", cv::_OutputArray::DepthMask::DEPTH_MASK_16U).
    define_value("DEPTH_MASK_16S", cv::_OutputArray::DepthMask::DEPTH_MASK_16S).
    define_value("DEPTH_MASK_32S", cv::_OutputArray::DepthMask::DEPTH_MASK_32S).
    define_value("DEPTH_MASK_32F", cv::_OutputArray::DepthMask::DEPTH_MASK_32F).
    define_value("DEPTH_MASK_64F", cv::_OutputArray::DepthMask::DEPTH_MASK_64F).
    define_value("DEPTH_MASK_16F", cv::_OutputArray::DepthMask::DEPTH_MASK_16F).
    define_value("DEPTH_MASK_ALL", cv::_OutputArray::DepthMask::DEPTH_MASK_ALL).
    define_value("DEPTH_MASK_ALL_BUT_8S", cv::_OutputArray::DepthMask::DEPTH_MASK_ALL_BUT_8S).
    define_value("DEPTH_MASK_ALL_16F", cv::_OutputArray::DepthMask::DEPTH_MASK_ALL_16F).
    define_value("DEPTH_MASK_FLT", cv::_OutputArray::DepthMask::DEPTH_MASK_FLT);

  Rice::Data_Type<cv::_InputOutputArray> rb_cCvInputOutputArray = define_class_under<cv::_InputOutputArray, cv::_OutputArray>(rb_mCv, "InputOutputArray").
    define_constructor(Constructor<cv::_InputOutputArray>()).
    define_constructor(Constructor<cv::_InputOutputArray, int, void*>(),
      Arg("_flags"), ArgBuffer("_obj")).
    define_constructor(Constructor<cv::_InputOutputArray, cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_InputOutputArray, std::vector<cv::Mat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_InputOutputArray, cv::cuda::GpuMat&>(),
      Arg("d_mat")).
    define_constructor(Constructor<cv::_InputOutputArray, cv::ogl::Buffer&>(),
      Arg("buf")).
    define_constructor(Constructor<cv::_InputOutputArray, cv::cuda::HostMem&>(),
      Arg("cuda_mem")).
    define_constructor(Constructor<cv::_InputOutputArray, cv::UMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_InputOutputArray, std::vector<cv::UMat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_InputOutputArray, const cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_InputOutputArray, const std::vector<cv::Mat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_InputOutputArray, const cv::cuda::GpuMat&>(),
      Arg("d_mat")).
    define_constructor(Constructor<cv::_InputOutputArray, const std::vector<cv::cuda::GpuMat>&>(),
      Arg("d_mat")).
    define_constructor(Constructor<cv::_InputOutputArray, const cv::ogl::Buffer&>(),
      Arg("buf")).
    define_constructor(Constructor<cv::_InputOutputArray, const cv::cuda::HostMem&>(),
      Arg("cuda_mem")).
    define_constructor(Constructor<cv::_InputOutputArray, const cv::UMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_InputOutputArray, const std::vector<cv::UMat>&>(),
      Arg("vec"));

  rb_mCv.define_module_function<cv::InputOutputArray(*)()>("no_array", &cv::noArray);

  Enum<cv::UMatUsageFlags> rb_cCvUMatUsageFlags = define_enum_under<cv::UMatUsageFlags>("UMatUsageFlags", rb_mCv).
    define_value("USAGE_DEFAULT", cv::UMatUsageFlags::USAGE_DEFAULT).
    define_value("USAGE_ALLOCATE_HOST_MEMORY", cv::UMatUsageFlags::USAGE_ALLOCATE_HOST_MEMORY).
    define_value("USAGE_ALLOCATE_DEVICE_MEMORY", cv::UMatUsageFlags::USAGE_ALLOCATE_DEVICE_MEMORY).
    define_value("USAGE_ALLOCATE_SHARED_MEMORY", cv::UMatUsageFlags::USAGE_ALLOCATE_SHARED_MEMORY).
    define_value("__UMAT_USAGE_FLAGS_32BIT", cv::UMatUsageFlags::__UMAT_USAGE_FLAGS_32BIT);

  Rice::Data_Type<cv::MatAllocator> rb_cCvMatAllocator = define_class_under<cv::MatAllocator>(rb_mCv, "MatAllocator").
    define_method<cv::UMatData*(cv::MatAllocator::*)(int, const int*, int, void*, size_t*, cv::AccessFlag, cv::UMatUsageFlags) const>("allocate", &cv::MatAllocator::allocate,
      Arg("dims"), ArgBuffer("sizes"), Arg("type"), ArgBuffer("data"), ArgBuffer("step"), Arg("flags"), Arg("usage_flags")).
    define_method<bool(cv::MatAllocator::*)(cv::UMatData*, cv::AccessFlag, cv::UMatUsageFlags) const>("allocate", &cv::MatAllocator::allocate,
      Arg("data"), Arg("accessflags"), Arg("usage_flags")).
    define_method<void(cv::MatAllocator::*)(cv::UMatData*) const>("deallocate", &cv::MatAllocator::deallocate,
      Arg("data")).
    define_method<void(cv::MatAllocator::*)(cv::UMatData*, cv::AccessFlag) const>("map", &cv::MatAllocator::map,
      Arg("data"), Arg("accessflags")).
    define_method<void(cv::MatAllocator::*)(cv::UMatData*) const>("unmap", &cv::MatAllocator::unmap,
      Arg("data")).
    define_method<void(cv::MatAllocator::*)(cv::UMatData*, void*, int, const size_t[], const size_t[], const size_t[], const size_t[]) const>("download", &cv::MatAllocator::download,
      Arg("data"), ArgBuffer("dst"), Arg("dims"), Arg("sz"), Arg("srcofs"), Arg("srcstep"), Arg("dststep")).
    define_method<void(cv::MatAllocator::*)(cv::UMatData*, const void*, int, const size_t[], const size_t[], const size_t[], const size_t[]) const>("upload", &cv::MatAllocator::upload,
      Arg("data"), ArgBuffer("src"), Arg("dims"), Arg("sz"), Arg("dstofs"), Arg("dststep"), Arg("srcstep")).
    define_method<void(cv::MatAllocator::*)(cv::UMatData*, cv::UMatData*, int, const size_t[], const size_t[], const size_t[], const size_t[], const size_t[], bool) const>("copy", &cv::MatAllocator::copy,
      Arg("srcdata"), Arg("dstdata"), Arg("dims"), Arg("sz"), Arg("srcofs"), Arg("srcstep"), Arg("dstofs"), Arg("dststep"), Arg("sync")).
    define_method<cv::BufferPoolController*(cv::MatAllocator::*)(const char*) const>("get_buffer_pool_controller", &cv::MatAllocator::getBufferPoolController,
      Arg("id") = static_cast<const char*>(NULL));

  Rice::Data_Type<cv::UMatData> rb_cCvUMatData = define_class_under<cv::UMatData>(rb_mCv, "UMatData").
    define_constructor(Constructor<cv::UMatData, const cv::MatAllocator*>(),
      Arg("allocator")).
    define_method<void(cv::UMatData::*)()>("lock", &cv::UMatData::lock).
    define_method<void(cv::UMatData::*)()>("unlock", &cv::UMatData::unlock).
    define_method<bool(cv::UMatData::*)() const>("host_copy_obsolete?", &cv::UMatData::hostCopyObsolete).
    define_method<bool(cv::UMatData::*)() const>("device_copy_obsolete?", &cv::UMatData::deviceCopyObsolete).
    define_method<bool(cv::UMatData::*)() const>("device_mem_mapped?", &cv::UMatData::deviceMemMapped).
    define_method<bool(cv::UMatData::*)() const>("copy_on_map?", &cv::UMatData::copyOnMap).
    define_method<bool(cv::UMatData::*)() const>("temp_u_mat?", &cv::UMatData::tempUMat).
    define_method<bool(cv::UMatData::*)() const>("temp_copied_u_mat?", &cv::UMatData::tempCopiedUMat).
    define_method<void(cv::UMatData::*)(bool)>("mark_host_copy_obsolete", &cv::UMatData::markHostCopyObsolete,
      Arg("flag")).
    define_method<void(cv::UMatData::*)(bool)>("mark_device_copy_obsolete", &cv::UMatData::markDeviceCopyObsolete,
      Arg("flag")).
    define_method<void(cv::UMatData::*)(bool)>("mark_device_mem_mapped", &cv::UMatData::markDeviceMemMapped,
      Arg("flag")).
    define_attr("prev_allocator", &cv::UMatData::prevAllocator).
    define_attr("curr_allocator", &cv::UMatData::currAllocator).
    define_attr("urefcount", &cv::UMatData::urefcount).
    define_attr("refcount", &cv::UMatData::refcount).
    define_attr("data", &cv::UMatData::data).
    define_attr("origdata", &cv::UMatData::origdata).
    define_attr("size", &cv::UMatData::size).
    define_attr("flags", &cv::UMatData::flags).
    define_attr("handle", &cv::UMatData::handle).
    define_attr("userdata", &cv::UMatData::userdata).
    define_attr("allocator_flags_", &cv::UMatData::allocatorFlags_).
    define_attr("mapcount", &cv::UMatData::mapcount).
    define_attr("original_u_mat_data", &cv::UMatData::originalUMatData).
    define_attr("allocator_context", &cv::UMatData::allocatorContext);

  Enum<cv::UMatData::MemoryFlag> rb_cCvUMatDataMemoryFlag = define_enum_under<cv::UMatData::MemoryFlag>("MemoryFlag", rb_cCvUMatData).
    define_value("COPY_ON_MAP", cv::UMatData::MemoryFlag::COPY_ON_MAP).
    define_value("HOST_COPY_OBSOLETE", cv::UMatData::MemoryFlag::HOST_COPY_OBSOLETE).
    define_value("DEVICE_COPY_OBSOLETE", cv::UMatData::MemoryFlag::DEVICE_COPY_OBSOLETE).
    define_value("TEMP_UMAT", cv::UMatData::MemoryFlag::TEMP_UMAT).
    define_value("TEMP_COPIED_UMAT", cv::UMatData::MemoryFlag::TEMP_COPIED_UMAT).
    define_value("USER_ALLOCATED", cv::UMatData::MemoryFlag::USER_ALLOCATED).
    define_value("DEVICE_MEM_MAPPED", cv::UMatData::MemoryFlag::DEVICE_MEM_MAPPED).
    define_value("ASYNC_CLEANUP", cv::UMatData::MemoryFlag::ASYNC_CLEANUP);

  Rice::Data_Type<cv::MatSize> rb_cCvMatSize = define_class_under<cv::MatSize>(rb_mCv, "MatSize").
    define_constructor(Constructor<cv::MatSize, int*>(),
      ArgBuffer("_p")).
    define_method<int(cv::MatSize::*)() const noexcept>("dims", &cv::MatSize::dims).
    define_method<cv::Size(cv::MatSize::*)() const>("to_size", &cv::MatSize::operator()). // Manual - renamed from "call", returns cv::Size
    define_method<const int&(cv::MatSize::*)(int) const>("[]", &cv::MatSize::operator[],
      Arg("i")).
    define_method<int&(cv::MatSize::*)(int)>("[]", &cv::MatSize::operator[],
      Arg("i")).
    define_method("[]=", [](cv::MatSize&self, int index, int & value)
    {
        self[index] = value;
    }).
    define_method("to_const int", [](const cv::MatSize& self) -> const int*
    {
      return self;
    }).
    define_method<bool(cv::MatSize::*)(const cv::MatSize&) const noexcept>("==", &cv::MatSize::operator==,
      Arg("sz")).
    define_method<bool(cv::MatSize::*)(const cv::MatSize&) const noexcept>("!=", &cv::MatSize::operator!=,
      Arg("sz")).
    define_attr("p", &cv::MatSize::p);

  Rice::Data_Type<cv::MatStep> rb_cCvMatStep = define_class_under<cv::MatStep>(rb_mCv, "MatStep").
    define_constructor(Constructor<cv::MatStep>()).
    define_constructor(Constructor<cv::MatStep, size_t>(),
      Arg("s")).
    define_method<const size_t&(cv::MatStep::*)(int) const noexcept>("[]", &cv::MatStep::operator[],
      Arg("i")).
    define_method<size_t&(cv::MatStep::*)(int) noexcept>("[]", &cv::MatStep::operator[],
      Arg("i")).
    define_method("[]=", [](cv::MatStep&self, int index, size_t & value)
    {
        self[index] = value;
    }).
    define_method("to_size", [](const cv::MatStep& self) -> size_t
    {
      return self;
    }).
    define_method<cv::MatStep&(cv::MatStep::*)(size_t)>("assign", &cv::MatStep::operator=,
      Arg("s")).
    define_attr("p", &cv::MatStep::p).
    define_attr("buf", &cv::MatStep::buf, Rice::AttrAccess::Read);

  Rice::Data_Type<cv::Mat> rb_cCvMat = define_class_under<cv::Mat>(rb_mCv, "Mat").
    define_constructor(Constructor<cv::Mat>()).
    define_constructor(Constructor<cv::Mat, int, int, int>(),
      Arg("rows"), Arg("cols"), Arg("type")).
    define_constructor(Constructor<cv::Mat, cv::Size, int>(),
      Arg("size"), Arg("type")).
    define_constructor(Constructor<cv::Mat, int, int, int, const cv::Scalar&>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("s")).
    define_constructor(Constructor<cv::Mat, cv::Size, int, const cv::Scalar&>(),
      Arg("size"), Arg("type"), Arg("s")).
    define_constructor(Constructor<cv::Mat, int, const int*, int>(),
      Arg("ndims"), ArgBuffer("sizes"), Arg("type")).
    define_constructor(Constructor<cv::Mat, const std::vector<int>&, int>(),
      Arg("sizes"), Arg("type")).
    define_constructor(Constructor<cv::Mat, int, const int*, int, const cv::Scalar&>(),
      Arg("ndims"), ArgBuffer("sizes"), Arg("type"), Arg("s")).
    define_constructor(Constructor<cv::Mat, const std::vector<int>&, int, const cv::Scalar&>(),
      Arg("sizes"), Arg("type"), Arg("s")).
    define_constructor(Constructor<cv::Mat, const cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::Mat, int, int, int, void*, size_t>(),
      Arg("rows"), Arg("cols"), Arg("type"), ArgBuffer("data"), Arg("step") = static_cast<size_t>(cv::Mat::AUTO_STEP)).
    define_constructor(Constructor<cv::Mat, cv::Size, int, void*, size_t>(),
      Arg("size"), Arg("type"), ArgBuffer("data"), Arg("step") = static_cast<size_t>(cv::Mat::AUTO_STEP)).
    define_constructor(Constructor<cv::Mat, int, const int*, int, void*, const size_t*>(),
      Arg("ndims"), ArgBuffer("sizes"), Arg("type"), ArgBuffer("data"), ArgBuffer("steps") = static_cast<const size_t*>(0)).
    define_constructor(Constructor<cv::Mat, const std::vector<int>&, int, void*, const size_t*>(),
      Arg("sizes"), Arg("type"), ArgBuffer("data"), ArgBuffer("steps") = static_cast<const size_t*>(0)).
    define_constructor(Constructor<cv::Mat, const cv::Mat&, const cv::Range&, const cv::Range&>(),
      Arg("m"), Arg("row_range"), Arg("col_range") = static_cast<const cv::Range&>(cv::Range::all())).
    define_constructor(Constructor<cv::Mat, const cv::Mat&, const cv::Rect&>(),
      Arg("m"), Arg("roi")).
    define_constructor(Constructor<cv::Mat, const cv::Mat&, const cv::Range*>(),
      Arg("m"), Arg("ranges")).
    define_constructor(Constructor<cv::Mat, const cv::Mat&, const std::vector<cv::Range>&>(),
      Arg("m"), Arg("ranges")).
    define_constructor(Constructor<cv::Mat, const cv::cuda::GpuMat&>(),
      Arg("m")).
    define_method<cv::Mat&(cv::Mat::*)(const cv::Mat&)>("assign", &cv::Mat::operator=,
      Arg("m")).
    define_method<cv::Mat&(cv::Mat::*)(const cv::MatExpr&)>("assign", &cv::Mat::operator=,
      Arg("expr")).
    define_method<cv::UMat(cv::Mat::*)(cv::AccessFlag, cv::UMatUsageFlags) const>("get_u_mat", &cv::Mat::getUMat,
      Arg("access_flags"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::USAGE_DEFAULT)).
    define_method<cv::Mat(cv::Mat::*)(int) const>("row", &cv::Mat::row,
      Arg("y")).
    define_method<cv::Mat(cv::Mat::*)(int) const>("col", &cv::Mat::col,
      Arg("x")).
    define_method<cv::Mat(cv::Mat::*)(int, int) const>("row_range", &cv::Mat::rowRange,
      Arg("startrow"), Arg("endrow")).
    define_method<cv::Mat(cv::Mat::*)(const cv::Range&) const>("row_range", &cv::Mat::rowRange,
      Arg("r")).
    define_method<cv::Mat(cv::Mat::*)(int, int) const>("col_range", &cv::Mat::colRange,
      Arg("startcol"), Arg("endcol")).
    define_method<cv::Mat(cv::Mat::*)(const cv::Range&) const>("col_range", &cv::Mat::colRange,
      Arg("r")).
    define_method<cv::Mat(cv::Mat::*)(int) const>("diag", &cv::Mat::diag,
      Arg("d") = static_cast<int>(0)).
    define_singleton_function<cv::Mat(*)(const cv::Mat&)>("diag", &cv::Mat::diag,
      Arg("d")).
    define_method<cv::Mat(cv::Mat::*)() const>("clone", &cv::Mat::clone).
    define_method<void(cv::Mat::*)(cv::OutputArray) const>("copy_to", &cv::Mat::copyTo,
      Arg("m")).
    define_method<void(cv::Mat::*)(cv::OutputArray, cv::InputArray) const>("copy_to", &cv::Mat::copyTo,
      Arg("m"), Arg("mask")).
    define_method<void(cv::Mat::*)(cv::OutputArray, int, double, double) const>("convert_to", &cv::Mat::convertTo,
      Arg("m"), Arg("rtype"), Arg("alpha") = static_cast<double>(1), Arg("beta") = static_cast<double>(0)).
    define_method<void(cv::Mat::*)(cv::Mat&, int) const>("assign_to", &cv::Mat::assignTo,
      Arg("m"), Arg("type") = static_cast<int>(-1)).
    define_method<cv::Mat&(cv::Mat::*)(const cv::Scalar&)>("assign", &cv::Mat::operator=,
      Arg("s")).
    define_method<cv::Mat&(cv::Mat::*)(cv::InputArray, cv::InputArray)>("set_to", &cv::Mat::setTo,
      Arg("value"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<cv::Mat(cv::Mat::*)(int, int) const>("reshape", &cv::Mat::reshape,
      Arg("cn"), Arg("rows") = static_cast<int>(0)).
    define_method<cv::Mat(cv::Mat::*)(int, int, const int*) const>("reshape", &cv::Mat::reshape,
      Arg("cn"), Arg("newndims"), ArgBuffer("newsz")).
    define_method<cv::Mat(cv::Mat::*)(int, const std::vector<int>&) const>("reshape", &cv::Mat::reshape,
      Arg("cn"), Arg("newshape")).
    define_method<cv::MatExpr(cv::Mat::*)() const>("t", &cv::Mat::t).
    define_method<cv::MatExpr(cv::Mat::*)(int) const>("inv", &cv::Mat::inv,
      Arg("method") = static_cast<int>(cv::DECOMP_LU)).
    define_method<cv::MatExpr(cv::Mat::*)(cv::InputArray, double) const>("mul", &cv::Mat::mul,
      Arg("m"), Arg("scale") = static_cast<double>(1)).
    define_method<cv::Mat(cv::Mat::*)(cv::InputArray) const>("cross", &cv::Mat::cross,
      Arg("m")).
    define_method<double(cv::Mat::*)(cv::InputArray) const>("dot", &cv::Mat::dot,
      Arg("m")).
    define_singleton_function<cv::MatExpr(*)(int, int, int)>("zeros", &cv::Mat::zeros,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(cv::Size, int)>("zeros", &cv::Mat::zeros,
      Arg("size"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(int, const int*, int)>("zeros", &cv::Mat::zeros,
      Arg("ndims"), ArgBuffer("sz"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(int, int, int)>("ones", &cv::Mat::ones,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(cv::Size, int)>("ones", &cv::Mat::ones,
      Arg("size"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(int, const int*, int)>("ones", &cv::Mat::ones,
      Arg("ndims"), ArgBuffer("sz"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(int, int, int)>("eye", &cv::Mat::eye,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(cv::Size, int)>("eye", &cv::Mat::eye,
      Arg("size"), Arg("type")).
    define_method<void(cv::Mat::*)(int, int, int)>("create", &cv::Mat::create,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_method<void(cv::Mat::*)(cv::Size, int)>("create", &cv::Mat::create,
      Arg("size"), Arg("type")).
    define_method<void(cv::Mat::*)(int, const int*, int)>("create", &cv::Mat::create,
      Arg("ndims"), ArgBuffer("sizes"), Arg("type")).
    define_method<void(cv::Mat::*)(const std::vector<int>&, int)>("create", &cv::Mat::create,
      Arg("sizes"), Arg("type")).
    define_method<void(cv::Mat::*)()>("addref", &cv::Mat::addref).
    define_method<void(cv::Mat::*)()>("release", &cv::Mat::release).
    define_method<void(cv::Mat::*)()>("deallocate", &cv::Mat::deallocate).
    define_method<void(cv::Mat::*)(const cv::Mat&)>("copy_size", &cv::Mat::copySize,
      Arg("m")).
    define_method<void(cv::Mat::*)(size_t)>("reserve", &cv::Mat::reserve,
      Arg("sz")).
    define_method<void(cv::Mat::*)(size_t)>("reserve_buffer", &cv::Mat::reserveBuffer,
      Arg("sz")).
    define_method<void(cv::Mat::*)(size_t)>("resize", &cv::Mat::resize,
      Arg("sz")).
    define_method<void(cv::Mat::*)(size_t, const cv::Scalar&)>("resize", &cv::Mat::resize,
      Arg("sz"), Arg("s")).
    define_method<void(cv::Mat::*)(const cv::Mat&)>("push_back", &cv::Mat::push_back,
      Arg("m")).
    define_method<void(cv::Mat::*)(size_t)>("pop_back", &cv::Mat::pop_back,
      Arg("nelems") = static_cast<size_t>(1)).
    define_method<void(cv::Mat::*)(cv::Size&, cv::Point&) const>("locate_roi", &cv::Mat::locateROI,
      Arg("whole_size"), Arg("ofs")).
    define_method<cv::Mat&(cv::Mat::*)(int, int, int, int)>("adjust_roi", &cv::Mat::adjustROI,
      Arg("dtop"), Arg("dbottom"), Arg("dleft"), Arg("dright")).
    // Manual - changed "call" to "[]" for ROI access methods
    define_method<cv::Mat(cv::Mat::*)(cv::Range, cv::Range) const>("[]", &cv::Mat::operator(),
      Arg("row_range"), Arg("col_range")).
    define_method<cv::Mat(cv::Mat::*)(const cv::Rect&) const>("[]", &cv::Mat::operator(),
      Arg("roi")).
    define_method<cv::Mat(cv::Mat::*)(const cv::Range*) const>("[]", &cv::Mat::operator(),
      Arg("ranges")).
    define_method<cv::Mat(cv::Mat::*)(const std::vector<cv::Range>&) const>("[]", &cv::Mat::operator(),
      Arg("ranges")).
    define_method<bool(cv::Mat::*)() const>("continuous?", &cv::Mat::isContinuous).
    define_method<bool(cv::Mat::*)() const>("submatrix?", &cv::Mat::isSubmatrix).
    define_method<size_t(cv::Mat::*)() const>("elem_size", &cv::Mat::elemSize).
    define_method<size_t(cv::Mat::*)() const>("elem_size1", &cv::Mat::elemSize1).
    define_method<int(cv::Mat::*)() const>("type", &cv::Mat::type).
    define_method<int(cv::Mat::*)() const>("depth", &cv::Mat::depth).
    define_method<int(cv::Mat::*)() const>("channels", &cv::Mat::channels).
    define_method<size_t(cv::Mat::*)(int) const>("step1", &cv::Mat::step1,
      Arg("i") = static_cast<int>(0)).
    define_method<bool(cv::Mat::*)() const>("empty?", &cv::Mat::empty).
    define_method<size_t(cv::Mat::*)() const>("total", &cv::Mat::total).
    define_method<size_t(cv::Mat::*)(int, int) const>("total", &cv::Mat::total,
      Arg("start_dim"), Arg("end_dim") = static_cast<int>(INT_MAX)).
    define_method<int(cv::Mat::*)(int, int, bool) const>("check_vector", &cv::Mat::checkVector,
      Arg("elem_channels"), Arg("depth") = static_cast<int>(-1), Arg("require_continuous") = static_cast<bool>(true)).
    define_method<uchar*(cv::Mat::*)(int)>("ptr", &cv::Mat::ptr,
      Arg("i0") = static_cast<int>(0), ReturnBuffer()).
    define_method<const uchar*(cv::Mat::*)(int) const>("ptr", &cv::Mat::ptr,
      Arg("i0") = static_cast<int>(0), ReturnBuffer()).
    define_method<uchar*(cv::Mat::*)(int, int)>("ptr", &cv::Mat::ptr,
      Arg("row"), Arg("col"), ReturnBuffer()).
    define_method<const uchar*(cv::Mat::*)(int, int) const>("ptr", &cv::Mat::ptr,
      Arg("row"), Arg("col"), ReturnBuffer()).
    define_method<uchar*(cv::Mat::*)(int, int, int)>("ptr", &cv::Mat::ptr,
      Arg("i0"), Arg("i1"), Arg("i2"), ReturnBuffer()).
    define_method<const uchar*(cv::Mat::*)(int, int, int) const>("ptr", &cv::Mat::ptr,
      Arg("i0"), Arg("i1"), Arg("i2"), ReturnBuffer()).
    define_method<uchar*(cv::Mat::*)(const int*)>("ptr", &cv::Mat::ptr,
      ArgBuffer("idx"), ReturnBuffer()).
    define_method<const uchar*(cv::Mat::*)(const int*) const>("ptr", &cv::Mat::ptr,
      ArgBuffer("idx"), ReturnBuffer()).
    define_method<cv::Mat&(cv::Mat::*)(cv::Mat&&)>("assign", &cv::Mat::operator=,
      Arg("m")).
    define_attr("flags", &cv::Mat::flags).
    define_attr("dims", &cv::Mat::dims).
    define_attr("rows", &cv::Mat::rows).
    define_attr("cols", &cv::Mat::cols).
    define_attr("data", &cv::Mat::data).
    define_attr("datastart", &cv::Mat::datastart).
    define_attr("dataend", &cv::Mat::dataend).
    define_attr("datalimit", &cv::Mat::datalimit).
    define_attr("allocator", &cv::Mat::allocator).
    define_singleton_function<cv::MatAllocator*(*)()>("get_std_allocator", &cv::Mat::getStdAllocator).
    define_singleton_function<cv::MatAllocator*(*)()>("get_default_allocator", &cv::Mat::getDefaultAllocator).
    define_singleton_function<void(*)(cv::MatAllocator*)>("set_default_allocator", &cv::Mat::setDefaultAllocator,
      Arg("allocator")).
    define_method<void(cv::Mat::*)()>("update_continuity_flag", &cv::Mat::updateContinuityFlag).
    define_attr("u", &cv::Mat::u).
    define_attr("size", &cv::Mat::size).
    define_attr("step", &cv::Mat::step, Rice::AttrAccess::Read);

  rb_cCvMat.define_constant("MAGIC_VAL", (int)cv::Mat::MAGIC_VAL);
  rb_cCvMat.define_constant("AUTO_STEP", (int)cv::Mat::AUTO_STEP);
  rb_cCvMat.define_constant("CONTINUOUS_FLAG", (int)cv::Mat::CONTINUOUS_FLAG);
  rb_cCvMat.define_constant("SUBMATRIX_FLAG", (int)cv::Mat::SUBMATRIX_FLAG);

  rb_cCvMat.define_constant("MAGIC_MASK", (int)cv::Mat::MAGIC_MASK);
  rb_cCvMat.define_constant("TYPE_MASK", (int)cv::Mat::TYPE_MASK);
  rb_cCvMat.define_constant("DEPTH_MASK", (int)cv::Mat::DEPTH_MASK);

  Rice::Data_Type<cv::Mat_<uchar>> rb_cMat1b = Mat__instantiate<unsigned char>(rb_mCv, "Mat1b");

  Rice::Data_Type<cv::Mat_<cv::Vec<unsigned char, 2>>> rb_cMat2b = Mat__instantiate<cv::Vec<unsigned char, 2>>(rb_mCv, "Mat2b");

  Rice::Data_Type<cv::Mat_<cv::Vec<unsigned char, 3>>> rb_cMat3b = Mat__instantiate<cv::Vec<unsigned char, 3>>(rb_mCv, "Mat3b");

  Rice::Data_Type<cv::Mat_<cv::Vec<unsigned char, 4>>> rb_cMat4b = Mat__instantiate<cv::Vec<unsigned char, 4>>(rb_mCv, "Mat4b");

  Rice::Data_Type<cv::Mat_<short>> rb_cMat1s = Mat__instantiate<short>(rb_mCv, "Mat1s");

  Rice::Data_Type<cv::Mat_<cv::Vec<short, 2>>> rb_cMat2s = Mat__instantiate<cv::Vec<short, 2>>(rb_mCv, "Mat2s");

  Rice::Data_Type<cv::Mat_<cv::Vec<short, 3>>> rb_cMat3s = Mat__instantiate<cv::Vec<short, 3>>(rb_mCv, "Mat3s");

  Rice::Data_Type<cv::Mat_<cv::Vec<short, 4>>> rb_cMat4s = Mat__instantiate<cv::Vec<short, 4>>(rb_mCv, "Mat4s");

  Rice::Data_Type<cv::Mat_<ushort>> rb_cMat1w = Mat__instantiate<unsigned short>(rb_mCv, "Mat1w");

  Rice::Data_Type<cv::Mat_<cv::Vec<unsigned short, 2>>> rb_cMat2w = Mat__instantiate<cv::Vec<unsigned short, 2>>(rb_mCv, "Mat2w");

  Rice::Data_Type<cv::Mat_<cv::Vec<unsigned short, 3>>> rb_cMat3w = Mat__instantiate<cv::Vec<unsigned short, 3>>(rb_mCv, "Mat3w");

  Rice::Data_Type<cv::Mat_<cv::Vec<unsigned short, 4>>> rb_cMat4w = Mat__instantiate<cv::Vec<unsigned short, 4>>(rb_mCv, "Mat4w");

  Rice::Data_Type<cv::Mat_<int>> rb_cMat1i = Mat__instantiate<int>(rb_mCv, "Mat1i");

  Rice::Data_Type<cv::Mat_<cv::Vec<int, 2>>> rb_cMat2i = Mat__instantiate<cv::Vec<int, 2>>(rb_mCv, "Mat2i");

  Rice::Data_Type<cv::Mat_<cv::Vec<int, 3>>> rb_cMat3i = Mat__instantiate<cv::Vec<int, 3>>(rb_mCv, "Mat3i");

  Rice::Data_Type<cv::Mat_<cv::Vec<int, 4>>> rb_cMat4i = Mat__instantiate<cv::Vec<int, 4>>(rb_mCv, "Mat4i");

  Rice::Data_Type<cv::Mat_<float>> rb_cMat1f = Mat__instantiate<float>(rb_mCv, "Mat1f");

  Rice::Data_Type<cv::Mat_<cv::Vec<float, 2>>> rb_cMat2f = Mat__instantiate<cv::Vec<float, 2>>(rb_mCv, "Mat2f");

  Rice::Data_Type<cv::Mat_<cv::Vec<float, 3>>> rb_cMat3f = Mat__instantiate<cv::Vec<float, 3>>(rb_mCv, "Mat3f");

  Rice::Data_Type<cv::Mat_<cv::Vec<float, 4>>> rb_cMat4f = Mat__instantiate<cv::Vec<float, 4>>(rb_mCv, "Mat4f");

  Rice::Data_Type<cv::Mat_<double>> rb_cMat1d = Mat__instantiate<double>(rb_mCv, "Mat1d");

  Rice::Data_Type<cv::Mat_<cv::Vec<double, 2>>> rb_cMat2d = Mat__instantiate<cv::Vec<double, 2>>(rb_mCv, "Mat2d");

  Rice::Data_Type<cv::Mat_<cv::Vec<double, 3>>> rb_cMat3d = Mat__instantiate<cv::Vec<double, 3>>(rb_mCv, "Mat3d");

  Rice::Data_Type<cv::Mat_<cv::Vec<double, 4>>> rb_cMat4d = Mat__instantiate<cv::Vec<double, 4>>(rb_mCv, "Mat4d");

  Rice::Data_Type<cv::UMat> rb_cCvUMat = define_class_under<cv::UMat>(rb_mCv, "UMat").
    define_constructor(Constructor<cv::UMat, cv::UMatUsageFlags>(),
      Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, int, int, int, cv::UMatUsageFlags>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, cv::Size, int, cv::UMatUsageFlags>(),
      Arg("size"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, int, int, int, const cv::Scalar&, cv::UMatUsageFlags>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("s"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, cv::Size, int, const cv::Scalar&, cv::UMatUsageFlags>(),
      Arg("size"), Arg("type"), Arg("s"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, int, const int*, int, cv::UMatUsageFlags>(),
      Arg("ndims"), ArgBuffer("sizes"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, int, const int*, int, const cv::Scalar&, cv::UMatUsageFlags>(),
      Arg("ndims"), ArgBuffer("sizes"), Arg("type"), Arg("s"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, const cv::UMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::UMat, const cv::UMat&, const cv::Range&, const cv::Range&>(),
      Arg("m"), Arg("row_range"), Arg("col_range") = static_cast<const cv::Range&>(cv::Range::all())).
    define_constructor(Constructor<cv::UMat, const cv::UMat&, const cv::Rect&>(),
      Arg("m"), Arg("roi")).
    define_constructor(Constructor<cv::UMat, const cv::UMat&, const cv::Range*>(),
      Arg("m"), Arg("ranges")).
    define_constructor(Constructor<cv::UMat, const cv::UMat&, const std::vector<cv::Range>&>(),
      Arg("m"), Arg("ranges")).
    define_method<cv::UMat&(cv::UMat::*)(const cv::UMat&)>("assign", &cv::UMat::operator=,
      Arg("m")).
    define_method<cv::Mat(cv::UMat::*)(cv::AccessFlag) const>("get_mat", &cv::UMat::getMat,
      Arg("flags")).
    define_method<cv::UMat(cv::UMat::*)(int) const>("row", &cv::UMat::row,
      Arg("y")).
    define_method<cv::UMat(cv::UMat::*)(int) const>("col", &cv::UMat::col,
      Arg("x")).
    define_method<cv::UMat(cv::UMat::*)(int, int) const>("row_range", &cv::UMat::rowRange,
      Arg("startrow"), Arg("endrow")).
    define_method<cv::UMat(cv::UMat::*)(const cv::Range&) const>("row_range", &cv::UMat::rowRange,
      Arg("r")).
    define_method<cv::UMat(cv::UMat::*)(int, int) const>("col_range", &cv::UMat::colRange,
      Arg("startcol"), Arg("endcol")).
    define_method<cv::UMat(cv::UMat::*)(const cv::Range&) const>("col_range", &cv::UMat::colRange,
      Arg("r")).
    define_method<cv::UMat(cv::UMat::*)(int) const>("diag", &cv::UMat::diag,
      Arg("d") = static_cast<int>(0)).
    define_singleton_function<cv::UMat(*)(const cv::UMat&, cv::UMatUsageFlags)>("diag", &cv::UMat::diag,
      Arg("d"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(const cv::UMat&)>("diag", &cv::UMat::diag,
      Arg("d")).
    define_method<cv::UMat(cv::UMat::*)() const>("clone", &cv::UMat::clone).
    define_method<void(cv::UMat::*)(cv::OutputArray) const>("copy_to", &cv::UMat::copyTo,
      Arg("m")).
    define_method<void(cv::UMat::*)(cv::OutputArray, cv::InputArray) const>("copy_to", &cv::UMat::copyTo,
      Arg("m"), Arg("mask")).
    define_method<void(cv::UMat::*)(cv::OutputArray, int, double, double) const>("convert_to", &cv::UMat::convertTo,
      Arg("m"), Arg("rtype"), Arg("alpha") = static_cast<double>(1), Arg("beta") = static_cast<double>(0)).
    define_method<void(cv::UMat::*)(cv::UMat&, int) const>("assign_to", &cv::UMat::assignTo,
      Arg("m"), Arg("type") = static_cast<int>(-1)).
    define_method<cv::UMat&(cv::UMat::*)(const cv::Scalar&)>("assign", &cv::UMat::operator=,
      Arg("s")).
    define_method<cv::UMat&(cv::UMat::*)(cv::InputArray, cv::InputArray)>("set_to", &cv::UMat::setTo,
      Arg("value"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<cv::UMat(cv::UMat::*)(int, int) const>("reshape", &cv::UMat::reshape,
      Arg("cn"), Arg("rows") = static_cast<int>(0)).
    define_method<cv::UMat(cv::UMat::*)(int, int, const int*) const>("reshape", &cv::UMat::reshape,
      Arg("cn"), Arg("newndims"), ArgBuffer("newsz")).
    define_method<cv::UMat(cv::UMat::*)() const>("t", &cv::UMat::t).
    define_method<cv::UMat(cv::UMat::*)(int) const>("inv", &cv::UMat::inv,
      Arg("method") = static_cast<int>(cv::DECOMP_LU)).
    define_method<cv::UMat(cv::UMat::*)(cv::InputArray, double) const>("mul", &cv::UMat::mul,
      Arg("m"), Arg("scale") = static_cast<double>(1)).
    define_method<double(cv::UMat::*)(cv::InputArray) const>("dot", &cv::UMat::dot,
      Arg("m")).
    define_singleton_function<cv::UMat(*)(int, int, int, cv::UMatUsageFlags)>("zeros", &cv::UMat::zeros,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(cv::Size, int, cv::UMatUsageFlags)>("zeros", &cv::UMat::zeros,
      Arg("size"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(int, const int*, int, cv::UMatUsageFlags)>("zeros", &cv::UMat::zeros,
      Arg("ndims"), ArgBuffer("sz"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(int, int, int)>("zeros", &cv::UMat::zeros,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_singleton_function<cv::UMat(*)(cv::Size, int)>("zeros", &cv::UMat::zeros,
      Arg("size"), Arg("type")).
    define_singleton_function<cv::UMat(*)(int, const int*, int)>("zeros", &cv::UMat::zeros,
      Arg("ndims"), ArgBuffer("sz"), Arg("type")).
    define_singleton_function<cv::UMat(*)(int, int, int, cv::UMatUsageFlags)>("ones", &cv::UMat::ones,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(cv::Size, int, cv::UMatUsageFlags)>("ones", &cv::UMat::ones,
      Arg("size"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(int, const int*, int, cv::UMatUsageFlags)>("ones", &cv::UMat::ones,
      Arg("ndims"), ArgBuffer("sz"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(int, int, int)>("ones", &cv::UMat::ones,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_singleton_function<cv::UMat(*)(cv::Size, int)>("ones", &cv::UMat::ones,
      Arg("size"), Arg("type")).
    define_singleton_function<cv::UMat(*)(int, const int*, int)>("ones", &cv::UMat::ones,
      Arg("ndims"), ArgBuffer("sz"), Arg("type")).
    define_singleton_function<cv::UMat(*)(int, int, int, cv::UMatUsageFlags)>("eye", &cv::UMat::eye,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(cv::Size, int, cv::UMatUsageFlags)>("eye", &cv::UMat::eye,
      Arg("size"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(int, int, int)>("eye", &cv::UMat::eye,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_singleton_function<cv::UMat(*)(cv::Size, int)>("eye", &cv::UMat::eye,
      Arg("size"), Arg("type")).
    define_method<void(cv::UMat::*)(int, int, int, cv::UMatUsageFlags)>("create", &cv::UMat::create,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::USAGE_DEFAULT)).
    define_method<void(cv::UMat::*)(cv::Size, int, cv::UMatUsageFlags)>("create", &cv::UMat::create,
      Arg("size"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::USAGE_DEFAULT)).
    define_method<void(cv::UMat::*)(int, const int*, int, cv::UMatUsageFlags)>("create", &cv::UMat::create,
      Arg("ndims"), ArgBuffer("sizes"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::USAGE_DEFAULT)).
    define_method<void(cv::UMat::*)(const std::vector<int>&, int, cv::UMatUsageFlags)>("create", &cv::UMat::create,
      Arg("sizes"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::USAGE_DEFAULT)).
    define_method<void(cv::UMat::*)()>("addref", &cv::UMat::addref).
    define_method<void(cv::UMat::*)()>("release", &cv::UMat::release).
    define_method<void(cv::UMat::*)()>("deallocate", &cv::UMat::deallocate).
    define_method<void(cv::UMat::*)(const cv::UMat&)>("copy_size", &cv::UMat::copySize,
      Arg("m")).
    define_method<void(cv::UMat::*)(cv::Size&, cv::Point&) const>("locate_roi", &cv::UMat::locateROI,
      Arg("whole_size"), Arg("ofs")).
    define_method<cv::UMat&(cv::UMat::*)(int, int, int, int)>("adjust_roi", &cv::UMat::adjustROI,
      Arg("dtop"), Arg("dbottom"), Arg("dleft"), Arg("dright")).
    // Manual - changed "call" to "[]" for ROI access methods
    define_method<cv::UMat(cv::UMat::*)(cv::Range, cv::Range) const>("[]", &cv::UMat::operator(),
      Arg("row_range"), Arg("col_range")).
    define_method<cv::UMat(cv::UMat::*)(const cv::Rect&) const>("[]", &cv::UMat::operator(),
      Arg("roi")).
    define_method<cv::UMat(cv::UMat::*)(const cv::Range*) const>("[]", &cv::UMat::operator(),
      Arg("ranges")).
    define_method<cv::UMat(cv::UMat::*)(const std::vector<cv::Range>&) const>("[]", &cv::UMat::operator(),
      Arg("ranges")).
    define_method<bool(cv::UMat::*)() const>("continuous?", &cv::UMat::isContinuous).
    define_method<bool(cv::UMat::*)() const>("submatrix?", &cv::UMat::isSubmatrix).
    define_method<size_t(cv::UMat::*)() const>("elem_size", &cv::UMat::elemSize).
    define_method<size_t(cv::UMat::*)() const>("elem_size1", &cv::UMat::elemSize1).
    define_method<int(cv::UMat::*)() const>("type", &cv::UMat::type).
    define_method<int(cv::UMat::*)() const>("depth", &cv::UMat::depth).
    define_method<int(cv::UMat::*)() const>("channels", &cv::UMat::channels).
    define_method<size_t(cv::UMat::*)(int) const>("step1", &cv::UMat::step1,
      Arg("i") = static_cast<int>(0)).
    define_method<bool(cv::UMat::*)() const>("empty?", &cv::UMat::empty).
    define_method<size_t(cv::UMat::*)() const>("total", &cv::UMat::total).
    define_method<int(cv::UMat::*)(int, int, bool) const>("check_vector", &cv::UMat::checkVector,
      Arg("elem_channels"), Arg("depth") = static_cast<int>(-1), Arg("require_continuous") = static_cast<bool>(true)).
    define_method<cv::UMat&(cv::UMat::*)(cv::UMat&&)>("assign", &cv::UMat::operator=,
      Arg("m")).
    define_method<void*(cv::UMat::*)(cv::AccessFlag) const>("handle", &cv::UMat::handle,
      Arg("access_flags"), ReturnBuffer()).
    define_method<void(cv::UMat::*)(size_t*) const>("ndoffset", &cv::UMat::ndoffset,
      ArgBuffer("ofs")).
    define_attr("flags", &cv::UMat::flags).
    define_attr("dims", &cv::UMat::dims).
    define_attr("rows", &cv::UMat::rows).
    define_attr("cols", &cv::UMat::cols).
    define_attr("allocator", &cv::UMat::allocator).
    define_attr("usage_flags", &cv::UMat::usageFlags).
    define_singleton_function<cv::MatAllocator*(*)()>("get_std_allocator", &cv::UMat::getStdAllocator).
    define_method<void(cv::UMat::*)()>("update_continuity_flag", &cv::UMat::updateContinuityFlag).
    define_attr("u", &cv::UMat::u).
    define_attr("offset", &cv::UMat::offset).
    define_attr("size", &cv::UMat::size).
    define_attr("step", &cv::UMat::step, Rice::AttrAccess::Read);

  rb_cCvUMat.define_constant("MAGIC_VAL", (int)cv::UMat::MAGIC_VAL);
  rb_cCvUMat.define_constant("AUTO_STEP", (int)cv::UMat::AUTO_STEP);
  rb_cCvUMat.define_constant("CONTINUOUS_FLAG", (int)cv::UMat::CONTINUOUS_FLAG);
  rb_cCvUMat.define_constant("SUBMATRIX_FLAG", (int)cv::UMat::SUBMATRIX_FLAG);

  rb_cCvUMat.define_constant("MAGIC_MASK", (int)cv::UMat::MAGIC_MASK);
  rb_cCvUMat.define_constant("TYPE_MASK", (int)cv::UMat::TYPE_MASK);
  rb_cCvUMat.define_constant("DEPTH_MASK", (int)cv::UMat::DEPTH_MASK);

  Rice::Data_Type<cv::SparseMat> rb_cCvSparseMat = define_class_under<cv::SparseMat>(rb_mCv, "SparseMat").
    define_constructor(Constructor<cv::SparseMat>()).
    define_constructor(Constructor<cv::SparseMat, int, const int*, int>(),
      Arg("dims"), ArgBuffer("_sizes"), Arg("_type")).
    define_constructor(Constructor<cv::SparseMat, const cv::SparseMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::SparseMat, const cv::Mat&>(),
      Arg("m")).
    define_method<cv::SparseMat&(cv::SparseMat::*)(const cv::SparseMat&)>("assign", &cv::SparseMat::operator=,
      Arg("m")).
    define_method<cv::SparseMat&(cv::SparseMat::*)(const cv::Mat&)>("assign", &cv::SparseMat::operator=,
      Arg("m")).
    define_method<cv::SparseMat(cv::SparseMat::*)() const>("clone", &cv::SparseMat::clone).
    define_method<void(cv::SparseMat::*)(cv::SparseMat&) const>("copy_to", &cv::SparseMat::copyTo,
      Arg("m")).
    define_method<void(cv::SparseMat::*)(cv::Mat&) const>("copy_to", &cv::SparseMat::copyTo,
      Arg("m")).
    define_method<void(cv::SparseMat::*)(cv::SparseMat&, int, double) const>("convert_to", &cv::SparseMat::convertTo,
      Arg("m"), Arg("rtype"), Arg("alpha") = static_cast<double>(1)).
    define_method<void(cv::SparseMat::*)(cv::Mat&, int, double, double) const>("convert_to", &cv::SparseMat::convertTo,
      Arg("m"), Arg("rtype"), Arg("alpha") = static_cast<double>(1), Arg("beta") = static_cast<double>(0)).
    define_method<void(cv::SparseMat::*)(cv::SparseMat&, int) const>("assign_to", &cv::SparseMat::assignTo,
      Arg("m"), Arg("type") = static_cast<int>(-1)).
    define_method<void(cv::SparseMat::*)(int, const int*, int)>("create", &cv::SparseMat::create,
      Arg("dims"), ArgBuffer("_sizes"), Arg("_type")).
    define_method<void(cv::SparseMat::*)()>("clear", &cv::SparseMat::clear).
    define_method<void(cv::SparseMat::*)()>("addref", &cv::SparseMat::addref).
    define_method<void(cv::SparseMat::*)()>("release", &cv::SparseMat::release).
    define_method<size_t(cv::SparseMat::*)() const>("elem_size", &cv::SparseMat::elemSize).
    define_method<size_t(cv::SparseMat::*)() const>("elem_size1", &cv::SparseMat::elemSize1).
    define_method<int(cv::SparseMat::*)() const>("type", &cv::SparseMat::type).
    define_method<int(cv::SparseMat::*)() const>("depth", &cv::SparseMat::depth).
    define_method<int(cv::SparseMat::*)() const>("channels", &cv::SparseMat::channels).
    define_method<const int*(cv::SparseMat::*)() const>("size", &cv::SparseMat::size,
      ReturnBuffer()).
    define_method<int(cv::SparseMat::*)(int) const>("size", &cv::SparseMat::size,
      Arg("i")).
    define_method<int(cv::SparseMat::*)() const>("dims", &cv::SparseMat::dims).
    define_method<size_t(cv::SparseMat::*)() const>("nzcount", &cv::SparseMat::nzcount).
    define_method<size_t(cv::SparseMat::*)(int) const>("hash", &cv::SparseMat::hash,
      Arg("i0")).
    define_method<size_t(cv::SparseMat::*)(int, int) const>("hash", &cv::SparseMat::hash,
      Arg("i0"), Arg("i1")).
    define_method<size_t(cv::SparseMat::*)(int, int, int) const>("hash", &cv::SparseMat::hash,
      Arg("i0"), Arg("i1"), Arg("i2")).
    define_method<size_t(cv::SparseMat::*)(const int*) const>("hash", &cv::SparseMat::hash,
      ArgBuffer("idx")).
    define_method<uchar*(cv::SparseMat::*)(int, bool, size_t*)>("ptr", &cv::SparseMat::ptr,
      Arg("i0"), Arg("create_missing"), ArgBuffer("hashval") = static_cast<size_t*>(0), ReturnBuffer()).
    define_method<uchar*(cv::SparseMat::*)(int, int, bool, size_t*)>("ptr", &cv::SparseMat::ptr,
      Arg("i0"), Arg("i1"), Arg("create_missing"), ArgBuffer("hashval") = static_cast<size_t*>(0), ReturnBuffer()).
    define_method<uchar*(cv::SparseMat::*)(int, int, int, bool, size_t*)>("ptr", &cv::SparseMat::ptr,
      Arg("i0"), Arg("i1"), Arg("i2"), Arg("create_missing"), ArgBuffer("hashval") = static_cast<size_t*>(0), ReturnBuffer()).
    define_method<uchar*(cv::SparseMat::*)(const int*, bool, size_t*)>("ptr", &cv::SparseMat::ptr,
      ArgBuffer("idx"), Arg("create_missing"), ArgBuffer("hashval") = static_cast<size_t*>(0), ReturnBuffer()).
    define_method<void(cv::SparseMat::*)(int, int, size_t*)>("erase", &cv::SparseMat::erase,
      Arg("i0"), Arg("i1"), ArgBuffer("hashval") = static_cast<size_t*>(0)).
    define_method<void(cv::SparseMat::*)(int, int, int, size_t*)>("erase", &cv::SparseMat::erase,
      Arg("i0"), Arg("i1"), Arg("i2"), ArgBuffer("hashval") = static_cast<size_t*>(0)).
    define_method<void(cv::SparseMat::*)(const int*, size_t*)>("erase", &cv::SparseMat::erase,
      ArgBuffer("idx"), ArgBuffer("hashval") = static_cast<size_t*>(0)).
    // Manual - Comment out SparseMat define_iterator calls - SparseMatIterator doesn't dereference like standard iterators
    // define_iterator<cv::SparseMatIterator(cv::SparseMat::*)()>(&cv::SparseMat::begin, &cv::SparseMat::end, "each").
    // define_iterator<cv::SparseMatConstIterator(cv::SparseMat::*)() const>(&cv::SparseMat::begin, &cv::SparseMat::end, "each_const").
    define_method<cv::SparseMat::Node*(cv::SparseMat::*)(size_t)>("node", &cv::SparseMat::node,
      Arg("nidx")).
    define_method<const cv::SparseMat::Node*(cv::SparseMat::*)(size_t) const>("node", &cv::SparseMat::node,
      Arg("nidx")).
    define_method<uchar*(cv::SparseMat::*)(const int*, size_t)>("new_node", &cv::SparseMat::newNode,
      ArgBuffer("idx"), Arg("hashval"), ReturnBuffer()).
    define_method<void(cv::SparseMat::*)(size_t, size_t, size_t)>("remove_node", &cv::SparseMat::removeNode,
      Arg("hidx"), Arg("nidx"), Arg("previdx")).
    define_method<void(cv::SparseMat::*)(size_t)>("resize_hash_tab", &cv::SparseMat::resizeHashTab,
      Arg("newsize")).
    define_attr("flags", &cv::SparseMat::flags).
    define_attr("hdr", &cv::SparseMat::hdr);

  Rice::Data_Type<cv::SparseMat::Hdr> rb_cCvSparseMatHdr = define_class_under<cv::SparseMat::Hdr>(rb_cCvSparseMat, "Hdr").
    define_constructor(Constructor<cv::SparseMat::Hdr, int, const int*, int>(),
      Arg("_dims"), ArgBuffer("_sizes"), Arg("_type")).
    define_method<void(cv::SparseMat::Hdr::*)()>("clear", &cv::SparseMat::Hdr::clear).
    define_attr("refcount", &cv::SparseMat::Hdr::refcount).
    define_attr("dims", &cv::SparseMat::Hdr::dims).
    define_attr("value_offset", &cv::SparseMat::Hdr::valueOffset).
    define_attr("node_size", &cv::SparseMat::Hdr::nodeSize).
    define_attr("node_count", &cv::SparseMat::Hdr::nodeCount).
    define_attr("free_list", &cv::SparseMat::Hdr::freeList).
    define_attr("pool", &cv::SparseMat::Hdr::pool).
    define_attr("hashtab", &cv::SparseMat::Hdr::hashtab).
    define_attr("size", &cv::SparseMat::Hdr::size, Rice::AttrAccess::Read);

  Rice::Data_Type<cv::SparseMat::Node> rb_cCvSparseMatNode = define_class_under<cv::SparseMat::Node>(rb_cCvSparseMat, "Node").
    define_constructor(Constructor<cv::SparseMat::Node>()).
    define_attr("hashval", &cv::SparseMat::Node::hashval).
    define_attr("next", &cv::SparseMat::Node::next).
    define_attr("idx", &cv::SparseMat::Node::idx, Rice::AttrAccess::Read);

  rb_cCvSparseMat.define_constant("MAGIC_VAL", (int)cv::SparseMat::MAGIC_VAL);
  rb_cCvSparseMat.define_constant("MAX_DIM", (int)cv::SparseMat::MAX_DIM);
  rb_cCvSparseMat.define_constant("HASH_SCALE", (int)cv::SparseMat::HASH_SCALE);
  rb_cCvSparseMat.define_constant("HASH_BIT", (int)cv::SparseMat::HASH_BIT);

  Rice::Data_Type<cv::MatConstIterator> rb_cCvMatConstIterator = define_class_under<cv::MatConstIterator>(rb_mCv, "MatConstIterator").
    define_constructor(Constructor<cv::MatConstIterator>()).
    define_constructor(Constructor<cv::MatConstIterator, const cv::Mat*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::MatConstIterator, const cv::Mat*, int, int>(),
      Arg("_m"), Arg("_row"), Arg("_col") = static_cast<int>(0)).
    define_constructor(Constructor<cv::MatConstIterator, const cv::Mat*, cv::Point>(),
      Arg("_m"), Arg("_pt")).
    // Linker error - no explicit template instantiation
    // define_constructor(Constructor<cv::MatConstIterator, const cv::Mat*, const int*>(),
    //   Arg("_m"), ArgBuffer("_idx")).
    define_constructor(Constructor<cv::MatConstIterator, const cv::MatConstIterator&>(),
      Arg("it")).
    define_method<cv::MatConstIterator&(cv::MatConstIterator::*)(const cv::MatConstIterator&)>("assign", &cv::MatConstIterator::operator=,
      Arg("it")).
    define_method<const uchar*(cv::MatConstIterator::*)() const>("dereference", &cv::MatConstIterator::operator*,
      ReturnBuffer()).
    define_method<const uchar*(cv::MatConstIterator::*)(ptrdiff_t) const>("[]", &cv::MatConstIterator::operator[],
      Arg("i"), ReturnBuffer()).
    define_method<cv::MatConstIterator&(cv::MatConstIterator::*)(ptrdiff_t)>("assign_plus", &cv::MatConstIterator::operator+=,
      Arg("ofs")).
    define_method<cv::MatConstIterator&(cv::MatConstIterator::*)(ptrdiff_t)>("assign_minus", &cv::MatConstIterator::operator-=,
      Arg("ofs")).
    define_method<cv::MatConstIterator&(cv::MatConstIterator::*)()>("decrement", &cv::MatConstIterator::operator--).
    define_method<cv::MatConstIterator(cv::MatConstIterator::*)(int)>("decrement_post", &cv::MatConstIterator::operator--,
      Arg("arg_0")).
    define_method<cv::MatConstIterator&(cv::MatConstIterator::*)()>("increment", &cv::MatConstIterator::operator++).
    define_method<cv::MatConstIterator(cv::MatConstIterator::*)(int)>("increment_post", &cv::MatConstIterator::operator++,
      Arg("arg_0")).
    define_method<cv::Point(cv::MatConstIterator::*)() const>("pos", &cv::MatConstIterator::pos).
    define_method<void(cv::MatConstIterator::*)(int*) const>("pos", &cv::MatConstIterator::pos,
      ArgBuffer("_idx")).
    define_method<ptrdiff_t(cv::MatConstIterator::*)() const>("lpos", &cv::MatConstIterator::lpos).
    define_method<void(cv::MatConstIterator::*)(ptrdiff_t, bool)>("seek", &cv::MatConstIterator::seek,
      Arg("ofs"), Arg("relative") = static_cast<bool>(false)).
    define_method<void(cv::MatConstIterator::*)(const int*, bool)>("seek", &cv::MatConstIterator::seek,
      ArgBuffer("_idx"), Arg("relative") = static_cast<bool>(false)).
    define_attr("m", &cv::MatConstIterator::m).
    define_attr("elem_size", &cv::MatConstIterator::elemSize).
    define_attr("ptr", &cv::MatConstIterator::ptr).
    define_attr("slice_start", &cv::MatConstIterator::sliceStart).
    define_attr("slice_end", &cv::MatConstIterator::sliceEnd);

  Rice::Data_Type<cv::SparseMatConstIterator> rb_cCvSparseMatConstIterator = define_class_under<cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator").
    define_constructor(Constructor<cv::SparseMatConstIterator>()).
    define_constructor(Constructor<cv::SparseMatConstIterator, const cv::SparseMat*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::SparseMatConstIterator, const cv::SparseMatConstIterator&>(),
      Arg("it")).
    define_method<cv::SparseMatConstIterator&(cv::SparseMatConstIterator::*)(const cv::SparseMatConstIterator&)>("assign", &cv::SparseMatConstIterator::operator=,
      Arg("it")).
    define_method<const cv::SparseMat::Node*(cv::SparseMatConstIterator::*)() const>("node", &cv::SparseMatConstIterator::node).
    // Linker error - no explicit template instantiation
    // define_method<cv::SparseMatConstIterator&(cv::SparseMatConstIterator::*)()>("decrement", &cv::SparseMatConstIterator::operator--).
    // define_method<cv::SparseMatConstIterator(cv::SparseMatConstIterator::*)(int)>("decrement_post", &cv::SparseMatConstIterator::operator--,
    //   Arg("arg_0")).
    define_method<cv::SparseMatConstIterator&(cv::SparseMatConstIterator::*)()>("increment", &cv::SparseMatConstIterator::operator++).
    define_method<cv::SparseMatConstIterator(cv::SparseMatConstIterator::*)(int)>("increment_post", &cv::SparseMatConstIterator::operator++,
      Arg("arg_0")).
    define_method<void(cv::SparseMatConstIterator::*)()>("seek_end", &cv::SparseMatConstIterator::seekEnd).
    define_attr("m", &cv::SparseMatConstIterator::m).
    define_attr("hashidx", &cv::SparseMatConstIterator::hashidx).
    define_attr("ptr", &cv::SparseMatConstIterator::ptr);

  Rice::Data_Type<cv::SparseMatIterator> rb_cCvSparseMatIterator = define_class_under<cv::SparseMatIterator, cv::SparseMatConstIterator>(rb_mCv, "SparseMatIterator").
    define_constructor(Constructor<cv::SparseMatIterator>()).
    define_constructor(Constructor<cv::SparseMatIterator, cv::SparseMat*>(),
      Arg("_m")).
    // Linker error - no explicit template instantiation
    // define_constructor(Constructor<cv::SparseMatIterator, cv::SparseMat*, const int*>(),
    //   Arg("_m"), ArgBuffer("idx")).
    define_constructor(Constructor<cv::SparseMatIterator, const cv::SparseMatIterator&>(),
      Arg("it")).
    define_method<cv::SparseMatIterator&(cv::SparseMatIterator::*)(const cv::SparseMatIterator&)>("assign", &cv::SparseMatIterator::operator=,
      Arg("it")).
    define_method<cv::SparseMat::Node*(cv::SparseMatIterator::*)() const>("node", &cv::SparseMatIterator::node).
    define_method<cv::SparseMatIterator&(cv::SparseMatIterator::*)()>("increment", &cv::SparseMatIterator::operator++).
    define_method<cv::SparseMatIterator(cv::SparseMatIterator::*)(int)>("increment_post", &cv::SparseMatIterator::operator++,
      Arg("arg_0"));

  Rice::Data_Type<cv::NAryMatIterator> rb_cCvNAryMatIterator = define_class_under<cv::NAryMatIterator>(rb_mCv, "NAryMatIterator").
    define_constructor(Constructor<cv::NAryMatIterator>()).
    define_constructor(Constructor<cv::NAryMatIterator, const cv::Mat**, uchar**, int>(),
      ArgBuffer("arrays"), ArgBuffer("ptrs"), Arg("narrays") = static_cast<int>(-1)).
    define_constructor(Constructor<cv::NAryMatIterator, const cv::Mat**, cv::Mat*, int>(),
      ArgBuffer("arrays"), Arg("planes"), Arg("narrays") = static_cast<int>(-1)).
    define_method<void(cv::NAryMatIterator::*)(const cv::Mat**, cv::Mat*, uchar**, int)>("init", &cv::NAryMatIterator::init,
      ArgBuffer("arrays"), Arg("planes"), ArgBuffer("ptrs"), Arg("narrays") = static_cast<int>(-1)).
    define_method<cv::NAryMatIterator&(cv::NAryMatIterator::*)()>("increment", &cv::NAryMatIterator::operator++).
    define_method<cv::NAryMatIterator(cv::NAryMatIterator::*)(int)>("increment_post", &cv::NAryMatIterator::operator++,
      Arg("arg_0")).
    define_attr("arrays", &cv::NAryMatIterator::arrays).
    define_attr("planes", &cv::NAryMatIterator::planes).
    define_attr("ptrs", &cv::NAryMatIterator::ptrs).
    define_attr("narrays", &cv::NAryMatIterator::narrays).
    define_attr("nplanes", &cv::NAryMatIterator::nplanes).
    define_attr("size", &cv::NAryMatIterator::size);

  Rice::Data_Type<cv::MatOp> rb_cCvMatOp = define_class_under<cv::MatOp>(rb_mCv, "MatOp").
    define_method<bool(cv::MatOp::*)(const cv::MatExpr&) const>("element_wise", &cv::MatOp::elementWise,
      Arg("expr")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, cv::Mat&, int) const>("assign", &cv::MatOp::assign,
      Arg("expr"), Arg("m"), Arg("type") = static_cast<int>(-1)).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, const cv::Range&, const cv::Range&, cv::MatExpr&) const>("roi", &cv::MatOp::roi,
      Arg("expr"), Arg("row_range"), Arg("col_range"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, int, cv::MatExpr&) const>("diag", &cv::MatOp::diag,
      Arg("expr"), Arg("d"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, cv::Mat&) const>("aug_assign_add", &cv::MatOp::augAssignAdd,
      Arg("expr"), Arg("m")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, cv::Mat&) const>("aug_assign_subtract", &cv::MatOp::augAssignSubtract,
      Arg("expr"), Arg("m")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, cv::Mat&) const>("aug_assign_multiply", &cv::MatOp::augAssignMultiply,
      Arg("expr"), Arg("m")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, cv::Mat&) const>("aug_assign_divide", &cv::MatOp::augAssignDivide,
      Arg("expr"), Arg("m")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, cv::Mat&) const>("aug_assign_and", &cv::MatOp::augAssignAnd,
      Arg("expr"), Arg("m")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, cv::Mat&) const>("aug_assign_or", &cv::MatOp::augAssignOr,
      Arg("expr"), Arg("m")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, cv::Mat&) const>("aug_assign_xor", &cv::MatOp::augAssignXor,
      Arg("expr"), Arg("m")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, const cv::MatExpr&, cv::MatExpr&) const>("add", &cv::MatOp::add,
      Arg("expr1"), Arg("expr2"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, const cv::Scalar&, cv::MatExpr&) const>("add", &cv::MatOp::add,
      Arg("expr1"), Arg("s"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, const cv::MatExpr&, cv::MatExpr&) const>("subtract", &cv::MatOp::subtract,
      Arg("expr1"), Arg("expr2"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::Scalar&, const cv::MatExpr&, cv::MatExpr&) const>("subtract", &cv::MatOp::subtract,
      Arg("s"), Arg("expr"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, const cv::MatExpr&, cv::MatExpr&, double) const>("multiply", &cv::MatOp::multiply,
      Arg("expr1"), Arg("expr2"), Arg("res"), Arg("scale") = static_cast<double>(1)).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, double, cv::MatExpr&) const>("multiply", &cv::MatOp::multiply,
      Arg("expr1"), Arg("s"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, const cv::MatExpr&, cv::MatExpr&, double) const>("divide", &cv::MatOp::divide,
      Arg("expr1"), Arg("expr2"), Arg("res"), Arg("scale") = static_cast<double>(1)).
    define_method<void(cv::MatOp::*)(double, const cv::MatExpr&, cv::MatExpr&) const>("divide", &cv::MatOp::divide,
      Arg("s"), Arg("expr"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, cv::MatExpr&) const>("abs", &cv::MatOp::abs,
      Arg("expr"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, cv::MatExpr&) const>("transpose", &cv::MatOp::transpose,
      Arg("expr"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, const cv::MatExpr&, cv::MatExpr&) const>("matmul", &cv::MatOp::matmul,
      Arg("expr1"), Arg("expr2"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, int, cv::MatExpr&) const>("invert", &cv::MatOp::invert,
      Arg("expr"), Arg("method"), Arg("res")).
    define_method<cv::Size(cv::MatOp::*)(const cv::MatExpr&) const>("size", &cv::MatOp::size,
      Arg("expr")).
    define_method<int(cv::MatOp::*)(const cv::MatExpr&) const>("type", &cv::MatOp::type,
      Arg("expr"));

  Rice::Data_Type<cv::MatExpr> rb_cCvMatExpr = define_class_under<cv::MatExpr>(rb_mCv, "MatExpr").
    define_constructor(Constructor<cv::MatExpr>()).
    define_constructor(Constructor<cv::MatExpr, const cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::MatExpr, const cv::MatOp*, int, const cv::Mat&, const cv::Mat&, const cv::Mat&, double, double, const cv::Scalar&>(),
      Arg("_op"), Arg("_flags"), Arg("_a") = static_cast<const cv::Mat&>(cv::Mat()), Arg("_b") = static_cast<const cv::Mat&>(cv::Mat()), Arg("_c") = static_cast<const cv::Mat&>(cv::Mat()), Arg("_alpha") = static_cast<double>(1), Arg("_beta") = static_cast<double>(1), Arg("_s") = static_cast<const cv::Scalar&>(cv::Scalar())).
    define_method("to_mat", [](const cv::MatExpr& self) -> cv::Mat
    {
      return self;
    }).
    define_method<cv::Size(cv::MatExpr::*)() const>("size", &cv::MatExpr::size).
    define_method<int(cv::MatExpr::*)() const>("type", &cv::MatExpr::type).
    define_method<cv::MatExpr(cv::MatExpr::*)(int) const>("row", &cv::MatExpr::row,
      Arg("y")).
    define_method<cv::MatExpr(cv::MatExpr::*)(int) const>("col", &cv::MatExpr::col,
      Arg("x")).
    define_method<cv::MatExpr(cv::MatExpr::*)(int) const>("diag", &cv::MatExpr::diag,
      Arg("d") = static_cast<int>(0)).
    // Manual - changed "call" to "[]" for ROI access methods
    define_method<cv::MatExpr(cv::MatExpr::*)(const cv::Range&, const cv::Range&) const>("[]", &cv::MatExpr::operator(),
      Arg("row_range"), Arg("col_range")).
    define_method<cv::MatExpr(cv::MatExpr::*)(const cv::Rect&) const>("[]", &cv::MatExpr::operator(),
      Arg("roi")).
    define_method<cv::MatExpr(cv::MatExpr::*)() const>("t", &cv::MatExpr::t).
    define_method<cv::MatExpr(cv::MatExpr::*)(int) const>("inv", &cv::MatExpr::inv,
      Arg("method") = static_cast<int>(cv::DECOMP_LU)).
    define_method<cv::MatExpr(cv::MatExpr::*)(const cv::MatExpr&, double) const>("mul", &cv::MatExpr::mul,
      Arg("e"), Arg("scale") = static_cast<double>(1)).
    define_method<cv::MatExpr(cv::MatExpr::*)(const cv::Mat&, double) const>("mul", &cv::MatExpr::mul,
      Arg("m"), Arg("scale") = static_cast<double>(1)).
    define_method<cv::Mat(cv::MatExpr::*)(const cv::Mat&) const>("cross", &cv::MatExpr::cross,
      Arg("m")).
    define_method<double(cv::MatExpr::*)(const cv::Mat&) const>("dot", &cv::MatExpr::dot,
      Arg("m")).
    define_method<void(cv::MatExpr::*)(cv::MatExpr&)>("swap", &cv::MatExpr::swap,
      Arg("b")).
    define_attr("op", &cv::MatExpr::op).
    define_attr("flags", &cv::MatExpr::flags).
    define_attr("a", &cv::MatExpr::a).
    define_attr("b", &cv::MatExpr::b).
    define_attr("c", &cv::MatExpr::c).
    define_attr("alpha", &cv::MatExpr::alpha).
    define_attr("beta", &cv::MatExpr::beta).
    define_attr("s", &cv::MatExpr::s);

  rb_mCv.define_module_function<cv::MatExpr(*)(const cv::Mat&, const cv::Mat&)>("min", &cv::min,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function<cv::MatExpr(*)(const cv::Mat&, double)>("min", &cv::min,
    Arg("a"), Arg("s"));

  rb_mCv.define_module_function<cv::MatExpr(*)(double, const cv::Mat&)>("min", &cv::min,
    Arg("s"), Arg("a"));

  rb_mCv.define_module_function<cv::MatExpr(*)(const cv::Mat&, const cv::Mat&)>("max", &cv::max,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function<cv::MatExpr(*)(const cv::Mat&, double)>("max", &cv::max,
    Arg("a"), Arg("s"));

  rb_mCv.define_module_function<cv::MatExpr(*)(double, const cv::Mat&)>("max", &cv::max,
    Arg("s"), Arg("a"));

  rb_mCv.define_module_function<cv::MatExpr(*)(const cv::Mat&)>("abs", &cv::abs,
    Arg("m"));

  rb_mCv.define_module_function<cv::MatExpr(*)(const cv::MatExpr&)>("abs", &cv::abs,
    Arg("e"));

  rb_cCvMat.
    define_method("+", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self + other;
    }).
    define_method("+", [](const cv::Mat& self, const cv::Scalar& other) -> cv::MatExpr
    {
      return self + other;
    }).
    define_method("+", [](const cv::Mat& self, const cv::MatExpr& other) -> cv::MatExpr
    {
      return self + other;
    }).
    define_method("-", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self - other;
    }).
    define_method("-", [](const cv::Mat& self, const cv::Scalar& other) -> cv::MatExpr
    {
      return self - other;
    }).
    define_method("-", [](const cv::Mat& self, const cv::MatExpr& other) -> cv::MatExpr
    {
      return self - other;
    }).
    define_method("-@", [](const cv::Mat& self) -> cv::MatExpr
    {
      return -self;
    }).
    define_method("*", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self * other;
    }).
    define_method("*", [](const cv::Mat& self, double other) -> cv::MatExpr
    {
      return self * other;
    }).
    define_method("*", [](const cv::Mat& self, const cv::MatExpr& other) -> cv::MatExpr
    {
      return self * other;
    }).
    define_method("/", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self / other;
    }).
    define_method("/", [](const cv::Mat& self, double other) -> cv::MatExpr
    {
      return self / other;
    }).
    define_method("/", [](const cv::Mat& self, const cv::MatExpr& other) -> cv::MatExpr
    {
      return self / other;
    }).
    define_method("<", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self < other;
    }).
    define_method("<", [](const cv::Mat& self, double other) -> cv::MatExpr
    {
      return self < other;
    }).
    define_method("<=", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self <= other;
    }).
    define_method("<=", [](const cv::Mat& self, double other) -> cv::MatExpr
    {
      return self <= other;
    }).
    define_method("==", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self == other;
    }).
    define_method("==", [](const cv::Mat& self, double other) -> cv::MatExpr
    {
      return self == other;
    }).
    define_method("!=", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self != other;
    }).
    define_method("!=", [](const cv::Mat& self, double other) -> cv::MatExpr
    {
      return self != other;
    }).
    define_method(">=", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self >= other;
    }).
    define_method(">=", [](const cv::Mat& self, double other) -> cv::MatExpr
    {
      return self >= other;
    }).
    define_method(">", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self > other;
    }).
    define_method(">", [](const cv::Mat& self, double other) -> cv::MatExpr
    {
      return self > other;
    }).
    define_method("&", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self & other;
    }).
    define_method("&", [](const cv::Mat& self, const cv::Scalar& other) -> cv::MatExpr
    {
      return self & other;
    }).
    define_method("|", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self | other;
    }).
    define_method("|", [](const cv::Mat& self, const cv::Scalar& other) -> cv::MatExpr
    {
      return self | other;
    }).
    define_method("^", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self ^ other;
    }).
    define_method("^", [](const cv::Mat& self, const cv::Scalar& other) -> cv::MatExpr
    {
      return self ^ other;
    }).
    define_method("~", [](const cv::Mat& self) -> cv::MatExpr
    {
      return ~self;
    });
  
  Data_Type<cv::Scalar>().
    define_method("+", [](const cv::Scalar& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self + other;
    }).
    define_method("+", [](const cv::Scalar& self, const cv::MatExpr& other) -> cv::MatExpr
    {
      return self + other;
    }).
    define_method("-", [](const cv::Scalar& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self - other;
    }).
    define_method("-", [](const cv::Scalar& self, const cv::MatExpr& other) -> cv::MatExpr
    {
      return self - other;
    }).
    define_method("&", [](const cv::Scalar& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self & other;
    }).
    define_method("|", [](const cv::Scalar& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self | other;
    }).
    define_method("^", [](const cv::Scalar& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self ^ other;
    });
  
  rb_cCvMatExpr.
    define_method("+", [](const cv::MatExpr& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self + other;
    }).
    define_method("+", [](const cv::MatExpr& self, const cv::Scalar& other) -> cv::MatExpr
    {
      return self + other;
    }).
    define_method("+", [](const cv::MatExpr& self, const cv::MatExpr& other) -> cv::MatExpr
    {
      return self + other;
    }).
    define_method("-", [](const cv::MatExpr& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self - other;
    }).
    define_method("-", [](const cv::MatExpr& self, const cv::Scalar& other) -> cv::MatExpr
    {
      return self - other;
    }).
    define_method("-", [](const cv::MatExpr& self, const cv::MatExpr& other) -> cv::MatExpr
    {
      return self - other;
    }).
    define_method("-@", [](const cv::MatExpr& self) -> cv::MatExpr
    {
      return -self;
    }).
    define_method("*", [](const cv::MatExpr& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self * other;
    }).
    define_method("*", [](const cv::MatExpr& self, double other) -> cv::MatExpr
    {
      return self * other;
    }).
    define_method("*", [](const cv::MatExpr& self, const cv::MatExpr& other) -> cv::MatExpr
    {
      return self * other;
    }).
    define_method("/", [](const cv::MatExpr& self, const cv::Mat& other) -> cv::MatExpr
    {
      return self / other;
    }).
    define_method("/", [](const cv::MatExpr& self, double other) -> cv::MatExpr
    {
      return self / other;
    }).
    define_method("/", [](const cv::MatExpr& self, const cv::MatExpr& other) -> cv::MatExpr
    {
      return self / other;
    });
}