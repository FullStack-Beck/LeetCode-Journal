class Solution {
    vector<int> numbers;
public:
    int romanToInt(string s) {
        int total = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            if( i + 1 < s.length())
            {
                if(s[i] == 'C' && s[i + 1] == 'M')
                {
                    numbers.push_back(900);
                    total += 900;
                    i++;
                    continue; // this is required to jump to the next iteration of the loop, and not to take both CM as 900 and 1000 and just to take 900 
                }
                if(s[i] == 'C' && s[i + 1] == 'D')
                {
                    numbers.push_back(400);
                    total += 400;
                    i++;
                    continue;
                }
                if(s[i] == 'X' && s[i + 1] == 'C')
                {
                    numbers.push_back(90);
                    total += 90;
                    i++;
                    continue;
                }
                if(s[i] == 'X' && s[i + 1] == 'L')
                {
                    numbers.push_back(40);
                    total += 40;
                    i++; 
                    continue;
                }
                if(s[i] == 'I' && s[i + 1] == 'X')
                {
                    numbers.push_back(9);
                    total += 9;
                    i++;
                    continue;
                }
                if(s[i] == 'I' && s[i + 1] == 'V')
                {
                    numbers.push_back(4);
                    total += 4;
                    i++;
                    continue;
                }
            }
            if(s[i] == 'M')
            {
                numbers.push_back(1000);
                total += 1000;
            }
            if(s[i] == 'D')
            {
                numbers.push_back(500);
                total += 500;
            }
            if(s[i] == 'C')
            {
                numbers.push_back(100);
                total += 100;
            }
            if(s[i] == 'L')
            {
                numbers.push_back(50);
                total += 50;
            }
            if(s[i] == 'X')
            {
                numbers.push_back(10);
                total += 10;
            }
            if(s[i] == 'V')
            {
                numbers.push_back(5);
                total += 5;
            }
            if(s[i] == 'I')
            {
                numbers.push_back(1);
                total += 1;
            }
        
        }
        for (int num : numbers) {
        cout << num << " "; // Outputs: 99 5 1 1
        }
        return total;
    }
};

/*
This is a more efficient Solution

#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            // Check if there is a next character available to form a pair
            if (i + 1 < n) {
                if (s[i] == 'C' && s[i + 1] == 'M') { total += 900; i++; continue; }
                if (s[i] == 'C' && s[i + 1] == 'D') { total += 400; i++; continue; }
                if (s[i] == 'X' && s[i + 1] == 'C') { total += 90;  i++; continue; }
                if (s[i] == 'X' && s[i + 1] == 'L') { total += 40;  i++; continue; }
                if (s[i] == 'I' && s[i + 1] == 'X') { total += 9;   i++; continue; }
                if (s[i] == 'I' && s[i + 1] == 'V') { total += 4;   i++; continue; }
            }

            // Fallback to single characters if no pair matched
            if (s[i] == 'M') total += 1000;
            else if (s[i] == 'D') total += 500; // Note: 'D' was missing in your original code
            else if (s[i] == 'C') total += 100;
            else if (s[i] == 'L') total += 50;
            else if (s[i] == 'X') total += 10;
            else if (s[i] == 'V') total += 5;
            else if (s[i] == 'I') total += 1;
        }
        
        return total;
    }
};
*/
