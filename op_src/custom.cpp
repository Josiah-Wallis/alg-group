#include "../op_header/custom.hpp"

void Custom::set_operation(string op_string){
	OpFactory* factory = new OpFactory();
	op = factory->parse(1, l, r, op_string);
		
}

double Custom::evaluate() {
	return op->evaluate();
}

