# STATE-SPACE-PUZZLE
Find out all the solutions to A-B-C jug problem.
Data structures:
    The primary data strucutre used is a tree. Each node of the tree is of struct state type. The tree helps to store all valid paths of transition. Each node can have 
    atmost 6 children as 6 transtions are possible on any state. To create the tree we have an array of structures which helps us store the states in the current path.
    This helps us make sure that no state gets repeated in any given path.
    Once the tree is created, we traverse through each path to find the valid paths. Using an array of structures we store each node of the path into the array. The 
    moment we reach the required state we print all the nodes in the array till the required node.

Compiling:
    gcc A3_client_PES1201800148.c A3_impl_PES1201800148.c
    a.exe < input.txt

Key takeaway:
    Using a tree and an array to help create it, I learnt how to keep a track of each and every state we encounter. I also understood how to make sure no state gets
    repeated using the array. The array helped me keep a track of the current path and keep backtracking to the previous encountered states to make sure no repititons
    occur.
