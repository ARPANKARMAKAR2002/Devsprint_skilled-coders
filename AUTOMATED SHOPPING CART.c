#include <stdlib.h>
 
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
void traversebeg();
void traverseend(int);
void sort();
void search();
void update();
void delete();
void payment();
 
int count = 0;
 
void main()
{
    int ch;
 
    h = NULL;
    temp = temp1 = NULL;
    printf("\n 1 -ITEM MENU LIST");
    printf("\n 2 - Insert at beginning of cart");
    printf("\n 3 - Insert at end of cart");
    printf("\n 4 - Insert at position i of ur cart");
    printf("\n 5 - Delete at i");
    printf("\n 6 - Display from beginning");
    printf("\n 7 - Display from end");
    printf("\n 8 - Search for item in cart from numbering in list");
    printf("\n 9 - Sort the list");
    printf("\n 10 - Update an element");
    printf("\n 11- PAYMENT");
    printf("\n 12 - Exit");
    
    printf("\n ORDER ITEM AT UR CART BY INSERTING THE NUMBER FROM 'ITEM MENU LIST'\n");
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        	menu();
        	break;
        case 2:
        	printf("enter 1 to 20");
            insert1();
            break;
        case 3:
        	printf("enter 1 to 20");
            insert2();
            break;
        case 4:
        	printf("enter 1 to 20");
            insert3();
            break;
        case 5:
            delete();
            break;
        case 6:
            traversebeg();
            break;
        case 7:
            temp2 = h;
            if (temp2 == NULL)
                printf("\n Error : List empty to display ");
            else
            {
                printf("\n Reverse order of cart list is : ");
                traverseend(temp2->n);
            }
            break;
        case 8:
            search();
            break;
        case 9:
            sort();
            break;
        case 10:
            update();
            break;
        /*case 11:
        	payment();
        	break;*/
        case 12:
            exit(0);
        default:
            printf("\n Wrong choice menu");
        }
    }
}
 
/* TO create an empty node */
int create()
{
    int data;
 
    temp =(struct cart*)malloc(1*sizeof(struct cart));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter value to cart : ");
    scanf("%d", &data);
    temp->n = data;
     if(data<0 || data>20)
        {
        	printf("NOT IN MENU LIST\n");
        	temp=NULL;
        }
     else
	 {
	 	count++;
	 }    
}
//Menu
void menu()
{
  printf("VEGETABLES:-\n");
  printf("1.Cabbage\n");
  printf("2.Cauliflower\n");
  printf("3.Spinach\n");
  printf("4.Brocolli\n");
  printf("--------------------------------------------------------\n");
  printf("MEAT:-\n");
  printf("5.Prawn\n");
  printf("6.Chicken\n");
  printf("7.Mutton\n");
  printf("8.Pork\n");
  printf("9.Squid\n");
  printf("10.Duck\n");
  printf("----------------------------------------------------------\n");
  printf("RICE:-\n");
  printf("11.Basmati rice\n");
  printf("12.Jeera rice\n");
  printf("13.sticky rice\n");
  printf("----------------------------------------------------------\n");
  printf("PULSES:-\n");
  printf("14.Mong dal\n");
  printf("15.Masoor dal\n");
  printf("16.Urad Dal\n");
  printf("17.Chana Dal\n");
  printf("----------------------------------------------------------\n");
  printf("WHEAT:-\n");
  printf("18.VL-832\n");
  printf("19.HS-240\n");
  printf("20.HS-365\n");
  printf("----------------------------------------------------------\n");
}
 
/*  TO insert at beginning */
void insert1()
{
    if (h == NULL)
    {
        create();
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
 
/* To insert at end */
void insert2()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}
 
/* To insert at any position */
void insert3()
{
    int pos, i = 2;
 
    printf("\n Enter position to be inserted : ");
    scanf("%d", &pos);
    temp2 = h;
 
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Position out of range to insert");
        return;
    }
    if ((h == NULL) && (pos != 1))
    {
        printf("\n Empty cart list cannot insert other than 1st position");
        return;
    }
    if ((h == NULL) && (pos == 1))
    {
        create();
        h = temp;
        temp1 = h;
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        create();
        temp->prev = temp2;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        temp2->next = temp;
    }
}
 
