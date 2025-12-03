#include <opencv2/core/base.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/flann_base.hpp>
#include "../../opencv_ruby_version.hpp"
#include "flann_base-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannFILEScopeGuard;
Rice::Class rb_cCvflannSavedIndexParams;

template<typename Data_Type_T, typename Distance>
inline void Index_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::Index<Distance>, const cvflann::Matrix<typename cvflann::Index<Distance>::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("features"), Arg("params"), Arg("distance") = static_cast<Distance>(Distance())).
    template define_method<>("build_index", &cvflann::Index<Distance>::buildIndex).
    template define_method<>("save", &cvflann::Index<Distance>::save,
      Arg("filename")).
    template define_method<>("save_index", &cvflann::Index<Distance>::saveIndex,
      Arg("stream")).
    template define_method<>("load_index", &cvflann::Index<Distance>::loadIndex,
      Arg("stream")).
    template define_method<>("veclen", &cvflann::Index<Distance>::veclen).
    template define_method<>("size", &cvflann::Index<Distance>::size).
    template define_method<>("get_type", &cvflann::Index<Distance>::getType).
    template define_method<>("used_memory", &cvflann::Index<Distance>::usedMemory).
    template define_method<>("get_parameters", &cvflann::Index<Distance>::getParameters).
    template define_method<>("knn_search", &cvflann::Index<Distance>::knnSearch,
      Arg("queries"), Arg("indices"), Arg("dists"), Arg("knn"), Arg("params")).
    template define_method<>("radius_search", &cvflann::Index<Distance>::radiusSearch,
      Arg("query"), Arg("indices"), Arg("dists"), Arg("radius"), Arg("params")).
    template define_method<>("find_neighbors", &cvflann::Index<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params")).
    template define_method<>("get_index", &cvflann::Index<Distance>::getIndex).
    template define_method<>("get_index_parameters", &cvflann::Index<Distance>::getIndexParameters);
};

void Init_FlannBase()
{
  Module rb_mCvflann = define_module("Cvflann");

#if RUBY_CV_VERSION >= 408
  rb_cCvflannFILEScopeGuard = define_class_under<cvflann::FILEScopeGuard>(rb_mCvflann, "FILEScopeGuard").
    define_constructor(Constructor<cvflann::FILEScopeGuard, ::FILE*>(),
      Arg("file"));
#endif
  
  rb_mCvflann.define_module_function("log_verbosity", &cvflann::log_verbosity,
    Arg("level"));
  
  rb_cCvflannSavedIndexParams = define_class_under<cvflann::SavedIndexParams, cvflann::IndexParams>(rb_mCvflann, "SavedIndexParams").
    define_constructor(Constructor<cvflann::SavedIndexParams, cv::String>(),
      Arg("filename"));

}