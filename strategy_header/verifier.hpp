#ifndef _VERIFIER
#define _VERIFIER

#include "../group_header/group.hpp"
#include <vector>

class Verifier{
	public:
		Verifier();
        vector<bool> check(int num1, int num2);
        void pass(Group* g);
        void setGroup(Group* group){g = group;};
        virtual bool verify() = 0;

	private:
		vector<Verifier* > verifier;
        Group* g;
};

#endif
