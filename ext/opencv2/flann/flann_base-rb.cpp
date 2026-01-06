#include <opencv2/flann/flann_base.hpp>
#include "flann_base-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannFILEScopeGuard;
Rice::Class rb_cCvflannSavedIndexParams;

template<typename Data_Type_T, typename Distance>
inline void Index_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::Index<Distance>, const Matrix<type-parameter-0-0::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("features"), Arg("params"), Arg("distance") = static_cast<Distance>(cvflann::Index::Distance())).
    define_method("build_index", &cvflann::Index<Distance>::buildIndex).
    define_method("save", &cvflann::Index<Distance>::save,
      Arg("filename")).
    define_method("save_index", &cvflann::Index<Distance>::saveIndex,
      Arg("stream")).
    define_method("load_index", &cvflann::Index<Distance>::loadIndex,
      Arg("stream")).
    define_method("veclen", &cvflann::Index<Distance>::veclen).
    define_method("size", &cvflann::Index<Distance>::size).
    define_method("get_type", &cvflann::Index<Distance>::getType).
    define_method("used_memory", &cvflann::Index<Distance>::usedMemory).
    define_method("get_parameters", &cvflann::Index<Distance>::getParameters).
    define_method("knn_search", &cvflann::Index<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    define_method("radius_search", &cvflann::Index<Distance>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("params")).
    define_method("find_neighbors", &cvflann::Index<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params"));
};
void Init_FlannBase()
{
  Module rb_mCvflann = define_module("Cvflann");

  rb_cCvflannFILEScopeGuard = define_class_under<cvflann::FILEScopeGuard>(rb_mCvflann, "FILEScopeGuard").
    define_constructor(Constructor<cvflann::FILEScopeGuard, FILE*>(),
      Arg("file"));

  rb_mCvflann.define_module_function("log_verbosity", &cvflann::log_verbosity,
    Arg("level"));

  rb_cCvflannSavedIndexParams = define_class_under<cvflann::SavedIndexParams, cvflann::IndexParams>(rb_mCvflann, "SavedIndexParams").
    define_constructor(Constructor<cvflann::SavedIndexParams, cv::String>(),
      Arg("filename"));

}