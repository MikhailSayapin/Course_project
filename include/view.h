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
	if (x < 835)
		temp_x = 835;
	if (y < 520)
		temp_y = 520;
	if (x > 1270)
		temp_x = 1270;
	if (y > 1202)
		temp_y = 1202;
	view.setCenter(temp_x, temp_y);
}
