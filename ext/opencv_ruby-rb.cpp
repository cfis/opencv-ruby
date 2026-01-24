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

#ifdef OpenCV_HAS_CUDA
#include "opencv2/core/cuda-rb.hpp"
#include "opencv2/core/cuda_stream_accessor-rb.hpp"
#include "opencv2/core/cuda_types-rb.hpp"
#endif

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

// Core Utils
#include "opencv2/core/utils/allocator_stats-rb.hpp"
#include "opencv2/core/utils/allocator_stats.impl-rb.hpp"
#include "opencv2/core/utils/filesystem-rb.hpp"
#include "opencv2/core/utils/logger-rb.hpp"
#include "opencv2/core/utils/logger.defines-rb.hpp"
#include "opencv2/core/utils/logtag-rb.hpp"
#include "opencv2/core/utils/trace-rb.hpp"

// DNN
#include "opencv2/dnn/all_layers-rb.hpp"
#include "opencv2/dnn/dict-rb.hpp"
#include "opencv2/dnn/dnn-rb.hpp"
#include "opencv2/dnn/layer-rb.hpp"
#include "opencv2/dnn/layer.details-rb.hpp"
#include "opencv2/dnn/shape_utils-rb.hpp"
#include "opencv2/dnn/version-rb.hpp"

// DNN Utils
#include "opencv2/dnn/utils/debug_utils-rb.hpp"
#include "opencv2/dnn/utils/inference_engine-rb.hpp"

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
#include "opencv2/stitching/detail/util_inl-rb.hpp"
#include "opencv2/stitching/detail/warpers-rb.hpp"
#include "opencv2/stitching/warpers-rb.hpp"

// Video
#include "opencv2/video/detail/tracking.detail-rb.hpp"
#include "opencv2/video/background_segm-rb.hpp"
#include "opencv2/video/tracking-rb.hpp"
#include "opencv2/video/video-rb.hpp"

// Top Level
#include "opencv2/aruco-rb.hpp"
#include "opencv2/bgsegm-rb.hpp"
#include "opencv2/bioinspired-rb.hpp"
#include "opencv2/calib3d-rb.hpp"
#include "opencv2/ccalib-rb.hpp"
#include "opencv2/core-rb.hpp"
#include "opencv2/core_detect-rb.hpp"
//#include "opencv2/cudaarithm-rb.hpp"
//#include "opencv2/cudabgsegm-rb.hpp"
//#include "opencv2/cudacodec-rb.hpp"
//#include "opencv2/cudafeatures2d-rb.hpp"
//#include "opencv2/cudafilters-rb.hpp"
//#include "opencv2/cudaimgproc-rb.hpp"
//#include "opencv2/cudalegacy-rb.hpp"
//#include "opencv2/cudaobjdetect-rb.hpp"
//#include "opencv2/cudaoptflow-rb.hpp"
//#include "opencv2/cudastereo-rb.hpp"
//#include "opencv2/cudawarping-rb.hpp"
//#include "opencv2/cudev-rb.hpp"
#include "opencv2/cvconfig-rb.hpp"
#include "opencv2/dnn-rb.hpp"
#include "opencv2/dnn_superres-rb.hpp"
#include "opencv2/dpm-rb.hpp"
#include "opencv2/face-rb.hpp"
#include "opencv2/features2d-rb.hpp"
#include "opencv2/flann-rb.hpp"
#include "opencv2/fuzzy-rb.hpp"
#include "opencv2/hdf-rb.hpp"
#include "opencv2/hfs-rb.hpp"
#include "opencv2/highgui-rb.hpp"
#include "opencv2/img_hash-rb.hpp"
#include "opencv2/imgcodecs-rb.hpp"
#include "opencv2/imgproc-rb.hpp"
#include "opencv2/intensity_transform-rb.hpp"
#include "opencv2/line_descriptor-rb.hpp"
#include "opencv2/mcc-rb.hpp"
#include "opencv2/ml-rb.hpp"
#include "opencv2/objdetect-rb.hpp"
#include "opencv2/opencv-rb.hpp"
#include "opencv2/opencv_modules-rb.hpp"
#include "opencv2/optflow-rb.hpp"
#include "opencv2/phase_unwrapping-rb.hpp"
#include "opencv2/photo-rb.hpp"
#include "opencv2/plot-rb.hpp"
#include "opencv2/rapid-rb.hpp"
#include "opencv2/saliency-rb.hpp"
#include "opencv2/shape-rb.hpp"
#include "opencv2/signal-rb.hpp"
#include "opencv2/stereo-rb.hpp"
#include "opencv2/stitching-rb.hpp"
#include "opencv2/structured_light-rb.hpp"
#include "opencv2/superres-rb.hpp"
#include "opencv2/surface_matching-rb.hpp"
#include "opencv2/text-rb.hpp"
#include "opencv2/tracking-rb.hpp"
#include "opencv2/video-rb.hpp"
#include "opencv2/videoio-rb.hpp"
#include "opencv2/videostab-rb.hpp"
#include "opencv2/wechat_qrcode-rb.hpp"
#include "opencv2/xfeatures2d-rb.hpp"
#include "opencv2/ximgproc-rb.hpp"
#include "opencv2/xobjdetect-rb.hpp"
#include "opencv2/xphoto-rb.hpp"

