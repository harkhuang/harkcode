import json

from pprint import pprint

# get the version depend trees
versions_deps = []
with open('data.json') as f:
    data = json.load(f)


print data

print data['version']['P2019-01-00'][0]

print data['version']['P2019-01-00'][0]['detail'][0]

for (k,v) in data["version"].items():
   versions_deps.append(k)
   pprint(k + '\n')

# get the deploy steps
versions_deps.sort()

for i in versions_deps:
   pprint(i)


# print "===================="
# pprint(versions_deps)
# pprint(versions_deps[0])
# pprint(versions_deps[0:2])
# pprint(versions_deps[-1])
# pprint(versions_deps[0:4])
