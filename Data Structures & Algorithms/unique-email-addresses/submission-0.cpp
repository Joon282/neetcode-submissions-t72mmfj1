class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        int unsent = 0;
        std::unordered_map<std::string, int> map1;
        for (const std::string& email : emails){
            int i = 0;
            std::string localName = "";
            std::string domainName = "";
            while (i < email.length()){
                if (email[i] == '@'){
                    domainName = email.substr(i+1);
                    break;
                }
                if (email[i] == '.'){
                    i++;
                    continue;
                } 
                localName += email[i];
                i++;
            }
            i = 0;
            while (i < localName.length()){
                if (localName[i] == '+'){
                    localName = localName.substr(0, i-1);
                }
                i++;
            }
            std::string address = localName + '@' + domainName;
            if (map1.count(address)){
                unsent++;
            }
            map1[address]++;
        }
        return n - unsent;
    }
};