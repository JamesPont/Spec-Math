#pragma warning(disable : 4996)
#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>

#include <vector>
#include <stack>
#include <set>
#include <iostream>
#include <fstream>
#include <iterator>  // ostream_iterator
#include <windows.h>
#define MAX_NUMBER_VERTICES (40)//������������ ���������� ������

using namespace std;


// ������� ������
ifstream in_stream;
ofstream out_stream;

int n,m,m1,d1,d2,choice=1,sum=0;
int choice1;
// vector < vector < pair<int,int> > > g1;
vector < vector<int> > g, gr;

int matrixSM[MAX_NUMBER_VERTICES][MAX_NUMBER_VERTICES];//������� ���������
int matrixINC[MAX_NUMBER_VERTICES][MAX_NUMBER_VERTICES];//������� �������������

// ������ ������ ���������
void Print_SPSM()
{
	    // ������
	    for (int i=0; i<n; ++i) {
	    	cout << " " << i+1 << ": ";
	    for (size_t j=0; j<g[i].size(); ++j)
		  cout << g[i][j]+1 << " ";
		  
		  cout << endl;
	    }
	    
}


// ������ ������� ���������
void Print_MSM()
{
	    // ������
	    for (int i=0; i<n; ++i) {
	    for (int j=0; j<n; ++j)
		  cout << matrixSM[i][j] << " ";
		  
		  cout << endl;
	    }
	    
}


// ������ ������� �������������
void Print_MINC()
{
	    for (int i=0; i<m; ++i) {
	    for (int j=0; j<n; ++j)
		  cout << matrixINC[i][j] << " "; 
		  
		  cout << endl;
        }	
	
}




// �������������� �� ������� ��������� � ������ ���������
void Preobr_MSM_SPSM()
{
	int m1=0;
	
		for (int i=0; i<n; ++i) {
			g.push_back(vector <int> ());
	    }
	
		
		for (int i=0; i<n; ++i) 
			for (int j=0; j<n; ++j) {
				// cout << i<< "="<<j <<" ";
		 	   if(matrixSM[i][j] == 1){
		  	       g[i].push_back(j);
		  	       m1++;  // ������� �����
		  	       // cout << m1 <<"*";
		 	   }
		    }  
		 
		 //  cout << "m1= " << m1 << endl;
		 // Print_SPSM();
	  	
} 
 
 

// �������������� �� ������� ������������� � ������ ���������
void Preobr_MINC_SPSM()
{
	int m1=0,d1,d2;
	boolean foundv;
	
		for (int i=0; i<n; ++i) {
			g.push_back(vector <int> ());
	    }
	
	
		for (int i=0; i<m; ++i) 
		{
			foundv = false;
		
			for (int j=0; j<n; ++j) {
				 //cout << i<< "="<<j <<" ";
		 	   if(matrixINC[i][j] == -1){
		 	   	   d1=j; foundv = true;
		 	   }
		 	   if(matrixINC[i][j] == 1){
		 	   	   d2=j;
		 	   }
		 	   
		  	       
		  	       // cout << m1 <<"*";
		    } 
		    
		    if (foundv) {
		       g[d1].push_back(d2);
		  	   m1++;  // ������� �����	
			}
		    
	    }
		 
		 //     cout << "m1= " << m1 << endl;
         // Print_SPSM();
	  	
} 

// �������������� �� ������ ��������� � �������  ���������
void Preobr_SPSM_MSM()  
{
	int k1=0;
	    for (int i=0; i<n; ++i) 
	 	  for (int j=0; j<n; ++j)
	 	     matrixSM[i][j]=0;
	 	   
	 	   
	
	    for (int i=0; i<n; ++i) {
	    for (size_t j=0; j<g[i].size(); ++j) {
	    	matrixSM[i][g[i][j]]=1;
	        k1++;
		}
		k1=0;
	    }
	
}


