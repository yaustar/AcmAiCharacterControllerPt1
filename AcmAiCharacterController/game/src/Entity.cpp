#include <Game\Entity.hpp>
#include <SFML\Window\Keyboard.hpp>


Game::Entity::Entity(const sf::Vector2f &startPosition, float maxSpeed, std::shared_ptr<sf::Texture> pTexture) {
	_maxSpeed = maxSpeed;
		
	_data.position = startPosition;

	// TODO Have this data driven. This is fine to be hard coded for now
	_data.bounds = sf::Vector2f(64.f, 64.f);

	_view.pTexture = pTexture;
	_view.sprite.setTexture(*pTexture);
	_view.sprite.setOrigin(sf::Vector2f(8.f, 8.f));
	_view.sprite.setScale(sf::Vector2f(4.f, 4.f));
}


Game::Entity::Data& Game::Entity::GetData() {
	return _data;
}


const Game::Entity::Data& Game::Entity::GetData() const {
	return _data;
}


const Game::Entity::View& Game::Entity::GetView() const {
	return _view;
}


void Game::Entity::UpdateLogic(float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_data.position.y -= _maxSpeed * dt;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_data.position.y += _maxSpeed * dt;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		_data.position.x -= _maxSpeed * dt;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		_data.position.x += _maxSpeed * dt;
	}
}


void Game::Entity::UpdateView() {
	_view.sprite.setPosition(_data.position);
}
