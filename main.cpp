#include <iostream>
#include <iomanip>
#include <string>
#include <thread>

#include "mpi.h"

#include "mpi_routines.h"
#include "csv.h"

using namespace std;
using namespace functions;
using namespace CSVpp;

int main(int* argc, char** argv)
{
    auto* csv = new CSV();
    
    MPI_Init(NULL, NULL);
    function::do_parallel_addition();
    MPI_Finalize;
    return 0;
}

/* Compile flags:
-I/usr/lib/x86_64-linux-gnu/openmpi/include/openmpi -I/usr/lib/x86_64-linux-gnu/openmpi/include/openmpi/opal/mca/event/libevent2022/libevent -I/usr/lib/x86_64-linux-gnu/openmpi/include/openmpi/opal/mca/event/libevent2022/libevent/include -I/usr/lib/x86_64-linux-gnu/openmpi/include -pthread
*/