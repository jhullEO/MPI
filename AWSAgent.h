#pragma once
#include <string>

#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/PutObjectRequest.h>
#include <aws/s3/model/ListObjectsRequest.h>
#include <aws/s3/model/GetObjectRequest.h>
#include <aws/s3/model/Object.h>

#include "csv.h"

using namespace std;

namespace aws_agents
{
	class s3_agent
	{
	public :
		s3_agent()
		{
			Aws::InitAPI(options);
		};
		~s3_agent()
		{
			Aws::ShutdownAPI(options);
		};
		Aws::Vector<Aws::S3::Model::Object> list_objects(char* path);
	private :
		const Aws::SDKOptions options;
		Aws::S3::S3Client s3_client;
	};

	
}