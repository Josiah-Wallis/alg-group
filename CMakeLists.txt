CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(op_tests
	tests/op_tests.cpp
	op_src/custom.cpp
	factory_src/op_factory.cpp
)

ADD_EXECUTABLE(factory_tests
	tests/factory_tests.cpp
	factory_src/op_factory.cpp
	op_src/custom.cpp
)

TARGET_LINK_LIBRARIES(op_tests gtest)
TARGET_LINK_LIBRARIES(factory_tests gtest)
TARGET_COMPILE_DEFINITIONS(op_tests PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(factory_tests PRIVATE gtest_disable_pthreads=ON)
