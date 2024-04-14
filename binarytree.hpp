/* 
定义了二叉树以及相关的操作
本人能力有限，难免存在BUG与不完善、可优化的地方，欢迎各位大佬使用与更正！
作者：SamKinGLiiiEeE
个人仓库：https://github.com/Samking-Li
CSDN：https://blog.csdn.net/qq_33994286?spm=1011.2124.3001.5343
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

//二叉树节点类
template <class T>
class binarytreenode
{
public:
	T data;
	binarytreenode* left_child;
	binarytreenode* right_child;
	binarytreenode() {}
	binarytreenode(T data)
	{
		this->data = data;
		this->left_child = NULL;
		this->right_child = NULL;
	}
	binarytreenode(T data, binarytreenode* lchild, binarytreenode* rchild)
	{
		this->data = data;
		this->left_child = lchild;
		this->right_child = rchild;
	}
};

//二叉树类
template<class T>
class binarytree
{
	binarytreenode<T>* root;
public:
	binarytree()
	{
		this->root = new binarytreenode<T>();
	}
	binarytree(T data)
	{
		this->root = new binarytreenode<T>(data);
	}
	//根据vector列表逐层生成树
	binarytree(vector<T> list)
	{
		int i = 1;
		int n = list.size();
		queue<binarytreenode<T>*> Q;
		this->root = new binarytreenode<T>(list[0]);
		binarytreenode<T>* p = this->root;
		Q.push(this->root);
		while (Q.size() != 0)
		{
			p = Q.front();
			if (i < n-1)
			{
				insert(list[i++], p, false);
				if (i < n - 1)
				{
					insert(list[i++], p, true);
				}
				if (p->LChild != NULL)
				{
					Q.push(p->LChild);
				}
				if (p->RChild != NULL)
				{
					Q.push(p->RChild);
				}
			}
			Q.pop();
		}
	}
	//获得根节点
	binarytreenode<T>*& get_root()
	{
		return this->root;
	}
	//遍历操作，参数控制遍历顺序
	void order(string FLAG = 'pre')
	{
		if (FLAG == 'pre')
		{
			preorder(this->root);
		}
		else if (FLAG == 'mid') 
		{
			midorder(this->root);
		}
		else if (FLAG == 'post')
		{
			postorder(this->root);
		}
		else
		{
			throw invalid_argument("Invalid parameters, Please check whether the parameters are correct."）;
		}
	}
	void preorder(binarytreenode<T>* node)
	{
		if (node != null) 
		{
			cout << node->data << " ";
			if (node->left_child != null)
			{
				this->preorder(node->left_child);
			}
			if (node->right_child != null)
			{
				this->preorder(node->right_child);
			}
				
		}
	}
	void midorder(binarytreenode<T>* node)
	{
		if (node != null) 
		{
			if (node->left_child != null)
			{
				this->midorder(node->left_child);
			}
			cout << node->data << " ";
			if (node->right_child != null)
			{
				this->midorder(node->right_child);
			}
		}
	}
	void postorder(binarytreenode<T>* node)
	{
		if (node != null)
		{
			if (node->left_child != null)
			{
				this->postorder(node->left_child);
			}
			if (node->right_child != null)
			{
				this->postorder(node->right_child);
			}
			cout << node->data << " ";
		}
	}
	//插入新节点，RL控制插入左孩子还是右孩子，RL1控制若已有左/右孩子时，将左/右孩子作为新节点的左/右孩子。缺省时默认插入左孩子
	void insert(T data, binarytreenode<T>*& node, bool RL = false, bool RL1 = false)
	{
		binarytreenode<T>* p = NULL;
		if (RL)
		{
			if (node->right_child != NULL)
			{
				p = node->right_child;
				node->right_child = new binarytreenode<T>(data);
				if (RL1)
				{
					node->right_child->right_child = p;
				}
				else
				{
					node->right_child->left_child = p;
				}
			}
			else
			{
				node->right_child = new binarytreenode<T>(data);
			}
		}
		else
		{
			if (node->left_child != NULL)
			{
				p = node->left_child;
				node->left_child = new binarytreenode<T>(data);
				if (RL1)
				{
					node->left_child->right_child = p;
				}
				else
				{
					node->left_child->left_child = p;
				}
			}
			else
			{
				node->left_child = new binarytreenode<T>(data);
			}
		}
	}
	//删除指定节点（待完善）
	void remove(binarytreenode<T>*& node)
	{
		/*待完善*/
	}
};