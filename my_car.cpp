// $_FILEHEADER_BEGIN ****************************
// FileName��my_car.c
// Date��    2015��08��26��
// Author��  LiZunju
// Remains�� car
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
