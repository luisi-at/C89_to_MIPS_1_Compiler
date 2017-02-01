//  Imperial College London
//
//  EE1-07 Software Engineering 1- Introduction to Computing 2015-2016
//  Spring 2016 Assigment
//  '2048' based on the game 2048 by Gabrielle Cirulli (http://gabrielecirulli.github.io/2048/)
//
//  Created by Alexander Luisi on 02/02/2016.
//  CID: 01055508

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//function declarations

//game management
void play_game(int (&board)[4][4], const char key_in);

//key presses
//processes 'a' key pressed
void move_left(int (&board)[4][4]);
//processes 'd' key pressed
void move_right(int (&board)[4][4]);
//processes 'w' key pressed
void move_up(int (&board)[4][4]);
//processes 's' key pressed
void move_down(int (&board)[4][4]);

//board management
//checks for any available moves
bool check_for_moves(int (&board)[4][4]);
//display the board
void display_board(int (&board)[4][4]);
//restore board to default state
void set_default(int (&board)[4][4]);

//random number to choose column/row to place 2
int get_random();
//routine to insert
void insert_random(int (&board)[4][4]);

//error

int main() {
    //seed the generator
    srand((unsigned(time(0))));
    
    //local variable/array declarations
    
    //decare the 2-dimensional array for the board
    int board[4][4];
    //general control variables
    bool game_over = false;
    char key_pressed;
    //file variables
    bool file_opened = false;
    string user_filename;
    ifstream user_file;
    
    //get filename
    cout << "Enter initial configuration filename" << endl;
    
    cin >> user_filename;
    
    //open the file
    user_file.open(user_filename.c_str());
    
    if(!user_file.is_open()){
        //check if the file is open
        cout << "File not found, using default start configuration" << endl;
        //mark that the file was not found and open default configuration
        file_opened = false;
        
    }
    else{
        //mark that the file was found and opened, so present file contents on board
        file_opened = true;
        
        //input values from file to board
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                user_file >> board[i][j]; //this could be problematic, have a check in the labs
            }
        }
    }
    
    //check if the file has been read in
    if(file_opened == true){
        
        //check for any moves as file may not have any available moves
        game_over = check_for_moves(board);
        
        //loop until game ends
        display_board(board);
        while(game_over == false){
            //get the user key press
            cin >> key_pressed;
            //go to the game play routine
            play_game(board, key_pressed);
            //check for any further moves
            game_over = check_for_moves(board);
            display_board(board);
        }
        cout << "No more moves. Game Over" << endl;
    }
    else{
        //initialise the non-file board
        set_default(board);
        //loop until game ends
        display_board(board);
        while(game_over == false){
            //get the user key press
            cin >> key_pressed;
            //go to the game play routine
            play_game(board, key_pressed); //returns a value to evaluate program termination
            //check for any further moves
            game_over = check_for_moves(board);
            display_board(board);
        }
        cout << "No more moves. Game Over" << endl;
    }
    
    return 0;
}

void play_game(int (&board)[4][4], const char key_in){
    
    if(key_in == 'a'){
        move_left(board);
    }
    else if(key_in == 'd'){
        move_right(board); //check this- does it work?
    }
    else if(key_in == 'w'){
        move_up(board);
    }
    else if(key_in == 's'){
        move_down(board);
    }
    
}

