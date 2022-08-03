/*
--------------------------------------------

Name: Sara Mohamed Taha Mohamed Abdalla

X-O TASK 1
--------------------------------------------
*/

#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable : 4996)             //disable warnings for scanf

char matrix[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };  //initialize XO table with spaces
char choice;                                                       //X-O input
int column, row;

bool position(int column, int row)
{
    if (matrix[row - 1][column - 1] == ' ')   // -1 because array starts from 0 not 1
    {
        matrix[row - 1][column - 1] = choice;
        return true;                    // x or o added
    }
    else
        return false;                   //if place is full or doesn't exist
}


char WinMove(char matrix[3][3])          //checks all possible winning rows, columns,and diagonals
{
    if ((matrix[0][0] == 'x') && (matrix[0][1] == 'x') && (matrix[0][2] == 'x'))         //row 1
    {
        return 'x';
    }
    else if ((matrix[1][0] == 'x') && (matrix[1][1] == 'x') && (matrix[1][2] == 'x'))    //row 2
    {
        return 'x';
    }
    else if ((matrix[2][0] == 'x') && (matrix[2][1] == 'x') && (matrix[2][2] == 'x'))    //row 3
    {
        return 'x';
    }
    else if ((matrix[0][0] == 'x') && (matrix[1][0] == 'x') && (matrix[2][0] == 'x'))    //column 1
    {
        return 'x';
    }
    else if ((matrix[0][1] == 'x') && (matrix[1][1] == 'x') && (matrix[2][1] == 'x'))    //column 2
    {
        return 'x';
    }
    else if ((matrix[0][2] == 'x') && (matrix[1][2] == 'x') && (matrix[2][2] == 'x'))    //column 3
    {
        return 'x';
    }
    else if ((matrix[0][0] == 'o') && (matrix[0][1] == 'o') && (matrix[0][2] == 'o'))    //row 1
    {
        return 'o';
    }
    else if ((matrix[1][0] == 'o') && (matrix[1][1] == 'o') && (matrix[1][2] == 'o'))    //row 2
    {
        return 'o';
    }
    else if ((matrix[2][0] == 'o') && (matrix[2][1] == 'o') && (matrix[2][2] == 'o'))    //row 3
    {
        return 'o';
    }
    else if ((matrix[0][0] == 'o') && (matrix[1][0] == 'o') && (matrix[2][0] == 'o'))    //column 1
    {
        return 'o';
    }
    else if ((matrix[0][1] == 'o') && (matrix[1][1] == 'o') && (matrix[2][1] == 'o'))    //column 2
    {
        return 'o';
    }
    else if ((matrix[0][2] == 'o') && (matrix[1][2] == 'o') && (matrix[2][2] == 'o'))    //column 3
    {
        return 'o';
    }
    else if ((matrix[0][0] == 'x') && (matrix[1][1] == 'x') && (matrix[2][2] == 'x'))    //diagonal 1
    {
        return 'x';
    }
    else if ((matrix[2][0] == 'x') && (matrix[1][1] == 'x') && (matrix[0][2] == 'x'))    //diagonal 2
    {
        return 'x';
    }
    else if ((matrix[0][0] == 'o') && (matrix[1][1] == 'o') && (matrix[2][2] == 'o'))    //diagonal 1
    {
        return 'o';
    }
    else if ((matrix[2][0] == 'o') && (matrix[1][1] == 'o') && (matrix[0][2] == 'o'))    //diagonal 2
    {
        return 'o';
    }
    else
        return 't';             //if no winning move is found, then it's a tie
}

void display()
{
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c ", matrix[i][0], matrix[i][1], matrix[i][2]);

        if (i != 2)
        {
            printf("\n---|---|---\n");
        }
    }
    printf("\n\n");
}

int main()
{
    do
    {
        printf("Enter x for Player 1 or o for Player 2: ");

        scanf(" %c", &choice);
    } while (choice != 'x' && choice != 'o');

    for (int i = 0; i < 9; i++)
    {
        printf("\n%c turn\nEnter coordinates: ", choice);
        printf("\nThe column: ");
        scanf("%d", &column);
        printf("The row: ");
        scanf("%d", &row);


        if (position(column, row))
        {
            display();
            if (WinMove(matrix) == 'x')
            {
                printf("x WINS!");
                break;
            }
            else if (WinMove(matrix) == 'o')
            {
                printf("o WINS!");
                break;
            }
            else if ((WinMove(matrix) == 't') && (i == 8))
            {
                printf("TIE!\n");
            }

            if (choice == 'x')             //to change turns bet. X & O
                choice = 'o';
            else
                choice = 'x';
        }
        else
        {
            i--;                        //to not count as a turn
            printf("FULL. Try another coordinate\n");
        }
    }
    return 0;
}
