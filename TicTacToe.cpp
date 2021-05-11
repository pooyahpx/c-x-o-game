/*--------
//This Program written by POYA
visit us at:
discord:POYA#2243
--------------*/
#include<iostream>
#include<conio.h>
#define TABSIZE 150
using namespace std;


bool isEmpty(char **a , int column , int row)
{
     if(a[column][row]=='-')
     {
          return true;
     }
     else
     {
          return false;
     }
}

int *chooseEasy(char **a)
{
    int * comch=new int[2];
    int i=0 , j=0;
    for(i=1 ; i<3 ; i++)
    {
            for( j=1 ; j<3 ; j++ )
            {
                 if(isEmpty(a,(2*i)+1,(j*4)+2)==true)
                 {
                                  comch[0]=(2*i)+1;
                                  comch[1]=(4*j)+2;
                 }
            }
    }
    /*chs:
    i=rand()%3+1;
    j=rand()%3+1;
    if(isEmpty(a,(2*i)+1,(j*4)+2)==false)
    {
           goto chs;
    }*/
    return comch;
}

int *choose(char **a )
{
         int * comch=new int[2];
         if ( a[3][6]=='X' && a[3][10]=='X' && isEmpty(a,3,14)==true)
         {
              comch[0]=3;
              comch[1]=14;
         }
         else if ( a[3][10]=='X' && a[3][14]=='X' && isEmpty(a,3,6)==true)
         {
              comch[0]=3;
              comch[1]=6;
         }
         else if ( a[3][6]=='X' && a[3][14]=='X' && isEmpty(a,3,10)==true)
         {
              comch[0]=3;
              comch[1]=10;
         }
         else if ( a[5][6]=='X' && a[5][10]=='X' && isEmpty(a,5,14)==true)
         {
              comch[0]=5;
              comch[1]=14;
         }
         else if ( a[5][14]=='X' && a[5][6]=='X' && isEmpty(a,5,10)==true)
         {
              comch[0]=5;
              comch[1]=10;
         }
         else if ( a[5][10]=='X' && a[5][14]=='X' && isEmpty(a,5,6)==true)
         {
              comch[0]=5;
              comch[1]=6;
         }
         else if ( a[7][6]=='X' && a[7][10]=='X' && isEmpty(a,7,14)==true)
         {
              comch[0]=7;
              comch[1]=14;
         }
         else if ( a[7][6]=='X' && a[7][14]=='X' && isEmpty(a,7,10)==true)
         {
              comch[0]=7;
              comch[1]=10;
         }
         else if ( a[7][14]=='X' && a[7][10]=='X' && isEmpty(a,7,6)==true)
         {
              comch[0]=7;
              comch[1]=6;
         }
         else if ( a[3][6]=='X' && a[5][6]=='X' && isEmpty(a,7,6)==true)
         {
              comch[0]=7;
              comch[1]=6;
         }
         else if ( a[3][10]=='X' && a[5][10]=='X' && isEmpty(a,7,10)==true)
         {
              comch[0]=7;
              comch[1]=10;
         }
         else if ( a[3][14]=='X' && a[5][14]=='X' && isEmpty(a,7,14)==true)
         {
              comch[0]=7;
              comch[1]=14;
         }
         else if ( a[3][10]=='X' && a[7][10]=='X' && isEmpty(a,5,10)==true)
         {
              comch[0]=5;
              comch[1]=10;
         }
         else if ( a[3][6]=='X' && a[7][6]=='X' && isEmpty(a,5,6)==true)
         {
              comch[0]=5;
              comch[1]=6;
         }
         else if ( a[3][14]=='X' && a[7][14]=='X' && isEmpty(a,5,14)==true)
         {
              comch[0]=5;
              comch[1]=14;
         }
         else if ( a[7][6]=='X' && a[5][6]=='X' && isEmpty(a,3,6)==true)
         {
              comch[0]=3;
              comch[1]=6;
         }
         else if ( a[7][10]=='X' && a[5][10]=='X' && isEmpty(a,3,10)==true)
         {
              comch[0]=3;
              comch[1]=10;
         }
         else if ( a[7][14]=='X' && a[5][14]=='X' && isEmpty(a,3,14)==true)
         {
              comch[0]=3;
              comch[1]=14;
         }
         else if ( a[3][6]=='X' && a[5][10]=='X' && isEmpty(a,7,14)==true)
         {
              comch[0]=7;
              comch[1]=14;
         }
         else if ( a[3][6]=='X' && a[7][14]=='X' && isEmpty(a,5,10)==true)
         {
              comch[0]=5;
              comch[1]=10;
         }
         else if ( a[5][10]=='X' && a[7][14]=='X' && isEmpty(a,3,6)==true)
         {
              comch[0]=3;
              comch[1]=6;
         }
         else if ( a[3][14]=='X' && a[5][10]=='X' && isEmpty(a,7,6)==true)
         {
              comch[0]=7;
              comch[1]=6;
         }
         else if ( a[3][14]=='X' && a[7][6]=='X' && isEmpty(a,5,10)==true)
         {
              comch[0]=5;
              comch[1]=10;
         }
         else if ( a[7][6]=='X' && a[5][10]=='X' && isEmpty(a,3,14)==true)
         {
              comch[0]=3;
              comch[1]=14;
         }
         else if ( a[5][10]=='X')
         {
              if(isEmpty(a,3,6)==true)
              {
                   comch[0]=3;
                   comch[1]=6;
              }
              else if(isEmpty(a,7,6)==true)
              {
                   comch[0]=7;
                   comch[1]=6;
              }
              else if(isEmpty(a,7,14)==true)
              {
                   comch[0]=7;
                   comch[1]=14;
              }
              else if(isEmpty(a,3,14)==true)
              {
                   comch[0]=3;
                   comch[1]=14;
              }
         }
         else if (isEmpty(a,5,10)==true)
         {
              comch[0]=5;
              comch[1]=10;
         }
         else
         {
             for(int i=1;i<3;i++)
             {
                     for(int j=1;j<3;j++)
                     {
                             if(isEmpty(a,(i*2)+1,(j*4)+2)==true)
                             {
                                                     comch[0]=(i*2)+1;
                                                     comch[1]=(j*4)+2;
                             }
                     }
             }
        }
         return comch;
}

