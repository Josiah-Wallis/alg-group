#ifndef _OPERATIONS
#define _OPERATIONS

#include "base.hpp"
#include <cmath>

using namespace std;

class Add: public Base{
	public:
		Add(Base* l, Base* r) : l(l), r(r) {}
		virtual double evaluate() { return l->evaluate() + r->evaluate(); }
		virtual bool has_inverse() { return true; }
		virtual bool is_closed() { return true; }
		virtual bool is_inverse(Base *a) { return true; }
	private:
		Base* l;
		Base* r;
};

class Sub: public Base{
	public:
		Sub(Base* l, Base* r): l(l), r(r) {}
		virtual double evaluate() { return l->evaluate() - r->evaluate(); }
		virtual bool has_inverse() { return true; }
		virtual bool is_closed() { return true; }
		virtual bool is_inverse(Base *a) { return true; }
	private:
		Base* l;
		Base* r;
};

class Div: public Base{
	public:
		Div(Base* l, Base* r): l(l), r(r) {}
		virtual double evaluate() { return l->evaluate() / r->evaluate(); }
		virtual bool has_inverse() { return true; }
		virtual bool is_closed() { return true; }
		virtual bool is_inverse(Base* a) { return true;}
	private:
		Base* l;
		Base* r;
};

class Mult: public Base{
	public:
		Mult(Base* l, Base* r): l(l), r(r) {}
		virtual double evaluate() { return l->evaluate() * r->evaluate(); }
		virtual bool has_inverse() { return true; }
		virtual bool is_closed() { return true; }
		virtual bool is_inverse(Base* a) { return true; }
	private:
		Base* l;
		Base* r;
};

class Pow: public Base{
	 public:
		Pow(Base* l, Base* r): l(l), r(r) {}
		virtual double evaluate() { return pow(l->evaluate(), r->evaluate()); }
		virtual bool has_inverse() { return true; }
		virtual bool is_closed() { return true; }
		virtual bool is_inverse(Base* a) { return true; }
	private:
		Base* l;
		Base* r;
};

class ModM: public Base{
	public:
		ModM(Base* l, Base* r, Base* m) : l(l), r(r), mod(m) {}
		virtual double evaluate () { return (l->evaluate() * r->evaluate()) % m->evaluate();}
		virtual bool has_inverse() { return true; }
		virtual bool is_closed() { return true; }
		virtual bool is_inverse(Base* a) { return true; }
	private:
		Base* l;
		Base* r;
		Base* m;
};

Class ModP: public Base{
	public:
		ModP(Base* l, Base* r, Base* m): l(l), r(r), mod(m) {}
		virtual double evaluate() { return (l->evaluate() + r->evaluate()) % m->evaluate(); }
		virtual bool has_inverse() { return true; }
		virtual bool is_closed() { return true; }
		virtual bool is_inverse(Base* a) { return true; }
	private:
		Base* l;
		Base* r;
		Base* m;
};

#endif
