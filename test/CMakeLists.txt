# Raspboop unit tests

cmake_minimum_required(VERSION 2.8)

set(TESTS
  boards
  sensors
  server
)

foreach(test ${TESTS})
  add_executable(${test} ${test}.cpp)
  target_link_libraries(${test} raspboop ${RBP_LIBRARIES})
  set_target_properties(${test} PROPERTIES FOLDER Tests)
endforeach(test)
