# Usage

## C++ SDK

The C++ SDK archive provides headers, libraries, and a CMake package.

```text
3rdparty/smrcore_sdk/
├── include/rcore/sdk/*.hpp
└── lib/cmake/smrcore_sdk/
```

Use it in your own CMake project:

```cmake
cmake_minimum_required(VERSION 3.16)
project(my_robot_app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(smrcore_sdk REQUIRED)

add_executable(my_robot_app main.cpp)
target_link_libraries(my_robot_app PRIVATE smrcore::sdk)
```

Build with:

```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH=/path/to/smrcore_sdk
cmake --build build
```

Minimal program:

```cpp
#include "sdk/robot.hpp"

#include <cstdio>

int main()
{
    rcore::sdk::Robot robot;
    if (!robot.Initialize(""))
    {
        std::fprintf(stderr, "Initialize failed\n");
        return 1;
    }

    std::printf("connected=%s\n", robot.IsConnected() ? "true" : "false");
    robot.Shutdown();
    return 0;
}
```

## Python SDK

After installing the wheel, import `rcore_sdk` and check the linked runtime
version:

```python
import rcore_sdk
from rcore_sdk import _native

print(rcore_sdk.__version__)
print(_native.linked_sdk())
```

Minimal program:

```python
from rcore_sdk import Robot

robot = Robot()
if not robot.Initialize(""):
    raise RuntimeError("Initialize failed")

print(f"connected={robot.IsConnected()}")
robot.Shutdown()
```
