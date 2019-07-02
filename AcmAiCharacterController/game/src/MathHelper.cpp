#include <cmath>
#include <Game\MathHelper.hpp>


const sf::Vector2f& Game::MathHelper::NormaliseVector2f(sf::Vector2f& v) {
	float l = LengthVector2f(v);
	if (l != 0.f) {
		v.x = v.x / l;
		v.y = v.y / l;
	}

	return v;
}


float Game::MathHelper::LengthVector2f(const sf::Vector2f& v) {
	float x2 = v.x * v.x;
	float y2 = v.y * v.y;
	return std::sqrtf(x2 + y2);
}