void move_left(int (&board)[4][4]){
    //search for adjacent pairs in horizontal
    //i is the row counter
    //j is the column counter
    
    //check if the operation has been done
    bool done_add = false;
    bool moved_left = false;
    //check to insert random number
    bool check_insert = false;
    
    for(int i = 0; i < 4; i++){
        done_add = false;
        for(int j = 0; j < 4; j++){
            done_add = false;
            
            if((j + 1) < 4){ //ensure that the loop does not go outside the bounds of the array
                //if any pairs of the same numbers exist, sum them
                if((board[i][j] == board[i][(j+1)]) && (board[i][j] != 0)){
                    //sum goes in the left element of the pair
                    board[i][j] = board[i][j] + board[i][(j+1)];
                    //zero the right element of the pair
                    board[i][(j+1)] = 0;
                    done_add = true;
                    check_insert = true;
                }
            }
            
            if(((j + 2) < 4) && (done_add == false)){ //ensure that the loop does not go outside the bounds of the array
                //if any pairs of the same numbers exist, sum them
                if((board[i][j] == board[i][(j+2)]) && (board[i][j] != 0) && (board[i][(j+1)] == 0)){
                    //sum goes in the left element of the pair
                    board[i][j] = board[i][j] + board[i][(j+2)];
                    //zero the right element of the pair
                    board[i][(j+2)] = 0;
                    done_add = true;
                    check_insert = true;
                }
            }
            
            if(((j + 3) < 4) && (done_add == false)){ //ensure that the loop does not go outside the bounds of the array
                //if any pairs of the same numbers exist, sum them
                if((board[i][j] == board[i][(j+3)]) && (board[i][j] != 0) && ((board[i][(j+1)] == 0) && (board[i][(j+2)] == 0))){
                    //sum goes in the left element of the pair
                    board[i][j] = board[i][j] + board[i][(j+3)];
                    //zero the right element of the pair
                    board[i][(j+3)] = 0;
                    done_add = true;
                    check_insert = true;
                }
            }
            
        }
    }
    
    //move everything left as far as possible
    for(int i = 0; i < 4; i++){
        moved_left = false;
        for(int j = 0; j < 4; j++){
            moved_left = false;
            
            if(((j+1) < 4) && (board[i][j] == 0) && (board[i][j+1] != 0)){
                board[i][j] = board[i][j+1];
                board[i][j+1] = 0;
                moved_left = true;
                check_insert = true;
            }
            
            if(((j+2) < 4) && (board[i][j] == 0) && (board[i][j+2] != 0) && (moved_left == false)){
                board[i][j] = board[i][j+2];
                board[i][j+2] = 0;
                moved_left = true;
                check_insert = true;
            }
            
            if(((j+3) < 4) && (board[i][j] == 0) && (board[i][j+3] != 0) && (moved_left == false)){
                board[i][j] = board[i][j+3];
                board[i][j+3] = 0;
                moved_left = true;
                check_insert = true;
            }
            
        }
    }
    
    //if a move has been performed, insert a 2 in a random position
    if(check_insert == true){
        insert_random(board);
    }
    
}

