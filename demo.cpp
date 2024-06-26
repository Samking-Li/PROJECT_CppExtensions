#include <vector>
#include "binarytree.hpp"
#include "slidwindow.hpp"
using namespace std;

void bitree_demo()
{
	//根据数组构造二叉树
	vector<int> list = { 1,5,3,3,6,9,8 };
	binarytree<int>* tree = new binarytree<int>(list);
	//fun绑定print函数，先序遍历二叉树打印各节点值
	auto fun = bind(&binarytree<int>::print,tree, placeholders::_1);
	tree->order(fun,0);
	//查找data==3的节点地址
	auto address = tree->search(3);
	for (auto iter = address.begin(); iter != address.end(); iter++)
	{
		cout << "address: " << *iter << "  data:" << (*iter)->data << endl;
	}
	//查找第一个data==3的节点的父节点地址
	auto father = tree->parent(address[0]);
	cout << "address: " << father << "  data:" << father->data << endl;


}

void graph_demo()
{

}

void PID_demo()
{


}

void slidwin_demo()
{
	vector<int> arr;
	int i;
	int n;
	int item;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> item;
		arr.push_back(item);
	}
	slidewindow<int> window = slidewindow<int>(arr);
	for (i = 0; i < n; i++)
	{
		window.add();
	}
	function<void(int)> fun = (
		[&](int item)
		{
			cout << item << endl;
		}
	);
	window.order(fun);
}

void main()
{
	slidwin_demo();
}

