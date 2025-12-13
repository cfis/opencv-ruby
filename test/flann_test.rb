#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class FlannTest < OpenCVTestCase
  # ============ CvType Classes ============
  def test_cvtype_char
    cvtype = Cv::Flann::CvTypeChar.new
    refute_nil(cvtype)
    assert_instance_of(Cv::Flann::CvTypeChar, cvtype)
  end

  def test_cvtype_unsigned_char
    cvtype = Cv::Flann::CvTypeUnsignedChar.new
    refute_nil(cvtype)
    assert_instance_of(Cv::Flann::CvTypeUnsignedChar, cvtype)
  end

  def test_cvtype_short
    cvtype = Cv::Flann::CvTypeShort.new
    refute_nil(cvtype)
    assert_instance_of(Cv::Flann::CvTypeShort, cvtype)
  end

  def test_cvtype_unsigned_short
    cvtype = Cv::Flann::CvTypeUnsignedShort.new
    refute_nil(cvtype)
    assert_instance_of(Cv::Flann::CvTypeUnsignedShort, cvtype)
  end

  def test_cvtype_int
    cvtype = Cv::Flann::CvTypeInt.new
    refute_nil(cvtype)
    assert_instance_of(Cv::Flann::CvTypeInt, cvtype)
  end

  def test_cvtype_float
    cvtype = Cv::Flann::CvTypeFloat.new
    refute_nil(cvtype)
    assert_instance_of(Cv::Flann::CvTypeFloat, cvtype)
  end

  def test_cvtype_double
    cvtype = Cv::Flann::CvTypeDouble.new
    refute_nil(cvtype)
    assert_instance_of(Cv::Flann::CvTypeDouble, cvtype)
  end

  # ============ Index Params Classes ============
  def test_index_params
    params = Cv::Flann::IndexParams.new
    refute_nil(params)
    assert_instance_of(Cv::Flann::IndexParams, params)
  end

  def test_kdtree_index_params
    params = Cv::Flann::KDTreeIndexParams.new
    refute_nil(params)
    assert_instance_of(Cv::Flann::KDTreeIndexParams, params)
  end

  def test_kdtree_index_params_with_trees
    params = Cv::Flann::KDTreeIndexParams.new(8)
    refute_nil(params)
  end

  def test_kmeans_index_params
    params = Cv::Flann::KMeansIndexParams.new
    refute_nil(params)
    assert_instance_of(Cv::Flann::KMeansIndexParams, params)
  end

  def test_linear_index_params
    params = Cv::Flann::LinearIndexParams.new
    refute_nil(params)
    assert_instance_of(Cv::Flann::LinearIndexParams, params)
  end

  def test_composite_index_params
    params = Cv::Flann::CompositeIndexParams.new
    refute_nil(params)
    assert_instance_of(Cv::Flann::CompositeIndexParams, params)
  end

  def test_autotuned_index_params
    params = Cv::Flann::AutotunedIndexParams.new
    refute_nil(params)
    assert_instance_of(Cv::Flann::AutotunedIndexParams, params)
  end

  def test_hierarchical_clustering_index_params
    params = Cv::Flann::HierarchicalClusteringIndexParams.new
    refute_nil(params)
    assert_instance_of(Cv::Flann::HierarchicalClusteringIndexParams, params)
  end

  def test_lsh_index_params
    # LshIndexParams requires table_number, key_size, multi_probe_level
    params = Cv::Flann::LshIndexParams.new(12, 20, 2)
    refute_nil(params)
    assert_instance_of(Cv::Flann::LshIndexParams, params)
  end

  def test_saved_index_params
    # SavedIndexParams requires a filename
    params = Cv::Flann::SavedIndexParams.new("dummy_filename.idx")
    refute_nil(params)
    assert_instance_of(Cv::Flann::SavedIndexParams, params)
  end

  def test_search_params
    params = Cv::Flann::SearchParams.new
    refute_nil(params)
    assert_instance_of(Cv::Flann::SearchParams, params)
  end

  def test_search_params_with_checks
    params = Cv::Flann::SearchParams.new(64)
    refute_nil(params)
  end

  # ============ Index Class ============
  def test_index_class_exists
    assert(Cv::Flann.const_defined?(:Index))
  end
end
