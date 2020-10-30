#include<stdio.h>
#include "A3_header_PES1201800148.h"

//Global variables
int answer_number; //Holds total number of solutions
state *root; //THe root of the tree with the initial states
int A; //Max capacity of jug 1
int B; //Max capacity of jug 2
int C; //Max capacity of jug 3
int AF; //Final state of jug 1
int BF; //Final state of jug 2
int CF; //Final state of jug 3

int main()
{
    answer_number = 0;

    //Max capacities of the jugs
    int max_capacity[3];
    scanf("%d %d %d",&max_capacity[0],&max_capacity[1],&max_capacity[2]);
    A = max_capacity[0];
    B = max_capacity[1];
    C = max_capacity[2];

    //Initial states
    int initial_states[3];
    scanf("%d %d %d",&initial_states[0],&initial_states[1],&initial_states[2]);

    //Final states
    int final_states[3];
    scanf("%d %d %d",&final_states[0],&final_states[1],&final_states[2]);
    AF = final_states[0];
    BF = final_states[1];
    CF = final_states[2];

    //Generates tree with all possible transitions
    gen_tree(initial_states[0],initial_states[1],initial_states[2]);

    //Prints all required paths of the tree
    print_tree(root);
    
    return 0;
}