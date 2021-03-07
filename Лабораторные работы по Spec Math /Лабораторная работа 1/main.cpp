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
#define MAX_NUMBER_VERTICES (40)//максимальное количество вершин

using namespace std;


// входные данные
ifstream in_stream;
ofstream out_stream;

int n,m,m1,d1,d2,choice=1,sum=0;
int choice1;
// vector < vector < pair<int,int> > > g1;
vector < vector<int> > g, gr;

int matrixSM[MAX_NUMBER_VERTICES][MAX_NUMBER_VERTICES];//матрица смежности
int matrixINC[MAX_NUMBER_VERTICES][MAX_NUMBER_VERTICES];//матрица инцидентности

// Печать списка смежности
void Print_SPSM()
{
	    // печать
	    for (int i=0; i<n; ++i) {
	    	cout << " " << i+1 << ": ";
	    for (size_t j=0; j<g[i].size(); ++j)
		  cout << g[i][j]+1 << " ";
		  
		  cout << endl;
	    }
	    
}


// Печать матрицы смежности
void Print_MSM()
{
	    // печать
	    for (int i=0; i<n; ++i) {
	    for (int j=0; j<n; ++j)
		  cout << matrixSM[i][j] << " ";
		  
		  cout << endl;
	    }
	    
}


// Печать матрицы инцидентности
void Print_MINC()
{
	    for (int i=0; i<m; ++i) {
	    for (int j=0; j<n; ++j)
		  cout << matrixINC[i][j] << " "; 
		  
		  cout << endl;
        }	
	
}




// преобразование из матрицы смежности в список смежности
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
		  	       m1++;  // подсчет ребер
		  	       // cout << m1 <<"*";
		 	   }
		    }  
		 
		 //  cout << "m1= " << m1 << endl;
		 // Print_SPSM();
	  	
} 
 
 

// преобразование из матрицы инцидентности в список смежности
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
		  	   m1++;  // подсчет ребер	
			}
		    
	    }
		 
		 //     cout << "m1= " << m1 << endl;
         // Print_SPSM();
	  	
} 

// преобразование из списка смежности в матрицу  смежности
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


// преобразование из списка смежности в матрицу  инцидентности
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
	    m=k1;  // количество ребер
	
}
 
 
 
 
 
 
 
