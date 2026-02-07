#[Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)
## Singleton Methods
[create_from_angle_axis](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#af9dbf22a931a68bfe93229602235cd1f)(angle: [Float](https://docs.ruby-lang.org/en/master/Float.html), axis: [Cv::Vec3d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[create_from_euler_angles](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a2e64f41599dcd003532f65ab03a2b5b3)(angles: [Cv::Vec3d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html), euler_angles_type: [Cv::QuatEnum::EulerAnglesType](https://docs.opencv.org/4.x/d2/d53/classcv_1_1QuatEnum.html#abceb161bc29a481f2f55439ec723ee45)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[create_from_rot_mat](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a3f15aa205d922f22978017547fdcca0a)(r: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[create_from_rvec](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a0ab5aa43f4dbaa066b56c8b104cb37a3)(rvec: [Cv::InputArray](https://docs.opencv.org/4.x/d4/d32/classcv_1_1__InputArray.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[create_from_x_rot](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a2e825f32624d229abaa50f199f29d224)(theta: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[create_from_y_rot](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a10d7c4b49847599b75e2c9a448305307)(theta: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[create_from_z_rot](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a0d27a97a7dbcc3354f9196abd11d2197)(theta: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[inter_point](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#ab0937ff64d39f878721cba0b2d425f67)(q0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), q1: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), q2: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[lerp](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#abc47b8d47941679879a6ed8271ff035a)(q0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), q1: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), t: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[nlerp](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a96fd21e5b37443f64a9b00d6561f6063)(q0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), q1: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), t: [Float](https://docs.ruby-lang.org/en/master/Float.html), assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[slerp](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a8fe36e833958e845843ccbf05709523f)(q0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), q1: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), t: [Float](https://docs.ruby-lang.org/en/master/Float.html), assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e), direct_change: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[spline](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a201bf27bb9c78e61700fc8d6edb3354f)(q0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), q1: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), q2: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), q3: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), t: [Float](https://docs.ruby-lang.org/en/master/Float.html), assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[squad](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a838644cf97793cd43775ee0bf601cde8)(q0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), s0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), s1: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), q1: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), t: [Float](https://docs.ruby-lang.org/en/master/Float.html), assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e), direct_change: [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)


## Constructors
[initialize](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a40cb6433e291eac3b32622a3359078b9)()

[initialize](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a40cb6433e291eac3b32622a3359078b9)(w: [Float](https://docs.ruby-lang.org/en/master/Float.html), x: [Float](https://docs.ruby-lang.org/en/master/Float.html), y: [Float](https://docs.ruby-lang.org/en/master/Float.html), z: [Float](https://docs.ruby-lang.org/en/master/Float.html))

[initialize](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a40cb6433e291eac3b32622a3359078b9)(coeff: [Cv::Vec4d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html))


## Attributes
[w](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#af261492a691c1f0ae62708564b2f1021): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[x](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#ab2fbcb463f79a6b9de87c440e3c09dc7): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[y](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a7fec2f7d0b5928826dd359773643ecdc): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)

[z](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a6836f50dd74292ad753a51a906200af2): [Float](https://docs.ruby-lang.org/en/master/Float.html) (read/write)


## Methods
[\*](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a23fb72c7e5c3fc2e09827e8a2d3e02ff)(arg_0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[\+](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#aacf40ca4d13c186b85748c21ba0b076a)(arg_0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[\-](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#ac220e1453b8fdb21628f2db4bd85643c)(arg_0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

-@ -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[/](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#afa6684d45256bb23ff3efa68e566edc3)(arg_0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[/](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#afa6684d45256bb23ff3efa68e566edc3)(s: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[==](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a1ce2829104f53d64fc24c8b4510f69de)(arg_0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[\[\]](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a5e3c6bc6b495b4b7f6bb54c088d77dae)(n: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[\[\]](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a5e3c6bc6b495b4b7f6bb54c088d77dae)(n: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[\[\]=](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a5e3c6bc6b495b4b7f6bb54c088d77dae)(arg_0: [Integer](https://docs.ruby-lang.org/en/master/Integer.html), arg_1: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[assert_normal](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#ac21b01e626dc888bdf69d0f1f7d8b060)(eps: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [NilClass](https://docs.ruby-lang.org/en/master/NilClass.html)

[assign_divide](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#ad35d0c9f759410b4aa4d18b7994cd400)(arg_0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[assign_divide](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#ad35d0c9f759410b4aa4d18b7994cd400)(s: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[assign_minus](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a561bd7289ecdb6b26ac7afbf12d571ab)(arg_0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[assign_multiply](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a42a91a8316dbf40a26817723916d2cb5)(arg_0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[assign_multiply](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a42a91a8316dbf40a26817723916d2cb5)(s: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[assign_plus](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a67b0a3009e6c01b4cd1277b0a9dc4139)(arg_0: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[at](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#aee1c99898d16d0954135b8432980004b)(index: [Integer](https://docs.ruby-lang.org/en/master/Integer.html)) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[conjugate](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a1244885e306d3474a0588267434f8edd) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[cos](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#aa6af67876fdb0d0513d7e5857da7722f) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[cosh](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a068171935c99beda2828713e8a37e8d1) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[cross_product](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a625200e06ce00174775a0f01eca60ac6)(q: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[dot](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a06faebf4b5163be987dcfd4aa463bfed)(q: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[exp](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a3ada6692a495cbd3539baaeb80245c6f) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[get_angle](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a305053004bb816fe41062fcb2fd0f6d7)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[get_axis](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a373084accc615303ceed2e940a434caa)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Vec3d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)

[inv](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#ad10983de973d03a9e1e302d077b7a984)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[log](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#aa6b5de55cb24db25d7aa98300f958c01)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[norm](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#abf08767595e119eee2f101420f7b9c24) -> [Float](https://docs.ruby-lang.org/en/master/Float.html)

[normal?](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a5c555f37ea9df65d7486ca234cc57c46)(eps: [Float](https://docs.ruby-lang.org/en/master/Float.html)) -> [TrueClass](https://docs.ruby-lang.org/en/master/TrueClass.html)

[normalize](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a71f77ce18f1f6c1668b1bacbe8c713fc) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[power](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a7ff361fd75bfe101dcc5703e0068e694)(x: [Float](https://docs.ruby-lang.org/en/master/Float.html), assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[power](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a7ff361fd75bfe101dcc5703e0068e694)(q: [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html), assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[sin](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#ac5a9ff28beec664f250ab515e20b2878) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[sinh](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a5ac30d3bde8eefe94ff2ed9a1bab4634) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[sqrt](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a50b4888d807b61d9b402089d6c2e5191)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[tan](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a4427a6c8348f9835cd1bc3066fd60329) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[tanh](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#aa81811302533efb7248c5b9aa2ef884c) -> [Cv::Quatd](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html)

[to_euler_angles](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a5fa902f27a084399249384db77e03d9b)(euler_angles_type: [Cv::QuatEnum::EulerAnglesType](https://docs.opencv.org/4.x/d2/d53/classcv_1_1QuatEnum.html#abceb161bc29a481f2f55439ec723ee45)) -> [Cv::Vec3d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)

[to_rot_mat3x3](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#ad23d13ffd008f0803cdaa3fb56ec15f9)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Matx33d](https://docs.opencv.org/4.x/de/de1/classcv_1_1Matx.html)

[to_rot_mat4x4](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a430eacc7bab6e36d937667d5402afd7e)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Matx44d](https://docs.opencv.org/4.x/de/de1/classcv_1_1Matx.html)

[to_rot_vec](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#aed326a6191db7e129864a74c0a1f6cde)(assume_unit: [Cv::QuatAssumeType](https://docs.opencv.org/4.x/d8/d07/group__core__quaternion.html#ga935c8234953e2a2c8557c019ad8d509e)) -> [Cv::Vec3d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)

[to_vec](https://docs.opencv.org/4.x/da/d4a/classcv_1_1Quat.html#a6110ac68734531e33a7dceede9ccc048) -> [Cv::Vec4d](https://docs.opencv.org/4.x/d6/dcf/classcv_1_1Vec.html)


