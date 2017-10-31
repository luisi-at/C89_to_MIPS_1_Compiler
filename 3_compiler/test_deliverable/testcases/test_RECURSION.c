int recursive(int input){
    int x = input;
    if(x > 0){
        x--;
        x = recursive(x);
    }
    return x;
}
