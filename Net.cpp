#include "stdafx.h"
#include "Net.h"

Net::Net(const std::string& name)
	:GameObject(name)
{
}

void Net::Init()
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	net.setSize({5.f, bounds.height});
	net.setFillColor(sf::Color::White);
	SetOrigin(Origins::TC);
	net.setPosition({ bounds.width * 0.5f, bounds.top });

}

void Net::Release()
{
}

void Net::Reset()
{
}

void Net::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	Utils::SetOrigin(net, preset);
}

void Net::Update(float dt)
{
}

void Net::Draw(sf::RenderWindow& window)
{
	window.draw(net);
}
