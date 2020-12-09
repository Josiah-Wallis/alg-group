#ifndef _ASSOCIATIVE_
#define _ASSOCIATIVE_

#include "../group_header/group.hpp"
#include "verifier.hpp"

class Associative : public Verifier{
	public:
		Associative() : Verifier() {}
       		virtual bool verify();
};

#endif //_ASSOCIATIVE_
