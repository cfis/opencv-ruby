#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <opencv2/core/cvstd_wrapper.hpp>

void Init_CvstdWrapper();


namespace Rice
{
  template<typename T>
  inline Data_Type<cv::Ptr<T>> define_cv_ptr()
  {
    using Ptr_T = cv::Ptr<T>;
    using Data_Type_T = Data_Type<Ptr_T>;

    detail::TypeMapper<Ptr_T> typeMapper;
    std::string klassName = typeMapper.rubyName();
    
    Module rb_mCv = define_module("Cv");
    return define_class_under<cv::Ptr<T>>(rb_mCv, klassName).
      define_constructor(Constructor<cv::Ptr<T>>()).
      // define_constructor(Constructor<cv::Ptr<T>, nullptr_t>(),
       //  Arg("")).
      define_constructor(Constructor<cv::Ptr<T>, T*>(),
        Arg("ptr").takeOwnership()).
      define_constructor(Constructor<cv::Ptr<T>, const cv::Ptr<T>&>(),
        Arg("o")).
      define_constructor(Constructor<cv::Ptr<T>, const std::shared_ptr<T>&>(),
        Arg("o")).
      define_constructor(Constructor<cv::Ptr<T>, std::shared_ptr<T>&&>(),
        Arg("o")).
      template define_method<void(cv::Ptr<T>::*)()>("reset", &cv::Ptr<T>::reset).
      template define_method<cv::Ptr<T>&(cv::Ptr<T>::*)(const cv::Ptr<T>&)>("assign", &cv::Ptr<T>::operator=,
        Arg("o")).
      define_method("->", &cv::Ptr<T>::operator->).
      define_method("dereference", &cv::Ptr<T>::operator*).
      define_method("release", &cv::Ptr<T>::release).
      define_method("empty?", &cv::Ptr<T>::empty);
  };

  namespace detail
  {
    // --------- Wrapper ---------
    template<typename T>
    class Wrapper<cv::Ptr<T>> : public WrapperBase
    {
    public:
      Wrapper(cv::Ptr<T>& data) : data_(data)
      {
      }

      ~Wrapper()
      {
        Registries::instance.instances.remove(this->get());
      }

      void* get() override
      {
        return (void*)this->data_.get();
      }

      cv::Ptr<T>& data()
      {
        return data_;
      }

    private:
      cv::Ptr<T> data_;
    };


    // -------- Type ---------
    template<typename T>
    struct Type<cv::Ptr<T>>
    {
      static bool verify()
      {
        if constexpr (std::is_fundamental_v<T>)
        {
          Type<Pointer<T>>::verify();
          Type<Buffer<T>>::verify();
        }
        else
        {
          if (!Type<intrinsic_type<T>>::verify())
          {
            return false;
          }
        }

        if constexpr (!std::is_void_v<T>)
        {
          if (!Data_Type<cv::Ptr<T>>::is_defined())
          {
            Rice::define_cv_ptr<T>();
          }
        }
        return true;

      }

      static VALUE rubyKlass()
      {
        if (Data_Type<cv::Ptr<T>>::is_defined())
        {
          std::pair<VALUE, rb_data_type_t*> pair = Registries::instance.types.getType<cv::Ptr<T>>();
          return pair.first;
        }
        else
        {
          TypeMapper<T> typeMapper;
          return typeMapper.rubyKlass();
        }
      }
    };

    template<typename T>
    struct Type<cv::Ptr<T>*>
    {
      static bool verify()
      {
        return Type<T>::verify();
      }

      static VALUE rubyKlass()
      {
        if (Data_Type<cv::Ptr<T>>::is_defined())
        {
          std::pair<VALUE, rb_data_type_t*> pair = Registries::instance.types.getType<cv::Ptr<T>>();
          return pair.first;
        }
        else
        {
          TypeMapper<T> typeMapper;
          return typeMapper.rubyKlass();
        }
      }
    };

    // --------- To_Ruby ---------
    template <typename T>
    class To_Ruby<cv::Ptr<T>>
    {
    public:
      To_Ruby() = default;

      explicit To_Ruby(Arg* arg) : arg_(arg)
      {
      }

      VALUE convert(cv::Ptr<T>& data)
      {
        if constexpr (std::is_fundamental_v<T>)
        {
          return detail::wrap(Data_Type<T>::klass(), Data_Type<T>::ruby_data_type(), data, true);
        }
        else
        {
          return detail::wrap<cv::Ptr<T>>(Data_Type<T>::klass(), Data_Type<T>::ruby_data_type(), data, true);
        }
      }

      VALUE convert(const cv::Ptr<T>& data)
      {
        return this->convert((cv::Ptr<T>&)data);
      }

