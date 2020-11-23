#include "gtest/gtest.h"
#include "../op_header/operations.hpp"
#include "../op_header/base.hpp"
#include "../op_header/op.hpp"
#include "../op_header/custom.hpp"

typedef Op o;

TEST(AddTest, T1){
	o* x = new o(5);
	o* y = new o(6);

	o* u = new o(1);
	o* v = new o(2);

	Add* add1 = new Add(x, y);
	Add* add2 = new Add(add1, u);
	Add* add3 = new Add(v, add2);
	
	EXPECT_EQ(14, add3->evaluate());
}

TEST(SubTest, T1){
	o* x = new o(2);
	o* y = new o(3);
	o* z = new o(4);
	o* u = new o(5);
	
	Sub* sub1 = new Sub(z, y);
	Sub* sub2 = new Sub(sub1, x);
	Sub* sub3 = new Sub(u, sub2);

	EXPECT_EQ(6, sub3->evaluate());
}
	



int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
