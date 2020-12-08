#include "../group_header/group.hpp"

Group::Group(){
	binary_op = "";
	group = 0;
	bank = new GroupBank(this);
	save = 0;
	questionable_save = 0;
	all_saves = new Caretaker();
}

Group::Group(string op){ 
	binary_op = op;
	group = 0;
	bank = new GroupBank(this);
	save = 0;
	questionable_save = 0;
	all_saves = new Caretaker();
	
}

Group::Group(set<Op* >* g, string op){
	group = g;
	binary_op = op;
	bank = new GroupBank(this);
	save = 0;
	questionable_save = 0;
	all_saves = new Caretaker(); //COMEBACk after finishing force_save
	//make it so memento is saved as first state group is in, only if initialized with values	
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

	if(!questionable_save)
		questionable_save = new GoodGroup();
	questionable_save->s_set = this->mutable_set();
	questionable_save->s_op = this->binary_operation();
	
	for(itr = group->begin(); itr != group->end(); ++itr){
		if((*itr)->evaluate() == ele->evaluate()){
			in = true;
			return;
		}
	}
	if(!in)
		group->insert(ele);

	if(this->is_group()){
		//setLastSave used to be here
		std::cout << group->size() << std::endl;
		all_saves->force_save(this, this);
		bank->setLastSave(this);
	}
			
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
	return false; //stub
}

void Group::undo(int x){
	bank->restore(this, x);
}

void Group::back_track(int i){
	if(!all_saves){
		std::cout << "No saves, but we'll make a caretaker for you!" << std::endl;
		all_saves = new Caretaker();
		return;
	}
	save = all_saves->select_save(all_saves->num_saves() - i);
}

void Group::safe_save(){
	if(!all_saves){
		std::cout << "No caretaker, but we'll make one for you!" << std::endl;
		all_saves = new Caretaker();
		all_saves->check_save(this, this);
		return;
	}
	all_saves->check_save(this, this);
	
}

void Group::force_save(){
	if(!all_saves){
		std::cout << "No caretaker, but we'll make one for you!" << std::endl;
		all_saves = new Caretaker();
		all_saves->force_save(this, this);
		return;
	}
	all_saves->force_save(this, this);
}



