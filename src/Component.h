#pragma once

class Component
{
public:
	Component(class Actor* owner, int updateOrder = 100);

	virtual ~Component();

	virtual void Update(float deltaTime);

	virtual void ProcessInput();

	const class Actor* GetOwner() const { return mOwner; }
	int GetUpdateOrder() const { return mUpdateOrder; }


private:

	int mUpdateOrder;

	class Actor* mOwner;
};