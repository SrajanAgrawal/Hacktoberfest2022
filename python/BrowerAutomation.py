from helium import wait_until, Button
from selenium import webdriver
from selenium.webdriver.common import keys
from bs4 import BeautifulSoup
from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager
from helium import *

# brower = webdriver.Chrome(ChromeDriverManager().install())
link = 'https://ytmp3.cc/https://www.youtube.com/watch?v=QyuAPVcpAL8'
start_chrome(link)
if Link('Download mp3').exists():
    click(Link('Download mp3'))
    print('clicked')
# brower = webdriver.Chrome('chromedriver.exe')
# browser = brower.get(link)
# source = BeautifulSoup(brower.page_source)
# print(source.prettify())
# store = brower.find_element_by_id('input')
# store.send_keys('https://www.youtube.com/watch?v=QyuAPVcpAL8')  # your link
# store.send_keys(keys.Keys.ENTER)
# i = source.find(id='buttons')

# b = i.findAll('a')
# c = b[0]['href']
# while c == "":
#     c = b[0]['href']
#     try:
#         b = brower.find_element_by_css_selector('#buttons > a:nth-child(1)')
#         b.send_keys(keys.Keys.ENTER)
#     except:
#         print('waiti')

# brower.refresh()
