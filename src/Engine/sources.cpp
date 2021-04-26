#include "Include/sources.hpp"

Sources * Sources::sources_ptr = nullptr;


Sources * Sources::GetSources()
{
	if (sources_ptr == nullptr)
		sources_ptr = new Sources();
	return sources_ptr;
}

void Sources::CleanUp()
{
	if (sources_ptr != nullptr)
		delete sources_ptr;
}

Sources::Sources()
{
	//initTextboxColors(TextBoxColorLocation);
}
