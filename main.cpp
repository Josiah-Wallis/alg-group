#include "group_header/group.hpp"

using namespace std;

int main(){
	set<Op*>* stuff = new set<Op*> {new Op(1), new Op(2)};
	string op = "a+b-2";

	Group* group = new Group(stuff, op);

	if(group->is_group())
		cout << "Hazzah! This is an algebraic group!" << endl;
	else
		cout << "This group object does not satisfy all group requirements." << endl;

	return 0;
}

