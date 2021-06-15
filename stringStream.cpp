// count number of words in a space seperated string
int count_of_words(string &s){
    stringstream ss(s);
    string word;
    int count=0;
    while(ss>>word){
        count++;
    }
    return count;
}

// Remove spaces from a string
void remove_space(string &s){
    stringstream ss(s);
    string temp;
    ss<<s;
    s="";
    while(!ss.eof()){
        ss>>temp;
        s+=temp;
    }
}

// Another way to remove space from a string
// it will remove all char equal to ch; here ch=' ';
void removeSpace(string &s){
    stringstream ss(s);
    string temp;
    s="";
    vector<string>v;
    char ch=' ';
    while(getline(ss,temp,ch)){
        s+=temp;
        v.push_back(temp);
    }
}

// Parse comma seperated string
// e.g.:: "1,2,3,4,5" then vector contains integer  v:={1,2,3,4,5};
vector<int> parseComma(string &s){
    string s1=s;
    if(s1[0]=='[' || s1[0]=='(' || s1[0]=='{' ){
        s="";
        for(int i=1;i<s1.length()-1;i++) s.push_back(s1[i]);
    }
    vector<int>v;
    stringstream ss(s);
    while(ss.good()){
        string temp;
        getline(ss,temp,',');
        v.push_back(stoi(temp));
    }
    int m=v.size();
    return v;
}
