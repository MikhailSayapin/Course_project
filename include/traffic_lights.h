#include <SFML\Graphics.hpp>
#include <iostream>
#include <Windows.h>

using namespace sf;

namespace Lights
{
	class Traffic_Light
	{
	private:
		int section = 0; //0 - red, 1 - yellow, 2 - green
		float x, y, w, h;
		Image map_im;
		Texture map_tex;
		Sprite sp_map;
	public:
		Traffic_Light(float x, float y, float w, float h)
		{
			this->x = x; this->y = y;
			this->w = w; this->h = h;
			map_im.loadFromFile("D:\\Projects\\images\\light.png");
			map_tex.loadFromImage(map_im);
			sp_map.setTexture(map_tex);
			sp_map.setTextureRect(IntRect(0, 0, w, h));
			sp_map.setPosition(x, y);
		}
		Sprite & get_sp() { return sp_map; }

		void change_section()
		{
			int timer = 0;
			while (true)
			{
				Sleep(1000);
				if (timer <= 5)
					section = 0;

				if (timer > 5 && timer <= 7)
					section = 1;

				if (timer > 7 && timer <= 12)
					section = 2;

				if (timer > 12)
					timer = 0;
			}
		}


	};
	Traffic_Light tl1(0, 0, 14, 39);
	void draw_traffic_lights(RenderWindow &w)
	{
		w.draw(tl1.get_sp());
	}
}