int *chooseHard(char **a )
{
         int * comch=new int[2];
         
         if ( a[3][6]=='O' && a[3][10]=='O' && isEmpty(a,3,14)==true)
         {
              comch[0]=3;
              comch[1]=14;
         }
         else if ( a[3][10]=='O' && a[3][14]=='O' && isEmpty(a,3,6)==true)
         {
              comch[0]=3;
              comch[1]=6;
         }
         else if ( a[3][6]=='O' && a[3][14]=='O' && isEmpty(a,3,10)==true)
         {
              comch[0]=3;
              comch[1]=10;
         }
         else if ( a[5][6]=='O' && a[5][10]=='O' && isEmpty(a,5,14)==true)
         {
              comch[0]=5;
              comch[1]=14;
         }
         else if ( a[5][14]=='O' && a[5][6]=='O' && isEmpty(a,5,10)==true)
         {
              comch[0]=5;
              comch[1]=10;
         }
         else if ( a[5][10]=='O' && a[5][14]=='O' && isEmpty(a,5,6)==true)
         {
              comch[0]=5;
              comch[1]=6;
         }
         else if ( a[7][6]=='O' && a[7][10]=='O' && isEmpty(a,7,14)==true)
         {
              comch[0]=7;
              comch[1]=14;
         }
         else if ( a[7][6]=='O' && a[7][14]=='O' && isEmpty(a,7,10)==true)
         {
              comch[0]=7;
              comch[1]=10;
         }
         else if ( a[7][14]=='O' && a[7][10]=='O' && isEmpty(a,7,6)==true)
         {
              comch[0]=7;
              comch[1]=6;
         }
         else if ( a[3][6]=='O' && a[5][6]=='O' && isEmpty(a,7,6)==true)
         {
              comch[0]=7;
              comch[1]=6;
         }
         else if ( a[3][10]=='O' && a[5][10]=='O' && isEmpty(a,7,10)==true)
         {
              comch[0]=7;
              comch[1]=10;
         }
         else if ( a[3][14]=='O' && a[5][14]=='O' && isEmpty(a,7,14)==true)
         {
              comch[0]=7;
              comch[1]=14;
         }
         else if ( a[3][10]=='O' && a[7][10]=='O' && isEmpty(a,5,10)==true)
         {
              comch[0]=5;
              comch[1]=10;
         }
         else if ( a[3][6]=='O' && a[7][6]=='O' && isEmpty(a,5,6)==true)
         {
              comch[0]=5;
              comch[1]=6;
         }
         else if ( a[3][14]=='O' && a[7][14]=='O' && isEmpty(a,5,14)==true)
         {
              comch[0]=5;
              comch[1]=14;
         }
         else if ( a[7][6]=='O' && a[5][6]=='O' && isEmpty(a,3,6)==true)
         {
              comch[0]=3;
              comch[1]=6;
         }
         else if ( a[7][10]=='O' && a[5][10]=='O' && isEmpty(a,3,10)==true)
         {
              comch[0]=3;
              comch[1]=10;
         }
         else if ( a[7][14]=='O' && a[5][14]=='O' && isEmpty(a,3,14)==true)
         {
              comch[0]=3;
              comch[1]=14;
         }
         else if ( a[3][6]=='X' && a[3][10]=='X' && isEmpty(a,3,14)==true)
         {
              comch[0]=3;
              comch[1]=14;
         }
         else if ( a[3][10]=='X' && a[3][14]=='X' && isEmpty(a,3,6)==true)
         {
              comch[0]=3;
              comch[1]=6;
         }
         else if ( a[3][6]=='X' && a[3][14]=='X' && isEmpty(a,3,10)==true)
         {
              comch[0]=3;
              comch[1]=10;
         }
         else if ( a[5][6]=='X' && a[5][10]=='X' && isEmpty(a,5,14)==true)
         {
              comch[0]=5;
              comch[1]=14;
         }
         else if ( a[5][14]=='X' && a[5][6]=='X' && isEmpty(a,5,10)==true)
         {
              comch[0]=5;
              comch[1]=10;
         }
         else if ( a[5][10]=='X' && a[5][14]=='X' && isEmpty(a,5,6)==true)
         {
              comch[0]=5;
              comch[1]=6;
         }
         else if ( a[7][6]=='X' && a[7][10]=='X' && isEmpty(a,7,14)==true)
         {
              comch[0]=7;
              comch[1]=14;
         }
         else if ( a[7][6]=='X' && a[7][14]=='X' && isEmpty(a,7,10)==true)
         {
              comch[0]=7;
              comch[1]=10;
         }
         else if ( a[7][14]=='X' && a[7][10]=='X' && isEmpty(a,7,6)==true)
         {
              comch[0]=7;
              comch[1]=6;
         }
         else if ( a[3][6]=='X' && a[5][6]=='X' && isEmpty(a,7,6)==true)
         {
              comch[0]=7;
              comch[1]=6;
         }
         else if ( a[3][10]=='X' && a[5][10]=='X' && isEmpty(a,7,10)==true)
         {
              comch[0]=7;
              comch[1]=10;
         }
         else if ( a[3][14]=='X' && a[5][14]=='X' && isEmpty(a,7,14)==true)
         {
              comch[0]=7;
              comch[1]=14;
         }
         else if ( a[3][10]=='X' && a[7][10]=='X' && isEmpty(a,5,10)==true)
         {
              comch[0]=5;
              comch[1]=10;
         }
         else if ( a[3][6]=='X' && a[7][6]=='X' && isEmpty(a,5,6)==true)
         {
              comch[0]=5;
              comch[1]=6;
         }
         else if ( a[3][14]=='X' && a[7][14]=='X' && isEmpty(a,5,14)==true)
         {
              comch[0]=5;
              comch[1]=14;
         }
         else if ( a[7][6]=='X' && a[5][6]=='X' && isEmpty(a,3,6)==true)
         {
              comch[0]=3;
              comch[1]=6;
         }
         else if ( a[7][10]=='X' && a[5][10]=='X' && isEmpty(a,3,10)==true)
         {
              comch[0]=3;
              comch[1]=10;
         }
         else if ( a[7][14]=='X' && a[5][14]=='X' && isEmpty(a,3,14)==true)
         {
              comch[0]=3;
              comch[1]=14;
         }
         else if ( a[3][6]=='X' && a[5][10]=='X' && isEmpty(a,7,14)==true)
         {
              comch[0]=7;
              comch[1]=14;
         }
         else if ( a[3][6]=='X' && a[7][14]=='X' && isEmpty(a,5,10)==true)
         {
              comch[0]=5;
              comch[1]=10;
         }
         else if ( a[5][10]=='X' && a[7][14]=='X' && isEmpty(a,3,6)==true)
         {
              comch[0]=3;
              comch[1]=6;
         }
         else if ( a[3][14]=='X' && a[5][10]=='X' && isEmpty(a,7,6)==true)
         {
              comch[0]=7;
              comch[1]=6;
         }
         else if ( a[3][14]=='X' && a[7][6]=='X' && isEmpty(a,5,10)==true)
         {
              comch[0]=5;
              comch[1]=10;
         }
         else if ( a[7][6]=='X' && a[5][10]=='X' && isEmpty(a,3,14)==true)
         {
              comch[0]=3;
              comch[1]=14;
         }
         else if ( a[5][10]=='X')
         {
              if(isEmpty(a,3,6)==true)
              {
                   comch[0]=3;
                   comch[1]=6;
              }
              else if(isEmpty(a,7,6)==true)
              {
                   comch[0]=7;
                   comch[1]=6;
              }
              else if(isEmpty(a,7,14)==true)
              {
                   comch[0]=7;
                   comch[1]=14;
              }
              else if(isEmpty(a,3,14)==true)
              {
                   comch[0]=3;
                   comch[1]=14;
              }
         }
         else if (isEmpty(a,5,10)==true)
         {
              comch[0]=5;
              comch[1]=10;
         }
         else
         {
             for(int i=1;i<3;i++)
             {
                     for(int j=1;j<3;j++)
                     {
                             if(isEmpty(a,(i*2)+1,(j*4)+2)==true)
                             {
                                                     comch[0]=(i*2)+1;
                                                     comch[1]=(j*4)+2;
                             }
                     }
             }
        }
         return comch;
}

