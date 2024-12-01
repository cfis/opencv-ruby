#include <opencv2/stitching/detail/util.hpp>
#include "util-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDetailDisjointSets;
Rice::Class rb_cCvDetailGraph;
Rice::Class rb_cCvDetailGraphEdge;

void Init_Util()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  rb_cCvDetailDisjointSets = define_class_under<cv::detail::DisjointSets>(rb_mCvDetail, "DisjointSets").
    define_constructor(Constructor<cv::detail::DisjointSets, int>(),
      Arg("elem_count") = static_cast<int>(0)).
    define_method("create_one_elem_sets", &cv::detail::DisjointSets::createOneElemSets,
      Arg("elem_count")).
    define_method("find_set_by_elem", &cv::detail::DisjointSets::findSetByElem,
      Arg("elem")).
    define_method("merge_sets", &cv::detail::DisjointSets::mergeSets,
      Arg("set1"), Arg("set2")).
    define_attr("parent", &cv::detail::DisjointSets::parent).
    define_attr("size", &cv::detail::DisjointSets::size);
  
  rb_cCvDetailGraphEdge = define_class_under<cv::detail::GraphEdge>(rb_mCvDetail, "GraphEdge").
    define_constructor(Constructor<cv::detail::GraphEdge, int, int, float>(),
      Arg("from"), Arg("to"), Arg("weight")).
    define_method("<", &cv::detail::GraphEdge::operator<,
      Arg("other")).
    define_method(">", &cv::detail::GraphEdge::operator>,
      Arg("other")).
    define_attr("from", &cv::detail::GraphEdge::from).
    define_attr("to", &cv::detail::GraphEdge::to).
    define_attr("weight", &cv::detail::GraphEdge::weight);
  
  rb_cCvDetailGraph = define_class_under<cv::detail::Graph>(rb_mCvDetail, "Graph").
    define_constructor(Constructor<cv::detail::Graph, int>(),
      Arg("num_vertices") = static_cast<int>(0)).
    define_method("create", &cv::detail::Graph::create,
      Arg("num_vertices")).
    define_method("num_vertices", &cv::detail::Graph::numVertices).
    define_method("add_edge", &cv::detail::Graph::addEdge,
      Arg("from"), Arg("to"), Arg("weight"));
  
  rb_mCvDetail.define_module_function("overlap_roi?", &cv::detail::overlapRoi,
    Arg("tl1"), Arg("tl2"), Arg("sz1"), Arg("sz2"), Arg("roi"));
  
  rb_mCvDetail.define_module_function<cv::Rect(*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&)>("result_roi", &cv::detail::resultRoi,
    Arg("corners"), Arg("images"));
  
  rb_mCvDetail.define_module_function<cv::Rect(*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::Size_<int>>&)>("result_roi", &cv::detail::resultRoi,
    Arg("corners"), Arg("sizes"));
  
  rb_mCvDetail.define_module_function("result_roi_intersection", &cv::detail::resultRoiIntersection,
    Arg("corners"), Arg("sizes"));
  
  rb_mCvDetail.define_module_function("result_tl", &cv::detail::resultTl,
    Arg("corners"));
  
  rb_mCvDetail.define_module_function("select_random_subset", &cv::detail::selectRandomSubset,
    Arg("count"), Arg("size"), Arg("subset"));
  
  rb_mCvDetail.define_module_function("stitching_log_level", &cv::detail::stitchingLogLevel);

}