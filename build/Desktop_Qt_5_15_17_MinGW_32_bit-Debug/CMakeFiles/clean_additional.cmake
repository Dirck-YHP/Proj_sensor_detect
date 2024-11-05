# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Proj_Sensor_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Proj_Sensor_autogen.dir\\ParseCache.txt"
  "Proj_Sensor_autogen"
  )
endif()