void move_right(int (&board)[4][4]){
    //search for adjacent pairs in horizontal
    //i is the row counter
    //j is the column counter
    
    //check if the operation has been done
    bool done_add = false;
    bool moved_right = false;
    //check to insert random number
    bool check_insert = false;
    
    for(int i = 0; i < 4; i++){
        done_add = false;
        for(int j = 3; j >= 0; j--){
            done_add = false;
            
            if((j - 1) >= 0){ //ensure that the loop does not go outside the bounds of the array
                //if any pairs of the same numbers exist, sum them
                if((board[i][j] == board[i][(j-1)]) && (board[i][j] != 0)){
                    //sum goes in the left element of the pair
                    board[i][j] = board[i][j] + board[i][(j-1)];
                    //zero the right element of the pair
                    board[i][(j-1)] = 0;
                    done_add = true;
                    check_insert = true;
                }
            }
            
            if(((j - 2) >= 0) && (done_add == false)){ //ensure that the loop does not go outside the bounds of the array
                //if any pairs of the same numbers exist, sum them
                if((board[i][j] == board[i][(j-2)]) && (board[i][j] != 0) && (board[i][(j-1)] == 0)){
                    //sum goes in the left element of the pair
                    board[i][j] = board[i][j] + board[i][(j-2)];
                    //zero the right element of the pair
                    board[i][(j-2)] = 0;
                    done_add = true;
                    check_insert = true;
                }
            }
            
            if(((j - 3) >= 0) && (done_add == false)){ //ensure that the loop does not go outside the bounds of the array
                //if any pairs of the same numbers exist, sum them
                if((board[i][j] == board[i][(j-3)]) && (board[i][j] != 0) && ((board[i][(j-1)] == 0) && (board[i][(j-2)] == 0))){
                    //sum goes in the left element of the pair
                    board[i][j] = board[i][j] + board[i][(j-3)];
                    //zero the right element of the pair
                    board[i][(j-3)] = 0;
                    done_add = true;
                    check_insert = true;
                }
            }
            
        }
    }
    
    //move everything right as far as possible
    for(int i = 0; i < 4; i++){
        moved_right = false;
        for(int j = 3; j >=0; j--){
            moved_right = false;
            
            if(((j-1) >= 0) && (board[i][j] == 0) && (board[i][j-1] != 0)){
                board[i][j] = board[i][j-1];
                board[i][j-1] = 0;
                moved_right = true;
                check_insert = true;
            }
            
            if(((j-2) >= 0) && (board[i][j] == 0) && (board[i][j-2] != 0) && (moved_right == false)){
                board[i][j] = board[i][j-2];
                board[i][j-2] = 0;
                moved_right = true;
                check_insert = true;
            }
            
            if(((j-3) >= 0) && (board[i][j] == 0) && (board[i][j-3] != 0) && (moved_right == false)){
                board[i][j] = board[i][j-3];
                board[i][j-3] = 0;
                moved_right = true;
                check_insert = true;
            }
            
        }
    }
    
    if(check_insert == true){
        insert_random(board);
    }
    
}

void move_down(int (&board)[4][4]){
    //search for adjacent pairs in horizontal
    //i is the row counter
    //j is the column counter
    
    //check if the operation has been done
    bool done_add = false;
    bool moved_down = false;
    //check to insert random number
    bool check_insert = false;
    
    for(int i = 3; i >= 0; i--){
        done_add = false;
        for(int j = 0; j < 4; j++){
            done_add = false;
            
            if((i - 1) >= 0){ //ensure that the loop does not go outside the bounds of the array
                //if any pairs of the same numbers exist, sum them
                if((board[i][j] == board[i-1][j]) && (board[i][j] != 0)){
                    //sum goes in the left element of the pair
                    board[i][j] = board[i][j] + board[i-1][j];
                    //zero the right element of the pair
                    board[i-1][j] = 0;
                    done_add = true;
                    check_insert = true;
                }
            }
            
            if(((i - 2) >= 0) && (done_add == false)){ //ensure that the loop does not go outside the bounds of the array
                //if any pairs of the same numbers exist, sum them
                if((board[i][j] == board[i-2][j]) && (board[i][j] != 0) && (board[i-1][j] == 0)){
                    //sum goes in the left element of the pair
                    board[i][j] = board[i][j] + board[i-2][j];
                    //zero the right element of the pair
                    board[i-2][j] = 0;
                    done_add = true;
                    check_insert = true;
                }
            }
            
            if(((i - 3) >= 0) && (done_add == false)){ //ensure that the loop does not go outside the bounds of the array
                //if any pairs of the same numbers exist, sum them
                if((board[i][j] == board[i-3][j]) && (board[i][j] != 0) && ((board[i-1][j] == 0) && (board[(i-2)][j] == 0))){
                    //sum goes in the left element of the pair
                    board[i][j] = board[i][j] + board[(i-3)][j];
                    //zero the right element of the pair
                    board[(i-3)][j] = 0;
                    done_add = true;
                    check_insert = true;
                }
            }
            
        }
    }
    
    //move everything down as far as possible
    for(int i = 3; i >= 0; i--){
        moved_down = false;
        for(int j = 0; j < 4; j++){
            moved_down = false;
            
            if(((i-1) >= 0) && (board[i][j] == 0) && (board[i-1][j] != 0)){
                board[i][j] = board[i-1][j];
                board[i-1][j] = 0;
                moved_down = true;
                check_insert = true;
            }
            
            if(((i-2) >= 0) && (board[i][j] == 0) && (board[i-2][j] != 0) && (moved_down == false)){
                board[i][j] = board[i-2][j];
                board[i-2][j] = 0;
                moved_down = true;
                check_insert = true;
            }
            
            if(((i-3) >= 0) && (board[i][j] == 0) && (board[i-3][j] != 0) && (moved_down == false)){
                board[i][j] = board[i-3][j];
                board[i-3][j] = 0;
                moved_down = true;
                check_insert = true;
            }
            
        }
    }
    
    if(check_insert == true){
        insert_random(board);
    }
    
}

