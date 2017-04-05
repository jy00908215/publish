 
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
int main()  
{  
    char gps[1024];  
    char k[20];  
    char b[7];  
    int *p;  
    int hh, mm, ss, sum, n,count=0;  
    for (; strcmp(gps, "END");)  
    {  
        scanf("%s", gps);  
  
        if (strstr(gps, "$GPRMC") && strstr(gps, "A"))  
        {  
            sum = gps[1];  
  
            for (int i = 2; gps[i] != '*'; i++)  
            {  
                sum ^= gps[i];  
            }  
            sprintf(k, "%X", sum % 65536);   //将一个整形十进制变量格式化为十六进制，并转换为字符串  
            p = strchr(gps, '*') + 1;        //找到校验值  
            if (strcmp(k, p) == 0)  
            {  
                count++;                     //看看有没有有效的输入  
                p = strchr(gps, ',' )+1;  
                n = atoi(strncpy(k, p, 6));  //将字符型数字转换为int型整数  
                hh = n / 10000 + 8;  
                mm = n % 10000 / 100;  
                ss = n % 100;  
                if (hh >= 24)  
                {  
                    hh=hh-24;  
                }  
            }  
        }  
  
    }  
    if(count) printf("%02d:%02d:%02d", hh, mm, ss);  
  
  
  
    system("pause");  
    return 0;  
}  
