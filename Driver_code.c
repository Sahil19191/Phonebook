#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Phonebook.h"

int Choice()                        // Giving the choice to user
{
    printf("\n");
    for(int i=0;i<40;i++)   printf("\4");

    printf("\nOperations:\n");

    for(int i=0;i<25;i++)   printf("\6");

    printf("\n1 - Add a Phone number\n2 - Delete a Phone number\n");
    printf("3 - Display Phonebook \n4 - Search a Phone number\n");
    printf("5 - Edit a Phone number\n0 - Close the Program\n");

    for(int i=0;i<40;i++)   printf("\4");
    int c;
    printf("\nEnter Choice: \n ");
    scanf("%d",&c);
    return c;
}


int main()
{
    Node* Root=NULL;    // Setting root to null
    int c=0;            // Choice
    char a[100];
    long long int b;
    Root = Input_from_file(Root);   // calling input method

    do{
        c=Choice();

        switch(c){
            case 1:                         // Inserting a node
                printf("\nEnter Name: ");
                fflush(stdin);
                gets(a);

                printf("\nEnter Phone Number: ");
                scanf("%lld",&b);

                Root = Add(Root,a,b);
                break;
            case 2:                         // Delete
                Root = Delete(Root);
                break;
            case 3:                         // Display
                if(Root){
                    Display(Root);}
                else
                {
                    printf("\nNote: Phonebook is empty\n");
                }

                break;
            case 4:                         // Searching
            if(Root){
                    Search(Root);
                    }
                else
                {
                    printf("\nNote: Phonebook is empty\n");
                }
                break;

            case 5:
                Root = Edit(Root);          // Edit a phone number
                break;
            case 0:
                break;

            default:
                printf("\nInvalid Input\n");
        }

    }while(c!=0);

}

