template<typename _Tp>
inline Rice::Data_Type<cv::Mat_<_Tp>> Mat__instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::Mat_<_Tp>>(parent, name).
    define_constructor(Constructor<cv::Mat_<_Tp>>()).
    define_constructor(Constructor<cv::Mat_<_Tp>, int, int>(),
      Arg("_rows"), Arg("_cols")).
    define_constructor(Constructor<cv::Mat_<_Tp>, int, int, const _Tp&>(),
      Arg("_rows"), Arg("_cols"), Arg("value")).
    define_constructor(Constructor<cv::Mat_<_Tp>, cv::Size>(),
      Arg("_size")).
    define_constructor(Constructor<cv::Mat_<_Tp>, cv::Size, const _Tp&>(),
      Arg("_size"), Arg("value")).
    define_constructor(Constructor<cv::Mat_<_Tp>, int, const int*>(),
      Arg("_ndims"), ArgBuffer("_sizes")).
    define_constructor(Constructor<cv::Mat_<_Tp>, int, const int*, const _Tp&>(),
      Arg("_ndims"), ArgBuffer("_sizes"), Arg("value")).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Mat_<_Tp>&>(),
      Arg("m")).
    define_constructor(Constructor<cv::Mat_<_Tp>, int, int, _Tp*, size_t>(),
      Arg("_rows"), Arg("_cols"), std::conditional_t<std::is_fundamental_v<_Tp>, ArgBuffer, Arg>("_data"), Arg("_step") = static_cast<size_t>(cv::Mat::AUTO_STEP)).
    define_constructor(Constructor<cv::Mat_<_Tp>, int, const int*, _Tp*, const size_t*>(),
      Arg("_ndims"), ArgBuffer("_sizes"), std::conditional_t<std::is_fundamental_v<_Tp>, ArgBuffer, Arg>("_data"), ArgBuffer("_steps") = static_cast<const size_t*>(0)).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Mat_<_Tp>&, const cv::Range&, const cv::Range&>(),
      Arg("m"), Arg("row_range"), Arg("col_range") = static_cast<const cv::Range&>(cv::Range::all())).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Mat_<_Tp>&, const cv::Rect&>(),
      Arg("m"), Arg("roi")).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Mat_<_Tp>&, const cv::Range*>(),
      Arg("m"), Arg("ranges")).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Mat_<_Tp>&, const std::vector<cv::Range>&>(),
      Arg("m"), Arg("ranges")).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::MatExpr&>(),
      Arg("e")).
    define_constructor(Constructor<cv::Mat_<_Tp>, const std::vector<_Tp>&, bool>(),
      Arg("vec"), Arg("copy_data") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Point_<typename cv::DataType<_Tp>::channel_type>&, bool>(),
      Arg("pt"), Arg("copy_data") = static_cast<bool>(true)).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Point3_<typename cv::DataType<_Tp>::channel_type>&, bool>(),
      Arg("pt"), Arg("copy_data") = static_cast<bool>(true)).
    template define_method<cv::Mat_<_Tp>&(cv::Mat_<_Tp>::*)(const cv::Mat&)>("assign", &cv::Mat_<_Tp>::operator=,
      Arg("m")).
    template define_method<cv::Mat_<_Tp>&(cv::Mat_<_Tp>::*)(const cv::Mat_<_Tp>&)>("assign", &cv::Mat_<_Tp>::operator=,
      Arg("m")).
    template define_method<cv::Mat_<_Tp>&(cv::Mat_<_Tp>::*)(const _Tp&)>("assign", &cv::Mat_<_Tp>::operator=,
      Arg("s")).
    template define_method<cv::Mat_<_Tp>&(cv::Mat_<_Tp>::*)(const cv::MatExpr&)>("assign", &cv::Mat_<_Tp>::operator=,
      Arg("e")).
    template define_iterator<typename cv::Mat_<_Tp>::iterator(cv::Mat_<_Tp>::*)()>(&cv::Mat_<_Tp>::begin, &cv::Mat_<_Tp>::end, "each").
    template define_iterator<typename cv::Mat_<_Tp>::const_iterator(cv::Mat_<_Tp>::*)() const>(&cv::Mat_<_Tp>::begin, &cv::Mat_<_Tp>::end, "each_const").
    template define_iterator<std::reverse_iterator<cv::Mat_<_Tp>::iterator>(cv::Mat_<_Tp>::*)()>(&cv::Mat_<_Tp>::rbegin, &cv::Mat_<_Tp>::rend, "each_reverse").
    template define_iterator<std::reverse_iterator<cv::Mat_<_Tp>::const_iterator>(cv::Mat_<_Tp>::*)() const>(&cv::Mat_<_Tp>::rbegin, &cv::Mat_<_Tp>::rend, "each_reverse_const").
    template define_method<void(cv::Mat_<_Tp>::*)(int, int)>("create", &cv::Mat_<_Tp>::create,
      Arg("_rows"), Arg("_cols")).
    template define_method<void(cv::Mat_<_Tp>::*)(cv::Size)>("create", &cv::Mat_<_Tp>::create,
      Arg("_size")).
    template define_method<void(cv::Mat_<_Tp>::*)(int, const int*)>("create", &cv::Mat_<_Tp>::create,
      Arg("_ndims"), ArgBuffer("_sizes")).
    template define_method<void(cv::Mat_<_Tp>::*)()>("release", &cv::Mat_<_Tp>::release).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)(const cv::Mat_<_Tp>&) const>("cross", &cv::Mat_<_Tp>::cross,
      Arg("m")).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)(int) const>("row", &cv::Mat_<_Tp>::row,
      Arg("y")).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)(int) const>("col", &cv::Mat_<_Tp>::col,
      Arg("x")).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)(int) const>("diag", &cv::Mat_<_Tp>::diag,
      Arg("d") = static_cast<int>(0)).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)() const>("clone", &cv::Mat_<_Tp>::clone).
    template define_method<size_t(cv::Mat_<_Tp>::*)() const>("elem_size", &cv::Mat_<_Tp>::elemSize).
    template define_method<size_t(cv::Mat_<_Tp>::*)() const>("elem_size1", &cv::Mat_<_Tp>::elemSize1).
    template define_method<int(cv::Mat_<_Tp>::*)() const>("type", &cv::Mat_<_Tp>::type).
    template define_method<int(cv::Mat_<_Tp>::*)() const>("depth", &cv::Mat_<_Tp>::depth).
    template define_method<int(cv::Mat_<_Tp>::*)() const>("channels", &cv::Mat_<_Tp>::channels).
    template define_method<size_t(cv::Mat_<_Tp>::*)(int) const>("step1", &cv::Mat_<_Tp>::step1,
      Arg("i") = static_cast<int>(0)).
    template define_method<size_t(cv::Mat_<_Tp>::*)(int) const>("step_t", &cv::Mat_<_Tp>::stepT,
      Arg("i") = static_cast<int>(0)).
    template define_method<cv::Mat_<_Tp>&(cv::Mat_<_Tp>::*)(int, int, int, int)>("adjust_roi", &cv::Mat_<_Tp>::adjustROI,
      Arg("dtop"), Arg("dbottom"), Arg("dleft"), Arg("dright")).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)(const cv::Range&, const cv::Range&) const>("call", &cv::Mat_<_Tp>::operator(),
      Arg("row_range"), Arg("col_range")).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)(const cv::Rect&) const>("call", &cv::Mat_<_Tp>::operator(),
      Arg("roi")).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)(const cv::Range*) const>("call", &cv::Mat_<_Tp>::operator(),
      Arg("ranges")).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)(const std::vector<cv::Range>&) const>("call", &cv::Mat_<_Tp>::operator(),
      Arg("ranges")).
    template define_method<_Tp*(cv::Mat_<_Tp>::*)(int)>("[]", &cv::Mat_<_Tp>::operator[],
      Arg("y")).
    template define_method<const _Tp*(cv::Mat_<_Tp>::*)(int) const>("[]", &cv::Mat_<_Tp>::operator[],
      Arg("y")).
    template define_method<_Tp&(cv::Mat_<_Tp>::*)(const int*)>("call", &cv::Mat_<_Tp>::operator(),
      ArgBuffer("idx")).
    template define_method<const _Tp&(cv::Mat_<_Tp>::*)(const int*) const>("call", &cv::Mat_<_Tp>::operator(),
      ArgBuffer("idx")).
    template define_method<_Tp&(cv::Mat_<_Tp>::*)(int)>("call", &cv::Mat_<_Tp>::operator(),
      Arg("idx0")).
    template define_method<const _Tp&(cv::Mat_<_Tp>::*)(int) const>("call", &cv::Mat_<_Tp>::operator(),
      Arg("idx0")).
    template define_method<_Tp&(cv::Mat_<_Tp>::*)(int, int)>("call", &cv::Mat_<_Tp>::operator(),
      Arg("row"), Arg("col")).
    template define_method<const _Tp&(cv::Mat_<_Tp>::*)(int, int) const>("call", &cv::Mat_<_Tp>::operator(),
      Arg("row"), Arg("col")).
    template define_method<_Tp&(cv::Mat_<_Tp>::*)(int, int, int)>("call", &cv::Mat_<_Tp>::operator(),
      Arg("idx0"), Arg("idx1"), Arg("idx2")).
    template define_method<const _Tp&(cv::Mat_<_Tp>::*)(int, int, int) const>("call", &cv::Mat_<_Tp>::operator(),
      Arg("idx0"), Arg("idx1"), Arg("idx2")).
    template define_method<_Tp&(cv::Mat_<_Tp>::*)(cv::Point)>("call", &cv::Mat_<_Tp>::operator(),
      Arg("pt")).
    template define_method<const _Tp&(cv::Mat_<_Tp>::*)(cv::Point) const>("call", &cv::Mat_<_Tp>::operator(),
      Arg("pt")).
    template define_method<cv::Mat_<_Tp>&(cv::Mat_<_Tp>::*)(cv::Mat_<_Tp>&&)>("assign", &cv::Mat_<_Tp>::operator=,
      Arg("m")).
    define_constructor(Constructor<cv::Mat_<_Tp>, cv::Mat&&>(),
      Arg("m")).
    template define_method<cv::Mat_<_Tp>&(cv::Mat_<_Tp>::*)(cv::Mat&&)>("assign", &cv::Mat_<_Tp>::operator=,
      Arg("m")).
    define_constructor(Constructor<cv::Mat_<_Tp>, cv::MatExpr&&>(),
      Arg("e")).
    template define_singleton_function<cv::MatExpr(*)(int, int)>("zeros", &cv::Mat_<_Tp>::zeros,
      Arg("rows"), Arg("cols")).
    template define_singleton_function<cv::MatExpr(*)(cv::Size)>("zeros", &cv::Mat_<_Tp>::zeros,
      Arg("size")).
    template define_singleton_function<cv::MatExpr(*)(int, const int*)>("zeros", &cv::Mat_<_Tp>::zeros,
      Arg("_ndims"), ArgBuffer("_sizes")).
    template define_singleton_function<cv::MatExpr(*)(int, int)>("ones", &cv::Mat_<_Tp>::ones,
      Arg("rows"), Arg("cols")).
    template define_singleton_function<cv::MatExpr(*)(cv::Size)>("ones", &cv::Mat_<_Tp>::ones,
      Arg("size")).
    template define_singleton_function<cv::MatExpr(*)(int, const int*)>("ones", &cv::Mat_<_Tp>::ones,
      Arg("_ndims"), ArgBuffer("_sizes")).
    template define_singleton_function<cv::MatExpr(*)(int, int)>("eye", &cv::Mat_<_Tp>::eye,
      Arg("rows"), Arg("cols")).
    template define_singleton_function<cv::MatExpr(*)(cv::Size)>("eye", &cv::Mat_<_Tp>::eye,
      Arg("size"));
}

