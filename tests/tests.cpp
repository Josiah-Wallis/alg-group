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

TEST(SetterTest, T1){
	Group* group = new Group();

	ASSERT_EQ(group->order(), 0);
	
	set<Op*>* stuff = new set<Op*>{new Op(1), new Op(2)};
	group->set_group(stuff);
	group->set_binary_operation("a+b-3");

	EXPECT_EQ(group->order(), 2);
	EXPECT_EQ(group->binary_operation(), "a+b-3");

}

TEST(SetterTest, T2){
	set<Op*>* stuff = new set<Op*> {new Op(1)};
	Group* test = new Group(stuff, "+");

	ASSERT_EQ(test->order(), 1);

	set<Op*>* new_stuff = test->mutable_set();
	Group* real = new Group(new_stuff, "-");
	
	EXPECT_EQ(real->order(), 1);
	EXPECT_EQ(real->binary_operation(), "-");
}

TEST(Insert_Remove_Test, T1){	
	set<Op*>* stuff = new set<Op*> {new Op(1), new Op(2), new Op(3)};
	Group* group = new Group(stuff, "-");
	
	ASSERT_EQ(group->order(), 3);

	group->insert(new Op(3));

	ASSERT_EQ(group->order(), 3);

	group->insert(new Op(4));

	EXPECT_EQ(group->order(), 4);

	group->remove(1);
	group->remove(2);

	EXPECT_EQ(group->order(), 2);
}

TEST(GroupTest, IsGroup){
	set<Op*>* stuff = new set<Op*> { new Op(1), new Op(3), new Op(5), new Op(7)};
	Group* group = new Group(stuff, "modm8");

	EXPECT_EQ(group->is_group(), true);
}

TEST(GroupTest, NotGroup){
	set<Op*>* stuff = new set<Op*> { new Op(1), new Op(2), new Op(3)};
	Group* group = new Group(stuff, "+");

	EXPECT_EQ(group->is_group(), false);	

}







int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
