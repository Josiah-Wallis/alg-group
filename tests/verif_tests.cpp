//#include "..group_header/group.hpp"
//#include "..op_header/op.hpp"
#include "gtest/gtest.h"
#include "../strategy_header/associative.hpp"
#include "../strategy_header/closure.hpp"
#include "../strategy_header/commutative.hpp"
#include "../strategy_header/identity.hpp"
#include "../strategy_header/inverse.hpp"
#include "../strategy_header/verifier.hpp"
#include "../strategy_header/verification.hpp"


int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


