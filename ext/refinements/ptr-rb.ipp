#include <opencv2/core/cvstd_wrapper.hpp>

namespace Rice
{
  namespace detail
  {
    template<typename T>
    inline Data_Type<cv::Ptr<T>> define_cv_ptr(std::string klassName = "")
    {
      using Ptr_T = cv::Ptr<T>;
      using Data_Type_T = Data_Type<Ptr_T>;

      if (klassName.empty())
      {
        detail::TypeDetail<Ptr_T> typeDetail;
        klassName = typeDetail.rubyName();
      }

      Module rb_mStd = define_module("Std");
      if (Data_Type_T::check_defined(klassName, rb_mStd))
      {
        return Data_Type_T();
      }

      Module rb_mCv = define_module("Cv");
      Data_Type_T result = define_class_under<cv::Ptr<T>>(rb_mCv, klassName).
        define_constructor(Constructor<cv::Ptr<T>, const cv::Ptr<T>&>(),
          Arg("o")).
        define_constructor(Constructor<cv::Ptr<T>, const std::shared_ptr<T>&>(),
          Arg("o")).
        define_constructor(Constructor<cv::Ptr<T>, std::shared_ptr<T>&&>(),
          Arg("o")).
        template define_method<void(cv::Ptr<T>::*)()>("reset", &cv::Ptr<T>::reset).
        template define_method<cv::Ptr<T>&(cv::Ptr<T>::*)(const cv::Ptr<T>&)>("assign", &cv::Ptr<T>::operator=,
          Arg("o")).
        define_method("get", &cv::Ptr<T>::operator*).
        define_method("release", &cv::Ptr<T>::release).
        define_method("empty?", [](cv::Ptr<T>& self)->bool
          {
            return !self;
          });

      if constexpr (!std::is_void_v<T> && is_complete_v<T>)
      {
        result.
          define_constructor(Constructor<cv::Ptr<T>>()).
          define_constructor(Constructor<cv::Ptr<T>, T*>(),
            Arg("ptr").takeOwnership()).
          define_constructor(Constructor<Ptr_T, typename Ptr_T::element_type*>(), Arg("value").takeOwnership());
      }

      // Forward methods to wrapped T
      if constexpr (!std::is_void_v<T> && !std::is_fundamental_v<T> && is_complete_v<T>)
      {
        result.instance_eval(R"(
        define_method(:method_missing) do |method_name, *args, &block|
          self.get.send(method_name, *args, &block)
        end

        define_method(:respond_to_missing?) do |method_name, include_private = false|
          self.get.send(method_name, *args, &block)
        end
      )");
      }

      return result;
    }

    template<typename T>
    class Wrapper<cv::Ptr<T>> : public WrapperBase
    {
    public:
      Wrapper(rb_data_type_t* rb_data_type, const cv::Ptr<T>& data) :
        WrapperBase(rb_data_type), data_(data)
      {
        using Intrinsic_T = intrinsic_type<T>;

        if constexpr (std::is_fundamental_v<Intrinsic_T>)
        {
          inner_rb_data_type_ = Data_Type<Pointer<Intrinsic_T>>::ruby_data_type();
        }
        else
        {
          inner_rb_data_type_ = Data_Type<Intrinsic_T>::ruby_data_type();
        }
      }

      ~Wrapper()
      {
        Registries::instance.instances.remove(this->get(this->rb_data_type_));
      }

      void* get(rb_data_type_t* requestedType) override
      {
        if (rb_typeddata_inherited_p(this->rb_data_type_, requestedType))
        {
          return &this->data_;
        }
        else if (rb_typeddata_inherited_p(this->inner_rb_data_type_, requestedType))
        {
          return (void*)this->data_.get();
        }
        else
        {
          throw Exception(rb_eTypeError, "wrong argument type (expected %s)",
            requestedType->wrap_struct_name);
        }
      }

    private:
      cv::Ptr<T> data_;
      rb_data_type_t* inner_rb_data_type_;
    };

    // -------- Type ---------
    template<typename T>
    struct Type<cv::Ptr<T>>
    {
      static bool verify()
      {
        bool result = true;
        if constexpr (std::is_fundamental_v<T>)
        {
          result = result && Type<Pointer<T>>::verify();
        }
        else
        {
          result = result && Type<intrinsic_type<T>>::verify();
        }

        // We ALWAYS need to define the cv::Ptr<T>, even if T is not bound, because it could be bound after this call
        define_cv_ptr<T>();

        return result;
      }
    };

    template<typename T>
    struct Type<cv::Ptr<T>*>
    {
      static bool verify()
      {
        return Type<T>::verify();
      }
    };
  }
}

