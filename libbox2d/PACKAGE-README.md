# libbox2d - 2D physics engine for games

This is a `build2` package for the [Box2D](https://github.com/erincatto/box2d)
C library. It provides a portable 2D rigid body physics engine for games
(collision detection, joints, continuous physics, and related features).


## Usage

To start using `libbox2d` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libbox2d ^3.1.1
```

Then import the library in your `buildfile`:

```
import libs = libbox2d%lib{box2d}
```

Public headers are installed under `include/box2d/`. Include them as:

```c
#include <box2d/box2d.h>
```


## Importable targets

This package provides the following importable targets:

```
lib{box2d}
```

This is the Box2D physics library.


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libbox2d.disable_simd  ?= false
[bool] config.libbox2d.avx2          ?= false
[bool] config.libbox2d.enable_assert ?= false
[bool] config.libbox2d.validate      ?= true
```

`config.libbox2d.disable_simd` builds the scalar math fallback instead of
SSE2/NEON/AVX2 (`BOX2D_DISABLE_SIMD`). Slower. Implementation detail only (not
part of the public export interface).

`config.libbox2d.avx2` enables AVX2 on x86_64 (`BOX2D_AVX2` plus the matching
compiler arch flag). Ignored when SIMD is disabled. Implementation detail only.

`config.libbox2d.enable_assert` keeps `B2_ASSERT()` active in release builds
where `NDEBUG` is defined (`B2_ENABLE_ASSERT`). Matches the behaviour of
upstream's MSVC RelWithDebInfo configuration. The define is re-exported to
consumers so assertions are consistent across the boundary.

`config.libbox2d.validate` enables heavy internal validation (`BOX2D_VALIDATE`).
Validation only activates in builds where `NDEBUG` is not defined, it is a no-op
in release builds regardless of this setting.
