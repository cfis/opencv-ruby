#include "opencv_ruby_version.hpp"
#include <opencv2/opencv_modules.hpp>
#include "opencv_ruby-rb.hpp"

#ifdef HAVE_OPENCV_ARUCO
// Aruco
#include "opencv2/aruco/aruco_calib-rb.hpp"
#include "opencv2/aruco/charuco-rb.hpp"
#endif

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
#include "opencv2/core/cvstd.inl-rb.hpp"
#include "opencv2/core/cvstd_wrapper-rb.hpp"
#include "opencv2/core/directx-rb.hpp"
#include "opencv2/core/dualquaternion-rb.hpp"
#include "opencv2/core/eigen-rb.hpp"
#include "opencv2/core/fast_math-rb.hpp"
#include "opencv2/core/mat-rb.hpp"
#include "opencv2/core/mat.inl-rb.hpp"
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

#ifdef HAVE_OPENCV_DNN
// DNN
#include "opencv2/dnn/all_layers-rb.hpp"
#include "opencv2/dnn/dict-rb.hpp"
#include "opencv2/dnn/dnn-rb.hpp"
#include "opencv2/dnn/dnn.inl-rb.hpp"
#include "opencv2/dnn/layer-rb.hpp"
#include "opencv2/dnn/layer.details-rb.hpp"
#include "opencv2/dnn/shape_utils-rb.hpp"
#include "opencv2/dnn/version-rb.hpp"

// DNN Utils
#include "opencv2/dnn/utils/debug_utils-rb.hpp"
#include "opencv2/dnn/utils/inference_engine-rb.hpp"
#endif

#ifdef HAVE_OPENCV_FACE
// Face
#include "opencv2/face/bif-rb.hpp"
#include "opencv2/face/face_alignment-rb.hpp"
#include "opencv2/face/facemark-rb.hpp"
#include "opencv2/face/facemarkAAM-rb.hpp"
#include "opencv2/face/facemarkLBF-rb.hpp"
#include "opencv2/face/facemark_train-rb.hpp"
#include "opencv2/face/facerec-rb.hpp"
#include "opencv2/face/mace-rb.hpp"
#include "opencv2/face/predict_collector-rb.hpp"
#endif

#ifdef HAVE_OPENCV_FLANN
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
#include "opencv2/flann/timer-rb.hpp"
#endif

#ifdef HAVE_OPENCV_OBJDETECT
// Object Detection
#include "opencv2/objdetect/aruco_board-rb.hpp"
#include "opencv2/objdetect/aruco_detector-rb.hpp"
#include "opencv2/objdetect/aruco_dictionary-rb.hpp"
#include "opencv2/objdetect/barcode-rb.hpp"
#include "opencv2/objdetect/charuco_detector-rb.hpp"
#include "opencv2/objdetect/detection_based_tracker-rb.hpp"
#include "opencv2/objdetect/face-rb.hpp"
#include "opencv2/objdetect/graphical_code_detector-rb.hpp"
#endif

#ifdef HAVE_OPENCV_STITCHING
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
#endif

#ifdef HAVE_OPENCV_SUPERRES
// Superres
#include "opencv2/superres/optical_flow-rb.hpp"
#endif

#ifdef HAVE_OPENCV_VIDEO
// Video
#include "opencv2/video/detail/tracking.detail-rb.hpp"
#include "opencv2/video/background_segm-rb.hpp"
#include "opencv2/video/tracking-rb.hpp"
#include "opencv2/video/video-rb.hpp"
#endif

