#pragma once
#include "Scene.h"

class Bat;
class Ball;
class Net;

class SceneGame : public Scene
{
protected:
	Bat* bat = nullptr;
	Bat* bat2 = nullptr;
	Net* net = nullptr;
	Ball* ball = nullptr;

	bool ballActive = false;

public:
	SceneGame();
	~SceneGame();

	void Init() override;
	void Enter() override;
	void Update(float dt) override;

	void SetGameOver();



};

