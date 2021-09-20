# `cnalloc.h` bug MRE

To reproduce:
```bash
cmake -S . -B build
cmake --build build
python pymod_test.py
```

Notes
- By commenting out `#include <carma>` in `pymod.cpp` the bug no longer appears.
- The bug persists even after avoiding the precompiled `cnalloc.h` file by using the target `carma::headers` in `CMakeLists.txt`, even with the [prescribed include order](https://carma.readthedocs.io/en/latest/building.html#cmake-build).
- The program only crashes for separately compiled code, which appears not to be using Carma's malloc function (see `arma_extra_code=0` in the Armadillo debug statements).