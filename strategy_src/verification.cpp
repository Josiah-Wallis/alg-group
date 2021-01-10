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
		bool in = false;
		for(unsigned i = 0; i < verifier->size(); i++){
			if(typeid(*v).name() == typeid(*(verifier->at(i))).name()){
				in = true;
				break;
			}
		}

		if(!in)
			verifier->push_back(v);
		else
			return;
	}
}

bool* Verification::check(){
	if(!verifier)
		return nullptr;
	bool* x = new bool[verifier->size()];
	
	for(unsigned i = 0; i < verifier->size(); i++){
		if(verifier->at(i)->verify())
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

int Verification::size(){
	if(!verifier)
		return 0;
	else
		return verifier->size();
}


