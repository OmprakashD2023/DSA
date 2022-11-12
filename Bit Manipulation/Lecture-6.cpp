//Check if the number is a power of 2

#include <iostream>
using namespace std;

bool isPow2(int n)
{
    if(n == 0)
        return true;
    
    return ((n & (n - 1)) == 0);
}
    
// If the total no.of set bits is 1, then it is a power of 2

int main() {
	
	int n = 4;
	
	printf("%s", isPow2(n)? "True": "False");
}