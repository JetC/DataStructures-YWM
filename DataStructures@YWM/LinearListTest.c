//
//  LinearListTest.c
//  DataStructures@YWM
//
//  Created by 孙培峰 on 9/5/15.
//  Copyright (c) 2015 孙培峰. All rights reserved.
//

#include "LinearListTest.h"
#include "LinearListPrc.h"

int testInsertDelete()
{
    FILE *fin = fopen("/Users/sunpeifeng/Desktop/SourceTree/DataStructures@YWM/DataStructures@YWM/SqListSource", "r");

    SqList sqlist = setupLinearListUsingFile(fin);
    int e = 9999;
    deleteFromList(&sqlist, 1, &e);
    int *a = traverseList(sqlist);
    *a = 0;
    return OK;
}

//int compareListWithGivenResultFile(SqList list, FILE *resultFin)
//{
//
//}









