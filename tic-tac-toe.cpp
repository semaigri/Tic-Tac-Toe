#include "iostream"
#include <random>
#include <stdlib.h>
#include <string.h>
using namespace std;

bool winFirstPossibility(string (&gameArray)[3][3]){
bool winning = false;
  int line;
     int column=0 ;
     int i = 0;
     int zero=0, first=1,second=2;
      while( i <= 9){
       if(gameArray[zero][zero]==gameArray[zero][first]){
            if(gameArray[zero][first]==gameArray[zero][second]){
                    if(gameArray[zero][first] != "?"){
                        winning = true;
                    }

            }
       }

       if(gameArray[first][zero]==gameArray[first][first]){
            if(gameArray[first][first]==gameArray[first][second]){
                 if(gameArray[first][first] != "?"){
                        winning = true;
                    }
            }
       }

        if(gameArray[second][zero]==gameArray[second][first]){
            if(gameArray[second][first]==gameArray[second][second]){
                if(gameArray[second][first] != "?"){
                        winning = true;
                    }
            }
       }
       i++;
   }
   return winning;
}

bool winSecondPossibility(string (&gameArray)[3][3]){
bool winning = false;
  int line;
     int column=0 ;
     int i = 0;
     int zero=0, first=1,second=2;
      while( i <= 9){
       if(gameArray[zero][zero]==gameArray[first][zero]){
            if(gameArray[first][zero]==gameArray[second][zero]){
                    if(gameArray[second][zero] != "?"){
                        winning = true;
                    }

            }
       }

       if(gameArray[zero][first]==gameArray[first][first]){
            if(gameArray[first][first]==gameArray[second][first]){
                 if(gameArray[first][first] != "?"){
                        winning = true;
                    }
            }
       }

        if(gameArray[zero][second]==gameArray[first][second]){
            if(gameArray[first][second]==gameArray[second][second]){
                if(gameArray[first][second] != "?"){
                        winning = true;
                    }
            }
       }

       i++;

   }
   return winning;
}



bool winThirdPossibility(string (&gameArray)[3][3]){
    bool winning = false;
 if(gameArray[0][0] == gameArray[1][1]){
    if(gameArray[1][1] == gameArray[2][2]){
        if(gameArray[2][2] != "?"){
            winning = true;
        }
    }
 }
  if(gameArray[0][2] == gameArray[1][1]){
    if(gameArray[1][1] == gameArray[2][0]){
        if(gameArray[2][0] != "?"){
            winning = true;
        }
    }
 }
 return winning;

}

bool win(string (&gameArray) [3][3]){
  bool a=winFirstPossibility(gameArray);
  bool b=winSecondPossibility(gameArray);
  bool c=winThirdPossibility(gameArray);
  bool winning=0;

   if((a or b ==1) or (c ==1)){

    winning = 1;
   }


return winning;

}

void moving2(string (&gameArray)[3][3]){
  //знает что это 0 игрок
  int lineCoordinate;
  int columnCoordinate;
    cout<<"Type the coordinate in XY format \n";
    cin>>lineCoordinate>>columnCoordinate;
     if((lineCoordinate >= 0)&& (lineCoordinate <= 3) && (columnCoordinate >= 0) && (columnCoordinate <= 3)){
       if(gameArray[lineCoordinate][columnCoordinate] == "?"){
       gameArray[lineCoordinate][columnCoordinate] = "X";
       }
       else{
        cout<<"The field is already taken\n";
        moving2(gameArray);
       }
     }

     else{
        cout<<"Incorrect number\n";
        moving2(gameArray);
     }



}

int moving1(string (&gameArray)[3][3]){
  //знает что это 0 игрок
  int lineCoordinate;
  int columnCoordinate;
    cout<<"Type the coordinate in XY format \n";
    cin>>lineCoordinate>>columnCoordinate;
     if((lineCoordinate >= 0)&& (lineCoordinate <= 3) && (columnCoordinate >= 0) && (columnCoordinate <= 3)){
       if(gameArray[lineCoordinate][columnCoordinate] == "?"){
       gameArray[lineCoordinate][columnCoordinate] = "0";
       }
       else{
        cout<<"The field is already taken\n";
        moving1(gameArray);
       }
     }

     else{
        cout<<"Incorrect number\n";
        moving1(gameArray);
     }



}


