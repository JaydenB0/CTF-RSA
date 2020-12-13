add_executable(ctfrsa main.cpp)
target_link_libraries(ctfrsa PUBLIC gmp)
target_link_libraries(ctfrsa PUBLIC gmpxx)
target_include_directories(ctfrsa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
