#include "stdafx.h"
#include "Net.h"

Net::Net(const std::string& name)
	:GameObject(name)
{
}

void Net::Init()
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	/*net.setSize({5.f, 50.f});
	net.setFillColor(sf::Color::White);
	SetOrigin(Origins::TC);
	net.setPosition({ bounds.width * 0.5f, bounds.top });*/


    float netX = bounds.width * 0.5f;
    float netWidth = 5.f;
    float netHeight = 15.f;
    float netGap = 15.f;

    net.clear();

    for (float y = 0; y < bounds.height; y += netHeight + netGap)
    {
        sf::RectangleShape net({ netWidth, netHeight });
        net.setFillColor(sf::Color(255, 255, 255, 128));
        net.setOrigin(netWidth * 0.5f, 0.f);
        net.setPosition(netX, y);
        this->net.push_back(net);
    }

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
	//Utils::SetOrigin(net, preset);
}

void Net::Update(float dt)
{
}

void Net::Draw(sf::RenderWindow& window)
{
    for (auto& netPlus : net)
    {
        window.draw(netPlus);
    }
}