template<typename _Tp>
inline Rice::Data_Type<cv::SparseMat_<_Tp>> SparseMat__instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::SparseMat_<_Tp>>(parent, name).
    define_constructor(Constructor<cv::SparseMat_<_Tp>>()).
    define_constructor(Constructor<cv::SparseMat_<_Tp>, int, const int*>(),
      Arg("dims"), ArgBuffer("_sizes")).
    define_constructor(Constructor<cv::SparseMat_<_Tp>, const cv::SparseMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::SparseMat_<_Tp>, const cv::SparseMat_<_Tp>&>(),
      Arg("m")).
    define_constructor(Constructor<cv::SparseMat_<_Tp>, const cv::Mat&>(),
      Arg("m")).
    template define_method<cv::SparseMat_<_Tp>&(cv::SparseMat_<_Tp>::*)(const cv::SparseMat&)>("assign", &cv::SparseMat_<_Tp>::operator=,
      Arg("m")).
    template define_method<cv::SparseMat_<_Tp>&(cv::SparseMat_<_Tp>::*)(const cv::SparseMat_<_Tp>&)>("assign", &cv::SparseMat_<_Tp>::operator=,
      Arg("m")).
    template define_method<cv::SparseMat_<_Tp>&(cv::SparseMat_<_Tp>::*)(const cv::Mat&)>("assign", &cv::SparseMat_<_Tp>::operator=,
      Arg("m")).
    template define_method<cv::SparseMat_<_Tp>(cv::SparseMat_<_Tp>::*)() const>("clone", &cv::SparseMat_<_Tp>::clone).
    template define_method<void(cv::SparseMat_<_Tp>::*)(int, const int*)>("create", &cv::SparseMat_<_Tp>::create,
      Arg("dims"), ArgBuffer("_sizes")).
    template define_method<int(cv::SparseMat_<_Tp>::*)() const>("type", &cv::SparseMat_<_Tp>::type).
    template define_method<int(cv::SparseMat_<_Tp>::*)() const>("depth", &cv::SparseMat_<_Tp>::depth).
    template define_method<int(cv::SparseMat_<_Tp>::*)() const>("channels", &cv::SparseMat_<_Tp>::channels).
    template define_method<_Tp&(cv::SparseMat_<_Tp>::*)(int, size_t*)>("ref", &cv::SparseMat_<_Tp>::ref,
      Arg("i0"), ArgBuffer("hashval") = static_cast<size_t*>(0)).
    template define_method<_Tp&(cv::SparseMat_<_Tp>::*)(int, int, size_t*)>("ref", &cv::SparseMat_<_Tp>::ref,
      Arg("i0"), Arg("i1"), ArgBuffer("hashval") = static_cast<size_t*>(0)).
    template define_method<_Tp&(cv::SparseMat_<_Tp>::*)(int, int, int, size_t*)>("ref", &cv::SparseMat_<_Tp>::ref,
      Arg("i0"), Arg("i1"), Arg("i2"), ArgBuffer("hashval") = static_cast<size_t*>(0)).
    template define_method<_Tp&(cv::SparseMat_<_Tp>::*)(const int*, size_t*)>("ref", &cv::SparseMat_<_Tp>::ref,
      ArgBuffer("idx"), ArgBuffer("hashval") = static_cast<size_t*>(0)).
    template define_method<_Tp(cv::SparseMat_<_Tp>::*)(int, size_t*) const>("call", &cv::SparseMat_<_Tp>::operator(),
      Arg("i0"), ArgBuffer("hashval") = static_cast<size_t*>(0)).
    template define_method<_Tp(cv::SparseMat_<_Tp>::*)(int, int, size_t*) const>("call", &cv::SparseMat_<_Tp>::operator(),
      Arg("i0"), Arg("i1"), ArgBuffer("hashval") = static_cast<size_t*>(0)).
    template define_method<_Tp(cv::SparseMat_<_Tp>::*)(int, int, int, size_t*) const>("call", &cv::SparseMat_<_Tp>::operator(),
      Arg("i0"), Arg("i1"), Arg("i2"), ArgBuffer("hashval") = static_cast<size_t*>(0)).
    template define_method<_Tp(cv::SparseMat_<_Tp>::*)(const int*, size_t*) const>("call", &cv::SparseMat_<_Tp>::operator(),
      ArgBuffer("idx"), ArgBuffer("hashval") = static_cast<size_t*>(0)).
    template define_iterator<cv::SparseMatIterator_<_Tp>(cv::SparseMat_<_Tp>::*)()>(&cv::SparseMat_<_Tp>::begin, &cv::SparseMat_<_Tp>::end, "each").
    template define_iterator<cv::SparseMatConstIterator_<_Tp>(cv::SparseMat_<_Tp>::*)() const>(&cv::SparseMat_<_Tp>::begin, &cv::SparseMat_<_Tp>::end, "each_const");
}

