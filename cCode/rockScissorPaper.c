#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand((unsigned int)time(NULL)); // 使用时间函数设置随机数种子，创造伪随机数
    int counterCpt = 0, counterUser = 0, counterTie = 0, counterTurn = 0;
    int user;
    char opt;
    do
    {
        printf("Score: Computer %d : %d User, Tie %d\n", counterCpt, counterUser, counterTie);
        printf("==================Round %d=================\n", ++counterTurn);
        int cpt = rand() % 3 + 1; // 取模
        do
        {
            printf("Please enter your option:\n1.rock\n2.scissors\n3.paper\n");
            scanf("%d", &user);
            if (user < 1 || user > 3)
                printf("Invalid input,try again!\n(Enter 1,2 or 3)\n");
        } while (user < 1 || user > 3); // 输入验证
        printf("Computer's option is:%d\n", cpt);
        printf("Your option is:%d\n", user); // 这里的选择可以显示的更明确，将数字与选项名称绑定，苦于超纲
        if (cpt == user)
        {
            printf("Sorry,it is a tie!\n");
            counterTie++;
        }
        else if ((cpt == 1 && user == 2) || (cpt == 2 && user == 3) || (cpt == 3 && user == 1))
        {
            printf("Computer:\"Pity! you are loser!\"\n");
            counterCpt++;
        }
        else
        {
            printf("Man! you win!\n");
            counterUser++;
        }
        do
        {
            printf("Do you want to play again?(Y/N)\n");
            scanf(" %c", &opt);
            if (opt != 'Y' && opt != 'N' && opt != 'y' && opt != 'n')
                printf("invalid input!\nWhat are you doing?\nPlease try again!\n");
        } while (opt != 'Y' && opt != 'N' && opt != 'y' && opt != 'n'); // 输入验证
    } while (opt == 'Y' || opt == 'y');
    printf("Thank you for playing!\n");
    printf("The final score is:\nComputer %d : %d User, Tie %d\n", counterCpt, counterUser, counterTie);
    if (counterCpt == counterUser)
        printf("It is a tie!\n");
    else if (counterCpt > counterUser)
        printf("Sorry,but computer wins!\n");
    else
        printf("Congratulations! You win!\n");
    return 0;
}