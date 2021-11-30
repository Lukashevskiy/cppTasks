#!/bin/bash

API_KEY="9bf007a897f54e4a94203f8aa88cd2b1"
REGION="westeurope"

inputfile="./input.txt"
outputfile="./output.txt"
language="ru"

while [ -n "$1" ]
do 
	case $1 in
		"-l") language=(`$1 | cut -f 2 -d'='`);;
	       	"-o") outputfile=(`$1 | cut -f 2 -d'='`);;
		"-i") inputfile=(`$s1 | cut -f 2 -d'='`);;
	esac
	shift
done

text=$(cat $inputfile)

curl -X POST "https://api.cognitive.microsofttranslator.com/translate?api-version=3.0&to=$language" \
	-H "Ocp-Apim-Subscription-Key: $API_KEY" \
	-H "Ocp-Apim-Subscription-Region: $REGION" \
	-H "Content-Type: application/json" \
	-d "[{'Text':'\"$text\"'}]" | python3 decodejson.py > $outputfile


