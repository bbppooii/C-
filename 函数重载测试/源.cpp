#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#pragma once
//Stack.h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

namespace bit
{
#define N 10000
	typedef int STDataType;
	typedef struct Stack
	{
		STDataType* a;
		int top;
		int capacity;
	}ST;

	static int x = 0;
	static int y = 0;

	// 缺省参数在声明给
	void STInit(ST* ps, int n = 4);
	void STDestroy(ST* ps);

	// 栈顶
	void STPush(ST* ps, STDataType x);
	void STPop(ST* ps);
	STDataType STTop(ST* ps);
	int STSize(ST* ps);
	bool STEmpty(ST* ps);
}

#include"Stack.h"
//Stack.cpp
namespace bit
{
	// 缺省参数不能声明和定义同时给
	void STInit(ST* ps, int n)
	{
		assert(ps);

		ps->a = (STDataType*)malloc(n * sizeof(STDataType));
		ps->top = 0;
		ps->capacity = n;
	}

	void STDestroy(ST* ps)
	{
		assert(ps);

		free(ps->a);
		ps->a = NULL;
		ps->top = ps->capacity = 0;
	}

	// 栈顶
	void STPush(ST* ps, STDataType x)
	{
		assert(ps);

		// 满了， 扩容
		if (ps->top == ps->capacity)
		{
			printf("扩容\n");
			int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
			STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
		ps->a[ps->top] = x;
		ps->top++;
	}

	void STPop(ST* ps)
	{
		assert(ps);
		assert(!STEmpty(ps));
		ps->top--;
	}

	STDataType STTop(ST* ps)
	{
		assert(ps);
		assert(!STEmpty(ps));
		return ps->a[ps->top - 1];
	}

	int STSize(ST* ps)
	{
		assert(ps);
		return ps->top;
	}

	bool STEmpty(ST* ps)
	{
		assert(ps);
		return ps->top == 0;
	}
}

//Test.cpp
int main()
{
	bit::ST st1;
	STInit(&st1);
	STPush(&st1, 1);
	STPush(&st1, 2);
	printf("%d\n", sizeof(st1));
	bit::ST st2;
	printf("%d\n", sizeof(st2));
	bit::STInit(&st2);
	bit::STPush(&st2, 1);
	bit::STPush(&st2, 2);
	return 0;
}