add_library(mathops STATIC mathops.cpp)
# target_include_directories(mathops PUBLIC ${PROJECT_SOURCE_DIRECTORY}/include)

target_include_directories(mathops
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

install(TARGETS mathops EXPORT mathopsTargets
  LIBRARY DESTINATION lib # install in your local system
  ARCHIVE DESTINATION lib 
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

# install(FILES mathops.hpp DESTINATION include)

