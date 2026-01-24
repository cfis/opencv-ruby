#include <opencv2/dnn_superres.hpp>
#include "dnn_superres-rb.hpp"

using namespace Rice;

void Init_DnnSuperres()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnnSuperres = define_module_under(rb_mCv, "DnnSuperres");

  Rice::Data_Type<cv::dnn_superres::DnnSuperResImpl> rb_cCvDnnSuperresDnnSuperResImpl = define_class_under<cv::dnn_superres::DnnSuperResImpl>(rb_mCvDnnSuperres, "DnnSuperResImpl").
    define_constructor(Constructor<cv::dnn_superres::DnnSuperResImpl>()).
    define_constructor(Constructor<cv::dnn_superres::DnnSuperResImpl, const cv::String&, int>(),
      Arg("algo"), Arg("scale")).
    define_method<void(cv::dnn_superres::DnnSuperResImpl::*)(const cv::String&)>("read_model", &cv::dnn_superres::DnnSuperResImpl::readModel,
      Arg("path")).
    define_method<void(cv::dnn_superres::DnnSuperResImpl::*)(const cv::String&, const cv::String&)>("read_model", &cv::dnn_superres::DnnSuperResImpl::readModel,
      Arg("weights"), Arg("definition")).
    define_method("set_model", &cv::dnn_superres::DnnSuperResImpl::setModel,
      Arg("algo"), Arg("scale")).
    define_method("set_preferable_backend", &cv::dnn_superres::DnnSuperResImpl::setPreferableBackend,
      Arg("backend_id")).
    define_method("set_preferable_target", &cv::dnn_superres::DnnSuperResImpl::setPreferableTarget,
      Arg("target_id")).
    define_method("upsample", &cv::dnn_superres::DnnSuperResImpl::upsample,
      Arg("img"), Arg("result")).
    define_method("upsample_multioutput", &cv::dnn_superres::DnnSuperResImpl::upsampleMultioutput,
      Arg("img"), Arg("imgs_new"), Arg("scale_factors"), Arg("node_names")).
    define_method("get_scale", &cv::dnn_superres::DnnSuperResImpl::getScale).
    define_method("get_algorithm", &cv::dnn_superres::DnnSuperResImpl::getAlgorithm).
    define_singleton_function("create", &cv::dnn_superres::DnnSuperResImpl::create);
}