int lightState;
int lightNumber;
int animationNumber;
int animations = 6;  // number of animations
int lights = 8;
int light[] = {
  12, 11, 10, 9, 8, 7, 6, 5};
int buttonPin = 4;
char charInput;
String command;

void setup()
{
  for (int i = 0; i < lights; i++)
  {
    pinMode(light[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
  for (int i = 0; i < lights; i++)
  {
    digitalWrite(light[i], LOW);
  }
  Serial.begin(9600);
  // wait until there is input
  while (!Serial)
  {
  }
  Serial.write("Arduino Light Controller\n");
  Serial.write("\n");
  Serial.write("Switch to \"no line ending\" and enter command :\n");
}

void loop()
{
  // read characters from the computer when available
  while (Serial.available() > 0)
  {
    charInput = Serial.read();
    command = command + charInput;

    if (charInput == ';')
    {
      Serial.println("Command Received: " + command);
      if (command.charAt(0) == 'P' && command.charAt(1) == 'R' && command.charAt(2) == 'E' && command.charAt(3) == 'P' && command.length() == 5)
      {
        // turn all lights off
        prepareLights();
      }
      else if (command.charAt(0) == 'A' && command.charAt(1) == 'U' && command.charAt(2) == 'T' && command.charAt(3) == 'O' && command.length() == 5)
      {
        // automatically select random animations
        while(!Serial.available())
        {
          animationNumber = random(1, animations + 1);
          animation(animationNumber);
        }
        prepareLights();
      }
      else if (command.charAt(0) == 'P' && command.charAt(1) == 'R' && command.charAt(2) == 'E' && command.length() == 5)
      {
        // run a predefined animation
        animationNumber = command.charAt(3) - '0';
        while(!Serial.available())
        {
          animation(animationNumber);
        }
        prepareLights();
      }
      else if (command.charAt(0) == 'L' && command.charAt(2) == '=' && command.length() == 5)
      {
        // turn an individual light on or off
        lightState = command.charAt(3) - '0';
        lightNumber = command.charAt(1) - '0';

        digitalWrite(light[lightNumber], lightState);
      }
      else
      {
        Serial.println("ERROR IN COMMAND.");
      }
      command = "";
    }
  }

  // if the button is pressed, play random animations
  if(digitalRead(buttonPin))
  {
    while(!Serial.available())
    {
      animationNumber = random(1, animations + 1);
      animation(animationNumber);
    }
  }
}

void prepareLights()
{
  setLights(0, 0, 0, 0, 0, 0, 0, 0);
}

void setLights(int L0, int L1, int L2, int L3, int L4, int L5, int L6, int L7)
{
  digitalWrite(light[0], L0);
  digitalWrite(light[1], L1);
  digitalWrite(light[2], L2);
  digitalWrite(light[3], L3);
  digitalWrite(light[4], L4);
  digitalWrite(light[5], L5);
  digitalWrite(light[6], L6);
  digitalWrite(light[7], L7);
}

void animation(int number)
{
  switch (number)
  {
  case 1:
    setLights(0, 0, 0, 1, 1, 1, 1, 1);
    delay(2000);
    for(int i = 0; i < 5; i++)
    {
      setLights(1, 0, 1, 1, 0, 0, 0, 0);
      delay(500);
      setLights(1, 0, 0, 0, 1, 0, 1, 0);
      delay(500);
      setLights(1, 0, 0, 0, 0, 1, 0, 1);
      delay(500);
    }
    for(int i = 0; i < 5; i++)
    {
      setLights(1, 0, 1, 0, 1, 0, 0, 1);
      delay(500);
      setLights(1, 0, 0, 0, 0, 1, 1, 0);
      delay(500);
    }
    setLights(0, 0, 0, 1, 1, 0, 0, 0);
    delay(750);
    setLights(0, 0, 0, 1, 0, 0, 1, 0);
    delay(750);
    setLights(0, 0, 0, 1, 0, 1, 0, 0);
    delay(750);
    setLights(0, 0, 0, 1, 0, 0, 0, 1);
    delay(750);
    break;
  case 2:
    for(int i = 0; i < 3; i++)
    {
      setLights(0, 0, 0, 0, 1, 0, 0, 1);
      delay(1000);
      setLights(0, 0, 0, 0, 0, 1, 1, 0);
      delay(1000);
    }
    setLights(0, 0, 0, 0, 0, 1, 0, 1);
    delay(1000);
    setLights(1, 0, 0, 0, 0, 1, 0, 1);
    delay(1000);
    setLights(0, 0, 0, 0, 1, 0, 1, 0);
    delay(1000);
    setLights(1, 0, 1, 0, 0, 0, 0, 0);
    delay(3500);
    setLights(0, 1, 0, 1, 0, 0, 0, 0);
    delay(1000);
    setLights(1, 1, 1, 1, 0, 0, 0, 0);
    delay(3000);
    setLights(1, 1, 1, 0, 1, 0, 1, 0);
    delay(500);
    setLights(1, 1, 1, 1, 1, 1, 1, 1);
    delay(500);
    for(int i = 0; i < 5; i++)
    {
      setLights(0, 1, 1, 1, 1, 0, 1, 0);
      delay(500);
      setLights(0, 1, 1, 0, 0, 1, 0, 1);
      delay(500);
    }
    for(int i = 0; i < 5; i++)
    {
      setLights(0, 0, 0, 1, 1, 1, 1, 1);
      delay(1000);
      setLights(0, 1, 1, 1, 1, 1, 1, 1);
      delay(1000);
    }
    setLights(0, 0, 0, 0, 0, 0, 0, 0);
    delay(1500);
    setLights(1, 0, 0, 0, 0, 0, 0, 0);
    delay(1000);
    setLights(1, 1, 0, 0, 0, 0, 0, 0);
    delay(1000);
    setLights(1, 1, 1, 0, 0, 0, 0, 0);
    delay(1000);
    setLights(1, 1, 1, 1, 0, 0, 0, 0);
    delay(1000);
    setLights(1, 1, 1, 1, 1, 0, 0, 0);
    delay(1000);
    setLights(1, 1, 1, 1, 1, 1, 0, 0);
    delay(1000);
    setLights(1, 1, 1, 1, 1, 1, 1, 0);
    delay(1000);
    setLights(1, 1, 1, 1, 1, 1, 1, 1);
    delay(1000);
    setLights(1, 1, 1, 1, 0, 0, 0, 0);
    delay(1500);
    for(int i = 0; i < 5; i++)
    {
      setLights(1, 1, 1, 1, 1, 0, 1, 0);
      delay(500);
      setLights(1, 1, 1, 1, 0, 1, 0, 1);
      delay(500);
    }
    for(int i = 0; i < 5; i++)
    {
      setLights(1, 1, 1, 1, 1, 1, 0, 0);
      delay(500);
      setLights(1, 1, 1, 1, 0, 0, 1, 1);
      delay(500);
    }
    setLights(1, 1, 1, 1, 0, 0, 0, 0);
    delay(1000);
    setLights(1, 1, 1, 0, 0, 0, 0, 0);
    delay(1000);
    setLights(1, 1, 0, 0, 0, 0, 0, 0);
    delay(1000);
    setLights(1, 0, 0, 0, 0, 0, 0, 0);
    delay(1000);
    setLights(0, 0, 0, 0, 0, 0, 0, 0);
    delay(3000);
    break;
  case 3:
    setLights(1, 0, 0, 0, 0, 0, 0, 0);
    delay(250);
    setLights(0, 1, 0, 0, 0, 0, 0, 0);
    delay(250);
    setLights(0, 0, 1, 0, 0, 0, 0, 0);
    delay(250);
    setLights(0, 0, 0, 1, 0, 0, 0, 0);
    delay(250);
    setLights(0, 0, 0, 0, 1, 0, 0, 0);
    delay(250);
    setLights(0, 0, 0, 0, 0, 1, 0, 0);
    delay(250);
    setLights(0, 0, 0, 0, 1, 0, 0, 0);
    delay(250);
    setLights(0, 0, 0, 1, 0, 0, 0, 0);
    delay(250);
    setLights(0, 0, 1, 0, 0, 0, 0, 0);
    delay(250);
    setLights(0, 1, 0, 0, 0, 0, 0, 0);
    delay(250);
    setLights(1, 0, 0, 0, 0, 0, 0, 0);
    delay(250);
    for(int i = 0; i < 5; i++)
    {
      setLights(0, 0, 1, 1, 0, 0, 0, 0);
      delay(250);
      setLights(0, 0, 0, 0, 0, 0, 0, 0);
      delay(250);
    }
    for(int i = 0; i < 3; i++)
    {
      setLights(1, 0, 0, 0, 0, 1, 1, 1);
      delay(250);
      setLights(0, 1, 0, 0, 1, 0, 1, 1);
      delay(250);
      setLights(0, 0, 1, 1, 0, 0, 1, 1);
      delay(250);
      setLights(0, 0, 0, 0, 0, 0, 1, 1);
      delay(250);
      setLights(0, 0, 1, 1, 0, 0, 1, 1);
      delay(250);
      setLights(0, 1, 0, 0, 1, 0, 1, 1);
      delay(250);
      setLights(1, 0, 0, 0, 0, 1, 1, 1);
      delay(250);
    }
    break;
  case 4:
    for(int i = 0; i < 5; i++)
    {
      for(int i = 0; i < 3; i++)
      {
        setLights(0, 0, 1, 0, 1, 0, 0, 1);
        delay(175);
        setLights(0, 0, 1, 0, 0, 1, 1, 0);
        delay(175);
      }
      for(int i = 0; i < 5; i++)
      {
        setLights(0, 0, 0, 0, 0, 0, 0, 0);
        delay(40);
        setLights(0, 0, 1, 0, 1, 0, 0, 1);
        delay(40);
      }
    }
    break;
  case 5:
    setLights(0, 0, 0, 0, 0, 0, 0, 0);
    for(int i = 0; i < 8; i++)
    {
      digitalWrite(light[i], HIGH);
      delay(500);
      setLights(0, 0, 0, 0, 0, 0, 0, 0);
      delay(500);
    }
    delay(4500);
    setLights(0, 1, 0, 0, 0, 0, 0, 0);
    delay(2000);
    setLights(0, 1, 0, 0, 1, 1, 1, 1);
    delay(500);
    setLights(1, 0, 1, 1, 0, 0, 0, 0);
    delay(500);
    for(int i = 0; i < 5; i++)
    {
      setLights(0, 1, 0, 0, 1, 1, 1, 1);
      delay(250);
      setLights(1, 0, 1, 1, 0, 0, 0, 0);
      delay(250);
    }
    setLights(1, 0, 0, 0, 0, 0, 0, 0);
    delay(4000);
    for(int i = 0; i < 5; i++)
    {
      setLights(0, 0, 0, 0, 0, 0, 0, 1);
      delay(300);
      setLights(1, 0, 1, 0, 0, 0, 0, 0);
      delay(300);
      setLights(0, 0, 0, 0, 0, 1, 0, 0);
      delay(300);
      setLights(1, 0, 1, 0, 0, 0, 0, 0);
      delay(300);
      setLights(0, 0, 0, 0, 0, 0, 1, 0);
      delay(300);
      setLights(1, 0, 1, 0, 0, 0, 0, 0);
      delay(300);
      setLights(0, 0, 0, 0, 1, 0, 0, 0);
      delay(300);
      setLights(1, 0, 1, 0, 0, 0, 0, 0);
      delay(300);
    }
    delay(2700);
    setLights(1, 1, 1, 1, 1, 1, 1, 1);
    delay(2000);
    setLights(0, 0, 0, 0, 0, 0, 0, 0);
    delay(1000);
    break;
  case 6:
    setLights(0, 1, 0, 0, 0, 0, 0, 0);
    delay(60000);
    setLights(1, 1, 1, 0, 1, 0, 0, 1);
    delay(1000);
    setLights(1, 0, 1, 0, 0, 1, 1, 0);
    delay(1000);
    setLights(1, 1, 1, 0, 0, 0, 0, 0);
    delay(58000);
    setLights(1, 0, 1, 0, 0, 1, 0, 1);
    delay(30000);
    break;
  }
}

