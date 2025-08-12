import json
import boto3

sns = boto3.client('sns')
TOPIC_ARN = "arn:aws:sns:us-east-1:123456789012:HighTempAlert"

def lambda_handler(event, context):
    for record in event.get('Records', []):
        payload = json.loads(record.get('body', '{}'))
        temperature = payload.get("temperature", 0)
        
        if temperature > 30:
            sns.publish(
                TopicArn=TOPIC_ARN,
                Message=f"High Temperature Alert! Current temperature: {temperature}°C",
                Subject="AWS IoT Alert"
            )
    return {"statusCode": 200, "body": "Processed"}
