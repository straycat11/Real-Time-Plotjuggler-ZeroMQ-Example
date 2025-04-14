cmake_minimum_required(VERSION 3.10)
project(ZMQPlotJugglerExample)

set(CMAKE_CXX_STANDARD 17)

# Vcpkg integration
set(CMAKE_TOOLCHAIN_FILE "C:/Users/utku.yucel/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "")

add_executable(main src/main.cpp)

# Manually add include and link directories
target_include_directories(main PRIVATE "C:/Users/utku.yucel/vcpkg/installed/x64-windows/include")
target_link_directories(main PRIVATE "C:/Users/utku.yucel/vcpkg/installed/x64-windows/lib")

# Link the actual library
target_link_libraries(main PRIVATE libzmq-mt-4_3_5)
