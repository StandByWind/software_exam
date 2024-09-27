#include <stdio.h>
#include <stdlib.h>

typedef struct string {
    char val[20];
}string;

typedef struct Zhang{
    string a;
    struct Zhang* next;
}zhang;

typedef struct Operate{
    int x;
    string a;
    struct Operate* next;
}operate;

void insert(zhang* content,operate* record,string* a){
    zhang* P;
    operate* Q;
    P=(zhang*) malloc(sizeof(zhang));
    P->a=*a;
    P->next=content->next;
    content->next=P;
    Q=(operate*) malloc(sizeof(operate));
    Q->next=record->next;
    record->next=Q;
    Q->x=1;
}

void delete(zhang* content,operate* record){
    zhang* P;
    operate* Q;
    if(content->next==NULL){
        printf("栈空，删除失败");
    }else{
        Q=(operate*) malloc(sizeof(operate));
        Q->a=content->next->a;
        Q->next=record->next;
        record->next=Q;
        Q->x=2;
        P=content->next;
        content->next=P->next;
        free(P);
    }
}

void cancel(zhang* content,operate* record){
    if(!record->next){
        printf("还没操作，撤销失败");
    }else{
        if(record->next->x==1){
            delete(content,record);
        }else if(record->next->x==2){
            string *a=&(record->next->a);
            insert(content,record,a);
        }
    }
}

void output(zhang* content){
    if(content==NULL){
        return;
    }
    if(content->next){
        output(content->next);
    }
    printf("%s",content->a.val);


}

int main(){
    int y;
    zhang* content;
    operate* record;
    content=(zhang*) malloc(sizeof(zhang));
    record=(operate*) malloc(sizeof(operate));
    content->next=NULL;
    record->next=NULL;
    do{
        printf("插入按 1 ，删除按 2 ，撤销按 3 ，输出按 4 ，退出按 0\n");
        scanf("%d",&y);
        if(y==1){
            string *a;
            a=(string *) malloc(sizeof(string));
            printf("请输入：");
            scanf("%s",a->val);
            insert(content,record,a);
        }else if(y==2){
            delete(content,record);
        }else if(y==3){
            cancel(content,record);
        }else if(y==4){
            if(!content->next){
                printf("没有输入，输出失败");
            }else{
                zhang* tamp;
                tamp=content->next;
                output(tamp);
            }
        }
    } while (y);
}