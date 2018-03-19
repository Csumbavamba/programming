#include <iostream>

class Test
{
public:
	// Make the data equal to the value
	Test(int value)
		:data(value)
	{
	}

	int GetData() { return data; }
private:
	int data;
};

template<class T>

void Swap(T& one, T& two)
{
	T temp(one);
	one = two;
	two = temp;

}

int main()
{
	int firstNumber = 5;
	int secondNumber = 10;

	Swap(firstNumber, secondNumber);

	float float1 = 40.7f;
	float float2 = 55.5f;

	Swap(float1, float2);

	Test x(10);
	Test y(20);

	Swap(x, y);

	system("pause");

	return 0;
}