#include <VirtualWire.h>

#define x A0
#define y A1
#define z A2

char *data;

int x_val;
int y_val;
int z_val;

int x_val2;
int y_val2;
int z_val2;

void setup()
{
    vw_set_tx_pin(12);
    vw_setup(2000);

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
    // Read current sensor values
    x_val = analogRead(x);
    y_val = analogRead(y);
    z_val = analogRead(z);

    // Calculate change from initial position
    int x_axis = x_val - x_val2;
    int y_axis = y_val - y_val2;
    int z_axis = z_val - z_val2;

    // Backward
    if (y_axis >= 50)
    {
        data = "b";

        vw_send((uint8_t *)data, strlen(data));
        vw_wait_tx();

        Serial.println("Backward");
    }

    // Forward
    else if (y_axis <= -50)
    {
        data = "f";

        vw_send((uint8_t *)data, strlen(data));
        vw_wait_tx();

        Serial.println("Forward");
    }

    // Left
    else if (x_axis >= 50)
    {
        data = "l";

        vw_send((uint8_t *)data, strlen(data));
        vw_wait_tx();

        Serial.println("Left");
    }

    // Right
    else if (x_axis <= -50)
    {
        data = "r";

        vw_send((uint8_t *)data, strlen(data));
        vw_wait_tx();

        Serial.println("Right");
    }

    // Stop
    else
    {
        data = "s";

        vw_send((uint8_t *)data, strlen(data));
        vw_wait_tx();

        Serial.println("Stop");
    }

    delay(500);
}
