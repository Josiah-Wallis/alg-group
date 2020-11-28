#ifndef _GROUP
#define _GROUP

#include "../op_header/op.hpp"
#include "../op_header/operations.hpp"
#include "../op_header/custom.hpp"
#include "../factory_header/op_factory.hpp"

#include <iostream>
#include <set>
#include <iterator>
#include <string>

class Op;
class OpFactory;

using namespace std;

class Group{
	public:
		//Constructors
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

		//Primary function
		bool is_group() const;
		
		//Saved States
		void undo(); //uses memento to go to last group save
		void back_track(int i); //goes back this many saved group iterations in
		//the memento vector/container

	private:
		set<Op* >* group;
		string binary_op;
		//save a memento object in here to save last time group was verified	
};

#endif
