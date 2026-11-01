int red = 7;
int yellow = 6;
int green = 5;

int start = 13;
int stop = 12;

boolean running = false;

boolean waitStop(int time)
{
  for (int i = 0; i < time; i += 10)
  {
    if (digitalRead(stop) == LOW)
      return false;

    delay(10);
  }

  return true;
}

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  pinMode(start, INPUT_PULLUP);
  pinMode(stop, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(start) == LOW)
    running = true;

  if (digitalRead(stop) == LOW)
  {
    running = false;

    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  }

  if (running)
  {
    digitalWrite(red, HIGH);

    if (!waitStop(2000))
    {
      running = false;
      return;
    }

    digitalWrite(yellow, HIGH);

    if (!waitStop(700))
    {
      running = false;
      return;
    }

    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);

    digitalWrite(green, HIGH);

    if (!waitStop(2000))
    {
      running = false;
      return;
    }

    for (int i = 0; i < 6; i++)
    {
      digitalWrite(green, LOW);

      if (!waitStop(250))
      {
        running = false;
        return;
      }

      digitalWrite(green, HIGH);

      if (!waitStop(250))
      {
        running = false;
        return;
      }
    }

    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);

    if (!waitStop(700))
    {
      running = false;
      return;
    }

    digitalWrite(yellow, LOW);
  }
}
