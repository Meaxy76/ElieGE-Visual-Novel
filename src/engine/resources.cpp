#include "../include/resources.h"

Resources * Resources::resources_ptr = nullptr;


Resources * Resources::GetResources()
{
	if (resources_ptr == nullptr)
		resources_ptr = new Resources();
	return resources_ptr;
}

void Resources::CleanUp()
{
	if (resources_ptr != nullptr)
		delete resources_ptr;
}

Resources::Resources()
{
	
}