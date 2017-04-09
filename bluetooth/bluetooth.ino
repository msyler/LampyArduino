const int BLED   = 9;
const int GLED   = 10;
const int RLED   = 11;

String inText;
String lastCommand;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);

}

void loop()
{
  Serial.flush();

  if (Serial.available() > 0) {
    // read the incoming byte:
    inText = Serial.readString();

    int lastIndex = inText.lastIndexOf('R');
    lastCommand = inText.substring(lastIndex);
   
    //Get RGB Command
    int R =   lastCommand.substring( 1, 4 ).toInt();
    int G =   lastCommand.substring( 5, 8 ).toInt();
    int B =   lastCommand.substring( 9 ).toInt();

    analogWrite(RLED, R);
    analogWrite(GLED, G);
    analogWrite(BLED, B);
  }

}

