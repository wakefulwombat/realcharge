#ifndef _TASKBASE_
#define _TASKBASE_

class TaskBase{
public:
	virtual ~TaskBase(){};
	virtual void initialize(){};
	virtual void update()=0;
	virtual void draw()=0;
	virtual void finalize(){};
};

#endif