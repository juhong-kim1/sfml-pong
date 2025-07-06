#pragma once
#include "GameObject.h"
class UiHud : public GameObject
{
protected:
	sf::Text textScore;

	std::string fontId;


public:
	UiHud(const std::string& name = "");
	~UiHud() override = default;
	
	void SetScore(int score);

	void Init() override;

	void Release() override;

	void Reset() override;

	void Update(float dt) override;

	void Draw(sf::RenderWindow& window) override;

};

