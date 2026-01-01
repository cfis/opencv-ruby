#Cv::Ogl
## Singleton Methods
convert_from_gl_texture_2d(texture: [Cv::Ogl::Texture2D](https://docs.opencv.org/4.x/d5/ddf/classcv_1_1ogl_1_1Texture2D.html), dst: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

convert_to_gl_texture_2d(src: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), texture: [Cv::Ogl::Texture2D](https://docs.opencv.org/4.x/d5/ddf/classcv_1_1ogl_1_1Texture2D.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

map_gl_buffer(buffer: [Cv::Ogl::Buffer](https://docs.opencv.org/4.x/d3/d68/classcv_1_1ogl_1_1Buffer.html), access_flags: [Cv::AccessFlag](https://docs.opencv.org/4.x/dc/d84/group__core__basic.html#ga6226c29c7b0e7bda7aff72e96ba8e1df)) -> [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)

[render](https://docs.opencv.org/4.x/d2/d3c/group__core__opengl.html#ga090c1f371c37a575dea8b5c6371aec70)(arr: [Cv::Ogl::Arrays](https://docs.opencv.org/4.x/d6/d53/classcv_1_1ogl_1_1Arrays.html), mode: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), color: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[render](https://docs.opencv.org/4.x/d2/d3c/group__core__opengl.html#ga090c1f371c37a575dea8b5c6371aec70)(tex: [Cv::Ogl::Texture2D](https://docs.opencv.org/4.x/d5/ddf/classcv_1_1ogl_1_1Texture2D.html), wnd_rect: [Cv::Rect2d](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html), tex_rect: [Cv::Rect2d](https://docs.opencv.org/4.x/d2/d44/classcv_1_1Rect__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[render](https://docs.opencv.org/4.x/d2/d3c/group__core__opengl.html#ga090c1f371c37a575dea8b5c6371aec70)(arr: [Cv::Ogl::Arrays](https://docs.opencv.org/4.x/d6/d53/classcv_1_1ogl_1_1Arrays.html), indices: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), mode: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), color: [Cv::Scalar](https://docs.opencv.org/4.x/d1/da0/classcv_1_1Scalar__.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

unmap_gl_buffer(u: [Cv::UMat](https://docs.opencv.org/4.x/d7/d45/classcv_1_1UMat.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


