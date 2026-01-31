#include <opencv2/cudev/ptr2d/texture.hpp>
#include "texture-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T, typename R>
inline void TexturePtr_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cudev::TexturePtr<T, R>>()).
    define_constructor(Constructor<cv::cudev::TexturePtr<T, R>, const cudaTextureObject_t>(),
      Arg("tex_")).
    template define_method<R(cv::cudev::TexturePtr<T, R>::*)(typename cv::cudev::TexturePtr<T, R>::index_type, typename cv::cudev::TexturePtr<T, R>::index_type) const>("call", &cv::cudev::TexturePtr<T, R>::operator(),
      Arg("y"), Arg("x")).
    template define_method<R(cv::cudev::TexturePtr<T, R>::*)(typename cv::cudev::TexturePtr<T, R>::index_type) const>("call", &cv::cudev::TexturePtr<T, R>::operator(),
      Arg("x"));
};

template<typename Data_Type_T, typename T, typename R>
inline void TextureOffPtr_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cudev::TextureOffPtr<T, R>, const cudaTextureObject_t, const int, const int>(),
      Arg("tex_"), Arg("yoff_"), Arg("xoff_")).
    template define_method<R(cv::cudev::TextureOffPtr<T, R>::*)(typename cv::cudev::TextureOffPtr<T, R>::index_type, typename cv::cudev::TextureOffPtr<T, R>::index_type) const>("call", &cv::cudev::TextureOffPtr<T, R>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename T, typename R>
inline void UniqueTexture_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cudev::UniqueTexture<T, R>>()).
    define_constructor(Constructor<cv::cudev::UniqueTexture<T, R>, const int, const int, T*, const size_t, const bool, const cudaTextureFilterMode, const cudaTextureAddressMode, const cudaTextureReadMode>(),
      Arg("rows"), Arg("cols"), std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data"), Arg("step"), Arg("normalized_coords") = static_cast<const bool>(false), Arg("filter_mode") = static_cast<const cudaTextureFilterMode>(cudaTextureFilterMode::cudaFilterModePoint), Arg("address_mode") = static_cast<const cudaTextureAddressMode>(cudaTextureAddressMode::cudaAddressModeClamp), Arg("read_mode") = static_cast<const cudaTextureReadMode>(cudaTextureReadMode::cudaReadModeElementType)).
    define_constructor(Constructor<cv::cudev::UniqueTexture<T, R>, const size_t, T*, const bool, const cudaTextureFilterMode, const cudaTextureAddressMode, const cudaTextureReadMode>(),
      Arg("size_in_bytes"), std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data"), Arg("normalized_coords") = static_cast<const bool>(false), Arg("filter_mode") = static_cast<const cudaTextureFilterMode>(cudaTextureFilterMode::cudaFilterModePoint), Arg("address_mode") = static_cast<const cudaTextureAddressMode>(cudaTextureAddressMode::cudaAddressModeClamp), Arg("read_mode") = static_cast<const cudaTextureReadMode>(cudaTextureReadMode::cudaReadModeElementType)).
    template define_method<cv::cudev::UniqueTexture<T, R>&(cv::cudev::UniqueTexture<T, R>::*)(cv::cudev::UniqueTexture<T, R>&&) noexcept>("assign", &cv::cudev::UniqueTexture<T, R>::operator=,
      Arg("other")).
    template define_method<cudaTextureObject_t(cv::cudev::UniqueTexture<T, R>::*)() const noexcept>("get", &cv::cudev::UniqueTexture<T, R>::get).
    define_method("to_bool", [](const cv::cudev::UniqueTexture<T, R>& self) -> bool
    {
      return self;
    });
};

template<typename Data_Type_T, typename T, typename R>
inline void Texture_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cudev::Texture<T, R>>()).
    define_constructor(Constructor<cv::cudev::Texture<T, R>, const cv::cudev::Texture<T, R>&>(),
      Arg("arg_0")).
    define_constructor(Constructor<cv::cudev::Texture<T, R>, const int, const int, T*, const size_t, const bool, const cudaTextureFilterMode, const cudaTextureAddressMode, const cudaTextureReadMode>(),
      Arg("rows_"), Arg("cols_"), std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data"), Arg("step"), Arg("normalized_coords") = static_cast<const bool>(false), Arg("filter_mode") = static_cast<const cudaTextureFilterMode>(cudaTextureFilterMode::cudaFilterModePoint), Arg("address_mode") = static_cast<const cudaTextureAddressMode>(cudaTextureAddressMode::cudaAddressModeClamp), Arg("read_mode") = static_cast<const cudaTextureReadMode>(cudaTextureReadMode::cudaReadModeElementType)).
    define_constructor(Constructor<cv::cudev::Texture<T, R>, const size_t, T*, const bool, const cudaTextureFilterMode, const cudaTextureAddressMode, const cudaTextureReadMode>(),
      Arg("size_in_bytes"), std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data"), Arg("normalized_coords") = static_cast<const bool>(false), Arg("filter_mode") = static_cast<const cudaTextureFilterMode>(cudaTextureFilterMode::cudaFilterModePoint), Arg("address_mode") = static_cast<const cudaTextureAddressMode>(cudaTextureAddressMode::cudaAddressModeClamp), Arg("read_mode") = static_cast<const cudaTextureReadMode>(cudaTextureReadMode::cudaReadModeElementType)).
    define_constructor(Constructor<cv::cudev::Texture<T, R>, cv::cuda::PtrStepSz<T>, const bool, const cudaTextureFilterMode, const cudaTextureAddressMode, const cudaTextureReadMode>(),
      Arg("src"), Arg("normalized_coords") = static_cast<const bool>(false), Arg("filter_mode") = static_cast<const cudaTextureFilterMode>(cudaTextureFilterMode::cudaFilterModePoint), Arg("address_mode") = static_cast<const cudaTextureAddressMode>(cudaTextureAddressMode::cudaAddressModeClamp), Arg("read_mode") = static_cast<const cudaTextureReadMode>(cudaTextureReadMode::cudaReadModeElementType)).
    template define_method<cv::cudev::Texture<T, R>&(cv::cudev::Texture<T, R>::*)(const cv::cudev::Texture<T, R>&)>("assign", &cv::cudev::Texture<T, R>::operator=,
      Arg("arg_0")).
    template define_method<cv::cudev::Texture<T, R>&(cv::cudev::Texture<T, R>::*)(cv::cudev::Texture<T, R>&&)>("assign", &cv::cudev::Texture<T, R>::operator=,
      Arg("arg_0")).
    define_method("to_bool", [](const cv::cudev::Texture<T, R>& self) -> bool
    {
      return self;
    }).
    define_attr("rows", &cv::cudev::Texture<T, R>::rows).
    define_attr("cols", &cv::cudev::Texture<T, R>::cols);
};

template<typename Data_Type_T, typename T, typename R>
inline void TextureOff_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::cudev::TextureOff<T, R>, const cv::cudev::TextureOff<T, R>&>(),
      Arg("arg_0")).
    define_constructor(Constructor<cv::cudev::TextureOff<T, R>, const int, const int, T*, const size_t, const int, const int, const bool, const cudaTextureFilterMode, const cudaTextureAddressMode, const cudaTextureReadMode>(),
      Arg("rows"), Arg("cols"), std::conditional_t<std::is_fundamental_v<T>, ArgBuffer, Arg>("data"), Arg("step"), Arg("yoff_") = static_cast<const int>(0), Arg("xoff_") = static_cast<const int>(0), Arg("normalized_coords") = static_cast<const bool>(false), Arg("filter_mode") = static_cast<const cudaTextureFilterMode>(cudaTextureFilterMode::cudaFilterModePoint), Arg("address_mode") = static_cast<const cudaTextureAddressMode>(cudaTextureAddressMode::cudaAddressModeClamp), Arg("read_mode") = static_cast<const cudaTextureReadMode>(cudaTextureReadMode::cudaReadModeElementType)).
    define_constructor(Constructor<cv::cudev::TextureOff<T, R>, cv::cuda::PtrStepSz<T>, const int, const int, const bool, const cudaTextureFilterMode, const cudaTextureAddressMode, const cudaTextureReadMode>(),
      Arg("src"), Arg("yoff_") = static_cast<const int>(0), Arg("xoff_") = static_cast<const int>(0), Arg("normalized_coords") = static_cast<const bool>(false), Arg("filter_mode") = static_cast<const cudaTextureFilterMode>(cudaTextureFilterMode::cudaFilterModePoint), Arg("address_mode") = static_cast<const cudaTextureAddressMode>(cudaTextureAddressMode::cudaAddressModeClamp), Arg("read_mode") = static_cast<const cudaTextureReadMode>(cudaTextureReadMode::cudaReadModeElementType)).
    template define_method<cv::cudev::TextureOff<T, R>&(cv::cudev::TextureOff<T, R>::*)(const cv::cudev::TextureOff<T, R>&)>("assign", &cv::cudev::TextureOff<T, R>::operator=,
      Arg("arg_0")).
    template define_method<cv::cudev::TextureOff<T, R>&(cv::cudev::TextureOff<T, R>::*)(cv::cudev::TextureOff<T, R>&&)>("assign", &cv::cudev::TextureOff<T, R>::operator=,
      Arg("arg_0"));
};

