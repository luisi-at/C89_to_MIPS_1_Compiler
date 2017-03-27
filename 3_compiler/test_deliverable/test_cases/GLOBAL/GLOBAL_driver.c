int global;

void globalfunc();

int main(){

  globalfunc();
  if(global == 42){
    return 0;
  }
  else{
    return 1;
  }
return 0;
}
