cmake_minimum_required(VERSION 3.16)
project( MTX_LIB VERSION 1.0.0 )

add_library( MtxLib_ObjLib OBJECT )

target_sources( MtxLib_ObjLib
  PRIVATE "src/DenseMatrix.cpp" "src/Random.cpp"
  PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/include" )

target_compile_features( MtxLib_ObjLib PUBLIC cxx_constexpr )

target_include_directories( MtxLib_ObjLib
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

add_library( basicmath SHARED )
target_link_libraries( basicmath PUBLIC MtxLib_ObjLib GSL::gslcblas )

add_library( MatrixToolbox::basicmath ALIAS basicmath )

file(COPY ${CMAKE_SOURCE_DIR}/lib/include
     DESTINATION ${CMAKE_BINARY_DIR})

# install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_BINARY_DIR/lib})

