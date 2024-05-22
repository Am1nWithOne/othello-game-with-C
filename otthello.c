#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <stdbool.h>

#define SIZE 8



void mainMenu();
void printBoard();//Safhe bazi ro chap mikone
void StartGame();//bazi 1 vs 1
void wio();// What is othello? + rules
void Am1n();
void playWithAi();
void aiMakeMove();

char board[SIZE][SIZE];//array 2D vase Zamin bazi.
void initializBoard();//meghdar dehi Avaliye be jadval
int charToInt(char);
int isValidMove(int, int, char);
void flipNuts(char, int, int, int, int);
void makeMove(char, int, int);
int anyValidMove(char);
void Score();//tedad mohre ha ro mishmare
int FPS;//First Player Score
int SPS;//Second Player Score
int ESC;//Empty Spot Count
int endGame=0;
void endOfGame(int );
//int firstTime = 0

char currentPlayer;
char firstPlayer;
char secondPlayer;

int rows;
char columns;
int col;

int main(){





    mainMenu();



    return 0;

}

// FINISH!!!!! :D
void printBoard(){

    system("cls");
    printf("\n");

    Score();

    printf(" #### NEW GAMEBOARD \tFirstPlayer Score(%c): %d\t | SecondPlayer Score(%c): %d\tEmpty Spots: %d ####", firstPlayer, FPS, secondPlayer, SPS, ESC);

    printf("\n\n");

    printf("    ");
    char cc[SIZE][25]={"A", "B", "C", "D", "E", "F", "G", "H"};
    for (int i = 0; i <SIZE ; ++i) {
        printf("%s            ", cc[i]);//Horoof balay jadval ra chap mikonad.
    }

    printf("\n");

    //-------------------------------------------------------------------------------------------

    for(int t=0; t<SIZE; t++){
    //har khone toye jadval ro 3 bakhsh mikonim, bad 8 ta khone chap mionim.

        //part1: khathaye balla(Avalin khat zamin bazi)
        for (int i = 0; i < SIZE; ++i) {
            if (i == SIZE-1) {
                printf("+ ----- +    \n");//khat akhar
            } else {
                printf("+ ----- +    ");//sayer khotoot
            }
        }


        //part2: khotoot amodi va maghadir array board
        for (int i = 1; i < 4; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (j == SIZE -1 && i == 2) {//Khat vasat: Akharin khone jadvale ke shomare Satr ro benviseh.
                    printf("|   %c   | ", board[t][j]) ;
                    printf("%d", t+1);
                } else if( i==2){//Khat vasat: khone hay gheyr akhar.
                    printf("|   %c   |    ", board[t][j]);
                } else {// baghiye line ha
                    printf("|       |    ");
                }
            }
            printf("\n");
        }
    }


        //part3: Akharin Khat Ofoghi jadval
        for (int i = 0; i < 8; ++i) {
        if (i == 7) {
            printf("+ ----- +    \n");
        } else {
            printf("+ ----- +    ");
        }
    }


}

// FINISH!!!!! :D
void initializBoard(){

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            board[i][j] = ' ';
        }

    }

    board[SIZE/2-1][SIZE/2-1]=firstPlayer;
    board[SIZE/2][SIZE/2-1]=secondPlayer;
    board[SIZE/2-1][SIZE/2]=secondPlayer;
    board[SIZE/2][SIZE/2]=firstPlayer;

    currentPlayer = firstPlayer;


}

// FINISH!!!!! :D
int charToInt(char c){
    int res;

    switch(c){
        case 'a':
        case 'A':
            res = 1;
            break;
        case 'b':
        case 'B':
            res = 2;
            break;
        case 'c':
        case 'C':
            res = 3;
            break;
        case 'd':
        case 'D':
            res = 4;
            break;
        case 'e':
        case 'E':
            res = 5;
            break;
        case 'f':
        case 'F':
            res = 6;
            break;
        case 'g':
        case 'G':
            res = 7;
            break;
        case 'h':
        case 'H':
            res = 8;
            break;
        default:
            puts("WTF????????!!!!!!!!!!!");
    }

    return res;

}

