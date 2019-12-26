cmake_minimum_required(VERSION 3.15)
project(LLVMLan)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-I/usr/local/Cellar/llvm/9.0.0_1/include")
set(LLVM_LINK_COMPONENTS
        Analysis
        Core
        ExecutionEngine
        InstCombine
        Object
        OrcJIT
        RuntimeDyld
        ScalarOpts
        Support
        native
        )
add_executable(LLVMLan src/main.cpp)