#include "gtest/gtest.h"
#include "../strategy_header/associative.hpp"
#include "../strategy_header/closure.hpp"
#include "../strategy_header/commutative.hpp"
#include "../strategy_header/identity.hpp"
#include "../strategy_header/inverse.hpp"
#include "../strategy_header/verifier.hpp"

TEST(IdentityTest, T1){
    	set<Op*>* x = new set <Op*> {
		new Op(-1), new Op(1)};
    	string op = "*";
    	Group* g = new Group(x, op);
	Identity* v =  new Identity();
	v->setGroup(g);
	Op* idn = v->getIdentity();
	EXPECT_EQ(idn->evaluate(), 1);
}

TEST(IdentityTest, T2){
	set<Op*>* x = new set <Op*> {
		new Op(1), new Op(3), new Op(5), new Op(7)};
	string op = "modm8";
	Group* g = new Group(x, op);
	Identity* v = new Identity();
	v->setGroup(g);
	Op* idn = v->getIdentity();
	EXPECT_EQ(idn->evaluate(), 1);
}

TEST(IdentityTest, T3){
        set<Op*>* x = new set <Op*> {
                new Op(1), new Op(2), new Op(3)};
        string op = "a*b/2";
        Group* g = new Group(x, op);
        Identity* v = new Identity();
        v->setGroup(g);
        Op* idn = v->getIdentity();
        EXPECT_EQ(idn->evaluate(), 2);
}

TEST(IdentityTest, T4){
        set<Op*>* x = new set <Op*> {
                new Op(1), new Op(2), new Op(3), new Op(4)};
        string op = "a/b+2";
        Group* g = new Group(x, op);
        Identity* v = new Identity();
        v->setGroup(g);
        EXPECT_EQ(v->getIdentity(), nullptr);
}

TEST(IdentityTest, T5){
        set<Op*>* x = new set <Op*> {
                new Op(1), new Op(2), new Op(3)};
        string op = "modp6";
        Group* g = new Group(x, op);
        Identity* v = new Identity();
        v->setGroup(g);
        EXPECT_EQ(v->getIdentity(), nullptr);
}

TEST(AssociativeTest, T1){
        set<Op*>* x = new set <Op*> {
                new Op(1), new Op(5), new Op(9)};
        string op = "+";
        Group* g = new Group(x, op);
        Verifier* v = new Associative();
        v->setGroup(g);
        EXPECT_EQ(v->verify(), true);
}

TEST(AssociativeTest, T2){
        set<Op*>* x = new set <Op*> {
                new Op(1), new Op(3), new Op(3)};
        string op = "modp6";
        Group* g = new Group(x, op);
        Verifier* v = new Associative();
        v->setGroup(g);
        EXPECT_EQ(v->verify(), true);
}

TEST(AssociativeTest, T3){
        set<Op*>* x = new set <Op*> {
                new Op(1), new Op(2), new Op(4)};
        string op = "a/b+2";
        Group* g = new Group(x, op);
        Verifier* v = new Associative();
        v->setGroup(g);
        EXPECT_EQ(v->verify(), false);
}

TEST(AssociativeTest, T4){
        set<Op*>* x = new set <Op*> {
                new Op(1), new Op(3), new Op(5), new Op(7)};
        string op = "modm8";
        Group* g = new Group(x, op);
        Verifier* v = new Associative();
        v->setGroup(g);
        EXPECT_EQ(v->verify(), true);
}

TEST(AssociativeTest, T5){
        set<Op*>* x = new set <Op*> {
                new Op(1), new Op(3)};
        string op = "+";
        Group* g = new Group(x, op);
        Verifier* v = new Associative();
        v->setGroup(g);
        EXPECT_EQ(v->verify(), true);
}

int main(int argc, char **argv){
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
