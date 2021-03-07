
#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define inf 100000

using namespace std;

struct Edges{
int u, v;  // ������� u v ������� ��������� ������
float w;   // ������������ ��� ����� (������������� ��� �� < 100000 )
};

ifstream in_stream; 
// ofstream out_stream;



const int Vmax=1000;
const int Emax=Vmax*(Vmax-1)/2;
int i, j, n, e, start,send;
Edges edge[Emax];
float d[Vmax];

//�������� ��������-������
void bellman_k(int n, int s, int s2)
{
int i, j;
 
for (i=0; i<n; i++) d[i]=inf;
d[s]=0;
 
for (i=0; i<n-1; i++)
for (j=0; j<e; j++)
    // �������� ����������� ����
	if (d[edge[j].v]+edge[j].w<d[edge[j].u])
		d[edge[j].u]=d[edge[j].v]+edge[j].w;
 
for (i=0; i<n; i++) 
	if (d[i]==inf)
		cout<<endl<<start<<"->"<<i+1<<"="<<"��� �������";
	else if (i==(send-1)) {
  		cout<<endl<<start<<"->"<<i+1<<"="<<d[i];	
	}
}


//������� �������
int main()
{
setlocale(LC_ALL, "Rus");
float w;  // ��� �����
 
    in_stream.open( "inputB.txt" ); // ��������� ������� ���� 
	if ( in_stream.fail() )
    {
       cout << "���� ������� �� �������." << endl;
       getch(); 
       exit(1);
    }
      
	cout << "������ �� ����� ����������� �� ����� inputB.txt " << endl;  
    in_stream >>n;  
    cout<<"���������� ������ > "<< n << endl;         
	        
	e=0;
	for (i=0; i<n; i++)
	for (j=0; j<n; j++)
	{
		in_stream >>w ; cout<<"��� "<<i+1<<"->"<<j+1<<" > " << w << endl;
		
		if (w!=0)
		{
			edge[e].v=i;  // �� ����� �������
			edge[e].u=j;  // � ����� �������
			edge[e].w=w;  // ��� ����� L (i,j)
			e++;  // ������� ������ ���������� ����� � ����� � ������� � ����.�������
		}
	}
 
cout<<"��������� ������� > "; cin>>start;
cout<<"��������  ������� > "; cin>>send;

cout<<"���������� ����:";
bellman_k(n, start-1, send-1 );
cout << " " << endl;
system("pause");
}
