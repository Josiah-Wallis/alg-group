#ifndef _CLOSURE_
#define _CLOSURE_

#include "../group_header/group.hpp"
#include "verifier.hpp"

class Closure : public Verifier{
	public:
		Closure(): Verifier() {}
        	virtual bool verify();
};

#endif //_CLOSURE_
