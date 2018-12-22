#pragma once

#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

namespace Lights
{
	class Traffic_Light
	{
	private:
		int section = 0; //0 - red, 1 - yellow, 2 - green
		float x, y;
		Image map_im;
		Texture map_tex;
		Sprite sp_map;
	public:
		Traffic_Light(float x, float y)
		{
			this->x = x; this->y = y;
			map_im.loadFromFile("D:\\Projects\\images\\light.png");
			map_im.createMaskFromColor(Color(255, 255, 255));
			map_tex.loadFromImage(map_im);
			sp_map.setTexture(map_tex);
			sp_map.setPosition(x, y);
		}
		Sprite & get_sp() { return sp_map; }
		int & get_section() { return section; }
		void set_section(int section) { this->section = section; }

		void change_image()
		{
			if (section == 0)
			{
				sp_map.setTextureRect(IntRect(1, 1, 13, 39));
			}

			if (section == 1)
			{
				sp_map.setTextureRect(IntRect(36, 1, 13, 39));
			}

			if (section == 2)
			{
				sp_map.setTextureRect(IntRect(18, 1, 14, 39));
			}
		}

		void spr_rotation_270()
		{
			sp_map.setRotation(270.f);
		}

		void spr_rotation_90()
		{
			sp_map.setRotation(90.f);
		}
	};
	
	Clock cl_for_lights_highway;
	Clock cl_for_lights_roads;
	float time;
	void change_section_for_highway(Traffic_Light &tl)
	{
		time = cl_for_lights_highway.getElapsedTime().asSeconds();
		if (time <= 4)
		{
			tl.set_section(0);
			tl.change_image();
		}

		if (time > 4 && time <= 6)
		{
			tl.set_section(1);
			tl.change_image();
		}

		if (time > 6 && time <= 16)
		{
			tl.set_section(2);
			tl.change_image();
		}

		if (time > 16 && time <= 18)
		{
			tl.set_section(1);
			tl.change_image();
		}

		if (time > 18)
		{
			time = 0;
			cl_for_lights_highway.restart();
		}
	}

	void change_section_for_parr(Traffic_Light &tl)
	{
		if (time <= 4)
		{
			tl.set_section(2);
			tl.change_image();
		}

		if (time > 4 && time <= 6)
		{
			tl.set_section(1);
			tl.change_image();
		}

		if (time > 6 && time <= 16)
		{
			tl.set_section(0);
			tl.change_image();
		}

		if (time > 16 && time <= 18)
		{
			tl.set_section(1);
			tl.change_image();
		}

		if (time > 18)
		{
			time = 0;
			cl_for_lights_highway.restart();
		}
	}

	void change_section_for_left_right(Traffic_Light &tl)
	{
		time = cl_for_lights_roads.getElapsedTime().asSeconds();
		if (time <= 6)
		{
			tl.set_section(2);
			tl.change_image();
		}

		if (time > 6 && time <= 8)
		{
			tl.set_section(1);
			tl.change_image();
		}

		if (time > 8 && time <= 12)
		{
			tl.set_section(0);
			tl.change_image();
		}

		if (time > 12 && time <= 14)
		{
			tl.set_section(1);
			tl.change_image();
		}

		if (time > 14)
		{
			time = 0;
			cl_for_lights_roads.restart();
		}
	}

	void change_section_for_up_down(Traffic_Light &tl)
	{
		if (time <= 6)
		{
			tl.set_section(0);
			tl.change_image();
		}

		if (time > 6 && time <= 8)
		{
			tl.set_section(1);
			tl.change_image();
		}

		if (time > 8 && time <= 12)
		{
			tl.set_section(2);
			tl.change_image();
		}

		if (time > 12 && time <= 14)
		{
			tl.set_section(1);
			tl.change_image();
		}

		if (time > 14)
		{
			time = 0;
			cl_for_lights_roads.restart();
		}
	}

