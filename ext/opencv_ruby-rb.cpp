#include "opencv_ruby_version.hpp"
#include "opencv_ruby-rb.hpp"

// Core Detail
#include "opencv2/core/detail/async_promise-rb.hpp"
#include "opencv2/core/detail/dispatch_helper.impl-rb.hpp"
#include "opencv2/core/detail/exception_ptr-rb.hpp"

// Core Hal
#include "opencv2/core/hal/interface-rb.hpp"

// Core
#include "opencv2/core/affine-rb.hpp"
#include "opencv2/core/async-rb.hpp"
#include "opencv2/core/base-rb.hpp"
#include "opencv2/core/bindings_utils-rb.hpp"
#include "opencv2/core/bufferpool-rb.hpp"
#include "opencv2/core/check-rb.hpp"
#include "opencv2/core/cuda-rb.hpp"
#include "opencv2/core/cuda_stream_accessor-rb.hpp"
#include "opencv2/core/cuda_types-rb.hpp"
#include "opencv2/core/cvdef-rb.hpp"
#include "opencv2/core/cvstd-rb.hpp"
#include "opencv2/core/cvstd_wrapper-rb.hpp"
#include "opencv2/core/directx-rb.hpp"
#include "opencv2/core/dualquaternion-rb.hpp"
#include "opencv2/core/eigen-rb.hpp"
#include "opencv2/core/fast_math-rb.hpp"
#include "opencv2/core/mat-rb.hpp"
#include "opencv2/core/matx-rb.hpp"
#include "opencv2/core/neon_utils-rb.hpp"
#include "opencv2/core/ocl-rb.hpp"
#include "opencv2/core/ocl_genbase-rb.hpp"
#include "opencv2/core/opengl-rb.hpp"
#include "opencv2/core/operations-rb.hpp"
#include "opencv2/core/optim-rb.hpp"
#include "opencv2/core/ovx-rb.hpp"
#include "opencv2/core/persistence-rb.hpp"
#include "opencv2/core/quaternion-rb.hpp"
#include "opencv2/core/saturate-rb.hpp"
#include "opencv2/core/simd_intrinsics-rb.hpp"
#include "opencv2/core/softfloat-rb.hpp"
#include "opencv2/core/sse_utils-rb.hpp"
#include "opencv2/core/traits-rb.hpp"
#include "opencv2/core/types-rb.hpp"
#include "opencv2/core/utility-rb.hpp"
#include "opencv2/core/va_intel-rb.hpp"
#include "opencv2/core/version-rb.hpp"
#include "opencv2/core/vsx_utils-rb.hpp"

// DNN
#include "opencv2/dnn/all_layers-rb.hpp"
#include "opencv2/dnn/dict-rb.hpp"
#include "opencv2/dnn/dnn-rb.hpp"
#include "opencv2/dnn/layer-rb.hpp"
#include "opencv2/dnn/layer.details-rb.hpp"
#include "opencv2/dnn/shape_utils-rb.hpp"
#include "opencv2/dnn/version-rb.hpp"

// Flann
#include "opencv2/flann/allocator-rb.hpp"
#include "opencv2/flann/all_indices-rb.hpp"
#include "opencv2/flann/any-rb.hpp"
#include "opencv2/flann/autotuned_index-rb.hpp"
#include "opencv2/flann/composite_index-rb.hpp"
#include "opencv2/flann/config-rb.hpp"
#include "opencv2/flann/defines-rb.hpp"
#include "opencv2/flann/dist-rb.hpp"
#include "opencv2/flann/dynamic_bitset-rb.hpp"
#include "opencv2/flann/flann_base-rb.hpp"
#include "opencv2/flann/general-rb.hpp"
#include "opencv2/flann/ground_truth-rb.hpp"
#include "opencv2/flann/hdf5-rb.hpp"
#include "opencv2/flann/heap-rb.hpp"
#include "opencv2/flann/hierarchical_clustering_index-rb.hpp"
#include "opencv2/flann/index_testing-rb.hpp"
#include "opencv2/flann/kdtree_index-rb.hpp"
#include "opencv2/flann/kdtree_single_index-rb.hpp"
#include "opencv2/flann/kmeans_index-rb.hpp"
#include "opencv2/flann/linear_index-rb.hpp"
#include "opencv2/flann/logger-rb.hpp"
#include "opencv2/flann/lsh_index-rb.hpp"
#include "opencv2/flann/matrix-rb.hpp"
#include "opencv2/flann/miniflann-rb.hpp"
#include "opencv2/flann/nn_index-rb.hpp"
#include "opencv2/flann/object_factory-rb.hpp"
#include "opencv2/flann/params-rb.hpp"
#include "opencv2/flann/random-rb.hpp"
#include "opencv2/flann/result_set-rb.hpp"
#include "opencv2/flann/sampling-rb.hpp"
#include "opencv2/flann/saving-rb.hpp"
#include "opencv2/flann/simplex_downhill-rb.hpp"
#include "opencv2/flann/timer-rb.hpp"

// Object Detection
#include "opencv2/objdetect/aruco_board-rb.hpp"
#include "opencv2/objdetect/aruco_detector-rb.hpp"
#include "opencv2/objdetect/aruco_dictionary-rb.hpp"
#include "opencv2/objdetect/barcode-rb.hpp"
#include "opencv2/objdetect/charuco_detector-rb.hpp"
#include "opencv2/objdetect/detection_based_tracker-rb.hpp"
#include "opencv2/objdetect/face-rb.hpp"
#include "opencv2/objdetect/graphical_code_detector-rb.hpp"

