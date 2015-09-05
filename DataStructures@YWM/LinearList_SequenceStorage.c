//
//  LinearList_SequenceStorage.c
//  DataStructures@YWM
//
//  Created by 孙培峰 on 9/5/15.
//  Copyright (c) 2015 孙培峰. All rights reserved.
//

#include <stdio.h>
#include "LinearList_SequenceStorage.h"

/**
 初始化一个线性表

 :return: 状态
 */
Status initList_Sq(SqList *l){

    l->elem = (ElemType *)malloc(LIST_INIT_SIZE *sizeof(ElemType));
    if (!l->elem) {
        exit(0);
    }
    l->length = 0;
    l->listSize = LIST_INIT_SIZE;
    return OK;
}

/**
 *    在顺序线性表中 第i个位置之前 插入元素e
 *
 *    @param l 线性表,下标范围:1到length
 *    @param i 插入到第i个位置之前,合法长度:1到length+1(在表末尾添加)
 *    @param e 待插入元素
 *
 *    @return 状态
 */
Status insertIntoList(SqList *l, int i, ElemType e){

    //注意这里是i>length+1 !
    if (i<0 || i>l->length+1) {
        return ERROR;
    }
    if (l->length >= l->listSize) {
        //当前空间已满，增加分配
        //注意申请的空间为 现空间的总和！
        ElemType *newBase = (ElemType *)realloc(l->elem, (LIST_INIT_SIZE+LISTINCREMENT) * sizeof(ElemType));
        if (!newBase) {
            //出现内存问题时都要直接exit
            exit(OVERFLOW);
        }
        l->elem = newBase;//新基地址
        l->listSize = l->listSize + LISTINCREMENT;//新的存储容量
    }
    ElemType *q = &(l->elem[i-1]);//代表要插入的位置

    //将q上面及其后的元素后移
    //p作为临时存储的变量,值从l的表尾开始,向前遍历,一直取到q处为止(包括q)
    //判断条件:p的地址在q后面,或者在q上,都进行操作
    for (ElemType *p = &l->elem[l->length-1]; p >= q; --p) {
        *(p+1) = *p;
    }

    //在要插入的位置写入e
    *q = e;
    ++l->length;
    return OK;
}

/**
 *    从l中删除第i个元素,用e返回已删除元素的值
 *
 *    @param l <#l description#>
 *    @param i <#i description#>
 *    @param e <#e description#>
 *
 *    @return <#return value description#>
 */
Status deleteFromList(SqList *l, int i, ElemType *e){

    if(i<1 || i>l->length)
    {
        //i值不合法
        return ERROR;
    }

    //q为被删除元素的位置,在下标i-1处
    ElemType *q = &(l->elem[i-1]);
    *e = *q;
    //p为指向末尾的指针
    ElemType *p = &l->elem[l->length-1];

    for (; q<p; q++) {
        *q = *(q+1);
    }

    --l->length;
    return OK;
}

/**
 *    自用:遍历表
 *
 *    @param l <#l description#>
 *
 *    @return <#return value description#>
 */
int* traverseList(SqList l){
    int *traversedResultChars;
    traversedResultChars = malloc(sizeof(l.elem)*l.length);
    for (int i = 0; i<l.length; i++) {
        *(traversedResultChars+i) = l.elem[i];
    }
    return traversedResultChars;
}


/**
 *    自用:修改表l中的第i个元素的值为e
 *
 *    @param l <#l description#>
 *    @param i 第i个元素,i>=1
 *
 *    @return <#return value description#>
 */
int modifyElementInList(SqList *l, int i, ElemType e){

    if(i<1 || i>l->length){
        return ERROR;
    }

    l->elem[i-1] = e;
    return OK;
}



























