//Logic layer (stu_service.c): process relative business logics.
#include "global.h"
#include "model.h"
#include "stu_file.h"
#include "stu_service.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insertFromHead(struct stuNode* neww)
{
		if(head==NULL){
			
			neww->nextaddr=NULL;
			head=neww;
		}
		else{
			neww->nextaddr=head;
			head=neww;
		}		
}

void add()
{
    struct stuNode *p=(struct stuNode *)malloc(sizeof(struct stuNode));

    printf("Please enter the student's id number:");
    scanf("%ld",&p->date.stuID);

    printf("Please enter the student's name:");
    scanf("%s",p->date.stuName);
    getchar();

    printf("Please enter the student's gender(M for male while F for female):");
    scanf("%c",&p->date.gender);

    printf("Please enter the student's age:");
    scanf("%d",&p->date.age);

    printf("Please enter the student's scores of C,math,English:");
    scanf("%lf%lf%lf",&p->date.cSco,&p->date.mathSco,&p->date.EngSco);
    
    insertFromHead(p);
}


void display()
{
	struct stuNode* cur=head;
	
	if(cur==NULL){
		printf("No student information available.\n");
		return;
	}
	
	printf("\nStudent Information:\n");
	    while (cur != NULL) {
	        printf("ID: %ld, Name: %s, Gender: %c, Age: %d, C Score: %.lf, Math Score: %.lf, English Score: %.lf\n",
	               cur->date.stuID, cur->date.stuName, cur->date.gender, cur->date.age, cur->date.cSco, cur->date.mathSco, cur->date.EngSco);
	        cur = cur->nextaddr;
	    }

}

void sort()
{
	bubbleSort_();
	printf("Sucessfully sort!");	
	
}

void bubbleSort_()
{
	struct stuNode* dummy=(struct stuNode*)malloc(sizeof(struct stuNode));
		dummy->nextaddr=head;
	
	struct stuNode* cur= head;
	int cnt=0;
	
	struct stuInfo temp[1000];
	
	cur=head;
	int i=0;
	
	while(cur!=NULL){
		
		temp[i].stuID=cur->date.stuID;
		strcpy(temp[i].stuName,cur->date.stuName);
		temp[i].gender=cur->date.gender;
		temp[i].age=cur->date.age;
		temp[i].cSco=cur->date.cSco;
		temp[i].mathSco=cur->date.mathSco;
		temp[i].EngSco=cur->date.EngSco;
		cur=cur->nextaddr;
		i++;
		cnt++;
		}
	
	for(int i=0;i<cnt-1;i++){
		for(int j=0;j<cnt-1;j++){
			if(temp[j].stuID>temp[j+1].stuID){
				struct stuInfo temp2;
				temp2=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=temp2;
//为什么不能用呢？
//				temp[j]=(temp[j]^temp[j+1]);
//				temp[j+1]=(temp[j+1]^temp[j]);
//				temp[j]=(temp[j]^temp[j+1]);
			}
		}
	}
	
	cur=head;
	i=0;
		
		while(cur!=NULL){
		
			cur->date.stuID=temp[i].stuID;
			strcpy(cur->date.stuName,temp[i].stuName);
			cur->date.gender=temp[i].gender;
			cur->date.age=temp[i].age;
			cur->date.cSco=temp[i].cSco;
			cur->date.mathSco=temp[i].mathSco;
			cur->date.EngSco=temp[i].EngSco;
			cur=cur->nextaddr;
			i++;
			}
	
	
	
	
//    for (int turn = cnt-1;turn>0; turn--) {
//        int swapped = 0; // 标志是否发生交换
//
//        for (struct stuNode* move = dummy; move->nextaddr != NULL ;move = move->nextaddr) {
//            if (move->nextaddr->nextaddr != NULL&&move->nextaddr->date.stuID > move->nextaddr->nextaddr->date.stuID) {
//                struct stuNode* temp=move->nextaddr;
////这样为什么不行？？
////								move->nextaddr=move->nextaddr->nextaddr;
////								move->nextaddr->nextaddr= move->nextaddr->nextaddr->nextaddr;
////							    move->nextaddr->nextaddr->nextaddr=temp;
////这样行了一次又不行了？？？
//				struct stuNode* temp1=move->nextaddr->nextaddr->nextaddr;
//				move->nextaddr = move->nextaddr->nextaddr;    // 步骤一
//				move->nextaddr->nextaddr= temp1;          // 步骤二
//				move->nextaddr->nextaddr->nextaddr= temp;
//                
//                swapped = 1; // 标记发生了交换
//            } 
//        }
//
//        if (!swapped) {
//            break; // 如果没有发生交换，说明已经有序，提前退出循环
//        }
//    }
//    
//    head=dummy->nextaddr;
    display();
}

void search()
{
	printf("Please enter the student's name you want to search for:");
	
	char find[50];
	scanf("%s",find);
	
	struct stuNode* cur=head;
	int is=0;
	for(;cur!=NULL;cur=cur->nextaddr){
		if(strcmp(find,cur->date.stuName)==0){
			is=1;
			printf("Successfully find!");
			printf("\nStudent Information:\n");
			printf("ID: %ld, Name: %s, Gender: %c, Age: %d, C Score: %.lf, Math Score: %.lf, English Score: %.lf\n",
				cur->date.stuID, cur->date.stuName, cur->date.gender, cur->date.age, cur->date.cSco, cur->date.mathSco, cur->date.EngSco);
			break;
		}
	}
	
	if(is==0)	printf("No student information available.\n");
	
}
//加分项：增加改变学生信息的功能
void change()
{
	printf("Please enter the position you want to change:");
	display();
	
	int po;
	scanf("%d",&po);
	
	struct stuNode* dummy=(struct stuNode*)malloc(sizeof(struct stuNode));
	dummy->nextaddr=head;
	
	struct stuNode* cur=dummy;
	while(po--){
		cur=cur->nextaddr;
	}
	printf("Please enter the new information:\n");
	printf("Please enter the student's id number:");
	    scanf("%ld",&cur->date.stuID);
	
	    printf("Please enter the student's name:");
	    scanf("%s",cur->date.stuName);
	    getchar();
	
	    printf("Please enter the student's gender(M for male while F for female):");
	    scanf("%c",&cur->date.gender);
	
	    printf("Please enter the student's age:");
	    scanf("%d",&cur->date.age);
	
	    printf("Please enter the student's scores of C,math,English:");
	    scanf("%lf%lf%lf",&cur->date.cSco,&cur->date.mathSco,&cur->date.EngSco);
	
	printf("Successfully change!\n");
	printf("\nStudent Information:\n");
				printf("ID: %ld, Name: %s, Gender: %c, Age: %d, C Score: %.lf, Math Score: %.lf, English Score: %.lf\n",
					cur->date.stuID, cur->date.stuName, cur->date.gender, cur->date.age, cur->date.cSco, cur->date.mathSco, cur->date.EngSco);    
	
}
	
	
