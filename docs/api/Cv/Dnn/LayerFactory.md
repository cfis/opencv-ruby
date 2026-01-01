#LayerFactory
## Singleton Methods
create_layer_instance(type: [String](https://docs.ruby-lang.org/en/master/String.html), params: Cv::Dnn::LayerParams) -> Cv::Ptr≺cv꞉꞉dnn꞉꞉dnn4V20241223꞉꞉Layer≻

is_layer_registered(type: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

register_layer(type: [String](https://docs.ruby-lang.org/en/master/String.html), constructor: [Proc](https://docs.ruby-lang.org/en/master/Proc.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

unregister_layer(type: [String](https://docs.ruby-lang.org/en/master/String.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)


