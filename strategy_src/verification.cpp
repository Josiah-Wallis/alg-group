#include "../strategy_header/verification.hpp"
#include "../strategy_header/associative.hpp"
#include "../strategy_header/closure.hpp"
#include "../strategy_header/commutative.hpp"
#include "../strategy_header/identity.hpp"
#include "../strategy_header/inverse.hpp"

Verification::Verification(){
	verifier = 0;
}

void Verification::push_back(Verifier* v){
	if(!verifier)
		verifier = new vector<Verifier*>;
	if(verifier->size() == 0)
		verifier->push_back(v);
	else{
		Associative assoc;
		Closure clos;
		Commutative comm;
		Identity iden;
		Inverse inv;
		bool in = false;
		for(unsigned i = 0; i < verifier->size(); i++){
			if(typename(*v).name() == typename(assoc).name())
				break;
			else if(typename(*v).name() == typename(clos).name())
				break;
			else if(typename(*v).name() == typename(comm).name())
				break;
			else if(typename(*v).name() == typename(iden).name())
				break;
			else if(typename(*v).name() == typename(inv).name())
				break;
			else
				verifier->push_back(v);
		}
	}
}

bool[] Verification::check(int itr1, int itr2){
	//Function assumes no itr size errors
	bool x[verifier->size()];
	
	for(unsigned i = 0; i < verifier->size(); i++){
		if(verifier->at(i)->verify()){
			x[i] = true;
		else
			x[i] = false;
	}
	return x;
}

void Verification::pass(Group* g){
	//assumes verifier is at least size 1
	for(unsigned i = 0; i < verifier->size(); i++){
		verifier->at(i)->setGroup(g);
	}
}


