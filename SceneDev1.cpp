#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"

SceneDev1::SceneDev1()
	: Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{
	fontIds.push_back("fonts/DS-DIGIT.ttf");

	TextGo* go = new TextGo("fonts/DS-DIGIT.ttf");
	go->SetString("Dev 1");
	go->SetCharacterSize(30);
	go->SetFillColor(sf::Color::White);
	AddGameObject(go);

	testGo = new TextGo("fonts/DS-DIGIT.ttf");
	testGo->SetString("Dev 1");
	testGo->SetCharacterSize(30);
	testGo->SetFillColor(sf::Color::Red);
	AddGameObject(testGo);

	Scene::Init();
}

void SceneDev1::Update(float dt)
{

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Num1))
	{
		testGo->sortingOrder = 1;
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
	{
		testGo->sortingOrder = -1;
	}
	if (InputMgr::GetMouseButtonDown(sf::Mouse::Button::Left))
	{
		std::cout << "마우스 왼쪽 키 입력" << std::endl;
	}
	if (InputMgr::GetMouseButtonDown(sf::Mouse::Button::Right))
	{
		std::cout << "마우스 오른쪽 키 입력" << std::endl;
	}

	/*sf::Vector2i mousePos = InputMgr::GetMousePosition();
	std::cout  << mousePos.x << ", " << mousePos.y << std::endl;*/


	sf::Vector2f dir;
	dir.x = InputMgr::GetAxisRaw(Axis::Horizontal);
	dir.y = InputMgr::GetAxisRaw(Axis::Vertical);

	sf::Vector2f pos = testGo->GetPosition();
	pos += dir * 100.f * dt;
	testGo->SetPosition(pos);


}