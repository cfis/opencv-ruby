#include <opencv2/core/base.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/kmeans_index.h>
#include "kmeans_index-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannKMeansIndexParams;

template<typename Data_Type_T, typename Distance>
inline void KMeansIndex_builder(Data_Type_T& klass)
{
  klass.define_attr("choose_centers", &cvflann::KMeansIndex<Distance>::chooseCenters).
    template define_method("choose_centers_random", &cvflann::KMeansIndex<Distance>::chooseCentersRandom,
      Arg("k"), Arg("indices"), Arg("indices_length"), Arg("centers"), Arg("centers_length")).
    template define_method("choose_centers_gonzales", &cvflann::KMeansIndex<Distance>::chooseCentersGonzales,
      Arg("k"), Arg("indices"), Arg("indices_length"), Arg("centers"), Arg("centers_length")).
    template define_method("choose_centers_k_meanspp", &cvflann::KMeansIndex<Distance>::chooseCentersKMeanspp,
      Arg("k"), Arg("indices"), Arg("indices_length"), Arg("centers"), Arg("centers_length")).
    template define_method("get_type", &cvflann::KMeansIndex<Distance>::getType).
    define_constructor(Constructor<cvflann::KMeansIndex<Distance>, const typename cvflann::Matrix<typename cvflann::KMeansIndex<Distance>::ElementType>&, const cvflann::IndexParams&, Distance>(),
      Arg("input_data"), Arg("params") = static_cast<const cvflann::IndexParams &>(cvflann::KMeansIndexParams()), Arg("d") = static_cast<Distance>(Distance())).
    define_constructor(Constructor<cvflann::KMeansIndex<Distance>, const cvflann::KMeansIndex<Distance>&>(),
      Arg("")).
    template define_method("assign", &cvflann::KMeansIndex<Distance>::operator=,
      Arg("")).
    template define_method("size", &cvflann::KMeansIndex<Distance>::size).
    template define_method("veclen", &cvflann::KMeansIndex<Distance>::veclen).
    template define_method("set_cb_index", &cvflann::KMeansIndex<Distance>::set_cb_index,
      Arg("index")).
    template define_method("used_memory", &cvflann::KMeansIndex<Distance>::usedMemory).
    template define_method("build_index", &cvflann::KMeansIndex<Distance>::buildIndex).
    template define_method("save_index", &cvflann::KMeansIndex<Distance>::saveIndex,
      Arg("stream")).
    template define_method("load_index", &cvflann::KMeansIndex<Distance>::loadIndex,
      Arg("stream")).
    template define_method("find_neighbors", &cvflann::KMeansIndex<Distance>::findNeighbors,
      Arg("result"), Arg("vec"), Arg("search_params")).
    template define_method("get_cluster_centers", &cvflann::KMeansIndex<Distance>::getClusterCenters,
      Arg("centers")).
    template define_method("get_parameters", &cvflann::KMeansIndex<Distance>::getParameters);
};

template<typename Data_Type_T, typename CentersContainerType>
inline void KMeansDistanceComputer_builder(Data_Type_T& klass)
{
  //klass.define_constructor(Constructor<cvflann::KMeansIndex::KMeansDistanceComputer<CentersContainerType>, Distance, const cvflann::Matrix<typename cvflann::KMeansIndex::KMeansDistanceComputer<CentersContainerType>::ElementType>&, const int, const int*, const CentersContainerType&, const ::size_t, std::vector<int>&, std::vector<cvflann::KMeansIndex::DistanceType>&>(),
//      Arg("_distance"), Arg("_dataset"), Arg("_branching"), Arg("_indices"), Arg("_dcenters"), Arg("_veclen"), Arg("_new_centroids"), Arg("_sq_dists")).
//    template define_method("call", &cvflann::KMeansIndex<Distance>::KMeansDistanceComputer<CentersContainerType>::operator(),
//      Arg("range"));
};
void Init_KmeansIndex()
{
  Class(rb_cObject).define_constant("BITS_PER_CHAR", BITS_PER_CHAR);
  
  Class(rb_cObject).define_constant("BITS_PER_BASE", BITS_PER_BASE);
  
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannKMeansIndexParams = define_class_under<cvflann::KMeansIndexParams, cvflann::IndexParams>(rb_mCvflann, "KMeansIndexParams").
    define_constructor(Constructor<cvflann::KMeansIndexParams, int, int, cvflann::flann_centers_init_t, float, int>(),
      Arg("branching") = static_cast<int>(32), Arg("iterations") = static_cast<int>(11), Arg("centers_init") = static_cast<cvflann::flann_centers_init_t>(cvflann::flann_centers_init_t::FLANN_CENTERS_RANDOM), Arg("cb_index") = static_cast<float>(0.2), Arg("trees") = static_cast<int>(1));

}