// Top Level
#ifdef HAVE_OPENCV_ARUCO
#include "opencv2/aruco-rb.hpp"
#endif
#ifdef HAVE_OPENCV_BGSEGM
#include "opencv2/bgsegm-rb.hpp"
#endif
#ifdef HAVE_OPENCV_BIOINSPIRED
#include "opencv2/bioinspired-rb.hpp"
#endif
#ifdef HAVE_OPENCV_CALIB3D
#include "opencv2/calib3d-rb.hpp"
#endif
#ifdef HAVE_OPENCV_CCALIB
#include "opencv2/ccalib-rb.hpp"
#endif
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
#ifdef HAVE_OPENCV_DNN
#include "opencv2/dnn-rb.hpp"
#endif
#ifdef HAVE_OPENCV_DNN_SUPERRES
#include "opencv2/dnn_superres-rb.hpp"
#endif
#ifdef HAVE_OPENCV_DPM
#include "opencv2/dpm-rb.hpp"
#endif
#ifdef HAVE_OPENCV_FACE
#include "opencv2/face-rb.hpp"
#endif
#ifdef HAVE_OPENCV_FEATURES2D
#include "opencv2/features2d-rb.hpp"
#endif
#ifdef HAVE_OPENCV_FLANN
#include "opencv2/flann-rb.hpp"
#endif
#ifdef HAVE_OPENCV_FUZZY
#include "opencv2/fuzzy-rb.hpp"
#endif
#ifdef HAVE_OPENCV_HDF
#include "opencv2/hdf-rb.hpp"
#endif
#ifdef HAVE_OPENCV_HFS
#include "opencv2/hfs-rb.hpp"
#endif
#ifdef HAVE_OPENCV_HIGHGUI
#include "opencv2/highgui-rb.hpp"
#endif
#ifdef HAVE_OPENCV_IMG_HASH
#include "opencv2/img_hash-rb.hpp"
#endif
#ifdef HAVE_OPENCV_IMGCODECS
#include "opencv2/imgcodecs-rb.hpp"
#endif
#ifdef HAVE_OPENCV_IMGPROC
#include "opencv2/imgproc-rb.hpp"
#endif
#ifdef HAVE_OPENCV_INTENSITY_TRANSFORM
#include "opencv2/intensity_transform-rb.hpp"
#endif
#ifdef HAVE_OPENCV_LINE_DESCRIPTOR
#include "opencv2/line_descriptor-rb.hpp"
#endif
#ifdef HAVE_OPENCV_MCC
#include "opencv2/mcc-rb.hpp"
#endif
#ifdef HAVE_OPENCV_ML
#include "opencv2/ml-rb.hpp"
#endif
#ifdef HAVE_OPENCV_OBJDETECT
#include "opencv2/objdetect-rb.hpp"
#endif
#include "opencv2/opencv-rb.hpp"
#include "opencv2/opencv_modules-rb.hpp"
#ifdef HAVE_OPENCV_OPTFLOW
#include "opencv2/optflow-rb.hpp"
#endif
#ifdef HAVE_OPENCV_PHASE_UNWRAPPING
#include "opencv2/phase_unwrapping-rb.hpp"
#endif
#ifdef HAVE_OPENCV_PHOTO
#include "opencv2/photo-rb.hpp"
#endif
#ifdef HAVE_OPENCV_PLOT
#include "opencv2/plot-rb.hpp"
#endif
#ifdef HAVE_OPENCV_RAPID
#include "opencv2/rapid-rb.hpp"
#endif
#ifdef HAVE_OPENCV_SALIENCY
#include "opencv2/saliency-rb.hpp"
#endif
#ifdef HAVE_OPENCV_SHAPE
#include "opencv2/shape-rb.hpp"
#endif
#ifdef HAVE_OPENCV_SIGNAL
#include "opencv2/signal-rb.hpp"
#endif
#ifdef HAVE_OPENCV_STEREO
#include "opencv2/stereo-rb.hpp"
#endif
#ifdef HAVE_OPENCV_STITCHING
#include "opencv2/stitching-rb.hpp"
#endif
#ifdef HAVE_OPENCV_STRUCTURED_LIGHT
#include "opencv2/structured_light-rb.hpp"
#endif
#ifdef HAVE_OPENCV_SUPERRES
#include "opencv2/superres-rb.hpp"
#endif
#ifdef HAVE_OPENCV_SURFACE_MATCHING
#include "opencv2/surface_matching-rb.hpp"
#endif
#ifdef HAVE_OPENCV_TEXT
#include "opencv2/text-rb.hpp"
#endif
#ifdef HAVE_OPENCV_TRACKING
#include "opencv2/tracking-rb.hpp"
#endif
#ifdef HAVE_OPENCV_VIDEO
#include "opencv2/video-rb.hpp"
#endif
#ifdef HAVE_OPENCV_VIDEOIO
#include "opencv2/videoio-rb.hpp"
#endif
#ifdef HAVE_OPENCV_VIDEOSTAB
#include "opencv2/videostab-rb.hpp"
#endif
#ifdef HAVE_OPENCV_WECHAT_QRCODE
#include "opencv2/wechat_qrcode-rb.hpp"
#endif
#ifdef HAVE_OPENCV_XFEATURES2D
#include "opencv2/xfeatures2d-rb.hpp"
#endif
#ifdef HAVE_OPENCV_XIMGPROC
#include "opencv2/ximgproc-rb.hpp"
#endif
#ifdef HAVE_OPENCV_XOBJDETECT
#include "opencv2/xobjdetect-rb.hpp"
#endif
#ifdef HAVE_OPENCV_XPHOTO
#include "opencv2/xphoto-rb.hpp"
#endif

