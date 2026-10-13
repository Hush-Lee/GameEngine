find_package(Catch2 CONFIG REQUIRED)

add_executable(engine_tests SmokeTests.cpp)
target_link_libraries(engine_tests PRIVATE Catch2::Catch2WithMain)

add_test(NAME engine_tests COMMAND engine_tests)
