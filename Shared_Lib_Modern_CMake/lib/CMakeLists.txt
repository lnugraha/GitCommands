cmake_minimum_required(VERSION 3.16)
project( MTX_LIB VERSION 1.0.0 )


# An OBJECT-library, used to only compile common sources once
# which are used in both math-libraries.
add_library( MtxLib_ObjLib OBJECT )

target_sources( MtxLib_ObjLib
  PRIVATE "src/DenseMatrix.cpp" "src/Random.cpp"
  PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/include" )

target_compile_features( MtxLib_ObjLib PUBLIC cxx_constexpr )

target_include_directories( MtxLib_ObjLib
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )


# A shared library for basic-math functionality.
add_library( basicmath SHARED )
target_link_libraries( basicmath PUBLIC MtxLib_ObjLib )


# Create ALIAS targets.
add_library( MatrixToolbox::basicmath ALIAS basicmath )

