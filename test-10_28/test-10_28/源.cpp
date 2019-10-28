#define _CRT_SECURE_NO_WARNINGS 1
#if 0
// ��ֵ
// �ŵ�: �Ժ����βεĸı䲻��Ӱ���ⲿ��ʵ��
// ȱ�㣺����ͨ���βθı��ⲿ��ʵ�Σ��˷ѿռ䣬���ʹ��������Ч��
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

// ����ַ
// �ŵ㣺����ͨ���βθı��ⲿ��ʵ�Σ����ε�Ч��
// ȱ�㣺�����ĸ����û�Ӱ���ⲿ��ʵ��  ָ�벻��ȫ�����ʹ���Ŀɶ���
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
// ���õĸ���
int main()
{
	int a = 10;
	// һ��ʵ������ж������
	int& ra1 = a;
	int& ra2 = a;
	int& ra3 = ra2;

	ra1 = 100;
	ra2 = 200;
	ra3 = 200;

	cout << &a << " " << &ra1 << endl;

	// һ���������͵ı���һ����һ��ʵ���Ϻ󣬾Ͳ��ܹ���������ʵ����
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

	// ����ͨ��rc�޸�c
	int c = 10;
	const int& rc = c;

	double d = 12.34;
	const int& rd = d;
	cout << &rd << " " << &d << endl;
	return 0;
}
#endif

#if 0
// ������Ϊ�������βΣ������Ҫͨ���βθı��ⲿʵ��---������ͨ��������
//                  �������Ҫͨ���βθı��ⲿʵ��---����const��������

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
// ������Ϊ�����ķ���ֵ����
// ע�⣺����������÷�ʽ���з��أ�һ�����ܷ���ջ�ϵĿռ�
// �������ͣ����ر������������ڲ��ܺ���������Ӱ��
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
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(&a);
	size_t end1 = clock();

	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
}
// ���ж�Σ����ֵ�������ڴ��η����Ч������
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
// ָ������õ�����*****
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
	int&& r = 10;   // C++11 ��ֵ����
	return 0;
}
#endif

// �����ȱ�㣺
// �꣺���峣��

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


// �꺯����
#define MAX(a,b) ((a)>(b))? (a):(b)


int main()
{
	int a = 10;
	int b = 20;
	int c = MAX(a, b);
	c = MAX(++b, a);
	return 0;
}