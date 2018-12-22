#pragma once

#include <SFML/Graphics.hpp>
#include "view.h"
#include "car.h"
#include "traffic_lights.h"
#include <thread>
#include <chrono>

using namespace sf;

namespace Player
{
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
		void set_x(float x) { this->x = x; }
		void set_y(float y) { this->y = y; }
		float get_our_car_coor_x() { return x; }
		float get_our_car_coor_y() { return y; }
		Sprite &get_sprite() { return sprite; }
		float &get_speed() { return speed; }
		int &get_dir() { return dir; }
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
		if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Num1))
		{
			p.set_dir(1);
			p.set_speed(0.05);
			p.get_sprite().setTextureRect(IntRect(0, 30, 69, 28));
			get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Num1))
		{
			p.set_dir(0);
			p.set_speed(0.05);
			p.get_sprite().setTextureRect(IntRect(0, 0, 70, 28));
			get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Num1))
		{
			p.set_dir(3);
			p.set_speed(0.05);
			p.get_sprite().setTextureRect(IntRect(80, 0, 28, 70));
			get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Num1))
		{
			p.set_dir(2);
			p.set_speed(0.05);
			p.get_sprite().setTextureRect(IntRect(110, 0, 28, 70));
			get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Num2))
		{
			p.set_dir(1);
			p.set_speed(0.07);
			p.get_sprite().setTextureRect(IntRect(0, 30, 69, 28));
			get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Num2))
		{
			p.set_dir(0);
			p.set_speed(0.07);
			p.get_sprite().setTextureRect(IntRect(0, 0, 70, 28));
			get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Num2))
		{
			p.set_dir(3);
			p.set_speed(0.07);
			p.get_sprite().setTextureRect(IntRect(80, 0, 28, 70));
			get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Num2))
		{
			p.set_dir(2);
			p.set_speed(0.07);
			p.get_sprite().setTextureRect(IntRect(110, 0, 28, 70));
			get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Num3))
		{
			p.set_dir(1);
			p.set_speed(0.1);
			p.get_sprite().setTextureRect(IntRect(0, 30, 69, 28));
			get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
		}

		if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Num3))
		{
			p.set_dir(0);
			p.set_speed(0.1);
			p.get_sprite().setTextureRect(IntRect(0, 0, 70, 28));
			get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Num3))
		{
			p.set_dir(3);
			p.set_speed(0.1);
			p.get_sprite().setTextureRect(IntRect(80, 0, 28, 70));
			get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Num3))
		{
			p.set_dir(2);
			p.set_speed(0.1);
			p.get_sprite().setTextureRect(IntRect(110, 0, 28, 70));
			get_player_coordinate(p.get_our_car_coor_x(), p.get_our_car_coor_y());
		}

		p.update(time);
	}
	Player our_car(1960, 1130, 70, 28);

	Image image_crash;
	Texture texture_crash;
	Sprite sprite_crash;

	void crash(Player &p, Other_Car::Car &oc, RenderWindow &w)
	{
		if (oc.get_dir() == 0)
		{
			if (p.get_sprite().getPosition().x - oc.get_sprite().getPosition().x < 5 && p.get_sprite().getPosition().x - oc.get_sprite().getPosition().x  > -5)
			{
				if (p.get_sprite().getPosition().y - oc.get_sprite().getPosition().y < 5 && p.get_sprite().getPosition().y - oc.get_sprite().getPosition().y > -5)
				{
					image_crash.loadFromFile("D:\\Projects\\images\\boom.png");
					image_crash.createMaskFromColor(Color(1, 1, 1));

					texture_crash.loadFromImage(image_crash);
					sprite_crash.setTexture(texture_crash);
					sprite_crash.setTextureRect(IntRect(0, 0, 131, 127));
					std::this_thread::sleep_for(chrono::milliseconds(3000));
					w.close();
				}
			}
		}

		if (oc.get_dir() == 1)
		{
			if (p.get_sprite().getPosition().x - oc.get_sprite().getPosition().x < 5 && p.get_sprite().getPosition().x - oc.get_sprite().getPosition().x  > -5)
			{
				if (p.get_sprite().getPosition().y - oc.get_sprite().getPosition().y < 5 && p.get_sprite().getPosition().y - oc.get_sprite().getPosition().y > -5)
				{
					image_crash.loadFromFile("D:\\Projects\\images\\boom.png");
					image_crash.createMaskFromColor(Color(1, 1, 1));

					texture_crash.loadFromImage(image_crash);
					sprite_crash.setTexture(texture_crash);
					sprite_crash.setTextureRect(IntRect(0, 0, 131, 127));
					std::this_thread::sleep_for(chrono::milliseconds(3000));
					w.close();
				}
			}
		}

		if (oc.get_dir() == 2)
		{
			if (p.get_sprite().getPosition().x - oc.get_sprite().getPosition().x < 5 && p.get_sprite().getPosition().x - oc.get_sprite().getPosition().x  > -5)
			{
				if (p.get_sprite().getPosition().y - oc.get_sprite().getPosition().y < 5 && p.get_sprite().getPosition().y - oc.get_sprite().getPosition().y > -5)
				{
					image_crash.loadFromFile("D:\\Projects\\images\\boom.png");
					image_crash.createMaskFromColor(Color(1, 1, 1));

					texture_crash.loadFromImage(image_crash);
					sprite_crash.setTexture(texture_crash);
					sprite_crash.setTextureRect(IntRect(0, 0, 131, 127));
					std::this_thread::sleep_for(chrono::milliseconds(3000));
					w.close();
				}
			}
		}

		if (oc.get_dir() == 3)
		{
			if (p.get_sprite().getPosition().x - oc.get_sprite().getPosition().x < 5 && p.get_sprite().getPosition().x - oc.get_sprite().getPosition().x  > -5)
			{
				if (p.get_sprite().getPosition().y - oc.get_sprite().getPosition().y < 5 && p.get_sprite().getPosition().y - oc.get_sprite().getPosition().y > -5)
				{
					image_crash.loadFromFile("D:\\Projects\\images\\boom.png");
					image_crash.createMaskFromColor(Color(1, 1, 1));

					texture_crash.loadFromImage(image_crash);
					sprite_crash.setTexture(texture_crash);
					sprite_crash.setTextureRect(IntRect(0, 0, 131, 127));
					std::this_thread::sleep_for(chrono::milliseconds(3000));
					w.close();
				}
			}
		}
	}
	void crash_run(RenderWindow &w)
	{
		crash(our_car, Other_Car::oc1, w);
		crash(our_car, Other_Car::oc2, w);
		crash(our_car, Other_Car::oc3, w);
		crash(our_car, Other_Car::oc7, w);
		crash(our_car, Other_Car::oc8, w);
		crash(our_car, Other_Car::oc9, w);
		crash(our_car, Other_Car::oc10, w);
		crash(our_car, Other_Car::oc11, w);
		crash(our_car, Other_Car::oc13, w);
		crash(our_car, Other_Car::oc14, w);
		crash(our_car, Other_Car::oc18, w);
		crash(our_car, Other_Car::oc19, w);
		crash(our_car, Other_Car::oc20, w);
		crash(our_car, Other_Car::oc21, w);
		crash(our_car, Other_Car::oc22, w);
		crash(our_car, Other_Car::oc23, w);
		crash(our_car, Other_Car::oc24, w);
		crash(our_car, Other_Car::oc27, w);
		crash(our_car, Other_Car::oc28, w);
		crash(our_car, Other_Car::oc31, w);
		crash(our_car, Other_Car::oc32, w);
		crash(our_car, Other_Car::oc35, w);
	}

	Font font;
	void message(RenderWindow &w)
	{
		if (Keyboard::isKeyPressed(Keyboard::Num3) && (our_car.get_our_car_coor_x() < 150 || our_car.get_our_car_coor_x() > 300))
		{
			font.loadFromFile("D:\\Projects\\images\\times-new-roman.ttf");
			Text text("", font, 50);
			text.setFillColor(Color::Blue);
			text.setStyle(sf::Text::Bold | sf::Text::Underlined);
			text.setString("OVER SPEED!!!");
			text.setPosition(view.getCenter().x - 700, view.getCenter().y - 500);
			w.draw(text);
		}

		if (our_car.get_our_car_coor_x() < 300 && our_car.get_our_car_coor_x() > 150 && Lights::tl3.get_section() != 2)
		{
			if (our_car.get_dir() == 1 || our_car.get_dir() == 0)
			{
				font.loadFromFile("D:\\Projects\\images\\times-new-roman.ttf");
				Text text("", font, 50);
				text.setFillColor(Color::Blue);
				text.setStyle(sf::Text::Bold | sf::Text::Underlined);
				text.setString("TRAVEL TO READ");
				text.setPosition(view.getCenter().x, view.getCenter().y - 500);
				w.draw(text);
			}
		}

		if (our_car.get_our_car_coor_x() < 900 && our_car.get_our_car_coor_x() > 1050 && Lights::tl15.get_section() != 2)
		{
			if (our_car.get_dir() == 1 || our_car.get_dir() == 0)
			{
				font.loadFromFile("D:\\Projects\\images\\times-new-roman.ttf");
				Text text("", font, 50);
				text.setFillColor(Color::Blue);
				text.setStyle(sf::Text::Bold | sf::Text::Underlined);
				text.setString("TRAVEL TO READ");
				text.setPosition(view.getCenter().x, view.getCenter().y - 500);
				w.draw(text);
			}
		}

		if (our_car.get_our_car_coor_y() > 300 && our_car.get_our_car_coor_y() < 450)
		{
			if ((our_car.get_dir() == 3 || our_car.get_dir() == 2) && Lights::tl1.get_section() != 2)
			{
				font.loadFromFile("D:\\Projects\\images\\times-new-roman.ttf");
				Text text("", font, 50);
				text.setFillColor(Color::Blue);
				text.setStyle(sf::Text::Bold | sf::Text::Underlined);
				text.setString("TRAVEL TO READ");
				text.setPosition(view.getCenter().x, view.getCenter().y - 500);
				w.draw(text);
			}
		}

		if (our_car.get_our_car_coor_y() > 900 && our_car.get_our_car_coor_y() < 1050)
		{
			if ((our_car.get_dir() == 3 || our_car.get_dir() == 2) && Lights::tl13.get_section() != 2)
			{
				font.loadFromFile("D:\\Projects\\images\\times-new-roman.ttf");
				Text text("", font, 50);
				text.setFillColor(Color::Blue);
				text.setStyle(sf::Text::Bold | sf::Text::Underlined);
				text.setString("TRAVEL TO READ");
				text.setPosition(view.getCenter().x, view.getCenter().y - 500);
				w.draw(text);
			}
		}
	}
}