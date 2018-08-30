import urllib2
import sys 
enable_proxy = True
proxy_handler = urllib2.ProxyHandler({"http" : 'http://www.baidu.com:8080'})
null_proxy_handler = urllib2.ProxyHandler({})
if enable_proxy:
    opener = urllib2.build_opener(proxy_handler)

    print(opener) 
else:
    opener = urllib2.build_opener(null_proxy_handler)
 
    print(opener) 
urllib2.install_opener(opener)
