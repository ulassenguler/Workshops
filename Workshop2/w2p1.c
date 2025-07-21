/*
*****************************************************************************
                          Workshop - #2 (P1)
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double tax = 0.13;          // Tax rate 13%
    const char patSize = 'S', salSize = 'M', tomSize = 'L';  // Shirt sizes
    double price_S, price_M, price_L;
    int quantity;
    int subTotal, total;
    int price_S_cent, tax_cent, subTotal_cent, total_cent;

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter a price for the SMALL shirt: $");
    scanf("%lf", &price_S);

    printf("Enter a price for the MEDIUM shirt: $");
    scanf("%lf", &price_M);

    printf("Enter a price for the LARGE shirt: $");
    scanf("%lf", &price_L);

    printf("\n\nShirt Prices List\n");
    printf("=================\n");
    printf("Small Shirt: $%0.2f\n", price_S);
    printf("Medium Shirt: $%0.2f\n", price_M);
    printf("Large Shirt: $%0.2f\n", price_L);

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &quantity);

    printf("\nPatty's shopping cart...\n");
    printf("Contains: %d shirts\n", quantity);

    // Convert price to cents (integer)
    price_S_cent = (int)(price_S * 100.0 + 0.5);
    // Calculate subtotal in cents
    subTotal_cent = price_S_cent * quantity;
    // Calculate tax in cents
    tax_cent = (int)(subTotal_cent * tax + 0.5);
    // Calculate total (subtotal + tax) in cents
    total_cent = subTotal_cent + tax_cent;

    printf("Sub-total: $%.4lf\n", subTotal_cent / 100.0);
    printf("Taxes    : $%.4lf\n", tax_cent / 100.0);
    printf("Total    : $%.4lf\n", total_cent / 100.0);

	// Wait for user to press Enter
    getchar();
    getchar();

    return 0;
}

