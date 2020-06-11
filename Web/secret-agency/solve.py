import requests

url = "http://159.65.13.76:1337/"
header = {"User-Agent": "eevee"}
source = requests.get(url, headers = header)
print(source.text)