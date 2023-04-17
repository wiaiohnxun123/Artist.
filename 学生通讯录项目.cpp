#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define OVERFLOW 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int Status;
//ѧ���ṹ�� 
typedef struct{
	char no[10];
	char name[30];
	char phone[16];
}Student;
//���Ա�����Դ洢�ṹ 
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
	printf("���Ա��ȣ�%d\n",L.length);
	printf("��ʼ�����Ա�ռ䣺%d\n",L.listsize);
	return 1; 
}
//���Ա��� 
void CreateList_Sq(SqList&L,int n){
	int i;
	printf("����ѧ��������");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("������ѧ��%d��Ϣ\n",i+1);
		printf("������%dѧ����ѧ�ţ�",i+1);
		     scanf("%s",&L.elem[i].no);
	    printf("������%dѧ����������",i+1);
	         scanf("%s",&L.elem[i].name);
	    printf("������%dѧ���ĵ绰��",i+1);
	         scanf("%s",&L.elem[i].phone);
	    L.length++;
	} 
}
//���Ա����
void PrintList_Sq(SqList L){
 printf("ѧ����Ϣ��\n");
 int i;
 for(i=0;i<L.length;i++){
  printf("��%dѧ����Ϣ��",i+1);
  printf("ѧ�ţ�%s",L.elem[i].no);
  printf("������%s",L.elem[i].name);
  printf("�绰��%s\n",L.elem[i].phone);
 }
} 
//���Ա��ѯ 
Status GetElem_Sq(SqList L,int i){
	printf("�����ѯѧ������ţ�");
	scanf("%d",&i);
	if(i<1||i>L.length) return 0;
	printf("��%dѧ������Ϣ��",i);
	printf("ѧ�ţ�%s",L.elem[i-1].no);
	printf("������%s",L.elem[i-1].name);
	printf("�绰��%s\n",L.elem[i-1].phone);
	return 1;
}
//����ѧ����Ϣ
Status ListInsert_Sq(SqList &L,int i){
 Student *newbase;
 Student *q;
 Student *p;
 printf("�������ĸ�λ�ò����µ�Ԫ�أ�");
 scanf("%d",&i);
 if(i < 1 || i >L.length+1) return 0;
 if(L.length >= L.listsize){
// ��ǰ�洢�ռ�����
     newbase=(Student *)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(Student));
  if(!newbase) exit(OVERFLOW);
   L.elem=newbase;
   L.listsize+=LISTINCREMENT;
 } 
 q = &(L.elem[i-1]);
 for (p = &(L.elem[L.length-1]); p >= q; --p);
    *(p+1) = *p;
    printf("���������ѧ����Ϣ\n");
    printf("������ѧ����ѧ�ţ�");
    scanf("%s",&q->no); 
    printf("������ѧ����������");
    scanf("%s",&q->name);
    printf("������ѧ���ĵ绰��");
    scanf("%s",&q->phone);
    ++L.length;
    return 1; 
}

//ɾ��ѧ����Ϣ 
Status ListDelete_Sq(SqList &L,int i){
	Student *q;
	Student *p; 
	printf("����Ҫɾ���ڼ���Ԫ�أ�");
	scanf("%d",&i);
	if((i<1)||(i>L.length)) return 0;
	p=&(L.elem[i-1]);
	q=L.elem+L.length-1;
	for(++p;p<=q;++p)
	*(p-1)=*p;
	--L.length;
	printf("ɾ���ɹ���\n");
	return 1; 
}
int main(){
	SqList L;
	int x,n,i;	
	while(1){
		printf("       --------����ѡ��--------\n");
		printf("             1:��ʼ�����Ա�\n");
		printf("             2:����ѧ����Ϣ\n"); 
		printf("             3:���ѧ����Ϣ\n");
		printf("             4:��i��λ�ò���ѧ����Ϣ\n");
		printf("             5:��ѯ�ڼ���ѧ����Ϣ\n");
		printf("             6:ɾ���ڼ���ѧ����Ϣ\n");
		printf("       -------------------------\n");
		printf("�����ּ�ѡ��Ҫִ�еĲ���:");
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
            printf("��������ֲ���ȷ\n");
            break;
        }
   	}
   	return 0;
}





