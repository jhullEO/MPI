#include "mpi.h"
#include "mpi_routines.h"
#include "csv.h"
#include <iostream>
using namespace std;
using namespace functions;
using namespace CSVpp;

void function::do_parallel_addition()
{
    int my_node, total_nodes;
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &total_nodes);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_node);
    const auto master = 0;
    auto sum = 0;
    int start_val = 1000 * (my_node) / total_nodes + 1;
    int end_val = 1000 * (my_node + 1) / total_nodes;
    for (int i = start_val; i <= end_val; i++)
    {
        sum += i;
    }
    if (my_node != master)
    {
        MPI_Send(&sum, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
    }
    else
    {
        int accumulator;
        cout << "I am the master node and I contribute: " << sum << endl;
        for (auto j = 1; j < total_nodes; j++)
        {
            MPI_Recv(&accumulator, 1, MPI_INT, j, 2, MPI_COMM_WORLD, &status);
            sum = sum + accumulator;
            cout << "Received " << accumulator << " from node " << status.MPI_SOURCE << "." << endl;
        }
    }
    if (my_node == master)
    {
        cout << "I am the master. " << endl;
        cout << "The final sum from 1 to 1000 is: " << sum << endl;
    }
}

void function::get_a_file_from_s3()
{
    char path[] = "eo-redshift/bestusage";
    char* p_to_ch;
    p_to_ch = strchr(path, '/');
    int index = p_to_ch - path + 1;
	/*int slash_position = path.find('/');
    int next = path.find('/') +1;
    char bucket[46];
    strcpy(bucket, path.substr(0, slash_position).c_str());
    char directory[path.length() - (slash_position + 1)];
    strcpy(directory, path.substr(slash_position).c_str());
    */
    cout << path << endl;
    cout << index << endl;
	cout << "foo" << endl;
}