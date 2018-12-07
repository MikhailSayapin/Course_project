#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

const int H_MAP = 8; //Высота
const int W_MAP = 14;

/*
* T - деревья обычные
* В - кусты
* Н - дома
* F - многоэтажки
* S - ель
* R - обычные дороги
* C - торговый центр
* Р - парк
* M - магистраль
*/

std::string Map[H_MAP] =
{ //Краснодар 
	"TTTTTTMTTTTTTT",
	"SRRRRRMRRRRRRS", //улица Красных Партизан
	"SBBBBBMRRRRRRR",
	"SHHHHHMHHHHHHS",
	"SSSSSSMSSSSSSS",
	"SRRRRRMRRRRRRS", //улица Бабушкина
	"SFFFFFMFFFFFCS",
	"STTTTTMTTTTTTT",
};

Image map_im;
Texture map_tex;
Sprite sp_map;

void create_map_sprite()
{
	map_im.createMaskFromColor(Color(0, 0, 0));
	map_im.loadFromFile("D:\\Projects\\images\\map.png");
	map_tex.loadFromImage(map_im);
	sp_map.setTexture(map_tex);
}



void draw_map(RenderWindow &w)
{
	for (int i = 0; i < H_MAP; i++)
	{
		for (int j = 0; j < W_MAP; j++)
		{
			switch (Map[i][j])
			{
			case 'M':
				sp_map.setTextureRect(IntRect(0, 90, 90, 90));
				break;
			case 'T':
				sp_map.setTextureRect(IntRect(0, 0, 90, 90));
				break;
			case 'S':
				sp_map.setTextureRect(IntRect(90, 0, 90, 90));
				break;
			case 'P':
				sp_map.setTextureRect(IntRect(90, 90, 90, 90));
				break;
			case 'R':
				sp_map.setTextureRect(IntRect(180, 0, 90, 90));
				break;
			case 'C':
				sp_map.setTextureRect(IntRect(180, 90, 90, 90));
				break;
			case 'B':
				sp_map.setTextureRect(IntRect(360, 0, 90, 90));
				break;
			case 'F':
				sp_map.setTextureRect(IntRect(360, 90, 90, 90));
				break;
			case 'H':
				sp_map.setTextureRect(IntRect(270, 0, 90, 90));
				break;
			} 
			sp_map.setPosition(j * 90, i * 90);
			w.draw(sp_map);
		}
	}
}
