#include<stdio.h>
#include<math.h>

int main()
{
	int n, n1, n2, i, temp, len = 0, sum = 0;
	
	printf("Enter the number:");
	scanf("%d", &n);
	
	n1 = n;
	n2 = n;
	
	while (n1 > 0)
	{
		n1 = n1 / 10;
		len++;
	}
	
	while (n2 > 0)
	{
		temp = n2 % 10;
		sum += pow(temp, len);
		n2 = n2 / 10;
	}
	
	if (sum == n) printf("Entered number %d is Armstrong number.", n);
	else printf("Entered number is not %d is not Armstrong number.", n);
	return 0;
}