template<typename _Tp>
inline Rice::Data_Type<cv::MatConstIterator_<_Tp>> MatConstIterator__instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::MatConstIterator_<_Tp>>(parent, name).
    define_constructor(Constructor<cv::MatConstIterator_<_Tp>>()).
    define_constructor(Constructor<cv::MatConstIterator_<_Tp>, const cv::Mat_<_Tp>*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::MatConstIterator_<_Tp>, const cv::Mat_<_Tp>*, int, int>(),
      Arg("_m"), Arg("_row"), Arg("_col") = static_cast<int>(0)).
    define_constructor(Constructor<cv::MatConstIterator_<_Tp>, const cv::Mat_<_Tp>*, cv::Point>(),
      Arg("_m"), Arg("_pt")).
    define_constructor(Constructor<cv::MatConstIterator_<_Tp>, const cv::Mat_<_Tp>*, const int*>(),
      Arg("_m"), ArgBuffer("_idx")).
    define_constructor(Constructor<cv::MatConstIterator_<_Tp>, const cv::MatConstIterator_<_Tp>&>(),
      Arg("it")).
    template define_method<cv::MatConstIterator_<_Tp>&(cv::MatConstIterator_<_Tp>::*)(const cv::MatConstIterator_<_Tp>&)>("assign", &cv::MatConstIterator_<_Tp>::operator=,
      Arg("it")).
    template define_method<const _Tp&(cv::MatConstIterator_<_Tp>::*)() const>("dereference", &cv::MatConstIterator_<_Tp>::operator*).
    template define_method<const _Tp&(cv::MatConstIterator_<_Tp>::*)(ptrdiff_t) const>("[]", &cv::MatConstIterator_<_Tp>::operator[],
      Arg("i")).
    template define_method<cv::MatConstIterator_<_Tp>&(cv::MatConstIterator_<_Tp>::*)(ptrdiff_t)>("assign_plus", &cv::MatConstIterator_<_Tp>::operator+=,
      Arg("ofs")).
    template define_method<cv::MatConstIterator_<_Tp>&(cv::MatConstIterator_<_Tp>::*)(ptrdiff_t)>("assign_minus", &cv::MatConstIterator_<_Tp>::operator-=,
      Arg("ofs")).
    template define_method<cv::MatConstIterator_<_Tp>&(cv::MatConstIterator_<_Tp>::*)()>("decrement", &cv::MatConstIterator_<_Tp>::operator--).
    template define_method<cv::MatConstIterator_<_Tp>(cv::MatConstIterator_<_Tp>::*)(int)>("decrement_post", &cv::MatConstIterator_<_Tp>::operator--,
      Arg("arg_0")).
    template define_method<cv::MatConstIterator_<_Tp>&(cv::MatConstIterator_<_Tp>::*)()>("increment", &cv::MatConstIterator_<_Tp>::operator++).
    template define_method<cv::MatConstIterator_<_Tp>(cv::MatConstIterator_<_Tp>::*)(int)>("increment_post", &cv::MatConstIterator_<_Tp>::operator++,
      Arg("arg_0")).
    template define_method<cv::Point(cv::MatConstIterator_<_Tp>::*)() const>("pos", &cv::MatConstIterator_<_Tp>::pos);
}

