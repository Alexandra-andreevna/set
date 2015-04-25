#include "ISet.h"

int main (void)
{
	Set < int > set1;

	set1.add(9);
	set1.add(5);
	set1.add(3);
	set1.remove(3);
	cout<<set1.contains(5);
	cout<<set1.size();
}
