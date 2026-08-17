#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

/* Structure Definition */
struct Product
{
    int id;
    char name[50];
    float price;
    int quantity;
};

/* Function Prototypes */
void addProduct(struct Product products[], int *count);
void displayProducts(struct Product products[], int count);
void searchProduct(struct Product products[], int count);
void updateProduct(struct Product products[], int count);
void deleteProduct(struct Product products[], int *count);
void totalInventoryValue(struct Product products[], int count);
void mostExpensiveProduct(struct Product products[], int count);
void lowestStockProduct(struct Product products[], int count);


/* Add Product */
void addProduct(struct Product products[], int *count)
{
    if (*count >= MAX_PRODUCTS)
    {
        printf("\nInventory is full!\n");
        return;
    }

    printf("\n========== ADD PRODUCT ==========\n");

    printf("Enter Product ID: ");
    scanf("%d", &products[*count].id);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", products[*count].name);

    printf("Enter Price: ");
    scanf("%f", &products[*count].price);

    printf("Enter Quantity: ");
    scanf("%d", &products[*count].quantity);

    (*count)++;

    printf("\nProduct added successfully!\n");
}


/* Display Products */
void displayProducts(struct Product products[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo products available!\n");
        return;
    }

    printf("\n================ INVENTORY ================\n");

    printf("%-8s %-25s %-12s %-10s\n",
           "ID", "Product", "Price", "Quantity");

    printf("----------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%-8d %-25s %-12.2f %-10d\n",
               products[i].id,
               products[i].name,
               products[i].price,
               products[i].quantity);
    }
}


/* Search Product */
void searchProduct(struct Product products[], int count)
{
    int id;
    int i;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo products available!\n");
        return;
    }

    printf("\nEnter Product ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            printf("\n========== PRODUCT FOUND ==========\n");
            printf("ID       : %d\n", products[i].id);
            printf("Name     : %s\n", products[i].name);
            printf("Price    : %.2f\n", products[i].price);
            printf("Quantity : %d\n", products[i].quantity);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nProduct not found!\n");
    }
}


/* Update Product */
void updateProduct(struct Product products[], int count)
{
    int id;
    int i;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo products available!\n");
        return;
    }

    printf("\nEnter Product ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            printf("\nProduct Found!\n");

            printf("Enter New Product Name: ");
            scanf(" %[^\n]", products[i].name);

            printf("Enter New Price: ");
            scanf("%f", &products[i].price);

            printf("Enter New Quantity: ");
            scanf("%d", &products[i].quantity);

            printf("\nProduct updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nProduct not found!\n");
    }
}


/* Delete Product */
void deleteProduct(struct Product products[], int *count)
{
    int id;
    int i;
    int j;
    int found = 0;

    if (*count == 0)
    {
        printf("\nNo products available!\n");
        return;
    }

    printf("\nEnter Product ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++)
    {
        if (products[i].id == id)
        {
            for (j = i; j < *count - 1; j++)
            {
                products[j] = products[j + 1];
            }

            (*count)--;

            printf("\nProduct deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nProduct not found!\n");
    }
}


/* Calculate Total Inventory Value */
void totalInventoryValue(struct Product products[], int count)
{
    int i;
    float total = 0;

    if (count == 0)
    {
        printf("\nNo products available!\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        total += products[i].price * products[i].quantity;
    }

    printf("\nTotal Inventory Value: %.2f\n", total);
}


/* Find Most Expensive Product */
void mostExpensiveProduct(struct Product products[], int count)
{
    int i;
    int index = 0;

    if (count == 0)
    {
        printf("\nNo products available!\n");
        return;
    }

    for (i = 1; i < count; i++)
    {
        if (products[i].price > products[index].price)
        {
            index = i;
        }
    }

    printf("\n========== MOST EXPENSIVE PRODUCT ==========\n");

    printf("ID       : %d\n", products[index].id);
    printf("Name     : %s\n", products[index].name);
    printf("Price    : %.2f\n", products[index].price);
    printf("Quantity : %d\n", products[index].quantity);
}


/* Find Lowest Stock Product */
void lowestStockProduct(struct Product products[], int count)
{
    int i;
    int index = 0;

    if (count == 0)
    {
        printf("\nNo products available!\n");
        return;
    }

    for (i = 1; i < count; i++)
    {
        if (products[i].quantity < products[index].quantity)
        {
            index = i;
        }
    }

    printf("\n========== LOWEST STOCK PRODUCT ==========\n");

    printf("ID       : %d\n", products[index].id);
    printf("Name     : %s\n", products[index].name);
    printf("Price    : %.2f\n", products[index].price);
    printf("Quantity : %d\n", products[index].quantity);
}


/* Main Function */
int main()
{
    struct Product products[MAX_PRODUCTS];

    int count = 0;
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("       PRODUCT INVENTORY SYSTEM\n");
        printf("========================================\n");

        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Calculate Total Inventory Value\n");
        printf("7. Find Most Expensive Product\n");
        printf("8. Find Lowest Stock Product\n");
        printf("9. Exit\n");

        printf("========================================\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addProduct(products, &count);
                break;

            case 2:
                displayProducts(products, count);
                break;

            case 3:
                searchProduct(products, count);
                break;

            case 4:
                updateProduct(products, count);
                break;

            case 5:
                deleteProduct(products, &count);
                break;

            case 6:
                totalInventoryValue(products, count);
                break;

            case 7:
                mostExpensiveProduct(products, count);
                break;

            case 8:
                lowestStockProduct(products, count);
                break;

            case 9:
                printf("\nThank you for using Product Inventory System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}