include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(storages_shapes_tests test.cc)
target_link_libraries(storages_shapes_tests PRIVATE storages_shapes GTest::gtest_main)

add_test(NAME storages_shapes_tests COMMAND storages_shapes_tests)
