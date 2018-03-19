#include <iostream>
#include <sstream>

template<typename T> bool 
VarianceEquals(T value, T compare, T range)
{
	return
	{
		(value > (compare - range)) &&
		(value < (compare + range))
	};
}

template<typename T>
std::string ToString(const T& value)
{
	std::ostringstream stringStream;
	stringStream << value << std::endl;
	return (stringStream.str());
}



int main()
{
	float f1 = 10.01f;
	float f2 = 9.99f;

	std::string stringOutput;
	stringOutput.append("f1 = ");
	stringOutput.append(ToString(f1));
	stringOutput.append(", f2 = ");
	stringOutput.append(ToString(f2));

	if (f1 == f2)
		stringOutput.append("; Equal, ");
	stringOutput.append("; Not Equal, ");

	if (VarianceEquals(f1, f2, 0.1f))
	{
		stringOutput.append("but close enough to be equal!");
	}
	else
	{
		stringOutput.append("and not close enough to be equal!");
	}
		
	

	std::cout << stringOutput << std::endl;

	system("pause");

	return 0;
}