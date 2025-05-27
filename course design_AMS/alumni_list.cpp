#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "alumni_list.h"
#include "Utils.h"
#include "alumni.h"
using namespace std;
void alumni_list<alumni>::sort(bool (*Compare)(const alumni& val1, const alumni& val2)) {
	//List newList;
	alumni* p1 = head;
	alumni* p2 = head;//p1,p2都为目标结点前一个结点
	//head = new Node;//内存分配失败会系统自己崩溃，不用过多处理
	if (head != NULL) {
		head->data = val;
		head->next = temp;
	}
	while ((p2->next) != NULL) {
		if (Compare(head->data, (p2->next)->data) {//头结点特殊处理
			alumni* aim = (p2->next);
			p2->next = aim->next;
			aim->next = head;
			head = aim;
		}
		alumni* p1 = head;
			while ((p1->next) != (p2->next)) {
				if (Compare((p1->next)->data, (p2->next)->data) {//头结点特殊处理
					alumni* aim = (p2->next);
					p2->next = aim->next;
					aim->next = (p1->next)
						p1->next = aim;
						break;
				}
				p1 = p1->next;
			}

	}
}