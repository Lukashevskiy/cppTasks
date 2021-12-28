import requests
import json
import sys


key = "68f77c57427c41198d20ba540e8ca54c"
endpoint = "https://wannadie.cognitiveservices.azure.com/text/analytics/v3.1/sentiment?&loggingOptOut=1&opinionMining=1&stringIndexType=TextElement_v8"
headers = { "Content-Type": "application/json", 
            "Ocp-Apim-Subscription-Key": key }

path_data = sys.argv[1]

text = "".join(open(path_data, 'r').readlines()).replace('\n', '') 
data = '{ documents: [{ id: "1", language:"en", text: "' + text + '" }]}' 

r = requests.post(endpoint, headers=headers, data= data)


page = '''<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	
</head>
<body>
	
	<div style="width: 150px; height: auto; float: left;">
		<div style=" margin-bottom: 10px;">  
			<div style=" width:30px; height: 30px; background-color: red;"></div>
			<label style=" ">negative</label> 
		</div>
		<div style=" margin-bottom: 10px;">  
			<div style=" width:30px; height: 30px; background-color: black;"></div>
			<label style=" ;">neutral</label> 
		</div>
		<div>  
			<div style=" width:30px; height: 30px; background-color: green;"></div>
			<label style=";"> positive </label> 
		</div>
	</div>
	<div style="width: 1000px; height: auto; margin:auto; box-shadow: 0 0 10px rgba(0,0,0,0.5); border-radius: 30px; padding: 50px; text-align: center; font-size: 21pt; font-family: Calibri;">
{0}
<br>
{1}
	</div>
</body>
</html>'''

#with open('/home/dmitriy/Documents/out.html', 'w') as f:
text1 = ''
for element in r.json()['documents'][0]['sentences']:
    sentiment = element['sentiment']
    start = element['offset']
    stop = start + element['length']
    color = "black"
    if sentiment == 'negative':
        color = "red"
    elif sentiment == 'positive':
        color = 'green'   
    text1 += '\t\t'
    text1 += '<span style="color:{0}">{1}</span>'.format(color, element['text'])
    text1 += '\n'

open('./out.html', 'w').writelines(page.format(text,text1))
