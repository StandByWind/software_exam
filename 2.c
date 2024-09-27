#include <stdio.h>
#include <stdlib.h>


//typedef struct Student{
//    int xue_hao,niang_ling,ban_ji;
//    char* xin_ming;不能用指针，因为函数结束字符数组就被释放，但地址还在，导致出现野指针，出现乱码
//    struct Student* next;
//}student;
//
//student* creat(student* Q){
//    int xue_hao,niang_ling,ban_ji;
//    char xin_ming[10];不能用指针，因为函数结束字符数组就被释放，但地址还在，导致出现野指针，出现乱码
//    printf("请输入 学号，姓名，年龄，班级：");
//    scanf("%d %s %d %d",&xue_hao,xin_ming,&niang_ling,&ban_ji);
//    student* P;
//    P=(student*)malloc(sizeof(student));
//    P->xue_hao=xue_hao;
//    P->xin_ming=xin_ming;不能用指针，因为函数结束字符数组就被释放，但地址还在，导致出现野指针，出现乱码
//    P->niang_ling=niang_ling;
//    P->ban_ji=ban_ji;
//    P->next=NULL;
//    Q->next=P;
//    return P;
//}


typedef struct xing_ming_t {
    char val[20];
}xing_ming_t;

typedef struct student {
    int xue_hao, niang_ling, ban_ji;
    struct xing_ming_t xin_ming;
    xing_ming_t xing_ming;
    struct student *next;
}student;

student* creat(student* Q){
    int xue_hao,niang_ling,ban_ji;
    xing_ming_t xin_ming;
    printf("请输入 学号，姓名，年龄，班级：");
    scanf("%d %s %d %d",&xue_hao,xin_ming.val,&niang_ling,&ban_ji);
    student* P;
    P=(student*)malloc(sizeof(student));
    P->xue_hao=xue_hao;
    P->xin_ming=xin_ming;
    P->niang_ling=niang_ling;
    P->ban_ji=ban_ji;
    P->next=NULL;
    Q->next=P;
    return P;
}

student* find_student(student* P){
    int xue_hao;
    printf("请输入学生学号：");
    scanf("%d",&xue_hao);
    if(!P->next){
        printf("没有这个学生");
        return 0;
    }else{
        while(P->next&&P->next->xue_hao!=xue_hao){
            P=P->next;
        }
        return P;
    }
}

void delete(student* P){
    student* tamp;
    if(!P){
        printf("删除失败");
    }else{
        tamp=P->next;
        P->next=tamp->next;
        free(tamp);
    }
}

void change(student* P){
    P=P->next;
    int y,xue_hao,niang_ling,ban_ji;
    xing_ming_t xin_ming;
    do{
        printf("修改学生学号按 1 ，修改学生姓名按 2 ，修改学生年龄按 3 ，修改学生班级按 4 ，退出按0\n");
        scanf("%d",&y);
        if(y==1){
            scanf("%d",&xue_hao);
            P->xue_hao=xue_hao;
        }else if(y==2){
            scanf("%s",xin_ming.val);
            P->xin_ming=xin_ming;
        }else if(y==3){
            scanf("%d",&niang_ling);
            P->niang_ling=niang_ling;
        }else if(y==4){
            scanf("%d",&ban_ji);
            P->ban_ji=ban_ji;
        }
    }while(y);
}

void show(student* P){
    P=P->next;
    while(P){
        printf("学号：%d  姓名：%s  年龄：%d  班级：%d\n",P->xue_hao,P->xin_ming.val,P->niang_ling,P->ban_ji);
        P=P->next;
    }
}

int main(){
    student* P,*tamp,*find;
    int x;
    P=(student*)malloc(sizeof(student));
    P->next=NULL;
    tamp=P;
    do{
        printf("添加学生信息按 1 ，删除学生信息按 2 ，修改学生信息按 3 ，显示所有学生信息按 4 ，退出按 0\n");
        scanf("%d",&x);
        if(x==1){
            tamp=creat(tamp);
        }else if(x==2){
            find=find_student(P);
            delete(find);
        }else if(x==3){
            find= find_student(P);
            change(find);
        }else if(x==4){
            show(P);
        }
    }while(x);
    free(P);
}