	Traffic_Light tl1(130, 280); //блок одной параллели
	Traffic_Light tl2(305, 430);
	Traffic_Light tl3(305, 320);
	Traffic_Light tl4(145, 430);

	Traffic_Light tl5(130, 880);
	Traffic_Light tl6(305, 1030);
	Traffic_Light tl7(305, 920);
	Traffic_Light tl8(145, 1030);

	Traffic_Light tl9(130, 1330);
	Traffic_Light tl10(305, 1480);
	Traffic_Light tl11(305, 1370);
	Traffic_Light tl12(145, 1480);

	////////////////////////////////////////////////////////

	Traffic_Light tl13(905, 280); //блок другой параллели
	Traffic_Light tl14(1030, 430);
	Traffic_Light tl15(1035, 320);
	Traffic_Light tl16(915, 430);

	Traffic_Light tl17(905, 880);
	Traffic_Light tl18(1030, 1030);
	Traffic_Light tl19(1035, 920);
	Traffic_Light tl20(915, 1030);

	Traffic_Light tl21(905, 1330);
	Traffic_Light tl22(1030, 1480);
	Traffic_Light tl23(1035, 1370);
	Traffic_Light tl24(915, 1480);




	void change_section()
	{
		change_section_for_highway(tl1); //блок одной параллели
		change_section_for_highway(tl2);
		change_section_for_parr(tl3);
		change_section_for_parr(tl4);

		change_section_for_highway(tl5);
		change_section_for_highway(tl6);
		change_section_for_parr(tl7);
		change_section_for_parr(tl8);

		change_section_for_highway(tl9);
		change_section_for_highway(tl10);
		change_section_for_parr(tl11);
		change_section_for_parr(tl12);

		///////////////////////////////////////////////////////////////
		
		change_section_for_up_down(tl13); //Блок другой парралели
		change_section_for_up_down(tl14);
		change_section_for_left_right(tl15);
		change_section_for_left_right(tl16);

		change_section_for_up_down(tl17);
		change_section_for_up_down(tl18);
		change_section_for_left_right(tl19);
		change_section_for_left_right(tl20);

		change_section_for_up_down(tl21);
		change_section_for_up_down(tl22);
		change_section_for_left_right(tl23);
		change_section_for_left_right(tl24);
	}

	void rotation() //для параллельных светофоров
	{
		tl3.spr_rotation_270();
		tl7.spr_rotation_270();
		tl11.spr_rotation_270();
		tl15.spr_rotation_270();
		tl19.spr_rotation_270();
		tl23.spr_rotation_270();

		tl4.spr_rotation_90();
		tl8.spr_rotation_90();
		tl12.spr_rotation_90();
		tl16.spr_rotation_90();
		tl20.spr_rotation_90();
		tl24.spr_rotation_90();
	}

	void draw_traffic_lights(RenderWindow &w)
	{
		change_section();
		rotation();

		w.draw(tl1.get_sp()); //блок одной параллели
		w.draw(tl2.get_sp());
		w.draw(tl3.get_sp());
		w.draw(tl4.get_sp());

		w.draw(tl5.get_sp());
		w.draw(tl6.get_sp());
		w.draw(tl7.get_sp());
		w.draw(tl8.get_sp());
		
		w.draw(tl9.get_sp());
		w.draw(tl10.get_sp());
		w.draw(tl11.get_sp());
		w.draw(tl12.get_sp());

		////////////////////////////////////////////////////

		w.draw(tl13.get_sp()); //Блок другой парралели
		w.draw(tl14.get_sp());
		w.draw(tl15.get_sp());
		w.draw(tl16.get_sp());

		w.draw(tl17.get_sp());
		w.draw(tl18.get_sp());
		w.draw(tl19.get_sp());
		w.draw(tl20.get_sp());

		w.draw(tl21.get_sp());
		w.draw(tl22.get_sp());
		w.draw(tl23.get_sp());
		w.draw(tl24.get_sp());
	}
}

