# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/prehelp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/prehelp_autogen.dir/ParseCache.txt"
  "prehelp_autogen"
  )
endif()
