#ifndef _ABSTRACT_FACTORY
#define _ABSTRACT_FACTORY

#include <string>
#include <iostream>
#include "../op_header/operations.hpp"
#include "../op_header/base.hpp"
#include "../op_header/custom.hpp"
#include "../op_header/op.hpp"

using namespace std;

class AbstractFactory{
	public:
		AbstractFactory() {}
		virtual Base* parse(int custom = 0, Base* left, Base* right, string operation) = 0;
};


#endif
