#include <stdio.h>
int check_palindrome(int n);
int main()
{
    int n;
    printf("ENTER A NUMBER: ");
    scanf("%d",&n);
    check_palindrome(n);
    return 0;
}
int check_palindrome(int n) 
{
    int rem, rev=0, temp;
	temp=n;
	while(n!=0)
	{
 	 rem = n % 10;
 	 rev = (rev*10) + rem;
 	 n = n / 10;
	}
 	if(rev==temp)
 	{
 		printf("%d IS A PALINDROME NUMBER\n",temp);
	}
 	else
 	{
  		printf("%d IS NOT A PALINDROME NUMBER\n",temp);
	}
	return 0;
}
