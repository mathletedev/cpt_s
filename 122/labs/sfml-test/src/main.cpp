#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window;
	window.create(sf::VideoMode(1920, 1200), "SFML Test");

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
