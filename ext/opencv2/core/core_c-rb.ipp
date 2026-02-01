template<typename _Tp>
inline Rice::Data_Type<cv::Seq<_Tp>> Seq_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::Seq<_Tp>>(parent, name).
    define_constructor(Constructor<cv::Seq<_Tp>>()).
    define_constructor(Constructor<cv::Seq<_Tp>, const CvSeq*>(),
      Arg("seq")).
    define_constructor(Constructor<cv::Seq<_Tp>, cv::MemStorage&, int>(),
      Arg("storage"), Arg("header_size") = static_cast<int>(sizeof(CvSeq))).
    template define_method<_Tp&(cv::Seq<_Tp>::*)(int)>("[]", &cv::Seq<_Tp>::operator[],
      Arg("idx")).
    define_method("[]=", [](cv::Seq<_Tp>&self, int index, _Tp & value)
    {
        self[index] = value;
    }).
    template define_method<const _Tp&(cv::Seq<_Tp>::*)(int) const>("[]", &cv::Seq<_Tp>::operator[],
      Arg("idx")).
    template define_iterator<cv::SeqIterator<_Tp>(cv::Seq<_Tp>::*)() const>(&cv::Seq<_Tp>::begin, &cv::Seq<_Tp>::end, "each_const").
    template define_method<size_t(cv::Seq<_Tp>::*)() const>("size", &cv::Seq<_Tp>::size).
    template define_method<int(cv::Seq<_Tp>::*)() const>("type", &cv::Seq<_Tp>::type).
    template define_method<int(cv::Seq<_Tp>::*)() const>("depth", &cv::Seq<_Tp>::depth).
    template define_method<int(cv::Seq<_Tp>::*)() const>("channels", &cv::Seq<_Tp>::channels).
    template define_method<size_t(cv::Seq<_Tp>::*)() const>("elem_size", &cv::Seq<_Tp>::elemSize).
    template define_method<size_t(cv::Seq<_Tp>::*)(const _Tp&) const>("index", &cv::Seq<_Tp>::index,
      Arg("elem")).
    template define_method<void(cv::Seq<_Tp>::*)(const _Tp&)>("push_back", &cv::Seq<_Tp>::push_back,
      Arg("elem")).
    template define_method<void(cv::Seq<_Tp>::*)(const _Tp&)>("push_front", &cv::Seq<_Tp>::push_front,
      Arg("elem")).
    template define_method<void(cv::Seq<_Tp>::*)(const _Tp*, size_t)>("push_back", &cv::Seq<_Tp>::push_back,
      std::conditional_t<std::is_fundamental_v<const _Tp>, ArgBuffer, Arg>("elems"), Arg("count")).
    template define_method<void(cv::Seq<_Tp>::*)(const _Tp*, size_t)>("push_front", &cv::Seq<_Tp>::push_front,
      std::conditional_t<std::is_fundamental_v<const _Tp>, ArgBuffer, Arg>("elems"), Arg("count")).
    template define_method<void(cv::Seq<_Tp>::*)(int, const _Tp&)>("insert", &cv::Seq<_Tp>::insert,
      Arg("idx"), Arg("elem")).
    template define_method<void(cv::Seq<_Tp>::*)(int, const _Tp*, size_t)>("insert", &cv::Seq<_Tp>::insert,
      Arg("idx"), std::conditional_t<std::is_fundamental_v<const _Tp>, ArgBuffer, Arg>("elems"), Arg("count")).
    template define_method<void(cv::Seq<_Tp>::*)(int)>("remove", &cv::Seq<_Tp>::remove,
      Arg("idx")).
    template define_method<void(cv::Seq<_Tp>::*)(const cv::Range&)>("remove", &cv::Seq<_Tp>::remove,
      Arg("r")).
    template define_method<_Tp&(cv::Seq<_Tp>::*)()>("front", &cv::Seq<_Tp>::front).
    template define_method<const _Tp&(cv::Seq<_Tp>::*)() const>("front", &cv::Seq<_Tp>::front).
    template define_method<_Tp&(cv::Seq<_Tp>::*)()>("back", &cv::Seq<_Tp>::back).
    template define_method<const _Tp&(cv::Seq<_Tp>::*)() const>("back", &cv::Seq<_Tp>::back).
    template define_method<bool(cv::Seq<_Tp>::*)() const>("empty?", &cv::Seq<_Tp>::empty).
    template define_method<void(cv::Seq<_Tp>::*)()>("clear", &cv::Seq<_Tp>::clear).
    template define_method<void(cv::Seq<_Tp>::*)()>("pop_front", &cv::Seq<_Tp>::pop_front).
    template define_method<void(cv::Seq<_Tp>::*)()>("pop_back", &cv::Seq<_Tp>::pop_back).
    template define_method<void(cv::Seq<_Tp>::*)(_Tp*, size_t)>("pop_front", &cv::Seq<_Tp>::pop_front,
      std::conditional_t<std::is_fundamental_v<_Tp>, ArgBuffer, Arg>("elems"), Arg("count")).
    template define_method<void(cv::Seq<_Tp>::*)(_Tp*, size_t)>("pop_back", &cv::Seq<_Tp>::pop_back,
      std::conditional_t<std::is_fundamental_v<_Tp>, ArgBuffer, Arg>("elems"), Arg("count")).
    template define_method<void(cv::Seq<_Tp>::*)(std::vector<_Tp>&, const cv::Range&) const>("copy_to", &cv::Seq<_Tp>::copyTo,
      Arg("vec"), Arg("range") = static_cast<const cv::Range&>(cv::Range::all())).
    define_attr("seq", &cv::Seq<_Tp>::seq);
}

