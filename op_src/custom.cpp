#include "../op_header/custom.hpp"

void Custom::set_operation(string op_string){
	OpFactory* factory = new OpFactory();
	op = factory->parse(l, r, op_string, 1);
		
}

double Custom::evaluate() {
	return op->evaluate();
}

