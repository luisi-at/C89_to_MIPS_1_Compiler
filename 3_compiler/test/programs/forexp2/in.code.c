int main()
{
  int x;
  int y;

  y = 1;

  for(x = 0; x > 4; x++){
    if(x == 3){
      y = y + 4;
    }
    else{
      y++;
    }
  }

  return y + 2;
}
