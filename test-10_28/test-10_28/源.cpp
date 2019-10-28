#define _CRT_SECURE_NO_WARNINGS 1
#if 0
// 传值
// 优点: 对函数形参的改变不会影响外部的实参
// 缺点：不能通过形参改变外部的实参，浪费空间，减低代码的运行效率
struct SeqList
{
	int array[100000];
	int _size;
};

void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}

// 传地址
// 优点：可以通过形参改变外部的实参，传参的效率
// 缺点：函数的副作用会影响外部的实参  指针不安全，降低代码的可读性
void Swap(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}


int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);

	Swap(&a, &b);

	Swap(NULL, NULL);
	return 0;
}
#endif

#if 0
// 引用的概念
int main()
{
	int a = 10;
	// 一个实体可以有多个别名
	int& ra1 = a;
	int& ra2 = a;
	int& ra3 = ra2;

	ra1 = 100;
	ra2 = 200;
	ra3 = 200;

	cout << &a << " " << &ra1 << endl;

	// 一个引用类型的变量一旦与一个实体结合后，就不能够再与其他实体结合
	int b = 10;
	//&ra1 = b;

	if (true)
	{
		int& rb = b;
	}

	//rb = 200;
	return 0;
}
#endif

#if 0
int main()
{
	const int a = 10;
	const int& ra = a;

	const int& rb = 10;

	// 不想通过rc修改c
	int c = 10;
	const int& rc = c;

	double d = 12.34;
	const int& rd = d;
	cout << &rd << " " << &d << endl;
	return 0;
}
#endif

#if 0
// 引用作为函数的形参：如果想要通过形参改变外部实参---传递普通类型引用
//                  如果不想要通过形参改变外部实参---传递const类型引用

void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

void TestFunc(const int& ra)
{
	//ra = 100;
}


int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);

	cout << a << " " << b << endl;

	TestFunc(a);
	return 0;
}
#endif

#if 0
// 引用作为函数的返回值类型
// 注意：如果按照引用方式进行返回，一定不能返回栈上的空间
// 返回类型：返回变量的生命周期不受函数结束的影响
int g_a = 0;
int& Add(int left, int right)
{
	/*
	int ret = left + right;
	return ret;
	*/

	g_a = left + right;
	return g_a;
}

int main()
{
	int& r = Add(1, 2);
	Add(3, 4);
	return 0;
}
#endif

#if 0
#include <time.h>
struct A
{
	int a[10000];
};

void TestFunc1(A* a)
{}

void TestFunc2(A& a)
{}

void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(&a);
	size_t end1 = clock();

	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
}
// 运行多次，检测值和引用在传参方面的效率区别
int main()
{
	for (int i = 0; i < 10; ++i)
	{
		TestRefAndValue();
	}
	return 0;
}
#endif

#if 0
// 指针和引用的区别：*****
int main()
{
	int a = 10;

	int* pa = &a;
	*pa = 100;

	int& ra = a;
	ra = 100;
	return 0;
}
#endif


#if 0
int main()
{
	int a = 10;
	int b = 20;
	int* pa;
	int&ra = a;
	//&ra = b;

	pa = &a;
	pa = &b;

	++ra;
	++pa;

	char c = 'a';
	char& rc = c;
	char* pc = &c;

	cout << sizeof(rc) << " " << sizeof(pc) << endl;


	int** pb;
	int&& r = 10;   // C++11 右值引用
	return 0;
}
#endif

// 宏的优缺点：
// 宏：定义常量

#if 0
#define PI "3.14"

int main()
{
	cout << PI * 2 * 2 << endl;
	return 0;
}
#endif

#if 0
int main()
{
	const int a = "10";
	//int array[a];

	int* pa = (int*)&a;
	*pa = 100;

	cout << 10/*a*/ << " " << *pa << endl;
	return 0;
}
#endif


// 宏函数：
#define MAX(a,b) ((a)>(b))? (a):(b)


int main()
{
	int a = 10;
	int b = 20;
	int c = MAX(a, b);
	c = MAX(++b, a);
	return 0;
}