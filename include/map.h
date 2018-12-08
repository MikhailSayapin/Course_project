#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

namespace Map
{
	const int H_MAP = 11;
	const int W_MAP = 14;

	/*
	* T - äĺđĺâü˙ îáű÷íűĺ
	* Â - ęóńňű
	* Í - äîěŕ
	* F - ěíîăîýňŕćęč
	* S - ĺëü
	* ^ - îáű÷íűĺ äîđîăč ââĺđő-âíčç
	* > - îáű÷íűĺ äîđîăč âďđŕâî - âëĺâî
	* C - ňîđăîâűé öĺíňđ
	* Đ - ďŕđę
	* = - ěŕăčńňđŕëü
	* + - ďĺđĺęđ¸ńňîę
	*/
//
	String Map[H_MAP] =
	{
		"S=SSSS^SSSSSSS",
		"T=TTTT^TTTTTTT",
		">#>>>>+>>>>>>>",
		"S=HHHP^PHHHHHH",
		"S=BBBP^PSSSSPP",
		"S=FFFF^HHHHHPP",
		">#>>>>+>>>>>CC",
		"S=FFFF^FFFFFCC",
		"S=TTTT^TTTTTTT",
		">#>>>>+>>>>>>>",
		"S=SSSS^SSSSSSS",
	};

	Image map_im;
	Texture map_tex;
	Sprite sp_map;

	void create_map_sprite()
	{
		map_im.loadFromFile("D:\\Projects\\images\\map_new.png");
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
				case '=':
					sp_map.setTextureRect(IntRect(0, 150, 150, 150));
					break;
				case 'T':
					sp_map.setTextureRect(IntRect(0, 0, 150, 150));
					break;
				case 'S':
					sp_map.setTextureRect(IntRect(150, 0, 150, 150));
					break;
				case 'P':
					sp_map.setTextureRect(IntRect(150, 150, 150, 150));
					break;
				case '>':
					sp_map.setTextureRect(IntRect(300, 0, 150, 150));
					break;
				case 'C':
					sp_map.setTextureRect(IntRect(300, 150, 150, 150));
					break;
				case 'B':
					sp_map.setTextureRect(IntRect(600, 0, 150, 150));
					break;
				case 'F':
					sp_map.setTextureRect(IntRect(600, 150, 150, 150));
					break;
				case 'H':
					sp_map.setTextureRect(IntRect(450, 0, 150, 150));
					break;
				case '^':
					sp_map.setTextureRect(IntRect(450, 150, 150, 150));
					break;
				case '+':
					sp_map.setTextureRect(IntRect(150, 300, 150, 150));
					break;
				case '#':
					sp_map.setTextureRect(IntRect(0, 300, 150, 150));
					break;
				}
				sp_map.setPosition(j * 150, i * 150);
				w.draw(sp_map);
			}
		}
	}
}
