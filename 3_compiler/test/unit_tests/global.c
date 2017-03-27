int global;
int global2;
int global3;
int global4;

int function(){
  return 12;
}

int main(){
  int local;

  local = 42;

  global = 0;
  global2 = 12;
  global3 = local;
  global4 = function();
  return 0;
}
