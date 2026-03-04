# GCC 15 `-Wtemplate-body` Build Failures

## Problem

GCC 15 introduces `-Wtemplate-body`, which checks template definitions at definition time rather than deferring all checking to instantiation time. This catches unqualified dependent names that older GCC versions silently accepted.

The generated flann binding templates (`ext/opencv2/flann/*-rb.ipp`) use unqualified names that fail under this stricter checking.

## GCC Version

```
c++ (GCC) 15.2.1 20251211 (Red Hat 15.2.1-5)
```

Fedora 43 with OpenCV 4.11.0 (`dnf install opencv-devel`).

## Failing Files

All failures are in flann template instantiation files (`.ipp`):

- `opencv2/flann/all_indices-rb.ipp`
- `opencv2/flann/autotuned_index-rb.ipp`
- `opencv2/flann/composite_index-rb.ipp`
- `opencv2/flann/flann_base-rb.ipp`

## Error Categories

### 1. Unqualified `ElementType`

The generated code uses bare `ElementType` instead of `typename Distance::ElementType`:

```cpp
// Generated (wrong):
Constructor<cvflann::CompositeIndex<Distance>, const cvflann::Matrix<ElementType>&, ...>

// Should be:
Constructor<cvflann::CompositeIndex<Distance>, const cvflann::Matrix<typename Distance::ElementType>&, ...>
```

**Files:** `composite_index-rb.ipp:5`, `autotuned_index-rb.ipp:5`, `flann_base-rb.ipp:5`

### 2. Unqualified `Matrix`

The generated code uses bare `Matrix` instead of `cvflann::Matrix`:

```cpp
// Generated (wrong):
const Matrix<typename Distance::ElementType>&

// Should be:
const cvflann::Matrix<typename Distance::ElementType>&
```

**File:** `all_indices-rb.ipp:5`

### 3. Unqualified class self-reference in default arguments

The generated code uses the class template name without template arguments in default argument expressions:

```cpp
// Generated (wrong):
Arg("d") = static_cast<Distance>(cvflann::CompositeIndex::Distance())

// Should be:
Arg("d") = static_cast<Distance>(cvflann::CompositeIndex<Distance>::Distance())
```

**Files:** `composite_index-rb.ipp:6`, `autotuned_index-rb.ipp:6`, `flann_base-rb.ipp:6`

### 4. OpenCV header bugs (`ground_truth.h`)

OpenCV's own `flann/ground_truth.h` header also has `-Wtemplate-body` issues (unqualified `std::vector` usage). This is an upstream OpenCV bug, not a ruby-bindgen issue.

**File:** `/usr/include/opencv4/opencv2/flann/ground_truth.h:50-54`

## Root Cause

ruby-bindgen generates template code using names as they appear in the clang AST. Inside a template definition, dependent names from template parameters (like `Distance::ElementType`) need to be fully qualified with `typename` and namespace prefixes. GCC < 15 deferred this checking to instantiation time, but GCC 15's `-Wtemplate-body` enforces it at definition time.

## Fix Options

### Option A: Fix in ruby-bindgen (proper fix)

Ensure ruby-bindgen fully qualifies dependent type names in generated template code:
- Add `typename` keyword for dependent type names
- Fully qualify nested types with their enclosing template class and namespace
- Add template arguments when referencing the enclosing class template in default arguments

### Option B: Suppress warning (workaround)

Add `-Wno-template-body` to the Linux CMake preset flags. This suppresses the warning but leaves the technically-incorrect code in place.

```json
"CMAKE_CXX_FLAGS": "-Wall -Wno-template-body ..."
```
