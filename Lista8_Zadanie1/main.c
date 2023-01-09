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
    else
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
    return Search(root, x)->left;
}

Node* find_next(Node* root, int x)
{
    Node* node = Search(root, x);
    if(node == NULL)
    {
    return node
}

int main()
{
    Node* root = new_Node(5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 7);
    insert(root, 1);

    inorder(root);
    printf("\n");

    if(Search(root, 6) != NULL)
    {
        printf("Finded\n");
    }
    else
    {
        printf("Not finded\n");
    }

    delete(root, 7);

    Node* prev = find_prev(root, 1);
    if(prev != NULL)
    {
        printf("Previous for 5 = %d\n", prev->data);
    }
    else
    {
        printf("1 does'nt have previous element\n");
    }

    Node* next = find_next(root, 1);
    if(next != NULL)
    {
        printf("Next for 5 = %d\n", next->data);
    }
    else
    {
        printf("1 does'nt have next element\n");
    }

    printf("Minimum = %d\n", find_minimum(root)->data);
    printf("Maximum = %d\n", find_maximum(root)->data);
}
