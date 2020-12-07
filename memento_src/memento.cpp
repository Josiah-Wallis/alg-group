#include "../memento_header/memento.hpp"

Caretaker::Caretaler() {
	mementos = 0;
}

void Caretaker::clear_saves(){
	if(!mementos)
		return;
	else if(mementos->size() == 0)
		return;
	else{
		for(unsigned i = 0; i < mementos->size(); ++i){
			delete mementos->at(i);
			mementos->at(i) = 0;
		}
	}
}

GoodGroup* Caretaker::select_save(int i) {
	if(!mementos){
		std::cout << "There are no saves on file! Returning NULL" << std::endl;
		return 0;
	}
	else if(mementos->size() == 0){
		std::cout << "There are no saves on file! Returning NULL" << std::endl;
		return 0;
	}
	else if(i >= mementos->size()){
		std::cout << "The selected index is out of range! Returning NULL" << std::endl;
		return 0;
	}
	else
		return mementos->at(i);
		
	
}

void Caretaker::check_save(Group* group) { //finish later
	if(!mementos)
		mementos = new vector<GoodGroup*>;

	if(!group){
		std::cout << "Force save to save a null pointer. Entered group will not be saved" << std::endl;
	else{
		if(group->is_group())
			mementos->push_back(gro
}

void Caretaker::force_save(Group* group) {} //finish later

int Caretaker::num_saves(){
	if(!mementos)
		return 0;
	else
		return mementos->size();
}

GroupBank::GroupBank() {
	saved_set = 0;
	saved_op = "";
}

void GroupBank::setLastSave() {
	if(!group)
		return;
	set<Op*>* x = new set<Op*>(*group);
	save = new GoodGroup();
	save->s_set = x;
	save->s_op = binary_op;
}

GoodGroup* GroupBank::create_memento(){
	GoodGroup* x = new GoodGroup();
	x->s_set = saved_set;
	x->s_op = saved_op;
	return x;
}

GoodGroup::GoodGroup() {
	s_set = 0;
	s_op = "";
}

set<Op*>* GoodGroup::getSet(){
	if(!s_set)
		return 0;
	set<Op*>* x = new set<Op*>(*s_set);
	return x;
}

string GoodGroup::getOp(){
	return s_op;
}




