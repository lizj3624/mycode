// $_FILEHEADER_BEGIN ****************************
// �����˶Ȼ����Ƽ����޹�˾��Ȩ����
// Copyright (C) Badu Corporation.  All Rights Reserved
// �ļ����ƣ�mystatic.cpp
// �������ڣ�2015��08��21��
// �����ˣ�  LiZunju
// �ļ�˵����static
// $_FILEHEADER_END ******************************

#include <iostream>
#include <string>

class myclass
{
public:
    myclass();
    ~myclass();

    void my_fun1();
    static void my_fun2();

//private:
    int my_i;
    static int my_i2;
};

void my_fun3();

static void my_fun4();
