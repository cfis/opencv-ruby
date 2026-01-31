#include <opencv2/surface_matching/t_hash_int.hpp>
#include "t_hash_int-rb.hpp"

using namespace Rice;

void Init_SurfaceMatching_THashInt()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvPpfMatch3d = define_module_under(rb_mCv, "PpfMatch3d");

  Rice::Data_Type<cv::ppf_match_3d::hashnode_i> rb_cCvPpfMatch3dHashnodeI = define_class_under<cv::ppf_match_3d::hashnode_i>(rb_mCvPpfMatch3d, "HashnodeI").
    define_constructor(Constructor<cv::ppf_match_3d::hashnode_i>()).
    define_attr("key", &cv::ppf_match_3d::hashnode_i::key).
    define_attr("data", &cv::ppf_match_3d::hashnode_i::data).
    define_attr("next", &cv::ppf_match_3d::hashnode_i::next);

  Rice::Data_Type<cv::ppf_match_3d::HSHTBL_i> rb_cCvPpfMatch3dHSHTBLI = define_class_under<cv::ppf_match_3d::HSHTBL_i>(rb_mCvPpfMatch3d, "HSHTBLI").
    define_constructor(Constructor<cv::ppf_match_3d::HSHTBL_i>()).
    define_attr("size", &cv::ppf_match_3d::HSHTBL_i::size).
    define_attr("nodes", &cv::ppf_match_3d::HSHTBL_i::nodes).
    define_attr("hashfunc", &cv::ppf_match_3d::HSHTBL_i::hashfunc);

  rb_mCvPpfMatch3d.define_module_function<uint(*)(uint)>("next_power_of_two", &cv::ppf_match_3d::next_power_of_two,
    Arg("value"));

  rb_mCvPpfMatch3d.define_module_function<cv::ppf_match_3d::hashtable_int*(*)(size_t, size_t (*)(uint))>("hashtable_create", &cv::ppf_match_3d::hashtableCreate,
    Arg("size"), Arg("hashfunc"));

  rb_mCvPpfMatch3d.define_module_function<void(*)(cv::ppf_match_3d::hashtable_int*)>("hashtable_destroy", &cv::ppf_match_3d::hashtableDestroy,
    Arg("hashtbl"));

  rb_mCvPpfMatch3d.define_module_function<int(*)(cv::ppf_match_3d::hashtable_int*, cv::ppf_match_3d::KeyType, void*)>("hashtable_insert", &cv::ppf_match_3d::hashtableInsert,
    Arg("hashtbl"), Arg("key"), ArgBuffer("data"));

  rb_mCvPpfMatch3d.define_module_function<int(*)(cv::ppf_match_3d::hashtable_int*, cv::ppf_match_3d::KeyType, void*)>("hashtable_insert_hashed", &cv::ppf_match_3d::hashtableInsertHashed,
    Arg("hashtbl"), Arg("key"), ArgBuffer("data"));

  rb_mCvPpfMatch3d.define_module_function<int(*)(cv::ppf_match_3d::hashtable_int*, cv::ppf_match_3d::KeyType)>("hashtable_remove", &cv::ppf_match_3d::hashtableRemove,
    Arg("hashtbl"), Arg("key"));

  rb_mCvPpfMatch3d.define_module_function<void*(*)(cv::ppf_match_3d::hashtable_int*, cv::ppf_match_3d::KeyType)>("hashtable_get", &cv::ppf_match_3d::hashtableGet,
    Arg("hashtbl"), Arg("key"), ReturnBuffer());

  rb_mCvPpfMatch3d.define_module_function<cv::ppf_match_3d::hashnode_i*(*)(cv::ppf_match_3d::hashtable_int*, cv::ppf_match_3d::KeyType)>("hashtable_get_bucket_hashed", &cv::ppf_match_3d::hashtableGetBucketHashed,
    Arg("hashtbl"), Arg("key"));

  rb_mCvPpfMatch3d.define_module_function<int(*)(cv::ppf_match_3d::hashtable_int*, size_t)>("hashtable_resize", &cv::ppf_match_3d::hashtableResize,
    Arg("hashtbl"), Arg("size"));

  rb_mCvPpfMatch3d.define_module_function<cv::ppf_match_3d::hashtable_int*(*)(cv::ppf_match_3d::hashtable_int*)>("hashtable_int_clone", &cv::ppf_match_3d::hashtable_int_clone,
    Arg("hashtbl"));

  rb_mCvPpfMatch3d.define_module_function<cv::ppf_match_3d::hashtable_int*(*)(FILE*)>("hashtable_read", &cv::ppf_match_3d::hashtableRead,
    Arg("f"));

  rb_mCvPpfMatch3d.define_module_function<int(*)(const cv::ppf_match_3d::hashtable_int*, const size_t, FILE*)>("hashtable_write", &cv::ppf_match_3d::hashtableWrite,
    Arg("hashtbl"), Arg("data_size"), Arg("f"));

  rb_mCvPpfMatch3d.define_module_function<void(*)(cv::ppf_match_3d::hashtable_int*)>("hashtable_print", &cv::ppf_match_3d::hashtablePrint,
    Arg("hashtbl"));
}