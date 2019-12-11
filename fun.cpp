#include "pch.h"
#include "fun.h"


double g_height=600.0, g_width=1200.0;
vector<sf::Vector2<double>> att_point;

Obj::Obj()
{
	_r=get_random(1,10);
	_c.x=get_random(_r,(g_width-_r));
	_c.y=get_random(_r,(g_height-_r));

	_m=get_random((100*_r),(1000*_r));

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
	double dt=0.06;

	for(size_t i=0; i<att_point.size(); i++)
	{
		//punkty przyciągania
		double x_p=att_point[i].x;
		double y_p=att_point[i].y;

		//siła F=1/(d-2)
		double F =  1 / (get_d(x_p,y_p, _c.x, _c.y)-2);

		//kierunki działania sił
		double F_x=(x_p-_c.x),
			   F_y=(y_p-_c.y);

		//siła na obie wsp
		F_x=F_x*F;
		F_y=F_y*F;

		//przyspieszenie
		double a_x = F_x / _m,
			   a_y = F_y / _m;

		//finalna predkosc z przyspieszeniem i sila
		_c.vx +=a_x+ F_x;
		_c.vy +=a_y+ F_y;
	}

	if(_c.x+_c.vx>=g_width-_r || _c.x+_c.vx<=_r )
		_c.vx*=-1;
	if(_c.y+_c.vy>=g_height-_r || _c.y+_c.vy<=_r )
		_c.vy*=-1;

	_c.x += _c.vx *dt;
    _c.y += _c.vy *dt;

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