extern "C"
void Init_opencv_ruby()
{
  return Rice::detail::cpp_protect([]
  {
    // HAL
    //Init_Core_Hal_Interface();

    // Core
    Init_Core();

    // Core Detail
    //Init_AsyncPromise();
    //Init_Core_Detail_DispatchHelperImpl();
    //Init_Core_Detail_ExceptionPtr();

    // Core
    Init_Core_Affine();
    Init_Core_Async();
    Init_Core_Base();
    Init_Core_BindingsUtils();
    Init_Core_Bufferpool();
    Init_Core_Check();

#ifdef OpenCV_HAS_CUDA
    Init_Core_Cuda();
    Init_Core_CudaStreamAccessor();
    Init_Core_CudaTypes();
#endif 

    Init_Core_Cvdef();
    Init_Core_Cvstd();
    Init_Core_CvstdWrapper();
    //Init_Core_Directx();
    Init_Core_Dualquaternion();
    //Init_Core_Eigen();
    Init_Core_FastMath();
    Init_Core_Matx();
    Init_Core_Types(); // Types needs to come before mat since it nees to initialize Range and Scalar externs
    Init_Core_Mat();
    Init_Core_NeonUtils();
    Init_Core_Ocl();
    Init_Core_OclGenbase();
    Init_Core_Opengl();
    Init_Core_Operations();
    Init_Core_Optim();
    Init_Core_Ovx();
    Init_Core_Persistence();
    Init_Core_Quaternion();
    Init_Core_Saturate();
    Init_Core_SimdIntrinsics();
    Init_Core_Softfloat();
    Init_Core_Utility();
    Init_Core_VaIntel();
    Init_Core_Version();
    Init_Core_VsxUtils();

    // Core Utils
    /*Init_Core_Utils_AllocatorStats();
    Init_Core_Utils_AllocatorStatsImpl();
    Init_Core_Utils_Filesystem();
    Init_Core_Utils_Logger();
    Init_Core_Utils_LoggerDefines();
    Init_Core_Utils_Logtag();
    Init_Core_Utils_Trace();*/

    // DNN
    Init_Dnn_Version();
    Init_Dnn_Dict();
    Init_Dnn_Dnn();
    Init_Dnn_Layer();
    Init_Dnn_LayerDetails();
    Init_Dnn_AllLayers();
    Init_Dnn_ShapeUtils();

    // DNN Utils
    //Init_Dnn_Utils_DebugUtils();
    //Init_Dnn_Utils_InferenceEngine();

    // Flann
    Init_Flann_Allocator();
    Init_Flann_AllIndices();
    Init_Flann_Any();
    Init_Flann_AutotunedIndex();
    Init_Flann_CompositeIndex();
    Init_Flann_Config();
    Init_Flann_Defines();
    Init_Flann_Dist();
    Init_Flann_DynamicBitset();
    Init_Flann_FlannBase();
    Init_Flann_Logger();
    Init_Flann_General();
    Init_Flann_GroundTruth();
    Init_Flann_Heap();
    Init_Flann_HierarchicalClusteringIndex();
    Init_Flann_IndexTesting();
    Init_Flann_KdtreeIndex();
    Init_Flann_KdtreeSingleIndex();
    Init_Flann_KmeansIndex();
    Init_Flann_LinearIndex();
    Init_Flann_LshIndex();
    Init_Flann_Matrix();
    Init_Flann_Miniflann();
    Init_Flann_NnIndex();
    Init_Flann_ObjectFactory();
    Init_Flann_Params();
    Init_Flann_Random();
    Init_Flann_ResultSet();
    Init_Flann_Sampling();
    Init_Flann_Saving();
    Init_Flann_SimplexDownhill();
    Init_Flann_Timer();

#if RUBY_CV_VERSION >= 408
    // Object Detection
    Init_Objdetect_ArucoBoard();
    Init_Objdetect_ArucoDetector();
    Init_Objdetect_ArucoDictionary();
    Init_Objdetect_GraphicalCodeDetector();
    Init_Objdetect_Barcode();
    Init_Objdetect_CharucoDetector();
    Init_Objdetect_DetectionBasedTracker();
    Init_Objdetect_Face();
#endif

    // Stitching
    Init_Stitching_Detail_Autocalib();
    Init_Stitching_Detail_Blenders();
    Init_Stitching_Detail_Camera();
    Init_Stitching_Detail_ExposureCompensate();
    Init_Stitching_Detail_Matchers();
    Init_Stitching_Detail_MotionEstimators();
    Init_Stitching_Detail_SeamFinders();
    Init_Stitching_Detail_Timelapsers();
    Init_Stitching_Detail_Util();
    Init_Stitching_Detail_UtilInl();
    Init_Stitching_Detail_Warpers();
    Init_Stitching_Warpers();

    // Video
    Init_Video_Detail_TrackingDetail();
    Init_Video_BackgroundSegm();
    Init_Video_Tracking();
    Init_Video_Video();

    // Top level
    Init_Aruco();
    Init_Bgsegm();
    Init_Bioinspired();
    Init_Calib3d();
    Init_Ccalib();
    Init_CoreDetect();
    //Init_Cudaarithm();
    //Init_Cudabgsegm();
    //Init_Cudacodec();
    //Init_Cudafeatures2d();
    //Init_Cudafilters();
    //Init_Cudaimgproc();
    //Init_Cudalegacy();
    //Init_Cudaobjdetect();
    //Init_Cudaoptflow();
    //Init_Cudastereo();
    //Init_Cudawarping();
    //Init_Cudev();
    Init_Cvconfig();
    Init_Dnn();
    Init_DnnSuperres();
    Init_Dpm();
    Init_Face();
    Init_Features2d();
    Init_Flann();
    Init_Fuzzy();
    Init_Hdf();
    Init_Hfs();
    Init_Highgui();
    Init_ImgHash();
    Init_Imgcodecs();
    Init_Imgproc();
    Init_IntensityTransform();
    Init_LineDescriptor();
    Init_Mcc();
    Init_Ml();
    Init_Objdetect();
    Init_Opencv();
    Init_OpencvModules();
    Init_Optflow();
    Init_PhaseUnwrapping();
    Init_Photo();
    Init_Plot();
    Init_Rapid();
    Init_Saliency();
    Init_Shape();
    Init_Signal();
    Init_Stereo();
    Init_Stitching();
    Init_StructuredLight();
    Init_Superres();
    Init_SurfaceMatching();
    Init_Text();
    Init_Tracking();
    Init_Video();
    Init_Videoio();
    Init_Videostab();
    Init_WechatQrcode();
    Init_Xfeatures2d();
    Init_Ximgproc();
    Init_Xobjdetect();
    Init_Xphoto();

    // Validate types
    Rice::detail::Registries::instance.types.validateTypes();

    // Setup Ruby API
    Init_Rice_Api();
  });
}