#ifndef _MEMENTO_H
#define _MEMENTO_H

#include "../group_header/group.hpp"

#include <vector>

class Group;
class GoodGroup;

using namespace std;

class Caretaker{ //Caretaker
	public:
		Caretaker();

		void clear_saves();
		GoodGroup* select_save(int i);
		void check_save(Group*); //place these checks whenever a group is changed, checks if savable
		void force_save(Group*);
		int num_saves();

	private:
		vector<GoodGroup*>* mementos;
};

class GroupBank{ //Originator
	public:
		GroupBank();
		void setLastSave(); //sets current group to last save using memento in group
		GoodGroup* create_memento(); //creates memento using saved data
	private:
		set<Op*>* saved_set;
		string saved_op;
};

class GoodGroup{ //Memento
	public:
		GoodGroup();
		set<Op*>* getSet();
		string getOp(); 

		friend class GroupBank;	

	private:
		set<Op*>* s_set;
		string s_op;
};


#endif
