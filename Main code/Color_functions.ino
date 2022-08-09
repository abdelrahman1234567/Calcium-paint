ColorValue ColorCode(){
  // The color sensor works with RGB method
  // So, we will take the reading of Red, Green, and Blue

  // Red parameter reading
  ColorValue Color;
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Color.Red = pulseIn(output, LOW);
  
  // Blue parameter reading
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  Color.Blue = pulseIn(output, LOW);
  
  //Green parameter reading
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  Color.Green = pulseIn(output, LOW);

  return Color; 
}

int validColor(ColorValue Color){
  if(Color.Red > IdealColor.Red+30)
    return 1;
  if(Color.Red < IdealColor.Red-10)
    return -1;
   
  return 0;
}
