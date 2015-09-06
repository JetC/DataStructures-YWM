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
    ElemType *a = traverseList(sqlist);
    printf("%d",*a);
//        fclose(fin);

    rewind(fin);
    compareListWithGivenResultFile(sqlist, fin);
    return OK;
}

int compareListWithGivenResultFile(SqList listToTest, FILE *resultFin)
{
    SqList list = setupLinearListUsingFile(resultFin);
    ElemType *resultArr = traverseList(list);
    ElemType *listToTestArr = traverseList(listToTest);
    *resultArr = 0;
    *listToTestArr = 0;
    return OK;
}

int compareListWithList(SqList list1, SqList list2){
    return OK;
}









