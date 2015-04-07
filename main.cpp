#include "ISet.h"

int main (void)
{
	Set < int > set1;

	int y = 9;

	set1.add(y);
	set1.remove(y);
	cout<<set1.contains(y);

}
