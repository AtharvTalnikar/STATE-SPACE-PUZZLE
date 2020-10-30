#include<stdio.h>
#include"A3_header_PES1201800148.h"

//Global variables
extern int answer_number;
extern state* root;
extern int A;
extern int B;
extern int C;
extern int AF;
extern int BF;
extern int CF;

//Iniitalises a state with the valid transition values and appends it to the current path array. Then returns the state
state* initialise_state(int x, int y, int z, state path[],int pathlen)
{
    state* temp = (state*)malloc(sizeof(state));
    temp->Ja = x;
    temp->Jb = y;
    temp->Jc = z;

    temp->next1 = NULL;
    temp->next2 = NULL;
    temp->next3 = NULL;
    temp->next4 = NULL;
    temp->next5 = NULL;
    temp->next6 = NULL;

    path[pathlen] = *temp;
    return temp;
}

//This function helps check if a given state already exists in the current_path array. If the transition exists then returns 0 else returns 1.
int state_exists(int x,int y,int z,state path[],int pathlen)
{
    for(int i=pathlen-1 ; i>=0 ; i--)
    {
        if((path[i].Ja == x) && (path[i].Jb == y) && (path[i].Jc == z))
            return 1;
    }
    return 0;
}

/*
The function helps check for all the 6 possible transition for the given node values. The transition is then checked to make sure it is not repeated in the given path.
If it is repeated, the current transition is skipped and the function checks for the next next transition. If it is not repeated then a node is initialised with the  
transition values and is liked to by the respective link. After initialisation, the new node is passed as we recrusively call gen_tree_recur().  
*/
void gen_tree_recur(state* node, state path[],int pathlen)
{
    int a = node->Ja;
    int b = node->Jb;
    int c = node->Jc;

    //empty jug A
    if(a>0)
    {
        if(a+b<=B) //completely empty A into B
        {
            if(!state_exists(0,a+b,c,path,pathlen)) //check if transition values already exist
            {
                node->next1 = initialise_state(0,a+b,c,path,pathlen);
                gen_tree_recur(node->next1,path,pathlen+1);
            }
        }
        else //partially empty A into B
        {
            if(!state_exists(a-(B-b),B,c,path,pathlen)) //check if transition values already exist
            {
                node->next1 = initialise_state(a-(B-b),B,c,path,pathlen);
                gen_tree_recur(node->next1,path,pathlen+1);
            }
        }

        if(a+c<=C) //completely empty A into C
        {
            if(!state_exists(0,b,a+c,path,pathlen)) //check if transition values already exist
            {
                node->next2 = initialise_state(0,b,a+c,path,pathlen);
                gen_tree_recur(node->next2,path,pathlen+1);
            }
        }
        else //partially empty A into C
        {
            if(!state_exists(a-(C-c),b,C,path,pathlen)) //check if transition values already exist
            {
                node->next2 = initialise_state(a-(C-c),b,C,path,pathlen);
                gen_tree_recur(node->next2,path,pathlen+1);
            }
        }       
    }

    //empty jug b
    if(b>0)
    {
        if(a+b<=A) //completely empty B into A
        {
            if(!state_exists(a+b,0,c,path,pathlen)) //check if transition values already exist
            {
                node->next3 = initialise_state(a+b,0,c,path,pathlen);
                gen_tree_recur(node->next3,path,pathlen+1);
            }
        }
        else //partially empty B into A
        {
            if(!state_exists(A,b-(A-a),c,path,pathlen)) //check if transition values already exist
            {
                node->next3 = initialise_state(A,b-(A-a),c,path,pathlen);
                gen_tree_recur(node->next3,path,pathlen+1);
            }
        }

        if(b+c<=C) //completely empty B into C
        {
            if(!state_exists(a,0,b+c,path,pathlen)) //check if transition values already exist
            {
                node->next4 = initialise_state(a,0,b+c,path,pathlen);
                gen_tree_recur(node->next4,path,pathlen+1);
            }
        }
        else //partially empty B into C
        {
            if(!state_exists(a,b-(C-c),C,path,pathlen)) //check if transition values already exist
            {
                node->next4 = initialise_state(a,b-(C-c),C,path,pathlen);
                gen_tree_recur(node->next4,path,pathlen+1);
            }
        }  
    }
    
    if(c>0)
    {
        if(c+a<=A) //completely empty C into A
        {
            if(!state_exists(a+c,b,0,path,pathlen)) //check if transition values already exist
            {
                node->next5 = initialise_state(a+c,b,0,path,pathlen);
                gen_tree_recur(node->next5,path,pathlen+1);
            }
        }
        else //partially empty C into A
        {
            if(!state_exists(A,b,c-(A-a),path,pathlen)) //check if transition values already exist
            {
                node->next5 = initialise_state(A,b,c-(A-a),path,pathlen);
                gen_tree_recur(node->next5,path,pathlen+1);
            }
        }

        if(b+c<=B) //completely empty C into B
        {
            if(!state_exists(a,b+c,0,path,pathlen)) //check if transition values already exist
            {
                node->next6 = initialise_state(a,b+c,0,path,pathlen);
                gen_tree_recur(node->next6,path,pathlen+1);
            }
        }
        else //partially empty C into B
        {
            if(!state_exists(a,B,c-(B-b),path,pathlen)) //check if transition values already exists
            {
                node->next6 = initialise_state(a,B,c-(B-b),path,pathlen);
                gen_tree_recur(node->next6,path,pathlen+1);
            }
        }
    }

    return;
}

//This function passes the root state to gen_tree_recur() to generate the tree structure. 
void gen_tree(int x, int y, int z)
{
    //The current path array is used to hold the states present in the current state. Helps make sure that no state gets repeated in a given path.
    state curr_path[1000]; 
    root = initialise_state(x,y,z,curr_path,0); 
    gen_tree_recur(root,curr_path,1); //pass pathlen value as 1. 0th index is occupied by the root
}

//recursive function to print all the required paths in the given tree
void print_tree_recur(state* node,state curr_path[], int pathlen) //pathlen variable helps store depth of the path
{   
    if(node == NULL) //return if node is NULL
        return;

    curr_path[pathlen++] = *node; //If not NULL then add node to the current path array

    //If the node state values match the required final values then print the current path array 
    if(node->Ja == AF && node->Jb == BF && node->Jc == CF)
    {
        answer_number += 1; //increment number of solutions
        for(int i=0 ; i<pathlen ; i++) //Loop to print the array
        {
            printf("%d %d %d\n",curr_path[i].Ja,curr_path[i].Jb,curr_path[i].Jc);
        }
        printf("\n");
    }
    else //pass each child of the node to print_tree_recur()
    {
        print_tree_recur(node->next1,curr_path,pathlen);
        print_tree_recur(node->next2,curr_path,pathlen);
        print_tree_recur(node->next3,curr_path,pathlen);
        print_tree_recur(node->next4,curr_path,pathlen);
        print_tree_recur(node->next5,curr_path,pathlen);
        print_tree_recur(node->next6,curr_path,pathlen);
    }
}

void print_tree(state* root)  
{ 
  state path[1000]; //helps the the transition in the current path
  print_tree_recur(root, path, 0); //initially pathlen value is passed as 0
  printf("Total number of solution = %d\n",answer_number); //printing total number of solutions
}