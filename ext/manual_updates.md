# Manual Include Directives

When regenerating bindings with ruby-bindgen, each of the following sections must be applied completely. This is a plan previously created by Claude. You do not need to plan again. Just execute the steps in this file.

**IMPORTANT FOR AI ASSISTANTS:** After ANY regeneration, systematically check EVERY file listed in this document and apply missing changes. Do not wait for the user to specify which files - iterate through all entries below and verify each one.

## Manual Includes
First add the following `#include` directives. These are required for compilation but are not automatically generated. They must be applied in the correct order within a file.


| File                                                       | Manual Includes                                                          |
|------------------------------------------------------------|--------------------------------------------------------------------------|
| `opencv2/core/bindings_utils-rb.cpp`                       | `<opencv2/core.hpp>`                                                     |
| `opencv2/core/check-rb.cpp`                                | `<opencv2/core/types.hpp>`                                               |
| `opencv2/core/cvstd.inl-rb.cpp`                           | `<opencv2/core/core.hpp>`, `<opencv2/core/traits.hpp>`, `<opencv2/core/mat.hpp>`, `<opencv2/core/matx.hpp>` |
| `opencv2/core/detail/async_promise-rb.cpp`                 | `<opencv2/core.hpp>`, `<opencv2/core/detail/exception_ptr.hpp>`          |
| `opencv2/core/detail/dispatch_helper.impl-rb.cpp`          | `<opencv2/opencv.hpp>`                                                   |
| `opencv2/core/mat-rb.cpp`                                  | `<opencv2/core/cuda.hpp>`, `<opencv2/core/opengl.hpp>`, `"types-rb.hpp"`, `"refinements/mat-iterators.hpp"` |
| `opencv2/core/mat.inl-rb.cpp`                              | `<opencv2/core/mat.hpp>`                                                 |
| `opencv2/core/matx-rb.cpp`                                 | `<opencv2/core.hpp>`                                                     |
| `opencv2/core/ocl_genbase-rb.cpp`                          | `<opencv2/core/ocl.hpp>`                                                 |
| `opencv2/core/opengl-rb.cpp`                               | `<opencv2/core/cuda.hpp>`                                                |
| `opencv2/core/operations-rb.cpp`                           | `<opencv2/core/core.hpp>`, `"mat-rb.hpp"`      |
| `opencv2/core/parallel/backend/parallel_for.openmp-rb.cpp` | `<string>`                                                               |
| `opencv2/core/parallel/backend/parallel_for.tbb-rb.cpp`    | `<string>`                                                               |
| `opencv2/core/parallel/parallel_backend-rb.cpp`            | `<string>`, `<memory>`                                                   |
| `opencv2/core/saturate-rb.cpp`                             | `<algorithm>`, `<climits>`                                               |
| `opencv2/core/softfloat-rb.cpp`                            | `<opencv2/opencv.hpp>`                                                   |
| `opencv2/core/utils/filesystem-rb.cpp`                     | `<opencv2/core/core.hpp>`                                                |
| `opencv2/core/utils/logger-rb.cpp`                         | `<opencv2/core.hpp>`                                                     |
| `opencv2/core/utils/logger.defines-rb.cpp`                 | `<opencv2/opencv.hpp>`                                                   |
| `opencv2/core/utils/trace-rb.cpp`                          | `<opencv2/core/base.hpp>`                                                |
| `opencv2/flann/dist-rb.cpp`                                | `<opencv2/core/base.hpp>`                                                |
| `opencv2/flann/dynamic_bitset-rb.cpp`                      | `<vector>`, `<opencv2/core/base.hpp>`                                    |
| `opencv2/flann/flann_base-rb.cpp`                          | `<opencv2/core/base.hpp>`, `<opencv2/flann/defines.h>`                   |
| `opencv2/flann/lsh_table-rb.cpp`                           | `<opencv2/core.hpp>`, `<vector>`                                         |
| `opencv2/imgproc/bindings-rb.cpp`                          | `<opencv2/core/mat.hpp>`, `<opencv2/imgproc.hpp>`                        |
| `opencv2/imgproc/detail/gcgraph-rb.cpp`                    | `<opencv2/core.hpp>`                                                     |
| `opencv2/ml/ml.inl-rb.cpp`                                | `<opencv2/core/cvdef.h>`, `<opencv2/core/operations.hpp>`                |
| `opencv2/flann/ground_truth-rb.cpp`                        | `<opencv2/core/base.hpp>`                                                |
| `opencv2/flann/heap-rb.cpp`                                | `<opencv2/core/base.hpp>`                                                |
| `opencv2/flann/random-rb.cpp`                              | `<opencv2/core.hpp>`                                                     |
| `opencv2/flann/sampling-rb.cpp`                            | `<opencv2/core/core.hpp>`, `<opencv2/flann/defines.h>`                   |
| `opencv2/objdetect/aruco_board-rb.cpp`                     | `<opencv2/objdetect/aruco_dictionary.hpp>`                               |
| `opencv2/stereo/descriptor-rb.cpp`                         | `<opencv2/core.hpp>`                                                     |
| `opencv2/surface_matching/pose_3d-rb.cpp`                  | `<opencv2/core/matx.hpp>`                                                |
| `opencv2/surface_matching/t_hash_int-rb.cpp`               | `<opencv2/core/hal/interface.h>`                                         |
| `opencv2/datasets/track_alov-rb.cpp`                        | `<opencv2/core.hpp>`, `<opencv2/datasets/dataset.hpp>`                   |
| `opencv2/datasets/track_vot-rb.cpp`                         | `<opencv2/core.hpp>`, `<opencv2/datasets/dataset.hpp>`                   |
| `opencv2/xfeatures2d-rb.cpp`                               | `<opencv2/features2d.hpp>`                                               |
| `opencv2/cudaimgproc-rb.cpp`                               | `<opencv2/core/mat.hpp>`                                                 |

