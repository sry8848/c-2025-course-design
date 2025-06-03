#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "list.h"
#include "fileManager.h"
#include "Utils.h"
#include "alumni.h"
using namespace std;
template<typename T>
List<T>::List() {
	head = NULL;
}
template<typename T>
List<T>::~List() {
	while (head != NULL) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
template<typename T>
void List<T>::insert(const T& val) {
	Node* temp = head;
	head = new Node;//�ڴ����ʧ�ܻ�ϵͳ�Լ����������ù��ദ��
	if (head != NULL) {
		head->data = val;
		head->next = temp;
	}
}
template<typename T>
void List<T>::erase(int num) {
	if (num < 1) {
		cerr << "out of range\n";
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
				p1 = p1->next;//p1Ϊɾ�����ǰһ�����
			}
			else {
				cerr << "out of range\n";
				exit(1);
			}
		}
		p2 = p1->next;
		p1->next = p2->next;
		delete p2;
	}
}
template<typename T>
bool List<T>::empty() const{
	return head == NULL;
}
template<typename T>
T List<T>::operator[](int num) {
	if (num < 1) {
		cerr << "out of range\n";
		exit(1);
	}
	else {
		Node* p1 = head;
		for (int i = 1; i < num; ++i) {
			if (p1 != NULL) {
				p1 = p1->next;
			}
			else {
				cerr << "out of range\n";
				exit(1);
			}
		}
		return p1->data;
	}
}
template<typename T>
bool count(const T& val) {
	Node* p1 = head;
	while (p1 != NULL) {
		if(*p1==val){
			return true; // �ҵ�Ԫ�أ�����true
		}
		p1 = p1->next;	
	}
	return false; // û���ҵ�Ԫ�أ�����false
}
template<typename T>
List<T> List<T>::operator=(const List<T>& other) {
	head = other.head;
}

