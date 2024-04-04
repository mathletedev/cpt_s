#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

int main() {
	sf::RenderWindow window;
	window.create(sf::VideoMode(500, 500, 32), "SFML Test");

	sf::Texture person_texture;
	person_texture.loadFromFile("static/person.jpg");

	sf::Sprite person_sprite;
	person_sprite.setTexture(person_texture);
	person_sprite.setPosition(sf::Vector2f(250, 250));
	person_sprite.setOrigin(sf::Vector2f(150, 150));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();

			window.clear();

			window.draw(person_sprite);

			window.display();
		}
	}

	return 0;
}
