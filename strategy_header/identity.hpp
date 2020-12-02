#ifndef _IDENTITY
#define _IDENTITY

#include "../group_header/group.hpp"
#include "verifier.hpp"
#include <vector>

class Identity : Verifier{
	public:
		Identity();
        vector<bool> check(int num1, int num2);
        void pass(Group* g);
        void setGroup(Group* group){g = group;};
        virtual bool verify();

	private:
        Group* g;
};

#endif
