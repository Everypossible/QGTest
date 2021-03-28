#include<stdio.h>
#include "linkedList.h"

//主函数负责显示界面和调用来实现功能

//显示界面的函数
void view(){
    printf("____________________________________________\n");
    printf("|    1. 新建链表                            |\n");
    printf("|    2. 查询链表某个值的位置                |\n");
    printf("|    3. 删除链表某个位置后一个位置的元素    |\n");
    printf("|    4. 在链表的某个位置插入元素            |\n");
    printf("|    5. 单链表奇偶互换                      |\n");
    printf("|    6. 寻找单链表的中点                    |\n");
    printf("|    7. 判断链表是否成环                    |\n");
    printf("|    8. 反转链表                            |\n");
    printf("|    9. 销毁链表                            |\n");
    printf("|___________________________________________|\n\n");
    printf("请根据您所需要的功能输入功能前的数字：\n");
}

int main(){
    int    input = 0;
    int    num;
    char   c;
    LNode *head = NULL;
    LNode *location = (LNode*)malloc(sizeof(LNode));
    LNode *value = (LNode*)malloc(sizeof(LNode)); ;


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
            InitList(&head);
            break;
        case '2':
            printf("请问您需要查询值为多少的元素的第一个位置呢？\n");
            scanf("%d", &input);
            SearchList(head, input);
            break;
        case '3':
            printf("请问您需要删除第几个元素后的一个元素呢？\n");
            scanf("%d", &input);
            DeleteList(head, &input);
            break;
        case '4':
            printf("请问您需要在第几个元素后面插入元素呢？(输入完请按回车)\n");
            scanf("%d", &input);
            location = TransLocation(head, input);
            printf("请问您插入的值是多少呢？(输入完请按回车)\n");
            scanf("%d", &num);
            value = TransValue(num);
            InsertList(location, value);
            break;
        case '5':
            ReverseEvenList(&head);
            printf("奇偶互换后的链表的各元素值依次是：\n");
            TraverseList(head, visit);
            printf("\n");
            break;
        case '6':
            FindMidNode(&head);
            break;
        case '7':
            IsLoopList(head);
            break;
        case '8':
            printf("反转前链表中各节点的数据是：\n");
            TraverseList(head, visit);
            printf("\n");
            ReverseList(&head);
            printf("反转后链表中各节点的数据是：\n");
            TraverseList(head, visit);
            printf("\n");
            break;
        case '9':
            DestroyList(&head);
        break;
        default: printf("您输入的不符合要求，请重试\n");
            break;
        }
    }
    return 0;
}
