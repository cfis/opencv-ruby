#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class VecTest < OpenCVTestCase
  CLASSES = [Cv::Vec2b, Cv::Vec3b, Cv::Vec4b,
             Cv::Vec2s, Cv::Vec3s, Cv::Vec4s,
             Cv::Vec2w, Cv::Vec3w, Cv::Vec4w,
             Cv::Vec2f, Cv::Vec3f, Cv::Vec4f, Cv::Vec6f,
             Cv::Vec2d, Cv::Vec3d, Cv::Vec4d, Cv::Vec6d,
             Cv::Vec2i, Cv::Vec3i, Cv::Vec4i, Cv::Vec6i, Cv::Vec8i,
             Cv::Vec2l]

  def test_initialize_binary
    alphabet = ("A".."Z").to_a
    [Cv::Vec2b, Cv::Vec3b, Cv::Vec4b].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i
      # Get some characters based on the size
      characters = alphabet[0..size-1].join("")

      # Send in unsigned characters
      buffer = Rice::Buffer≺unsigned char≻.new(characters)
      vector = klass.new(buffer)
      assert_equal(characters.bytes, vector.to_a)

      # And now the same but bytes
      buffer = Rice::Buffer≺unsigned char≻.new(characters.bytes)
      vector = klass.new(buffer)
      assert_equal(characters.bytes, vector.to_a)
    end
  end

  def test_initialize_signed_short
    [Cv::Vec2s, Cv::Vec3s, Cv::Vec4s].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      values = size.times.map do
        rand(-128..127)
      end

      buffer = Rice::Buffer≺short≻.new(values)
      vector = klass.new(buffer)
      assert_equal(values, vector.to_a)
    end
  end

  def test_initialize_unsigned_short
    [Cv::Vec2w, Cv::Vec3w, Cv::Vec4w].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      values = size.times.map do
        rand(0..255)
      end

      buffer = Rice::Buffer≺unsigned short≻.new(values)
      vector = klass.new(buffer)
      assert_equal(values, vector.to_a)
    end
  end

  def test_initialize_float
    [Cv::Vec2f, Cv::Vec3f, Cv::Vec4f, Cv::Vec6f].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      values = size.times.map do
        rand(1.0e-38..1.0e38)
      end

      vector = klass.new(*values)
      assert_in_delta_array(values, vector.to_a, values.max/1_000_000)
    end
  end

  def test_initialize_double
    [Cv::Vec2d, Cv::Vec3d, Cv::Vec4d, Cv::Vec6d].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      values = size.times.map do
        rand(-Float::MAX..Float::MAX)
      end

      vector = klass.new(*values)
      assert_in_delta_array(values, vector.to_a, 0.000001)
    end
  end

  def test_initialize_signed_integer
    [Cv::Vec2i, Cv::Vec3i, Cv::Vec4i, Cv::Vec6i, Cv::Vec8i].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      # Get some random integers that are 0 to 255
      values = size.times.map do
        rand(-2_147_483_648..2_147_483_647)
      end

      vector = klass.new(*values)
      assert_equal(values, vector.to_a)
    end
  end

  def test_initialize_signed_long
    [Cv::Vec2l].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      # Get some random integers that are 0 to 255
      values = size.times.map do
        rand(-9_223_372_036_854_775_808..9_223_372_036_854_775_807)
      end

      vector = klass.new(*values)
      assert_equal(values, vector.to_a)
    end
  end

  def test_initialize_individual_values
    klasses = [Cv::Vec1i, Cv::Vec2i, Cv::Vec3i, Cv::Vec4i, Cv::Vec6i, Cv::Vec8i]
    array = (1..8).to_a

    klasses.each.with_index do |vec_klass, i|
      subarray = array.slice(0..vec_klass::Rows - 1)
      vec = vec_klass.new(*subarray)
      assert_equal(subarray, vec.to_a)
    end
  end

  def test_all
    vector = Cv::Vec4i.all(5)
    assert_equal([5, 5, 5, 5], vector.to_a)

    vector = Cv::Vec4f.all(4.44)
    assert_in_delta_array([4.44, 4.44, 4.44, 4.44], vector.to_a, 0.0001)
  end

  def test_ones
    vector = Cv::Vec3s.ones
    assert_equal([1, 1, 1], vector.to_a)

    vector = Cv::Vec4f.ones
    assert_in_delta_array([1.0, 1.0, 1.0, 1.0], vector.to_a, 0.0001)
  end

  def test_clone
    vector_original = Cv::Vec4f.new(1.1, 2.2, 3.3, 4.4)
    vector_clone = vector_original.clone
    refute_same(vector_original, vector_clone)
    assert_equal(vector_original.to_a, vector_clone.to_a)
  end

  def test_aref
    vector = Cv::Vec4f.new(10, 20.2, 0.31, 40)
    assert_in_delta(10, vector[0])
    assert_in_delta(20.2, vector[1])
    assert_in_delta(0.31, vector[2])
    assert_in_delta(40, vector[3])
  end

  def test_destructure
    vector = Cv::Vec4f.new(7.7, 8.8, 9.9, 10.10)
    a, b, c, d = vector
    assert_in_delta(7.7, vector[0])
    assert_in_delta(8.8, vector[1])
    assert_in_delta(9.9, vector[2])
    assert_in_delta(10.10, vector[3])
  end

  def test_equal
    vec1 = Cv::Vec2i.new(3, 4)
    vec2 = Cv::Vec2i.new(3, 4)
    vec3 = Cv::Vec2i.new(4, 5)
    vec4 = Cv::Vec2f.new(4, 5)
    assert_equal(vec1, vec2)
    refute_equal(vec1, vec3)

    assert_raises(TypeError) do
      vec3 == vec4
    end

    assert_raises(TypeError) do
      vec3.eql?(vec4)
    end

    refute(vec3.equal?(vec4))
  end

  def test_aset
    vector = Cv::Vec4f.new

    expected = [10, 20, 30.3, 0.4]
    expected.each.with_index do |x, i|
      vector[i] = x
    end
    assert_in_delta_array(expected, vector.to_a)
  end

  def test_add
    vec1 = Cv::Vec4f.new(10, 20, 30, 40)
    vec2 = Cv::Vec4f.new(2, 4, 6, 8)

    matx1 = vec1 + vec2
    assert_equal([12, 24, 36, 48], matx1.each.to_a, 0.01)
  end

  def test_sub
    vec1 = Cv::Vec4i.new(10, 20, 30, 40)
    vec2 = Cv::Vec4i.new(2, 4, 6, 8)

    matx1 = vec1 - vec2
    assert_equal([8, 16, 24, 32], matx1.each.to_a, 0.01)
  end

  def test_to_a
    vec1 = Cv::Vec4i.new(10, 20, 30, 40)
    assert_equal([10, 20, 30, 40], vec1.to_a)

    vec2 = Cv::Vec4f.new(0.1, 0.2, 0.3, 0.4)
    assert_in_delta_array([0.1, 0.2, 0.3, 0.4], vec2.to_a, 0.01)
  end

  def test_to_s
    assert_equal("<Cv::Vec4i:[10, 20, 30, 40]>", Cv::Vec4i.new(10, 20, 30, 40).to_s)
    assert_equal("<Cv::Vec4f:[0.1, 0.2, 0.3, 0.4]>", Cv::Vec4f.new(0.1, 0.2, 0.3, 0.4).to_s)
  end
end
