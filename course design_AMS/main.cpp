#include <iostream>
#include "list.h"
#include "VistorModle.h"
#include "alumniModle.h"
#include "managerModle.h"
#include "LoginSystem.h"
#include "Utils.h"
using namespace std;
int main() {
	//����һ��У��¼����
	alumniModle* alumni_list = new alumniModle();
	//����һ������Ա����
	managerModle* manager = new managerModle();
	//����һ����¼ϵͳ����
	LoginSystem* loginSystem = new LoginSystem(alumni_list, manager);
	//����һ���ÿ�ģʽ����
	VistorModle* vistor = new VistorModle(alumni_list);
	return 0;
}
