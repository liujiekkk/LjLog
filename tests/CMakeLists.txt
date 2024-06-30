cmake_minimum_required(VERSION 3.8)

project("tests")

add_executable("main" "${PROJECT_SOURCE_DIR}/main.cpp")

# 设置生成文件依赖的头文件目录.
target_include_directories("main" PUBLIC ${PATH_INCLUDE})

# 连接自定义日志库
target_link_libraries("main" PRIVATE "LjLog")
# 设置自定义库的目录
target_link_directories("main" PUBLIC ${PATH_LIB})