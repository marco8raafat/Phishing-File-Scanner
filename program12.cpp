#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
ifstream file;
map<string, int> phishingPhrases = { //map to store phishing phrases and words.
        {"Verify your account", 3},
        {"Your account has been suspended", 3},
        {"Update your information", 3},
        {"Immediate action required", 3},
        {"Click here to reset your password", 3},
        {"Security alert", 3},
        {"Your account has been compromised", 3},
        {"Your payment was declined", 3},
        {"Confirm your identity", 3},
        {"Login to secure your account", 3},
        {"Urgent", 2},
        {"Log in to view", 2},
        {"Unusual activity", 2},
        {"Account verification", 2},
        {"Limited-time offer", 2},
        {"Free gift", 2},
        {"Congratulations, you've won", 2},
        {"Action needed: Suspicious login attempt detected", 2},
        {"We couldn't process your recent payment", 2},
        {"Payment confirmation required", 2},
        {"Secure login", 1},
        {"Survey: Rate your recent customer service experience", 1},
        {"Secure your investment: Account upgrade required", 1},
        {"We've credited your account, confirm details", 1},
        {"Unexpected sign-in from a new device", 1},
        {"Document shared with you: 'Your Contract.pdf'", 1},
        {"New voicemail from [Company Name]", 1},
        {"Corporate IT: Password expiration notice", 1},
        {"Pending invoice: Complete your wire transfer", 1},
        {"Refund issued verify your account to receive funds", 1}
    };
    map<string, int> key_value; //(word,num of occurrences)
    int TotalPointsFound = 0; 
file.open("phishing_email.txt");
if (!file.is_open()) {
    cout << "Unable to open file";
    return 1;
}
else{
    //scanning the file
    cout << "Scanning the file\n";
    string line;
    while (!file.eof()){
        getline(file, line);
        for (auto it = phishingPhrases.begin(); it != phishingPhrases.end(); it++){
    string search = it->first;
    int count = 0; //number of occurrences
    int pos = line.find(search); // variable to store the position of the word
    // check if the word is present in the line
    while (pos != string::npos) {
        count++;
        pos = line.find(search, pos + search.length());
    }
    
    if (count > 0){
    key_value[search] += count;
    TotalPointsFound += it->second * count;
    }
 
}

    }
    for (auto entry : key_value){ 
        int points = entry.second * phishingPhrases[entry.first]; // num of occurrences multiply with num of points
        cout << "word/phrase : " << entry.first << "\nnum of occur: " << entry.second << "\ntotal points: "<<points<<endl; 
        cout<<"--------------------------------------------------\n";

    }
    cout << "Total points found: " << TotalPointsFound << endl;
    if (TotalPointsFound >= 10){
    cout << "This email is likely a phishing attempt.\n";
} else{
    cout << "This email is not a phishing attempt.\n";
}
    file.close();
    cout << "File closed successfully.\n";

}


    return 0;
}
