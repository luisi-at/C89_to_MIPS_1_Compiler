#include <stdlib.h>

int testAtoi();

int main(){
  int local;
  int test;

  local = atoi("a");
  test = testAtoi();

  if(test == local){
    return 0;
  }
return 1;
}
