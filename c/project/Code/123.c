 
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
            sprintf(k, "%X", sum % 65536);   //��һ������ʮ���Ʊ�����ʽ��Ϊʮ�����ƣ���ת��Ϊ�ַ���  
            p = strchr(gps, '*') + 1;        //�ҵ�У��ֵ  
            if (strcmp(k, p) == 0)  
            {  
                count++;                     //������û����Ч������  
                p = strchr(gps, ',' )+1;  
                n = atoi(strncpy(k, p, 6));  //���ַ�������ת��Ϊint������  
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
