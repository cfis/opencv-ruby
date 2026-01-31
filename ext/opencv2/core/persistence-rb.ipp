#include <opencv2/core/persistence.hpp>
#include "persistence-rb.hpp"

// Iterator traits specializations for iterators missing std::iterator_traits
namespace std
{
  template<>
  struct iterator_traits<cv::FileNodeIterator>
  {
    using iterator_category = forward_iterator_tag;
    using value_type = cv::FileNode;
    using difference_type = ptrdiff_t;
    using pointer = cv::FileNode*;
    using reference = cv::FileNode&;
  };
}

using namespace Rice;

template<typename Data_Type_T, typename _Tp, int numflag>
inline void VecWriterProxy_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::internal::VecWriterProxy<_Tp, numflag>, cv::FileStorage*>(),
      Arg("_fs")).
    template define_method<void(cv::internal::VecWriterProxy<_Tp, numflag>::*)(const std::vector<_Tp>&) const>("call", &cv::internal::VecWriterProxy<_Tp, numflag>::operator(),
      Arg("vec"));
};

template<typename Data_Type_T, typename _Tp, int numflag>
inline void VecReaderProxy_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::internal::VecReaderProxy<_Tp, numflag>, cv::FileNodeIterator*>(),
      Arg("_it")).
    template define_method<void(cv::internal::VecReaderProxy<_Tp, numflag>::*)(std::vector<_Tp>&, size_t) const>("call", &cv::internal::VecReaderProxy<_Tp, numflag>::operator(),
      Arg("vec"), Arg("count"));
};

