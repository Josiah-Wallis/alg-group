#ifndef _GROUP
#define _GROUP

#include "../op_header/operations.hpp"
#include "../op_header/custom.hpp"
#include "../op_header/op.hpp"
#include "../op_header/base.hpp"
#include "../factory_header/op_factory.hpp"

#include <iostream>
#include <set>
#include <iterator>
#include <string>

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
		void remove(Op* );

		//Primary function
		bool is_group() const;

	private:
		set<Op* >* group;
		string binary_op;
		OpFactory* factory;		
};

#endif
