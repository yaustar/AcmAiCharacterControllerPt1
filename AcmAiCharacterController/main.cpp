#include <SFML\Graphics.hpp>
#include <Game\Game.hpp>
#include <SFML\System\Clock.hpp>
#include <cmath>


int main() {
	const sf::Vector2f WORLD_BOUNDS(640.f, 640.f);
	sf::RenderWindow window(sf::VideoMode((unsigned int)std::round(WORLD_BOUNDS.x), (unsigned int)std::round(WORLD_BOUNDS.y)), "AI Character Controller 1");
	Game::Game game(WORLD_BOUNDS);
	sf::Clock deltaClock;
	sf::Time dt;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		game.Tick(dt.asSeconds());

		window.clear(sf::Color(189, 195, 199));
		game.Render(window);
		window.display();

		dt = deltaClock.restart();
	}

	return 0;
}