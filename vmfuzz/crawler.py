import requests
from multiprocessing.dummy import Pool
import sys
from threading import Thread
 
with open("moz_top_500.txt", "rt") as f:
    moz_top_500_urls = f.read()
 
urls = moz_top_500_urls.split()
"""
for url in urls:
    print("[+] requesting [http://www." + url + "]......")
    try:
        requests.get("http://"+url, timeout=0.1)
    except KeyboardInterrupt:
        sys.exit(1)
    except Exception as e:
        #print(str(e))
        sys.exit()
        pass
"""
pool = Pool(500)
futures = []
for url in urls:
    futures.append(pool.apply_async(requests.get, ["http://"+url]))
 
 
i = 0
for future in futures:
    print("[+] requesting [http://www." + urls[i] + "]......")
    i = i + 1
    try:
        future.get()
    except KeyboardInterrupt:
        sys.exit()
    except Exception as e:
        print(str(e))
    #req_proc= multiprocessing.Process(target=requests.get, args=("http://" + url,), kwargs={'timeout':1,})
    #req_proc.start()