template<typename _Tp>
inline Rice::Data_Type<cv::SeqIterator<_Tp>> SeqIterator_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::SeqIterator<_Tp>>(parent, name).
    define_constructor(Constructor<cv::SeqIterator<_Tp>>()).
    define_constructor(Constructor<cv::SeqIterator<_Tp>, const cv::Seq<_Tp>&, bool>(),
      Arg("seq"), Arg("seek_end") = static_cast<bool>(false)).
    template define_method<void(cv::SeqIterator<_Tp>::*)(size_t)>("seek", &cv::SeqIterator<_Tp>::seek,
      Arg("pos")).
    template define_method<size_t(cv::SeqIterator<_Tp>::*)() const>("tell", &cv::SeqIterator<_Tp>::tell).
    template define_method<_Tp&(cv::SeqIterator<_Tp>::*)()>("dereference", &cv::SeqIterator<_Tp>::operator*).
    template define_method<const _Tp&(cv::SeqIterator<_Tp>::*)() const>("dereference", &cv::SeqIterator<_Tp>::operator*).
    template define_method<cv::SeqIterator<_Tp>&(cv::SeqIterator<_Tp>::*)()>("increment", &cv::SeqIterator<_Tp>::operator++).
    template define_method<cv::SeqIterator<_Tp>(cv::SeqIterator<_Tp>::*)(int) const>("increment_post", &cv::SeqIterator<_Tp>::operator++,
      Arg("arg_0")).
    template define_method<cv::SeqIterator<_Tp>&(cv::SeqIterator<_Tp>::*)()>("decrement", &cv::SeqIterator<_Tp>::operator--).
    template define_method<cv::SeqIterator<_Tp>(cv::SeqIterator<_Tp>::*)(int) const>("decrement_post", &cv::SeqIterator<_Tp>::operator--,
      Arg("arg_0")).
    template define_method<cv::SeqIterator<_Tp>&(cv::SeqIterator<_Tp>::*)(int)>("assign_plus", &cv::SeqIterator<_Tp>::operator+=,
      Arg("arg_0")).
    template define_method<cv::SeqIterator<_Tp>&(cv::SeqIterator<_Tp>::*)(int)>("assign_minus", &cv::SeqIterator<_Tp>::operator-=,
      Arg("arg_0")).
    define_attr("index", &cv::SeqIterator<_Tp>::index);
}

