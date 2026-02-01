#pragma once
#include <opencv2/core/mat.hpp>

// Non-templated base class iterator traits
namespace std
{
  template<>
  struct iterator_traits<cv::SparseMatConstIterator>
  {
    using iterator_category = forward_iterator_tag;
    using value_type = const uchar*;
    using difference_type = ptrdiff_t;
    using pointer = const uchar**;
    using reference = const uchar*;
  };

  template<>
  struct iterator_traits<cv::SparseMatIterator>
  {
    using iterator_category = forward_iterator_tag;
    using value_type = uchar*;
    using difference_type = ptrdiff_t;
    using pointer = uchar**;
    using reference = uchar*;
  };
}

// Templated iterator traits
namespace std
{
  template<typename _Tp>
  struct iterator_traits<cv::SparseMatConstIterator_<_Tp>>
  {
    using iterator_category = forward_iterator_tag;
    using value_type = const _Tp;
    using difference_type = ptrdiff_t;
    using pointer = const _Tp*;
    using reference = const _Tp&;
  };
}

namespace std
{
  template<typename _Tp>
  struct iterator_traits<cv::SparseMatIterator_<_Tp>>
  {
    using iterator_category = forward_iterator_tag;
    using value_type = _Tp;
    using difference_type = ptrdiff_t;
    using pointer = _Tp*;
    using reference = _Tp&;
  };
}

template<typename T>
void mat_iterate(cv::Mat* mat)
{
  // The iterator returns references - we do NOT want to create a copy
  detail::To_Ruby<T&> toRuby;

  auto it = mat->begin<T>();
  auto end = mat->end<T>();

  for (; it != end; ++it)
  {
    detail::protect(rb_yield, toRuby.convert(*it));
  }
}
