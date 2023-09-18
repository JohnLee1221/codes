#设置python的头文件和库文件路径
set(Python3_INCLUDE_DIRS "/usr/include/python3.8d")
set(Python3_LIBRARIES "/usr/lib/x86_64-linux-gnu/libpython3.8.so")
set(PYTHON_EXECUTABLE "/usr/bin/python3.8")

# set(Numpy_INCLUDE_DIRS "/usr/include/python3.6m/numpy")
# set(Numpy_LIBRARIES "/usr/lib/x86_64-linux-gnu/libboost_numpy.so")

# Library target
add_library(matplotlib_cpp INTERFACE)

target_include_directories(matplotlib_cpp INTERFACE
    ${PROJECT_SOURCE_DIR}#工程目录
    "usr/include"#系统目录
    "usr/local/include"#安装文件目录
    ${Python3_INCLUDE_DIRS}
)

target_link_libraries(matplotlib_cpp INTERFACE
                      ${Python3_LIBRARIES}
)

target_compile_features(matplotlib_cpp INTERFACE
  cxx_std_17
)
