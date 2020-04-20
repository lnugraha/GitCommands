set(GSL_USE_STATIC_LIBS   FALSE)
set(GSL_USE_MULTITHREADED TRUE)

find_package(GSL REQUIRED)
# GSL_INCLUDE_DIRS
# GSL_LIBRARES
# GSL_VERSION

if ( GSL_FOUND )
  message( GSL_VERSION )
  set_target_properties( GSL::gsl GSL::gslcblas
                         PROPERTIES IMPORTED_GLOBAL TRUE )
else()
  message("GSL is not available")
endif()
