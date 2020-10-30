#include<stdlib.h>

//Structure to store each valid transition state
typedef struct state
{
    int Ja; 
    int Jb;
    int Jc;

    //As atmost 6 transition are allowed there are 6 self referencing variables
    struct state* next1; //For transition A->B
    struct state* next2; //For transition A->C
    struct state* next3; //For transition B->A
    struct state* next4; //For transition B->C
    struct state* next5; //For transition C->A
    struct state* next6; //For transition C->B
} state;

state* initialise_state(int, int, int, state*, int);
int state_exists(int, int, int, state*, int );
void gen_tree_recur(state*,state*,int);
void gen_tree(int,int,int);
void print_tree_recur(state*, state*, int);
void print_tree(state*);