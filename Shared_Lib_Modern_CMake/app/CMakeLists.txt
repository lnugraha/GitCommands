cmake_minimum_required( VERSION 3.16 )

project( MatrixCalculatorApp VERSION 1.0.0 )

# Freely available calculator app.
add_executable( MatrixCalculator )
target_sources( MatrixCalculator PRIVATE "src/main.cpp" )
target_link_libraries( MatrixCalculator PRIVATE MatrixToolbox::basicmath )

# Possibly, compile key-file into premium-calculator, too.
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/key-file.cpp")
    target_sources( PremiumCalculator
        PRIVATE "src/key-file.cpp" )
endif ()
