#[DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)
## Singleton Methods
[create_from_affine3](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#aa9a70877a60df4e0b1497c6962e4acd7)(r: [Cv::Affine3d](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[create_from_mat](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a4f7b257b8452e3b1b679bb7cdf4aa413)(_r: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[create_from_pitch](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#ae02a61313b52aff85ca03181ad0a06a9)(angle: [Float](https://docs.ruby-lang.org/en/master/Float.html), d: [Float](https://docs.ruby-lang.org/en/master/Float.html), axis: [Cv::Vec3d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html), moment: [Cv::Vec3d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[dqblend](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a08a7d1d9532dacb6c305a67b0f4792c8)(q1: [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html), q2: [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html), t: [Float](https://docs.ruby-lang.org/en/master/Float.html), assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[gdqblend](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a426a2313b560d70c19c7085c4f66af79)(dualquat: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), weights: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html), assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[sclerp](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#aa946c25787313a8dcdebfa7315ea99eb)(q1: [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html), q2: [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html), t: [Float](https://docs.ruby-lang.org/en/master/Float.html), direct_change: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html), assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a46806b056f582b8a01376a9e4f206c98)()

[initialize](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a46806b056f582b8a01376a9e4f206c98)(w: [Float](https://docs.ruby-lang.org/en/master/Float.html), x: [Float](https://docs.ruby-lang.org/en/master/Float.html), y: [Float](https://docs.ruby-lang.org/en/master/Float.html), z: [Float](https://docs.ruby-lang.org/en/master/Float.html), w_: [Float](https://docs.ruby-lang.org/en/master/Float.html), x_: [Float](https://docs.ruby-lang.org/en/master/Float.html), y_: [Float](https://docs.ruby-lang.org/en/master/Float.html), z_: [Float](https://docs.ruby-lang.org/en/master/Float.html))

[initialize](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a46806b056f582b8a01376a9e4f206c98)(q: [Cv::Vec8d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html))


## Attributes
[w](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#aea1571d04e7a8413d694c86ccb65a4ca): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[w_](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a26df9a4cba469c1308b777b2a80d380c): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[x](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a85106b84b92f42e36c550865935377a0): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[x_](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a5d5a3b9f89b32fc12ebd6f75f2392221): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[y](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a0d5bdf3d341452e406d2ab9878e435a9): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[y_](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a0112c38fdb2e93d6bade42a1234447d5): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[z](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#ad26885c85d72c4b9bc42d229b76e3790): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[z_](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a38eccd00b69906fa7c72a7a81b8f5c0e): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)


## Methods
[\+](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a81e8fa7039d633304fd04d1e61c17b85)(arg_0: [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[\-](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#adc0e0d4680064be4faeae36e19c62e66)(arg_0: [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

-@ -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[/](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a0f1789f186bcb3116822ccc7300f610f)(arg_0: [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[/](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a0f1789f186bcb3116822ccc7300f610f)(s: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[==](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a4019b91de3aeee1d7aa49f69564111aa)(arg_0: [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[assign_minus](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#ae80f34dd4e834d1346ab05143435de07)(arg_0: [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[assign_plus](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a7333ce03d1cb13eb7c501fbd6e987fb2)(arg_0: [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[conjugate](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a200969671d846d9b0e1015ac69e8fa45) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[dot](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a167be7d41482406ede53614790bccaf0)(p: [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[exp](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a95d25e9e29be8873f41dd7b4813f4e25) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[get_dual_part](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a9789d8c6fc93a6f74233527f70154c36) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[get_real_part](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a70d0ff6ef9baeff5ef1b7e4915650a7c) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[get_rotation](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#ab1511be26b63684751babd658b008f38)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[get_translation](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#abaec08131f1d51b1068a7ca629c5f394)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Vec3d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)

[inv](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#ac170ce9abec6a1c16c1840f6249579ab)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[log](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#ae3abb4637a1284045039311758ec95a3)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[norm](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#ab372a7f26f9733ae3e0fc07e3dec3f16) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[normalize](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a9ab10d995f216d98ff6023e5be389822) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[power](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a116da0afad3a6efa7fbc8ce427b341d8)(q: [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html), assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[power](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a116da0afad3a6efa7fbc8ce427b341d8)(t: [Float](https://docs.ruby-lang.org/en/master/Float.html), assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::DualQuatd](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html)

[to_affine3](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a7d112dd462cb8e6069cdf1915700d0ca)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Affine3d](https://docs.opencv.org/4.x/dd/d99/classcv_1_1Affine3.html)

[to_mat](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a8c4d7d9c3bed88b00fb2eca6cb2e9130)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Matx44d](https://docs.opencv.org/4.x/de/de1/classcv_1_1Matx.html)

[to_vec](https://docs.opencv.org/4.x/d4/db4/classcv_1_1DualQuat.html#a6b9f552661817db24d29778a32e4dcf1) -> [Cv::Vec8d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)


