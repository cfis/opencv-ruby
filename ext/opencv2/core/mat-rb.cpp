#include <opencv2/core/cuda.hpp>
#include <opencv2/core/opengl.hpp>
#include <opencv2/core/mat.hpp>

#include "types-rb.hpp"
#include "mat-rb.hpp"

using namespace Rice;

Data_Type<cv::_InputArray> rb_cCvInputArray;
Rice::Class rb_cCvInputOutputArray;
Rice::Class rb_cCvMat;
Rice::Class rb_cCvMatAllocator;
Rice::Class rb_cCvMatConstIterator;
Rice::Class rb_cCvMatExpr;
Rice::Class rb_cCvMatOp;
Rice::Class rb_cCvMatSize;
Rice::Class rb_cCvMatStep;
Rice::Class rb_cCvNAryMatIterator;
Data_Type<cv::_OutputArray> rb_cCvOutputArray;
Rice::Class rb_cCvSparseMat;
Rice::Class rb_cCvSparseMatConstIterator;
Rice::Class rb_cCvSparseMatHdr;
Rice::Class rb_cCvSparseMatIterator;
Rice::Class rb_cCvSparseMatNode;
Rice::Class rb_cCvUMat;
Rice::Class rb_cCvUMatData;
Rice::Class rb_cMat1b;
Rice::Class rb_cMat1d;
Rice::Class rb_cMat1f;
Rice::Class rb_cMat1i;
Rice::Class rb_cMat1s;
Rice::Class rb_cMat1w;
Rice::Class rb_cMat2b;
Rice::Class rb_cMat2d;
Rice::Class rb_cMat2f;
Rice::Class rb_cMat2i;
Rice::Class rb_cMat2s;
Rice::Class rb_cMat2w;
Rice::Class rb_cMat3b;
Rice::Class rb_cMat3d;
Rice::Class rb_cMat3f;
Rice::Class rb_cMat3i;
Rice::Class rb_cMat3s;
Rice::Class rb_cMat3w;
Rice::Class rb_cMat4b;
Rice::Class rb_cMat4d;
Rice::Class rb_cMat4f;
Rice::Class rb_cMat6f;
Rice::Class rb_cMat4i;
Rice::Class rb_cMat4s;
Rice::Class rb_cMat4w;
Rice::Class rb_cSparseMat1b;
Rice::Class rb_cSparseMat1d;
Rice::Class rb_cSparseMat1f;
Rice::Class rb_cSparseMat1i;
Rice::Class rb_cSparseMat1s;
Rice::Class rb_cSparseMat1w;
Rice::Class rb_cSparseMat2b;
Rice::Class rb_cSparseMat2d;
Rice::Class rb_cSparseMat2f;
Rice::Class rb_cSparseMat2i;
Rice::Class rb_cSparseMat2s;
Rice::Class rb_cSparseMat2w;
Rice::Class rb_cSparseMat3b;
Rice::Class rb_cSparseMat3d;
Rice::Class rb_cSparseMat3f;
Rice::Class rb_cSparseMat3i;
Rice::Class rb_cSparseMat3s;
Rice::Class rb_cSparseMat3w;
Rice::Class rb_cSparseMat4b;
Rice::Class rb_cSparseMat4d;
Rice::Class rb_cSparseMat4f;
Rice::Class rb_cSparseMat6f;
Rice::Class rb_cSparseMat4i;
Rice::Class rb_cSparseMat4s;
Rice::Class rb_cSparseMat4w;

Rice::Class rb_cSparseMatConstIterator1b;
Rice::Class rb_cSparseMatConstIterator1d;
Rice::Class rb_cSparseMatConstIterator1f;
Rice::Class rb_cSparseMatConstIterator1i;
Rice::Class rb_cSparseMatConstIterator1s;
Rice::Class rb_cSparseMatConstIterator1w;
Rice::Class rb_cSparseMatConstIterator2b;
Rice::Class rb_cSparseMatConstIterator2d;
Rice::Class rb_cSparseMatConstIterator2f;
Rice::Class rb_cSparseMatConstIterator2i;
Rice::Class rb_cSparseMatConstIterator2s;
Rice::Class rb_cSparseMatConstIterator2w;
Rice::Class rb_cSparseMatConstIterator3b;
Rice::Class rb_cSparseMatConstIterator3d;
Rice::Class rb_cSparseMatConstIterator3f;
Rice::Class rb_cSparseMatConstIterator3i;
Rice::Class rb_cSparseMatConstIterator3s;
Rice::Class rb_cSparseMatConstIterator3w;
Rice::Class rb_cSparseMatConstIterator4b;
Rice::Class rb_cSparseMatConstIterator4d;
Rice::Class rb_cSparseMatConstIterator4f;
Rice::Class rb_cSparseMatConstIterator6f;
Rice::Class rb_cSparseMatConstIterator4i;
Rice::Class rb_cSparseMatConstIterator4s;
Rice::Class rb_cSparseMatConstIterator4w;

Rice::Class rb_cSparseMatIterator1b;
Rice::Class rb_cSparseMatIterator1d;
Rice::Class rb_cSparseMatIterator1f;
Rice::Class rb_cSparseMatIterator1i;
Rice::Class rb_cSparseMatIterator1s;
Rice::Class rb_cSparseMatIterator1w;
Rice::Class rb_cSparseMatIterator2b;
Rice::Class rb_cSparseMatIterator2d;
Rice::Class rb_cSparseMatIterator2f;
Rice::Class rb_cSparseMatIterator2i;
Rice::Class rb_cSparseMatIterator2s;
Rice::Class rb_cSparseMatIterator2w;
Rice::Class rb_cSparseMatIterator3b;
Rice::Class rb_cSparseMatIterator3d;
Rice::Class rb_cSparseMatIterator3f;
Rice::Class rb_cSparseMatIterator3i;
Rice::Class rb_cSparseMatIterator3s;
Rice::Class rb_cSparseMatIterator3w;
Rice::Class rb_cSparseMatIterator4b;
Rice::Class rb_cSparseMatIterator4d;
Rice::Class rb_cSparseMatIterator4f;
Rice::Class rb_cSparseMatIterator6f;
Rice::Class rb_cSparseMatIterator4i;
Rice::Class rb_cSparseMatIterator4s;
Rice::Class rb_cSparseMatIterator4w;

template<typename Data_Type_T, typename _Tp>
inline void MatCommaInitializer__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::MatCommaInitializer_<_Tp>, cv::Mat_<_Tp>*>(),
      Arg("_m")).
    define_method("to_mat_", [](const cv::MatCommaInitializer_<_Tp>& self) -> cv::Mat_<_Tp>
    {
      return self;
    });
};

template<typename Data_Type_T, typename _Tp>
inline void Mat__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Mat_<_Tp>>()).
    define_constructor(Constructor<cv::Mat_<_Tp>, int, int>(),
      Arg("_rows"), Arg("_cols")).
    define_constructor(Constructor<cv::Mat_<_Tp>, int, int, const _Tp&>(),
      Arg("_rows"), Arg("_cols"), Arg("value")).
    define_constructor(Constructor<cv::Mat_<_Tp>, cv::Size>(),
      Arg("_size")).
    define_constructor(Constructor<cv::Mat_<_Tp>, cv::Size, const _Tp&>(),
      Arg("_size"), Arg("value")).
    define_constructor(Constructor<cv::Mat_<_Tp>, int, const int*>(),
      Arg("_ndims"), Arg("_sizes")).
    define_constructor(Constructor<cv::Mat_<_Tp>, int, const int*, const _Tp&>(),
      Arg("_ndims"), Arg("_sizes"), Arg("value")).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Mat_<_Tp>&>(),
      Arg("m")).
    define_constructor(Constructor<cv::Mat_<_Tp>, int, int, _Tp*, ::size_t>(),
      Arg("_rows"), Arg("_cols"), ArgBuffer("_data"), Arg("_step") = static_cast<size_t>(cv::Mat::AUTO_STEP)).
    define_constructor(Constructor<cv::Mat_<_Tp>, int, const int*, _Tp*, const ::size_t*>(),
      Arg("_ndims"), ArgBuffer("_sizes"), ArgBuffer("_data"), Arg("_steps") = static_cast<const size_t *>(0)).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Mat_<_Tp>&, const cv::Range&, const cv::Range&>(),
      Arg("m"), Arg("row_range"), Arg("col_range") = static_cast<const cv::Range &>(cv::Range::all())).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Mat_<_Tp>&, const cv::Rect&>(),
      Arg("m"), Arg("roi")).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Mat_<_Tp>&, const cv::Range*>(),
      Arg("m"), ArgBuffer("ranges")).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Mat_<_Tp>&, const std::vector<cv::Range>&>(),
      Arg("m"), Arg("ranges")).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::MatExpr&>(),
      Arg("e")).
    define_constructor(Constructor<cv::Mat_<_Tp>, const std::vector<_Tp>&, bool>(),
      Arg("vec"), Arg("copy_data") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Point_<typename cv::DataType<_Tp>::channel_type>&, bool>(),
      Arg("pt"), Arg("copy_data") = static_cast<bool>(true)).
    define_constructor(Constructor<cv::Mat_<_Tp>, const cv::Point3_<typename cv::DataType<_Tp>::channel_type>&, bool>(),
      Arg("pt"), Arg("copy_data") = static_cast<bool>(true)).
    //define_constructor(Constructor<cv::Mat_<_Tp>, const cv::MatCommaInitializer_<_Tp>&>(),
    //  Arg("comma_initializer")).
    template define_iterator<typename cv::Mat_<_Tp>::iterator(cv::Mat_<_Tp>::*)()>(&cv::Mat_<_Tp>::begin, &cv::Mat_<_Tp>::end, "each").
    template define_iterator<typename cv::Mat_<_Tp>::const_iterator(cv::Mat_<_Tp>::*)() const>(&cv::Mat_<_Tp>::begin, &cv::Mat_<_Tp>::end, "each_const").
    template define_iterator<std::reverse_iterator<typename cv::Mat_<_Tp>::iterator>(cv::Mat_<_Tp>::*)()>(&cv::Mat_<_Tp>::rbegin, &cv::Mat_<_Tp>::rend, "each_reverse").
    template define_iterator<std::reverse_iterator<typename cv::Mat_<_Tp>::const_iterator>(cv::Mat_<_Tp>::*)() const>(&cv::Mat_<_Tp>::rbegin, &cv::Mat_<_Tp>::rend, "each_reverse_const").
    template define_method<void(cv::Mat_<_Tp>::*)(int, int)>("create", &cv::Mat_<_Tp>::create,
      Arg("_rows"), Arg("_cols")).
    template define_method<void(cv::Mat_<_Tp>::*)(cv::Size)>("create", &cv::Mat_<_Tp>::create,
      Arg("_size")).
    template define_method<void(cv::Mat_<_Tp>::*)(int, const int*)>("create", &cv::Mat_<_Tp>::create,
      Arg("_ndims"), Arg("_sizes")).
    define_method("release", &cv::Mat_<_Tp>::release).
    define_method("cross", &cv::Mat_<_Tp>::cross,
      Arg("m")).
    define_method("row", &cv::Mat_<_Tp>::row,
      Arg("y")).
    define_method("col", &cv::Mat_<_Tp>::col,
      Arg("x")).
    define_method("diag", &cv::Mat_<_Tp>::diag,
      Arg("d") = static_cast<int>(0)).
    define_method("clone", &cv::Mat_<_Tp>::clone).
    define_method("elem_size", &cv::Mat_<_Tp>::elemSize).
    define_method("elem_size1", &cv::Mat_<_Tp>::elemSize1).
    define_method("type", &cv::Mat_<_Tp>::type).
    define_method("depth", &cv::Mat_<_Tp>::depth).
    define_method("channels", &cv::Mat_<_Tp>::channels).
    define_method("step1", &cv::Mat_<_Tp>::step1,
      Arg("i") = static_cast<int>(0)).
    define_method("step_t", &cv::Mat_<_Tp>::stepT,
      Arg("i") = static_cast<int>(0)).
    template define_singleton_function<cv::MatExpr(*)(int, int)>("zeros", &cv::Mat_<_Tp>::zeros,
      Arg("rows"), Arg("cols")).
    template define_singleton_function<cv::MatExpr(*)(cv::Size)>("zeros", &cv::Mat_<_Tp>::zeros,
      Arg("size")).
    //template define_singleton_function<cv::MatExpr(*)(int, const int*)>("zeros", &cv::Mat_<_Tp>::zeros,
    //  Arg("_ndims"), Arg("_sizes")).
    template define_singleton_function<cv::MatExpr(*)(int, int)>("ones", &cv::Mat_<_Tp>::ones,
      Arg("rows"), Arg("cols")).
    template define_singleton_function<cv::MatExpr(*)(cv::Size)>("ones", &cv::Mat_<_Tp>::ones,
      Arg("size")).
    //template define_singleton_function<cv::MatExpr(*)(int, const int*)>("ones", &cv::Mat_<_Tp>::ones,
    //  Arg("_ndims"), Arg("_sizes")).
    template define_singleton_function<cv::MatExpr(*)(int, int)>("eye", &cv::Mat_<_Tp>::eye,
      Arg("rows"), Arg("cols")).
    template define_singleton_function<cv::MatExpr(*)(cv::Size)>("eye", &cv::Mat_<_Tp>::eye,
      Arg("size")).
    define_method("adjust_roi", &cv::Mat_<_Tp>::adjustROI,
      Arg("dtop"), Arg("dbottom"), Arg("dleft"), Arg("dright")).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)(const cv::Range&, const cv::Range&) const>("[]", &cv::Mat_<_Tp>::operator(),
      Arg("row_range"), Arg("col_range")).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)(const cv::Rect&) const>("[]", &cv::Mat_<_Tp>::operator(),
      Arg("roi")).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)(const cv::Range*) const>("[]", &cv::Mat_<_Tp>::operator(),
      Arg("ranges")).
    template define_method<cv::Mat_<_Tp>(cv::Mat_<_Tp>::*)(const std::vector<cv::Range>&) const>("[]", &cv::Mat_<_Tp>::operator(),
      Arg("ranges")).
    /*template define_method<_Tp* (cv::Mat_<_Tp>::*)(int)>("[]", &cv::Mat_<_Tp>::operator[],
      Arg("y")).
    template define_method<const _Tp*(cv::Mat_<_Tp>::*)(int) const>("[]", &cv::Mat_<_Tp>::operator[],
      Arg("y")).*/
    //template define_method<_Tp&(cv::Mat_<_Tp>::*)(const int*)>("[]", &cv::Mat_<_Tp>::operator(),
    //  Arg("idx")).
   // template define_method<const _Tp& (cv::Mat_<_Tp>::*)(const int*) const>("[]", &cv::Mat_<_Tp>::operator(),
    //  Arg("idx")).
   template define_method<_Tp& (cv::Mat_<_Tp>::*)(int)>("[]", &cv::Mat_<_Tp>::operator(),
      Arg("idx0")).
    //template define_method<const _Tp&(cv::Mat_<_Tp>::*)(int) const>("[]", &cv::Mat_<_Tp>::operator(),
    //  Arg("idx0")).
    template define_method<_Tp&(cv::Mat_<_Tp>::*)(int, int)>("[]", &cv::Mat_<_Tp>::operator(),
      Arg("row"), Arg("col")).
   // template define_method<const _Tp&(cv::Mat_<_Tp>::*)(int, int) const>("[]", &cv::Mat_<_Tp>::operator(),
   //   Arg("row"), Arg("col")).
    template define_method<_Tp&(cv::Mat_<_Tp>::*)(int, int, int)>("[]", &cv::Mat_<_Tp>::operator(),
      Arg("idx0"), Arg("idx1"), Arg("idx2")).
    //template define_method<const _Tp&(cv::Mat_<_Tp>::*)(int, int, int) const>("[]", &cv::Mat_<_Tp>::operator(),
    //  Arg("idx0"), Arg("idx1"), Arg("idx2")).
    template define_method<_Tp&(cv::Mat_<_Tp>::*)(cv::Point)>("[]", &cv::Mat_<_Tp>::operator(),
      Arg("pt")).
    //template define_method<const _Tp&(cv::Mat_<_Tp>::*)(cv::Point) const>("[]", &cv::Mat_<_Tp>::operator(),
    //  Arg("pt")).
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
    }).
    define_constructor(Constructor<cv::Mat_<_Tp>, cv::Mat&&>(),
      Arg("m")).
    define_constructor(Constructor<cv::Mat_<_Tp>, cv::MatExpr&&>(),
      Arg("e")).
    // Make minitest exception handling happy
    define_method("_dump_data", [](cv::Mat_<_Tp>&) -> Rice::Hash
    {
      Rice::Hash result;
      return result;
    });
};

