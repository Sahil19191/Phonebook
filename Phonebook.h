
typedef struct Phonebook{

    // Data field
    long long int number;
    char Name[100];

    // Linking Field
    struct Phonebook *left, *right;
} Node;

Node* Construct_node(long long int n,const char *a)      //Helper function to create a node
{
    Node *New = (Node*)malloc(sizeof(Node));
    New->number=n;
    strcpy(New->Name,a);
    //printf("\n%s %ld",New->Name,New->number);
    New->left = New->right = NULL;

    return New;
}

void Print_Node(Node *root)         //Helper function to print the information of given node
{
    printf("\nName\t\tPhone number\n");
    printf("%s\t\t%lld\n",root->Name,root->number);
}

Node* Add(Node *root,char *a,long long int b)        // Inserting a node
{
    Node* New = Construct_node(b,a);

    if(root==NULL)          // if list is empty
    {
        //printf("\n%s %ld",New->Name,New->number);
        root=New;
    }
    else
    {
        Node* temp=root;
        int n=strcmp(temp->Name,a);
        //printf("%d\n",n);

        // If node to be inserted at first position
        if(n>0){
            New->right=temp;
            temp->left = New;
            root=New;
        }
        else
        {
            // Finding the correct position to insert the node
            // according to the name
            while(n<0 && temp->right!=NULL)
            {
                temp=temp->right;
                n=strcmp(temp->Name,a);
            }

            if(n>0)         // if name in the given node is bigger than the node to be inserted
            {
                Node* Prev=temp->left;

                // Binding with previous
                Prev->right=New;
                New->left=Prev;
                // Binding with next
                New->right=temp;
                temp->left=New;
            }
            else
            {
                if(n==0 && temp->number==b)     // if name and number both are same
                {
                    printf("\nNote : Duplicates are not allowed\n");
                }

                else
                {
                Node* Next=temp->right;     // saving the further list from temp into next

                temp->right=New;        //Binding the New with Temp
                New->left=temp;


                New->right=Next;
                if(Next != NULL)        // Binding the New with the further list
                Next->left=New;
                }
            }
        }
    }
    return root;
}

Node* search_node(Node* root,long long int n)       // to search a node
{
    Node* temp=root;
    while(temp->number!=n && temp->right!=NULL)
    {
        temp=temp->right;
    }
    if(temp->number==n) return temp;
    else
    {
        return NULL;
    }
}

void Search(Node* root)             // Search and seek funtionality
{
    long long int n;
    printf("\nEnter Phone Number : ");
    scanf("%lld",&n);
    Node* found = search_node(root,n);
    if(found != NULL)
    {
        Print_Node(found);
        int choice=0;
        do
        {
            printf("\n1 - Seek Next Phone number\n2 - Seek Previous Phone number\n0 - Go back to Phonebook\nEnter : ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                if(found->right!=NULL)
                {
                    found = found->right;
                    Print_Node(found);
                }
                else
                {
                    printf("\nNote: No Next Entry\n");
                }
                break;
            case 2:
                if(found->left!=NULL)
                {
                    found = found->left;
                    Print_Node(found);
                }
                else
                {
                    printf("\nNote: No Previous Entry\n");
                }
                break;
            case 0:
            break;

            default:
                printf("\nInvalid Input\n");
                break;
            }
        } while (choice!=0);

    }
    else
    {
        printf("\nNote : Not Found\n");
    }

}

Node* Delete_Node(Node *root,long long int n)
{
    Node* found = search_node(root,n);      // calling the search method to find a node to be deleted
    if(found!=NULL){

        if(found->left == NULL)     //If founded node is first node
        {
            Node* To_be_free = found;
            root=root->right;
            if(root!=NULL)
            root->left = NULL;

            free(To_be_free);
            printf("\nDeleted");
        }
        else
        {
            Node* To_be_free = found;
            found->left->right = found->right;
            if(found->right!=NULL)          // if founded node is last node
            found->right->left = found->left;
            free(To_be_free);
            printf("\nDeleted");
        }
    }
    else
    {
        printf("\nNote: Not Found\n");
    }

    return root;
}

Node* Delete(Node *root)            // Delete a phonenumber form given node
{
    long long int n;
    printf("\nEnter Phone Number : ");
    scanf("%lld",&n);

    Node* found = search_node(root,n);      // calling the search method to find a node to be deleted
    if(found!=NULL){

        if(found->left == NULL)     //If founded node is first node
        {
            Node* To_be_free = found;
            root=root->right;
            if(root!=NULL)
            root->left = NULL;

            free(To_be_free);
            printf("\nDeleted");
        }
        else
        {
            Node* To_be_free = found;
            found->left->right = found->right;
            if(found->right!=NULL)          // if founded node is last node
            found->right->left = found->left;
            free(To_be_free);
            printf("\nDeleted");
        }
    }
    else
    {
        printf("\nNote: Not Found\n");
    }


    return root;
}

Node* Input_from_file(Node* root)   // taking default input from file
{
    FILE *fp;
    fp=fopen("Input.txt","r");
    char a[100];
    long long int d;
    while(fscanf(fp,"%s %lld\n",a,&d)!=EOF)
    {
        root=Add(root,a,d);
    }

    return root;
}

void Display(Node *root)            // to display the phonebook
{
    Node* temp=root;
    printf("\nName\t\tPhone number\n");

    while(temp!=NULL)
    {
        printf("%s\t\t%lld\n",temp->Name,temp->number);
        temp=temp->right;
    }
}

Node* Edit(Node *root)              // Edit the number in perticular node
{
    long long int n;
    printf("\nEnter Phone Number : ");
    scanf("%lld",&n);
    Node* found = search_node(root,n);
    if(found != NULL)
    {
        printf("\nEnter New Phone number\n");
        long long int temp;
        scanf("%lld",&temp);
        //root = Delete_Node(root,found->number);
        root = Add(root,found->Name,temp);          // adding new entry
        root = Delete_Node(root,found->number);     // deleting previous entry
    }
    else
    {
        printf("\nNote: Phone Number not found\n");
    }
    return root;
}
