#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-

# LBPH sample in opencv-ruby, equivalent to http://docs.opencv.org/trunk/_downloads/facerec_lbph.cpp
# See http://docs.opencv.org/trunk/modules/contrib/doc/facerec/facerec_tutorial.html
require 'opencv'
include OpenCV

def read_csv(filename, sepalator = ';')
  images = []
  labels = []
  open(filename, 'r') { |f|
    f.each { |line|
      path, label = line.chomp.split(sepalator)
      images << CvMat.load(path, CV_LOAD_IMAGE_GRAYSCALE)
      labels << label.to_i
    }
  }

  [images, labels]
end

# Check for valid command line arguments, print usage
# if no arguments were given.
if ARGV.size < 1
  puts "usage: ruby #{__FILE__} <csv.ext>"
  exit 1
end

# Get the path to your CSV.
fn_csv = ARGV.shift

# Read in the data. This can fail if no valid
# input filename is given.
images, labels = read_csv(fn_csv);

# Quit if there are not enough images for this demo.
raise 'This demo needs at least 2 images to work. Please add more images to your data set!' if images.size <= 1

# Get the height from the first image. We'll need this
# later in code to reshape the images to their original size:
height = images[0].rows;

# The following lines simply get the last images from
# your dataset and remove it from the vector. This is
# done, so that the training data (which we learn the
# cv::FaceRecognizer on) and the test data we test
# the model with, do not overlap.
test_sample = images.pop
test_label = labels.pop

# The following lines create an LBPH model for
# face recognition and train it with the images and
# labels read from the given CSV file.
# 
# The LBPHFaceRecognizer uses Extended Local Binary Patterns
# (it's probably configurable with other operators at a later
# point), and has the following default values
# 
#      radius = 1
#      neighbors = 8
#      grid_x = 8
#      grid_y = 8
# 
# So if you want a LBPH FaceRecognizer using a radius of
# 2 and 16 neighbors, call the factory method with:
# 
#      LBPH.new(2, 16);
# 
# And if you want a threshold (e.g. 123.0) call it with its default values:
# 
#      LBPH.new(1,8,8,8,123.0)
# 
model = LBPH.new
model.train(images, labels)

# The following line predicts the label of a given test image:
predicted_label, predicted_confidence = model.predict(test_sample)

# To get the confidence of a prediction call the model with:
# 
#      predicted_label = -1;
#      confidence = 0.0;
#      model.predict(test_sample, predicted_label, confidence)
# 
puts "Predicted class: #{predicted_label} / Actual class: #{test_label}"

# Sometimes you'll need to get/set internal model data,
# which isn't exposed by the public FaceRecognizer.
# Since each FaceRecognizer is derived from a Algorithm,
# you can query the data.
#
# First we'll use it to set the threshold of the FaceRecognizer
# to 0.0 without retraining the model. This can be useful if
# you are evaluating the model:
model.set_double('threshold', 0.0);

# Now the threshold of this model is set to 0.0. A prediction
# now returns -1, as it's impossible to have a distance below it
predicted_label, predicted_confidence = model.predict(test_sample)
puts "Predicted class = #{predicted_label}"

# Show some informations about the model, as there's no cool
# Model data to display as in Eigenfaces/Fisherfaces.
# Due to efficiency reasons the LBP images are not stored
# within the model:
puts 'Model Information:'
model_info = "\tLBPH(radius=#{model.get_int('radius')}, neighbors=#{model.get_int('neighbors')}, grid_x=#{model.get_int('grid_x')}, grid_y=#{model.get_int('grid_y')}, threshold=#{model.get_double('threshold')})"
puts model_info

# We could get the histograms for example:
histgrams = model.get_matvector('histograms');

# But should I really visualize it? Probably the length is interesting:
puts "Size of the histograms: #{histgrams[0].dims.reduce(&:*)}"

