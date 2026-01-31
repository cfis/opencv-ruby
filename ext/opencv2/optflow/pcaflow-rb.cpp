#include <opencv2/optflow/pcaflow.hpp>
#include "pcaflow-rb.hpp"

using namespace Rice;

void Init_Optflow_Pcaflow()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvOptflow = define_module_under(rb_mCv, "Optflow");

  Rice::Data_Type<cv::optflow::PCAPrior> rb_cCvOptflowPCAPrior = define_class_under<cv::optflow::PCAPrior>(rb_mCvOptflow, "PCAPrior").
    define_constructor(Constructor<cv::optflow::PCAPrior, const char*>(),
      Arg("path_to_prior")).
    define_method<int(cv::optflow::PCAPrior::*)() const>("get_padding", &cv::optflow::PCAPrior::getPadding).
    define_method<int(cv::optflow::PCAPrior::*)() const>("get_basis_size", &cv::optflow::PCAPrior::getBasisSize).
    define_method<void(cv::optflow::PCAPrior::*)(float*, float*, float*, float*) const>("fill_constraints", &cv::optflow::PCAPrior::fillConstraints,
      ArgBuffer("a1"), ArgBuffer("a2"), ArgBuffer("b1"), ArgBuffer("b2"));

  Rice::Data_Type<cv::optflow::OpticalFlowPCAFlow> rb_cCvOptflowOpticalFlowPCAFlow = define_class_under<cv::optflow::OpticalFlowPCAFlow, cv::DenseOpticalFlow>(rb_mCvOptflow, "OpticalFlowPCAFlow").
    define_constructor(Constructor<cv::optflow::OpticalFlowPCAFlow, cv::Ptr<const cv::optflow::PCAPrior>, const cv::Size, float, float, float, float, float>(),
      Arg("_prior") = static_cast<cv::Ptr<const cv::optflow::PCAPrior>>(cv::Ptr<const cv::optflow::PCAPrior>()), Arg("_basis_size") = static_cast<const cv::Size>(cv::Size( 18, 14 )), Arg("_sparse_rate") = static_cast<float>(0.024), Arg("_retained_corners_fraction") = static_cast<float>(0.2), Arg("_occlusions_threshold") = static_cast<float>(0.0003), Arg("_damping_factor") = static_cast<float>(0.00002), Arg("_clahe_clip") = static_cast<float>(14)).
    define_method<void(cv::optflow::OpticalFlowPCAFlow::*)(cv::InputArray, cv::InputArray, cv::InputOutputArray)>("calc", &cv::optflow::OpticalFlowPCAFlow::calc,
      Arg("i0"), Arg("i1"), Arg("flow")).
    define_method<void(cv::optflow::OpticalFlowPCAFlow::*)()>("collect_garbage", &cv::optflow::OpticalFlowPCAFlow::collectGarbage);

  rb_mCvOptflow.define_module_function<cv::Ptr<cv::DenseOpticalFlow>(*)()>("create_opt_flow_pca_flow", &cv::optflow::createOptFlow_PCAFlow);
}