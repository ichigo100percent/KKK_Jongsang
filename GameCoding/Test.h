#pragma once
#include "MonoBehaviour.h"

class Test : public MonoBehaviour 
{
	shared_ptr<Transform> _transform = make_shared<Transform>();
	//shared_ptr<Transform> _parent = make_shared<Transform>();


	virtual void Awake() override;
	virtual void Update() override;
};

