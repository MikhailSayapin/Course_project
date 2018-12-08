#include <SFML\Graphics.hpp>
#include <iostream>

using namespace sf;

namespace Lights
{
	const int H_MAP = 30;
	const int W_MAP = 50;

	/*
	* 1 - светофор по типу улица - улица
	* 2 - светофор по типу шоссе - улица
	*/

	String Map[H_MAP] =
	{
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"            1                                     ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                   1                              ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
		"                                                  ",
	};

	Image map_im;
	Texture map_tex;
	Sprite sp_map;

	void create_map_sprite()
	{
		map_im.loadFromFile("D:\\Projects\\images\\light.png");
		map_tex.loadFromImage(map_im);
		sp_map.setTexture(map_tex);
	}

	void switching()
	{
		Clock cl;
		while (true)
		{
			float time = cl.getElapsedTime().asMicroseconds();
			cl.restart();
			time /= 800;
			if (time <= 5)
				sp_map.setTextureRect(IntRect(1, 1, 13, 39));
				
			if (time > 5 && time <= 10)
				sp_map.setTextureRect(IntRect(36, 1, 13, 39));
				
			if (time > 10)
				sp_map.setTextureRect(IntRect(18, 1, 14, 39));
		}
	}

	void draw_map(RenderWindow &w)
	{
		for (int i = 0; i < H_MAP; i++)
		{
			for (int j = 0; j < W_MAP; j++)
			{
				switch (Map[i][j])
				{
				case '1':
					switching();
					//sp_map.setTextureRect(IntRect(54, 1, 14, 39));
					break;
				case ' ':
					continue;
				case '2':
					break;
				}

				sp_map.setPosition(j * 14, i * 39);
				w.draw(sp_map);
			}
		}
	}

}