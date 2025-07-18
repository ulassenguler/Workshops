/*
*****************************************************************************
                          Workshop - #2 (P1)

*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	
    const double tax = 0.13;
    const char patSize = 'S';
    double shirt1, shirt2, shirt3;
    int quantity;
    int subTotal,total;
    int shirt1_cent,tax_cent,subTotal_cent,total_cent;
    
    printf("Set Shirt Prices\n");
    printf("================\n");
    
    printf("Enter a price for the SMALL shirt: $");
    scanf("%lf",&shirt1);
    
    printf("Enter a price for the MEDIUM shirt: $");
    scanf("%lf",&shirt2);
    
    printf("Enter a price for the LARGE shirt: $");
    scanf("%lf",&shirt3);

    printf("\n\nShirt Prices List\n");
    printf("=================\n");
    printf("Small Shirt: $%0.2f\n",shirt1);
    printf("Medium Shirt: $%0.2f\n",shirt2);
    printf("Large Shirt: $%0.2f\n",shirt3);
    
    printf("Patty's shirt size is '%c'\n",patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d",&quantity);

    printf("\nPatty's shopping cart...\n");
    printf("Contains: %d shirts\n",quantity);

    //cent cinsinden shirt fiyati
    shirt1_cent = (int)(shirt1 * 100.0 + 0.5);
    //cent cinsinden alt toplam
    subTotal_cent = shirt1_cent * quantity;
    //cent cinsinden vergi
    tax_cent = (int)(subTotal_cent * tax + 0.5);
    //cent cinsinden vergiyle birlikte toplam fiyat
    total_cent = subTotal_cent + tax_cent;     
   
    printf("Sub-total: $%.4lf\n", subTotal_cent / 100.0);
    printf("Taxes    : $ %.4lf\n", tax_cent / 100.0);
    printf("Total    : $%.4lf\n", total_cent / 100.0);
    
    getchar();
    getchar();

    return 0;
}


