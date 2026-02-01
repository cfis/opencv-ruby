#include <opencv2/core/mat.hpp>
#include "../opencv2/core/mat-rb.ipp"
#include "../opencv2/core/mat-iterators.hpp"
#include "mat_refinements.hpp"

using namespace Rice;

// Tuple of types we need to implement Mat template functions like at, begin, end.
using Mat_Tuple_T = std::tuple<unsigned char, cv::Vec<unsigned char, 2>, cv::Vec<unsigned char, 3>, cv::Vec<unsigned char, 4>,
  short, cv::Vec<short, 2>, cv::Vec<short, 3>, cv::Vec<short, 4>,
  unsigned short, cv::Vec<unsigned short, 2>, cv::Vec<unsigned short, 3>, cv::Vec<unsigned short, 4>,
  int, cv::Vec<int, 2>, cv::Vec<int, 3>, cv::Vec<int, 4>,
  float, cv::Vec<float, 2>, cv::Vec<float, 3>, cv::Vec<float, 4>,
  double, cv::Vec<double, 2>, cv::Vec<double, 3>, cv::Vec<double, 4>>;

using Variant_T = typename detail::tuple_to_variant<Mat_Tuple_T>::type;
using Buffer_Tuple_T = typename detail::tuple_map<Buffer, Mat_Tuple_T>::type;
using Buffer_Variant_T = detail::tuple_to_variant<Buffer_Tuple_T>::type;

template<typename Data_Type_T, typename _Tp>
inline void Mat__Refinement_builder(Data_Type_T& klass)
{
  klass.
    // Make minitest exception handling happy
    define_method("_dump_data", [](cv::Mat_<_Tp>&) -> Rice::Hash
    {
      Rice::Hash result;
      return result;
    }).
    define_method("[]=", [](cv::Mat_<_Tp>& self, int index, _Tp& value)
    {
      self(index) = value;
    }).
    define_method("[]=", [](cv::Mat_<_Tp>& self, int row, int column, _Tp& value)
    {
      self(row, column) = value;
    }).
    define_method("[]=", [](cv::Mat_<_Tp>& self, int index1, int index2, int index3, _Tp& value)
    {
      self(index1, index2, index3) = value;
    }).
    define_method("[]=", [](cv::Mat_<_Tp>& self, cv::Point point, _Tp& value)
    {
      self(point) = value;
    }).
    define_method("to_vector", [](const cv::Mat_<_Tp>& self) -> std::vector<_Tp>
    {
      return self;
    });
};

template<typename Data_Type_T, typename _Tp>
inline void SparseMat__Refinement_builder(Data_Type_T& klass)
{
  // Manual
  klass.
    // Provide access to SparseMatIterator_<_Tp> because it has additional methods on it
    template define_method<cv::SparseMatIterator_<_Tp>(cv::SparseMat_<_Tp>::*)()>("begin", &cv::SparseMat_<_Tp>::begin).
    template define_method<cv::SparseMatIterator_<_Tp>(cv::SparseMat_<_Tp>::*)()>("end", &cv::SparseMat_<_Tp>::end).
    define_method("[]", [](cv::SparseMat_<_Tp>& self, int i0) -> _Tp&
    {
      return self.ref(i0);
    }).
    define_method("[]=", [](cv::SparseMat_<_Tp>& self, int i0, _Tp& value) -> _Tp&
    {
      self.ref(i0) = value;
      return value;
    }).
    define_method("[]", [](cv::SparseMat_<_Tp>& self, int i0, int i1) -> _Tp&
    {
      return self.ref(i0, i1);
    }).
    define_method("[]=", [](cv::SparseMat_<_Tp>& self, int i0, int i1, _Tp& value) -> _Tp&
    {
      self.ref(i0, i1) = value;
      return value;
    }).
    define_method("[]", [](cv::SparseMat_<_Tp>& self, int i0, int i1, int i2) -> _Tp&
    {
      return self.ref(i0, i1, i2);
    }).
    define_method("[]=", [](cv::SparseMat_<_Tp>& self, int i0, int i1, int i2, _Tp& value) -> _Tp&
    {
      self.ref(i0, i1, i2) = value;
      return value;
    }).
    define_method("[]", [](cv::SparseMat_<_Tp>& self, const int* idx) -> _Tp&
    {
      return self.ref(idx);
    }).
    define_method("[]=", [](cv::SparseMat_<_Tp>& self, const int* idx, _Tp& value) -> _Tp&
    {
      self.ref(idx) = value;
      return value;
    });
}

