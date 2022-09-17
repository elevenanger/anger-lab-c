/*
 * @author Anger
 * @date 2022/9/17
 * @brief 将数组转换成英文单词
 */
#include <stdio.h>

int main(void){
    int number;
    int one_digit,two_digit;

    char *number_words[] = {"...", "one", "two", "three", "four", "five",
                            "six", "seven", "eight", "nine", "ten",
                            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                            "Sixteen", "Seventeen", "Nineteen"};

    char *number_words_over_nineteen[] = {"Twenty-", "Thirty-", "Forty-", "Fifty-",
                                          "Sixty-", "Seventy-", "Eighty-", "Ninety-"};

    printf("Enter a two-digit number: ");
    scanf("%d", &number);
    printf("You entered the number ");

    if (number > 0 && number < 20)
        puts(number_words[number]);
    else {
        two_digit = number / 10;
        one_digit = number % 10;
        printf("%s%s", number_words_over_nineteen[two_digit - 2], number_words[one_digit]);
    }

    return 0;
}
