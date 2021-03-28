#include<stddef.h>
#include "linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    *L = (LinkedList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    printf("恭喜！创建单链表成功\n");
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    if ( ! isExistLinked(*L) ) return;
    LNode *p;
    while ((*L)->next){
        p = (*L)->next;
        (*L)->next = p->next;
        free(p);
    }
    free(*L);
    printf("该单链表已成功销毁\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    if (p == NULL){
        printf("插入位置无效\n");
        return ERROR;
    }
    if (q == NULL){
        printf("插入数据无效\n");
        return ERROR;
    }
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    if( ! isExistLinked(p) ) return ERROR;
    if(p->next == NULL){
        printf("该位置后没有元素\n");
        return ERROR;
    }
	LNode *q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	printf("删除成功，删除的元素的值为%d\n", *e);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    if ( ! isExistLinked(L) ) return;
    LNode *p = L->next;
	while(p){
		visit(p->data);
		p=p->next;
	}
}

void visit(ElemType e){
	printf("%d  ",e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    int i = 0;
    while(L){
        i++;
        if(L->data == e){
            printf("您查询的元素数值位于第%d个位置\n", i);
            return SUCCESS;
        }
        L = L->next;
    }
    printf("查询失败\n");
    return ERROR;
}


/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    if( ! isExistLinked(*L) ) return ERROR;
	LNode *p, *q = NULL, *r = NULL;
	p = (*L)->next;
	(*L)->next = NULL;
	while(p){
		q = p->next;
		p->next = r;
		r = p;
		p = q;
	}
	(*L)->next = r;
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    if( ! isExistLinked(L) ) return ERROR;
    if(L->next == NULL || L->next->next == NULL){
        printf("链表中未存储数据或数据在2个以下所以不能成环\n");
        return ERROR;
    }
	LNode *slow, *fast;
	slow = L->next;
	fast = L->next->next;
	while(1){
		if(!fast || !slow){
		    printf("该链表不是循环链表\n");
            return ERROR;
		}
		if(fast == slow){
		    printf("该链表是循环链表\n");
                return ERROR;
		}
		else{
			fast = fast->next->next;
			slow = slow->next;
		}
	}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    if( ! isExistLinked(L) ) return (*L);
    if((*L)->next == NULL){
        printf("链表中元素不足2个，无法交换\n");
        return (*L);
    }

    LNode *p = *L;
    LNode *q = p->next;
    while (q != NULL && q->next != NULL){
        p->next = q->next;
        q->next = p->next->next;
        p->next->next = q;
        p = q;
        q = q->next;
    }
    return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    if( ! isExistLinked(*L) ) return (*L);
    if((*L)->next == NULL){
        printf("链表中元素不足2个，不存在中间元素\n");
        return (*L);
    }
	LNode *mid = (*L), *fast = (*L);
	while(fast != NULL){
//一个指针两倍速走，一个一倍速走
		if(fast->next == NULL){
                fast = fast->next;
		}else{
		    fast = fast->next->next;
		}
		mid = mid->next;
	}
	return mid;
}



//将插入的位置转化为结点
LNode* TransLocation(LNode *p, ElemType location){
    LNode *temp = p;
    for(int i = 1; i < location; i++) {
        temp = temp->next;
        if (temp == NULL) return temp;
    }
    return temp;
}

//将插入的值转换为结点
LNode* TransValue(ElemType value){
    LNode *temp = (LNode*)malloc(sizeof(LNode));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

int isExistLinked(LNode *L){
    if (L == NULL){
        printf("不存在链表，请先创建链表\n");
        return 0;
    }
    return 1;
}
