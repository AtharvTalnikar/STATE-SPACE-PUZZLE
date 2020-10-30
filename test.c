#include "A3_header_PES1201800148.h"
#include<stdio.h>
extern state *answer;
extern state *all_states;
extern int all_states_size;
extern int answer_size;
extern int A;
extern int B;
extern int C;
extern int AF;
extern int BF;
extern int CF;

int check_state(int x,int y,int z)
{
    for(int i=0 ; i<all_states_size ; i++)
    {
        if((all_states[i].Ja == x) && (all_states[i].Jb == y) && (all_states[i].Jc == z))
            return 1;
    }
    return 0;
}

state* create_state(int x, int y, int z)
{
    state *temp = (state*)malloc(sizeof(state));
    temp->Ja = x;
    temp->Jb = y;
    temp->Jc = z;

    return temp;
}

void append_allstates(state *curr)
{
    all_states[all_states_size++] = *curr;
}

void append_answer(state *curr)
{
    answer[answer_size++] = *curr;
}

int get_states(int a,int b, int c)
{
    state *curr = create_state(a,b,c);

    if(a==AF && b==BF && c==CF)
    {
        append_answer(curr);
        return 1;
    }

    if(!check_state(a,b,c))
    {
        append_allstates(curr);
    }*
    else
    {
        return 0;
    }

    //empty jug A
    if(a>0)
    {
        //empty a into b
        if(a+b<=B)
        {
            if(get_states(0,a+b,c))
            {
                append_answer(curr);
                return 1;
            }
        }
        else
        {
            if(get_states(a-(B-b),B,c))
            {
                append_answer(curr);
                return 1;
            }
        }

        //empty a into c
        if(a+c<=C)
        {
            if(get_states(0,b,a+c))
            {
                append_answer(curr);
                return 1;
            }
        }
        else
        {
            if(get_states(a-(C-c),b,C))
            {
                append_answer(curr);
                return 1;
            }
        }       
    }

    //empty jug b
    if(b>0)
    {
        //empty b into a
        if(a+b<=A)
        {
            if(get_states(a+b,0,c))
            {
                append_answer(curr);
                return 1;
            }
        }
        else
        {
            if(get_states(A,b-(A-a),c))
            {
                append_answer(curr);
                return 1;
            }
        }

        //empty b into c
        if(b+c<=C)
        {
            if(get_states(a,0,b+c))
            {
                append_answer(curr);
                return 1;
            }
        }
        else
        {
            if(get_states(a,b-(C-c),C))
            {
                append_answer(curr);
                return 1;
            }
        }  
    }

    //empty jug c
    if(c>0)
    {
        //empty c into a
        if(c+a<=A)
        {
            if(get_states(a+c,b,0))
            {
                append_answer(curr);
                return 1;
            }
        }
        else
        {
            if(get_states(A,b,c-(A-a)))
            {
                append_answer(curr);
                return 1;
            }
        }

        //empty c into b
        if(b+c<=B)
        {
            if(get_states(a,b+c,0))
            {
                append_answer(curr);
                return 1;
            }
        }
        else
        {
            if(get_states(a,B,c-(B-b)))
            {
                append_answer(curr);
                return 1;
            }
        }
    }

    return 0;
}