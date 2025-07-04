#include "stdafx.h"
#include "Ball.h"
#include "Bat.h"
#include "SceneGame.h"

Ball::Ball(const std::string& name)
{
}

void Ball::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	shape.setPosition(pos);
}

void Ball::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	shape.setRotation(rot);
}

void Ball::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	shape.setScale(s);
}

void Ball::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	shape.setOrigin(o);
}

void Ball::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	Utils::SetOrigin(shape, preset);
}

void Ball::Fire(const sf::Vector2f& d, float s)
{
	direction = d;
	speed = s;
}

void Ball::Init()
{
	shape.setRadius(10.0f);
	shape.setFillColor(sf::Color::Red);
	SetOrigin(Origins::ML);
}

void Ball::Release()
{
}

void Ball::Reset()
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	SetPosition({ bounds.width * 0.5f, bounds.height * 0.5f });


	float radius = shape.getRadius();
	minX = bounds.left - 200.f;
	maxX = (bounds.left + bounds.width) - radius * 2;

	minY = bounds.top + radius;
	maxY = bounds.top + bounds.height - radius;

	direction = { 0.f, 0.f };
	speed = 0.f;
}

void Ball::Update(float dt)
{
	sf::Vector2f pos = GetPosition() + direction * speed * dt;

	if (pos.x < minX)
	{
		if (SCENE_MGR.GetCurrentSceneId() == SceneIds::Game)
		{
			SceneGame* scene = (SceneGame*)SCENE_MGR.GetCurrentScene();
			scene->SetGameOver();
		}
	}
	if (pos.x > maxX)
	{
		pos.x = maxX;
		direction.x *= -1.f;
	}
	if (pos.y < minY)
	{
		pos.y = minY;
		direction.y *= -1.f;
	}
	if (pos.y > maxY)
	{
		pos.y = maxY;
		direction.y *= -1.f;
	}

	if (bat != nullptr)
	{
		const sf::FloatRect& batBounds = bat->GetGlobalBounds();
		if (shape.getGlobalBounds().intersects(batBounds))
		{
			pos.x = batBounds.left + 5;
			direction.x *= -1.f;
		}
	}

	SetPosition(pos);
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
