#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "alumni_list.h"
#include "Utils.h"
#include "alumni.h"
#include "alumniFilter.h"
using namespace std;
alumni_list::alumni_list():List<alumni>() {}//��ȫ��list���캯����ͬ
alumni_list::~alumni_list() {
	while(head != NULL) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
void alumni_list::sort(bool (*Compare)(const alumni& val1, const alumni& val2)) {
	//List newList;
	Node* p1 = head;
	Node* p2 = head;//p1,p2��ΪĿ����ǰһ�����
	//head = new Node;//�ڴ����ʧ�ܻ�ϵͳ�Լ����������ù��ദ��
	/*if (head != NULL) {
		head->data = val;
		head->next = temp;
	}*/
	while ((p2->next) != NULL) {
		if (Compare(head->data, (p2->next)->data)) {//ͷ������⴦��
			Node* aim = (p2->next);
			p2->next = aim->next;
			aim->next = head;
			head = aim;
		}
		Node* p1 = head;
			while ((p1->next) != (p2->next)) {
				if (Compare((p1->next)->data, (p2->next)->data)) {//ͷ������⴦��
					Node* aim = (p2->next);
					p2->next = aim->next;
					aim->next = (p1->next);
					p1->next = aim;
					break;
				}
				p1 = p1->next;
			}

	}
}

void alumni_list::show() const {
	int i = 1;
	Node* p1 = head;
	while (p1 != NULL) {
		cout << setw(4) << setfill('0') << i << " ";
		p1->data.show();
		p1 = p1->next;
		i++;
		if (i % 10 == 0) {
			int choice;
			cout << "ѡ�\n 1.��һҳ\n 2.������һ��\n";
			choice = Utils::getChoice(2);
			if (choice == 2) {
				return;
			}
		}
	}
}

void alumni_list::filter_show(const alumniFilter& myAlumniFilter) const {
	int i = 1;
	Node* p1 = head;
	while (p1 != NULL) {
		if (myAlumniFilter.filter(p1->data)) {
			cout << setw(4) << setfill('0') << i << " ";
			p1->data.show();
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

void alumni_list::show_allowChange() {
	int i = 1;
	Node* p1 = head;
	while (p1 != NULL) {
		cout << setw(4) << setfill('0') << i << " ";
		p1->data.show();
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
						cout << "ɾ���ɹ���\n";
					}
				}
				return;
			}
			else if(choice == 4) {
				break;
			}
		}
	}
}

void alumni_list::filter_show_allowChange(const alumniFilter& alumniFilter) {
	int i = 1;
	Node* p1 = head;
	while (p1 != NULL) {
		if (alumniFilter.filter(p1->data)) {//ɸѡ�������
			cout << setw(4) << setfill('0') << i << " ";
			p1->data.show();
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
			else if(choice == 4) {
				break;
			}
		}
	}
}