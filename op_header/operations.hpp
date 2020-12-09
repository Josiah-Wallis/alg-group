#ifndef _OPERATIONS
#define _OPERATIONS
#include "../group_header/group.hpp"
#include "base.hpp"
#include <cmath>
#include <set>

using namespace std;

class Add: public Base{
	public:
		Add(Base* l, Base* r) : l(l), r(r) {}
		virtual double evaluate() { return l->evaluate() + r->evaluate(); }
		virtual bool is_closed(Group* group) { 
			for(auto i : group->associated_set){
				Base* temp = new Op(i->evaluate() + this->evaluate());
				if(group->associated_set.find(temp) != group->associated_set()){
					return false;
				}
			}
			return true;
		}

	private:
		Base* l;	
		Base* r;
};

class Sub: public Base{
	public:
		Sub(Base* l, Base* r): l(l), r(r) {}
		virtual double evaluate() { return l->evaluate() - r->evaluate(); }
		virtual bool is_closed(Group* group) { 
			for(auto i : group->associated_set){
				Base* temp = new Op(this->evaluate() - i->evaluate());
				if(group->associated_set.find(temp) != group->associated_set()){
					return false;
				}
			}
			return true;
		}
	private:
		Base* l;
		Base* r;
};

class Div: public Base{
	public:
		Div(Base* l, Base* r): l(l), r(r) {}
		virtual double evaluate() { return l->evaluate() / r->evaluate(); }
		virtual bool is_closed(Group* group) { 
			for(auto i : group->associated_set){
				Base* temp = new Op(this->evaluate() / i->evaluate());
				if(group->associated_set.find(temp) != group->associated_set()){
					return false;
				}
			}
			return true;
		}
	private:
		Base* l;
		Base* r;
};

class Mult: public Base{
	public:
		Mult(Base* l, Base* r): l(l), r(r) {}
		virtual double evaluate() { return l->evaluate() * r->evaluate(); }
		virtual bool is_closed(Group* group) { 
			for(auto i : group->associated_set){
				Base* temp = new Op(this->evaluate() * i->evaluate());
				if(group->associated_set.find(temp) != group->associated_set()){
					return false;
				}
			}
			return true;
		}
	private:
		Base* l;
		Base* r;
};

class Pow: public Base{
	 public:
		Pow(Base* l, Base* r): l(l), r(r) {}
		virtual double evaluate() { return pow(l->evaluate(), r->evaluate()); }
		virtual bool is_closed(Group* group) { 
			for(auto i : group->associated_set){
				Base* temp = new Op(this->evaluate() ^ i->evaluate());
				if(group->associated_set.find(temp) != group->associated_set()){
					return false;
				}
			}
			return true;
		}
	private:
		Base* l;
		Base* r;
};

class ModM: public Base{
	public:
		ModM(Base* l, Base* r, Base* m) : l(l), r(r), mod(m) {}
		virtual double evaluate () { return (int)(l->evaluate() * r->evaluate()) % (int)mod->evaluate();}
		virtual bool is_closed(Group* group) { 
			for(auto i : group->associated_set){
				Base* temp = new Op(this->evaluate() * i->evaluate() % (int)mod->evaluate());
				if(group->associated_set.find(temp) != group->associated_set()){
					return false;
				}
			}
			return true;
		}
	private:
		Base* l;
		Base* r;
		Base* mod;
};

class ModP: public Base{
	public:
		ModP(Base* l, Base* r, Base* m): l(l), r(r), mod(m) {}
		virtual double evaluate() { return (int)(l->evaluate() + r->evaluate()) % (int)mod->evaluate(); }
		virtual bool is_closed(Group* group) { 
			for(auto i : group->associated_set){
				Base* temp = new Op(this->evaluate() + i->evaluate() % (int)mod->evaluate());
				if(group->associated_set.find(temp) != group->associated_set()){
					return false;
				}
			}
			return true;
		}
	private:
		Base* l;
		Base* r;
		Base* mod;
};

#endif
