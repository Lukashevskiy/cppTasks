curl -v -X POST "https://aza.cognitiveservices.azure.com/face/v1.0/detect?returnFaceId=true&faceRectangle={string}&recognitionModel=recognition_03&returnRecognitionModel=false&detectionModel=detection_03&faceIdTimeToLive=86400" \
-H "Content-Type: application/octet-stream" \
-H "Ocp-Apim-Subscription-Key: bd975a30ef924096add2e4f1169c167d" \
--data-binary "@./img.jpg" | python3 facereqtangle.py
