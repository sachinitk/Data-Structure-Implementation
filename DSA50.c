#include<stdio.h>
int main() // Main method.
{
    // Variables needed.
    int a[3][100001];// This array has three rows
    /*
    Three rows are : 
    1) Parent of the node. (a[0][x])
    2) Color of the node. (a[1][x])
    3) Nearest ancestor of the node which 
       has the same color as the node. (a[2][x])
    */
    int temp1=0,temp2=0,n=0,c=0,i=0;
    /*
    (n) = Number of nodes.
    (c) = Number of colors.
    (i) = Loop variable.
    (temp1) and (temp2) are temporary variables.
    */

    scanf("%d",&n);// Input number of nodes (n).
    scanf("%d",&c);// Input of number of colors (c).

    // Input parents of nodes (2 to n).
    // Parent of node 1 is 0.
    // Since node 1 is considered the root.It has no parent.   
    a[0][1]=0;
    for(i=2;i<=n;i++)
    scanf("%d",&a[0][i]);

    // Input colors of nodes (1 to n).
    for(i=1;i<=n;i++)
    scanf("%d",&a[1][i]);

    // Checking algorithm.
    // Finds nearest ancestor which has the same color as the node (i).
    for(i=1;i<=n;i++)
    {
	// (temp1) is assigned the parent of node (i) every iteration.
        temp1=a[0][i];
	// (temp2) is assigned the value of (-1) every iteration.	
	// (-1) = Default ancestor (or) no ancestor
        temp2=-1;
	// Loop is executed until the root is reached and checked.
	// i.e when (temp1 = 0) implies root or node 1 has been reached.
        for(;temp1!=0;)
        {
	    // Checks if color of ancestor is the same as the node (i).
            if(a[1][i] == a[1][temp1])
            {
		// (temp2) is assgined the value of the ancestor.
                temp2=temp1;
                break;// Loop is terminated since ancestor has been found.
            }
	    // Update statement.
	    // (temp1) is updated to (the parent of the current node).
            temp1=a[0][temp1];
	    // Each iteration (temp1) keeps moving up the tree.
        }
	// Result is stored in the third row of the array. (a[2][i])
        a[2][i]=temp2;
    }

    // This loop displays the result.(a[2][i])
    for(i=1;i<=n;i++)
    printf("%d ",a[2][i]);
    return 0;
}
