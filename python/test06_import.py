
import time
import requests

# print("start")
# time.sleep(2)
# print("finish")

response = requests.get("https://gitee.com/kongfanhe/opencv_tutorial")
print(response.content)