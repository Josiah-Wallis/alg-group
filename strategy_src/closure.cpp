#include "../strategy_header/closure.hpp"

bool Closure::verify(){
	bool isClosed = true;
    	set<Op*>* s = g->mutable_set();
    	OpFactory* f = new OpFactory();

    	set <Op*>::iterator i;
    	set <Op*>::iterator j;
	set <Op*>::iterator k;

	Base* a = 0;
    
    	for(i = s->begin(); i != s->end(); ++i){
        	for(j = s->begin(); j != s->end(); ++j){
            		if(g->binary_operation().size() != 1 && g->binary_operation().at(0) != 'm'){
                		a = f->parse(*i, *j, g->binary_operation(), 1);
            		}
            		else {
                		a = f->parse(*i, *j, g->binary_operation(), 0);
            		}
			for(k = s->begin(); k != s->end(); ++k){
				if(a->evaluate() != (*k)->evaluate()){
					isClosed = false;
				}
				else{
					isClosed = true;
					break;
				}
			}
			if(isClosed == false){
				return isClosed;
			}
        	}
		
    	}
return isClosed;
}
