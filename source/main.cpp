#include "map.h"
#include "traffic_lights.h"
#include "window.h"
#include "player.h"
#include "car.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	setlocale(LC_ALL, "ru");
	RenderWindow window(VideoMode(1680, 1050), "TRAFFIC SIMULATOR");
	view.reset(sf::FloatRect(430, 520, 1680, 1050));
	Map::create_map_sprite();
	Clock cl;
	float current_frame = 0;
	Player our_car(1960, 1130, 70, 28);
	while (window.isOpen())
	{
		float time = cl.getElapsedTime().asMicroseconds();
		cl.restart();
		time /= 800;
		window.setView(view);
		view_map(time);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		our_car_move(our_car, time);
		Other_Car::run(time);
		Map::draw_map(window);
		window.draw(Map::sp_map);
		window.draw(our_car.get_sprite());
		Lights::draw_traffic_lights(window);
		Other_Car::draw(window);
		window.display();
		window.clear();
	}
}