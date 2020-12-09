#ifndef _CUSTOM
#define _CUSTOM

#include "base.hpp"
#include "../factory_header/op_factory.hpp"
#include <string>

using namespace std;

class Custom: public Base{
	public:
		Custom(Base* l, Base* r, string custom_op) : l(l), r(r) {
			set_operation(custom_op);
		}
		virtual double evaluate();
		void set_operation(string ); //helper function for evaluate()
	private:
		Base* l;
		Base* r;
		Base* op;
};

#endif
