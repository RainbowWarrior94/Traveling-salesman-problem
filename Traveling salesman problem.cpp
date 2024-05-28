//Author: Anastasiya Kruhlik
#include <iostream>
#include <iomanip>

using namespace std;

const int n=16;

bool Exist(int *T, int n, int x);
void Nearest_Neighbor(int **G, int n, string *cities);

int main()
{char choise='y';
 string cities[n]=
      {"Bialystok", "Bydgoszcz", "Gdansk", "Gorzow W.", "Katowice", "Kielce", "Krakow",
       "Lodz", "Lublin", "Olsztyn", "Opole", "Poznan", "Rzeszow", "Szczecin", "Warszawa", "Wroclaw"};

 int D[n][n]=
  {//1  2   3   4   5   6   7   8   9  10  11  12   13  14  15  16
     0,410,405,654,500,367,487,319,249,227,511,501,424,757,201,545, //1
     410,0,174,217,416,358,482,209,434,214,369,130,516,260,267,276, //2
     405,174,0,335,530,472,584,330,510,163,542,302,630,362,343,463, //3
     654,217,335,0,469,518,543,344,631,430,371,136,676,103,464,269, //4
     500,416,530,469,0,159,78,203,350,481,101,355,248,577,293,197,  //5
     367,358,472,518,159,0,117,155,176,394,268,357,160,621,175,349, //6
     487,482,584,543,78,117,0,252,307,509,181,419,170,648,292,271,  //7
     319,209,330,344,203,155,252,0,261,291,218,202,315,446,137,210, //8
     249,434,510,631,350,176,307,261,0,382,460,467,182,714,177,451, //9
     227,214,163,430,481,394,509,291,382,0,502,329,523,474,219,517, //10
     511,369,542,371,101,268,181,218,460,502,0,286,359,475,318,87,  //11
     501,130,302,136,355,357,419,202,467,329,286,0,628,241,312,169, //12
     424,516,630,676,248,160,170,315,182,523,359,628,0,816,300,438, //13
     757,260,362,103,577,621,648,446,714,474,475,241,816,0,563,395, //14
     201,267,343,464,293,175,292,137,177,219,318,312,300,563,0,356, //15
     545,276,463,269,197,349,271,210,451,517,87,169,438,395,356,0}; //16

 int **M=new int*[n];

      for (int i=0; i<n; i++) M[i]=D[i];

    cout<<"Author: Anastasiya Kruhlik "<<endl;
    cout<<endl;
    cout<<"    =============================================="<<endl;
    cout<<"    ||Solution to the traveling salesman problem||"<<endl;
    cout<<"    =============================================="<<endl;
    cout<<endl;
    cout<<"All 16 voivodship cities in Poland, sorted alphabetically and numbered from 1 to 16: "<<endl;
      for(int i=1;i<=n;i++) {cout<<i<<"-"<<cities[i-1]<<endl;}
    cout<<endl;

    cout<<"The matrix of the shortest road distance between cities:"<<endl;
    cout<<"  |";
      for(int i=1;i<=n;i++) {cout<<setw(7)<<i;}
    cout<<endl;
      for(int i=1;i<n;i++) {cout<<"--------";}
    cout<<endl;

      for(int i=0; i<n; i++)
         {cout<<setw(2)<<i+1<<"|";
           for(int j=0; j<n; j++) {cout<<setw(7)<<D[i][j];}
          cout<<endl;}
    cout<<endl;

  do
  {Nearest_Neighbor(M, n, cities);
   cout<<endl;
   cout<<"Do you want to choose a different starting point? (y/n): ";
   cin>>choise;
   cout<<endl;}
  while (choise=='y');

   return 0;
}

bool Exist(int *T, int n, int x)                                 //a function that is responsible for ensuring that a route passes through an x-city only once

    {for (int j=0; j<n; j++) if (T[j]==x) return true;
     return false;}

void Nearest_Neighbor(int **D, int n, string *cities)            //a function that implements the nearest neighbor algorithm 

    {int start_2, start, s, L=0;
     int *T=new int[n];                                          //memory allocation for the dynamic array
     char choise='Y';

      for (int i=0; i<n; i++) T[i]=-1;                           //a one-dimensional dynamic array is created and filled with the value "-1"  

    cout<<"Select a starting point: ";
    cin>>start;
    cout<<"Selected city: "<<start<<"-"<<cities[start-1]<<endl;
    cout<<endl;

     s=start-1;
     start_2=s;

     D[s][s]=0;

      for (int j=0; j<n; j++)                                    //going through each j-row of the matrix 
         {int min; bool first=true;

          T[j]=s;
        for (int i=0; i<n; i++)                                  //going through each i-element of the j-row of the matrix
           {if (Exist(T,n,i)==false)                             //check if the road ran through the i-city
              {if (first==true) {min=i; first=false;}
               if (D[s][min]>D[s][i] && j!=n-1) min=i;}}         //search for a minimal i-element

        if (j!=n) s=min;}

     T[n]=start_2;

    cout<<"Vector T=[";
      for (int i=0; i<n-1; i++) {cout<<D[T[i]][ T[i+1]]<<", "; L+=D[T[i]][ T[i+1]];}
    cout<<D[T[n-1]][ T[n]]<<"]"<<endl; L+=D[T[n-1]][ T[n]];
    cout<<endl;
    cout<<"Total length L: "<<L<<" km"<<endl;
    cout<<endl;
    cout<<"Order of cities visited  T=[";
      for (int i=0; i<n; i++) {cout<<T[i]+1<<", "; L+=D[T[i]][ T[i+1]];}
    cout<<T[n]+1<<"]"<<endl;
    cout<<endl;
    cout<<"Show details? (Y/N) ";
    cin>>choise;
     if (choise=='Y')
     { for (int i=0; i<n; i++)
         {cout<<"From "<<cities[T[i]]<<" to "<<cities[T[i+1]]<<" = "<<D[T[i]][ T[i+1]]<<" km"<<endl;}}

    delete[] T;                                                  //memory deallocation from a dynamic array
}

