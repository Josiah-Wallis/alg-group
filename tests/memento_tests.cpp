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
	
	group->undo(0);

	EXPECT_EQ(group->order(), 3);

	group->undo(0);

	EXPECT_EQ(group->order(), 4);

	group->undo(0);

	EXPECT_EQ(group->order(), 3);
}

TEST(UndoTest, T3){
	set<Op*>* x = new set<Op*> { new Op(3), new Op(4), new Op(5) };
	string op = "a+b-2";

	Group* group = new Group(x, op);

	ASSERT_EQ(group->order(), 3);
	ASSERT_EQ(group->binary_operation(), "a+b-2");

	group->safe_save();
	
	group->insert(new Op(2));
	group->set_binary_operation("+");

	EXPECT_EQ(group->order(), 4);
	EXPECT_EQ(group->binary_operation(), "+");

	group->undo(0);

	EXPECT_EQ(group->order(), 3);
	EXPECT_EQ(group->binary_operation(), "a+b-2");

	group->undo(0);

	EXPECT_EQ(group->order(), 4);
	EXPECT_EQ(group->binary_operation(), "+");
}

TEST(ForceBackTrackTest, T1){
	set<Op*>* x = new set<Op*> { new Op(1), new Op(2), new Op(3) };
	string op = "*";

	Group* group = new Group(x, op);

	ASSERT_EQ(group->order(), 3);
	ASSERT_EQ(group->binary_operation(), "*");

	group->safe_save();

	group->force_save();

	group->insert(new Op(4));

	group->force_save();

	group->insert(new Op(5));

	group->force_save();

	EXPECT_EQ(group->order(), 5);

	group->back_track(1);
	group->undo(1);

	EXPECT_EQ(group->order(), 4);

	group->back_track(2);
	group->undo(1);

	EXPECT_EQ(group->order(), 3);
}	


int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
