# pybind11 demo

### results (release build, i5-4670 @ 3.4Ghz x 4)
```bash
# pure python
scripts/ackermann.py		~10 mins

# numba jit compiled python
scripts/ackermann_numba.py 	~30 secs

# pybind calling c++ code
scripts/ackermann_pybind.py 	~2.6 secs 
```

### install
Dependencies:
* python >= 3
* cmake >= 3.1
* g++, clang supporting c++11

```bash
git clone --recursive https://github.com/juliangaal/pybind_demo
cd pybind_demo && mkdir build && cd build
cmake ..
make 
```
Default `CMAKE_BUILD_TYPE=Release`

*Custom Options*
* `LIB_GEN_PATH`: Where generated library will be placed. **Default**: `scripts/`

***Note***
You may need to manually set the python version to build against, e.g. when encountering a `PythonLibs` and `PythonInterpreter` mismatch, in `build` directory:
```bash
cmake -DPYTHON_LIBRARY=$(python-config --prefix)/lib/libpython<version>.dylib -DPYTHON_INCLUDE_DIR=$(python-config --prefix)/include/python<version> ..
make
```

### use from python
To run the compiled c++ lib from python code, in `scripts/`: run 
``` bash
python-<version you compiled against> ackermann_pybind.py
```

The easiest way to use the generated library from *anywhere* is to add the output path (default `scripts`) to `PYTHONPATH`
```bash
PYTHONPATH="${PYTHONPATH}:/path/to/this/repo/scripts"
export PYTHONPATH
```
or change `LIB_GEN_PATH` to an existing path in `$PYTHONPATH`
