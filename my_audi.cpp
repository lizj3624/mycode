// $_FILEHEADER_BEGIN ****************************
// FileName��my_audi.c
// Date��    2015��08��26��
// Author��  LiZunju
// Remains�� audi
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
