#pragma once
#include "GameObject.h"


class Net : public GameObject
{
protected:
	sf::RectangleShape net;


public:
	Net(const std::string& name = "");
	~Net() = default;

	// GameObject��(��) ���� ��ӵ�
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	void SetOrigin(Origins preset) override;
};

