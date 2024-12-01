#include <opencv2/core/directx.hpp>
#include "directx-rb.hpp"

using namespace Rice;


void Init_Directx()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDirectx = define_module_under(rb_mCv, "Directx");
  
  Module rb_mCvDirectxOcl = define_module_under(rb_mCvDirectx, "Ocl");
  
  rb_mCvDirectxOcl.define_module_function("initialize_context_from_d3_d11_device", &cv::directx::ocl::initializeContextFromD3D11Device,
    Arg("p_d3_d11_device"));
  
  rb_mCvDirectxOcl.define_module_function("initialize_context_from_d3_d10_device", &cv::directx::ocl::initializeContextFromD3D10Device,
    Arg("p_d3_d10_device"));
  
  rb_mCvDirectxOcl.define_module_function("initialize_context_from_direct3_d_device9_ex", &cv::directx::ocl::initializeContextFromDirect3DDevice9Ex,
    Arg("p_direct3_d_device9_ex"));
  
  rb_mCvDirectxOcl.define_module_function("initialize_context_from_direct3_d_device9", &cv::directx::ocl::initializeContextFromDirect3DDevice9,
    Arg("p_direct3_d_device9"));
  
  rb_mCvDirectx.define_module_function("convert_to_d3_d11_texture_2d", &cv::directx::convertToD3D11Texture2D,
    Arg("src"), Arg("p_d3_d11_texture_2d"));
  
  rb_mCvDirectx.define_module_function("convert_from_d3_d11_texture_2d", &cv::directx::convertFromD3D11Texture2D,
    Arg("p_d3_d11_texture_2d"), Arg("dst"));
  
  rb_mCvDirectx.define_module_function("convert_to_d3_d10_texture_2d", &cv::directx::convertToD3D10Texture2D,
    Arg("src"), Arg("p_d3_d10_texture_2d"));
  
  rb_mCvDirectx.define_module_function("convert_from_d3_d10_texture_2d", &cv::directx::convertFromD3D10Texture2D,
    Arg("p_d3_d10_texture_2d"), Arg("dst"));
  
  rb_mCvDirectx.define_module_function("convert_to_direct3_d_surface9", &cv::directx::convertToDirect3DSurface9,
    Arg("src"), Arg("p_direct3_d_surface9"), Arg("surface_shared_handle") = static_cast<void *>(NULL));
  
  rb_mCvDirectx.define_module_function("convert_from_direct3_d_surface9", &cv::directx::convertFromDirect3DSurface9,
    Arg("p_direct3_d_surface9"), Arg("dst"), Arg("surface_shared_handle") = static_cast<void *>(NULL));
  
  rb_mCvDirectx.define_module_function("get_type_from_dxgi_format", &cv::directx::getTypeFromDXGI_FORMAT,
    Arg("i_dxgi_format"));
  
  rb_mCvDirectx.define_module_function("get_type_from_d3_dformat", &cv::directx::getTypeFromD3DFORMAT,
    Arg("i_d3_dformat"));

}