// Refinements - manual additions to generated classes
#include "refinements/base-rb.hpp"
#include "refinements/core-rb.hpp"
#ifdef OpenCV_HAS_CUDA
#include "refinements/cuda-rb.hpp"
#endif
#ifdef HAVE_OPENCV_DNN
#include "refinements/dnn-rb.hpp"
#endif
#include "refinements/hal-rb.hpp"
#include "refinements/mat-rb.hpp"
#include "refinements/matx-rb.hpp"
#include "refinements/persistence-rb.hpp"
#include "refinements/types-rb.hpp"

extern "C"
void Init_opencv_ruby()
{
  return Rice::detail::cpp_protect([]
  {
#ifdef HAVE_OPENCV_ARUCO
    // Aruco
    Init_Aruco_ArucoCalib();
    Init_Aruco_Charuco();
#endif

    // HAL
    Init_Core_Hal_Interface();

    // Core
    Init_Core();

    // Core Detail
    Init_Core_Detail_AsyncPromise();
    Init_Core_Detail_DispatchHelperImpl();
    Init_Core_Detail_ExceptionPtr();

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
    Init_Core_CvstdInl();
    Init_Core_MatInl();
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
   /* Init_Core_Utils_AllocatorStats();
    Init_Core_Utils_AllocatorStatsImpl();
    Init_Core_Utils_Filesystem();
    Init_Core_Utils_Logger();
    Init_Core_Utils_LoggerDefines();
    Init_Core_Utils_Logtag();
    Init_Core_Utils_Trace();*/

    // Core Refinements
    Init_Core_Refinements();
    Init_Core_Base_Refinements();
#ifdef OpenCV_HAS_CUDA
    Init_Core_Cuda_Refinements();
#endif
    Init_Core_Mat_Refinements();
    Init_Core_Matx_Refinements();
    Init_Core_Persistence_Refinements();
    Init_Core_Types_Refinements();
    Init_Core_Hal_Refinements();

#ifdef HAVE_OPENCV_DNN
    // DNN
    Init_Dnn_Version();
    Init_Dnn_Dict();
    Init_Dnn_Dnn();
    Init_Dnn_DnnInl();
    Init_Dnn_Layer();
    Init_Dnn_LayerDetails();
    Init_Dnn_AllLayers();
    Init_Dnn_ShapeUtils();

    // DNN Utils
    //Init_Dnn_Utils_DebugUtils();
    //Init_Dnn_Utils_InferenceEngine();

    // DNN Refinements
    Init_Dnn_Refinements();
#endif

#ifdef HAVE_OPENCV_FLANN
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
    Init_Flann_Timer();
#endif

#ifdef HAVE_OPENCV_FACE
    // Face (order matters due to inheritance)
    Init_Face_Bif();
    Init_Face_Mace();
    Init_Face_PredictCollector();
    Init_Face_Facemark();
    Init_Face_FacemarkTrain();
    Init_Face_FaceAlignment();
    Init_Face_FacemarkAAM();
    Init_Face_FacemarkLBF();
#endif

#ifdef HAVE_OPENCV_OBJDETECT
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
#endif

#ifdef HAVE_OPENCV_STITCHING
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
#endif

#ifdef HAVE_OPENCV_SUPERRES
    // Superres
    Init_Superres_OpticalFlow();
#endif

#ifdef HAVE_OPENCV_VIDEO
    // Video
    Init_Video_Detail_TrackingDetail();
    Init_Video_BackgroundSegm();
    Init_Video_Tracking();
    Init_Video_Video();
#endif

    // Top level
#ifdef HAVE_OPENCV_ARUCO
    Init_Aruco();
#endif
#ifdef HAVE_OPENCV_BGSEGM
    Init_Bgsegm();
#endif
#ifdef HAVE_OPENCV_BIOINSPIRED
    Init_Bioinspired();
#endif
#ifdef HAVE_OPENCV_CALIB3D
    Init_Calib3d();
#endif
#ifdef HAVE_OPENCV_CCALIB
    Init_Ccalib();
#endif
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
#ifdef HAVE_OPENCV_DNN
    Init_Dnn();
#endif
#ifdef HAVE_OPENCV_DNN_SUPERRES
    Init_DnnSuperres();
#endif
#ifdef HAVE_OPENCV_DPM
    Init_Dpm();
#endif
#ifdef HAVE_OPENCV_FACE
    Init_Face();
    Init_Face_Facerec();  // Must come after Init_Face() which defines FaceRecognizer
#endif
#ifdef HAVE_OPENCV_FEATURES2D
    Init_Features2d();
#endif
#ifdef HAVE_OPENCV_FLANN
    Init_Flann();
#endif
#ifdef HAVE_OPENCV_FUZZY
    Init_Fuzzy();
#endif
#ifdef HAVE_OPENCV_HDF
    Init_Hdf();
#endif
#ifdef HAVE_OPENCV_HFS
    Init_Hfs();
#endif
#ifdef HAVE_OPENCV_HIGHGUI
    Init_Highgui();
#endif
#ifdef HAVE_OPENCV_IMG_HASH
    Init_ImgHash();
#endif
#ifdef HAVE_OPENCV_IMGCODECS
    Init_Imgcodecs();
#endif
#ifdef HAVE_OPENCV_IMGPROC
    Init_Imgproc();
#endif
#ifdef HAVE_OPENCV_INTENSITY_TRANSFORM
    Init_IntensityTransform();
#endif
#ifdef HAVE_OPENCV_LINE_DESCRIPTOR
    Init_LineDescriptor();
#endif
#ifdef HAVE_OPENCV_MCC
    Init_Mcc();
#endif
#ifdef HAVE_OPENCV_ML
    Init_Ml();
#endif
#ifdef HAVE_OPENCV_OBJDETECT
    Init_Objdetect();
#endif
    Init_Opencv();
    Init_OpencvModules();
#ifdef HAVE_OPENCV_OPTFLOW
    Init_Optflow();
#endif
#ifdef HAVE_OPENCV_PHASE_UNWRAPPING
    Init_PhaseUnwrapping();
#endif
#ifdef HAVE_OPENCV_PHOTO
    Init_Photo();
#endif
#ifdef HAVE_OPENCV_PLOT
    Init_Plot();
#endif
#ifdef HAVE_OPENCV_RAPID
    Init_Rapid();
#endif
#ifdef HAVE_OPENCV_SALIENCY
    Init_Saliency();
#endif
#ifdef HAVE_OPENCV_SHAPE
    Init_Shape();
#endif
#ifdef HAVE_OPENCV_SIGNAL
    Init_Signal();
#endif
#ifdef HAVE_OPENCV_STEREO
    Init_Stereo();
#endif
#ifdef HAVE_OPENCV_STITCHING
    Init_Stitching();
#endif
#ifdef HAVE_OPENCV_STRUCTURED_LIGHT
    Init_StructuredLight();
#endif
#ifdef HAVE_OPENCV_SUPERRES
    Init_Superres();
#endif
#ifdef HAVE_OPENCV_SURFACE_MATCHING
    Init_SurfaceMatching();
#endif
#ifdef HAVE_OPENCV_TEXT
    Init_Text();
#endif
#ifdef HAVE_OPENCV_TRACKING
    Init_Tracking();
#endif
#ifdef HAVE_OPENCV_VIDEO
    Init_Video();
#endif
#ifdef HAVE_OPENCV_VIDEOIO
    Init_Videoio();
#endif
#ifdef HAVE_OPENCV_VIDEOSTAB
    Init_Videostab();
#endif
#ifdef HAVE_OPENCV_WECHAT_QRCODE
    Init_WechatQrcode();
#endif
#ifdef HAVE_OPENCV_XFEATURES2D
    Init_Xfeatures2d();
#endif
#ifdef HAVE_OPENCV_XIMGPROC
    Init_Ximgproc();
#endif
#ifdef HAVE_OPENCV_XOBJDETECT
    Init_Xobjdetect();
#endif
#ifdef HAVE_OPENCV_XPHOTO
    Init_Xphoto();
#endif

    // Validate types
    Rice::detail::Registries::instance.types.validateTypes();

    // Setup Ruby API
    Init_Rice_Api();
  });
}
