#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define OVERFLOW 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int Status;
//学生结构体 
typedef struct{
	char no[10];
	char name[30];
	char phone[16];
}Student;
//线性表的线性存储结构 
typedef struct{
	Student *elem;
	int length;
	int listsize;
}SqList;
Status InitList_Sq(SqList&L); 
void CreateList_Sq(SqList&L,int); 
void PrintList_Sq(SqList L);
Status GetElem_Sq(SqList L,int); 
Status ListInsert_Sq(SqList &L,int);
Status ListDeiete_Sq(SqList &L,int);

Status InitList_Sq(SqList&L){
	L.elem=(Student*)malloc(LIST_INIT_SIZE*sizeof(Student));
	if(!L.elem)exit(OVERFLOW);
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	printf("线性表长度：%d\n",L.length);
	printf("初始化线性表空间：%d\n",L.listsize);
	return 1; 
}
//线性表建立 
void CreateList_Sq(SqList&L,int n){
	int i;
	printf("输入学生人数：");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("请输入学生%d信息\n",i+1);
		printf("请输入%d学生的学号：",i+1);
		     scanf("%s",&L.elem[i].no);
	    printf("请输入%d学生的姓名：",i+1);
	         scanf("%s",&L.elem[i].name);
	    printf("请输入%d学生的电话：",i+1);
	         scanf("%s",&L.elem[i].phone);
	    L.length++;
	} 
}
//线性表输出
void PrintList_Sq(SqList L){
 printf("学生信息：\n");
 int i;
 for(i=0;i<L.length;i++){
  printf("第%d学生信息：",i+1);
  printf("学号：%s",L.elem[i].no);
  printf("姓名：%s",L.elem[i].name);
  printf("电话：%s\n",L.elem[i].phone);
 }
} 
//线性表查询 
Status GetElem_Sq(SqList L,int i){
	printf("输入查询学生的序号：");
	scanf("%d",&i);
	if(i<1||i>L.length) return 0;
	printf("第%d学生的信息：",i);
	printf("学号：%s",L.elem[i-1].no);
	printf("姓名：%s",L.elem[i-1].name);
	printf("电话：%s\n",L.elem[i-1].phone);
	return 1;
}
//插入学生信息
Status ListInsert_Sq(SqList &L,int i){
 Student *newbase;
 Student *q;
 Student *p;
 printf("输入在哪个位置插入新的元素：");
 scanf("%d",&i);
 if(i < 1 || i >L.length+1) return 0;
 if(L.length >= L.listsize){
// 当前存储空间已满
     newbase=(Student *)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(Student));
  if(!newbase) exit(OVERFLOW);
   L.elem=newbase;
   L.listsize+=LISTINCREMENT;
 } 
 q = &(L.elem[i-1]);
 for (p = &(L.elem[L.length-1]); p >= q; --p);
    *(p+1) = *p;
    printf("请输入插入学生信息\n");
    printf("请输入学生的学号：");
    scanf("%s",&q->no); 
    printf("请输入学生的姓名：");
    scanf("%s",&q->name);
    printf("请输入学生的电话：");
    scanf("%s",&q->phone);
    ++L.length;
    return 1; 
}

//删除学生信息 
Status ListDelete_Sq(SqList &L,int i){
	Student *q;
	Student *p; 
	printf("输入要删除第几个元素：");
	scanf("%d",&i);
	if((i<1)||(i>L.length)) return 0;
	p=&(L.elem[i-1]);
	q=L.elem+L.length-1;
	for(++p;p<=q;++p)
	*(p-1)=*p;
	--L.length;
	printf("删除成功：\n");
	return 1; 
}
int main(){
	SqList L;
	int x,n,i;	
	while(1){
		printf("       --------操作选项--------\n");
		printf("             1:初始化线性表\n");
		printf("             2:输入学生信息\n"); 
		printf("             3:输出学生信息\n");
		printf("             4:第i个位置插入学生信息\n");
		printf("             5:查询第几个学生信息\n");
		printf("             6:删除第几个学生信息\n");
		printf("       -------------------------\n");
		printf("按数字键选择要执行的操作:");
		scanf("%d",&x);
		printf("\n");
		switch(x) {
        case 1:
            InitList_Sq(L);
            break;
        case 2:
            CreateList_Sq(L,n);
            break;
        case 3:
            PrintList_Sq(L);
            break;
        case 4:
            ListInsert_Sq(L,i);
            break;
        case 5:
            GetElem_Sq(L,i);
            break;   
        case 6:
            ListDelete_Sq(L,i);
            break;
        default:
            printf("输入的数字不正确\n");
            break;
        }
   	}
   	return 0;
}





