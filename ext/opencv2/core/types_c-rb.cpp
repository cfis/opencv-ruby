#include <opencv2/core/types_c.h>
#include "types_c-rb.hpp"

using namespace Rice;

void Init_Core_TypesC()
{
  Class(rb_cObject).define_constant("CV_RNG_COEFF", CV_RNG_COEFF);

  Class(rb_cObject).define_constant("IPL_DEPTH_SIGN", IPL_DEPTH_SIGN);

  Class(rb_cObject).define_constant("IPL_DEPTH_1U", IPL_DEPTH_1U);

  Class(rb_cObject).define_constant("IPL_DEPTH_8U", IPL_DEPTH_8U);

  Class(rb_cObject).define_constant("IPL_DEPTH_16U", IPL_DEPTH_16U);

  Class(rb_cObject).define_constant("IPL_DEPTH_32F", IPL_DEPTH_32F);

  Class(rb_cObject).define_constant("IPL_DATA_ORDER_PIXEL", IPL_DATA_ORDER_PIXEL);

  Class(rb_cObject).define_constant("IPL_DATA_ORDER_PLANE", IPL_DATA_ORDER_PLANE);

  Class(rb_cObject).define_constant("IPL_ORIGIN_TL", IPL_ORIGIN_TL);

  Class(rb_cObject).define_constant("IPL_ORIGIN_BL", IPL_ORIGIN_BL);

  Class(rb_cObject).define_constant("IPL_ALIGN_4BYTES", IPL_ALIGN_4BYTES);

  Class(rb_cObject).define_constant("IPL_ALIGN_8BYTES", IPL_ALIGN_8BYTES);

  Class(rb_cObject).define_constant("IPL_ALIGN_16BYTES", IPL_ALIGN_16BYTES);

  Class(rb_cObject).define_constant("IPL_ALIGN_32BYTES", IPL_ALIGN_32BYTES);

  Class(rb_cObject).define_constant("IPL_BORDER_CONSTANT", IPL_BORDER_CONSTANT);

  Class(rb_cObject).define_constant("IPL_BORDER_REPLICATE", IPL_BORDER_REPLICATE);

  Class(rb_cObject).define_constant("IPL_BORDER_REFLECT", IPL_BORDER_REFLECT);

  Class(rb_cObject).define_constant("IPL_BORDER_WRAP", IPL_BORDER_WRAP);

  Class(rb_cObject).define_constant("IPL_IMAGE_HEADER", IPL_IMAGE_HEADER);

  Class(rb_cObject).define_constant("IPL_IMAGE_DATA", IPL_IMAGE_DATA);

  Class(rb_cObject).define_constant("IPL_IMAGE_ROI", IPL_IMAGE_ROI);

  Class(rb_cObject).define_constant("IPL_BORDER_REFLECT_101", IPL_BORDER_REFLECT_101);

  Class(rb_cObject).define_constant("IPL_BORDER_TRANSPARENT", IPL_BORDER_TRANSPARENT);

  Class(rb_cObject).define_constant("CV_TYPE_NAME_IMAGE", CV_TYPE_NAME_IMAGE);

  Class(rb_cObject).define_constant("IPL_DEPTH_64F", IPL_DEPTH_64F);

  Class(rb_cObject).define_constant("CV_AUTO_STEP", CV_AUTO_STEP);

  Class(rb_cObject).define_constant("CV_MAGIC_MASK", CV_MAGIC_MASK);

  Class(rb_cObject).define_constant("CV_MAT_MAGIC_VAL", CV_MAT_MAGIC_VAL);

  Class(rb_cObject).define_constant("CV_TYPE_NAME_MAT", CV_TYPE_NAME_MAT);

  Class(rb_cObject).define_constant("CV_MATND_MAGIC_VAL", CV_MATND_MAGIC_VAL);

  Class(rb_cObject).define_constant("CV_TYPE_NAME_MATND", CV_TYPE_NAME_MATND);

  Class(rb_cObject).define_constant("CV_SPARSE_MAT_MAGIC_VAL", CV_SPARSE_MAT_MAGIC_VAL);

  Class(rb_cObject).define_constant("CV_TYPE_NAME_SPARSE_MAT", CV_TYPE_NAME_SPARSE_MAT);

  Class(rb_cObject).define_constant("CV_HIST_MAGIC_VAL", CV_HIST_MAGIC_VAL);

  Class(rb_cObject).define_constant("CV_HIST_ARRAY", CV_HIST_ARRAY);

  Class(rb_cObject).define_constant("CV_HIST_SPARSE", CV_HIST_SPARSE);

  Class(rb_cObject).define_constant("CV_HIST_UNIFORM", CV_HIST_UNIFORM);

  Class(rb_cObject).define_constant("CV_TERMCRIT_ITER", CV_TERMCRIT_ITER);

  Class(rb_cObject).define_constant("CV_TERMCRIT_EPS", CV_TERMCRIT_EPS);

  Class(rb_cObject).define_constant("CV_WHOLE_SEQ_END_INDEX", CV_WHOLE_SEQ_END_INDEX);

  Class(rb_cObject).define_constant("CV_STORAGE_MAGIC_VAL", CV_STORAGE_MAGIC_VAL);

  Class(rb_cObject).define_constant("CV_TYPE_NAME_SEQ", CV_TYPE_NAME_SEQ);

  Class(rb_cObject).define_constant("CV_TYPE_NAME_SEQ_TREE", CV_TYPE_NAME_SEQ_TREE);

  Class(rb_cObject).define_constant("CV_TYPE_NAME_GRAPH", CV_TYPE_NAME_GRAPH);

  Class(rb_cObject).define_constant("CV_SEQ_MAGIC_VAL", CV_SEQ_MAGIC_VAL);

  Class(rb_cObject).define_constant("CV_SET_MAGIC_VAL", CV_SET_MAGIC_VAL);

  Class(rb_cObject).define_constant("CV_SEQ_ELTYPE_BITS", CV_SEQ_ELTYPE_BITS);

  Class(rb_cObject).define_constant("CV_SEQ_ELTYPE_GENERIC", CV_SEQ_ELTYPE_GENERIC);

  Class(rb_cObject).define_constant("CV_SEQ_ELTYPE_GRAPH_EDGE", CV_SEQ_ELTYPE_GRAPH_EDGE);

  Class(rb_cObject).define_constant("CV_SEQ_ELTYPE_GRAPH_VERTEX", CV_SEQ_ELTYPE_GRAPH_VERTEX);

  Class(rb_cObject).define_constant("CV_SEQ_ELTYPE_TRIAN_ATR", CV_SEQ_ELTYPE_TRIAN_ATR);

  Class(rb_cObject).define_constant("CV_SEQ_ELTYPE_CONNECTED_COMP", CV_SEQ_ELTYPE_CONNECTED_COMP);

  Class(rb_cObject).define_constant("CV_SEQ_KIND_BITS", CV_SEQ_KIND_BITS);

  Class(rb_cObject).define_constant("CV_StsOk", (int)::CV_StsOk);
  Class(rb_cObject).define_constant("CV_StsBackTrace", (int)::CV_StsBackTrace);
  Class(rb_cObject).define_constant("CV_StsError", (int)::CV_StsError);
  Class(rb_cObject).define_constant("CV_StsInternal", (int)::CV_StsInternal);
  Class(rb_cObject).define_constant("CV_StsNoMem", (int)::CV_StsNoMem);
  Class(rb_cObject).define_constant("CV_StsBadArg", (int)::CV_StsBadArg);
  Class(rb_cObject).define_constant("CV_StsBadFunc", (int)::CV_StsBadFunc);
  Class(rb_cObject).define_constant("CV_StsNoConv", (int)::CV_StsNoConv);
  Class(rb_cObject).define_constant("CV_StsAutoTrace", (int)::CV_StsAutoTrace);
  Class(rb_cObject).define_constant("CV_HeaderIsNull", (int)::CV_HeaderIsNull);
  Class(rb_cObject).define_constant("CV_BadImageSize", (int)::CV_BadImageSize);
  Class(rb_cObject).define_constant("CV_BadOffset", (int)::CV_BadOffset);
  Class(rb_cObject).define_constant("CV_BadDataPtr", (int)::CV_BadDataPtr);
  Class(rb_cObject).define_constant("CV_BadStep", (int)::CV_BadStep);
  Class(rb_cObject).define_constant("CV_BadModelOrChSeq", (int)::CV_BadModelOrChSeq);
  Class(rb_cObject).define_constant("CV_BadNumChannels", (int)::CV_BadNumChannels);
  Class(rb_cObject).define_constant("CV_BadNumChannel1U", (int)::CV_BadNumChannel1U);
  Class(rb_cObject).define_constant("CV_BadDepth", (int)::CV_BadDepth);
  Class(rb_cObject).define_constant("CV_BadAlphaChannel", (int)::CV_BadAlphaChannel);
  Class(rb_cObject).define_constant("CV_BadOrder", (int)::CV_BadOrder);
  Class(rb_cObject).define_constant("CV_BadOrigin", (int)::CV_BadOrigin);
  Class(rb_cObject).define_constant("CV_BadAlign", (int)::CV_BadAlign);
  Class(rb_cObject).define_constant("CV_BadCallBack", (int)::CV_BadCallBack);
  Class(rb_cObject).define_constant("CV_BadTileSize", (int)::CV_BadTileSize);
  Class(rb_cObject).define_constant("CV_BadCOI", (int)::CV_BadCOI);
  Class(rb_cObject).define_constant("CV_BadROISize", (int)::CV_BadROISize);
  Class(rb_cObject).define_constant("CV_MaskIsTiled", (int)::CV_MaskIsTiled);
  Class(rb_cObject).define_constant("CV_StsNullPtr", (int)::CV_StsNullPtr);
  Class(rb_cObject).define_constant("CV_StsVecLengthErr", (int)::CV_StsVecLengthErr);
  Class(rb_cObject).define_constant("CV_StsFilterStructContentErr", (int)::CV_StsFilterStructContentErr);
  Class(rb_cObject).define_constant("CV_StsKernelStructContentErr", (int)::CV_StsKernelStructContentErr);
  Class(rb_cObject).define_constant("CV_StsFilterOffsetErr", (int)::CV_StsFilterOffsetErr);
  Class(rb_cObject).define_constant("CV_StsBadSize", (int)::CV_StsBadSize);
  Class(rb_cObject).define_constant("CV_StsDivByZero", (int)::CV_StsDivByZero);
  Class(rb_cObject).define_constant("CV_StsInplaceNotSupported", (int)::CV_StsInplaceNotSupported);
  Class(rb_cObject).define_constant("CV_StsObjectNotFound", (int)::CV_StsObjectNotFound);
  Class(rb_cObject).define_constant("CV_StsUnmatchedFormats", (int)::CV_StsUnmatchedFormats);
  Class(rb_cObject).define_constant("CV_StsBadFlag", (int)::CV_StsBadFlag);
  Class(rb_cObject).define_constant("CV_StsBadPoint", (int)::CV_StsBadPoint);
  Class(rb_cObject).define_constant("CV_StsBadMask", (int)::CV_StsBadMask);
  Class(rb_cObject).define_constant("CV_StsUnmatchedSizes", (int)::CV_StsUnmatchedSizes);
  Class(rb_cObject).define_constant("CV_StsUnsupportedFormat", (int)::CV_StsUnsupportedFormat);
  Class(rb_cObject).define_constant("CV_StsOutOfRange", (int)::CV_StsOutOfRange);
  Class(rb_cObject).define_constant("CV_StsParseError", (int)::CV_StsParseError);
  Class(rb_cObject).define_constant("CV_StsNotImplemented", (int)::CV_StsNotImplemented);
  Class(rb_cObject).define_constant("CV_StsBadMemBlock", (int)::CV_StsBadMemBlock);
  Class(rb_cObject).define_constant("CV_StsAssert", (int)::CV_StsAssert);
  Class(rb_cObject).define_constant("CV_GpuNotSupported", (int)::CV_GpuNotSupported);
  Class(rb_cObject).define_constant("CV_GpuApiCallError", (int)::CV_GpuApiCallError);
  Class(rb_cObject).define_constant("CV_OpenGlNotSupported", (int)::CV_OpenGlNotSupported);
  Class(rb_cObject).define_constant("CV_OpenGlApiCallError", (int)::CV_OpenGlApiCallError);
  Class(rb_cObject).define_constant("CV_OpenCLApiCallError", (int)::CV_OpenCLApiCallError);
  Class(rb_cObject).define_constant("CV_OpenCLDoubleNotSupported", (int)::CV_OpenCLDoubleNotSupported);
  Class(rb_cObject).define_constant("CV_OpenCLInitError", (int)::CV_OpenCLInitError);
  Class(rb_cObject).define_constant("CV_OpenCLNoAMDBlasFft", (int)::CV_OpenCLNoAMDBlasFft);

  define_global_function<CvRNG(*)(int64)>("cv_rng", &cvRNG,
    Arg("seed"));

  define_global_function<unsigned int(*)(CvRNG*)>("cv_rand_int", &cvRandInt,
    ArgBuffer("rng"));

  define_global_function<double(*)(CvRNG*)>("cv_rand_real", &cvRandReal,
    ArgBuffer("rng"));

  define_global_function<_IplImage(*)(const cv::Mat&)>("cv_ipl_image", &cvIplImage,
    Arg("m"));

  Rice::Data_Type<_IplImage> rb_cIplImage = define_class<_IplImage>("IplImage");

  Rice::Data_Type<_IplTileInfo> rb_cIplTileInfo = define_class_under<_IplTileInfo>(rb_cIplImage, "IplTileInfo");

  rb_cIplImage.
    define_constructor(Constructor<_IplImage>()).
    define_attr("n_size", &_IplImage::nSize).
    define_attr("id", &_IplImage::ID).
    define_attr("n_channels", &_IplImage::nChannels).
    define_attr("alpha_channel", &_IplImage::alphaChannel).
    define_attr("depth", &_IplImage::depth).
    define_attr("color_model", &_IplImage::colorModel, Rice::AttrAccess::Read).
    define_attr("channel_seq", &_IplImage::channelSeq, Rice::AttrAccess::Read).
    define_attr("data_order", &_IplImage::dataOrder).
    define_attr("origin", &_IplImage::origin).
    define_attr("align", &_IplImage::align).
    define_attr("width", &_IplImage::width).
    define_attr("height", &_IplImage::height).
    define_attr("roi", &_IplImage::roi).
    define_attr("mask_roi", &_IplImage::maskROI).
    define_attr("image_id", &_IplImage::imageId).
    define_attr("tile_info", &_IplImage::tileInfo).
    define_attr("image_size", &_IplImage::imageSize).
    define_attr("image_data", &_IplImage::imageData).
    define_attr("width_step", &_IplImage::widthStep).
    define_attr("border_mode", &_IplImage::BorderMode, Rice::AttrAccess::Read).
    define_attr("border_const", &_IplImage::BorderConst, Rice::AttrAccess::Read).
    define_attr("image_data_origin", &_IplImage::imageDataOrigin);

  Rice::Data_Type<_IplROI> rb_cIplROI = define_class<_IplROI>("IplROI").
    define_constructor(Constructor<_IplROI>());

  define_global_function<IplImage(*)()>("cv_ipl_image", &cvIplImage);

  Rice::Data_Type<_IplROI> rb_cIplROI = define_class<_IplROI>("IplROI").
    define_constructor(Constructor<_IplROI>()).
    define_attr("coi", &_IplROI::coi).
    define_attr("x_offset", &_IplROI::xOffset).
    define_attr("y_offset", &_IplROI::yOffset).
    define_attr("width", &_IplROI::width).
    define_attr("height", &_IplROI::height);

  Rice::Data_Type<_IplConvKernel> rb_cIplConvKernel = define_class<_IplConvKernel>("IplConvKernel").
    define_constructor(Constructor<_IplConvKernel>()).
    define_attr("n_cols", &_IplConvKernel::nCols).
    define_attr("n_rows", &_IplConvKernel::nRows).
    define_attr("anchor_x", &_IplConvKernel::anchorX).
    define_attr("anchor_y", &_IplConvKernel::anchorY).
    define_attr("values", &_IplConvKernel::values).
    define_attr("n_shift_r", &_IplConvKernel::nShiftR);

  Rice::Data_Type<_IplConvKernelFP> rb_cIplConvKernelFP = define_class<_IplConvKernelFP>("IplConvKernelFP").
    define_constructor(Constructor<_IplConvKernelFP>()).
    define_attr("n_cols", &_IplConvKernelFP::nCols).
    define_attr("n_rows", &_IplConvKernelFP::nRows).
    define_attr("anchor_x", &_IplConvKernelFP::anchorX).
    define_attr("anchor_y", &_IplConvKernelFP::anchorY).
    define_attr("values", &_IplConvKernelFP::values);

  define_global_function<CvMat(*)(const cv::Mat&)>("cv_mat", &cvMat,
    Arg("m"));

  Rice::Data_Type<CvMat> rb_cCvMat = define_class<CvMat>("CvMat").
    define_constructor(Constructor<CvMat>()).
    define_attr("type", &CvMat::type).
    define_attr("step", &CvMat::step).
    define_attr("refcount", &CvMat::refcount).
    define_attr("hdr_refcount", &CvMat::hdr_refcount).
    define_attr("data", &CvMat::data);

  define_global_function<CvMat(*)(int, int, int, void*)>("cv_mat", &cvMat,
    Arg("rows"), Arg("cols"), Arg("type"), ArgBuffer("data"));

  define_global_function<CvMat(*)(const cv::Mat&)>("cv_mat", &cvMat,
    Arg("m"));

  define_global_function<CvMat(*)()>("cv_mat", &cvMat);

  define_global_function<CvMat(*)(const CvMat&)>("cv_mat", &cvMat,
    Arg("m"));

  define_global_function<double(*)(const CvMat*, int, int)>("cvm_get", &cvmGet,
    Arg("mat"), Arg("row"), Arg("col"));

  define_global_function<void(*)(CvMat*, int, int, double)>("cvm_set", &cvmSet,
    Arg("mat"), Arg("row"), Arg("col"), Arg("value"));

  define_global_function<int(*)(int)>("cv_ipl_depth", &cvIplDepth,
    Arg("type"));

  define_global_function<CvMatND(*)(const cv::Mat&)>("cv_mat_nd", &cvMatND,
    Arg("m"));

  Rice::Data_Type<CvMatND> rb_cCvMatND = define_class<CvMatND>("CvMatND").
    define_constructor(Constructor<CvMatND>()).
    define_attr("type", &CvMatND::type).
    define_attr("dims", &CvMatND::dims).
    define_attr("refcount", &CvMatND::refcount).
    define_attr("hdr_refcount", &CvMatND::hdr_refcount).
    define_attr("data", &CvMatND::data).
    define_attr("dim", &CvMatND::dim, Rice::AttrAccess::Read);

  Rice::Data_Type<CvMatND::(unnamed struct at /mnt/c/Source/opencv-ruby/ext/build/msvc-debug/vcpkg_installed/x64-windows/include/opencv4/opencv2/core/types_c.h:690:5)> rb_cCvMatND(unnamedStructAt::Mnt::C::Source::OpencvRuby::Ext::Build::MsvcDebug::VcpkgInstalled::X64Windows::Include::Opencv4::Opencv2::Core::TypesCH:690:5) = define_class_under<CvMatND::(unnamed struct at /mnt/c/Source/opencv-ruby/ext/build/msvc-debug/vcpkg_installed/x64-windows/include/opencv4/opencv2/core/types_c.h:690:5)>(rb_cCvMatND, "(unnamedStructAt::Mnt::C::Source::OpencvRuby::Ext::Build::MsvcDebug::VcpkgInstalled::X64Windows::Include::Opencv4::Opencv2::Core::TypesCH:690:5)").
    define_constructor(Constructor<CvMatND::(unnamed struct at /mnt/c/Source/opencv-ruby/ext/build/msvc-debug/vcpkg_installed/x64-windows/include/opencv4/opencv2/core/types_c.h:690:5)>()).
    define_attr("size", &CvMatND::(unnamed struct at /mnt/c/Source/opencv-ruby/ext/build/msvc-debug/vcpkg_installed/x64-windows/include/opencv4/opencv2/core/types_c.h:690:5)::size).
    define_attr("step", &CvMatND::(unnamed struct at /mnt/c/Source/opencv-ruby/ext/build/msvc-debug/vcpkg_installed/x64-windows/include/opencv4/opencv2/core/types_c.h:690:5)::step);

  define_global_function<CvMatND(*)()>("cv_mat_nd", &cvMatND);

  Rice::Data_Type<CvSparseMat> rb_cCvSparseMat = define_class<CvSparseMat>("CvSparseMat").
    define_constructor(Constructor<CvSparseMat>()).
    define_attr("type", &CvSparseMat::type).
    define_attr("dims", &CvSparseMat::dims).
    define_attr("refcount", &CvSparseMat::refcount).
    define_attr("hdr_refcount", &CvSparseMat::hdr_refcount).
    define_attr("heap", &CvSparseMat::heap).
    define_attr("hashtable", &CvSparseMat::hashtable).
    define_attr("hashsize", &CvSparseMat::hashsize).
    define_attr("valoffset", &CvSparseMat::valoffset).
    define_attr("idxoffset", &CvSparseMat::idxoffset).
    define_attr("size", &CvSparseMat::size, Rice::AttrAccess::Read).
    define_method<void(CvSparseMat::*)(cv::SparseMat&) const>("copy_to_sparse_mat", &CvSparseMat::copyToSparseMat,
      Arg("m"));

  define_global_function<CvSparseMat*(*)(const cv::SparseMat&)>("cv_create_sparse_mat", &cvCreateSparseMat,
    Arg("m"));

  Rice::Data_Type<CvSparseNode> rb_cCvSparseNode = define_class<CvSparseNode>("CvSparseNode").
    define_constructor(Constructor<CvSparseNode>()).
    define_attr("hashval", &CvSparseNode::hashval).
    define_attr("next", &CvSparseNode::next);

  Rice::Data_Type<CvSparseMatIterator> rb_cCvSparseMatIterator = define_class<CvSparseMatIterator>("CvSparseMatIterator").
    define_constructor(Constructor<CvSparseMatIterator>()).
    define_attr("mat", &CvSparseMatIterator::mat).
    define_attr("node", &CvSparseMatIterator::node).
    define_attr("curidx", &CvSparseMatIterator::curidx);

  Rice::Data_Type<CvHistogram> rb_cCvHistogram = define_class<CvHistogram>("CvHistogram").
    define_constructor(Constructor<CvHistogram>()).
    define_attr("type", &CvHistogram::type).
    define_attr("bins", &CvHistogram::bins).
    define_attr("thresh", &CvHistogram::thresh, Rice::AttrAccess::Read).
    define_attr("thresh2", &CvHistogram::thresh2).
    define_attr("mat", &CvHistogram::mat);

  Rice::Data_Type<CvRect> rb_cCvRect = define_class<CvRect>("CvRect").
    define_constructor(Constructor<CvRect>()).
    define_attr("x", &CvRect::x).
    define_attr("y", &CvRect::y).
    define_attr("width", &CvRect::width).
    define_attr("height", &CvRect::height);

  define_global_function<CvRect(*)(int, int, int, int)>("cv_rect", &cvRect,
    Arg("x"), Arg("y"), Arg("width"), Arg("height"));

  define_global_function<CvRect(*)(const cv::Rect&)>("cv_rect", &cvRect,
    Arg("rc"));

  define_global_function<IplROI(*)(CvRect, int)>("cv_rect_to_roi", &cvRectToROI,
    Arg("rect"), Arg("coi"));

  define_global_function<CvRect(*)(IplROI)>("cv_roi_to_rect", &cvROIToRect,
    Arg("roi"));

  Rice::Data_Type<CvTermCriteria> rb_cCvTermCriteria = define_class<CvTermCriteria>("CvTermCriteria").
    define_constructor(Constructor<CvTermCriteria>()).
    define_attr("type", &CvTermCriteria::type).
    define_attr("max_iter", &CvTermCriteria::max_iter).
    define_attr("epsilon", &CvTermCriteria::epsilon).
    define_method("to_term_criteria", [](const CvTermCriteria& self) -> cv::TermCriteria
    {
      return self;
    });

  define_global_function<CvTermCriteria(*)(int, int, double)>("cv_term_criteria", &cvTermCriteria,
    Arg("type"), Arg("max_iter"), Arg("epsilon"));

  define_global_function<CvTermCriteria(*)(const cv::TermCriteria&)>("cv_term_criteria", &cvTermCriteria,
    Arg("t"));

  Rice::Data_Type<CvPoint> rb_cCvPoint = define_class<CvPoint>("CvPoint").
    define_constructor(Constructor<CvPoint>()).
    define_attr("x", &CvPoint::x).
    define_attr("y", &CvPoint::y);

  define_global_function<CvPoint(*)(int, int)>("cv_point", &cvPoint,
    Arg("x"), Arg("y"));

  define_global_function<CvPoint(*)(const cv::Point&)>("cv_point", &cvPoint,
    Arg("pt"));

  Rice::Data_Type<CvPoint2D32f> rb_cCvPoint2D32f = define_class<CvPoint2D32f>("CvPoint2D32f").
    define_constructor(Constructor<CvPoint2D32f>()).
    define_attr("x", &CvPoint2D32f::x).
    define_attr("y", &CvPoint2D32f::y);

  define_global_function<CvPoint2D32f(*)(double, double)>("cv_point_2d32f", &cvPoint2D32f,
    Arg("x"), Arg("y"));

  define_global_function<CvPoint2D32f(*)(CvPoint)>("cv_point_to32f", &cvPointTo32f,
    Arg("point"));

  define_global_function<CvPoint(*)(CvPoint2D32f)>("cv_point_from32f", &cvPointFrom32f,
    Arg("point"));

  Rice::Data_Type<CvPoint3D32f> rb_cCvPoint3D32f = define_class<CvPoint3D32f>("CvPoint3D32f").
    define_constructor(Constructor<CvPoint3D32f>()).
    define_attr("x", &CvPoint3D32f::x).
    define_attr("y", &CvPoint3D32f::y).
    define_attr("z", &CvPoint3D32f::z);

  define_global_function<CvPoint3D32f(*)(double, double, double)>("cv_point_3d32f", &cvPoint3D32f,
    Arg("x"), Arg("y"), Arg("z"));

  Rice::Data_Type<CvPoint2D64f> rb_cCvPoint2D64f = define_class<CvPoint2D64f>("CvPoint2D64f").
    define_constructor(Constructor<CvPoint2D64f>()).
    define_attr("x", &CvPoint2D64f::x).
    define_attr("y", &CvPoint2D64f::y);

  define_global_function<CvPoint2D64f(*)(double, double)>("cv_point_2d64f", &cvPoint2D64f,
    Arg("x"), Arg("y"));

  Rice::Data_Type<CvPoint3D64f> rb_cCvPoint3D64f = define_class<CvPoint3D64f>("CvPoint3D64f").
    define_constructor(Constructor<CvPoint3D64f>()).
    define_attr("x", &CvPoint3D64f::x).
    define_attr("y", &CvPoint3D64f::y).
    define_attr("z", &CvPoint3D64f::z);

  define_global_function<CvPoint3D64f(*)(double, double, double)>("cv_point_3d64f", &cvPoint3D64f,
    Arg("x"), Arg("y"), Arg("z"));

  Rice::Data_Type<CvSize> rb_cCvSize = define_class<CvSize>("CvSize").
    define_constructor(Constructor<CvSize>()).
    define_attr("width", &CvSize::width).
    define_attr("height", &CvSize::height);

  define_global_function<CvSize(*)(int, int)>("cv_size", &cvSize,
    Arg("width"), Arg("height"));

  define_global_function<CvSize(*)(const cv::Size&)>("cv_size", &cvSize,
    Arg("sz"));

  Rice::Data_Type<CvSize2D32f> rb_cCvSize2D32f = define_class<CvSize2D32f>("CvSize2D32f").
    define_constructor(Constructor<CvSize2D32f>()).
    define_attr("width", &CvSize2D32f::width).
    define_attr("height", &CvSize2D32f::height);

  define_global_function<CvSize2D32f(*)(double, double)>("cv_size_2d32f", &cvSize2D32f,
    Arg("width"), Arg("height"));

  Rice::Data_Type<CvBox2D> rb_cCvBox2D = define_class<CvBox2D>("CvBox2D").
    define_constructor(Constructor<CvBox2D>()).
    define_attr("center", &CvBox2D::center).
    define_attr("size", &CvBox2D::size).
    define_attr("angle", &CvBox2D::angle).
    define_method("to_rotated_rect", [](const CvBox2D& self) -> cv::RotatedRect
    {
      return self;
    });

  define_global_function<CvBox2D(*)(CvPoint2D32f, CvSize2D32f, float)>("cv_box_2d", &cvBox2D,
    Arg("c") = static_cast<CvPoint2D32f>(CvPoint2D32f()), Arg("s") = static_cast<CvSize2D32f>(CvSize2D32f()), Arg("a") = static_cast<float>(0));

  define_global_function<CvBox2D(*)(const cv::RotatedRect&)>("cv_box_2d", &cvBox2D,
    Arg("rr"));

  Rice::Data_Type<CvLineIterator> rb_cCvLineIterator = define_class<CvLineIterator>("CvLineIterator").
    define_constructor(Constructor<CvLineIterator>()).
    define_attr("ptr", &CvLineIterator::ptr).
    define_attr("err", &CvLineIterator::err).
    define_attr("plus_delta", &CvLineIterator::plus_delta).
    define_attr("minus_delta", &CvLineIterator::minus_delta).
    define_attr("plus_step", &CvLineIterator::plus_step).
    define_attr("minus_step", &CvLineIterator::minus_step);

  Rice::Data_Type<CvSlice> rb_cCvSlice = define_class<CvSlice>("CvSlice").
    define_constructor(Constructor<CvSlice>()).
    define_attr("start_index", &CvSlice::start_index).
    define_attr("end_index", &CvSlice::end_index);

  define_global_function<CvSlice(*)(int, int)>("cv_slice", &cvSlice,
    Arg("start"), Arg("end"));

  define_global_function<CvSlice(*)(const cv::Range&)>("cv_slice", &cvSlice,
    Arg("r"));

  Rice::Data_Type<CvScalar> rb_cCvScalar = define_class<CvScalar>("CvScalar").
    define_constructor(Constructor<CvScalar>()).
    define_attr("val", &CvScalar::val, Rice::AttrAccess::Read);

  define_global_function<CvScalar(*)(double, double, double, double)>("cv_scalar", &cvScalar,
    Arg("val0"), Arg("val1"), Arg("val2"), Arg("val3"));

  define_global_function<CvScalar(*)()>("cv_scalar", &cvScalar);

  define_global_function<CvScalar(*)(const cv::Scalar&)>("cv_scalar", &cvScalar,
    Arg("s"));

  define_global_function<CvScalar(*)(double)>("cv_real_scalar", &cvRealScalar,
    Arg("val0"));

  define_global_function<CvScalar(*)(double)>("cv_scalar_all", &cvScalarAll,
    Arg("val0123"));

  Rice::Data_Type<CvMemBlock> rb_cCvMemBlock = define_class<CvMemBlock>("CvMemBlock").
    define_constructor(Constructor<CvMemBlock>()).
    define_attr("prev", &CvMemBlock::prev).
    define_attr("next", &CvMemBlock::next);

  Rice::Data_Type<CvMemStorage> rb_cCvMemStorage = define_class<CvMemStorage>("CvMemStorage").
    define_constructor(Constructor<CvMemStorage>()).
    define_attr("signature", &CvMemStorage::signature).
    define_attr("bottom", &CvMemStorage::bottom).
    define_attr("top", &CvMemStorage::top).
    define_attr("parent", &CvMemStorage::parent).
    define_attr("block_size", &CvMemStorage::block_size).
    define_attr("free_space", &CvMemStorage::free_space);

  Rice::Data_Type<CvMemStoragePos> rb_cCvMemStoragePos = define_class<CvMemStoragePos>("CvMemStoragePos").
    define_constructor(Constructor<CvMemStoragePos>()).
    define_attr("top", &CvMemStoragePos::top).
    define_attr("free_space", &CvMemStoragePos::free_space);

  Rice::Data_Type<CvSeqBlock> rb_cCvSeqBlock = define_class<CvSeqBlock>("CvSeqBlock").
    define_constructor(Constructor<CvSeqBlock>()).
    define_attr("prev", &CvSeqBlock::prev).
    define_attr("next", &CvSeqBlock::next).
    define_attr("start_index", &CvSeqBlock::start_index).
    define_attr("count", &CvSeqBlock::count).
    define_attr("data", &CvSeqBlock::data);

  Rice::Data_Type<CvSeq> rb_cCvSeq = define_class<CvSeq>("CvSeq").
    define_constructor(Constructor<CvSeq>()).
    define_attr("flags", &CvSeq::flags).
    define_attr("header_size", &CvSeq::header_size).
    define_attr("h_prev", &CvSeq::h_prev).
    define_attr("h_next", &CvSeq::h_next).
    define_attr("v_prev", &CvSeq::v_prev).
    define_attr("v_next", &CvSeq::v_next).
    define_attr("total", &CvSeq::total).
    define_attr("elem_size", &CvSeq::elem_size).
    define_attr("block_max", &CvSeq::block_max).
    define_attr("ptr", &CvSeq::ptr).
    define_attr("delta_elems", &CvSeq::delta_elems).
    define_attr("storage", &CvSeq::storage).
    define_attr("free_blocks", &CvSeq::free_blocks).
    define_attr("first", &CvSeq::first);

  Rice::Data_Type<CvSetElem> rb_cCvSetElem = define_class<CvSetElem>("CvSetElem").
    define_constructor(Constructor<CvSetElem>()).
    define_attr("flags", &CvSetElem::flags).
    define_attr("next_free", &CvSetElem::next_free);

  Rice::Data_Type<CvSet> rb_cCvSet = define_class<CvSet>("CvSet").
    define_constructor(Constructor<CvSet>()).
    define_attr("flags", &CvSet::flags).
    define_attr("header_size", &CvSet::header_size).
    define_attr("h_prev", &CvSet::h_prev).
    define_attr("h_next", &CvSet::h_next).
    define_attr("v_prev", &CvSet::v_prev).
    define_attr("v_next", &CvSet::v_next).
    define_attr("total", &CvSet::total).
    define_attr("elem_size", &CvSet::elem_size).
    define_attr("block_max", &CvSet::block_max).
    define_attr("ptr", &CvSet::ptr).
    define_attr("delta_elems", &CvSet::delta_elems).
    define_attr("storage", &CvSet::storage).
    define_attr("free_blocks", &CvSet::free_blocks).
    define_attr("first", &CvSet::first).
    define_attr("free_elems", &CvSet::free_elems).
    define_attr("active_count", &CvSet::active_count);

  Rice::Data_Type<CvGraphEdge> rb_cCvGraphEdge = define_class<CvGraphEdge>("CvGraphEdge").
    define_constructor(Constructor<CvGraphEdge>()).
    define_attr("flags", &CvGraphEdge::flags).
    define_attr("weight", &CvGraphEdge::weight).
    define_attr("next", &CvGraphEdge::next, Rice::AttrAccess::Read).
    define_attr("vtx", &CvGraphEdge::vtx, Rice::AttrAccess::Read);

  Rice::Data_Type<CvGraphVtx> rb_cCvGraphVtx = define_class<CvGraphVtx>("CvGraphVtx").
    define_constructor(Constructor<CvGraphVtx>());

  Rice::Data_Type<CvGraphVtx> rb_cCvGraphVtx = define_class<CvGraphVtx>("CvGraphVtx").
    define_constructor(Constructor<CvGraphVtx>()).
    define_attr("flags", &CvGraphVtx::flags).
    define_attr("first", &CvGraphVtx::first);

  Rice::Data_Type<CvGraphVtx2D> rb_cCvGraphVtx2D = define_class<CvGraphVtx2D>("CvGraphVtx2D").
    define_constructor(Constructor<CvGraphVtx2D>()).
    define_attr("flags", &CvGraphVtx2D::flags).
    define_attr("first", &CvGraphVtx2D::first).
    define_attr("ptr", &CvGraphVtx2D::ptr);

  Rice::Data_Type<CvGraph> rb_cCvGraph = define_class<CvGraph>("CvGraph").
    define_constructor(Constructor<CvGraph>()).
    define_attr("flags", &CvGraph::flags).
    define_attr("header_size", &CvGraph::header_size).
    define_attr("h_prev", &CvGraph::h_prev).
    define_attr("h_next", &CvGraph::h_next).
    define_attr("v_prev", &CvGraph::v_prev).
    define_attr("v_next", &CvGraph::v_next).
    define_attr("total", &CvGraph::total).
    define_attr("elem_size", &CvGraph::elem_size).
    define_attr("block_max", &CvGraph::block_max).
    define_attr("ptr", &CvGraph::ptr).
    define_attr("delta_elems", &CvGraph::delta_elems).
    define_attr("storage", &CvGraph::storage).
    define_attr("free_blocks", &CvGraph::free_blocks).
    define_attr("first", &CvGraph::first).
    define_attr("free_elems", &CvGraph::free_elems).
    define_attr("active_count", &CvGraph::active_count).
    define_attr("edges", &CvGraph::edges);

  Rice::Data_Type<CvChain> rb_cCvChain = define_class<CvChain>("CvChain").
    define_constructor(Constructor<CvChain>()).
    define_attr("flags", &CvChain::flags).
    define_attr("header_size", &CvChain::header_size).
    define_attr("h_prev", &CvChain::h_prev).
    define_attr("h_next", &CvChain::h_next).
    define_attr("v_prev", &CvChain::v_prev).
    define_attr("v_next", &CvChain::v_next).
    define_attr("total", &CvChain::total).
    define_attr("elem_size", &CvChain::elem_size).
    define_attr("block_max", &CvChain::block_max).
    define_attr("ptr", &CvChain::ptr).
    define_attr("delta_elems", &CvChain::delta_elems).
    define_attr("storage", &CvChain::storage).
    define_attr("free_blocks", &CvChain::free_blocks).
    define_attr("first", &CvChain::first).
    define_attr("origin", &CvChain::origin);

  Rice::Data_Type<CvContour> rb_cCvContour = define_class<CvContour>("CvContour").
    define_constructor(Constructor<CvContour>()).
    define_attr("flags", &CvContour::flags).
    define_attr("header_size", &CvContour::header_size).
    define_attr("h_prev", &CvContour::h_prev).
    define_attr("h_next", &CvContour::h_next).
    define_attr("v_prev", &CvContour::v_prev).
    define_attr("v_next", &CvContour::v_next).
    define_attr("total", &CvContour::total).
    define_attr("elem_size", &CvContour::elem_size).
    define_attr("block_max", &CvContour::block_max).
    define_attr("ptr", &CvContour::ptr).
    define_attr("delta_elems", &CvContour::delta_elems).
    define_attr("storage", &CvContour::storage).
    define_attr("free_blocks", &CvContour::free_blocks).
    define_attr("first", &CvContour::first).
    define_attr("rect", &CvContour::rect).
    define_attr("color", &CvContour::color).
    define_attr("reserved", &CvContour::reserved, Rice::AttrAccess::Read);

  Rice::Data_Type<CvSeqWriter> rb_cCvSeqWriter = define_class<CvSeqWriter>("CvSeqWriter").
    define_constructor(Constructor<CvSeqWriter>()).
    define_attr("header_size", &CvSeqWriter::header_size).
    define_attr("seq", &CvSeqWriter::seq).
    define_attr("block", &CvSeqWriter::block).
    define_attr("ptr", &CvSeqWriter::ptr).
    define_attr("block_min", &CvSeqWriter::block_min).
    define_attr("block_max", &CvSeqWriter::block_max);

  Rice::Data_Type<CvSeqReader> rb_cCvSeqReader = define_class<CvSeqReader>("CvSeqReader").
    define_constructor(Constructor<CvSeqReader>()).
    define_attr("header_size", &CvSeqReader::header_size).
    define_attr("seq", &CvSeqReader::seq).
    define_attr("block", &CvSeqReader::block).
    define_attr("ptr", &CvSeqReader::ptr).
    define_attr("block_min", &CvSeqReader::block_min).
    define_attr("block_max", &CvSeqReader::block_max).
    define_attr("delta_index", &CvSeqReader::delta_index).
    define_attr("prev_elem", &CvSeqReader::prev_elem);
}
