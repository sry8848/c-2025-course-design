#include <iostream>
#include "myList.h"
#include "alumni_list.h"
#include "VisitorModle.h"
#include "alumniModle.h"
#include "managerModle.h"
#include "LoginSystem.h"
#include "Utils.h"
using namespace std;
int main() {
	LoginSystem LS;
	LS.run();
	return 0;
}
/*
账号,密码,姓名,姓名拼音,性别,年龄,毕业年份,系,专业,班级,地址,电话号码,QQ,电子邮箱
20230008,230008,小芳,XiaoFang,W,23,2021,计算机类,软件工程,02,保密,保密,保密,保密
20230005,230005,小明,XiaoMing,M,24,2023,计算机类,计算机科学与技术,02,保密,保密,保密,保密
20230001,230001,小帅,XiaoShuai,M,22,2021,计算机类,软件工程,01,保密,保密,保密,保密
20230011,230011,小亮,XiaoLiang,M,23,2023,计算机类,软件工程,01,保密,保密,保密,保密
20230004,230004,小丽,XiaoLi,W,22,2023,计算机类,软件工程,01,保密,保密,保密,保密
20230009,230009,小杰,XiaoJie,M,22,2023,计算机类,计算机科学与技术,01,保密,保密,保密,保密
20230006,230006,小华,XiaoHua,W,21,2023,机械类,机械设计制造及其自动化,03,保密,保密,保密,保密
20230002,230002,小红,XiaoHong,W,21,2023,计算机类,计算机科学与技术,02,保密,保密,保密,保密
20230003,230003,小刚,XiaoGang,M,23,2023,计算机类,软件工程,01,保密,保密,保密,保密
*/