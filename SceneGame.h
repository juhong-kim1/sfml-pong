#pragma once
#include "Scene.h"

class Bat;
class Ball;
class Net;
class TextGo;

class SceneGame : public Scene
{
protected:
	Bat* bat = nullptr;
	Bat* bat2 = nullptr;
	Net* net = nullptr;
	Ball* ball = nullptr;

	bool ballActive = false;
	bool isGameOver = false;

	int score1 = 0;
	int score2 = 0;

	TextGo* scoreText1 = nullptr;
	TextGo* scoreText2 = nullptr;
	TextGo* restart = nullptr;

public:
	SceneGame();
	~SceneGame();

	void Init() override;
	void Enter() override;
	void Update(float dt) override;

	void SetGameOver();
	void UpdateScore();
	void AddScore(int playerNumber);



};

