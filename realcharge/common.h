#ifndef _COMMON_
#define _COMMON_


#define WINDOW_WIDTH 840
#define WINDOW_HEIGHT 630

#define GAME_WINDOW_WIDTH 516
#define GAME_WINDOW_HEIGHT 582

#define GAME_WINDOW_OFFSET_X 24
#define GAME_WINDOW_OFFSET_Y 24

#define GAME_BOARD_OFFSET_X 540
#define GAME_BOARD_OFFSET_Y 24

#define M_PI 3.14159265358980

class Size{
public:
	int width,height;
	Size(){};
	Size(int width,int height);
	Size operator/(const int& i);
	Size operator*(const double& d);
	Size operator+(const Size& obj);
};

class Point{
public:
	double x,y;
	Point();
	Point(double x, double y);
	Point operator+(const Point& obj);
	Point& operator+=(const Point& obj);
	Point operator+(const Size& obj);
	Point operator*(const double& d);
	Point operator/(const double& d);

	static Point getRandomPoint(Point leftup,Point rightdown);
	static Point getCircleRandomPoint(Point center, double r,Point leftup,Point rightdown);
};

extern int Round(double x);

#endif