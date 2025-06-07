/*

//myList.h
#pragma once//头文件保护，防止重复包含
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "alumni.h"
#include "fileManager.h"
#include "Utils.h"
template<typename T>
class List {
public:
	struct Node {//Node结构体需定义在Iterator类之前，否则会报错
		T data;
		Node* next = NULL;
	};
	Node* head;
	//template<typename T>
	List() {
		head = NULL;
	}
	//template<typename T>
	void clear(){
		while (head != NULL) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	virtual ~List() {
		clear();
	}
	
	//template<typename T>
	void insert(const T& val){
		Node* temp = head;
		head = new Node;//内存分配失败会系统自己崩溃，不用过多处理
		if (head != NULL) {
			head->data = val;
			head->next = temp;
		}
	}
	//template<typename T>
	void erase(int num) {
		if (num < 1) {
			std::cerr << "out of range\n";
			exit(1);
		}
		else if (num == 1) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		else {
			Node* p1 = head;
			Node* p2 = head;
			for (int i = 2; i < num; ++i) {
				if (p1->next != NULL) {
					p1 = p1->next;//p1为删除结点前一个结点
				}
				else {
					std::cerr << "out of range\n";
					exit(1);
				}
			}
			p2 = p1->next;
			p1->next = p2->next;
			delete p2;
		}
	}
	//template<typename T>
	bool empty() const {
		return head == NULL;
	}
	//template<typename T>
	T operator[](int num) {
		if (num < 1) {
			std::cerr << "out of range\n";
			exit(1);
		}
		else {
			Node* p1 = head;
			for (int i = 1; i < num; ++i) {
				if (p1 != NULL) {
					p1 = p1->next;
				}
				else {
					std::cerr << "out of range\n";
					exit(1);
				}
			}
			return p1->data;
		}
	}
	//template<typename T>
	bool count(const T& val) {
		Node* p1 = head;
		while (p1 != NULL) {
			if (p1->data == val) {
				return true; // 找到元素，返回true
			}
			p1 = p1->next;
		}
		return false; // 没有找到元素，返回false
	}
	//template<typename T>
	List<T>& operator=(const List<T>& other) {
		if (this == &other) {
			return *this; // 防止自赋值
		}
		this->clear(); // 清空当前链表
		Node* p1 = other.head;
		while (p1 != NULL) {
			insert(p1->data);
			p1 = p1->next;
		}
		return *this;
	}
	


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
//template class List<alumni>;


*/