#ifndef _CLOSURE
#define _CLOSURE

#include "../group_header/group.hpp"
#include "verifier.hpp"
#include <vector>

class Commutative : Verifier{
	public:
		Commutative();
        vector<bool> check(int num1, int num2);
        void pass(Group* g);
        void setGroup(Group* group){g = group;};
        virtual bool verify();

	private:
        Group* g;
};

#endif
