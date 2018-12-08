#include <SFML\Graphics.hpp>

using namespace sf;

View view;
void view_map(float time)
{
	if (Keyboard::isKeyPressed(Keyboard::D))
		view.move(0.1*time, 0);
	if (Keyboard::isKeyPressed(Keyboard::S))
		view.move(0, 0.1*time);
	if (Keyboard::isKeyPressed(Keyboard::A))
		view.move(-0.1*time, 0);
	if (Keyboard::isKeyPressed(Keyboard::W))
		view.move(0, -0.1*time);
}

void get_player_coordinate(float x, float y)
{
	float temp_x = x;
	float temp_y = y;
	if (x < 850)
		temp_x = 850;
	if (y < 700)
		temp_y = 700;
	if (x > 1250)
		temp_x = 1250;
	if (y > 1120)
		temp_y = 1120;
	view.setCenter(temp_x, temp_y);
}