// �������������� �� ������ ��������� � �������  �������������
void Preobr_SPSM_MINC()  
{
	int k1=0,d1;
	    for (int i=0; i<m; ++i) 
	 	  for (int j=0; j<n; ++j)
	 	     matrixINC[i][j]=0;
	 	   
	 	   
	    k1=0;
	    for (int i=0; i<n; ++i) {
	    for (size_t j=0; j<g[i].size(); ++j) {
	    	d1=g[i][j];
	    	
	    	matrixINC[k1][i]=-1;
	    	matrixINC[k1][d1]=1;
	    	
	    	// cout << "k1=d1=" << k1 << " " << d1;
	        k1++;
		}
	    }
	    m=k1;  // ���������� �����
	
}
 
 
 
 
 
 
 
int main()
{
	  system ("chcp 1251"); // ������� ��� �������, ������ ���������
	  setlocale(LC_ALL, "Russian");
	  
	  int m2,n2,z2;
	  

// *** 1. ���� ������  **
cout << "���� �����. 1) ������ � ���� ������� ���������." << endl;
cout << "            2) ������ � ���� ������� �������������." << endl;
cout << "            3) ������ � ���� ������ ���������." << endl;
cout << " ��� �����: 1 2 ��� 3 ? " << endl;
cin >> choice;
if ((choice>3) || (choice<1)) {
	choice=1;
}


// cout << choice << endl;


if (choice==1) {
	 // 1. ������ ������ �� ����� in1.txt
	 cout << "������� ��������� �� ����� in1.txt "<< endl;
     in_stream.open( "in1.txt" ); // ��������� ������� ���� 
		if ( in_stream.fail() )
        {
           cout << "���� ������� �� �������." << endl;
           getch(); 
           exit(1);
        }
		
		in_stream >> n;  // 8
		for (int i=0; i<n; ++i) 
		for (int j=0; j<n; ++j) {
			
		   // ���������� � ������ �����
           in_stream >> d1 ;
	  	   matrixSM[i][j]=d1;
	    }
	    
	    // Print_MSM();
	  
}


if (choice==2) {
	 // 1. ������ ������ �� ����� in2.txt
	 cout << "������� ������������� �� ����� in2.txt "<< endl;
     in_stream.open( "in2.txt" ); // ��������� ������� ���� 
		if ( in_stream.fail() )
        {
           cout << "���� ������� �� �������." << endl;
           getch(); 
           exit(1);
        }
		
		in_stream >> m;  // 5  - ���������� �����
		in_stream >> n;  // 4  - ���������� ������
		
		for (int i=0; i<m ; ++i) 
		for (int j=0; j<n ; ++j) {
			
		   // ���������� � ������ �����
           in_stream >> d1 ;
	  	   matrixINC[i][j]=d1;
	    }
	    
	     // Print_MINC();
}


if (choice==3) {
	
	 // 1. ������ ������ �� ����� in3.txt
	 cout << "������ ��������� �� ����� in3.txt "<< endl;
	 
     in_stream.open( "in3.txt" ); // ��������� ������� ���� 
		if ( in_stream.fail() )
        {
           cout << "���� ������� �� �������." << endl;
           getch(); 
           exit(1);
        }
        
		in_stream >> n;  // 8 - ���������� ������
		in_stream >> m; // 14 - ���������� ����� � �����
		
		for (int i=0; i<n; ++i) {
			g.push_back(vector <int> ());
			// gr.push_back(vector <int> ());
	    }
	
	 //cout << " ==0 " << endl;
		
		for (int i=0; i<m; ++i) {
		   // ���������� � ������ �����
           in_stream >> d1 >>  d2 ;
	  	   g[d1-1].push_back(d2-1);
	    }
	    
	    // cout << " 0 " << endl;
	    
	    for (int i=0; i<n; ++i) {
	    	cout << " " << i+1 << ": ";
	    for (size_t j=0; j<g[i].size(); ++j)
		  cout << g[i][j]+1 << " ";
		  
		  cout << endl;
	    }
}

choice1=choice;  // ��������� ����� ������� ����� �����

// Preobr_SPSM_MINC();  // �������������� �� �����a ���������  � ������� ��������������

// *** 2. ��������������� ������  **
while (choice!=3) {
	
cout << "�������������� �����. " << endl;
cout << "  1) ������� ���� �� �����." << endl;
cout << "  2) �������� ������." << endl;
cout << "  3) ����� �� ��������������." << endl;

cout << " ��� �����: 1 - 3 ? " << endl;
cin >> choice;
if ((choice>3) || (choice<1)) {
	choice=1;
}

// *** ������ �����
if (choice==1) {  
if (choice1==1) {
   Print_MSM(); 
}
if (choice1==2) {
   Print_MINC();  
}
if (choice1==3) {
   	Print_SPSM(); 
}

}

// *** �������� ������ �����
if (choice==2) {  
if (choice1==1) {  // ������� ��������� 
  cout << " ������� ������ ������� ���������." << endl;
  cin >> n2;
  cout << " ������� ������� ������� ���������." << endl;
  cin >> m2;
  cout << " ������� ��������: 0 ��� 1." << endl;
  cin >> z2;
  if ((n2>=1) && (m2>=1) &&  (z2>=0) &&  (z2<=1) &&  (n2<=n) &&  (m2<=n)) {
  	  matrixSM[n2-1][m2-1]=z2;
  	  cout << " ����������� �������." << endl;
  } else {
  	 cout << " ����������� �� �������. ������ ������." << endl;
  }  
   // Print_MSM(); 
}


if (choice1==2) { // ������� �������������
  cout << " ������� ������ ������� �������������." << endl;
  cin >> n2;
  cout << " ������� ������� ������� �������������." << endl;
  cin >> m2;
  cout << " ������� ��������: 0,1 ��� -1." << endl;
  cin >> z2;
  if ((n2>=1) && (m2>=1) &&  (z2>=-1) &&  (z2<=1) &&  (n2<=n) &&  (m2<=m)) {
  	  matrixINC[n2-1][m2-1]=z2;
  	  cout << " ����������� �������." << endl;
  } else {
  	 cout << " ����������� �� �������. ������ ������." << endl;
  }  
}


if (choice1==3) { // ������ ��������� 
  cout << " ������� ������ ������ ���������." << endl;
  cin >> n2;
  cout << " ������� ����� �������." << endl;
  cin >> m2;
  cout << " ������� ��������: " << endl;
  cin >> z2;
  if ((n2>=1) && (m2>=1) &&  (z2>=1) &&  (z2<=n) &&  (n2<=n) &&  (m2<=n)) {
		  
	  for (int j=0; j<g[n2-1].size(); ++j) {
	  	if ((g[n2-1][j]+1)==m2) {
	  	    g[n2-1][j]=z2-1;	
		  }
	  }
	  
  	  cout << " ����������� �������." << endl;
  } else {
  	 cout << " ����������� �� �������. ������ ������." << endl;
  }  
}

}



} // end while (�������������� �����)


if (choice1==1) {
   Preobr_MSM_SPSM();  // �������������� �� ������� ��������� � ������ ���������
   // Print_SPSM();
}

if (choice1==2) {
   Preobr_MINC_SPSM();  // �������������� �� ������� �������������� � ������ ���������
   // Print_SPSM();
}


// *** 3. ����� ����������  � ����� � ����� �� ����  ����� 
//        ( ����� ��  ���������� ������������ ) �� �������; **	
 
cout << "����� �����. 1) ������� � ���� ������� ���������." << endl;
cout << "             2) ������� � ���� ������� �������������." << endl;
cout << "             3) ������� � ���� ������ ���������." << endl;
cout << " ��� �����: 1 2 ��� 3 ? " << endl;
cin >> choice;
if ((choice>3) || (choice<1)) {
	choice=1;
}

if ((choice==1) && (choice1!=1 )) {
	cout << "������� �� ������� ���������...�����������." << endl;
   Preobr_SPSM_MSM();  // �������������� � ������� ��������� �� ������ ���������
   Print_MSM(); 
} else if ((choice==1)  && (choice1==1)) {
   Print_MSM(); 
}

if ((choice==2) && (choice1!=2 )) {
	cout << "������� �� ������� �������������...�����������." << endl;
    Preobr_SPSM_MINC();  // �������������� � ������� ������������� �� ������ ���������
    Print_MINC();
} else if  ((choice==2) && (choice1==2))  {
   Print_MINC(); 
}
	
if (choice==3) {	
	Print_SPSM();
}

	
    getchar();
    printf("\n");
    return 0;
}
