#include <stdio.h>
#include "tris.h"

void echanger(int *t, int n1, int n2)
{
	int tmp = t[n1];
	t[n1] = t[n2];
	t[n2] = tmp;
}

structSondes tri_bulle_naif(int *t, int n)
{
	structSondes sondes = {0,0,0}; 

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			++sondes.nb_comparaisons;
			if(t[j] > t[j+1]) {
				echanger(t, j,j+1);
				sondes.nb_copies+=3;
				++sondes.nb_echanges;
			}
		}
	}

	return sondes;
}


structSondes tri_bulle_bool(int *t, int n)
{
	structSondes sondes = {0,0,0}; 


	return sondes;
}


structSondes tri_bulle_opt(int *t, int n)
{
	structSondes sondes = {0,0,0}; 
	int tmp = n;
	int posLastSwap = tmp;

	for(int i = 0; i < n -1; ++i)
	{
		for(int j = 0; j < tmp; ++j)
		{
			++sondes.nb_comparaisons;
			if(t[j] > t[j+1]) {
				echanger(t, j,j+1);
				posLastSwap = j;
				sondes.nb_copies+=3;
				++sondes.nb_echanges;
			}
		}
		tmp = posLastSwap;
	}

	return sondes;
}


structSondes tri_insertion(int *t, int n)
{
	structSondes sondes; /* @todo utiliser sonde */

	return sondes;
}


structSondes tri_selection(int *t, int n)
{
	structSondes sondes = {0,0,0};

	int max = 0;
	int tmp = n;
	int i,j;

	for(i = 0; i < n-1; ++i)
	{
		for(j = 0; j < tmp-1; ++j)
		{
			++sondes.nb_comparaisons;
			if(t[j] > t[max])
			{
				max = j;
				++sondes.nb_copies;
			}
		}
		sondes.nb_copies+=3;
		echanger(t, max, tmp-1);
		++sondes.nb_echanges;
		--tmp;
	}
	return sondes;
}


structSondes tri_rapide(int *t, int gauche, int droite)
{
	structSondes sondes; /* @todo utiliser sonde */

	return sondes;
}
