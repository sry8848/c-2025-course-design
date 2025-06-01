#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include <fstream>
#include <iostream>
#include "list.h"
#include "alumni_list.h"	
#include "fileManager.h"
using namespace std;
void fileManager::save_alumni_list(const std::string& fileName, const alumni_list& alumniList){// 保存校友列表到文件 
	if (alumniList.empty()) {
		return; // 如果列表为空，直接返回
	}
	ofstream outfile(fileName);//不应使用"fileName"
	if(!outfile) { // 检查文件是否成功打开
		cerr << "无法打开文件: " << fileName << endl;
		return;
	}
	outfile << "账号,密码,姓名,姓名拼音,性别,年龄,毕业年份,系,专业,班级,地址,电话号码,QQ,电子邮箱\n"; // 写入表头（CSV格式,通用性强，可以用Excel打开(分隔符推荐，或\t））
	auto it= alumniList.begin();//
	while (it != alumniList.end()) {
		outfile << (*it).getUserName() << "," //自定义迭代器重载了'*'，*it即为alumni对象
			<< (*it).getPassword() << "," 
			<< (*it).getName() << "," 
			<< (*it).getPinyin() << "," 
			<< (*it).getGender() << ","
			<< (*it).getAge() << ","
			<< (*it).getGraduationYear() << ","
			<< (*it).getDepartment() << ","
			<< (*it).getMajor() << ","
			<< (*it).getClass() << ","
			<< (*it).getAddress() << ","
			<< (*it).getPhoneNumber() << ","
			<< (*it).getQQ() << ","
			<< (*it).getEmail() << "\n";
		++it; // 移动到下一个元素
	}
	outfile.close(); // 关闭文件
}
alumni_list fileManager::load_alumni_list(const std::string& fileName) {
	ifstream infile(fileName);
	if (!infile) { // 检查文件是否成功打开
		cerr << "无法打开文件: " << fileName << endl;
		return alumni_list(); // 返回一个空的 alumni_list
	}
	alumni_list alumniList;
	string line;
	std::string userName_;
	std::string password_;
	std::string name;
	std::string pinyin;
	char gender;
	int age;
	int year_of_graduation;
	std::string department;
	std::string major;
	int Class;
	std::string address;
	std::string phoneNumber;
	std::string qq;
	std::string email;
	string tempInformation;
	getline(infile, line); // 读取表头
	while (getline(infile, userName_, ',')) {//遇到文件终止符结束
		getline(infile, password_, ',');
		getline(infile, name, ',');
		getline(infile, pinyin, ','); // 读取姓名拼音
		getline(infile, tempInformation, ',');
		gender = tempInformation[0]; // 假设性别是单个字符
		getline(infile, tempInformation, ',');
		age = stoi(tempInformation); // 将字符串转换为整数
		getline(infile, tempInformation, ',');
		year_of_graduation = stoi(tempInformation); // 将字符串转换为整数
		getline(infile, department, ',');
		getline(infile, major, ',');
		getline(infile, tempInformation, ',');
		Class = stoi(tempInformation); // 将字符串转换为整数
		getline(infile, address, ',');
		getline(infile, phoneNumber, ',');
		getline(infile, qq, ',');
		getline(infile, email); // 最后一行没有逗号
		alumni newAlumni(userName_,password_,name,pinyin,gender,age,year_of_graduation,department,major,Class,address,phoneNumber,qq,email); // 创建一个新的 alumni 对象
		alumniList.insert(newAlumni); // 将新对象插入到 alumniList 中
	}
	infile.close(); // 关闭文件
	return alumniList; // 返回加载的 alumni_list
}
template <typename T>
static void fileManager::save_T_list(const std::string& fileName, List<T>& TList) {
	if (TList.empty()) {
		return; // 如果列表为空，直接返回
	}
	ofstream outfile(fileName);//不应使用"fileName"
	if (!outfile) { // 检查文件是否成功打开
		cerr << "无法打开文件: " << fileName << endl;
		return;
	}
	outfile << "账号,密码\n"; // 写入表头（CSV格式,通用性强，可以用Excel打开(分隔符推荐，或\t））
	auto it = TList.begin();
	while (it != TList.end()) {
		outfile << (*it).getUserName() << "," //自定义迭代器重载了'*'，*it即为alumni对象
			<< (*it).getPassword() << "\n";
		++it; // 移动到下一个元素
	}
	outfile.close(); // 关闭文件
}
template <typename T>
List<T> fileManager::load_T_list(const std::string& fileName){
	ifstream infile(fileName);
	if (!infile) { // 检查文件是否成功打开
		cerr << "无法打开文件: " << fileName << endl;
		return List<T>(); // 返回一个空的 List<T>
	}
	string line;
	std::string userName_;
	std::string password_;
	List<T> TList; // 创建一个通用列表
	getline(infile, line); // 读取表头
	while (getline(infile, userName_, ',')) {//遇到文件终止符结束
		getline(infile, password_);
		T item(userName_, password_);
		TList.insert(item);
	}
	infile.close(); // 关闭文件
	return TList; // 返回加载的通用列表
}
