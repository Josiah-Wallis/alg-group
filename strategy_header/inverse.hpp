#ifndef _INVERSE
#define _INVERSE

#include "../group_header/group.hpp"
#include "verifier.hpp"
#include <vector>

class Inverse : Verifier{
	public:
		Inverse();
        vector<bool> check(int num1, int num2);
        void pass(Group* g);
        void setGroup(Group* group){g=group;};
        virtual bool verify();

	private:
        Group* g;
};

#endif
