//某软件公司大约有30名员工，每名员工有姓名、工号、职务等属性，
//每年都有员工离职和入职。把所有员工建立一个线性表，建立离职和入职函数，
//当有员工离职或入职时，修改线性表，并且显示最新的员工名单。
//要求: 按照顺序和链式存储两种结构存储；实现顺序表和链表基本操作；调用基本操作完成。
//assignment1实现顺序表
#include "list.h"
int main()
{
	SqList StaffList;
	InitList(StaffList);
	Staff s1;
	strcpy_s(s1.name, "zhangsan");
	s1.ID = 1888888;
	strcpy_s(s1.job, "attorney");
	Staff s2,s3;
	strcpy_s(s2.name, "list");
	s2.ID = 1888889;
	strcpy_s(s2.job, "lawyer");
	InsertList(StaffList, 1, s1);
	InsertList(StaffList, 1, s2);
	DisplayAll(StaffList);
	DeleteStaff(StaffList, 1, s3);
	printf("%d",ExtendList(StaffList));
	return 0;
}