// $_FILEHEADER_BEGIN ****************************
// FileName£ºmy_car.c
// Date£º    2015Äê08ÔÂ26ÈÕ
// Author£º  LiZunju
// Remains£º car
// $_FILEHEADER_END ******************************
//
#include "my_car.h"

cat::cat()
{
    std::cout << "cat" << std::endl;
}

cat::~cat()
{
    std::cout << "cat delete" << std::endl;
}

void cat::run()
{
    std::cout << "cat run" << std::endl;
}

void cat::stop()
{
    std::cout << "cat stop" << std::endl;
}
