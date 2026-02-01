#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/mat.hpp>
#include "mat-rb.hpp"
#include "../opencv2/core/mat-rb.ipp"
#include "mat-iterators.hpp"

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

template<typename _Tp>
inline void Mat__Refinements()
{
  Data_Type<cv::Mat_<_Tp>>().
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

template<typename _Tp>
inline void SparseMat__Refinements()
{
  // Manual
  Data_Type<cv::SparseMat_<_Tp>>().
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

  // -------- Mat -----------
  Rice::Data_Type<cv::Mat> mat;

  mat.
    define_method("data", [](cv::Mat& self) -> VALUE
    {
      size_t byteSize = 0;
      if (self.isContinuous() || self.dims > 2)
      {
        byteSize = self.total() * self.elemSize();
      }
      else
      {
        byteSize = self.step[0] * self.rows;
      }

      return detail::protect(rb_usascii_str_new_static, (const char*)self.data, (long)byteSize);
    }, Return().setValue()).
    define_method("input_array", [](cv::Mat& self) -> cv::_InputArray
    {
      return cv::_InputArray(self);
    }).
    define_method("output_array", [](cv::Mat& self) -> cv::_OutputArray
    {
      return cv::_OutputArray(self);
    }).
    define_method("input_output_array", [](cv::Mat& self) -> cv::_InputOutputArray
    {
      return cv::_InputOutputArray(self);
    }).
    define_method("inspect", [](const cv::Mat& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    }).
    define_method("[]", [](const cv::Mat& self, int x, int y) -> Variant_T
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
    }).
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
    }).
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

  rb_define_alias(mat.value(), "at", "[]");

  // Setup iteration with Enumerable
  mat.
    include_module(rb_mEnumerable).
    define_method("each", [](VALUE self, VALUE /*proc*/) -> VALUE
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
    }, Arg("proc").setValue() = Qnil, Return().setValue());

  // ------  MatSize ----------
  Rice::Data_Type<cv::MatSize> matSize;
  matSize.
    define_method("inspect", [](const cv::MatSize& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });

  // ------  Umat ----------
  Data_Type<cv::UMat>().
    define_method("inspect", [](const cv::UMat& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });

  // ------  InputArray ----------
  Rice::Data_Type<cv::_InputArray> inputArray;
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

  // ------  OutputArray ----------
  Rice::Data_Type<cv::_OutputArray> outputArray;
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

  // First process the mat_ classes already constructed in mat-rb.cpp
  Mat__Refinements<unsigned char>();
  Mat__Refinements<cv::Vec<unsigned char, 2>>();
  Mat__Refinements<cv::Vec<unsigned char, 3>>();
  Mat__Refinements<cv::Vec<unsigned char, 4>>();

  Mat__Refinements<short>();
  Mat__Refinements<cv::Vec<short, 2>>();
  Mat__Refinements<cv::Vec<short, 3>>();
  Mat__Refinements<cv::Vec<short, 4>>();

  Mat__Refinements<unsigned short>();
  Mat__Refinements<cv::Vec<unsigned short, 2>>();
  Mat__Refinements<cv::Vec<unsigned short, 3>>();
  Mat__Refinements<cv::Vec<unsigned short, 4>>();

  Mat__Refinements<int>();
  Mat__Refinements<cv::Vec<int, 2>>();
  Mat__Refinements<cv::Vec<int, 3>>();
  Mat__Refinements<cv::Vec<int, 4>>();

  Mat__Refinements<float>();
  Mat__Refinements<cv::Vec<float, 2>>();
  Mat__Refinements<cv::Vec<float, 3>>();
  Mat__Refinements<cv::Vec<float, 4>>();

  Mat__Refinements<double>();
  Mat__Refinements<cv::Vec<double, 2>>();
  Mat__Refinements<cv::Vec<double, 3>>();
  Mat__Refinements<cv::Vec<double, 4>>();

  // New mat_ classs
  Mat__instantiate<cv::Vec<float, 6>>(rb_mCv, "Mat6f");
  Mat__Refinements<cv::Vec<float, 6>>();
   
  SparseMat__instantiate<unsigned char>(rb_mCv, "SparseMat1b");
  SparseMat__Refinements<unsigned char>();
  SparseMat__instantiate<cv::Vec<unsigned char, 2>>(rb_mCv, "SparseMat2b");
  SparseMat__Refinements<cv::Vec<unsigned char, 2>>();
  SparseMat__instantiate<cv::Vec<unsigned char, 3>>(rb_mCv, "SparseMat3b");
  SparseMat__Refinements<cv::Vec<unsigned char, 3>>();
  SparseMat__instantiate<cv::Vec<unsigned char, 4>>(rb_mCv, "SparseMat4b");
  SparseMat__Refinements<cv::Vec<unsigned char, 4>>();
  SparseMat__instantiate<short>(rb_mCv, "SparseMat1s");
  SparseMat__Refinements<short>();
  SparseMat__instantiate<cv::Vec<short, 2>>(rb_mCv, "SparseMat2s");
  SparseMat__Refinements<cv::Vec<short, 2>>();
  SparseMat__instantiate<cv::Vec<short, 3>>(rb_mCv, "SparseMat3s");
  SparseMat__Refinements<cv::Vec<short, 3>>();
  SparseMat__instantiate<cv::Vec<short, 4>>(rb_mCv, "SparseMat4s");
  SparseMat__Refinements<cv::Vec<short, 4>>();
  SparseMat__instantiate<unsigned short>(rb_mCv, "SparseMat1w");
  SparseMat__Refinements<unsigned short>();
  SparseMat__instantiate<cv::Vec<unsigned short, 2>>(rb_mCv, "SparseMat2w");
  SparseMat__Refinements<cv::Vec<unsigned short, 2>>();
  SparseMat__instantiate<cv::Vec<unsigned short, 3>>(rb_mCv, "SparseMat3w");
  SparseMat__Refinements<cv::Vec<unsigned short, 3>>();
  SparseMat__instantiate<cv::Vec<unsigned short, 4>>(rb_mCv, "SparseMat4w");
  SparseMat__Refinements<cv::Vec<unsigned short, 4>>();
  SparseMat__instantiate<int>(rb_mCv, "SparseMat1i");
  SparseMat__Refinements<int>();
  SparseMat__instantiate<cv::Vec<int, 2>>(rb_mCv, "SparseMat2i");
  SparseMat__Refinements<cv::Vec<int, 2>>();
  SparseMat__instantiate<cv::Vec<int, 3>>(rb_mCv, "SparseMat3i");
  SparseMat__Refinements<cv::Vec<int, 3>>();
  SparseMat__instantiate<cv::Vec<int, 4>>(rb_mCv, "SparseMat4i");
  SparseMat__Refinements<cv::Vec<int, 4>>();
  SparseMat__instantiate<float>(rb_mCv, "SparseMat1f");
  SparseMat__Refinements<float>();
  SparseMat__instantiate<cv::Vec<float, 2>>(rb_mCv, "SparseMat2f");
  SparseMat__Refinements<cv::Vec<float, 2>>();
  SparseMat__instantiate<cv::Vec<float, 3>>(rb_mCv, "SparseMat3f");
  SparseMat__Refinements<cv::Vec<float, 3>>();
  SparseMat__instantiate<cv::Vec<float, 4>>(rb_mCv, "SparseMat4f");
  SparseMat__Refinements<cv::Vec<float, 4>>();
  SparseMat__instantiate<cv::Vec<float, 6>>(rb_mCv, "SparseMat6f");
  SparseMat__Refinements<cv::Vec<float, 6>>();
  SparseMat__instantiate<double>(rb_mCv, "SparseMat1d");
  SparseMat__Refinements<double>();
  SparseMat__instantiate<cv::Vec<double, 2>>(rb_mCv, "SparseMat2d");
  SparseMat__Refinements<cv::Vec<double, 2>>();
  SparseMat__instantiate<cv::Vec<double, 3>>(rb_mCv, "SparseMat3d");
  SparseMat__Refinements<cv::Vec<double, 3>>();
  SparseMat__instantiate<cv::Vec<double, 4>>(rb_mCv, "SparseMat4d");
  SparseMat__Refinements<cv::Vec<double, 4>>();

  SparseMatConstIterator__instantiate<unsigned char>(rb_mCv, "SparseMatConstIterator1b");
  SparseMatConstIterator__instantiate<cv::Vec<unsigned char, 2>>(rb_mCv, "SparseMatConstIterator2b");
  SparseMatConstIterator__instantiate<cv::Vec<unsigned char, 3>>(rb_mCv, "SparseMatConstIterator3b");
  SparseMatConstIterator__instantiate<cv::Vec<unsigned char, 4>>(rb_mCv, "SparseMatConstIterator4b");
  SparseMatConstIterator__instantiate<short>(rb_mCv, "SparseMatConstIterator1s");
  SparseMatConstIterator__instantiate<cv::Vec<short, 2>>(rb_mCv, "SparseMatConstIterator2s");
  SparseMatConstIterator__instantiate<cv::Vec<short, 3>>(rb_mCv, "SparseMatConstIterator3s");
  SparseMatConstIterator__instantiate<cv::Vec<short, 4>>(rb_mCv, "SparseMatConstIterator4s");
  SparseMatConstIterator__instantiate<unsigned short>(rb_mCv, "SparseMatConstIterator1w");
  SparseMatConstIterator__instantiate<cv::Vec<unsigned short, 2>>(rb_mCv, "SparseMatConstIterator2w");
  SparseMatConstIterator__instantiate<cv::Vec<unsigned short, 3>>(rb_mCv, "SparseMatConstIterator3w");
  SparseMatConstIterator__instantiate<cv::Vec<unsigned short, 4>>(rb_mCv, "SparseMatConstIterator4w");
  SparseMatConstIterator__instantiate<int>(rb_mCv, "SparseMatConstIterator1i");
  SparseMatConstIterator__instantiate<cv::Vec<int, 2>>(rb_mCv, "SparseMatConstIterator2i");
  SparseMatConstIterator__instantiate<cv::Vec<int, 3>>(rb_mCv, "SparseMatConstIterator3i");
  SparseMatConstIterator__instantiate<cv::Vec<int, 4>>(rb_mCv, "SparseMatConstIterator4i");
  SparseMatConstIterator__instantiate<float>(rb_mCv, "SparseMatConstIterator1f");
  SparseMatConstIterator__instantiate<cv::Vec<float, 2>>(rb_mCv, "SparseMatConstIterator2f");
  SparseMatConstIterator__instantiate<cv::Vec<float, 3>>(rb_mCv, "SparseMatConstIterator3f");
  SparseMatConstIterator__instantiate<cv::Vec<float, 4>>(rb_mCv, "SparseMatConstIterator4f");
  SparseMatConstIterator__instantiate<cv::Vec<float, 6>>(rb_mCv, "SparseMatConstIterator6f");
  SparseMatConstIterator__instantiate<double>(rb_mCv, "SparseMatConstIterator1d");
  SparseMatConstIterator__instantiate<cv::Vec<double, 2>>(rb_mCv, "SparseMatConstIterator2d");
  SparseMatConstIterator__instantiate<cv::Vec<double, 3>>(rb_mCv, "SparseMatConstIterator3d");
  SparseMatConstIterator__instantiate<cv::Vec<double, 4>>(rb_mCv, "SparseMatConstIterator4d");

  SparseMatIterator__instantiate<unsigned char>(rb_mCv, "SparseMatIterator1b");
  SparseMatIterator__instantiate<cv::Vec<unsigned char, 2>>(rb_mCv, "SparseMatIterator2b");
  SparseMatIterator__instantiate<cv::Vec<unsigned char, 3>>(rb_mCv, "SparseMatIterator3b");
  SparseMatIterator__instantiate<cv::Vec<unsigned char, 4>>(rb_mCv, "SparseMatIterator4b");
  SparseMatIterator__instantiate<short>(rb_mCv, "SparseMatIterator1s");
  SparseMatIterator__instantiate<cv::Vec<short, 2>>(rb_mCv, "SparseMatIterator2s");
  SparseMatIterator__instantiate<cv::Vec<short, 3>>(rb_mCv, "SparseMatIterator3s");
  SparseMatIterator__instantiate<cv::Vec<short, 4>>(rb_mCv, "SparseMatIterator4s");
  SparseMatIterator__instantiate<unsigned short>(rb_mCv, "SparseMatIterator1w");
  SparseMatIterator__instantiate<cv::Vec<unsigned short, 2>>(rb_mCv, "SparseMatIterator2w");
  SparseMatIterator__instantiate<cv::Vec<unsigned short, 3>>(rb_mCv, "SparseMatIterator3w");
  SparseMatIterator__instantiate<cv::Vec<unsigned short, 4>>(rb_mCv, "SparseMatIterator4w");
  SparseMatIterator__instantiate<int>(rb_mCv, "SparseMatIterator1i");
  SparseMatIterator__instantiate<cv::Vec<int, 2>>(rb_mCv, "SparseMatIterator2i");
  SparseMatIterator__instantiate<cv::Vec<int, 3>>(rb_mCv, "SparseMatIterator3i");
  SparseMatIterator__instantiate<cv::Vec<int, 4>>(rb_mCv, "SparseMatIterator4i");
  SparseMatIterator__instantiate<float>(rb_mCv, "SparseMatIterator1f");
  SparseMatIterator__instantiate<cv::Vec<float, 2>>(rb_mCv, "SparseMatIterator2f");
  SparseMatIterator__instantiate<cv::Vec<float, 3>>(rb_mCv, "SparseMatIterator3f");
  SparseMatIterator__instantiate<cv::Vec<float, 4>>(rb_mCv, "SparseMatIterator4f");
  SparseMatIterator__instantiate<cv::Vec<float, 6>>(rb_mCv, "SparseMatIterator6f");
  SparseMatIterator__instantiate<double>(rb_mCv, "SparseMatIterator1d");
  SparseMatIterator__instantiate<cv::Vec<double, 2>>(rb_mCv, "SparseMatIterator2d");
  SparseMatIterator__instantiate<cv::Vec<double, 3>>(rb_mCv, "SparseMatIterator3d");
  SparseMatIterator__instantiate<cv::Vec<double, 4>>(rb_mCv, "SparseMatIterator4d");

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
  define_buffer<cv::Vec<double, 4>>(u8"Buffer≺Cv꞉꞉Vec4d≻");
}
