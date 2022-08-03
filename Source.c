/*
--------------------------------------------

Name: Sara Mohamed Taha Mohamed Abdalla

X-O TASK 1
--------------------------------------------
*/

#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable : 4996)             //disable warnings for scanf

char arr[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };  //initialize XO table with spaces
char ans;                                                       //X-O input


bool input(int row,int column)
{
    if (arr[column - 1][row - 1] == ' ')   // -1 because array starts from 0 not 1
    {
        arr[column - 1][row - 1] = ans;
        return true;                    // x or o added
    }
    else
        return false;                   //if place is full or doesn't exist
}

void Print()
{
    int i;

    for (i = 0; i < 3; i++) 
    {   
        printf(" %c | %c | %c ", arr[i][0], arr[i][1], arr[i][2]);

        if (i != 2) 
        {
            printf("\n---|---|---\n");
        }
    }
    printf("\n\n");
}

char WinMove(char arr[3][3])          //checks all possible winning rows, columns,and diagonals
{
    if ((arr[0][0] == 'x') && (arr[0][1] == 'x') && (arr[0][2] == 'x'))         //row 1
    {
        return 'x';
    }
    else if ((arr[1][0] == 'x') && (arr[1][1] == 'x') && (arr[1][2] == 'x'))    //row 2
    {
        return 'x';
    }
    else if ((arr[2][0] == 'x') && (arr[2][1] == 'x') && (arr[2][2] == 'x'))    //row 3
    {
        return 'x';
    }
    else if ((arr[0][0] == 'x') && (arr[1][0] == 'x') && (arr[2][0] == 'x'))    //column 1
    {
        return 'x';
    }
    else if ((arr[0][1] == 'x') && (arr[1][1] == 'x') && (arr[2][1] == 'x'))    //column 2
    {
        return 'x';
    }
    else if ((arr[0][2] == 'x') && (arr[1][2] == 'x') && (arr[2][2] == 'x'))    //column 3
    {
        return 'x';
    }
    else if ((arr[0][0] == 'o') && (arr[0][1] == 'o') && (arr[0][2] == 'o'))    //row 1
    {
        return 'o';
    }
    else if ((arr[1][0] == 'o') && (arr[1][1] == 'o') && (arr[1][2] == 'o'))    //row 2
    {
        return 'o';
    }
    else if ((arr[2][0] == 'o') && (arr[2][1] == 'o') && (arr[2][2] == 'o'))    //row 3
    {
        return 'o';
    }
    else if ((arr[0][0] == 'o') && (arr[1][0] == 'o') && (arr[2][0] == 'o'))    //column 1
    {
        return 'o';
    }
    else if ((arr[0][1] == 'o') && (arr[1][1] == 'o') && (arr[2][1] == 'o'))    //column 2
    {
        return 'o';
    }
    else if ((arr[0][2] == 'o') && (arr[1][2] == 'o') && (arr[2][2] == 'o'))    //column 3
    {
        return 'o';
    }
    else if ((arr[0][0] == 'x') && (arr[1][1] == 'x') && (arr[2][2] == 'x'))    //diagonal 1
    {
        return 'x';
    }
    else if ((arr[2][0] == 'x') && (arr[1][1] == 'x') && (arr[0][2] == 'x'))    //diagonal 2
    {
        return 'x';
    }
    else if ((arr[0][0] == 'o') && (arr[1][1] == 'o') && (arr[2][2] == 'o'))    //diagonal 1
    {
        return 'o';
    }
    else if ((arr[2][0] == 'o') && (arr[1][1] == 'o') && (arr[0][2] == 'o'))    //diagonal 2
    {
        return 'o';
    }
    else
        return 't';             //if no winning move is found, then it's a tie
}

int main()
{
    do
    {
        printf("Enter x for Player 1 or o for Player 2: ");

        scanf(" %c", &ans);
    } while (ans != 'x' && ans != 'o');

    int column, row;
    ans = 'x';

    printf("   1  2  3 \n 1\n 2\n 3\n");        //coordinates for table

    for (int i = 0; i < 9; i++)
    {
        printf("\n%c turn\nEnter coordinates: ", ans);
        printf("\nThe column: ");
        scanf("%d", &column);
        printf("The row: ");
        scanf("%d", &row);


        if (input(column, row))
        {
            Print();
            if (WinMove(arr) == 'x')
            {
                printf("x WINS!");
                break;
            }
            else if (WinMove(arr) == 'o')
            {
                printf("o WINS!");
                break;
            }
            else if ((WinMove(arr) == 't') && (i == 8))
            {
                printf("Game Over - TIE!\n");
            }

            if (ans == 'x')             //to change turns bet. X & O
                ans = 'o';
            else
                ans = 'x';
        }
        else
        {
            i--;                        //to not count as a turn
            printf("Cell wasn't empty. Try again\n");
        }
    }
    return 0;
}