template<typename Data_Type_T, typename _Tp>
inline void SparseMat__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::SparseMat_<_Tp>>()).
    define_constructor(Constructor<cv::SparseMat_<_Tp>, int, const int*>(),
      Arg("dims"), Arg("_sizes")).
    define_constructor(Constructor<cv::SparseMat_<_Tp>, const cv::SparseMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::SparseMat_<_Tp>, const cv::SparseMat_<_Tp>&>(),
      Arg("m")).
    define_constructor(Constructor<cv::SparseMat_<_Tp>, const cv::Mat&>(),
      Arg("m")).
    define_method("clone", &cv::SparseMat_<_Tp>::clone).
    define_method("create", &cv::SparseMat_<_Tp>::create,
      Arg("dims"), Arg("_sizes")).
    define_method("type", &cv::SparseMat_<_Tp>::type).
    define_method("depth", &cv::SparseMat_<_Tp>::depth).
    define_method("channels", &cv::SparseMat_<_Tp>::channels).
   /* template define_method<_Tp& (cv::SparseMat_<_Tp>::*)(int, ::size_t*)>("ref", &cv::SparseMat_<_Tp>::ref,
      Arg("i0"), Arg("hashval") = static_cast<size_t *>(0)).
    template define_method<_Tp&(cv::SparseMat_<_Tp>::*)(int, int, ::size_t*)>("ref", &cv::SparseMat_<_Tp>::ref,
      Arg("i0"), Arg("i1"), Arg("hashval") = static_cast<size_t *>(0)).
    template define_method<_Tp&(cv::SparseMat_<_Tp>::*)(int, int, int, ::size_t*)>("ref", &cv::SparseMat_<_Tp>::ref,
      Arg("i0"), Arg("i1"), Arg("i2"), Arg("hashval") = static_cast<size_t *>(0)).
    template define_method<_Tp&(cv::SparseMat_<_Tp>::*)(const int*, ::size_t*)>("ref", &cv::SparseMat_<_Tp>::ref,
      Arg("idx"), Arg("hashval") = static_cast<size_t *>(0)).
    template define_method<_Tp(cv::SparseMat_<_Tp>::*)(int, ::size_t*) const>("[]", &cv::SparseMat_<_Tp>::operator(),
      Arg("i0"), Arg("hashval") = static_cast<size_t *>(0)).
    template define_method<_Tp(cv::SparseMat_<_Tp>::*)(int, int, ::size_t*) const>("[]", &cv::SparseMat_<_Tp>::operator(),
      Arg("i0"), Arg("i1"), Arg("hashval") = static_cast<size_t *>(0)).
    template define_method<_Tp(cv::SparseMat_<_Tp>::*)(int, int, int, ::size_t*) const>("[]", &cv::SparseMat_<_Tp>::operator(),
      Arg("i0"), Arg("i1"), Arg("i2"), Arg("hashval") = static_cast<size_t *>(0)).
    template define_method<_Tp(cv::SparseMat_<_Tp>::*)(const int*, ::size_t*) const>("[]", &cv::SparseMat_<_Tp>::operator(),
      Arg("idx"), Arg("hashval") = static_cast<size_t *>(0)).*/
    template define_iterator<cv::SparseMatIterator_<_Tp>(cv::SparseMat_<_Tp>::*)()>(&cv::SparseMat_<_Tp>::begin, &cv::SparseMat_<_Tp>::end, "each").
    template define_iterator<cv::SparseMatConstIterator_<_Tp>(cv::SparseMat_<_Tp>::*)() const>(&cv::SparseMat_<_Tp>::begin, &cv::SparseMat_<_Tp>::end, "each_const").
    // Provide access to SparseMatIterator_<_Tp> because it has additional methods on it
    template define_method<cv::SparseMatIterator_<_Tp>(cv::SparseMat_<_Tp>::*)()>("begin", &cv::SparseMat_<_Tp>::begin).
    template define_method<cv::SparseMatIterator_<_Tp>(cv::SparseMat_<_Tp>::*)()>("end", &cv::SparseMat_<_Tp>::end);

  klass.define_method("[]", [](cv::SparseMat_<_Tp>& self, int i0) -> _Tp&
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
};

template<typename Data_Type_T, typename _Tp>
inline void MatConstIterator__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::MatConstIterator_<_Tp>>()).
    define_constructor(Constructor<cv::MatConstIterator_<_Tp>, const cv::Mat_<_Tp>*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::MatConstIterator_<_Tp>, const cv::Mat_<_Tp>*, int, int>(),
      Arg("_m"), Arg("_row"), Arg("_col") = static_cast<int>(0)).
    define_constructor(Constructor<cv::MatConstIterator_<_Tp>, const cv::Mat_<_Tp>*, cv::Point>(),
      Arg("_m"), Arg("_pt")).
    define_constructor(Constructor<cv::MatConstIterator_<_Tp>, const cv::Mat_<_Tp>*, const int*>(),
      Arg("_m"), Arg("_idx")).
    define_constructor(Constructor<cv::MatConstIterator_<_Tp>, const cv::MatConstIterator_<_Tp>&>(),
      Arg("it")).
    define_method("dereference", &cv::MatConstIterator_<_Tp>::operator*).
    define_method("[]", &cv::MatConstIterator_<_Tp>::operator[],
      Arg("i")).
    define_method("assign_plus", &cv::MatConstIterator_<_Tp>::operator+=,
      Arg("ofs")).
    define_method("assign_minus", &cv::MatConstIterator_<_Tp>::operator-=,
      Arg("ofs")).
    template define_method<cv::MatConstIterator_<_Tp>&(cv::MatConstIterator_<_Tp>::*)()>("decrement", &cv::MatConstIterator_<_Tp>::operator--).
    template define_method<cv::MatConstIterator_<_Tp>(cv::MatConstIterator_<_Tp>::*)(int)>("decrement", &cv::MatConstIterator_<_Tp>::operator--,
      Arg("")).
    template define_method<cv::MatConstIterator_<_Tp>&(cv::MatConstIterator_<_Tp>::*)()>("increment", &cv::MatConstIterator_<_Tp>::operator++).
    template define_method<cv::MatConstIterator_<_Tp>(cv::MatConstIterator_<_Tp>::*)(int)>("increment", &cv::MatConstIterator_<_Tp>::operator++,
      Arg("")).
    define_method("pos", &cv::MatConstIterator_<_Tp>::pos);
};

template<typename Data_Type_T, typename _Tp>
inline void MatIterator__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::MatIterator_<_Tp>>()).
    define_constructor(Constructor<cv::MatIterator_<_Tp>, cv::Mat_<_Tp>*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::MatIterator_<_Tp>, cv::Mat_<_Tp>*, int, int>(),
      Arg("_m"), Arg("_row"), Arg("_col") = static_cast<int>(0)).
    define_constructor(Constructor<cv::MatIterator_<_Tp>, cv::Mat_<_Tp>*, cv::Point>(),
      Arg("_m"), Arg("_pt")).
    define_constructor(Constructor<cv::MatIterator_<_Tp>, cv::Mat_<_Tp>*, const int*>(),
      Arg("_m"), Arg("_idx")).
    define_constructor(Constructor<cv::MatIterator_<_Tp>, const cv::MatIterator_<_Tp>&>(),
      Arg("it")).
    define_method("dereference", &cv::MatIterator_<_Tp>::operator*).
    define_method("[]", &cv::MatIterator_<_Tp>::operator[],
      Arg("i")).
    define_method("assign_plus", &cv::MatIterator_<_Tp>::operator+=,
      Arg("ofs")).
    define_method("assign_minus", &cv::MatIterator_<_Tp>::operator-=,
      Arg("ofs")).
    template define_method<cv::MatIterator_<_Tp>&(cv::MatIterator_<_Tp>::*)()>("decrement", &cv::MatIterator_<_Tp>::operator--).
    template define_method<cv::MatIterator_<_Tp>(cv::MatIterator_<_Tp>::*)(int)>("decrement", &cv::MatIterator_<_Tp>::operator--,
      Arg("")).
    template define_method<cv::MatIterator_<_Tp>&(cv::MatIterator_<_Tp>::*)()>("increment", &cv::MatIterator_<_Tp>::operator++).
    template define_method<cv::MatIterator_<_Tp>(cv::MatIterator_<_Tp>::*)(int)>("increment", &cv::MatIterator_<_Tp>::operator++,
      Arg(""));
};

template<typename Data_Type_T, typename _Tp>
inline void SparseMatConstIterator__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::SparseMatConstIterator_<_Tp>>()).
    define_constructor(Constructor<cv::SparseMatConstIterator_<_Tp>, const cv::SparseMat_<_Tp>*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::SparseMatConstIterator_<_Tp>, const cv::SparseMat*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::SparseMatConstIterator_<_Tp>, const cv::SparseMatConstIterator_<_Tp>&>(),
      Arg("it")).
    define_method("dereference", &cv::SparseMatConstIterator_<_Tp>::operator*).
    template define_method<cv::SparseMatConstIterator_<_Tp>&(cv::SparseMatConstIterator_<_Tp>::*)()>("increment", &cv::SparseMatConstIterator_<_Tp>::operator++).
    template define_method<cv::SparseMatConstIterator_<_Tp>(cv::SparseMatConstIterator_<_Tp>::*)(int)>("increment", &cv::SparseMatConstIterator_<_Tp>::operator++,
      Arg(""));

  klass.
    define_method("==", [](const cv::SparseMatConstIterator_<_Tp>& self, const cv::SparseMatConstIterator_<_Tp>& other) -> bool
    {
      return self == other;
    }).
    define_method("!=", [](const cv::SparseMatConstIterator_<_Tp>& self, const cv::SparseMatConstIterator_<_Tp>& other) -> bool
    {
      return self != other;
    });
};

// Manually define SparseMatConstIterator_ traits
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

// Manually define SparseMatIterator_ traits
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

template<typename Data_Type_T, typename _Tp>
inline void SparseMatIterator__builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::SparseMatIterator_<_Tp>>()).
    define_constructor(Constructor<cv::SparseMatIterator_<_Tp>, cv::SparseMat_<_Tp>*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::SparseMatIterator_<_Tp>, cv::SparseMat*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::SparseMatIterator_<_Tp>, const cv::SparseMatIterator_<_Tp>&>(),
      Arg("it")).
    define_method("dereference", &cv::SparseMatIterator_<_Tp>::operator*).
    template define_method<cv::SparseMatIterator_<_Tp>&(cv::SparseMatIterator_<_Tp>::*)()>("increment", &cv::SparseMatIterator_<_Tp>::operator++).
    template define_method<cv::SparseMatIterator_<_Tp>(cv::SparseMatIterator_<_Tp>::*)(int)>("increment", &cv::SparseMatIterator_<_Tp>::operator++,
      Arg(""));
};

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

