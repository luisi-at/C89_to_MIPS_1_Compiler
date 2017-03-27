int globalfunc();

int global = 0;

int main(){
  int x;

  x = globalfunc();
  if(global == 42){
    return 0;
  }
  else{
    return 1;
  }
return 0;
}
