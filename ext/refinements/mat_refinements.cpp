#include <rice/rice.hpp>
#include <rice/stl.hpp>
#include <opencv2/core/mat.hpp>
#include <sstream>
#include <variant>

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

void Mat_refinements(Rice::Class& rb_cCvMat)
{
  // Element access operator []
  rb_cCvMat.define_method("[]", [](const cv::Mat& self, int x, int y) -> Variant_T
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
  rb_define_alias(rb_cCvMat, "at", "[]");

  // Element assignment operator []=
  rb_cCvMat.define_method("[]=", [](cv::Mat& self, int x, int y, Variant_T value) -> cv::Mat&
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
  rb_cCvMat.define_method("ptr", [](cv::Mat& self, int row) -> Buffer_Variant_T
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
  rb_cCvMat.include_module(rb_mEnumerable).
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
}
