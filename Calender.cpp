#include<bits/stdc++.h>
using namespace std;


void init_code(){
	#ifndef ONLINE_JUDGE
	freopen("F:/CP/input.txt", "r", stdin);
	freopen("F:/CP/output.txt", "w", stdout);
	#endif 
}

set<string> users;
map<string,vector<set<string>>> calenderDay;
int event=0;
map<string,vector<int>> eventDate;
map<int,set<string>> events;
map<int,pair<int,int>> eventsTime;
map<string,set<int>> userEvent;

string registerUser()
{
	string name;
	cin>>name;
	if(users.find(name)!=users.end())
		return "Failure";
	users.insert(name);
	return "Success";
}
string createEvent()
{
	string day;
	cin>>day;
	int startTime;
	cin>>startTime;
	int duration;
	cin>>duration;
	int endTime = startTime + duration;
	int usersCount;
	cin>>usersCount;
	vector<string> userName(usersCount);
	for(int i=0;i<usersCount;i++)
		cin>>userName[i];
	if(endTime>=1440)
		return "Failure";
	for(auto s:userName)
	{	
		if(users.find(s)==users.end())
			return "Failure";			
	}
	if(calenderDay.find(day)==calenderDay.end())
	{
		vector<set<string>> event(1440);
		calenderDay[day]=event;
	}
	for(int i=startTime;i<endTime;i++)
	{
		for(auto s:userName)
		{
			if(calenderDay[day][i].find(s)!=calenderDay[day][i].end())
				return "Failure";
		}
	}
	for(int i=startTime;i<endTime;i++)
	{
		for(auto s:userName)
		{
			calenderDay[day][i].insert(s);			
		}
	}
	for(auto s:userName)
	{
		events[event].insert(s);
		userEvent[s].insert(event);
	}
	eventsTime[event]={startTime,endTime};
	eventDate[day].push_back(event);
	event++;
	return "Success";
	
}


vector<string> showEvent()
{
	vector<string> ans;
	string day;
	cin>>day;
	string name;
	cin>>name;
	for(auto eve:eventDate[day])
	{
		if(events[eve].find(name)!=events[eve].end())
		{
			string temp;
			temp = to_string(eventsTime[eve].first)+"-"+to_string(eventsTime[eve].second);
			for(auto u:events[eve])
				temp+=(" "+u);
			ans.push_back(temp);
		}
	}
	return ans;
	
}


int suggestSlot()
{
	string day;
	cin>>day;
	int startTime;
	cin>>startTime;
	int endTime;
	cin>>endTime;
	int duration;
	cin>>duration;
	int usersCount;
	cin>>usersCount;
	vector<string> userName(usersCount);
	
	for(int i=0;i<usersCount;i++)
		cin>>userName[i];
	
	for(int i=startTime;i<=endTime;i++)
	{
		bool ok = true;
		for(int j=i;j<i+duration;j++)
		{
			for(auto s:userName)
			{
				if(calenderDay[day][j].find(s)!=calenderDay[day][j].end())
				{
					ok=false;
					break;
				}
				
			}
			if(!ok)
				break;
		}
		if(ok)
			return i;
	}
	return -1;
}

int main(){
	init_code();
	
	int n;
	cin>>n;
	while(n--)
	{
		string input;
		cin>>input;
		if(input=="add-user")
			cout<<registerUser()<<endl;
		else if(input=="create-event")
			cout<<createEvent()<<endl;
		else if(input=="show-events")
		{
			vector<string> ans = showEvent();
			for(auto s:ans)
				cout<<s<<endl;
		}
		else
		{
			int res=suggestSlot();
			if(res==-1)
				cout<<"None"<<endl;
			else
				cout<<res<<endl;	
		}
	}
	return 0;
}

//input
// 8
// add-user user1
// add-user user2
// add-user user3
// create-event 2021-07-21 600 60 2 user1 user2
// create-event 2021-07-21 660 30 2 user1 user3
// show-events 2021-07-21 user1
// suggest-slot 2021-07-21 600 700 30 3 user1 user2 user3
// suggest-slot 2021-07-21 600 689 30 3 user1 user2 user3


//output
// Success
// Success
// Success
// Success
// Success
// 600-660 user1 user2
// 660-690 user1 user3
// 690
// None
