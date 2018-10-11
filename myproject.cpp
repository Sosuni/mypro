#include<stdio.h>
#include<string.h>
#include<iostream>
#include<sys/time.h>
#include<malloc.h>
int Hannie(int n);
void printout(unsigned int N);
void InsertSort(int a[],int n);
void BubbleSort(int a[],int n);
void swap(int arr[],int i ,int j);

struct timeval begin,end;
typedef struct node{
    int data;
    node *next;
}Node_List;

int main(void){
    int a[20]={1,-2,23,6,4,5,-5,35,53,67,43,21,34,54,23,12,67,23,204,-232};
    int b[20]={1,2,5,7,18,26,30,31,32,33,55,55,63,76,80,89,94,96,102,107};
    const int c[20]={1,-2,23,6,4,5,-5,35,53,67,43,21,34,54,23,12,67,23,204,-232};
    int lengtha =sizeof(a)/sizeof(int);
    int lengthb = sizeof(b)/sizeof(int);

    for(int i;i<5;i++){
        for(int i=0;i<lengtha;i++){
            a[i]=c[i];
            printf("%d ",a[i]);
        }
        gettimeofday(&begin,NULL);
        InsertSort(a,lengtha);
        //BubbleSort(a,lengtha);
        //BubbleSort(b,lengthb);
        gettimeofday(&end,NULL);
        putchar('\n');
        printf("Time = %ld us\n",1000000*(end.tv_sec-begin.tv_sec)+(end.tv_usec-begin.tv_usec));
    }      

    for(int i=0;i<lengtha;i++){
        printf("%d ",a[i]);
        //printf("%d ",b[i]);
    }
    getchar();
    return 0;
}

int Hannie(int n){
        return n==1 ? 1 :(2*Hannie(n-1)+1);
}

void printout(unsigned int N){
    if(N>=10)
        printout(N/10);
    printf("%d",N%10);
    //return (N>=10) ?(printf("%d",N%10)):(printout(N/10));
}

void InsertSort(int a[],int n){

    for(int i=0;i<=n;i++){
        for(int j=i;j<n;j++){
            if(a[j]<a[i])
                swap(a,i,j);
        }
    }
}
void BubbleSort(int a[],int n){

    for(int i=0;i<n;i++){
        bool Sorted = true;
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(a,j,j+1);
                Sorted = false;
            }   
        }
        if(Sorted==true)
                return;
    }

}

void swap(int arr[],int i ,int j){
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
}

// unsigned int length(const int arr[]){
//     while()
//     return n
// }
class List{
    public:
    int length;
    struct node* header;
    struct node* ender;
    
    List(){
        header =(Node_List*)(malloc(sizeof(Node_List)));
        ender = header;
        header->next==NULL;
        ender ->next==NULL;
    }

    // Node_List* NodeCreate(Node_List *header){
    //     header =(Node_List*)(malloc(sizeof(Node_List)));
    //     ender = header;
    //     header->next==NULL;
    //     ender ->next==NULL;
    //     return header;
    // }

    void NodeAdd(Node_List *header){
        if(header==NULL){
            printf("add fail ,list is empty");
            return;
        }
        else{
            Node_List* p =(Node_List*)(malloc(sizeof(Node_List)));
            p->next = NULL;
            ender->next = p;
            ender = p;
        }

    }

    bool NodeEmpty (Node_List *header){
        return header->next==NULL;
    }

    void PrintfNode(Node_List *header){
        for(Node_List* p=header;p!=NULL;p=p->next){
            int i = 0;
            printf("%d ,%d",p->data,i);
            i++;
        }
    }



};

