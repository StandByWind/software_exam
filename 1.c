#include <stdio.h>
#include <stdlib.h>

void radom(int** a){
    int c,d,num;
    do{
        c=rand()%4;
        d=rand()%4;
    } while (a[c][d]!=0);
    num=(rand())%2;
    if(a[c][d]==0&&num==0){
        a[c][d]=num+2;
    }else if(a[c][d]==0&&num==1) {
        a[c][d] = num + 3;
    }
}

void left(int** a){
    for(int i=0;i<4;i++){
        int fast=0,slow=0;
        for(int j=0;j<4;j++){
            if(a[i][j]){
                if(j==0||(j!=0&&a[i][j-1]!=0)){
                    slow++;
                }else{
                    a[i][slow++]=a[i][fast];
                    a[i][fast]=0;
                }
            }
            fast++;
        }
        if(slow){
            if(slow==1){
                continue;
            }else if(slow==2){
                if(a[i][0]==a[i][1]){
                    a[i][0]*=2;
                    a[i][1]=0;
                }else{
                    continue;
                }
            }else if(slow==3){
                if(a[i][0]==a[i][1]){
                    a[i][0]*=2;
                    a[i][1]=a[i][2];
                    a[i][2]=0;
                }else if(a[i][2]==a[i][1]){
                    a[i][1]*=2;
                    a[i][2]=0;
                }else{
                    continue;
                }
            }else if(slow==4){
                if(a[i][0]==a[i][1]){
                    a[i][0]*=2;
                    a[i][1]=a[i][2];
                    a[i][2]=a[i][3];
                    a[i][3]=0;
                }else if(a[i][2]==a[i][1]){
                    a[i][1]*=2;
                    a[i][2]=a[i][3];
                    a[i][3]=0;
                }else if(a[i][2]==a[i][3]){
                    a[i][2]*=2;
                    a[i][3]=0;
                }else{
                    continue;
                }
            }
        }
    }
}

void right(int** a){
    for(int i=0;i<4;i++){
        int fast=3,slow=3;
        for(int j=3;j>=0;j--){
            if(a[i][j]){
                if(i==3||(j!=3&&a[i][j+1]!=0)){
                    slow--;
                }else{
                    a[i][slow--]=a[i][fast];
                    a[i][fast]=0;
                }
            }
            fast--;
        }
        if(slow!=3){
            if(slow==2){
                continue;
            }else if(slow==1){
                if(a[i][3]==a[i][2]){
                    a[i][3]*=2;
                    a[i][2]=0;
                }else{
                    continue;
                }
            }else if(slow==0){
                if(a[i][3]==a[i][2]){
                    a[i][3]*=2;
                    a[i][2]=a[i][1];
                    a[i][1]=0;
                }else if(a[i][2]==a[i][1]){
                    a[i][2]*=2;
                    a[i][1]=0;
                }else{
                    continue;
                }
            }else if(slow==-1){
                if(a[i][3]==a[i][2]){
                    a[i][3]*=2;
                    a[i][2]=a[i][1];
                    a[i][1]=a[i][0];
                    a[i][0]=0;
                }else if(a[i][2]==a[i][1]){
                    a[i][2]*=2;
                    a[i][1]=a[i][0];
                    a[i][0]=0;
                }else if(a[i][1]==a[i][0]){
                    a[i][1]*=2;
                    a[i][0]=0;
                }else{
                    continue;
                }
            }
        }
    }
}

void up(int** a){
    for(int j=0;j<4;j++){
        int fast=0,slow=0;
        for(int i=0;i<4;i++){
            if(a[i][j]){
                if(i==0||(i!=0&&a[i-1][j]!=0)){
                    slow++;
                }else{
                    a[slow++][j]=a[fast][j];
                    a[fast][j]=0;
                }
            }
            fast++;
        }
        if(slow){
            if(slow==1){
                continue;
            }else if(slow==2){
                if(a[0][j]==a[1][j]){
                    a[0][j]*=2;
                    a[1][j]=0;
                }
            }else if(slow==3){
                if(a[0][j]==a[1][j]){
                    a[0][j]*=2;
                    a[1][j]=a[2][j];
                    a[2][j]=0;
                }else if(a[2][j]==a[1][j]){
                    a[1][j]*=2;
                    a[2][j]=0;
                }
            }else if(slow==4){
                if(a[0][j]==a[1][j]){
                    a[0][j]*=2;
                    a[1][j]=a[2][j];
                    a[2][j]=a[3][j];
                    a[3][j]=0;
                }else if(a[2][j]==a[1][j]){
                    a[1][j]*=2;
                    a[2][j]=a[3][j];
                    a[3][j]=0;
                }else if(a[2][j]==a[3][j]){
                    a[2][j]*=2;
                    a[3][j]=0;
                }
            }
        }
    }
}

void down(int** a){
    for(int j=0;j<4;j++){
        int fast=3,slow=3;
        for(int i=3;i>=0;i--){
            if(a[i][j]){
                if(i==3||(i!=3&&a[i+1][j]!=0)){
                    slow--;
                }else{
                    a[slow--][j]=a[fast][j];
                    a[fast][j]=0;
                }
            }
            fast--;
        }
        if(slow!=3){
            if(slow==2){
                continue;
            }else if(slow==1){
                if(a[3][j]==a[2][j]){
                    a[3][j]*=2;
                    a[2][j]=0;
                }
            }else if(slow==0){
                if(a[3][j]==a[2][j]){
                    a[3][j]*=2;
                    a[2][j]=a[1][j];
                    a[1][j]=0;
                }else if(a[2][j]==a[1][j]){
                    a[2][j]*=2;
                    a[1][j]=0;
                }
            }else if(slow==-1){
                if(a[3][j]==a[2][j]){
                    a[3][j]*=2;
                    a[2][j]=a[1][j];
                    a[1][j]=a[0][j];
                    a[0][j]=0;
                }else if(a[2][j]==a[1][j]){
                    a[2][j]*=2;
                    a[1][j]=a[0][j];
                    a[0][j]=0;
                }else if(a[1][j]==a[0][j]){
                    a[1][j]*=2;
                    a[0][j]=0;
                }
            }
        }
    }
}

int show(int** a){
    int sum=0,flag=0;
    for(int p=0;p<4;p++){
        for(int q=0;q<4;q++){
            printf("%d  ",a[p][q]);
            if(!a[p][q]){
                sum++;
            }
            if(a[p][q]==2048){
                flag=1;
            }
        }
        printf("\n");
    }
    if(flag){
        printf("游戏胜利！");
    }
    return sum;
}

int main(){
    int** a;
    int x,sum;
    a=(int**)calloc(4,sizeof(int*));
    for(int i=0;i<4;i++){
        a[i]=(int*)calloc(4,sizeof(int));
    }
    radom(a);
    show(a);
    do{
        printf("向左按 1 ，向右按 2 ，向上按 3 ，向下按 4 ，退出按 0\n");
        scanf("%d",&x);
        if(x==1){
            left(a);
            radom(a);
            show(a);
        }else if(x==2){
            right(a);
            radom(a);
            show(a);
        }else if(x==3) {
            up(a);
            radom(a);
            show(a);
        }else if(x==4){
            down(a);
            radom(a);
            sum=show(a);
            if(!sum){
                printf("没有可移动的方块，游戏结束");
                x=0;
            }
        }
    } while (x);
}

