import argparse
import sys
import os
import re
from urllib import request, error
from bs4 import BeautifulSoup
import bs4.element

IMAGE_NO = 1

def image(tag, namespace=''):
  global IMAGE_NO
  src = tag['src']
  if src.startswith('/'):
    src = 'https://www.acmicpc.net' + src
  s = '![%s%d](%s)' % (namespace, IMAGE_NO, src)
  IMAGE_NO += 1
  return s

def code(tag):
  matching = {'c++': 'cpp'}
  lang = ''
  for class_name in tag['class']:
    if 'brush:' in class_name:
      lang = class_name[class_name.find(':') + 1:].strip()[:-1]
  if lang in matching:
    lang = matching[lang]
  return '```%s\n%s```\n' % (lang, tag.text)

def unordered_list(tag):
  result = ''
  for item in tag:
    if item.name == 'li':
      for item2 in item.children:
        if type(item2) is bs4.element.NavigableString:
          result += '* ' + item.text
        else:
          print("UNKNOWN ELEMENT [unordered_list]")
      result += '\n'
  return result + '\n'

def parsing_tag(parent_tag):
  content = ''
  for item in parent_tag.children:
    if type(item) is bs4.element.NavigableString:
      pass
    elif type(item) is bs4.element.Tag:
      if item.name == 'p':
        for item2 in item.children:
          if type(item2) is bs4.element.NavigableString:
            content += item2.lstrip() # by. 1001
          elif type(item2) is bs4.element.Tag:
            if item2.name == 'code':
              content += '`' + item2.text + '`'
            elif item2.name == 'img':
              content += image(item2, problem_title)
            elif item2.name == 'sup':
              content += '<sup>' + item2.text + '</sup>'
            else:
              print("UNKNOWN TAG...[in p tag :%s]" % item2.name)
        content += '\n\n'

      elif item.name == 'pre':
        content += code(item)
      elif item.name == 'ul': # ex. 1013
        content += unordered_list(item)
      elif item.name == 'blockquote':
        content += '> ' + item.text + '\n\n'
      elif item.name == 'table':
        content += '\n' + str(item) + '\n\n'
      elif item.name == '':
        pass
      else:
        print("UNKNOWN TAG...[global tag :%s]" % item.name)
    else:
      print("UNKNOWN ELEMENT...")
  return re.sub(r"\n{3,}", r"\n\n", content)

parser = argparse.ArgumentParser(description='acmicpc problem parser')
parser.add_argument('-n', '--no', type=int, metavar="problem_no", help='problem no', required=True)

header = {"User-Agent": "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36"}
header["Cookie"] = ""

args = parser.parse_args()
problem_no = args.no
try:
  req = request.urlopen(request.Request("https://www.acmicpc.net/problem/%d" % problem_no, headers=header))
  res = req.read()
except error.HTTPError as e:
  sys.exit()

soup = BeautifulSoup(res, "html.parser")

problem_title = soup.find(id="problem_title").text

# parsing problem content...
problem_tag = soup.find(id="problem_description")
problem_content = parsing_tag(problem_tag)

# parsing input content...
input_tag = soup.find(id="problem_input")
input_content = parsing_tag(input_tag)

# parsing output content...
output_tag = soup.find(id="problem_output")
output_content = parsing_tag(output_tag)

# parsing classify
classify_tag = soup.find_all('a', class_="spoiler-link")
classify_content = "\n".join(["- " + item.text for item in classify_tag]) + "\n"

if not os.path.isdir('%d' % problem_no):
  os.makedirs('%d' % problem_no)

with open('%d/Problem.md' % problem_no, 'wb') as f:
  f.write(('# [%s](https://www.acmicpc.net/problem/%d)\n\n' % (problem_title, problem_no)).encode())
  f.write('## 문제\n'.encode())
  f.write(problem_content.encode())
  f.write('## 입력\n'.encode())
  f.write(input_content.encode())
  f.write('## 출력\n'.encode())
  f.write(output_content.encode())
  f.write('## 분류\n'.encode())
  f.write(classify_content.encode())
