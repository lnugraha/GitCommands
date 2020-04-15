add_library(mathops SHARED mathops.cpp)
target_include_directories(mathops PUBLIC ${PROJECT_SOURCE_DIRECTORY}/include)
# install(TARGETS mathops DESTINATION lib)
# install(FILES mathops.hpp DESTINATION include)

