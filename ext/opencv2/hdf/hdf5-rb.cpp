#include <opencv2/hdf/hdf5.hpp>
#include "hdf5-rb.hpp"

using namespace Rice;

void Init_Hdf_Hdf5()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvHdf = define_module_under(rb_mCv, "Hdf");

  Rice::Data_Type<cv::hdf::HDF5> rb_cCvHdfHDF5 = define_class_under<cv::hdf::HDF5>(rb_mCvHdf, "HDF5").
    define_method<void(cv::hdf::HDF5::*)()>("close", &cv::hdf::HDF5::close).
    define_method<void(cv::hdf::HDF5::*)(const cv::String&)>("grcreate", &cv::hdf::HDF5::grcreate,
      Arg("grlabel")).
    define_method<bool(cv::hdf::HDF5::*)(const cv::String&) const>("hlexists", &cv::hdf::HDF5::hlexists,
      Arg("label")).
    define_method<bool(cv::hdf::HDF5::*)(const cv::String&) const>("atexists", &cv::hdf::HDF5::atexists,
      Arg("atlabel")).
    define_method<void(cv::hdf::HDF5::*)(const cv::String&)>("atdelete", &cv::hdf::HDF5::atdelete,
      Arg("atlabel")).
    define_method<void(cv::hdf::HDF5::*)(const int, const cv::String&)>("atwrite", &cv::hdf::HDF5::atwrite,
      Arg("value"), Arg("atlabel")).
    define_method<void(cv::hdf::HDF5::*)(int*, const cv::String&)>("atread", &cv::hdf::HDF5::atread,
      ArgBuffer("value"), Arg("atlabel")).
    define_method<void(cv::hdf::HDF5::*)(const double, const cv::String&)>("atwrite", &cv::hdf::HDF5::atwrite,
      Arg("value"), Arg("atlabel")).
    define_method<void(cv::hdf::HDF5::*)(double*, const cv::String&)>("atread", &cv::hdf::HDF5::atread,
      ArgBuffer("value"), Arg("atlabel")).
    define_method<void(cv::hdf::HDF5::*)(const cv::String&, const cv::String&)>("atwrite", &cv::hdf::HDF5::atwrite,
      Arg("value"), Arg("atlabel")).
    define_method<void(cv::hdf::HDF5::*)(cv::String*, const cv::String&)>("atread", &cv::hdf::HDF5::atread,
      Arg("value"), Arg("atlabel")).
    define_method<void(cv::hdf::HDF5::*)(cv::InputArray, const cv::String&)>("atwrite", &cv::hdf::HDF5::atwrite,
      Arg("value"), Arg("atlabel")).
    define_method<void(cv::hdf::HDF5::*)(cv::OutputArray, const cv::String&)>("atread", &cv::hdf::HDF5::atread,
      Arg("value"), Arg("atlabel")).
    define_method<void(cv::hdf::HDF5::*)(const int, const int, const int, const cv::String&) const>("dscreate", &cv::hdf::HDF5::dscreate,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("dslabel")).
    define_method<void(cv::hdf::HDF5::*)(const int, const int, const int, const cv::String&, const int) const>("dscreate", &cv::hdf::HDF5::dscreate,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("dslabel"), Arg("compresslevel")).
    define_method<void(cv::hdf::HDF5::*)(const int, const int, const int, const cv::String&, const int, const std::vector<int>&) const>("dscreate", &cv::hdf::HDF5::dscreate,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("dslabel"), Arg("compresslevel"), Arg("dims_chunks")).
    define_method<void(cv::hdf::HDF5::*)(const int, const int, const int, const cv::String&, const int, const int*) const>("dscreate", &cv::hdf::HDF5::dscreate,
      Arg("rows"), Arg("cols"), Arg("type"), Arg("dslabel"), Arg("compresslevel"), ArgBuffer("dims_chunks")).
    define_method<void(cv::hdf::HDF5::*)(const int, const int*, const int, const cv::String&) const>("dscreate", &cv::hdf::HDF5::dscreate,
      Arg("n_dims"), ArgBuffer("sizes"), Arg("type"), Arg("dslabel")).
    define_method<void(cv::hdf::HDF5::*)(const int, const int*, const int, const cv::String&, const int) const>("dscreate", &cv::hdf::HDF5::dscreate,
      Arg("n_dims"), ArgBuffer("sizes"), Arg("type"), Arg("dslabel"), Arg("compresslevel")).
    define_method<void(cv::hdf::HDF5::*)(const std::vector<int>&, const int, const cv::String&, const int, const std::vector<int>&) const>("dscreate", &cv::hdf::HDF5::dscreate,
      Arg("sizes"), Arg("type"), Arg("dslabel"), Arg("compresslevel") = static_cast<const int>(cv::hdf::HDF5::H5_NONE), Arg("dims_chunks") = static_cast<const std::vector<int>&>(std::vector<int>())).
    define_method<void(cv::hdf::HDF5::*)(const int, const int*, const int, const cv::String&, const int, const int*) const>("dscreate", &cv::hdf::HDF5::dscreate,
      Arg("n_dims"), ArgBuffer("sizes"), Arg("type"), Arg("dslabel"), Arg("compresslevel"), ArgBuffer("dims_chunks")).
    define_method<std::vector<int>(cv::hdf::HDF5::*)(const cv::String&, int) const>("dsgetsize", &cv::hdf::HDF5::dsgetsize,
      Arg("dslabel"), Arg("dims_flag") = static_cast<int>(cv::hdf::HDF5::H5_GETDIMS)).
    define_method<int(cv::hdf::HDF5::*)(const cv::String&) const>("dsgettype", &cv::hdf::HDF5::dsgettype,
      Arg("dslabel")).
    define_method<void(cv::hdf::HDF5::*)(cv::InputArray, const cv::String&) const>("dswrite", &cv::hdf::HDF5::dswrite,
      Arg("array"), Arg("dslabel")).
    define_method<void(cv::hdf::HDF5::*)(cv::InputArray, const cv::String&, const int*) const>("dswrite", &cv::hdf::HDF5::dswrite,
      Arg("array"), Arg("dslabel"), ArgBuffer("dims_offset")).
    define_method<void(cv::hdf::HDF5::*)(cv::InputArray, const cv::String&, const std::vector<int>&, const std::vector<int>&) const>("dswrite", &cv::hdf::HDF5::dswrite,
      Arg("array"), Arg("dslabel"), Arg("dims_offset"), Arg("dims_counts") = static_cast<const std::vector<int>&>(std::vector<int>())).
    define_method<void(cv::hdf::HDF5::*)(cv::InputArray, const cv::String&, const int*, const int*) const>("dswrite", &cv::hdf::HDF5::dswrite,
      Arg("array"), Arg("dslabel"), ArgBuffer("dims_offset"), ArgBuffer("dims_counts")).
    define_method<void(cv::hdf::HDF5::*)(cv::InputArray, const cv::String&) const>("dsinsert", &cv::hdf::HDF5::dsinsert,
      Arg("array"), Arg("dslabel")).
    define_method<void(cv::hdf::HDF5::*)(cv::InputArray, const cv::String&, const int*) const>("dsinsert", &cv::hdf::HDF5::dsinsert,
      Arg("array"), Arg("dslabel"), ArgBuffer("dims_offset")).
    define_method<void(cv::hdf::HDF5::*)(cv::InputArray, const cv::String&, const std::vector<int>&, const std::vector<int>&) const>("dsinsert", &cv::hdf::HDF5::dsinsert,
      Arg("array"), Arg("dslabel"), Arg("dims_offset"), Arg("dims_counts") = static_cast<const std::vector<int>&>(std::vector<int>())).
    define_method<void(cv::hdf::HDF5::*)(cv::InputArray, const cv::String&, const int*, const int*) const>("dsinsert", &cv::hdf::HDF5::dsinsert,
      Arg("array"), Arg("dslabel"), ArgBuffer("dims_offset"), ArgBuffer("dims_counts")).
    define_method<void(cv::hdf::HDF5::*)(cv::OutputArray, const cv::String&) const>("dsread", &cv::hdf::HDF5::dsread,
      Arg("array"), Arg("dslabel")).
    define_method<void(cv::hdf::HDF5::*)(cv::OutputArray, const cv::String&, const int*) const>("dsread", &cv::hdf::HDF5::dsread,
      Arg("array"), Arg("dslabel"), ArgBuffer("dims_offset")).
    define_method<void(cv::hdf::HDF5::*)(cv::OutputArray, const cv::String&, const std::vector<int>&, const std::vector<int>&) const>("dsread", &cv::hdf::HDF5::dsread,
      Arg("array"), Arg("dslabel"), Arg("dims_offset"), Arg("dims_counts") = static_cast<const std::vector<int>&>(std::vector<int>())).
    define_method<void(cv::hdf::HDF5::*)(cv::OutputArray, const cv::String&, const int*, const int*) const>("dsread", &cv::hdf::HDF5::dsread,
      Arg("array"), Arg("dslabel"), ArgBuffer("dims_offset"), ArgBuffer("dims_counts")).
    define_method<int(cv::hdf::HDF5::*)(const cv::String&, int) const>("kpgetsize", &cv::hdf::HDF5::kpgetsize,
      Arg("kplabel"), Arg("dims_flag") = static_cast<int>(cv::hdf::HDF5::H5_GETDIMS)).
    define_method<void(cv::hdf::HDF5::*)(const int, const cv::String&, const int, const int) const>("kpcreate", &cv::hdf::HDF5::kpcreate,
      Arg("size"), Arg("kplabel"), Arg("compresslevel") = static_cast<const int>(cv::hdf::HDF5::H5_NONE), Arg("chunks") = static_cast<const int>(cv::hdf::HDF5::H5_NONE)).
    define_method<void(cv::hdf::HDF5::*)(const std::vector<cv::KeyPoint>, const cv::String&, const int, const int) const>("kpwrite", &cv::hdf::HDF5::kpwrite,
      Arg("keypoints"), Arg("kplabel"), Arg("offset") = static_cast<const int>(cv::hdf::HDF5::H5_NONE), Arg("counts") = static_cast<const int>(cv::hdf::HDF5::H5_NONE)).
    define_method<void(cv::hdf::HDF5::*)(const std::vector<cv::KeyPoint>, const cv::String&, const int, const int) const>("kpinsert", &cv::hdf::HDF5::kpinsert,
      Arg("keypoints"), Arg("kplabel"), Arg("offset") = static_cast<const int>(cv::hdf::HDF5::H5_NONE), Arg("counts") = static_cast<const int>(cv::hdf::HDF5::H5_NONE)).
    define_method<void(cv::hdf::HDF5::*)(std::vector<cv::KeyPoint>&, const cv::String&, const int, const int) const>("kpread", &cv::hdf::HDF5::kpread,
      Arg("keypoints"), Arg("kplabel"), Arg("offset") = static_cast<const int>(cv::hdf::HDF5::H5_NONE), Arg("counts") = static_cast<const int>(cv::hdf::HDF5::H5_NONE));

  rb_cCvHdfHDF5.define_constant("H5_UNLIMITED", (int)cv::hdf::HDF5::H5_UNLIMITED);
  rb_cCvHdfHDF5.define_constant("H5_NONE", (int)cv::hdf::HDF5::H5_NONE);
  rb_cCvHdfHDF5.define_constant("H5_GETDIMS", (int)cv::hdf::HDF5::H5_GETDIMS);
  rb_cCvHdfHDF5.define_constant("H5_GETMAXDIMS", (int)cv::hdf::HDF5::H5_GETMAXDIMS);
  rb_cCvHdfHDF5.define_constant("H5_GETCHUNKDIMS", (int)cv::hdf::HDF5::H5_GETCHUNKDIMS);

  rb_mCvHdf.define_module_function<cv::Ptr<cv::hdf::HDF5>(*)(const cv::String&)>("open", &cv::hdf::open,
    Arg("hdf5_filename"));
}