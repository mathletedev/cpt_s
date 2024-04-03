#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

int main() {
	sf::RenderWindow window;
	window.create(sf::VideoMode(500, 500, 32), "SFML Test");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();

			window.clear();

			window.display();
		}
	}

	return 0;
}
