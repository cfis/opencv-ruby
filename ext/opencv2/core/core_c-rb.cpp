#include <opencv2/core/core_c.h>
#include "core_c-rb.hpp"

using namespace Rice;

#include "cvstd_wrapper-rb.ipp"
#include "core_c-rb.ipp"

void Init_Core_CoreC()
{
  Class(rb_cObject).define_constant("CV_AUTOSTEP", CV_AUTOSTEP);

  Class(rb_cObject).define_constant("CV_MAX_ARR", CV_MAX_ARR);

  Class(rb_cObject).define_constant("CV_NO_DEPTH_CHECK", CV_NO_DEPTH_CHECK);

  Class(rb_cObject).define_constant("CV_NO_CN_CHECK", CV_NO_CN_CHECK);

  Class(rb_cObject).define_constant("CV_NO_SIZE_CHECK", CV_NO_SIZE_CHECK);

  Class(rb_cObject).define_constant("CV_CMP_EQ", CV_CMP_EQ);

  Class(rb_cObject).define_constant("CV_CMP_GT", CV_CMP_GT);

  Class(rb_cObject).define_constant("CV_CMP_GE", CV_CMP_GE);

  Class(rb_cObject).define_constant("CV_CMP_LT", CV_CMP_LT);

  Class(rb_cObject).define_constant("CV_CMP_LE", CV_CMP_LE);

  Class(rb_cObject).define_constant("CV_CMP_NE", CV_CMP_NE);

  Class(rb_cObject).define_constant("CV_CHECK_RANGE", CV_CHECK_RANGE);

  Class(rb_cObject).define_constant("CV_CHECK_QUIET", CV_CHECK_QUIET);

  Class(rb_cObject).define_constant("CV_RAND_UNI", CV_RAND_UNI);

  Class(rb_cObject).define_constant("CV_RAND_NORMAL", CV_RAND_NORMAL);

  Class(rb_cObject).define_constant("CV_SORT_EVERY_ROW", CV_SORT_EVERY_ROW);

  Class(rb_cObject).define_constant("CV_SORT_EVERY_COLUMN", CV_SORT_EVERY_COLUMN);

  Class(rb_cObject).define_constant("CV_SORT_ASCENDING", CV_SORT_ASCENDING);

  Class(rb_cObject).define_constant("CV_SORT_DESCENDING", CV_SORT_DESCENDING);

  Class(rb_cObject).define_constant("CV_GEMM_A_T", CV_GEMM_A_T);

  Class(rb_cObject).define_constant("CV_GEMM_B_T", CV_GEMM_B_T);

  Class(rb_cObject).define_constant("CV_GEMM_C_T", CV_GEMM_C_T);

  Class(rb_cObject).define_constant("CV_SVD_MODIFY_A", CV_SVD_MODIFY_A);

  Class(rb_cObject).define_constant("CV_SVD_U_T", CV_SVD_U_T);

  Class(rb_cObject).define_constant("CV_SVD_V_T", CV_SVD_V_T);

  Class(rb_cObject).define_constant("CV_LU", CV_LU);

  Class(rb_cObject).define_constant("CV_SVD", CV_SVD);

  Class(rb_cObject).define_constant("CV_SVD_SYM", CV_SVD_SYM);

  Class(rb_cObject).define_constant("CV_CHOLESKY", CV_CHOLESKY);

  Class(rb_cObject).define_constant("CV_QR", CV_QR);

  Class(rb_cObject).define_constant("CV_NORMAL", CV_NORMAL);

  Class(rb_cObject).define_constant("CV_COVAR_SCRAMBLED", CV_COVAR_SCRAMBLED);

  Class(rb_cObject).define_constant("CV_COVAR_NORMAL", CV_COVAR_NORMAL);

  Class(rb_cObject).define_constant("CV_COVAR_USE_AVG", CV_COVAR_USE_AVG);

  Class(rb_cObject).define_constant("CV_COVAR_SCALE", CV_COVAR_SCALE);

  Class(rb_cObject).define_constant("CV_COVAR_ROWS", CV_COVAR_ROWS);

  Class(rb_cObject).define_constant("CV_COVAR_COLS", CV_COVAR_COLS);

  Class(rb_cObject).define_constant("CV_PCA_DATA_AS_ROW", CV_PCA_DATA_AS_ROW);

  Class(rb_cObject).define_constant("CV_PCA_DATA_AS_COL", CV_PCA_DATA_AS_COL);

  Class(rb_cObject).define_constant("CV_PCA_USE_AVG", CV_PCA_USE_AVG);

  Class(rb_cObject).define_constant("CV_C", CV_C);

  Class(rb_cObject).define_constant("CV_L1", CV_L1);

  Class(rb_cObject).define_constant("CV_L2", CV_L2);

  Class(rb_cObject).define_constant("CV_NORM_MASK", CV_NORM_MASK);

  Class(rb_cObject).define_constant("CV_RELATIVE", CV_RELATIVE);

  Class(rb_cObject).define_constant("CV_DIFF", CV_DIFF);

  Class(rb_cObject).define_constant("CV_MINMAX", CV_MINMAX);

  Class(rb_cObject).define_constant("CV_REDUCE_SUM", CV_REDUCE_SUM);

  Class(rb_cObject).define_constant("CV_REDUCE_AVG", CV_REDUCE_AVG);

  Class(rb_cObject).define_constant("CV_REDUCE_MAX", CV_REDUCE_MAX);

  Class(rb_cObject).define_constant("CV_REDUCE_MIN", CV_REDUCE_MIN);

  Class(rb_cObject).define_constant("CV_DXT_FORWARD", CV_DXT_FORWARD);

  Class(rb_cObject).define_constant("CV_DXT_INVERSE", CV_DXT_INVERSE);

  Class(rb_cObject).define_constant("CV_DXT_SCALE", CV_DXT_SCALE);

  Class(rb_cObject).define_constant("CV_DXT_ROWS", CV_DXT_ROWS);

  Class(rb_cObject).define_constant("CV_DXT_MUL_CONJ", CV_DXT_MUL_CONJ);

  Class(rb_cObject).define_constant("CV_FRONT", CV_FRONT);

  Class(rb_cObject).define_constant("CV_BACK", CV_BACK);

  Class(rb_cObject).define_constant("CV_GRAPH_VERTEX", CV_GRAPH_VERTEX);

  Class(rb_cObject).define_constant("CV_GRAPH_TREE_EDGE", CV_GRAPH_TREE_EDGE);

  Class(rb_cObject).define_constant("CV_GRAPH_BACK_EDGE", CV_GRAPH_BACK_EDGE);

  Class(rb_cObject).define_constant("CV_GRAPH_FORWARD_EDGE", CV_GRAPH_FORWARD_EDGE);

  Class(rb_cObject).define_constant("CV_GRAPH_CROSS_EDGE", CV_GRAPH_CROSS_EDGE);

  Class(rb_cObject).define_constant("CV_GRAPH_ANY_EDGE", CV_GRAPH_ANY_EDGE);

  Class(rb_cObject).define_constant("CV_GRAPH_NEW_TREE", CV_GRAPH_NEW_TREE);

  Class(rb_cObject).define_constant("CV_GRAPH_BACKTRACKING", CV_GRAPH_BACKTRACKING);

  Class(rb_cObject).define_constant("CV_KMEANS_USE_INITIAL_LABELS", CV_KMEANS_USE_INITIAL_LABELS);

  Class(rb_cObject).define_constant("CV_ErrModeLeaf", CV_ErrModeLeaf);

  Class(rb_cObject).define_constant("CV_ErrModeParent", CV_ErrModeParent);

  Class(rb_cObject).define_constant("CV_ErrModeSilent", CV_ErrModeSilent);

  Module rb_mCv = define_module("Cv");

  rb_mCv.define_module_function<cv::Mat(*)(const CvArr*, bool, bool, int, cv::AutoBuffer<double>*)>("cvarr_to_mat", &cv::cvarrToMat,
    ArgBuffer("arr"), Arg("copy_data") = static_cast<bool>(false), Arg("allow_nd") = static_cast<bool>(true), Arg("coi_mode") = static_cast<int>(0), Arg("buf") = static_cast<cv::AutoBuffer<double>*>(0));

  rb_mCv.define_module_function<cv::Mat(*)(const CvArr*, bool, int)>("cvarr_to_mat_nd", &cv::cvarrToMatND,
    ArgBuffer("arr"), Arg("copy_data") = static_cast<bool>(false), Arg("coi_mode") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(const CvArr*, cv::OutputArray, int)>("extract_image_coi", &cv::extractImageCOI,
    ArgBuffer("arr"), Arg("coiimg"), Arg("coi") = static_cast<int>(-1));

  rb_mCv.define_module_function<void(*)(cv::InputArray, CvArr*, int)>("insert_image_coi", &cv::insertImageCOI,
    Arg("coiimg"), ArgBuffer("arr"), Arg("coi") = static_cast<int>(-1));

  Rice::Data_Type<cv::DefaultDeleter<CvMat>> rb_cCvDefaultDeleterCvMat = define_class_under<cv::DefaultDeleter<CvMat>>(rb_mCv, "DefaultDeleterCvMat").
    define_constructor(Constructor<cv::DefaultDeleter<CvMat>>()).
    define_method<void(cv::DefaultDeleter<CvMat>::*)(CvMat*) const>("call", &cv::DefaultDeleter<CvMat>::operator(),
      Arg("obj"));

  Rice::Data_Type<cv::DefaultDeleter<IplImage>> rb_cCvDefaultDeleterIplImage = define_class_under<cv::DefaultDeleter<IplImage>>(rb_mCv, "DefaultDeleterIplImage").
    define_constructor(Constructor<cv::DefaultDeleter<IplImage>>()).
    define_method<void(cv::DefaultDeleter<IplImage>::*)(IplImage*) const>("call", &cv::DefaultDeleter<IplImage>::operator(),
      Arg("obj"));

  Rice::Data_Type<cv::DefaultDeleter<CvMatND>> rb_cCvDefaultDeleterCvMatND = define_class_under<cv::DefaultDeleter<CvMatND>>(rb_mCv, "DefaultDeleterCvMatND").
    define_constructor(Constructor<cv::DefaultDeleter<CvMatND>>()).
    define_method<void(cv::DefaultDeleter<CvMatND>::*)(CvMatND*) const>("call", &cv::DefaultDeleter<CvMatND>::operator(),
      Arg("obj"));

  Rice::Data_Type<cv::DefaultDeleter<CvSparseMat>> rb_cCvDefaultDeleterCvSparseMat = define_class_under<cv::DefaultDeleter<CvSparseMat>>(rb_mCv, "DefaultDeleterCvSparseMat").
    define_constructor(Constructor<cv::DefaultDeleter<CvSparseMat>>()).
    define_method<void(cv::DefaultDeleter<CvSparseMat>::*)(CvSparseMat*) const>("call", &cv::DefaultDeleter<CvSparseMat>::operator(),
      Arg("obj"));

  Rice::Data_Type<cv::DefaultDeleter<CvMemStorage>> rb_cCvDefaultDeleterCvMemStorage = define_class_under<cv::DefaultDeleter<CvMemStorage>>(rb_mCv, "DefaultDeleterCvMemStorage").
    define_constructor(Constructor<cv::DefaultDeleter<CvMemStorage>>()).
    define_method<void(cv::DefaultDeleter<CvMemStorage>::*)(CvMemStorage*) const>("call", &cv::DefaultDeleter<CvMemStorage>::operator(),
      Arg("obj"));

  Rice::Data_Type<cv::__shared_ptr_access<CvMemStorage, _Lp>> rb_cSharedPtrAccessCvMemStorageLp = __shared_ptr_access_instantiate<CvMemStorage, _Lp>(rb_mCv, "SharedPtrAccessCvMemStorageLp");
  Rice::Data_Type<cv::__shared_ptr<CvMemStorage>> rb_cSharedPtrCvMemStorage = __shared_ptr_instantiate<CvMemStorage>(rb_mCv, "SharedPtrCvMemStorage");
  Rice::Data_Type<cv::shared_ptr<CvMemStorage>> rb_cSharedPtrCvMemStorage = shared_ptr_instantiate<CvMemStorage>(rb_mCv, "SharedPtrCvMemStorage");
  Rice::Data_Type<cv::Ptr<CvMemStorage>> rb_cMemStorage = Ptr_instantiate<CvMemStorage>(rb_mCv, "MemStorage");

  rb_mCv.define_module_function<schar*(*)(CvSeq*, const void*)>("seq_push", &cv::seqPush,
    Arg("seq"), ArgBuffer("element") = static_cast<const void*>(0), ReturnBuffer());

  rb_mCv.define_module_function<schar*(*)(CvSeq*, const void*)>("seq_push_front", &cv::seqPushFront,
    Arg("seq"), ArgBuffer("element") = static_cast<const void*>(0), ReturnBuffer());

  rb_mCv.define_module_function<void(*)(CvSeq*, void*)>("seq_pop", &cv::seqPop,
    Arg("seq"), ArgBuffer("element") = static_cast<void*>(0));

  rb_mCv.define_module_function<void(*)(CvSeq*, void*)>("seq_pop_front", &cv::seqPopFront,
    Arg("seq"), ArgBuffer("element") = static_cast<void*>(0));

  rb_mCv.define_module_function<void(*)(CvSeq*, void*, int, int)>("seq_pop_multi", &cv::seqPopMulti,
    Arg("seq"), ArgBuffer("elements"), Arg("count"), Arg("in_front") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(CvSeq*, int)>("seq_remove", &cv::seqRemove,
    Arg("seq"), Arg("index"));

  rb_mCv.define_module_function<void(*)(CvSeq*)>("clear_seq", &cv::clearSeq,
    Arg("seq"));

  rb_mCv.define_module_function<schar*(*)(const CvSeq*, int)>("get_seq_elem", &cv::getSeqElem,
    Arg("seq"), Arg("index"), ReturnBuffer());

  rb_mCv.define_module_function<void(*)(CvSeq*, CvSlice)>("seq_remove_slice", &cv::seqRemoveSlice,
    Arg("seq"), Arg("slice"));

  rb_mCv.define_module_function<void(*)(CvSeq*, int, const CvArr*)>("seq_insert_slice", &cv::seqInsertSlice,
    Arg("seq"), Arg("before_index"), ArgBuffer("from_arr"));
}
