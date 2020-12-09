#ifndef _VERIFIER_
#define _VERIFIER_

#include "../group_header/group.hpp"

class Verifier{
	public:
		Verifier(){
	       		g = 0;
       		}
        	void setGroup(Group* group){
            		g = group;
        	}
        	virtual bool verify() = 0;
	protected:
        	Group* g;
};

#endif // _VERIFIER_