// FINISH!!!!!
int isValidMove(int r, int c, char player){
    r--;
    c--;

    if(board[r][c] != ' '){
        return 0;//khone hamin alanesham pore
    }

    //Toye har 8 jahat migarde bbine koja ye done mohre enemy peyda mikone
    int directionRows[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int directionCols[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for(int direction = 0; direction< 8; direction++){
        int rrooww = r+directionRows[direction];
        int ccooll = c+directionCols[direction];
        int flip = 0;

        while(rrooww>=0 && rrooww<SIZE && ccooll>=0 && ccooll<SIZE && board[rrooww][ccooll] != ' ' && board[rrooww][ccooll] != currentPlayer){

            rrooww += directionRows[direction];
            ccooll += directionCols[direction];
            flip = 1;
        }

        if(flip && rrooww>=0 && rrooww<SIZE && ccooll>=0 && ccooll<SIZE && board[rrooww][ccooll] == currentPlayer){
            return 1;//valid Move
        }

    }

    return 0;//Invalid move
}

// FINISH!!!!! :D
void Score(){

    FPS =0;
    SPS =0;
    ESC =0;

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(board[i][j] == firstPlayer){
                FPS++;
            }else if(board[i][j] == secondPlayer){
                SPS++;
            }else{
                ESC++;
            }
        }
    }
}

// FINISH!!!!! :D
void flipNuts(char player, int row, int coll, int dr, int dc){



        int r = row + dr;
        int c = coll + dc;

        while(r>=0 && r<SIZE && c>=0 && c<SIZE){
            if(board[r][c] == player){
                break;
            }else if(board[r][c] == ' '){
                return;
            }else{
            r += dr;
            c += dc;
            }
        }

        if(r>=0 && r<SIZE && c>=0 && c<SIZE && board[r][c] == currentPlayer){
                //Flip nuts from (row, coll) to (r, c) in the specified direction
                r -= dr;
                c -= dc;
                while(r != row || c != coll){
                    board[r][c] = currentPlayer;
                    r -= dr;
                    c -= dc;
                }
        }
}

// FINISH!!!!! :D
void makeMove(char player, int row, int coll){
        row--;
        coll--;


        int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};// jahat haye ehtemali

        for(int i=0; i<SIZE; i++){

            flipNuts(player, row, coll, directions[i][0], directions[i][1]);// Toye har 8jahat khone entekhabi tabe FlipNuts ro ejra mikone

        }
        board[row][coll]= player;
        // dar akhar ham mohre current player ro mizare toye khone mad nazar
}



void StartGame(){


    printf("\t\t\t\t Enter First Player Symbol:");
    scanf("%c", &firstPlayer);
    getchar();
    printf("\t\t\t\t Enter Second Player Symbol:");
    scanf("%c", &secondPlayer);
    getchar();

    initializBoard();
    printBoard();


    while(1){


            if(!anyValidMove(firstPlayer) && !anyValidMove(secondPlayer)){

                puts("NO VALID MOVE!!!,THIS IS END OF THE GAME");
                break;

            }






            if(currentPlayer == firstPlayer && anyValidMove(firstPlayer)){
                endGame =0;
                printf("\nFirst player\'s turn( %c ), Enter a position to set your character:", firstPlayer);
                scanf("%c%d",&columns, &rows);
                getchar();
                int col = charToInt(columns);
                if(isValidMove(rows, col, firstPlayer)){
                //board[rows-1][col-1] = currentPlayer;
                makeMove(currentPlayer, rows, col);
                currentPlayer = secondPlayer;
                printBoard();
                }else{
                puts("WTF??????!!!!!!!!!");
                }
            }else if(currentPlayer == secondPlayer && anyValidMove(secondPlayer)){
                endGame = 0;
                printf("\nSecond player\'s turn( %c ), Enter a position to set your character:", secondPlayer);
                scanf("%c%d",&columns, &rows);
                getchar();
                int col = charToInt(columns);
                if(isValidMove(rows, col, secondPlayer)){
               // board[rows-1][col-1] = currentPlayer;
                makeMove(currentPlayer, rows, col);
                currentPlayer = firstPlayer;
                printBoard();
                endGame--;
                }else{
                puts("WTF??????!!!!!!!!!");
                }
            }else{
                currentPlayer = (currentPlayer == firstPlayer) ? secondPlayer : firstPlayer;
                printf("SORRY!!!, NO VALID MOVE!!!, NEXT PLAYER\'S( %c ) TURN.", currentPlayer);
                Sleep(1000);
                currentPlayer == firstPlayer;
                endGame++;

            }


    }

    endOfGame(1);
}



