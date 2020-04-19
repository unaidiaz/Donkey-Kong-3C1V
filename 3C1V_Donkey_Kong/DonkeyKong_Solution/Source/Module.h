#ifndef __MODULE_H__
#define __MODULE_H__

#include "Globals.h"
struct Collider;
class Module
{
public:
	//Called at the beginning of the application execution
	virtual bool Init();
	virtual bool Start();
	//Called at the beginning of each application loop
	virtual update_status PreUpdate();

	//Called at the middle of each application loop
	virtual update_status Update();

	//Called at the end of each application loop
	virtual update_status PostUpdate();

	//Called at the end of the application
	virtual bool CleanUp();
	virtual void OnCollision(Collider* c1, Collider* c2);
};

#endif // __MODULE_H__