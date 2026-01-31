#include <opencv2/core/cuda/vec_math.hpp>
#include "vec_math-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_VecMath()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Module rb_mCvCudaDeviceVecMathDetail = define_module_under(rb_mCvCudaDevice, "VecMathDetail");

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("abs", &cv::cuda::device::abs,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("abs", &cv::cuda::device::abs,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("abs", &cv::cuda::device::abs,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("abs", &cv::cuda::device::abs,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("sqrt", &cv::cuda::device::sqrt,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("exp", &cv::cuda::device::exp,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("exp2", &cv::cuda::device::exp2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("exp10", &cv::cuda::device::exp10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("log", &cv::cuda::device::log,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("log2", &cv::cuda::device::log2,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("log10", &cv::cuda::device::log10,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("sin", &cv::cuda::device::sin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("cos", &cv::cuda::device::cos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("tan", &cv::cuda::device::tan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("asin", &cv::cuda::device::asin,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("acos", &cv::cuda::device::acos,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("atan", &cv::cuda::device::atan,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("sinh", &cv::cuda::device::sinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("cosh", &cv::cuda::device::cosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("tanh", &cv::cuda::device::tanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("asinh", &cv::cuda::device::asinh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("acosh", &cv::cuda::device::acosh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&)>("atanh", &cv::cuda::device::atanh,
    Arg("a"));

  rb_mCvCudaDevice.define_module_function<uchar1(*)(const uchar1&, const uchar1&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar2(*)(const uchar2&, const uchar2&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar3(*)(const uchar3&, const uchar3&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar4(*)(const uchar4&, const uchar4&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char1(*)(const char1&, const char1&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char2(*)(const char2&, const char2&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char3(*)(const char3&, const char3&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char4(*)(const char4&, const char4&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort1(*)(const ushort1&, const ushort1&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort2(*)(const ushort2&, const ushort2&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort3(*)(const ushort3&, const ushort3&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort4(*)(const ushort4&, const ushort4&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short1(*)(const short1&, const short1&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short2(*)(const short2&, const short2&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short3(*)(const short3&, const short3&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short4(*)(const short4&, const short4&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint1(*)(const uint1&, const uint1&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint2(*)(const uint2&, const uint2&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint3(*)(const uint3&, const uint3&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint4(*)(const uint4&, const uint4&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int1(*)(const int1&, const int1&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int2(*)(const int2&, const int2&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int3(*)(const int3&, const int3&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int4(*)(const int4&, const int4&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&, const float1&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&, const float2&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&, const float3&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&, const float4&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&, const double1&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&, const double2&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&, const double3&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&, const double4&)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar1(*)(const uchar1&, const uchar1&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar2(*)(const uchar2&, const uchar2&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar3(*)(const uchar3&, const uchar3&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar4(*)(const uchar4&, const uchar4&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char1(*)(const char1&, const char1&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char2(*)(const char2&, const char2&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char3(*)(const char3&, const char3&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char4(*)(const char4&, const char4&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort1(*)(const ushort1&, const ushort1&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort2(*)(const ushort2&, const ushort2&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort3(*)(const ushort3&, const ushort3&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort4(*)(const ushort4&, const ushort4&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short1(*)(const short1&, const short1&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short2(*)(const short2&, const short2&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short3(*)(const short3&, const short3&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short4(*)(const short4&, const short4&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint1(*)(const uint1&, const uint1&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint2(*)(const uint2&, const uint2&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint3(*)(const uint3&, const uint3&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint4(*)(const uint4&, const uint4&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int1(*)(const int1&, const int1&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int2(*)(const int2&, const int2&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int3(*)(const int3&, const int3&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int4(*)(const int4&, const int4&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&, const float1&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&, const float2&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&, const float3&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&, const float4&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&, const double1&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&, const double2&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&, const double3&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&, const double4&)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&, const uchar1&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&, const uchar2&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&, const uchar3&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&, const uchar4&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&, const char1&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&, const char2&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&, const char3&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&, const char4&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&, const ushort1&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&, const ushort2&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&, const ushort3&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&, const ushort4&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&, const short1&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&, const short2&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&, const short3&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&, const short4&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&, const uint1&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&, const uint2&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&, const uint3&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&, const uint4&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&, const int1&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&, const int2&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&, const int3&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&, const int4&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&, const float1&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&, const float2&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&, const float3&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&, const float4&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&, const double1&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&, const double2&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&, const double3&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&, const double4&)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&, const uchar1&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&, const uchar2&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&, const uchar3&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&, const uchar4&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&, const char1&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&, const char2&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&, const char3&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&, const char4&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&, const ushort1&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&, const ushort2&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&, const ushort3&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&, const ushort4&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&, const short1&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&, const short2&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&, const short3&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&, const short4&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&, const uint1&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&, const uint2&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&, const uint3&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&, const uint4&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&, const int1&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&, const int2&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&, const int3&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&, const int4&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&, const float1&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&, const float2&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&, const float3&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&, const float4&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&, const double1&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&, const double2&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&, const double3&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&, const double4&)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar1(*)(const uchar1&, uchar)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uchar1(*)(uchar, const uchar1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar2(*)(const uchar2&, uchar)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uchar2(*)(uchar, const uchar2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar3(*)(const uchar3&, uchar)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uchar3(*)(uchar, const uchar3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar4(*)(const uchar4&, uchar)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uchar4(*)(uchar, const uchar4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const uchar1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const uchar2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const uchar3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const uchar4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const uchar1&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const uchar1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const uchar2&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const uchar2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const uchar3&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const uchar3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const uchar4&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const uchar4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char1(*)(const char1&, char)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<char1(*)(char, const char1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char2(*)(const char2&, char)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<char2(*)(char, const char2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char3(*)(const char3&, char)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<char3(*)(char, const char3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char4(*)(const char4&, char)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<char4(*)(char, const char4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const char1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const char2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const char3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const char4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const char1&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const char1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const char2&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const char2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const char3&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const char3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const char4&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const char4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort1(*)(const ushort1&, ushort)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<ushort1(*)(ushort, const ushort1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort2(*)(const ushort2&, ushort)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<ushort2(*)(ushort, const ushort2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort3(*)(const ushort3&, ushort)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<ushort3(*)(ushort, const ushort3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort4(*)(const ushort4&, ushort)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<ushort4(*)(ushort, const ushort4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const ushort1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const ushort2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const ushort3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const ushort4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const ushort1&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const ushort1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const ushort2&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const ushort2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const ushort3&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const ushort3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const ushort4&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const ushort4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short1(*)(const short1&, short)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<short1(*)(short, const short1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short2(*)(const short2&, short)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<short2(*)(short, const short2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short3(*)(const short3&, short)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<short3(*)(short, const short3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short4(*)(const short4&, short)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<short4(*)(short, const short4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const short1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const short2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const short3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const short4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const short1&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const short1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const short2&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const short2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const short3&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const short3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const short4&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const short4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint1(*)(const uint1&, uint)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uint1(*)(uint, const uint1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint2(*)(const uint2&, uint)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uint2(*)(uint, const uint2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint3(*)(const uint3&, uint)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uint3(*)(uint, const uint3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint4(*)(const uint4&, uint)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uint4(*)(uint, const uint4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const uint1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const uint2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const uint3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const uint4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const uint1&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const uint1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const uint2&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const uint2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const uint3&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const uint3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const uint4&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const uint4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int1(*)(const int1&, int)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<int1(*)(int, const int1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int2(*)(const int2&, int)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<int2(*)(int, const int2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int3(*)(const int3&, int)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<int3(*)(int, const int3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int4(*)(const int4&, int)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<int4(*)(int, const int4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const int1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const int2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const int3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const int4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const int1&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const int1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const int2&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const int2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const int3&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const int3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const int4&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const int4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const float1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const float2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const float3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&, float)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const float4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const float1&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const float1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const float2&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const float2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const float3&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const float3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const float4&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const float4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const double1&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const double2&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const double3&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&, double)>("max", &cv::cuda::device::max,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const double4&)>("max", &cv::cuda::device::max,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar1(*)(const uchar1&, uchar)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uchar1(*)(uchar, const uchar1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar2(*)(const uchar2&, uchar)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uchar2(*)(uchar, const uchar2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar3(*)(const uchar3&, uchar)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uchar3(*)(uchar, const uchar3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uchar4(*)(const uchar4&, uchar)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uchar4(*)(uchar, const uchar4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const uchar1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const uchar2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const uchar3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const uchar4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const uchar1&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const uchar1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const uchar2&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const uchar2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const uchar3&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const uchar3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const uchar4&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const uchar4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char1(*)(const char1&, char)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<char1(*)(char, const char1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char2(*)(const char2&, char)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<char2(*)(char, const char2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char3(*)(const char3&, char)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<char3(*)(char, const char3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<char4(*)(const char4&, char)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<char4(*)(char, const char4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const char1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const char2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const char3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const char4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const char1&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const char1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const char2&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const char2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const char3&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const char3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const char4&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const char4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort1(*)(const ushort1&, ushort)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<ushort1(*)(ushort, const ushort1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort2(*)(const ushort2&, ushort)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<ushort2(*)(ushort, const ushort2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort3(*)(const ushort3&, ushort)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<ushort3(*)(ushort, const ushort3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<ushort4(*)(const ushort4&, ushort)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<ushort4(*)(ushort, const ushort4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const ushort1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const ushort2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const ushort3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const ushort4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const ushort1&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const ushort1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const ushort2&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const ushort2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const ushort3&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const ushort3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const ushort4&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const ushort4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short1(*)(const short1&, short)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<short1(*)(short, const short1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short2(*)(const short2&, short)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<short2(*)(short, const short2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short3(*)(const short3&, short)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<short3(*)(short, const short3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<short4(*)(const short4&, short)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<short4(*)(short, const short4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const short1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const short2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const short3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const short4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const short1&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const short1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const short2&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const short2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const short3&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const short3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const short4&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const short4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint1(*)(const uint1&, uint)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uint1(*)(uint, const uint1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint2(*)(const uint2&, uint)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uint2(*)(uint, const uint2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint3(*)(const uint3&, uint)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uint3(*)(uint, const uint3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<uint4(*)(const uint4&, uint)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<uint4(*)(uint, const uint4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const uint1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const uint2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const uint3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const uint4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const uint1&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const uint1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const uint2&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const uint2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const uint3&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const uint3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const uint4&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const uint4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int1(*)(const int1&, int)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<int1(*)(int, const int1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int2(*)(const int2&, int)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<int2(*)(int, const int2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int3(*)(const int3&, int)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<int3(*)(int, const int3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<int4(*)(const int4&, int)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<int4(*)(int, const int4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const int1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const int2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const int3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const int4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const int1&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const int1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const int2&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const int2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const int3&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const int3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const int4&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const int4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const float1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const float2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const float3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&, float)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const float4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const float1&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const float1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const float2&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const float2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const float3&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const float3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const float4&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const float4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const double1&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const double2&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const double3&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&, double)>("min", &cv::cuda::device::min,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const double4&)>("min", &cv::cuda::device::min,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const uchar1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const uchar2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const uchar3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const uchar4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const uchar1&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const uchar1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const uchar2&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const uchar2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const uchar3&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const uchar3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const uchar4&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const uchar4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const char1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const char2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const char3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const char4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const char1&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const char1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const char2&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const char2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const char3&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const char3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const char4&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const char4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const ushort1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const ushort2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const ushort3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const ushort4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const ushort1&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const ushort1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const ushort2&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const ushort2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const ushort3&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const ushort3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const ushort4&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const ushort4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const short1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const short2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const short3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const short4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const short1&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const short1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const short2&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const short2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const short3&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const short3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const short4&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const short4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const uint1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const uint2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const uint3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const uint4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const uint1&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const uint1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const uint2&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const uint2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const uint3&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const uint3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const uint4&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const uint4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const int1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const int2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const int3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const int4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const int1&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const int1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const int2&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const int2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const int3&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const int3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const int4&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const int4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const float1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const float2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const float3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&, float)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const float4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const float1&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const float1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const float2&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const float2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const float3&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const float3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const float4&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const float4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const double1&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const double2&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const double3&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&, double)>("hypot", &cv::cuda::device::hypot,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const double4&)>("hypot", &cv::cuda::device::hypot,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uchar1&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const uchar1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uchar2&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const uchar2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uchar3&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const uchar3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uchar4&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const uchar4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const uchar1&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const uchar1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const uchar2&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const uchar2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const uchar3&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const uchar3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const uchar4&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const uchar4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const char1&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const char1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const char2&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const char2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const char3&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const char3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const char4&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const char4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const char1&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const char1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const char2&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const char2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const char3&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const char3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const char4&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const char4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const ushort1&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const ushort1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const ushort2&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const ushort2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const ushort3&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const ushort3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const ushort4&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const ushort4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const ushort1&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const ushort1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const ushort2&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const ushort2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const ushort3&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const ushort3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const ushort4&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const ushort4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const short1&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const short1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const short2&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const short2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const short3&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const short3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const short4&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const short4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const short1&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const short1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const short2&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const short2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const short3&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const short3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const short4&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const short4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const uint1&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const uint1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const uint2&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const uint2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const uint3&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const uint3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const uint4&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const uint4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const uint1&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const uint1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const uint2&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const uint2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const uint3&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const uint3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const uint4&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const uint4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const int1&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const int1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const int2&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const int2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const int3&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const int3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const int4&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const int4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const int1&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const int1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const int2&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const int2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const int3&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const int3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const int4&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const int4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float1(*)(const float1&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float1(*)(float, const float1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float2(*)(const float2&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float2(*)(float, const float2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float3(*)(const float3&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float3(*)(float, const float3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<float4(*)(const float4&, float)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<float4(*)(float, const float4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const float1&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const float1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const float2&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const float2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const float3&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const float3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const float4&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const float4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double1(*)(const double1&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double1(*)(double, const double1&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double2(*)(const double2&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double2(*)(double, const double2&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double3(*)(const double3&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double3(*)(double, const double3&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_mCvCudaDevice.define_module_function<double4(*)(const double4&, double)>("atan2", &cv::cuda::device::atan2,
    Arg("a"), Arg("s"));

  rb_mCvCudaDevice.define_module_function<double4(*)(double, const double4&)>("atan2", &cv::cuda::device::atan2,
    Arg("s"), Arg("b"));

  rb_cUchar1.
    define_method("+", [](const uchar1& self, const uchar1& other) -> int1
  {
    return self + other;
  }).
    define_method("-", [](const uchar1& self, const uchar1& other) -> int1
  {
    return self - other;
  }).
    define_method("*", [](const uchar1& self, const uchar1& other) -> int1
  {
    return self * other;
  }).
    define_method("/", [](const uchar1& self, const uchar1& other) -> int1
  {
    return self / other;
  }).
    define_method("==", [](const uchar1& self, const uchar1& other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const uchar1& self, const uchar1& other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const uchar1& self, const uchar1& other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const uchar1& self, const uchar1& other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const uchar1& self, const uchar1& other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const uchar1& self, const uchar1& other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uchar1& self, const uchar1& other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const uchar1& self, const uchar1& other) -> uchar1
  {
    return self || other;
  }).
    define_method("&", [](const uchar1& self, const uchar1& other) -> uchar1
  {
    return self & other;
  }).
    define_method("|", [](const uchar1& self, const uchar1& other) -> uchar1
  {
    return self | other;
  }).
    define_method("^", [](const uchar1& self, const uchar1& other) -> uchar1
  {
    return self ^ other;
  }).
    define_method("+", [](const uchar1& self, int other) -> int1
  {
    return self + other;
  }).
    define_method("+", [](const uchar1& self, float other) -> float1
  {
    return self + other;
  }).
    define_method("+", [](const uchar1& self, double other) -> double1
  {
    return self + other;
  }).
    define_method("-", [](const uchar1& self, int other) -> int1
  {
    return self - other;
  }).
    define_method("-", [](const uchar1& self, float other) -> float1
  {
    return self - other;
  }).
    define_method("-", [](const uchar1& self, double other) -> double1
  {
    return self - other;
  }).
    define_method("*", [](const uchar1& self, int other) -> int1
  {
    return self * other;
  }).
    define_method("*", [](const uchar1& self, float other) -> float1
  {
    return self * other;
  }).
    define_method("*", [](const uchar1& self, double other) -> double1
  {
    return self * other;
  }).
    define_method("/", [](const uchar1& self, int other) -> int1
  {
    return self / other;
  }).
    define_method("/", [](const uchar1& self, float other) -> float1
  {
    return self / other;
  }).
    define_method("/", [](const uchar1& self, double other) -> double1
  {
    return self / other;
  }).
    define_method("==", [](const uchar1& self, uchar other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const uchar1& self, uchar other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const uchar1& self, uchar other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const uchar1& self, uchar other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const uchar1& self, uchar other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const uchar1& self, uchar other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uchar1& self, uchar other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const uchar1& self, uchar other) -> uchar1
  {
    return self || other;
  }).
    define_method("&", [](const uchar1& self, uchar other) -> uchar1
  {
    return self & other;
  }).
    define_method("|", [](const uchar1& self, uchar other) -> uchar1
  {
    return self | other;
  }).
    define_method("^", [](const uchar1& self, uchar other) -> uchar1
  {
    return self ^ other;
  });
  
  rb_cUchar2.
    define_method("+", [](const uchar2& self, const uchar2& other) -> int2
  {
    return self + other;
  }).
    define_method("-", [](const uchar2& self, const uchar2& other) -> int2
  {
    return self - other;
  }).
    define_method("*", [](const uchar2& self, const uchar2& other) -> int2
  {
    return self * other;
  }).
    define_method("/", [](const uchar2& self, const uchar2& other) -> int2
  {
    return self / other;
  }).
    define_method("==", [](const uchar2& self, const uchar2& other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const uchar2& self, const uchar2& other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const uchar2& self, const uchar2& other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const uchar2& self, const uchar2& other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const uchar2& self, const uchar2& other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const uchar2& self, const uchar2& other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uchar2& self, const uchar2& other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const uchar2& self, const uchar2& other) -> uchar2
  {
    return self || other;
  }).
    define_method("&", [](const uchar2& self, const uchar2& other) -> uchar2
  {
    return self & other;
  }).
    define_method("|", [](const uchar2& self, const uchar2& other) -> uchar2
  {
    return self | other;
  }).
    define_method("^", [](const uchar2& self, const uchar2& other) -> uchar2
  {
    return self ^ other;
  }).
    define_method("+", [](const uchar2& self, int other) -> int2
  {
    return self + other;
  }).
    define_method("+", [](const uchar2& self, float other) -> float2
  {
    return self + other;
  }).
    define_method("+", [](const uchar2& self, double other) -> double2
  {
    return self + other;
  }).
    define_method("-", [](const uchar2& self, int other) -> int2
  {
    return self - other;
  }).
    define_method("-", [](const uchar2& self, float other) -> float2
  {
    return self - other;
  }).
    define_method("-", [](const uchar2& self, double other) -> double2
  {
    return self - other;
  }).
    define_method("*", [](const uchar2& self, int other) -> int2
  {
    return self * other;
  }).
    define_method("*", [](const uchar2& self, float other) -> float2
  {
    return self * other;
  }).
    define_method("*", [](const uchar2& self, double other) -> double2
  {
    return self * other;
  }).
    define_method("/", [](const uchar2& self, int other) -> int2
  {
    return self / other;
  }).
    define_method("/", [](const uchar2& self, float other) -> float2
  {
    return self / other;
  }).
    define_method("/", [](const uchar2& self, double other) -> double2
  {
    return self / other;
  }).
    define_method("==", [](const uchar2& self, uchar other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const uchar2& self, uchar other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const uchar2& self, uchar other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const uchar2& self, uchar other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const uchar2& self, uchar other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const uchar2& self, uchar other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uchar2& self, uchar other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const uchar2& self, uchar other) -> uchar2
  {
    return self || other;
  }).
    define_method("&", [](const uchar2& self, uchar other) -> uchar2
  {
    return self & other;
  }).
    define_method("|", [](const uchar2& self, uchar other) -> uchar2
  {
    return self | other;
  }).
    define_method("^", [](const uchar2& self, uchar other) -> uchar2
  {
    return self ^ other;
  });
  
  rb_cUchar3.
    define_method("+", [](const uchar3& self, const uchar3& other) -> int3
  {
    return self + other;
  }).
    define_method("-", [](const uchar3& self, const uchar3& other) -> int3
  {
    return self - other;
  }).
    define_method("*", [](const uchar3& self, const uchar3& other) -> int3
  {
    return self * other;
  }).
    define_method("/", [](const uchar3& self, const uchar3& other) -> int3
  {
    return self / other;
  }).
    define_method("==", [](const uchar3& self, const uchar3& other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const uchar3& self, const uchar3& other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const uchar3& self, const uchar3& other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const uchar3& self, const uchar3& other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const uchar3& self, const uchar3& other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const uchar3& self, const uchar3& other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uchar3& self, const uchar3& other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const uchar3& self, const uchar3& other) -> uchar3
  {
    return self || other;
  }).
    define_method("&", [](const uchar3& self, const uchar3& other) -> uchar3
  {
    return self & other;
  }).
    define_method("|", [](const uchar3& self, const uchar3& other) -> uchar3
  {
    return self | other;
  }).
    define_method("^", [](const uchar3& self, const uchar3& other) -> uchar3
  {
    return self ^ other;
  }).
    define_method("+", [](const uchar3& self, int other) -> int3
  {
    return self + other;
  }).
    define_method("+", [](const uchar3& self, float other) -> float3
  {
    return self + other;
  }).
    define_method("+", [](const uchar3& self, double other) -> double3
  {
    return self + other;
  }).
    define_method("-", [](const uchar3& self, int other) -> int3
  {
    return self - other;
  }).
    define_method("-", [](const uchar3& self, float other) -> float3
  {
    return self - other;
  }).
    define_method("-", [](const uchar3& self, double other) -> double3
  {
    return self - other;
  }).
    define_method("*", [](const uchar3& self, int other) -> int3
  {
    return self * other;
  }).
    define_method("*", [](const uchar3& self, float other) -> float3
  {
    return self * other;
  }).
    define_method("*", [](const uchar3& self, double other) -> double3
  {
    return self * other;
  }).
    define_method("/", [](const uchar3& self, int other) -> int3
  {
    return self / other;
  }).
    define_method("/", [](const uchar3& self, float other) -> float3
  {
    return self / other;
  }).
    define_method("/", [](const uchar3& self, double other) -> double3
  {
    return self / other;
  }).
    define_method("==", [](const uchar3& self, uchar other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const uchar3& self, uchar other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const uchar3& self, uchar other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const uchar3& self, uchar other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const uchar3& self, uchar other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const uchar3& self, uchar other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uchar3& self, uchar other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const uchar3& self, uchar other) -> uchar3
  {
    return self || other;
  }).
    define_method("&", [](const uchar3& self, uchar other) -> uchar3
  {
    return self & other;
  }).
    define_method("|", [](const uchar3& self, uchar other) -> uchar3
  {
    return self | other;
  }).
    define_method("^", [](const uchar3& self, uchar other) -> uchar3
  {
    return self ^ other;
  });
  
  rb_cUchar4.
    define_method("+", [](const uchar4& self, const uchar4& other) -> int4
  {
    return self + other;
  }).
    define_method("-", [](const uchar4& self, const uchar4& other) -> int4
  {
    return self - other;
  }).
    define_method("*", [](const uchar4& self, const uchar4& other) -> int4
  {
    return self * other;
  }).
    define_method("/", [](const uchar4& self, const uchar4& other) -> int4
  {
    return self / other;
  }).
    define_method("==", [](const uchar4& self, const uchar4& other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const uchar4& self, const uchar4& other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const uchar4& self, const uchar4& other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const uchar4& self, const uchar4& other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const uchar4& self, const uchar4& other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const uchar4& self, const uchar4& other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uchar4& self, const uchar4& other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const uchar4& self, const uchar4& other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](const uchar4& self, const uchar4& other) -> uchar4
  {
    return self & other;
  }).
    define_method("|", [](const uchar4& self, const uchar4& other) -> uchar4
  {
    return self | other;
  }).
    define_method("^", [](const uchar4& self, const uchar4& other) -> uchar4
  {
    return self ^ other;
  }).
    define_method("+", [](const uchar4& self, int other) -> int4
  {
    return self + other;
  }).
    define_method("+", [](const uchar4& self, float other) -> float4
  {
    return self + other;
  }).
    define_method("+", [](const uchar4& self, double other) -> double4
  {
    return self + other;
  }).
    define_method("-", [](const uchar4& self, int other) -> int4
  {
    return self - other;
  }).
    define_method("-", [](const uchar4& self, float other) -> float4
  {
    return self - other;
  }).
    define_method("-", [](const uchar4& self, double other) -> double4
  {
    return self - other;
  }).
    define_method("*", [](const uchar4& self, int other) -> int4
  {
    return self * other;
  }).
    define_method("*", [](const uchar4& self, float other) -> float4
  {
    return self * other;
  }).
    define_method("*", [](const uchar4& self, double other) -> double4
  {
    return self * other;
  }).
    define_method("/", [](const uchar4& self, int other) -> int4
  {
    return self / other;
  }).
    define_method("/", [](const uchar4& self, float other) -> float4
  {
    return self / other;
  }).
    define_method("/", [](const uchar4& self, double other) -> double4
  {
    return self / other;
  }).
    define_method("==", [](const uchar4& self, uchar other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const uchar4& self, uchar other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const uchar4& self, uchar other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const uchar4& self, uchar other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const uchar4& self, uchar other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const uchar4& self, uchar other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uchar4& self, uchar other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const uchar4& self, uchar other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](const uchar4& self, uchar other) -> uchar4
  {
    return self & other;
  }).
    define_method("|", [](const uchar4& self, uchar other) -> uchar4
  {
    return self | other;
  }).
    define_method("^", [](const uchar4& self, uchar other) -> uchar4
  {
    return self ^ other;
  });
  
  rb_cChar1.
    define_method("+", [](const char1& self, const char1& other) -> int1
  {
    return self + other;
  }).
    define_method("-", [](const char1& self, const char1& other) -> int1
  {
    return self - other;
  }).
    define_method("*", [](const char1& self, const char1& other) -> int1
  {
    return self * other;
  }).
    define_method("/", [](const char1& self, const char1& other) -> int1
  {
    return self / other;
  }).
    define_method("==", [](const char1& self, const char1& other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const char1& self, const char1& other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const char1& self, const char1& other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const char1& self, const char1& other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const char1& self, const char1& other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const char1& self, const char1& other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const char1& self, const char1& other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const char1& self, const char1& other) -> uchar1
  {
    return self || other;
  }).
    define_method("&", [](const char1& self, const char1& other) -> char1
  {
    return self & other;
  }).
    define_method("|", [](const char1& self, const char1& other) -> char1
  {
    return self | other;
  }).
    define_method("^", [](const char1& self, const char1& other) -> char1
  {
    return self ^ other;
  }).
    define_method("+", [](const char1& self, int other) -> int1
  {
    return self + other;
  }).
    define_method("+", [](const char1& self, float other) -> float1
  {
    return self + other;
  }).
    define_method("+", [](const char1& self, double other) -> double1
  {
    return self + other;
  }).
    define_method("-", [](const char1& self, int other) -> int1
  {
    return self - other;
  }).
    define_method("-", [](const char1& self, float other) -> float1
  {
    return self - other;
  }).
    define_method("-", [](const char1& self, double other) -> double1
  {
    return self - other;
  }).
    define_method("*", [](const char1& self, int other) -> int1
  {
    return self * other;
  }).
    define_method("*", [](const char1& self, float other) -> float1
  {
    return self * other;
  }).
    define_method("*", [](const char1& self, double other) -> double1
  {
    return self * other;
  }).
    define_method("/", [](const char1& self, int other) -> int1
  {
    return self / other;
  }).
    define_method("/", [](const char1& self, float other) -> float1
  {
    return self / other;
  }).
    define_method("/", [](const char1& self, double other) -> double1
  {
    return self / other;
  }).
    define_method("==", [](const char1& self, char other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const char1& self, char other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const char1& self, char other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const char1& self, char other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const char1& self, char other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const char1& self, char other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const char1& self, char other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const char1& self, char other) -> uchar1
  {
    return self || other;
  }).
    define_method("&", [](const char1& self, char other) -> char1
  {
    return self & other;
  }).
    define_method("|", [](const char1& self, char other) -> char1
  {
    return self | other;
  }).
    define_method("^", [](const char1& self, char other) -> char1
  {
    return self ^ other;
  });
  
  rb_cChar2.
    define_method("+", [](const char2& self, const char2& other) -> int2
  {
    return self + other;
  }).
    define_method("-", [](const char2& self, const char2& other) -> int2
  {
    return self - other;
  }).
    define_method("*", [](const char2& self, const char2& other) -> int2
  {
    return self * other;
  }).
    define_method("/", [](const char2& self, const char2& other) -> int2
  {
    return self / other;
  }).
    define_method("==", [](const char2& self, const char2& other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const char2& self, const char2& other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const char2& self, const char2& other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const char2& self, const char2& other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const char2& self, const char2& other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const char2& self, const char2& other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const char2& self, const char2& other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const char2& self, const char2& other) -> uchar2
  {
    return self || other;
  }).
    define_method("&", [](const char2& self, const char2& other) -> char2
  {
    return self & other;
  }).
    define_method("|", [](const char2& self, const char2& other) -> char2
  {
    return self | other;
  }).
    define_method("^", [](const char2& self, const char2& other) -> char2
  {
    return self ^ other;
  }).
    define_method("+", [](const char2& self, int other) -> int2
  {
    return self + other;
  }).
    define_method("+", [](const char2& self, float other) -> float2
  {
    return self + other;
  }).
    define_method("+", [](const char2& self, double other) -> double2
  {
    return self + other;
  }).
    define_method("-", [](const char2& self, int other) -> int2
  {
    return self - other;
  }).
    define_method("-", [](const char2& self, float other) -> float2
  {
    return self - other;
  }).
    define_method("-", [](const char2& self, double other) -> double2
  {
    return self - other;
  }).
    define_method("*", [](const char2& self, int other) -> int2
  {
    return self * other;
  }).
    define_method("*", [](const char2& self, float other) -> float2
  {
    return self * other;
  }).
    define_method("*", [](const char2& self, double other) -> double2
  {
    return self * other;
  }).
    define_method("/", [](const char2& self, int other) -> int2
  {
    return self / other;
  }).
    define_method("/", [](const char2& self, float other) -> float2
  {
    return self / other;
  }).
    define_method("/", [](const char2& self, double other) -> double2
  {
    return self / other;
  }).
    define_method("==", [](const char2& self, char other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const char2& self, char other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const char2& self, char other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const char2& self, char other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const char2& self, char other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const char2& self, char other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const char2& self, char other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const char2& self, char other) -> uchar2
  {
    return self || other;
  }).
    define_method("&", [](const char2& self, char other) -> char2
  {
    return self & other;
  }).
    define_method("|", [](const char2& self, char other) -> char2
  {
    return self | other;
  }).
    define_method("^", [](const char2& self, char other) -> char2
  {
    return self ^ other;
  });
  
  rb_cChar3.
    define_method("+", [](const char3& self, const char3& other) -> int3
  {
    return self + other;
  }).
    define_method("-", [](const char3& self, const char3& other) -> int3
  {
    return self - other;
  }).
    define_method("*", [](const char3& self, const char3& other) -> int3
  {
    return self * other;
  }).
    define_method("/", [](const char3& self, const char3& other) -> int3
  {
    return self / other;
  }).
    define_method("==", [](const char3& self, const char3& other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const char3& self, const char3& other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const char3& self, const char3& other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const char3& self, const char3& other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const char3& self, const char3& other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const char3& self, const char3& other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const char3& self, const char3& other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const char3& self, const char3& other) -> uchar3
  {
    return self || other;
  }).
    define_method("&", [](const char3& self, const char3& other) -> char3
  {
    return self & other;
  }).
    define_method("|", [](const char3& self, const char3& other) -> char3
  {
    return self | other;
  }).
    define_method("^", [](const char3& self, const char3& other) -> char3
  {
    return self ^ other;
  }).
    define_method("+", [](const char3& self, int other) -> int3
  {
    return self + other;
  }).
    define_method("+", [](const char3& self, float other) -> float3
  {
    return self + other;
  }).
    define_method("+", [](const char3& self, double other) -> double3
  {
    return self + other;
  }).
    define_method("-", [](const char3& self, int other) -> int3
  {
    return self - other;
  }).
    define_method("-", [](const char3& self, float other) -> float3
  {
    return self - other;
  }).
    define_method("-", [](const char3& self, double other) -> double3
  {
    return self - other;
  }).
    define_method("*", [](const char3& self, int other) -> int3
  {
    return self * other;
  }).
    define_method("*", [](const char3& self, float other) -> float3
  {
    return self * other;
  }).
    define_method("*", [](const char3& self, double other) -> double3
  {
    return self * other;
  }).
    define_method("/", [](const char3& self, int other) -> int3
  {
    return self / other;
  }).
    define_method("/", [](const char3& self, float other) -> float3
  {
    return self / other;
  }).
    define_method("/", [](const char3& self, double other) -> double3
  {
    return self / other;
  }).
    define_method("==", [](const char3& self, char other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const char3& self, char other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const char3& self, char other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const char3& self, char other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const char3& self, char other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const char3& self, char other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const char3& self, char other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const char3& self, char other) -> uchar3
  {
    return self || other;
  }).
    define_method("&", [](const char3& self, char other) -> char3
  {
    return self & other;
  }).
    define_method("|", [](const char3& self, char other) -> char3
  {
    return self | other;
  }).
    define_method("^", [](const char3& self, char other) -> char3
  {
    return self ^ other;
  });
  
  rb_cChar4.
    define_method("+", [](const char4& self, const char4& other) -> int4
  {
    return self + other;
  }).
    define_method("-", [](const char4& self, const char4& other) -> int4
  {
    return self - other;
  }).
    define_method("*", [](const char4& self, const char4& other) -> int4
  {
    return self * other;
  }).
    define_method("/", [](const char4& self, const char4& other) -> int4
  {
    return self / other;
  }).
    define_method("==", [](const char4& self, const char4& other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const char4& self, const char4& other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const char4& self, const char4& other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const char4& self, const char4& other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const char4& self, const char4& other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const char4& self, const char4& other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const char4& self, const char4& other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const char4& self, const char4& other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](const char4& self, const char4& other) -> char4
  {
    return self & other;
  }).
    define_method("|", [](const char4& self, const char4& other) -> char4
  {
    return self | other;
  }).
    define_method("^", [](const char4& self, const char4& other) -> char4
  {
    return self ^ other;
  }).
    define_method("+", [](const char4& self, int other) -> int4
  {
    return self + other;
  }).
    define_method("+", [](const char4& self, float other) -> float4
  {
    return self + other;
  }).
    define_method("+", [](const char4& self, double other) -> double4
  {
    return self + other;
  }).
    define_method("-", [](const char4& self, int other) -> int4
  {
    return self - other;
  }).
    define_method("-", [](const char4& self, float other) -> float4
  {
    return self - other;
  }).
    define_method("-", [](const char4& self, double other) -> double4
  {
    return self - other;
  }).
    define_method("*", [](const char4& self, int other) -> int4
  {
    return self * other;
  }).
    define_method("*", [](const char4& self, float other) -> float4
  {
    return self * other;
  }).
    define_method("*", [](const char4& self, double other) -> double4
  {
    return self * other;
  }).
    define_method("/", [](const char4& self, int other) -> int4
  {
    return self / other;
  }).
    define_method("/", [](const char4& self, float other) -> float4
  {
    return self / other;
  }).
    define_method("/", [](const char4& self, double other) -> double4
  {
    return self / other;
  }).
    define_method("==", [](const char4& self, char other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const char4& self, char other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const char4& self, char other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const char4& self, char other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const char4& self, char other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const char4& self, char other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const char4& self, char other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const char4& self, char other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](const char4& self, char other) -> char4
  {
    return self & other;
  }).
    define_method("|", [](const char4& self, char other) -> char4
  {
    return self | other;
  }).
    define_method("^", [](const char4& self, char other) -> char4
  {
    return self ^ other;
  });
  
  rb_cUshort1.
    define_method("+", [](const ushort1& self, const ushort1& other) -> int1
  {
    return self + other;
  }).
    define_method("-", [](const ushort1& self, const ushort1& other) -> int1
  {
    return self - other;
  }).
    define_method("*", [](const ushort1& self, const ushort1& other) -> int1
  {
    return self * other;
  }).
    define_method("/", [](const ushort1& self, const ushort1& other) -> int1
  {
    return self / other;
  }).
    define_method("==", [](const ushort1& self, const ushort1& other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const ushort1& self, const ushort1& other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const ushort1& self, const ushort1& other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const ushort1& self, const ushort1& other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const ushort1& self, const ushort1& other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const ushort1& self, const ushort1& other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const ushort1& self, const ushort1& other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const ushort1& self, const ushort1& other) -> uchar1
  {
    return self || other;
  }).
    define_method("&", [](const ushort1& self, const ushort1& other) -> ushort1
  {
    return self & other;
  }).
    define_method("|", [](const ushort1& self, const ushort1& other) -> ushort1
  {
    return self | other;
  }).
    define_method("^", [](const ushort1& self, const ushort1& other) -> ushort1
  {
    return self ^ other;
  }).
    define_method("+", [](const ushort1& self, int other) -> int1
  {
    return self + other;
  }).
    define_method("+", [](const ushort1& self, float other) -> float1
  {
    return self + other;
  }).
    define_method("+", [](const ushort1& self, double other) -> double1
  {
    return self + other;
  }).
    define_method("-", [](const ushort1& self, int other) -> int1
  {
    return self - other;
  }).
    define_method("-", [](const ushort1& self, float other) -> float1
  {
    return self - other;
  }).
    define_method("-", [](const ushort1& self, double other) -> double1
  {
    return self - other;
  }).
    define_method("*", [](const ushort1& self, int other) -> int1
  {
    return self * other;
  }).
    define_method("*", [](const ushort1& self, float other) -> float1
  {
    return self * other;
  }).
    define_method("*", [](const ushort1& self, double other) -> double1
  {
    return self * other;
  }).
    define_method("/", [](const ushort1& self, int other) -> int1
  {
    return self / other;
  }).
    define_method("/", [](const ushort1& self, float other) -> float1
  {
    return self / other;
  }).
    define_method("/", [](const ushort1& self, double other) -> double1
  {
    return self / other;
  }).
    define_method("==", [](const ushort1& self, ushort other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const ushort1& self, ushort other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const ushort1& self, ushort other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const ushort1& self, ushort other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const ushort1& self, ushort other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const ushort1& self, ushort other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const ushort1& self, ushort other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const ushort1& self, ushort other) -> uchar1
  {
    return self || other;
  }).
    define_method("&", [](const ushort1& self, ushort other) -> ushort1
  {
    return self & other;
  }).
    define_method("|", [](const ushort1& self, ushort other) -> ushort1
  {
    return self | other;
  }).
    define_method("^", [](const ushort1& self, ushort other) -> ushort1
  {
    return self ^ other;
  });
  
  rb_cUshort2.
    define_method("+", [](const ushort2& self, const ushort2& other) -> int2
  {
    return self + other;
  }).
    define_method("-", [](const ushort2& self, const ushort2& other) -> int2
  {
    return self - other;
  }).
    define_method("*", [](const ushort2& self, const ushort2& other) -> int2
  {
    return self * other;
  }).
    define_method("/", [](const ushort2& self, const ushort2& other) -> int2
  {
    return self / other;
  }).
    define_method("==", [](const ushort2& self, const ushort2& other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const ushort2& self, const ushort2& other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const ushort2& self, const ushort2& other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const ushort2& self, const ushort2& other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const ushort2& self, const ushort2& other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const ushort2& self, const ushort2& other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const ushort2& self, const ushort2& other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const ushort2& self, const ushort2& other) -> uchar2
  {
    return self || other;
  }).
    define_method("&", [](const ushort2& self, const ushort2& other) -> ushort2
  {
    return self & other;
  }).
    define_method("|", [](const ushort2& self, const ushort2& other) -> ushort2
  {
    return self | other;
  }).
    define_method("^", [](const ushort2& self, const ushort2& other) -> ushort2
  {
    return self ^ other;
  }).
    define_method("+", [](const ushort2& self, int other) -> int2
  {
    return self + other;
  }).
    define_method("+", [](const ushort2& self, float other) -> float2
  {
    return self + other;
  }).
    define_method("+", [](const ushort2& self, double other) -> double2
  {
    return self + other;
  }).
    define_method("-", [](const ushort2& self, int other) -> int2
  {
    return self - other;
  }).
    define_method("-", [](const ushort2& self, float other) -> float2
  {
    return self - other;
  }).
    define_method("-", [](const ushort2& self, double other) -> double2
  {
    return self - other;
  }).
    define_method("*", [](const ushort2& self, int other) -> int2
  {
    return self * other;
  }).
    define_method("*", [](const ushort2& self, float other) -> float2
  {
    return self * other;
  }).
    define_method("*", [](const ushort2& self, double other) -> double2
  {
    return self * other;
  }).
    define_method("/", [](const ushort2& self, int other) -> int2
  {
    return self / other;
  }).
    define_method("/", [](const ushort2& self, float other) -> float2
  {
    return self / other;
  }).
    define_method("/", [](const ushort2& self, double other) -> double2
  {
    return self / other;
  }).
    define_method("==", [](const ushort2& self, ushort other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const ushort2& self, ushort other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const ushort2& self, ushort other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const ushort2& self, ushort other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const ushort2& self, ushort other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const ushort2& self, ushort other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const ushort2& self, ushort other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const ushort2& self, ushort other) -> uchar2
  {
    return self || other;
  }).
    define_method("&", [](const ushort2& self, ushort other) -> ushort2
  {
    return self & other;
  }).
    define_method("|", [](const ushort2& self, ushort other) -> ushort2
  {
    return self | other;
  }).
    define_method("^", [](const ushort2& self, ushort other) -> ushort2
  {
    return self ^ other;
  });
  
  rb_cUshort3.
    define_method("+", [](const ushort3& self, const ushort3& other) -> int3
  {
    return self + other;
  }).
    define_method("-", [](const ushort3& self, const ushort3& other) -> int3
  {
    return self - other;
  }).
    define_method("*", [](const ushort3& self, const ushort3& other) -> int3
  {
    return self * other;
  }).
    define_method("/", [](const ushort3& self, const ushort3& other) -> int3
  {
    return self / other;
  }).
    define_method("==", [](const ushort3& self, const ushort3& other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const ushort3& self, const ushort3& other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const ushort3& self, const ushort3& other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const ushort3& self, const ushort3& other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const ushort3& self, const ushort3& other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const ushort3& self, const ushort3& other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const ushort3& self, const ushort3& other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const ushort3& self, const ushort3& other) -> uchar3
  {
    return self || other;
  }).
    define_method("&", [](const ushort3& self, const ushort3& other) -> ushort3
  {
    return self & other;
  }).
    define_method("|", [](const ushort3& self, const ushort3& other) -> ushort3
  {
    return self | other;
  }).
    define_method("^", [](const ushort3& self, const ushort3& other) -> ushort3
  {
    return self ^ other;
  }).
    define_method("+", [](const ushort3& self, int other) -> int3
  {
    return self + other;
  }).
    define_method("+", [](const ushort3& self, float other) -> float3
  {
    return self + other;
  }).
    define_method("+", [](const ushort3& self, double other) -> double3
  {
    return self + other;
  }).
    define_method("-", [](const ushort3& self, int other) -> int3
  {
    return self - other;
  }).
    define_method("-", [](const ushort3& self, float other) -> float3
  {
    return self - other;
  }).
    define_method("-", [](const ushort3& self, double other) -> double3
  {
    return self - other;
  }).
    define_method("*", [](const ushort3& self, int other) -> int3
  {
    return self * other;
  }).
    define_method("*", [](const ushort3& self, float other) -> float3
  {
    return self * other;
  }).
    define_method("*", [](const ushort3& self, double other) -> double3
  {
    return self * other;
  }).
    define_method("/", [](const ushort3& self, int other) -> int3
  {
    return self / other;
  }).
    define_method("/", [](const ushort3& self, float other) -> float3
  {
    return self / other;
  }).
    define_method("/", [](const ushort3& self, double other) -> double3
  {
    return self / other;
  }).
    define_method("==", [](const ushort3& self, ushort other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const ushort3& self, ushort other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const ushort3& self, ushort other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const ushort3& self, ushort other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const ushort3& self, ushort other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const ushort3& self, ushort other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const ushort3& self, ushort other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const ushort3& self, ushort other) -> uchar3
  {
    return self || other;
  }).
    define_method("&", [](const ushort3& self, ushort other) -> ushort3
  {
    return self & other;
  }).
    define_method("|", [](const ushort3& self, ushort other) -> ushort3
  {
    return self | other;
  }).
    define_method("^", [](const ushort3& self, ushort other) -> ushort3
  {
    return self ^ other;
  });
  
  rb_cUshort4.
    define_method("+", [](const ushort4& self, const ushort4& other) -> int4
  {
    return self + other;
  }).
    define_method("-", [](const ushort4& self, const ushort4& other) -> int4
  {
    return self - other;
  }).
    define_method("*", [](const ushort4& self, const ushort4& other) -> int4
  {
    return self * other;
  }).
    define_method("/", [](const ushort4& self, const ushort4& other) -> int4
  {
    return self / other;
  }).
    define_method("==", [](const ushort4& self, const ushort4& other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const ushort4& self, const ushort4& other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const ushort4& self, const ushort4& other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const ushort4& self, const ushort4& other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const ushort4& self, const ushort4& other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const ushort4& self, const ushort4& other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const ushort4& self, const ushort4& other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const ushort4& self, const ushort4& other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](const ushort4& self, const ushort4& other) -> ushort4
  {
    return self & other;
  }).
    define_method("|", [](const ushort4& self, const ushort4& other) -> ushort4
  {
    return self | other;
  }).
    define_method("^", [](const ushort4& self, const ushort4& other) -> ushort4
  {
    return self ^ other;
  }).
    define_method("+", [](const ushort4& self, int other) -> int4
  {
    return self + other;
  }).
    define_method("+", [](const ushort4& self, float other) -> float4
  {
    return self + other;
  }).
    define_method("+", [](const ushort4& self, double other) -> double4
  {
    return self + other;
  }).
    define_method("-", [](const ushort4& self, int other) -> int4
  {
    return self - other;
  }).
    define_method("-", [](const ushort4& self, float other) -> float4
  {
    return self - other;
  }).
    define_method("-", [](const ushort4& self, double other) -> double4
  {
    return self - other;
  }).
    define_method("*", [](const ushort4& self, int other) -> int4
  {
    return self * other;
  }).
    define_method("*", [](const ushort4& self, float other) -> float4
  {
    return self * other;
  }).
    define_method("*", [](const ushort4& self, double other) -> double4
  {
    return self * other;
  }).
    define_method("/", [](const ushort4& self, int other) -> int4
  {
    return self / other;
  }).
    define_method("/", [](const ushort4& self, float other) -> float4
  {
    return self / other;
  }).
    define_method("/", [](const ushort4& self, double other) -> double4
  {
    return self / other;
  }).
    define_method("==", [](const ushort4& self, ushort other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const ushort4& self, ushort other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const ushort4& self, ushort other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const ushort4& self, ushort other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const ushort4& self, ushort other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const ushort4& self, ushort other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const ushort4& self, ushort other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const ushort4& self, ushort other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](const ushort4& self, ushort other) -> ushort4
  {
    return self & other;
  }).
    define_method("|", [](const ushort4& self, ushort other) -> ushort4
  {
    return self | other;
  }).
    define_method("^", [](const ushort4& self, ushort other) -> ushort4
  {
    return self ^ other;
  });
  
  rb_cShort1.
    define_method("+", [](const short1& self, const short1& other) -> int1
  {
    return self + other;
  }).
    define_method("-", [](const short1& self, const short1& other) -> int1
  {
    return self - other;
  }).
    define_method("*", [](const short1& self, const short1& other) -> int1
  {
    return self * other;
  }).
    define_method("/", [](const short1& self, const short1& other) -> int1
  {
    return self / other;
  }).
    define_method("==", [](const short1& self, const short1& other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const short1& self, const short1& other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const short1& self, const short1& other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const short1& self, const short1& other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const short1& self, const short1& other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const short1& self, const short1& other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const short1& self, const short1& other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const short1& self, const short1& other) -> uchar1
  {
    return self || other;
  }).
    define_method("&", [](const short1& self, const short1& other) -> short1
  {
    return self & other;
  }).
    define_method("|", [](const short1& self, const short1& other) -> short1
  {
    return self | other;
  }).
    define_method("^", [](const short1& self, const short1& other) -> short1
  {
    return self ^ other;
  }).
    define_method("+", [](const short1& self, int other) -> int1
  {
    return self + other;
  }).
    define_method("+", [](const short1& self, float other) -> float1
  {
    return self + other;
  }).
    define_method("+", [](const short1& self, double other) -> double1
  {
    return self + other;
  }).
    define_method("-", [](const short1& self, int other) -> int1
  {
    return self - other;
  }).
    define_method("-", [](const short1& self, float other) -> float1
  {
    return self - other;
  }).
    define_method("-", [](const short1& self, double other) -> double1
  {
    return self - other;
  }).
    define_method("*", [](const short1& self, int other) -> int1
  {
    return self * other;
  }).
    define_method("*", [](const short1& self, float other) -> float1
  {
    return self * other;
  }).
    define_method("*", [](const short1& self, double other) -> double1
  {
    return self * other;
  }).
    define_method("/", [](const short1& self, int other) -> int1
  {
    return self / other;
  }).
    define_method("/", [](const short1& self, float other) -> float1
  {
    return self / other;
  }).
    define_method("/", [](const short1& self, double other) -> double1
  {
    return self / other;
  }).
    define_method("==", [](const short1& self, short other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const short1& self, short other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const short1& self, short other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const short1& self, short other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const short1& self, short other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const short1& self, short other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const short1& self, short other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const short1& self, short other) -> uchar1
  {
    return self || other;
  }).
    define_method("&", [](const short1& self, short other) -> short1
  {
    return self & other;
  }).
    define_method("|", [](const short1& self, short other) -> short1
  {
    return self | other;
  }).
    define_method("^", [](const short1& self, short other) -> short1
  {
    return self ^ other;
  });
  
  rb_cShort2.
    define_method("+", [](const short2& self, const short2& other) -> int2
  {
    return self + other;
  }).
    define_method("-", [](const short2& self, const short2& other) -> int2
  {
    return self - other;
  }).
    define_method("*", [](const short2& self, const short2& other) -> int2
  {
    return self * other;
  }).
    define_method("/", [](const short2& self, const short2& other) -> int2
  {
    return self / other;
  }).
    define_method("==", [](const short2& self, const short2& other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const short2& self, const short2& other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const short2& self, const short2& other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const short2& self, const short2& other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const short2& self, const short2& other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const short2& self, const short2& other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const short2& self, const short2& other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const short2& self, const short2& other) -> uchar2
  {
    return self || other;
  }).
    define_method("&", [](const short2& self, const short2& other) -> short2
  {
    return self & other;
  }).
    define_method("|", [](const short2& self, const short2& other) -> short2
  {
    return self | other;
  }).
    define_method("^", [](const short2& self, const short2& other) -> short2
  {
    return self ^ other;
  }).
    define_method("+", [](const short2& self, int other) -> int2
  {
    return self + other;
  }).
    define_method("+", [](const short2& self, float other) -> float2
  {
    return self + other;
  }).
    define_method("+", [](const short2& self, double other) -> double2
  {
    return self + other;
  }).
    define_method("-", [](const short2& self, int other) -> int2
  {
    return self - other;
  }).
    define_method("-", [](const short2& self, float other) -> float2
  {
    return self - other;
  }).
    define_method("-", [](const short2& self, double other) -> double2
  {
    return self - other;
  }).
    define_method("*", [](const short2& self, int other) -> int2
  {
    return self * other;
  }).
    define_method("*", [](const short2& self, float other) -> float2
  {
    return self * other;
  }).
    define_method("*", [](const short2& self, double other) -> double2
  {
    return self * other;
  }).
    define_method("/", [](const short2& self, int other) -> int2
  {
    return self / other;
  }).
    define_method("/", [](const short2& self, float other) -> float2
  {
    return self / other;
  }).
    define_method("/", [](const short2& self, double other) -> double2
  {
    return self / other;
  }).
    define_method("==", [](const short2& self, short other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const short2& self, short other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const short2& self, short other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const short2& self, short other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const short2& self, short other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const short2& self, short other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const short2& self, short other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const short2& self, short other) -> uchar2
  {
    return self || other;
  }).
    define_method("&", [](const short2& self, short other) -> short2
  {
    return self & other;
  }).
    define_method("|", [](const short2& self, short other) -> short2
  {
    return self | other;
  }).
    define_method("^", [](const short2& self, short other) -> short2
  {
    return self ^ other;
  });
  
  rb_cShort3.
    define_method("+", [](const short3& self, const short3& other) -> int3
  {
    return self + other;
  }).
    define_method("-", [](const short3& self, const short3& other) -> int3
  {
    return self - other;
  }).
    define_method("*", [](const short3& self, const short3& other) -> int3
  {
    return self * other;
  }).
    define_method("/", [](const short3& self, const short3& other) -> int3
  {
    return self / other;
  }).
    define_method("==", [](const short3& self, const short3& other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const short3& self, const short3& other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const short3& self, const short3& other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const short3& self, const short3& other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const short3& self, const short3& other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const short3& self, const short3& other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const short3& self, const short3& other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const short3& self, const short3& other) -> uchar3
  {
    return self || other;
  }).
    define_method("&", [](const short3& self, const short3& other) -> short3
  {
    return self & other;
  }).
    define_method("|", [](const short3& self, const short3& other) -> short3
  {
    return self | other;
  }).
    define_method("^", [](const short3& self, const short3& other) -> short3
  {
    return self ^ other;
  }).
    define_method("+", [](const short3& self, int other) -> int3
  {
    return self + other;
  }).
    define_method("+", [](const short3& self, float other) -> float3
  {
    return self + other;
  }).
    define_method("+", [](const short3& self, double other) -> double3
  {
    return self + other;
  }).
    define_method("-", [](const short3& self, int other) -> int3
  {
    return self - other;
  }).
    define_method("-", [](const short3& self, float other) -> float3
  {
    return self - other;
  }).
    define_method("-", [](const short3& self, double other) -> double3
  {
    return self - other;
  }).
    define_method("*", [](const short3& self, int other) -> int3
  {
    return self * other;
  }).
    define_method("*", [](const short3& self, float other) -> float3
  {
    return self * other;
  }).
    define_method("*", [](const short3& self, double other) -> double3
  {
    return self * other;
  }).
    define_method("/", [](const short3& self, int other) -> int3
  {
    return self / other;
  }).
    define_method("/", [](const short3& self, float other) -> float3
  {
    return self / other;
  }).
    define_method("/", [](const short3& self, double other) -> double3
  {
    return self / other;
  }).
    define_method("==", [](const short3& self, short other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const short3& self, short other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const short3& self, short other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const short3& self, short other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const short3& self, short other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const short3& self, short other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const short3& self, short other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const short3& self, short other) -> uchar3
  {
    return self || other;
  }).
    define_method("&", [](const short3& self, short other) -> short3
  {
    return self & other;
  }).
    define_method("|", [](const short3& self, short other) -> short3
  {
    return self | other;
  }).
    define_method("^", [](const short3& self, short other) -> short3
  {
    return self ^ other;
  });
  
  rb_cShort4.
    define_method("+", [](const short4& self, const short4& other) -> int4
  {
    return self + other;
  }).
    define_method("-", [](const short4& self, const short4& other) -> int4
  {
    return self - other;
  }).
    define_method("*", [](const short4& self, const short4& other) -> int4
  {
    return self * other;
  }).
    define_method("/", [](const short4& self, const short4& other) -> int4
  {
    return self / other;
  }).
    define_method("==", [](const short4& self, const short4& other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const short4& self, const short4& other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const short4& self, const short4& other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const short4& self, const short4& other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const short4& self, const short4& other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const short4& self, const short4& other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const short4& self, const short4& other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const short4& self, const short4& other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](const short4& self, const short4& other) -> short4
  {
    return self & other;
  }).
    define_method("|", [](const short4& self, const short4& other) -> short4
  {
    return self | other;
  }).
    define_method("^", [](const short4& self, const short4& other) -> short4
  {
    return self ^ other;
  }).
    define_method("+", [](const short4& self, int other) -> int4
  {
    return self + other;
  }).
    define_method("+", [](const short4& self, float other) -> float4
  {
    return self + other;
  }).
    define_method("+", [](const short4& self, double other) -> double4
  {
    return self + other;
  }).
    define_method("-", [](const short4& self, int other) -> int4
  {
    return self - other;
  }).
    define_method("-", [](const short4& self, float other) -> float4
  {
    return self - other;
  }).
    define_method("-", [](const short4& self, double other) -> double4
  {
    return self - other;
  }).
    define_method("*", [](const short4& self, int other) -> int4
  {
    return self * other;
  }).
    define_method("*", [](const short4& self, float other) -> float4
  {
    return self * other;
  }).
    define_method("*", [](const short4& self, double other) -> double4
  {
    return self * other;
  }).
    define_method("/", [](const short4& self, int other) -> int4
  {
    return self / other;
  }).
    define_method("/", [](const short4& self, float other) -> float4
  {
    return self / other;
  }).
    define_method("/", [](const short4& self, double other) -> double4
  {
    return self / other;
  }).
    define_method("==", [](const short4& self, short other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const short4& self, short other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const short4& self, short other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const short4& self, short other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const short4& self, short other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const short4& self, short other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const short4& self, short other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const short4& self, short other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](const short4& self, short other) -> short4
  {
    return self & other;
  }).
    define_method("|", [](const short4& self, short other) -> short4
  {
    return self | other;
  }).
    define_method("^", [](const short4& self, short other) -> short4
  {
    return self ^ other;
  });
  
  rb_cInt1.
    define_method("+", [](const int1& self, const int1& other) -> int1
  {
    return self + other;
  }).
    define_method("-", [](const int1& self, const int1& other) -> int1
  {
    return self - other;
  }).
    define_method("*", [](const int1& self, const int1& other) -> int1
  {
    return self * other;
  }).
    define_method("/", [](const int1& self, const int1& other) -> int1
  {
    return self / other;
  }).
    define_method("==", [](const int1& self, const int1& other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const int1& self, const int1& other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const int1& self, const int1& other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const int1& self, const int1& other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const int1& self, const int1& other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const int1& self, const int1& other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const int1& self, const int1& other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const int1& self, const int1& other) -> uchar1
  {
    return self || other;
  }).
    define_method("&", [](const int1& self, const int1& other) -> int1
  {
    return self & other;
  }).
    define_method("|", [](const int1& self, const int1& other) -> int1
  {
    return self | other;
  }).
    define_method("^", [](const int1& self, const int1& other) -> int1
  {
    return self ^ other;
  }).
    define_method("+", [](const int1& self, int other) -> int1
  {
    return self + other;
  }).
    define_method("+", [](const int1& self, float other) -> float1
  {
    return self + other;
  }).
    define_method("+", [](const int1& self, double other) -> double1
  {
    return self + other;
  }).
    define_method("-", [](const int1& self, int other) -> int1
  {
    return self - other;
  }).
    define_method("-", [](const int1& self, float other) -> float1
  {
    return self - other;
  }).
    define_method("-", [](const int1& self, double other) -> double1
  {
    return self - other;
  }).
    define_method("*", [](const int1& self, int other) -> int1
  {
    return self * other;
  }).
    define_method("*", [](const int1& self, float other) -> float1
  {
    return self * other;
  }).
    define_method("*", [](const int1& self, double other) -> double1
  {
    return self * other;
  }).
    define_method("/", [](const int1& self, int other) -> int1
  {
    return self / other;
  }).
    define_method("/", [](const int1& self, float other) -> float1
  {
    return self / other;
  }).
    define_method("/", [](const int1& self, double other) -> double1
  {
    return self / other;
  }).
    define_method("==", [](const int1& self, int other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const int1& self, int other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const int1& self, int other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const int1& self, int other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const int1& self, int other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const int1& self, int other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const int1& self, int other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const int1& self, int other) -> uchar1
  {
    return self || other;
  }).
    define_method("&", [](const int1& self, int other) -> int1
  {
    return self & other;
  }).
    define_method("|", [](const int1& self, int other) -> int1
  {
    return self | other;
  }).
    define_method("^", [](const int1& self, int other) -> int1
  {
    return self ^ other;
  });
  
  rb_cInt2.
    define_method("+", [](const int2& self, const int2& other) -> int2
  {
    return self + other;
  }).
    define_method("-", [](const int2& self, const int2& other) -> int2
  {
    return self - other;
  }).
    define_method("*", [](const int2& self, const int2& other) -> int2
  {
    return self * other;
  }).
    define_method("/", [](const int2& self, const int2& other) -> int2
  {
    return self / other;
  }).
    define_method("==", [](const int2& self, const int2& other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const int2& self, const int2& other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const int2& self, const int2& other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const int2& self, const int2& other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const int2& self, const int2& other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const int2& self, const int2& other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const int2& self, const int2& other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const int2& self, const int2& other) -> uchar2
  {
    return self || other;
  }).
    define_method("&", [](const int2& self, const int2& other) -> int2
  {
    return self & other;
  }).
    define_method("|", [](const int2& self, const int2& other) -> int2
  {
    return self | other;
  }).
    define_method("^", [](const int2& self, const int2& other) -> int2
  {
    return self ^ other;
  }).
    define_method("+", [](const int2& self, int other) -> int2
  {
    return self + other;
  }).
    define_method("+", [](const int2& self, float other) -> float2
  {
    return self + other;
  }).
    define_method("+", [](const int2& self, double other) -> double2
  {
    return self + other;
  }).
    define_method("-", [](const int2& self, int other) -> int2
  {
    return self - other;
  }).
    define_method("-", [](const int2& self, float other) -> float2
  {
    return self - other;
  }).
    define_method("-", [](const int2& self, double other) -> double2
  {
    return self - other;
  }).
    define_method("*", [](const int2& self, int other) -> int2
  {
    return self * other;
  }).
    define_method("*", [](const int2& self, float other) -> float2
  {
    return self * other;
  }).
    define_method("*", [](const int2& self, double other) -> double2
  {
    return self * other;
  }).
    define_method("/", [](const int2& self, int other) -> int2
  {
    return self / other;
  }).
    define_method("/", [](const int2& self, float other) -> float2
  {
    return self / other;
  }).
    define_method("/", [](const int2& self, double other) -> double2
  {
    return self / other;
  }).
    define_method("==", [](const int2& self, int other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const int2& self, int other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const int2& self, int other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const int2& self, int other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const int2& self, int other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const int2& self, int other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const int2& self, int other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const int2& self, int other) -> uchar2
  {
    return self || other;
  }).
    define_method("&", [](const int2& self, int other) -> int2
  {
    return self & other;
  }).
    define_method("|", [](const int2& self, int other) -> int2
  {
    return self | other;
  }).
    define_method("^", [](const int2& self, int other) -> int2
  {
    return self ^ other;
  });
  
  rb_cInt3.
    define_method("+", [](const int3& self, const int3& other) -> int3
  {
    return self + other;
  }).
    define_method("-", [](const int3& self, const int3& other) -> int3
  {
    return self - other;
  }).
    define_method("*", [](const int3& self, const int3& other) -> int3
  {
    return self * other;
  }).
    define_method("/", [](const int3& self, const int3& other) -> int3
  {
    return self / other;
  }).
    define_method("==", [](const int3& self, const int3& other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const int3& self, const int3& other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const int3& self, const int3& other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const int3& self, const int3& other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const int3& self, const int3& other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const int3& self, const int3& other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const int3& self, const int3& other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const int3& self, const int3& other) -> uchar3
  {
    return self || other;
  }).
    define_method("&", [](const int3& self, const int3& other) -> int3
  {
    return self & other;
  }).
    define_method("|", [](const int3& self, const int3& other) -> int3
  {
    return self | other;
  }).
    define_method("^", [](const int3& self, const int3& other) -> int3
  {
    return self ^ other;
  }).
    define_method("+", [](const int3& self, int other) -> int3
  {
    return self + other;
  }).
    define_method("+", [](const int3& self, float other) -> float3
  {
    return self + other;
  }).
    define_method("+", [](const int3& self, double other) -> double3
  {
    return self + other;
  }).
    define_method("-", [](const int3& self, int other) -> int3
  {
    return self - other;
  }).
    define_method("-", [](const int3& self, float other) -> float3
  {
    return self - other;
  }).
    define_method("-", [](const int3& self, double other) -> double3
  {
    return self - other;
  }).
    define_method("*", [](const int3& self, int other) -> int3
  {
    return self * other;
  }).
    define_method("*", [](const int3& self, float other) -> float3
  {
    return self * other;
  }).
    define_method("*", [](const int3& self, double other) -> double3
  {
    return self * other;
  }).
    define_method("/", [](const int3& self, int other) -> int3
  {
    return self / other;
  }).
    define_method("/", [](const int3& self, float other) -> float3
  {
    return self / other;
  }).
    define_method("/", [](const int3& self, double other) -> double3
  {
    return self / other;
  }).
    define_method("==", [](const int3& self, int other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const int3& self, int other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const int3& self, int other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const int3& self, int other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const int3& self, int other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const int3& self, int other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const int3& self, int other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const int3& self, int other) -> uchar3
  {
    return self || other;
  }).
    define_method("&", [](const int3& self, int other) -> int3
  {
    return self & other;
  }).
    define_method("|", [](const int3& self, int other) -> int3
  {
    return self | other;
  }).
    define_method("^", [](const int3& self, int other) -> int3
  {
    return self ^ other;
  });
  
  rb_cInt4.
    define_method("+", [](const int4& self, const int4& other) -> int4
  {
    return self + other;
  }).
    define_method("-", [](const int4& self, const int4& other) -> int4
  {
    return self - other;
  }).
    define_method("*", [](const int4& self, const int4& other) -> int4
  {
    return self * other;
  }).
    define_method("/", [](const int4& self, const int4& other) -> int4
  {
    return self / other;
  }).
    define_method("==", [](const int4& self, const int4& other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const int4& self, const int4& other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const int4& self, const int4& other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const int4& self, const int4& other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const int4& self, const int4& other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const int4& self, const int4& other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const int4& self, const int4& other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const int4& self, const int4& other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](const int4& self, const int4& other) -> int4
  {
    return self & other;
  }).
    define_method("|", [](const int4& self, const int4& other) -> int4
  {
    return self | other;
  }).
    define_method("^", [](const int4& self, const int4& other) -> int4
  {
    return self ^ other;
  }).
    define_method("+", [](const int4& self, int other) -> int4
  {
    return self + other;
  }).
    define_method("+", [](const int4& self, float other) -> float4
  {
    return self + other;
  }).
    define_method("+", [](const int4& self, double other) -> double4
  {
    return self + other;
  }).
    define_method("-", [](const int4& self, int other) -> int4
  {
    return self - other;
  }).
    define_method("-", [](const int4& self, float other) -> float4
  {
    return self - other;
  }).
    define_method("-", [](const int4& self, double other) -> double4
  {
    return self - other;
  }).
    define_method("*", [](const int4& self, int other) -> int4
  {
    return self * other;
  }).
    define_method("*", [](const int4& self, float other) -> float4
  {
    return self * other;
  }).
    define_method("*", [](const int4& self, double other) -> double4
  {
    return self * other;
  }).
    define_method("/", [](const int4& self, int other) -> int4
  {
    return self / other;
  }).
    define_method("/", [](const int4& self, float other) -> float4
  {
    return self / other;
  }).
    define_method("/", [](const int4& self, double other) -> double4
  {
    return self / other;
  }).
    define_method("==", [](const int4& self, int other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const int4& self, int other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const int4& self, int other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const int4& self, int other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const int4& self, int other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const int4& self, int other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const int4& self, int other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const int4& self, int other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](const int4& self, int other) -> int4
  {
    return self & other;
  }).
    define_method("|", [](const int4& self, int other) -> int4
  {
    return self | other;
  }).
    define_method("^", [](const int4& self, int other) -> int4
  {
    return self ^ other;
  });
  
  rb_cUint1.
    define_method("+", [](const uint1& self, const uint1& other) -> uint1
  {
    return self + other;
  }).
    define_method("-", [](const uint1& self, const uint1& other) -> uint1
  {
    return self - other;
  }).
    define_method("*", [](const uint1& self, const uint1& other) -> uint1
  {
    return self * other;
  }).
    define_method("/", [](const uint1& self, const uint1& other) -> uint1
  {
    return self / other;
  }).
    define_method("==", [](const uint1& self, const uint1& other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const uint1& self, const uint1& other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const uint1& self, const uint1& other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const uint1& self, const uint1& other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const uint1& self, const uint1& other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const uint1& self, const uint1& other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uint1& self, const uint1& other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const uint1& self, const uint1& other) -> uchar1
  {
    return self || other;
  }).
    define_method("&", [](const uint1& self, const uint1& other) -> uint1
  {
    return self & other;
  }).
    define_method("|", [](const uint1& self, const uint1& other) -> uint1
  {
    return self | other;
  }).
    define_method("^", [](const uint1& self, const uint1& other) -> uint1
  {
    return self ^ other;
  }).
    define_method("+", [](const uint1& self, uint other) -> uint1
  {
    return self + other;
  }).
    define_method("+", [](const uint1& self, float other) -> float1
  {
    return self + other;
  }).
    define_method("+", [](const uint1& self, double other) -> double1
  {
    return self + other;
  }).
    define_method("-", [](const uint1& self, uint other) -> uint1
  {
    return self - other;
  }).
    define_method("-", [](const uint1& self, float other) -> float1
  {
    return self - other;
  }).
    define_method("-", [](const uint1& self, double other) -> double1
  {
    return self - other;
  }).
    define_method("*", [](const uint1& self, uint other) -> uint1
  {
    return self * other;
  }).
    define_method("*", [](const uint1& self, float other) -> float1
  {
    return self * other;
  }).
    define_method("*", [](const uint1& self, double other) -> double1
  {
    return self * other;
  }).
    define_method("/", [](const uint1& self, uint other) -> uint1
  {
    return self / other;
  }).
    define_method("/", [](const uint1& self, float other) -> float1
  {
    return self / other;
  }).
    define_method("/", [](const uint1& self, double other) -> double1
  {
    return self / other;
  }).
    define_method("==", [](const uint1& self, uint other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const uint1& self, uint other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const uint1& self, uint other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const uint1& self, uint other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const uint1& self, uint other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const uint1& self, uint other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uint1& self, uint other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const uint1& self, uint other) -> uchar1
  {
    return self || other;
  }).
    define_method("&", [](const uint1& self, uint other) -> uint1
  {
    return self & other;
  }).
    define_method("|", [](const uint1& self, uint other) -> uint1
  {
    return self | other;
  }).
    define_method("^", [](const uint1& self, uint other) -> uint1
  {
    return self ^ other;
  });
  
  rb_cUint2.
    define_method("+", [](const uint2& self, const uint2& other) -> uint2
  {
    return self + other;
  }).
    define_method("-", [](const uint2& self, const uint2& other) -> uint2
  {
    return self - other;
  }).
    define_method("*", [](const uint2& self, const uint2& other) -> uint2
  {
    return self * other;
  }).
    define_method("/", [](const uint2& self, const uint2& other) -> uint2
  {
    return self / other;
  }).
    define_method("==", [](const uint2& self, const uint2& other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const uint2& self, const uint2& other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const uint2& self, const uint2& other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const uint2& self, const uint2& other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const uint2& self, const uint2& other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const uint2& self, const uint2& other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uint2& self, const uint2& other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const uint2& self, const uint2& other) -> uchar2
  {
    return self || other;
  }).
    define_method("&", [](const uint2& self, const uint2& other) -> uint2
  {
    return self & other;
  }).
    define_method("|", [](const uint2& self, const uint2& other) -> uint2
  {
    return self | other;
  }).
    define_method("^", [](const uint2& self, const uint2& other) -> uint2
  {
    return self ^ other;
  }).
    define_method("+", [](const uint2& self, uint other) -> uint2
  {
    return self + other;
  }).
    define_method("+", [](const uint2& self, float other) -> float2
  {
    return self + other;
  }).
    define_method("+", [](const uint2& self, double other) -> double2
  {
    return self + other;
  }).
    define_method("-", [](const uint2& self, uint other) -> uint2
  {
    return self - other;
  }).
    define_method("-", [](const uint2& self, float other) -> float2
  {
    return self - other;
  }).
    define_method("-", [](const uint2& self, double other) -> double2
  {
    return self - other;
  }).
    define_method("*", [](const uint2& self, uint other) -> uint2
  {
    return self * other;
  }).
    define_method("*", [](const uint2& self, float other) -> float2
  {
    return self * other;
  }).
    define_method("*", [](const uint2& self, double other) -> double2
  {
    return self * other;
  }).
    define_method("/", [](const uint2& self, uint other) -> uint2
  {
    return self / other;
  }).
    define_method("/", [](const uint2& self, float other) -> float2
  {
    return self / other;
  }).
    define_method("/", [](const uint2& self, double other) -> double2
  {
    return self / other;
  }).
    define_method("==", [](const uint2& self, uint other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const uint2& self, uint other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const uint2& self, uint other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const uint2& self, uint other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const uint2& self, uint other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const uint2& self, uint other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uint2& self, uint other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const uint2& self, uint other) -> uchar2
  {
    return self || other;
  }).
    define_method("&", [](const uint2& self, uint other) -> uint2
  {
    return self & other;
  }).
    define_method("|", [](const uint2& self, uint other) -> uint2
  {
    return self | other;
  }).
    define_method("^", [](const uint2& self, uint other) -> uint2
  {
    return self ^ other;
  });
  
  rb_cUint3.
    define_method("+", [](const uint3& self, const uint3& other) -> uint3
  {
    return self + other;
  }).
    define_method("-", [](const uint3& self, const uint3& other) -> uint3
  {
    return self - other;
  }).
    define_method("*", [](const uint3& self, const uint3& other) -> uint3
  {
    return self * other;
  }).
    define_method("/", [](const uint3& self, const uint3& other) -> uint3
  {
    return self / other;
  }).
    define_method("==", [](const uint3& self, const uint3& other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const uint3& self, const uint3& other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const uint3& self, const uint3& other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const uint3& self, const uint3& other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const uint3& self, const uint3& other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const uint3& self, const uint3& other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uint3& self, const uint3& other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const uint3& self, const uint3& other) -> uchar3
  {
    return self || other;
  }).
    define_method("&", [](const uint3& self, const uint3& other) -> uint3
  {
    return self & other;
  }).
    define_method("|", [](const uint3& self, const uint3& other) -> uint3
  {
    return self | other;
  }).
    define_method("^", [](const uint3& self, const uint3& other) -> uint3
  {
    return self ^ other;
  }).
    define_method("+", [](const uint3& self, uint other) -> uint3
  {
    return self + other;
  }).
    define_method("+", [](const uint3& self, float other) -> float3
  {
    return self + other;
  }).
    define_method("+", [](const uint3& self, double other) -> double3
  {
    return self + other;
  }).
    define_method("-", [](const uint3& self, uint other) -> uint3
  {
    return self - other;
  }).
    define_method("-", [](const uint3& self, float other) -> float3
  {
    return self - other;
  }).
    define_method("-", [](const uint3& self, double other) -> double3
  {
    return self - other;
  }).
    define_method("*", [](const uint3& self, uint other) -> uint3
  {
    return self * other;
  }).
    define_method("*", [](const uint3& self, float other) -> float3
  {
    return self * other;
  }).
    define_method("*", [](const uint3& self, double other) -> double3
  {
    return self * other;
  }).
    define_method("/", [](const uint3& self, uint other) -> uint3
  {
    return self / other;
  }).
    define_method("/", [](const uint3& self, float other) -> float3
  {
    return self / other;
  }).
    define_method("/", [](const uint3& self, double other) -> double3
  {
    return self / other;
  }).
    define_method("==", [](const uint3& self, uint other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const uint3& self, uint other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const uint3& self, uint other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const uint3& self, uint other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const uint3& self, uint other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const uint3& self, uint other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uint3& self, uint other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const uint3& self, uint other) -> uchar3
  {
    return self || other;
  }).
    define_method("&", [](const uint3& self, uint other) -> uint3
  {
    return self & other;
  }).
    define_method("|", [](const uint3& self, uint other) -> uint3
  {
    return self | other;
  }).
    define_method("^", [](const uint3& self, uint other) -> uint3
  {
    return self ^ other;
  });
  
  rb_cUint4.
    define_method("+", [](const uint4& self, const uint4& other) -> uint4
  {
    return self + other;
  }).
    define_method("-", [](const uint4& self, const uint4& other) -> uint4
  {
    return self - other;
  }).
    define_method("*", [](const uint4& self, const uint4& other) -> uint4
  {
    return self * other;
  }).
    define_method("/", [](const uint4& self, const uint4& other) -> uint4
  {
    return self / other;
  }).
    define_method("==", [](const uint4& self, const uint4& other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const uint4& self, const uint4& other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const uint4& self, const uint4& other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const uint4& self, const uint4& other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const uint4& self, const uint4& other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const uint4& self, const uint4& other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uint4& self, const uint4& other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const uint4& self, const uint4& other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](const uint4& self, const uint4& other) -> uint4
  {
    return self & other;
  }).
    define_method("|", [](const uint4& self, const uint4& other) -> uint4
  {
    return self | other;
  }).
    define_method("^", [](const uint4& self, const uint4& other) -> uint4
  {
    return self ^ other;
  }).
    define_method("+", [](const uint4& self, uint other) -> uint4
  {
    return self + other;
  }).
    define_method("+", [](const uint4& self, float other) -> float4
  {
    return self + other;
  }).
    define_method("+", [](const uint4& self, double other) -> double4
  {
    return self + other;
  }).
    define_method("-", [](const uint4& self, uint other) -> uint4
  {
    return self - other;
  }).
    define_method("-", [](const uint4& self, float other) -> float4
  {
    return self - other;
  }).
    define_method("-", [](const uint4& self, double other) -> double4
  {
    return self - other;
  }).
    define_method("*", [](const uint4& self, uint other) -> uint4
  {
    return self * other;
  }).
    define_method("*", [](const uint4& self, float other) -> float4
  {
    return self * other;
  }).
    define_method("*", [](const uint4& self, double other) -> double4
  {
    return self * other;
  }).
    define_method("/", [](const uint4& self, uint other) -> uint4
  {
    return self / other;
  }).
    define_method("/", [](const uint4& self, float other) -> float4
  {
    return self / other;
  }).
    define_method("/", [](const uint4& self, double other) -> double4
  {
    return self / other;
  }).
    define_method("==", [](const uint4& self, uint other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const uint4& self, uint other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const uint4& self, uint other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const uint4& self, uint other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const uint4& self, uint other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const uint4& self, uint other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const uint4& self, uint other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const uint4& self, uint other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](const uint4& self, uint other) -> uint4
  {
    return self & other;
  }).
    define_method("|", [](const uint4& self, uint other) -> uint4
  {
    return self | other;
  }).
    define_method("^", [](const uint4& self, uint other) -> uint4
  {
    return self ^ other;
  });
  
  rb_cFloat1.
    define_method("+", [](const float1& self, const float1& other) -> float1
  {
    return self + other;
  }).
    define_method("-", [](const float1& self, const float1& other) -> float1
  {
    return self - other;
  }).
    define_method("*", [](const float1& self, const float1& other) -> float1
  {
    return self * other;
  }).
    define_method("/", [](const float1& self, const float1& other) -> float1
  {
    return self / other;
  }).
    define_method("==", [](const float1& self, const float1& other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const float1& self, const float1& other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const float1& self, const float1& other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const float1& self, const float1& other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const float1& self, const float1& other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const float1& self, const float1& other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const float1& self, const float1& other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const float1& self, const float1& other) -> uchar1
  {
    return self || other;
  }).
    define_method("+", [](const float1& self, float other) -> float1
  {
    return self + other;
  }).
    define_method("+", [](const float1& self, double other) -> double1
  {
    return self + other;
  }).
    define_method("-", [](const float1& self, float other) -> float1
  {
    return self - other;
  }).
    define_method("-", [](const float1& self, double other) -> double1
  {
    return self - other;
  }).
    define_method("*", [](const float1& self, float other) -> float1
  {
    return self * other;
  }).
    define_method("*", [](const float1& self, double other) -> double1
  {
    return self * other;
  }).
    define_method("/", [](const float1& self, float other) -> float1
  {
    return self / other;
  }).
    define_method("/", [](const float1& self, double other) -> double1
  {
    return self / other;
  }).
    define_method("==", [](const float1& self, float other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const float1& self, float other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const float1& self, float other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const float1& self, float other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const float1& self, float other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const float1& self, float other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const float1& self, float other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const float1& self, float other) -> uchar1
  {
    return self || other;
  });
  
  rb_cFloat2.
    define_method("+", [](const float2& self, const float2& other) -> float2
  {
    return self + other;
  }).
    define_method("-", [](const float2& self, const float2& other) -> float2
  {
    return self - other;
  }).
    define_method("*", [](const float2& self, const float2& other) -> float2
  {
    return self * other;
  }).
    define_method("/", [](const float2& self, const float2& other) -> float2
  {
    return self / other;
  }).
    define_method("==", [](const float2& self, const float2& other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const float2& self, const float2& other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const float2& self, const float2& other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const float2& self, const float2& other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const float2& self, const float2& other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const float2& self, const float2& other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const float2& self, const float2& other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const float2& self, const float2& other) -> uchar2
  {
    return self || other;
  }).
    define_method("+", [](const float2& self, float other) -> float2
  {
    return self + other;
  }).
    define_method("+", [](const float2& self, double other) -> double2
  {
    return self + other;
  }).
    define_method("-", [](const float2& self, float other) -> float2
  {
    return self - other;
  }).
    define_method("-", [](const float2& self, double other) -> double2
  {
    return self - other;
  }).
    define_method("*", [](const float2& self, float other) -> float2
  {
    return self * other;
  }).
    define_method("*", [](const float2& self, double other) -> double2
  {
    return self * other;
  }).
    define_method("/", [](const float2& self, float other) -> float2
  {
    return self / other;
  }).
    define_method("/", [](const float2& self, double other) -> double2
  {
    return self / other;
  }).
    define_method("==", [](const float2& self, float other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const float2& self, float other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const float2& self, float other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const float2& self, float other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const float2& self, float other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const float2& self, float other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const float2& self, float other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const float2& self, float other) -> uchar2
  {
    return self || other;
  });
  
  rb_cFloat3.
    define_method("+", [](const float3& self, const float3& other) -> float3
  {
    return self + other;
  }).
    define_method("-", [](const float3& self, const float3& other) -> float3
  {
    return self - other;
  }).
    define_method("*", [](const float3& self, const float3& other) -> float3
  {
    return self * other;
  }).
    define_method("/", [](const float3& self, const float3& other) -> float3
  {
    return self / other;
  }).
    define_method("==", [](const float3& self, const float3& other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const float3& self, const float3& other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const float3& self, const float3& other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const float3& self, const float3& other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const float3& self, const float3& other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const float3& self, const float3& other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const float3& self, const float3& other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const float3& self, const float3& other) -> uchar3
  {
    return self || other;
  }).
    define_method("+", [](const float3& self, float other) -> float3
  {
    return self + other;
  }).
    define_method("+", [](const float3& self, double other) -> double3
  {
    return self + other;
  }).
    define_method("-", [](const float3& self, float other) -> float3
  {
    return self - other;
  }).
    define_method("-", [](const float3& self, double other) -> double3
  {
    return self - other;
  }).
    define_method("*", [](const float3& self, float other) -> float3
  {
    return self * other;
  }).
    define_method("*", [](const float3& self, double other) -> double3
  {
    return self * other;
  }).
    define_method("/", [](const float3& self, float other) -> float3
  {
    return self / other;
  }).
    define_method("/", [](const float3& self, double other) -> double3
  {
    return self / other;
  }).
    define_method("==", [](const float3& self, float other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const float3& self, float other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const float3& self, float other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const float3& self, float other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const float3& self, float other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const float3& self, float other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const float3& self, float other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const float3& self, float other) -> uchar3
  {
    return self || other;
  });
  
  rb_cFloat4.
    define_method("+", [](const float4& self, const float4& other) -> float4
  {
    return self + other;
  }).
    define_method("-", [](const float4& self, const float4& other) -> float4
  {
    return self - other;
  }).
    define_method("*", [](const float4& self, const float4& other) -> float4
  {
    return self * other;
  }).
    define_method("/", [](const float4& self, const float4& other) -> float4
  {
    return self / other;
  }).
    define_method("==", [](const float4& self, const float4& other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const float4& self, const float4& other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const float4& self, const float4& other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const float4& self, const float4& other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const float4& self, const float4& other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const float4& self, const float4& other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const float4& self, const float4& other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const float4& self, const float4& other) -> uchar4
  {
    return self || other;
  }).
    define_method("+", [](const float4& self, float other) -> float4
  {
    return self + other;
  }).
    define_method("+", [](const float4& self, double other) -> double4
  {
    return self + other;
  }).
    define_method("-", [](const float4& self, float other) -> float4
  {
    return self - other;
  }).
    define_method("-", [](const float4& self, double other) -> double4
  {
    return self - other;
  }).
    define_method("*", [](const float4& self, float other) -> float4
  {
    return self * other;
  }).
    define_method("*", [](const float4& self, double other) -> double4
  {
    return self * other;
  }).
    define_method("/", [](const float4& self, float other) -> float4
  {
    return self / other;
  }).
    define_method("/", [](const float4& self, double other) -> double4
  {
    return self / other;
  }).
    define_method("==", [](const float4& self, float other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const float4& self, float other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const float4& self, float other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const float4& self, float other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const float4& self, float other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const float4& self, float other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const float4& self, float other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const float4& self, float other) -> uchar4
  {
    return self || other;
  });
  
  rb_cDouble1.
    define_method("+", [](const double1& self, const double1& other) -> double1
  {
    return self + other;
  }).
    define_method("-", [](const double1& self, const double1& other) -> double1
  {
    return self - other;
  }).
    define_method("*", [](const double1& self, const double1& other) -> double1
  {
    return self * other;
  }).
    define_method("/", [](const double1& self, const double1& other) -> double1
  {
    return self / other;
  }).
    define_method("==", [](const double1& self, const double1& other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const double1& self, const double1& other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const double1& self, const double1& other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const double1& self, const double1& other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const double1& self, const double1& other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const double1& self, const double1& other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const double1& self, const double1& other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const double1& self, const double1& other) -> uchar1
  {
    return self || other;
  }).
    define_method("+", [](const double1& self, double other) -> double1
  {
    return self + other;
  }).
    define_method("-", [](const double1& self, double other) -> double1
  {
    return self - other;
  }).
    define_method("*", [](const double1& self, double other) -> double1
  {
    return self * other;
  }).
    define_method("/", [](const double1& self, double other) -> double1
  {
    return self / other;
  }).
    define_method("==", [](const double1& self, double other) -> uchar1
  {
    return self == other;
  }).
    define_method("!=", [](const double1& self, double other) -> uchar1
  {
    return self != other;
  }).
    define_method(">", [](const double1& self, double other) -> uchar1
  {
    return self > other;
  }).
    define_method("<", [](const double1& self, double other) -> uchar1
  {
    return self < other;
  }).
    define_method(">=", [](const double1& self, double other) -> uchar1
  {
    return self >= other;
  }).
    define_method("<=", [](const double1& self, double other) -> uchar1
  {
    return self <= other;
  }).
    define_method("logical_and", [](const double1& self, double other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_or", [](const double1& self, double other) -> uchar1
  {
    return self || other;
  });
  
  rb_cDouble2.
    define_method("+", [](const double2& self, const double2& other) -> double2
  {
    return self + other;
  }).
    define_method("-", [](const double2& self, const double2& other) -> double2
  {
    return self - other;
  }).
    define_method("*", [](const double2& self, const double2& other) -> double2
  {
    return self * other;
  }).
    define_method("/", [](const double2& self, const double2& other) -> double2
  {
    return self / other;
  }).
    define_method("==", [](const double2& self, const double2& other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const double2& self, const double2& other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const double2& self, const double2& other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const double2& self, const double2& other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const double2& self, const double2& other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const double2& self, const double2& other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const double2& self, const double2& other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const double2& self, const double2& other) -> uchar2
  {
    return self || other;
  }).
    define_method("+", [](const double2& self, double other) -> double2
  {
    return self + other;
  }).
    define_method("-", [](const double2& self, double other) -> double2
  {
    return self - other;
  }).
    define_method("*", [](const double2& self, double other) -> double2
  {
    return self * other;
  }).
    define_method("/", [](const double2& self, double other) -> double2
  {
    return self / other;
  }).
    define_method("==", [](const double2& self, double other) -> uchar2
  {
    return self == other;
  }).
    define_method("!=", [](const double2& self, double other) -> uchar2
  {
    return self != other;
  }).
    define_method(">", [](const double2& self, double other) -> uchar2
  {
    return self > other;
  }).
    define_method("<", [](const double2& self, double other) -> uchar2
  {
    return self < other;
  }).
    define_method(">=", [](const double2& self, double other) -> uchar2
  {
    return self >= other;
  }).
    define_method("<=", [](const double2& self, double other) -> uchar2
  {
    return self <= other;
  }).
    define_method("logical_and", [](const double2& self, double other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_or", [](const double2& self, double other) -> uchar2
  {
    return self || other;
  });
  
  rb_cDouble3.
    define_method("+", [](const double3& self, const double3& other) -> double3
  {
    return self + other;
  }).
    define_method("-", [](const double3& self, const double3& other) -> double3
  {
    return self - other;
  }).
    define_method("*", [](const double3& self, const double3& other) -> double3
  {
    return self * other;
  }).
    define_method("/", [](const double3& self, const double3& other) -> double3
  {
    return self / other;
  }).
    define_method("==", [](const double3& self, const double3& other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const double3& self, const double3& other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const double3& self, const double3& other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const double3& self, const double3& other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const double3& self, const double3& other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const double3& self, const double3& other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const double3& self, const double3& other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const double3& self, const double3& other) -> uchar3
  {
    return self || other;
  }).
    define_method("+", [](const double3& self, double other) -> double3
  {
    return self + other;
  }).
    define_method("-", [](const double3& self, double other) -> double3
  {
    return self - other;
  }).
    define_method("*", [](const double3& self, double other) -> double3
  {
    return self * other;
  }).
    define_method("/", [](const double3& self, double other) -> double3
  {
    return self / other;
  }).
    define_method("==", [](const double3& self, double other) -> uchar3
  {
    return self == other;
  }).
    define_method("!=", [](const double3& self, double other) -> uchar3
  {
    return self != other;
  }).
    define_method(">", [](const double3& self, double other) -> uchar3
  {
    return self > other;
  }).
    define_method("<", [](const double3& self, double other) -> uchar3
  {
    return self < other;
  }).
    define_method(">=", [](const double3& self, double other) -> uchar3
  {
    return self >= other;
  }).
    define_method("<=", [](const double3& self, double other) -> uchar3
  {
    return self <= other;
  }).
    define_method("logical_and", [](const double3& self, double other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_or", [](const double3& self, double other) -> uchar3
  {
    return self || other;
  });
  
  rb_cDouble4.
    define_method("+", [](const double4& self, const double4& other) -> double4
  {
    return self + other;
  }).
    define_method("-", [](const double4& self, const double4& other) -> double4
  {
    return self - other;
  }).
    define_method("*", [](const double4& self, const double4& other) -> double4
  {
    return self * other;
  }).
    define_method("/", [](const double4& self, const double4& other) -> double4
  {
    return self / other;
  }).
    define_method("==", [](const double4& self, const double4& other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const double4& self, const double4& other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const double4& self, const double4& other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const double4& self, const double4& other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const double4& self, const double4& other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const double4& self, const double4& other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const double4& self, const double4& other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const double4& self, const double4& other) -> uchar4
  {
    return self || other;
  }).
    define_method("+", [](const double4& self, double other) -> double4
  {
    return self + other;
  }).
    define_method("-", [](const double4& self, double other) -> double4
  {
    return self - other;
  }).
    define_method("*", [](const double4& self, double other) -> double4
  {
    return self * other;
  }).
    define_method("/", [](const double4& self, double other) -> double4
  {
    return self / other;
  }).
    define_method("==", [](const double4& self, double other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](const double4& self, double other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](const double4& self, double other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](const double4& self, double other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](const double4& self, double other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](const double4& self, double other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](const double4& self, double other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](const double4& self, double other) -> uchar4
  {
    return self || other;
  });
  
  rb_cUInt.
    define_method("+", [](uint self, const uint1& other) -> uint1
  {
    return self + other;
  }).
    define_method("+", [](uint self, const uint2& other) -> uint2
  {
    return self + other;
  }).
    define_method("+", [](uint self, const uint3& other) -> uint3
  {
    return self + other;
  }).
    define_method("+", [](uint self, const uint4& other) -> uint4
  {
    return self + other;
  }).
    define_method("-", [](uint self, const uint1& other) -> uint1
  {
    return self - other;
  }).
    define_method("-", [](uint self, const uint2& other) -> uint2
  {
    return self - other;
  }).
    define_method("-", [](uint self, const uint3& other) -> uint3
  {
    return self - other;
  }).
    define_method("-", [](uint self, const uint4& other) -> uint4
  {
    return self - other;
  }).
    define_method("*", [](uint self, const uint1& other) -> uint1
  {
    return self * other;
  }).
    define_method("*", [](uint self, const uint2& other) -> uint2
  {
    return self * other;
  }).
    define_method("*", [](uint self, const uint3& other) -> uint3
  {
    return self * other;
  }).
    define_method("*", [](uint self, const uint4& other) -> uint4
  {
    return self * other;
  }).
    define_method("/", [](uint self, const uint1& other) -> uint1
  {
    return self / other;
  }).
    define_method("/", [](uint self, const uint2& other) -> uint2
  {
    return self / other;
  }).
    define_method("/", [](uint self, const uint3& other) -> uint3
  {
    return self / other;
  }).
    define_method("/", [](uint self, const uint4& other) -> uint4
  {
    return self / other;
  }).
    define_method("==", [](uint self, const uint1& other) -> uchar1
  {
    return self == other;
  }).
    define_method("==", [](uint self, const uint2& other) -> uchar2
  {
    return self == other;
  }).
    define_method("==", [](uint self, const uint3& other) -> uchar3
  {
    return self == other;
  }).
    define_method("==", [](uint self, const uint4& other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](uint self, const uint1& other) -> uchar1
  {
    return self != other;
  }).
    define_method("!=", [](uint self, const uint2& other) -> uchar2
  {
    return self != other;
  }).
    define_method("!=", [](uint self, const uint3& other) -> uchar3
  {
    return self != other;
  }).
    define_method("!=", [](uint self, const uint4& other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](uint self, const uint1& other) -> uchar1
  {
    return self > other;
  }).
    define_method(">", [](uint self, const uint2& other) -> uchar2
  {
    return self > other;
  }).
    define_method(">", [](uint self, const uint3& other) -> uchar3
  {
    return self > other;
  }).
    define_method(">", [](uint self, const uint4& other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](uint self, const uint1& other) -> uchar1
  {
    return self < other;
  }).
    define_method("<", [](uint self, const uint2& other) -> uchar2
  {
    return self < other;
  }).
    define_method("<", [](uint self, const uint3& other) -> uchar3
  {
    return self < other;
  }).
    define_method("<", [](uint self, const uint4& other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](uint self, const uint1& other) -> uchar1
  {
    return self >= other;
  }).
    define_method(">=", [](uint self, const uint2& other) -> uchar2
  {
    return self >= other;
  }).
    define_method(">=", [](uint self, const uint3& other) -> uchar3
  {
    return self >= other;
  }).
    define_method(">=", [](uint self, const uint4& other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](uint self, const uint1& other) -> uchar1
  {
    return self <= other;
  }).
    define_method("<=", [](uint self, const uint2& other) -> uchar2
  {
    return self <= other;
  }).
    define_method("<=", [](uint self, const uint3& other) -> uchar3
  {
    return self <= other;
  }).
    define_method("<=", [](uint self, const uint4& other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](uint self, const uint1& other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_and", [](uint self, const uint2& other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_and", [](uint self, const uint3& other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_and", [](uint self, const uint4& other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](uint self, const uint1& other) -> uchar1
  {
    return self || other;
  }).
    define_method("logical_or", [](uint self, const uint2& other) -> uchar2
  {
    return self || other;
  }).
    define_method("logical_or", [](uint self, const uint3& other) -> uchar3
  {
    return self || other;
  }).
    define_method("logical_or", [](uint self, const uint4& other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](uint self, const uint1& other) -> uint1
  {
    return self & other;
  }).
    define_method("&", [](uint self, const uint2& other) -> uint2
  {
    return self & other;
  }).
    define_method("&", [](uint self, const uint3& other) -> uint3
  {
    return self & other;
  }).
    define_method("&", [](uint self, const uint4& other) -> uint4
  {
    return self & other;
  }).
    define_method("|", [](uint self, const uint1& other) -> uint1
  {
    return self | other;
  }).
    define_method("|", [](uint self, const uint2& other) -> uint2
  {
    return self | other;
  }).
    define_method("|", [](uint self, const uint3& other) -> uint3
  {
    return self | other;
  }).
    define_method("|", [](uint self, const uint4& other) -> uint4
  {
    return self | other;
  }).
    define_method("^", [](uint self, const uint1& other) -> uint1
  {
    return self ^ other;
  }).
    define_method("^", [](uint self, const uint2& other) -> uint2
  {
    return self ^ other;
  }).
    define_method("^", [](uint self, const uint3& other) -> uint3
  {
    return self ^ other;
  }).
    define_method("^", [](uint self, const uint4& other) -> uint4
  {
    return self ^ other;
  });
  
  rb_cUChar.
    define_method("==", [](uchar self, const uchar1& other) -> uchar1
  {
    return self == other;
  }).
    define_method("==", [](uchar self, const uchar2& other) -> uchar2
  {
    return self == other;
  }).
    define_method("==", [](uchar self, const uchar3& other) -> uchar3
  {
    return self == other;
  }).
    define_method("==", [](uchar self, const uchar4& other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](uchar self, const uchar1& other) -> uchar1
  {
    return self != other;
  }).
    define_method("!=", [](uchar self, const uchar2& other) -> uchar2
  {
    return self != other;
  }).
    define_method("!=", [](uchar self, const uchar3& other) -> uchar3
  {
    return self != other;
  }).
    define_method("!=", [](uchar self, const uchar4& other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](uchar self, const uchar1& other) -> uchar1
  {
    return self > other;
  }).
    define_method(">", [](uchar self, const uchar2& other) -> uchar2
  {
    return self > other;
  }).
    define_method(">", [](uchar self, const uchar3& other) -> uchar3
  {
    return self > other;
  }).
    define_method(">", [](uchar self, const uchar4& other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](uchar self, const uchar1& other) -> uchar1
  {
    return self < other;
  }).
    define_method("<", [](uchar self, const uchar2& other) -> uchar2
  {
    return self < other;
  }).
    define_method("<", [](uchar self, const uchar3& other) -> uchar3
  {
    return self < other;
  }).
    define_method("<", [](uchar self, const uchar4& other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](uchar self, const uchar1& other) -> uchar1
  {
    return self >= other;
  }).
    define_method(">=", [](uchar self, const uchar2& other) -> uchar2
  {
    return self >= other;
  }).
    define_method(">=", [](uchar self, const uchar3& other) -> uchar3
  {
    return self >= other;
  }).
    define_method(">=", [](uchar self, const uchar4& other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](uchar self, const uchar1& other) -> uchar1
  {
    return self <= other;
  }).
    define_method("<=", [](uchar self, const uchar2& other) -> uchar2
  {
    return self <= other;
  }).
    define_method("<=", [](uchar self, const uchar3& other) -> uchar3
  {
    return self <= other;
  }).
    define_method("<=", [](uchar self, const uchar4& other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](uchar self, const uchar1& other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_and", [](uchar self, const uchar2& other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_and", [](uchar self, const uchar3& other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_and", [](uchar self, const uchar4& other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](uchar self, const uchar1& other) -> uchar1
  {
    return self || other;
  }).
    define_method("logical_or", [](uchar self, const uchar2& other) -> uchar2
  {
    return self || other;
  }).
    define_method("logical_or", [](uchar self, const uchar3& other) -> uchar3
  {
    return self || other;
  }).
    define_method("logical_or", [](uchar self, const uchar4& other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](uchar self, const uchar1& other) -> uchar1
  {
    return self & other;
  }).
    define_method("&", [](uchar self, const uchar2& other) -> uchar2
  {
    return self & other;
  }).
    define_method("&", [](uchar self, const uchar3& other) -> uchar3
  {
    return self & other;
  }).
    define_method("&", [](uchar self, const uchar4& other) -> uchar4
  {
    return self & other;
  }).
    define_method("|", [](uchar self, const uchar1& other) -> uchar1
  {
    return self | other;
  }).
    define_method("|", [](uchar self, const uchar2& other) -> uchar2
  {
    return self | other;
  }).
    define_method("|", [](uchar self, const uchar3& other) -> uchar3
  {
    return self | other;
  }).
    define_method("|", [](uchar self, const uchar4& other) -> uchar4
  {
    return self | other;
  }).
    define_method("^", [](uchar self, const uchar1& other) -> uchar1
  {
    return self ^ other;
  }).
    define_method("^", [](uchar self, const uchar2& other) -> uchar2
  {
    return self ^ other;
  }).
    define_method("^", [](uchar self, const uchar3& other) -> uchar3
  {
    return self ^ other;
  }).
    define_method("^", [](uchar self, const uchar4& other) -> uchar4
  {
    return self ^ other;
  });
  
  rb_cUShort.
    define_method("==", [](ushort self, const ushort1& other) -> uchar1
  {
    return self == other;
  }).
    define_method("==", [](ushort self, const ushort2& other) -> uchar2
  {
    return self == other;
  }).
    define_method("==", [](ushort self, const ushort3& other) -> uchar3
  {
    return self == other;
  }).
    define_method("==", [](ushort self, const ushort4& other) -> uchar4
  {
    return self == other;
  }).
    define_method("!=", [](ushort self, const ushort1& other) -> uchar1
  {
    return self != other;
  }).
    define_method("!=", [](ushort self, const ushort2& other) -> uchar2
  {
    return self != other;
  }).
    define_method("!=", [](ushort self, const ushort3& other) -> uchar3
  {
    return self != other;
  }).
    define_method("!=", [](ushort self, const ushort4& other) -> uchar4
  {
    return self != other;
  }).
    define_method(">", [](ushort self, const ushort1& other) -> uchar1
  {
    return self > other;
  }).
    define_method(">", [](ushort self, const ushort2& other) -> uchar2
  {
    return self > other;
  }).
    define_method(">", [](ushort self, const ushort3& other) -> uchar3
  {
    return self > other;
  }).
    define_method(">", [](ushort self, const ushort4& other) -> uchar4
  {
    return self > other;
  }).
    define_method("<", [](ushort self, const ushort1& other) -> uchar1
  {
    return self < other;
  }).
    define_method("<", [](ushort self, const ushort2& other) -> uchar2
  {
    return self < other;
  }).
    define_method("<", [](ushort self, const ushort3& other) -> uchar3
  {
    return self < other;
  }).
    define_method("<", [](ushort self, const ushort4& other) -> uchar4
  {
    return self < other;
  }).
    define_method(">=", [](ushort self, const ushort1& other) -> uchar1
  {
    return self >= other;
  }).
    define_method(">=", [](ushort self, const ushort2& other) -> uchar2
  {
    return self >= other;
  }).
    define_method(">=", [](ushort self, const ushort3& other) -> uchar3
  {
    return self >= other;
  }).
    define_method(">=", [](ushort self, const ushort4& other) -> uchar4
  {
    return self >= other;
  }).
    define_method("<=", [](ushort self, const ushort1& other) -> uchar1
  {
    return self <= other;
  }).
    define_method("<=", [](ushort self, const ushort2& other) -> uchar2
  {
    return self <= other;
  }).
    define_method("<=", [](ushort self, const ushort3& other) -> uchar3
  {
    return self <= other;
  }).
    define_method("<=", [](ushort self, const ushort4& other) -> uchar4
  {
    return self <= other;
  }).
    define_method("logical_and", [](ushort self, const ushort1& other) -> uchar1
  {
    return self && other;
  }).
    define_method("logical_and", [](ushort self, const ushort2& other) -> uchar2
  {
    return self && other;
  }).
    define_method("logical_and", [](ushort self, const ushort3& other) -> uchar3
  {
    return self && other;
  }).
    define_method("logical_and", [](ushort self, const ushort4& other) -> uchar4
  {
    return self && other;
  }).
    define_method("logical_or", [](ushort self, const ushort1& other) -> uchar1
  {
    return self || other;
  }).
    define_method("logical_or", [](ushort self, const ushort2& other) -> uchar2
  {
    return self || other;
  }).
    define_method("logical_or", [](ushort self, const ushort3& other) -> uchar3
  {
    return self || other;
  }).
    define_method("logical_or", [](ushort self, const ushort4& other) -> uchar4
  {
    return self || other;
  }).
    define_method("&", [](ushort self, const ushort1& other) -> ushort1
  {
    return self & other;
  }).
    define_method("&", [](ushort self, const ushort2& other) -> ushort2
  {
    return self & other;
  }).
    define_method("&", [](ushort self, const ushort3& other) -> ushort3
  {
    return self & other;
  }).
    define_method("&", [](ushort self, const ushort4& other) -> ushort4
  {
    return self & other;
  }).
    define_method("|", [](ushort self, const ushort1& other) -> ushort1
  {
    return self | other;
  }).
    define_method("|", [](ushort self, const ushort2& other) -> ushort2
  {
    return self | other;
  }).
    define_method("|", [](ushort self, const ushort3& other) -> ushort3
  {
    return self | other;
  }).
    define_method("|", [](ushort self, const ushort4& other) -> ushort4
  {
    return self | other;
  }).
    define_method("^", [](ushort self, const ushort1& other) -> ushort1
  {
    return self ^ other;
  }).
    define_method("^", [](ushort self, const ushort2& other) -> ushort2
  {
    return self ^ other;
  }).
    define_method("^", [](ushort self, const ushort3& other) -> ushort3
  {
    return self ^ other;
  }).
    define_method("^", [](ushort self, const ushort4& other) -> ushort4
  {
    return self ^ other;
  });
}