# Subdirectories
add_subdirectory ("aruco")
add_subdirectory ("bioinspired")
add_subdirectory ("calib3d")
add_subdirectory ("ccalib")
add_subdirectory ("core")
add_subdirectory ("datasets")
add_subdirectory ("dnn")
add_subdirectory ("face")
add_subdirectory ("features2d")
add_subdirectory ("flann")
add_subdirectory ("fuzzy")
add_subdirectory ("hdf")
add_subdirectory ("highgui")
add_subdirectory ("img_hash")
add_subdirectory ("imgcodecs")
add_subdirectory ("imgproc")
add_subdirectory ("line_descriptor")
add_subdirectory ("mcc")
add_subdirectory ("ml")
add_subdirectory ("objdetect")
add_subdirectory ("optflow")
add_subdirectory ("phase_unwrapping")
add_subdirectory ("photo")
add_subdirectory ("reg")
add_subdirectory ("saliency")
add_subdirectory ("shape")
add_subdirectory ("signal")
add_subdirectory ("stereo")
add_subdirectory ("stitching")
add_subdirectory ("structured_light")
add_subdirectory ("superres")
add_subdirectory ("surface_matching")
add_subdirectory ("text")
add_subdirectory ("tracking")
add_subdirectory ("video")
add_subdirectory ("videoio")
add_subdirectory ("videostab")
add_subdirectory ("xfeatures2d")
add_subdirectory ("ximgproc")
add_subdirectory ("xphoto")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "aruco-rb.cpp"
    "bgsegm-rb.cpp"
    "bioinspired-rb.cpp"
    "calib3d-rb.cpp"
    "ccalib-rb.cpp"
    "core-rb.cpp"
    "core_detect-rb.cpp"
    "cudaarithm-rb.cpp"
    "cudabgsegm-rb.cpp"
    "cudacodec-rb.cpp"
    "cudafeatures2d-rb.cpp"
    "cudafilters-rb.cpp"
    "cudaimgproc-rb.cpp"
    "cudaobjdetect-rb.cpp"
    "cudaoptflow-rb.cpp"
    "cudastereo-rb.cpp"
    "cudawarping-rb.cpp"
    "cvconfig-rb.cpp"
    "dnn-rb.cpp"
    "dnn_superres-rb.cpp"
    "dpm-rb.cpp"
    "face-rb.cpp"
    "features2d-rb.cpp"
    "flann-rb.cpp"
    "fuzzy-rb.cpp"
    "hdf-rb.cpp"
    "hfs-rb.cpp"
    "highgui-rb.cpp"
    "img_hash-rb.cpp"
    "imgcodecs-rb.cpp"
    "imgproc-rb.cpp"
    "intensity_transform-rb.cpp"
    "line_descriptor-rb.cpp"
    "mcc-rb.cpp"
    "ml-rb.cpp"
    "objdetect-rb.cpp"
    "opencv-rb.cpp"
    "opencv_modules-rb.cpp"
    "optflow-rb.cpp"
    "phase_unwrapping-rb.cpp"
    "photo-rb.cpp"
    "plot-rb.cpp"
    "rapid-rb.cpp"
    "saliency-rb.cpp"
    "shape-rb.cpp"
    "signal-rb.cpp"
    "stereo-rb.cpp"
    "stitching-rb.cpp"
    "structured_light-rb.cpp"
    "superres-rb.cpp"
    "surface_matching-rb.cpp"
    "text-rb.cpp"
    "tracking-rb.cpp"
    "video-rb.cpp"
    "videoio-rb.cpp"
    "videostab-rb.cpp"
    "wechat_qrcode-rb.cpp"
    "xfeatures2d-rb.cpp"
    "ximgproc-rb.cpp"
    "xobjdetect-rb.cpp"
    "xphoto-rb.cpp"
  )
