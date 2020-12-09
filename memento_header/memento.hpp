#ifndef _MEMENTO_H
#define _MEMENTO_H

#include "../group_header/group.hpp"

#include <vector>
#include <set>

class Group;
class GoodGroup;
class Op;

using namespace std;

class Caretaker{ //Caretaker
	public:
		Caretaker();

		void clear_saves();
		GoodGroup* select_save(int i);
		void check_save(Group*, Group*); //place these checks whenever a group is changed, checks if savable
		void force_save(Group*, Group*);//group to be saved, group we're working with
		int num_saves();

	private:
		vector<GoodGroup*>* mementos;
};

class GroupBank{ //Originator
	public:
		GroupBank(Group*);
		void setLastSave(Group*); //sets current group to last save using memento in group
		GoodGroup* create_memento(); //creates memento using saved data
		void restore(Group*, int); //rolls back group to last save state
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
		friend class Group; 
		//limited to insert and remove

	private:
		set<Op*>* s_set;
		string s_op;
};


#endif
