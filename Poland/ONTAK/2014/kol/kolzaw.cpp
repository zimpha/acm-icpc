#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include "kol.h"

#define massert(x,...) { if (!(x)) { printf("Blad: "); printf(__VA_ARGS__); printf("\n"); exit(0); }  }
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
//#define dprintf(...)

const int maxv = 5000;
const int maxe = 300000;


int vertices,edges;
std::vector<int> graph[maxv];
bool initdone = false;


void init()
{

  vertices = 0;
  edges = 0;
  initdone = true;
}

int create(std::vector<int> neighbours)
{
  massert(initdone,"init() nie wywolane!");
  for(int i=0; i<(int)neighbours.size(); i++)
    massert(neighbours[i]>=0 && neighbours[i]<vertices,"Zly numer sasiada!");
  graph[vertices] = neighbours;
  edges += neighbours.size();
  massert(vertices<=maxv,"Zbyt wielu kolegow!");
  massert(edges<=maxe,"Zbyt wiele znajomosci!");
  vertices++;
  return vertices-1;
}

void answer(std::vector<int> user)
{
  massert(initdone,"init() nie wywolane!");  
  massert((int)user.size()==vertices,"Zly rozmiar tablicy!");
  for(int i=0; i<vertices; i++)
    for(int j=0; j<(int)graph[i].size(); j++)
      massert(user[i]!=user[graph[i][j]],"Znajomosc (%d,%d) ma ten sam kolor!",i,graph[i][j]);
  sort(user.begin(), user.end());
  user.erase(unique(user.begin(),user.end()),user.end());
  printf("Uzytkownik: %d kolorow, Bajtazar: %d.\n",user.size(),vertices);
}



