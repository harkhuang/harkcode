import json
import array
from pprint import pprint
# get the version depend trees
versions_deps = []
with open('data.json') as f:
    data = json.load(f)
from_version = data["deploy_from_version"]
to_version = data["deploy_to_version"]
print ("from=>" + from_version)
print ("to=>" + to_version)

Line_steps = list()
temp = []
temp1 = []
### 如果存在空指针的情况 请对应处理
###
pre_version = []
print ("== 第一步找到回退版本===============================")
flag = 0  # 00 version flag
for (k,v) in data["version"].items():
    if k == from_version:
       pre_version = k
       flag = 1
       break
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
pre_version = []
print ("== 第二步找到回退版本===============================")
for (k,v) in data["version"].items():
    ## 降级    
    # cur = 04-00
    if (from_version[0:8] > to_version[0:8]) :      
      if( from_version[0:8] >= k[0:8]  >= to_version[0:8]):
         print("from=" + from_version[0:8] +"->" +  k[0:8]  + "->" + to_version[0:8] )
         print("down->"  + k)
         if not pre_version:
            print ("do noting")
         else:
          temp = []
          temp.append("0")
          temp.append(k)
          temp.append(pre_version)
          if flag == 0:
             Line_steps.insert(1,temp)
          if flag == 1:
             Line_steps.insert(0,temp)
          print (Line_steps)
    ## 升级
    elif (from_version[0:8] < to_version[0:8]):
      if(from_version[0:8] <= k[0:8]  <= to_version[0:8]) :
        if not pre_version:
          print ("do noting")
        else :     
            print("up->"  + k)
            temp = []
            temp.append("1")
            temp.append(pre_version)
            temp.append(k)
            Line_steps.append(temp)      
            print (Line_steps)
    pre_version = k

    if (from_version == to_version):
      print ("do nothing")

 
print ("== 第三步找到回退版本===============================")
for (k,v) in data["version"].items():
    for i in v:
      if (i["name"] == to_version):
         print ("up->" + pre_version + "to->"+to_version)
         temp = []
         temp.append("1") 
         temp.append(i["detail"]["preversion"])
         temp.append(to_version)
         Line_steps.append(temp)

print ("==test===============================")
for i in Line_steps:
      print (i)
print (Line_steps)
print ("=========================================")
