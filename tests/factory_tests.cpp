#include "gtest/gtest.h"
#include "../factory_header/op_factory.hpp"
#include "../op_header/operations.hpp"
#include "../op_header/base.hpp"
#include "../op_header/op.hpp"

typedef OpFactory of;
typedef Op o;

TEST(CustomOpTest, T1){
	
}


TEST(AddOpTest, T1){
	of* factory = new of();
	Base* a = factory->parse(0, 0, "3", 0);
	Base* b = factory->parse(0, 0, "4", 0);

	Base* addOp = factory->parse(a, b, "+", 0); /* Panic, what am i even doing omg*/
	EXPECT_EQ(addOp->evaluate(), 7);	
}

TEST(SubOpTest, T1){
	of* factory = new of();
	o* a = new o(4);
	o* b = new o(3);

	Base* subOp = factory->parse(a, b, "-", 0);
	EXPECT_EQ(subOp->evaluate(), 1);
}

TEST(MultOpTest, T1){
	of* factory = new of();
	o* a = new o(6);
	o* b = new o(9);

	Base* multOp = factory->parse(a, b, "*", 0);
	EXPECT_EQ(multOp->evaluate(), 54);
}

TEST(DivOpTest, T1){
	of* factory = new of();
	o* a = new o(6);
	o* b = new o(2);

	Base* divOp = factory->parse(a, b, "/", 0);
	EXPECT_EQ(divOp->evaluate(), 3);
}

TEST(PowOpTest, T1){
	of* factory = new of();
	o* a = new o(2);
	o* b = new o(3);
	
	Base* powOp = factory->parse(a, b, "**", 0);
	EXPECT_EQ(powOp->evaluate(), 8);
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
