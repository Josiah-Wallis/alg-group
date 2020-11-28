#include "../factory_header/op_factory.hpp"
#include <cctype>

Base* OpFactory::parse(Base* l, Base* r, string operation, int custom){
	queue<Base*> ops;
	if(custom){
		for(auto i = 0; i < operation.size(); i++){
			if(operation[i] == 'a')
				ops.push(l);
			else if(operation[i] == '+'){
				if(operation[i + 1] == 'b'){
					Add* item = new Add(ops.front(), r);
					ops.pop();
					ops.push(item);
					i++;
				}
				else if(isdigit(operation[i + 1])){
					Op* x = new Op((int)operation[i + 1] - 48);
					Add* item = new Add(ops.front(), x);
					ops.pop();
					ops.push(item);
					i++;
				}
				else
					return 0;
			}
			else if(operation[i] == '-'){
				if(operation[i + 1] == 'b'){
					Sub* item = new Sub(ops.front(), r);
					ops.pop();
					ops.push(item);
					i++;
				}
				else if(isdigit(operation[i + 1])){
					Op* x = new Op((int)operation[i + 1] - 48);
					Sub* item = new Sub(ops.front(), x);
					ops.pop();
					ops.push(item);
					i++;
				}
				else
					return 0;
			}
			else if(operation[i] == '/'){
				if(operation[i + 1] == 'b'){
					Div* item = new Div(ops.front(), r);
					ops.pop();
					ops.push(item);
					i++;
				}
				else if(isdigit(operation[i + 1])){
					Op* x = new Op((int)operation[i + 1] - 48);
					Div* item = new Div(ops.front(), x);
					ops.pop();
					ops.push(item);
					i++;
				}
				else
					return 0;
			}
			else if(operation[i] == '*'){
				if(operation[i + 1] == '*'){
					if(operation[i + 2] == 'b'){
						Pow* item = new Pow(ops.front(), r);
						ops.pop();
						ops.push(item);
						i = i + 2;
					}
					else if(isdigit(operation[i + 2])){
						Op* x = new Op((int)operation[i + 2] - 48);
						Pow* item = new Pow(ops.front(), x);
						ops.pop();
						ops.push(item);
						i = i + 2;
					}
					else
						return 0;
				}
				else if(operation[i + 1] == 'b'){
					Mult* item = new Mult(ops.front(), r);
					ops.pop();
					ops.push(item);
					i++;
				}
				else if(isdigit(operation[i + 1])){
					Op* x = new Op((int)operation[i + 1] - 48);
					Mult* item = new Mult(ops.front(), x);
					ops.pop();
					ops.push(item);
					i++;
				}
				else
					return 0;
			}
			
		}
		return ops.front();


	}
	else{
		if(operation == "+"){
			return new Add(l, r);
		}
		else if(operation == "-"){
			return new Sub(l, r);
		}
		else if(operation == "*"){
			return new Mult(l, r);
		}
		else if(operation == "/"){
			return new Div(l, r);
		}
		else if(operation == "**"){
			return new Pow(l, r);
		}
		else if(isdigit(operation[0])){	/* need to double check */

			return new Op(operation[0] - 48);

		}
		else{
			return 0;
		}
	}
}

iuayhgsdouiayhgdouaygdiuaygdiuaysgd
