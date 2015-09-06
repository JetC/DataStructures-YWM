//
//  LinearListPrc.c
//  DataStructures@YWM
//
//  Created by 孙培峰 on 9/5/15.
//  Copyright (c) 2015 孙培峰. All rights reserved.
//

#include "LinearListPrc.h"

SqList setupLinearListUsingFile(FILE *fin)
{
    SqList list;
    initList_Sq(&list);
    if (feof(fin)) {
        rewind(fin);
    }
    int i = 1;
    while (!feof(fin)) {

        int temp;
        fscanf (fin, "%d", &temp);
        //此处不能直接modify,因为此时表长length为0,不包含元素
        insertIntoList(&list, i, temp);
        i++;
    }
    return list;
}