template<typename _Tp>
inline Rice::Data_Type<cv::MatIterator_<_Tp>> MatIterator__instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::MatIterator_<_Tp>>(parent, name).
    define_constructor(Constructor<cv::MatIterator_<_Tp>>()).
    define_constructor(Constructor<cv::MatIterator_<_Tp>, cv::Mat_<_Tp>*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::MatIterator_<_Tp>, cv::Mat_<_Tp>*, int, int>(),
      Arg("_m"), Arg("_row"), Arg("_col") = static_cast<int>(0)).
    define_constructor(Constructor<cv::MatIterator_<_Tp>, cv::Mat_<_Tp>*, cv::Point>(),
      Arg("_m"), Arg("_pt")).
    define_constructor(Constructor<cv::MatIterator_<_Tp>, cv::Mat_<_Tp>*, const int*>(),
      Arg("_m"), ArgBuffer("_idx")).
    define_constructor(Constructor<cv::MatIterator_<_Tp>, const cv::MatIterator_<_Tp>&>(),
      Arg("it")).
    template define_method<cv::MatIterator_<_Tp>&(cv::MatIterator_<_Tp>::*)(const cv::MatIterator_<_Tp>&)>("assign", &cv::MatIterator_<_Tp>::operator=,
      Arg("it")).
    template define_method<_Tp&(cv::MatIterator_<_Tp>::*)() const>("dereference", &cv::MatIterator_<_Tp>::operator*).
    template define_method<_Tp&(cv::MatIterator_<_Tp>::*)(ptrdiff_t) const>("[]", &cv::MatIterator_<_Tp>::operator[],
      Arg("i")).
    template define_method<cv::MatIterator_<_Tp>&(cv::MatIterator_<_Tp>::*)(ptrdiff_t)>("assign_plus", &cv::MatIterator_<_Tp>::operator+=,
      Arg("ofs")).
    template define_method<cv::MatIterator_<_Tp>&(cv::MatIterator_<_Tp>::*)(ptrdiff_t)>("assign_minus", &cv::MatIterator_<_Tp>::operator-=,
      Arg("ofs")).
    template define_method<cv::MatIterator_<_Tp>&(cv::MatIterator_<_Tp>::*)()>("decrement", &cv::MatIterator_<_Tp>::operator--).
    template define_method<cv::MatIterator_<_Tp>(cv::MatIterator_<_Tp>::*)(int)>("decrement_post", &cv::MatIterator_<_Tp>::operator--,
      Arg("arg_0")).
    template define_method<cv::MatIterator_<_Tp>&(cv::MatIterator_<_Tp>::*)()>("increment", &cv::MatIterator_<_Tp>::operator++).
    template define_method<cv::MatIterator_<_Tp>(cv::MatIterator_<_Tp>::*)(int)>("increment_post", &cv::MatIterator_<_Tp>::operator++,
      Arg("arg_0"));
}

