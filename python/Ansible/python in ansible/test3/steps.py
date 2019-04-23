import json
import array

from pprint import pprint
# get the version depend trees
versions_deps = []
with open('data.json') as f:
    data = json.load(f)

from_version = data["deploy_from_version"]
to_version = data["deploy_to_version"]
version_line = []

for (k,v) in data["version"].items():
   versions_deps.append(k)
   #if k == from_version:
   print "|-" + k 
   for i in v:
     print  "|--" + i["name"]
print versions_deps




from_v = "P2019-04-01"
to_v   = "P2019-05-01"
steps = list()

#step1 degrade to base line version
step1 = from_v[0:-2] + "00"
temp = []
temp.append("0") # 0:degrade
temp.append(from_v)
temp.append(step1)
steps.append(temp)
# step2 up or down main version
### get the main version number
step2 = from_v[6:8] 

if step2[0] == "0":
   step2 = step2[1]

int_step2 = int(step2)
step3 = to_v[6:8] 

if step3[0] == "0":
   step3 = step3[1]

int_step3 = int(step3)
temp = []
f = min(int_step3, int_step2)
t = max(int_step2, int_step3)

num = 0
for i in range(f, t):
   step_f = []
   step_t = []
   temp = []
   pos = 0
   if (int_step2 < int_step3):
      temp.append("1")  # 1:up
   else:
      temp.append("0")  # 0:down
   if i < 9 and int_step2 < int_step2:   
     step_f = from_v[0:7]  + str(i) + "-00"
     step_t = to_v[0:7] + str(i+1) + "-00"
   elif i > 9 and int_step2 < int_step2: 
     step_f = from_v[0:6]  +  str(i) + "-00"
     step_t = to_v[0:6] + str( i+1) + "-00"

   if i < 9 and int_step2 > int_step3:
     step_f = from_v[0:7]  + str(int_step2 - num) + "-00"
     step_t = to_v[0:7] + str(int_step2 - num - 1) + "-00"
     num = num + 1
   elif i > 9 and int_step2 > int_step2: 
     step_f = from_v[0:6]  +  str(int_step2 - num) + "-00"
     step_t = to_v[0:6] + str(int_step2 - num -1) + "-00"

   temp.append(step_f)
   temp.append(step_t)
   steps.append(temp)


# step3 update min version
temp = []
temp.append("1")
temp.append(to_v[0:9] + "00")
temp.append(to_v)
steps.append(temp)

#print temp
print "from :" + from_v + " to " + to_v
#print steps
for i in steps:
    pprint(i)