void Init_Mat()
{
  Module rb_mCv = define_module("Cv");
  
  Enum<cv::AccessFlag> rb_cCvAccessFlag = define_enum_under<cv::AccessFlag>("AccessFlag", rb_mCv).
    define_value("ACCESS_READ", cv::AccessFlag::ACCESS_READ).
    define_value("ACCESS_WRITE", cv::AccessFlag::ACCESS_WRITE).
    define_value("ACCESS_RW", cv::AccessFlag::ACCESS_RW).
    define_value("ACCESS_MASK", cv::AccessFlag::ACCESS_MASK).
    define_value("ACCESS_FAST", cv::AccessFlag::ACCESS_FAST);
  
  rb_cCvInputArray = define_class_under<cv::_InputArray>(rb_mCv, "InputArray").
    define_constructor(Constructor<cv::_InputArray>()).
    define_constructor(Constructor<cv::_InputArray, int, void*>(),
      Arg("_flags"), Arg("_obj")).
    define_constructor(Constructor<cv::_InputArray, const cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_InputArray, const cv::MatExpr&>(),
      Arg("expr")).
    define_constructor(Constructor<cv::_InputArray, const std::vector<cv::Mat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_InputArray, const std::vector<bool>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_InputArray, const double&>(),
      Arg("val")).
    define_constructor(Constructor<cv::_InputArray, const cv::cuda::GpuMat&>(),
      Arg("d_mat")).
    //define_constructor(Constructor<cv::_InputArray, const std::vector<cv::cuda::GpuMat>&>(),
    //  Arg("d_mat_array")).
    define_constructor(Constructor<cv::_InputArray, const cv::ogl::Buffer&>(),
      Arg("buf")).
    define_constructor(Constructor<cv::_InputArray, const cv::cuda::HostMem&>(),
      Arg("cuda_mem")).
    define_constructor(Constructor<cv::_InputArray, const cv::UMat&>(),
      Arg("um")).
    define_constructor(Constructor<cv::_InputArray, const std::vector<cv::UMat>&>(),
      Arg("umv")).
    define_method("get_mat", &cv::_InputArray::getMat,
      Arg("idx") = static_cast<int>(-1)).
    define_method("get_mat_", &cv::_InputArray::getMat_,
      Arg("idx") = static_cast<int>(-1)).
    define_method("get_u_mat", &cv::_InputArray::getUMat,
      Arg("idx") = static_cast<int>(-1)).
    define_method("get_mat_vector", &cv::_InputArray::getMatVector,
      Arg("mv")).
    define_method("get_u_mat_vector", &cv::_InputArray::getUMatVector,
      Arg("umv")).
    define_method("get_gpu_mat_vector", &cv::_InputArray::getGpuMatVector,
      Arg("gpumv")).
    define_method("get_gpu_mat", &cv::_InputArray::getGpuMat).
    define_method("get_o_gl_buffer", &cv::_InputArray::getOGlBuffer).
    define_method("get_flags", &cv::_InputArray::getFlags).
    define_method("get_obj", &cv::_InputArray::getObj).
    define_method("get_sz", &cv::_InputArray::getSz).
    define_method("kind", &cv::_InputArray::kind).
    define_method("dims", &cv::_InputArray::dims,
      Arg("i") = static_cast<int>(-1)).
    define_method("cols", &cv::_InputArray::cols,
      Arg("i") = static_cast<int>(-1)).
    define_method("rows", &cv::_InputArray::rows,
      Arg("i") = static_cast<int>(-1)).
    define_method("size", &cv::_InputArray::size,
      Arg("i") = static_cast<int>(-1)).
    define_method("sizend", &cv::_InputArray::sizend,
      Arg("sz"), Arg("i") = static_cast<int>(-1)).
    define_method("same_size?", &cv::_InputArray::sameSize,
      Arg("arr")).
    define_method("total", &cv::_InputArray::total,
      Arg("i") = static_cast<int>(-1)).
    define_method("type", &cv::_InputArray::type,
      Arg("i") = static_cast<int>(-1)).
    define_method("depth", &cv::_InputArray::depth,
      Arg("i") = static_cast<int>(-1)).
    define_method("channels", &cv::_InputArray::channels,
      Arg("i") = static_cast<int>(-1)).
    define_method("continuous?", &cv::_InputArray::isContinuous,
      Arg("i") = static_cast<int>(-1)).
    define_method("submatrix?", &cv::_InputArray::isSubmatrix,
      Arg("i") = static_cast<int>(-1)).
    define_method("empty?", static_cast<bool(cv::_InputArray::*)() const>(&cv::_InputArray::empty)).
    define_method<void(cv::_InputArray::*)(const cv::_OutputArray&) const>("copy_to", &cv::_InputArray::copyTo,
      Arg("arr")).
    define_method<void(cv::_InputArray::*)(const cv::_OutputArray&, const cv::_InputArray&) const>("copy_to", &cv::_InputArray::copyTo,
      Arg("arr"), Arg("mask")).
    define_method("offset", &cv::_InputArray::offset,
      Arg("i") = static_cast<int>(-1)).
    define_method("step", &cv::_InputArray::step,
      Arg("i") = static_cast<int>(-1)).
    define_method("mat?", &cv::_InputArray::isMat).
    define_method("u_mat?", &cv::_InputArray::isUMat).
    define_method("mat_vector?", &cv::_InputArray::isMatVector).
    define_method("u_mat_vector?", &cv::_InputArray::isUMatVector).
    define_method("matx?", &cv::_InputArray::isMatx).
    define_method("vector?", &cv::_InputArray::isVector).
    define_method("gpu_mat?", &cv::_InputArray::isGpuMat).
    define_method("gpu_mat_vector?", &cv::_InputArray::isGpuMatVector);
  
  Enum<cv::_InputArray::KindFlag> rb_cCvInputArrayKindFlag = define_enum_under<cv::_InputArray::KindFlag>("KindFlag", rb_cCvInputArray).
    define_value("KIND_SHIFT", cv::_InputArray::KindFlag::KIND_SHIFT).
    define_value("FIXED_TYPE", cv::_InputArray::KindFlag::FIXED_TYPE).
    define_value("FIXED_SIZE", cv::_InputArray::KindFlag::FIXED_SIZE).
    define_value("KIND_MASK", cv::_InputArray::KindFlag::KIND_MASK).
    define_value("NONE", cv::_InputArray::KindFlag::NONE).
    define_value("MAT", cv::_InputArray::KindFlag::MAT).
    define_value("MATX", cv::_InputArray::KindFlag::MATX).
    define_value("STD_VECTOR", cv::_InputArray::KindFlag::STD_VECTOR).
    define_value("STD_VECTOR_VECTOR", cv::_InputArray::KindFlag::STD_VECTOR_VECTOR).
    define_value("STD_VECTOR_MAT", cv::_InputArray::KindFlag::STD_VECTOR_MAT).
    define_value("EXPR", cv::_InputArray::KindFlag::EXPR).
    define_value("OPENGL_BUFFER", cv::_InputArray::KindFlag::OPENGL_BUFFER).
    define_value("CUDA_HOST_MEM", cv::_InputArray::KindFlag::CUDA_HOST_MEM).
    define_value("CUDA_GPU_MAT", cv::_InputArray::KindFlag::CUDA_GPU_MAT).
    define_value("UMAT", cv::_InputArray::KindFlag::UMAT).
    define_value("STD_VECTOR_UMAT", cv::_InputArray::KindFlag::STD_VECTOR_UMAT).
    define_value("STD_BOOL_VECTOR", cv::_InputArray::KindFlag::STD_BOOL_VECTOR).
    define_value("STD_VECTOR_CUDA_GPU_MAT", cv::_InputArray::KindFlag::STD_VECTOR_CUDA_GPU_MAT).
    define_value("STD_ARRAY", cv::_InputArray::KindFlag::STD_ARRAY).
    define_value("STD_ARRAY_MAT", cv::_InputArray::KindFlag::STD_ARRAY_MAT);
  
  rb_cCvOutputArray = define_class_under<cv::_OutputArray, cv::_InputArray>(rb_mCv, "OutputArray").
    define_constructor(Constructor<cv::_OutputArray>()).
    define_constructor(Constructor<cv::_OutputArray, int, void*>(),
      Arg("_flags"), Arg("_obj")).
    define_constructor(Constructor<cv::_OutputArray, cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::Mat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_OutputArray, cv::cuda::GpuMat&>(),
      Arg("d_mat")).
    //define_constructor(Constructor<cv::_OutputArray, std::vector<cv::cuda::GpuMat>&>(),
    //  Arg("d_mat")).
    define_constructor(Constructor<cv::_OutputArray, cv::ogl::Buffer&>(),
      Arg("buf")).
    define_constructor(Constructor<cv::_OutputArray, cv::cuda::HostMem&>(),
      Arg("cuda_mem")).
    define_constructor(Constructor<cv::_OutputArray, cv::UMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_OutputArray, std::vector<cv::UMat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_OutputArray, const cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_OutputArray, const std::vector<cv::Mat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_OutputArray, const cv::cuda::GpuMat&>(),
      Arg("d_mat")).
    //define_constructor(Constructor<cv::_OutputArray, const std::vector<cv::cuda::GpuMat>&>(),
    //  Arg("d_mat")).
    define_constructor(Constructor<cv::_OutputArray, const cv::ogl::Buffer&>(),
      Arg("buf")).
    define_constructor(Constructor<cv::_OutputArray, const cv::cuda::HostMem&>(),
      Arg("cuda_mem")).
    define_constructor(Constructor<cv::_OutputArray, const cv::UMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_OutputArray, const std::vector<cv::UMat>&>(),
      Arg("vec")).
    define_method("fixed_size?", &cv::_OutputArray::fixedSize).
    define_method("fixed_type?", &cv::_OutputArray::fixedType).
    define_method("needed?", &cv::_OutputArray::needed).
    define_method("get_mat_ref", &cv::_OutputArray::getMatRef,
      Arg("i") = static_cast<int>(-1)).
    define_method("get_u_mat_ref", &cv::_OutputArray::getUMatRef,
      Arg("i") = static_cast<int>(-1)).
    define_method("get_gpu_mat_ref", &cv::_OutputArray::getGpuMatRef).
    define_method("get_gpu_mat_vec_ref", &cv::_OutputArray::getGpuMatVecRef).
    define_method("get_o_gl_buffer_ref", &cv::_OutputArray::getOGlBufferRef).
    define_method("get_host_mem_ref", &cv::_OutputArray::getHostMemRef).
    define_method<void(cv::_OutputArray::*)(cv::Size, int, int, bool, cv::_OutputArray::DepthMask) const>("create", &cv::_OutputArray::create,
      Arg("sz"), Arg("type"), Arg("i") = static_cast<int>(-1), Arg("allow_transposed") = static_cast<bool>(false), Arg("fixed_depth_mask") = static_cast<cv::_OutputArray::DepthMask>(static_cast<cv::_OutputArray::DepthMask>(0))).
    define_method<void(cv::_OutputArray::*)(int, int, int, int, bool, cv::_OutputArray::DepthMask) const>("create", &cv::_OutputArray::create,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("i") = static_cast<int>(-1), Arg("allow_transposed") = static_cast<bool>(false), Arg("fixed_depth_mask") = static_cast<cv::_OutputArray::DepthMask>(static_cast<cv::_OutputArray::DepthMask>(0))).
    define_method<void(cv::_OutputArray::*)(int, const int*, int, int, bool, cv::_OutputArray::DepthMask) const>("create", &cv::_OutputArray::create,
      Arg("dims"), Arg("size"), Arg("type"), Arg("i") = static_cast<int>(-1), Arg("allow_transposed") = static_cast<bool>(false), Arg("fixed_depth_mask") = static_cast<cv::_OutputArray::DepthMask>(static_cast<cv::_OutputArray::DepthMask>(0))).
    define_method<void(cv::_OutputArray::*)(const cv::_InputArray&, int) const>("create_same_size", &cv::_OutputArray::createSameSize,
      Arg("arr"), Arg("mtype")).
    define_method<void(cv::_OutputArray::*)() const>("release", &cv::_OutputArray::release).
    define_method<void(cv::_OutputArray::*)() const>("clear", &cv::_OutputArray::clear).
    define_method<void(cv::_OutputArray::*)(const cv::_InputArray&, const cv::_InputArray&) const>("set_to", &cv::_OutputArray::setTo,
      Arg("value"), Arg("mask") = static_cast<const cv::_InputArray &>(cv::_InputArray())).
    define_method<void(cv::_OutputArray::*)(const cv::UMat&) const>("assign", &cv::_OutputArray::assign,
      Arg("u")).
    define_method<void(cv::_OutputArray::*)(const cv::Mat&) const>("assign", &cv::_OutputArray::assign,
      Arg("m")).
    define_method<void(cv::_OutputArray::*)(const std::vector<cv::UMat>&) const>("assign", &cv::_OutputArray::assign,
      Arg("v")).
    define_method<void(cv::_OutputArray::*)(const std::vector<cv::Mat>&) const>("assign", &cv::_OutputArray::assign,
      Arg("v")).
    define_method<void(cv::_OutputArray::*)(cv::UMat&) const>("move", &cv::_OutputArray::move,
      Arg("u")).
    define_method<void(cv::_OutputArray::*)(cv::Mat&) const>("move", &cv::_OutputArray::move,
      Arg("m"));

  Enum<cv::_OutputArray::DepthMask> rb_cCvOutputArrayDepthMask = define_enum_under<cv::_OutputArray::DepthMask>("DepthMask", rb_cCvOutputArray).
    define_value("DEPTH_MASK_8U", cv::_OutputArray::DepthMask::DEPTH_MASK_8U).
    define_value("DEPTH_MASK_8S", cv::_OutputArray::DepthMask::DEPTH_MASK_8S).
    define_value("DEPTH_MASK_16U", cv::_OutputArray::DepthMask::DEPTH_MASK_16U).
    define_value("DEPTH_MASK_16S", cv::_OutputArray::DepthMask::DEPTH_MASK_16S).
    define_value("DEPTH_MASK_32S", cv::_OutputArray::DepthMask::DEPTH_MASK_32S).
    define_value("DEPTH_MASK_32F", cv::_OutputArray::DepthMask::DEPTH_MASK_32F).
    define_value("DEPTH_MASK_64F", cv::_OutputArray::DepthMask::DEPTH_MASK_64F).
    define_value("DEPTH_MASK_16F", cv::_OutputArray::DepthMask::DEPTH_MASK_16F).
    define_value("DEPTH_MASK_ALL", cv::_OutputArray::DepthMask::DEPTH_MASK_ALL).
    define_value("DEPTH_MASK_ALL_BUT_8S", cv::_OutputArray::DepthMask::DEPTH_MASK_ALL_BUT_8S).
    define_value("DEPTH_MASK_ALL_16F", cv::_OutputArray::DepthMask::DEPTH_MASK_ALL_16F).
    define_value("DEPTH_MASK_FLT", cv::_OutputArray::DepthMask::DEPTH_MASK_FLT);
  
  rb_cCvInputOutputArray = define_class_under<cv::_InputOutputArray, cv::_OutputArray>(rb_mCv, "InputOutputArray").
    define_constructor(Constructor<cv::_InputOutputArray>()).
    define_constructor(Constructor<cv::_InputOutputArray, int, void*>(),
      Arg("_flags"), Arg("_obj")).
    define_constructor(Constructor<cv::_InputOutputArray, cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_InputOutputArray, std::vector<cv::Mat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_InputOutputArray, cv::cuda::GpuMat&>(),
      Arg("d_mat")).
    define_constructor(Constructor<cv::_InputOutputArray, cv::ogl::Buffer&>(),
      Arg("buf")).
    define_constructor(Constructor<cv::_InputOutputArray, cv::cuda::HostMem&>(),
      Arg("cuda_mem")).
    define_constructor(Constructor<cv::_InputOutputArray, cv::UMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_InputOutputArray, std::vector<cv::UMat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_InputOutputArray, const cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_InputOutputArray, const std::vector<cv::Mat>&>(),
      Arg("vec")).
    define_constructor(Constructor<cv::_InputOutputArray, const cv::cuda::GpuMat&>(),
      Arg("d_mat")).
    define_constructor(Constructor<cv::_InputOutputArray, const std::vector<cv::cuda::GpuMat>&>(),
      Arg("d_mat")).
    define_constructor(Constructor<cv::_InputOutputArray, const cv::ogl::Buffer&>(),
      Arg("buf")).
    define_constructor(Constructor<cv::_InputOutputArray, const cv::cuda::HostMem&>(),
      Arg("cuda_mem")).
    define_constructor(Constructor<cv::_InputOutputArray, const cv::UMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::_InputOutputArray, const std::vector<cv::UMat>&>(),
      Arg("vec"));
  
  rb_mCv.define_module_function<cv::InputOutputArray(*)()>("no_array", &cv::noArray);
  
  Enum<cv::UMatUsageFlags> rb_cCvUMatUsageFlags = define_enum_under<cv::UMatUsageFlags>("UMatUsageFlags", rb_mCv).
    define_value("USAGE_DEFAULT", cv::UMatUsageFlags::USAGE_DEFAULT).
    define_value("USAGE_ALLOCATE_HOST_MEMORY", cv::UMatUsageFlags::USAGE_ALLOCATE_HOST_MEMORY).
    define_value("USAGE_ALLOCATE_DEVICE_MEMORY", cv::UMatUsageFlags::USAGE_ALLOCATE_DEVICE_MEMORY).
    define_value("USAGE_ALLOCATE_SHARED_MEMORY", cv::UMatUsageFlags::USAGE_ALLOCATE_SHARED_MEMORY).
    define_value("__UMAT_USAGE_FLAGS_32BIT", cv::UMatUsageFlags::__UMAT_USAGE_FLAGS_32BIT);
  
  rb_cCvMatAllocator = define_class_under<cv::MatAllocator>(rb_mCv, "MatAllocator").
    define_method<cv::UMatData*(cv::MatAllocator::*)(int, const int*, int, void*, ::size_t*, cv::AccessFlag, cv::UMatUsageFlags) const>("allocate", &cv::MatAllocator::allocate,
      Arg("dims"), Arg("sizes"), Arg("type"), Arg("data"), Arg("step"), Arg("flags"), Arg("usage_flags")).
    define_method<bool(cv::MatAllocator::*)(cv::UMatData*, cv::AccessFlag, cv::UMatUsageFlags) const>("allocate?", &cv::MatAllocator::allocate,
      Arg("data"), Arg("accessflags"), Arg("usage_flags")).
    define_method("deallocate", &cv::MatAllocator::deallocate,
      Arg("data")).
    define_method("map", &cv::MatAllocator::map,
      Arg("data"), Arg("accessflags")).
    define_method("unmap", &cv::MatAllocator::unmap,
      Arg("data")).
    define_method("download", &cv::MatAllocator::download,
      Arg("data"), Arg("dst"), Arg("dims"), Arg("sz"), Arg("srcofs"), Arg("srcstep"), Arg("dststep")).
    define_method("upload", &cv::MatAllocator::upload,
      Arg("data"), Arg("src"), Arg("dims"), Arg("sz"), Arg("dstofs"), Arg("dststep"), Arg("srcstep")).
    define_method("copy", &cv::MatAllocator::copy,
      Arg("srcdata"), Arg("dstdata"), Arg("dims"), Arg("sz"), Arg("srcofs"), Arg("srcstep"), Arg("dstofs"), Arg("dststep"), Arg("sync")).
    define_method("get_buffer_pool_controller", &cv::MatAllocator::getBufferPoolController,
      Arg("id") = static_cast<const char *>(NULL));
  
  rb_cCvUMatData = define_class_under<cv::UMatData>(rb_mCv, "UMatData").
    define_constructor(Constructor<cv::UMatData, const cv::MatAllocator*>(),
      Arg("allocator")).
    define_method("lock", &cv::UMatData::lock).
    define_method("unlock", &cv::UMatData::unlock).
    define_method("host_copy_obsolete?", &cv::UMatData::hostCopyObsolete).
    define_method("device_copy_obsolete?", &cv::UMatData::deviceCopyObsolete).
    define_method("device_mem_mapped?", &cv::UMatData::deviceMemMapped).
    define_method("copy_on_map?", &cv::UMatData::copyOnMap).
    define_method("temp_u_mat?", &cv::UMatData::tempUMat).
    define_method("temp_copied_u_mat?", &cv::UMatData::tempCopiedUMat).
    define_method("mark_host_copy_obsolete", &cv::UMatData::markHostCopyObsolete,
      Arg("flag")).
    define_method("mark_device_copy_obsolete", &cv::UMatData::markDeviceCopyObsolete,
      Arg("flag")).
    define_method("mark_device_mem_mapped", &cv::UMatData::markDeviceMemMapped,
      Arg("flag")).
    define_attr("prev_allocator", &cv::UMatData::prevAllocator).
    define_attr("curr_allocator", &cv::UMatData::currAllocator).
    define_attr("urefcount", &cv::UMatData::urefcount).
    define_attr("refcount", &cv::UMatData::refcount).
    define_attr("data", &cv::UMatData::data).
    define_attr("origdata", &cv::UMatData::origdata).
    define_attr("size", &cv::UMatData::size).
    define_attr("flags", &cv::UMatData::flags).
    define_attr("handle", &cv::UMatData::handle).
    define_attr("userdata", &cv::UMatData::userdata).
    define_attr("allocator_flags_", &cv::UMatData::allocatorFlags_).
    define_attr("mapcount", &cv::UMatData::mapcount).
    define_attr("original_u_mat_data", &cv::UMatData::originalUMatData).
    define_attr("allocator_context", &cv::UMatData::allocatorContext);
  
  Enum<cv::UMatData::MemoryFlag> rb_cCvUMatDataMemoryFlag = define_enum_under<cv::UMatData::MemoryFlag>("MemoryFlag", rb_cCvUMatData).
    define_value("COPY_ON_MAP", cv::UMatData::MemoryFlag::COPY_ON_MAP).
    define_value("HOST_COPY_OBSOLETE", cv::UMatData::MemoryFlag::HOST_COPY_OBSOLETE).
    define_value("DEVICE_COPY_OBSOLETE", cv::UMatData::MemoryFlag::DEVICE_COPY_OBSOLETE).
    define_value("TEMP_UMAT", cv::UMatData::MemoryFlag::TEMP_UMAT).
    define_value("TEMP_COPIED_UMAT", cv::UMatData::MemoryFlag::TEMP_COPIED_UMAT).
    define_value("USER_ALLOCATED", cv::UMatData::MemoryFlag::USER_ALLOCATED).
    define_value("DEVICE_MEM_MAPPED", cv::UMatData::MemoryFlag::DEVICE_MEM_MAPPED).
    define_value("ASYNC_CLEANUP", cv::UMatData::MemoryFlag::ASYNC_CLEANUP);
  
  rb_cCvMatSize = define_class_under<cv::MatSize>(rb_mCv, "MatSize").
    define_constructor(Constructor<cv::MatSize, int*>(),
      Arg("_p")).
    define_method("dims", &cv::MatSize::dims).
    define_method("to_size", &cv::MatSize::operator()).
    define_method<int&(cv::MatSize::*)(int)>("[]", &cv::MatSize::operator[],
      Arg("i")).
    define_method("[]=", [](cv::MatSize& self, int index, int& value)
    {
        self[index] = value;
    }).
    define_method("==", &cv::MatSize::operator==,
      Arg("sz")).
    define_method("!=", &cv::MatSize::operator!=,
      Arg("sz")).
    define_attr("p", &cv::MatSize::p).
    define_method("inspect", [](const cv::MatSize& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });

  rb_cCvMatStep = define_class_under<cv::MatStep>(rb_mCv, "MatStep").
    define_constructor(Constructor<cv::MatStep>()).
    define_constructor(Constructor<cv::MatStep, ::size_t>(),
      Arg("s")).
    define_method<const ::size_t&(cv::MatStep::*)(int) const noexcept>("[]", &cv::MatStep::operator[],
      Arg("i")).
    define_method<::size_t&(cv::MatStep::*)(int) noexcept>("[]", &cv::MatStep::operator[],
      Arg("i")).
    define_method("[]=", [](cv::MatStep&self, int index, size_t & value)
    {
        self[index] = value;
    }).
    define_method("to_size_t", [](const cv::MatStep& self) -> ::size_t
    {
      return self;
    }).
    define_attr("p", &cv::MatStep::p).
    define_attr("buf", &cv::MatStep::buf, Rice::AttrAccess::Read);

  // Tuple of types we need to implement Mat template functions like at, begin, end.
  using Mat_Tuple_T = std::tuple<unsigned char, cv::Vec<unsigned char, 2>, cv::Vec<unsigned char, 3>, cv::Vec<unsigned char, 4>,
    short, cv::Vec<short, 2>, cv::Vec<short, 3>, cv::Vec<short, 4>,
    unsigned short, cv::Vec<unsigned short, 2>, cv::Vec<unsigned short, 3>, cv::Vec<unsigned short, 4>,
    int, cv::Vec<int, 2>, cv::Vec<int, 3>, cv::Vec<int, 4>,
    float, cv::Vec<float, 2>, cv::Vec<float, 3>, cv::Vec<float, 4>,
    double, cv::Vec<double, 2>, cv::Vec<double, 3>, cv::Vec<double, 4>>;

  rb_cCvMat = define_class_under<cv::Mat>(rb_mCv, "Mat").
    define_constructor(Constructor<cv::Mat>()).
    define_constructor(Constructor<cv::Mat, int, int, int>(),
      Arg("rows"), Arg("cols"), Arg("type")).
    define_constructor(Constructor<cv::Mat, cv::Size, int>(),
      Arg("size"), Arg("type")).
    define_constructor(Constructor<cv::Mat, int, int, int, const cv::Scalar&>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("s")).
    define_constructor(Constructor<cv::Mat, cv::Size, int, const cv::Scalar&>(),
      Arg("size"), Arg("type"), Arg("s")).
    define_constructor(Constructor<cv::Mat, int, const int*, int>(),
      Arg("ndims"), Arg("sizes"), Arg("type")).
    define_constructor(Constructor<cv::Mat, const std::vector<int>&, int>(),
      Arg("sizes"), Arg("type")).
    define_constructor(Constructor<cv::Mat, int, const int*, int, const cv::Scalar&>(),
      Arg("ndims"), Arg("sizes"), Arg("type"), Arg("s")).
    define_constructor(Constructor<cv::Mat, const std::vector<int>&, int, const cv::Scalar&>(),
      Arg("sizes"), Arg("type"), Arg("s")).
    define_constructor(Constructor<cv::Mat, const cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::Mat, int, int, int, void*, ::size_t>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("data"), Arg("step") = static_cast<size_t>(cv::Mat::AUTO_STEP)).
    define_constructor(Constructor<cv::Mat, cv::Size, int, void*, ::size_t>(),
      Arg("size"), Arg("type"), Arg("data"), Arg("step") = static_cast<size_t>(cv::Mat::AUTO_STEP)).
    define_constructor(Constructor<cv::Mat, int, const int*, int, void*, const ::size_t*>(),
      Arg("ndims"), Arg("sizes"), Arg("type"), Arg("data"), Arg("steps") = static_cast<const size_t *>(0)).
    define_constructor(Constructor<cv::Mat, const std::vector<int>&, int, void*, const ::size_t*>(),
      Arg("sizes"), Arg("type"), Arg("data"), Arg("steps") = static_cast<const size_t *>(0)).
    define_constructor(Constructor<cv::Mat, const cv::Mat&, const cv::Range&, const cv::Range&>(),
      Arg("m"), Arg("row_range"), Arg("col_range") = static_cast<const cv::Range &>(cv::Range::all())).
    define_constructor(Constructor<cv::Mat, const cv::Mat&, const cv::Rect&>(),
      Arg("m"), Arg("roi")).
    define_constructor(Constructor<cv::Mat, const cv::Mat&, const cv::Range*>(),
      Arg("m"), Arg("ranges")).
    define_constructor(Constructor<cv::Mat, const cv::Mat&, const std::vector<cv::Range>&>(),
      Arg("m"), Arg("ranges")).
    define_constructor(Constructor<cv::Mat, const cv::cuda::GpuMat&>(),
      Arg("m")).
    define_method<cv::UMat(cv::Mat::*)(cv::AccessFlag, cv::UMatUsageFlags) const>("get_u_mat", &cv::Mat::getUMat,
      Arg("access_flags"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::UMatUsageFlags::USAGE_DEFAULT)).
    define_method<cv::Mat(cv::Mat::*)(int) const>("row", &cv::Mat::row,
      Arg("y")).
    define_method("col", &cv::Mat::col,
      Arg("x")).
    define_method<cv::Mat(cv::Mat::*)(int, int) const>("row_range", &cv::Mat::rowRange,
      Arg("startrow"), Arg("endrow")).
    define_method<cv::Mat(cv::Mat::*)(const cv::Range&) const>("row_range", &cv::Mat::rowRange,
      Arg("r")).
    define_method<cv::Mat(cv::Mat::*)(int, int) const>("col_range", &cv::Mat::colRange,
      Arg("startcol"), Arg("endcol")).
    define_method<cv::Mat(cv::Mat::*)(const cv::Range&) const>("col_range", &cv::Mat::colRange,
      Arg("r")).
    define_method<cv::Mat(cv::Mat::*)(int) const>("diag", &cv::Mat::diag,
      Arg("d") = static_cast<int>(0)).
    define_singleton_function<cv::Mat(*)(const cv::Mat&)>("diag", &cv::Mat::diag,
      Arg("d")).
    define_method("clone", &cv::Mat::clone).
    define_method<void(cv::Mat::*)(cv::OutputArray) const>("copy_to", &cv::Mat::copyTo,
      Arg("m")).
    define_method<void(cv::Mat::*)(cv::OutputArray, cv::InputArray) const>("copy_to", &cv::Mat::copyTo,
      Arg("m"), Arg("mask")).
    define_method("convert_to", &cv::Mat::convertTo,
      Arg("m"), Arg("rtype"), Arg("alpha") = static_cast<double>(1), Arg("beta") = static_cast<double>(0)).
    define_method("assign_to", &cv::Mat::assignTo,
      Arg("m"), Arg("type") = static_cast<int>(-1)).
    define_method<cv::Mat&(cv::Mat::*)(const cv::Mat&)>("assign", &cv::Mat::operator=,
      Arg("m")).
    define_method<cv::Mat&(cv::Mat::*)(const cv::MatExpr&)>("assign", &cv::Mat::operator=,
      Arg("expr")).
    define_method<cv::Mat&(cv::Mat::*)(const cv::Scalar&)>("assign", &cv::Mat::operator=,
      Arg("s")).
    define_method("set_to", &cv::Mat::setTo,
      Arg("value"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<cv::Mat(cv::Mat::*)(int, int) const>("reshape", &cv::Mat::reshape,
      Arg("cn"), Arg("rows") = static_cast<int>(0)).
    define_method<cv::Mat(cv::Mat::*)(int, int, const int*) const>("reshape", &cv::Mat::reshape,
      Arg("cn"), Arg("newndims"), Arg("newsz")).
    define_method<cv::Mat(cv::Mat::*)(int, const std::vector<int>&) const>("reshape", &cv::Mat::reshape,
      Arg("cn"), Arg("newshape")).
    define_method("t", &cv::Mat::t).
    define_method("inv", &cv::Mat::inv,
      Arg("method") = static_cast<int>(cv::DecompTypes::DECOMP_LU)).
    define_method("mul", &cv::Mat::mul,
      Arg("m"), Arg("scale") = static_cast<double>(1)).
    define_method("cross", &cv::Mat::cross,
      Arg("m")).
    define_method("dot", &cv::Mat::dot,
      Arg("m")).
    define_singleton_function<cv::MatExpr(*)(int, int, int)>("zeros", &cv::Mat::zeros,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(cv::Size, int)>("zeros", &cv::Mat::zeros,
      Arg("size"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(int, const int*, int)>("zeros", &cv::Mat::zeros,
      Arg("ndims"), Arg("sz"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(int, int, int)>("ones", &cv::Mat::ones,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(cv::Size, int)>("ones", &cv::Mat::ones,
      Arg("size"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(int, const int*, int)>("ones", &cv::Mat::ones,
      Arg("ndims"), Arg("sz"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(int, int, int)>("eye", &cv::Mat::eye,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_singleton_function<cv::MatExpr(*)(cv::Size, int)>("eye", &cv::Mat::eye,
      Arg("size"), Arg("type")).
    define_method<void(cv::Mat::*)(int, int, int)>("create", &cv::Mat::create,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_method<void(cv::Mat::*)(cv::Size, int)>("create", &cv::Mat::create,
      Arg("size"), Arg("type")).
    define_method<void(cv::Mat::*)(int, const int*, int)>("create", &cv::Mat::create,
      Arg("ndims"), Arg("sizes"), Arg("type")).
    define_method<void(cv::Mat::*)(const std::vector<int>&, int)>("create", &cv::Mat::create,
      Arg("sizes"), Arg("type")).
    define_method("addref", &cv::Mat::addref).
    define_method("release", &cv::Mat::release).
    define_method("deallocate", &cv::Mat::deallocate).
    define_method("copy_size", &cv::Mat::copySize,
      Arg("m")).
    define_method("reserve", &cv::Mat::reserve,
      Arg("sz")).
    define_method("reserve_buffer", &cv::Mat::reserveBuffer,
      Arg("sz")).
    define_method<void(cv::Mat::*)(::size_t)>("resize", &cv::Mat::resize,
      Arg("sz")).
    define_method<void(cv::Mat::*)(::size_t, const cv::Scalar&)>("resize", &cv::Mat::resize,
      Arg("sz"), Arg("s")).
    define_method("push_back_", &cv::Mat::push_back_,
      Arg("elem")).
    define_method<void(cv::Mat::*)(const cv::Mat&)>("push_back", &cv::Mat::push_back,
      Arg("m")).
    define_method("pop_back", &cv::Mat::pop_back,
      Arg("nelems") = static_cast<size_t>(1)).
    define_method("locate_roi", &cv::Mat::locateROI,
      Arg("whole_size"), Arg("ofs")).
    define_method("adjust_roi", &cv::Mat::adjustROI,
      Arg("dtop"), Arg("dbottom"), Arg("dleft"), Arg("dright")).
    define_method<cv::Mat(cv::Mat::*)(cv::Range, cv::Range) const>("[]", &cv::Mat::operator(),
      Arg("row_range"), Arg("col_range")).
    define_method<cv::Mat(cv::Mat::*)(const cv::Rect&) const>("[]", &cv::Mat::operator(),
      Arg("roi")).
    define_method<cv::Mat(cv::Mat::*)(const cv::Range*) const>("[]", &cv::Mat::operator(),
      Arg("ranges")).
    define_method<cv::Mat(cv::Mat::*)(const std::vector<cv::Range>&) const>("[]", &cv::Mat::operator(),
      Arg("ranges")).
    define_method("continuous?", &cv::Mat::isContinuous).
    define_method("submatrix?", &cv::Mat::isSubmatrix).
    define_method("elem_size", &cv::Mat::elemSize).
    define_method("elem_size1", &cv::Mat::elemSize1).
    define_method("type", &cv::Mat::type).
    define_method("depth", &cv::Mat::depth).
    define_method("channels", &cv::Mat::channels).
    define_method("step1", &cv::Mat::step1,
      Arg("i") = static_cast<int>(0)).
    define_method("empty?", &cv::Mat::empty).
    define_method<::size_t(cv::Mat::*)() const>("total", &cv::Mat::total).
    define_method<::size_t(cv::Mat::*)(int, int) const>("total", &cv::Mat::total,
      Arg("start_dim"), Arg("end_dim") = static_cast<int>(INT_MAX)).
    define_method("check_vector", &cv::Mat::checkVector,
      Arg("elem_channels"), Arg("depth") = static_cast<int>(-1), Arg("require_continuous") = static_cast<bool>(true)).
    define_attr("flags", &cv::Mat::flags).
    define_attr("dims", &cv::Mat::dims).
    define_attr("rows", &cv::Mat::rows).
    define_attr("cols", &cv::Mat::cols).
    define_attr("data", &cv::Mat::data).
    define_attr("datastart", &cv::Mat::datastart).
    define_attr("dataend", &cv::Mat::dataend).
    define_attr("datalimit", &cv::Mat::datalimit).
    define_attr("allocator", &cv::Mat::allocator).
    define_singleton_function("get_std_allocator", &cv::Mat::getStdAllocator).
    define_singleton_function("get_default_allocator", &cv::Mat::getDefaultAllocator).
    define_singleton_function("set_default_allocator", &cv::Mat::setDefaultAllocator,
      Arg("allocator")).
    define_method("update_continuity_flag", &cv::Mat::updateContinuityFlag).
    define_attr("u", &cv::Mat::u).
    define_attr("size", &cv::Mat::size).
    define_attr("step", &cv::Mat::step, Rice::AttrAccess::Read).
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
    });

  using Variant_T = typename detail::tuple_to_variant<Mat_Tuple_T>::type;
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
  rb_define_alias(rb_cCvMat, "at", "[]");

  // Row access
  using Buffer_Tuple_T = typename detail::tuple_map<Buffer, Mat_Tuple_T>::type;
  using Buffer_Variant_T = detail::tuple_to_variant<Buffer_Tuple_T>::type;
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

  // Setup iteration
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
  
  rb_cCvMat.define_constant("MAGIC_VAL", (int)cv::Mat::MAGIC_VAL);
  rb_cCvMat.define_constant("AUTO_STEP", (int)cv::Mat::AUTO_STEP);
  rb_cCvMat.define_constant("CONTINUOUS_FLAG", (int)cv::Mat::CONTINUOUS_FLAG);
  rb_cCvMat.define_constant("SUBMATRIX_FLAG", (int)cv::Mat::SUBMATRIX_FLAG);
  
  rb_cCvMat.define_constant("MAGIC_MASK", (int)cv::Mat::MAGIC_MASK);
  rb_cCvMat.define_constant("TYPE_MASK", (int)cv::Mat::TYPE_MASK);
  rb_cCvMat.define_constant("DEPTH_MASK", (int)cv::Mat::DEPTH_MASK);

  rb_cMat1b = define_class_under<cv::Mat_<unsigned char>, cv::Mat>(rb_mCv, "Mat1b").
    define(&Mat__builder<Data_Type<cv::Mat_<unsigned char>>, unsigned char>);
  
  rb_cMat2b = define_class_under<cv::Mat_<cv::Vec<unsigned char, 2>>, cv::Mat>(rb_mCv, "Mat2b").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<unsigned char, 2>>>, cv::Vec<unsigned char, 2>>);
  
  rb_cMat3b = define_class_under<cv::Mat_<cv::Vec<unsigned char, 3>>, cv::Mat>(rb_mCv, "Mat3b").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<unsigned char, 3>>>, cv::Vec<unsigned char, 3>>);
  
  rb_cMat4b = define_class_under<cv::Mat_<cv::Vec<unsigned char, 4>>, cv::Mat>(rb_mCv, "Mat4b").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<unsigned char, 4>>>, cv::Vec<unsigned char, 4>>);
  
  rb_cMat1s = define_class_under<cv::Mat_<short>, cv::Mat>(rb_mCv, "Mat1s").
    define(&Mat__builder<Data_Type<cv::Mat_<short>>, short>);
  
  rb_cMat2s = define_class_under<cv::Mat_<cv::Vec<short, 2>>, cv::Mat>(rb_mCv, "Mat2s").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<short, 2>>>, cv::Vec<short, 2>>);
  
  rb_cMat3s = define_class_under<cv::Mat_<cv::Vec<short, 3>>, cv::Mat>(rb_mCv, "Mat3s").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<short, 3>>>, cv::Vec<short, 3>>);
  
  rb_cMat4s = define_class_under<cv::Mat_<cv::Vec<short, 4>>, cv::Mat>(rb_mCv, "Mat4s").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<short, 4>>>, cv::Vec<short, 4>>);
  
  rb_cMat1w = define_class_under<cv::Mat_<unsigned short>, cv::Mat>(rb_mCv, "Mat1w").
    define(&Mat__builder<Data_Type<cv::Mat_<unsigned short>>, unsigned short>);
  
  rb_cMat2w = define_class_under<cv::Mat_<cv::Vec<unsigned short, 2>>, cv::Mat>(rb_mCv, "Mat2w").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<unsigned short, 2>>>, cv::Vec<unsigned short, 2>>);
  
  rb_cMat3w = define_class_under<cv::Mat_<cv::Vec<unsigned short, 3>>, cv::Mat>(rb_mCv, "Mat3w").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<unsigned short, 3>>>, cv::Vec<unsigned short, 3>>);
  
  rb_cMat4w = define_class_under<cv::Mat_<cv::Vec<unsigned short, 4>>, cv::Mat>(rb_mCv, "Mat4w").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<unsigned short, 4>>>, cv::Vec<unsigned short, 4>>);
  
  rb_cMat1i = define_class_under<cv::Mat_<int>, cv::Mat>(rb_mCv, "Mat1i").
    define(&Mat__builder<Data_Type<cv::Mat_<int>>, int>);
  
  rb_cMat2i = define_class_under<cv::Mat_<cv::Vec<int, 2>>, cv::Mat>(rb_mCv, "Mat2i").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<int, 2>>>, cv::Vec<int, 2>>);
  
  rb_cMat3i = define_class_under<cv::Mat_<cv::Vec<int, 3>>, cv::Mat>(rb_mCv, "Mat3i").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<int, 3>>>, cv::Vec<int, 3>>);
  
  rb_cMat4i = define_class_under<cv::Mat_<cv::Vec<int, 4>>, cv::Mat>(rb_mCv, "Mat4i").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<int, 4>>>, cv::Vec<int, 4>>);
  
  rb_cMat1f = define_class_under<cv::Mat_<float>, cv::Mat>(rb_mCv, "Mat1f").
    define(&Mat__builder<Data_Type<cv::Mat_<float>>, float>);
  
  rb_cMat2f = define_class_under<cv::Mat_<cv::Vec<float, 2>>, cv::Mat>(rb_mCv, "Mat2f").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<float, 2>>>, cv::Vec<float, 2>>);
  
  rb_cMat3f = define_class_under<cv::Mat_<cv::Vec<float, 3>>, cv::Mat>(rb_mCv, "Mat3f").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<float, 3>>>, cv::Vec<float, 3>>);
  
  rb_cMat4f = define_class_under<cv::Mat_<cv::Vec<float, 4>>, cv::Mat>(rb_mCv, "Mat4f").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<float, 4>>>, cv::Vec<float, 4>>);

  // For corner_eigen_vals_and_vecs
  rb_cMat6f = define_class_under<cv::Mat_<cv::Vec<float, 6>>, cv::Mat>(rb_mCv, "Mat6f").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<float, 6>>>, cv::Vec<float, 6>>);
    
  rb_cMat1d = define_class_under<cv::Mat_<double>, cv::Mat>(rb_mCv, "Mat1d").
    define(&Mat__builder<Data_Type<cv::Mat_<double>>, double>);
  
  rb_cMat2d = define_class_under<cv::Mat_<cv::Vec<double, 2>>, cv::Mat>(rb_mCv, "Mat2d").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<double, 2>>>, cv::Vec<double, 2>>);
  
  rb_cMat3d = define_class_under<cv::Mat_<cv::Vec<double, 3>>, cv::Mat>(rb_mCv, "Mat3d").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<double, 3>>>, cv::Vec<double, 3>>);
  
  rb_cMat4d = define_class_under<cv::Mat_<cv::Vec<double, 4>>, cv::Mat>(rb_mCv, "Mat4d").
    define(&Mat__builder<Data_Type<cv::Mat_<cv::Vec<double, 4>>>, cv::Vec<double, 4>>);

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

  rb_cCvUMat = define_class_under<cv::UMat>(rb_mCv, "UMat").
    define_constructor(Constructor<cv::UMat, cv::UMatUsageFlags>(),
      Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::UMatUsageFlags::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, int, int, int, cv::UMatUsageFlags>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::UMatUsageFlags::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, cv::Size, int, cv::UMatUsageFlags>(),
      Arg("size"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::UMatUsageFlags::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, int, int, int, const cv::Scalar&, cv::UMatUsageFlags>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("s"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::UMatUsageFlags::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, cv::Size, int, const cv::Scalar&, cv::UMatUsageFlags>(),
      Arg("size"), Arg("type"), Arg("s"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::UMatUsageFlags::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, int, const int*, int, cv::UMatUsageFlags>(),
      Arg("ndims"), Arg("sizes"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::UMatUsageFlags::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, int, const int*, int, const cv::Scalar&, cv::UMatUsageFlags>(),
      Arg("ndims"), Arg("sizes"), Arg("type"), Arg("s"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::UMatUsageFlags::USAGE_DEFAULT)).
    define_constructor(Constructor<cv::UMat, const cv::UMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::UMat, const cv::UMat&, const cv::Range&, const cv::Range&>(),
      Arg("m"), Arg("row_range"), Arg("col_range") = static_cast<const cv::Range &>(cv::Range::all())).
    define_constructor(Constructor<cv::UMat, const cv::UMat&, const cv::Rect&>(),
      Arg("m"), Arg("roi")).
    define_constructor(Constructor<cv::UMat, const cv::UMat&, const cv::Range*>(),
      Arg("m"), Arg("ranges")).
    define_constructor(Constructor<cv::UMat, const cv::UMat&, const std::vector<cv::Range>&>(),
      Arg("m"), Arg("ranges")).
    define_method("get_mat", &cv::UMat::getMat,
      Arg("flags")).
    define_method("row", &cv::UMat::row,
      Arg("y")).
    define_method("col", &cv::UMat::col,
      Arg("x")).
    define_method<cv::UMat(cv::UMat::*)(int, int) const>("row_range", &cv::UMat::rowRange,
      Arg("startrow"), Arg("endrow")).
    define_method<cv::UMat(cv::UMat::*)(const cv::Range&) const>("row_range", &cv::UMat::rowRange,
      Arg("r")).
    define_method<cv::UMat(cv::UMat::*)(int, int) const>("col_range", &cv::UMat::colRange,
      Arg("startcol"), Arg("endcol")).
    define_method<cv::UMat(cv::UMat::*)(const cv::Range&) const>("col_range", &cv::UMat::colRange,
      Arg("r")).
    define_method<cv::UMat(cv::UMat::*)(int) const>("diag", &cv::UMat::diag,
      Arg("d") = static_cast<int>(0)).
    define_singleton_function<cv::UMat(*)(const cv::UMat&, cv::UMatUsageFlags)>("diag", &cv::UMat::diag,
      Arg("d"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(const cv::UMat&)>("diag", &cv::UMat::diag,
      Arg("d")).
    define_method("clone", &cv::UMat::clone).
    define_method<void(cv::UMat::*)(cv::OutputArray) const>("copy_to", &cv::UMat::copyTo,
      Arg("m")).
    define_method<void(cv::UMat::*)(cv::OutputArray, cv::InputArray) const>("copy_to", &cv::UMat::copyTo,
      Arg("m"), Arg("mask")).
    define_method("convert_to", &cv::UMat::convertTo,
      Arg("m"), Arg("rtype"), Arg("alpha") = static_cast<double>(1), Arg("beta") = static_cast<double>(0)).
    define_method("assign_to", &cv::UMat::assignTo,
      Arg("m"), Arg("type") = static_cast<int>(-1)).
    define_method("set_to", &cv::UMat::setTo,
      Arg("value"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray())).
    define_method<cv::UMat(cv::UMat::*)(int, int) const>("reshape", &cv::UMat::reshape,
      Arg("cn"), Arg("rows") = static_cast<int>(0)).
    define_method<cv::UMat(cv::UMat::*)(int, int, const int*) const>("reshape", &cv::UMat::reshape,
      Arg("cn"), Arg("newndims"), Arg("newsz")).
    define_method("t", &cv::UMat::t).
    define_method("inv", &cv::UMat::inv,
      Arg("method") = static_cast<int>(cv::DecompTypes::DECOMP_LU)).
    define_method("mul", &cv::UMat::mul,
      Arg("m"), Arg("scale") = static_cast<double>(1)).
    define_method("dot", &cv::UMat::dot,
      Arg("m")).
    define_singleton_function<cv::UMat(*)(int, int, int, cv::UMatUsageFlags)>("zeros", &cv::UMat::zeros,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(cv::Size, int, cv::UMatUsageFlags)>("zeros", &cv::UMat::zeros,
      Arg("size"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(int, const int*, int, cv::UMatUsageFlags)>("zeros", &cv::UMat::zeros,
      Arg("ndims"), Arg("sz"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(int, int, int)>("zeros", &cv::UMat::zeros,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_singleton_function<cv::UMat(*)(cv::Size, int)>("zeros", &cv::UMat::zeros,
      Arg("size"), Arg("type")).
    define_singleton_function<cv::UMat(*)(int, const int*, int)>("zeros", &cv::UMat::zeros,
      Arg("ndims"), Arg("sz"), Arg("type")).
    define_singleton_function<cv::UMat(*)(int, int, int, cv::UMatUsageFlags)>("ones", &cv::UMat::ones,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(cv::Size, int, cv::UMatUsageFlags)>("ones", &cv::UMat::ones,
      Arg("size"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(int, const int*, int, cv::UMatUsageFlags)>("ones", &cv::UMat::ones,
      Arg("ndims"), Arg("sz"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(int, int, int)>("ones", &cv::UMat::ones,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_singleton_function<cv::UMat(*)(cv::Size, int)>("ones", &cv::UMat::ones,
      Arg("size"), Arg("type")).
    define_singleton_function<cv::UMat(*)(int, const int*, int)>("ones", &cv::UMat::ones,
      Arg("ndims"), Arg("sz"), Arg("type")).
    define_singleton_function<cv::UMat(*)(int, int, int, cv::UMatUsageFlags)>("eye", &cv::UMat::eye,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(cv::Size, int, cv::UMatUsageFlags)>("eye", &cv::UMat::eye,
      Arg("size"), Arg("type"), Arg("usage_flags")).
    define_singleton_function<cv::UMat(*)(int, int, int)>("eye", &cv::UMat::eye,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_singleton_function<cv::UMat(*)(cv::Size, int)>("eye", &cv::UMat::eye,
      Arg("size"), Arg("type")).
    define_method<void(cv::UMat::*)(int, int, int, cv::UMatUsageFlags)>("create", &cv::UMat::create,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::UMatUsageFlags::USAGE_DEFAULT)).
    define_method<void(cv::UMat::*)(cv::Size, int, cv::UMatUsageFlags)>("create", &cv::UMat::create,
      Arg("size"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::UMatUsageFlags::USAGE_DEFAULT)).
    define_method<void(cv::UMat::*)(int, const int*, int, cv::UMatUsageFlags)>("create", &cv::UMat::create,
      Arg("ndims"), Arg("sizes"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::UMatUsageFlags::USAGE_DEFAULT)).
    define_method<void(cv::UMat::*)(const std::vector<int>&, int, cv::UMatUsageFlags)>("create", &cv::UMat::create,
      Arg("sizes"), Arg("type"), Arg("usage_flags") = static_cast<cv::UMatUsageFlags>(cv::UMatUsageFlags::USAGE_DEFAULT)).
    define_method<void(cv::UMat::*)()>("addref", &cv::UMat::addref).
    define_method<void(cv::UMat::*)()>("release", &cv::UMat::release).
    define_method<void(cv::UMat::*)()>("deallocate", &cv::UMat::deallocate).
    define_method<void(cv::UMat::*)(const cv::UMat&)>("copy_size", &cv::UMat::copySize,
      Arg("m")).
    define_method<void(cv::UMat::*)(cv::Size&, cv::Point&) const>("locate_roi", &cv::UMat::locateROI,
      Arg("whole_size"), Arg("ofs")).
    define_method<cv::UMat&(cv::UMat::*)(int, int, int, int)>("adjust_roi", &cv::UMat::adjustROI,
      Arg("dtop"), Arg("dbottom"), Arg("dleft"), Arg("dright")).
    define_method<cv::UMat(cv::UMat::*)(cv::Range, cv::Range) const>("[]", &cv::UMat::operator(),
      Arg("row_range"), Arg("col_range")).
    define_method<cv::UMat(cv::UMat::*)(const cv::Rect&) const>("[]", &cv::UMat::operator(),
      Arg("roi")).
    define_method<cv::UMat(cv::UMat::*)(const cv::Range*) const>("[]", &cv::UMat::operator(),
      Arg("ranges")).
    define_method<cv::UMat(cv::UMat::*)(const std::vector<cv::Range>&) const>("[]", &cv::UMat::operator(),
      Arg("ranges")).
    define_method("continuous?", &cv::UMat::isContinuous).
    define_method("submatrix?", &cv::UMat::isSubmatrix).
    define_method("elem_size", &cv::UMat::elemSize).
    define_method("elem_size1", &cv::UMat::elemSize1).
    define_method("type", &cv::UMat::type).
    define_method("depth", &cv::UMat::depth).
    define_method("channels", &cv::UMat::channels).
    define_method("step1", &cv::UMat::step1,
      Arg("i") = static_cast<int>(0)).
    define_method("empty?", &cv::UMat::empty).
    define_method("total", &cv::UMat::total).
    define_method("check_vector", &cv::UMat::checkVector,
      Arg("elem_channels"), Arg("depth") = static_cast<int>(-1), Arg("require_continuous") = static_cast<bool>(true)).
    define_method("handle", &cv::UMat::handle,
      Arg("access_flags")).
    define_method("ndoffset", &cv::UMat::ndoffset,
      Arg("ofs")).
    define_attr("flags", &cv::UMat::flags).
    define_attr("dims", &cv::UMat::dims).
    define_attr("rows", &cv::UMat::rows).
    define_attr("cols", &cv::UMat::cols).
    define_attr("allocator", &cv::UMat::allocator).
    define_attr("usage_flags", &cv::UMat::usageFlags).
    define_singleton_function("get_std_allocator", &cv::UMat::getStdAllocator).
    define_method("update_continuity_flag", &cv::UMat::updateContinuityFlag).
    define_attr("u", &cv::UMat::u).
    define_attr("offset", &cv::UMat::offset).
    define_attr("size", &cv::UMat::size).
    define_attr("step", &cv::UMat::step, Rice::AttrAccess::Read).
    define_method("inspect", [](const cv::UMat& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });

  rb_cCvUMat.define_constant("MAGIC_VAL", (int)cv::UMat::MAGIC_VAL);
  rb_cCvUMat.define_constant("AUTO_STEP", (int)cv::UMat::AUTO_STEP);
  rb_cCvUMat.define_constant("CONTINUOUS_FLAG", (int)cv::UMat::CONTINUOUS_FLAG);
  rb_cCvUMat.define_constant("SUBMATRIX_FLAG", (int)cv::UMat::SUBMATRIX_FLAG);
  
  rb_cCvUMat.define_constant("MAGIC_MASK", (int)cv::UMat::MAGIC_MASK);
  rb_cCvUMat.define_constant("TYPE_MASK", (int)cv::UMat::TYPE_MASK);
  rb_cCvUMat.define_constant("DEPTH_MASK", (int)cv::UMat::DEPTH_MASK);
  
  rb_cCvSparseMat = define_class_under<cv::SparseMat>(rb_mCv, "SparseMat").
    define_constructor(Constructor<cv::SparseMat>()).
    define_constructor(Constructor<cv::SparseMat, int, const int*, int>(),
      Arg("dims"), Arg("_sizes"), Arg("_type")).
    define_constructor(Constructor<cv::SparseMat, const cv::SparseMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::SparseMat, const cv::Mat&>(),
      Arg("m")).
    define_method("clone", &cv::SparseMat::clone).
    define_method<void(cv::SparseMat::*)(cv::SparseMat&) const>("copy_to", &cv::SparseMat::copyTo,
      Arg("m")).
    define_method<void(cv::SparseMat::*)(cv::Mat&) const>("copy_to", &cv::SparseMat::copyTo,
      Arg("m")).
    define_method<void(cv::SparseMat::*)(cv::SparseMat&, int, double) const>("convert_to", &cv::SparseMat::convertTo,
      Arg("m"), Arg("rtype"), Arg("alpha") = static_cast<double>(1)).
    define_method<void(cv::SparseMat::*)(cv::Mat&, int, double, double) const>("convert_to", &cv::SparseMat::convertTo,
      Arg("m"), Arg("rtype"), Arg("alpha") = static_cast<double>(1), Arg("beta") = static_cast<double>(0)).
    define_method("assign_to", &cv::SparseMat::assignTo,
      Arg("m"), Arg("type") = static_cast<int>(-1)).
    define_method("create", &cv::SparseMat::create,
      Arg("dims"), Arg("_sizes"), Arg("_type")).
    define_method("clear", &cv::SparseMat::clear).
    define_method("addref", &cv::SparseMat::addref).
    define_method("release", &cv::SparseMat::release).
    define_method("elem_size", &cv::SparseMat::elemSize).
    define_method("elem_size1", &cv::SparseMat::elemSize1).
    define_method("type", &cv::SparseMat::type).
    define_method("depth", &cv::SparseMat::depth).
    define_method("channels", &cv::SparseMat::channels).
    define_method<const int*(cv::SparseMat::*)() const>("size", &cv::SparseMat::size).
    define_method<int(cv::SparseMat::*)(int) const>("size", &cv::SparseMat::size,
      Arg("i")).
    define_method("dims", &cv::SparseMat::dims).
    define_method("nzcount", &cv::SparseMat::nzcount).
    define_method<::size_t(cv::SparseMat::*)(int) const>("hash", &cv::SparseMat::hash,
      Arg("i0")).
    define_method<::size_t(cv::SparseMat::*)(int, int) const>("hash", &cv::SparseMat::hash,
      Arg("i0"), Arg("i1")).
    define_method<::size_t(cv::SparseMat::*)(int, int, int) const>("hash", &cv::SparseMat::hash,
      Arg("i0"), Arg("i1"), Arg("i2")).
    define_method<::size_t(cv::SparseMat::*)(const int*) const>("hash", &cv::SparseMat::hash,
      Arg("idx")).
    define_method<uchar*(cv::SparseMat::*)(int, bool, ::size_t*)>("ptr", &cv::SparseMat::ptr,
      Arg("i0"), Arg("create_missing"), Arg("hashval") = static_cast<size_t *>(0)).
    define_method<uchar*(cv::SparseMat::*)(int, int, bool, ::size_t*)>("ptr", &cv::SparseMat::ptr,
      Arg("i0"), Arg("i1"), Arg("create_missing"), Arg("hashval") = static_cast<size_t *>(0)).
    define_method<uchar*(cv::SparseMat::*)(int, int, int, bool, ::size_t*)>("ptr", &cv::SparseMat::ptr,
      Arg("i0"), Arg("i1"), Arg("i2"), Arg("create_missing"), Arg("hashval") = static_cast<size_t *>(0)).
    define_method<uchar*(cv::SparseMat::*)(const int*, bool, ::size_t*)>("ptr", &cv::SparseMat::ptr,
      Arg("idx"), Arg("create_missing"), Arg("hashval") = static_cast<size_t *>(0)).
    define_method<void(cv::SparseMat::*)(int, int, ::size_t*)>("erase", &cv::SparseMat::erase,
      Arg("i0"), Arg("i1"), Arg("hashval") = static_cast<size_t *>(0)).
    define_method<void(cv::SparseMat::*)(int, int, int, ::size_t*)>("erase", &cv::SparseMat::erase,
      Arg("i0"), Arg("i1"), Arg("i2"), Arg("hashval") = static_cast<size_t *>(0)).
    define_method<void(cv::SparseMat::*)(const int*, ::size_t*)>("erase", &cv::SparseMat::erase,
      Arg("idx"), Arg("hashval") = 0).
    //define_iterator<cv::SparseMatIterator(cv::SparseMat::*)()>(&cv::SparseMat::begin, &cv::SparseMat::end, "each").
    //define_iterator<cv::SparseMatConstIterator(cv::SparseMat::*)() const>(&cv::SparseMat::begin, &cv::SparseMat::end, "each_const").
    define_method<cv::SparseMat::Node*(cv::SparseMat::*)(::size_t)>("node", &cv::SparseMat::node,
      Arg("nidx")).
    define_method<const cv::SparseMat::Node*(cv::SparseMat::*)(::size_t) const>("node", &cv::SparseMat::node,
      Arg("nidx")).
    define_method<uchar*(cv::SparseMat::*)(const int*, ::size_t)>("new_node", &cv::SparseMat::newNode,
      Arg("idx"), Arg("hashval")).
    define_method<void(cv::SparseMat::*)(::size_t, ::size_t, ::size_t)>("remove_node", &cv::SparseMat::removeNode,
      Arg("hidx"), Arg("nidx"), Arg("previdx")).
    define_method<void(cv::SparseMat::*)(::size_t)>("resize_hash_tab", &cv::SparseMat::resizeHashTab,
      Arg("newsize")).
    define_attr("flags", &cv::SparseMat::flags).
    define_attr("hdr", &cv::SparseMat::hdr);
  
  rb_cCvSparseMatHdr = define_class_under<cv::SparseMat::Hdr>(rb_cCvSparseMat, "Hdr").
    define_constructor(Constructor<cv::SparseMat::Hdr, int, const int*, int>(),
      Arg("_dims"), Arg("_sizes"), Arg("_type")).
    define_method<void(cv::SparseMat::Hdr::*)()>("clear", &cv::SparseMat::Hdr::clear).
    define_attr("refcount", &cv::SparseMat::Hdr::refcount).
    define_attr("dims", &cv::SparseMat::Hdr::dims).
    define_attr("value_offset", &cv::SparseMat::Hdr::valueOffset).
    define_attr("node_size", &cv::SparseMat::Hdr::nodeSize).
    define_attr("node_count", &cv::SparseMat::Hdr::nodeCount).
    define_attr("free_list", &cv::SparseMat::Hdr::freeList).
    define_attr("pool", &cv::SparseMat::Hdr::pool).
    define_attr("hashtab", &cv::SparseMat::Hdr::hashtab);
  
  rb_cCvSparseMatNode = define_class_under<cv::SparseMat::Node>(rb_cCvSparseMat, "Node").
    define_constructor(Constructor<cv::SparseMat::Node>()).
    define_attr("hashval", &cv::SparseMat::Node::hashval).
    define_attr("next", &cv::SparseMat::Node::next).
    define_attr("idx", &cv::SparseMat::Node::idx, Rice::AttrAccess::Read);
 
  rb_cCvSparseMat.define_constant("MAGIC_VAL", (int)cv::SparseMat::MAGIC_VAL);
  rb_cCvSparseMat.define_constant("MAX_DIM", (int)cv::SparseMat::MAX_DIM);
  rb_cCvSparseMat.define_constant("HASH_SCALE", (int)cv::SparseMat::HASH_SCALE);
  rb_cCvSparseMat.define_constant("HASH_BIT", (int)cv::SparseMat::HASH_BIT);
  
  rb_cCvMatConstIterator = define_class_under<cv::MatConstIterator>(rb_mCv, "MatConstIterator").
    define_constructor(Constructor<cv::MatConstIterator>()).
    define_constructor(Constructor<cv::MatConstIterator, const cv::Mat*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::MatConstIterator, const cv::Mat*, int, int>(),
      Arg("_m"), Arg("_row"), Arg("_col") = static_cast<int>(0)).
    define_constructor(Constructor<cv::MatConstIterator, const cv::Mat*, cv::Point>(),
      Arg("_m"), Arg("_pt")).
    // define_constructor(Constructor<cv::MatConstIterator, const cv::Mat*, const int*>(),
     //  Arg("_m"), Arg("_idx")).
    define_constructor(Constructor<cv::MatConstIterator, const cv::MatConstIterator&>(),
      Arg("it")).
    // define_method("dereference", &cv::MatConstIterator::operator*).
    // define_method("[]", &cv::MatConstIterator::operator[],
    //   Arg("i")).
    define_method("assign_plus", &cv::MatConstIterator::operator+=,
      Arg("ofs")).
    define_method("assign_minus", &cv::MatConstIterator::operator-=,
      Arg("ofs")).
    define_method<cv::MatConstIterator & (cv::MatConstIterator::*)()>("decrement", &cv::MatConstIterator::operator--).
    define_method<cv::MatConstIterator(cv::MatConstIterator::*)(int)>("decrement", &cv::MatConstIterator::operator--,
      Arg("")).
    define_method<cv::MatConstIterator & (cv::MatConstIterator::*)()>("increment", &cv::MatConstIterator::operator++).
    define_method<cv::MatConstIterator(cv::MatConstIterator::*)(int)>("increment", &cv::MatConstIterator::operator++,
      Arg("")).
    define_method<cv::Point(cv::MatConstIterator::*)() const>("pos", &cv::MatConstIterator::pos).
    define_method<void(cv::MatConstIterator::*)(int*) const>("pos", &cv::MatConstIterator::pos,
      Arg("_idx")).
    define_method("lpos", &cv::MatConstIterator::lpos).
    define_method<void(cv::MatConstIterator::*)(::ptrdiff_t, bool)>("seek", &cv::MatConstIterator::seek,
      Arg("ofs"), Arg("relative") = static_cast<bool>(false)).
    define_method<void(cv::MatConstIterator::*)(const int*, bool)>("seek", &cv::MatConstIterator::seek,
      Arg("_idx"), Arg("relative") = static_cast<bool>(false)).
    define_attr("m", &cv::MatConstIterator::m).
    define_attr("elem_size", &cv::MatConstIterator::elemSize).
    define_attr("ptr", &cv::MatConstIterator::ptr).
    define_attr("slice_start", &cv::MatConstIterator::sliceStart).
    define_attr("slice_end", &cv::MatConstIterator::sliceEnd);
  
  rb_cCvSparseMatConstIterator = define_class_under<cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator").
    define_constructor(Constructor<cv::SparseMatConstIterator>()).
    define_constructor(Constructor<cv::SparseMatConstIterator, const cv::SparseMat*>(),
      Arg("_m")).
    define_constructor(Constructor<cv::SparseMatConstIterator, const cv::SparseMatConstIterator&>(),
      Arg("it")).
    define_method<const cv::SparseMat::Node*(cv::SparseMatConstIterator::*)() const>("node", &cv::SparseMatConstIterator::node).
    //define_method<cv::SparseMatConstIterator&(cv::SparseMatConstIterator::*)()>("decrement", &cv::SparseMatConstIterator::operator--).
    //define_method<cv::SparseMatConstIterator(cv::SparseMatConstIterator::*)(int)>("decrement", &cv::SparseMatConstIterator::operator--,
    //  Arg("")).
    define_method<cv::SparseMatConstIterator&(cv::SparseMatConstIterator::*)()>("increment", &cv::SparseMatConstIterator::operator++).
    define_method<cv::SparseMatConstIterator(cv::SparseMatConstIterator::*)(int)>("increment", &cv::SparseMatConstIterator::operator++,
      Arg("")).
    define_method("seek_end", &cv::SparseMatConstIterator::seekEnd).
    define_attr("m", &cv::SparseMatConstIterator::m).
    define_attr("hashidx", &cv::SparseMatConstIterator::hashidx).
    define_attr("ptr", &cv::SparseMatConstIterator::ptr);
  
  rb_cCvSparseMatIterator = define_class_under<cv::SparseMatIterator, cv::SparseMatConstIterator>(rb_mCv, "SparseMatIterator").
    define_constructor(Constructor<cv::SparseMatIterator>()).
    define_constructor(Constructor<cv::SparseMatIterator, cv::SparseMat*>(),
      Arg("_m")).
    //define_constructor(Constructor<cv::SparseMatIterator, cv::SparseMat*, const int*>(),
    //  Arg("_m"), Arg("idx")).
    define_constructor(Constructor<cv::SparseMatIterator, const cv::SparseMatIterator&>(),
      Arg("it")).
    define_method("node", &cv::SparseMatIterator::node).
    define_method<cv::SparseMatIterator&(cv::SparseMatIterator::*)()>("increment", &cv::SparseMatIterator::operator++).
    define_method<cv::SparseMatIterator(cv::SparseMatIterator::*)(int)>("increment", &cv::SparseMatIterator::operator++,
      Arg(""));
  
  rb_cSparseMat1b = define_class_under<cv::SparseMat_<unsigned char>, cv::SparseMat>(rb_mCv, "SparseMat1b").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<unsigned char>>, unsigned char>);

  rb_cSparseMat2b = define_class_under<cv::SparseMat_<cv::Vec<unsigned char, 2>>, cv::SparseMat>(rb_mCv, "SparseMat2b").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<unsigned char, 2>>>, cv::Vec<unsigned char, 2>>);

  rb_cSparseMat3b = define_class_under<cv::SparseMat_<cv::Vec<unsigned char, 3>>, cv::SparseMat>(rb_mCv, "SparseMat3b").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<unsigned char, 3>>>, cv::Vec<unsigned char, 3>>);

  rb_cSparseMat4b = define_class_under<cv::SparseMat_<cv::Vec<unsigned char, 4>>, cv::SparseMat>(rb_mCv, "SparseMat4b").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<unsigned char, 4>>>, cv::Vec<unsigned char, 4>>);

  rb_cSparseMat1s = define_class_under<cv::SparseMat_<short>, cv::SparseMat>(rb_mCv, "SparseMat1s").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<short>>, short>);

  rb_cSparseMat2s = define_class_under<cv::SparseMat_<cv::Vec<short, 2>>, cv::SparseMat>(rb_mCv, "SparseMat2s").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<short, 2>>>, cv::Vec<short, 2>>);

  rb_cSparseMat3s = define_class_under<cv::SparseMat_<cv::Vec<short, 3>>, cv::SparseMat>(rb_mCv, "SparseMat3s").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<short, 3>>>, cv::Vec<short, 3>>);

  rb_cSparseMat4s = define_class_under<cv::SparseMat_<cv::Vec<short, 4>>, cv::SparseMat>(rb_mCv, "SparseMat4s").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<short, 4>>>, cv::Vec<short, 4>>);

  rb_cSparseMat1w = define_class_under<cv::SparseMat_<unsigned short>, cv::SparseMat>(rb_mCv, "SparseMat1w").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<unsigned short>>, unsigned short>);

  rb_cSparseMat2w = define_class_under<cv::SparseMat_<cv::Vec<unsigned short, 2>>, cv::SparseMat>(rb_mCv, "SparseMat2w").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<unsigned short, 2>>>, cv::Vec<unsigned short, 2>>);

  rb_cSparseMat3w = define_class_under<cv::SparseMat_<cv::Vec<unsigned short, 3>>, cv::SparseMat>(rb_mCv, "SparseMat3w").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<unsigned short, 3>>>, cv::Vec<unsigned short, 3>>);

  rb_cSparseMat4w = define_class_under<cv::SparseMat_<cv::Vec<unsigned short, 4>>, cv::SparseMat>(rb_mCv, "SparseMat4w").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<unsigned short, 4>>>, cv::Vec<unsigned short, 4>>);

  rb_cSparseMat1i = define_class_under<cv::SparseMat_<int>, cv::SparseMat>(rb_mCv, "SparseMat1i").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<int>>, int>);

  rb_cSparseMat2i = define_class_under<cv::SparseMat_<cv::Vec<int, 2>>, cv::SparseMat>(rb_mCv, "SparseMat2i").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<int, 2>>>, cv::Vec<int, 2>>);

  rb_cSparseMat3i = define_class_under<cv::SparseMat_<cv::Vec<int, 3>>, cv::SparseMat>(rb_mCv, "SparseMat3i").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<int, 3>>>, cv::Vec<int, 3>>);

  rb_cSparseMat4i = define_class_under<cv::SparseMat_<cv::Vec<int, 4>>, cv::SparseMat>(rb_mCv, "SparseMat4i").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<int, 4>>>, cv::Vec<int, 4>>);

  rb_cSparseMat1f = define_class_under<cv::SparseMat_<float>, cv::SparseMat>(rb_mCv, "SparseMat1f").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<float>>, float>);

  rb_cSparseMat2f = define_class_under<cv::SparseMat_<cv::Vec<float, 2>>, cv::SparseMat>(rb_mCv, "SparseMat2f").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<float, 2>>>, cv::Vec<float, 2>>);

  rb_cSparseMat3f = define_class_under<cv::SparseMat_<cv::Vec<float, 3>>, cv::SparseMat>(rb_mCv, "SparseMat3f").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<float, 3>>>, cv::Vec<float, 3>>);

  rb_cSparseMat4f = define_class_under<cv::SparseMat_<cv::Vec<float, 4>>, cv::SparseMat>(rb_mCv, "SparseMat4f").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<float, 4>>>, cv::Vec<float, 4>>);

  rb_cSparseMat6f = define_class_under<cv::SparseMat_<cv::Vec<float, 6>>, cv::SparseMat>(rb_mCv, "SparseMat6f").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<float, 6>>>, cv::Vec<float, 6>>);

  rb_cSparseMat1d = define_class_under<cv::SparseMat_<double>, cv::SparseMat>(rb_mCv, "SparseMat1d").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<double>>, double>);

  rb_cSparseMat2d = define_class_under<cv::SparseMat_<cv::Vec<double, 2>>, cv::SparseMat>(rb_mCv, "SparseMat2d").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<double, 2>>>, cv::Vec<double, 2>>);

  rb_cSparseMat3d = define_class_under<cv::SparseMat_<cv::Vec<double, 3>>, cv::SparseMat>(rb_mCv, "SparseMat3d").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<double, 3>>>, cv::Vec<double, 3>>);

  rb_cSparseMat4d = define_class_under<cv::SparseMat_<cv::Vec<double, 4>>, cv::SparseMat>(rb_mCv, "SparseMat4d").
    define(&SparseMat__builder<Data_Type<cv::SparseMat_<cv::Vec<double, 4>>>, cv::Vec<double, 4>>);

  rb_cSparseMatConstIterator1b = define_class_under<cv::SparseMatConstIterator_<unsigned char>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator1b").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<unsigned char>>, unsigned char>);

  rb_cSparseMatConstIterator2b = define_class_under<cv::SparseMatConstIterator_<cv::Vec<unsigned char, 2>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator2b").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<unsigned char, 2>>>, cv::Vec<unsigned char, 2>>);

  rb_cSparseMatConstIterator3b = define_class_under<cv::SparseMatConstIterator_<cv::Vec<unsigned char, 3>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator3b").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<unsigned char, 3>>>, cv::Vec<unsigned char, 3>>);

  rb_cSparseMatConstIterator4b = define_class_under<cv::SparseMatConstIterator_<cv::Vec<unsigned char, 4>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator4b").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<unsigned char, 4>>>, cv::Vec<unsigned char, 4>>);

  rb_cSparseMatConstIterator1s = define_class_under<cv::SparseMatConstIterator_<short>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator1s").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<short>>, short>);

  rb_cSparseMatConstIterator2s = define_class_under<cv::SparseMatConstIterator_<cv::Vec<short, 2>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator2s").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<short, 2>>>, cv::Vec<short, 2>>);

  rb_cSparseMatConstIterator3s = define_class_under<cv::SparseMatConstIterator_<cv::Vec<short, 3>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator3s").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<short, 3>>>, cv::Vec<short, 3>>);

  rb_cSparseMatConstIterator4s = define_class_under<cv::SparseMatConstIterator_<cv::Vec<short, 4>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator4s").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<short, 4>>>, cv::Vec<short, 4>>);

  rb_cSparseMatConstIterator1w = define_class_under<cv::SparseMatConstIterator_<unsigned short>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator1w").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<unsigned short>>, unsigned short>);

  rb_cSparseMatConstIterator2w = define_class_under<cv::SparseMatConstIterator_<cv::Vec<unsigned short, 2>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator2w").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<unsigned short, 2>>>, cv::Vec<unsigned short, 2>>);

  rb_cSparseMatConstIterator3w = define_class_under<cv::SparseMatConstIterator_<cv::Vec<unsigned short, 3>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator3w").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<unsigned short, 3>>>, cv::Vec<unsigned short, 3>>);

  rb_cSparseMatConstIterator4w = define_class_under<cv::SparseMatConstIterator_<cv::Vec<unsigned short, 4>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator4w").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<unsigned short, 4>>>, cv::Vec<unsigned short, 4>>);

  rb_cSparseMatConstIterator1i = define_class_under<cv::SparseMatConstIterator_<int>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator1i").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<int>>, int>);

  rb_cSparseMatConstIterator2i = define_class_under<cv::SparseMatConstIterator_<cv::Vec<int, 2>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator2i").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<int, 2>>>, cv::Vec<int, 2>>);

  rb_cSparseMatConstIterator3i = define_class_under<cv::SparseMatConstIterator_<cv::Vec<int, 3>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator3i").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<int, 3>>>, cv::Vec<int, 3>>);

  rb_cSparseMatConstIterator4i = define_class_under<cv::SparseMatConstIterator_<cv::Vec<int, 4>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator4i").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<int, 4>>>, cv::Vec<int, 4>>);

  rb_cSparseMatConstIterator1f = define_class_under<cv::SparseMatConstIterator_<float>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator1f").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<float>>, float>);

  rb_cSparseMatConstIterator2f = define_class_under<cv::SparseMatConstIterator_<cv::Vec<float, 2>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator2f").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<float, 2>>>, cv::Vec<float, 2>>);

  rb_cSparseMatConstIterator3f = define_class_under<cv::SparseMatConstIterator_<cv::Vec<float, 3>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator3f").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<float, 3>>>, cv::Vec<float, 3>>);

  rb_cSparseMatConstIterator4f = define_class_under<cv::SparseMatConstIterator_<cv::Vec<float, 4>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator4f").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<float, 4>>>, cv::Vec<float, 4>>);

  rb_cSparseMatConstIterator6f = define_class_under<cv::SparseMatConstIterator_<cv::Vec<float, 6>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator6f").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<float, 6>>>, cv::Vec<float, 6>>);

  rb_cSparseMatConstIterator1d = define_class_under<cv::SparseMatConstIterator_<double>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator1d").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<double>>, double>);

  rb_cSparseMatConstIterator2d = define_class_under<cv::SparseMatConstIterator_<cv::Vec<double, 2>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator2d").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<double, 2>>>, cv::Vec<double, 2>>);

  rb_cSparseMatConstIterator3d = define_class_under<cv::SparseMatConstIterator_<cv::Vec<double, 3>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator3d").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<double, 3>>>, cv::Vec<double, 3>>);

  rb_cSparseMatConstIterator4d = define_class_under<cv::SparseMatConstIterator_<cv::Vec<double, 4>>, cv::SparseMatConstIterator>(rb_mCv, "SparseMatConstIterator4d").
    define(&SparseMatConstIterator__builder<Data_Type<cv::SparseMatConstIterator_<cv::Vec<double, 4>>>, cv::Vec<double, 4>>);

  rb_cSparseMatIterator1b = define_class_under<cv::SparseMatIterator_<unsigned char>, cv::SparseMatConstIterator_<unsigned char>>(rb_mCv, "SparseMatIterator1b").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<unsigned char>>, unsigned char>);

  rb_cSparseMatIterator2b = define_class_under<cv::SparseMatIterator_<cv::Vec<unsigned char, 2>>, cv::SparseMatConstIterator_<cv::Vec<unsigned char, 2>>>(rb_mCv, "SparseMatIterator2b").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<unsigned char, 2>>>, cv::Vec<unsigned char, 2>>);

  rb_cSparseMatIterator3b = define_class_under<cv::SparseMatIterator_<cv::Vec<unsigned char, 3>>, cv::SparseMatConstIterator_<cv::Vec<unsigned char, 3>>>(rb_mCv, "SparseMatIterator3b").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<unsigned char, 3>>>, cv::Vec<unsigned char, 3>>);

  rb_cSparseMatIterator4b = define_class_under<cv::SparseMatIterator_<cv::Vec<unsigned char, 4>>, cv::SparseMatConstIterator_<cv::Vec<unsigned char, 4>>>(rb_mCv, "SparseMatIterator4b").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<unsigned char, 4>>>, cv::Vec<unsigned char, 4>>);

  rb_cSparseMatIterator1s = define_class_under<cv::SparseMatIterator_<short>, cv::SparseMatConstIterator_<short>>(rb_mCv, "SparseMatIterator1s").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<short>>, short>);

  rb_cSparseMatIterator2s = define_class_under<cv::SparseMatIterator_<cv::Vec<short, 2>>, cv::SparseMatConstIterator_<cv::Vec<short, 2>>>(rb_mCv, "SparseMatIterator2s").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<short, 2>>>, cv::Vec<short, 2>>);

  rb_cSparseMatIterator3s = define_class_under<cv::SparseMatIterator_<cv::Vec<short, 3>>, cv::SparseMatConstIterator_<cv::Vec<short, 3>>>(rb_mCv, "SparseMatIterator3s").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<short, 3>>>, cv::Vec<short, 3>>);

  rb_cSparseMatIterator4s = define_class_under<cv::SparseMatIterator_<cv::Vec<short, 4>>, cv::SparseMatConstIterator_<cv::Vec<short, 4>>>(rb_mCv, "SparseMatIterator4s").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<short, 4>>>, cv::Vec<short, 4>>);

  rb_cSparseMatIterator1w = define_class_under<cv::SparseMatIterator_<unsigned short>, cv::SparseMatConstIterator_<unsigned short>>(rb_mCv, "SparseMatIterator1w").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<unsigned short>>, unsigned short>);

  rb_cSparseMatIterator2w = define_class_under<cv::SparseMatIterator_<cv::Vec<unsigned short, 2>>, cv::SparseMatConstIterator_<cv::Vec<unsigned short, 2>>>(rb_mCv, "SparseMatIterator2w").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<unsigned short, 2>>>, cv::Vec<unsigned short, 2>>);

  rb_cSparseMatIterator3w = define_class_under<cv::SparseMatIterator_<cv::Vec<unsigned short, 3>>, cv::SparseMatConstIterator_<cv::Vec<unsigned short, 3>>>(rb_mCv, "SparseMatIterator3w").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<unsigned short, 3>>>, cv::Vec<unsigned short, 3>>);

  rb_cSparseMatIterator4w = define_class_under<cv::SparseMatIterator_<cv::Vec<unsigned short, 4>>, cv::SparseMatConstIterator_<cv::Vec<unsigned short, 4>>>(rb_mCv, "SparseMatIterator4w").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<unsigned short, 4>>>, cv::Vec<unsigned short, 4>>);

  rb_cSparseMatIterator1i = define_class_under<cv::SparseMatIterator_<int>, cv::SparseMatConstIterator_<int>>(rb_mCv, "SparseMatIterator1i").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<int>>, int>);

  rb_cSparseMatIterator2i = define_class_under<cv::SparseMatIterator_<cv::Vec<int, 2>>, cv::SparseMatConstIterator_<cv::Vec<int, 2>>>(rb_mCv, "SparseMatIterator2i").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<int, 2>>>, cv::Vec<int, 2>>);

  rb_cSparseMatIterator3i = define_class_under<cv::SparseMatIterator_<cv::Vec<int, 3>>, cv::SparseMatConstIterator_<cv::Vec<int, 3>>>(rb_mCv, "SparseMatIterator3i").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<int, 3>>>, cv::Vec<int, 3>>);

  rb_cSparseMatIterator4i = define_class_under<cv::SparseMatIterator_<cv::Vec<int, 4>>, cv::SparseMatConstIterator_<cv::Vec<int, 4>>>(rb_mCv, "SparseMatIterator4i").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<int, 4>>>, cv::Vec<int, 4>>);

  rb_cSparseMatIterator1f = define_class_under<cv::SparseMatIterator_<float>, cv::SparseMatConstIterator_<float>>(rb_mCv, "SparseMatIterator1f").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<float>>, float>);

  rb_cSparseMatIterator2f = define_class_under<cv::SparseMatIterator_<cv::Vec<float, 2>>, cv::SparseMatConstIterator_<cv::Vec<float, 2>>>(rb_mCv, "SparseMatIterator2f").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<float, 2>>>, cv::Vec<float, 2>>);

  rb_cSparseMatIterator3f = define_class_under<cv::SparseMatIterator_<cv::Vec<float, 3>>, cv::SparseMatConstIterator_<cv::Vec<float, 3>>>(rb_mCv, "SparseMatIterator3f").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<float, 3>>>, cv::Vec<float, 3>>);

  rb_cSparseMatIterator4f = define_class_under<cv::SparseMatIterator_<cv::Vec<float, 4>>, cv::SparseMatConstIterator_<cv::Vec<float, 4>>>(rb_mCv, "SparseMatIterator4f").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<float, 4>>>, cv::Vec<float, 4>>);

  rb_cSparseMatIterator6f = define_class_under<cv::SparseMatIterator_<cv::Vec<float, 6>>, cv::SparseMatConstIterator_<cv::Vec<float, 6>>>(rb_mCv, "SparseMatIterator6f").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<float, 6>>>, cv::Vec<float, 6>>);

  rb_cSparseMatIterator1d = define_class_under<cv::SparseMatIterator_<double>, cv::SparseMatConstIterator_<double>>(rb_mCv, "SparseMatIterator1d").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<double>>, double>);

  rb_cSparseMatIterator2d = define_class_under<cv::SparseMatIterator_<cv::Vec<double, 2>>, cv::SparseMatConstIterator_<cv::Vec<double, 2>>>(rb_mCv, "SparseMatIterator2d").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<double, 2>>>, cv::Vec<double, 2>>);

  rb_cSparseMatIterator3d = define_class_under<cv::SparseMatIterator_<cv::Vec<double, 3>>, cv::SparseMatConstIterator_<cv::Vec<double, 3>>>(rb_mCv, "SparseMatIterator3d").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<double, 3>>>, cv::Vec<double, 3>>);

  rb_cSparseMatIterator4d = define_class_under<cv::SparseMatIterator_<cv::Vec<double, 4>>, cv::SparseMatConstIterator_<cv::Vec<double, 4>>>(rb_mCv, "SparseMatIterator4d").
    define(&SparseMatIterator__builder<Data_Type<cv::SparseMatIterator_<cv::Vec<double, 4>>>, cv::Vec<double, 4>>);

  rb_cCvNAryMatIterator = define_class_under<cv::NAryMatIterator>(rb_mCv, "NAryMatIterator").
    define_constructor(Constructor<cv::NAryMatIterator>()).
    define_constructor(Constructor<cv::NAryMatIterator, const cv::Mat**, uchar**, int>(),
      Arg("arrays"), Arg("ptrs"), Arg("narrays") = static_cast<int>(-1)).
    define_constructor(Constructor<cv::NAryMatIterator, const cv::Mat**, cv::Mat*, int>(),
      Arg("arrays"), Arg("planes"), Arg("narrays") = static_cast<int>(-1)).
    define_method("init", &cv::NAryMatIterator::init,
      Arg("arrays"), Arg("planes"), Arg("ptrs"), Arg("narrays") = static_cast<int>(-1)).
    define_method<cv::NAryMatIterator&(cv::NAryMatIterator::*)()>("increment", &cv::NAryMatIterator::operator++).
    define_method<cv::NAryMatIterator(cv::NAryMatIterator::*)(int)>("increment", &cv::NAryMatIterator::operator++,
      Arg("")).
    define_attr("arrays", &cv::NAryMatIterator::arrays).
    define_attr("planes", &cv::NAryMatIterator::planes).
    define_attr("ptrs", &cv::NAryMatIterator::ptrs).
    define_attr("narrays", &cv::NAryMatIterator::narrays).
    define_attr("nplanes", &cv::NAryMatIterator::nplanes).
    define_attr("size", &cv::NAryMatIterator::size);
  
  rb_cCvMatOp = define_class_under<cv::MatOp>(rb_mCv, "MatOp").
    define_method("element_wise?", &cv::MatOp::elementWise,
      Arg("expr")).
    define_method("assign", &cv::MatOp::assign,
      Arg("expr"), Arg("m"), Arg("type") = static_cast<int>(-1)).
    define_method("roi", &cv::MatOp::roi,
      Arg("expr"), Arg("row_range"), Arg("col_range"), Arg("res")).
    define_method("diag", &cv::MatOp::diag,
      Arg("expr"), Arg("d"), Arg("res")).
    define_method("aug_assign_add", &cv::MatOp::augAssignAdd,
      Arg("expr"), Arg("m")).
    define_method("aug_assign_subtract", &cv::MatOp::augAssignSubtract,
      Arg("expr"), Arg("m")).
    define_method("aug_assign_multiply", &cv::MatOp::augAssignMultiply,
      Arg("expr"), Arg("m")).
    define_method("aug_assign_divide", &cv::MatOp::augAssignDivide,
      Arg("expr"), Arg("m")).
    define_method("aug_assign_and", &cv::MatOp::augAssignAnd,
      Arg("expr"), Arg("m")).
    define_method("aug_assign_or", &cv::MatOp::augAssignOr,
      Arg("expr"), Arg("m")).
    define_method("aug_assign_xor", &cv::MatOp::augAssignXor,
      Arg("expr"), Arg("m")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, const cv::MatExpr&, cv::MatExpr&) const>("add", &cv::MatOp::add,
      Arg("expr1"), Arg("expr2"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, const cv::Scalar&, cv::MatExpr&) const>("add", &cv::MatOp::add,
      Arg("expr1"), Arg("s"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, const cv::MatExpr&, cv::MatExpr&) const>("subtract", &cv::MatOp::subtract,
      Arg("expr1"), Arg("expr2"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::Scalar&, const cv::MatExpr&, cv::MatExpr&) const>("subtract", &cv::MatOp::subtract,
      Arg("s"), Arg("expr"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, const cv::MatExpr&, cv::MatExpr&, double) const>("multiply", &cv::MatOp::multiply,
      Arg("expr1"), Arg("expr2"), Arg("res"), Arg("scale") = static_cast<double>(1)).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, double, cv::MatExpr&) const>("multiply", &cv::MatOp::multiply,
      Arg("expr1"), Arg("s"), Arg("res")).
    define_method<void(cv::MatOp::*)(const cv::MatExpr&, const cv::MatExpr&, cv::MatExpr&, double) const>("divide", &cv::MatOp::divide,
      Arg("expr1"), Arg("expr2"), Arg("res"), Arg("scale") = static_cast<double>(1)).
    define_method<void(cv::MatOp::*)(double, const cv::MatExpr&, cv::MatExpr&) const>("divide", &cv::MatOp::divide,
      Arg("s"), Arg("expr"), Arg("res")).
    define_method("abs", &cv::MatOp::abs,
      Arg("expr"), Arg("res")).
    define_method("transpose", &cv::MatOp::transpose,
      Arg("expr"), Arg("res")).
    define_method("matmul", &cv::MatOp::matmul,
      Arg("expr1"), Arg("expr2"), Arg("res")).
    define_method("invert", &cv::MatOp::invert,
      Arg("expr"), Arg("method"), Arg("res")).
    define_method("size", &cv::MatOp::size,
      Arg("expr")).
    define_method("type", &cv::MatOp::type,
      Arg("expr"));
  
  rb_cCvMatExpr = define_class_under<cv::MatExpr>(rb_mCv, "MatExpr").
    define_constructor(Constructor<cv::MatExpr>()).
    define_constructor(Constructor<cv::MatExpr, const cv::Mat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::MatExpr, const cv::MatOp*, int, const cv::Mat&, const cv::Mat&, const cv::Mat&, double, double, const cv::Scalar&>(),
      Arg("_op"), Arg("_flags"), Arg("_a") = static_cast<const cv::Mat &>(cv::Mat()), Arg("_b") = static_cast<const cv::Mat &>(cv::Mat()), Arg("_c") = static_cast<const cv::Mat &>(cv::Mat()), Arg("_alpha") = static_cast<double>(1), Arg("_beta") = static_cast<double>(1), Arg("_s") = static_cast<const cv::Scalar &>(cv::Scalar())).
    define_method("to_mat", [](const cv::MatExpr& self) -> cv::Mat
    {
      return self;
    }).
    define_method("size", &cv::MatExpr::size).
    define_method("type", &cv::MatExpr::type).
    define_method("row", &cv::MatExpr::row,
      Arg("y")).
    define_method("col", &cv::MatExpr::col,
      Arg("x")).
    define_method("diag", &cv::MatExpr::diag,
      Arg("d") = static_cast<int>(0)).
    define_method<cv::MatExpr(cv::MatExpr::*)(const cv::Range&, const cv::Range&) const>("[]", &cv::MatExpr::operator(),
      Arg("row_range"), Arg("col_range")).
    define_method<cv::MatExpr(cv::MatExpr::*)(const cv::Rect&) const>("[]", &cv::MatExpr::operator(),
      Arg("roi")).
    define_method("t", &cv::MatExpr::t).
    define_method("inv", &cv::MatExpr::inv,
      Arg("method") = static_cast<int>(cv::DecompTypes::DECOMP_LU)).
    define_method<cv::MatExpr(cv::MatExpr::*)(const cv::MatExpr&, double) const>("mul", &cv::MatExpr::mul,
      Arg("e"), Arg("scale") = static_cast<double>(1)).
    define_method<cv::MatExpr(cv::MatExpr::*)(const cv::Mat&, double) const>("mul", &cv::MatExpr::mul,
      Arg("m"), Arg("scale") = static_cast<double>(1)).
    define_method("cross", &cv::MatExpr::cross,
      Arg("m")).
    define_method("dot", &cv::MatExpr::dot,
      Arg("m")).
    define_method("swap", &cv::MatExpr::swap,
      Arg("b")).
    define_attr("op", &cv::MatExpr::op).
    define_attr("flags", &cv::MatExpr::flags).
    define_attr("a", &cv::MatExpr::a).
    define_attr("b", &cv::MatExpr::b).
    define_attr("c", &cv::MatExpr::c).
    define_attr("alpha", &cv::MatExpr::alpha).
    define_attr("beta", &cv::MatExpr::beta).
    define_attr("s", &cv::MatExpr::s);
  
  rb_cCvMat.define_method("+", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self + other;
  });
  
  rb_cCvMat.define_method("+", [](const cv::Mat& self, const cv::Scalar& other) -> cv::MatExpr
  {
    return self + other;
  });
  
  rb_cScalar.define_method("+", [](const cv::Scalar& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self + other;
  });
  
  rb_cCvMatExpr.define_method("+", [](const cv::MatExpr& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self + other;
  });
  
  rb_cCvMat.define_method("+", [](const cv::Mat& self, const cv::MatExpr& other) -> cv::MatExpr
  {
    return self + other;
  });
  
  rb_cCvMatExpr.define_method("+", [](const cv::MatExpr& self, const cv::Scalar& other) -> cv::MatExpr
  {
    return self + other;
  });
  
  rb_cScalar.define_method("+", [](const cv::Scalar& self, const cv::MatExpr& other) -> cv::MatExpr
  {
    return self + other;
  });
  
  rb_cCvMatExpr.define_method("+", [](const cv::MatExpr& self, const cv::MatExpr& other) -> cv::MatExpr
  {
    return self + other;
  });
  
  rb_cCvMat.define_method("-", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self - other;
  });
  
  rb_cCvMat.define_method("-", [](const cv::Mat& self, const cv::Scalar& other) -> cv::MatExpr
  {
    return self - other;
  });
  
  rb_cScalar.define_method("-", [](const cv::Scalar& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self - other;
  });
  
  rb_cCvMatExpr.define_method("-", [](const cv::MatExpr& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self - other;
  });
  
  rb_cCvMat.define_method("-", [](const cv::Mat& self, const cv::MatExpr& other) -> cv::MatExpr
  {
    return self - other;
  });
  
  rb_cCvMatExpr.define_method("-", [](const cv::MatExpr& self, const cv::Scalar& other) -> cv::MatExpr
  {
    return self - other;
  });
  
  rb_cScalar.define_method("-", [](const cv::Scalar& self, const cv::MatExpr& other) -> cv::MatExpr
  {
    return self - other;
  });
  
  rb_cCvMatExpr.define_method("-", [](const cv::MatExpr& self, const cv::MatExpr& other) -> cv::MatExpr
  {
    return self - other;
  });
  
  rb_cCvMat.define_method("*", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self * other;
  });
  
  rb_cCvMat.define_method("*", [](const cv::Mat& self, double other) -> cv::MatExpr
  {
    return self * other;
  });
  
  rb_cCvMatExpr.define_method("*", [](const cv::MatExpr& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self * other;
  });
  
  rb_cCvMat.define_method("*", [](const cv::Mat& self, const cv::MatExpr& other) -> cv::MatExpr
  {
    return self * other;
  });
  
  rb_cCvMatExpr.define_method("*", [](const cv::MatExpr& self, double other) -> cv::MatExpr
  {
    return self * other;
  });
  
  rb_cCvMatExpr.define_method("*", [](const cv::MatExpr& self, const cv::MatExpr& other) -> cv::MatExpr
  {
    return self * other;
  });
  
  rb_cCvMat.define_method("/", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self / other;
  });
  
  rb_cCvMat.define_method("/", [](const cv::Mat& self, double other) -> cv::MatExpr
  {
    return self / other;
  });
  
  rb_cCvMatExpr.define_method("/", [](const cv::MatExpr& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self / other;
  });
  
  rb_cCvMat.define_method("/", [](const cv::Mat& self, const cv::MatExpr& other) -> cv::MatExpr
  {
    return self / other;
  });
  
  rb_cCvMatExpr.define_method("/", [](const cv::MatExpr& self, double other) -> cv::MatExpr
  {
    return self / other;
  });
  
  rb_cCvMatExpr.define_method("/", [](const cv::MatExpr& self, const cv::MatExpr& other) -> cv::MatExpr
  {
    return self / other;
  });
  
  rb_cCvMat.define_method("<", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self < other;
  });
  
  rb_cCvMat.define_method("<", [](const cv::Mat& self, double other) -> cv::MatExpr
  {
    return self < other;
  });
  
  rb_cCvMat.define_method("<=", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self <= other;
  });
  
  rb_cCvMat.define_method("<=", [](const cv::Mat& self, double other) -> cv::MatExpr
  {
    return self <= other;
  });
  
  rb_cCvMat.define_method("==", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self == other;
  });
  
  rb_cCvMat.define_method("==", [](const cv::Mat& self, double other) -> cv::MatExpr
  {
    return self == other;
  });
  
  rb_cCvMat.define_method("!=", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self != other;
  });
  
  rb_cCvMat.define_method("!=", [](const cv::Mat& self, double other) -> cv::MatExpr
  {
    return self != other;
  });
  
  rb_cCvMat.define_method(">=", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self >= other;
  });
  
  rb_cCvMat.define_method(">=", [](const cv::Mat& self, double other) -> cv::MatExpr
  {
    return self >= other;
  });
  
  rb_cCvMat.define_method(">", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self > other;
  });
  
  rb_cCvMat.define_method(">", [](const cv::Mat& self, double other) -> cv::MatExpr
  {
    return self > other;
  });
  
  rb_cCvMat.define_method("&", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self & other;
  });
  
  rb_cCvMat.define_method("&", [](const cv::Mat& self, const cv::Scalar& other) -> cv::MatExpr
  {
    return self & other;
  });
  
  rb_cScalar.define_method("&", [](const cv::Scalar& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self & other;
  });
  
  rb_cCvMat.define_method("|", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self | other;
  });
  
  rb_cCvMat.define_method("|", [](const cv::Mat& self, const cv::Scalar& other) -> cv::MatExpr
  {
    return self | other;
  });
  
  rb_cScalar.define_method("|", [](const cv::Scalar& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self | other;
  });
  
  rb_cCvMat.define_method("^", [](const cv::Mat& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self ^ other;
  });
  
  rb_cCvMat.define_method("^", [](const cv::Mat& self, const cv::Scalar& other) -> cv::MatExpr
  {
    return self ^ other;
  });
  
  rb_cScalar.define_method("^", [](const cv::Scalar& self, const cv::Mat& other) -> cv::MatExpr
  {
    return self ^ other;
  });
  
  rb_cScalar.define_method("~", [](const cv::Mat& self) -> cv::MatExpr
  {
    return ~self;
  });

  rb_mCv.define_module_function<cv::MatExpr(*)(const cv::Mat&, const cv::Mat&)>("min", &cv::min,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::MatExpr(*)(const cv::Mat&, double)>("min", &cv::min,
    Arg("a"), Arg("s"));
  
  rb_mCv.define_module_function<cv::MatExpr(*)(double, const cv::Mat&)>("min", &cv::min,
    Arg("s"), Arg("a"));
  
  rb_mCv.define_module_function<cv::MatExpr(*)(const cv::Mat&, const cv::Mat&)>("max", &cv::max,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::MatExpr(*)(const cv::Mat&, double)>("max", &cv::max,
    Arg("a"), Arg("s"));
  
  rb_mCv.define_module_function<cv::MatExpr(*)(double, const cv::Mat&)>("max", &cv::max,
    Arg("s"), Arg("a"));
  
  rb_mCv.define_module_function<cv::MatExpr(*)(const cv::Mat&)>("abs", &cv::abs,
    Arg("m"));
  
  rb_mCv.define_module_function<cv::MatExpr(*)(const cv::MatExpr&)>("abs", &cv::abs,
    Arg("e"));

  // Define a bunch of constructors for input array needed for countours and general
  // usefullness
  rb_cCvInputArray.
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

  rb_cCvOutputArray.
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
}
