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
cmake -DCMAKE_BUILD_TYPE=Release ..
make 
```
#### Note
You may need to manually set the python version to build against, e.g. when encountering a `PythonLibs` and `PythonInterpreter` mismatch, in `build` directory:
```bash
cmake -DCMAKE_BUILD_TYPE=Release -DPYTHON_LIBRARY=$(python-config --prefix)/lib/libpython<version>.dylib -DPYTHON_INCLUDE_DIR=$(python-config --prefix)/include/python<version> ..
make
```

To run the compiled c++ lib from python code, in `scripts/`: run `python-<version you compiled against> ackermann_pybind.py`