void mainMenu(){

    system("cls");


    puts("\n\t\t\t\t########################################");
    puts("\t\t\t\t WELCOM");
    Sleep(1000);
    puts("\t\t\t\t\t TO THE");
    Sleep(1000);
    puts("\t\t\t\t\t\t OTHELLO");
    Sleep(500);
    puts("\t\t\t\t\t\t\t GAME\n");
    Sleep(1500);

    puts("\n");

    int option;


    puts("\n\t\t\t\t MENU:");

    puts("\t\t\t\t 1.Start Game :D");

    puts("\t\t\t\t 2.-> Play With AI <-");

    puts("\t\t\t\t 3.What is othello?( rules )");

    puts("\t\t\t\t 4.about me...");

    puts("\t\t\t\t 5.Exit");

    printf("\t\t\t\t Select one option:");
    scanf("%d", &option);
    getchar();

    switch(option){
        case 1:
            StartGame();
            break;
        case 2:
            playWithAi();
            break;
        case 3:
            wio();
            break;
        case 4:
            Am1n();
            break;
        case 5:
            exit(0);




    }
}

// FINISH!!!!! :D
void wio(){
    char info[] = "\n\tReversi or Otheo is a strategy board game for two players, played on an 8*8 board.\n\tThere are sixty-four identical game pieces called disks, which are light on one side and dark on the other side.\n\tPlayers take turns placing disk on the board with their assigned color facing up.\n\n\tif you like more information open up your Google plz... ";

    system("cls");

    int i = 0;
    while(info[i] != '\0'){
        Sleep(70);
        printf("%c", info[i]);
        i++;
    }

    puts("\nPress enter to back to the main Menu.....");

    getchar();
    mainMenu();

}


// FINISH!!!!! :D
void Am1n(){

    system("cls");

    puts("\n\t\t\t\tAbout me:");

   char name[]= "\tHello my freind!!!\n\tmy name is Amin and i love programming!!!\n\tI made this game with C proramming Language and it was a hell of suffer and pain\n\tPlease don\'t try it at All.(even if you have to)\n\tUse something else and save yourself.\n\temail: \"am1nwithone@gmail.com\"\n";

    int i = 0;

   while(name[i] != '\0'){
    Sleep(70);
    if(name[i] == '\t'){
        printf("\t\t\t");
    }
    printf("%c", name[i]);
    i++;
   }

    printf("\n\t\t\t\tpress Enter to back to the main menu...");
    getchar();

    system("cls");

    mainMenu();




}

// FINISH!!!!! :D
int anyValidMove(char playerr){


    //khone khali haye board ro check mikone, va function isValidmove ro vase hamashon ejra mikone, age yekish brabr 1 shod, yani ba on khone mishe ye mohasere anjam dad.
    for(int i=1; i<=SIZE; i++){
        for(int j=1; j<=SIZE; j++){
            if(board[i-1][j-1] == ' '){
                if(isValidMove(i, j, playerr)){
                    return 1;
                }
            }
        }

    }


    return 0;

}


// almost done
void endOfGame(int x){


    printf("\n\tFirstPlayer( %c ) Score is: %d\n", firstPlayer, FPS);
    printf("\n\tSecondPlayer( %c ) Score is: %d\n", secondPlayer, SPS);



    if(FPS == SPS){

        printf("\n\tThat\'s a draw!!!\n\tI Hope you enjoy during play this game!!!!");


    }else if(FPS > SPS){

        printf("\n\tLook's like player %c has more tokens than player %c,\n\tSo the WINNERR IS:\n",firstPlayer, secondPlayer);
        Sleep(1000);
        puts("\t.");
        Sleep(1000);
        puts("\t.");
        printf("\n\n\t FIRST PLAYERRRRRRRRRR( %c%c%c%c%c%c)!!!!!!!!!!!!", firstPlayer, firstPlayer, firstPlayer, firstPlayer, firstPlayer, firstPlayer);
        Sleep(1000);

    }else{

        printf("\n\tLook's like player %c has more tokens than player %c,\n\tSo the WINNERR IS:\n", secondPlayer, firstPlayer);
        Sleep(1000);
        puts("\t.");
        Sleep(1000);
        puts("\t.");
        printf("\n\t SECOND PLAYERRRRRRRRRR( %c%c%c%c%c%c)!!!!!!!!!!!!", secondPlayer, secondPlayer, secondPlayer, secondPlayer, secondPlayer, secondPlayer);

    }


    int op;
    printf("\n\tI Hope both of you enjoy while playing othello game :)\n");
    do{
    printf("\n\tNow, choose an option:\n");

    puts("\t1.Play again:");
    printf("\t2.Back to the mainMenu");
    scanf("%d", &op);

    switch(op){
        case 1:
            if(x == 1){
                StartGame();
            }else{
                playWithAi();
            }
            break;
        case 2:
            mainMenu();
            break;

        }

    }while(op != 1 || op != 2);
}



