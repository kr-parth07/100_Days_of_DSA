/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32
*/

#include<stdio.h>
int power(int x, int y){
    if(y==0){
        return 1;
    }
    return x * power(x, y-1);
}
int main(){
    int x, y;
    scanf("%d %d", &x, &y);

    printf("%d", power(x,y));
    return 0;

}
