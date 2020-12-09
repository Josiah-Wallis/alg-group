#ifndef _COMMUTATIVE_
#define _COMMUTATIVE_

#include "../group_header/group.hpp"
#include "verifier.hpp"

class Commutative : public Verifier{
	public:
		Commutative() : Verifier() {}
        	virtual bool verify();
};

#endif //_COMMUTATIVE_
