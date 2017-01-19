#include <stdio.h>
#include <stdlib.h>
#include <new>

class student
{
public:
	student()
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
	}
private:
	int m_num;
};

template <class T>
void first_delete(void *obj)
{
	((T*)(obj))->~T();
	free(obj);
}

template <class T>
T* first_new()
{
	void* obj = malloc(sizeof(T));
	new(obj) T();
	return (T*)obj;
}

int main(int argc,char *argv[])
{
	boy *stu = first_new<good_boy>();
	first_delete<boy>(stu);
	return 0;
}
