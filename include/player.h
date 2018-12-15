#pragma once

#include <SFML/Graphics.hpp>
#include "view.h"

using namespace sf;

class Player 
{ 
private:
	float x, y, w, h, dx, dy, speed = 0; 
	int dir = 0;
	Image image;
	Texture texture;
	Sprite sprite;
public:
	Player(float x, float y, float w, float h) 
	{  
		this->w = w;
		this->h = h;
		image.loadFromFile("D:\\Projects\\images\\car.png");
		image.createMaskFromColor(Color(255, 255, 255));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		this->x = x;
		this->y = y;
		sprite.setTextureRect(IntRect(0, 0, w, h));  
	}
	void update(float time);
	void set_dir(int dir) { this->dir = dir; }
	void set_speed(float speed) { this->speed = speed; }
	float get_our_car_coor_x() { return x; }
	float get_our_car_coor_y() { return y; }
	Sprite &get_sprite() { return sprite; }
};

void Player::update(float time)
{
	switch (dir)
	{
	case 0:
		dx = speed;
		dy = 0;
		break;
	case 1:
		dx = -speed;
		dy = 0;
		break;
	case 2:
		dx = 0;
		dy = speed;
		break;
	case 3: dx = 0;
		dy = -speed;
		break;
	}

	x += dx * time;
	y += dy * time;

	speed = 0;
	sprite.setPosition(x, y);
}

void our_car_move(Player &p, float &time)
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		p.set_dir(1);
		p.set_speed(0.07);
		p.get_sprite().setTextureRect(IntRect(0, 30, 69, 28));
		get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		p.set_dir(0);
		p.set_speed(0.07);
		p.get_sprite().setTextureRect(IntRect(0, 0, 70, 28));
		get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		p.set_dir(3);
		p.set_speed(0.07);
		p.get_sprite().setTextureRect(IntRect(80, 0, 28, 70));
		get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
	}

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		p.set_dir(2);
		p.set_speed(0.07);
		p.get_sprite().setTextureRect(IntRect(110, 0, 28, 70));
		get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
	}

	p.update(time);
}