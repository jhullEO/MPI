#include <iostream>

#include<aws/core/Aws.h>
using namespace std;
using namespace Aws;


int main(int argc, argv* char[])
{
	SDKOptions options;
	InitAPI(options);
	cout << "Hello AWS!" << endl;
	ShutdownAPI(options);
	return 0;
}