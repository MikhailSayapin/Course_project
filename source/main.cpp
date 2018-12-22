#include "map.h"
#include "traffic_lights.h"
#include "window.h"
#include "player.h"
#include "car.h"
#include "speed_regulation.h"
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

		Player::our_car_move(Player::our_car, time);
		Other_Car::run(time);
		Map::draw_map(window);
		Signs::draw(window);
		window.draw(Map::sp_map);
		window.draw(Player::our_car.get_sprite());
		Lights::draw_traffic_lights(window);
		Other_Car::draw(window);
		Player::crash_run(window);
		Player::message(window);
		window.display();
		window.clear();
	}
}