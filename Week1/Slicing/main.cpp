#include <iostream>

class SuperExample
{
public:
	int data;

	SuperExample()
	{
		data = 0;
	}

	virtual int GetData() const
	{
		return data;
	}

	virtual void Method()
	{
		data = 100;
	}
};


class SubExample : public SuperExample
{
public: 
	int moreData;

	SubExample()
	{
		moreData = 0;
	}

	int GetMoreData() const
	{
		return moreData;
	}

	virtual void Method()
	{
		data = 200;
		moreData = 1000;
	}

};

void PassingByValue(SuperExample instance)
{
	instance.Method();
	std::cout << "Passing by value";
	std::cout << instance.GetData() << std::endl;
}

void PassingByReference(SuperExample& instance)
{
	instance.Method();
	std::cout << "Passing by reference";
	std::cout << instance.GetData() << std::endl;
}

int main()
{
	SubExample subExample;
	SuperExample * parentPointer = &subExample;

	subExample.Method();
	parentPointer->Method();

	PassingByValue(subExample);
	PassingByReference(subExample);

	int wait;
	std::cin >> wait;


	return 0;
}