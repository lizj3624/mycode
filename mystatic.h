// $_FILEHEADER_BEGIN ****************************
// 北京八度互联科技有限公司版权所有
// Copyright (C) Badu Corporation.  All Rights Reserved
// 文件名称：mystatic.cpp
// 创建日期：2015年08月21日
// 创建人：  LiZunju
// 文件说明：static
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
