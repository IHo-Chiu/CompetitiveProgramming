
import requests
from bs4 import BeautifulSoup
import re
import random

response = requests.get('http://par.cse.nsysu.edu.tw/~advprog/star.php')
soup = BeautifulSoup(response.text, "html.parser")

results = soup.find_all('td', {'class': 'list_problem'})

problem_level_dict = {}
for i in range(len(results)):
    if i%2 == 1: continue
    problem_level_dict[int(results[i].text)] = int(results[i+1].text)


response = requests.get('https://cpe.cse.nsysu.edu.tw/cpe/test_data/problems')
soup = BeautifulSoup(response.text, "html.parser")

results = soup.find_all('a', href=re.compile('.pdf'))
results += soup.find_all('a', href=re.compile('uva.onlinejudge'))

for result in results:
    t = re.search(r'\d+', result.text)
    if not t: continue
    problem = int(t.group())
    if problem in problem_level_dict:
        del problem_level_dict[problem]


one_star_special_problems = [
    10041,10055,10035,100,10929,10101,10420,10008,10222,11332,10252,490,272,
    12019,10038,10056,10170,10268,10783,10812,11349,11461,11063,10071,10093,
    948,10019,10931,11005,10050,10193,10190,10235,10922,11417,10908,10221,
    10642,10242,10057,10062,299,10226,10189,10409,10415,118,11150,11321]

for problem in one_star_special_problems:
    if problem in problem_level_dict:
        del problem_level_dict[problem]

level_problem = [[],[],[],[]]
for problem, level in problem_level_dict.items():
    if level < 1 or level > 4: continue
    level_problem[level-1].append(problem)

random_problems = []
random_problems.append(random.sample(one_star_special_problems, 1))
random_problems.append(random.sample(level_problem[0], 2))
random_problems.append(random.sample(level_problem[1], 2))
random_problems.append(random.sample(level_problem[2], 1))
random_problems.append(random.sample(level_problem[3], 1))
print(random_problems)