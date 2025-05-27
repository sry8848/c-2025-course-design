#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "list.h"
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
		T* temp = head;
		head = head->next;
		delete temp;
	}
}
template<typename T>
void List<T>::insert(const T& val) {
	T* temp = head;
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
		T* temp = head;
		head = head->next;
		delete temp;
	}
	else {
		T* p1 = head;
		T* p2 = head;
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
bool List<T>::empty() {
	return head == NULL;
}
template<typename T>
T List<T>::operator[](int num) {
	if (num < 1) {
		cerr << "out of range\n";
		exit(1);
	}
	else {
		T* p1 = head;
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
void List<T>::show() const{
	int i = 1;
	T* p1 = head;
	while (p1 != NULL) {
		cout << setw(4) << setfill('0') << i << " ";
		p1->data.show_alumni_information();
		p1 = p1->next;
		i++;
		if(i%10==0){
			int choice;
			cout<<"ѡ�\n 1.��һҳ\n 2.������һ��\n";
			choice = Utils::getChoice(2);
			if (choice == 2) {
				return;
			}
		}
	}
}
template<typename T>
void List<T>::filter_show(const alumniFilter& myAlumniFilter) const {
	int i = 1;
	T* p1 = head;
	while (p1 != NULL) {
		if (myAlumniFilter.filter(p1->data)) {
			cout << setw(4) << setfill('0') << i << " ";
			p1->data.show_alumni_information();
			i++;
		}
		p1 = p1->next;
		if (i % 10 == 0) {
			int choice;
			cout << "ѡ�\n 1.��һҳ\n 2.������һ��\n";
			choice = Utils::getChoice(2);
			if (choice == 2) {
				break;
			}
		}
	}
}
template<typename T>
void List<T>::show_allowChange() {
	int i = 1;
	T* p1 = head;
	while (p1 != NULL) {
		cout << setw(4) << setfill('0') << i << " ";
		p1->data.show_alumni_information();
		p1 = p1->next;
		i++;
		if (i % 10 == 0) {
			int choice;
			cout << "ѡ�\n 1.��һҳ\n 2.�޸�\n 3.ɾ��\n 4.������һ��\n ";
			choice = Utils::getChoice(4);
			if (choice == 2) {
				int num;
				cout << "������Ҫ�޸ĵ�У����Ϣǰ����ţ�";
				num = Utils::getChoice(i);
				p1->data.modify_information();
			}
			else if (choice == 3) {
				int num;
				while (1) {
					cout << "������Ҫɾ����У����Ϣǰ����ţ�����0�������룩��";
					num = Utils::getChoice(i);
					erase(num);
					if (choice == 0) {
						break;
					}
					else {
						cout<<"ɾ���ɹ���\n";
					}
				}
				return;
			}
			else(choice == 4) {
				break;
			}
		}
	}
}
template<typename T>
void List<T>::filter_show_allowChange(const alumniFilter& alumniFilter) {
	int i = 1;
	T* p1 = head;
	while (p1 != NULL) {
		if (alumniFilter.filter(p1->data)) {
			cout << setw(4) << setfill('0') << i << " ";
			p1->data.show_alumni_information();
			i++;
		}
		p1 = p1->next;
		if (i % 10 == 0) {
			int choice;
			cout << "ѡ�\n 1.��һҳ\n 2.�޸�\n 3.ɾ��\n 4.������һ��\n ";
			choice = Utils::getChoice(4);
			if (choice == 2) {
				int num;
				cout << "������Ҫ�޸ĵ�У����Ϣǰ����ţ�";
				num = Utils::getChoice(i);
				p1->data.modify_information();
			}
			else if (choice == 3) {
				int num;
				while (1) {
					cout << "������Ҫɾ����У����Ϣǰ����ţ�����0�������룩��";
					num = Utils::getChoice(i);
					erase(num);
					if (choice == 0) {
						break;
					}
					else {
						cout << "ɾ���ɹ���\n";
					}
				}
				return;
			}
			else(choice == 4) {
				break;
			}
		}
	}
}