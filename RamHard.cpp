// Algorithm to generate Ramanujan-Hardy numbers smaller to n

#include <iostream>
#include <iomanip>
#include <cmath>

int main ()
{
	std::cout.setf ( std::ios::fixed );
	unsigned int n { 1000 };
	for ( unsigned int i { n }; i >= 4; i -- )
	{
		for ( unsigned int j { i - 1 }; j >= 3; j -- )
		{
			for ( unsigned int k { 1 }; k <= j - 2; k ++ )
			{
				for ( unsigned int l { k + 1 }; l <= j - 1; l ++ )
				{
					if ( ( pow ( i, 3 ) + pow ( k, 3 ) == pow ( j, 3 ) + pow ( l, 3 ) ) && k != i && k != j && l != i && l != j && k != l && i != j )
					{
						std::cout << std::setprecision ( 0 ) << i << ", " << k << " and " <<  j << ", " << l << " are Ramanujan-Hardy numbers of " << pow ( k, 3 ) + pow ( i, 3 ) << std::endl;
					}
				}
			}
		}
	}
	std::cout << "\n\nPress any key to exit...";
	std::cin.get();
	return 0;
}