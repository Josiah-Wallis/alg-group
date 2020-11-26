#include "../group_header/group.hpp"

Group::Group(string op){ 
	binary_op = op;
	group = 0;
	factory = 0;
}

Group::Group(set<Op* >* g, string op){
	group = g;
	binary_op = op;
	factory = 0;
}

int Group::order() const{}

const set<Op* >* Group::associated_set() const{}

const string Group::binary_operation() const{}

bool Group::empty() {}

void Group::set_group(set<Op* >* g){}

void Group::set_binary_operation(string op){}

void Group::insert(Op* ele){}

void Group::remove(Op* ele){}

bool Group::is_group() const{}
