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

typedef Verification V;
typedef Verifier Ver;

TEST(PB_Tests, NullTest){
	V* ver = new V();

	EXPECT_EQ(ver->size(), 0);
}

TEST(PB_Tests, Push){
	V* ver = new V();

	Ver* assoc = new Associative();
	Ver* closure = new Closure();

	ver->push_back(assoc);

	ASSERT_EQ(ver->size(), 1);

	ver->push_back(closure);

	EXPECT_EQ(ver->size(), 2);

}


TEST(PB_Tests, RepPush){
	V* ver = new V();

	Ver* iden = new Identity();
	Ver* rep = new Identity();
	Ver* inv = new Inverse();
	
	ver->push_back(iden);

	ASSERT_EQ(ver->size(), 1);

	ver->push_back(rep);

	EXPECT_EQ(ver->size(), 1);

	ver->push_back(inv);

	EXPECT_EQ(ver->size(), 2);
}

TEST(CheckTests, NullTest){
	V* ver = new V();
	
	bool* stuff = ver->check();

	EXPECT_EQ(stuff, nullptr);
}

TEST(CheckTests, MultiCheck){
	V* ver = new V();

	Ver* assoc = new Associative();
	Ver* closure = new Closure();
	Ver* identity = new Identity();

	ver->push_back(assoc);
	ver->push_back(closure);
	ver->push_back(identity);

	set<Op*>* x = new set<Op*> { new Op(1), new Op(3), new Op(5), new Op(7) };
	string op = "modm8";

	Group* g = new Group(x, op);
	
	ver->pass(g);
	bool* test = ver->check();

	EXPECT_EQ(test[0], true);
	EXPECT_EQ(test[1], true);
	EXPECT_EQ(test[2], true);

}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


