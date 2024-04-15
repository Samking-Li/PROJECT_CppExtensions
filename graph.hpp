#pragma once
/*
定义了无向图、有向图以及相关的操作
本人能力有限，难免存在BUG与不完善、可优化的地方，欢迎各位大佬使用与更正！
作者：SamKinGLiiiEeE
个人仓库：https://github.com/Samking-Li
CSDN：https://blog.csdn.net/qq_33994286?type=blog
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;

/*邻接表*/
//边表节点类
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
//节点表节点类
template<class T,class T1>
class node
{
public:
	T data;	//节点数据
	list<arcnode<T1>*> arclist; //边表
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
		return (this->arclist.size());
	}
};
//邻接表类
template<class T, class T1>
class adjgraph
{
public:
	list<node<T, T1>*> nodelist; //节点表
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
	bool empty() //查询是否为空
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
	int size(string FLAG = "node") //查询大小，缺省默认查询节点数
	{
		if (FLAG == "node")	//节点数
		{
			return this->nodelist.size();
		}
		else if(FLAG == "arc")	//边数
		{
			int count = 0;
			for (auto i = this->nodelist.begin(); i != this->nodelist.end(); ++i)
			{
				count += i->arcsize();
			}
			return count;
		}
	}
	void insert_node(T data)	//插入节点
	{
		this->nodelist.push_back(new node<T, T1>(data));
	}
	void erase_node(node<T, T1>* node)		//删除节点
	{
		for (auto i = this->nodelist.begin(); i != this->nodelist.end(); ++i)
		{
			if (i == node)
			{
				/*LATEST*/
			}
		}
	}
	void insert_arc(node<T, T1>* start, node<T, T1>* end)	//插入边
	{
		for (auto i = this->nodelist.begin(); i != this->nodelist.end(); ++i)
		{
			if (i == start)
			{
				/*LATEST*/
			}
		}
	}
};


/*邻接矩阵*/
template <class T>
class adjarray
{
	/*LATEST*/
}