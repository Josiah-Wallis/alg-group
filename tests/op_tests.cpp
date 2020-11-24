#include "gtest/gtest.h"
#include "../op_header/operations.hpp"
#include "../op_header/base.hpp"
#include "../op_header/op.hpp"
#include "../op_header/custom.hpp"
#include "../factory_header/op_factory.hpp"

typedef Op o;

TEST(AddTest, eval){
	o* x = new o(5);
	o* y = new o(6);

	o* u = new o(1);
	o* v = new o(2);

	Add* add1 = new Add(x, y);
	Add* add2 = new Add(add1, u);
	Add* add3 = new Add(v, add2);
	
	EXPECT_EQ(14, add3->evaluate());
}

TEST(SubTest, eval){
	o* x = new o(2);
	o* y = new o(3);
	o* z = new o(4);
	o* u = new o(5);
	
	Sub* sub1 = new Sub(z, y);
	Sub* sub2 = new Sub(sub1, x);
	Sub* sub3 = new Sub(u, sub2);

	EXPECT_EQ(6, sub3->evaluate());
}
	
TEST(DivTest, eval){
	o* x = new o(1);
	o* y = new o(2);
	o* z = new o(3);
	o* u = new o(6);
	
	Div* div1 = new Div(u, y);
	Div* div2 = new Div(div1, z);
	Div* div3 = new Div(x, div2);

	EXPECT_EQ(1, div3->evaluate());
}

TEST(MultTest, eval){
	o* x = new o(2);
	o* y = new o(3);
	o* z = new o(4);
	o* u = new o(5);
	
	Mult* mult1 = new Mult(z, y);
	Mult* mult2 = new Mult(mult1, x);
	Mult* mult3 = new Mult(u, mult2);

	EXPECT_EQ(120, mult3->evaluate());
}

TEST(PowTest, eval){
	o* x = new o(2);
	o* y = new o(2);
	o* z = new o(2);
	o* u = new o(2);
	
	Pow* pow1 = new Pow(z, y);
	Pow* pow2 = new Pow(pow1, x);
	Pow* pow3 = new Pow(u, pow2);

	EXPECT_EQ(65536, pow3->evaluate());
}

TEST(ModMTest, eval){
	o* x = new o(2);
	o* y = new o(3);
	o* z = new o(4);
	o* u = new o(5);
	
	ModM* mod1 = new ModM(z, y, u);
	ModM* mod2 = new ModM(mod1, u, y);
	ModM* mod3 = new ModM(u, mod2, z);

	EXPECT_EQ(mod1->evaluate(), 2);
	EXPECT_EQ(mod2->evaluate(), 1);
	EXPECT_EQ(mod3->evaluate(), 1);
}

TEST(ModPTest, T1){
	o* x = new o(2);
	o* y = new o(3);
	o* z = new o(4);
	o* u = new o(5);
	
	ModP* mod1 = new ModP(z, y, u);
	ModP* mod2 = new ModP(mod1, u , x);
	ModP* mod3 = new ModP(z, mod2, y);

	EXPECT_EQ(2, mod1->evaluate());
	EXPECT_EQ(1, mod2->evaluate());
	EXPECT_EQ(2, mod3->evaluate());
}



int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
