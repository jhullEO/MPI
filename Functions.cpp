#include "mpi.h"
#include "Functions.h"
#include "csv.h"
#include <iostream>
using namespace std;
using namespace functions;
using namespace CSVpp;

void function::DoParallelAddition()
{
    int mynode, totalnodes;
    int sum, startval, endval, accum;
    MPI_Status status;
    
    MPI_Comm_size(MPI_COMM_WORLD, &totalnodes);
    MPI_Comm_rank(MPI_COMM_WORLD, &mynode);
    int master = 0;
    sum = 0;
    startval = 1000 * (mynode) / totalnodes + 1;
    endval = 1000 * (mynode + 1) / totalnodes;
    for (int i = startval; i <= endval; i++)
    {
        sum += i;
    }
    if (mynode != master)
    {
        MPI_Send(&sum, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }
    else
    {
        cout << "I am the master node and I contribute: " << sum << endl;
        for (int j = 1; j < totalnodes; j++)
        {
            MPI_Recv(&accum, 1, MPI_INT, j, 2, MPI_COMM_WORLD, &status);
            sum = sum + accum;
            cout << "Recieved " << accum << " from node " << status.MPI_SOURCE << "." << endl;
        }
    }
    if (mynode == master)
    {
        cout << "I am the master. " << endl;
        cout << "The final sum from 1 to 1000 is: " << sum << endl;
    }
}