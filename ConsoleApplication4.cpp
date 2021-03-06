/* This program utilizes factor patterns to estimate the value p in the N=p*q keys in RSA and other 
cryptography ciphers that use the product of semi-prime numbers.
Note it is complex to program math into a programming language. Large values could easily crash this program.
As an example I recommend testing 85 for N and 5 for x. 

Also note that finding the error between PNP and pnp_check is crucial to solving this problem. For this demenstration estimate is set
to 7. Abviously to make this program usefull estimate must be determined exactly. For now this stands as a demonstration of the equation.
*/

#include "stdafx.h"
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	bool testvalue = false;
	int PNP;
	double root, estimate = 7;
	float x, pnp_check;

	cout << "Input N the know product of 2 Prime numbers" << endl;
	cin >> PNP;


	do
	{
		cout << "Enter the small Prime factor of N as test value+." << endl;
		cin >> x;

		/*		PNPcheck = sqrt[(((((x ^ 2) * (PNP ^ 4) + 2 * PNP ^ 2 * (x ^ 5)) + x ^ 8) / PNP ^ 4) * (((PNP ^ 2) / x ^ 2)))];

		estimate = (2 * x ^ 5 / PNP ^ 2 + x ^ 8 / PNP ^ 4);
*/


		pnp_check = (((( (x*x) * (PNP*PNP*PNP*PNP) + 2 * (PNP * PNP) * (x*x*x*x*x)) + (x*x*x*x*x*x*x*x)) /   (PNP*PNP*PNP*PNP)) * ( ( (PNP*PNP) / (x*x) )));


		root = sqrt(double(pnp_check));


		if ((abs(root - double(PNP))) < ((estimate))) { testvalue = true; };


		cout << "The root that compares to N is " << root << endl;

		if (root > PNP) {
			cout << "Chose lower x if program does not end." << endl;
		};


		cout << pnp_check << endl;

		if (root < PNP) { cout << "Chose higher x if program does not end." << endl; 
		};
	
 
	} while (testvalue != true);
	
	cout << endl << endl << endl;

	cout << "The smaller Prime Factor is around  " << x << endl;
	
	
	system("pause");
	
 		return 0;
}

