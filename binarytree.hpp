/* 
定义了二叉树以及相关的操作
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
#include <stack>
using namespace std;

//二叉树节点类
template <class T>
class binarytreenode
{
public:
	T data;
	binarytreenode<T>* left_child;
	binarytreenode<T>* right_child;
	binarytreenode() {}
	binarytreenode(T data)
	{
		this->data = data;
		this->left_child = NULL;
		this->right_child = NULL;
	}
	binarytreenode(T data, binarytreenode<T>* lchild, binarytreenode<T>* rchild)
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
		this->root->left_child = NULL;
		this->root->right_child = NULL;
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
				if (p->left_child != NULL)
				{
					Q.push(p->left_child);
				}
				if (p->right_child != NULL)
				{
					Q.push(p->right_child);
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
	//打印节点数据
	void print(binarytreenode<T>* node)
	{
		cout >> node->data >> endl;
	}
	//遍历操作，参数控制遍历顺序
	void order(void(*func)(binarytreenode<T>*& node), string FLAG = 'pre')
	{
		if (FLAG == 'pre')
		{
			preorder(void (*func)(binarytreenode<T>*&node), this->root);
		}
		else if (FLAG == 'mid') 
		{
			midorder(void (*func)(binarytreenode<T>*&node), this->root);
		}
		else if (FLAG == 'post')
		{
			postorder(void (*func)(binarytreenode<T>*&node), this->root);
		}
		else
		{
			throw invalid_argument("Invalid parameters, Please check whether the parameters are correct."）;
		}
	}
	//对应的节点遍历以及访问操作
private:
	void preorder(void (*func)(binarytreenode<T>*& node), binarytreenode<T>* node)
	{
		if (node != NULL) 
		{
			(*func)(node);
			if (node->left_child != NULL)
			{
				this->preorder(void (*func)(binarytreenode<T>*&node), node->left_child);
			}
			if (node->right_child != NULL)
			{
				this->preorder(void (*func)(binarytreenode<T>*&node), node->right_child);
			}
				
		}
	}
	void midorder(void(*func)(binarytreenode<T>*& node), binarytreenode<T>* node)
	{
		if (node != NULL)
		{
			if (node->left_child != NULL)
			{
				this->midorder(void (*func)(binarytreenode<T>*&node), node->left_child);
			}
			(*func)(node);
			if (node->right_child != NULL)
			{
				this->midorder(void (*func)(binarytreenode<T>*&node), node->right_child);
			}
		}
	}
	void postorder(void(*func)(binarytreenode<T>*& node), binarytreenode<T>* node)
	{
		if (node != NULL)
		{
			if (node->left_child != NULL)
			{
				this->postorder(void (*func)(binarytreenode<T>*&node), node->left_child);
			}
			if (node->right_child != NULL)
			{
				this->postorder(void (*func)(binarytreenode<T>*&node), node->right_child);
			}
			(*func)(node);
		}
	}
public:
	//查找节点的父节点。非递归先序遍历查找
	binarytreenode<T>* parent(binarytreenode<T>* node)
	{
		stack<binarytreenode<T>*> S;
		binarytreenode<T>* p = this->root;
		while (p != NULL || !S.empty())
		{
			if (p != NULL)
			{
				if (p->left_child == node|| p->right_child == node)
				{
					return p;
				}
				else
				{
					S.push(p);
					p = p->left_child;
				}
			}
			else
			{
				p = S.top();
				S.pop();
				p = p->right_child;
			}
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
	//删除指定节点。RL控制删除方式
	void remove(binarytreenode<T>*& node, bool RL = false)
	{
		binarytreenode<T>* father = parent(node);
		bool FLAG = (father->left_child == node);		//判断是父节点的左孩子还是右孩子
		if (node->left_child == NULL && node->right_child == NULL)	//若为叶子节点，直接删除
		{
			if (FLAG)
			{
				father->left_child = NULL;
				delete node;
			}
			else
			{
				father->right_child = NULL;
				delete node;
			}
		}
		else if (node -> left_child != NULL && node->right_child == NULL)	//左子树不空右子树空，直接连接到左子树上
		{
			if (FLAG)
			{
				/*LATEST*/
			}
			else
			{
				/*LATEST*/
			}
		}
		else if (node->right_child != NULL && node->left_child == NULL)		//右子树不空左子树空，直接连接到右子树上
		{
			if (FLAG)
			{
				/*LATEST*/
			}
			else
			{
				/*LATEST*/
			}
		}
		else
		{
			if (RL)		//RL == TRUE时，以右子树的最左叶子节点替换待删除节点，再删除该叶子节点
			{
				/*LATEST*/
			}
			else		//RL == FALSE时，以左子树的最右叶子节点替换待删除节点，再删除该叶子节点
			{
				/*LATEST*/
			}
		}
	}
};