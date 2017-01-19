#include <stdio.h>
#include <stdlib.h>
#include <new>
#include "jemalloc.h"

using namespace std;

class student
{
public:
	student() : m_num(0)
	{
		printf("student\n");
	}
	virtual ~student()
	{
		printf("~student\n");
	}

	virtual void test()
	{
	}

	void set_test(int num)
	{
		m_num = num;
	}

	int m_num;
};

class boy : public student
{
public:
	boy()
	{
		printf("boy\n");
	}
	virtual ~boy()
	{
		printf("~boy\n");
	}

	virtual void test()
	{
	}
};

class good_boy : public boy
{
public:
	good_boy()
	{
		printf("good_boy\n");
	}
	virtual ~good_boy()
	{
		printf("~good_boy\n");
	}
	virtual void test()
	{
		printf("good_boy %d\n",m_num);
	}
};

template <class T>
void first_delete(void *obj)
{
	((T*)(obj))->~T();
	je_free(obj);
}

template <class T>
T* first_new()
{
	void* obj = je_malloc(sizeof(T));
	new(obj) T();
	return (T*)obj;
}

int main(int argc,char *argv[])
{
	for(int i = 0;i < 100000;++i)
	{
		boy *stu = first_new<good_boy>();
		stu->set_test(i);
		stu->test();
		//if(i%2 == 0)
		if(false)
		{
			first_delete<boy>(stu);
		}
	}
	while(true);
	return 0;
}
