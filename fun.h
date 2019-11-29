#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace std;

extern double g_width, g_height;
extern vector<sf::Vector2<double>> att_point;
double get_random(double min, double max);
double get_d(double x0, double y0, double x, double y);

struct coords
{
	double vx,vy;
	double x,y;
	double m;
};

class Obj
{
	coords _c;
	double _r;
	sf::CircleShape shape;
public:
	Obj();
	void draw(sf::RenderWindow &windowRef);
	void reset();
};
