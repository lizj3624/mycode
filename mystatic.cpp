// $_FILEHEADER_BEGIN ****************************
// 文件名称：mystatic.cpp
// 创建日期：2015年08月21日
// 创建人：  LiZunju
// 文件说明：static.cpp
// $_FILEHEADER_END ******************************
#include "mystatic.h"

int myclass::my_i2 = 1;

int my_i_3 = 33;

static int my_i_4 = 44;

myclass::myclass()
{
    my_i = 1;
}

myclass::~myclass()
{

}

void myclass::my_fun1()
{
    std::cout << "fun1"<< std::endl;
    std::cout << "fun1 i3 = "<< my_i_3 << std::endl;
    std::cout << "fun1 i4 = "<< my_i_4 << std::endl;
}

void myclass::my_fun2()
{
    static int fun2_i = 53;
    std::cout << "fun2" << std::endl;
    std::cout << "fun2 i3 = "<< my_i_3 << std::endl;
    std::cout << "fun2 i4 = "<< my_i_4 << std::endl;
    std::cout << "fun2_i = "<< fun2_i << std::endl;
}

void my_fun3()
{
    std::cout << "fun3" << std::endl; 
    std::cout << "fun3 i3 = "<< my_i_3 << std::endl;
    std::cout << "fun3 i4 = "<< my_i_4 << std::endl;
    my_fun4();
}

static void my_fun4()
{
    std::cout << "fun4" << std::endl; 
    std::cout << "fun4 i3 = "<< my_i_3 << std::endl;
    std::cout << "fun4 i4 = "<< my_i_4 << std::endl;
}

