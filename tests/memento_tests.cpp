#include "../memento_header/memento.hpp"
#include "../group_header/group.hpp"
#include "../op_header/op.hpp"
#include "gtest/gtest.h"

TEST(UndoTest, T1){
	set<Op*>* x = new set<Op*> {new Op(1), new Op(5)};
	string op = "modm6";

	Group* group = new Group(x, op);

	ASSERT_EQ(group->order(), 2);

	group->safe_save();

	group->insert(new Op(4));

	ASSERT_EQ(group->order(),3);

	group->set_binary_operation("+");

	EXPECT_EQ(group->binary_operation(), "+");

	group->undo(0);

	EXPECT_EQ(group->order(), 2);

	EXPECT_EQ(group->binary_operation(), "modm6");

}


TEST(UndoTest, T2){
	set<Op*>* x = new set<Op*> { new Op(1), new Op(5)};
	string op = "modm6";

	Group* group = new Group(x, op);

	ASSERT_EQ(group->order(), 2);
	ASSERT_EQ(group->binary_operation(), "modm6");

	group->safe_save();

	group->insert(new Op(4));
	group->insert(new Op(6));

	EXPECT_EQ(group->order(), 4);
	
	//group->undo(0);

	//EXPECT_EQ(group->order(), 3);
}

	


int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
