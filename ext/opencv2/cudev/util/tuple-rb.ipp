template<typename T>
inline Rice::Data_Type<cv::cudev::TupleTraits<T>> TupleTraits_instantiate(Rice::Module& parent, const char* name)
{
  return Rice::define_class_under<cv::cudev::TupleTraits<T>>(parent, name).
    define_constant("Is_tuple", (int)cv::cudev::TupleTraits<T>::is_tuple).
    define_constant("Size", (int)cv::cudev::TupleTraits<T>::size);
}