void welcome(){

    string gameArray[3][3]={"?","?","?","?","?","?","?","?","?"};


  cout<<"Hi! Welcome to tic-tao-toe game. Find a partner to play with.\n";
  cout<<"\n\n        [0]        [1]         [2]  \n";
  cout<<"    ------------------------------------"<<endl;
  cout<<"    |         |           |           |"<<endl;
  cout<<"    |         |           |           |"<<endl;
 cout<<"[0] |    "<<gameArray[0][0]<<"    |     "<<gameArray[0][1]<<"     |     "<<gameArray[0][2]<<"     |"<<endl;
  cout<<"    |         |           |           |"<<endl;
  cout<<"    |         |           |           |"<<endl;
  cout<<"    -----------------------------------"<<endl;
  cout<<"    |         |           |           |"<<endl;
  cout<<"    |         |           |           |"<<endl;
  cout<<"[1] |    "<<gameArray[1][0]<<"    |     "<<gameArray[1][1]<<"     |     "<<gameArray[1][2]<<"     |"<<endl;
  cout<<"    |         |           |           |"<<endl;
  cout<<"    |---------------------|-----------|"<<endl;
  cout<<"    |         |           |           |"<<endl;
  cout<<"    |         |           |           |"<<endl;
  cout<<"[2] |    "<<gameArray[2][0]<<"    |     "<<gameArray[2][1]<<"     |     "<<gameArray[2][2]<<"     |"<<endl;
  cout<<"    |         |           |           |"<<endl;
  cout<<"    |         |           |           |"<<endl;
  cout<<"    ----------------------------------|"<<endl;


}
int main()
 { //crosses and zeros for two players
     welcome();
    int input;
    bool winning=false;
    int counter=0;
    string gameArray[3][3]={"?","?","?","?","?","?","?","?","?"};
    cout<<"1st player is 0, second is X.\n";
    while(winning==false && counter < 9){
    if(counter %2 ==0){
    cout<<"1st player's move\n";
    moving1(gameArray);
    counter++;
    }
    else{
        cout<<"2nd player's move\n";
        moving2(gameArray);
    counter++;
    }
   winning = win(gameArray);
                          // <<"\033[31;10;1m"
                          //   "\033[0m"

  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                        [0]        [1]         [2]  \n";
  cout<<"\t\t  ------------------------------------"<<endl;
  cout<<"\t\t    |         |           |           |"<<endl;
  cout<<"\t\t    |         |           |           |"<<endl;
 cout<<"\t\t[0] |    "<<"\033[31;10;1m"<<gameArray[0][0]<<"\033[0m"<<"    |     "<<"\033[31;10;1m"<<gameArray[0][1]<<"\033[0m"<<"     |     "<<"\033[31;10;1m"<<gameArray[0][2]<<"\033[0m     |"<<endl;
  cout<<"\t\t    |         |           |           |"<<endl;
  cout<<"\t\t    |         |           |           |"<<endl;
  cout<<"\t\t    -----------------------------------"<<endl;
  cout<<"\t\t    |         |           |           |"<<endl;
  cout<<"\t\t    |         |           |           |"<<endl;
  cout<<"\t\t[1] |    "<<"\033[31;10;1m"<<gameArray[1][0]<<"\033[0m"<<"    |     "<<"\033[31;10;1m"<<gameArray[1][1]<<"\033[0m"<<"     |     "<<"\033[31;10;1m"<<gameArray[1][2]<<"\033[0m     |"<<endl;
  cout<<"\t\t    |         |           |           |"<<endl;
  cout<<"\t\t    |---------------------|-----------|"<<endl;
  cout<<"\t\t    |         |           |           |"<<endl;
  cout<<"\t\t    |         |           |           |"<<endl;
  cout<<"\t\t[2] |    "<<"\033[31;10;1m"<<gameArray[2][0]<<"\033[0m"<<"    |     "<<"\033[31;10;1m"<<gameArray[2][1]<<"\033[0m"<<"     |     "<<"\033[31;10;1m"<<gameArray[2][2]<<"\033[0m     |"<<endl;
  cout<<"\t\t    |         |           |           |"<<endl;
  cout<<"\t\t    |         |           |           |"<<endl;
  cout<<"\t\t    ----------------------------------|"<<endl;


     if(winning == 1){
        if(counter % 2 !=0){
            cout<<"\033[33;10;1mVICTORY!\nCongrats to the first player!!\033[0m\n";
        }
        else{
          cout<<"\033[33;10;1mVICTORY!\nCongrats to the second player!!\033[0m\n";
        }
   }
}
         if(counter == 9 && winning == false){
            cout<<"\033[31;10;1mDraw! Congrats to both of you!\033[0m\n";
         }

 }
