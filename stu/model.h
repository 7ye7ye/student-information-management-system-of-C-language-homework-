//model.h: includes definition of structure Student or the structure of link list node
#ifndef MODEL_H
#define MODEL_H
//学生信息表
struct stuInfo{
    long int stuID;      //Student ID: numbers only with the maximum length of 10.
    char stuName[30];   //Name: characters only with the maximum length of 30; ## is not allowed. 
    char gender;        //Gender: only M or F. M for male, while F for female
    int age;            //Age: value from 0~100.
    double cSco;        //C score: a decimal number with 1 decimal place, value from 0~100. 
    double mathSco;     //Math score: a decimal number with 1 decimal place, value from 0~100. 
    double EngSco;      //English score: a decimal number with 1 decimal place, value from 0~100.
};

struct stuNode{
    struct stuInfo date;
    struct stuNode *nextaddr;
};
#endif
