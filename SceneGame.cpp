#include "stdafx.h"
#include "SceneGame.h"
#include "Bat.h"
#include "Ball.h"
#include "Net.h"
#include "TextGo.h"

SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	fontIds.push_back("fonts/DS-DIGIT.ttf");

	scoreText1 = (TextGo*)AddGameObject(new TextGo("fonts/DS-DIGIT.ttf"));
	scoreText1->SetPosition({ 300.f, 50.f });
	scoreText1->SetCharacterSize(50);
	scoreText1->SetFillColor(sf::Color::White);
	scoreText1->SetString(std::to_string(score1));

	scoreText2 = (TextGo*)AddGameObject(new TextGo("fonts/DS-DIGIT.ttf"));
	scoreText2->SetPosition({ 900.f, 50.f });
	scoreText2->SetCharacterSize(50);
	scoreText2->SetFillColor(sf::Color::White);
	scoreText2->SetString(std::to_string(score2));


	bat = (Bat*)AddGameObject(new Bat("Bat1", 1));
	bat2 = (Bat*)AddGameObject(new Bat("Bat2", 2));
	net = (Net*)AddGameObject(new Net("Net"));
	ball = (Ball*)AddGameObject(new Ball("Ball"));


	ball->SetBat(bat, bat2);

	Scene::Init();
}

void SceneGame::Enter()
{
	ballActive = false;
	Scene::Enter();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);

	if (!ballActive)
	{
		//ball->SetPosition(bat->GetPosition());

		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			ballActive = true;
			sf::Vector2f dir(-1.f, 1.f);
			Utils::Normalize(dir);
			ball->Fire(dir, 500.f);
		}
	}
}

void SceneGame::SetGameOver()
{
	SCENE_MGR.ChangeScene(SceneIds::Game);
}

void SceneGame::UpdateScore()
{
	scoreText1->SetString(std::to_string(score1));
	scoreText2->SetString(std::to_string(score2));
}

void SceneGame::AddScore(int playerNumber)
{
	if (playerNumber == 1)
	{
		score1++;
	}
	else if (playerNumber == 2)
	{
		score2++;
	}
	UpdateScore();

	if (score1 >= 10 || score2 >= 10)
	{
		score1 = 0;
		score2 = 0;
		UpdateScore();
	}

	ballActive = false;
	ball->Reset();

}
