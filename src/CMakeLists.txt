# Raspboop CMake file

cmake_minimum_required(VERSION 2.8)

# Raspboop Modules

set(MODULES
  essentials/Core
  data/Command
  boards/L298N
  abstracts/GPIOConsumer
  abstracts/Sensor
  sensors/HCSR04
  sensors/HCSR501
  com/Server
)

set(HEADERS
  ${CMAKE_SOURCE_DIR}/include/raspboop/Raspboop
  ${CMAKE_SOURCE_DIR}/include/raspboop/essentials/Types
)

set(INTERFACES
  ${CMAKE_SOURCE_DIR}/include/raspboop/interfaces/Commandable
  ${CMAKE_SOURCE_DIR}/include/raspboop/interfaces/Serializable
)

foreach(module ${MODULES})
  list(APPEND HEADERS ${CMAKE_SOURCE_DIR}/include/raspboop/${module})
endforeach(module)

foreach(interface ${INTERFACES})
  list(APPEND HEADERS ${interface})
endforeach(interface)

add_library(raspboop ${HEADERS} ${MODULES})
target_link_libraries(raspboop ${RBP_LIBRARIES})
set_target_properties(raspboop PROPERTIES FOLDER Raspboop)

if(INSTALL_SDK)
  install(TARGETS raspboop
          RUNTIME DESTINATION bin
          LIBRARY DESTINATION lib
          ARCHIVE DESTINATION lib/static)

  install(DIRECTORY ${RBP_INC_DIR}
          DESTINATION include
          FILES_MATCHING PATTERN "*.h")
endif()
