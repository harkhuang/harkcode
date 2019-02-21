import json

from pprint import pprint

# get the version depend trees
versions_deps = []
with open('data.json') as f:
    data = json.load(f)

for (k,v) in data["version"].items():
   versions_deps.append(k)
   pprint(k + '\n')

# get the deploy steps

versions_deps.sort()
#versions_deps.append("P99")
#versions_deps.append("P77")
#versions_deps.append("P88")
for i in versions_deps:
   pprint(i)

pprint(versions_deps)
pprint(versions_deps[0])
pprint(versions_deps[0:2])
pprint(versions_deps[-1])
pprint(versions_deps[0:4])




#  get version detail
version_to = 'P0202'
version_from = 'P0101' 
# get main index  
main_version_from = version_from[0:3]
main_version_to = version_to[0:3]
min_version_from = version_from[3:5]
min_version_to = version_to[3:5]

main_index_from = versions_deps.index(main_version_from)
main_index_to = versions_deps.index(main_version_to)
#min_index_from = versions_deps.index(min_version_from)
#min_index_to = versions_deps.index(min_version_to)

print(main_index_from)


main_steps = []
#main_steps = [ versions_deps[int(main_index_from)] for i in versions_deps ]
#pprint(main_steps)

i = 0

pprint(main_index_to)
pprint(main_index_from)
for i in  range(main_index_from, main_index_to + 1):
   main_steps.append(versions_deps[i])

if main_index_from < main_index_to:

   pprint("this is main version to update")
   pprint(main_steps)
else:
   pprint("this is main version to degrade")
   pprint(main_steps.reverse)
# get min index

# from P0101 to P0202

# get version form 






#pprint(versions_deps.index("0"))
