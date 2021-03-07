
#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define inf 100000

using namespace std;

struct Edges{
int u, v;  // вершины u v которые соединены ребром
float w;   // вещественный вес ребра (предполгается что он < 100000 )
};

ifstream in_stream; 
// ofstream out_stream;



const int Vmax=1000;
const int Emax=Vmax*(Vmax-1)/2;
int i, j, n, e, start,send;
Edges edge[Emax];
float d[Vmax];

//алгоритм Беллмана-Калаба
void bellman_k(int n, int s, int s2)
{
int i, j;
 
for (i=0; i<n; i++) d[i]=inf;
d[s]=0;
 
for (i=0; i<n-1; i++)
for (j=0; j<e; j++)
    // выбираем минимальный путь
	if (d[edge[j].v]+edge[j].w<d[edge[j].u])
		d[edge[j].u]=d[edge[j].v]+edge[j].w;
 
for (i=0; i<n; i++) 
	if (d[i]==inf)
		cout<<endl<<start<<"->"<<i+1<<"="<<"Нет решения";
	else if (i==(send-1)) {
  		cout<<endl<<start<<"->"<<i+1<<"="<<d[i];	
	}
}


//главная функция
int main()
{
setlocale(LC_ALL, "Rus");
float w;  // вес ребра
 
    in_stream.open( "inputB.txt" ); // открываем входной файл 
	if ( in_stream.fail() )
    {
       cout << "Файл открыть не удалось." << endl;
       getch(); 
       exit(1);
    }
      
	cout << "Данные по графу считываются из файла inputB.txt " << endl;  
    in_stream >>n;  
    cout<<"Количество вершин > "<< n << endl;         
	        
	e=0;
	for (i=0; i<n; i++)
	for (j=0; j<n; j++)
	{
		in_stream >>w ; cout<<"Вес "<<i+1<<"->"<<j+1<<" > " << w << endl;
		
		if (w!=0)
		{
			edge[e].v=i;  // из какой вершины
			edge[e].u=j;  // в какую вершину
			edge[e].w=w;  // вес ребра L (i,j)
			e++;  // подсчет общего количества ребер в графе и переход к след.вершине
		}
	}
 
cout<<"Стартовая вершина > "; cin>>start;
cout<<"Конечная  вершина > "; cin>>send;

cout<<"Кратчайший путь:";
bellman_k(n, start-1, send-1 );
cout << " " << endl;
system("pause");
}
