#pragma once
#include "GameObject.h"


class Net : public GameObject
{
protected:
	sf::RectangleShape net;


public:
	Net(const std::string& name = "");
	~Net() = default;

	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	void SetOrigin(Origins preset) override;
};

