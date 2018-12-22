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
		float &get_speed() { return speed; }
		int &get_dir() { return dir; }

		void rotate(int deg)
		{
			sprite.setRotation(deg);
		}

		void return_back_right_left()
		{
			if (x < -70)
				x = 2100;
		}

		void return_back_left_right()
		{
			if (x > 2170)
				x = 0;
		}

		void return_back_up_down()
		{
			if (y > 1720)
				y = 0;
		}

		void return_back_down_up()
		{
			if (y < -70)
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
		case 3: 
			dx = 0;
			dy = -speed;
			return_back_down_up();
			break;
		}

		x += dx * time;
		y += dy * time;

		speed = 0;
		sprite.setPosition(x, y);
	}

	void stop_at_the_tl(Car &oc)
	{
		if (oc.get_dir() == 0)
		{
			if ((oc.get_x() >= 149 && oc.get_x() <= 151) && (Lights::tl3.get_section() == 0 || Lights::tl3.get_section() == 1))
				oc.set_x(150);
			
			if ((oc.get_x() >= 899 && oc.get_x() <= 901) && (Lights::tl15.get_section() == 0 || Lights::tl15.get_section() == 1))
				oc.set_x(900);
		}

		if (oc.get_dir() == 1)
		{
			if ((oc.get_x() >= 299 && oc.get_x() <= 301) && (Lights::tl3.get_section() == 0 || Lights::tl3.get_section() == 1))
				oc.set_x(300);

			if ((oc.get_x() >= 1049 && oc.get_x() <= 1051) && (Lights::tl15.get_section() == 0 || Lights::tl15.get_section() == 1))
				oc.set_x(1050);
		}

		if (oc.get_dir() == 2)
		{
			if (oc.get_x() > 100 && oc.get_x() < 400)
			{
				if ((oc.get_y() >= 299 && oc.get_y() <= 301) && (Lights::tl1.get_section() == 0 || Lights::tl1.get_section() == 1))
					oc.set_y(300);

				if ((oc.get_y() >= 1349 && oc.get_y() <= 1351) && (Lights::tl1.get_section() == 0 || Lights::tl1.get_section() == 1))
					oc.set_y(1350);

				if ((oc.get_y() >= 899 && oc.get_y() <= 901) && (Lights::tl1.get_section() == 0 || Lights::tl1.get_section() == 1))
					oc.set_y(900);
			}

			else
			{
				if ((oc.get_y() >= 299 && oc.get_y() <= 301) && (Lights::tl13.get_section() == 0 || Lights::tl13.get_section() == 1))
					oc.set_y(300);

				if ((oc.get_y() >= 899 && oc.get_y() <= 901) && (Lights::tl13.get_section() == 0 || Lights::tl13.get_section() == 1))
					oc.set_y(900);

				if ((oc.get_y() >= 1349 && oc.get_y() <= 1351) && (Lights::tl13.get_section() == 0 || Lights::tl13.get_section() == 1))
					oc.set_y(1350);
			}
		}

		if (oc.get_dir() == 3)
		{
			if (oc.get_x() > 100 && oc.get_x() < 400)
			{
				if ((oc.get_y() >= 449 && oc.get_y() <= 451) && (Lights::tl1.get_section() == 0 || Lights::tl1.get_section() == 1))
					oc.set_y(450);

				if ((oc.get_y() >= 1499 && oc.get_y() <= 1501) && (Lights::tl1.get_section() == 0 || Lights::tl1.get_section() == 1))
					oc.set_y(1500);

				if ((oc.get_y() >= 1049 && oc.get_y() <= 1051) && (Lights::tl1.get_section() == 0 || Lights::tl1.get_section() == 1))
					oc.set_y(1050);
			}

			else
			{
				if ((oc.get_y() >= 449 && oc.get_y() <= 451) && (Lights::tl13.get_section() == 0 || Lights::tl13.get_section() == 1))
					oc.set_y(450);

				if ((oc.get_y() >= 1049 && oc.get_y() <= 1051) && (Lights::tl13.get_section() == 0 || Lights::tl13.get_section() == 1))
					oc.set_y(1050);

				if ((oc.get_y() >= 1449 && oc.get_y() <= 1501) && (Lights::tl13.get_section() == 0 || Lights::tl13.get_section() == 1))
					oc.set_y(1500);
			}
		}
	}

	void other_car_move(Car &p, float &time, int variant)
	{
		if (variant == 1)
		{
			p.get_sprite().setRotation(270);
			p.set_dir(1);
			p.set_speed(0.05);
			stop_at_the_tl(p);
		}

		if (variant == 0)
		{
			p.get_sprite().setRotation(90);
			p.set_dir(0);
			p.set_speed(0.05);
			stop_at_the_tl(p);
		}

		if (variant == 3)
		{
			p.set_dir(3);
			p.set_speed(0.05);
			stop_at_the_tl(p);
		}

		if (variant == 2)
		{
			p.get_sprite().setRotation(180);
			p.set_dir(2);
			p.set_speed(0.05);
			stop_at_the_tl(p);
		}

		if (variant == 4)
		{
			p.set_dir(3);
			p.set_speed(0.07);
			stop_at_the_tl(p);
		}

		if (variant == 5)
		{
			p.set_dir(3);
			p.set_speed(0.1);
			stop_at_the_tl(p);
		}

		if (variant == 6)
		{
			p.get_sprite().setRotation(180.f);
			p.set_dir(2);
			p.set_speed(0.1);
			stop_at_the_tl(p);
		}

		if (variant == 7)
		{
			p.get_sprite().setRotation(180.f);
			p.set_dir(2);
			p.set_speed(0.07);
			stop_at_the_tl(p);
		}
		p.update(time);
	}
	    
	Car oc1(2100, 365, 1);
	Car oc2(1200, 365, 5);
	Car oc3(500, 365, 4);

	Car oc7(0, 385, 3);
	Car oc8(1000, 385, 5);

	Car oc9(970, 0, 6);
	Car oc10(970, 400, 2);
	Car oc11(970, 2000, 5);

	Car oc13(985, 2000, 4);
	Car oc14(985, 700, 5);

	Car oc18(0, 1430, 2);
	Car oc19(1800, 1430, 6);

	Car oc20(0, 1415, 3);
	Car oc21(1800, 1415, 5);
	Car oc22(700, 1415, 1);

	Car oc23(263, 0, 3); //по шоссе вверх медленный
	Car oc24(263, 1600, 1);

	Car oc27(233, 150, 5); //по шоссе вверх быстрый
	Car oc28(233, 2000, 2);

	Car oc31(213, 0, 1); //по шоссе вниз быстрый
	Car oc32(213, 1200, 6);

	Car oc35(183, 150, 3); //по шоссе вниз медленный

	void run(float &time)
	{
		other_car_move(oc1, time, 1);
		other_car_move(oc2, time, 1);
		other_car_move(oc3, time, 1);

		other_car_move(oc7, time, 0);
		other_car_move(oc8, time, 0);

		other_car_move(oc9, time, 2);
		other_car_move(oc10, time, 2);
		other_car_move(oc11, time, 2);

		other_car_move(oc13, time, 3);
		other_car_move(oc14, time, 3);

		other_car_move(oc18, time, 0);
		other_car_move(oc19, time, 0);

		other_car_move(oc20, time, 1);
		other_car_move(oc21, time, 1);
		other_car_move(oc22, time, 1);

		other_car_move(oc23, time, 4);
		other_car_move(oc24, time, 4);

		other_car_move(oc27, time, 5);
		other_car_move(oc28, time, 5);

		other_car_move(oc31, time, 6);
		other_car_move(oc32, time, 6);

		other_car_move(oc35, time, 7);
	}

	void draw(RenderWindow &w)
	{
		w.draw(oc1.get_sprite());
		w.draw(oc2.get_sprite());
		w.draw(oc3.get_sprite());

		w.draw(oc7.get_sprite());
		w.draw(oc8.get_sprite());

		w.draw(oc9.get_sprite());
		w.draw(oc10.get_sprite());
		w.draw(oc11.get_sprite());

		w.draw(oc13.get_sprite());
		w.draw(oc14.get_sprite());

		w.draw(oc18.get_sprite());
		w.draw(oc19.get_sprite());

		w.draw(oc20.get_sprite());
		w.draw(oc21.get_sprite());
		w.draw(oc22.get_sprite());

		w.draw(oc23.get_sprite());
		w.draw(oc24.get_sprite());

		w.draw(oc27.get_sprite());
		w.draw(oc28.get_sprite());

		w.draw(oc31.get_sprite());
		w.draw(oc32.get_sprite());

		w.draw(oc35.get_sprite());
	}
}
