#ifndef _OP_FACTORY
#define _OP_FACTORY

#include <string>
#include <iostream>
#include <queue>
#include "../op_header/operations.hpp"
#include "../op_header/base.hpp"
#include "../op_header/custom.hpp"
#include "../op_header/op.hpp"

class OpFactory: public AbstractFactory{
	public:
		OpFactory() : AbstractFactory() {}
		virtual Base* parse(int custom = 0, Base* left, Base* right, string oepration);

};

#endif


