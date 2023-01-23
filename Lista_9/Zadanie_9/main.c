#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char letter;
    struct Node** children;
}Node;

Node* CreateNode(char letter)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->letter = letter;
    SetAlphabet(node->children);

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
    Node* node = (Node*)malloc(sizeof(Node));
    tree->root = node;
    tree->Add = Add;
}

void SetAlphabet(Node** node)
{
    for (int i = 0; i < 26; i++)
    {
        node[i] = CreateNode('a' + i);
    }
}

/*Node* AddLetter(Node* root, char letter)
{
    if (root != NULL)
    {
        if (letter < root->letter)
        {
            root->left = AddLetter(root->left, letter);
            return root->left;
        }
        else
        {
            root->right = AddLetter(root->right, letter);
            return root->right;
        }
    }
    else
    {
        //printf("%c ", letter);
        return CreateNode(letter);
    }

    return root;
}*/

void Add(Words_BST* tree, const char* word)
{
    Node* root = tree->root;
    int i = 0;
    for(; root->children != NULL; i++)
    {
        root = root->children[word[i] - 'a'];
    }
    root->letter = word[i];
    SetAlphabet(root->children);
}

void PrintRoot(Node* root)
{
    for(int i = 0; i < 26; i++)
    {
        printf("%c", root->letter);
        PrintRoot(root->children[i]);
    }
}

int main()
{
    Words_BST* tree = Create_Words_BST();
    const char* word = "andrew";
    tree->Add(tree, word);

}
