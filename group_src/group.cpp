#include "../group_header/group.hpp"

Group::Group(string op){ 
	binary_op = op;
	group = 0;
	
}

Group::Group(set<Op* >* g, string op){
	group = g;
	binary_op = op;
	
}

int Group::order() const{
	if(!group)
		return 0;
	else
		return group->size();
}

const set<Op* >* Group::associated_set() const{
	const set<Op* >* x = group;
	return x;
}

const string Group::binary_operation() const{
	const string x = binary_op;
	return x;
}

bool Group::empty() const{
	if(!group)
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
	set<Op*>::iterator itr;
	bool in = false;

	if(!group)
		return;
	
	for(itr = group->begin(); itr != group->end(); ++itr){
		if((*itr)->evaluate() == ele->evaluate()){
			in = true;
			return;
		}
	}
	if(!in)
		group->insert(ele);
			
}


void Group::remove(double x){
	set<Op*>::iterator itr;
	
	if(!group)
		return;
	
	for(itr = group->begin(); itr != group->end(); ++itr){
		if((*itr)->evaluate() == x)
			group->erase(itr);
	}
}

bool Group::is_group() const{
	return true; //stub
}
