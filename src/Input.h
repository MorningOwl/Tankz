#pragma once
#include <SFML/Window.hpp>


enum class Key { Left, Right, Up, Down, W, A, S, D };

class Input
{
	public:
		bool isKeyHeld(Key key);
};