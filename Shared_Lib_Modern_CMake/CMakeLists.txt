cmake_minimum_required(VERSION 3.16)

project( MODERN_CMAKE VERSION 1.0.0 )

set (CMAKE_POSITION_INDEPENDENT_CODE ON )

##################################
# external/ is merged with app/  #
# add_subdirectory(external)     #
##################################

add_subdirectory(lib)
add_subdirectory(app)




