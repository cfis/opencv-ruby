#include <opencv2/text/ocr.hpp>
#include "ocr-rb.hpp"

using namespace Rice;

void Init_Text_Ocr()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvText = define_module_under(rb_mCv, "Text");

  rb_mCvText.define_constant("OCR_LEVEL_WORD", (int)cv::text::OCR_LEVEL_WORD);
  rb_mCvText.define_constant("OCR_LEVEL_TEXTLINE", (int)cv::text::OCR_LEVEL_TEXTLINE);

  Enum<cv::text::page_seg_mode> rb_cCvTextPageSegMode = define_enum_under<cv::text::page_seg_mode>("PageSegMode", rb_mCvText).
    define_value("PSM_OSD_ONLY", cv::text::page_seg_mode::PSM_OSD_ONLY).
    define_value("PSM_AUTO_OSD", cv::text::page_seg_mode::PSM_AUTO_OSD).
    define_value("PSM_AUTO_ONLY", cv::text::page_seg_mode::PSM_AUTO_ONLY).
    define_value("PSM_AUTO", cv::text::page_seg_mode::PSM_AUTO).
    define_value("PSM_SINGLE_COLUMN", cv::text::page_seg_mode::PSM_SINGLE_COLUMN).
    define_value("PSM_SINGLE_BLOCK_VERT_TEXT", cv::text::page_seg_mode::PSM_SINGLE_BLOCK_VERT_TEXT).
    define_value("PSM_SINGLE_BLOCK", cv::text::page_seg_mode::PSM_SINGLE_BLOCK).
    define_value("PSM_SINGLE_LINE", cv::text::page_seg_mode::PSM_SINGLE_LINE).
    define_value("PSM_SINGLE_WORD", cv::text::page_seg_mode::PSM_SINGLE_WORD).
    define_value("PSM_CIRCLE_WORD", cv::text::page_seg_mode::PSM_CIRCLE_WORD).
    define_value("PSM_SINGLE_CHAR", cv::text::page_seg_mode::PSM_SINGLE_CHAR);

  Enum<cv::text::ocr_engine_mode> rb_cCvTextOcrEngineMode = define_enum_under<cv::text::ocr_engine_mode>("OcrEngineMode", rb_mCvText).
    define_value("OEM_TESSERACT_ONLY", cv::text::ocr_engine_mode::OEM_TESSERACT_ONLY).
    define_value("OEM_CUBE_ONLY", cv::text::ocr_engine_mode::OEM_CUBE_ONLY).
    define_value("OEM_TESSERACT_CUBE_COMBINED", cv::text::ocr_engine_mode::OEM_TESSERACT_CUBE_COMBINED).
    define_value("OEM_DEFAULT", cv::text::ocr_engine_mode::OEM_DEFAULT);

  Rice::Data_Type<cv::text::BaseOCR> rb_cCvTextBaseOCR = define_class_under<cv::text::BaseOCR>(rb_mCvText, "BaseOCR").
    define_method<void(cv::text::BaseOCR::*)(cv::Mat&, std::string&, std::vector<cv::Rect_<int>>*, std::vector<std::string>*, std::vector<float>*, int)>("run", &cv::text::BaseOCR::run,
      Arg("image"), Arg("output_text"), Arg("component_rects") = static_cast<std::vector<cv::Rect_<int>>*>(NULL), Arg("component_texts") = static_cast<std::vector<std::string>*>(NULL), Arg("component_confidences") = static_cast<std::vector<float>*>(NULL), Arg("component_level") = static_cast<int>(0)).
    define_method<void(cv::text::BaseOCR::*)(cv::Mat&, cv::Mat&, std::string&, std::vector<cv::Rect_<int>>*, std::vector<std::string>*, std::vector<float>*, int)>("run", &cv::text::BaseOCR::run,
      Arg("image"), Arg("mask"), Arg("output_text"), Arg("component_rects") = static_cast<std::vector<cv::Rect_<int>>*>(NULL), Arg("component_texts") = static_cast<std::vector<std::string>*>(NULL), Arg("component_confidences") = static_cast<std::vector<float>*>(NULL), Arg("component_level") = static_cast<int>(0));

  Rice::Data_Type<cv::text::OCRTesseract> rb_cCvTextOCRTesseract = define_class_under<cv::text::OCRTesseract, cv::text::BaseOCR>(rb_mCvText, "OCRTesseract").
    define_method<void(cv::text::OCRTesseract::*)(cv::Mat&, std::string&, std::vector<cv::Rect_<int>>*, std::vector<std::string>*, std::vector<float>*, int)>("run", &cv::text::OCRTesseract::run,
      Arg("image"), Arg("output_text"), Arg("component_rects") = static_cast<std::vector<cv::Rect_<int>>*>(NULL), Arg("component_texts") = static_cast<std::vector<std::string>*>(NULL), Arg("component_confidences") = static_cast<std::vector<float>*>(NULL), Arg("component_level") = static_cast<int>(0)).
    define_method<void(cv::text::OCRTesseract::*)(cv::Mat&, cv::Mat&, std::string&, std::vector<cv::Rect_<int>>*, std::vector<std::string>*, std::vector<float>*, int)>("run", &cv::text::OCRTesseract::run,
      Arg("image"), Arg("mask"), Arg("output_text"), Arg("component_rects") = static_cast<std::vector<cv::Rect_<int>>*>(NULL), Arg("component_texts") = static_cast<std::vector<std::string>*>(NULL), Arg("component_confidences") = static_cast<std::vector<float>*>(NULL), Arg("component_level") = static_cast<int>(0)).
    define_method<cv::String(cv::text::OCRTesseract::*)(cv::InputArray, int, int)>("run", &cv::text::OCRTesseract::run,
      Arg("image"), Arg("min_confidence"), Arg("component_level") = static_cast<int>(0)).
    define_method<cv::String(cv::text::OCRTesseract::*)(cv::InputArray, cv::InputArray, int, int)>("run", &cv::text::OCRTesseract::run,
      Arg("image"), Arg("mask"), Arg("min_confidence"), Arg("component_level") = static_cast<int>(0)).
    define_method<void(cv::text::OCRTesseract::*)(const cv::String&)>("set_white_list", &cv::text::OCRTesseract::setWhiteList,
      Arg("char_whitelist")).
    define_singleton_function<cv::Ptr<cv::text::OCRTesseract>(*)(const char*, const char*, const char*, int, int)>("create", &cv::text::OCRTesseract::create,
      Arg("datapath") = static_cast<const char*>(NULL), Arg("language") = static_cast<const char*>(NULL), Arg("char_whitelist") = static_cast<const char*>(NULL), Arg("oem") = static_cast<int>(cv::text::OEM_DEFAULT), Arg("psmode") = static_cast<int>(cv::text::PSM_AUTO));

  Enum<cv::text::decoder_mode> rb_cCvTextDecoderMode = define_enum_under<cv::text::decoder_mode>("DecoderMode", rb_mCvText).
    define_value("OCR_DECODER_VITERBI", cv::text::decoder_mode::OCR_DECODER_VITERBI);

  Enum<cv::text::classifier_type> rb_cCvTextClassifierType = define_enum_under<cv::text::classifier_type>("ClassifierType", rb_mCvText).
    define_value("OCR_KNN_CLASSIFIER", cv::text::classifier_type::OCR_KNN_CLASSIFIER).
    define_value("OCR_CNN_CLASSIFIER", cv::text::classifier_type::OCR_CNN_CLASSIFIER);

  Rice::Data_Type<cv::text::OCRHMMDecoder> rb_cCvTextOCRHMMDecoder = define_class_under<cv::text::OCRHMMDecoder, cv::text::BaseOCR>(rb_mCvText, "OCRHMMDecoder").
    define_constructor(Constructor<cv::text::OCRHMMDecoder>()).
    define_method<void(cv::text::OCRHMMDecoder::*)(cv::Mat&, std::string&, std::vector<cv::Rect_<int>>*, std::vector<std::string>*, std::vector<float>*, int)>("run", &cv::text::OCRHMMDecoder::run,
      Arg("image"), Arg("output_text"), Arg("component_rects") = static_cast<std::vector<cv::Rect_<int>>*>(NULL), Arg("component_texts") = static_cast<std::vector<std::string>*>(NULL), Arg("component_confidences") = static_cast<std::vector<float>*>(NULL), Arg("component_level") = static_cast<int>(0)).
    define_method<void(cv::text::OCRHMMDecoder::*)(cv::Mat&, cv::Mat&, std::string&, std::vector<cv::Rect_<int>>*, std::vector<std::string>*, std::vector<float>*, int)>("run", &cv::text::OCRHMMDecoder::run,
      Arg("image"), Arg("mask"), Arg("output_text"), Arg("component_rects") = static_cast<std::vector<cv::Rect_<int>>*>(NULL), Arg("component_texts") = static_cast<std::vector<std::string>*>(NULL), Arg("component_confidences") = static_cast<std::vector<float>*>(NULL), Arg("component_level") = static_cast<int>(0)).
    define_method<cv::String(cv::text::OCRHMMDecoder::*)(cv::InputArray, int, int)>("run", &cv::text::OCRHMMDecoder::run,
      Arg("image"), Arg("min_confidence"), Arg("component_level") = static_cast<int>(0)).
    define_method<cv::String(cv::text::OCRHMMDecoder::*)(cv::InputArray, cv::InputArray, int, int)>("run", &cv::text::OCRHMMDecoder::run,
      Arg("image"), Arg("mask"), Arg("min_confidence"), Arg("component_level") = static_cast<int>(0)).
    define_singleton_function<cv::Ptr<cv::text::OCRHMMDecoder>(*)(const cv::Ptr<cv::text::OCRHMMDecoder::ClassifierCallback>, const cv::String&, cv::InputArray, cv::InputArray, int)>("create", &cv::text::OCRHMMDecoder::create,
      Arg("classifier"), Arg("vocabulary"), Arg("transition_probabilities_table"), Arg("emission_probabilities_table"), Arg("mode") = static_cast<int>(cv::text::OCR_DECODER_VITERBI)).
    define_singleton_function<cv::Ptr<cv::text::OCRHMMDecoder>(*)(const cv::String&, const cv::String&, cv::InputArray, cv::InputArray, int, int)>("create", &cv::text::OCRHMMDecoder::create,
      Arg("filename"), Arg("vocabulary"), Arg("transition_probabilities_table"), Arg("emission_probabilities_table"), Arg("mode") = static_cast<int>(cv::text::OCR_DECODER_VITERBI), Arg("classifier") = static_cast<int>(cv::text::OCR_KNN_CLASSIFIER));

  Rice::Data_Type<cv::text::OCRHMMDecoder::ClassifierCallback> rb_cCvTextOCRHMMDecoderClassifierCallback = define_class_under<cv::text::OCRHMMDecoder::ClassifierCallback>(rb_cCvTextOCRHMMDecoder, "ClassifierCallback").
    define_constructor(Constructor<cv::text::OCRHMMDecoder::ClassifierCallback>()).
    define_method<void(cv::text::OCRHMMDecoder::ClassifierCallback::*)(cv::InputArray, std::vector<int>&, std::vector<double>&)>("eval", &cv::text::OCRHMMDecoder::ClassifierCallback::eval,
      Arg("image"), Arg("out_class"), Arg("out_confidence"));

  rb_mCvText.define_module_function<cv::Ptr<cv::text::OCRHMMDecoder::ClassifierCallback>(*)(const cv::String&)>("load_ocrhmm_classifier_nm", &cv::text::loadOCRHMMClassifierNM,
    Arg("filename"));

  rb_mCvText.define_module_function<cv::Ptr<cv::text::OCRHMMDecoder::ClassifierCallback>(*)(const cv::String&)>("load_ocrhmm_classifier_cnn", &cv::text::loadOCRHMMClassifierCNN,
    Arg("filename"));

  rb_mCvText.define_module_function<cv::Ptr<cv::text::OCRHMMDecoder::ClassifierCallback>(*)(const cv::String&, int)>("load_ocrhmm_classifier", &cv::text::loadOCRHMMClassifier,
    Arg("filename"), Arg("classifier"));

  rb_mCvText.define_module_function<void(*)(std::string&, std::vector<std::string>&, cv::OutputArray)>("create_ocrhmm_transitions_table", &cv::text::createOCRHMMTransitionsTable,
    Arg("vocabulary"), Arg("lexicon"), Arg("transition_probabilities_table"));

  rb_mCvText.define_module_function<cv::Mat(*)(const cv::String&, std::vector<cv::String>&)>("create_ocrhmm_transitions_table", &cv::text::createOCRHMMTransitionsTable,
    Arg("vocabulary"), Arg("lexicon"));

  Rice::Data_Type<cv::text::OCRBeamSearchDecoder> rb_cCvTextOCRBeamSearchDecoder = define_class_under<cv::text::OCRBeamSearchDecoder, cv::text::BaseOCR>(rb_mCvText, "OCRBeamSearchDecoder").
    define_constructor(Constructor<cv::text::OCRBeamSearchDecoder>()).
    define_method<void(cv::text::OCRBeamSearchDecoder::*)(cv::Mat&, std::string&, std::vector<cv::Rect_<int>>*, std::vector<std::string>*, std::vector<float>*, int)>("run", &cv::text::OCRBeamSearchDecoder::run,
      Arg("image"), Arg("output_text"), Arg("component_rects") = static_cast<std::vector<cv::Rect_<int>>*>(NULL), Arg("component_texts") = static_cast<std::vector<std::string>*>(NULL), Arg("component_confidences") = static_cast<std::vector<float>*>(NULL), Arg("component_level") = static_cast<int>(0)).
    define_method<void(cv::text::OCRBeamSearchDecoder::*)(cv::Mat&, cv::Mat&, std::string&, std::vector<cv::Rect_<int>>*, std::vector<std::string>*, std::vector<float>*, int)>("run", &cv::text::OCRBeamSearchDecoder::run,
      Arg("image"), Arg("mask"), Arg("output_text"), Arg("component_rects") = static_cast<std::vector<cv::Rect_<int>>*>(NULL), Arg("component_texts") = static_cast<std::vector<std::string>*>(NULL), Arg("component_confidences") = static_cast<std::vector<float>*>(NULL), Arg("component_level") = static_cast<int>(0)).
    define_method<cv::String(cv::text::OCRBeamSearchDecoder::*)(cv::InputArray, int, int)>("run", &cv::text::OCRBeamSearchDecoder::run,
      Arg("image"), Arg("min_confidence"), Arg("component_level") = static_cast<int>(0)).
    define_method<cv::String(cv::text::OCRBeamSearchDecoder::*)(cv::InputArray, cv::InputArray, int, int)>("run", &cv::text::OCRBeamSearchDecoder::run,
      Arg("image"), Arg("mask"), Arg("min_confidence"), Arg("component_level") = static_cast<int>(0)).
    define_singleton_function<cv::Ptr<cv::text::OCRBeamSearchDecoder>(*)(const cv::Ptr<cv::text::OCRBeamSearchDecoder::ClassifierCallback>, const std::string&, cv::InputArray, cv::InputArray, cv::text::decoder_mode, int)>("create", &cv::text::OCRBeamSearchDecoder::create,
      Arg("classifier"), Arg("vocabulary"), Arg("transition_probabilities_table"), Arg("emission_probabilities_table"), Arg("mode") = static_cast<cv::text::decoder_mode>(cv::text::OCR_DECODER_VITERBI), Arg("beam_size") = static_cast<int>(500)).
    define_singleton_function<cv::Ptr<cv::text::OCRBeamSearchDecoder>(*)(const cv::String&, const cv::String&, cv::InputArray, cv::InputArray, cv::text::decoder_mode, int)>("create", &cv::text::OCRBeamSearchDecoder::create,
      Arg("filename"), Arg("vocabulary"), Arg("transition_probabilities_table"), Arg("emission_probabilities_table"), Arg("mode") = static_cast<cv::text::decoder_mode>(cv::text::OCR_DECODER_VITERBI), Arg("beam_size") = static_cast<int>(500));

  Rice::Data_Type<cv::text::OCRBeamSearchDecoder::ClassifierCallback> rb_cCvTextOCRBeamSearchDecoderClassifierCallback = define_class_under<cv::text::OCRBeamSearchDecoder::ClassifierCallback>(rb_cCvTextOCRBeamSearchDecoder, "ClassifierCallback").
    define_constructor(Constructor<cv::text::OCRBeamSearchDecoder::ClassifierCallback>()).
    define_method<void(cv::text::OCRBeamSearchDecoder::ClassifierCallback::*)(cv::InputArray, std::vector<std::vector<double>>&, std::vector<int>&)>("eval", &cv::text::OCRBeamSearchDecoder::ClassifierCallback::eval,
      Arg("image"), Arg("recognition_probabilities"), Arg("oversegmentation")).
    define_method<int(cv::text::OCRBeamSearchDecoder::ClassifierCallback::*)()>("get_window_size", &cv::text::OCRBeamSearchDecoder::ClassifierCallback::getWindowSize).
    define_method<int(cv::text::OCRBeamSearchDecoder::ClassifierCallback::*)()>("get_step_size", &cv::text::OCRBeamSearchDecoder::ClassifierCallback::getStepSize);

  rb_mCvText.define_module_function<cv::Ptr<cv::text::OCRBeamSearchDecoder::ClassifierCallback>(*)(const cv::String&)>("load_ocr_beam_search_classifier_cnn", &cv::text::loadOCRBeamSearchClassifierCNN,
    Arg("filename"));

  Rice::Data_Type<cv::text::OCRHolisticWordRecognizer> rb_cCvTextOCRHolisticWordRecognizer = define_class_under<cv::text::OCRHolisticWordRecognizer, cv::text::BaseOCR>(rb_mCvText, "OCRHolisticWordRecognizer").
    define_method<void(cv::text::OCRHolisticWordRecognizer::*)(cv::Mat&, std::string&, std::vector<cv::Rect_<int>>*, std::vector<std::string>*, std::vector<float>*, int)>("run", &cv::text::OCRHolisticWordRecognizer::run,
      Arg("image"), Arg("output_text"), Arg("component_rects") = static_cast<std::vector<cv::Rect_<int>>*>(NULL), Arg("component_texts") = static_cast<std::vector<std::string>*>(NULL), Arg("component_confidences") = static_cast<std::vector<float>*>(NULL), Arg("component_level") = static_cast<int>(cv::text::OCR_LEVEL_WORD)).
    define_method<void(cv::text::OCRHolisticWordRecognizer::*)(cv::Mat&, cv::Mat&, std::string&, std::vector<cv::Rect_<int>>*, std::vector<std::string>*, std::vector<float>*, int)>("run", &cv::text::OCRHolisticWordRecognizer::run,
      Arg("image"), Arg("mask"), Arg("output_text"), Arg("component_rects") = static_cast<std::vector<cv::Rect_<int>>*>(NULL), Arg("component_texts") = static_cast<std::vector<std::string>*>(NULL), Arg("component_confidences") = static_cast<std::vector<float>*>(NULL), Arg("component_level") = static_cast<int>(cv::text::OCR_LEVEL_WORD)).
    define_singleton_function<cv::Ptr<cv::text::OCRHolisticWordRecognizer>(*)(const std::string&, const std::string&, const std::string&)>("create", &cv::text::OCRHolisticWordRecognizer::create,
      Arg("arch_filename"), Arg("weights_filename"), Arg("words_filename"));
}
