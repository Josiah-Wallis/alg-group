#include "../strategy_header/inverse.hpp"
#include "../strategy_header/identity.hpp"

bool Inverse::verify(){
	bool hasInverse = false;

	//a * b = e st e is the identity element
	//if ab = e for some element b, then b = eb = a − 1ab = a − 1e = a - 1

	set<Op*>* s = g->mutable_set();
	OpFactory* f = new OpFactory();
	Identity* v = new Identity();
	v->setGroup(g);

	set <Op*>::iterator i;
	set <Op*>::iterator j;
	Op* e = v->getIdentity();
		if(v->getIdentity() == nullptr){
			return hasInverse;
		}
	Base* b = 0;

	for(i = s->begin(); i != s->end(); ++i){
		for(j = s->begin(); j != s->end(); ++j){
			if(g->binary_operation().size() != 1 && g->binary_operation().at(0) != 'm' ){
				b = f->parse(*i, *j, g->binary_operation(), 1);
			}
			else{
				b = f->parse(*i, *j, g->binary_operation(), 0);
			}
			if(b->evaluate() == e->evaluate()){
                		hasInverse = true;
			}
			else{
				hasInverse = false;
			}
		}
	}
return hasInverse;
}
