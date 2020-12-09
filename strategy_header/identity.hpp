#ifndef _IDENTITY_
#define _IDENTITY_

#include "../group_header/group.hpp"
#include "verifier.hpp"

class Identity : public Verifier{
	public:
		Identity() : Verifier() {
            		identity = 0;
       		}
        	virtual bool verify();
        	Op* getIdentity(){
            		return identity;
        	}
};

#endif //_IDENTITY_
