#pragma once
#include <SFML\System\Vector2.hpp>

namespace Game {
	namespace MathHelper {
		// TODO Make these templated to match SFML
		const sf::Vector2f& NormaliseVector2f(sf::Vector2f& v);
		float LengthVector2f(const sf::Vector2f& v);
	}
}