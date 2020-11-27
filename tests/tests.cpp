#include "../group_header/group.hpp"
#include "../op_header/op.hpp"
#include "gtest/gtest.h"

TEST(ConstructorTests, T1){
	Group* group = new Group("+");
	
	ASSERT_EQ(true, group->empty());
	EXPECT_EQ(0, group->order());
	EXPECT_EQ("+", group->binary_operation());
}





int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
