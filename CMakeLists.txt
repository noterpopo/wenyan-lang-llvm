cmake_minimum_required(VERSION 3.15)
project(LLVMLan)

set(CMAKE_CXX_STANDARD 14)
include_directories(/usr/local/Cellar/llvm/9.0.0_1/include -std=c++11 -stdlib=libc++)
set(CMAKE_SHARED_LINKER_FLAGS  "-L/usr/local/Cellar/llvm/9.0.0_1/lib -Wl,-search_paths_first -Wl,-headerpad_max_install_names")
link_directories(/usr/local/Cellar/llvm/9.0.0_1/lib)
add_definitions(
        -D__STDC_CONSTANT_MACROS
        -D__STDC_FORMAT_MACROS
        -D__STDC_LIMIT_MACROS
)
add_executable(LLVMLan src/main.cpp)
target_link_libraries(
        LLVMLan
        LLVMX86Disassembler
        LLVMX86AsmParser
        LLVMX86CodeGen
        LLVMGlobalISel
        LLVMSelectionDAG
        LLVMAsmPrinter
        LLVMDebugInfoDWARF
        LLVMCodeGen
        LLVMScalarOpts
        LLVMInstCombine
        LLVMAggressiveInstCombine
        LLVMBitWriter
        LLVMX86Desc
        LLVMMCDisassembler
        LLVMX86Utils
        LLVMX86Info
        LLVMMCJIT
        LLVMOrcJIT
        LLVMTransformUtils
        LLVMJITLink
        LLVMExecutionEngine
        LLVMTarget
        LLVMAnalysis
        LLVMProfileData
        LLVMRuntimeDyld
        LLVMObject
        LLVMMCParser
        LLVMBitReader
        LLVMBitstreamReader
        LLVMMC
        LLVMDebugInfoCodeView
        LLVMDebugInfoMSF
        LLVMCore
        LLVMRemarks
        LLVMBinaryFormat
        LLVMSupport
        LLVMX86Utils
        LLVMX86Info
        LLVMDemangle
        )
include(FindCurses)
target_link_libraries(LLVMLan
        z
        m
        xml2
        ${CURSES_LIBRARIES}
        )
