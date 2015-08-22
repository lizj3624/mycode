#include <iostream>
using namespace std;
int main()
{
    int a[4][4] = {  1,  2,  3,  4,
                     5,  6,  7,  8,
                     9, 10, 11, 12,
                    13, 14, 15, 16  };
    //i和j是最小维度
    int i=0;   
    //int j=0;
     
 
    //p和q是最大维度(四维数组最多取到a[3][3])
    int p=3;
    int q=3;
     
    int m,n;
     
    while(p > 0 || q > -1)
    {
        for(m = i, n = p; n <= q ; m++, n++)
        {
            cout << a[m][n] << " ";
        }
        if(p > 0)
        {
            p--;
        }
        else
        {
            q--;
            i++;
        }
    }
    cout << endl;

    return 0;
} 
 
 
//运行结果是：
//4 3 8 2 7 12 1 6 11 16 5 10 15 9 14 13
//你应该是要的这个结果吧？
//其他像5维数组、6维数组也是可以的，只用把p和q值改成维度-1就可以了
