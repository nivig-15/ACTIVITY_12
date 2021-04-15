#include<stdio.h>
typedef struct
{
	int n;
	int num[10];
	int den[10];
	int final_num;
	int final_den;
}unit_fraction;

int input_n()
{
	int n;
	printf("Enter number of test cases: ");
	scanf("%d",&n);
	return n;
}

unit_fraction input_fraction()
{
	unit_fraction uf;
	printf("Enter the number of fractions: ");
	scanf("%d",&uf.n);
	printf("Enter denominator of the fraction: ");
	for(int i=0;i<uf.n;i++)
	{
	    
	    scanf("%d",&uf.den[i]);
	    uf.num[i]=1;
	}
	return uf;
}

void input_n_fraction(int n, unit_fraction uf[n])
{
	for(int i=0;i<n;i++)
	{
		uf[i] = input_fraction();
	}
}

int gcd(int a, int b)
{
    while (a != b)
    {
       	if (a > b)
         		a = a-b;
        	else
          		b = b-a; 
    }
   	return a;
}

void compute_fraction(unit_fraction *f)
{
	int final_num=0,final_den=1, g;
	for(int i=0;i<f->n;i++)
	{
		final_den *= f->den[i];
	}
	for(int i=0;i<f->n;i++)
	{
		final_num += (f->num[i]) * (final_den/f->den[i]);
	}
	g = gcd(final_num, final_den);
    	f->final_num = final_num/g;
	f->final_den = final_den/g;
}

void compute_n_fraction(int n, unit_fraction uf[n])
{
	for(int i=0;i<n;i++)
	{
		compute_fraction(&uf[i]);
	}
}

void output_fraction(int n,unit_fraction uf)
{
	printf("\nThe sum of the egyptian fractions is: ");
	for(int i=0;i<uf.n-1;i++)
	{
	    printf("%d/%d + ",uf.num [i],uf.den [i]);
    }
    printf("%d/%d = %d/%d\n",uf.num [uf.n-1],uf.den [uf.n-1],uf.final_num,uf.final_den);
}
void output_n_fraction(int n, unit_fraction uf[n])
{
	for(int i=0;i<n;i++)
	{
		output_fraction(n,uf[i]);
	}
}

int main()
{
	int n;
	n = input_n();
	unit_fraction uf[n];
	input_n_fraction(n,uf);
	compute_n_fraction(n,uf);
	output_n_fraction(n,uf);
	return 0;
}
