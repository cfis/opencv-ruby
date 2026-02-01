template<typename Op, int n>
inline Rice::Data_Type<cv::cudev::UnaryTupleAdapter<Op, n>> UnaryTupleAdapter_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::UnaryTupleAdapter<Op, n>>(parent, name).
    define_attr("op", &cv::cudev::UnaryTupleAdapter<Op, n>::op);
}

template<typename Op, int n0, int n1>
inline Rice::Data_Type<cv::cudev::BinaryTupleAdapter<Op, n0, n1>> BinaryTupleAdapter_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::BinaryTupleAdapter<Op, n0, n1>>(parent, name).
    define_attr("op", &cv::cudev::BinaryTupleAdapter<Op, n0, n1>::op);
}