// Stitching
#include "opencv2/stitching/detail/autocalib-rb.hpp"
#include "opencv2/stitching/detail/blenders-rb.hpp"
#include "opencv2/stitching/detail/camera-rb.hpp"
#include "opencv2/stitching/detail/exposure_compensate-rb.hpp"
#include "opencv2/stitching/detail/matchers-rb.hpp"
#include "opencv2/stitching/detail/motion_estimators-rb.hpp"
#include "opencv2/stitching/detail/seam_finders-rb.hpp"
#include "opencv2/stitching/detail/timelapsers-rb.hpp"
#include "opencv2/stitching/detail/util-rb.hpp"
#include "opencv2/stitching/detail/warpers-rb.hpp"
#include "opencv2/stitching/warpers-rb.hpp"

// Video
#include "opencv2/video/detail/tracking.detail-rb.hpp"
#include "opencv2/video/background_segm-rb.hpp"
#include "opencv2/video/tracking-rb.hpp"
#include "opencv2/video/video-rb.hpp"

// Top Level
#include "opencv2/calib3d-rb.hpp"
#include "opencv2/core-rb.hpp"
#include "opencv2/features2d-rb.hpp"
#include "opencv2/flann-rb.hpp"
#include "opencv2/highgui-rb.hpp"
#include "opencv2/imgcodecs-rb.hpp"
#include "opencv2/imgproc-rb.hpp"
#include "opencv2/ml-rb.hpp"
#include "opencv2/objdetect-rb.hpp"
#include "opencv2/opencv_modules-rb.hpp"
#include "opencv2/photo-rb.hpp"
#include "opencv2/stitching-rb.hpp"
#include "opencv2/videoio-rb.hpp"

extern "C"
void Init_opencv_ruby()
{
  return Rice::detail::cpp_protect([]
  {
    // HAL
    Init_Interface();

    // Core
    Init_Core();

    // Core Detail
    //Init_AsyncPromise();
    Init_DispatchHelperImpl();
    Init_ExceptionPtr();

    // Core
    Init_Affine();
    Init_Async();
    Init_Base();
    Init_BindingsUtils();
    Init_Bufferpool();
    Init_Check();
    Init_Cuda();
    //Init_CudaStreamAccessor();
    //Init_CudaTypes();
    Init_Cvdef();
    Init_Cvstd();
    Init_CvstdWrapper();
    //Init_Directx();
    Init_Dualquaternion();
    //Init_Eigen();
    Init_FastMath();
    Init_Matx();
    Init_Types(); // Types needs to come before mat since it nees to initialize Range and Scalar externs
    Init_Mat();
    Init_NeonUtils();
    Init_Ocl();
    Init_OclGenbase();
    Init_Opengl();
    Init_Operations();
    Init_Optim();
    Init_Ovx();
    Init_Persistence();
    Init_Quaternion();
    Init_Saturate();
    Init_SimdIntrinsics();
    Init_Softfloat();
    Init_Utility();
    Init_VaIntel();
    Init_Version();
    Init_VsxUtils();

    // DNN
    Init_DnnVersion();
    Init_Dict();
    Init_Dnn();
    Init_Layer();
    Init_LayerDetails();
    Init_AllLayers();
    Init_ShapeUtils();

    // Flann
    Init_Allocator();
    Init_AllIndices();
    Init_Any();
    Init_AutotunedIndex();
    Init_CompositeIndex();
    Init_Config();
    Init_Defines();
    Init_Dist();
    Init_DynamicBitset();
    Init_FlannBase();
    Init_Flann_Logger();
    Init_General();
    Init_GroundTruth();
    // Init_Hdf5();
    Init_Heap();
    Init_HierarchicalClusteringIndex();
    Init_IndexTesting();
    Init_KdtreeIndex();
    Init_KdtreeSingleIndex();
    Init_KmeansIndex();
    Init_LinearIndex();
    Init_LshIndex();
    Init_Matrix();
    Init_Miniflann();
    Init_NnIndex();
    Init_ObjectFactory();
    Init_Params();
    Init_Random();
    Init_ResultSet();
    Init_Sampling();
    Init_Saving();
    Init_SimplexDownhill();
    Init_Timer();

#if RUBY_CV_VERSION >= 408
    // Object Detection
    Init_ArucoBoard();
    Init_ArucoDetector();
    Init_ArucoDictionary();
    Init_GraphicalCodeDetector();
    Init_Barcode();
    Init_CharucoDetector();
    Init_DetectionBasedTracker();
    Init_Face();
#endif

    // Stitching
    Init_Autocalib();
    Init_Blenders();
    Init_Camera();
    Init_ExposureCompensate();
    Init_Matchers();
    Init_MotionEstimators();
    Init_SeamFinders();
    Init_Timelapsers();
    Init_Util();
    Init_Detail_Warpers();
    Init_Warpers();

    // Video
    Init_TrackingDetail();
    Init_BackgroundSegm();
    Init_Tracking();
    Init_Video();

    // Top level
    Init_Calib3d();
    Init_Features2d();
    Init_Flann();
    Init_Highgui();
    Init_Imgcodecs();
    Init_Imgproc();
    Init_Ml();
    Init_Objdetect();
    Init_OpencvModules();
    Init_Photo();
    Init_Stitching();
    Init_Videoio();

    // Validate types
    Rice::detail::Registries::instance.types.validateTypes();

    // Setup Ruby API
    Init_Rice_Api();
  });
}