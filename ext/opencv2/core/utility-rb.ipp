#include <opencv2/core/utility.hpp>
#include "utility-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename _Tp, size_t fixed_size>
inline void AutoBuffer_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::AutoBuffer<_Tp, fixed_size>>()).
    define_constructor(Constructor<cv::AutoBuffer<_Tp, fixed_size>, size_t>(),
      Arg("_size")).
    define_constructor(Constructor<cv::AutoBuffer<_Tp, fixed_size>, const cv::AutoBuffer<_Tp, fixed_size>&>(),
      Arg("buf")).
    template define_method<cv::AutoBuffer<_Tp, fixed_size>&(cv::AutoBuffer<_Tp, fixed_size>::*)(const cv::AutoBuffer<_Tp, fixed_size>&)>("assign", &cv::AutoBuffer<_Tp, fixed_size>::operator=,
      Arg("buf")).
    template define_method<void(cv::AutoBuffer<_Tp, fixed_size>::*)(size_t)>("allocate", &cv::AutoBuffer<_Tp, fixed_size>::allocate,
      Arg("_size")).
    template define_method<void(cv::AutoBuffer<_Tp, fixed_size>::*)()>("deallocate", &cv::AutoBuffer<_Tp, fixed_size>::deallocate).
    template define_method<void(cv::AutoBuffer<_Tp, fixed_size>::*)(size_t)>("resize", &cv::AutoBuffer<_Tp, fixed_size>::resize,
      Arg("_size")).
    template define_method<size_t(cv::AutoBuffer<_Tp, fixed_size>::*)() const>("size", &cv::AutoBuffer<_Tp, fixed_size>::size).
    template define_method<_Tp*(cv::AutoBuffer<_Tp, fixed_size>::*)()>("data", &cv::AutoBuffer<_Tp, fixed_size>::data).
    template define_method<const _Tp*(cv::AutoBuffer<_Tp, fixed_size>::*)() const>("data", &cv::AutoBuffer<_Tp, fixed_size>::data).
    define_method("to_ptr", [](cv::AutoBuffer<_Tp, fixed_size>& self) -> _Tp*
    {
      return self;
    }).
    define_method("to_const_ptr", [](const cv::AutoBuffer<_Tp, fixed_size>& self) -> const _Tp*
    {
      return self;
    });
};

template<typename Data_Type_T, typename OBJECT>
inline void Node_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Node<OBJECT>>()).
    define_constructor(Constructor<cv::Node<OBJECT>, OBJECT&>(),
      Arg("payload")).
    template define_method<cv::Node<OBJECT>*(cv::Node<OBJECT>::*)(OBJECT&) const>("find_child", &cv::Node<OBJECT>::findChild,
      Arg("payload")).
    template define_method<int(cv::Node<OBJECT>::*)(cv::Node<OBJECT>*) const>("find_child", &cv::Node<OBJECT>::findChild,
      Arg("p_node")).
    template define_method<void(cv::Node<OBJECT>::*)(cv::Node<OBJECT>*)>("add_child", &cv::Node<OBJECT>::addChild,
      Arg("p_node")).
    template define_method<void(cv::Node<OBJECT>::*)()>("remove_childs", &cv::Node<OBJECT>::removeChilds).
    template define_method<int(cv::Node<OBJECT>::*)()>("get_depth", &cv::Node<OBJECT>::getDepth).
    define_attr("m_payload", &cv::Node<OBJECT>::m_payload).
    define_attr("m_p_parent", &cv::Node<OBJECT>::m_pParent).
    define_attr("m_childs", &cv::Node<OBJECT>::m_childs);
};

