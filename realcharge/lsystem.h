#ifndef _LSYSTEM_
#define _LSYSTEM_

#include <string>
#include <map>
#include <vector>
#include "common.h"
using namespace std;

class LSystem{
private:
	Point center, start;
	string text;
	map<char, string> rules;
	double rot_rad;//回転角度
	double direction_rad;//現在の向いている角度
	double unit_length;//頂点間の長さ
	int box_size;//図形を収める正方形の大きさ

	vector<Point> result_all;
	vector<char> key_chara_list;
	vector<Point> result_onekey;

	void translation();
public:
	LSystem();
	void initialize(Point center, int box_size, double rot_rad, double direction0, string init_text);

	void setRule(char charactor, string transform);

	void calculate(int repeat);
	string getResultText(){ return this->text; }
	vector<Point>& getResultAllPoint(){ return this->result_all; }

	void extractionKeyList(char key);
	vector<Point>& getResultKeyPoint(){ return this->result_onekey; }

	void sortFromLeft();
	void sortFromRight();
	void sortFromUp();
	void sortFromDown();
	void sortFromCenter();

	Point getCenter(){ return this->center; }
};

#endif