#!/bin/bash

API_KEY="c544943ca4204a04b955eb69025a51d3"
REGION="germanywestcentral"

inputfile=""
outputfile="./output.txt"
language="ru"
while [ -n "$1" ]
do
	IFS='=' read -ra cname <<< "$1"
	case ${cname[0]} in
		'-l') language="${cname[1]}";;
	       	'-o') outputfile="${cname[1]}";;
		'-i') inputfile="${cname[1]}";;
	esac
	shift
done
if [ -z $inputfile ]
then 
	echo "Use default input file (input.txt)"
	inputfile= "./input.txt"	
fi


if [ ! -e $inputfile ]
then
	echo "Input file not found"
	exit
fi
text=$(cat $inputfile)

curl -X POST "https://api.cognitive.microsofttranslator.com/translate?api-version=3.0&to=$language" \
	-H "Ocp-Apim-Subscription-Key: $API_KEY" \
	-H "Ocp-Apim-Subscription-Region: $REGION" \
	-H "Content-Type: application/json" \
	-d "[{'Text':'\"$text\"'}]" | python3 decodejson.py > $outputfile





