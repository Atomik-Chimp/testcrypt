// testcrypt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

/* C++ Program to Implement the RSA Algorithm */
using namespace std;
	
long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();

int _tmain(int argc, _TCHAR* argv[]){
	cout << "\nENTER FIRST PRIME NUMBER\n";
	cin >> p;
	flag = prime(p);
	if (flag == 0){
		cout << "\nWRONG INPUT\n";
		exit(1);
	}
	cout << "\nENTER ANOTHER PRIME NUMBER\n";
	cin >> q;
	flag = prime(q);
	if (flag == 0 || p == q){
		cout << "\nWRONG INPUT\n";
		exit(1);
	}
	cout << "\nENTER MESSAGE\n";
	fflush(stdin);
	cin >> msg;
	for (i = 0; msg[i] != '\0'; i++)
		m[i] = msg[i];
	n = p * q;
	t = (p - 1) * (q - 1);
	ce();
	cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";
	for (i = 0; i < j - 1; i++)
		cout << e[i] << "\t" << d[i] << "\n";

	cout << "Before Encrypt\n";
	encrypt();
	cout << "After Encrypt\n";
	cin >> p;
	cout << "After Pause\n";
	cin >> q;

	decrypt();
	
	cin >> p;

	return 0;
}

/* this tests to see if it is a prime number */
int prime(long int pr){
	int i;
	j = sqrt(double(pr));
	for (i = 2; i <= j; i++){
		if (pr % i == 0)
			return 0;
	}
	return 1;
}
	

	
void ce(){
	
	int k;
	k = 0;
	for (i = 2; i < t; i++){
		if (t % i == 0)
			continue;
		flag = prime(i);
		if (flag == 1 && i != p && i != q){
			e[k] = i;
			flag = cd(e[k]);
			if (flag > 0){
				d[k] = flag;
				k++;
			}
			if (k == 99)
				break;
		}
	}
}

long int cd(long int x){
	long int k = 1;
	while (1){
		k = k + t;
		if (k % x == 0)
			return (k / x);
	}
}

void encrypt(){
	long int pt, ct, key = e[0], k, len;
	i = 0;
	len = strlen(msg);
	while (i != len){
		pt = m[i];
		pt = pt - 96;
		k = 1;
		for (j = 0; j < key; j++){
			k = k * pt;
			k = k % n;
		}
		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}
	en[i] = -1;
	cout << "THE ENCRYPTED MESSAGE IS\n";
	for (i = 0; en[i] != -1; i++)
		printf("%c", en[i]);
	cout << "\n";
}

void decrypt(){

	cout << "Inside Decrypt\n";
	int imp;
	cin >> imp;

	long int pt, ct, key = d[0], k;
	i = 0;

	cin >> imp;
	
	while (en[i] != -1){
		ct = temp[i];
		k = 1;
		for (j = 0; j < key; j++){
			k = k * ct;
			k = k % n;
		}
		pt = k + 96;
		m[i] = pt;
		i++;
	}
	m[i] = -1;
	cout << "\nTHE DECRYPTED MESSAGE IS\n";

	for (i = 0; m[i] != -1; i++)
		printf("%c", m[i]);

}

