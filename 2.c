#include <stdio.h>
#include <stdlib.h>


//typedef struct Student{
//    int xue_hao,niang_ling,ban_ji;
//    char* xin_ming;������ָ�룬��Ϊ���������ַ�����ͱ��ͷţ�����ַ���ڣ����³���Ұָ�룬��������
//    struct Student* next;
//}student;
//
//student* creat(student* Q){
//    int xue_hao,niang_ling,ban_ji;
//    char xin_ming[10];������ָ�룬��Ϊ���������ַ�����ͱ��ͷţ�����ַ���ڣ����³���Ұָ�룬��������
//    printf("������ ѧ�ţ����������䣬�༶��");
//    scanf("%d %s %d %d",&xue_hao,xin_ming,&niang_ling,&ban_ji);
//    student* P;
//    P=(student*)malloc(sizeof(student));
//    P->xue_hao=xue_hao;
//    P->xin_ming=xin_ming;������ָ�룬��Ϊ���������ַ�����ͱ��ͷţ�����ַ���ڣ����³���Ұָ�룬��������
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
    printf("������ ѧ�ţ����������䣬�༶��");
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
    printf("������ѧ��ѧ�ţ�");
    scanf("%d",&xue_hao);
    if(!P->next){
        printf("û�����ѧ��");
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
        printf("ɾ��ʧ��");
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
        printf("�޸�ѧ��ѧ�Ű� 1 ���޸�ѧ�������� 2 ���޸�ѧ�����䰴 3 ���޸�ѧ���༶�� 4 ���˳���0\n");
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
        printf("ѧ�ţ�%d  ������%s  ���䣺%d  �༶��%d\n",P->xue_hao,P->xin_ming.val,P->niang_ling,P->ban_ji);
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
        printf("���ѧ����Ϣ�� 1 ��ɾ��ѧ����Ϣ�� 2 ���޸�ѧ����Ϣ�� 3 ����ʾ����ѧ����Ϣ�� 4 ���˳��� 0\n");
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