#pragma once
/*
����������ͼ������ͼ�Լ���صĲ���
�����������ޣ��������BUG�벻���ơ����Ż��ĵط�����ӭ��λ����ʹ���������
���ߣ�SamKinGLiiiEeE
���˲ֿ⣺https://github.com/Samking-Li
CSDN��https://blog.csdn.net/qq_33994286?spm=1011.2124.3001.5343
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;

/*�ڽӱ�*/

//�߱�ڵ���
template <class T>
class arcnode
{
public:
	int adjvex;
	T weigh;
	arcnode(int adjvex)
	{
		this->adjvex = adjvex;
		this->weigh = 1;
	}
	arcnode(int adjvex, T weigh)
	{
		this->adjvex = adjvex;
		this->weigh = weigh;
	}
};

//�ڵ��ڵ�
template<class T,class T1>
class node
{
public:
	T data;	//�ڵ�����
	list<arcnode<T1>> arclist; //�߱�
	node() {}
	node(T data)
	{
		this->data = data;
	}
	node(T data, int adjvex)
	{
		this->data = data;
		this->arclist.push_back(new arcnode<T1>(adjvex));
	}
	node(T data, int adjvex, T1 weight)
	{
		this->data = data;
		this->arclist.push_back(new arcnode<T1>(adjvex, weight));
	}
	int arcsize()
	{
		return (arclist.size());
	}
};

//�ڽӱ���
template<class T, class T1>
class adjgraph
{
	vector<node<T, T1>*> nodelist; //�ڵ��
public:
	adjgraph()
	{
		this->nodelist.push_back(new node<T, T1>());
	}
	adjgraph(T data)
	{
		this->nodelist.push_back(new node<T, T1>(data));
	}
	adjgraph(T data, int adjvex)
	{
		this->nodelist.push_back(new node<T, T1>(data, adjvex));
	}
	adjgraph(T data, int adjvex, T1 weight)
	{
		this->nodelist.push_back(new node<T, T1>(data, adjvex, weight));
	}
	bool empty() //��ѯ�Ƿ�Ϊ��
	{
		if (this->nodelist.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int size(string FLAG = "node") //��ѯ��С��ȱʡĬ�ϲ�ѯ�ڵ���
	{
		if (FLAG == "node")	//�ڵ���
		{
			return this->nodelist.size();
		}
		else if(FLAG == "arc")	//����
		{
			int count = 0;
			int i;
			int len = this->nodelist.size();
			for (i = 0; i < len; i++)
			{
				count+=this->
			}
			return count;
		}
	}
	void insert_node(T data)	//����ڵ�
	{
		this->nodelist.push_back(new node<T, T1>(data, nex));
	}
	void erase_node(int locate)		//ɾ���ڵ�
	{
		
	}
	void insert_arc(int start, int end)	//�����
	{
		node<T, T1>* p = this->nodelist.begin();
	}
};