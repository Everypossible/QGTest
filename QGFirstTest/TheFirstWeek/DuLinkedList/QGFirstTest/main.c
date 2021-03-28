#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

//主函数负责显示界面和调用来实现功能

//显示界面的函数
void view(){
    printf("____________________________________________\n");
    printf("|    1. 新建双链表                          |\n");
    printf("|    2. 删除链表某个位置后一个位置的元素    |\n");
    printf("|    3. 在链表的某个位置前插入元素          |\n");
    printf("|    4. 在链表的某个位置后插入元素          |\n");
    printf("|    5. 销毁链表                            |\n");
    printf("|___________________________________________|\n\n");
    printf("请根据您所需要的功能输入功能前的数字：\n");
}

int main(){
    int      input = 0;
    int      num;
    char     c;
    DuLNode *head = NULL;
    DuLNode *location = (DuLNode*)malloc(sizeof(DuLNode));
    DuLNode *value = (DuLNode*)malloc(sizeof(DuLNode)); ;


    while(1){
        fflush(stdin);
        view();
        //避免输入字符串时崩掉
        c = getchar();
        while ( !(c > 48 && c < 58) ) {
            printf("请输入1-9，不要乱输入哦\n");
            fflush(stdin);
            c = getchar();
        }
        switch(c){
        case '1':
            InitList_DuL(&head);
            break;
        case '2':
            printf("请问您需要删除第几个元素后的一个元素呢？\n");
            scanf("%d", &input);
            DeleteList_DuL(head, &input);
            break;
        case '3':
            printf("请问您需要在第几个元素前面插入元素呢？(输入完请按回车)\n");
            scanf("%d", &input);
            location = TransLocation(head, input);
            printf("请问您插入的值是多少呢？(输入完请按回车)\n");
            scanf("%d", &num);
            value = TransValue(num);
            InsertBeforeList_DuL(location, value);
            break;
        case '4':
            printf("请问您需要在第几个元素后面插入元素呢？(输入完请按回车)\n");
            scanf("%d", &input);
            location = TransLocation(head, input);
            printf("请问您插入的值是多少呢？(输入完请按回车)\n");
            scanf("%d", &num);
            value = TransValue(num);
            InsertAfterList_DuL(location, value);
            break;
        case '5':
            DestroyList_DuL(&head);
        break;
        default:
            printf("您输入的不符合要求，请重试\n");
            break;
        }
    }
    return 0;
}

