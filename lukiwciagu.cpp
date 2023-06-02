#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ifstream plik, plik1, plik2;
    int tab[1000];
    int ntab[1000];
    long long najwieksza =0;
    long long najmniejsza =1000000000000;
    int roznica, ile =2, ilemakx =0;
    plik.open("dane4.txt");
    for(int i =0; i<1000; i++)
    {
        plik>>tab[i];
    }
    for(int x =0; x<999; x++)
    {
        roznica = abs(tab[x]-tab[x+1]);
        if(roznica>najwieksza)
        {
            najwieksza =roznica;
        }

        if(roznica<najmniejsza)
        {
            najmniejsza = roznica;
        }
    }
    cout<<"4.1 " << najwieksza << " "<< najmniejsza << endl;
    plik1.open("dane4.txt");
    int nowaroznica, stararoznica, mozliwapierwsza, mozliwaostatnia, pierwsza;
    for(int i =0; i<1000; i++)
    {
        plik1>>ntab[i];
    }
    stararoznica = -1;
    for (int x =0; x<999; x++)
    {

        nowaroznica = abs(ntab[x]-ntab[x+1]);
        //cout << ntab[x]<<" "<<ntab[x+1]<< " "<<nowaroznica<<" "<< stararoznica<<endl;
        if(nowaroznica==stararoznica)
        {
            ile++;
            if(ile ==3)
            {
                mozliwapierwsza = ntab[x-1];
            }
            if(ile>ilemakx)
            {
                ilemakx =ile;
                mozliwaostatnia = ntab[x+1];
                pierwsza = mozliwapierwsza;

            }
        }
        else
        {
            ile =2;
        }
        stararoznica = nowaroznica;


    }
    cout<<"4.2 " << ilemakx<<" "<<pierwsza<<" "<<mozliwaostatnia << endl;
    plik2.open("dane4.txt");

    int kolejnaroznica, krotnosc =1, maxkrotnosc =0, najw;
    int htab[1000];
    int ftab[999];
    for(int z =0; z<1000; z++)
    {
        plik2>>htab[z];
    }
     for(int l =0; l<999; l++)
    {
      ftab[l]=abs(htab[l]-htab[l+1]);
    }
    sort(ftab,ftab+999);
    for(int k=0; k<998; k++)
    {
        if(ftab[k]==ftab[k+1])
        {
            krotnosc++;
            if(krotnosc>maxkrotnosc)
            {
                maxkrotnosc = krotnosc;
            }

        }
        else
        {
            krotnosc=1;
        }
    }
najw = maxkrotnosc;
cout<<"4.3 " << maxkrotnosc<< " ";
  for(int c=0; c<998; c++)
    {
        if(ftab[c]==ftab[c+1])
        {
            krotnosc++;
            if(krotnosc==najw)
            {
                cout << ftab[c]<< " ";
            }

        }
        else
        {
            krotnosc=1;
        }
    }

}



