template<typename TWeight>
inline Rice::Data_Type<cv::detail::GCGraph<TWeight>> GCGraph_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::detail::GCGraph<TWeight>>(parent, name).
    define_constructor(Constructor<cv::detail::GCGraph<TWeight>>()).
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
}

