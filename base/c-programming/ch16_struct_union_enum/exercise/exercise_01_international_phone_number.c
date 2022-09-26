/*
 * @author Anger
 * @date 2022/9/26
 * @brief 输入国际电话区号，然后在数组 country_code 中查找到对应的数据
 * 程序显示国家名称
 * 否则显示错误消息
 */
#include <stdio.h>

#define SIZE(a) (int) (sizeof(a) / sizeof(a[0]))

struct dialing_code {
    char *country;
    int area_code;
};

const struct dialing_code country_codes[] =
        {{"Argentina",            54},	{"Bangladesh",     	        880},
         {"Brazil",               55},	{"Burma (Myanmar)",	        95},
         {"China",                86},	{"Colombia",        	    57},
         {"Congo, Dem. Rep. of", 243},	{"Egypt",         	        20},
         {"Ethiopia",            251},	{"France",         	        33},
         {"Germany",              49},	{"India ",           	    91},
         {"Indonesia",            62},	{"Iran",     	            98},
         {"Italy",                39},	{"Japan",          	        81},
         {"Mexico",               52},	{"Nigeria",        	        234},
         {"Pakistan",             92},	{"Philippines",    	        63},
         {"Poland",               48},	{"Russia",          	    7},
         {"South Africa",         27},	{"Korea",     	            82},
         {"Spain",                34},	{"Sudan",     	            249},
         {"Thailand",             66},	{"Turkey",       	        90},
         {"Ukraine",             380},	{"United Kingdom",   	    44},
         {"United States",         1},	{"Vietnam",        	        84}};

int main(void) {

    int area_code, index = -1;

    printf("Enter area code : ");

    scanf("%d", &area_code);

    for (int i = 0; i < SIZE(country_codes); ++i) {
        if (country_codes[i].area_code == area_code){
            index = i;
            break;
        }
    }

    if (index != -1)
        printf("Country name => %s\n", country_codes[index].country);
    else
        printf("Out of the space.\n");

    return 0;
}