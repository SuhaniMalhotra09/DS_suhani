Q4.//String Related Programs
//(a) Write a program to concatenate one string to another string.
//(b) Write a program to reverse a string.
//(c) Write a program to delete all the vowels from the string.
//(d) Write a program to sort the strings in alphabetical order.
//(e) Write a program to convert a character from uppercase to lowercase.

  #include <iostream>
using namespace std;

int main() {
    char s1[100] = "hello";
    char s2[7] = "world";
    
    int i = 0;
    int len1 = 0;
    
    while (s1[len1] != '\0') {
        len1++;
    }
    
    int len2 = 0;
    while (s2[len2] != '\0') {
        len2++;
    }
    
   
    for (int j = 0; j < len2; j++) {
        s1[len1 + j] = s2[j];
    }
    
   
    s1[len1 + len2] = '\0';
    
  
    cout << s1;
    
  return 0;
}
//reverse
#include <iostream>
using namespace std;

int main() {
    char s1[] = "keha";  
    
    int length = 0;
    
    while (s1[length] != '\0') {
        length++;
    }
    
    int first = 0;
    int last = length - 1;
    
    while (first < last) {
        char temp = s1[first];
        s1[first] = s1[last];
        s1[last] = temp;
        first++;
        last--;
    }
    
   
    cout << s1 << endl;
    
    return 0;
}
//delete vowels
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int j = 0; 
    int i = 0;

    while (str[i] != '\0') {  
        char ch = str[i];
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
              ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
            str[j++] = ch; 
        }
        i++;
    }

    str[j] = '\0'; 

    cout << "String without vowels: " << str.c_str() ;

    return 0;
}
//sort strings
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); 

    string arr[100]; 
    cout << "Enter " << n << " strings:" ;
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

   
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) { 
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "\nStrings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
//uppercase to lowercase
#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; 
        cout << "Lowercase: " << ch << endl;
    } else {
        cout << "Not an uppercase letter!";
    }

    return 0;
}
