#include <iostream>
#include <unistd.h>
#include "Thread.h"
#include "WorkThreadPool.h"
#include "Task.h"
using namespace std;

class TaskA :public Task
{
public:
	TaskA()
	{
	}
	TaskA(int id)
	{
		m_itaskID = id;
	}
	~TaskA()
	{
	}
	void doTask()
	{
		sleep(2);
		cout << "doTaskA" << endl;
		
	}
private:
	int m_itaskID;
};

class TaskB :public Task
{
public:
	TaskB()
	{
	}
	TaskB(int id)
	{
		m_itaskID = id;
	}
	~TaskB()
	{
	}
	void doTask()
	{
		sleep(2);
		cout << "doTaskB" << endl;
	}
private:
	int m_itaskID;
};

int main(int argc, char *argv[])
{
	WorkThreadPool *pool = new WorkThreadPool(3);
	Task *task = new TaskA(1);

	for (int i = 0; i < 5;i++)
	{
		pool->addTask(task);
	}

	pool->destoryThreadPool();
	return 0;
}