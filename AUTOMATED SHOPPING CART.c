#include <stdio.h>
#include <stdlib.h>

typedef struct cart{
	int product_code;
	int product_price;
	int product_discount;
	int discounted_price;
	int quantity;
	struct cart *next;
	
}x;

x *start;

void input();
void remove_from_cart();
void display_bill();
void payment();
int calculate();

int main()
{
	start=NULL;
	int stopping_case=1;
	while (stopping_case=1)
	{
		int ch;
		printf("Enter 1 for adding an item 2 for displaying bill 3 for deleting or reducing quantity of an item 4 for payment details.\n");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				input();
				break;
			case 2:
				display_bill();
				break;
			case 3:
				remove_from_cart();
				break;
			case 4:
				payment();
				break;
		}
	}
}

void input()
{
	x *new_node=(x*)malloc(sizeof(x));
	printf("Enter the product code:\n");
	scanf("%d",&new_node->product_code);
	if(start==NULL)
	{
		start=new_node;
		new_node->next=NULL;			
	}
	else
	{
		x *temp=NULL;
		for(temp=start; temp->next!=NULL; temp=temp->next);
		temp->next=new_node;
		new_node->next=NULL;
	}
}

void remove_from_cart()
{
	if(start==NULL)
	{
		printf("your cart is empty plz continue with shopping\n");
	}
	else
	{
		int ch,c;
		printf("Enter the product code to reduce the quantity of the product or completely remove it from the card");
		scanf("%d",&ch);
		printf("Enter choice 1 to reduce quantity 2 to completely remove the product");
		scanf("%d",&c);
		x *temp=NULL;
		x *temp1=NULL;
		temp=start;
		while(temp->next!=NULL)
		{
			temp1=temp;
			if(temp->product_code==ch)
			{
				if(c==1&&temp->quantity>1)
				{
					int t;
					printf("Enter the amount of to be reduced ");
					scanf("%d",&t);
					if(t<temp->quantity)
						temp->quantity=temp->quantity-t;
					else
					{
						temp1->next=temp->next;
						free(temp);
					}
				}
				else
				{
					temp1->next=temp->next;
					free(temp);
				}
				break;
			}
			temp=temp->next;
		}
	}
}

void diplay_bill()
{
	x *temp=NULL;
	printf("product code\t\tquantity\t\tproduct price per unit\t\tproduct discount\n");
	for(temp=start;temp->next!=NULL;temp=temp->next)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\n",temp->product_code,temp->quantity,temp->product_price,temp->product_discount);
	}
	int p=calculate();
	printf("TOTAL:\t\t\t\t\t\t%d",p);
	
}

int calculate()
{
	int price=0;
	x *temp=NULL;
	for(temp=start; temp->next!=NULL; temp=temp->next)
		price=price+temp->discounted_price;
	return price;
}

void payment()
{
	
}
