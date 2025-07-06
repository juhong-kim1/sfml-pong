#include "stdafx.h"
#include "Bat.h"

Bat::Bat(const std::string& name, int playerNumber)
	:GameObject(name), playerNumber(playerNumber)
{
}

void Bat::Init()
{
	shape.setSize({5.f,100.f});
	shape.setFillColor(sf::Color::White);
	SetOrigin(Origins::MC);
}

void Bat::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	shape.setPosition(pos);
}

void Bat::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	shape.setRotation(rot);
}

void Bat::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	shape.setScale (s);
}

void Bat::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	shape.setOrigin(o);
}

void Bat::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	Utils::SetOrigin(shape, preset);
}

void Bat::Release()
{
}

void Bat::Reset()
{
	if (playerNumber == 1)
	{
		sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
		SetPosition({ bounds.left + 50.f, bounds.height * 0.5f });

		sf::Vector2f size = shape.getSize();

		minY = bounds.top + size.y * 0.5f;
		maxY = (bounds.top + bounds.height) - size.y * 0.5f;
		minX = bounds.left + shape.getSize().x * 0.5f;
		maxX = bounds.left + bounds.width * 0.5 - 25.f;
	}
	if (playerNumber == 2)
	{
		sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
		SetPosition({ bounds.width - 50.f, bounds.height * 0.5f });

		sf::Vector2f size = shape.getSize();

		minY = bounds.top + size.y * 0.5f;
		maxY = (bounds.top + bounds.height) - size.y * 0.5f;
		minX = bounds.width * 0.5 + 25.f;
		maxX = bounds.width - shape.getSize().x * 0.5f;
	}

}

void Bat::Update(float dt)
{
	if (playerNumber == 1)
	{
		direction.y = InputMgr::GetAxis(Axis::Vertical1);
		//direction.x = InputMgr::GetAxis(Axis::Horizontal1);
	}

	if (playerNumber == 2)
	{
		direction.y = InputMgr::GetAxis(Axis::Vertical2);
		//direction.x = InputMgr::GetAxis(Axis::Horizontal2);
	}

	sf::Vector2f pos = GetPosition() + direction * speed * dt;

	pos.y = Utils::Clamp(pos.y, minY, maxY);
	pos.x = Utils::Clamp(pos.x, minX, maxX);


	SetPosition(pos);


}

void Bat::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