## DNN Module
Remove the versioning in the DNN namespace.

| File                                     | Reason                                                                                                                                                                                                                |
|------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `opencv2/dnn/*.cpp`, `opencv2/dnn/*.hpp` | Remove inline namespace version suffix: replace `::dnn4_v\d+` with empty string (e.g., `cv::dnn::dnn4_v20241223` → `cv::dnn`)                                                                                         |
| `opencv2/dnn/*.cpp`, `opencv2/dnn/*.hpp` | Remove version from variable names: replace `Dnn4V\d+` with empty string (e.g., `rb_cCvDnnDnn4V20241223Layer` → `rb_cCvDnnLayer`)                                                                                     |
| `opencv2/dnn/*.cpp`                      | Delete empty module definition line: `Module rb_mCvDnn = define_module_under(rb_mCvDnn, "");`                                                                                                                         |

## Additional Updates
Apply all these updates

| File                                     | Reason                                                                                                                                                                                                                |
|------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `opencv2/core/fast_math-rb.cpp`          | Wrap `OPENCV_USE_FASTMATH_BUILTINS` constant in `#ifdef` guard                                                                                                                                                        |
| `opencv2/dnn/version-rb.cpp`             | Add `#define CV_DNN_DONT_ADD_INLINE_NS` on line 1 before includes                                                                                                                                                     |
| `opencv2/core/mat-rb.cpp`                | Comment out SparseMat `define_iterator` calls - SparseMatIterator doesn't dereference like standard iterators, use SparseMat__Refinements instead |
| `opencv2/core/cuda-rb.cpp`               | Remove default `Stream::Null()` arguments (~lines 332, 472) from `Event::record` and `convert_fp16`. Change `Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null())` to just `Arg("stream")`. Add comment: `// Remove default value for stream (Stream::Null) since it calls get_device which forces needing a GPU installed` |
| `opencv2/core/types-rb.cpp`              | Change `long` to `int64` for Point2l (~line 21) and Size2l (~line 38): `cv::Point_<long>` → `cv::Point_<int64>`, `cv::Size_<long>` → `cv::Size_<int64>`. Change template argument from `<long>` to `<int64>`. Add comment: `// Manual fix: use int64 instead of long` |
| `opencv2/core/types-rb.cpp`              | Remove duplicate `Matx41d` instantiation (~line 115): delete `Rice::Data_Type<cv::Matx<double, 4, 1>> rb_cMatx41d = Matx_instantiate<double, 4, 1>(rb_mCv, "Matx41d");` — already defined in `matx-rb.cpp` |
| `opencv2/core/types-rb.cpp`              | Remove duplicate `Vec4d` instantiation (~line 115): delete `Rice::Data_Type<cv::Vec<double, 4>> rb_cVec4d = Vec_instantiate<double, 4>(rb_mCv, "Vec4d");` — already defined in `matx-rb.cpp` |
| `opencv2/core/mat.inl-rb.cpp`            | Remove `ptrdiff_t` operator+ with `MatConstIterator` (~line 52): `ptrdiff_t` is not a Rice-wrapped type |

