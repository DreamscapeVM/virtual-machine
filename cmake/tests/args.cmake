
add_executable(TestProgram tests/args/import.cpp)

target_link_libraries(TestProgram PRIVATE 
            ${PROJ_NAME}
            GTest::gtest GTest::gtest_main)

add_test(Test1 TestProgram)
