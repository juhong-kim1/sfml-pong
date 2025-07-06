#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneDev1.h"
#include "SceneDev2.h"
#include "SceneGame.h"
#include <unordered_map>


void SceneMgr::Init()
{
	scenes[SceneIds::Game] = new SceneGame();
	scenes[SceneIds::Dev2] = new SceneDev2();

	for (auto scene : scenes)
	{
		scene.second->Init();
	}

	currentScene = startScene;
	scenes.find(currentScene)->second->Enter();
}

void SceneMgr::Release()
{
	for (auto pair : scenes)
	{
		Scene* scene = pair.second;
		if (pair.first == currentScene)
		{
			scene->Exit();
		}
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

Scene* SceneMgr::GetCurrentScene()
{
	auto scene = scenes.find(currentScene);
	return scene->second;
}

void SceneMgr::ChangeScene(SceneIds id)
{
	nextScene = id;
}

void SceneMgr::Update(float dt)
{
	if (nextScene != SceneIds::None)
	{
		scenes.find(currentScene)->second->Exit();

		currentScene = nextScene;
		nextScene = SceneIds::None;

		scenes.find(currentScene)->second->Enter();
	}

	scenes.find(currentScene)->second->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes.find(currentScene)->second->Draw(window);
}
