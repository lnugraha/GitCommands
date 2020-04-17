file(REMOVE_RECURSE
  "libbasicmath.dylib"
  "libbasicmath.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/basicmath.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
