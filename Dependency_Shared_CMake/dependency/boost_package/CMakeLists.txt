cmake_minimum_required( VERSION 3.16 )
project( External.Reviewed_Boost.outcome VERSION 1.0.0 )

# Provide target for "Boost.Outcome" library.
add_library( Reviewed_Boost.outcome INTERFACE 
  IMPORTED GLOBAL )

# Store include search-path containing headers of "Boost.Outcome".
target_include_directories( Reviewed_Boost.outcome SYSTEM
    INTERFACE /opt/boost-outcome/include )

# Require at least compiling with C++14.
target_compile_features( Reviewed_Boost.outcome INTERFACE cxx_std_14 )

# Create an alias for "Boost.Outcome".
add_library( Boost::outcome ALIAS Reviewed_Boost.outcome )
