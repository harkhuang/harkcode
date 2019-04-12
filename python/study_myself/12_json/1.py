import json

from pprint import pprint

with open('data.json') as f:
    data = json.load(f)

#pprint(data["version"])
#pprint(data["version"]["P01"][0]["name"])

for (k, v) in data["version"].items():
   
   ##  from P0101 ~  P0202
   ## from P0202 ~ P0101
   pprint("Key: " + k  + "\n")
   #pprint("Value: " + str(v) + "\n")

versions = []

for (k, v) in data["version"].items():
   
   ##  from P0101 ~  P0202
   ##  from P0202 ~ P0101
   versions.append(k)
   pprint("key:" + k + "\n")

for x in versions:
    pprint("myversionlist:" + x + "\n")

#for x in versions:
#    pprint("myversionlist:" + x + "\n")

#with open('demo.json') as f:
#    data1 = json.load(f)
#pprint(data1["maps"][0]["id"])
#pprint(data1["masks"]["id"])
#pprint(data1["om_points"])






## 获取操作信息
version_to = P0202
version_from = P0101 



## 获取版本库信息
versions = []
with open('data.json') as f:
    data = json.load(f)