## Template Builder Modifications

**NOTE:** Template builder functions (`*_instantiate`) are located in `.ipp` files, not `.cpp` files. The `.cpp` files include the `.ipp` files and instantiate the templates.

The `Matx_instantiate` and `Vec_instantiate` templates in `opencv2/core/matx-rb.ipp` require `if constexpr` guards because OpenCV only defines constructors and methods for specific dimensions/types.

**Builder pattern:** Change `return Rice::define_class_under<...>(parent, name).` to `Rice::Data_Type<...> klass = Rice::define_class_under<...>(parent, name).` to store the class in a variable. Keep non-conditional methods (constants, default constructor, pointer constructor, static functions, always-available methods, operation constructors, val attr) in the fluent chain. Then use `klass.define_constructor(...)` / `klass.template define_method<...>(...)` in `if constexpr` blocks after the chain. Return `klass` at the end.

### `Matx_instantiate<typename _Tp, int m, int n>` changes:

1. **Dimension-specific constructors** - Move each multi-arg constructor out of the fluent chain and wrap in `if constexpr (m * n >= N)` (OpenCV uses `CV_StaticAssert(channels >= N)` internally):
   - `m * n >= 1`: 1-arg constructor
   - `m * n >= 2`: 2-arg constructor
   - `m * n >= 3`: 3-arg constructor
   - `m * n >= 4`: 4-arg constructor
   - `m * n >= 5`: 5-arg constructor
   - `m * n >= 6`: 6-arg constructor
   - `m * n >= 7`: 7-arg constructor
   - `m * n >= 8`: 8-arg constructor
   - `m * n >= 9`: 9-arg constructor
   - `m * n >= 10`: 10-arg constructor
   - `m * n >= 12`: 12-arg constructor
   - `m * n >= 14`: 14-arg constructor
   - `m * n >= 16`: 16-arg constructor

2. **Float/double-only methods** - Wrap `inv` and `solve` methods in:
   ```cpp
   if constexpr (std::is_same_v<_Tp, float> || std::is_same_v<_Tp, double>)
   {
   ```
   Note: Opening braces go on new lines per project code style.

3. **Vector-only single-index operator** - Wrap single-index `operator()` in:
   ```cpp
   if constexpr (m == 1 || n == 1)
   ```

### `Vec_instantiate<typename _Tp, int cn>` changes:

1. **Channel-specific constructors** - Move each multi-arg constructor out of the fluent chain and wrap in `if constexpr (cn >= N)` (OpenCV uses `CV_StaticAssert(channels >= N)` internally):
   - `cn >= 1` through `cn >= 10`, and `cn >= 14`

2. **Comment out randu/randn** - Same as Matx, these don't have explicit instantiations:
   ```cpp
   // Manual - Commented out randu/randn - no explicit template instantiations in OpenCV DLL
   // template define_singleton_function<cv::Vec<_Tp, cn>(*)(_Tp, _Tp)>("randn", ...);
   // template define_singleton_function<cv::Vec<_Tp, cn>(*)(_Tp, _Tp)>("randu", ...);
   ```

3. **Complex conjugate method** - Wrap `conj` method in:
   ```cpp
   if constexpr ((cn == 2 || cn == 4) && (std::is_same_v<_Tp, float> || std::is_same_v<_Tp, double>))
   ```

