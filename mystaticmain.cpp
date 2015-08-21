// $_FILEHEADER_BEGIN ****************************
// 文件名称：mystaticmain.cpp
// 创建日期：2015年08月21日
// 创建人：  LiZunju
// 文件说明：main
// $_FILEHEADER_END ******************************

#include "mystatic.h"
#include <iostream> 

using namespace std;

extern int my_i_3;
int my_i_4 = 55;

static void my_fun4()
{
    cout << "main fun4" << endl;
}

int main()
{
    myclass my_class;
    my_class.my_fun1(); 
    my_class.my_fun2(); 
    myclass::my_fun2();

    cout << "main i3 = " << my_i_3 << endl;
    cout << "main i4 = " << my_i_4 << endl;
    cout << "my_i2 = " << myclass::my_i2 << endl;
    cout << "my_i2 = " << my_class.my_i2 << endl;

    my_fun3();
    my_fun4();

    return 0;
}

