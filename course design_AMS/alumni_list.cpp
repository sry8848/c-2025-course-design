#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "alumni_list.h"
#include "Utils.h"
#include "alumni.h"
#include "alumniFilter.h"
using namespace std;
alumni_list::alumni_list():List<alumni>() {}//完全与list构造函数相同
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
	Node* p2 = head;//p1,p2都为目标结点前一个结点
	//head = new Node;//内存分配失败会系统自己崩溃，不用过多处理
	/*if (head != NULL) {
		head->data = val;
		head->next = temp;
	}*/
	while ((p2->next) != NULL) {
		if (Compare(head->data, (p2->next)->data)) {//头结点特殊处理
			Node* aim = (p2->next);
			p2->next = aim->next;
			aim->next = head;
			head = aim;
		}
		Node* p1 = head;
			while ((p1->next) != (p2->next)) {
				if (Compare((p1->next)->data, (p2->next)->data)) {//头结点特殊处理
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
			cout << "选项：\n 1.下一页\n 2.返回上一级\n";
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
			cout << "选项：\n 1.下一页\n 2.返回上一级\n";
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
			cout << "选项：\n 1.下一页\n 2.修改\n 3.删除\n 4.返回上一级\n ";
			choice = Utils::getChoice(4);
			if (choice == 2) {
				int num;
				cout << "请输入要修改的校友信息前的序号：";
				num = Utils::getChoice(i);
				p1->data.modify_information();
			}
			else if (choice == 3) {
				int num;
				while (1) {
					cout << "请输入要删除的校友信息前的序号（输入0结束输入）：";
					num = Utils::getChoice(i);
					erase(num);
					if (choice == 0) {
						break;
					}
					else {
						cout << "删除成功！\n";
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
		if (alumniFilter.filter(p1->data)) {//筛选并标序号
			cout << setw(4) << setfill('0') << i << " ";
			p1->data.show();
			i++;
		}
		p1 = p1->next;
		if (i % 10 == 0) {
			int choice;
			cout << "选项：\n 1.下一页\n 2.修改\n 3.删除\n 4.返回上一级\n ";
			choice = Utils::getChoice(4);
			if (choice == 2) {
				int num;
				cout << "请输入要修改的校友信息前的序号：";
				num = Utils::getChoice(i);
				p1->data.modify_information();
			}
			else if (choice == 3) {
				int num;
				while (1) {
					cout << "请输入要删除的校友信息前的序号（输入0结束输入）：";
					num = Utils::getChoice(i);
					erase(num);
					if (choice == 0) {
						break;
					}
					else {
						cout << "删除成功！\n";
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