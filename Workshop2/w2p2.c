/*
*****************************************************************************
                          Workshop - #2 (P2)
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    const double tax = 0.13;  // Tax rate 13%
    const char patSize = 'S', salSize = 'M', tomSize = 'L'; // Shirt sizes

    double price_S, price_M, price_L;
    int qty_patty, qty_sally, qty_tommy;

    int price_S_cent, price_M_cent, price_L_cent;

    int sub_patty_cent, tax_patty_cent, total_patty_cent;
    int sub_sally_cent, tax_sally_cent, total_sally_cent;
    int sub_tommy_cent, tax_tommy_cent, total_tommy_cent;
    int total_sub_cent, total_tax_cent, total_all_cent;

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter a price for the SMALL shirt: $");
    scanf("%lf", &price_S);
    printf("Enter a price for the MEDIUM shirt: $");
    scanf("%lf", &price_M);
    printf("Enter a price for the LARGE shirt: $");
    scanf("%lf", &price_L);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", price_S);
    printf("MEDIUM : $%.2lf\n", price_M);
    printf("LARGE  : $%.2lf\n", price_L);

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &qty_patty);
    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &qty_tommy);
    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &qty_sally);

    // Convert prices to cents (int)
    price_S_cent = (int)(price_S * 100.0 + 0.5);
    price_M_cent = (int)(price_M * 100.0 + 0.5);
    price_L_cent = (int)(price_L * 100.0 + 0.5);

    // Calculate subtotal, tax, total for Patty
    sub_patty_cent = price_S_cent * qty_patty;
    tax_patty_cent = (int)(sub_patty_cent * tax + 0.5);
    total_patty_cent = sub_patty_cent + tax_patty_cent;

    // Calculate subtotal, tax, total for Sally
    sub_sally_cent = price_M_cent * qty_sally;
    tax_sally_cent = (int)(sub_sally_cent * tax + 0.5);
    total_sally_cent = sub_sally_cent + tax_sally_cent;

    // Calculate subtotal, tax, total for Tommy
    sub_tommy_cent = price_L_cent * qty_tommy;
    tax_tommy_cent = (int)(sub_tommy_cent * tax + 0.5);
    total_tommy_cent = sub_tommy_cent + tax_tommy_cent;

    // Totals for all customers
    total_sub_cent = sub_patty_cent + sub_sally_cent + sub_tommy_cent;
    total_tax_cent = tax_patty_cent + tax_sally_cent + tax_tommy_cent;
    total_all_cent = total_sub_cent + total_tax_cent;

    printf("\nCustomer Size Price Qty Sub-Total  Tax       Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %c    %5.2lf  %d  %9.4lf %9.4lf %9.4lf\n", patSize, price_S, qty_patty, sub_patty_cent / 100.0, tax_patty_cent / 100.0, total_patty_cent / 100.0);
    printf("Sally    %c    %5.2lf  %d  %9.4lf %9.4lf %9.4lf\n", salSize, price_M, qty_sally, sub_sally_cent / 100.0, tax_sally_cent / 100.0, total_sally_cent / 100.0);
    printf("Tommy    %c    %5.2lf  %d  %9.4lf %9.4lf %9.4lf\n", tomSize, price_L, qty_tommy, sub_tommy_cent / 100.0, tax_tommy_cent / 100.0, total_tommy_cent / 100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n", total_sub_cent / 100.0, total_tax_cent / 100.0, total_all_cent / 100.0);

    printf("\nDaily retail sales represented by coins\n");
    printf("=======================================\n");

    int balance_cent = total_sub_cent;

    // Count coins without tax
    int toonies = balance_cent / 200;  
    balance_cent %= 200;
    int loonies = balance_cent / 100;  
    balance_cent %= 100;
    int quarters = balance_cent / 25;  
    balance_cent %= 25;
    int dimes = balance_cent / 10;     
    balance_cent %= 10;
    int nickels = balance_cent / 5;    
    balance_cent %= 5;
    int pennies = balance_cent;        

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("\t\t%9.4lf\n", total_sub_cent / 100.0);
    printf("Toonies  %3d   %9.4lf\n", toonies, (total_sub_cent - (toonies * 200)) / 100.0);
    printf("Loonies  %3d   %9.4lf\n", loonies, (total_sub_cent - (toonies * 200 + loonies * 100)) / 100.0);
    printf("Quarters %3d   %9.4lf\n", quarters, (total_sub_cent - (toonies * 200 + loonies * 100 + quarters * 25)) / 100.0);
    printf("Dimes    %3d   %9.4lf\n", dimes, (total_sub_cent - (toonies * 200 + loonies * 100 + quarters * 25 + dimes * 10)) / 100.0);
    printf("Nickels  %3d   %9.4lf\n", nickels, (total_sub_cent - (toonies * 200 + loonies * 100 + quarters * 25 + dimes * 10 + nickels * 5)) / 100.0);
    printf("Pennies  %3d   %9.4lf\n", pennies, 0.0);

    // Average cost per shirt (no tax)
    double avg_cost_shirt = (double)total_sub_cent / (qty_patty + qty_sally + qty_tommy) / 100.0;
    printf("Average cost/shirt: $%.4lf\n", avg_cost_shirt);

    // Repeat coin breakdown with tax
    balance_cent = total_all_cent;
    toonies = balance_cent / 200;
    balance_cent %= 200;
    loonies = balance_cent / 100;
    balance_cent %= 100;
    quarters = balance_cent / 25;
    balance_cent %= 25;
    dimes = balance_cent / 10;
    balance_cent %= 10;
    nickels = balance_cent / 5;
    balance_cent %= 5;
    pennies = balance_cent;

    printf("\nSales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("\t\t%9.4lf\n", total_all_cent / 100.0);
    printf("Toonies  %3d   %9.4lf\n", toonies, (total_all_cent - (toonies * 200)) / 100.0);
    printf("Loonies  %3d   %9.4lf\n", loonies, (total_all_cent - (toonies * 200 + loonies * 100)) / 100.0);
    printf("Quarters %3d   %9.4lf\n", quarters, (total_all_cent - (toonies * 200 + loonies * 100 + quarters * 25)) / 100.0);
    printf("Dimes    %3d   %9.4lf\n", dimes, (total_all_cent - (toonies * 200 + loonies * 100 + quarters * 25 + dimes * 10)) / 100.0);
    printf("Nickels  %3d   %9.4lf\n", nickels, (total_all_cent - (toonies * 200 + loonies * 100 + quarters * 25 + dimes * 10 + nickels * 5)) / 100.0);
    printf("Pennies  %3d   %9.4lf\n", pennies, 0.0);

    avg_cost_shirt = (double)total_all_cent / (qty_patty + qty_sally + qty_tommy) / 100.0;
    printf("Average cost/shirt: $%.4lf\n", avg_cost_shirt);

	// Wait for user to press Enter
    getchar();
    getchar();

    return 0;
}
