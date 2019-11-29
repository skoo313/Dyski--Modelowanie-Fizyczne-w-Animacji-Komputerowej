#include "fun.h"

using namespace std;

double g_height=600.0, g_width=1200.0;
vector<sf::Vector2<double>> att_point;

Obj::Obj()
{
	_r=get_random(1,10);
	_c.x=get_random(_r,(g_width-_r));
	_c.y=get_random(_r,(g_height-_r));

	_c.m=get_random((5*_r)*1000,100000);

	if(get_random(-1,1)>0)
		_c.vx=get_random(-10,-1);
	else
		_c.vx=get_random(1,10);
	if(get_random(-1,1)>0)
		_c.vy=get_random(-10,-1);
	else
		_c.vy=get_random(1,10);

	shape.setRadius(_r);
	shape.setPosition(_c.x,_c.y);
	shape.setFillColor(sf::Color(get_random(0,255),get_random(0,255),get_random(0,255)));
}
void Obj::draw(sf::RenderWindow &windowRef)
{

	for(size_t i=0; i<att_point.size(); i++)
	{
		double x_p=att_point[i].x;
		double y_p=att_point[i].y;
		double F = get_d(x_p,y_p, _c.x, _c.y);
	    double a = F/_c.m;

		_c.vx+=a;
		_c.vy+=a;
		_c.vx+=(x_p - _c.x) / F;
		_c.vy+=(y_p - _c.y) / F;
	}

	if(_c.x+_c.vx>=g_width-_r || _c.x+_c.vx<=_r )
		_c.vx*=-1;
	if(_c.y+_c.vy>=g_height-_r || _c.y+_c.vy<=_r )
		_c.vy*=-1;

	_c.x += (_c.vx/10);
    _c.y += (_c.vy/10);

	shape.setPosition(_c.x,_c.y);
	windowRef.draw(shape);
}
void Obj::reset()
{
	if(get_random(-1,1)>0)
		_c.vx=get_random(-10,-1);
	else
		_c.vx=get_random(1,10);
	if(get_random(-1,1)>0)
		_c.vy=get_random(-10,-1);
	else
		_c.vy=get_random(1,10);
}

double get_random(double min, double max)
{
  return (max - min) * ( (double)rand() / (double)RAND_MAX ) + min;
}

double get_d(double x0, double y0, double x, double y)
{
	return sqrt((x0 - x)*(x0 - x) + (y0 - y)*(y0 - y));
}
