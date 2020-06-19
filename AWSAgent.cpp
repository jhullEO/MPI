#include <string>

#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/PutObjectRequest.h>
#include <aws/s3/model/ListObjectsRequest.h>
#include <aws/s3/model/GetObjectRequest.h>
#include <aws/s3/model/Object.h>

#include "AWSAgent.h"

using namespace std;
using namespace aws_agents;

Aws::Vector<Aws::S3::Model::Object> s3_agent::list_objects(char* path)
{	

	/*
	const size_t slash_position = path.find('/');
	char bucket[slash_position + 1];
	strcpy(bucket,path.substr(0, slash_position).c_str());
	char directory[path.length() - (slash_position + 1)];
	strcpy(directory, path.substr(slash_position).c_str());
	*/
	char bucket[] = "eo-redshift";
	char directory[] = "bestusage";
	Aws::S3::Model::ListObjectsRequest list_objects_request;
	Aws::S3::Model::GetObjectRequest get_object_request;
	list_objects_request.WithBucket(bucket);
	list_objects_request.WithPrefix(directory);
	auto list_objects_outcome = s3_client.ListObjects(list_objects_request);
	return list_objects_outcome.GetResult().GetContents();
}