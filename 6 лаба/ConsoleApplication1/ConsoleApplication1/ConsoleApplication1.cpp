//#include <iostream>
//#include <string>
//
//using namespace std;
//
//bool isAlmostPalindrome(const string& s) {
//    for (int i = 0; i < s.length(); ++i) {
//        string temp = s;
//        temp.erase(i, 1);
//        bool isPalindrome = true;
//        for (int j = 0; j < temp.length() / 2; ++j) {
//            if (temp[j] != temp[temp.length() - 1 - j]) {
//                isPalindrome = false;
//                break;
//            }
//        }
//        if (isPalindrome) {
//            return true;
//        }
//    }
//    return false;
//}
//
//int main() {
//
//    string s;
//    cin >> s;
//    if (s.length() > 4) {
//        cout << "Enter a 4-character string!";
//        cin >> s;
//
//
//
//    }
//    if (isAlmostPalindrome(s)) {
//        cout << "YES" << endl;
//    }
//    else {
//        cout << "NO" << endl;
//    }
//    return 0;
//}
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    vector<int> t(n + 1), s(n + 1);  
//
//    for (int i = 1; i <= n; ++i) {
//        cin >> t[i] >> s[i];
//    }
//
//    int q;
//    cin >> q;
//    vector<pair<int, int>> queries(q);  
//    for (int i = 0; i < q; ++i) {
//        cin >> queries[i].first >> queries[i].second;
//    }
//
//    vector<int> answers(q);  
//    for (int i = 0; i < q; ++i) {
//        int k = queries[i].first;
//        int m = queries[i].second;
//
//        if (m <= t[k]) {
//            answers[i] = t[k];
//        }
//        else {
//            int x = (m - t[k] + s[k] - 1) / s[k] + 1;
//            answers[i] = t[k] + (x - 1) * s[k];
//        }
//    }
//
//    for (int ans : answers) {
//        cout << ans << "\n";
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_set>
//
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//
//    sort(a.begin(), a.end(), greater<int>());
//
//    unordered_set<int> unique_elements;
//
//    for (int x : a) {
//        while (x > 0) {
//            if (unique_elements.find(x) == unique_elements.end()) {
//                unique_elements.insert(x);
//                break;
//            }
//            x /= 2;
//        }
//        if (x == 0 && unique_elements.find(0) == unique_elements.end()) {
//            unique_elements.insert(0);
//        }
//    }
//
//    cout << unique_elements.size() << "\n";
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//int main() {
//
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//
//    int count = 0;
//
//    for (int l = 0; l < n; ++l) {
//        for (int r = l + 2; r < n; ++r) {  
//            bool found = false;
//            for (int i = l; i <= r && !found; ++i) {
//                for (int j = i + 1; j <= r && !found; ++j) {
//                    for (int k = j + 1; k <= r && !found; ++k) {
//                        if (2 * a[j] == a[i] + a[k]) {
//                            found = true;
//                            count++;
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    cout << count << "\n";
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//    int n, a, b;
//    cin >> n >> a >> b;
//    string s;
//    cin >> s;
//
//    int open = 0, close = 0;
//
//    for (char ch : s) {
//        if (ch == '(') {
//            open++;
//        }
//        else {
//            if (open > 0) {
//                open--; 
//            }
//            else {
//                close++; 
//            }
//        }
//    }
//
//    int cost = 0;
//
//    if (a < 2 * b) {
//        cost += min(open, close) * a; 
//        cost += (abs(open - close)- min(open, close)) * b;
//    }
//    else {
//        cost += open * b; 
//        cost += close * b; 
//    }
//
//    cout << cost << endl;
//
//    return 0;
//}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int open = 0, close = 0;

    // Подсчет лишних открывающих и закрывающих скобок
    for (char ch : s) {
        if (ch == '(') {
            open++;
        }
        else {
            if (open > 0) {
                open--; // Удаляем пару
            }
            else {
                close++; // Увеличиваем количество лишних закрывающих
            }
        }
    }

    int cost = 0;

    // Сравниваем стоимость операций
    if (a < 2 * b) {
        // Если перестановка дешевле двух замен
        int pairs = min(open, close); // Количество пар, которые можно поменять
        cost += pairs * a; // Стоимость перестановки пар

        // Остаток нужно заменить
        cost += (open - pairs) * b; // Заменяем лишние открывающие
        cost += (close - pairs) * b; // Заменяем лишние закрывающие
    }
    else {
        // Если замена дешевле
        cost += open * b; // Замена лишних открывающих
        cost += close * b; // Замена лишних закрывающих
    }

    cout << cost << endl;

    return 0;
}