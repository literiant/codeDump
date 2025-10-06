#include <stdio.h>
void clBuf()
{
    while (getchar() != '\n')
        ;
} /* cleanBuffer原理:读入字符直到遇到换行符.先取一个字符，满足则循环，直至取出/n后退出循环.
     cleanBuffer可以清除所有输入缓冲区的内容,避免后续输入受到干扰,但这里只用清除一个\n,所以把clBuf改为getchar也可以.
     %c前加空格可以忽略前面的空白字符(包括换行符),避免上次输入的换行符被当作本次输入.
     如果不例行清除或者跳过残留字符，后续scanf会读取残留的\n,而\n的ASCII码不在if的条件范围内(现在多加了不在a-zA-Z范围内的判断),
     则opc不会被赋值，打印opc时会保留上次所赋的值作为结果
     如果是被repo的scanf读取，会直接判断不符条件而进入循环，阴差阳错把\n消耗掉，但会略显奇怪*/
int main()
{
    printf("Welcome to the letter case converter!\n");
    char repo;
    do
    {
        printf("Please enter a letter:\n");
        char ipc, opc; // 输入,输出
        scanf("%c", &ipc);
        clBuf(); // 例行清空
        // ASCII:大写字母比小写字母少32
        if (ipc >= 'a' && ipc <= 'z')
        {
            opc = ipc - 32;
            printf("'%c''s upper case is '%c'\n", ipc, opc);
        }
        else if (ipc >= 'A' && ipc <= 'Z')
        {
            opc = ipc + 32;
            printf("'%c''s lower case is '%c'\n", ipc, opc);
        }
        else
            printf("Error! %c is not a letter.\n", ipc);
        do
        {
            printf("Do you want to continue? (y/n)\n");
            scanf("%c", &repo);
            clBuf(); // 例行清空

            if (repo != 'n' && repo != 'N' && repo != 'y' && repo != 'Y')
                printf("Error! Please enter 'y' or 'n'.\n");

        } while (repo != 'n' && repo != 'N' && repo != 'y' && repo != 'Y');
    } while (repo == 'y' || repo == 'Y');
    return 0;
}
