cmake_minimum_required( VERSION 3.16 )

project( MatrixCalculatorApp VERSION 1.0.0 )

# Freely available calculator app.
add_executable( MatrixCalculator )
target_sources( MatrixCalculator PRIVATE "src/main.cpp" )

# External Library that you wish to include
find_package( GSL COMPONENTS gsl gslcblas )
if ( GSL_FOUND )
  set_target_properties( GSL::gsl GSL::gslcblas
    PROPERTIES IMPORTED_GLOBAL TRUE )
endif()

target_link_libraries( MatrixCalculator PRIVATE MatrixToolbox::basicmath 
  GSL::gsl GSL::gslcblas )

# Possibly, compile key-file into premium-calculator, too.
# if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/key-file.cpp")
#    target_sources( PremiumCalculator  PRIVATE "src/key-file.cpp" )
# endif ()