void move_up(int (&board)[4][4]){
    //search for adjacent pairs in horizontal
    //i is the row counter
    //j is the column counter
    
    //check if the operation has been done
    bool done_add = false;
    bool moved_up = false;
    //check to insert random number
    bool check_insert = false;
    
    for(int i = 0; i < 4; i++){
        done_add = false;
        for(int j = 0; j < 4; j++){
            done_add = false;
            
            if((i + 1) < 4){ //ensure that the loop does not go outside the bounds of the array
                //if any pairs of the same numbers exist, sum them
                if((board[i][j] == board[i+1][j]) && (board[i][j] != 0)){
                    //sum goes in the left element of the pair
                    board[i][j] = board[i][j] + board[i+1][j];
                    //zero the right element of the pair
                    board[i+1][j] = 0;
                    done_add = true;
                    check_insert = true;
                }
            }
            
            if(((i + 2) < 4) && (done_add == false)){ //ensure that the loop does not go outside the bounds of the array
                //if any pairs of the same numbers exist, sum them
                if((board[i][j] == board[i+2][j]) && (board[i][j] != 0) && (board[i+1][j] == 0)){
                    //sum goes in the left element of the pair
                    board[i][j] = board[i][j] + board[i+2][j];
                    //zero the right element of the pair
                    board[i+2][j] = 0;
                    done_add = true;
                    check_insert = true;
                }
            }
            
            if(((i + 3) < 4) && (done_add == false)){ //ensure that the loop does not go outside the bounds of the array
                //if any pairs of the same numbers exist, sum them
                if((board[i][j] == board[(i+3)][j]) && (board[i][j] != 0) && ((board[(i+1)][j] == 0) && (board[(i+2)][j] == 0))){
                    //sum goes in the left element of the pair
                    board[i][j] = board[i][j] + board[(i+3)][j];
                    //zero the right element of the pair
                    board[(i+3)][j] = 0;
                    done_add = true;
                    check_insert = true;
                }
            }
            
        }
    }
    
    //move everything up as far as possible
    for(int i = 0; i < 4; i++){
        moved_up = false;
        for(int j = 0; j < 4; j++){
            moved_up = false;
            
            if(((i+1) < 4) && (board[i][j] == 0) && (board[i+1][j] != 0)){
                board[i][j] = board[i+1][j];
                board[i+1][j] = 0;
                moved_up = true;
                check_insert = true;
            }
            
            if(((i+2) < 4) && (board[i][j] == 0) && (board[i+2][j] != 0) && (moved_up == false)){
                board[i][j] = board[i+2][j];
                board[i+2][j] = 0;
                moved_up = true;
                check_insert = true;
            }
            
            if(((i+3) < 4) && (board[i][j] == 0) && (board[i+3][j] != 0) && (moved_up == false)){
                board[i][j] = board[i+3][j];
                board[i+3][j] = 0;
                moved_up = true;
                check_insert = true;
            }
            
        }
    }
    
    if(check_insert == true){
        insert_random(board);
    }
    
}

