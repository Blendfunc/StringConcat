#include "stdio.h"
// TEST MEMORY LEAK
#include "vld.h"
//
typedef unsigned char byte;
char _tempStr[] = {'a','b','c','d'};
bool ConcatString(byte** _string1,byte** _string2,int nLength,void* _outstring)
{
	return true;
}
bool CopyString(byte** _SourceStr,byte** _DesStr,int nLength)
{
	return true;
}
void DeleteString(void* p)
{

}
void GenerateString(int nLength,byte*** _outStr)//初始化'0'填充的字符串,空串
{
	*_outStr = new byte*[nLength];
	int i = 0;
	while(i<nLength)
	{
//		char tempChar = 'A';//不能如此操作，结果返回临时变量指针
		char* tempChar = new char;
		*tempChar = 'A';
		byte* a = (byte*)tempChar;
		*((*_outStr)+i) = a;
		char b = (char)(**((*_outStr)+i));
//		printf("%c",((char)**((*_outStr)+i)));
		i++;
	}
}

void main()
{
	//test code 20160816
	byte*** p = new byte**;
	GenerateString(100,p);	 
	int i = 0;
	while(i<100)
	{
		printf("%c",((char)(**((*p)+i))));
		i++;
	}
	//
}
