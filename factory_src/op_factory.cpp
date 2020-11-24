#include "../factory_header/op_factory.hpp"

Base* OpFactory::parse(Base* l, Base* r, string operation, int custom){
	return new Op(5);
}
