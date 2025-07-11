#pragma once
#include "GameObject.h"
class Bat : public GameObject
{
protected:
	sf::RectangleShape shape;
	float speed = 500.f;
	sf::Vector2f direction;
	sf::Keyboard::Key key;
	int playerNumber = 0;

	float minY = 0.f;
	float maxY = 0.f;
	float minX = 0.f;
	float maxX = 0.f;



public:
	Bat(const std::string& name = "", int playerNumber = 0);
	~Bat() = default;


	// GameObject을(를) 통해 상속됨
	void Init() override;

	void Release() override;

	void Reset() override;

	void Update(float dt) override;

	void Draw(sf::RenderWindow& window) override;

	void SetPosition(const sf::Vector2f& pos) override;

	void SetRotation(float rot) override;

	void SetScale(const sf::Vector2f& s) override;

	void SetOrigin(const sf::Vector2f& o) override;

	void SetOrigin(Origins preset) override;

	sf::FloatRect GetGlobalBounds() { return shape.getGlobalBounds(); }

};

