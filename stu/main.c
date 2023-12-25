//View layer (main.c): receive user inputs, display data and interact with users.
#include "global.h"
#include "model.h"
#include "stu_file.h"
#include "stu_service.h"
#include<stdio.h>

struct stuNode *head = NULL;


int main()
{
	
    int enter;
	
    do{
        printf("************************************\n");
        printf("Student Information Management\n");
        printf("************************************\n");
        printf("***************Menu***************\n");
        printf("1.Add student info\n2.Display student info \n3.Sort by student ID\n4.Search student info\n5.Save student info to file\n6.Read student info form file\n7.Change student info form file\n8.Exit system\n");
        printf("************************************\n");
        printf("\nPlease enter your option.(1~8):");

        scanf("%d",&enter);

        printf("\n");
        switch(enter){
            case 1:
                add();
                break;
             case 2:
                display();
                break;
             case 3:
                sort();
                break;
             case 4:
                 search();
                 break;
             case 5:
                 save();
                 break;
             case 6:
                 read();
                 break;
             case 7:
                 change();
                 break;
             default:
                 printf("Thanks for using.");
                 exit(1);
         }
    	//暂停程序
    	system("pause");
		//清空控制台
		system("cls");
	}while(enter!=8);
	
	// 释放链表内存
	struct stuNode* current =head;
	while (current != NULL) {
	    struct stuNode* temp = current;
	    current = current->nextaddr;
	    free(temp);
	}
	
	return 0;
}
