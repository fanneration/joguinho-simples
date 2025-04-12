#include<iostream>
#include<cmath>
#include<ctime>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
using namespace std;
char display[10]={'x','x','x','x','x','x','x','x','x','x'},googoogaga;
int delay,goodposition,position=0,points=0;
void randomdelay(){
    delay=100*abs(sin(rand()))+100;
}
void randomposition(){
    goodposition=9*abs(sin(rand()));
}
void displayfunc(){
    display[goodposition]='o';
    while (true){
        if (position>=1&&position<=8){
            cout << display[position-1] << display[position] << display[position+1] << "\npoints: " << points << "    round: " << points+1;
        }else if (position==0){
            cout << display[9] << display[position] << display[position+1] << "\npoints: " << points << "   round: " << points+1;
        }else{
            cout << display[position-1] << display[position] << display[0] << "\npoints: " << points << "   round: " << points+1;
        }
        Sleep(delay);
        system("CLS");
        if (position==9){
            position=0;
            continue;
        }
        if (_kbhit()){
            cin.ignore();
            break;
        }
        position++;
    }
}
int main(){
    srand(time(0));
    while (true){
        randomposition();
        randomdelay();
        displayfunc();
        if (position==goodposition){
            display[goodposition]='x';
            points++;
        }else{
            break;
        }
    }
    cout << "you lost!";
    cin >> googoogaga;
    return 0;
    }
