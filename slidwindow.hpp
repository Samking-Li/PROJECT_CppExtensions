#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <string>
using namespace std;

template<class T>
class slidewindow
{
private:
	size_t size;
	deque<T> window;
	void *begin;
	void *end;
public:
	slidewindow()
	{
		this->size = 0;
	}
	slidewindow(vector<T> V)
	{
		this->size = 0;
		this->begin = new (V.begin());
		this->end = new (V.begin());
	}
	slidewindow(list<T> L)
	{
		this->size = 0;
		this->begin = new (L.begin());
		this->end = new (L.begin());
	}
	void add()
	{
		this->window.push_back(**(this->end));
		++(*(this->end));
		this->size += 1;
	}
	void remove()
	{
		++(*(this->begin));
		this->window.pop_front();
		this->size -= 1;
	}
	void order(function<void(T)> fun)
	{
		for (auto ita = *(this->begin); ita != *(this->end); ++ita)
		{
			fun(*ita);
		}
	}
};
