#ifndef _OP
#define _OP

#include "base.hpp"
#include "../group_header/group.hpp"

class Op : public Base{
	public:
		Op(double x) : value(x), l(0), r(0) {}
		virtual double evaluate() { return value; }
		virtual bool has_inverse() { return true; } //work later
		virtual bool is_closed() { return true; } //work later
		virtual bool is_inverse(Base* x, Base* identity) { return true; }
		/* will take in x and the identity, perform the group operation 
 		by calling group methods taking in this and x as inputs and checking
		if the result is equal to identity->evaluate() */
	private:
		double value;
		Base* l;
		Base* r;
};

#endif
