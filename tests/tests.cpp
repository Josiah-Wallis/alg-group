#include "../group_header/group.hpp"
#include "../op_header/op.hpp"
#include "gtest/gtest.h"

TEST(ConstructorTests, T1){
	Group* group = new Group("+");
	
	ASSERT_EQ(true, group->empty());
	EXPECT_EQ(0, group->order());
	EXPECT_EQ("+", group->binary_operation());
}

TEST(ConstructorTests, T2){
	set<Op*>* stuff = new set<Op*>{
		new Op(5), new Op(3), new Op(7)};

	Group* group = new Group(stuff, "-");

	ASSERT_EQ(false, group->empty());
	EXPECT_EQ(3, group->order());
	EXPECT_EQ("-", group->binary_operation());

	Op* x = new Op(6);
	group->insert(x);

	EXPECT_EQ(4, group->order());

	Op* y = new Op(7);
	group->insert(y);

	EXPECT_EQ(4, group->order());
}


int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
