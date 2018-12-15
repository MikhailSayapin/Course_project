#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "traffic_lights.h"

using namespace sf;

namespace Other_Car
{
	class Car
	{
	private:
		float x, y, w, h, dx, dy, speed = 0;
		int dir = 0;
		int color; // 1 - фиолетовый, 2 - серый, 3 - зелёный, 4 - жёлтый, 5 - розовый, 6 - рыжий
		int variant;
		Image image;
		Texture texture;
		Sprite sprite;
	public:
		Car(float x, float y, int color)
		{
			image.loadFromFile("D:\\Projects\\images\\cars.png");
			image.createMaskFromColor(Color(255, 255, 255));
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			this->x = x;
			this->y = y;
			this->color = color;
			if (color == 1)
			{
				sprite.setTextureRect(IntRect(0, 0, 26, 65));
			}

			if (color == 2)
			{
				sprite.setTextureRect(IntRect(36, 0, 27, 67));
			}

			if (color == 3)
			{
				sprite.setTextureRect(IntRect(1, 83, 24, 61));
			}

			if (color == 4)
			{
				sprite.setTextureRect(IntRect(72, 83, 25, 66));
			}

			if (color == 5)
			{
				sprite.setTextureRect(IntRect(36, 83, 27, 62));
			}

			if (color == 6)
			{
				sprite.setTextureRect(IntRect(106, 0, 28, 56));
			}
		}

		void set_dir(int dir) { this->dir = dir; }
		void set_speed(float speed) { this->speed = speed; }
		void set_x(float x) { this->x = x; }
		void set_y(float y) { this->y = y; }
		Sprite &get_sprite() { return sprite; }
		float &get_x() { return x; } //Возвращает текущее Х
		float &get_y() { return y; } //Возвращает текущее Y

		void rotate(int deg)
		{
			sprite.setRotation(deg);
		}

		void return_back_right_left()
		{
			if (x < 0)
				x = 2100;
		}

		void return_back_left_right()
		{
			if (x > 2100)
				x = 0;
		}

		void return_back_up_down()
		{
			if (y > 1650)
				y = 0;
		}

		void return_back_down_up()
		{
			if (y < 0)
				y = 1650;
		}

		void update(float time);
	};

	void Car::update(float time)
	{
		switch (dir)
		{
		case 0:
			dx = speed;
			dy = 0;
			return_back_left_right();
			break;
		case 1:
			dx = -speed;
			dy = 0;
			return_back_right_left();
			break;
		case 2:
			dx = 0;
			dy = speed;
			return_back_up_down();
			break;
		case 3: dx = 0;
			dy = -speed;
			return_back_down_up();
			break;
		}

		x += dx * time;
		y += dy * time;

		speed = 0;
		sprite.setPosition(x, y);
	}

	void other_car_move(Car &p, float &time, int variant)
	{
		if (variant == 1)
		{
			p.get_sprite().setRotation(270);
			p.set_dir(1);
			p.set_speed(0.07);
		}

		if (variant == 0)
		{
			p.get_sprite().setRotation(90);
			p.set_dir(0);
			p.set_speed(0.07);
		}

		if (variant == 3)
		{
			p.set_dir(3);
			p.set_speed(0.07);
		}

		if (variant == 2)
		{
			p.get_sprite().setRotation(180);
			p.set_dir(2);
			p.set_speed(0.07);
		}
		p.update(time);
	}

	Car oc1(2100, 365, 1);
	Car oc2(1800, 365, 5);
	Car oc3(1500, 365, 4);
	Car oc4(1200, 365, 6);
	Car oc5(900, 365, 2);
	Car oc6(600, 365, 3);

	Car oc7(0, 385, 3);
	Car oc8(1000, 385, 5);

	Car oc9(970, 0, 6);
	Car oc10(970, 300, 2);
	Car oc11(970, 1300, 5);
	Car oc12(970, 1500, 1);

	Car oc13(985, 1650, 4);
	Car oc14(985, 1430, 5);
	Car oc15(985, 1000, 3);
	Car oc16(985, 700, 6);
	Car oc17(985, 0, 1);

	Car oc18(0, 1430, 2);
	Car oc19(1800, 1430, 6);

	Car oc20(0, 1415, 3);
	Car oc21(1800, 1415, 5);
	Car oc22(700, 1415, 1);

	void run(float &time)
	{
		other_car_move(oc1, time, 1);
		other_car_move(oc2, time, 1);
		other_car_move(oc3, time, 1);
		other_car_move(oc4, time, 1);
		other_car_move(oc5, time, 1);
		other_car_move(oc6, time, 1);

		other_car_move(oc7, time, 0);
		other_car_move(oc8, time, 0);

		other_car_move(oc9, time, 2);
		other_car_move(oc10, time, 2);
		other_car_move(oc11, time, 2);
		other_car_move(oc12, time, 2);

		other_car_move(oc13, time, 3);
		other_car_move(oc14, time, 3);
		other_car_move(oc15, time, 3);
		other_car_move(oc16, time, 3);
		other_car_move(oc17, time, 3);

		other_car_move(oc18, time, 0);
		other_car_move(oc19, time, 0);

		other_car_move(oc20, time, 1);
		other_car_move(oc21, time, 1);
		other_car_move(oc22, time, 1);
	}

	void stop_at_the_tl()
	{
		while()
	}
	void draw(RenderWindow &w)
	{
		w.draw(oc1.get_sprite());
		w.draw(oc2.get_sprite());
		w.draw(oc3.get_sprite());
		w.draw(oc4.get_sprite());
		w.draw(oc5.get_sprite());
		w.draw(oc6.get_sprite());

		w.draw(oc7.get_sprite());
		w.draw(oc8.get_sprite());

		w.draw(oc9.get_sprite());
		w.draw(oc10.get_sprite());
		w.draw(oc11.get_sprite());
		w.draw(oc12.get_sprite());

		w.draw(oc13.get_sprite());
		w.draw(oc14.get_sprite());
		w.draw(oc15.get_sprite());
		w.draw(oc16.get_sprite());
		w.draw(oc17.get_sprite());

		w.draw(oc18.get_sprite());
		w.draw(oc19.get_sprite());

		w.draw(oc20.get_sprite());
		w.draw(oc21.get_sprite());
		w.draw(oc22.get_sprite());
	}
}