#include "duLinkedList.h"
#include<stddef.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
     (*L) = (DuLinkedList)malloc(sizeof(DuLNode));
     if( !(*L) ){
        printf("创建失败\n");
        return ERROR;
     }
     (*L)->next = NULL;
     (*L)->prior = NULL;
     printf("创建成功\n");
     return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
     if (*L == NULL){
         printf("不存在链表，请先创建链表\n");
         return;
     }
     DuLinkedList p;
     while (*L){
         p = (*L)->next;
         free(*L);
         *L = p;
     }
     printf("销毁成功\n");
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
     if(!p) {
        printf("想插入的位置不存在\n");
        return ERROR;
     }
     if (p->prior == NULL){
        printf("链表中未存入元素\n");
        return ERROR;
     }
     q->prior = p->prior;
     p->prior->next = q;
     q->next = p;
     p->prior = q;
     printf("恭喜！插入完成\n");
     return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if(!p) {
        printf("想插入的位置不存在\n");
        return ERROR;
    }
    q->next = p->next;
    if (p->next != NULL){
        p->next->prior = q;
    }
    q->prior = p;
    p->next = q;
    printf("恭喜！插入完成\n");
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if( ! isExistLinked(p) ) return ERROR;
    if(p->next == NULL){
        printf("该位置后没有元素\n");
        return ERROR;
    }
	DuLNode *q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	printf("删除成功，删除的元素的值为%d\n", *e);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    if ( ! isExistLinked(L) ) return;
    DuLNode *p = L->next;
	while(p){
		visit(p->data);
		p = p->next;
	}
}

void visit(ElemType e){
	printf("%d  ",e);
}

//将插入的位置转化为结点
DuLNode* TransLocation(DuLNode *p, ElemType location){
    DuLNode *temp = p;
    for(int i = 1; i < location; i++) {
        temp = temp->next;
        if (temp == NULL) return temp;
    }
    return temp;
}

//将插入的值转换为结点
DuLNode* TransValue(ElemType value){
    DuLNode *temp = (DuLNode*)malloc(sizeof(DuLNode));
    temp->data  = value;
    temp->prior = NULL;
    temp->next  = NULL;
    return temp;
}

int isExistLinked(DuLNode *L){
    if (L == NULL){
        printf("不存在链表，请先创建链表\n");
        return 0;
    }
    return 1;
}
