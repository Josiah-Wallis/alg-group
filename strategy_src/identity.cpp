#include "../strategy_header/identity.hpp"
#include <iterator> 
#include <set>

Op* Identity::getIdentity(){
	// ae = ea = a 
 	//check all binary combos ae
    	//check all binary combos ea
    
    	set <Op*>::iterator i;
    	set <Op*>::iterator j;
    	set <Op*>::iterator k;
    
    	set<Op*>* s = g->mutable_set();
	OpFactory* f = new OpFactory();
    
//need to check if binary operation is size one or binary op[0] = 'm'
//use factory, pass in op, make custom val 0
//else use custom
	for(i = s->begin(); i != s->end(); ++i){
		Base* b = 0;
    		Op* e = *i; 
		bool loop1 = true;
		bool loop2 = true;
			for(j = s->begin(); j != s->end(); ++j){
			//check ae = a
				if(g->binary_operation().size() != 1 && g->binary_operation().at(0) != 'm' ){
					b = f->parse(*j, e, g->binary_operation(), 1); // need to fix lol
				}
				else{
					b = f->parse(*j, e, g->binary_operation(), 0);
				}
				if(b->evaluate() != (*j)->evaluate()){
					loop1 = false;
					break;
				}
			}
			
			if (loop1 == false){
				continue;
			}

			for(k = s->begin(); k != s->end(); ++k){
			//check ea = a
				if(g->binary_operation().size() != 1 && g->binary_operation().at(0) != 'm' ){
					b = f->parse(e, *k, g->binary_operation(), 1); // same as above
				}
				else{
					b = f->parse(e, *k, g->binary_operation(), 0);
				} 
				if(b->evaluate() != (*k)->evaluate()){
					loop2 = false;
					break;
				}
			}

			if(loop1 == loop2 && loop1 != false){
				identity =  new Op(e->evaluate());
				return identity;
			}
	}
	
	std::cout << "This group has no identity; Returning null pointer" << std::endl;
	return nullptr;
}

bool Identity::verify(){
	if(getIdentity() != nullptr){
		return true;
	}
	return false;
}
