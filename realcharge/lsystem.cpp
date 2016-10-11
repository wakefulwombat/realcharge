#include "lsystem.h"
#include <deque>
#include <algorithm>

LSystem::LSystem(){

}

void LSystem::initialize(Point center, int box_size, double rot_rad, double direction0, string init_text){
	this->center = center;
	this->box_size = box_size;
	this->rot_rad = rot_rad;
	this->direction_rad = direction0;
	this->text = init_text;

	this->rules.clear();
	this->result_all.clear();
	this->result_onekey.clear();
}

void LSystem::setRule(char charactor, string transform){
	this->rules.insert(make_pair(charactor, transform));
}

void LSystem::translation(){
	string temp;
	temp.clear();

	for (unsigned int i = 0; i < this->text.size(); i++){
		if (this->rules.find(this->text[i]) == this->rules.end()){
			temp += this->text[i];
		}
		else{
			temp += this->rules[this->text[i]];
		}
	}

	this->text.clear();
	this->text = temp;
}

void LSystem::calculate(int repeat){
	for (int i = 0; i < repeat; i++){
		this->translation();
	}

	deque<Point> pos_all;
	deque<Point> pop_pos;
	deque<double> pop_ang;
	Point now = Point();
	double angle = this->direction_rad;

	pos_all.push_back(now);
	for (unsigned int i = 0; i < this->text.size(); i++){
		if (this->text[i] == '+'){
			angle += this->rot_rad;
		}
		else if (this->text[i] == '-'){
			angle -= this->rot_rad;
		}
		else if (this->text[i] == '['){
			pop_pos.push_back(now);
			pop_ang.push_back(angle);
		}
		else if (this->text[i] == ']'){
			now = pop_pos.back();
			angle = pop_ang.back();
			pop_pos.pop_back();
			pop_ang.pop_back();
		}
		else{
			now += Point(cos(angle), sin(angle));
			pos_all.push_back(now);
		}
	}

	Point min = Point();
	Point max = Point();
	for (deque<Point>::iterator it = pos_all.begin(); it != pos_all.end(); ++it){
		if (it->x < min.x) min.x = it->x;
		if (it->y < min.y) min.y = it->y;
		if (it->x > max.x) max.x = it->x;
		if (it->y > max.y) max.y = it->y;
	}

	if ((max.x - min.x) > (max.y - min.y)){
		this->unit_length = 1.0*this->box_size / (max.x - min.x);
	}
	else{
		this->unit_length = 1.0*this->box_size / (max.y - min.y);
	}

	this->start = Point(this->unit_length*(-min.x),this->unit_length*(-min.y));


	pos_all.clear();
	pop_pos.clear();
	pop_ang.clear();

	this->result_all.clear();
	this->result_onekey.clear();
	this->key_chara_list.clear();

	now = this->center + this->start + Point(-this->box_size / 2, -this->box_size / 2);
	angle = this->direction_rad;
	this->result_all.push_back(now);
	this->key_chara_list.push_back('0');

	for (unsigned int i = 0; i < this->text.size(); i++){
		if (this->text[i] == '+'){
			angle += this->rot_rad;
		}
		else if (this->text[i] == '-'){
			angle -= this->rot_rad;
		}
		else if (this->text[i] == '['){
			pop_pos.push_back(now);
			pop_ang.push_back(angle);
		}
		else if (this->text[i] == ']'){
			now = pop_pos.back();
			angle = pop_ang.back();
			pop_pos.pop_back();
			pop_ang.pop_back();
		}
		else{
			now += Point(this->unit_length*cos(angle), this->unit_length*sin(angle));
			this->result_all.push_back(now);
			this->key_chara_list.push_back(this->text[i]);
		}
	}
}

void LSystem::extractionKeyList(char key){
	this->result_onekey.clear();
	for (unsigned int i = 0; i < this->key_chara_list.size();++i){
		if (this->key_chara_list[i] == key){
			this->result_onekey.push_back(this->result_all[i]);
		}
	}
}

void LSystem::sortFromLeft(){
	sort(this->result_all.begin(), this->result_all.end(), [](const Point& p1, const Point& p2){return (p1.x < p2.x); });
}

void LSystem::sortFromRight(){
	sort(this->result_all.begin(), this->result_all.end(), [](const Point& p1, const Point& p2){return (p1.x > p2.x); });
}

void LSystem::sortFromUp(){
	sort(this->result_all.begin(), this->result_all.end(), [](const Point& p1, const Point& p2){return (p1.y < p2.y); });
}

void LSystem::sortFromDown(){
	sort(this->result_all.begin(), this->result_all.end(), [](const Point& p1, const Point& p2){return (p1.y > p2.y); });
}

void LSystem::sortFromCenter(){
	sort(this->result_all.begin(), this->result_all.end(), [this](const Point& p1, const Point& p2){return (((p1.x - this->getCenter().x)*(p1.x - this->getCenter().x) + (p1.y - this->getCenter().y)*(p1.y - this->getCenter().y)) < ((p2.x - this->getCenter().x)*(p2.x - this->getCenter().x) + (p2.y - this->getCenter().y)*(p2.y - this->getCenter().y))); });
}