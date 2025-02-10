/*
Author: Seyi Adu
Program: lab1-rugby-further.c
Input: number of tries, conversions, penalties and drop goals
Output: number of point(s)
*/

#include  <stdio.h>

int valid_input();
int score_calc(int r_try, int conversion, int penalties, int dropgoal);

int main(int argc, char*argv[])
{
       int r_try, conversion, penalties, dropgoal;
       r_try = valid_input();
       conversion = valid_input();
       penalties = valid_input();
       dropgoal = valid_input();

       printf("%d\n", score_calc(r_try, conversion, penalties, dropgoal));

       return 0;
}

int valid_input()
{
    int value;
    do{
        scanf("%d", &value);
    }while(value < 0);
    return value;
}

int score_calc(int r_try, int conversion, int penalties, int dropgoal)
{
    int score;
    score = (r_try * 5) + (conversion * 2) + (penalties * 3) + (dropgoal * 3);

    return score;
}
