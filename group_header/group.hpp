#ifndef _GROUP
#define _GROUP

#include "../op_header/op.hpp"
#include "../op_header/operations.hpp"
#include "../op_header/custom.hpp"
#include "../factory_header/op_factory.hpp"
#include "../memento_header/memento.hpp"

#include <iostream>
#include <set>
#include <iterator>
#include <string>

class Op;
class OpFactory;
class GroupBank;
class Caretaker;
class GoodGroup;

using namespace std;

class Group{
	public:
		//Constructors
		Group();
		Group(string );
		Group(set<Op*>*, string );
		
		//Accessors
		int order() const;
		const set<Op*>* associated_set() const;
		const string binary_operation() const;
		bool empty() const;

		//Mutators
		void set_group(set<Op* >* );
		void set_binary_operation(string );
		
		//Basic actions
		void insert(Op* );
		void remove(double );
		set<Op*>* mutable_set();
		void print() const;

		//Primary functions
		bool is_group() const;
		
		//Saved States
		void undo(int); //uses memento to go to last group save
		void back_track(int i); //goes back this many saved group iterations in
		//the memento vector/container
		void safe_save(); //check_sve and update memento if is_group()
		void force_save(); //force saves and updates memento

		int num_saves() const;

		friend class GroupBank;
		friend class Caretaker;

	private:
		set<Op* >* group;
		string binary_op;
		GroupBank* bank;
		GoodGroup* save;
		GoodGroup* questionable_save;
		Caretaker* all_saves;
		//save a memento object in here to save last time group was verified	
};

#endif
