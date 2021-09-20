# `cnalloc.h` bug MRE

## RESOLVED!
The key was to link carma to the external library at compile time to avoid the memory allocation function mismatch. See https://github.com/RUrlus/carma/issues/89.

To reproduce:
```bash
cmake -S . -B build
cmake --build build
python pymod_test.py
```

Notes
- By commenting out `#include <carma>` in `pymod.cpp` the bug no longer appears.
- The bug persists even after avoiding the precompiled `cnalloc.h` file by using the target `carma::headers` in `CMakeLists.txt`, even with the [prescribed include order](https://carma.readthedocs.io/en/latest/building.html#cmake-build).
- The program appears to crash only for code compiled in a separate library, not from within the binding module or a header file.