#[Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)
## Singleton Methods
[null](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html#acff8c258f3bcf0a7acc5268bdc7ef67b) -> [Cv::Cuda::Stream](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html#aa6434e2f5f29bd81406732b39951c246)()

[initialize](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html#aa6434e2f5f29bd81406732b39951c246)(cuda_flags: [Integer](https://docs.ruby-lang.org/en/master/Integer.html))

[initialize](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html#aa6434e2f5f29bd81406732b39951c246)(allocator: Cv::Ptr≺cv꞉꞉cuda꞉꞉GpuMat꞉꞉Allocator≻)


## Methods
[cuda_ptr](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html#add837d7fb8b082caa70d99ee548bbcb4) -> [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)

[enqueue_host_callback](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html#aaad28e33e26b9c19c8d0c87c1d6f733d)(callback: [Proc](https://docs.ruby-lang.org/en/master/Proc.html), user_data: [Rice::Pointer≺void≻](https://ruby-rice.github.io/4.x/ruby_api/pointer)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[query_if_complete?](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html#a9fab618395d42fa31987506e42fab1b4) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[wait_event](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html#a9e8a713f312a15ba00702d6f46867987)(event: [Cv::Cuda::Event](https://docs.opencv.org/4.x/d5/d38/classcv_1_1cuda_1_1Event.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[wait_for_completion](https://docs.opencv.org/4.x/d9/df3/classcv_1_1cuda_1_1Stream.html#a0e1d939503e8faad741ab584b720bca6) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


