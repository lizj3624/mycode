// $_FILEHEADER_BEGIN ****************************
// FileName��my_audi.cpp
// Date��    2015��08��26��
// Author��  LiZunju
// Remains�� audi
// $_FILEHEADER_END ******************************

#ifndef _MY_AUDI_H_
#define _MY_AUDI_H_

#include "my_car.h"

class audi: public cat{
public:
    audi();
    virtual ~audi();

    virtual void run();
    
    void didi();

    void stop();

    void stop(std::string & str);
};

#endif
