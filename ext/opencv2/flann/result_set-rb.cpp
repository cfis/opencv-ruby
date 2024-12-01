#include <opencv2/core/base.hpp>
#include <opencv2/flann/defines.h>
#include <opencv2/flann/result_set.h>
#include "result_set-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannUniqueResultSetDistIndex;

template<typename Data_Type_T, typename T, typename DistanceType>
inline void BranchStruct_builder(Data_Type_T& klass)
{
  klass.define_attr("node", &cvflann::BranchStruct<T, DistanceType>::node).
    define_attr("mindist", &cvflann::BranchStruct<T, DistanceType>::mindist).
    define_constructor(Constructor<cvflann::BranchStruct<T, DistanceType>>()).
    define_constructor(Constructor<cvflann::BranchStruct<T, DistanceType>, const T&, DistanceType>(),
      Arg("a_node"), Arg("dist")).
    template define_method("<", &cvflann::BranchStruct<T, DistanceType>::operator<,
      Arg("rhs"));
};

template<typename Data_Type_T, typename DistanceType>
inline void ResultSet_builder(Data_Type_T& klass)
{
  klass.template define_method("full?", &cvflann::ResultSet<DistanceType>::full).
    template define_method("add_point", &cvflann::ResultSet<DistanceType>::addPoint,
      Arg("dist"), Arg("index")).
    template define_method("worst_dist", &cvflann::ResultSet<DistanceType>::worstDist);
};

template<typename Data_Type_T, typename DistanceType>
inline void KNNSimpleResultSet_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::KNNSimpleResultSet<DistanceType>, int>(),
      Arg("capacity_")).
    template define_method("init", &cvflann::KNNSimpleResultSet<DistanceType>::init,
      Arg("indices_"), Arg("dists_")).
    template define_method("size", &cvflann::KNNSimpleResultSet<DistanceType>::size).
    template define_method("full?", &cvflann::KNNSimpleResultSet<DistanceType>::full).
    template define_method("add_point", &cvflann::KNNSimpleResultSet<DistanceType>::addPoint,
      Arg("dist"), Arg("index")).
    template define_method("worst_dist", &cvflann::KNNSimpleResultSet<DistanceType>::worstDist);
};

template<typename Data_Type_T, typename DistanceType>
inline void KNNResultSet_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::KNNResultSet<DistanceType>, int>(),
      Arg("capacity_")).
    template define_method("init", &cvflann::KNNResultSet<DistanceType>::init,
      Arg("indices_"), Arg("dists_")).
    template define_method("size", &cvflann::KNNResultSet<DistanceType>::size).
    template define_method("full?", &cvflann::KNNResultSet<DistanceType>::full).
    template define_method("add_point", &cvflann::KNNResultSet<DistanceType>::addPoint,
      Arg("dist"), Arg("index")).
    template define_method("worst_dist", &cvflann::KNNResultSet<DistanceType>::worstDist);
};

template<typename Data_Type_T, typename DistanceType>
inline void RadiusResultSet_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::RadiusResultSet<DistanceType>, DistanceType, int*, DistanceType*, int>(),
      Arg("radius_"), Arg("indices_"), Arg("dists_"), Arg("capacity_")).
    template define_method("init", &cvflann::RadiusResultSet<DistanceType>::init).
    template define_method("size", &cvflann::RadiusResultSet<DistanceType>::size).
    template define_method("full?", &cvflann::RadiusResultSet<DistanceType>::full).
    template define_method("add_point", &cvflann::RadiusResultSet<DistanceType>::addPoint,
      Arg("dist"), Arg("index")).
    template define_method("worst_dist", &cvflann::RadiusResultSet<DistanceType>::worstDist);
};

template<typename Data_Type_T, typename DistanceType>
inline void UniqueResultSet_builder(Data_Type_T& klass)
{
  klass.rb_cCvflannUniqueResultSetDistIndex = define_class<cvflann::UniqueResultSet<DistanceType>::DistIndex>("DistIndex").
    define_constructor(Constructor<typename cvflann::UniqueResultSet<DistanceType>::DistIndex, DistanceType, unsigned int>(),
      Arg("dist"), Arg("index")).
    define_method("<", &cvflann::UniqueResultSet<DistanceType>::DistIndex::operator<,
      Arg("dist_index")).
    define_attr("dist_", &cvflann::UniqueResultSet<DistanceType>::DistIndex::dist_).
    define_attr("index_", &cvflann::UniqueResultSet<DistanceType>::DistIndex::index_).
    define_method("full?", &cvflann::UniqueResultSet<DistanceType>::full).
    define_method("clear", &cvflann::UniqueResultSet<DistanceType>::clear).
    define_method("copy", &cvflann::UniqueResultSet<DistanceType>::copy,
      Arg("indices"), Arg("dist"), Arg("n_neighbors") = static_cast<int>(-1)).
    define_method("sort_and_copy", &cvflann::UniqueResultSet<DistanceType>::sortAndCopy,
      Arg("indices"), Arg("dist"), Arg("n_neighbors") = static_cast<int>(-1)).
    define_method("size", &cvflann::UniqueResultSet<DistanceType>::size).
    define_method("worst_dist", &cvflann::UniqueResultSet<DistanceType>::worstDist);
};

template<typename Data_Type_T, typename DistanceType>
inline void KNNUniqueResultSet_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::KNNUniqueResultSet<DistanceType>, unsigned int>(),
      Arg("capacity")).
    template define_method("add_point", &cvflann::KNNUniqueResultSet<DistanceType>::addPoint,
      Arg("dist"), Arg("index")).
    template define_method("clear", &cvflann::KNNUniqueResultSet<DistanceType>::clear);
};

template<typename Data_Type_T, typename DistanceType>
inline void RadiusUniqueResultSet_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::RadiusUniqueResultSet<DistanceType>, DistanceType>(),
      Arg("radius")).
    template define_method("add_point", &cvflann::RadiusUniqueResultSet<DistanceType>::addPoint,
      Arg("dist"), Arg("index")).
    template define_method("clear", &cvflann::RadiusUniqueResultSet<DistanceType>::clear).
    template define_method("full?", &cvflann::RadiusUniqueResultSet<DistanceType>::full).
    template define_method("worst_dist", &cvflann::RadiusUniqueResultSet<DistanceType>::worstDist);
};

template<typename Data_Type_T, typename DistanceType>
inline void KNNRadiusUniqueResultSet_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::KNNRadiusUniqueResultSet<DistanceType>, unsigned int, DistanceType>(),
      Arg("capacity"), Arg("radius")).
    template define_method("clear", &cvflann::KNNRadiusUniqueResultSet<DistanceType>::clear);
};
void Init_ResultSet()
{
  Module rb_mCvflann = define_module("Cvflann");
  

}