#ifndef _OP
#define _OP

#include "base.hpp"

class Op : public Base{
	public:
		Op(double x) : value(x), l(0), r(0) {}
		virtual double evaluate() { return value; }
		virtual bool has_inverse() {} //work later
		virtual bool is_closed() {} //work later
		virtual bool is_inverse(Base* a) {}
	private:
		double value;
		Base* l;
		Base* r;
};

#endif
