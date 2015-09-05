//
//  main.c
//  DataStructures@YWM
//
//  Created by 孙培峰 on 9/5/15.
//  Copyright (c) 2015 孙培峰. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    int a = 5,b = 10;
/**
 *    此处,pointer为指向int的指针,*pointer为所指地址上类型为int的值; 对其赋值时,值是赋给p的(而不是*p),所以赋值符号右边只能是地址
 */
    int *pointer = &b;
    printf("Ori\nAddress:a:%p,b:%p,pointer:%p\n",&a,&b,&pointer);

    printf("Next...\n\n");
    pointer = &a;
    printf("Address:a:%p,pointer:%p\n",&a,&pointer);
    printf("(should be a)*pointer:%i\n",*pointer);

    *pointer = 233;
    printf("(should be 233)a:%i\n",a);

//  void * :可以指向任何类型的指针类型
//  但如果:
    int hoge = 5;
    void *hoge_p;
    hoge_p = &hoge;
    printf("*hoge_p:%d\n\n\n\n", *(int *)hoge_p);
/**
 *  此处若无(int *),将报错;因为系统不知道hoge_p指向了什么类型的东西,不知道这个类型所占的size,是无法取出hoge_p所指向的值的
 *
    (int *)让系统按照"指向int的指针"来理解hoge_p
 *
 */


/**
 *    对地址直接加减n,编译器会视为前后移动指针n个位置,自动对地址加减使指针指到相应位置上
 */
    int intList[10] = {10,20,30,40,50,60,70,80,90,100};
    printf("intList[1]:%d\n",intList[1]);
    printf("*(&intList[0]+1):%d\n",*(&intList[0]+1));

    return 0;
}























