
add_executable(TestProgram tests/args/import.cpp)

target_link_libraries(TestProgram PRIVATE 
            ${PROJ_NAME}
            GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(AllTestsInArgument TestProgram)

