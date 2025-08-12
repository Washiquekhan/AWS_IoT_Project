 AWS_IoT_Project
 AWS IoT Temperature Logger

A small IoT project that reads temperature from a DHT11 sensor using ESP8266, sends data to AWS IoT Core, stores it in DynamoDB, and triggers an SNS alert when temperature exceeds a threshold.

📌 Features
- Real-time temperature reading via ESP8266
- Secure MQTT communication with AWS IoT Core
- Automatic storage in DynamoDB
- Email/SMS alerts for high temperature
- Easy to set up and deploy

 🛠 Tech Stack
- ESP8266, DHT11
- AWS IoT Core, Lambda, DynamoDB, SNS
- Arduino IDE, Python (for Lambda)

🚀 Setup
1. Create AWS IoT Thing & download certificates
2. Update `temperature_logger.ino` with Wi-Fi and AWS details
3. Deploy Lambda function and set SNS topic
4. Create IoT Rule to trigger Lambda
5. Upload code to ESP8266

 📂 Folder Structure
```
aws-iot-temperature-logger/
│── esp8266_code/
│   └── temperature_logger.ino
│── lambda_function/
│   └── lambda_alert.py
│── README.md
│── LICENSE
```

 📜 License
MIT License
