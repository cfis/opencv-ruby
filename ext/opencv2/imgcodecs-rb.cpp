#include <opencv2/imgcodecs.hpp>
#include "../opencv_ruby_version.hpp"
#include "imgcodecs-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvImageCollection;
Rice::Class rb_cCvImageCollectionIterator;

void Init_Imgcodecs()
{
  Module rb_mCv = define_module("Cv");
  
  Enum<cv::ImreadModes> rb_cCvImreadModes = define_enum_under<cv::ImreadModes>("ImreadModes", rb_mCv).
    define_value("IMREAD_UNCHANGED", cv::ImreadModes::IMREAD_UNCHANGED).
    define_value("IMREAD_GRAYSCALE", cv::ImreadModes::IMREAD_GRAYSCALE).
    define_value("IMREAD_COLOR", cv::ImreadModes::IMREAD_COLOR).
    define_value("IMREAD_ANYDEPTH", cv::ImreadModes::IMREAD_ANYDEPTH).
    define_value("IMREAD_ANYCOLOR", cv::ImreadModes::IMREAD_ANYCOLOR).
    define_value("IMREAD_LOAD_GDAL", cv::ImreadModes::IMREAD_LOAD_GDAL).
    define_value("IMREAD_REDUCED_GRAYSCALE_2", cv::ImreadModes::IMREAD_REDUCED_GRAYSCALE_2).
    define_value("IMREAD_REDUCED_COLOR_2", cv::ImreadModes::IMREAD_REDUCED_COLOR_2).
    define_value("IMREAD_REDUCED_GRAYSCALE_4", cv::ImreadModes::IMREAD_REDUCED_GRAYSCALE_4).
    define_value("IMREAD_REDUCED_COLOR_4", cv::ImreadModes::IMREAD_REDUCED_COLOR_4).
    define_value("IMREAD_REDUCED_GRAYSCALE_8", cv::ImreadModes::IMREAD_REDUCED_GRAYSCALE_8).
    define_value("IMREAD_REDUCED_COLOR_8", cv::ImreadModes::IMREAD_REDUCED_COLOR_8).
    define_value("IMREAD_IGNORE_ORIENTATION", cv::ImreadModes::IMREAD_IGNORE_ORIENTATION);
  
  Enum<cv::ImwriteFlags> rb_cCvImwriteFlags = define_enum_under<cv::ImwriteFlags>("ImwriteFlags", rb_mCv).
    define_value("IMWRITE_JPEG_QUALITY", cv::ImwriteFlags::IMWRITE_JPEG_QUALITY).
    define_value("IMWRITE_JPEG_PROGRESSIVE", cv::ImwriteFlags::IMWRITE_JPEG_PROGRESSIVE).
    define_value("IMWRITE_JPEG_OPTIMIZE", cv::ImwriteFlags::IMWRITE_JPEG_OPTIMIZE).
    define_value("IMWRITE_JPEG_RST_INTERVAL", cv::ImwriteFlags::IMWRITE_JPEG_RST_INTERVAL).
    define_value("IMWRITE_JPEG_LUMA_QUALITY", cv::ImwriteFlags::IMWRITE_JPEG_LUMA_QUALITY).
    define_value("IMWRITE_JPEG_CHROMA_QUALITY", cv::ImwriteFlags::IMWRITE_JPEG_CHROMA_QUALITY).
    define_value("IMWRITE_PNG_COMPRESSION", cv::ImwriteFlags::IMWRITE_PNG_COMPRESSION).
    define_value("IMWRITE_PNG_STRATEGY", cv::ImwriteFlags::IMWRITE_PNG_STRATEGY).
    define_value("IMWRITE_PNG_BILEVEL", cv::ImwriteFlags::IMWRITE_PNG_BILEVEL).
    define_value("IMWRITE_PXM_BINARY", cv::ImwriteFlags::IMWRITE_PXM_BINARY).
    define_value("IMWRITE_EXR_TYPE", cv::ImwriteFlags::IMWRITE_EXR_TYPE).
    define_value("IMWRITE_EXR_COMPRESSION", cv::ImwriteFlags::IMWRITE_EXR_COMPRESSION).
    define_value("IMWRITE_WEBP_QUALITY", cv::ImwriteFlags::IMWRITE_WEBP_QUALITY).
    define_value("IMWRITE_PAM_TUPLETYPE", cv::ImwriteFlags::IMWRITE_PAM_TUPLETYPE).
    define_value("IMWRITE_TIFF_RESUNIT", cv::ImwriteFlags::IMWRITE_TIFF_RESUNIT).
    define_value("IMWRITE_TIFF_XDPI", cv::ImwriteFlags::IMWRITE_TIFF_XDPI).
    define_value("IMWRITE_TIFF_YDPI", cv::ImwriteFlags::IMWRITE_TIFF_YDPI).
    define_value("IMWRITE_TIFF_COMPRESSION", cv::ImwriteFlags::IMWRITE_TIFF_COMPRESSION).
    define_value("IMWRITE_JPEG2000_COMPRESSION_X1000", cv::ImwriteFlags::IMWRITE_JPEG2000_COMPRESSION_X1000);

#if RUBY_CV_VERSION >= 407
  rb_cCvImwriteFlags.
    define_value("IMWRITE_JPEG_SAMPLING_FACTOR", cv::ImwriteFlags::IMWRITE_JPEG_SAMPLING_FACTOR).
    define_value("IMWRITE_EXR_DWA_COMPRESSION_LEVEL", cv::ImwriteFlags::IMWRITE_EXR_DWA_COMPRESSION_LEVEL).
    define_value("IMWRITE_HDR_COMPRESSION", cv::ImwriteFlags::IMWRITE_HDR_COMPRESSION).
    define_value("IMWRITE_TIFF_ROWSPERSTRIP", cv::ImwriteFlags::IMWRITE_TIFF_ROWSPERSTRIP);
#endif 

#if RUBY_CV_VERSION >= 410
  rb_cCvImwriteFlags.
    define_value("IMWRITE_TIFF_PREDICTOR", cv::ImwriteFlags::IMWRITE_TIFF_PREDICTOR).
    define_value("IMWRITE_AVIF_QUALITY", cv::ImwriteFlags::IMWRITE_AVIF_QUALITY).
    define_value("IMWRITE_AVIF_DEPTH", cv::ImwriteFlags::IMWRITE_AVIF_DEPTH).
    define_value("IMWRITE_AVIF_SPEED", cv::ImwriteFlags::IMWRITE_AVIF_SPEED);
#endif
  
#if RUBY_CV_VERSION >= 407
  Enum<cv::ImwriteJPEGSamplingFactorParams> rb_cCvImwriteJPEGSamplingFactorParams = define_enum_under<cv::ImwriteJPEGSamplingFactorParams>("ImwriteJPEGSamplingFactorParams", rb_mCv).
    define_value("IMWRITE_JPEG_SAMPLING_FACTOR_411", cv::ImwriteJPEGSamplingFactorParams::IMWRITE_JPEG_SAMPLING_FACTOR_411).
    define_value("IMWRITE_JPEG_SAMPLING_FACTOR_420", cv::ImwriteJPEGSamplingFactorParams::IMWRITE_JPEG_SAMPLING_FACTOR_420).
    define_value("IMWRITE_JPEG_SAMPLING_FACTOR_422", cv::ImwriteJPEGSamplingFactorParams::IMWRITE_JPEG_SAMPLING_FACTOR_422).
    define_value("IMWRITE_JPEG_SAMPLING_FACTOR_440", cv::ImwriteJPEGSamplingFactorParams::IMWRITE_JPEG_SAMPLING_FACTOR_440).
    define_value("IMWRITE_JPEG_SAMPLING_FACTOR_444", cv::ImwriteJPEGSamplingFactorParams::IMWRITE_JPEG_SAMPLING_FACTOR_444);
#endif

#if RUBY_CV_VERSION >= 410
  Enum<cv::ImwriteTiffCompressionFlags> rb_cCvImwriteTiffCompressionFlags = define_enum_under<cv::ImwriteTiffCompressionFlags>("ImwriteTiffCompressionFlags", rb_mCv).
    define_value("IMWRITE_TIFF_COMPRESSION_NONE", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_NONE).
    define_value("IMWRITE_TIFF_COMPRESSION_CCITTRLE", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_CCITTRLE).
    define_value("IMWRITE_TIFF_COMPRESSION_CCITTFAX3", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_CCITTFAX3).
    define_value("IMWRITE_TIFF_COMPRESSION_CCITT_T4", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_CCITT_T4).
    define_value("IMWRITE_TIFF_COMPRESSION_CCITTFAX4", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_CCITTFAX4).
    define_value("IMWRITE_TIFF_COMPRESSION_CCITT_T6", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_CCITT_T6).
    define_value("IMWRITE_TIFF_COMPRESSION_LZW", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_LZW).
    define_value("IMWRITE_TIFF_COMPRESSION_OJPEG", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_OJPEG).
    define_value("IMWRITE_TIFF_COMPRESSION_JPEG", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_JPEG).
    define_value("IMWRITE_TIFF_COMPRESSION_T85", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_T85).
    define_value("IMWRITE_TIFF_COMPRESSION_T43", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_T43).
    define_value("IMWRITE_TIFF_COMPRESSION_NEXT", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_NEXT).
    define_value("IMWRITE_TIFF_COMPRESSION_CCITTRLEW", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_CCITTRLEW).
    define_value("IMWRITE_TIFF_COMPRESSION_PACKBITS", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_PACKBITS).
    define_value("IMWRITE_TIFF_COMPRESSION_THUNDERSCAN", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_THUNDERSCAN).
    define_value("IMWRITE_TIFF_COMPRESSION_IT8CTPAD", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_IT8CTPAD).
    define_value("IMWRITE_TIFF_COMPRESSION_IT8LW", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_IT8LW).
    define_value("IMWRITE_TIFF_COMPRESSION_IT8MP", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_IT8MP).
    define_value("IMWRITE_TIFF_COMPRESSION_IT8BL", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_IT8BL).
    define_value("IMWRITE_TIFF_COMPRESSION_PIXARFILM", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_PIXARFILM).
    define_value("IMWRITE_TIFF_COMPRESSION_PIXARLOG", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_PIXARLOG).
    define_value("IMWRITE_TIFF_COMPRESSION_DEFLATE", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_DEFLATE).
    define_value("IMWRITE_TIFF_COMPRESSION_ADOBE_DEFLATE", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_ADOBE_DEFLATE).
    define_value("IMWRITE_TIFF_COMPRESSION_DCS", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_DCS).
    define_value("IMWRITE_TIFF_COMPRESSION_JBIG", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_JBIG).
    define_value("IMWRITE_TIFF_COMPRESSION_SGILOG", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_SGILOG).
    define_value("IMWRITE_TIFF_COMPRESSION_SGILOG24", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_SGILOG24).
    define_value("IMWRITE_TIFF_COMPRESSION_JP2000", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_JP2000).
    define_value("IMWRITE_TIFF_COMPRESSION_LERC", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_LERC).
    define_value("IMWRITE_TIFF_COMPRESSION_LZMA", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_LZMA).
    define_value("IMWRITE_TIFF_COMPRESSION_ZSTD", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_ZSTD).
    define_value("IMWRITE_TIFF_COMPRESSION_WEBP", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_WEBP).
    define_value("IMWRITE_TIFF_COMPRESSION_JXL", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_JXL);
  
  Enum<cv::ImwriteTiffPredictorFlags> rb_cCvImwriteTiffPredictorFlags = define_enum_under<cv::ImwriteTiffPredictorFlags>("ImwriteTiffPredictorFlags", rb_mCv).
    define_value("IMWRITE_TIFF_PREDICTOR_NONE", cv::ImwriteTiffPredictorFlags::IMWRITE_TIFF_PREDICTOR_NONE).
    define_value("IMWRITE_TIFF_PREDICTOR_HORIZONTAL", cv::ImwriteTiffPredictorFlags::IMWRITE_TIFF_PREDICTOR_HORIZONTAL).
    define_value("IMWRITE_TIFF_PREDICTOR_FLOATINGPOINT", cv::ImwriteTiffPredictorFlags::IMWRITE_TIFF_PREDICTOR_FLOATINGPOINT);
#endif

  Enum<cv::ImwriteEXRTypeFlags> rb_cCvImwriteEXRTypeFlags = define_enum_under<cv::ImwriteEXRTypeFlags>("ImwriteEXRTypeFlags", rb_mCv).
    define_value("IMWRITE_EXR_TYPE_HALF", cv::ImwriteEXRTypeFlags::IMWRITE_EXR_TYPE_HALF).
    define_value("IMWRITE_EXR_TYPE_FLOAT", cv::ImwriteEXRTypeFlags::IMWRITE_EXR_TYPE_FLOAT);
  
  Enum<cv::ImwriteEXRCompressionFlags> rb_cCvImwriteEXRCompressionFlags = define_enum_under<cv::ImwriteEXRCompressionFlags>("ImwriteEXRCompressionFlags", rb_mCv).
    define_value("IMWRITE_EXR_COMPRESSION_NO", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_NO).
    define_value("IMWRITE_EXR_COMPRESSION_RLE", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_RLE).
    define_value("IMWRITE_EXR_COMPRESSION_ZIPS", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_ZIPS).
    define_value("IMWRITE_EXR_COMPRESSION_ZIP", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_ZIP).
    define_value("IMWRITE_EXR_COMPRESSION_PIZ", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_PIZ).
    define_value("IMWRITE_EXR_COMPRESSION_PXR24", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_PXR24).
    define_value("IMWRITE_EXR_COMPRESSION_B44", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_B44).
    define_value("IMWRITE_EXR_COMPRESSION_B44A", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_B44A).
    define_value("IMWRITE_EXR_COMPRESSION_DWAA", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_DWAA).
    define_value("IMWRITE_EXR_COMPRESSION_DWAB", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_DWAB);
  
  Enum<cv::ImwritePNGFlags> rb_cCvImwritePNGFlags = define_enum_under<cv::ImwritePNGFlags>("ImwritePNGFlags", rb_mCv).
    define_value("IMWRITE_PNG_STRATEGY_DEFAULT", cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_DEFAULT).
    define_value("IMWRITE_PNG_STRATEGY_FILTERED", cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_FILTERED).
    define_value("IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY", cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY).
    define_value("IMWRITE_PNG_STRATEGY_RLE", cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_RLE).
    define_value("IMWRITE_PNG_STRATEGY_FIXED", cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_FIXED);
  
  Enum<cv::ImwritePAMFlags> rb_cCvImwritePAMFlags = define_enum_under<cv::ImwritePAMFlags>("ImwritePAMFlags", rb_mCv).
    define_value("IMWRITE_PAM_FORMAT_NULL", cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_NULL).
    define_value("IMWRITE_PAM_FORMAT_BLACKANDWHITE", cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_BLACKANDWHITE).
    define_value("IMWRITE_PAM_FORMAT_GRAYSCALE", cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_GRAYSCALE).
    define_value("IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA", cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA).
    define_value("IMWRITE_PAM_FORMAT_RGB", cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_RGB).
    define_value("IMWRITE_PAM_FORMAT_RGB_ALPHA", cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_RGB_ALPHA);
  
#if RUBY_CV_VERSION >= 407
  Enum<cv::ImwriteHDRCompressionFlags> rb_cCvImwriteHDRCompressionFlags = define_enum_under<cv::ImwriteHDRCompressionFlags>("ImwriteHDRCompressionFlags", rb_mCv).
    define_value("IMWRITE_HDR_COMPRESSION_NONE", cv::ImwriteHDRCompressionFlags::IMWRITE_HDR_COMPRESSION_NONE).
    define_value("IMWRITE_HDR_COMPRESSION_RLE", cv::ImwriteHDRCompressionFlags::IMWRITE_HDR_COMPRESSION_RLE);
#endif

  rb_mCv.define_module_function<cv::Mat(*)(const cv::String&, int)>("imread", &cv::imread,
    Arg("filename"), Arg("flags") = static_cast<int>(cv::ImreadModes::IMREAD_COLOR));
  
#if RUBY_CV_VERSION >= 410
  rb_mCv.define_module_function<void(*)(const cv::String&, cv::OutputArray, int)>("imread", &cv::imread,
    Arg("filename"), Arg("dst"), Arg("flags") = static_cast<int>(cv::ImreadModes::IMREAD_COLOR));
#endif

  rb_mCv.define_module_function<bool(*)(const cv::String&, std::vector<cv::Mat>&, int)>("imreadmulti", &cv::imreadmulti,
    Arg("filename"), Arg("mats"), Arg("flags") = static_cast<int>(cv::ImreadModes::IMREAD_ANYCOLOR));
  
  rb_mCv.define_module_function<bool(*)(const cv::String&, std::vector<cv::Mat>&, int, int, int)>("imreadmulti", &cv::imreadmulti,
    Arg("filename"), Arg("mats"), Arg("start"), Arg("count"), Arg("flags") = static_cast<int>(cv::ImreadModes::IMREAD_ANYCOLOR));
  
  rb_mCv.define_module_function("imcount", &cv::imcount,
    Arg("filename"), Arg("flags") = static_cast<int>(cv::ImreadModes::IMREAD_ANYCOLOR));
  
  rb_mCv.define_module_function("imwrite", &cv::imwrite,
    Arg("filename"), Arg("img"), Arg("params") = static_cast<const std::vector<int> &>(std::vector<int>()));
  
  rb_mCv.define_module_function("imwritemulti", &cv::imwritemulti,
    Arg("filename"), Arg("img"), Arg("params") = static_cast<const std::vector<int> &>(std::vector<int>()));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, int)>("imdecode", &cv::imdecode,
    Arg("buf"), Arg("flags"));
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, int, cv::Mat*)>("imdecode", &cv::imdecode,
    Arg("buf"), Arg("flags"), Arg("dst"));
  
