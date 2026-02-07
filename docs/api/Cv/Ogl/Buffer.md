#Buffer
## Singleton Methods
unbind(target: [Cv::Ogl::Buffer::Target](https://docs.opencv.org/4.x/d3/d68/classcv_1_1ogl_1_1Buffer.html#a830568a629457171cb07918537ec66be)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


## Constructors
initialize()

initialize(arr: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), target: [Cv::Ogl::Buffer::Target](https://docs.opencv.org/4.x/d3/d68/classcv_1_1ogl_1_1Buffer.html#a830568a629457171cb07918537ec66be), auto_release: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html))

initialize(asize: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), atype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), abuf_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), auto_release: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html))

initialize(asize: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), atype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), target: [Cv::Ogl::Buffer::Target](https://docs.opencv.org/4.x/d3/d68/classcv_1_1ogl_1_1Buffer.html#a830568a629457171cb07918537ec66be), auto_release: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html))

initialize(arows: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), acols: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), atype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), abuf_id: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), auto_release: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html))

initialize(arows: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), acols: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), atype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), target: [Cv::Ogl::Buffer::Target](https://docs.opencv.org/4.x/d3/d68/classcv_1_1ogl_1_1Buffer.html#a830568a629457171cb07918537ec66be), auto_release: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html))


## Methods
bind(target: [Cv::Ogl::Buffer::Target](https://docs.opencv.org/4.x/d3/d68/classcv_1_1ogl_1_1Buffer.html#a830568a629457171cb07918537ec66be)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

buf_id -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

channels -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

clone(target: [Cv::Ogl::Buffer::Target](https://docs.opencv.org/4.x/d3/d68/classcv_1_1ogl_1_1Buffer.html#a830568a629457171cb07918537ec66be), auto_release: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> Cv::Ogl::Buffer

cols -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

copy_from(arr: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), target: [Cv::Ogl::Buffer::Target](https://docs.opencv.org/4.x/d3/d68/classcv_1_1ogl_1_1Buffer.html#a830568a629457171cb07918537ec66be), auto_release: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

copy_from(arr: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html), target: [Cv::Ogl::Buffer::Target](https://docs.opencv.org/4.x/d3/d68/classcv_1_1ogl_1_1Buffer.html#a830568a629457171cb07918537ec66be), auto_release: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

copy_to(arr: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html), stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

copy_to(arr: [Cv::OutputArray](https://docs.opencv.org/4.x/d2/d9e/classcv_1_1__OutputArray.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

create(asize: [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html), atype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), target: [Cv::Ogl::Buffer::Target](https://docs.opencv.org/4.x/d3/d68/classcv_1_1ogl_1_1Buffer.html#a830568a629457171cb07918537ec66be), auto_release: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

create(arows: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), acols: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), atype: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), target: [Cv::Ogl::Buffer::Target](https://docs.opencv.org/4.x/d3/d68/classcv_1_1ogl_1_1Buffer.html#a830568a629457171cb07918537ec66be), auto_release: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

depth -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

elem_size -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

elem_size1 -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

empty? -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

map_device -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

map_device(stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [Cv::Cuda::GpuMat](https://docs.opencv.org/4.x/d0/d60/classcv_1_1cuda_1_1GpuMat.html)

map_host(access: [Cv::Ogl::Buffer::Access](https://docs.opencv.org/4.x/d3/d68/classcv_1_1ogl_1_1Buffer.html#a6b2a295dc840db8b6728db2f3a439d6e)) -> [Cv::Mat](https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html)

release -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

rows -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

set_auto_release(flag: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

size -> [Cv::Size2i](https://docs.opencv.org/4.x/d6/d50/classcv_1_1Size__.html)

type -> [Integer](https://docs.ruby-lang.org/en/master/Integer.html)

unmap_device -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

unmap_device(stream: [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

unmap_host -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


