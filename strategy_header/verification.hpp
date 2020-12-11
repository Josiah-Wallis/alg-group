#ifndef _VERIFICATION
#define _VERIFICATION

#include <iostream>
#include <vector>
#include <typeinfo>
#include "verifier.hpp"
#include "../group_header/group.hpp"

using namespace std;

class Verification{
	public:
		Verification();

		void push_back(Verifier*);
		bool[] check(int, int);
		void pass(Group*);

	private:
		vector<Verifier*> verifier;


#endif
