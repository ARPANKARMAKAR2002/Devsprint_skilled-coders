#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>
struct cart
{
    struct cart *prev;
    int n;
    struct cart *next;
}*h,*temp,*temp1,*temp2,*temp4;
void menu(); 
void insert1();
void insert2();
void insert3();
main()
{
	
	printf("1.Create cart");
	 printf("\n 1 -ITEM MENU LIST")
    printf("\n 2 - Insert at beginning of cart");
    printf("\n 3 - Insert at end of cart");
    printf("\n 4 - Insert at position i of ur cart");
    printf("\n 5 - Delete at i");
	
	
	
}
abcd()
{
	
    temp =(struct cart*)malloc(1*sizeof(struct cart));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter value to cart : ");
    scanf("%d", &data);
    temp->n = data;
    count++;
}

void insert1()
{
    if (h == NULL)
    {
        create();
        if(data<0 || data>12)
        {
        	printf("")
		}
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}
void calculate()
{
	int price=0;
	for(temp=head; temp->next!=NULL; temp=temp->next)
	{
		price=price+temp->discounted_price;
	}
	printf("PAYABLE AMOUNT is: RS %d",price);
}

