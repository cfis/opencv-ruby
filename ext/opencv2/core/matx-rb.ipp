template<typename _Tp, int m, int n>
inline Rice::Data_Type<cv::Matx<_Tp, m, n>> Matx_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::Matx<_Tp, m, n>>(parent, name).
    define_constant("Rows", (int)cv::Matx<_Tp, m, n>::rows).
    define_constant("Cols", (int)cv::Matx<_Tp, m, n>::cols).
    define_constant("Channels", (int)cv::Matx<_Tp, m, n>::channels).
    define_constant("Shortdim", (int)cv::Matx<_Tp, m, n>::shortdim).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp>(),
      Arg("v0")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp>(),
      Arg("v0"), Arg("v1")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const _Tp*>(),
      std::conditional_t<std::is_fundamental_v<const _Tp>, ArgBuffer, Arg>("vals")).
    template define_method<_Tp(cv::Matx<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&) const>("dot", &cv::Matx<_Tp, m, n>::dot,
      Arg("v")).
    template define_method<double(cv::Matx<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&) const>("ddot", &cv::Matx<_Tp, m, n>::ddot,
      Arg("v")).
    template define_method<cv::Matx<_Tp, 1, n>(cv::Matx<_Tp, m, n>::*)(int) const>("row", &cv::Matx<_Tp, m, n>::row,
      Arg("i")).
    template define_method<cv::Matx<_Tp, m, 1>(cv::Matx<_Tp, m, n>::*)(int) const>("col", &cv::Matx<_Tp, m, n>::col,
      Arg("i")).
    template define_method<typename cv::Matx<_Tp, m, n>::diag_type(cv::Matx<_Tp, m, n>::*)() const>("diag", &cv::Matx<_Tp, m, n>::diag).
    template define_method<cv::Matx<_Tp, n, m>(cv::Matx<_Tp, m, n>::*)() const>("t", &cv::Matx<_Tp, m, n>::t).
    template define_method<cv::Matx<_Tp, n, m>(cv::Matx<_Tp, m, n>::*)(int, bool*) const>("inv", &cv::Matx<_Tp, m, n>::inv,
      Arg("method") = static_cast<int>(cv::DECOMP_LU), ArgBuffer("p_is_ok") = static_cast<bool*>(NULL)).
    template define_method<cv::Vec<_Tp, n>(cv::Matx<_Tp, m, n>::*)(const cv::Vec<_Tp, m>&, int) const>("solve", &cv::Matx<_Tp, m, n>::solve,
      Arg("rhs"), Arg("method")).
    template define_method<cv::Matx<_Tp, m, n>(cv::Matx<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&) const>("mul", &cv::Matx<_Tp, m, n>::mul,
      Arg("a")).
    template define_method<cv::Matx<_Tp, m, n>(cv::Matx<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&) const>("div", &cv::Matx<_Tp, m, n>::div,
      Arg("a")).
    template define_method<const _Tp&(cv::Matx<_Tp, m, n>::*)(int, int) const>("call", &cv::Matx<_Tp, m, n>::operator(),
      Arg("row"), Arg("col")).
    template define_method<_Tp&(cv::Matx<_Tp, m, n>::*)(int, int)>("call", &cv::Matx<_Tp, m, n>::operator(),
      Arg("row"), Arg("col")).
    template define_method<const _Tp&(cv::Matx<_Tp, m, n>::*)(int) const>("call", &cv::Matx<_Tp, m, n>::operator(),
      Arg("i")).
    template define_method<_Tp&(cv::Matx<_Tp, m, n>::*)(int)>("call", &cv::Matx<_Tp, m, n>::operator(),
      Arg("i")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_AddOp>(),
      Arg("a"), Arg("b"), Arg("arg_2")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_SubOp>(),
      Arg("a"), Arg("b"), Arg("arg_2")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_MulOp>(),
      Arg("a"), Arg("b"), Arg("arg_2")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_DivOp>(),
      Arg("a"), Arg("b"), Arg("arg_2")).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, n, m>&, cv::Matx_TOp>(),
      Arg("a"), Arg("arg_1")).
    define_attr("val", &cv::Matx<_Tp, m, n>::val, Rice::AttrAccess::Read).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)(_Tp)>("all", &cv::Matx<_Tp, m, n>::all,
      Arg("alpha")).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)()>("zeros", &cv::Matx<_Tp, m, n>::zeros).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)()>("ones", &cv::Matx<_Tp, m, n>::ones).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)()>("eye", &cv::Matx<_Tp, m, n>::eye).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)(const typename cv::Matx<_Tp, m, n>::diag_type&)>("diag", &cv::Matx<_Tp, m, n>::diag,
      Arg("d")).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)(_Tp, _Tp)>("randu", &cv::Matx<_Tp, m, n>::randu,
      Arg("a"), Arg("b")).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)(_Tp, _Tp)>("randn", &cv::Matx<_Tp, m, n>::randn,
      Arg("a"), Arg("b"));
}

