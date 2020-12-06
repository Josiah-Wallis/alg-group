#include "../group_header/group.hpp"

Group::Group(){
	binary_op = "";
	group = 0;
}

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
	else if(group->size() == 0)
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
	if(group->size() == 0)
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

set<Op*>* Group::mutable_set(){
	if(group){
		set<Op*>* stuff = new set<Op*>(*group);
		return stuff;
	}

	return 0;
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

void Group::print() const{
	set<Op*>::iterator itr;

	if(!group)
		std::cout << "Your group has no elements to print!" << std::endl;
	else if(group->size() == 0)
		std::cout << "Your group has no elements to print!" << std::endl;
	else{
		for(itr = group->begin(); itr != group->end(); ++itr){
			std::cout << (*itr)->evaluate() << std::endl;
		}
	}
}

bool Group::is_group() const{
	return true; //stub
}
















