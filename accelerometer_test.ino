#define x A0
#define y A1
#define z A2

int x_val;
int y_val;
int z_val;

int x_val2;
int y_val2;
int z_val2;

void setup()
{
    pinMode(x, INPUT);
    pinMode(y, INPUT);
    pinMode(z, INPUT);

    Serial.begin(9600);

    // Store initial sensor position
    x_val2 = analogRead(x);
    y_val2 = analogRead(y);
    z_val2 = analogRead(z);
}

void loop()
{
    // Read current values
    x_val = analogRead(x);
    y_val = analogRead(y);
    z_val = analogRead(z);

    // Calculate axis movement
    int x_axis = x_val - x_val2;
    int y_axis = y_val - y_val2;
    int z_axis = z_val - z_val2;

    if (y_axis >= 50)
    {
        Serial.println("Backward");
    }
    else if (y_axis <= -50)
    {
        Serial.println("Forward");
    }
    else if (x_axis >= 50)
    {
        Serial.println("Left");
    }
    else if (x_axis <= -50)
    {
        Serial.println("Right");
    }
    else
    {
        Serial.println("Stop");
    }

    delay(1000);
}
