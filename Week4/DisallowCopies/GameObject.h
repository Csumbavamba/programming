#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();

	void SetData(unsigned int data);
	unsigned int GetData() const;
	GameObject& Clone() const;
	void Copy(const GameObject& gameObject);

protected:
	unsigned int data;

private:
	GameObject(const GameObject& gameObject);
	GameObject& operator= (const GameObject& gameObject);
};

