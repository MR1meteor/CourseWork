#include "BaseException.h"

BaseException::BaseException(string data, string where, string what)
	: data(data), where(where), what(what) { }

void BaseException::ShowInfo()
{
	cout << "Exception info: " << what << endl <<
		"Exception source: " << where << endl <<
		"Exception data: " << data << endl;
}