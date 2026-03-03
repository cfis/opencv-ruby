#include <opencv2/core/directx.hpp>
#include "directx-rb.hpp"

using namespace Rice;

void Init_Core_Directx()
{
  Rice::Data_Type<ID3D11Device> rb_cID3D11Device = define_class<ID3D11Device>("ID3D11Device");

  Rice::Data_Type<ID3D11Texture2D> rb_cID3D11Texture2D = define_class<ID3D11Texture2D>("ID3D11Texture2D");

  Rice::Data_Type<ID3D10Device> rb_cID3D10Device = define_class<ID3D10Device>("ID3D10Device");

  Rice::Data_Type<ID3D10Texture2D> rb_cID3D10Texture2D = define_class<ID3D10Texture2D>("ID3D10Texture2D");

  Rice::Data_Type<IDirect3DDevice9> rb_cIDirect3DDevice9 = define_class<IDirect3DDevice9>("IDirect3DDevice9");

  Rice::Data_Type<IDirect3DDevice9Ex> rb_cIDirect3DDevice9Ex = define_class<IDirect3DDevice9Ex>("IDirect3DDevice9Ex");

  Rice::Data_Type<IDirect3DSurface9> rb_cIDirect3DSurface9 = define_class<IDirect3DSurface9>("IDirect3DSurface9");

  Module rb_mCv = define_module("Cv");

  Module rb_mCvDirectx = define_module_under(rb_mCv, "Directx");

  Module rb_mCvDirectxOcl = define_module_under(rb_mCvDirectx, "Ocl");

  rb_mCvDirectxOcl.define_module_function<cv::ocl::Context&(*)(ID3D11Device*)>("initialize_context_from_d3d11_device", &cv::directx::ocl::initializeContextFromD3D11Device,
    Arg("p_d3d11_device"));

  rb_mCvDirectxOcl.define_module_function<cv::ocl::Context&(*)(ID3D10Device*)>("initialize_context_from_d3d10_device", &cv::directx::ocl::initializeContextFromD3D10Device,
    Arg("p_d3d10_device"));

  rb_mCvDirectxOcl.define_module_function<cv::ocl::Context&(*)(IDirect3DDevice9Ex*)>("initialize_context_from_direct_3d_device9_ex", &cv::directx::ocl::initializeContextFromDirect3DDevice9Ex,
    Arg("p_direct_3d_device9_ex"));

  rb_mCvDirectxOcl.define_module_function<cv::ocl::Context&(*)(IDirect3DDevice9*)>("initialize_context_from_direct_3d_device9", &cv::directx::ocl::initializeContextFromDirect3DDevice9,
    Arg("p_direct_3d_device9"));

  rb_mCvDirectx.define_module_function<void(*)(cv::InputArray, ID3D11Texture2D*)>("convert_to_d3d11_texture_2d", &cv::directx::convertToD3D11Texture2D,
    Arg("src"), Arg("p_d3d11_texture_2d"));

  rb_mCvDirectx.define_module_function<void(*)(ID3D11Texture2D*, cv::OutputArray)>("convert_from_d3d11_texture_2d", &cv::directx::convertFromD3D11Texture2D,
    Arg("p_d3d11_texture_2d"), Arg("dst"));

  rb_mCvDirectx.define_module_function<void(*)(cv::InputArray, ID3D10Texture2D*)>("convert_to_d3d10_texture_2d", &cv::directx::convertToD3D10Texture2D,
    Arg("src"), Arg("p_d3d10_texture_2d"));

  rb_mCvDirectx.define_module_function<void(*)(ID3D10Texture2D*, cv::OutputArray)>("convert_from_d3d10_texture_2d", &cv::directx::convertFromD3D10Texture2D,
    Arg("p_d3d10_texture_2d"), Arg("dst"));

  rb_mCvDirectx.define_module_function<void(*)(cv::InputArray, IDirect3DSurface9*, void*)>("convert_to_direct_3d_surface9", &cv::directx::convertToDirect3DSurface9,
    Arg("src"), Arg("p_direct_3d_surface9"), ArgBuffer("surface_shared_handle") = static_cast<void*>(NULL));

  rb_mCvDirectx.define_module_function<void(*)(IDirect3DSurface9*, cv::OutputArray, void*)>("convert_from_direct_3d_surface9", &cv::directx::convertFromDirect3DSurface9,
    Arg("p_direct_3d_surface9"), Arg("dst"), ArgBuffer("surface_shared_handle") = static_cast<void*>(NULL));

  rb_mCvDirectx.define_module_function<int(*)(const int)>("get_type_from_dxgi_format", &cv::directx::getTypeFromDXGI_FORMAT,
    Arg("i_dxgi_format"));

  rb_mCvDirectx.define_module_function<int(*)(const int)>("get_type_from_d3dformat", &cv::directx::getTypeFromD3DFORMAT,
    Arg("i_d3dformat"));
}