int main()
{
	  system ("chcp 1251"); // команда для системы, меняем кодировку
	  setlocale(LC_ALL, "Russian");
	  
	  int m2,n2,z2;
	  

// *** 1. Ввод данных  **
cout << "Ввод графа. 1) Ввести в виде матрицы смежности." << endl;
cout << "            2) Ввести в виде матрицы инцидентности." << endl;
cout << "            3) Ввести в виде списка смежности." << endl;
cout << " Ваш выбор: 1 2 или 3 ? " << endl;
cin >> choice;
if ((choice>3) || (choice<1)) {
	choice=1;
}


// cout << choice << endl;


if (choice==1) {
	 // 1. Вводим данные из файла in1.txt
	 cout << "Матрица смежности из файла in1.txt "<< endl;
     in_stream.open( "in1.txt" ); // открываем входной файл 
		if ( in_stream.fail() )
        {
           cout << "Файл открыть не удалось." << endl;
           getch(); 
           exit(1);
        }
		
		in_stream >> n;  // 8
		for (int i=0; i<n; ++i) 
		for (int j=0; j<n; ++j) {
			
		   // информация о ребрах графа
           in_stream >> d1 ;
	  	   matrixSM[i][j]=d1;
	    }
	    
	    // Print_MSM();
	  
}


if (choice==2) {
	 // 1. Вводим данные из файла in2.txt
	 cout << "Матрица инцидентности из файла in2.txt "<< endl;
     in_stream.open( "in2.txt" ); // открываем входной файл 
		if ( in_stream.fail() )
        {
           cout << "Файл открыть не удалось." << endl;
           getch(); 
           exit(1);
        }
		
		in_stream >> m;  // 5  - количество ребер
		in_stream >> n;  // 4  - количество вершин
		
		for (int i=0; i<m ; ++i) 
		for (int j=0; j<n ; ++j) {
			
		   // информация о ребрах графа
           in_stream >> d1 ;
	  	   matrixINC[i][j]=d1;
	    }
	    
	     // Print_MINC();
}


if (choice==3) {
	
	 // 1. Вводим данные из файла in3.txt
	 cout << "Список смежности из файла in3.txt "<< endl;
	 
     in_stream.open( "in3.txt" ); // открываем входной файл 
		if ( in_stream.fail() )
        {
           cout << "Файл открыть не удалось." << endl;
           getch(); 
           exit(1);
        }
        
		in_stream >> n;  // 8 - количество вершин
		in_stream >> m; // 14 - количество ребер в графе
		
		for (int i=0; i<n; ++i) {
			g.push_back(vector <int> ());
			// gr.push_back(vector <int> ());
	    }
	
	 //cout << " ==0 " << endl;
		
		for (int i=0; i<m; ++i) {
		   // информация о ребрах графа
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

choice1=choice;  // запомнили выбор способа ввода графа

// Preobr_SPSM_MINC();  // преобразование из спискa смежности  в матрицы иницидентности

// *** 2. Редактрирование данных  **
while (choice!=3) {
	
cout << "Редактирование графа. " << endl;
cout << "  1) Вывести граф на экран." << endl;
cout << "  2) Изменить данные." << endl;
cout << "  3) Выйти из редактирования." << endl;

cout << " Ваш выбор: 1 - 3 ? " << endl;
cin >> choice;
if ((choice>3) || (choice<1)) {
	choice=1;
}

// *** печать графа
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

// *** изменить данные графа
if (choice==2) {  
if (choice1==1) {  // матрица смежности 
  cout << " Введите строку матрицы смежности." << endl;
  cin >> n2;
  cout << " Введите столбец матрицы смежности." << endl;
  cin >> m2;
  cout << " Введите значение: 0 или 1." << endl;
  cin >> z2;
  if ((n2>=1) && (m2>=1) &&  (z2>=0) &&  (z2<=1) &&  (n2<=n) &&  (m2<=n)) {
  	  matrixSM[n2-1][m2-1]=z2;
  	  cout << " Исправления внесены." << endl;
  } else {
  	 cout << " Исправления не внесены. Ошибка данных." << endl;
  }  
   // Print_MSM(); 
}


if (choice1==2) { // матрица инцидентности
  cout << " Введите строку матрицы инцидентности." << endl;
  cin >> n2;
  cout << " Введите столбец матрицы инцидентности." << endl;
  cin >> m2;
  cout << " Введите значение: 0,1 или -1." << endl;
  cin >> z2;
  if ((n2>=1) && (m2>=1) &&  (z2>=-1) &&  (z2<=1) &&  (n2<=n) &&  (m2<=m)) {
  	  matrixINC[n2-1][m2-1]=z2;
  	  cout << " Исправления внесены." << endl;
  } else {
  	 cout << " Исправления не внесены. Ошибка данных." << endl;
  }  
}


if (choice1==3) { // Список смежности 
  cout << " Введите строку списка смежности." << endl;
  cin >> n2;
  cout << " Введите номер вершины." << endl;
  cin >> m2;
  cout << " Введите значение: " << endl;
  cin >> z2;
  if ((n2>=1) && (m2>=1) &&  (z2>=1) &&  (z2<=n) &&  (n2<=n) &&  (m2<=n)) {
		  
	  for (int j=0; j<g[n2-1].size(); ++j) {
	  	if ((g[n2-1][j]+1)==m2) {
	  	    g[n2-1][j]=z2-1;	
		  }
	  }
	  
  	  cout << " Исправления внесены." << endl;
  } else {
  	 cout << " Исправления не внесены. Ошибка данных." << endl;
  }  
}

}



} // end while (редактирование графа)


if (choice1==1) {
   Preobr_MSM_SPSM();  // преобразование из матрицы смежности в список смежности
   // Print_SPSM();
}

if (choice1==2) {
   Preobr_MINC_SPSM();  // преобразование из матрицы иницидентности в список смежности
   // Print_SPSM();
}


// *** 3. вывод информации  о графе в любом из трех  видов 
//        ( также по  требованию пользователя ) на дисплей; **	
 
cout << "Вывод графа. 1) Вывести в виде матрицы смежности." << endl;
cout << "             2) Вывести в виде матрицы инцидентности." << endl;
cout << "             3) Вывести в виде списка смежности." << endl;
cout << " Ваш выбор: 1 2 или 3 ? " << endl;
cin >> choice;
if ((choice>3) || (choice<1)) {
	choice=1;
}

if ((choice==1) && (choice1!=1 )) {
	cout << "Введена не матрица смежности...Преобразуем." << endl;
   Preobr_SPSM_MSM();  // преобразование в матрицы смежности из списка смежности
   Print_MSM(); 
} else if ((choice==1)  && (choice1==1)) {
   Print_MSM(); 
}

if ((choice==2) && (choice1!=2 )) {
	cout << "Введена не матрица инцидентности...Преобразуем." << endl;
    Preobr_SPSM_MINC();  // преобразование в матрицу инцидентности из списка смежности
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
