#ifndef _INVERSE_
#define _INVERSE_

#include "../group_header/group.hpp"
#include "verifier.hpp"

class Inverse : public Verifier{
	public:
		Inverse() : Verifier() {}
        	virtual bool verify();
};

#endif //_INVERSE_
