#include <opencv2/surface_matching/pose_3d.hpp>
#include "pose_3d-rb.hpp"

using namespace Rice;

#include "cvstd_wrapper-rb.ipp"
#include "cvstd_wrapper-rb.ipp"

void Init_SurfaceMatching_Pose3d()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvPpfMatch3d = define_module_under(rb_mCv, "PpfMatch3d");

  Rice::Data_Type<cv::__shared_ptr_access<cv::ppf_match_3d::Pose3D, _Lp>> rb_cSharedPtrAccessPose3DLp = __shared_ptr_access_instantiate<cv::ppf_match_3d::Pose3D, _Lp>(rb_mCvPpfMatch3d, "SharedPtrAccessPose3DLp");
  Rice::Data_Type<cv::__shared_ptr<cv::ppf_match_3d::Pose3D>> rb_cSharedPtrPose3D = __shared_ptr_instantiate<cv::ppf_match_3d::Pose3D>(rb_mCvPpfMatch3d, "SharedPtrPose3D");
  Rice::Data_Type<cv::shared_ptr<cv::ppf_match_3d::Pose3D>> rb_cSharedPtrPose3D = shared_ptr_instantiate<cv::ppf_match_3d::Pose3D>(rb_mCvPpfMatch3d, "SharedPtrPose3D");
  Rice::Data_Type<cv::Ptr<cv::ppf_match_3d::Pose3D>> rb_cPose3DPtr = Ptr_instantiate<cv::ppf_match_3d::Pose3D>(rb_mCvPpfMatch3d, "Pose3DPtr");

  Rice::Data_Type<cv::__shared_ptr_access<cv::ppf_match_3d::PoseCluster3D, _Lp>> rb_cSharedPtrAccessPoseCluster3DLp = __shared_ptr_access_instantiate<cv::ppf_match_3d::PoseCluster3D, _Lp>(rb_mCvPpfMatch3d, "SharedPtrAccessPoseCluster3DLp");
  Rice::Data_Type<cv::__shared_ptr<cv::ppf_match_3d::PoseCluster3D>> rb_cSharedPtrPoseCluster3D = __shared_ptr_instantiate<cv::ppf_match_3d::PoseCluster3D>(rb_mCvPpfMatch3d, "SharedPtrPoseCluster3D");
  Rice::Data_Type<cv::shared_ptr<cv::ppf_match_3d::PoseCluster3D>> rb_cSharedPtrPoseCluster3D = shared_ptr_instantiate<cv::ppf_match_3d::PoseCluster3D>(rb_mCvPpfMatch3d, "SharedPtrPoseCluster3D");
  Rice::Data_Type<cv::Ptr<cv::ppf_match_3d::PoseCluster3D>> rb_cPoseCluster3DPtr = Ptr_instantiate<cv::ppf_match_3d::PoseCluster3D>(rb_mCvPpfMatch3d, "PoseCluster3DPtr");

  Rice::Data_Type<cv::ppf_match_3d::Pose3D> rb_cCvPpfMatch3dPose3D = define_class_under<cv::ppf_match_3d::Pose3D>(rb_mCvPpfMatch3d, "Pose3D").
    define_constructor(Constructor<cv::ppf_match_3d::Pose3D>()).
    define_constructor(Constructor<cv::ppf_match_3d::Pose3D, double, size_t, size_t>(),
      Arg("alpha"), Arg("model_index") = static_cast<size_t>(0), Arg("num_votes") = static_cast<size_t>(0)).
    define_method<void(cv::ppf_match_3d::Pose3D::*)(cv::Matx44d&)>("update_pose", &cv::ppf_match_3d::Pose3D::updatePose,
      Arg("new_pose")).
    define_method<void(cv::ppf_match_3d::Pose3D::*)(cv::Matx33d&, cv::Vec3d&)>("update_pose", &cv::ppf_match_3d::Pose3D::updatePose,
      Arg("new_r"), Arg("new_t")).
    define_method<void(cv::ppf_match_3d::Pose3D::*)(cv::Vec4d&, cv::Vec3d&)>("update_pose_quat", &cv::ppf_match_3d::Pose3D::updatePoseQuat,
      Arg("q"), Arg("new_t")).
    define_method<void(cv::ppf_match_3d::Pose3D::*)(cv::Matx44d&)>("append_pose", &cv::ppf_match_3d::Pose3D::appendPose,
      Arg("incremental_pose")).
    define_method<void(cv::ppf_match_3d::Pose3D::*)()>("print_pose", &cv::ppf_match_3d::Pose3D::printPose).
    define_method<cv::ppf_match_3d::Pose3DPtr(cv::ppf_match_3d::Pose3D::*)()>("clone", &cv::ppf_match_3d::Pose3D::clone).
    define_method<int(cv::ppf_match_3d::Pose3D::*)(FILE*)>("write_pose", &cv::ppf_match_3d::Pose3D::writePose,
      Arg("f")).
    define_method<int(cv::ppf_match_3d::Pose3D::*)(FILE*)>("read_pose", &cv::ppf_match_3d::Pose3D::readPose,
      Arg("f")).
    define_method<int(cv::ppf_match_3d::Pose3D::*)(const std::string&)>("write_pose", &cv::ppf_match_3d::Pose3D::writePose,
      Arg("file_name")).
    define_method<int(cv::ppf_match_3d::Pose3D::*)(const std::string&)>("read_pose", &cv::ppf_match_3d::Pose3D::readPose,
      Arg("file_name")).
    define_attr("alpha", &cv::ppf_match_3d::Pose3D::alpha).
    define_attr("residual", &cv::ppf_match_3d::Pose3D::residual).
    define_attr("model_index", &cv::ppf_match_3d::Pose3D::modelIndex).
    define_attr("num_votes", &cv::ppf_match_3d::Pose3D::numVotes).
    define_attr("pose", &cv::ppf_match_3d::Pose3D::pose).
    define_attr("angle", &cv::ppf_match_3d::Pose3D::angle).
    define_attr("t", &cv::ppf_match_3d::Pose3D::t).
    define_attr("q", &cv::ppf_match_3d::Pose3D::q);

  Rice::Data_Type<cv::ppf_match_3d::PoseCluster3D> rb_cCvPpfMatch3dPoseCluster3D = define_class_under<cv::ppf_match_3d::PoseCluster3D>(rb_mCvPpfMatch3d, "PoseCluster3D").
    define_constructor(Constructor<cv::ppf_match_3d::PoseCluster3D>()).
    define_constructor(Constructor<cv::ppf_match_3d::PoseCluster3D, cv::ppf_match_3d::Pose3DPtr>(),
      Arg("new_pose")).
    define_constructor(Constructor<cv::ppf_match_3d::PoseCluster3D, cv::ppf_match_3d::Pose3DPtr, int>(),
      Arg("new_pose"), Arg("new_id")).
    define_method<void(cv::ppf_match_3d::PoseCluster3D::*)(cv::ppf_match_3d::Pose3DPtr)>("add_pose", &cv::ppf_match_3d::PoseCluster3D::addPose,
      Arg("new_pose")).
    define_method<int(cv::ppf_match_3d::PoseCluster3D::*)(FILE*)>("write_pose_cluster", &cv::ppf_match_3d::PoseCluster3D::writePoseCluster,
      Arg("f")).
    define_method<int(cv::ppf_match_3d::PoseCluster3D::*)(FILE*)>("read_pose_cluster", &cv::ppf_match_3d::PoseCluster3D::readPoseCluster,
      Arg("f")).
    define_method<int(cv::ppf_match_3d::PoseCluster3D::*)(const std::string&)>("write_pose_cluster", &cv::ppf_match_3d::PoseCluster3D::writePoseCluster,
      Arg("file_name")).
    define_method<int(cv::ppf_match_3d::PoseCluster3D::*)(const std::string&)>("read_pose_cluster", &cv::ppf_match_3d::PoseCluster3D::readPoseCluster,
      Arg("file_name")).
    define_attr("pose_list", &cv::ppf_match_3d::PoseCluster3D::poseList).
    define_attr("num_votes", &cv::ppf_match_3d::PoseCluster3D::numVotes).
    define_attr("id", &cv::ppf_match_3d::PoseCluster3D::id);
}
