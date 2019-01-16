/* Developed by Ankur Varma & Jay  Suthat
 * @ sashivarma58@gmail.com
 */

#define ECHOPIN 3        
#define TRIGPIN 2      
#define BULB 4
#define FAN 5
#define AC 6
#define TV 7
int i = 0;
int j = 0;
int k = 0;
int l = 0;

  
void setup() 
{ 
  Serial.begin(9600); 
  pinMode(ECHOPIN, INPUT); 
  pinMode(TRIGPIN, OUTPUT);
  pinMode(BULB, OUTPUT);
  pinMode(FAN, OUTPUT);
  pinMode(AC, OUTPUT);
  pinMode(TV, OUTPUT); 
}

void loop() 
{  
  digitalWrite(TRIGPIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIGPIN, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIGPIN, LOW);

  
  
  float distance = pulseIn(ECHOPIN, HIGH); 
  distance= distance/58; 


  Serial.print(distance); 
  Serial.println(" cm");

  if ((distance > 6) && (distance < 12))
  {
    if(i%2 == 0){
    digitalWrite (BULB, HIGH);
    Serial.println("Bulb ON");
    i++;
    }
    else{
      digitalWrite (BULB, LOW);
      Serial.println("Bulb OFF");
      i++;
    }
  }
  else if ((distance > 14) && (distance < 18))
  {
    if(j%2 == 0){
    digitalWrite (FAN, HIGH);
    Serial.println("Fan ON");
    j++;
    }
    else{
      digitalWrite (FAN, LOW);
      Serial.println("Fan OFF");
      j++;
    }
  }
  else if ((distance > 19) && (distance < 25))
  {
    if(k%2 == 0){
    digitalWrite (AC, HIGH);
    Serial.println("Ac ON");
    k++;
    }
    else{
      digitalWrite (AC, LOW);
      Serial.println("Ac OFF");
      k++;
    }
  }
  else if ((distance > 26) && (distance < 35))
  {
    if(l%2 == 0){
    digitalWrite (TV, HIGH);
    Serial.println("Tv ON");
    l++;
    }
    else{
      digitalWrite (TV, LOW);
      Serial.println("Tv OFF");
      l++;
    }
  }

  delay(300); 
}
