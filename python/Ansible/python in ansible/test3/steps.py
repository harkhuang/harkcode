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
pre_version = []
print ("from=>" + from_version)
print ("to=>" + to_version)

Line_steps = list()
temp = []
temp1 = []
### 如果存在空指针的情况 请对应处理
###

print ("== 第一步找到回退版本===============================")

for (k,v) in data["version"].items():
    for i in v:
      if (i["name"] == from_version):
         temp.append("0")
         temp.append(i["name"])
         temp.append(i["detail"]["preversion"])
         Line_steps.append(temp)
         pre_version = i["detail"]["preversion"]
print (Line_steps)



## 根据依赖树（json）升级/回退主要版本号
temp2 = []
flag = "-1" 
print ("== 第二步找到回退版本===============================")
for (k,v) in data["version"].items():
    pre_version = k
    if (from_version[0:8] > to_version[0:8]):      
      if( from_version[0:8] >= k[0:8]  >= to_version[0:8]):
         print("down->"  + k)
         #temp2.append("0")       
         flag = "0" 
         temp2.append(k)  
    if (from_version[0:8] < to_version[0:8]):
      if(from_version[0:8] <= k[0:8]  <= to_version[0:8]):
        print("up->"  + k)
        #temp2.append("0") 
        flag = "1"
        temp2.append(k) 
    if (from_version == to_version):
      pre = []     
      print ("do nothing")

print ("==test in temp2 ===============================")

if flag == "0":
   for i in range(len(temp2) , 0):
      print (i)
      
if flag == "1":
   for i in range( 0 , len(temp2) ):
      print (i) 
      # temp = []      
      # temp.append(flag  )
      # temp.append(pre_version)
      # temp.append(i)
      # print(temp)
      # Line_steps.append(temp)
print  (Line_steps)
print ("==end temp2 ===============================")   
# if flag != "-1":
#   for i in temp2: 
#     print (i)
#     if(i == "0"):     
#       temp = []      
#       temp.append(flag  )
#       temp.append(pre_version)
#       temp.append(i)
#       print(temp)
#       Line_steps.append(temp)
#     elif(i == "1"):
#       temp = []      
#       temp.append(flag  )
#       temp.append(pre_version)
#       temp.append(i)
#       print(temp)
#       Line_steps.append(temp)
#     pre_version = i

temp3 = []
print ("== 第三步找到回退版本===============================")
for (k,v) in data["version"].items():
    for i in v:
      if (i["name"] == to_version):
         print ("up->" + pre_version + " to "+to_version)
         temp = []
         temp.append("1") 
         temp.append(pre_version)
         temp.append(to_version)
         Line_steps.append(temp)
print ("==test===============================")
print (Line_steps)
print ("=========================================")
