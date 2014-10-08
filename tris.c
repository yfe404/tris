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

	int echange = FALSE;

	for(int i = 0; i < n-1; ++i)
	{
		for(int j = 0; j < n-1; ++j)
		{
			++sondes.nb_comparaisons;
			if(t[j] > t[j+1]) {
				echanger(t, j, j+1);
				echange=TRUE;
				sondes.nb_copies+=3;
				++sondes.nb_echanges;
			}
		}
		if(echange == FALSE) return sondes;
		echange = FALSE;
	}


	return sondes;
}


structSondes tri_bulle_opt(int *t, int n)
{
	structSondes sondes = {0,0,0}; 
	int tmp = n;
	int posLastSwap = tmp;	/* Position du dernier échange (évite de tout reparcourir) */
	int echange = FALSE;

	for(int i = 0; i < n-1; ++i)
	{
		for(int j = 0; j < tmp-1; ++j)
		{
			++sondes.nb_comparaisons;
			if(t[j] > t[j+1]) {
				printf("%d > %d\n", t[j], t[j+1]);
				echanger(t, j,j+1);
				echange = TRUE;
				posLastSwap = j;
				sondes.nb_copies+=3;
				++sondes.nb_echanges;
			}
		}
		tmp = posLastSwap;
		if(echange == FALSE) return sondes;
		echange = FALSE;
	}

	return sondes;
}


structSondes tri_insertion(int *t, int n)
{
	structSondes sondes = {0,0,0}; /* @todo utiliser sonde */
	int j;

	for(int i = 1; i <= n-1; ++i){
		int v = t[i];
		j = i;

		while(t[j-1] > v) {
			t[j] = t[j-1]; j = j - 1;
		}
	t[j] = v;	

	}	

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
