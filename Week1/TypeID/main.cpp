#include <iostream>

class Cat
{
public:
	virtual ~Cat()
	{
	
	}
};

class Sziami : public Cat
{

};


class Dog
{

};

class Leonberger : public Dog
{

};

int main()
{
	Sziami bObject;
	Cat * aPointer = &bObject;
	Cat& aReference = bObject;

	std::cout << "catPointer " << typeid(*aPointer).name() << std::endl;
	std::cout << "catReference " << typeid(aReference).name() << std::endl;

	Leonberger dObject;
	Dog* cPointer = &dObject;
	Dog& cReference = dObject;

	std::cout << "dogPointer " << typeid(*cPointer).name() << std::endl;
	std::cout << "dogReference " << typeid(cReference).name() << std::endl;

	int wait;
	std::cin >> wait;

	return 0;
}