#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* right;
    struct node* left;
}Node;

Node* Search(Node* root, int x)
{
    if(root == NULL || root->data == x)//if root->data is x then the element is found
    {
        return root;
    }
    else if(x > root->data)// x is greater, so we will search the right subtree
    {
        return Search(root->right, x);
    }
    else //x is smaller than the data, so we will search the left subtree
    {
        return Search(root->left, x);
    }
}

Node* new_Node(int x)
{
    Node* root;
    root = malloc(sizeof(Node));
    root->data = x;
    root->left = NULL;
    root->right = NULL;

    return root;
}

Node* insert(Node* root, int x)
{
    if(root == NULL)
    {
        return new_Node(x);
    }
    else if(x > root->data)
    {
        root->right = insert(root->right, x);
    }
    else if(x < root->data)
    {
        root->left = insert(root->left, x);
    }

    return root;
}

Node* find_minimum(Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->left != NULL) // node with minimum value will have no left child
    {
        return find_minimum(root->left); // left most element will be minimum
    }

    return root;
}

Node* find_maximum(Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->right != NULL) // node with minimum value will have no left child
    {
        return find_maximum(root->right); // left most element will be minimum
    }

    return root;
}

Node* delete(Node* root, int x)
{
    //searching for the item to be deleted
    if(root == NULL)
    {
        return NULL;
    }
    if (x > root->data)
    {
        root->right = delete(root->right, x);
    }
    else if(x < root->data)
    {
        root->left = delete(root->left, x);
    }
    else
    {
        //No Children
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left == NULL || root->right == NULL)
        {
            Node* temp;
            if(root->left == NULL)
            {
                temp = root->right;
            }
            else
            {
                temp = root->left;
            }
            free(root);

            return temp;
        }

        //Two Children
        else
        {
            Node* temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    return root;
}


void inorder(Node* root)
{
    if(root != NULL) // checking if the root is not null
    {
        inorder(root->left); // visiting left child
        printf(" %d ", root->data); // printing data at root
        inorder(root->right);// visiting right child
    }
}

Node* find_prev(Node* root, int x)
{
    if(root != NULL)
    {
        if(x > root->data)
        {
            Node* prev = find_prev(root->right, x);
            if(prev == NULL)
            {
                prev = root;
            }

            return prev;
        }
        else if(x < root->data)
        {
            Node* prev = find_prev(root->left, x);

            return prev;
        }
        else
        {
            return root->left;
        }
    }

    return root;
}


Node* find_next(Node* root, int x)
{
    if(root != NULL)
    {
        if(x > root->data)
        {
            Node* next = find_next(root->right, x);

            return next;
        }
        else if(x < root->data)
        {
            Node* next = find_next(root->left, x);

            if(next == NULL)
            {
                next = root;
            }

            return next;
        }
        else
        {
            return root->right;
        }
    }

    return root;
}

int longerer = 7;

int printTreeAlternate(Node* root, int length)
{
    if(root != NULL)
    {
        length += 3;
        printTreeAlternate(root->left, length);

        for(int i = 0; i < length; i++)
        {
            printf(" ");
        }

        printf("%d\n", root->data);

        printTreeAlternate(root->right, length);
    }
    else
    {
        length -= 3;
    }
}

void printTree(Node* root, int length, int vector)
{
    if(root != NULL)
    {
        length += longerer;
        printTree(root->left, length, 0);


        if(vector == 1 && length > longerer)
        {
            for(int i = 0; i < 3; i++)
            {
                printf(" ");
            }
        }

        for(int i = 0; i < length; i++)
        {
            printf(" ");
        }
        if(length > longerer)
        {
            printf("-- ");
        }

        printf("%d\n", root->data);

        if(vector == 0)
        {
            length-=3;
            for(int i = 0; i < length; i++)
            {
                printf(" ");
            }
            if(root->right != NULL && length > longerer)
            {
                printf("/");
                for(int i = 0; i < longerer - 1; i++)
                {
                    printf(" ");
                }
                printf("\\\n");
            }
            else if(length > longerer)
            {
                printf("/\n");
            }
            else
            {
                for(int i = 0; i < longerer; i++)
                {
                    printf(" ");
                }
                printf("\\\n");
            }
        }
        else
        {
                if(root->right != NULL)
                {
                    for(int i = 0; i < length + longerer; i++)
                    {
                        printf(" ");
                    }
                    printf("\\\n");
                }
        }

        printTree(root->right, length, 1);
    }
    else
    {
        length-=longerer;
    }
}

int main()
{
    Node* root2 = NULL;

    printTreeAlternate(root2, 0);

    Node* root = new_Node(5);

    insert(root, 3);

    insert(root, 7);

    insert(root, 6);
    //insert(root, 7);
    insert(root, 1);
    insert(root, 5);
    insert(root, 5);
    insert(root, 6);
    insert(root, 6);
    insert(root, 4);
    insert(root, 8);

    insert(root, 2);
    insert(root, 0);
    insert(root, -1);

    //printTree(root, 0, 0);
    //printTreeAlternate(root, 0);

    printf("\n\n----------------------------\n\n");


    inorder(root);
    printf("\n");

    int number1 = 6;
    if(Search(root, number1) != NULL)
    {
        printf("Number %d was finded\n", number1);
    }
    else
    {
        printf("Not finded\n");
    }

    int number2 = 7;
    delete(root, number2);
    printf("Number %d was deleted\n", number2);
    printf("\n");
    inorder(root);
    printf("\n");

    int number = 7;
    Node* prev = find_prev(root, number);
    if(prev != NULL)
    {
        printf("Previous for %d = %d\n", number, prev->data);
    }
    else
    {
        printf("%d does'nt have previous element\n", number);
    }

    Node* next = find_next(root, number);
    if(next != NULL)
    {
        printf("Next for %d = %d\n", number, next->data);
    }
    else
    {
        printf("%d does'nt have next element\n", number);
    }

    printf("\n");

    printf("Minimum = %d\n", find_minimum(root)->data);
    printf("Maximum = %d\n", find_maximum(root)->data);
}