/* To delete an element */
void delete()
{
    int i = 1, pos;
 
    printf("\n Enter position to be deleted : ");
    scanf("%d", &pos);
    temp2 = h;
 
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Error : Position out of range to delete");
        return;
    }
    if (h == NULL)
    {
        printf("\n Error : Empty cart list no elements to delete");
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        if (i == 1)
        {
            if (temp2->next == NULL)
            {
                printf("item deleted from list");
                free(temp2);
                temp2 = h = NULL;
                return;
            }
        }
        if (temp2->next == NULL)
        {
            temp2->prev->next = NULL;
            free(temp2);
            printf("item deleted from list");
            return;
        }
        temp2->next->prev = temp2->prev;
        if (i != 1)
            temp2->prev->next = temp2->next;    /* Might not need this statement if i == 1 check */
        if (i == 1)
            h = temp2->next;
        printf("\n deleted");
        free(temp2);
    }
    count--;
}
 
/* Traverse from beginning */
void traversebeg()
{
    temp2 = h;
 
    if (temp2 == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf("\n list elements from begining : ");
 
    while (temp2->next != NULL)
    {
        printf(" %d ", temp2->n);
        temp2 = temp2->next;
    }
    printf(" %d ", temp2->n);
}
 
/* To traverse from end recursively */
void traverseend(int i)
{
    if (temp2 != NULL)
    {
        i = temp2->n;
        temp2 = temp2->next;
        traverseend(i);
        printf(" %d ", i);
    }
}
 
/* To search for an element in the list */
void search()
{
    int data, count = 0;
    temp2 = h;
 
    if (temp2 == NULL)
    {
        printf("\n Error : List empty to search for data");
        return;
    }
    printf("\n Enter value to search : ");
    scanf("%d", &data);
    while (temp2 != NULL)
    {
        if (temp2->n == data)
        {
            printf("\n Data found in %d position",count + 1);
            return;
        }
        else
             temp2 = temp2->next;
            count++;
    }
    printf("\n Error : %d not found in list", data);
}
 
/* To update a node value in the list */
void update()
{
    int data, data1;
 
    printf("\n Enter cart data to be updated : ");
    scanf("%d", &data);
    printf("\n Enter new data : ");
    scanf("%d", &data1);
    temp2 = h;
    if (temp2 == NULL)
    {
        printf("\n Error : List empty no node to update");
        return;
    }
    while (temp2 != NULL)
    {
        if (temp2->n == data)
        {
 
            temp2->n = data1;
            traversebeg();
            return;
        }
        else
            temp2 = temp2->next;
    }
 
    printf("\n Error : %d not found in list to update", data);
}
 
/* To sort the linked list */
void sort()
{
    int i, j, x;
 
    temp2 = h;
    temp4 = h;
 
    if (temp2 == NULL)
    {
        printf("\n List empty to sort");
        return;
    }
 
    for (temp2 = h; temp2 != NULL; temp2 = temp2->next)
    {
        for (temp4 = temp2->next; temp4 != NULL; temp4 = temp4->next)
        {
            if (temp2->n > temp4->n)
            {
                x = temp2->n;
                temp2->n = temp4->n;
                temp4->n = x;
            }
        }
    }
    traversebeg();
}
void calculate()
{
	int price=0;
	for(temp=head; temp->next!=NULL; temp=temp->next)
	{
		price=price+temp->discounted_price;
	}
	if(price<2000)
	{
		price=price-(0.05*price);
	}
	else if(price>=2000 && price<4000)
	{
		price=price-(0.1*price);
	}
	else if(price>=4000 && price<10000)
	{
		price=price-(0.2*price);
	}
	else
	{
		price=price-(0.3*price);
	}
	
	printf("PAYABLE AMOUNT is: RS %d",price);
}

