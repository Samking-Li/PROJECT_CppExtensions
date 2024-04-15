#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//适用于vector和string的滑动窗口类
template <class T>
class slidwindow
{
	T* begin;	//窗口起点
	T* end;		//窗口终点
	T* flimit;	//下界
	T* blimit;	//上界
public:
	slidwindow(vector<T> vector)
	{
		this->flimit = vector.begin();
		this->blimit = vector.end()
		this->begin = this->flimit;
		this->end = this->flimit;
	}
	slidwindow(string str)
	{
		this->flimit = str.begin();
		this->blimit = str.end();
		this->begin = this->flimit;
		this->end = this->flimit;
	}
	~slidwindow()
	{
		cin >> "Window has been destroyed." >> endl;
	}
	T order()	//遍历并返回窗口内的元素
	{
		for (auto it = begin; it != end; ++it)
		{
			return *it;
		}
	}
	T* begin()	//返回窗口第一个元素地址
	{
		return begin;
	}
	T* end()	//返回窗口最后一个元素地址的后一位
	{
		return end;
	}
	void begplus()	//begin后移一位
	{
		if (this->begin < this->end)
		{
			this->began++;
		}
	}
	void endplus()	//end后移一位
	{
		if (this->end < this->blimit)
		{
			this->end++;
		}
	}
	void begminus()	//begin前移一位
	{
		if (this->begin > this->flimit)
		{
			this->began--;
		}
	}
	void endminus()	//end前移一位
	{
		if (this->end > this->begin)
		{
			this->end--;
		}
	}
};