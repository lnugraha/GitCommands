cmake_minimum_required(VERSION 3.16)

project( External.Reviewed_GSL.outcome
  VERSION 1.0
  DESCRIPTION "Testing using GSL in Modern CMake")

add_library( Reviewed_GSL.outcome INTERFACE IMPORTED GLOBAL)

target_include_directories( Reviewed_GSL.outcome SYSTEM
  INTERFACE /opt/gsl-outcoe/include )

target_compile_features( Reviewed_GSL.outcome INTERFACE cxx_std_17 )
add_library( GSL::outcome ALIAS Reviewed_GSL.outcome )
