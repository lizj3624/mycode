// $_FILEHEADER_BEGIN ****************************
// FileName��my_car.cpp
// Date��    2015��08��26��
// Author��  LiZunju
// Remains�� car
// $_FILEHEADER_END ******************************

#ifndef _MY_CAT_H_
#define _MY_CAT_H_
#include <iostream>

class cat {
public:
    cat();
    virtual ~cat();
    
    virtual void run();

    void stop();
};

#endif
