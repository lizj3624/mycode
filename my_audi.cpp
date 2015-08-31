// $_FILEHEADER_BEGIN ****************************
// FileName£ºmy_audi.c
// Date£º    2015Äê08ÔÂ26ÈÕ
// Author£º  LiZunju
// Remains£º audi
// $_FILEHEADER_END ******************************
#include "my_audi.h"
#include <iostream> 

audi::audi()
{
    std::cout << "audi" << std::endl;
}

audi::~audi()
{
    std::cout << "audi detel" << std::endl;
}

void audi::run()
{
    std::cout << "audi run" << std::endl;
}

void audi::didi()
{
    std::cout << "audi didi" << std::endl;
}

void audi::stop()
{
    std::cout << "audi stop" << std::endl;
}

void audi::stop(std::string & str)
{
    std::cout << "audi stop " << str << std::endl;
}
