void CloseHoles(){
  int dis = curridx + 1; // the distance that the motor will move
  for(int i = 0;i<dis*2;i++){
    digitalWrite(GateCW,HIGH);
    delay(50);
    digitalWrite(GateCW,LOW);
    delay(500);
  }
}

void openHole(int index){
  if(index > curridx){
    int dis = index - curridx; // the distance that the motor will move
    for(int i = 0;i<dis*2;i++){
      digitalWrite(GateCW,HIGH);
      delay(50);
      digitalWrite(GateCW,LOW);
      delay(500);
    } 
  }
  else if(index < curridx){
    int dis = curridx - index; // the distance that the motor will move
    for(int i = 0;i<dis*2;i++){
      digitalWrite(GateCCW,HIGH);
      delay(50);
      digitalWrite(GateCCW,LOW);
      delay(500);
    }
  }
  curridx = index; // update the current index
}
