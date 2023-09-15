#include "Base.hpp"

Base *generate(void){
    int random = (rand() % 3) + 1;
    switch (random)
    {
        case 1:
            return (static_cast<Base*>(new A));
        case 2:
            return (static_cast<Base*>(new B));
        case 3:
            return (static_cast<Base*>(new C));
    }
    return (NULL);
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A";
    if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B";
    if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C";
}

void identify(Base &p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try{
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try{
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
}

int main(void){
    //srand(time(NULL));
    Base *base = generate();
    if (!base)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    std::cout << "***** Identify with pointer *****\n";
    identify(base);
    std::cout << std::endl;
    std::cout << "***** Identify with reference *****\n";
    identify(*base);
    std::cout << std::endl;

    delete base;
    return (0);
}