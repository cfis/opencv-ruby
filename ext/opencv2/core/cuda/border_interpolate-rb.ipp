template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdRowConstant<D>> BrdRowConstant_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdRowConstant<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdRowConstant<D>, int, const D&>(),
      Arg("width_"), Arg("val_") = static_cast<const D&>(cv::cuda::device::VecTraits<cv::cuda::device::BrdRowConstant::D>::all(0))).
    define_attr("width", &cv::cuda::device::BrdRowConstant<D>::width).
    define_attr("val", &cv::cuda::device::BrdRowConstant<D>::val);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdColConstant<D>> BrdColConstant_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdColConstant<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdColConstant<D>, int, const D&>(),
      Arg("height_"), Arg("val_") = static_cast<const D&>(cv::cuda::device::VecTraits<cv::cuda::device::BrdColConstant::D>::all(0))).
    define_attr("height", &cv::cuda::device::BrdColConstant<D>::height).
    define_attr("val", &cv::cuda::device::BrdColConstant<D>::val);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdConstant<D>> BrdConstant_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdConstant<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdConstant<D>, int, int, const D&>(),
      Arg("height_"), Arg("width_"), Arg("val_") = static_cast<const D&>(cv::cuda::device::VecTraits<cv::cuda::device::BrdConstant::D>::all(0))).
    define_attr("height", &cv::cuda::device::BrdConstant<D>::height).
    define_attr("width", &cv::cuda::device::BrdConstant<D>::width).
    define_attr("val", &cv::cuda::device::BrdConstant<D>::val);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdRowReplicate<D>> BrdRowReplicate_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdRowReplicate<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdRowReplicate<D>, int>(),
      Arg("width")).
    template define_method<int(cv::cuda::device::BrdRowReplicate<D>::*)(int) const>("idx_col_low", &cv::cuda::device::BrdRowReplicate<D>::idx_col_low,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdRowReplicate<D>::*)(int) const>("idx_col_high", &cv::cuda::device::BrdRowReplicate<D>::idx_col_high,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdRowReplicate<D>::*)(int) const>("idx_col", &cv::cuda::device::BrdRowReplicate<D>::idx_col,
      Arg("x")).
    define_attr("last_col", &cv::cuda::device::BrdRowReplicate<D>::last_col);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdColReplicate<D>> BrdColReplicate_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdColReplicate<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdColReplicate<D>, int>(),
      Arg("height")).
    template define_method<int(cv::cuda::device::BrdColReplicate<D>::*)(int) const>("idx_row_low", &cv::cuda::device::BrdColReplicate<D>::idx_row_low,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdColReplicate<D>::*)(int) const>("idx_row_high", &cv::cuda::device::BrdColReplicate<D>::idx_row_high,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdColReplicate<D>::*)(int) const>("idx_row", &cv::cuda::device::BrdColReplicate<D>::idx_row,
      Arg("y")).
    define_attr("last_row", &cv::cuda::device::BrdColReplicate<D>::last_row);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdReplicate<D>> BrdReplicate_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdReplicate<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdReplicate<D>, int, int>(),
      Arg("height"), Arg("width")).
    template define_method<int(cv::cuda::device::BrdReplicate<D>::*)(int) const>("idx_row_low", &cv::cuda::device::BrdReplicate<D>::idx_row_low,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdReplicate<D>::*)(int) const>("idx_row_high", &cv::cuda::device::BrdReplicate<D>::idx_row_high,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdReplicate<D>::*)(int) const>("idx_row", &cv::cuda::device::BrdReplicate<D>::idx_row,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdReplicate<D>::*)(int) const>("idx_col_low", &cv::cuda::device::BrdReplicate<D>::idx_col_low,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdReplicate<D>::*)(int) const>("idx_col_high", &cv::cuda::device::BrdReplicate<D>::idx_col_high,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdReplicate<D>::*)(int) const>("idx_col", &cv::cuda::device::BrdReplicate<D>::idx_col,
      Arg("x")).
    define_attr("last_row", &cv::cuda::device::BrdReplicate<D>::last_row).
    define_attr("last_col", &cv::cuda::device::BrdReplicate<D>::last_col);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdRowReflect101<D>> BrdRowReflect101_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdRowReflect101<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdRowReflect101<D>, int>(),
      Arg("width")).
    template define_method<int(cv::cuda::device::BrdRowReflect101<D>::*)(int) const>("idx_col_low", &cv::cuda::device::BrdRowReflect101<D>::idx_col_low,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdRowReflect101<D>::*)(int) const>("idx_col_high", &cv::cuda::device::BrdRowReflect101<D>::idx_col_high,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdRowReflect101<D>::*)(int) const>("idx_col", &cv::cuda::device::BrdRowReflect101<D>::idx_col,
      Arg("x")).
    define_attr("last_col", &cv::cuda::device::BrdRowReflect101<D>::last_col);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdColReflect101<D>> BrdColReflect101_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdColReflect101<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdColReflect101<D>, int>(),
      Arg("height")).
    template define_method<int(cv::cuda::device::BrdColReflect101<D>::*)(int) const>("idx_row_low", &cv::cuda::device::BrdColReflect101<D>::idx_row_low,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdColReflect101<D>::*)(int) const>("idx_row_high", &cv::cuda::device::BrdColReflect101<D>::idx_row_high,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdColReflect101<D>::*)(int) const>("idx_row", &cv::cuda::device::BrdColReflect101<D>::idx_row,
      Arg("y")).
    define_attr("last_row", &cv::cuda::device::BrdColReflect101<D>::last_row);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdReflect101<D>> BrdReflect101_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdReflect101<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdReflect101<D>, int, int>(),
      Arg("height"), Arg("width")).
    template define_method<int(cv::cuda::device::BrdReflect101<D>::*)(int) const>("idx_row_low", &cv::cuda::device::BrdReflect101<D>::idx_row_low,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdReflect101<D>::*)(int) const>("idx_row_high", &cv::cuda::device::BrdReflect101<D>::idx_row_high,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdReflect101<D>::*)(int) const>("idx_row", &cv::cuda::device::BrdReflect101<D>::idx_row,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdReflect101<D>::*)(int) const>("idx_col_low", &cv::cuda::device::BrdReflect101<D>::idx_col_low,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdReflect101<D>::*)(int) const>("idx_col_high", &cv::cuda::device::BrdReflect101<D>::idx_col_high,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdReflect101<D>::*)(int) const>("idx_col", &cv::cuda::device::BrdReflect101<D>::idx_col,
      Arg("x")).
    define_attr("last_row", &cv::cuda::device::BrdReflect101<D>::last_row).
    define_attr("last_col", &cv::cuda::device::BrdReflect101<D>::last_col);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdRowReflect<D>> BrdRowReflect_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdRowReflect<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdRowReflect<D>, int>(),
      Arg("width")).
    template define_method<int(cv::cuda::device::BrdRowReflect<D>::*)(int) const>("idx_col_low", &cv::cuda::device::BrdRowReflect<D>::idx_col_low,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdRowReflect<D>::*)(int) const>("idx_col_high", &cv::cuda::device::BrdRowReflect<D>::idx_col_high,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdRowReflect<D>::*)(int) const>("idx_col", &cv::cuda::device::BrdRowReflect<D>::idx_col,
      Arg("x")).
    define_attr("last_col", &cv::cuda::device::BrdRowReflect<D>::last_col);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdColReflect<D>> BrdColReflect_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdColReflect<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdColReflect<D>, int>(),
      Arg("height")).
    template define_method<int(cv::cuda::device::BrdColReflect<D>::*)(int) const>("idx_row_low", &cv::cuda::device::BrdColReflect<D>::idx_row_low,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdColReflect<D>::*)(int) const>("idx_row_high", &cv::cuda::device::BrdColReflect<D>::idx_row_high,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdColReflect<D>::*)(int) const>("idx_row", &cv::cuda::device::BrdColReflect<D>::idx_row,
      Arg("y")).
    define_attr("last_row", &cv::cuda::device::BrdColReflect<D>::last_row);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdReflect<D>> BrdReflect_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdReflect<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdReflect<D>, int, int>(),
      Arg("height"), Arg("width")).
    template define_method<int(cv::cuda::device::BrdReflect<D>::*)(int) const>("idx_row_low", &cv::cuda::device::BrdReflect<D>::idx_row_low,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdReflect<D>::*)(int) const>("idx_row_high", &cv::cuda::device::BrdReflect<D>::idx_row_high,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdReflect<D>::*)(int) const>("idx_row", &cv::cuda::device::BrdReflect<D>::idx_row,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdReflect<D>::*)(int) const>("idx_col_low", &cv::cuda::device::BrdReflect<D>::idx_col_low,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdReflect<D>::*)(int) const>("idx_col_high", &cv::cuda::device::BrdReflect<D>::idx_col_high,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdReflect<D>::*)(int) const>("idx_col", &cv::cuda::device::BrdReflect<D>::idx_col,
      Arg("x")).
    define_attr("last_row", &cv::cuda::device::BrdReflect<D>::last_row).
    define_attr("last_col", &cv::cuda::device::BrdReflect<D>::last_col);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdRowWrap<D>> BrdRowWrap_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdRowWrap<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdRowWrap<D>, int>(),
      Arg("width_")).
    template define_method<int(cv::cuda::device::BrdRowWrap<D>::*)(int) const>("idx_col_low", &cv::cuda::device::BrdRowWrap<D>::idx_col_low,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdRowWrap<D>::*)(int) const>("idx_col_high", &cv::cuda::device::BrdRowWrap<D>::idx_col_high,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdRowWrap<D>::*)(int) const>("idx_col", &cv::cuda::device::BrdRowWrap<D>::idx_col,
      Arg("x")).
    define_attr("width", &cv::cuda::device::BrdRowWrap<D>::width);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdColWrap<D>> BrdColWrap_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdColWrap<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdColWrap<D>, int>(),
      Arg("height_")).
    template define_method<int(cv::cuda::device::BrdColWrap<D>::*)(int) const>("idx_row_low", &cv::cuda::device::BrdColWrap<D>::idx_row_low,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdColWrap<D>::*)(int) const>("idx_row_high", &cv::cuda::device::BrdColWrap<D>::idx_row_high,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdColWrap<D>::*)(int) const>("idx_row", &cv::cuda::device::BrdColWrap<D>::idx_row,
      Arg("y")).
    define_attr("height", &cv::cuda::device::BrdColWrap<D>::height);
}