void playWithAi(){

    printf("\n\t\t\t\tEnter Your Symbol:");
    scanf("%c", &firstPlayer);
    getchar();
    puts("\n\t\t\t\tplz wait...");
    char symbol[] = {'!', '@', '#', '$', '%', '&', '*', '+', '?'};
    srand ( time(NULL) );

    do{

        secondPlayer = symbol[rand()%9];

    }while(secondPlayer == firstPlayer);

    Sleep(1000);

    printf("\n\t\t\t\tand the AI symbol is: %c", secondPlayer);

    Sleep(1000);



    initializBoard();
    printBoard();






    while(1){


            if(!anyValidMove(firstPlayer) && !anyValidMove(secondPlayer)){

                puts("NO VALID MOVE!!!,THIS IS END OF THE GAME");
                break;

            }






            if(currentPlayer == firstPlayer && anyValidMove(firstPlayer)){
                endGame =0;
                do{
                printf("\nFirst player\'s turn( %c ), Enter a position to set your character:", firstPlayer);
                scanf("%c%d",&columns, &rows);
                getchar();
                }while(columns == '\n' || rows == '\n');
                int col = charToInt(columns);
                if(isValidMove(rows, col, firstPlayer)){
                //board[rows-1][col-1] = currentPlayer;
                makeMove(firstPlayer, rows, col);
                currentPlayer = secondPlayer;
                printBoard();
                }else{
                puts("WTF??????!!!!!!!!!");
                }
            }else if(currentPlayer == secondPlayer && anyValidMove(secondPlayer)){
                endGame = 0;
                printf("\nAI\'s turn( %c ), AI is thinking about a good spot:", secondPlayer);
                //scanf("%c%d",&columns, &rows);
                //getchar();
                Sleep(1200);

                aiMakeMove();





                //int col = charToInt(columns);
                //if(isValidMove(rows, col, secondPlayer)){
               // board[rows-1][col-1] = currentPlayer;
                //makeMove(currentPlayer, rows, col);
                currentPlayer = firstPlayer;
                printBoard();
                endGame--;
                //}else{
                //puts("WTF??????!!!!!!!!!");
                //}
            }else{
                currentPlayer = (currentPlayer == firstPlayer) ? secondPlayer : firstPlayer;
                printf("SORRY!!!, NO VALID MOVE!!!, NEXT PLAYER\'S( %c ) TURN.", currentPlayer);
                Sleep(1000);
                currentPlayer == firstPlayer;
                endGame++;

            }



    }


    endOfGame(2);
}



void aiMakeMove(){

    int randomMove = rand()%4;

    switch(randomMove){
        case 0:

            for(int i=1; i<=SIZE; i++){
                for(int j=1; j<=SIZE; j++){
                    if(board[i-1][j-1] == ' ' && isValidMove(i, j, secondPlayer)){
                                makeMove(secondPlayer, i, j);
                                return;

                    }
                }
            }
            break;
        case 1:

            for(int i=SIZE; i>=1; i--){
                for(int j=1; j<=SIZE; j++){
                    if(board[i-1][j-1] == ' ' && isValidMove(i, j, secondPlayer)){
                                makeMove(secondPlayer, i, j);
                                return;

                    }
                }
            }

            break;
        case 2:

            for(int i=1; i<=SIZE; i++){
                for(int j=SIZE; j>= 1; j--){
                    if(board[i-1][j-1] == ' ' && isValidMove(i, j, secondPlayer)){
                                makeMove(secondPlayer, i, j);
                                return;

                    }
                }
            }

            break;
        case 3:

            for(int i=SIZE; i>= 1; i--){
                for(int j=SIZE; j>=1; j--){
                    if(board[i-1][j-1] == ' ' && isValidMove(i, j, secondPlayer)){
                                makeMove(secondPlayer, i, j);
                                return;

                    }
                }
            }

            break;

    }

}


