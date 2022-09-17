
import requests
import json
import pandas as pd
from datetime import datetime

user_list = ["sanir456","jpray","amit_code_007","khushalabrol14"]
l = []
for i in user_list:
    query = """query {
        matchedUser(username: \"""" + i + """") {
        username
        submitStats: submitStatsGlobal {
        acSubmissionNum {
        difficulty
        count
        submissions
        }
        }
        }
    }"""
    url = 'https://leetcode.com/graphql/'
    r = requests.post(url, json={'query': query})
    data = json.loads(r.text)
    count = data["data"]["matchedUser"]["submitStats"]["acSubmissionNum"]
    l.append(count[0]["count"])


link = "https://docs.google.com/forms/u/0/d/e/1FAIpQLSeDhUdcG00t0FadoXmplbEIWg5gbCN0GAzrS12ctonjNdPFdg/formResponse?entry.1870839823="+str(l[0])+"&entry.649122011="+str(l[1])+"&entry.452802326="+str(l[2])+"&entry.1820971951="+str(l[3])

import urllib.request
urllib.request.urlopen(link)
