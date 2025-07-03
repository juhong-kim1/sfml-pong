#include "stdafx.h"
#include "InputMgr.h"

std::list<sf::Keyboard::Key> InputMgr::downKeys;
std::list<sf::Keyboard::Key> InputMgr::heldKeys;
std::list<sf::Keyboard::Key> InputMgr::upKeys;
std::list<sf::Mouse::Button> InputMgr::buttonDownKeys;
std::list<sf::Mouse::Button> InputMgr::buttonHeldKeys;
std::list<sf::Mouse::Button> InputMgr::buttonUpKeys;
std::unordered_map<Axis, AxisInfo> InputMgr::axisInfoMap;

void InputMgr::Init()
{
	AxisInfo infoH;
	infoH.axis = Axis::Horizontal;
	infoH.positives.push_back(sf::Keyboard::Right);
	infoH.positives.push_back(sf::Keyboard::D);
	infoH.negatives.push_back(sf::Keyboard::Left);
	infoH.negatives.push_back(sf::Keyboard::A);

	axisInfoMap.insert({ Axis::Horizontal, infoH });

	AxisInfo infoV;
	infoV.axis = Axis::Vertical;
	infoV.positives.push_back(sf::Keyboard::S);
	infoV.positives.push_back(sf::Keyboard::Down);
	infoV.negatives.push_back(sf::Keyboard::W);
	infoV.negatives.push_back(sf::Keyboard::Up);

	axisInfoMap.insert({ Axis::Vertical, infoV });

}

void InputMgr::Clear() 
{
	downKeys.clear();
	upKeys.clear();
	buttonDownKeys.clear();
	buttonUpKeys.clear();
}

void InputMgr::UpdateEvent(const sf::Event& ev) 
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		if (!Contains(heldKeys, ev.key.code))
		{
			downKeys.push_back(ev.key.code);
			heldKeys.push_back(ev.key.code);
		}
		break;
	case sf::Event::KeyReleased:
		Remove(heldKeys, ev.key.code);
		upKeys.push_back(ev.key.code);
		break;

	case sf::Event::MouseButtonPressed:
		if (!Contains(buttonHeldKeys, ev.mouseButton.button))
		{
			buttonDownKeys.push_back(ev.mouseButton.button);
			buttonHeldKeys.push_back(ev.mouseButton.button);
		}
		break;

	case sf::Event::MouseButtonReleased:
		Remove(buttonHeldKeys, ev.mouseButton.button);
		buttonUpKeys.push_back(ev.mouseButton.button);
		break;
	}
	
}

void InputMgr::Update(float dt) 
{
}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	return Contains(downKeys, key);
}

bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return Contains(upKeys, key);
}

bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return Contains(heldKeys, key);
}

bool InputMgr::Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	return std::find(list.begin(), list.end(), key) != list.end();
}

void InputMgr::Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	list.remove(key);
}

float InputMgr::GetAxisRaw(Axis axis)
{
	auto findIt = axisInfoMap.find(axis);
	if (findIt == axisInfoMap.end())
	{
		return 0.f;
	}
	const AxisInfo& axisInfo = findIt->second;

	auto it = heldKeys.rbegin();

	while (it != heldKeys.rend())
	{
		sf::Keyboard::Key code = *it;
		if (Contains(axisInfo.positives, code))
		{
			return 1.f;

		}
		if (Contains(axisInfo.negatives, code))
		{
			return -1.f;

		}
		++it;
	}

	return 0.0f;
}

float InputMgr::GetAxis(Axis axis)
{
	return 0.0f;
}

bool InputMgr::GetMouseButtonDown(sf::Mouse::Button key)
{
	return Contains(buttonDownKeys, key);
}

bool InputMgr::GetMouseButtonUp(sf::Mouse::Button key)
{
	return Contains(buttonUpKeys, key);
}

bool InputMgr::GetMouseButton(sf::Mouse::Button key)
{
	return Contains(buttonHeldKeys, key);
}

bool InputMgr::Contains(const std::list<sf::Mouse::Button>& list, sf::Mouse::Button key)
{
	return std::find(list.begin(), list.end(), key) != list.end();
}

void InputMgr::Remove(std::list<sf::Mouse::Button>& list, sf::Mouse::Button key)
{
	list.remove(key);
}

sf::Vector2i InputMgr::GetMousePosition()
{
	return sf::Mouse::getPosition();
}

