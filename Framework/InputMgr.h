#pragma once

enum class Axis
{
	Horizontal,
	Vertical,
};

struct AxisInfo
{
	Axis axis;
	std::list<sf::Keyboard::Key> positives; // 1.f
	std::list<sf::Keyboard::Key> negatives; // -1.f

	float sensi = 10.f;
	float value = 0.f;
};

class InputMgr
{
private:
	static std::list<sf::Keyboard::Key> downKeys;
	static std::list<sf::Keyboard::Key> heldKeys;
	static std::list<sf::Keyboard::Key> upKeys;
	static std::list<sf::Mouse::Button> buttonDownKeys;
	static std::list<sf::Mouse::Button> buttonUpKeys;
	static std::list<sf::Mouse::Button> buttonHeldKeys;

	static std::unordered_map<Axis, AxisInfo> axisInfoMap;

public:
	static void Init();
	static void Clear();

	static void UpdateEvent(const sf::Event& ev);
	static void Update(float dt);

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	static bool Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);
	static void Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);

	static float GetAxisRaw(Axis axis);   // -1 0 1 바로 바뀌는 속도 구현
	static float GetAxis(Axis axis);  // 천천히 바뀌는 속도 구현

	static bool GetMouseButtonDown(sf::Mouse::Button key);
	static bool GetMouseButtonUp(sf::Mouse::Button key);
	static bool GetMouseButton(sf::Mouse::Button key);

	static bool Contains(const std::list<sf::Mouse::Button>& list, sf::Mouse::Button key);

	static void Remove(std::list<sf::Mouse::Button>& list, sf::Mouse::Button key);

	static sf::Vector2i GetMousePosition();

};


