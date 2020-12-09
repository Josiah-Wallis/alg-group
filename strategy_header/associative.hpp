#ifndef _ASSOCIATIVE
#define _ASSOCIATIVE

#include "../group_header/group.hpp"
#include "verifier.hpp"
#include <vector>

class Associative : Verifier{
	public:
		Associative();
        vector<bool> check(int num1, int num2);
        void pass(Group* g);
        void setGroup(Group* group){g = group;};
        virtual bool verify();

	private:
        Group* g;
};

#endif
