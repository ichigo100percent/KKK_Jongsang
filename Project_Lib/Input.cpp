#include "Input.h"

namespace J
{
	vector<Input::key> Input::keys = {};

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

	bool Input::Frame()
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
		for_each(keys.begin(), keys.end(),
			[](key& _key) -> void
			{
				updateKey(_key);
			});
	}

	void Input::updateKey(Input::key& _key)
	{
		if (isKeyDown(_key.keyCode))
		{
			updateKeyDown(_key);
		}
		else
		{
			updateKeyUp(_key);
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
}