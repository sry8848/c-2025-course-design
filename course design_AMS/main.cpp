#include <iostream>
#include "list.h"
#include "VistorModle.h"
#include "alumniModle.h"
#include "managerModle.h"
#include "LoginSystem.h"
#include "Utils.h"
using namespace std;
int main() {
	//创建一个校友录对象
	alumniModle* alumni_list = new alumniModle();
	//创建一个管理员对象
	managerModle* manager = new managerModle();
	//创建一个登录系统对象
	LoginSystem* loginSystem = new LoginSystem(alumni_list, manager);
	//创建一个访客模式对象
	VistorModle* vistor = new VistorModle(alumni_list);
	return 0;
}
