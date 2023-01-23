#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char letter;
    struct Node** children;
}Node;

Node* CreateNode()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->children = NULL;

    return node;
}

typedef struct Words_BST
{
    Node* root;
    void (*Add)(struct Words_BST* tree, const char* word);
}Words_BST;


void Add(Words_BST* tree, const char* word);

Words_BST* Create_Words_BST()
{
    Words_BST* tree = (Words_BST*)malloc(sizeof(Words_BST));
    tree->root = CreateNode();
    tree->Add = Add;
}

void CreateAlphabet(Node** node)
{
    node = (Node**)calloc(26, sizeof(Node*));
    for (int i = 0; i < 26; i++)
    {
        node[i] = CreateNode();
    }
}

void Add(Words_BST* tree, const char* word)
{
    Node* root = tree->root;
    for(int i = 0; word[i] != '\0'; i++)
    {
        if(root->children == NULL)
        {
            root->letter = word[i];
            CreateAlphabet(root->children);
            root = root->children[word[i] - 'a'];
        }
    }
}

int main()
{
    Words_BST* tree = Create_Words_BST();
    const char* word = "andrew";
    tree->Add(tree, word);
}
