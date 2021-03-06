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

ADD_EXECUTABLE(group_tests
	tests/tests.cpp
	group_src/group.cpp
	factory_src/op_factory.cpp
	op_src/custom.cpp
	memento_src/memento.cpp
	strategy_src/associative.cpp
	strategy_src/closure.cpp
	strategy_src/commutative.cpp
	strategy_src/identity.cpp
	strategy_src/inverse.cpp
	strategy_src/verifier.cpp
	strategy_src/verification.cpp
)

ADD_EXECUTABLE(memento_tests
	tests/memento_tests.cpp
	group_src/group.cpp
	factory_src/op_factory.cpp
	op_src/custom.cpp
	memento_src/memento.cpp
	strategy_src/associative.cpp
	strategy_src/closure.cpp
	strategy_src/commutative.cpp
	strategy_src/identity.cpp
	strategy_src/inverse.cpp
	strategy_src/verifier.cpp
	strategy_src/verification.cpp	
)

ADD_EXECUTABLE(strategy_tests
	tests/strategy_tests.cpp
	group_src/group.cpp
	factory_src/op_factory.cpp
	op_src/custom.cpp
	memento_src/memento.cpp
	strategy_src/associative.cpp
	strategy_src/closure.cpp
	strategy_src/commutative.cpp
	strategy_src/identity.cpp
	strategy_src/inverse.cpp
	strategy_src/verifier.cpp
	strategy_src/verification.cpp
)

ADD_EXECUTABLE(input_output
	group_src/group.cpp
	factory_src/op_factory.cpp
	op_src/custom.cpp
	memento_src/memento.cpp
	strategy_src/associative.cpp
	strategy_src/closure.cpp
	strategy_src/commutative.cpp
	strategy_src/identity.cpp
	strategy_src/inverse.cpp
	strategy_src/verifier.cpp
	strategy_src/verification.cpp
	main.cpp
)

ADD_EXECUTABLE(verif_tests
	tests/verif_tests.cpp
	group_src/group.cpp
	factory_src/op_factory.cpp
	op_src/custom.cpp
	memento_src/memento.cpp
	strategy_src/associative.cpp
	strategy_src/closure.cpp
	strategy_src/commutative.cpp
	strategy_src/identity.cpp
	strategy_src/inverse.cpp
	strategy_src/verifier.cpp
	strategy_src/verification.cpp
)
	

TARGET_LINK_LIBRARIES(group_tests gtest)
TARGET_LINK_LIBRARIES(op_tests gtest)
TARGET_LINK_LIBRARIES(factory_tests gtest)
TARGET_LINK_LIBRARIES(memento_tests gtest)
TARGET_LINK_LIBRARIES(strategy_tests gtest)
TARGET_LINK_LIBRARIES(verif_tests gtest)
TARGET_COMPILE_DEFINITIONS(memento_tests PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(group_tests PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(op_tests PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(factory_tests PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(strategy_tests PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(verif_tests PRIVATE gtest_disable_pthreads=ON)