template<typename D>
inline Rice::Data_Type<cv::cuda::device::BrdWrap<D>> BrdWrap_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BrdWrap<D>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BrdWrap<D>, int, int>(),
      Arg("height_"), Arg("width_")).
    template define_method<int(cv::cuda::device::BrdWrap<D>::*)(int) const>("idx_row_low", &cv::cuda::device::BrdWrap<D>::idx_row_low,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdWrap<D>::*)(int) const>("idx_row_high", &cv::cuda::device::BrdWrap<D>::idx_row_high,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdWrap<D>::*)(int) const>("idx_row", &cv::cuda::device::BrdWrap<D>::idx_row,
      Arg("y")).
    template define_method<int(cv::cuda::device::BrdWrap<D>::*)(int) const>("idx_col_low", &cv::cuda::device::BrdWrap<D>::idx_col_low,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdWrap<D>::*)(int) const>("idx_col_high", &cv::cuda::device::BrdWrap<D>::idx_col_high,
      Arg("x")).
    template define_method<int(cv::cuda::device::BrdWrap<D>::*)(int) const>("idx_col", &cv::cuda::device::BrdWrap<D>::idx_col,
      Arg("x")).
    define_attr("height", &cv::cuda::device::BrdWrap<D>::height).
    define_attr("width", &cv::cuda::device::BrdWrap<D>::width);
}

template<typename Ptr2D, typename B>
inline Rice::Data_Type<cv::cuda::device::BorderReader<Ptr2D, B>> BorderReader_instantiate(Rice::Module parent, const char* name)
{
  return Rice::define_class_under<cv::cuda::device::BorderReader<Ptr2D, B>>(parent, name).
    define_constructor(Constructor<cv::cuda::device::BorderReader<Ptr2D, B>, const Ptr2D&, const B&>(),
      Arg("ptr_"), Arg("b_")).
    template define_method<typename cv::cuda::device::BorderReader<Ptr2D, B>::elem_type(cv::cuda::device::BorderReader<Ptr2D, B>::*)(typename cv::cuda::device::BorderReader<Ptr2D, B>::index_type, typename cv::cuda::device::BorderReader<Ptr2D, B>::index_type) const>("call", &cv::cuda::device::BorderReader<Ptr2D, B>::operator(),
      Arg("y"), Arg("x")).
    define_attr("ptr", &cv::cuda::device::BorderReader<Ptr2D, B>::ptr).
    define_attr("b", &cv::cuda::device::BorderReader<Ptr2D, B>::b);
}

