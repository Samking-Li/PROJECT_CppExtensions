#include <vector>
#include "binarytree.hpp"
using namespace std;

void bitree_demo()
{
	//�������鹹�������
	vector<int> list = { 1,5,3,3,6,9,8 };
	binarytree<int>* tree = new binarytree<int>(list);
	//fun��print���������������������ӡ���ڵ�ֵ
	auto fun = bind(&binarytree<int>::print,tree, placeholders::_1);
	tree->order(fun,0);
	//����data==3�Ľڵ��ַ
	auto address = tree->search(3);
	for (auto iter = address.begin(); iter != address.end(); iter++)
	{
		cout << "address: " << *iter << "  data:" << (*iter)->data << endl;
	}
	//���ҵ�һ��data==3�Ľڵ�ĸ��ڵ��ַ
	auto father = tree->parent(address[0]);
	cout << "address: " << father << "  data:" << father->data << endl;


}

void graph_demo()
{

}

void PID_demo()
{


}

void main()
{
	bitree_demo();
}