template<typename _Tp>
inline Rice::Data_Type<cv::SparseMatConstIterator_<_Tp>> SparseMatConstIterator__instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::SparseMatConstIterator_<_Tp>>(parent, name).
    define_constructor(Constructor<cv::SparseMatConstIterator_<_Tp>>()).
    define_constructor(Constructor<cv::SparseMatConstIterator_<_Tp>, const cv::SparseMat_<_Tp>*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::SparseMatConstIterator_<_Tp>, const cv::SparseMat*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::SparseMatConstIterator_<_Tp>, const cv::SparseMatConstIterator_<_Tp>&>(),
      Arg("it")).
    template define_method<cv::SparseMatConstIterator_<_Tp>&(cv::SparseMatConstIterator_<_Tp>::*)(const cv::SparseMatConstIterator_<_Tp>&)>("assign", &cv::SparseMatConstIterator_<_Tp>::operator=,
      Arg("it")).
    template define_method<const _Tp&(cv::SparseMatConstIterator_<_Tp>::*)() const>("dereference", &cv::SparseMatConstIterator_<_Tp>::operator*).
    template define_method<cv::SparseMatConstIterator_<_Tp>&(cv::SparseMatConstIterator_<_Tp>::*)()>("increment", &cv::SparseMatConstIterator_<_Tp>::operator++).
    template define_method<cv::SparseMatConstIterator_<_Tp>(cv::SparseMatConstIterator_<_Tp>::*)(int)>("increment_post", &cv::SparseMatConstIterator_<_Tp>::operator++,
      Arg("arg_0"));
}

