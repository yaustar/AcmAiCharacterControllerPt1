#include <iostream>
#include <Game\Game.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics.hpp>
#include <Game\Entity.hpp>
#include <SFML\System\Vector2.hpp>


namespace Game {
	std::shared_ptr<sf::Texture> LoadTextureFromFile(const std::string& filename) {
		std::shared_ptr<sf::Texture> pTexture = std::make_shared<sf::Texture>();
		if (!pTexture->loadFromFile(filename)) {
			std::cerr << "Cannot load image file " << filename;
		}

		return pTexture;
	}
}


Game::Game::Game(const sf::Vector2f &worldBounds) : WORLD_BOUNDS(worldBounds) {
		
	// Setup the player entity
	const float MAX_PLAYER_SPEED = 200.f;
	const auto &pPlayerTexture = LoadTextureFromFile("player_no_weapon.png");
	auto pPlayerEntity = std::make_shared<Entity>(sf::Vector2f(480.f, 480.f), MAX_PLAYER_SPEED, pPlayerTexture);		
	_entities.emplace_back(pPlayerEntity);
}


void Game::Game::Tick(float dt) {
	UpdateLogic(dt);
	UpdateCollisions();
	UpdateViews();
}


void Game::Game::Render(sf::RenderWindow& window) {
	for (auto itr = _entities.begin(); itr != _entities.end(); ++itr) {
		window.draw((*itr)->GetView().sprite);
	}
}


void Game::Game::UpdateLogic(float dt) {
	for (auto itr = _entities.begin(); itr != _entities.end(); ++itr) {
		(*itr)->UpdateLogic(dt);
	}
}


void Game::Game::UpdateCollisions() {
	// TODO This is hardcoded for demo purposes but will later be replaced 
	// with something. Perhaps full physics with Box2D or a grid/tile based 
	// collision system

	// Check left, right, top bounds
	for (auto itr = _entities.begin(); itr != _entities.end(); ++itr) {
		auto& data = (*itr)->GetData();
		float halfW = data.bounds.x / 2.f;
		float halfH = data.bounds.y / 2.f;
			
		if (data.position.x - (halfW) < 0.f) {
			data.position.x = 0.f + halfW;
		} else if (data.position.x + (halfW) > WORLD_BOUNDS.x) {
			data.position.x = WORLD_BOUNDS.x - halfW;
		}

		if (data.position.y - (halfH) < 0.f) {
			data.position.y = 0.f + halfH;
		} else if (data.position.y + (halfH) > WORLD_BOUNDS.y) {
			data.position.y = WORLD_BOUNDS.y - halfH;
		}
	}
}

	
void Game::Game::UpdateViews() {
	for (auto itr = _entities.begin(); itr != _entities.end(); ++itr) {
		(*itr)->UpdateView();
	}
}