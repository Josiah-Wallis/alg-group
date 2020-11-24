#include "gtest/gtest.h"
#include "../factory_header/op_factory.hpp"
//#include "../op_header/operations.hpp"
#include "../op_header/base.hpp"
#include "../op_header/op.hpp"

typedef OpFactory of;
typedef Op o;

TEST(CustomParse, T1){
	of* factory = new of();
	o* x = new o(5);
	o* y = new o(7);
	o* u = new o(3);
	o* v = new o(2);

	Base* z1 = factory->parse(x, y, "a+b+2" , 1);
	Base* z2 = factory->parse(x, u, "a*b/3" , 1);
	Base* z3 = factory->parse(x, v, "a**b-6", 1);


	EXPECT_EQ(z1->evaluate(), 14);
	EXPECT_EQ(z2->evaluate(), 5);
	EXPECT_EQ(z3->evaluate(), 19);
}


int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

