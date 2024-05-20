
add_executable(fundamental tests/fundamental/for-loop.cpp)

target_link_libraries(fundamental PRIVATE 
            ${PROJ_NAME}
            GTest::gtest GTest::gtest_main)

add_test(Test2 fundamental)
