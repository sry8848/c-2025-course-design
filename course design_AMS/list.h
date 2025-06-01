#pragma once//头文件保护，防止重复包含
template<typename T>
class List {
protected:
	struct Node {//Node结构体需定义在Iterator类之前，否则会报错
		T data;
		Node* next;
	};
	Node* head;
public:
	List();
	~List();
	void insert(const T& val);//头插法
	void erase(int num);//查找元素并删除
	bool empty()const;
	T operator[](int num);//重载[]
	//迭代器
	class Iterator {
	public:
		Iterator(Node* node) : current(node) {}
		T& operator* () { return current->data; }
		Iterator& operator++() { current = current->next; return (*this); }
		Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; }
		bool operator!=(const Iterator& other) { return this->current != other.current; }
	private:
		Node* current;
	};
	Iterator begin() const{ return Iterator(head); }//需要定义在Iterator类外，否则会报错
	Iterator end() const{ return Iterator(nullptr); }
};