void Init_Core_Mat_Refinements()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::MatStep>::klass().define_method("[]", [](const cv::Mat& self, int x, int y) -> Variant_T
  {
    switch (self.type())
    {
      case CV_8UC1:
        return self.at<unsigned char>(x, y);
      case CV_8UC2:
        return self.at<cv::Vec<unsigned char, 2>>(x, y);
      case CV_8UC3:
        return self.at<cv::Vec<unsigned char, 3>>(x, y);
      case CV_8UC4:
        return self.at<cv::Vec<unsigned char, 4>>(x, y);
      case CV_16UC1:
        return self.at<unsigned short>(x, y);
      case CV_16UC2:
        return self.at<cv::Vec<unsigned short, 2>>(x, y);
      case CV_16UC3:
        return self.at<cv::Vec<unsigned short, 3>>(x, y);
      case CV_16UC4:
        return self.at<cv::Vec<unsigned short, 4>>(x, y);
      case CV_16SC1:
        return self.at<short>(x, y);
      case CV_16SC2:
        return self.at<cv::Vec<short, 2>>(x, y);
      case CV_16SC3:
        return self.at<cv::Vec<short, 3>>(x, y);
      case CV_16SC4:
        return self.at<cv::Vec<short, 4>>(x, y);
      case CV_32SC1:
        return self.at<int>(x, y);
      case CV_32SC2:
        return self.at<cv::Vec<int, 2>>(x, y);
      case CV_32SC3:
        return self.at<cv::Vec<int, 3>>(x, y);
      case CV_32SC4:
        return self.at<cv::Vec<int, 4>>(x, y);
      case CV_32FC1:
        return self.at<float>(x, y);
      case CV_32FC2:
        return self.at<cv::Vec<float, 2>>(x, y);
      case CV_32FC3:
        return self.at<cv::Vec<float, 3>>(x, y);
      case CV_32FC4:
        return self.at<cv::Vec<float, 4>>(x, y);
      case CV_64FC1:
        return self.at<double>(x, y);
      case CV_64FC2:
        return self.at<cv::Vec<double, 2>>(x, y);
      case CV_64FC3:
        return self.at<cv::Vec<double, 3>>(x, y);
      case CV_64FC4:
        return self.at<cv::Vec<double, 4>>(x, y);
      default:
        throw std::runtime_error("Unsupported type: " + std::to_string(self.type()));
    }
  });

  rb_define_alias(Rice::Data_Type<cv::Mat>::klass(), "at", "[]");

  // Element assignment operator []=
  Rice::Data_Type<cv::Mat>::klass().
    define_method("[]=", [](cv::Mat& self, int x, int y, Variant_T value) -> cv::Mat&
    {
      switch (self.type())
      {
        case CV_8UC1:
        {
          if (std::holds_alternative<unsigned char>(value))
          {
            self.at<unsigned char>(x, y) = std::get<unsigned char>(value);
          }
          else if (std::holds_alternative<short>(value))
          {
            self.at<unsigned char>(x, y) = (unsigned char)std::get<short>(value);
          }
          else if (std::holds_alternative<unsigned short>(value))
          {
            self.at<unsigned char>(x, y) = (unsigned char)std::get<unsigned short>(value);
          }
          else if (std::holds_alternative<int>(value))
          {
            self.at<unsigned char>(x, y) = (unsigned char)std::get<int>(value);
          }
          else
          {
            throw std::runtime_error("Unsupported type: " + std::to_string(self.type()));
          }
          break;
        }
        case CV_8UC2:
        {
          self.at<cv::Vec<unsigned char, 2>>(x, y) = std::get<cv::Vec<unsigned char, 2>>(value);
          break;
        }
        case CV_8UC3:
        {
          self.at<cv::Vec<unsigned char, 3>>(x, y) = std::get<cv::Vec<unsigned char, 3>>(value);
          break;
        }
        case CV_8UC4:
        {
          self.at<cv::Vec<unsigned char, 4>>(x, y) = std::get<cv::Vec<unsigned char, 4>>(value);
          break;
        }
        case CV_16UC1:
        {
          if (std::holds_alternative<unsigned char>(value))
          {
            self.at<unsigned short>(x, y) = std::get<unsigned char>(value);
          }
          else if (std::holds_alternative<short>(value))
          {
            self.at<unsigned short>(x, y) = std::get<short>(value);
          }
          else if (std::holds_alternative<unsigned short>(value))
          {
            self.at<unsigned short>(x, y) = std::get<unsigned short>(value);
          }
          else if (std::holds_alternative<int>(value))
          {
            self.at<unsigned short>(x, y) = (unsigned short)std::get<int>(value);
          }
          else
          {
            throw std::runtime_error("Unsupported type: " + std::to_string(self.type()));
          }
          break;
        }
        case CV_16UC2:
        {
          self.at<cv::Vec<unsigned short, 2>>(x, y) = std::get<cv::Vec<unsigned short, 2>>(value);
          break;
        }
        case CV_16UC3:
        {
          self.at<cv::Vec<unsigned short, 3>>(x, y) = std::get<cv::Vec<unsigned short, 3>>(value);
          break;
        }
        case CV_16UC4:
        {
          self.at<cv::Vec<unsigned short, 4>>(x, y) = std::get<cv::Vec<unsigned short, 4>>(value);
          break;
        }
        case CV_16SC1:
        {
          if (std::holds_alternative<unsigned char>(value))
          {
            self.at<short>(x, y) = std::get<unsigned char>(value);
          }
          else if (std::holds_alternative<short>(value))
          {
            self.at<short>(x, y) = std::get<short>(value);
          }
          else if (std::holds_alternative<unsigned short>(value))
          {
            self.at<short>(x, y) = std::get<unsigned short>(value);
          }
          else if (std::holds_alternative<int>(value))
          {
            self.at<short>(x, y) = (short)std::get<int>(value);
          }
          else
          {
            throw std::runtime_error("Unsupported type: " + std::to_string(self.type()));
          }
          break;
        }
        case CV_16SC2:
        {
          self.at<cv::Vec<short, 2>>(x, y) = std::get<cv::Vec<short, 2>>(value);
          break;
        }
        case CV_16SC3:
        {
          self.at<cv::Vec<short, 3>>(x, y) = std::get<cv::Vec<short, 3>>(value);
          break;
        }
        case CV_16SC4:
        {
          self.at<cv::Vec<short, 4>>(x, y) = std::get<cv::Vec<short, 4>>(value);
          break;
        }
        case CV_32SC1:
        {
          if (std::holds_alternative<unsigned char>(value))
          {
            self.at<int>(x, y) = std::get<unsigned char>(value);
          }
          else if (std::holds_alternative<short>(value))
          {
            self.at<int>(x, y) = std::get<short>(value);
          }
          else if (std::holds_alternative<unsigned short>(value))
          {
            self.at<int>(x, y) = std::get<unsigned short>(value);
          }
          else if (std::holds_alternative<int>(value))
          {
            self.at<int>(x, y) = std::get<int>(value);
          }
          else
          {
            throw std::runtime_error("Unsupported type: " + std::to_string(self.type()));
          }
          break;
        }
        case CV_32SC2:
        {
          self.at<cv::Vec<int, 2>>(x, y) = std::get<cv::Vec<int, 2>>(value);
          break;
        }
        case CV_32SC3:
        {
          self.at<cv::Vec<int, 3>>(x, y) = std::get<cv::Vec<int, 3>>(value);
          break;
        }
        case CV_32SC4:
        {
          self.at<cv::Vec<int, 4>>(x, y) = std::get<cv::Vec<int, 4>>(value);
          break;
        }
        case CV_32FC1:
        {
          if (std::holds_alternative<float>(value))
          {
            self.at<float>(x, y) = std::get<float>(value);
          }
          else if (std::holds_alternative<double>(value))
          {
            self.at<float>(x, y) = (float)std::get<double>(value);
          }
          else
          {
            throw std::runtime_error("Unsupported type: " + std::to_string(self.type()));
          }
          break;
        }
        case CV_32FC2:
        {
          self.at<cv::Vec<float, 2>>(x, y) = std::get<cv::Vec<float, 2>>(value);
          break;
        }
        case CV_32FC3:
        {
          self.at<cv::Vec<float, 3>>(x, y) = std::get<cv::Vec<float, 3>>(value);
          break;
        }
        case CV_32FC4:
        {
          self.at<cv::Vec<float, 4>>(x, y) = std::get<cv::Vec<float, 4>>(value);
          break;
        }
        case CV_64FC1:
        {
          if (std::holds_alternative<float>(value))
          {
            self.at<double>(x, y) = std::get<float>(value);
          }
          else if (std::holds_alternative<double>(value))
          {
            self.at<double>(x, y) = std::get<double>(value);
          }
          else
          {
            throw std::runtime_error("Unsupported type: " + std::to_string(self.type()));
          }
          break;
        }
        case CV_64FC2:
        {
          self.at<cv::Vec<double, 2>>(x, y) = std::get<cv::Vec<double, 2>>(value);
          break;
        }
        case CV_64FC3:
        {
          self.at<cv::Vec<double, 3>>(x, y) = std::get<cv::Vec<double, 3>>(value);
          break;
        }
        case CV_64FC4:
        {
          self.at<cv::Vec<double, 4>>(x, y) = std::get<cv::Vec<double, 4>>(value);
          break;
        }
        default:
        {
          throw std::runtime_error("Unsupported type: " + std::to_string(self.type()));
        }
      }
      return self;
    });

  // Row access via ptr
  Rice::Data_Type<cv::Mat>::klass().
    define_method("ptr", [](cv::Mat& self, int row) -> Buffer_Variant_T
    {
      switch (self.type())
      {
        case CV_8UC1:
          return Buffer<unsigned char>(self.ptr<unsigned char>(row), self.cols);
        case CV_8UC2:
          return Buffer<cv::Vec<unsigned char, 2>>(self.ptr<cv::Vec<unsigned char, 2>>(row), self.cols);
        case CV_8UC3:
          return Buffer<cv::Vec<unsigned char, 3>>(self.ptr<cv::Vec<unsigned char, 3>>(row), self.cols);
        case CV_8UC4:
          return Buffer<cv::Vec<unsigned char, 4>>(self.ptr<cv::Vec<unsigned char, 4>>(row), self.cols);
        case CV_16UC1:
          return Buffer<unsigned short>(self.ptr<unsigned short>(row), self.cols);
        case CV_16UC2:
          return Buffer<cv::Vec<unsigned short, 2>>(self.ptr<cv::Vec<unsigned short, 2>>(row), self.cols);
        case CV_16UC3:
          return Buffer<cv::Vec<unsigned short, 3>>(self.ptr<cv::Vec<unsigned short, 3>>(row), self.cols);
        case CV_16UC4:
          return Buffer<cv::Vec<unsigned short, 4>>(self.ptr<cv::Vec<unsigned short, 4>>(row), self.cols);
        case CV_16SC1:
          return Buffer<short>(self.ptr<short>(row), self.cols);
        case CV_16SC2:
          return Buffer<cv::Vec<short, 2>>(self.ptr<cv::Vec<short, 2>>(row), self.cols);
        case CV_16SC3:
          return Buffer<cv::Vec<short, 3>>(self.ptr<cv::Vec<short, 3>>(row), self.cols);
        case CV_16SC4:
          return Buffer<cv::Vec<short, 4>>(self.ptr<cv::Vec<short, 4>>(row), self.cols);
        case CV_32SC1:
          return Buffer<int>(self.ptr<int>(row), self.cols);
        case CV_32SC2:
          return Buffer<cv::Vec<int, 2>>(self.ptr<cv::Vec<int, 2>>(row), self.cols);
        case CV_32SC3:
          return Buffer<cv::Vec<int, 3>>(self.ptr<cv::Vec<int, 3>>(row), self.cols);
        case CV_32SC4:
          return Buffer<cv::Vec<int, 4>>(self.ptr<cv::Vec<int, 4>>(row), self.cols);
        case CV_32FC1:
          return Buffer<float>(self.ptr<float>(row), self.cols);
        case CV_32FC2:
          return Buffer<cv::Vec<float, 2>>(self.ptr<cv::Vec<float, 2>>(row), self.cols);
        case CV_32FC3:
          return Buffer<cv::Vec<float, 3>>(self.ptr<cv::Vec<float, 3>>(row), self.cols);
        case CV_32FC4:
          return Buffer<cv::Vec<float, 4>>(self.ptr<cv::Vec<float, 4>>(row), self.cols);
        case CV_64FC1:
          return Buffer<double>(self.ptr<double>(row), self.cols);
        case CV_64FC2:
          return Buffer<cv::Vec<double, 2>>(self.ptr<cv::Vec<double, 2>>(row), self.cols);
        case CV_64FC3:
          return Buffer<cv::Vec<double, 3>>(self.ptr<cv::Vec<double, 3>>(row), self.cols);
        case CV_64FC4:
          return Buffer<cv::Vec<double, 4>>(self.ptr<cv::Vec<double, 4>>(row), self.cols);
        default:
          throw std::runtime_error("Unsupported type: " + std::to_string(self.type()));
      }
    });

  // Setup iteration with Enumerable
  Rice::Data_Type<cv::Mat>::klass().include_module(rb_mEnumerable).
    define_method("each", [](VALUE self) -> VALUE
    {
      if (!detail::protect(rb_block_given_p))
      {
        static Identifier identifier("each");
        VALUE enumerator = detail::protect(rb_enumeratorize_with_size, self, identifier.to_sym(), 0, nullptr, nullptr);
        return enumerator;
      }
      else
      {
        cv::Mat* mat = detail::From_Ruby<cv::Mat*>().convert(self);

        switch (mat->type())
        {
          case CV_8UC1:
            mat_iterate<unsigned char>(mat);
            break;
          case CV_8UC2:
            mat_iterate<cv::Vec<unsigned char, 2>>(mat);
            break;
          case CV_8UC3:
            mat_iterate<cv::Vec<unsigned char, 3>>(mat);
            break;
          case CV_8UC4:
            mat_iterate<cv::Vec<unsigned char, 4>>(mat);
            break;
          case CV_16UC1:
            mat_iterate<unsigned short>(mat);
            break;
          case CV_16UC2:
            mat_iterate<cv::Vec<unsigned short, 2>>(mat);
            break;
          case CV_16UC3:
            mat_iterate<cv::Vec<unsigned short, 3>>(mat);
            break;
          case CV_16UC4:
            mat_iterate<cv::Vec<unsigned short, 4>>(mat);
            break;
          case CV_16SC1:
            mat_iterate<short>(mat);
            break;
          case CV_16SC2:
            mat_iterate<cv::Vec<short, 2>>(mat);
            break;
          case CV_16SC3:
            mat_iterate<cv::Vec<short, 3>>(mat);
            break;
          case CV_16SC4:
            mat_iterate<cv::Vec<short, 4>>(mat);
            break;
          case CV_32SC1:
            mat_iterate<int>(mat);
            break;
          case CV_32SC2:
            mat_iterate<cv::Vec<int, 2>>(mat);
            break;
          case CV_32SC3:
            mat_iterate<cv::Vec<int, 3>>(mat);
            break;
          case CV_32SC4:
            mat_iterate<cv::Vec<int, 4>>(mat);
            break;
          case CV_32FC1:
            mat_iterate<float>(mat);
            break;
          case CV_32FC2:
            mat_iterate<cv::Vec<float, 2>>(mat);
            break;
          case CV_32FC3:
            mat_iterate<cv::Vec<float, 3>>(mat);
            break;
          case CV_32FC4:
            mat_iterate<cv::Vec<float, 4>>(mat);
            break;
          case CV_64FC1:
            mat_iterate<double>(mat);
            break;
          case CV_64FC2:
            mat_iterate<cv::Vec<double, 2>>(mat);
            break;
          case CV_64FC3:
            mat_iterate<cv::Vec<double, 3>>(mat);
            break;
          case CV_64FC4:
            mat_iterate<cv::Vec<double, 4>>(mat);
            break;
          default:
            throw std::runtime_error("Unsupported type: " + std::to_string(mat->type()));
        }
        return self;
      }
    }, Return().setValue());

  Rice::Data_Type<cv::MatSize>::klass().
    define_method("inspect", [](const cv::MatSize& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });

  Rice::Data_Type<cv::_InputArray> inputArray = (Rice::Data_Type<cv::_InputArray>)Rice::Data_Type<cv::_InputArray>::klass();
  inputArray.
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Point>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Point2i>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Point2f>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Point2d>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<std::vector<cv::Point>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<unsigned char, 1>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<unsigned char, 2>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<unsigned char, 3>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<unsigned char, 4>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<short, 1>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<short, 2>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<short, 3>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<short, 4>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<unsigned short, 1>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<unsigned short, 2>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<unsigned short, 3>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<unsigned short, 4>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<int, 1>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<int, 2>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<int, 3>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<int, 4>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<float, 1>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<float, 2>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<float, 3>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<float, 4>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<float, 6>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<double, 1>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<double, 2>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<double, 3>>&>()).
    define_constructor(Constructor<cv::_InputArray, std::vector<cv::Vec<double, 4>>&>());

  Rice::Data_Type<cv::_OutputArray> outputArray = (Rice::Data_Type<cv::_OutputArray>)Rice::Data_Type<cv::_OutputArray>::klass();
  outputArray.
    define_constructor(Constructor<cv::_OutputArray, std::vector<std::vector<cv::Point>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<unsigned char, 1>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<unsigned char, 2>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<unsigned char, 3>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<unsigned char, 4>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<short, 1>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<short, 2>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<short, 3>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<short, 4>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<unsigned short, 1>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<unsigned short, 2>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<unsigned short, 3>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<unsigned short, 4>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<int, 1>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<int, 2>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<int, 3>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<int, 4>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<float, 1>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<float, 2>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<float, 3>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<float, 4>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<float, 6>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<double, 1>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<double, 2>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<double, 3>>&>()).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Vec<double, 4>>&>());

  // First process the mat_ classes already constructed
 /* Mat__Refinement_builder<Data_Type<cv::Mat_<uchar>>, unsigned char>(Data_Type<cv::Mat_<uchar>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<unsigned char, 2>>>, cv::Vec<unsigned char, 2>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<unsigned char, 2>>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<unsigned char, 3>>>, cv::Vec<unsigned char, 3>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<unsigned char, 3>>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<unsigned char, 4>>>, cv::Vec<unsigned char, 4>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<unsigned char, 4>>>::klass());

  Mat__Refinement_builder<Data_Type<cv::Mat_<uchar>>, short>(Data_Type<cv::Mat_<uchar>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<short, 2>>>, cv::Vec<short, 2>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<short, 2>>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<short, 3>>>, cv::Vec<short, 3>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<short, 3>>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<short, 4>>>, cv::Vec<short, 4>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<short, 4>>>::klass());

  Mat__Refinement_builder<Data_Type<cv::Mat_<uchar>>, unsigned short>(Data_Type<cv::Mat_<uchar>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<unsigned short, 2>>>, cv::Vec<unsigned short, 2>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<unsigned short, 2>>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<unsigned short, 3>>>, cv::Vec<unsigned short, 3>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<unsigned short, 3>>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<unsigned short, 4>>>, cv::Vec<unsigned short, 4>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<unsigned short, 4>>>::klass());

  Mat__Refinement_builder<Data_Type<cv::Mat_<uchar>>, int>(Data_Type<cv::Mat_<uchar>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<int, 2>>>, cv::Vec<int, 2>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<int, 2>>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<int, 3>>>, cv::Vec<int, 3>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<int, 3>>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<int, 4>>>, cv::Vec<int, 4>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<int, 4>>>::klass());

  Mat__Refinement_builder<Data_Type<cv::Mat_<uchar>>, float>(Data_Type<cv::Mat_<uchar>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<float, 2>>>, cv::Vec<float, 2>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<float, 2>>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<float, 3>>>, cv::Vec<float, 3>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<float, 3>>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<float, 4>>>, cv::Vec<float, 4>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<float, 4>>>::klass());

  Mat__Refinement_builder<Data_Type<cv::Mat_<uchar>>, double>(Data_Type<cv::Mat_<uchar>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<double, 2>>>, cv::Vec<double, 2>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<double, 2>>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<double, 3>>>, cv::Vec<double, 3>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<double, 3>>>::klass());
  Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<double, 4>>>, cv::Vec<double, 4>>(Data_Type<cv::Mat_cv::Mat_<cv::Vec<double, 4>>>::klass());
  */
  /*
   
 
  Rice::Class rb_cSparseMat1b = define_class_under<cv::SparseMat_<unsigned char>, cv::SparseMat>(rb_mCv, "SparseMat1b").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<unsigned char>>, unsigned char>);

  Rice::Class rb_cSparseMat2b = define_class_under<cv::SparseMat_<cv::Vec<unsigned char, 2>>, cv::SparseMat>(rb_mCv, "SparseMat2b").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<unsigned char, 2>>>, cv::Vec<unsigned char, 2>>);

  Rice::Class rb_cSparseMat3b = define_class_under<cv::SparseMat_<cv::Vec<unsigned char, 3>>, cv::SparseMat>(rb_mCv, "SparseMat3b").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<unsigned char, 3>>>, cv::Vec<unsigned char, 3>>);

  Rice::Class rb_cSparseMat4b = define_class_under<cv::SparseMat_<cv::Vec<unsigned char, 4>>, cv::SparseMat>(rb_mCv, "SparseMat4b").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<unsigned char, 4>>>, cv::Vec<unsigned char, 4>>);

  Rice::Class rb_cSparseMat1s = define_class_under<cv::SparseMat_<short>, cv::SparseMat>(rb_mCv, "SparseMat1s").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<short>>, short>);

  Rice::Class rb_cSparseMat2s = define_class_under<cv::SparseMat_<cv::Vec<short, 2>>, cv::SparseMat>(rb_mCv, "SparseMat2s").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<short, 2>>>, cv::Vec<short, 2>>);

  Rice::Class rb_cSparseMat3s = define_class_under<cv::SparseMat_<cv::Vec<short, 3>>, cv::SparseMat>(rb_mCv, "SparseMat3s").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<short, 3>>>, cv::Vec<short, 3>>);

  Rice::Class rb_cSparseMat4s = define_class_under<cv::SparseMat_<cv::Vec<short, 4>>, cv::SparseMat>(rb_mCv, "SparseMat4s").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<short, 4>>>, cv::Vec<short, 4>>);

  Rice::Class rb_cSparseMat1w = define_class_under<cv::SparseMat_<unsigned short>, cv::SparseMat>(rb_mCv, "SparseMat1w").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<unsigned short>>, unsigned short>);

  Rice::Class rb_cSparseMat2w = define_class_under<cv::SparseMat_<cv::Vec<unsigned short, 2>>, cv::SparseMat>(rb_mCv, "SparseMat2w").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<unsigned short, 2>>>, cv::Vec<unsigned short, 2>>);

  Rice::Class rb_cSparseMat3w = define_class_under<cv::SparseMat_<cv::Vec<unsigned short, 3>>, cv::SparseMat>(rb_mCv, "SparseMat3w").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<unsigned short, 3>>>, cv::Vec<unsigned short, 3>>);

  Rice::Class rb_cSparseMat4w = define_class_under<cv::SparseMat_<cv::Vec<unsigned short, 4>>, cv::SparseMat>(rb_mCv, "SparseMat4w").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<unsigned short, 4>>>, cv::Vec<unsigned short, 4>>);

  Rice::Class rb_cSparseMat1i = define_class_under<cv::SparseMat_<int>, cv::SparseMat>(rb_mCv, "SparseMat1i").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<int>>, int>);

  Rice::Class rb_cSparseMat2i = define_class_under<cv::SparseMat_<cv::Vec<int, 2>>, cv::SparseMat>(rb_mCv, "SparseMat2i").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<int, 2>>>, cv::Vec<int, 2>>);

  Rice::Class rb_cSparseMat3i = define_class_under<cv::SparseMat_<cv::Vec<int, 3>>, cv::SparseMat>(rb_mCv, "SparseMat3i").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<int, 3>>>, cv::Vec<int, 3>>);

  Rice::Class rb_cSparseMat4i = define_class_under<cv::SparseMat_<cv::Vec<int, 4>>, cv::SparseMat>(rb_mCv, "SparseMat4i").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<int, 4>>>, cv::Vec<int, 4>>);

  Rice::Class rb_cSparseMat1f = define_class_under<cv::SparseMat_<float>, cv::SparseMat>(rb_mCv, "SparseMat1f").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<float>>, float>);

  Rice::Class rb_cSparseMat2f = define_class_under<cv::SparseMat_<cv::Vec<float, 2>>, cv::SparseMat>(rb_mCv, "SparseMat2f").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<float, 2>>>, cv::Vec<float, 2>>);

  Rice::Class rb_cSparseMat3f = define_class_under<cv::SparseMat_<cv::Vec<float, 3>>, cv::SparseMat>(rb_mCv, "SparseMat3f").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<float, 3>>>, cv::Vec<float, 3>>);

  Rice::Class rb_cSparseMat4f = define_class_under<cv::SparseMat_<cv::Vec<float, 4>>, cv::SparseMat>(rb_mCv, "SparseMat4f").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<float, 4>>>, cv::Vec<float, 4>>);

  Rice::Class rb_cSparseMat6f = define_class_under<cv::SparseMat_<cv::Vec<float, 6>>, cv::SparseMat>(rb_mCv, "SparseMat6f").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<float, 6>>>, cv::Vec<float, 6>>);

  Rice::Class rb_cSparseMat1d = define_class_under<cv::SparseMat_<double>, cv::SparseMat>(rb_mCv, "SparseMat1d").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<double>>, double>);

  Rice::Class rb_cSparseMat2d = define_class_under<cv::SparseMat_<cv::Vec<double, 2>>, cv::SparseMat>(rb_mCv, "SparseMat2d").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<double, 2>>>, cv::Vec<double, 2>>);

  Rice::Class rb_cSparseMat3d = define_class_under<cv::SparseMat_<cv::Vec<double, 3>>, cv::SparseMat>(rb_mCv, "SparseMat3d").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<double, 3>>>, cv::Vec<double, 3>>);

  Rice::Class rb_cSparseMat4d = define_class_under<cv::SparseMat_<cv::Vec<double, 4>>, cv::SparseMat>(rb_mCv, "SparseMat4d").
    define(&SparseMat__Refinement_builder<Data_Type<cv::SparseMat_<cv::Vec<double, 4>>>, cv::Vec<double, 4>>);

  Rice::Class rb_cSparseMatConstIterator1b = define_class_under<cv::SparseMatConstIterator_<unsigned char>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator1b").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<unsigned char>>, unsigned char>);

  Rice::Class rb_cSparseMatConstIterator2b = define_class_under<cv::SparseMatConstIterator_<cv::Vec<unsigned char, 2>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator2b").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<unsigned char, 2>>>, cv::Vec<unsigned char, 2>>);

  Rice::Class rb_cSparseMatConstIterator3b = define_class_under<cv::SparseMatConstIterator_<cv::Vec<unsigned char, 3>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator3b").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<unsigned char, 3>>>, cv::Vec<unsigned char, 3>>);

  Rice::Class rb_cSparseMatConstIterator4b = define_class_under<cv::SparseMatConstIterator_<cv::Vec<unsigned char, 4>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator4b").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<unsigned char, 4>>>, cv::Vec<unsigned char, 4>>);

  Rice::Class rb_cSparseMatConstIterator1s = define_class_under<cv::SparseMatConstIterator_<short>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator1s").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<short>>, short>);

  Rice::Class rb_cSparseMatConstIterator2s = define_class_under<cv::SparseMatConstIterator_<cv::Vec<short, 2>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator2s").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<short, 2>>>, cv::Vec<short, 2>>);

  Rice::Class rb_cSparseMatConstIterator3s = define_class_under<cv::SparseMatConstIterator_<cv::Vec<short, 3>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator3s").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<short, 3>>>, cv::Vec<short, 3>>);

  Rice::Class rb_cSparseMatConstIterator4s = define_class_under<cv::SparseMatConstIterator_<cv::Vec<short, 4>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator4s").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<short, 4>>>, cv::Vec<short, 4>>);

  Rice::Class rb_cSparseMatConstIterator1w = define_class_under<cv::SparseMatConstIterator_<unsigned short>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator1w").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<unsigned short>>, unsigned short>);

  Rice::Class rb_cSparseMatConstIterator2w = define_class_under<cv::SparseMatConstIterator_<cv::Vec<unsigned short, 2>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator2w").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<unsigned short, 2>>>, cv::Vec<unsigned short, 2>>);

  Rice::Class rb_cSparseMatConstIterator3w = define_class_under<cv::SparseMatConstIterator_<cv::Vec<unsigned short, 3>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator3w").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<unsigned short, 3>>>, cv::Vec<unsigned short, 3>>);

  Rice::Class rb_cSparseMatConstIterator4w = define_class_under<cv::SparseMatConstIterator_<cv::Vec<unsigned short, 4>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator4w").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<unsigned short, 4>>>, cv::Vec<unsigned short, 4>>);

  Rice::Class rb_cSparseMatConstIterator1i = define_class_under<cv::SparseMatConstIterator_<int>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator1i").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<int>>, int>);

  Rice::Class rb_cSparseMatConstIterator2i = define_class_under<cv::SparseMatConstIterator_<cv::Vec<int, 2>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator2i").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<int, 2>>>, cv::Vec<int, 2>>);

  Rice::Class rb_cSparseMatConstIterator3i = define_class_under<cv::SparseMatConstIterator_<cv::Vec<int, 3>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator3i").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<int, 3>>>, cv::Vec<int, 3>>);

  Rice::Class rb_cSparseMatConstIterator4i = define_class_under<cv::SparseMatConstIterator_<cv::Vec<int, 4>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator4i").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<int, 4>>>, cv::Vec<int, 4>>);

  Rice::Class rb_cSparseMatConstIterator1f = define_class_under<cv::SparseMatConstIterator_<float>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator1f").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<float>>, float>);

  Rice::Class rb_cSparseMatConstIterator2f = define_class_under<cv::SparseMatConstIterator_<cv::Vec<float, 2>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator2f").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<float, 2>>>, cv::Vec<float, 2>>);

  Rice::Class rb_cSparseMatConstIterator3f = define_class_under<cv::SparseMatConstIterator_<cv::Vec<float, 3>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator3f").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<float, 3>>>, cv::Vec<float, 3>>);

  Rice::Class rb_cSparseMatConstIterator4f = define_class_under<cv::SparseMatConstIterator_<cv::Vec<float, 4>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator4f").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<float, 4>>>, cv::Vec<float, 4>>);

  Rice::Class rb_cSparseMatConstIterator6f = define_class_under<cv::SparseMatConstIterator_<cv::Vec<float, 6>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator6f").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<float, 6>>>, cv::Vec<float, 6>>);

  Rice::Class rb_cSparseMatConstIterator1d = define_class_under<cv::SparseMatConstIterator_<double>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator1d").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<double>>, double>);

  Rice::Class rb_cSparseMatConstIterator2d = define_class_under<cv::SparseMatConstIterator_<cv::Vec<double, 2>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator2d").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<double, 2>>>, cv::Vec<double, 2>>);

  Rice::Class rb_cSparseMatConstIterator3d = define_class_under<cv::SparseMatConstIterator_<cv::Vec<double, 3>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator3d").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<double, 3>>>, cv::Vec<double, 3>>);

  Rice::Class rb_cSparseMatConstIterator4d = define_class_under<cv::SparseMatConstIterator_<cv::Vec<double, 4>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator4d").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<double, 4>>>, cv::Vec<double, 4>>);

  Rice::Class rb_cSparseMatIterator1b = define_class_under<cv::SparseMatIterator_<unsigned char>, cv::SparseMatConstIterator_<unsigned char>>(rb_mCv, "SparseMatIterator1b").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<unsigned char>>, unsigned char>);

  Rice::Class rb_cSparseMatIterator2b = define_class_under<cv::SparseMatIterator_<cv::Vec<unsigned char, 2>>, cv::SparseMatConstIterator_<cv::Vec<unsigned char, 2>>>(rb_mCv, "SparseMatIterator2b").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<unsigned char, 2>>>, cv::Vec<unsigned char, 2>>);

  Rice::Class rb_cSparseMatIterator3b = define_class_under<cv::SparseMatIterator_<cv::Vec<unsigned char, 3>>, cv::SparseMatConstIterator_<cv::Vec<unsigned char, 3>>>(rb_mCv, "SparseMatIterator3b").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<unsigned char, 3>>>, cv::Vec<unsigned char, 3>>);

  Rice::Class rb_cSparseMatIterator4b = define_class_under<cv::SparseMatIterator_<cv::Vec<unsigned char, 4>>, cv::SparseMatConstIterator_<cv::Vec<unsigned char, 4>>>(rb_mCv, "SparseMatIterator4b").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<unsigned char, 4>>>, cv::Vec<unsigned char, 4>>);

  Rice::Class rb_cSparseMatIterator1s = define_class_under<cv::SparseMatIterator_<short>, cv::SparseMatConstIterator_<short>>(rb_mCv, "SparseMatIterator1s").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<short>>, short>);

  Rice::Class rb_cSparseMatIterator2s = define_class_under<cv::SparseMatIterator_<cv::Vec<short, 2>>, cv::SparseMatConstIterator_<cv::Vec<short, 2>>>(rb_mCv, "SparseMatIterator2s").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<short, 2>>>, cv::Vec<short, 2>>);

  Rice::Class rb_cSparseMatIterator3s = define_class_under<cv::SparseMatIterator_<cv::Vec<short, 3>>, cv::SparseMatConstIterator_<cv::Vec<short, 3>>>(rb_mCv, "SparseMatIterator3s").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<short, 3>>>, cv::Vec<short, 3>>);

  Rice::Class rb_cSparseMatIterator4s = define_class_under<cv::SparseMatIterator_<cv::Vec<short, 4>>, cv::SparseMatConstIterator_<cv::Vec<short, 4>>>(rb_mCv, "SparseMatIterator4s").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<short, 4>>>, cv::Vec<short, 4>>);

  Rice::Class rb_cSparseMatIterator1w = define_class_under<cv::SparseMatIterator_<unsigned short>, cv::SparseMatConstIterator_<unsigned short>>(rb_mCv, "SparseMatIterator1w").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<unsigned short>>, unsigned short>);

  Rice::Class rb_cSparseMatIterator2w = define_class_under<cv::SparseMatIterator_<cv::Vec<unsigned short, 2>>, cv::SparseMatConstIterator_<cv::Vec<unsigned short, 2>>>(rb_mCv, "SparseMatIterator2w").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<unsigned short, 2>>>, cv::Vec<unsigned short, 2>>);

  Rice::Class rb_cSparseMatIterator3w = define_class_under<cv::SparseMatIterator_<cv::Vec<unsigned short, 3>>, cv::SparseMatConstIterator_<cv::Vec<unsigned short, 3>>>(rb_mCv, "SparseMatIterator3w").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<unsigned short, 3>>>, cv::Vec<unsigned short, 3>>);

  Rice::Class rb_cSparseMatIterator4w = define_class_under<cv::SparseMatIterator_<cv::Vec<unsigned short, 4>>, cv::SparseMatConstIterator_<cv::Vec<unsigned short, 4>>>(rb_mCv, "SparseMatIterator4w").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<unsigned short, 4>>>, cv::Vec<unsigned short, 4>>);

  Rice::Class rb_cSparseMatIterator1i = define_class_under<cv::SparseMatIterator_<int>, cv::SparseMatConstIterator_<int>>(rb_mCv, "SparseMatIterator1i").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<int>>, int>);

  Rice::Class rb_cSparseMatIterator2i = define_class_under<cv::SparseMatIterator_<cv::Vec<int, 2>>, cv::SparseMatConstIterator_<cv::Vec<int, 2>>>(rb_mCv, "SparseMatIterator2i").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<int, 2>>>, cv::Vec<int, 2>>);

  Rice::Class rb_cSparseMatIterator3i = define_class_under<cv::SparseMatIterator_<cv::Vec<int, 3>>, cv::SparseMatConstIterator_<cv::Vec<int, 3>>>(rb_mCv, "SparseMatIterator3i").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<int, 3>>>, cv::Vec<int, 3>>);

  Rice::Class rb_cSparseMatIterator4i = define_class_under<cv::SparseMatIterator_<cv::Vec<int, 4>>, cv::SparseMatConstIterator_<cv::Vec<int, 4>>>(rb_mCv, "SparseMatIterator4i").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<int, 4>>>, cv::Vec<int, 4>>);

  Rice::Class rb_cSparseMatIterator1f = define_class_under<cv::SparseMatIterator_<float>, cv::SparseMatConstIterator_<float>>(rb_mCv, "SparseMatIterator1f").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<float>>, float>);

  Rice::Class rb_cSparseMatIterator2f = define_class_under<cv::SparseMatIterator_<cv::Vec<float, 2>>, cv::SparseMatConstIterator_<cv::Vec<float, 2>>>(rb_mCv, "SparseMatIterator2f").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<float, 2>>>, cv::Vec<float, 2>>);

  Rice::Class rb_cSparseMatIterator3f = define_class_under<cv::SparseMatIterator_<cv::Vec<float, 3>>, cv::SparseMatConstIterator_<cv::Vec<float, 3>>>(rb_mCv, "SparseMatIterator3f").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<float, 3>>>, cv::Vec<float, 3>>);

  Rice::Class rb_cSparseMatIterator4f = define_class_under<cv::SparseMatIterator_<cv::Vec<float, 4>>, cv::SparseMatConstIterator_<cv::Vec<float, 4>>>(rb_mCv, "SparseMatIterator4f").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<float, 4>>>, cv::Vec<float, 4>>);

  Rice::Class rb_cSparseMatIterator6f = define_class_under<cv::SparseMatIterator_<cv::Vec<float, 6>>, cv::SparseMatConstIterator_<cv::Vec<float, 6>>>(rb_mCv, "SparseMatIterator6f").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<float, 6>>>, cv::Vec<float, 6>>);

  Rice::Class rb_cSparseMatIterator1d = define_class_under<cv::SparseMatIterator_<double>, cv::SparseMatConstIterator_<double>>(rb_mCv, "SparseMatIterator1d").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<double>>, double>);

  Rice::Class rb_cSparseMatIterator2d = define_class_under<cv::SparseMatIterator_<cv::Vec<double, 2>>, cv::SparseMatConstIterator_<cv::Vec<double, 2>>>(rb_mCv, "SparseMatIterator2d").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<double, 2>>>, cv::Vec<double, 2>>);

  Rice::Class rb_cSparseMatIterator3d = define_class_under<cv::SparseMatIterator_<cv::Vec<double, 3>>, cv::SparseMatConstIterator_<cv::Vec<double, 3>>>(rb_mCv, "SparseMatIterator3d").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<double, 3>>>, cv::Vec<double, 3>>);

  Rice::Class rb_cSparseMatIterator4d = define_class_under<cv::SparseMatIterator_<cv::Vec<double, 4>>, cv::SparseMatConstIterator_<cv::Vec<double, 4>>>(rb_mCv, "SparseMatIterator4d").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<double, 4>>>, cv::Vec<double, 4>>);

  Rice::Data_Type<cv::Mat_<cv::Vec<float, 6>>> rb_cMat6f = define_class_under<cv::Mat_<cv::Vec<float, 6>>, cv::Mat>(rb_mCv, "Mat6f").
    define(&Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<float, 6>>>, cv::Vec<float, 6>>);

  Rice::Data_Type<cv::Mat_<cv::Vec<float, 6>>> rb_cMat6f = define_class_under<cv::Mat_<cv::Vec<float, 6>>, cv::Mat>(rb_mCv, "Mat6f").
    define(&Mat__Refinement_builder<Data_Type<cv::Mat_<cv::Vec<float, 6>>>, cv::Vec<float, 6>>);

  // Define friendly class names for Pointer<T>
  define_pointer<cv::Vec<unsigned char, 2>>(u8"Pointer≺Cv꞉꞉Vec2b≻");
  define_pointer<cv::Vec<unsigned char, 3>>(u8"Pointer≺Cv꞉꞉Vec3b≻");
  define_pointer<cv::Vec<unsigned char, 4>>(u8"Pointer≺Cv꞉꞉Vec3b≻");
  define_pointer<cv::Vec<short, 2>>(u8"Pointer≺Cv꞉꞉Vec2s≻");
  define_pointer<cv::Vec<short, 3>>(u8"Pointer≺Cv꞉꞉Vec3s≻");
  define_pointer<cv::Vec<short, 4>>(u8"Pointer≺Cv꞉꞉Vec4s≻");
  define_pointer<cv::Vec<unsigned short, 2>>(u8"Pointer≺Cv꞉꞉Vec2w≻");
  define_pointer<cv::Vec<unsigned short, 3>>(u8"Pointer≺Cv꞉꞉Vec3w≻");
  define_pointer<cv::Vec<unsigned short, 4>>(u8"Pointer≺Cv꞉꞉Vec4w≻");
  define_pointer<cv::Vec<int, 2>>(u8"Pointer≺Cv꞉꞉Vec2b≻");
  define_pointer<cv::Vec<int, 3>>(u8"Pointer≺Cv꞉꞉Vec3i≻");
  define_pointer<cv::Vec<int, 4>>(u8"Pointer≺Cv꞉꞉Vec4i");
  define_pointer<cv::Vec<float, 2>>(u8"Pointer≺Cv꞉꞉Vec2f≻");
  define_pointer<cv::Vec<float, 3>>(u8"Pointer≺Cv꞉꞉Vec3f≻");
  define_pointer<cv::Vec<float, 4>>(u8"Pointer≺Cv꞉꞉Vec4f≻");
  define_pointer<cv::Vec<float, 6>>(u8"Pointer≺Cv꞉꞉Vec6f≻");
  define_pointer<cv::Vec<double, 2>>(u8"Pointer≺Cv꞉꞉Vec2d≻");
  define_pointer<cv::Vec<double, 3>>(u8"Pointer≺Cv꞉꞉Vec3d≻");
  define_pointer<cv::Vec<double, 4>>(u8"Pointer≺Cv꞉꞉Vec4d≻");

  // Define friendly class names for Buffer<T>
  define_buffer<cv::Vec<unsigned char, 2>>(u8"Buffer≺Cv꞉꞉Vec2b≻");
  define_buffer<cv::Vec<unsigned char, 3>>(u8"Buffer≺Cv꞉꞉Vec3b≻");
  define_buffer<cv::Vec<unsigned char, 4>>(u8"Buffer≺Cv꞉꞉Vec3b≻");
  define_buffer<cv::Vec<short, 2>>(u8"Buffer≺Cv꞉꞉Vec2s≻");
  define_buffer<cv::Vec<short, 3>>(u8"Buffer≺Cv꞉꞉Vec3s≻");
  define_buffer<cv::Vec<short, 4>>(u8"Buffer≺Cv꞉꞉Vec4s≻");
  define_buffer<cv::Vec<unsigned short, 2>>(u8"Buffer≺Cv꞉꞉Vec2w≻");
  define_buffer<cv::Vec<unsigned short, 3>>(u8"Buffer≺Cv꞉꞉Vec3w≻");
  define_buffer<cv::Vec<unsigned short, 4>>(u8"Buffer≺Cv꞉꞉Vec4w≻");
  define_buffer<cv::Vec<int, 2>>(u8"Buffer≺Cv꞉꞉Vec2b≻");
  define_buffer<cv::Vec<int, 3>>(u8"Buffer≺Cv꞉꞉Vec3i≻");
  define_buffer<cv::Vec<int, 4>>(u8"Buffer≺Cv꞉꞉Vec4i");
  define_buffer<cv::Vec<float, 2>>(u8"Buffer≺Cv꞉꞉Vec2f≻");
  define_buffer<cv::Vec<float, 3>>(u8"Buffer≺Cv꞉꞉Vec3f≻");
  define_buffer<cv::Vec<float, 4>>(u8"Buffer≺Cv꞉꞉Vec4f≻");
  define_buffer<cv::Vec<float, 6>>(u8"Buffer≺Cv꞉꞉Vec6f≻");
  define_buffer<cv::Vec<double, 2>>(u8"Buffer≺Cv꞉꞉Vec2d≻");
  define_buffer<cv::Vec<double, 3>>(u8"Buffer≺Cv꞉꞉Vec3d≻");
  define_buffer<cv::Vec<double, 4>>(u8"Buffer≺Cv꞉꞉Vec4d≻");*/
}
