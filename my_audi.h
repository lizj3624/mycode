// $_FILEHEADER_BEGIN ****************************
// FileName£ºmy_audi.cpp
// Date£º    2015Äê08ÔÂ26ÈÕ
// Author£º  LiZunju
// Remains£º audi
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
