#include <iostream>

void init(char a[][3],bool b[][3]){
    for (int i=0;i<3;++i){
        for(int k=0;k<3;++k){
            a[i][k]=' ';
            b[i][k]=false;
        }
    }
}

void print(char a[][3]){
    std::cout << "y|-------|" << std::endl;
    for(int i=2;i>=0;--i){
        std::cout << i <<"| ";
        for(int k=0;k<3;++k){
            std::cout <<a[k][i]<<" ";
        }
        std::cout<<'|'<<std::endl;
    }
    std::cout << " |-0-1-2-|x" << std::endl;
}

char winner(char game[][3]){
    int sumOH=0,sumXH=0,sumXV=0,sumOV=0;
    for(int i=0;i<3;++i){
        sumOH=sumXH=sumXV=sumOV=0;
        for(int k=0;k<3;++k) {
            if (game[i][k] == 'X') sumXV += 1;
            else if (game[i][k] == 'O') sumOV += 1;
            if (game[k][i]=='X') sumXH+=1;
            else if (game[k][i]=='O') sumOH+=1;
        }
        if(sumOH==3||sumOV==3) return 'O';
        else if(sumXH==3||sumXV==3) return 'X';
    }
    return ' ';
}

int main() {
    char game[3][3];
    bool gameUsed[3][3];
    init(game,gameUsed);
    bool crossTurn=true,notDone= true;
    int x=-1,y=-1;
    for (int i=0;i<9;++i){
        notDone=true;
        print(game);
        if(winner(game)!=' ') break;
        do {
            x = -1, y = -1;
            std::cout << (crossTurn ? "Cross" : "Zero") << " turn! Input coords[x][y]:";
            std::cin >> x >> y;
            if (x >= 0 && y >= 0 && x < 3 && y < 3) {
                if (gameUsed[x][y]) {
                    std::cout << "Error field is used choose another!"<< std::endl;
                }else {
                    game[x][y]=(crossTurn?'X':'O');
                    gameUsed[x][y]=true;
                    notDone=false;
                }
            }
        }while(notDone);
        crossTurn=!crossTurn;
    }
    if(winner(game)!=' ')
        std::cout << (winner(game)=='X'?"Cross":"Zero") << " wins! Congratulations!!!"<< std::endl;
    else  {
        print(game);
        std::cout <<"Nobody wins!" << std::endl;
    }
    std::cout << "Game Over" << std::endl;
}
