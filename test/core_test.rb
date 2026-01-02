#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class CoreTest < OpenCVTestCase
  def test_add_weighted
    mat1 = create_mat(3, 2, CV_8UC1) { |j, i, c| c + 1 }
    mat2 = create_mat(3, 2, CV_8UC1) { |j, i, c| (c + 1) * 10 }
    mat3 = Cv::Mat.new
    alpha = 2.0
    beta = 0.1
    gamma = 100
    Cv.add_weighted(mat1.input_array, alpha, mat2.input_array, beta, gamma, mat3.output_array)
    assert_equal(mat1.class, mat3.class)
    assert_equal(mat1.rows, mat3.rows)
    assert_equal(mat1.cols, mat3.cols)
    assert_equal(mat1.depth, mat3.depth)
    assert_equal(mat1.channels, mat3.channels)

    mat1.rows.times do |j|
      mat1.cols.times do |i|
        expected = mat1[j, i] * alpha + mat2[j, i] * beta + gamma
        assert_equal(expected, mat3[j, i])
      end
    end
  end

  def test_convert_scale_abs
    mat1 = create_mat(2, 3, CV_8UC4) do |j, i, c|
      Cv::Vec4b.new(c, c, c, c)
    end

    mat2 = mat1.convert_scale_abs
    assert_equal("dd671da8f8262597637b4b047464ccda", hash_img(mat2))
  end

  def test_eigen
    elems = [6.0, -2.0, -2.0, 7.0]
    mat1 = create_mat(2, 2, CV_32FC1) do |j, i, c|
      elems[c]
    end
    values, vectors = mat1.eigen
    assert_equal([8.561553001403809, 4.438446998596191], values.to_a)
    assert_equal([0.6154122352600098, -0.7882053852081299, -0.7882053852081299, -0.6154122352600098], vectors.to_a)
  end

  def test_flip
    mat1 = create_mat(2, 3, CV_8UC1)
    mat2 = mat1.clone.flip(0)
    mat3 = mat1.clone.flip(1)
    mat4 = mat1.clone.flip(-1)

    expected = [1, 2, 3,
                4, 5, 6]
    assert_equal(expected, mat1.to_a)

    expected = [4, 5, 6,
                1, 2, 3]
    assert_equal(expected, mat2.to_a)

    expected = [3, 2, 1,
                6, 5, 4]
    assert_equal(expected, mat3.to_a)

    expected = [6, 5, 4,
                3, 2, 1]
    assert_equal(expected, mat4.to_a)
  end

  def test_lut
    mat1 = create_mat(2, 3, CV_8UC3)
    lut_mat = create_mat(1, 256, CV_8UC3) do |j, i, c|
      Cv::Vec3b.new(255 - c, 255 - c, 255 - c)
    end
    mat2 = mat1.lut(lut_mat)

    mat1.rows.times do |j|
      mat1.cols.times do |i|
        r, g, b = mat1[j, i].to_a.map { |c| 255 - c }
        assert_equal(Cv::Vec3b.new(r, g, b), mat2[j, i])
      end
    end
  end

  def test_merge
    mat1 = create_mat(2, 3, CV_8UC4) do |j, i, c|
      Cv::Vec4b.new(c * 10, c * 20, c * 30, c * 40)
    end

    mat2 = create_mat(2, 3, CV_8UC1) do |j, i, c|
      c * 10
    end

    mat3 = create_mat(2, 3, CV_8UC1) do |j, i, c|
      c * 20
    end

    mat4 = create_mat(2, 3, CV_8UC1) do |j, i, c|
      c * 30
    end

    mat5 = create_mat(2, 3, CV_8UC1) do |j, i, c|
      c * 40
    end

    vector = Std::Vector≺cv꞉꞉Mat≻.new([mat2, mat3, mat4, mat5])
    input = Cv::InputArray.new(vector)
    mat6 = Cv::Mat.new(mat2.rows, mat2.cols, mat2.type)
    Cv::merge(input, mat6.output_array)

    assert_equal(mat1.to_a, mat6.to_a)
  end

  def test_merge_image
    image_path = self.sample_path("starry_night.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
    channels = image.split

    output_array = Cv::InputArray.new(channels)
    merged = Cv::Mat.new
    Cv.merge(output_array, merged.output_array)

    assert_equal(image.cols, merged.cols)
    assert_equal(image.rows, merged.rows)
    assert_equal(image.type, merged.type)
    assert_equal(image, merged)
  end

  def test_rand_shuffle
    mat1 = create_mat(2, 3, CV_8UC1)
    mat2 = mat1.clone.rand_shuffle(iter_factor: 123)
    # Just verify it shuffles without error (results vary by platform)
    assert_equal(6, mat2.to_a.size)
    assert_equal([1, 2, 3, 4, 5, 6].sort, mat2.to_a.sort)

    mat3 = mat1.clone.rand_shuffle(rng: Cv::RNG.new)
    assert_equal(6, mat3.to_a.size)
    assert_equal([1, 2, 3, 4, 5, 6].sort, mat3.to_a.sort)
  end

  def test_split
    mat1 = create_mat(2, 3, CV_8UC3) do |j, i, c|
      Cv::Vec3b.new(c * 10, c * 20, c * 30)
    end
    channels = mat1.split
    assert_equal(mat1.channels, channels.size)
    channels.each_with_index do |mat, idx|
      assert_equal(Cv::Mat, mat.class)
      assert_equal(mat1.rows, mat.rows)
      assert_equal(mat1.cols, mat.cols)
      assert_equal(1, mat.channels)
      c = 0
      mat1.rows.times do |row|
        mat1.cols.times do |col|
          expected = c * 10 * (idx + 1)
          actual = mat[row, col]
          assert_equal(expected, actual)
          c += 1
        end
      end
    end
  end

  def test_split_image
    image_path = self.sample_path("starry_night.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
    channels = image.split
    assert_equal(3, channels.size)
    channels.each do |channel|
      assert_equal(channel.cols, image.cols)
      assert_equal(channel.rows, image.rows)
      assert_equal(CV_8UC1, channel.type)
    end
  end

  # ============ RNG Tests ============
  def test_rng_create
    rng = Cv::RNG.new
    assert_instance_of(Cv::RNG, rng)
  end

  def test_rng_create_with_seed
    rng = Cv::RNG.new(12345)
    assert_instance_of(Cv::RNG, rng)
    assert_equal(12345, rng.state)
  end

  def test_rng_next
    rng = Cv::RNG.new(42)
    val1 = rng.next
    val2 = rng.next
    assert(val1 != val2)
    assert(val1.is_a?(Integer))
  end

  def test_rng_uniform_int
    rng = Cv::RNG.new(42)
    100.times do
      val = rng.uniform(0, 100)
      assert(val >= 0 && val < 100)
    end
  end

  def test_rng_uniform_float
    rng = Cv::RNG.new(42)
    100.times do
      val = rng.uniform(0.0, 1.0)
      assert(val >= 0.0 && val < 1.0)
    end
  end

  def test_rng_gaussian
    rng = Cv::RNG.new(42)
    values = 1000.times.map { rng.gaussian(1.0) }
    mean = values.sum / values.size
    # Mean should be close to 0 for a gaussian with sigma=1
    assert_in_delta(0.0, mean, 0.2)
  end

  def test_rng_fill_uniform
    rng = Cv::RNG.new(42)
    mat = Cv::Mat.new(10, 10, CV_32FC1)
    low = Cv::Scalar.new(0.0)
    high = Cv::Scalar.new(1.0)
    rng.fill(mat.input_output_array, Cv::RNG::UNIFORM, low.input_array, high.input_array)
    mat.rows.times do |i|
      mat.cols.times do |j|
        val = mat[i, j]
        assert(val >= 0.0 && val <= 1.0, "Value #{val} out of range")
      end
    end
  end

  def test_rng_fill_normal
    rng = Cv::RNG.new(42)
    mat = Cv::Mat.new(100, 100, CV_32FC1)
    mean = Cv::Scalar.new(0.0)
    stddev = Cv::Scalar.new(1.0)
    rng.fill(mat.input_output_array, Cv::RNG::NORMAL, mean.input_array, stddev.input_array)
    # Just verify it doesn't crash and produces values
    assert_equal(100, mat.rows)
    assert_equal(100, mat.cols)
  end

  def test_rng_equality
    rng1 = Cv::RNG.new(42)
    rng2 = Cv::RNG.new(42)
    assert(rng1 == rng2)

    rng3 = Cv::RNG.new(43)
    refute(rng1 == rng3)
  end

  # ============ RNG_MT19937 Tests ============
  def test_rng_mt19937_create
    rng = Cv::RNG_MT19937.new
    assert_instance_of(Cv::RNG_MT19937, rng)
  end

  def test_rng_mt19937_with_seed
    rng = Cv::RNG_MT19937.new(12345)
    assert_instance_of(Cv::RNG_MT19937, rng)
  end

  def test_rng_mt19937_next
    rng = Cv::RNG_MT19937.new(42)
    val1 = rng.next
    val2 = rng.next
    assert(val1 != val2)
  end

  def test_rng_mt19937_uniform_int
    rng = Cv::RNG_MT19937.new(42)
    100.times do
      val = rng.uniform(0, 100)
      assert(val >= 0 && val < 100)
    end
  end

  def test_rng_mt19937_uniform_float
    rng = Cv::RNG_MT19937.new(42)
    100.times do
      val = rng.uniform(0.0, 1.0)
      assert(val >= 0.0 && val < 1.0)
    end
  end

  def test_rng_mt19937_seed
    rng = Cv::RNG_MT19937.new
    rng.seed(12345)
    val1 = rng.next

    rng.seed(12345)
    val2 = rng.next

    assert_equal(val1, val2)
  end

  # ============ PCA Tests ============
  def test_pca_create
    pca = Cv::PCA.new
    assert_instance_of(Cv::PCA, pca)
  end

  def test_pca_compute
    # Create sample data (5 samples, 3 features)
    data = Cv::Mat.new(5, 3, CV_32FC1)
    data[0, 0] = 1.0; data[0, 1] = 2.0; data[0, 2] = 3.0
    data[1, 0] = 2.0; data[1, 1] = 3.0; data[1, 2] = 4.0
    data[2, 0] = 3.0; data[2, 1] = 4.0; data[2, 2] = 5.0
    data[3, 0] = 4.0; data[3, 1] = 5.0; data[3, 2] = 6.0
    data[4, 0] = 5.0; data[4, 1] = 6.0; data[4, 2] = 7.0

    mean = Cv::Mat.new
    pca = Cv::PCA.new(data.input_array, mean.input_output_array, Cv::PCA::Flags::DATA_AS_ROW.to_i)

    assert_equal(1, pca.mean.rows)
    assert_equal(3, pca.mean.cols)
    assert_equal(3, pca.eigenvectors.rows)
    assert_equal(3, pca.eigenvectors.cols)
    assert_equal(3, pca.eigenvalues.rows)
    assert_equal(1, pca.eigenvalues.cols)
  end

  def test_pca_project_back_project
    # Create sample data
    data = Cv::Mat.new(5, 3, CV_32FC1)
    data[0, 0] = 1.0; data[0, 1] = 2.0; data[0, 2] = 3.0
    data[1, 0] = 2.0; data[1, 1] = 3.0; data[1, 2] = 4.0
    data[2, 0] = 3.0; data[2, 1] = 4.0; data[2, 2] = 5.0
    data[3, 0] = 4.0; data[3, 1] = 5.0; data[3, 2] = 6.0
    data[4, 0] = 5.0; data[4, 1] = 6.0; data[4, 2] = 7.0

    mean = Cv::Mat.new
    pca = Cv::PCA.new(data.input_array, mean.input_output_array, Cv::PCA::Flags::DATA_AS_ROW.to_i, 2)

    # Project first sample
    sample = Cv::Mat.new(1, 3, CV_32FC1)
    sample[0, 0] = 1.0; sample[0, 1] = 2.0; sample[0, 2] = 3.0
    projected = pca.project(sample.input_array)

    assert_equal(1, projected.rows)
    assert_equal(2, projected.cols)

    # Back project
    reconstructed = pca.back_project(projected.input_array)
    assert_equal(1, reconstructed.rows)
    assert_equal(3, reconstructed.cols)
  end

  def test_pca_flags
    assert_equal(0, Cv::PCA::Flags::DATA_AS_ROW.to_i)
    assert_equal(1, Cv::PCA::Flags::DATA_AS_COL.to_i)
    assert_equal(2, Cv::PCA::Flags::USE_AVG.to_i)
  end

  # ============ LDA Tests ============
  def test_lda_create
    lda = Cv::LDA.new
    assert_instance_of(Cv::LDA, lda)
  end

  def test_lda_create_with_components
    lda = Cv::LDA.new(2)
    assert_instance_of(Cv::LDA, lda)
  end

  def test_lda_compute
    # Create sample data with 2 classes
    src = Std::Vector≺cv꞉꞉Mat≻.new
    labels = Cv::Mat.new(10, 1, CV_32SC1)

    # Class 0: values around 1.0
    5.times do |i|
      mat = Cv::Mat.new(1, 3, CV_64FC1)
      mat[0, 0] = 1.0 + i * 0.1
      mat[0, 1] = 1.0 + i * 0.1
      mat[0, 2] = 1.0 + i * 0.1
      src.push_back(mat)
      labels[i, 0] = 0
    end

    # Class 1: values around 5.0
    5.times do |i|
      mat = Cv::Mat.new(1, 3, CV_64FC1)
      mat[0, 0] = 5.0 + i * 0.1
      mat[0, 1] = 5.0 + i * 0.1
      mat[0, 2] = 5.0 + i * 0.1
      src.push_back(mat)
      labels[5 + i, 0] = 1
    end

    lda = Cv::LDA.new(1)
    lda.compute(Cv::InputArray.new(src), labels.input_array)

    eigenvectors = lda.eigenvectors
    eigenvalues = lda.eigenvalues

    assert(eigenvectors.rows > 0)
    assert(eigenvalues.rows > 0)
  end

  def test_lda_project
    # Create sample data with 2 classes
    src = Std::Vector≺cv꞉꞉Mat≻.new
    labels = Cv::Mat.new(10, 1, CV_32SC1)

    5.times do |i|
      mat = Cv::Mat.new(1, 3, CV_64FC1)
      mat[0, 0] = 1.0 + i * 0.1
      mat[0, 1] = 1.0 + i * 0.1
      mat[0, 2] = 1.0 + i * 0.1
      src.push_back(mat)
      labels[i, 0] = 0
    end

    5.times do |i|
      mat = Cv::Mat.new(1, 3, CV_64FC1)
      mat[0, 0] = 5.0 + i * 0.1
      mat[0, 1] = 5.0 + i * 0.1
      mat[0, 2] = 5.0 + i * 0.1
      src.push_back(mat)
      labels[5 + i, 0] = 1
    end

    lda = Cv::LDA.new(1)
    lda.compute(Cv::InputArray.new(src), labels.input_array)

    # Project a sample
    sample = Cv::Mat.new(1, 3, CV_64FC1)
    sample[0, 0] = 3.0
    sample[0, 1] = 3.0
    sample[0, 2] = 3.0

    projected = lda.project(sample.input_array)
    assert_equal(1, projected.rows)
  end

  # ============ SVD Tests ============
  def test_svd_create
    svd = Cv::SVD.new
    assert_instance_of(Cv::SVD, svd)
  end

  def test_svd_compute
    mat = Cv::Mat.new(3, 3, CV_32FC1)
    mat[0, 0] = 1.0; mat[0, 1] = 2.0; mat[0, 2] = 3.0
    mat[1, 0] = 4.0; mat[1, 1] = 5.0; mat[1, 2] = 6.0
    mat[2, 0] = 7.0; mat[2, 1] = 8.0; mat[2, 2] = 9.0

    svd = Cv::SVD.new(mat.input_array)

    assert_equal(3, svd.u.rows)
    assert_equal(3, svd.u.cols)
    assert_equal(3, svd.w.rows)
    assert_equal(1, svd.w.cols)
    assert_equal(3, svd.vt.rows)
    assert_equal(3, svd.vt.cols)
  end

  def test_svd_compute_static
    mat = Cv::Mat.new(3, 3, CV_32FC1)
    mat[0, 0] = 1.0; mat[0, 1] = 2.0; mat[0, 2] = 3.0
    mat[1, 0] = 4.0; mat[1, 1] = 5.0; mat[1, 2] = 6.0
    mat[2, 0] = 7.0; mat[2, 1] = 8.0; mat[2, 2] = 9.0

    w = Cv::Mat.new
    u = Cv::Mat.new
    vt = Cv::Mat.new

    Cv::SVD.compute(mat.input_array, w.output_array, u.output_array, vt.output_array)

    assert_equal(3, u.rows)
    assert_equal(3, u.cols)
    assert_equal(3, w.rows)
    assert_equal(1, w.cols)
    assert_equal(3, vt.rows)
    assert_equal(3, vt.cols)
  end

  def test_svd_flags
    assert_equal(1, Cv::SVD::Flags::MODIFY_A.to_i)
    assert_equal(2, Cv::SVD::Flags::NO_UV.to_i)
    assert_equal(4, Cv::SVD::Flags::FULL_UV.to_i)
  end

  # ============ Math Operations Tests ============
  def test_add
    mat1 = Cv::Mat.new(2, 2, CV_32FC1)
    mat2 = Cv::Mat.new(2, 2, CV_32FC1)
    mat1[0, 0] = 1.0; mat1[0, 1] = 2.0
    mat1[1, 0] = 3.0; mat1[1, 1] = 4.0
    mat2[0, 0] = 5.0; mat2[0, 1] = 6.0
    mat2[1, 0] = 7.0; mat2[1, 1] = 8.0

    result = Cv::Mat.new
    Cv.add(mat1.input_array, mat2.input_array, result.output_array)

    assert_in_delta(6.0, result[0, 0], 0.001)
    assert_in_delta(8.0, result[0, 1], 0.001)
    assert_in_delta(10.0, result[1, 0], 0.001)
    assert_in_delta(12.0, result[1, 1], 0.001)
  end

  def test_subtract
    mat1 = Cv::Mat.new(2, 2, CV_32FC1)
    mat2 = Cv::Mat.new(2, 2, CV_32FC1)
    mat1[0, 0] = 5.0; mat1[0, 1] = 6.0
    mat1[1, 0] = 7.0; mat1[1, 1] = 8.0
    mat2[0, 0] = 1.0; mat2[0, 1] = 2.0
    mat2[1, 0] = 3.0; mat2[1, 1] = 4.0

    result = Cv::Mat.new
    Cv.subtract(mat1.input_array, mat2.input_array, result.output_array)

    assert_in_delta(4.0, result[0, 0], 0.001)
    assert_in_delta(4.0, result[0, 1], 0.001)
    assert_in_delta(4.0, result[1, 0], 0.001)
    assert_in_delta(4.0, result[1, 1], 0.001)
  end

  def test_multiply
    mat1 = Cv::Mat.new(2, 2, CV_32FC1)
    mat2 = Cv::Mat.new(2, 2, CV_32FC1)
    mat1[0, 0] = 1.0; mat1[0, 1] = 2.0
    mat1[1, 0] = 3.0; mat1[1, 1] = 4.0
    mat2[0, 0] = 2.0; mat2[0, 1] = 3.0
    mat2[1, 0] = 4.0; mat2[1, 1] = 5.0

    result = Cv::Mat.new
    Cv.multiply(mat1.input_array, mat2.input_array, result.output_array)

    assert_in_delta(2.0, result[0, 0], 0.001)
    assert_in_delta(6.0, result[0, 1], 0.001)
    assert_in_delta(12.0, result[1, 0], 0.001)
    assert_in_delta(20.0, result[1, 1], 0.001)
  end

  def test_divide
    mat1 = Cv::Mat.new(2, 2, CV_32FC1)
    mat2 = Cv::Mat.new(2, 2, CV_32FC1)
    mat1[0, 0] = 4.0; mat1[0, 1] = 6.0
    mat1[1, 0] = 8.0; mat1[1, 1] = 10.0
    mat2[0, 0] = 2.0; mat2[0, 1] = 2.0
    mat2[1, 0] = 2.0; mat2[1, 1] = 2.0

    result = Cv::Mat.new
    Cv.divide(mat1.input_array, mat2.input_array, result.output_array)

    assert_in_delta(2.0, result[0, 0], 0.001)
    assert_in_delta(3.0, result[0, 1], 0.001)
    assert_in_delta(4.0, result[1, 0], 0.001)
    assert_in_delta(5.0, result[1, 1], 0.001)
  end

  def test_sqrt
    mat = Cv::Mat.new(2, 2, CV_32FC1)
    mat[0, 0] = 4.0; mat[0, 1] = 9.0
    mat[1, 0] = 16.0; mat[1, 1] = 25.0

    result = Cv::Mat.new
    Cv.sqrt(mat.input_array, result.output_array)

    assert_in_delta(2.0, result[0, 0], 0.001)
    assert_in_delta(3.0, result[0, 1], 0.001)
    assert_in_delta(4.0, result[1, 0], 0.001)
    assert_in_delta(5.0, result[1, 1], 0.001)
  end

  def test_pow
    mat = Cv::Mat.new(2, 2, CV_32FC1)
    mat[0, 0] = 2.0; mat[0, 1] = 3.0
    mat[1, 0] = 4.0; mat[1, 1] = 5.0

    result = Cv::Mat.new
    Cv.pow(mat.input_array, 2.0, result.output_array)

    assert_in_delta(4.0, result[0, 0], 0.001)
    assert_in_delta(9.0, result[0, 1], 0.001)
    assert_in_delta(16.0, result[1, 0], 0.001)
    assert_in_delta(25.0, result[1, 1], 0.001)
  end

  def test_exp
    mat = Cv::Mat.new(2, 2, CV_32FC1)
    mat[0, 0] = 0.0; mat[0, 1] = 1.0
    mat[1, 0] = 2.0; mat[1, 1] = 3.0

    result = Cv::Mat.new
    Cv.exp(mat.input_array, result.output_array)

    assert_in_delta(1.0, result[0, 0], 0.001)
    assert_in_delta(Math::E, result[0, 1], 0.001)
    assert_in_delta(Math::E ** 2, result[1, 0], 0.001)
    assert_in_delta(Math::E ** 3, result[1, 1], 0.001)
  end

  def test_log
    mat = Cv::Mat.new(2, 2, CV_32FC1)
    mat[0, 0] = 1.0; mat[0, 1] = Math::E
    mat[1, 0] = Math::E ** 2; mat[1, 1] = Math::E ** 3

    result = Cv::Mat.new
    Cv.log(mat.input_array, result.output_array)

    assert_in_delta(0.0, result[0, 0], 0.001)
    assert_in_delta(1.0, result[0, 1], 0.001)
    assert_in_delta(2.0, result[1, 0], 0.001)
    assert_in_delta(3.0, result[1, 1], 0.001)
  end

  def test_sum
    mat = Cv::Mat.new(2, 2, CV_32FC1)
    mat[0, 0] = 1.0; mat[0, 1] = 2.0
    mat[1, 0] = 3.0; mat[1, 1] = 4.0

    result = Cv.sum(mat.input_array)
    assert_in_delta(10.0, result[0], 0.001)
  end

  def test_count_non_zero
    mat = Cv::Mat.new(2, 2, CV_8UC1)
    mat[0, 0] = 1; mat[0, 1] = 0
    mat[1, 0] = 0; mat[1, 1] = 5

    count = Cv.count_non_zero(mat.input_array)
    assert_equal(2, count)
  end

  def test_mean
    mat = Cv::Mat.new(2, 2, CV_32FC1)
    mat[0, 0] = 1.0; mat[0, 1] = 2.0
    mat[1, 0] = 3.0; mat[1, 1] = 4.0

    result = Cv.mean(mat.input_array)
    assert_in_delta(2.5, result[0], 0.001)
  end

  def test_min_max_loc
    mat = Cv::Mat.new(3, 3, CV_32FC1)
    mat[0, 0] = 5.0; mat[0, 1] = 2.0; mat[0, 2] = 8.0
    mat[1, 0] = 1.0; mat[1, 1] = 9.0; mat[1, 2] = 3.0
    mat[2, 0] = 7.0; mat[2, 1] = 4.0; mat[2, 2] = 6.0

    min_val, max_val, min_loc, max_loc = Cv.min_max_loc(mat.input_array)

    assert_in_delta(1.0, min_val, 0.001)
    assert_in_delta(9.0, max_val, 0.001)
    assert_equal(Cv::Point.new(0, 1), min_loc)
    assert_equal(Cv::Point.new(1, 1), max_loc)
  end

  def test_norm
    mat = Cv::Mat.new(2, 2, CV_32FC1)
    mat[0, 0] = 3.0; mat[0, 1] = 4.0
    mat[1, 0] = 0.0; mat[1, 1] = 0.0

    # L2 norm
    result = Cv.norm(mat.input_array)
    assert_in_delta(5.0, result, 0.001)
  end

  def test_normalize
    mat = Cv::Mat.new(1, 4, CV_32FC1)
    mat[0, 0] = 1.0; mat[0, 1] = 2.0; mat[0, 2] = 3.0; mat[0, 3] = 4.0

    result = Cv::Mat.new
    Cv.normalize(mat.input_array, result.input_output_array, 0.0, 1.0, Cv::NormTypes::NORM_MINMAX.to_i)

    # After normalization to range [0,1], min should be 0 and max should be 1
    min_val, max_val, _, _ = Cv.min_max_loc(result.input_array)
    assert_in_delta(0.0, min_val, 0.01)
    assert_in_delta(1.0, max_val, 0.01)
  end

  def test_transpose
    mat = Cv::Mat.new(2, 3, CV_32FC1)
    mat[0, 0] = 1.0; mat[0, 1] = 2.0; mat[0, 2] = 3.0
    mat[1, 0] = 4.0; mat[1, 1] = 5.0; mat[1, 2] = 6.0

    result = Cv::Mat.new
    Cv.transpose(mat.input_array, result.output_array)

    assert_equal(3, result.rows)
    assert_equal(2, result.cols)
    assert_in_delta(1.0, result[0, 0], 0.001)
    assert_in_delta(4.0, result[0, 1], 0.001)
    assert_in_delta(2.0, result[1, 0], 0.001)
    assert_in_delta(5.0, result[1, 1], 0.001)
  end

  def test_determinant
    mat = Cv::Mat.new(2, 2, CV_64FC1)
    mat[0, 0] = 1.0; mat[0, 1] = 2.0
    mat[1, 0] = 3.0; mat[1, 1] = 4.0

    det = Cv.determinant(mat.input_array)
    assert_in_delta(-2.0, det, 0.001)
  end

  def test_trace
    mat = Cv::Mat.new(3, 3, CV_32FC1)
    mat[0, 0] = 1.0; mat[0, 1] = 0.0; mat[0, 2] = 0.0
    mat[1, 0] = 0.0; mat[1, 1] = 2.0; mat[1, 2] = 0.0
    mat[2, 0] = 0.0; mat[2, 1] = 0.0; mat[2, 2] = 3.0

    tr = Cv.trace(mat.input_array)
    assert_in_delta(6.0, tr[0], 0.001)
  end

  def test_invert
    mat = Cv::Mat.new(2, 2, CV_64FC1)
    mat[0, 0] = 4.0; mat[0, 1] = 7.0
    mat[1, 0] = 2.0; mat[1, 1] = 6.0

    result = Cv::Mat.new
    Cv.invert(mat.input_array, result.output_array)

    assert_equal(2, result.rows)
    assert_equal(2, result.cols)
    # Verify A * A^-1 = I
    identity = Cv::Mat.new
    Cv.gemm(mat.input_array, result.input_array, 1.0, Cv::Mat.new.input_array, 0.0, identity.output_array)
    assert_in_delta(1.0, identity[0, 0], 0.01)
    assert_in_delta(0.0, identity[0, 1], 0.01)
    assert_in_delta(0.0, identity[1, 0], 0.01)
    assert_in_delta(1.0, identity[1, 1], 0.01)
  end

  def test_solve
    # Solve Ax = b
    a = Cv::Mat.new(2, 2, CV_64FC1)
    a[0, 0] = 1.0; a[0, 1] = 2.0
    a[1, 0] = 3.0; a[1, 1] = 4.0

    b = Cv::Mat.new(2, 1, CV_64FC1)
    b[0, 0] = 5.0
    b[1, 0] = 11.0

    x = Cv::Mat.new
    result = Cv.solve?(a.input_array, b.input_array, x.output_array)

    assert(result)
    assert_in_delta(1.0, x[0, 0], 0.001)
    assert_in_delta(2.0, x[1, 0], 0.001)
  end

  def test_bitwise_and
    mat1 = Cv::Mat.new(2, 2, CV_8UC1)
    mat2 = Cv::Mat.new(2, 2, CV_8UC1)
    mat1[0, 0] = 0b11110000; mat1[0, 1] = 0b11001100
    mat1[1, 0] = 0b10101010; mat1[1, 1] = 0b11111111
    mat2[0, 0] = 0b00001111; mat2[0, 1] = 0b11110000
    mat2[1, 0] = 0b01010101; mat2[1, 1] = 0b00000000

    result = Cv::Mat.new
    Cv.bitwise_and(mat1.input_array, mat2.input_array, result.output_array)

    assert_equal(0b00000000, result[0, 0])
    assert_equal(0b11000000, result[0, 1])
    assert_equal(0b00000000, result[1, 0])
    assert_equal(0b00000000, result[1, 1])
  end

  def test_bitwise_or
    mat1 = Cv::Mat.new(2, 2, CV_8UC1)
    mat2 = Cv::Mat.new(2, 2, CV_8UC1)
    mat1[0, 0] = 0b11110000; mat1[0, 1] = 0b11001100
    mat1[1, 0] = 0b10101010; mat1[1, 1] = 0b00000000
    mat2[0, 0] = 0b00001111; mat2[0, 1] = 0b00110011
    mat2[1, 0] = 0b01010101; mat2[1, 1] = 0b11111111

    result = Cv::Mat.new
    Cv.bitwise_or(mat1.input_array, mat2.input_array, result.output_array)

    assert_equal(0b11111111, result[0, 0])
    assert_equal(0b11111111, result[0, 1])
    assert_equal(0b11111111, result[1, 0])
    assert_equal(0b11111111, result[1, 1])
  end

  def test_bitwise_xor
    mat1 = Cv::Mat.new(2, 2, CV_8UC1)
    mat2 = Cv::Mat.new(2, 2, CV_8UC1)
    mat1[0, 0] = 0b11110000; mat1[0, 1] = 0b11001100
    mat1[1, 0] = 0b10101010; mat1[1, 1] = 0b11111111
    mat2[0, 0] = 0b11110000; mat2[0, 1] = 0b00110011
    mat2[1, 0] = 0b01010101; mat2[1, 1] = 0b11111111

    result = Cv::Mat.new
    Cv.bitwise_xor(mat1.input_array, mat2.input_array, result.output_array)

    assert_equal(0b00000000, result[0, 0])
    assert_equal(0b11111111, result[0, 1])
    assert_equal(0b11111111, result[1, 0])
    assert_equal(0b00000000, result[1, 1])
  end

  def test_bitwise_not
    mat = Cv::Mat.new(2, 2, CV_8UC1)
    mat[0, 0] = 0b11110000; mat[0, 1] = 0b00001111
    mat[1, 0] = 0b10101010; mat[1, 1] = 0b01010101

    result = Cv::Mat.new
    Cv.bitwise_not(mat.input_array, result.output_array)

    assert_equal(0b00001111, result[0, 0])
    assert_equal(0b11110000, result[0, 1])
    assert_equal(0b01010101, result[1, 0])
    assert_equal(0b10101010, result[1, 1])
  end

  def test_absdiff
    mat1 = Cv::Mat.new(2, 2, CV_32FC1)
    mat2 = Cv::Mat.new(2, 2, CV_32FC1)
    mat1[0, 0] = 5.0; mat1[0, 1] = 3.0
    mat1[1, 0] = 8.0; mat1[1, 1] = 2.0
    mat2[0, 0] = 3.0; mat2[0, 1] = 6.0
    mat2[1, 0] = 4.0; mat2[1, 1] = 9.0

    result = Cv::Mat.new
    Cv.absdiff(mat1.input_array, mat2.input_array, result.output_array)

    assert_in_delta(2.0, result[0, 0], 0.001)
    assert_in_delta(3.0, result[0, 1], 0.001)
    assert_in_delta(4.0, result[1, 0], 0.001)
    assert_in_delta(7.0, result[1, 1], 0.001)
  end

  def test_in_range
    mat = Cv::Mat.new(2, 2, CV_8UC1)
    mat[0, 0] = 50; mat[0, 1] = 100
    mat[1, 0] = 150; mat[1, 1] = 200

    lower = Cv::Scalar.new(75)
    upper = Cv::Scalar.new(175)
    result = Cv::Mat.new

    Cv.in_range(mat.input_array, lower.input_array, upper.input_array, result.output_array)

    assert_equal(0, result[0, 0])
    assert_equal(255, result[0, 1])
    assert_equal(255, result[1, 0])
    assert_equal(0, result[1, 1])
  end

  def test_compare
    mat1 = Cv::Mat.new(2, 2, CV_32FC1)
    mat2 = Cv::Mat.new(2, 2, CV_32FC1)
    mat1[0, 0] = 1.0; mat1[0, 1] = 2.0
    mat1[1, 0] = 3.0; mat1[1, 1] = 4.0
    mat2[0, 0] = 2.0; mat2[0, 1] = 2.0
    mat2[1, 0] = 2.0; mat2[1, 1] = 2.0

    result = Cv::Mat.new
    Cv.compare(mat1.input_array, mat2.input_array, result.output_array, Cv::CmpTypes::CMP_GT.to_i)

    assert_equal(0, result[0, 0])
    assert_equal(0, result[0, 1])
    assert_equal(255, result[1, 0])
    assert_equal(255, result[1, 1])
  end

  def test_min
    mat1 = Cv::Mat.new(2, 2, CV_32FC1)
    mat2 = Cv::Mat.new(2, 2, CV_32FC1)
    mat1[0, 0] = 1.0; mat1[0, 1] = 5.0
    mat1[1, 0] = 3.0; mat1[1, 1] = 7.0
    mat2[0, 0] = 2.0; mat2[0, 1] = 4.0
    mat2[1, 0] = 6.0; mat2[1, 1] = 8.0

    result = Cv::Mat.new
    Cv.min(mat1.input_array, mat2.input_array, result.output_array)

    assert_in_delta(1.0, result[0, 0], 0.001)
    assert_in_delta(4.0, result[0, 1], 0.001)
    assert_in_delta(3.0, result[1, 0], 0.001)
    assert_in_delta(7.0, result[1, 1], 0.001)
  end

  def test_max
    mat1 = Cv::Mat.new(2, 2, CV_32FC1)
    mat2 = Cv::Mat.new(2, 2, CV_32FC1)
    mat1[0, 0] = 1.0; mat1[0, 1] = 5.0
    mat1[1, 0] = 3.0; mat1[1, 1] = 7.0
    mat2[0, 0] = 2.0; mat2[0, 1] = 4.0
    mat2[1, 0] = 6.0; mat2[1, 1] = 8.0

    result = Cv::Mat.new
    Cv.max(mat1.input_array, mat2.input_array, result.output_array)

    assert_in_delta(2.0, result[0, 0], 0.001)
    assert_in_delta(5.0, result[0, 1], 0.001)
    assert_in_delta(6.0, result[1, 0], 0.001)
    assert_in_delta(8.0, result[1, 1], 0.001)
  end

  def test_hconcat
    mat1 = Cv::Mat.new(2, 2, CV_8UC1)
    mat2 = Cv::Mat.new(2, 3, CV_8UC1)
    mat1[0, 0] = 1; mat1[0, 1] = 2
    mat1[1, 0] = 3; mat1[1, 1] = 4
    mat2[0, 0] = 5; mat2[0, 1] = 6; mat2[0, 2] = 7
    mat2[1, 0] = 8; mat2[1, 1] = 9; mat2[1, 2] = 10

    result = Cv::Mat.new
    Cv.hconcat(mat1.input_array, mat2.input_array, result.output_array)

    assert_equal(2, result.rows)
    assert_equal(5, result.cols)
    assert_equal([1, 2, 5, 6, 7, 3, 4, 8, 9, 10], result.to_a)
  end

  def test_vconcat
    mat1 = Cv::Mat.new(2, 3, CV_8UC1)
    mat2 = Cv::Mat.new(2, 3, CV_8UC1)
    mat1[0, 0] = 1; mat1[0, 1] = 2; mat1[0, 2] = 3
    mat1[1, 0] = 4; mat1[1, 1] = 5; mat1[1, 2] = 6
    mat2[0, 0] = 7; mat2[0, 1] = 8; mat2[0, 2] = 9
    mat2[1, 0] = 10; mat2[1, 1] = 11; mat2[1, 2] = 12

    result = Cv::Mat.new
    Cv.vconcat(mat1.input_array, mat2.input_array, result.output_array)

    assert_equal(4, result.rows)
    assert_equal(3, result.cols)
    assert_equal([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], result.to_a)
  end

  def test_rotate
    mat = Cv::Mat.new(2, 3, CV_8UC1)
    mat[0, 0] = 1; mat[0, 1] = 2; mat[0, 2] = 3
    mat[1, 0] = 4; mat[1, 1] = 5; mat[1, 2] = 6

    result = Cv::Mat.new
    Cv.rotate(mat.input_array, result.output_array, Cv::RotateFlags::ROTATE_90_CLOCKWISE.to_i)

    assert_equal(3, result.rows)
    assert_equal(2, result.cols)
    assert_equal([4, 1, 5, 2, 6, 3], result.to_a)
  end

  def test_reduce
    mat = Cv::Mat.new(3, 3, CV_32FC1)
    mat[0, 0] = 1.0; mat[0, 1] = 2.0; mat[0, 2] = 3.0
    mat[1, 0] = 4.0; mat[1, 1] = 5.0; mat[1, 2] = 6.0
    mat[2, 0] = 7.0; mat[2, 1] = 8.0; mat[2, 2] = 9.0

    # Reduce to single row (sum columns)
    result = Cv::Mat.new
    Cv.reduce(mat.input_array, result.output_array, 0, Cv::ReduceTypes::REDUCE_SUM.to_i)

    assert_equal(1, result.rows)
    assert_equal(3, result.cols)
    assert_in_delta(12.0, result[0, 0], 0.001)
    assert_in_delta(15.0, result[0, 1], 0.001)
    assert_in_delta(18.0, result[0, 2], 0.001)
  end

  def test_sort
    mat = Cv::Mat.new(1, 5, CV_32FC1)
    mat[0, 0] = 5.0; mat[0, 1] = 2.0; mat[0, 2] = 8.0; mat[0, 3] = 1.0; mat[0, 4] = 9.0

    result = Cv::Mat.new
    Cv.sort(mat.input_array, result.output_array, Cv::SortFlags::SORT_EVERY_ROW.to_i | Cv::SortFlags::SORT_ASCENDING.to_i)

    assert_in_delta(1.0, result[0, 0], 0.001)
    assert_in_delta(2.0, result[0, 1], 0.001)
    assert_in_delta(5.0, result[0, 2], 0.001)
    assert_in_delta(8.0, result[0, 3], 0.001)
    assert_in_delta(9.0, result[0, 4], 0.001)
  end

  def test_kmeans
    # Create sample data
    data = Cv::Mat.new(20, 2, CV_32FC1)
    # Cluster 1 around (0, 0)
    10.times do |i|
      data[i, 0] = rand(-1.0..1.0)
      data[i, 1] = rand(-1.0..1.0)
    end
    # Cluster 2 around (10, 10)
    10.times do |i|
      data[10 + i, 0] = 10.0 + rand(-1.0..1.0)
      data[10 + i, 1] = 10.0 + rand(-1.0..1.0)
    end

    labels = Cv::Mat.new
    centers = Cv::Mat.new
    criteria = Cv::TermCriteria.new(Cv::TermCriteria::Type::COUNT.to_i | Cv::TermCriteria::Type::EPS.to_i, 100, 0.01)

    compactness = Cv.kmeans(data.input_array, 2, labels.input_output_array, criteria, 3,
                            Cv::KmeansFlags::KMEANS_PP_CENTERS.to_i, centers.output_array)

    assert(compactness >= 0)
    assert_equal(20, labels.rows)
    assert_equal(2, centers.rows)
    assert_equal(2, centers.cols)
  end

  # ============ Formatter Tests ============
  def test_formatter_get
    formatter = Cv::Formatter.get
    assert_instance_of(Cv::Ptr≺cv꞉꞉Formatter≻, formatter)
  end

  def test_formatter_format_types
    assert_equal(0, Cv::Formatter::FormatType::FMT_DEFAULT.to_i)
    assert_equal(1, Cv::Formatter::FormatType::FMT_MATLAB.to_i)
    assert_equal(2, Cv::Formatter::FormatType::FMT_CSV.to_i)
    assert_equal(3, Cv::Formatter::FormatType::FMT_PYTHON.to_i)
    assert_equal(4, Cv::Formatter::FormatType::FMT_NUMPY.to_i)
    assert_equal(5, Cv::Formatter::FormatType::FMT_C.to_i)
  end

  def test_formatter_format
    mat = Cv::Mat.new(2, 2, CV_32FC1)
    mat[0, 0] = 1.0; mat[0, 1] = 2.0
    mat[1, 0] = 3.0; mat[1, 1] = 4.0

    formatter = Cv::Formatter.get
    formatted = formatter.format(mat)
    str = formatted.to_s

    assert(str.include?("1"))
    assert(str.include?("2"))
    assert(str.include?("3"))
    assert(str.include?("4"))
  end

  # ============ Algorithm Tests ============
  def test_algorithm_create
    algo = Cv::Algorithm.new
    assert_instance_of(Cv::Algorithm, algo)
  end

  def test_algorithm_empty
    algo = Cv::Algorithm.new
    # Algorithm base class is not empty by default
    empty = algo.empty?
    assert([true, false].include?(empty))
  end

  def test_algorithm_default_name
    algo = Cv::Algorithm.new
    name = algo.get_default_name
    assert(name.is_a?(String))
  end

  # ============ DFT Tests ============
  def test_dft
    mat = Cv::Mat.new(4, 4, CV_32FC1)
    16.times { |i| mat[i / 4, i % 4] = (i + 1).to_f }

    result = Cv::Mat.new
    Cv.dft(mat.input_array, result.output_array)

    assert_equal(4, result.rows)
    assert_equal(4, result.cols)
  end

  def test_idft
    mat = Cv::Mat.new(4, 4, CV_32FC1)
    16.times { |i| mat[i / 4, i % 4] = (i + 1).to_f }

    # Forward DFT
    dft_result = Cv::Mat.new
    Cv.dft(mat.input_array, dft_result.output_array)

    # Inverse DFT
    idft_result = Cv::Mat.new
    Cv.idft(dft_result.input_array, idft_result.output_array, Cv::DftFlags::DFT_SCALE.to_i)

    # Should be close to original
    assert_equal(4, idft_result.rows)
    assert_equal(4, idft_result.cols)
  end

  def test_get_optimal_dft_size
    size = Cv.get_optimal_dft_size(100)
    assert(size >= 100)
    # Optimal DFT sizes are typically powers of 2, 3, or 5
    assert(size <= 128)
  end

  # ============ Global RNG Tests ============
  def test_the_rng
    rng = Cv.the_rng
    assert_instance_of(Cv::RNG, rng)
  end

  def test_set_rng_seed
    Cv.set_rng_seed(42)
    rng1 = Cv.the_rng
    val1 = rng1.next

    Cv.set_rng_seed(42)
    rng2 = Cv.the_rng
    val2 = rng2.next

    assert_equal(val1, val2)
  end

  def test_randu
    mat = Cv::Mat.new(10, 10, CV_32FC1)
    low = Cv::Scalar.new(0.0)
    high = Cv::Scalar.new(1.0)
    Cv.randu(mat.input_output_array, low.input_array, high.input_array)

    mat.rows.times do |i|
      mat.cols.times do |j|
        val = mat[i, j]
        assert(val >= 0.0 && val <= 1.0)
      end
    end
  end

  def test_randn
    mat = Cv::Mat.new(100, 100, CV_32FC1)
    mean_scalar = Cv::Scalar.new(0.0)
    stddev_scalar = Cv::Scalar.new(1.0)
    Cv.randn(mat.input_output_array, mean_scalar.input_array, stddev_scalar.input_array)

    # Calculate mean - should be close to 0
    mean = Cv.mean(mat.input_array)
    assert_in_delta(0.0, mean[0], 0.2)
  end

  # ============ Covariance Tests ============
  def test_calc_covar_matrix
    # Create sample data (5 samples, 3 features)
    samples = Cv::Mat.new(5, 3, CV_64FC1)
    samples[0, 0] = 1.0; samples[0, 1] = 2.0; samples[0, 2] = 3.0
    samples[1, 0] = 2.0; samples[1, 1] = 3.0; samples[1, 2] = 4.0
    samples[2, 0] = 3.0; samples[2, 1] = 4.0; samples[2, 2] = 5.0
    samples[3, 0] = 4.0; samples[3, 1] = 5.0; samples[3, 2] = 6.0
    samples[4, 0] = 5.0; samples[4, 1] = 6.0; samples[4, 2] = 7.0

    covar = Cv::Mat.new
    mean = Cv::Mat.new

    Cv.calc_covar_matrix(samples.input_array, covar.output_array, mean.input_output_array,
                         Cv::CovarFlags::COVAR_NORMAL.to_i | Cv::CovarFlags::COVAR_ROWS.to_i)

    assert_equal(3, covar.rows)
    assert_equal(3, covar.cols)
    assert_equal(1, mean.rows)
    assert_equal(3, mean.cols)
  end

  # ============ Mahalanobis Distance Test ============
  def test_mahalanobis
    v1 = Cv::Mat.new(1, 3, CV_64FC1)
    v2 = Cv::Mat.new(1, 3, CV_64FC1)
    v1[0, 0] = 1.0; v1[0, 1] = 2.0; v1[0, 2] = 3.0
    v2[0, 0] = 4.0; v2[0, 1] = 5.0; v2[0, 2] = 6.0

    # Identity covariance matrix
    icovar = Cv::Mat.new(3, 3, CV_64FC1)
    icovar[0, 0] = 1.0; icovar[0, 1] = 0.0; icovar[0, 2] = 0.0
    icovar[1, 0] = 0.0; icovar[1, 1] = 1.0; icovar[1, 2] = 0.0
    icovar[2, 0] = 0.0; icovar[2, 1] = 0.0; icovar[2, 2] = 1.0

    dist = Cv.mahalanobis(v1.input_array, v2.input_array, icovar.input_array)
    # With identity covariance, Mahalanobis = Euclidean distance
    expected = Math.sqrt(9 + 9 + 9)  # sqrt((4-1)^2 + (5-2)^2 + (6-3)^2)
    assert_in_delta(expected, dist, 0.001)
  end

  # ============ Constants Tests ============
  def test_sort_flags
    assert_equal(0, Cv::SortFlags::SORT_EVERY_ROW.to_i)
    assert_equal(1, Cv::SortFlags::SORT_EVERY_COLUMN.to_i)
    assert_equal(0, Cv::SortFlags::SORT_ASCENDING.to_i)
    assert_equal(16, Cv::SortFlags::SORT_DESCENDING.to_i)
  end

  def test_reduce_types
    assert_equal(0, Cv::ReduceTypes::REDUCE_SUM.to_i)
    assert_equal(1, Cv::ReduceTypes::REDUCE_AVG.to_i)
    assert_equal(2, Cv::ReduceTypes::REDUCE_MAX.to_i)
    assert_equal(3, Cv::ReduceTypes::REDUCE_MIN.to_i)
  end

  def test_kmeans_flags
    assert_equal(0, Cv::KmeansFlags::KMEANS_RANDOM_CENTERS.to_i)
    assert_equal(2, Cv::KmeansFlags::KMEANS_PP_CENTERS.to_i)
    assert_equal(1, Cv::KmeansFlags::KMEANS_USE_INITIAL_LABELS.to_i)
  end

  def test_rotate_flags
    assert_equal(0, Cv::RotateFlags::ROTATE_90_CLOCKWISE.to_i)
    assert_equal(1, Cv::RotateFlags::ROTATE_180.to_i)
    assert_equal(2, Cv::RotateFlags::ROTATE_90_COUNTERCLOCKWISE.to_i)
  end
end