#if RUBY_CV_VERSION >= 409
  rb_mCv.define_module_function("imdecodemulti", &cv::imdecodemulti,
    Arg("buf"), Arg("flags"), Arg("mats"), Arg("range") = static_cast<const cv::Range &>(cv::Range::all()));
#endif

  rb_mCv.define_module_function("imencode", &cv::imencode,
    Arg("ext"), Arg("img"), Arg("buf"), Arg("params") = static_cast<const std::vector<int> &>(std::vector<int>()));
  
  rb_mCv.define_module_function("have_image_reader?", &cv::haveImageReader,
    Arg("filename"));
  
  rb_mCv.define_module_function("have_image_writer?", &cv::haveImageWriter,
    Arg("filename"));
  
#if RUBY_CV_VERSION >= 407
  rb_cCvImageCollection = define_class_under<cv::ImageCollection>(rb_mCv, "ImageCollection").
    define_constructor(Constructor<cv::ImageCollection>()).
    define_constructor(Constructor<cv::ImageCollection, const cv::String&, int>(),
      Arg("filename"), Arg("flags")).
    define_method("init", &cv::ImageCollection::init,
      Arg("img"), Arg("flags")).
    define_method("size", &cv::ImageCollection::size).
    define_method("at", &cv::ImageCollection::at,
      Arg("index")).
    define_method("[]", &cv::ImageCollection::operator[],
      Arg("index")).
    define_method("release_cache", &cv::ImageCollection::releaseCache,
      Arg("index"));
    //define_iterator<cv::ImageCollection::iterator(cv::ImageCollection::*)()>(&cv::ImageCollection::begin, &cv::ImageCollection::end, "each").
   // define_method("get_impl", &cv::ImageCollection::getImpl);
    
  rb_cCvImageCollectionIterator = define_class_under<cv::ImageCollection::iterator>(rb_cCvImageCollection, "Iterator").
    define_constructor(Constructor<cv::ImageCollection::iterator, cv::ImageCollection*>(),
      Arg("col")).
    define_constructor(Constructor<cv::ImageCollection::iterator, cv::ImageCollection*, int>(),
      Arg("col"), Arg("end")).
    define_method("dereference", &cv::ImageCollection::iterator::operator*).
    define_method("->", &cv::ImageCollection::iterator::operator->).
    define_method<cv::ImageCollection::iterator&(cv::ImageCollection::iterator::*)()>("increment", &cv::ImageCollection::iterator::operator++).
    define_method<cv::ImageCollection::iterator(cv::ImageCollection::iterator::*)(int)>("increment", &cv::ImageCollection::iterator::operator++,
      Arg(""));
#endif
}