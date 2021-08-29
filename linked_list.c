#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs definition:

typedef struct list
{
    int len;
    struct reg *init;
} list;

typedef struct reg
{
    int reg_value;
    struct reg *next;
} reg;

// Prototipe functions:

list *allocate_list();
int list_ordely_insert(list *l, int x);
void show_list(list *l);

int main()
{
    int op, x;
    list *linked_list;

    linked_list = allocate_list();

    do
    {
        printf("1 - Add an item in list\n");
        printf("2 - Show the list\n");
        printf("9 - Leave\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            x = 0;
            printf("\nInsert item value: \n");
            scanf("%d", &x);

            list_ordely_insert(linked_list, x);
            break;

        case 2:
            printf("\nLinked list...\n");
            show_list(linked_list);
            break;

        case 9:
            printf("\nShutting down the program...");
            break;

        default:
            printf("\nInvalid option.");
            break;
        }
    } while (op != 9);
    
    
    printf("\n");
    return 0;
}

// Functions:

list *allocate_list()
{
    list *new;
    new = (list *)calloc(1, sizeof(list));
    return new;
}

reg *allocate_register()
{
    reg *new;
    new = (reg *)calloc(1, sizeof(reg));
    return new;
}

int list_ordely_insert(list *l, int x)
{
    if (l == NULL)
        return 0;

    reg *new, *aux = NULL, *before = NULL;
    new = allocate_register();
    new->reg_value = x;

    if (l->init == NULL)
    {
        l->init = new;
    }
    else
    {
        int is_insert = 0;
        aux = l->init;
        while (aux != NULL && !is_insert)
        {
            if (aux->reg_value == new->reg_value)
            {
                return 0;
            }

            if (aux->reg_value < new->reg_value)
            {
                before = aux;
                aux = aux->next;
            }            
            else
            {
                if (before == NULL)
                    l->init = new;

                else
                    before->next = new;

                new->next = aux;
                is_insert = 1;
            }
        }
        if (!is_insert)
        {
            before->next = new;
            is_insert = 1;
        }
    }
    l->len++;
    return 1;
}

void show_list(list *l)
{
    int i;
    reg *aux;

    if (l == NULL)
    {
        printf("List does not exist.\n");
        return;
    }
    if (l->init == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    aux = l->init;
    printf("List...\n");
    while(aux != NULL)
    {
        printf("%d \n", aux->reg_value);
        aux = aux->next;
    }
    return;
}