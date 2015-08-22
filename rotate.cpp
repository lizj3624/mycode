//�����ַ���������ת���������ַ���ǰ������ɸ��ַ��ƶ����ַ�����β����
//����ַ���abcdef����ת2λ�õ��ַ���cdefab��
//��ʵ���ַ�������ת�ĺ�����Ҫ��Գ���Ϊn���ַ���������ʱ�临�Ӷ�ΪO(n)��
//�ռ临�Ӷ�ΪO(1)�� 

//ok���������úó����ܽ�һ�´�˼·��������4�㣬����ϸ�Ķ�����
//1��������p1=ch[0]��p2=ch[m]������p1��p2���m�ľ��룻
//2���ж�p2+m-1�Ƿ�Խ�磬���û��Խ��ת��3������ת��4��abcdefgh��8����ĸ���ַ�����
//��4��������ô��ʼʱp2ָ��e��p2+4Խ���ˣ�����ʵ��p2��p2+m-1��m���ַ�����������һ����������
//3�����Ͻ���*p1��*p2��Ȼ��p1++��p2++��ѭ��m�Σ�Ȼ��ת��2��
//4����ʱp2+m-1 �Ѿ�Խ�磬�ڴ�ֻ�账��β�͡��������£�
//   4.1 ͨ��n-p2�õ�p2��β��֮��Ԫ�ظ���r��������Ҫǰ�Ƶ�Ԫ�ظ�����
//   4.2 ���¹���ִ��r�Σ�
//       ch[p2]<->ch[p2-1]��ch[p2-1]<->ch[p2-2]��....��ch[p1+1]<->ch[p1]��p1++��p2++��


#include <iostream>    
#include <string>    
using namespace std;    
      
void rotate(string &str, int m)    
{    
    if (str.length() == 0 || m < 0)    
         return;    
     
     //��ʼ��p1��p2    
     int p1 = 0, p2 = m;       
     int n = str.length();    
     
     // ����m����n    
     if (m % n == 0)    
         return;    
         
     // ѭ��ֱ��p2�����ַ���ĩβ    
     while(true)    
     {      
         swap(str[p1], str[p2]);    
         p1++;    
         if (p2 < n - 1)    
             p2++;    
         else    
             break;    
     }    
         
     // ����β����rΪβ��ѭ�����ƴ���    
     int r = m - n % m;  // r = 1.    
     while (r--)  //��ѭ��ִ��һ��    
     {    
         int i = p1;    
         char temp = str[p1];    
         while (i < p2)  //��ѭ��ִ������    
         {    
             str[i] = str[i+1];    
             i++;    
         }       
         str[p2] = temp;    
     }    
     //��һ������    
     //abcdefghijk    
     //��ִ�е������ʱ��defghiabcjk    
     //      p1    p2    
     //defghi a b c j k��a �� j������jbcak��Ȼ��p1++��p2++    
     //        p1    p2    
     //       j b c a k��b �� k������jkcab��Ȼ��p1++��p2������    
         
     //r = m - n % m= 3-11%3=1����ѭ����λ1�Ρ�    
     //          p1  p2    
     //       j k c a b    
     //p1��ָԪ��cʵ�ֱ�����temp�    
     //Ȼ��ִ�д�����䣺str[i] = str[i+1]; ��a�ܵ�c��λ�ô���a_b    
     //i++���ٴ�ִ�У�str[i] = str[i+1]��ab_    
     //��󣬱���õ�c ���룬Ϊabc�����ԣ���������Ϊdefghi jk abc��        
 }    
     
 int main()    
 {    
     string ch="abcdefghijk";    
     cout<<ch<<endl;    
     rotate(ch,3);    
     cout<<ch<<endl;    
     return 0;       
 }  

