#ifndef _OP_FACTORY
#define _OP_FACTORY

#include <string>
#include <iostream>
#include <queue>
#include "../op_header/operations.hpp"
#include "../op_header/base.hpp"
#include "../op_header/custom.hpp"
#include "../op_header/op.hpp"
#include "abstract_op_factory.hpp"

using namespace std;

class OpFactory : public AbstractFactory{
	public:
		OpFactory() { };
		virtual Base* parse(Base* left, Base* right, string operation, int custom = 0);

};

#endif


