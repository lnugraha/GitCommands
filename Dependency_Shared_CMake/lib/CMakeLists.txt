cmake_minimum_required(VERSION 3.16)
project( MTX_LIB VERSION 1.0.0 )

# Find the BLAS stuff
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(BLA_DEFINITIONS)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -Wall")
if ("$ENV{MKLROOT}" STREQUAL "")
  message(FATAL_ERROR "MKLROOT is not set. Please source the Intel MKL mklvars.sh file.")
endif()

# user defined options for MKL
option(MKL_USE_parallel "Use MKL parallel" True)
option(MKL_USE_sdl "Single Dynamic Library or static/dynamic" False)
set(MKL_USE_interface "lp64" CACHE STRING "for Intel(R)64 compatible arch: ilp64/lp64 or for ia32 arch: cdecl/stdcall")

if (BLA_VENDOR MATCHES "_seq")
  set(MKL_USE_parallel OFF)
else()
  set(MKL_USE_parallel ON)
endif()

find_package(MKL REQUIRED)

if (MKL_FOUND)
  set(BLA_INCLUDE_DIR ${MKL_INCLUDE_DIR})
  set(BLAS_LIBRARIES ${MKL_LIBRARIES})
  set(BLA_DEFINITIONS USE_MKL)
endif()

message(STATUS "BLAS Libraries: ${BLAS_LIBRARIES}")

add_library( MtxLib_ObjLib OBJECT )

target_sources( MtxLib_ObjLib
  PRIVATE "src/DenseMatrix.cpp" "src/Random.cpp"
  PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/include" )

target_compile_features( MtxLib_ObjLib PUBLIC cxx_constexpr )

target_include_directories( MtxLib_ObjLib
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

add_library( basicmath SHARED )
target_link_libraries( basicmath PUBLIC MtxLib_ObjLib ${MKL_LIBRARIES} )

add_library( MatrixToolbox::basicmath ALIAS basicmath )

# file(COPY ${CMAKE_SOURCE_DIR}/lib/include DESTINATION ${CMAKE_BINARY_DIR})
# install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_BINARY_DIR/lib})

