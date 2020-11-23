#ifndef _BASE
#define _BASE

#include <string>

class Base{
	public:
		Base() {}
		virtual double evaluate() = 0;
		virtual bool has_inverse() = 0; //Work on later
		virtual bool is_closed() = 0;//work on later
};

#endif
