from selenium import webdriver
import time
browser = webdriver.Chrome(executable_path=r"E:\chromedriver.exe")
browser.get('https://www.acmicpc.net/login?next=%2F')
ID = "isolet"
PW = "Isolet#3707"
elem_login = browser.find_element_by_name("login_user_id")
elem_login.send_keys(ID)
elem_login = browser.find_element_by_name("login_password")
elem_login.send_keys(PW)
browser.find_element_by_xpath('/html/body/div[3]/div[3]/div/div/form/div[4]/div[2]/button').click()
while True:
  browser.get('https://www.acmicpc.net/submit/16972/11963170') # 이전에 제출한 곳의 주소
  browser.find_element_by_xpath('//*[@id="submit_form"]/div[4]/div/button').click()
  time.sleep(9.5)
