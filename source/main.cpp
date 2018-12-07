#include "map.h"
#include "window.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	setlocale(LC_ALL, "ru");
	RenderWindow window(VideoMode(1346, 748), "Misha");
	create_map_sprite();
	while (window.isOpen())
	{
		window.clear();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		draw_map(window);
		window.draw(sp_map);
		window.display();
	}
}
