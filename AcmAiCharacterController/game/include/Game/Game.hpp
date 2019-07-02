#pragma once
#include <vector>
#include <memory>
#include <SFML\System\Vector2.hpp>

// Forward declarations 
namespace sf {
	class RenderWindow;
}


namespace Game {
	// Forward declartions 
	class Entity;

	class Game {
	public:
		Game(const sf::Vector2f &worldBounds);
		void Tick(float dt);
		void Render(sf::RenderWindow &window);


	private:
		const sf::Vector2f WORLD_BOUNDS;

		void UpdateLogic(float dt);
		void UpdateCollisions();
		void UpdateViews();


		std::vector<std::shared_ptr<Entity>> _entities;
	};
}
