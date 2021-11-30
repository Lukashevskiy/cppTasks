import sys, json
print(json.load(sys.stdin)[0]['translations'][0]['text'])