template<typename _Tp, int cn>
inline Rice::Data_Type<cv::Vec<_Tp, cn>> Vec_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::Vec<_Tp, cn>>(parent, name).
    define_constant("Channels", (int)cv::Vec<_Tp, cn>::channels).
    define_constant("_dummy_enum_finalizer", (int)cv::Vec<_Tp, cn>::_dummy_enum_finalizer).
    define_constructor(Constructor<cv::Vec<_Tp, cn>>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp>(),
      Arg("v0")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp>(),
      Arg("v0"), Arg("v1")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, const _Tp*>(),
      std::conditional_t<std::is_fundamental_v<const _Tp>, ArgBuffer, Arg>("values")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, const cv::Vec<_Tp, cn>&>(),
      Arg("v")).
    template define_method<cv::Vec<_Tp, cn>(cv::Vec<_Tp, cn>::*)(const cv::Vec<_Tp, cn>&) const>("mul", &cv::Vec<_Tp, cn>::mul,
      Arg("v")).
    template define_method<cv::Vec<_Tp, cn>(cv::Vec<_Tp, cn>::*)() const>("conj", &cv::Vec<_Tp, cn>::conj).
    template define_method<cv::Vec<_Tp, cn>(cv::Vec<_Tp, cn>::*)(const cv::Vec<_Tp, cn>&) const>("cross", &cv::Vec<_Tp, cn>::cross,
      Arg("v")).
    template define_method<const _Tp&(cv::Vec<_Tp, cn>::*)(int) const>("[]", &cv::Vec<_Tp, cn>::operator[],
      Arg("i")).
    template define_method<_Tp&(cv::Vec<_Tp, cn>::*)(int)>("[]", &cv::Vec<_Tp, cn>::operator[],
      Arg("i")).
    define_method("[]=", [](cv::Vec<_Tp, cn>&self, int index, _Tp & value)
    {
        self[index] = value;
    }).
    template define_method<const _Tp&(cv::Vec<_Tp, cn>::*)(int) const>("call", &cv::Vec<_Tp, cn>::operator(),
      Arg("i")).
    template define_method<_Tp&(cv::Vec<_Tp, cn>::*)(int)>("call", &cv::Vec<_Tp, cn>::operator(),
      Arg("i")).
    template define_method<cv::Vec<_Tp, cn>&(cv::Vec<_Tp, cn>::*)(const cv::Vec<_Tp, cn>&)>("assign", &cv::Vec<_Tp, cn>::operator=,
      Arg("rhs")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, const cv::Matx<_Tp, cn, 1>&, const cv::Matx<_Tp, cn, 1>&, cv::Matx_AddOp>(),
      Arg("a"), Arg("b"), Arg("arg_2")).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, const cv::Matx<_Tp, cn, 1>&, const cv::Matx<_Tp, cn, 1>&, cv::Matx_SubOp>(),
      Arg("a"), Arg("b"), Arg("arg_2")).
    template define_singleton_function<cv::Vec<_Tp, cn>(*)(_Tp)>("all", &cv::Vec<_Tp, cn>::all,
      Arg("alpha")).
    template define_singleton_function<cv::Vec<_Tp, cn>(*)()>("ones", &cv::Vec<_Tp, cn>::ones).
    template define_singleton_function<cv::Vec<_Tp, cn>(*)(_Tp, _Tp)>("randn", &cv::Vec<_Tp, cn>::randn,
      Arg("a"), Arg("b")).
    template define_singleton_function<cv::Vec<_Tp, cn>(*)(_Tp, _Tp)>("randu", &cv::Vec<_Tp, cn>::randu,
      Arg("a"), Arg("b")).
    template define_singleton_function<cv::Vec<_Tp, cn>(*)()>("zeros", &cv::Vec<_Tp, cn>::zeros);
}

