#include <stdio.h>
#include <string.h>

#define MAX_SENSORS 10
#define MAX_SENSOR_ID_LENGTH 10

typedef struct SensorInfo {
    char sensor_id[MAX_SENSOR_ID_LENGTH];
    float temperature;
    int humidity;
    int light_intensity;
} SensorInfo;

void parse_data(const char *data, SensorInfo *sensor_array, int *num_sensors) {
    char sensor_id[MAX_SENSOR_ID_LENGTH];
    float temperature;
    int humidity;
    int light_intensity;

    *num_sensors = 0;

    const char *delimiters = "-:T-H-L"; // Delimiters to split the data
    char *token = strtok((char *)data, delimiters);

    while (token != NULL && *num_sensors < MAX_SENSORS) {
        // Read sensor ID
        strcpy(sensor_id, token);

        // Read temperature, humidity, and light intensity values
        token = strtok(NULL, delimiters);
        sscanf(token, "%f", &temperature);

        token = strtok(NULL, delimiters);
        sscanf(token, "%d", &humidity);

        token = strtok(NULL, delimiters);
        sscanf(token, "%d", &light_intensity);

        // Populate the sensor information in the array
        strcpy(sensor_array[*num_sensors].sensor_id, sensor_id);
        sensor_array[*num_sensors].temperature = temperature;
        sensor_array[*num_sensors].humidity = humidity;
        sensor_array[*num_sensors].light_intensity = light_intensity;

        (*num_sensors)++;

        // Move to the next sensor
        token = strtok(NULL, delimiters);
    }
}

int main() {
    const char data[] = "S1-T:36.5-H:100-L:50";
    SensorInfo sensor_array[MAX_SENSORS];
    int num_sensors;

    parse_data(data, sensor_array, &num_sensors);

    printf("Sensor Info:\n");
    printf("_____________________\n");

    for (int i = 0; i < num_sensors; i++) {
        printf("Sensor ID: %s\n", sensor_array[i].sensor_id);
        printf("Temperature: %.1f C\n", sensor_array[i].temperature);
        printf("Humidity: %d\n", sensor_array[i].humidity);
        printf("Light Intensity: %d%%\n", sensor_array[i].light_intensity);
        printf("\n");
    }

    return 0;
}
