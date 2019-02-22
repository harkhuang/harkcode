import json
import array
from pprint import pprint
# get the version depend trees
versions_deps = []
with open('data.json') as f:
    data = json.load(f)

for (k,v) in data["version"].items():
   versions_deps.append(k)
   pprint(k + '\n')

from_v = "P2019-01-02"
to_v = "P2019-04-03"
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
pprint(step2)
if step2[0] == "0":
   step2 = step2[1]
pprint (step2)
int_step2 = int(step2)
step3 = to_v[6:8] 
pprint(step3)
if step3[0] == "0":
   step3 = step3[1]
pprint (step3)
int_step3 = int(step3)
temp = []
f = min(int_step3, int_step2)
t = max(int_step2, int_step3)

for i in range(f, t):
   step_f = []
   step_t = []
   temp = []
   if (int_step2 < int_step3):
      temp.append("1")  # 1:up
   else:
      temp.append("0")  # 0:down
   if i < 9:  # 
     step_f = from_v[0:7]  + str(i) + "-00"
     print step_f        
   else :
     step_f = from_v[0:6]  +  str(i) + "-00"
     print step_f
   if i+1 < 9:
      step_t = to_v[0:7] + str(i+1) + "-00"
   else:
      step_t = to_v[0:6] + str(i+1) + "-00"
   temp.append(step_f)
   temp.append(step_t)
   steps.append(temp)


# step3 update min version
temp = []
temp.append("1")
temp.append(to_v[0:9] + "00")
temp.append(to_v)
steps.append(temp)

print temp


print "from :" + from_v + " to " + to_v
print steps
for i in steps:
   pprint(i)
