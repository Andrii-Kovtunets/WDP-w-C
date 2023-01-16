#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char letter;
    struct Node* Left_Child;
    struct Node* Right_Child;
}Node;

typedef struct Root
{
    Node* alphabet;
}Root;

typedef struct BST_Trie
{
    Root* root;
    void (*Add_Word)(struct BST_Trie* tree, const char* word);
    void (*Print)(struct BST_Trie* tree);
}BST_Trie;

void Print_Tree(BST_Trie* tree);

void Add_Word(BST_Trie* tree, const char* word)
{
    Root* root = tree->root;
    Node* root_OfWord;

    for(int i = 0; i < 26; i++)
    {
        if(root->alphabet[i].letter == word[0])
        {
            root_OfWord = &root->alphabet[i];

            break;
        }
    }


    int indexOfLetterInWord = 1;
    while(word[indexOfLetterInWord] != '\0')
    {
        printf("%c", root_OfWord->letter);

        if(word[indexOfLetterInWord] > root_OfWord->letter)
        {
            if(root_OfWord->Right_Child != NULL)
            {
                root_OfWord = root_OfWord->Right_Child;
            }
            else
            {
                root_OfWord->Right_Child = Create_Node(word[indexOfLetterInWord]);
                root_OfWord = root_OfWord->Right_Child;
            }
        }
        else
        {
            if(root_OfWord->Left_Child != NULL)
            {
                root_OfWord = root_OfWord->Left_Child;
            }
            else
            {
                root_OfWord->Left_Child = Create_Node(word[indexOfLetterInWord]);
                root_OfWord = root_OfWord->Left_Child;
            }
        }

        indexOfLetterInWord++;
    }
    printf("%c\n", root_OfWord->letter);
}

BST_Trie* Create_BST_Trie()
{
    BST_Trie* tree = (BST_Trie*)malloc(sizeof(BST_Trie));
    tree->root = (Root*)malloc(sizeof(Root));
    tree->Add_Word = Add_Word;
    tree->Print = Print_Tree;

    int lengthOfAlphabet = 26;
    Node* alphabet_Array = (Node*)calloc(lengthOfAlphabet, sizeof(Node));
    for(int i = 0; i < lengthOfAlphabet; i++)
    {
        alphabet_Array[i].letter = i + 'a';
        alphabet_Array[i].Left_Child = NULL;
        alphabet_Array[i].Right_Child = NULL;
    }
    tree->root->alphabet = alphabet_Array;

    return tree;
}

void Create_Node(char letter)
{
    Node* letter_Node = (Node*)malloc(sizeof(Node));
    letter_Node->Left_Child = NULL;
    letter_Node->Right_Child = NULL;
    letter_Node->letter = letter;

    return letter_Node;
}

void PrintArray(Node* array, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%c\n", array[i].letter);
    }
}

void Print_Tree(BST_Trie* tree)
{
    Node* words = tree->root->alphabet;
    Node* word;
    for(int i = 0; i < 26; i++)
    {
        word = &words[i];
        PrintBST(word);
    }
}

void PrintBST(Node* root)
{
    if(root != NULL) // checking if the root is not null
    {
        PrintBST(root->Left_Child); // visiting left child
        printf("%c\n", root->letter); // printing data at root
        PrintBST(root->Right_Child);// visiting right child
    }
}

int main()
{
    BST_Trie* tree = Create_BST_Trie();
    tree->Add_Word(tree, "hello");
    tree->Print(tree);
}
