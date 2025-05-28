#pragma once//头文件保护，防止重复包含
template<typename T>
class List {
public:
	List();
	~List();
	void insert(const T& val);//头插法
	void erase(int num);//查找元素并删除
	bool empty();
	T operator[](int num);//重载[]
protected:
	struct Node{
		T data;
		Node* next;
	};
	Node* head;
};
