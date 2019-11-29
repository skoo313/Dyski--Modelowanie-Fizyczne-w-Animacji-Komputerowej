#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "fun.h"
using namespace std;

int main()
{
	srand(time(NULL));

	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(g_width, g_height));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(1);
	rectangle.setPosition(1, 1);
	rectangle.setFillColor(sf::Color::Transparent);
	sf::RenderWindow window(sf::VideoMode(1202,602), "Dyski");
	sf::Event event;

	const int num_of_discs=1000;
	Obj obj[num_of_discs];

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i position = sf::Mouse::getPosition(window);

				att_point.push_back(sf::Vector2<double>(position.x,position.y));
				cout<<att_point.size()<<endl;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{

				if(att_point.size()>0)
					att_point.pop_back();

				for(int i=0; i<num_of_discs; i++)
					obj[i].reset();
				cout<<att_point.size()<<endl;
			}
			// get global mouse position

		}
		sf::sleep(sf::milliseconds(25));
		window.clear();

		for(int i=0; i<num_of_discs; i++)
			obj[i].draw(window);
	//	window.draw(rectangle);
		window.display();
	}

	return 0;
}
