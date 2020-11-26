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

int Group::order() const{
	return group->size();
}

const set<Op* >* Group::associated_set() const{
	return group;
}

const string Group::binary_operation() const{
	return binary_op;
}

bool Group::empty(){
	if(group->empty())
		return true;
	else
		return false;
}

void Group::set_group(set<Op* >* g){
	group = g;
}

void Group::set_binary_operation(string op){
	binary_op = op;
}

void Group::insert(Op* ele){
	
}

void Group::remove(Op* ele){
	group->insert(ele);
}

bool Group::is_group() const{
	return true; //stub
}
