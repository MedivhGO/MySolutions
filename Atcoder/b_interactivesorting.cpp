#include <iostream>
#include <string>

using namespace std;

// ֻ��ͨ�� tc1
// �����Ż�

int main()
{
    int n, qn;
    cin >> n >> qn;
    
    string str;
    for (int i = 0; i < n; ++i) {
        str += char('A' + i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n ; j++) {
            cout << "?" << " " << str[i]  << " " << str[j] << endl;
            char op;
            cin >> op;
            if (op == '>') {
                swap(str[i], str[j]);
            }
        }
    }

    cout << "!" << " " << str << endl;
    return 0;
}
