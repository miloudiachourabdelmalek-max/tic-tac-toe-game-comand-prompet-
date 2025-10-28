#include <iostream>
#include <ctime>
#include <map>
#include <vector>


using namespace std;


void sum( int a[] , int m[][3]) {
int s=0 , s2 = 0 , k=0;
for(int i=0 ; i< 3 ; i++){
        s=0; s2=0;
   for(int j=0 ; j< 3 ; j++){

    s+=m[i][j];
    s2+=m[j][i];

 }
    a[k++]=s;
    a[k++]=s2;

}
s=0 ; s2=0;
for(int i=0 ; i < 3 ; i++) {

    s+=m[i][i];
    s2+=m[i][3-i-1];
}
a[k++]=s;
a[k++]=s2;

}




map <char , int > qwerty={

   {'Q',1},
   {'W',2},
   {'E',3},
   {'A',4},
   {'S',5},
   {'D',6},
   {'Z',7},
   {'X',8},
   {'C',9}

 };




map <char , int > azerty={


   {'A',1},
   {'Z',2},
   {'E',3},
   {'Q',4},
   {'S',5},
   {'D',6},
   {'W',7},
   {'X',8},
   {'C',9}

 };








int main()
{




srand(time(0));


vector <string> m;

int m2[][3]= { {9,9,9},
            {9,9,9},
            {9,9,9}};


            int a[8];


char c='X', c2='O';
int r=0,cl=0 , p ;
char pc;
  cout << "choose to play with X or O : " << endl;
 cin >> c;
 c=toupper(c);
while (c != 'X' && c!='O'){

    cout << "wrong char , enter again :" << endl;
    cin >> c;
    c=toupper(c);
}
int lang;
do{
        cout << "enter 1 for qwerty , 0 for azerty" << endl;
        cin >>lang;


}while(lang!=0 && lang!=1);


cout << "this is your table movments" <<endl;

if(lang){
m=   {      "      |      |       ",
                      "   Q  |   W  |   E   ",
                      "______|______|_______",
                      "      |      |       ",
                      "   A  |   S  |   D   ",
                      "______|______|_______",
                      "      |      |       ",
                      "   Z  |   X  |   C   ",
                      "      |      |       " } ; }
else {



   m =   {            "      |      |       ",
                      "   A  |   Z  |   E   ",
                      "______|______|_______",
                      "      |      |       ",
                      "   Q  |   S  |   D   ",
                      "______|______|_______",
                      "      |      |       ",
                      "   W  |   X  |   C   ",
                      "      |      |       " } ;



                      }


  for (int i = 0; i < 9; ++i) {
        cout << m[i] << endl;
    }





   m =   {            "      |      |       ",
                      "      |      |       ",
                      "______|______|_______",
                      "      |      |       ",
                      "      |      |       ",
                      "______|______|_______",
                      "      |      |       ",
                      "      |      |       ",
                      "      |      |       " } ;

c2 = (c == 'X') ? 'O' : 'X';
int j=0;
while (j < 9) {

newl:
do {
cout << "enter the position " << endl;
cout << "postion: " ;
cin >> pc ;
if (lang && qwerty.count(toupper(pc)))
    p = qwerty[toupper(pc)];
else if (!lang && azerty.count(toupper(pc)))
    p = azerty[toupper(pc)];
else
    p = 0;
} while(p==0);

cout << "p is :" << p <<endl;
p--;
r=p/3;
cl=p%3;

if(m2[r][cl]!=9) {

 cout << "position already taken , try again." << endl;
 goto newl;

}

m2[r][cl]=(c=='X') ? 1 : 0 ;

m[ r*3 + 1][cl +cl*6 + 3] =c ;
j++;
if(j<9) {

newl2:

    int rr = rand() % 3 ;
    int rc= rand() % 3 ;


   if(m2[rr][rc]!=9) {
    goto newl2;
   }

m2[rr][rc] = (c2 == 'X') ? 1 : 0;
m[ rr*3 + 1][rc +rc*6 + 3] =c2 ;
   cout << "\nthe computer has played in raw " << rr+1 << " and column " << rc+1 << endl;
}




    for (int i = 0; i < 9; ++i) {
        cout << m[i] << endl;
    }




sum( a , m2 ) ;



for (int i=0 ; i<8 ; i++) {

    if(a[i]==0) {
            if (c2=='O') {cout << "the winner is the computer ! " << endl ; goto endd;}
          else {cout << "the winner is you ! " << endl ; goto endd;}

    }
    else if (a[i]==3) {

         if (c2=='X') {cout << "the winner is the computer ! " << endl ; goto endd;}
          else {cout << "the winner is you ! " << endl ; goto endd;}


    }

}

j++;
 }



 cout << "there is a draw !" << endl;


 endd:
     return 0;
}
