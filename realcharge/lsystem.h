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
	double rot_rad;//��]�p�x
	double direction_rad;//���݂̌����Ă���p�x
	double unit_length;//���_�Ԃ̒���
	int box_size;//�}�`�����߂鐳���`�̑傫��

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