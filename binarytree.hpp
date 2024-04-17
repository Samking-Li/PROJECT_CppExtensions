/* 
�����˶������Լ���صĲ���
�����������ޣ��������BUG�벻���ơ����Ż��ĵط�����ӭ��λ����ʹ���������
���ߣ�SamKinGLiiiEeE
���˲ֿ⣺https://github.com/Samking-Li
CSDN��https://blog.csdn.net/qq_33994286?type=blog
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

//�������ڵ���
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

//��������
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
	//����vector�б����������
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
	//��ø��ڵ�
	binarytreenode<T>*& get_root()
	{
		return this->root;
	}
	//��ӡ�ڵ�����
	void print(binarytreenode<T>* node)
	{
		cout >> node->data >> endl;
	}
	//�����������������Ʊ���˳��
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
			throw invalid_argument("Invalid parameters, Please check whether the parameters are correct."��;
		}
	}
	//��Ӧ�Ľڵ�����Լ����ʲ���
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
	//���ҽڵ�ĸ��ڵ㡣�ǵݹ������������
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
	//�����½ڵ㣬RL���Ʋ������ӻ����Һ��ӣ�RL1������������/�Һ���ʱ������/�Һ�����Ϊ�½ڵ����/�Һ��ӡ�ȱʡʱĬ�ϲ�������
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
	//ɾ��ָ���ڵ㡣RL����ɾ����ʽ
	void remove(binarytreenode<T>*& node, bool RL = false)
	{
		binarytreenode<T>* father = parent(node);
		bool FLAG = (father->left_child == node);		//�ж��Ǹ��ڵ�����ӻ����Һ���
		if (node->left_child == NULL && node->right_child == NULL)	//��ΪҶ�ӽڵ㣬ֱ��ɾ��
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
		else if (node -> left_child != NULL && node->right_child == NULL)	//�����������������գ�ֱ�����ӵ���������
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
		else if (node->right_child != NULL && node->left_child == NULL)		//�����������������գ�ֱ�����ӵ���������
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
			if (RL)		//RL == TRUEʱ����������������Ҷ�ӽڵ��滻��ɾ���ڵ㣬��ɾ����Ҷ�ӽڵ�
			{
				/*LATEST*/
			}
			else		//RL == FALSEʱ����������������Ҷ�ӽڵ��滻��ɾ���ڵ㣬��ɾ����Ҷ�ӽڵ�
			{
				/*LATEST*/
			}
		}
	}
};