template<typename _Tp>
inline Rice::Data_Type<cv::SparseMatIterator_<_Tp>> SparseMatIterator__instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::SparseMatIterator_<_Tp>>(parent, name).
    define_constructor(Constructor<cv::SparseMatIterator_<_Tp>>()).
    define_constructor(Constructor<cv::SparseMatIterator_<_Tp>, cv::SparseMat_<_Tp>*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::SparseMatIterator_<_Tp>, cv::SparseMat*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::SparseMatIterator_<_Tp>, const cv::SparseMatIterator_<_Tp>&>(),
      Arg("it")).
    template define_method<cv::SparseMatIterator_<_Tp>&(cv::SparseMatIterator_<_Tp>::*)(const cv::SparseMatIterator_<_Tp>&)>("assign", &cv::SparseMatIterator_<_Tp>::operator=,
      Arg("it")).
    template define_method<_Tp&(cv::SparseMatIterator_<_Tp>::*)() const>("dereference", &cv::SparseMatIterator_<_Tp>::operator*).
    template define_method<cv::SparseMatIterator_<_Tp>&(cv::SparseMatIterator_<_Tp>::*)()>("increment", &cv::SparseMatIterator_<_Tp>::operator++).
    template define_method<cv::SparseMatIterator_<_Tp>(cv::SparseMatIterator_<_Tp>::*)(int)>("increment_post", &cv::SparseMatIterator_<_Tp>::operator++,
      Arg("arg_0"));
}

