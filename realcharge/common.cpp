#include "common.h"
#include "DxLib.h"
#include <math.h>

Size::Size(int width,int height){
	this->width=width;
	this->height=height;
}

Size Size::operator/(const int& i){
	Size tmp;
	tmp.width=this->width/i;
	tmp.height=this->height/i;

	return tmp;
}

Size Size::operator*(const double& d){
	Size tmp;
	tmp.width = (int)(d*this->width);
	tmp.height = (int)(d*this->height);

	return tmp;
}

Size Size::operator+(const Size& obj){
	Size tmp;
	tmp.width = this->width + obj.width;
	tmp.height = this->height + obj.height;

	return tmp;
}

Point::Point(){
	this->x = 0.000000;
	this->y = 0.000000;
}

Point::Point(double x,double y){
	this->x=x;
	this->y=y;
}

Point Point::operator+(const Point& obj){
	Point tmp;
	tmp.x = this->x+obj.x;
	tmp.y = this->y+obj.y;

	return tmp;
}

Point Point::operator+(const Size& obj){
	Point tmp;
	tmp.x = this->x+(double)obj.width;
	tmp.y = this->y+(double)obj.height;

	return tmp;
}

Point &Point::operator+=(const Point& obj){
	this->x+=obj.x;
	this->y+=obj.y;
	return *this;
}

Point Point::operator*(const double& d){
	Point tmp;
	tmp.x = d*this->x;
	tmp.y = d*this->y;

	return tmp;
}

Point Point::operator/(const double& d){
	Point tmp;
	tmp.x = this->x/d;
	tmp.y = this->y/d;

	return tmp;
}

Point Point::getRandomPoint(Point leftup, Point rightdown){
	Point tmp;
	tmp.x = leftup.x + GetRand((int)(rightdown.x - leftup.x));
	tmp.y = leftup.y + GetRand((int)(rightdown.y - leftup.y));
	return tmp;
}

Point Point::getCircleRandomPoint(Point center, double r, Point leftup, Point rightdown){
	double ang;
	while (true){
		ang = M_PI*GetRand(3600)/1800;
		if ((center.x + r*cos(ang) > leftup.x) && (center.x + r*cos(ang) < rightdown.x) && (center.y + r*sin(ang) > leftup.y) && (center.y + r*sin(ang) < rightdown.y)){
			break;
		}
	}
	return Point(center.x + r*cos(ang), center.y + r*sin(ang));
}