4. **Cross product method** - Wrap `cross` method in:
   ```cpp
   if constexpr (cn == 3)
   ```

### Why These Guards Are Needed

OpenCV's Matx and Vec are C++ templates. While the template definitions exist in headers, OpenCV only provides **explicit template instantiations** in its compiled library for specific type/dimension combinations that are commonly used.

**Problem on Windows/MSVC:** The linker requires all symbols to be resolved at link time. If you try to use a template method that OpenCV didn't explicitly instantiate (e.g., `Matx<float,2,1>::randu`), you get an "unresolved external symbol" error.

**Problem on Linux/macOS:** These platforms may use lazy symbol binding, so missing instantiations might not cause immediate errors (they'd fail at runtime if called).

**What OpenCV explicitly instantiates:**
- `randu`/`randn`: Not instantiated for most Matx/Vec types
- `inv`/`solve`: Only instantiated for square matrices (2x2, 3x3, 4x4, 6x6) with float/double
- `conj`: Only for Vec2f, Vec2d, Vec4f, Vec4d (complex number operations)
- `cross`: Only for Vec3 types (3D cross product)
- Constructors: Only for dimensions that match element count (e.g., 4-arg constructor only for 4-element matrices)

The `if constexpr` guards ensure we only define Ruby bindings for methods that have actual implementations in the OpenCV library.

## Class Inheritance Fixes

The generated `_instantiate` templates must specify parent classes for proper Ruby class inheritance.

### Vec inherits from Matx

**File:** `opencv2/core/matx-rb.ipp`, **Line ~129** (in `Vec_instantiate` function)

Change:
```cpp
Rice::Data_Type<cv::Vec<_Tp, cn>> klass = Rice::define_class_under<cv::Vec<_Tp, cn>>(parent, name).
```

To:
```cpp
Rice::Data_Type<cv::Vec<_Tp, cn>> klass = Rice::define_class_under<cv::Vec<_Tp, cn>, cv::Matx<_Tp, cn, 1>>(parent, name).
```

### Scalar_ inherits from Vec

**File:** `opencv2/core/types-rb.ipp`, **Line ~123** (in `Scalar__instantiate` function)

Change:
```cpp
return Rice::define_class_under<cv::Scalar_<_Tp>>(parent, name).
```

To:
```cpp
return Rice::define_class_under<cv::Scalar_<_Tp>, cv::Vec<_Tp, 4>>(parent, name).
```

### Mat_ inherits from Mat

**File:** `opencv2/core/mat-rb.ipp`, **Line ~4** (in `Mat__instantiate` function)

Change:
```cpp
return Rice::define_class_under<cv::Mat_<_Tp>>(parent, name).
```

To:
```cpp
return Rice::define_class_under<cv::Mat_<_Tp>, cv::Mat>(parent, name).
```

### PtrStep inherits from DevPtr

**File:** `opencv2/core/cuda_types-rb.ipp`, **Line ~34** (in `PtrStep_instantiate` function)

Change:
```cpp
return Rice::define_class_under<cv::cuda::PtrStep<T>>(parent, name).
```

To:
```cpp
return Rice::define_class_under<cv::cuda::PtrStep<T>, cv::cuda::DevPtr<T>>(parent, name).
```

### SparseMat_ inherits from SparseMat

**File:** `opencv2/core/mat-rb.ipp`, **Line ~146** (in `SparseMat__instantiate` function)

Change:
```cpp
return Rice::define_class_under<cv::SparseMat_<_Tp>>(parent, name).
```

To:
```cpp
return Rice::define_class_under<cv::SparseMat_<_Tp>, cv::SparseMat>(parent, name).
```

### MatConstIterator_ inherits from MatConstIterator

**File:** `opencv2/core/mat-rb.ipp`, **Line ~193** (in `MatConstIterator__instantiate` function)

Change:
```cpp
return Rice::define_class_under<cv::MatConstIterator_<_Tp>>(parent, name).
```

To:
```cpp
return Rice::define_class_under<cv::MatConstIterator_<_Tp>, cv::MatConstIterator>(parent, name).
```

### MatIterator_ inherits from MatConstIterator_

**File:** `opencv2/core/mat-rb.ipp`, **Line ~227** (in `MatIterator__instantiate` function)

Change:
```cpp
return Rice::define_class_under<cv::MatIterator_<_Tp>>(parent, name).
```

To:
```cpp
return Rice::define_class_under<cv::MatIterator_<_Tp>, cv::MatConstIterator_<_Tp>>(parent, name).
```

### SparseMatConstIterator_ inherits from SparseMatConstIterator

**File:** `opencv2/core/mat-rb.ipp`, **Line ~260** (in `SparseMatConstIterator__instantiate` function)

Change:
```cpp
return Rice::define_class_under<cv::SparseMatConstIterator_<_Tp>>(parent, name).
```

To:
```cpp
return Rice::define_class_under<cv::SparseMatConstIterator_<_Tp>, cv::SparseMatConstIterator>(parent, name).
```

### SparseMatIterator_ inherits from SparseMatConstIterator_

**File:** `opencv2/core/mat-rb.ipp`, **Line ~280** (in `SparseMatIterator__instantiate` function)

Change:
```cpp
return Rice::define_class_under<cv::SparseMatIterator_<_Tp>>(parent, name).
```

To:
```cpp
return Rice::define_class_under<cv::SparseMatIterator_<_Tp>, cv::SparseMatConstIterator_<_Tp>>(parent, name).
```

This ensures proper class hierarchies in Ruby.

## Final Step: Generate Diff File

After applying all manual updates, generate a unified diff file to document the changes:

```bash
git diff -- ext/ ':(exclude)ext/manual_updates.md' > ext/manual_updates.diff
```

This diff file serves as a reference for what manual changes were applied and can be used to verify or reapply changes if needed.

## Notes

- **NEVER use `git checkout` to restore files.** The generated branch contains freshly generated code. Checking out from main or other branches will overwrite the generated code and require regeneration.
- **IMPORTANT: Include order matters for compilation.** Follow these rules:
  - **OpenCV/system headers** (e.g., `<opencv2/core.hpp>`, `<vector>`, `<string>`) - Place BEFORE the primary header
  - **Local project headers** (e.g., `"mat-rb.hpp"`, `"matx-rb.hpp"`) - Place AFTER the primary header but before the file's own `-rb.hpp` header
  - When in doubt, check `git diff main` to see the working order from the main branch
- All manual includes should be marked with `// Manual` comment for identification
- These includes are needed because the generated bindings reference types or declarations from headers that aren't automatically included by the primary header

## Common Syntax Pitfalls

**IMPORTANT:** When applying manual updates, watch out for these syntax issues:

### 1. Commenting out methods in fluent chains

When commenting out methods at the end of a fluent chain (like in `dualquaternion-rb.ipp`), you must change the preceding `.` to `;` to properly terminate the chain.

**Wrong:**
```cpp
    template define_method<...>("/", &cv::DualQuat<_Tp>::operator/,
      Arg("arg_0")).
    // Commented out - causes linker errors
    // template define_method<...>("assign_divide", ...).
```

**Correct:**
```cpp
    template define_method<...>("/", &cv::DualQuat<_Tp>::operator/,
      Arg("arg_0"));  // Changed . to ; because next methods are commented out
    // Commented out - causes linker errors
    // template define_method<...>("assign_divide", ...).
```

## Verification Checklist

**CRITICAL:** Do not mark any task as complete without performing these verification steps.

1. **Verify after editing** - After claiming to edit a file, re-read it to confirm the changes are actually present before marking the task complete

2. **Show concrete evidence** - When completing a task, show the actual diff or key lines that changed, not just "I updated the file"

3. **Don't trust session summaries** - When resuming from a compacted session, verify file state by reading the files rather than trusting claims about what was done

4. **Be skeptical of completion claims** - Before saying "all done" on a multi-part task, read each affected file to verify the changes exist

5. **Explicit checkpoints** - For complex tasks, read each file after modification and state specifically what you see before moving on

Verification is not optional - it is part of completing a task. Saying something is done without confirming it creates problems.
