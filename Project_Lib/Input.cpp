#include "Input.h"
#include "Core.h"

extern J::Core core;

namespace J
{
	std::vector<Input::key> Input::keys = {};
	math::Vector2 Input::m_MousePosition = math::Vector2::One;

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
	};

	bool Input::Init()
	{
		createKeys();
		
		return true;
	}

	bool Input::Update()
	{
		updateKeys();
		
		return true;
	}

	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			keys.push_back(key);
		}
	}

	void Input::updateKeys()
	{
		std::for_each(keys.begin(), keys.end(),
			[](key& _key) -> void
			{
				updateKey(_key);
			});
	}

	void Input::updateKey(Input::key& _key)
	{
		if (GetFocus())
		{
			if (isKeyDown(_key.keyCode))
				updateKeyDown(_key);
			else
				updateKeyUp(_key);

			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}

	bool Input::isKeyDown(eKeyCode _code)
	{
		return GetAsyncKeyState(ASCII[(UINT)_code]) & 0x8000;
	}

	void Input::updateKeyDown(Input::key& _key)
	{
		if (_key.bPressed == true)
			_key.state = eKeyState::Pressed;
		else
			_key.state = eKeyState::Down;

		_key.bPressed = true;
	}

	void Input::updateKeyUp(Input::key& _key)
	{
		if (_key.bPressed == true)
		{
			_key.state = eKeyState::Up;
		}
		else
			_key.state = eKeyState::None;

		_key.bPressed = false;
	}
	void Input::getMousePositionByWindow()
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(core.GetHwnd(), &mousePos);

		m_MousePosition.x = mousePos.x;
		m_MousePosition.y = mousePos.y;
	}
	void Input::clearKeys()
	{
		for (key& key : keys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
				key.state = eKeyState::Up;
			else if (key.state == eKeyState::Up)
				key.state = eKeyState::None;

			key.bPressed = false;
		}
	}
}