void insert_random(int (&board)[4][4]){
    //initialise column and row variables
    int insertion_number_column = 0;
    int insertion_number_row = 0;
    
    //generate a random number between 0 and 3 for the row and the column
    // to check that the position is empty
    insertion_number_column = get_random();
    insertion_number_row = get_random();
    
    //if the position isn't zero then find it until it is
    while(board[insertion_number_row][insertion_number_column] != 0){
        insertion_number_column = get_random();
        insertion_number_row = get_random();
    }
    //insert 2 into the random position
    board[insertion_number_row][insertion_number_column] = 2;
}

int get_random(){
    //declare the variable to hold the return number
    int return_rand;
    
    //return a random number between 0 and 3
    return_rand = (rand() % 4);
    
    //return the random number
    return return_rand;
}

bool check_for_moves(int (&board)[4][4]){
    //local variable to hold move status
    //set to to so if there are no more moves, the boolean remains unchanged
    bool return_move_bool = true;
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            //check if any zeros
            if(board[i][j] == 0){
                return_move_bool = false;
            }
            
            //check for any pairs
            //check top left corner
            if((i-1 < 0) && (j-1 < 0)){
                if((board[i][j] == board[i+1][j]) or (board[i][j] == board[i][j+1])){
                    return_move_bool = false;
                }
            }
            
            //check bottom left corner
            if((i+1 > 4) && (j-1 < 0)){
                if((board[i][j] == board[i-1][j]) or (board[i][j] == board[i][j+1])){
                    return_move_bool = false;
                }
            }
            
            //check top right corner
            if((i-1 < 0) && (j+1 > 4)){
                if((board[i][j] == board[i+1][j]) or (board[i][j] == board[i][j-1])){
                    return_move_bool = false;
                }
            }
            
            //check bottom right corner
            if((i+1 > 4) && (j+1 > 4)){
                if((board[i][j] == board[i-1][j]) or (board[i][j] == board[i][j-1])){
                    return_move_bool = false;
                }
            }
            
            //check the middles for j = 0
            if((i-1 > 0) && (i+1 < 4) && (j-1 < 0)){
                if((board[i][j] == board[i][j+1]) or (board[i][j] == board[i-1][j]) or (board[i][j] == board[i+1][j])){
                    return_move_bool = false;
                }
            }
            
            //check the middles for j = 3
            if((i-1 > 0) && (i+1 < 4) && (j+1 > 4)){
                if((board[i][j] == board[i][j-1]) or (board[i][j] == board[i-1][j]) or (board[i][j] == board[i+1][j])){
                    return_move_bool = false;
                }
            }
            
            //check the middles for i = 0
            if((i-1 < 0) && (j-1 > 0) && (j+1 < 4)){
                if((board[i][j] == board[i][j-1]) or (board[i][j] == board[i][j+1]) or (board[i][j] == board[i+1][j])){
                    return_move_bool = false;
                }
            }
            
            //check the middles for i = 3
            if((i+1 > 4) && (j-1 > 0) && (j+1 < 4)){
                if((board[i][j] == board[i][j-1]) or (board[i][j] == board[i][j+1]) or (board[i][j] == board[i-1][j])){
                    return_move_bool = false;
                }
            }
            
            //check for the middles
            if((i-1 > 0) && (i+1 < 4) && (j-1 > 0) && (j+1 < 4)){
                if((board[i][j] == board[i][j-1]) or (board[i][j] == board[i][j+1]) or (board[i][j] == board[i-1][j]) or (board[i][j] == board[i+1][j])){
                    return_move_bool = false;
                }
            }
        }
    }
    
    //return the value back to the main
    return return_move_bool;
}

void display_board(int (&board)[4][4]){
    //print the board
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << board[i][j];
            cout << "\t";
        }
        cout << endl;
    }
}

void set_default(int (&board)[4][4]){
    //set the default board
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            board[i][j] = 0; //initiate all the board to zero
        }
    }
    
    board[3][3] = 2; //insert the 2 into the bottom, right-hand corner
    
}
