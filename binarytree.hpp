/* 
�����˶������Լ���صĲ���
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
using namespace std;

//�������ڵ���
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
	//��ø��ڵ�
	binarytreenode<T>*& get_root()
	{
		return this->root;
	}
	//�����������������Ʊ���˳��
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
			throw invalid_argument("Invalid parameters, Please check whether the parameters are correct."��;
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
	//ɾ��ָ���ڵ㣨�����ƣ�
	void remove(binarytreenode<T>*& node)
	{
		/*������*/
	}
};