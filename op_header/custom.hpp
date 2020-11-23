#ifndef _CUSTOM
#define _CUSTOM

#include "base.hpp"
#include <string>

using namespace std;

class Custom: public Base{
	public:
		Custom(Base* l, Base* r, string custom_op) : l(l), r(r), operation(custom_op) {}
		virtual double evaluate(); // TODO
		virtual bool has_inverse() { return true; }
		virtual bool is_closed() { return true; }
		virtual bool is_inverse(Base *a) { return true; }
	private:
		Base *l;
		Base *r;
		string operation;
};

#endif
