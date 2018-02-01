from bs4 import BeautifulSoup
from urllib import request
import sys
import os
import argparse

PATH_DIR = "/acmicpc/"
BASE_URL = "https://www.acmicpc.net/problem/"

def get_row(no, name, is_solved):
  if is_solved:
    return "[%d](%s%d) | %s | [Link](%s%d/Problem.md) | [Link](%s%d/%d.cpp)" % (no, BASE_URL, no, name, PATH_DIR, no, PATH_DIR, no, no)
  else:
    return "[%d](%s%d) | %s | - | -" % (no, BASE_URL, no, name)

def check_solved(no):
  return os.path.isfile('%d/%d.cpp' % (no, no))

with open('cookie.txt', 'r') as f:
  cookie = f.read()

header = {"User-Agent": "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36"}
header["Cookie"] = cookie

link_no = 1

parser = argparse.ArgumentParser(description='acmicpc problem list parser')
parser.add_argument('-n', '--no', type=int, metavar="link_no", help='link no', required=True)

args = parser.parse_args()
link_no = args.no

try:
  req = request.urlopen(request.Request("https://www.acmicpc.net/problemset/%d" % link_no, headers=header))
  res = req.read()
except error.HTTPError as e:
  sys.exit()
soup = BeautifulSoup(res, "html.parser")
problem_name = list(map(lambda x: x.text, soup.find_all('td', class_='click-this')))
problem_no = list(map(lambda x: int(x.text), soup.find_all('td', class_='list_problem_id')))

if(len(problem_no) != len(problem_name)):
  print("Size is not same...")
  sys.exit()

header = "번호 | 문제 이름 | 문제 내용 | 소스코드\n--- | --- | --- | ---\n".encode('utf-8')


f = open("ProblemSet/ProblemSet%03d.md" % link_no, "wb")
f.write(("# %d ~ %d\n\n" % (1000 + 100 * (link_no - 1), 1000 + 100 * link_no - 1)).encode('utf-8'))
f.write(header)
for no, name in zip(problem_no, problem_name):
  f.write((get_row(no, name, check_solved(no)) + "\n").encode('utf-8'))
f.close()