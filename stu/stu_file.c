//Data access layer (stu_file.c): process data, read or write files.
#include "global.h"
#include "model.h"
#include "stu_file.h"
#include "stu_service.h"
#include<stdio.h>
#include<stdlib.h>

void save()
{
	FILE*fp=fopen("student.txt","w");
	
	if(fp==NULL){
		perror("Failed to creat the file:");
	}
	else{
		struct stuNode*cur=head;
		fprintf(fp,"Student Information:\n");
		for(;cur!=NULL;cur=cur->nextaddr){
			fprintf(fp,"ID: %ld, Name: %s, Gender: %c, Age: %d, C Score: %.lf, Math Score: %.lf, English Score: %.lf\n",
				cur->date.stuID, cur->date.stuName, cur->date.gender, cur->date.age, cur->date.cSco, cur->date.mathSco, cur->date.EngSco);
		}
		printf("successfully save!\n");
	}
	fclose(fp);
}

void read()
{
	FILE*fp=fopen("student2.txt","r");
	if(fp==NULL){
			perror("Failed to open the file:");
		}
	else{
		while(!feof(fp)){
			struct stuNode* stu=(struct stuNode*)malloc(sizeof(struct stuNode));
			fscanf(fp,"%ld %s %c %d %lf %lf %lf",&stu->date.stuID, stu->date.stuName,&stu->date.gender,&stu->date.age,&stu->date.cSco,&stu->date.mathSco,&stu->date.EngSco);
			if(head==NULL){
				head=stu;
				head->nextaddr=NULL;
			}
			else{
				stu->nextaddr=head;
				head=stu;
			}
		}
		printf("Successfully read!\n");
	}
	fclose(fp);
}
