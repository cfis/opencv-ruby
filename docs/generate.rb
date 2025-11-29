require 'bundler/setup'

# Load needed files
require 'rice'
require 'rice/doc'

# Load the extension
require_relative '../lib/opencv_ruby.so'

# Get modules and classes
modules = Rice::Registries.instance.modules.modules
klasses = Rice::Registries.instance.types.klasses

# Doxygen documentation
doxygen_root = "https://docs.opencv.org/4.x"
doxygen_index = "https://docs.opencv.org/4.x/opencv.tag"
#doxygen_index = "c:/Users/cfis/Downloads/opencv.tag"
type_mappings = {/^enum\s*/i => '',
								 /^union\s*/i => '',
								 /<.*>/ => '',
								 '::debug_build_guard' => ''}

method_mappings = {'Cv' => {'agast' => 'AGAST',
														'approx_poly_dp' => 'approxPolyDP',
														'calc_optical_flow_pyr_lk' => 'calcOpticalFlowPyrLK',
														'calibrate_camera_ro' => 'calibrateCameraRO',
														'cam_shift' => 'CamShift',
														'compose_rt' => 'composeRT',
														'compute_ecc' => 'computeECC',
														'create_clahe' => 'createCLAHE',
														'current_ui_framework' => 'currentUIFramework',
														'create_align_mtb' => 'createAlignMTB',
														'create_background_subtractor_knn' => 'createBackgroundSubtractorKNN',
														'create_background_subtractor_mog2' => 'createBackgroundSubtractorMOG2',
														'denoise_tvl1' => 'denoise_TVL1',
														'emd' => 'EMD',
														'estimate_affine_2d' => 'estimateAffine2D',
														'estimate_affine_partial_2d' => 'estimateAffinePartial2D',
														'fast' => 'FAST',
														'filter_2d' => 'filter2D',
														'find_chessboard_corners_sb?' => 'findChessboardCornersSB',
														'find_transform_ecc' => 'findTransformECC',
														'fit_ellipse_ams' => 'fitEllipseAMS',
														'flip_nd' => 'flipND',
														'gaussian_blur' => 'GaussianBlur',
														'get_cpu_features_line' => 'getCPUFeaturesLine',
														'get_cpu_tick_count' => 'getCPUTickCount',
														'get_number_of_cp_us' => 'getNumberOfCPUs',
														'get_optimal_dft_size' => 'getOptimalDFTSize',
														'get_rotation_matrix_2d' => 'getRotationMatrix2D',
														'get_valid_disparity_roi' => 'getValidDisparityROI',
														'group_rectangles_meanshift' => 'groupRectangles_meanshift',
														'have_open_vx?' => 'haveOpenVX',
														'hough_circles' => 'HoughCircles',
														'hough_lines' => 'HoughLines',
														'hough_lines_p' => 'HoughLinesP',
														'hough_lines_point_set' => 'HoughLinesPointSet',
														'hu_moments' => 'HuMoments',
														'init_camera_matrix_2d' => 'initCameraMatrix2D',
														'lu' => 'LU',
														'lut' => 'LUT',
														'pca_back_project' => 'PCABackProject',
														'pca_compute' => 'PCACompute',
														'pca_project' => 'PCAProject',
														'psnr' => 'PSNR',
														'rq_decomp3x3' => 'RQDecomp3x3',
														'select_roi	' => 'selectROI',
														'sep_filter_2d' => 'sepFilter2D',
														'set_rng_seed' => 'setRNGSeed',
														'set_use_open_vx' => 'setUseOpenVX',
														'solve_lp' => 'solveLP',
														'solve_pn_p_refine_lm' => 'solvePnPRefineLM',
														'solve_pn_p_refine_vvs' => 'solvePnPRefineVVS',
														'sv_back_subst' => 'SVBackSubst',
														'sv_decomp' => 'SVDecomp',
														'the_rng' => 'theRNG',
														'transpose_nd' => 'transposeND',
														'use_open_vx?' => 'useOpenVX',
														'wrapper_emd' => 'wrapperEMD'},
									 'Cv::AsyncArray' => {'_get_impl' => '_getImpl',
																				'wait_for?' => 'wait_for'},
									 'Cv::BackgroundSubtractorKNN' => {'getk_nn_samples' => 'getkNNSamples',
																										 'setk_nn_samples' => 'setkNNSamples'},
									 'Cv::Cuda::DeviceInfo' => {'device_id' => 'deviceID',
																							'ecc_enabled?' => 'ECCEnabled',
																							'max_surface_2d' => 'maxSurface2D',
																							'max_texture_2d' => 'maxTexture2D',
																							'pci_bus_id' => 'pciBusID',
																							'pci_device_id' => 'pciDeviceID',
																							'pci_domain_id' => 'pciDomainID'},
									 'Cv::Cuda::GpuMat' => {'adjust_roi' => 'adjustROI',
																					'locate_roi' => 'locateROI'},
									 'Cv::Cuda::GpuMatND' => {'to_gpu_mat' => 'operator GpuMat'},
									 'Cv::FaceDetectorYN' => {'get_nms_threshold' => 'getNMSThreshold'},
									 'Cv::FaceRecognizerSF' => {'set_nms_threshold' => 'setNMSThreshold'},
									 'Cv::HOGDescriptor' => {'detect_multi_scale_roi' => 'detectMultiScaleROI',
																					 'detect_roi' => 'detectROI'},
									 'Cv::HOGDescriptor::DescriptorStorageFormat' => {'set_svm_detector' => 'setSVMDetector'},
									 'Cv::Hfloat' => {'to_float' => 'operator float'},
									 'Cv::Mat' => {'locate_roi' => 'locateROI'},
									 'Cv::Ml::ANN_MLP' => {'get_rprop_dw0' => 'getRpropDW0',
																				 'get_rprop_dw_max' => 'getRpropDWMax',
																				 'get_rprop_dw_min' => 'getRpropDWMin',
																				 'get_rprop_dw_minus' => 'getRpropDWMinus',
																				 'get_rprop_dw_plus' => 'getRpropDWPlus',
																				 'set_anneal_energy_rng' => 'setAnnealEnergyRNG',
																				 'set_rprop_dw0' => 'setRpropDW0',
																				 'set_rprop_dw_max' => 'setRpropDWMax',
																				 'set_rprop_dw_min' => 'setRpropDWMin',
																				 'set_rprop_dw_minus' => 'setRpropDWMinus',
																				 'set_rprop_dw_plus' => 'setRpropDWPlus'},
									 'Cv::Ml::DTrees' => {'get_cv_folds' => 'getCVFolds',
																				'get_use1_se_rule?' => 'getUse1SERule',
																				'set_cv_folds' => 'setCVFolds',
																				'set_use1_se_rule' => 'setUse1SERule'},
									 'Cv::Ml::RTrees' => {'get_oob_error' => 'getOOBError'}
}

doxygen_resolver = Rice::Doc::Doxygen.new(doxygen_root, doxygen_index, type_mappings, method_mappings)

# Setup resolvers per namespace
resolvers = {nil => Rice::Doc::Ruby.new,
						 'Cv' => doxygen_resolver,
						 'Rice' => Rice::Doc::Rice.new,
						 'Std' => Rice::Doc::CppReference.new}

output = File.expand_path('./reference')
generator = Rice::Doc::Mkdocs.new(modules + klasses, resolvers, output)
generator.generate
