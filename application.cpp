#include "application.h"
#include "HttpClient.h"

/**
* Declaring the variables.
*/
HttpClient http;

http_header_t headers[] = {
    { "Content-Type", "application/json" },
    { "Accept" , "application/json" },
    { "Authorization" , "Bearer DEVICE_SECRET_KEY"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
};

http_request_t request;
http_response_t response;

void setup() {
    Serial.begin(9600);
}

void loop() {
    // Request parameters
    request.hostname = "api.wia.io";
    request.port = 80;
    request.path = "/v1/events";

    // Body parameters in JSON format
    request.body = "{\"name\":\"temperature\", \"data\":\"21.5\"}";

    // POST request
    http.post(request, response, headers);

    // Response
    Serial.print("Application>\tResponse status: ");
    Serial.println(response.status);

    Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);

    delay(2000);
}
