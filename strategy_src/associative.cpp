#include "../strategy_header/associative.hpp"

bool Associative::verify(){
	bool isAssoc = true;
    	set<Op*>* s = g->mutable_set();
	OpFactory* f = new OpFactory();

    	set <Op*>::iterator i;
    	set <Op*>::iterator j;
    	set <Op*>::iterator k;

	if(g->binary_operation().size() != 1 && g->binary_operation().at(0) != 'm'){
		//custom
    		for(i = s->begin(); i != s->end(); ++i){
        		for(j = s->begin(); j != s->end(); ++j){
				// (x*y)*z == x*(y*z); were * is group->binary_operation()
				Base* a = f->parse(*i, *j, g->binary_operation(), 1);
            			for(k = s->begin(); k != s->end(); ++k){
					//(x+y)*Z
                			Base* b = f->parse(a, *k, g->binary_operation(), 1);
                                	//(y*z)
					Base* c = f->parse(*j, *k, g->binary_operation(), 1);
					//x*(y*z)
					Base* d = f->parse(*i, c, g->binary_operation(), 1);

                			if(b->evaluate() != d->evaluate()){
                    				isAssoc = false;
                    				return isAssoc;
                			}
            			}
        		}
    		}
	}
	else{
		for(i = s->begin(); i != s->end(); ++i){
                        for(j = s->begin(); j != s->end(); ++j){
                                // (x*y)*z == x*(y*z); were * is group->binary_operation()
				Base* a = f->parse(*i, *j, g->binary_operation(), 0);
				for(k = s->begin(); k != s->end(); ++k){
					//(x+y)*Z
					Base* b = f->parse(a, *k, g->binary_operation(), 0);
					//(y*z)
					Base* c = f->parse(*j, *k, g->binary_operation(), 0);
					//x*(y*z)
					Base* d = f->parse(*i, c, g->binary_operation(), 0);

					if(b->evaluate() != d->evaluate()){
						isAssoc = false;
						return isAssoc;
					}
				}
			}
		}
	}

return isAssoc;
}
