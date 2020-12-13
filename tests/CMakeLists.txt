find_package(Catch2 REQUIRED)

add_executable(tests tests-main.cpp test-000.cpp)

include_directories()

target_link_libraries(tests Catch2::Catch2)

include(CTest)
include(ParseAndAddCatchTests)
ParseAndAddCatchTests(tests)