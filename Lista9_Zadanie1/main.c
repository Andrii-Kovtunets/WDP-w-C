#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_CHARS 256

typedef struct trienode
{
    struct trienode *children[NUM_CHARS];
    bool terminal;
}trienode;

trienode *createnode()
{
    trienode* newnode = (trienode*)malloc(sizeof(trienode));
    for(int i = 0; i < NUM_CHARS; i++)
    {
        newnode->children[i] = NULL;
    }
    newnode->terminal = false;

    return newnode;
}

bool trieinsert(trienode** root, char* signedtext)
{
    if(*root == NULL)
    {
        *root = createnode();
    }

    unsigned char* text = (unsigned char*) signedtext;
    trienode *tmp = *root;
    int length = strlen(signedtext);

    for(int i = 0; i < length; i++)
    {
        if(tmp->children[text[i]] == NULL)
        {
            tmp->children[text[i]] = createnode();
        }

        tmp = tmp->children[text[i]];
    }

    if(tmp->terminal)
    {
        return false;
    }
    else
    {
        tmp->terminal = true;
        return true;
    }
}

void printtree_rec(trienode* node, unsigned char* prefix, int length)
{
    unsigned char newprefix[length + 2];
    memcpy(newprefix, prefix, length);
    newprefix[length + 1] = 0;

    if(node->terminal)
    {
        printf("%s\n", prefix);
    }

    for(int i = 0; i < NUM_CHARS; i++)
    {
        if(node->children[i] != NULL)
        {
            newprefix[length] = i;
            printtree_rec(node->children[i], newprefix, length + 1);
        }
    }

}

void printtrie(trienode* root)
{
    if(root == NULL)
    {
        printf("Trie is empty!\n");
        return;
    }

    printtree_rec(root, NULL, 0);
}

int main()
{
    trienode* root = NULL;
    trieinsert(&root, "Hello");
    trieinsert(&root, "Kat");
    trieinsert(&root, "House");
    trieinsert(&root, "Dall");
    trieinsert(&root, "Couple");

    printtrie(root);
}
