#include <opencv2/core/cuda.hpp>
#include <opencv2/core/opengl.hpp>

#include "opengl-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvOglArrays;
Rice::Class rb_cCvOglBuffer;
Rice::Class rb_cCvOglTexture2D;

void Init_Opengl()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvOgl = define_module_under(rb_mCv, "Ogl");
  
  rb_cCvOglBuffer = define_class_under<cv::ogl::Buffer>(rb_mCvOgl, "Buffer").
    define_constructor(Constructor<cv::ogl::Buffer>()).
    define_constructor(Constructor<cv::ogl::Buffer, int, int, int, unsigned int, bool>(),
      Arg("arows"), Arg("acols"), Arg("atype"), Arg("abuf_id"), Arg("auto_release") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::ogl::Buffer, cv::Size, int, unsigned int, bool>(),
      Arg("asize"), Arg("atype"), Arg("abuf_id"), Arg("auto_release") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::ogl::Buffer, int, int, int, cv::ogl::Buffer::Target, bool>(),
      Arg("arows"), Arg("acols"), Arg("atype"), Arg("target") = static_cast<cv::ogl::Buffer::Target>(cv::ogl::Buffer::Target::ARRAY_BUFFER), Arg("auto_release") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::ogl::Buffer, cv::Size, int, cv::ogl::Buffer::Target, bool>(),
      Arg("asize"), Arg("atype"), Arg("target") = static_cast<cv::ogl::Buffer::Target>(cv::ogl::Buffer::Target::ARRAY_BUFFER), Arg("auto_release") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::ogl::Buffer, cv::InputArray, cv::ogl::Buffer::Target, bool>(),
      Arg("arr"), Arg("target") = static_cast<cv::ogl::Buffer::Target>(cv::ogl::Buffer::Target::ARRAY_BUFFER), Arg("auto_release") = static_cast<bool>(false)).
    define_method<void(cv::ogl::Buffer::*)(int, int, int, cv::ogl::Buffer::Target, bool)>("create", &cv::ogl::Buffer::create,
      Arg("arows"), Arg("acols"), Arg("atype"), Arg("target") = static_cast<cv::ogl::Buffer::Target>(cv::ogl::Buffer::Target::ARRAY_BUFFER), Arg("auto_release") = static_cast<bool>(false)).
    define_method<void(cv::ogl::Buffer::*)(cv::Size, int, cv::ogl::Buffer::Target, bool)>("create", &cv::ogl::Buffer::create,
      Arg("asize"), Arg("atype"), Arg("target") = static_cast<cv::ogl::Buffer::Target>(cv::ogl::Buffer::Target::ARRAY_BUFFER), Arg("auto_release") = static_cast<bool>(false)).
    define_method<void(cv::ogl::Buffer::*)()>("release", &cv::ogl::Buffer::release).
    define_method<void(cv::ogl::Buffer::*)(bool)>("set_auto_release", &cv::ogl::Buffer::setAutoRelease,
      Arg("flag")).
    define_method<void(cv::ogl::Buffer::*)(cv::InputArray, cv::ogl::Buffer::Target, bool)>("copy_from", &cv::ogl::Buffer::copyFrom,
      Arg("arr"), Arg("target") = static_cast<cv::ogl::Buffer::Target>(cv::ogl::Buffer::Target::ARRAY_BUFFER), Arg("auto_release") = static_cast<bool>(false)).
    define_method<void(cv::ogl::Buffer::*)(cv::InputArray, cv::cuda::Stream&, cv::ogl::Buffer::Target, bool)>("copy_from", &cv::ogl::Buffer::copyFrom,
      Arg("arr"), Arg("stream"), Arg("target") = static_cast<cv::ogl::Buffer::Target>(cv::ogl::Buffer::Target::ARRAY_BUFFER), Arg("auto_release") = static_cast<bool>(false)).
    define_method<void(cv::ogl::Buffer::*)(cv::OutputArray) const>("copy_to", &cv::ogl::Buffer::copyTo,
      Arg("arr")).
    define_method<void(cv::ogl::Buffer::*)(cv::OutputArray, cv::cuda::Stream&) const>("copy_to", &cv::ogl::Buffer::copyTo,
      Arg("arr"), Arg("stream")).
    define_method<cv::ogl::Buffer(cv::ogl::Buffer::*)(cv::ogl::Buffer::Target, bool) const>("clone", &cv::ogl::Buffer::clone,
      Arg("target") = static_cast<cv::ogl::Buffer::Target>(cv::ogl::Buffer::Target::ARRAY_BUFFER), Arg("auto_release") = static_cast<bool>(false)).
    define_method<void(cv::ogl::Buffer::*)(cv::ogl::Buffer::Target) const>("bind", &cv::ogl::Buffer::bind,
      Arg("target")).
    define_singleton_function("unbind", &cv::ogl::Buffer::unbind,
      Arg("target")).
    define_method("map_host", &cv::ogl::Buffer::mapHost,
      Arg("access")).
    define_method("unmap_host", &cv::ogl::Buffer::unmapHost).
    define_method<cv::cuda::GpuMat(cv::ogl::Buffer::*)()>("map_device", &cv::ogl::Buffer::mapDevice).
    define_method<void(cv::ogl::Buffer::*)()>("unmap_device", &cv::ogl::Buffer::unmapDevice).
    define_method<cv::cuda::GpuMat(cv::ogl::Buffer::*)(cv::cuda::Stream&)>("map_device", &cv::ogl::Buffer::mapDevice,
      Arg("stream")).
    define_method<void(cv::ogl::Buffer::*)(cv::cuda::Stream&)>("unmap_device", &cv::ogl::Buffer::unmapDevice,
      Arg("stream")).
    define_method("rows", &cv::ogl::Buffer::rows).
    define_method("cols", &cv::ogl::Buffer::cols).
    define_method("size", &cv::ogl::Buffer::size).
    define_method("empty?", &cv::ogl::Buffer::empty).
    define_method("type", &cv::ogl::Buffer::type).
    define_method("depth", &cv::ogl::Buffer::depth).
    define_method("channels", &cv::ogl::Buffer::channels).
    define_method("elem_size", &cv::ogl::Buffer::elemSize).
    define_method("elem_size1", &cv::ogl::Buffer::elemSize1).
    define_method("buf_id", &cv::ogl::Buffer::bufId);
  
  
  Enum<cv::ogl::Buffer::Target> rb_cCvOglBufferTarget = define_enum_under<cv::ogl::Buffer::Target>("Target", rb_cCvOglBuffer).
    define_value("ARRAY_BUFFER", cv::ogl::Buffer::Target::ARRAY_BUFFER).
    define_value("ELEMENT_ARRAY_BUFFER", cv::ogl::Buffer::Target::ELEMENT_ARRAY_BUFFER).
    define_value("PIXEL_PACK_BUFFER", cv::ogl::Buffer::Target::PIXEL_PACK_BUFFER).
    define_value("PIXEL_UNPACK_BUFFER", cv::ogl::Buffer::Target::PIXEL_UNPACK_BUFFER);
  
  Enum<cv::ogl::Buffer::Access> rb_cCvOglBufferAccess = define_enum_under<cv::ogl::Buffer::Access>("Access", rb_cCvOglBuffer).
    define_value("READ_ONLY", cv::ogl::Buffer::Access::READ_ONLY).
    define_value("WRITE_ONLY", cv::ogl::Buffer::Access::WRITE_ONLY).
    define_value("READ_WRITE", cv::ogl::Buffer::Access::READ_WRITE);
  
  rb_cCvOglTexture2D = define_class_under<cv::ogl::Texture2D>(rb_mCvOgl, "Texture2D").
    define_constructor(Constructor<cv::ogl::Texture2D>()).
    define_constructor(Constructor<cv::ogl::Texture2D, int, int, cv::ogl::Texture2D::Format, unsigned int, bool>(),
      Arg("arows"), Arg("acols"), Arg("aformat"), Arg("atex_id"), Arg("auto_release") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::ogl::Texture2D, cv::Size, cv::ogl::Texture2D::Format, unsigned int, bool>(),
      Arg("asize"), Arg("aformat"), Arg("atex_id"), Arg("auto_release") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::ogl::Texture2D, int, int, cv::ogl::Texture2D::Format, bool>(),
      Arg("arows"), Arg("acols"), Arg("aformat"), Arg("auto_release") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::ogl::Texture2D, cv::Size, cv::ogl::Texture2D::Format, bool>(),
      Arg("asize"), Arg("aformat"), Arg("auto_release") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::ogl::Texture2D, cv::InputArray, bool>(),
      Arg("arr"), Arg("auto_release") = static_cast<bool>(false)).
    define_method<void(cv::ogl::Texture2D::*)(int, int, cv::ogl::Texture2D::Format, bool)>("create", &cv::ogl::Texture2D::create,
      Arg("arows"), Arg("acols"), Arg("aformat"), Arg("auto_release") = static_cast<bool>(false)).
    define_method<void(cv::ogl::Texture2D::*)(cv::Size, cv::ogl::Texture2D::Format, bool)>("create", &cv::ogl::Texture2D::create,
      Arg("asize"), Arg("aformat"), Arg("auto_release") = static_cast<bool>(false)).
    define_method("release", &cv::ogl::Texture2D::release).
    define_method("set_auto_release", &cv::ogl::Texture2D::setAutoRelease,
      Arg("flag")).
    define_method("copy_from", &cv::ogl::Texture2D::copyFrom,
      Arg("arr"), Arg("auto_release") = static_cast<bool>(false)).
    define_method("copy_to", &cv::ogl::Texture2D::copyTo,
      Arg("arr"), Arg("ddepth") = static_cast<int>(CV_32F), Arg("auto_release") = static_cast<bool>(false)).
    define_method("bind", &cv::ogl::Texture2D::bind).
    define_method("rows", &cv::ogl::Texture2D::rows).
    define_method("cols", &cv::ogl::Texture2D::cols).
    define_method("size", &cv::ogl::Texture2D::size).
    define_method("empty?", &cv::ogl::Texture2D::empty).
    define_method("format", &cv::ogl::Texture2D::format).
    define_method("tex_id", &cv::ogl::Texture2D::texId);
  
  
  Enum<cv::ogl::Texture2D::Format> rb_cCvOglTexture2DFormat = define_enum_under<cv::ogl::Texture2D::Format>("Format", rb_cCvOglTexture2D).
    define_value("NONE", cv::ogl::Texture2D::Format::NONE).
    define_value("DEPTH_COMPONENT", cv::ogl::Texture2D::Format::DEPTH_COMPONENT).
    define_value("RGB", cv::ogl::Texture2D::Format::RGB).
    define_value("RGBA", cv::ogl::Texture2D::Format::RGBA);
  
  rb_cCvOglArrays = define_class_under<cv::ogl::Arrays>(rb_mCvOgl, "Arrays").
    define_constructor(Constructor<cv::ogl::Arrays>()).
    define_method("set_vertex_array", &cv::ogl::Arrays::setVertexArray,
      Arg("vertex")).
    define_method("reset_vertex_array", &cv::ogl::Arrays::resetVertexArray).
    define_method("set_color_array", &cv::ogl::Arrays::setColorArray,
      Arg("color")).
    define_method("reset_color_array", &cv::ogl::Arrays::resetColorArray).
    define_method("set_normal_array", &cv::ogl::Arrays::setNormalArray,
      Arg("normal")).
    define_method("reset_normal_array", &cv::ogl::Arrays::resetNormalArray).
    define_method("set_tex_coord_array", &cv::ogl::Arrays::setTexCoordArray,
      Arg("tex_coord")).
    define_method("reset_tex_coord_array", &cv::ogl::Arrays::resetTexCoordArray).
    define_method("release", &cv::ogl::Arrays::release).
    define_method("set_auto_release", &cv::ogl::Arrays::setAutoRelease,
      Arg("flag")).
    define_method("bind", &cv::ogl::Arrays::bind).
    define_method("size", &cv::ogl::Arrays::size).
    define_method("empty?", &cv::ogl::Arrays::empty);
  
  Enum<cv::ogl::RenderModes> rb_cCvOglRenderModes = define_enum_under<cv::ogl::RenderModes>("RenderModes", rb_mCvOgl).
    define_value("POINTS", cv::ogl::RenderModes::POINTS).
    define_value("LINES", cv::ogl::RenderModes::LINES).
    define_value("LINE_LOOP", cv::ogl::RenderModes::LINE_LOOP).
    define_value("LINE_STRIP", cv::ogl::RenderModes::LINE_STRIP).
    define_value("TRIANGLES", cv::ogl::RenderModes::TRIANGLES).
    define_value("TRIANGLE_STRIP", cv::ogl::RenderModes::TRIANGLE_STRIP).
    define_value("TRIANGLE_FAN", cv::ogl::RenderModes::TRIANGLE_FAN).
    define_value("QUADS", cv::ogl::RenderModes::QUADS).
    define_value("QUAD_STRIP", cv::ogl::RenderModes::QUAD_STRIP).
    define_value("POLYGON", cv::ogl::RenderModes::POLYGON);
  
  rb_mCvOgl.define_module_function<void(*)(const cv::ogl::Texture2D&, cv::Rect_<double>, cv::Rect_<double>)>("render", &cv::ogl::render,
    Arg("tex"), Arg("wnd_rect") = static_cast<cv::Rect_<double>>(cv::Rect_<double>(0.0, 0.0, 1.0, 1.0)), Arg("tex_rect") = static_cast<cv::Rect_<double>>(cv::Rect_<double>(0.0, 0.0, 1.0, 1.0)));
  
  rb_mCvOgl.define_module_function<void(*)(const cv::ogl::Arrays&, int, cv::Scalar)>("render", &cv::ogl::render,
    Arg("arr"), Arg("mode") = static_cast<int>(cv::ogl::RenderModes::POINTS), Arg("color") = static_cast<cv::Scalar>(cv::Scalar::all(255)));
  
  rb_mCvOgl.define_module_function<void(*)(const cv::ogl::Arrays&, cv::InputArray, int, cv::Scalar)>("render", &cv::ogl::render,
    Arg("arr"), Arg("indices"), Arg("mode") = static_cast<int>(cv::ogl::RenderModes::POINTS), Arg("color") = static_cast<cv::Scalar>(cv::Scalar::all(255)));
  
  Module rb_mCvOglOcl = define_module_under(rb_mCvOgl, "Ocl");
  
  rb_mCvOglOcl.define_module_function("initialize_context_from_gl", &cv::ogl::ocl::initializeContextFromGL);
  
  rb_mCvOgl.define_module_function("convert_to_gl_texture_2d", &cv::ogl::convertToGLTexture2D,
    Arg("src"), Arg("texture"));
  
  rb_mCvOgl.define_module_function("convert_from_gl_texture_2d", &cv::ogl::convertFromGLTexture2D,
    Arg("texture"), Arg("dst"));
  
  rb_mCvOgl.define_module_function("map_gl_buffer", &cv::ogl::mapGLBuffer,
    Arg("buffer"), Arg("access_flags") = static_cast<cv::AccessFlag>(cv::AccessFlag::ACCESS_READ | cv::AccessFlag::ACCESS_WRITE));
  
  rb_mCvOgl.define_module_function("unmap_gl_buffer", &cv::ogl::unmapGLBuffer,
    Arg("u"));
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  rb_mCvCuda.define_module_function("set_gl_device", &cv::cuda::setGlDevice,
    Arg("device") = static_cast<int>(0));

}