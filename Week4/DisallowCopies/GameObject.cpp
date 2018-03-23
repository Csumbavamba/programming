#include <iostream>

#include "GameObject.h"



GameObject::GameObject()
	:data(0)
{
	std::cout << "GameObject Constructed" << std::endl;
}


GameObject::~GameObject()
{
	std::cout << "GameObject Destructed" << std::endl;
}

void GameObject::SetData(unsigned int data)
{
	this->data = data;
}

unsigned int GameObject::GetData() const
{
	return data;
}

GameObject & GameObject::Clone() const
{
	// TODO: insert return statement here
	GameObject * clone = new GameObject();
	clone->Copy(*this);

	return *clone;
}

void GameObject::Copy(const GameObject & gameObject)
{
	data = gameObject.data;
}
