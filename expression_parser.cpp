#include "expression_parser.h"
#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>
double parse_expression(const char * exp)
{

    int len = strlen(exp);
    char **nums;
    nums = new char*;
    int nums_len = -1, num_len = 0;
    bool last_char_is_digit = false;

    char current_character;
//
    for (int i=0; i<len; i++)
    {
        current_character = *(exp+i);

        if(isdigit(current_character) || current_character == '.')
        {
//            printf("a digit\n");
//            printf("%c\n",*(exp+i));
            if(!last_char_is_digit)
            {
                nums_len++;
                num_len = 0;
                nums[nums_len] = new char;
            }
            nums[nums_len][num_len] = current_character;
            num_len++;
            last_char_is_digit = true;
            continue;
        }

        if(nums_len > -1)
        {
            nums[nums_len][num_len] = '\0';
        }

        last_char_is_digit = false;
    }
    printf("nums %s\n",nums[0]);
    printf("nums %s\n",nums[1]);
    printf("%d",strlen(nums[0]));
}
