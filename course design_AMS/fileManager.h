#pragma once//头文件保护，防止重复包含
//不建议头文件包含#include<iostream>，而是使用std::
#include <string>//用到std::string就包含此头文件
#include <vector>
#include "alumni_list.h"
#include "myList.h"
#include "department.h"
#include <fstream>
#include <iostream>
#include "Class.h"
#include "major.h"
#include "fileManager.h"


using namespace std;

template <typename T> class List;
class alumni_list;
class Department;//添加前向声明，避免循环依赖！！
class fileManager {
public:
	static void save_alumni_list(const std::string& fileName,const alumni_list& alumniList); // 保存校友列表到文件                                                                                             
	static alumni_list load_alumni_list(const std::string& fileName); // 从指定文件加载校友列表(AlumniList 依赖 FileManager（单向依赖）)
	template <typename T>
	static void save_T_list(const std::string& fileName, List<T>& TList); // 从指定文件加载通用列表
	template <typename T>
	static List<T> load_T_list(const std::string& fileName) {
		std::ifstream infile(fileName);
		if (!infile) { // 检查文件是否成功打开
			cerr << "无法打开文件: " << fileName << endl;
			return List<T>(); // 返回一个空的 List<T>
		}
		string line;
		string userName_;
		string password_;
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
	static std::vector<Department> load_department_list(const std::string& fileName); // 从指定文件加载系列表
}
;