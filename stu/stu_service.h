//stu_service.h: includes function prototype declarations related to date processing. For example , 
//functions about handling array or linked list.
#ifndef STU_SERVICE_H
#define STU_SERVICE_H
//Add student info: saves student info in a linked list
void add();

//Display student info: displays student info of memory in form of list
void display();

//Search student info : finds student info specified by student name and display
void search();

//Sort students by student ID
void sort();

//change student information
void change();

//排序函数
void bubbleSort_();

//动态创建链表所需的头插函数
void insertFromHead(struct stuNode*);


#endif