    private:
      Arg* arg_ = nullptr;
    };

    // --------- From_Ruby ---------
    template <typename T>
    class From_Ruby<cv::Ptr<T>>
    {
    public:
      From_Ruby() = default;

      explicit From_Ruby(Arg* arg) : arg_(arg)
      {
      }

      Convertible is_convertible(VALUE value)
      {
        switch (rb_type(value))
        {
          case RUBY_T_DATA:
            return Convertible::Exact;
            break;
          default:
            return Convertible::None;
        }
      }

      cv::Ptr<T> convert(VALUE value)
      {
        if (value == Qnil && this->arg_ && this->arg_->hasDefaultValue())
        {
          return this->arg_->template defaultValue<cv::Ptr<T>>();
        }

        // Get the wrapper
        WrapperBase* wrapperBase = detail::getWrapper(value);

        // Was this Cv::Ptr created by the user from Ruby? If so it will
        // be wrapped as a pointer, cv::Ptr<T>*. In the case just
        // return the shared pointer
        if (dynamic_cast<Wrapper<cv::Ptr<T>*>*>(wrapperBase))
        {
          // Use unwrap to validate the underlying wrapper is the correct type
          cv::Ptr<T>* ptr = unwrap<cv::Ptr<T>>(value, Data_Type<cv::Ptr<T>>::ruby_data_type(), false);
          return *ptr;
        }
        else if constexpr (std::is_fundamental_v<T>)
        {
          // Get the wrapper again to validate T's type
          Wrapper<cv::Ptr<T>>* wrapper = getWrapper<Wrapper<cv::Ptr<T>>>(value, Data_Type<T>::ruby_data_type());
          return wrapper->data();
        }
        else
        {
          // Get the wrapper again to validate T's type
          Wrapper<cv::Ptr<T>>* wrapper = getWrapper<Wrapper<cv::Ptr<T>>>(value, Data_Type<T>::ruby_data_type());
          return wrapper->data();
        }
      }

    private:
      Arg* arg_ = nullptr;
    };

    template <typename T>
    class To_Ruby<cv::Ptr<T>&>
    {
    public:
      To_Ruby() = default;

      explicit To_Ruby(Arg* arg) : arg_(arg)
      {
      }

      VALUE convert(cv::Ptr<T>& data)
      {
        if constexpr (std::is_fundamental_v<T>)
        {
          return detail::wrap(Data_Type<T>::klass(), Data_Type<T>::ruby_data_type(), data, true);
        }
        else
        {
          return detail::wrap<cv::Ptr<T>>(Data_Type<T>::klass(), Data_Type<T>::ruby_data_type(), data, true);
        }
      }

      VALUE convert(const cv::Ptr<T>& data)
      {
        return this->convert((cv::Ptr<T>&)data);
      }

    private:
      Arg* arg_ = nullptr;
    };

    template <typename T>
    class From_Ruby<cv::Ptr<T>&>
    {
    public:
      From_Ruby() = default;

      explicit From_Ruby(Arg* arg) : arg_(arg)
      {
      }

      Convertible is_convertible(VALUE value)
      {
        switch (rb_type(value))
        {
          case RUBY_T_DATA:
            return Convertible::Exact;
            break;
          default:
            return Convertible::None;
        }
      }

      cv::Ptr<T>& convert(VALUE value)
      {
        // Get the wrapper
        WrapperBase* wrapperBase = detail::getWrapper(value);

        // Was this shared_ptr created by the user from Ruby? If so it will
        // be wrapped as a pointer, cv::Ptr<T>*. In the case just
        // return the shared pointer
        if (dynamic_cast<Wrapper<cv::Ptr<T>*>*>(wrapperBase))
        {
          // Use unwrap to validate the underlying wrapper is the correct type
          cv::Ptr<T>* ptr = unwrap<cv::Ptr<T>>(value, Data_Type<cv::Ptr<T>>::ruby_data_type(), false);
          return *ptr;
        }
        else if constexpr (std::is_fundamental_v<T>)
        {
          // Get the wrapper again to validate T's type
          Wrapper<cv::Ptr<T>>* wrapper = getWrapper<Wrapper<cv::Ptr<T>>>(value, Data_Type<T>::ruby_data_type());
          return wrapper->data();
        }
        else
        {
          // Get the wrapper again to validate T's type
          Wrapper<cv::Ptr<T>>* wrapper = getWrapper<Wrapper<cv::Ptr<T>>>(value, Data_Type<T>::ruby_data_type());
          return wrapper->data();
        }
      }

    private:
      Arg* arg_ = nullptr;
    };
  }
}