cmake_minimum_required(VERSION 3.16)
project(smrcore_sdk_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Point -DCMAKE_PREFIX_PATH at the extracted SDK directory.
# The SDK package provides lib/cmake/smrcore_sdk/smrcore_sdkConfig.cmake.
find_package(smrcore_sdk REQUIRED)

set(SMRCORE_SDK_EXAMPLES
    01_connect
    02_read_state
    03_movej
    04_movel
)

foreach(example ${SMRCORE_SDK_EXAMPLES})
    add_executable(${example} ${example}.cpp)
    target_link_libraries(${example} PRIVATE smrcore::sdk)
endforeach()