void printBoard(char** a)
{
     for(int i=0;i<9;i++)
     {
             for(int j=0;j<17;j++)
             {
                     cout<<a[i][j];
             }
             cout<<endl;
     }
}


int checkWin(char** a)
{
    if(a[3][6]==a[5][6] && a[5][6]==a[7][6])
    {
                        if(a[3][6]=='X')
                         {
                                         return 1;
                         }
                         else if(a[3][6]=='O')
                         {
                              return 2;
                         }
    }
    if(a[3][10]==a[5][10] && a[5][10]==a[7][10])
    {
                        if(a[3][10]=='X')
                         {
                                         return 1;
                         }
                         else if(a[3][10]=='O')
                         {
                              return 2;
                         }
    }
    if(a[3][14]==a[5][14] && a[5][14]==a[7][14])
    {
                        if(a[3][14]=='X')
                         {
                                         return 1;
                         }
                         else if(a[3][14]=='O')
                         {
                              return 2;
                         }
    }
    if(a[3][6]==a[3][10] && a[3][10]==a[3][14])
    {
                         if(a[3][6]=='X')
                         {
                                         return 1;
                         }
                         else if(a[3][6]=='O')
                         {
                              return 2;
                         }
    }
    if(a[5][6]==a[5][10] && a[5][10]==a[5][14])
    {
                         if(a[5][6]=='X')
                         {
                                         return 1;
                         }
                         else if(a[5][6]=='O')
                         {
                              return 2;
                         }
    }
    if(a[7][6]==a[7][10] && a[7][10]==a[7][14])
    {
                         if(a[7][6]=='X')
                         {
                                         return 1;
                         }
                         else if(a[7][6]=='O')
                         {
                              return 2;
                         }
    }
    if(a[3][6]==a[5][10] && a[5][10]==a[7][14])
    {
                         if(a[3][6]=='X')
                         {
                                         return 1;
                         }
                         else if(a[3][6]=='O')
                         {
                              return 2;
                         }
    }
    if(a[7][6]==a[5][10] && a[5][10]==a[3][14])
    {
                         if(a[7][6]=='X')
                         {
                                         return 1;
                         }
                         else if(a[7][6]=='O')
                         {
                              return 2;
                         }
    }
    if((a[3][6]=='X' || a[3][6]=='O') && (a[3][10]=='X' || a[3][10]=='O') && (a[3][14]=='X' || a[3][14]=='O') && (a[5][6]=='X' || a[5][6]=='O') && (a[5][10]=='X' || a[5][10]=='O') && (a[5][14]=='X' || a[5][14]=='O') && (a[7][6]=='X' || a[7][6]=='O') && (a[7][10]=='X' || a[7][10]=='O') && (a[7][14]=='X' || a[7][14]=='O'))
    {
                     return 3;
    }
    return 0;
}

