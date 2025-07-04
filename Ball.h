#pragma once
#include "GameObject.h"

class Bat;

class Ball : public GameObject
{
protected:
	sf::CircleShape shape;
	sf::Vector2f direction;
	float speed = 0.f;
	Bat* bat = nullptr;

	float minX = 0.f;
	float maxX = 0.f;
	float minY = 0.f;
	float maxY = 0.f;

public:
	Ball(const std::string& name = "");
	~Ball() = default;

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

	void Fire(const sf::Vector2f& d, float s);

	void SetBat(Bat* bat) { this->bat = bat; }
};

