//定义字符串的左旋转操作：把字符串前面的若干个字符移动到字符串的尾部，
//如把字符串abcdef左旋转2位得到字符串cdefab。
//请实现字符串左旋转的函数，要求对长度为n的字符串操作的时间复杂度为O(n)，
//空间复杂度为O(1)。 

//ok，咱们来好好彻底总结一下此思路二：（就4点，请仔细阅读）：
//1、首先让p1=ch[0]，p2=ch[m]，即让p1，p2相隔m的距离；
//2、判断p2+m-1是否越界，如果没有越界转到3，否则转到4（abcdefgh这8个字母的字符串，
//以4左旋，那么初始时p2指向e，p2+4越界了，但事实上p2至p2+m-1是m个字符，可以再做一个交换）。
//3、不断交换*p1与*p2，然后p1++，p2++，循环m次，然后转到2。
//4、此时p2+m-1 已经越界，在此只需处理尾巴。过程如下：
//   4.1 通过n-p2得到p2与尾部之间元素个数r，即我们要前移的元素个数。
//   4.2 以下过程执行r次：
//       ch[p2]<->ch[p2-1]，ch[p2-1]<->ch[p2-2]，....，ch[p1+1]<->ch[p1]；p1++；p2++；


#include <iostream>    
#include <string>    
using namespace std;    
      
void rotate(string &str, int m)    
{    
    if (str.length() == 0 || m < 0)    
         return;    
     
     //初始化p1，p2    
     int p1 = 0, p2 = m;       
     int n = str.length();    
     
     // 处理m大于n    
     if (m % n == 0)    
         return;    
         
     // 循环直至p2到达字符串末尾    
     while(true)    
     {      
         swap(str[p1], str[p2]);    
         p1++;    
         if (p2 < n - 1)    
             p2++;    
         else    
             break;    
     }    
         
     // 处理尾部，r为尾部循环左移次数    
     int r = m - n % m;  // r = 1.    
     while (r--)  //外循环执行一次    
     {    
         int i = p1;    
         char temp = str[p1];    
         while (i < p2)  //内循环执行俩次    
         {    
             str[i] = str[i+1];    
             i++;    
         }       
         str[p2] = temp;    
     }    
     //举一个例子    
     //abcdefghijk    
     //当执行到这里的时候，defghiabcjk    
     //      p1    p2    
     //defghi a b c j k，a 与 j交换，jbcak，然后，p1++，p2++    
     //        p1    p2    
     //       j b c a k，b 与 k交换，jkcab，然后，p1++，p2不动，    
         
     //r = m - n % m= 3-11%3=1，即循环移位1次。    
     //          p1  p2    
     //       j k c a b    
     //p1所指元素c实现保存在temp里，    
     //然后执行此条语句：str[i] = str[i+1]; 即a跑到c的位置处，a_b    
     //i++，再次执行：str[i] = str[i+1]，ab_    
     //最后，保存好的c 填入，为abc，所以，最终序列为defghi jk abc。        
 }    
     
 int main()    
 {    
     string ch="abcdefghijk";    
     cout<<ch<<endl;    
     rotate(ch,3);    
     cout<<ch<<endl;    
     return 0;       
 }  

