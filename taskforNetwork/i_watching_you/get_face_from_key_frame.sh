curl -X POST  "https://bkiiiiiiiiii.cognitiveservices.azure.com/face/v1.0/detect?returnFaceId=true&faceRectangle={string}&recognitionModel=recognition_03&returnRecognitionModel=false&detectionModel=detection_03&faceIdTimeToLive=86400" \
-H "Content-Type: application/octet-stream" \
-H "Ocp-Apim-Subscription-Key: 631264817e9c4b279d058c67d75db84d" \
--data-binary "@$1" >> json_faces.txt
echo " " >> json_faces.txt
echo $1 >> json_faces.txt
