#include <stdio.h>

int main(){
    int p, q;
    int top, bottom, left, right;
    int layer = 0;

    static char a[1000][1000];

    scanf("%d %d", &p, &q);

    top = 0;
    bottom = p - 1;
    left = 0;
    right = q - 1;

    while (top <= bottom && right >= left){
        char value;

        if (layer % 2 == 0)
            value = 'Y';
        else
            value = '0';

        for (int j = left; j <= right; j++)
            a[top][j] = value;

        for (int j = left; j <= right; j++)
            a[bottom][j] = value;

        for (int i = top; i <= bottom; i++)
            a[i][left] = value;

        for (int i = top; i <= bottom; i++)
            a[i][right] = value;

        top++;
        bottom--;
        left++;
        right--;

        layer++;
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            printf("%c", a[i][j]);

            if (j < q - 1)
                printf(" ");
        }

        printf("\n");
    }

    return 0;
}