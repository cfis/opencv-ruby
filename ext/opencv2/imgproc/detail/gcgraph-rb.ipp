#include <opencv2/imgproc/detail/gcgraph.hpp>
#include "gcgraph-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename TWeight>
inline void GCGraph_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::detail::GCGraph<TWeight>>()).
    define_constructor(Constructor<cv::detail::GCGraph<TWeight>, unsigned int, unsigned int>(),
      Arg("vtx_count"), Arg("edge_count")).
    template define_method<void(cv::detail::GCGraph<TWeight>::*)(unsigned int, unsigned int)>("create", &cv::detail::GCGraph<TWeight>::create,
      Arg("vtx_count"), Arg("edge_count")).
    template define_method<int(cv::detail::GCGraph<TWeight>::*)()>("add_vtx", &cv::detail::GCGraph<TWeight>::addVtx).
    template define_method<void(cv::detail::GCGraph<TWeight>::*)(int, int, TWeight, TWeight)>("add_edges", &cv::detail::GCGraph<TWeight>::addEdges,
      Arg("i"), Arg("j"), Arg("w"), Arg("revw")).
    template define_method<void(cv::detail::GCGraph<TWeight>::*)(int, TWeight, TWeight)>("add_term_weights", &cv::detail::GCGraph<TWeight>::addTermWeights,
      Arg("i"), Arg("source_w"), Arg("sink_w")).
    template define_method<TWeight(cv::detail::GCGraph<TWeight>::*)()>("max_flow", &cv::detail::GCGraph<TWeight>::maxFlow).
    template define_method<bool(cv::detail::GCGraph<TWeight>::*)(int)>("in_source_segment", &cv::detail::GCGraph<TWeight>::inSourceSegment,
      Arg("i"));
};

