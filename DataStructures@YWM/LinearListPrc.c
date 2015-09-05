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
    while (!feof(fin)) {

        int i = 1;
        int temp;
        fscanf (fin, "%d", &temp);
        modifyElementInList(&list, i, temp);
        i++;
    }
    return list;
}