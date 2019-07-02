#pragma once
#include <memory>
#include <SFML\Graphics\Sprite.hpp>

namespace Game {
	class Entity {
		struct Data {
			sf::Vector2f position;
			sf::Vector2f bounds;
		};


		struct View {
			std::shared_ptr<sf::Texture> pTexture;
			sf::Sprite sprite;
		};


	public:
		Entity(const sf::Vector2f& startPosition, float maxSpeed, std::shared_ptr<sf::Texture> pTexture);

		Data& GetData();
		const Data& GetData() const;

		const View& GetView() const;

		void UpdateLogic(float dt);
		void UpdateView();


	protected:
		Data _data;
		View _view;

		float _maxSpeed;
	};
}