void errorReport(int p)
{
     if(p==0)
     {
      cout<<"You havo to choose bewtween these numbers: 1 , 2 , 3"<<endl;
     }
     if(p==1)
     {
      cout<<"This space has been already choosed!! "<<endl;
     }
}

int main()
{
    system("color 0A");
    int k=0;
    int t=0;
    char difficulty='0';
    int numberOfPlayers=2;
    cout<<"Welcome to S*S TicTacToe"<<endl;
    cout<<"Press any key to play..."<<endl;
    getch();
    replay:
    system("CLS");
    cout<<"Enter number of players:\n";
    cout<<"( 1:Against computer \t 2:Two Players \t   oth:Exit )"<<endl;
    char np=getche();
    system("CLS");
    if(np=='2')
    {
    char ans='n';
    char win='n';
    char **a=new char*[9];
    for(int i=0;i<9;i++)
    {
            a[i]=new char[17];
    }
    win='n';
    ans='n';
    a[0][0]=char(201);
    a[0][1]=char(205);
    a[0][2]=char(205);
    a[0][3]=char(205);
    a[0][4]=char(209);
    a[0][5]=char(205);
    a[0][6]=char(205);
    a[0][7]=char(205);
    a[0][8]=char(209);
    a[0][9]=char(205);
    a[0][10]=char(205);
    a[0][11]=char(205);
    a[0][12]=char(209);
    a[0][13]=char(205);
    a[0][14]=char(205);
    a[0][15]=char(205);
    a[0][16]=char(187);
    a[1][0]=char(186);
    a[1][1]=' ';
    a[1][2]='*';
    a[1][3]=' ';
    a[1][4]=char(179);
    a[1][5]=' ';
    a[1][6]='1';
    a[1][7]=' ';
    a[1][8]=char(179);
    a[1][9]=' ';
    a[1][10]='2';
    a[1][11]=' ';
    a[1][12]=char(179);
    a[1][13]=' ';
    a[1][14]='3';
    a[1][15]=' ';
    a[1][16]=char(186);
    a[2][0]=char(204);
    a[2][1]=char(205);
    a[2][2]=char(205);
    a[2][3]=char(205);
    a[2][4]=char(216);
    a[2][5]=char(205);
    a[2][6]=char(205);
    a[2][7]=char(205);
    a[2][8]=char(216);
    a[2][9]=char(205);
    a[2][10]=char(205);
    a[2][11]=char(205);
    a[2][12]=char(216);
    a[2][13]=char(205);
    a[2][14]=char(205);
    a[2][15]=char(205);
    a[2][16]=char(185);
    a[3][0]=char(186);
    a[3][1]=' ';
    a[3][2]='1';
    a[3][3]=' ';
    a[3][4]=char(179);
    a[3][5]=' ';
    a[3][6]='-';
    a[3][7]=' ';
    a[3][8]=char(179);
    a[3][9]=' ';
    a[3][10]='-';
    a[3][11]=' ';
    a[3][12]=char(179);
    a[3][13]=' ';
    a[3][14]='-';
    a[3][15]=' ';
    a[3][16]=char(186);
        
    a[4][0]=char(204);
    a[4][1]=char(205);
    a[4][2]=char(205);
    a[4][3]=char(205);
    a[4][4]=char(216);
    a[4][5]=char(205);
    a[4][6]=char(205);
    a[4][7]=char(205);
    a[4][8]=char(216);
    a[4][9]=char(205);
    a[4][10]=char(205);
    a[4][11]=char(205);
    a[4][12]=char(216);
    a[4][13]=char(205);
    a[4][14]=char(205);
    a[4][15]=char(205);
    a[4][16]=char(185);
    a[5][0]=char(186);
    a[5][1]=' ';
    a[5][2]='2';
    a[5][3]=' ';
    a[5][4]=char(179);
    a[5][5]=' ';
    a[5][6]='-';
    a[5][7]=' ';
    a[5][8]=char(179);
    a[5][9]=' ';
    a[5][10]='-';
    a[5][11]=' ';
    a[5][12]=char(179);
    a[5][13]=' ';
    a[5][14]='-';
    a[5][15]=' ';
    a[5][16]=char(186);
    
    a[6][0]=char(204);
    a[6][1]=char(205);
    a[6][2]=char(205);
    a[6][3]=char(205);
    a[6][4]=char(216);
    a[6][5]=char(205);
    a[6][6]=char(205);
    a[6][7]=char(205);
    a[6][8]=char(216);
    a[6][9]=char(205);
    a[6][10]=char(205);
    a[6][11]=char(205);
    a[6][12]=char(216);
    a[6][13]=char(205);
    a[6][14]=char(205);
    a[6][15]=char(205);
    a[6][16]=char(185);
    a[7][0]=char(186);
    a[7][1]=' ';
    a[7][2]='3';
    a[7][3]=' ';
    a[7][4]=char(179);
    a[7][5]=' ';
    a[7][6]='-';
    a[7][7]=' ';
    a[7][8]=char(179);
    a[7][9]=' ';
    a[7][10]='-';
    a[7][11]=' ';
    a[7][12]=char(179);
    a[7][13]=' ';
    a[7][14]='-';
    a[7][15]=' ';
    a[7][16]=char(186);
        
    a[8][0]=char(200);
    a[8][1]=char(205);
    a[8][2]=char(205);
    a[8][3]=char(205);
    a[8][4]=char(207);
    a[8][5]=char(205);
    a[8][6]=char(205);
    a[8][7]=char(205);
    a[8][8]=char(207);
    a[8][9]=char(205);
    a[8][10]=char(205);
    a[8][11]=char(205);
    a[8][12]=char(207);
    a[8][13]=char(205);
    a[8][14]=char(205);
    a[8][15]=char(205);
    a[8][16]=char(188);
    int player=1;
    while(win!='y')
    {
                   mainBoard:
                   system("cls");
                   printBoard(a);
                   if(player==1)
                   {
                   system("color 0B");
                   cout<<"Pleyer 1:"<<endl;
                   cout<<"Enter your choose"<<endl;
                   cout<<"Row:";
                   cin>>k;
                   cout<<"Column:";
                   cin>>t;
                   if(k>3 || k<1 || t>3 || t<1)
                   {
                          errorReport(0);
                          getch();
                          goto mainBoard;
                   }
                   else
                   {
                       if(a[(k*2)+1][(4*t)+2]=='-')
                       {
                        a[(k*2)+1][(t*4)+2]='X';
                       }
                       else
                       {
                           errorReport(1);
                           getch();
                           goto mainBoard;
                       }
                   }
                   player=2;
                   }
                   else
                   {
                   system("color 0C");
                   cout<<"Pleyer 2:"<<endl;
                   cout<<"Enter your choose"<<endl;
                   cout<<"Row:";
                   cin>>k;
                   cout<<"Column:";
                   cin>>t;
                   if(k>3 || k<1 || t>3 || t<1)
                   {
                          errorReport(0);
                          getch();
                          goto mainBoard;
                   }
                   else
                   {
                       if(a[(k*2)+1][(4*t)+2]=='-')
                       {
                        a[(k*2)+1][(4*t)+2]='O';
                       }
                       else
                       {
                           errorReport(1);
                           getch();
                           goto mainBoard;
                       }
                   }
                   player=1;
                   }
                   if(checkWin(a)==1)
                   {
                                     system("cls");
                                     system("color 0A");
                                     win='y';
                                     cout<<"Player 1 won!!!!!"<<endl;
                   }
                   else if(checkWin(a)==2)
                   {
                                     system("cls");
                                     system("color 0A");
                                     win='y';
                                     cout<<"Player 2 won!!!!!"<<endl;
                   }
                   else if(checkWin(a)==3)
                   {
                                     system("cls");
                                     system("color 0A");
                                     win='y';
                                     cout<<"Cat's play"<<endl;
                   }
    }
    printBoard(a);
    cout<<endl;
    Ask:
    cout<<"Do you want to play again?(y/n)"<<endl;
    cin>>ans;
    if(ans=='y')
    {
                goto replay;
    }
    else if(ans !='n')
    {
         cout<<"you have to enter 'y' or 'n'\nPress any key..."<<endl;
         getch();
         goto Ask;
    }
    system("cls");
    cout<<"Thenk you for playing this game"<<endl;
    cout<<"By: Cpp Programmers "<<endl;
    cout<<"http://cppcenter.blogfa.com"<<endl;
    getch();
    return 0;
    }
    else if(np=='1')
    {
    AskDifficulty:
    cout<<"Choose the difficulty:\n1.Easy\n2.Normal\n3.Hard"<<endl;
    cin>>difficulty;
    
    if(difficulty!='1' && difficulty!='2' && difficulty!='3')
    {
                     cout<<"You must choose between these numbers : 1 , 2 & 3"<<endl;
                     getch();
                     system("CLS");
                     goto AskDifficulty; 
    }
    char ans='n';
    char win='n';
    char **a=new char*[9];
    for(int i=0;i<9;i++)
    {
            a[i]=new char[17];
    }
    win='n';
    ans='n';
    a[0][0]=char(201);
    a[0][1]=char(205);
    a[0][2]=char(205);
    a[0][3]=char(205);
    a[0][4]=char(209);
    a[0][5]=char(205);
    a[0][6]=char(205);
    a[0][7]=char(205);
    a[0][8]=char(209);
    a[0][9]=char(205);
    a[0][10]=char(205);
    a[0][11]=char(205);
    a[0][12]=char(209);
    a[0][13]=char(205);
    a[0][14]=char(205);
    a[0][15]=char(205);
    a[0][16]=char(187);
    a[1][0]=char(186);
    a[1][1]=' ';
    a[1][2]='*';
    a[1][3]=' ';
    a[1][4]=char(179);
    a[1][5]=' ';
    a[1][6]='1';
    a[1][7]=' ';
    a[1][8]=char(179);
    a[1][9]=' ';
    a[1][10]='2';
    a[1][11]=' ';
    a[1][12]=char(179);
    a[1][13]=' ';
    a[1][14]='3';
    a[1][15]=' ';
    a[1][16]=char(186);
    a[2][0]=char(204);
    a[2][1]=char(205);
    a[2][2]=char(205);
    a[2][3]=char(205);
    a[2][4]=char(216);
    a[2][5]=char(205);
    a[2][6]=char(205);
    a[2][7]=char(205);
    a[2][8]=char(216);
    a[2][9]=char(205);
    a[2][10]=char(205);
    a[2][11]=char(205);
    a[2][12]=char(216);
    a[2][13]=char(205);
    a[2][14]=char(205);
    a[2][15]=char(205);
    a[2][16]=char(185);
    a[3][0]=char(186);
    a[3][1]=' ';
    a[3][2]='1';
    a[3][3]=' ';
    a[3][4]=char(179);
    a[3][5]=' ';
    a[3][6]='-';
    a[3][7]=' ';
    a[3][8]=char(179);
    a[3][9]=' ';
    a[3][10]='-';
    a[3][11]=' ';
    a[3][12]=char(179);
    a[3][13]=' ';
    a[3][14]='-';
    a[3][15]=' ';
    a[3][16]=char(186);
        
    a[4][0]=char(204);
    a[4][1]=char(205);
    a[4][2]=char(205);
    a[4][3]=char(205);
    a[4][4]=char(216);
    a[4][5]=char(205);
    a[4][6]=char(205);
    a[4][7]=char(205);
    a[4][8]=char(216);
    a[4][9]=char(205);
    a[4][10]=char(205);
    a[4][11]=char(205);
    a[4][12]=char(216);
    a[4][13]=char(205);
    a[4][14]=char(205);
    a[4][15]=char(205);
    a[4][16]=char(185);
    a[5][0]=char(186);
    a[5][1]=' ';
    a[5][2]='2';
    a[5][3]=' ';
    a[5][4]=char(179);
    a[5][5]=' ';
    a[5][6]='-';
    a[5][7]=' ';
    a[5][8]=char(179);
    a[5][9]=' ';
    a[5][10]='-';
    a[5][11]=' ';
    a[5][12]=char(179);
    a[5][13]=' ';
    a[5][14]='-';
    a[5][15]=' ';
    a[5][16]=char(186);
    
    a[6][0]=char(204);
    a[6][1]=char(205);
    a[6][2]=char(205);
    a[6][3]=char(205);
    a[6][4]=char(216);
    a[6][5]=char(205);
    a[6][6]=char(205);
    a[6][7]=char(205);
    a[6][8]=char(216);
    a[6][9]=char(205);
    a[6][10]=char(205);
    a[6][11]=char(205);
    a[6][12]=char(216);
    a[6][13]=char(205);
    a[6][14]=char(205);
    a[6][15]=char(205);
    a[6][16]=char(185);
    a[7][0]=char(186);
    a[7][1]=' ';
    a[7][2]='3';
    a[7][3]=' ';
    a[7][4]=char(179);
    a[7][5]=' ';
    a[7][6]='-';
    a[7][7]=' ';
    a[7][8]=char(179);
    a[7][9]=' ';
    a[7][10]='-';
    a[7][11]=' ';
    a[7][12]=char(179);
    a[7][13]=' ';
    a[7][14]='-';
    a[7][15]=' ';
    a[7][16]=char(186);
        
    a[8][0]=char(200);
    a[8][1]=char(205);
    a[8][2]=char(205);
    a[8][3]=char(205);
    a[8][4]=char(207);
    a[8][5]=char(205);
    a[8][6]=char(205);
    a[8][7]=char(205);
    a[8][8]=char(207);
    a[8][9]=char(205);
    a[8][10]=char(205);
    a[8][11]=char(205);
    a[8][12]=char(207);
    a[8][13]=char(205);
    a[8][14]=char(205);
    a[8][15]=char(205);
    a[8][16]=char(188);
    int player=1;
    while(win!='y')
    {
                   mainBoard2:
                   system("cls");
                   printBoard(a);
                   if(player==1)
                   {
                   system("color 0B");
                   cout<<"Pleyer 1:"<<endl;
                   cout<<"Enter your choose"<<endl;
                   cout<<"Row:";
                   cin>>k;
                   cout<<"Column:";
                   cin>>t;
                   if(k>3 || k<1 || t>3 || t<1)
                   {
                          errorReport(0);
                          getch();
                          goto mainBoard2;
                   }
                   else
                   {
                       if(a[(k*2)+1][(4*t)+2]=='-')
                       {
                        a[(k*2)+1][(t*4)+2]='X';
                       }
                       else
                       {
                           errorReport(1);
                           getch();
                           goto mainBoard2;
                       }
                   }
                   player=2;
                   }
                   else
                   {
                       
                            system("color 0C");
                            cout<<"Computer :"<<endl;
                            int cch1 , cch2;
                            if(difficulty=='3')
                            {
                                               cch1=chooseHard(a)[0];
                                               cch2=chooseHard(a)[1];
                            }
                            if(difficulty=='2')
                            {
                                               cch1=choose(a)[0];
                                               cch2=choose(a)[1];
                            }
                            if(difficulty=='1')
                            {
                                               cch1=chooseEasy(a)[0];
                                               cch2=chooseEasy(a)[1];
                            }
                            a[cch1][cch2]='O';
                            cout<<"Computer choose row "<<(cch1-1)/2<<" and column "<<(cch2-2)/4<<"."<<endl;
                            getch();
                            player=1;
                            }
                            if(checkWin(a)==1)
                            {
                                       system("cls");
                                       system("color 0A");
                                       win='y';
                                       cout<<"Player 1 won!!!!!"<<endl;
                   }
                   else if(checkWin(a)==2)
                   {
                                     system("cls");
                                     system("color 0A");
                                     win='y';
                                     cout<<"Computer won!!!!!"<<endl;
                   }
                   else if(checkWin(a)==3)
                   {
                                     system("cls");
                                     system("color 0A");
                                     win='y';
                                     cout<<"Cat's play"<<endl;
                   }
    }
    printBoard(a);
    cout<<endl;
    Ask2:
    cout<<"do you want play again??(y/n)"<<endl;
    cin>>ans;
    if(ans=='y')
    {
                goto replay;
    }
    else if(ans !='n')
    {
         cout<<"you have to enter 'y' or 'n'\nPress any key..."<<endl;
         getch();
         goto Ask2;
    }
    system("cls");
    cout<<"MAMANON BARAYE ENTEKHAB BAZI(TNX)"<<endl;
    cout<<"By: POYA "<<endl;
    cout<<"POYA#2243"<<endl;
    getch();
    return 0;
    }
    else
    {
    cout<<"By: POYA "<<endl;
    cout<<"discord: POYA#2243"<<endl;
    getch();
    return 0;
    }
}
