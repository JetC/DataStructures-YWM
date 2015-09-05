//
//  LinearList_SequenceStorage.h
//  DataStructures@YWM
//
//  Created by 孙培峰 on 9/5/15.
//  Copyright (c) 2015 孙培峰. All rights reserved.
//

#ifndef __DataStructures_YWM__LinearList_SequenceStorage__
#define __DataStructures_YWM__LinearList_SequenceStorage__

#include "PublicDeclarations.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef char ElemType;

typedef struct {

    ElemType *elem;
    int length;//目前表的长度
    int listSize;//当前表的存储容量
} SqList;

Status initList_Sq(SqList *l);
Status insertIntoList(SqList *l, int i, ElemType e);
Status deleteFromList(SqList *l, int i, ElemType e);
int modifyElementInList(SqList *l, int i, ElemType e);




#endif /* defined(__DataStructures_YWM__LinearList_SequenceStorage__) */
