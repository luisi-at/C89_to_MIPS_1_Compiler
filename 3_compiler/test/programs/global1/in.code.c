int x;
int y;

void function(){
  x = 14;
}

void function2(){
  x = 13;
}

int main()
{
  x = 3;
  y = x + 5;
  function();
  function2();
  if(x > 3){
    y = 3;
    return 0;
  }
  return 1;
}
