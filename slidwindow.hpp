#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//������vector��string�Ļ���������
template <class T>
class slidwindow
{
	T* begin;	//�������
	T* end;		//�����յ�
	T* flimit;	//�½�
	T* blimit;	//�Ͻ�
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
	T order()	//���������ش����ڵ�Ԫ��
	{
		for (auto it = begin; it != end; ++it)
		{
			return *it;
		}
	}
	T* begin()	//���ش��ڵ�һ��Ԫ�ص�ַ
	{
		return begin;
	}
	T* end()	//���ش������һ��Ԫ�ص�ַ�ĺ�һλ
	{
		return end;
	}
	void begplus()	//begin����һλ
	{
		if (this->begin < this->end)
		{
			this->began++;
		}
	}
	void endplus()	//end����һλ
	{
		if (this->end < this->blimit)
		{
			this->end++;
		}
	}
	void begminus()	//beginǰ��һλ
	{
		if (this->begin > this->flimit)
		{
			this->began--;
		}
	}
	void endminus()	//endǰ��һλ
	{
		if (this->end > this->begin)
		{
			this->end--;
		}
	}
};