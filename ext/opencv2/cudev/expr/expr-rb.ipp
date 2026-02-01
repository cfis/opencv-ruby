template<typename Body>
inline Rice::Data_Type<cv::cudev::Expr<Body>> Expr_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::Expr<Body>>(parent, name).
    define_attr("body", &cv::cudev::Expr<Body>::body);
}

