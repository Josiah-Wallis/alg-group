#include "../strategy_header/commutative.hpp"

bool Commutative::verify(){
    bool isComm = true;
    set<Op*>* s = g->mutable_set();
    OpFactory* f = new OpFactory();

    set <Op*>::iterator i;
    set <Op*>::iterator j;

    Base* a = 0;
    Base* b = 0;

    for(i = s->begin(); i != s->end(); ++i){
        for(j = s->begin(); j != s->end(); ++j){
            if(g->binary_operation().size() != 1 && g->binary_operation().at(0) != 'm'){
                a = f->parse(*i, *j, g->binary_operation(), 1);
                b = f->parse(*j, *i, g->binary_operation(), 1);
                if(a->evaluate() != b->evaluate()){
                    isComm = false;
                    return isComm;
                }
            }
            else {
                a = f->parse(*i, *j, g->binary_operation(), 0);
                b = f->parse(*j, *i, g->binary_operation(), 0);
                if(a->evaluate() != b->evaluate()){
                    isComm = false;
                    return isComm;
                }
            }
        }
    }
return isComm;
}
