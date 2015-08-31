// $_FILEHEADER_BEGIN ****************************
// FileName£ºmy_cat_main.cpp
// Date£º    2015Äê08ÔÂ26ÈÕ
// Author£º  LiZunju
// Remains£º catmain
// $_FILEHEADER_END ******************************

#include <iostream>
#include "my_car.h"
#include "my_audi.h"

int main()
{
    cat *p = new audi();

    p->run();
    p->stop();

    delete p;

    audi my_audi;
    my_audi.run();
    my_audi.didi();
    my_audi.stop();

    //typedef void (audi::*ptr_commomfun)();
    //ptr_commomfun p1 = audi::run;
    std::string my_str("my_audi");
    my_audi.stop(my_str);

    return 0;
}
