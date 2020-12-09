#include "../memento_header/memento.hpp"

Caretaker::Caretaker() {
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

void Caretaker::check_save(Group* group, Group* current) {
	if(!mementos)
		mementos = new vector<GoodGroup*>;

	if(!group){
		std::cout << "Force save to save a null pointer. Entered group will not be saved" << std::endl;
		return;
	}
	else{
		if(group->is_group()){
			GoodGroup* x = current->bank->create_memento();
			std::cout << "Memento set size: " <<  x->getSet()->size() << std::endl;
			mementos->push_back(x);
			if(!current->save){
				current->save = mementos->at(0);
				std::cout << "Memento set size check 2: " << current->save->getSet()->size() << std::endl;
			}
			else
				current->bank->setLastSave(current);
		}
		else
			std::cout << "The passed object is not a group and will not be safe saved." << std::endl;
	}
}

void Caretaker::force_save(Group* group, Group* current){
	// Let user know this is very dangerous because the functionality assumes last memento is a group
	if(!mementos)
		mementos = new vector<GoodGroup*>;
	current->bank->update(current);
	GoodGroup* x = current->bank->create_memento();
	mementos->push_back(x); //COULD BE ERROR HERE	
	if(!current->save)
		current->save = mementos->at(0);
}

int Caretaker::num_saves(){
	if(!mementos)
		return 0;
	else
		return mementos->size();
}

GroupBank::GroupBank(Group* current) {
	saved_set = current->mutable_set();
	saved_op = current->binary_operation();
}

void GroupBank::setLastSave(Group* current) {
	if(!current->group)
		return;
	set<Op*>* x = current->mutable_set();
	saved_set = x;
	saved_op = current->binary_operation();
	
	current->save = create_memento();
}

GoodGroup* GroupBank::create_memento(){
	GoodGroup* x = new GoodGroup();
	x->s_set = saved_set;
	x->s_op = saved_op;
	return x;
}

void GroupBank::restore(Group* current, int x){
	if(!current->save && x == 1){
		std::cout << "You have no save points to roll back to!" << std::endl;
		return;
	}
	if(!current->questionable_save && x == 0){
		std::cout << "You have no save points to roll back to!" << std::endl;
		return;
	}

	if(!x){
		GroupBank* stuff = new GroupBank(current); //new

		current->group = current->questionable_save->getSet();
		current->binary_op = current->questionable_save->getOp();

		current->questionable_save = stuff->create_memento(); //new
			
	}
	else{
		GroupBank* stuff = new GroupBank(current); //new

		current->group = current->save->getSet();
		current->binary_op = current->save->getOp();

		current->questionable_save = stuff->create_memento(); //new
	}
	
}

void GroupBank::update(Group* current){
	saved_set = current->mutable_set();
	saved_op = current->binary_operation();
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




